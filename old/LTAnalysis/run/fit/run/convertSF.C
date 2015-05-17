#include <algorithm>

std::ofstream fout;

void convertSF(std::string tagger,std::string finLOOSE,std::string finMEDIUM,std::string finTIGHT)
{
   gROOT->SetBatch(1);

   // $P_{T} [GeV]$ & SF & Stat & $N_{trk}$ & $N_{jets}$ & $P_{T} (\mu)$ & $\eta (jet)$ & Pileup & Gluon splitting & b-frag & $D \to \mu X$ & c-frag & $K_{S}^{0} (\Lambda)$ & $N_{trk}^{gen}$ & JES & JER & $C_{b}$ & Add & Syst
   
   // CSV;OperatingPoint, measurementType, sysType, jetFlavor, etaMin, etaMax, ptMin, ptMax, discrMin, discrMax, formula

   std::string fname = tagger+"_7TEV_LEGACY_20130318_LT.csv";
   fout.open(fname.c_str());
   fout << tagger+";OperatingPoint, measurementType, sysType, jetFlavor, etaMin, etaMax, ptMin, ptMax, discrMin, discrMax, formula" << std::endl;
   
   if( finLOOSE != "" ) fillInfo(finLOOSE,"0");
   if( finMEDIUM != "" ) fillInfo(finMEDIUM,"1");
   if( finTIGHT != "" ) fillInfo(finTIGHT,"2");

   fout.close();
   
   gApplication->Terminate();
}

void fillInfo(std::string fin,std::string wp)
{
   const int nmax = 100;
   std::string ptMin[nmax];
   std::string ptMax[nmax];
   std::string central[nmax];
   std::string up[nmax], down[nmax];
   std::string up_stat[nmax], down_stat[nmax];
   std::string up_ntrk[nmax], down_ntrk[nmax];
   std::string up_njet[nmax], down_njet[nmax];
   std::string up_mupt[nmax], down_mupt[nmax];
   std::string up_jeta[nmax], down_jeta[nmax];
   std::string up_pu[nmax], down_pu[nmax];
   std::string up_gsplit[nmax], down_gsplit[nmax];
   std::string up_bfrag[nmax], down_bfrag[nmax];
   std::string up_dmux[nmax], down_dmux[nmax];
   std::string up_cfrag[nmax], down_cfrag[nmax];
   std::string up_ksl[nmax], down_ksl[nmax];
   std::string up_ntrkgen[nmax], down_ntrkgen[nmax];
   std::string up_jes[nmax], down_jes[nmax];
   std::string up_jer[nmax], down_jer[nmax];
   std::string up_cb[nmax], down_cb[nmax];
   std::string up_add[nmax], down_add[nmax];
   
   std::ifstream f(fin.c_str());
   int idx = 0;
   int ip = 0;
   while( !f.eof() )
     {
	std::string line;
	getline(f,line);
	if( idx > 4 && idx < 20 )
	  {
	     std::string lineSplit;
	     std::string line = "11111"+line;
	     std::string::iterator it = line.begin();
	     int nChar = 5;
	     char chars[] = {' ','$','p','m','\\'};
	     for(int i=0;i<nChar;i++) line.erase(std::remove(it,line.end(),chars[i]),line.end());
	     std::stringstream data(line);
	     int elem = 0;
	     while(getline(data,lineSplit,'&'))
	       {
		  // pT
		  if( elem == 0 )
		    {
		       std::string line_pt;
		       std::stringstream data_pt(lineSplit);
		       while(getline(data_pt,line_pt,'-'))
			 {
			    if( ptMin[ip] == "" ) ptMin[ip] = line_pt;
			    else ptMax[ip] = line_pt;
			 }		       
		    }
		  // central
		  else if( elem == 1 )
		    central[ip] = lineSplit;
		  // stat
		  else if( elem == 2 )
		    {		       
		       up_stat[ip] = lineSplit;
		       down_stat[ip] = "-"+lineSplit;
		    }		  
		  // ntrk
		  else if( elem == 3 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up_ntrk[ip] = v[0];
		       down_ntrk[ip] = v[1];
		    }		  
		  // njet
		  else if( elem == 4 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up_njet[ip] = v[0];
		       down_njet[ip] = v[1];
		    }		  
		  // mupt
		  else if( elem == 5 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up_mupt[ip] = v[0];
		       down_mupt[ip] = v[1];
		    }		  
		  // jeta
		  else if( elem == 6 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up_jeta[ip] = v[0];
		       down_jeta[ip] = v[1];
		    }		  
		  // pu
		  else if( elem == 7 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up_pu[ip] = v[0];
		       down_pu[ip] = v[1];
		    }		  
		  // gsplit
		  else if( elem == 8 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up_gsplit[ip] = v[0];
		       down_gsplit[ip] = v[1];
		    }		  
		  // bfrag
		  else if( elem == 9 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up_bfrag[ip] = v[0];
		       down_bfrag[ip] = v[1];
		    }		  
		  // dmux
		  else if( elem == 10 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up_dmux[ip] = v[0];
		       down_dmux[ip] = v[1];
		    }		  
		  // cfrag
		  else if( elem == 11 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up_cfrag[ip] = v[0];
		       down_cfrag[ip] = v[1];
		    }		  
		  // ksl
		  else if( elem == 12 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up_ksl[ip] = v[0];
		       down_ksl[ip] = v[1];
		    }		  
		  // ntrkgen
		  else if( elem == 13 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up_ntrkgen[ip] = v[0];
		       down_ntrkgen[ip] = v[1];
		    }		  
		  // jes
		  else if( elem == 14 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up_jes[ip] = v[0];
		       down_jes[ip] = v[1];
		    }		  
		  // jer
		  else if( elem == 15 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up_jer[ip] = v[0];
		       down_jer[ip] = v[1];
		    }		  
		  // cb
		  else if( elem == 16 )
		    {		       
		       up_cb[ip] = lineSplit;
		       down_cb[ip] = "-"+lineSplit;
		    }
		  // add
		  else if( elem == 17 )
		    {		       
		       up_add[ip] = lineSplit;
		       down_add[ip] = "-"+lineSplit;
		    }		  
		  // syst
		  else if( elem == 18 )
		    {		       
		       std::vector<std::string> v = getAsymError(lineSplit);
		       up[ip] = v[0];
		       down[ip] = v[1];
		    }		  
		  
		  elem++;
	       }
	     ip++;
	  }	
	idx++;
     }   
   f.close();
   
   std::string base1 = wp+", lt, ";
   for(int i=0;i<ip;i++)
     {	
	std::string base2 = ", 0, 0.0, 2.4, "+ptMin[i]+", "+ptMax[i]+", 0, 1, ";
	
	std::string oline = base1+"central"+base2+central[i]; fout << oline << std::endl;
	oline = base1+"up"+base2+up[i]; fout << oline << std::endl;
	oline = base1+"down"+base2+down[i]; fout << oline << std::endl;
	oline = base1+"up_ntrk"+base2+up_ntrk[i]; fout << oline << std::endl;
	oline = base1+"down_ntrk"+base2+down_ntrk[i]; fout << oline << std::endl;
	oline = base1+"up_njet"+base2+up_njet[i]; fout << oline << std::endl;
	oline = base1+"down_njet"+base2+down_njet[i]; fout << oline << std::endl;
	oline = base1+"up_mupt"+base2+up_mupt[i]; fout << oline << std::endl;
	oline = base1+"down_mupt"+base2+down_mupt[i]; fout << oline << std::endl;
	oline = base1+"up_jeta"+base2+up_jeta[i]; fout << oline << std::endl;
	oline = base1+"down_jeta"+base2+down_jeta[i]; fout << oline << std::endl;
	oline = base1+"up_pu"+base2+up_pu[i]; fout << oline << std::endl;
	oline = base1+"down_pu"+base2+down_pu[i]; fout << oline << std::endl;
	oline = base1+"up_gsplit"+base2+up_gsplit[i]; fout << oline << std::endl;
	oline = base1+"down_gsplit"+base2+down_gsplit[i]; fout << oline << std::endl;
	oline = base1+"up_bfrag"+base2+up_bfrag[i]; fout << oline << std::endl;
	oline = base1+"down_bfrag"+base2+down_bfrag[i]; fout << oline << std::endl;
	oline = base1+"up_dmux"+base2+up_dmux[i]; fout << oline << std::endl;
	oline = base1+"down_dmux"+base2+down_dmux[i]; fout << oline << std::endl;
	oline = base1+"up_cfrag"+base2+up_cfrag[i]; fout << oline << std::endl;
	oline = base1+"down_cfrag"+base2+down_cfrag[i]; fout << oline << std::endl;
	oline = base1+"up_ksl"+base2+up_ksl[i]; fout << oline << std::endl;
	oline = base1+"down_ksl"+base2+down_ksl[i]; fout << oline << std::endl;
	oline = base1+"up_ntrkgen"+base2+up_ntrkgen[i]; fout << oline << std::endl;
	oline = base1+"down_ntrkgen"+base2+down_ntrkgen[i]; fout << oline << std::endl;
	oline = base1+"up_jes"+base2+up_jes[i]; fout << oline << std::endl;
	oline = base1+"down_jes"+base2+down_jes[i]; fout << oline << std::endl;
	oline = base1+"up_jer"+base2+up_jer[i]; fout << oline << std::endl;
	oline = base1+"down_jer"+base2+down_jer[i]; fout << oline << std::endl;
	oline = base1+"up_cb"+base2+up_cb[i]; fout << oline << std::endl;
	oline = base1+"down_cb"+base2+down_cb[i]; fout << oline << std::endl;
	oline = base1+"up_add"+base2+up_add[i]; fout << oline << std::endl;
	oline = base1+"down_add"+base2+down_add[i]; fout << oline << std::endl;
	oline = base1+"up_stat"+base2+up_stat[i]; fout << oline << std::endl;
	oline = base1+"down_stat"+base2+down_stat[i]; fout << oline << std::endl;
     }   
}

std::vector<std::string> getAsymError(std::string err)
{
   std::vector<std::string> v;
   std::string v1 = ""; std::string v2 = "";
   int len = err.length();
   int sw = 0;
   
   for(int i=0;i<len;i++)
     {
	if( (err[i] == '+' || err[i] == '-') && i > 0 )
	  {
	     sw = 1;
	  }
	if( sw == 0 )
	  {
	     if( err[i] != '+' )
	       v1 += err[i];
	  }		
	if( sw == 1 )
	  {
	     if( err[i] != '+' )
	       v2 += err[i];
	  }	
     }
   
   v.push_back(v1);
   v.push_back(v2);
   
   return v;
}
