#include "../include/Reweight.h"

#include "TSystem.h"

LTANA::Reweight::Reweight()
{
}

LTANA::Reweight::~Reweight()
{
}

void LTANA::Reweight::init(int doRW,
			   std::vector<float> jPtMin,
			   std::vector<float> jPtMax,
			   std::vector<std::string> sel,
			   std::vector<std::string> selb,
			   std::vector<std::string> rwName)
{
   int _rwN = rwName.size();
   for(int i=0;i<_rwN;i++)
     {	
	_rwName.push_back(rwName[i]);
     }   

   _selName = sel;
   _selN = sel.size();

   _selbName = selb;
   _selbN = selb.size();
   
   rwBin.clear();
   rwSf.clear();

   _jPtMin = jPtMin;
   _jPtMax = jPtMax;
   
   std::cout << "Read corrections" << std::endl;

   std::string fname = "/home-pbs/kskovpen/bTag/CMSSW_7_4_0/src/LTAnalysis/test/reweight/test/corrections.root";
   
   bool exist = !(gSystem->AccessPathName(fname.c_str()));
   
   if( !exist )
     {
	std::cout << "Input file with RW factors can not be opened, no corrections will be applied" << std::endl;
	doRW = 0;
     }
   else _fcor = TFile::Open(fname.c_str(),"READ");
   
   if( doRW == 1 )
     {	     		
	for(int isf=0;isf<_rwN;isf++)
	  {
	     std::vector<std::vector<std::vector<std::pair<float,float> > > > v_ptBin;
	     std::vector<std::vector<std::vector<std::pair<float,float> > > > v_ptSf;
	     
	     for(int ipt=0;ipt<_selN;ipt++)
	       {
		  std::vector<std::vector<std::pair<float,float> > > v_btBin;
		  std::vector<std::vector<std::pair<float,float> > > v_btSf;

		  for(int ibtag=0;ibtag<_selbN;ibtag++)
		    {		       
		       std::string sfname = "sf_"+_selName[ipt]+"_"+_selbName[ibtag]+"_"+_rwName[isf];
		       TH1D *hSF = (TH1D*)_fcor->Get(sfname.c_str());
		       std::cout << sfname << std::endl;
		       
		       std::vector<std::pair<float,float> > v_valBin;
		       std::vector<std::pair<float,float> > v_valSf;
		       
		       int nb = hSF->GetXaxis()->GetNbins();
		       for(int ib=1;ib<=nb;ib++)
			 {		  
			    float pt1 = hSF->GetXaxis()->GetBinLowEdge(ib);
			    float pt2 = hSF->GetXaxis()->GetBinUpEdge(ib);
			    float sf = hSF->GetBinContent(ib);
			    float sferr = hSF->GetBinError(ib);
			    
			    std::pair<float,float> binfo = std::make_pair(pt1,pt2);
			    std::pair<float,float> sfinfo = std::make_pair(sf,sferr);
			    v_valBin.push_back(binfo);
			    v_valSf.push_back(sfinfo);
			 }
		       v_btBin.push_back(v_valBin);
		       v_btSf.push_back(v_valSf);
		    }
		  v_ptBin.push_back(v_btBin);
		  v_ptSf.push_back(v_btSf);
	       }	     
	     rwBin.push_back(v_ptBin);
	     rwSf.push_back(v_ptSf);	     
	  }		
     }   
/*   if( doRW == 2 )
     {
	std::vector<std::vector<std::pair<float,float> > > v_pt2DBinX;
	std::vector<std::vector<std::pair<float,float> > > v_pt2DBinY;
	std::vector<std::vector<std::pair<float,float> > > v_pt2DSf;
	v_pt2DBinX.clear();
	v_pt2DBinY.clear();
	v_pt2DSf.clear();
	
	for(int ipt=0;ipt<_selN;ipt++)
	  {		       
	     std::string sfname = "sf_"+_selName[ipt]+"_nosel_"+_rwName2d[0];
	     TH2D *hSF = (TH2D*)_fcor->Get(sfname.c_str());
	     std::cout << sfname << std::endl;
	     
	     std::vector<std::pair<float,float> > v_val2DBinX;
	     std::vector<std::pair<float,float> > v_val2DBinY;
	     std::vector<std::pair<float,float> > v_val2DSf;
	     v_val2DBinX.clear();
	     v_val2DBinY.clear();
	     v_val2DSf.clear();
	     
	     int nbX = hSF->GetXaxis()->GetNbins();
	     for(int ib=0;ib<=nbX+1;ib++)
	       {		  
		  float pt1 = hSF->GetXaxis()->GetBinLowEdge(ib);
		  float pt2 = hSF->GetXaxis()->GetBinUpEdge(ib);
		  
		  std::pair<float,float> binfo = std::make_pair(pt1,pt2);
		  v_val2DBinX.push_back(binfo);
	       }
	     v_pt2DBinX.push_back(v_val2DBinX);
	     
	     int nbY = hSF->GetYaxis()->GetNbins();
	     for(int ib=0;ib<=nbY+1;ib++)
	       {		  
		  float pt1 = hSF->GetYaxis()->GetBinLowEdge(ib);
		  float pt2 = hSF->GetYaxis()->GetBinUpEdge(ib);
		  
		  std::pair<float,float> binfo = std::make_pair(pt1,pt2);
		  v_val2DBinY.push_back(binfo);
	       }
	     v_pt2DBinY.push_back(v_val2DBinY);
	     
	     for(int ibx=0;ibx<=nbX+1;ibx++)
	       {		  
		  for(int iby=0;iby<=nbY+1;iby++)
		    {		  
		       float sf = hSF->GetBinContent(ibx,iby);
		       float sferr = hSF->GetBinError(ibx,iby);
		       
		       std::pair<float,float> sfinfo = std::make_pair(sf,sferr);
		       v_val2DSf.push_back(sfinfo);
		    }		       
	       }
	     
	     v_pt2DSf.push_back(v_val2DSf);
	  }
	
	rw2DBinX.push_back(v_pt2DBinX);
	rw2DBinY.push_back(v_pt2DBinY);
	
	rw2DSf.push_back(v_pt2DSf);
     }*/

   if( doRW ) _fcor->Close();
   
   _doRW = doRW;
}

void LTANA::Reweight::apply(float *sfj,int ibtag,int jPtBin,
			    int ntrk,int nseltrk,int njet,int nsv,float mupt,float jeta,float jpt)
{   
   // 0 - pre-tag
   // 1 - post-tag
   
   float rwSF = 1.;

   if( _doRW == 1 )
     {
	for(int iv=0;iv<_rwN;iv++)
	  {			    
	     std::vector<std::pair<float,float> > rwBinFound;
	     rwBinFound = rwBin[ibtag][iv][jPtBin];

	     std::vector<std::pair<float,float> > rwSfFound;
	     rwSfFound = rwSf[ibtag][iv][jPtBin];
	     
	     if( strcmp(_rwName[iv].c_str(),"1d_ntrk") == 0 )
	       {		
		  rwSF *= getSF(rwBinFound,rwSfFound,ntrk);
	       }
	     if( strcmp(_rwName[iv].c_str(),"1d_nseltrk") == 0 )
	       {		
		  rwSF *= getSF(rwBinFound,rwSfFound,nseltrk);
	       }
	     if( strcmp(_rwName[iv].c_str(),"1d_njet") == 0 )
	       {		
		  rwSF *= getSF(rwBinFound,rwSfFound,njet);
	       }
	     if( strcmp(_rwName[iv].c_str(),"1d_nsv") == 0 )
	       {		
		  rwSF *= getSF(rwBinFound,rwSfFound,nsv);
	       }
	     if( strcmp(_rwName[iv].c_str(),"1d_mupt") == 0 )
	       {
		  rwSF *= getSF(rwBinFound,rwSfFound,mupt);
	       }
	     if( strcmp(_rwName[iv].c_str(),"1d_eta") == 0 )
	       {		
		  rwSF *= getSF(rwBinFound,rwSfFound,jeta);
	       }
	     if( strcmp(_rwName[iv].c_str(),"1d_pt") == 0 )
	       {		
		  float jptmax = 1250.;
		  float jptmin = 0.;
		  if( jPtBin > 0 ) 
		    {
		       jptmax = _jPtMax[jPtBin-1];
		       jptmin = _jPtMin[jPtBin-1];
		    }	     
		  float vPT = (jpt-jptmin)/(jptmax-jptmin);
		  
		  rwSF *= getSF(rwBinFound,rwSfFound,vPT);
	       }
	  }		       
     }
/*   if( _doRW == 2 )
     {
	std::vector<std::pair<float,float> > rw2DBinXFound =
	  rw2DBinX[0][jPtBin];
	std::vector<std::pair<float,float> > rw2DBinYFound =
	  rw2DBinY[0][jPtBin];
	std::vector<std::pair<float,float> > rw2DSfFound =
	  rw2DSf[0][jPtBin];
	
	if( 
	   strcmp(_rwName2d[0].c_str(),"2d_ntrk_vs_mupt") == 0
	  )
	  {
	     rwSF *= get2DSF(rw2DBinXFound,rw2DBinYFound,
			     rw2DSfFound,
			     mupt,
			     ntrk);
	  }
	else if(
		strcmp(_rwName2d[0].c_str(),"2d_nseltrk_vs_njet") == 0
	       )
	  {
	     rwSF *= get2DSF(rw2DBinXFound,rw2DBinYFound,
			     rw2DSfFound,
			     njet,
			     nseltrk);
	  }
     }*/
   
   *sfj = (*sfj) * rwSF;
}

float LTANA::Reweight::getSF(std::vector<std::pair<float,float> > vBin,
			     std::vector<std::pair<float,float> > vSf,
			     float var)
{
   float sf = 1.;
   
   for(int ib=0;ib<vBin.size();ib++)
     {
	float blow = vBin.at(ib).first;
	float bup = vBin.at(ib).second;
	
	if( var >= blow && var < bup )
	  {
	     sf = vSf.at(ib).first;
	     break;
	  }	
     }   
   
   return sf;
}

/*float LTANA::Reweight::get2DSF(std::vector<std::pair<float,float> > vBinX,
			       std::vector<std::pair<float,float> > vBinY,
			       std::vector<std::pair<float,float> > vSf,
			       float varX,
			       float varY)
{
   float sf = 1.;

   int idx = -1;
   int idy = -1;

   int nbx = vBinX.size();
   int nby = vBinY.size();
   
   for(int ib=0;ib<vBinX.size();ib++)
     {
	float blow = vBinX.at(ib).first;
	float bup = vBinX.at(ib).second;
	
	if( varX >= blow && varX < bup )
	  {
	     idx = ib;
	     break;
	  }	
     }   

   for(int ib=0;ib<vBinY.size();ib++)
     {
	float blow = vBinY.at(ib).first;
	float bup = vBinY.at(ib).second;
	
	if( varY >= blow && varY < bup )
	  {
	     idy = ib;
	     break;
	  }	
     }   
   
   int id2D = idx*nby+idy;

   if( idx >= 0 && idy >= 0 )
     sf = vSf.at(id2D).first;
   
   return sf;
}*/
