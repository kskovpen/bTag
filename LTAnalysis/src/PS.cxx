#include "../include/PS.h"

#include "TSystem.h"

LTANA::PS::PS()
{
}

LTANA::PS::~PS()
{
   if( _doPS )
     {
	_fBTagMu_DiJet20_Mu5.close();
	_fBTagMu_DiJet40_Mu5.close();
	_fBTagMu_DiJet70_Mu5.close();
	_fBTagMu_DiJet110_Mu5.close();
	_fBTagMu_Jet300_Mu5.close();
     }   	     
}

void LTANA::PS::init(bool doPS)
{
   std::string path = "/user/kskovpen/analysis/bTag/CMSSW_8_0_12/src/LTAnalysis/test/PS/";
   std::string fnameBTagMu_DiJet20_Mu5 = path+"HLT_BTagMu_DiJet20_Mu5.csv";
   std::string fnameBTagMu_DiJet40_Mu5 = path+"HLT_BTagMu_DiJet40_Mu5.csv";
   std::string fnameBTagMu_DiJet70_Mu5 = path+"HLT_BTagMu_DiJet70_Mu5.csv";
   std::string fnameBTagMu_DiJet110_Mu5 = path+"HLT_BTagMu_DiJet110_Mu5.csv";
//   std::string fnameBTagMu_DiJet170_Mu5 = path+"HLT_BTagMu_DiJet170_Mu5.csv";
   std::string fnameBTagMu_Jet300_Mu5 = path+"HLT_BTagMu_Jet300_Mu5.csv";
   
   bool existBTagMu_DiJet20_Mu5 = !(gSystem->AccessPathName(fnameBTagMu_DiJet20_Mu5.c_str()));
   bool existBTagMu_DiJet40_Mu5 = !(gSystem->AccessPathName(fnameBTagMu_DiJet40_Mu5.c_str()));
   bool existBTagMu_DiJet70_Mu5 = !(gSystem->AccessPathName(fnameBTagMu_DiJet70_Mu5.c_str()));
   bool existBTagMu_DiJet110_Mu5 = !(gSystem->AccessPathName(fnameBTagMu_DiJet110_Mu5.c_str()));
//   bool existBTagMu_DiJet170_Mu5 = !(gSystem->AccessPathName(fnameBTagMu_DiJet170_Mu5.c_str()));
   bool existBTagMu_Jet300_Mu5 = !(gSystem->AccessPathName(fnameBTagMu_Jet300_Mu5.c_str()));

   if( !existBTagMu_DiJet20_Mu5 || !existBTagMu_DiJet40_Mu5 || !existBTagMu_DiJet70_Mu5 ||
       !existBTagMu_DiJet110_Mu5 || !existBTagMu_Jet300_Mu5 )
//       !existBTagMu_DiJet110_Mu5 || !existBTagMu_DiJet170_Mu5 || !existBTagMu_Jet300_Mu5 )
     {
	std::cout << "Input file with PS factors can not be opened, no reweighting will be applied" << std::endl;
	doPS = 0;
     }
   else 
     {
	std::cout << "Read PS" << std::endl;
	_fBTagMu_DiJet20_Mu5.open(fnameBTagMu_DiJet20_Mu5.c_str());
	_fBTagMu_DiJet40_Mu5.open(fnameBTagMu_DiJet40_Mu5.c_str());
	_fBTagMu_DiJet70_Mu5.open(fnameBTagMu_DiJet70_Mu5.c_str());
	_fBTagMu_DiJet110_Mu5.open(fnameBTagMu_DiJet110_Mu5.c_str());
//	_fBTagMu_DiJet170_Mu5.open(fnameBTagMu_DiJet170_Mu5.c_str());
	_fBTagMu_Jet300_Mu5.open(fnameBTagMu_Jet300_Mu5.c_str());
     }   
   
   _doPS = doPS;

   for(int i=0;i<100;i++) _nElem[i] = 0;
   
   for(int i=0;i<NMAX;i++)
     {	
	_psBTagMu_DiJet20_Mu5[i] = 0.;
	_runBTagMu_DiJet20_Mu5[i] = 0.;
	_lbBTagMu_DiJet20_Mu5[i] = 0.;
	
	_psBTagMu_DiJet40_Mu5[i] = 0.;
	_runBTagMu_DiJet40_Mu5[i] = 0.;
	_lbBTagMu_DiJet40_Mu5[i] = 0.;

	_psBTagMu_DiJet70_Mu5[i] = 0.;
	_runBTagMu_DiJet70_Mu5[i] = 0.;
	_lbBTagMu_DiJet70_Mu5[i] = 0.;

	_psBTagMu_DiJet110_Mu5[i] = 0.;
	_runBTagMu_DiJet110_Mu5[i] = 0.;
	_lbBTagMu_DiJet110_Mu5[i] = 0.;

//	_psBTagMu_DiJet170_Mu5[i] = 0.;
//	_runBTagMu_DiJet170_Mu5[i] = 0.;
//	_lbBTagMu_DiJet170_Mu5[i] = 0.;

	_psBTagMu_Jet300_Mu5[i] = 0.;
	_runBTagMu_Jet300_Mu5[i] = 0.;
	_lbBTagMu_Jet300_Mu5[i] = 0.;
     }   
   
   if( _doPS ) fillPS();
}

void LTANA::PS::fillPS()
{
   std::string trigName[5] = {"BTagMu_DiJet20_Mu5",
      "BTagMu_DiJet40_Mu5","BTagMu_DiJet70_Mu5","BTagMu_DiJet110_Mu5",
      "BTagMu_Jet300_Mu5"};
//      "BTagMu_DiJet170_Mu5","BTagMu_Jet300_Mu5"};
   
   int run,cmsls,totprescval;
   
   for(int i=0;i<5;i++)
     {	
	std::string name = trigName[i];
	
	std::ifstream *fps;
	if( strcmp(name.c_str(),"BTagMu_DiJet20_Mu5") == 0 ) fps = &_fBTagMu_DiJet20_Mu5;
	else if( strcmp(name.c_str(),"BTagMu_DiJet40_Mu5") == 0 ) fps = &_fBTagMu_DiJet40_Mu5;
	else if( strcmp(name.c_str(),"BTagMu_DiJet70_Mu5") == 0 ) fps = &_fBTagMu_DiJet70_Mu5;
	else if( strcmp(name.c_str(),"BTagMu_DiJet110_Mu5") == 0 ) fps = &_fBTagMu_DiJet110_Mu5;
//	else if( strcmp(name.c_str(),"BTagMu_DiJet170_Mu5") == 0 ) fps = &_fBTagMu_DiJet170_Mu5;
	else if( strcmp(name.c_str(),"BTagMu_Jet300_Mu5") == 0 ) fps = &_fBTagMu_Jet300_Mu5;
	else
	  {
	     std::cout << "PS file not known: " << name << std::endl;
	     exit(1);
	  }	
	
	int c = 0;
	while( !fps->eof() )
	  {
	     std::string line;
	     
	     *fps >> line;

	     if( c > 0 )
	       {		  
		  std::stringstream ss(line);
		  std::string item;
		  
		  int idx = 0;
		  while( std::getline(ss,item,',') )
		    {
		       if( idx == 0 ) run = atoi(item.c_str());
		       if( idx == 1 ) cmsls = atoi(item.c_str());
		       if( idx == 3 ) totprescval = atoi(item.c_str());
		       idx++;
		       
		       if( strcmp(name.c_str(),"BTagMu_DiJet20_Mu5") == 0 )
			 {		       
			    _psBTagMu_DiJet20_Mu5[c] = totprescval;
			    _runBTagMu_DiJet20_Mu5[c] = run;
			    _lbBTagMu_DiJet20_Mu5[c] = cmsls;
			 }		  
		       else if( strcmp(name.c_str(),"BTagMu_DiJet40_Mu5") == 0 )
			 {		       
			    _psBTagMu_DiJet40_Mu5[c] = totprescval;
			    _runBTagMu_DiJet40_Mu5[c] = run;
			    _lbBTagMu_DiJet40_Mu5[c] = cmsls;
			 }		  
		       else if( strcmp(name.c_str(),"BTagMu_DiJet70_Mu5") == 0 )
			 {		       
			    _psBTagMu_DiJet70_Mu5[c] = totprescval;
			    _runBTagMu_DiJet70_Mu5[c] = run;
			    _lbBTagMu_DiJet70_Mu5[c] = cmsls;
			 }		  
		       else if( strcmp(name.c_str(),"BTagMu_DiJet110_Mu5") == 0 )
			 {		       
			    _psBTagMu_DiJet110_Mu5[c] = totprescval;
			    _runBTagMu_DiJet110_Mu5[c] = run;
			    _lbBTagMu_DiJet110_Mu5[c] = cmsls;
			 }		  
/*		       else if( strcmp(name.c_str(),"BTagMu_DiJet170_Mu5") == 0 )
			 {		       
			    _psBTagMu_DiJet170_Mu5[c] = totprescval;
			    _runBTagMu_DiJet170_Mu5[c] = run;
			    _lbBTagMu_DiJet170_Mu5[c] = cmsls;
			 }*/
		       else if( strcmp(name.c_str(),"BTagMu_Jet300_Mu5") == 0 )
			 {		       
			    _psBTagMu_Jet300_Mu5[c] = totprescval;
			    _runBTagMu_Jet300_Mu5[c] = run;
			    _lbBTagMu_Jet300_Mu5[c] = cmsls;
			 }
		    }
	       }
	     
	     c++;
	  }

	_nElem[i] = c;
     }   
}

double LTANA::PS::getPSWeight(std::string trigName,int run,int lb)
{
   double w = 1.;
   
   if( _doPS )
     {
	if( strcmp(trigName.c_str(),"BTagMu_DiJet20_Mu5") == 0 )
	  {
	     for(int i=0;i<_nElem[0];i++)
	       {
		  if( run == _runBTagMu_DiJet20_Mu5[i] &&
		      lb >= _lbBTagMu_DiJet20_Mu5[i] )
		    {
		       int j = i;
		       while(1)
			 {
			    if( j+1 < _nElem[0] )
			      {				 
				 if( !(run == _runBTagMu_DiJet20_Mu5[j+1] &&
				       lb >= _lbBTagMu_DiJet20_Mu5[j+1] &&
				       _lbBTagMu_DiJet20_Mu5[j+1] > _lbBTagMu_DiJet20_Mu5[i]) )
				   break;
				 j++;
			      }
			    else break;
			 }
		       
		       w = _psBTagMu_DiJet20_Mu5[j];
		       
		       break;
		    }		  
	       }	     
	  }	
	else if( strcmp(trigName.c_str(),"BTagMu_DiJet40_Mu5") == 0 )
	  {
	     for(int i=0;i<_nElem[1];i++)
	       {
		  if( run == _runBTagMu_DiJet40_Mu5[i] &&
		      lb >= _lbBTagMu_DiJet40_Mu5[i] )
		    {
		       int j = i;
		       while(1)
			 {
			    if( j+1 < _nElem[1] )
			      {				 
				 if( !(run == _runBTagMu_DiJet40_Mu5[j+1] &&
				       lb >= _lbBTagMu_DiJet40_Mu5[j+1] &&
				       _lbBTagMu_DiJet40_Mu5[j+1] > _lbBTagMu_DiJet40_Mu5[i]) )
				   break;
				 j++;
			      }
			    else break;
			 }
		       
		       w = _psBTagMu_DiJet40_Mu5[j];
		       
		       break;
		    }		  
	       }	     
	  }	
	else if( strcmp(trigName.c_str(),"BTagMu_DiJet70_Mu5") == 0 )
	  {
	     for(int i=0;i<_nElem[2];i++)
	       {
		  if( run == _runBTagMu_DiJet70_Mu5[i] &&
		      lb >= _lbBTagMu_DiJet70_Mu5[i] )
		    {
		       int j = i;
		       while(1)
			 {
			    if( j+1 < _nElem[2] )
			      {				 
				 if( !(run == _runBTagMu_DiJet70_Mu5[j+1] &&
				       lb >= _lbBTagMu_DiJet70_Mu5[j+1] &&
				       _lbBTagMu_DiJet70_Mu5[j+1] > _lbBTagMu_DiJet70_Mu5[i]) )
				   break;
				 j++;
			      }
			    else break;
			 }
		       
		       w = _psBTagMu_DiJet70_Mu5[j];
		       
		       break;
		    }		  
	       }	     
	  }	
	else if( strcmp(trigName.c_str(),"BTagMu_DiJet110_Mu5") == 0 )
	  {
	     for(int i=0;i<_nElem[3];i++)
	       {
		  if( run == _runBTagMu_DiJet110_Mu5[i] &&
		      lb >= _lbBTagMu_DiJet110_Mu5[i] )
		    {
		       int j = i;
		       while(1)
			 {
			    if( j+1 < _nElem[3] )
			      {				 
				 if( !(run == _runBTagMu_DiJet110_Mu5[j+1] &&
				       lb >= _lbBTagMu_DiJet110_Mu5[j+1] &&
				       _lbBTagMu_DiJet110_Mu5[j+1] > _lbBTagMu_DiJet110_Mu5[i]) )
				   break;
				 j++;
			      }
			    else break;
			 }
		       
		       w = _psBTagMu_DiJet110_Mu5[j];
		       
		       break;
		    }		  
	       }	     
	  }	
/*	else if( strcmp(trigName.c_str(),"BTagMu_DiJet170_Mu5") == 0 )
	  {
	  }*/
	else if( strcmp(trigName.c_str(),"BTagMu_Jet300_Mu5") == 0 )
	  {
	     for(int i=0;i<_nElem[4];i++)
	       {
		  if( run == _runBTagMu_Jet300_Mu5[i] &&
		      lb >= _lbBTagMu_Jet300_Mu5[i] )
		    {
		       int j = i;
		       while(1)
			 {
			    if( j+1 < _nElem[4] )
			      {				 
				 if( !(run == _runBTagMu_Jet300_Mu5[j+1] &&
				       lb >= _lbBTagMu_Jet300_Mu5[j+1] &&
				       _lbBTagMu_Jet300_Mu5[j+1] > _lbBTagMu_Jet300_Mu5[i]) )
				   break;
				 j++;
			      }
			    else break;
			 }
		       
		       w = _psBTagMu_Jet300_Mu5[j];
		       
		       break;
		    }		  
	       }	     
	  }	
     }
   
   return w;
}
