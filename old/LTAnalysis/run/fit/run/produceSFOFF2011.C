void produceSFOFF2011(std::string wp,std::string btag)
{
   gROOT->SetBatch();

   const int npt = 15;
   double xp[npt+1] =
     {0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.10,0.12,0.16,0.21,0.26,0.32,0.40,0.50,0.67};

   TH1F *hSF = new TH1F("hSF","hSF",npt,xp);
   TH1F *hSF_OFF = (TH1F*)hSF->Clone("hSF_OFF");
   TH1F *hEFFMC_OFF = (TH1F*)hSF->Clone("hEFFMC_OFF");
   TH1F *hEFFDATA_OFF = (TH1F*)hSF->Clone("hEFFDATA_OFF");
   
   double sf_off[npt];
   double stat_off[npt];
   double sys_off[npt];
   double err_off[npt];
   std::string offname = "official/LT_CSVM_2011.txt";
   if( wp == "LOOSE" ) offname = "official/LT_CSVL_2011.txt";
   if( wp == "TIGHT" ) offname = "official/LT_CSVT_2011.txt";
   if( btag == "TCHP" )
     {
	if( wp == "MEDIUM" ) offname = "official/LT_TCHPM_2011.txt";
	if( wp == "TIGHT" ) offname = "official/LT_TCHPT_2011.txt";
     }   
   std::ifstream f_off(offname.c_str());
   for(int i=0;i<npt+1;i++)
     {
	f_off >> sf_off[i] >> stat_off[i] >> sys_off[i] >> err_off[i];
	hSF_OFF->SetBinContent(i+1,sf_off[i]);
	hSF_OFF->SetBinError(i+1,err_off[i]);
     }   
   f_off.close();

   double effDATA_off[npt];
   double effDATA_stat_off[npt];
   double effMC_off[npt];
   double effMC_stat_off[npt];
   std::string ltname_eff = "official/LT_CSVM_EFF_2011.txt";
   if( wp == "LOOSE" ) ltname_eff = "official/LT_CSVL_EFF_2011.txt";
   if( wp == "TIGHT" ) ltname_eff = "official/LT_CSVT_EFF_2011.txt";
   std::ifstream f_eff_off(ltname_eff.c_str());
   for(int i=0;i<npt+1;i++)
     {
	f_eff_off >> effDATA_off[i] >> effDATA_stat_off[i] >> effMC_off[i] >> effMC_stat_off[i];
	hEFFDATA_OFF->SetBinContent(i+1,effDATA_off[i]);
	hEFFDATA_OFF->SetBinError(i+1,effDATA_stat_off[i]);
	hEFFMC_OFF->SetBinContent(i+1,effMC_off[i]);
	hEFFMC_OFF->SetBinError(i+1,effMC_stat_off[i]);
     }   
   f_eff_off.close();

   int nsfp_off = npt*2+1;
   const int np_off = nsfp_off;

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
   
   TPolyLine *sysTot_off = new TPolyLine(np_off,xp_sysTot_off,yp_sysTot_off);
   sysTot_off->SetFillColor(0);
   sysTot_off->SetLineColor(kRed);
   sysTot_off->SetLineStyle(2);

   double xp_sysTot_effMC_off[np_off];
   double yp_sysTot_effMC_off[np_off];
   for(int k=0;k<npt;k++)
     {
	xp_sysTot_effMC_off[k] = (xp[k+1]-xp[k])/2.0 + xp[k];
	yp_sysTot_effMC_off[k] = effMC_off[k]+effMC_stat_off[k];
	yp_sysTot_effMC_off[npt+k] = effMC_off[npt-1-k]-effMC_stat_off[npt-1-k];
     }   

   for(int k=0;k<npt;k++)
     {
	xp_sysTot_effMC_off[npt+k] = xp_sysTot_effMC_off[npt-k-1];
     }
   
   xp_sysTot_effMC_off[np_off-1] = xp_sysTot_effMC_off[0];
   yp_sysTot_effMC_off[np_off-1] = yp_sysTot_effMC_off[0];
   
   TPolyLine *sysTot_effMC_off = new TPolyLine(np_off,xp_sysTot_effMC_off,yp_sysTot_effMC_off);
   sysTot_effMC_off->SetFillColor(0);
   sysTot_effMC_off->SetLineColor(kRed);
   sysTot_effMC_off->SetLineStyle(2);
   
   double xp_sysTot_effDATA_off[np_off];
   double yp_sysTot_effDATA_off[np_off];
   for(int k=0;k<npt;k++)
     {
	xp_sysTot_effDATA_off[k] = (xp[k+1]-xp[k])/2.0 + xp[k];
	yp_sysTot_effDATA_off[k] = effDATA_off[k]+effDATA_stat_off[k];
	yp_sysTot_effDATA_off[npt+k] = effDATA_off[npt-1-k]-effDATA_stat_off[npt-1-k];
     }   

   for(int k=0;k<npt;k++)
     {
	xp_sysTot_effDATA_off[npt+k] = xp_sysTot_effDATA_off[npt-k-1];
     }
   
   xp_sysTot_effDATA_off[np_off-1] = xp_sysTot_effDATA_off[0];
   yp_sysTot_effDATA_off[np_off-1] = yp_sysTot_effDATA_off[0];
   
   TPolyLine *sysTot_effDATA_off = new TPolyLine(np_off,xp_sysTot_effDATA_off,yp_sysTot_effDATA_off);
   sysTot_effDATA_off->SetFillColor(0);
   sysTot_effDATA_off->SetLineColor(kRed);
   sysTot_effDATA_off->SetLineStyle(2);

   // save to file
   
   std::string fSFname = "results/SF_OFFICIAL2011_"+wp+"_"+btag+".root";
   TFile *fSF = new TFile(fSFname.c_str(),"RECREATE");

   hSF_OFF->Write("OFF_SF");
   
   hEFFMC_OFF->Write("OFF_EFFMC");
   hEFFDATA_OFF->Write("OFF_EFFDATA");
   
   sysTot_off->Write("OFF_SFSYS");
   
   sysTot_effDATA_off->Write("OFF_EFFSYSDATA");
   sysTot_effMC_off->Write("OFF_EFFSYSMC");
   
   fSF->Write();
   fSF->Close();
   
   gApplication->Terminate();
}
