void produceSFOFF(std::string wp)
{
   gROOT->SetBatch();

   const int npt = 16;
   double xp[npt+2] = 
     {0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.10,0.12,0.16,0.21,0.26,0.32,0.40,0.50,0.60,0.80,1.00};

   TH1F *hSF = new TH1F("hSF","hSF",npt+1,xp);
   TH1F *hSF_OFF = (TH1F*)hSF->Clone("hSF_OFF");
   TH1F *hSF_LT = (TH1F*)hSF->Clone("hSF_LT");
   TH1F *hEFFMC_LT = (TH1F*)hSF->Clone("hEFFMC_LT");
   TH1F *hEFFDATA_LT = (TH1F*)hSF->Clone("hEFFDATA_LT");
   
   double sf_off[npt];
   double err_off[npt];
   std::string offname = "official/CSVM.txt";
   if( wp == "LOOSE" ) offname = "official/CSVL.txt";
   if( wp == "TIGHT" ) offname = "official/CSVT.txt";
   std::ifstream f_off(offname.c_str());
   for(int i=0;i<npt+2;i++)
     {
	if( i != 17 )
	  {	     
	     f_off >> sf_off[i] >> err_off[i];
	     hSF_OFF->SetBinContent(i+1,sf_off[i]);
	     hSF_OFF->SetBinError(i+1,err_off[i]);
	  }
	else
	  {
	     hSF_OFF->SetBinContent(i+1,0.);
	     hSF_OFF->SetBinError(i+1,0.);
	  }	
     }   
   f_off.close();

   double sf_lt[npt];
   double err_lt[npt];
   double stat_lt[npt];
   double syst_lt[npt];
   std::string ltname = "official/LT_CSVM.txt";
   if( wp == "LOOSE" ) ltname = "official/LT_CSVL.txt";
   if( wp == "TIGHT" ) ltname = "official/LT_CSVT.txt";
   std::ifstream f_lt(ltname.c_str());
   for(int i=0;i<npt+2;i++)
     {
	if( i != 17 )
	  {	     
	     f_lt >> sf_lt[i] >> stat_lt[i] >> syst_lt[i] >> err_lt[i];
	     hSF_LT->SetBinContent(i+1,sf_lt[i]);
	     hSF_LT->SetBinError(i+1,stat_lt[i]);
	  }
	else
	  {
	     hSF_LT->SetBinContent(i+1,0.);
	     hSF_LT->SetBinError(i+1,0.);
	  }	
     }   
   f_lt.close();

   double effMC_lt[npt];
   double effMC_stat_lt[npt];
   double effDATA_lt[npt];
   double effDATA_stat_lt[npt];
   std::string ltname_eff = "official/LT_CSVM_EFF.txt";
   if( wp == "LOOSE" ) ltname_eff = "official/LT_CSVL_EFF.txt";
   if( wp == "TIGHT" ) ltname_eff = "official/LT_CSVT_EFF.txt";
   std::ifstream f_eff_lt(ltname_eff.c_str());
   for(int i=0;i<npt+2;i++)
     {
	if( i != 17 )
	  {	     
	     f_eff_lt >> effDATA_lt[i] >> effDATA_stat_lt[i] >> effMC_lt[i] >> effMC_stat_lt[i];
	     hEFFDATA_LT->SetBinContent(i+1,effDATA_lt[i]);
	     hEFFDATA_LT->SetBinError(i+1,effDATA_stat_lt[i]);
	     hEFFMC_LT->SetBinContent(i+1,effMC_lt[i]);
	     hEFFMC_LT->SetBinError(i+1,effMC_stat_lt[i]);
	  }
	else
	  {
	     hEFFDATA_LT->SetBinContent(i+1,0.);
	     hEFFDATA_LT->SetBinError(i+1,0.);
	     hEFFMC_LT->SetBinContent(i+1,0.);
	     hEFFMC_LT->SetBinError(i+1,0.);
	  }	
     }   
   f_eff_lt.close();

   int nsfp_off = npt*2+1;
   const int np_off = nsfp_off;
   
   double xp_sysTot_lt[np_off];
   double yp_sysTot_lt[np_off];
   for(int k=0;k<npt;k++)
     {
	xp_sysTot_lt[k] = (xp[k+1]-xp[k])/2.0 + xp[k];
	yp_sysTot_lt[k] = sf_lt[k]+err_lt[k];
	yp_sysTot_lt[npt+k] = sf_lt[npt-1-k]-err_lt[npt-1-k];
     }   
   
   for(int k=0;k<npt;k++)
     {
	xp_sysTot_lt[npt+k] = xp_sysTot_lt[npt-k-1];
     }
   
   xp_sysTot_lt[np_off-1] = xp_sysTot_lt[0];
   yp_sysTot_lt[np_off-1] = yp_sysTot_lt[0];

   double xp_sysTot_off[np_off];
   double yp_sysTot_off[np_off];
   for(int k=0;k<npt;k++)
     {
	xp_sysTot_off[k] = (xp[k+1]-xp[k])/2.0 + xp[k];
	yp_sysTot_off[k] = sf_off[k]+err_off[k];
	yp_sysTot_off[npt+k] = sf_off[npt-1-k]-err_off[npt-1-k];
     }   

   for(int k=0;k<npt;k++)
     {
	xp_sysTot_off[npt+k] = xp_sysTot_off[npt-k-1];
     }
   
   xp_sysTot_off[np_off-1] = xp_sysTot_off[0];
   yp_sysTot_off[np_off-1] = yp_sysTot_off[0];
   
   TPolyLine *sysTot_lt = new TPolyLine(np_off,xp_sysTot_lt,yp_sysTot_lt);
   sysTot_lt->SetFillColor(0);
   sysTot_lt->SetLineColor(kRed);
   sysTot_lt->SetLineStyle(2);
   
   TPolyLine *sysTot_off = new TPolyLine(np_off,xp_sysTot_off,yp_sysTot_off);
   sysTot_off->SetFillColor(0);
   sysTot_off->SetLineColor(kRed);
   sysTot_off->SetLineStyle(2);

   double xp_sysTot_effMC_lt[np_off];
   double yp_sysTot_effMC_lt[np_off];
   for(int k=0;k<npt;k++)
     {
	xp_sysTot_effMC_lt[k] = (xp[k+1]-xp[k])/2.0 + xp[k];
	yp_sysTot_effMC_lt[k] = effMC_lt[k]+effMC_stat_lt[k];
	yp_sysTot_effMC_lt[npt+k] = effMC_lt[npt-1-k]-effMC_stat_lt[npt-1-k];
     }   

   for(int k=0;k<npt;k++)
     {
	xp_sysTot_effMC_lt[npt+k] = xp_sysTot_effMC_lt[npt-k-1];
     }
   
   xp_sysTot_effMC_lt[np_off-1] = xp_sysTot_effMC_lt[0];
   yp_sysTot_effMC_lt[np_off-1] = yp_sysTot_effMC_lt[0];
   
   TPolyLine *sysTot_effMC_lt = new TPolyLine(np_off,xp_sysTot_effMC_lt,yp_sysTot_effMC_lt);
   sysTot_effMC_lt->SetFillColor(0);
   sysTot_effMC_lt->SetLineColor(kRed);
   sysTot_effMC_lt->SetLineStyle(2);
   
   double xp_sysTot_effDATA_lt[np_off];
   double yp_sysTot_effDATA_lt[np_off];
   for(int k=0;k<npt;k++)
     {
	xp_sysTot_effDATA_lt[k] = (xp[k+1]-xp[k])/2.0 + xp[k];
	yp_sysTot_effDATA_lt[k] = effDATA_lt[k]+effDATA_stat_lt[k];
	yp_sysTot_effDATA_lt[npt+k] = effDATA_lt[npt-1-k]-effDATA_stat_lt[npt-1-k];
     }   

   for(int k=0;k<npt;k++)
     {
	xp_sysTot_effDATA_lt[npt+k] = xp_sysTot_effDATA_lt[npt-k-1];
     }
   
   xp_sysTot_effDATA_lt[np_off-1] = xp_sysTot_effDATA_lt[0];
   yp_sysTot_effDATA_lt[np_off-1] = yp_sysTot_effDATA_lt[0];
   
   TPolyLine *sysTot_effDATA_lt = new TPolyLine(np_off,xp_sysTot_effDATA_lt,yp_sysTot_effDATA_lt);
   sysTot_effDATA_lt->SetFillColor(0);
   sysTot_effDATA_lt->SetLineColor(kRed);
   sysTot_effDATA_lt->SetLineStyle(2);

   // save to file
   
   std::string fSFname = "results/SF_OFFICIAL_"+wp+".root";
   TFile *fSF = new TFile(fSFname.c_str(),"RECREATE");

   hSF_OFF->Write("OFF_SF");
   hSF_LT->Write("LT_SF");
   
   hEFFMC_LT->Write("LT_EFFMC");
   hEFFDATA_LT->Write("LT_EFFDATA");
   
   sysTot_lt->Write("LT_SFSYS");
   sysTot_off->Write("OFF_SFSYS");
   
   sysTot_effDATA_lt->Write("LT_EFFDATA");
   sysTot_effMC_lt->Write("LT_EFFMC");
   
   fSF->Write();
   fSF->Close();
   
   gApplication->Terminate();
}
