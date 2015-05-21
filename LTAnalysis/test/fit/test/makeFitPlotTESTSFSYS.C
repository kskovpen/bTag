void makeFitPlotTESTSFSYS()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x def.C");
   gROOT->ProcessLine(".x common.C");

   const int nbTot = 16;
   bool showOnlyStat = 0;
   bool showOnlySys = 0;
   bool symSyst = 0;
   bool drawMinuitErr = 0;
   int drawOfficial = 1;
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);

   TFile *fsfNom;
   TH1D *hsfNom;
   TH1D *h_eff1DATA;
   TH1D *h_eff1MC;

   TFile *fparNom_before;
   TH1D *hparNom_before_p1;
   TH1D *hparNom_before_p2;
   TH1D *hparNom_before_p3;

   TFile *fparNom_after;
   TH1D *hparNom_after_p1;
   TH1D *hparNom_after_p2;
   TH1D *hparNom_after_p3;

   std::string fname = "results/fit_EFF_beauty_ALL.root";
   fsfNom = TFile::Open(fname.c_str());
   hsfNom = (TH1D*)fsfNom->Get("h1c");
   h_eff1DATA = (TH1D*)fsfNom->Get("h_eff1DATA");
   h_eff1MC = (TH1D*)fsfNom->Get("h_eff1MC");

   fname = "results/fit_FIT123_beforeBTAG.root";
   fparNom_before = TFile::Open(fname.c_str());
   hparNom_before_p1 = (TH1D*)fparNom_before->Get("h_p1f1");
   hparNom_before_p2 = (TH1D*)fparNom_before->Get("h_p2f1");
   hparNom_before_p3 = (TH1D*)fparNom_before->Get("h_p3f1");

   fname = "results/fit_FIT123_afterBTAG.root";
   fparNom_after = TFile::Open(fname.c_str());
   hparNom_after_p1 = (TH1D*)fparNom_after->Get("h_p1f1");
   hparNom_after_p2 = (TH1D*)fparNom_after->Get("h_p2f1");
   hparNom_after_p3 = (TH1D*)fparNom_after->Get("h_p3f1");
   
   const int npt = 16;

   double cb[npt];
//   std::string cbname = "../../cb_nosel.txt";
   std::string cbname = "/opt/sbg/cms/ui5_data1/kskovpen/bTag/CMSSW_5_3_11/src/MistagAna/macro/cb.txt";
   std::ifstream f_cb(cbname.c_str());
   for(int i=0;i<npt;i++)
     {
	int ib;
	f_cb >> ib >> cb[i];
     }   
   f_cb.close();   
   
   double sf_off[npt];
   double err_off[npt];
   std::string offname = "official/CSVL.txt";
   std::ifstream f_off(offname.c_str());
   for(int i=0;i<npt;i++)
     {
	f_off >> sf_off[i] >> err_off[i];
     }   
   f_off.close();

   double sf_lt[npt];
   double err_lt[npt];
   double stat_lt[npt];
   double syst_lt[npt];
   std::string ltname = "official/LT_CSVL.txt";
   std::ifstream f_lt(ltname.c_str());
   for(int i=0;i<npt;i++)
     {
	f_lt >> sf_lt[i] >> stat_lt[i] >> syst_lt[i] >> err_lt[i];
     }   
   f_lt.close();

   double effDATA_lt[npt];
   double effDATAstat_lt[npt];
   double effMC_lt[npt];
   double effMCstat_lt[npt];
   std::string ltname_eff = "official/LT_CSVL_EFF.txt";
   std::ifstream f_eff_lt(ltname_eff.c_str());
   for(int i=0;i<npt;i++)
     {
	f_eff_lt >> effDATA_lt[i] >> effDATAstat_lt[i] >> effMC_lt[i] >> effMCstat_lt[i];
     }   
   f_eff_lt.close();
   
   TH1D *sf_nom = (TH1D*)hsfNom->Clone("sf_nom");
   TH1D *p1_before_nom = (TH1D*)hparNom_before_p1->Clone("p1_before_nom");
   TH1D *p2_before_nom = (TH1D*)hparNom_before_p2->Clone("p2_before_nom");
   TH1D *p3_before_nom = (TH1D*)hparNom_before_p3->Clone("p3_before_nom");
   TH1D *p1_after_nom = (TH1D*)hparNom_after_p1->Clone("p1_after_nom");
   TH1D *p2_after_nom = (TH1D*)hparNom_after_p2->Clone("p2_after_nom");
   TH1D *p3_after_nom = (TH1D*)hparNom_after_p3->Clone("p3_after_nom");
   
   int nbins0 = sf_nom->GetXaxis()->GetNbins();
   nbins0 = (nbTot < nbins0) ? nbTot : nbins0;
   const int nbins = nbins0;
   
   int nsfp = nbins*2+1;
   const int np = nsfp;
   
   // Draw
   
   hsfNom->SetMarkerSize(0.8);
   if( nbTot <= 16 ) {hsfNom->SetBinContent(17,0.);hsfNom->SetBinError(17,0.);}
   
   hsfNom->Draw("e1p");
   hsfNom->GetYaxis()->SetRangeUser(0.65,1.25);
   
   TH1D *hsfoff = (TH1D*)hsfNom->Clone("hsfoff");
   hsfoff->Reset();
   TH1D *hsflt = (TH1D*)hsfNom->Clone("hsflt");
   hsflt->Reset();
   for(int i=0;i<npt;i++)
     {
	hsfoff->SetBinContent(i+1,sf_off[i]);
	hsfoff->SetBinError(i+1,err_off[i]);

	hsflt->SetBinContent(i+1,sf_lt[i]);
	hsflt->SetBinError(i+1,err_lt[i]);
     }   

   double xp_sysTot_lt[np];
   double yp_sysTot_lt[np];
   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_lt[k] = sf_nom->GetBinWidth(k+1)/2.0 + sf_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_lt[k] = sf_lt[k]+err_lt[k];
	yp_sysTot_lt[nbins+k] = sf_lt[nbins-1-k]-err_lt[nbins-1-k];
     }   
   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_lt[nbins+k] = xp_sysTot_lt[nbins-k-1];
     }
   
   xp_sysTot_lt[np-1] = xp_sysTot_lt[0];
   yp_sysTot_lt[np-1] = yp_sysTot_lt[0];

   double xp_sysTot_off[np];
   double yp_sysTot_off[np];
   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_off[k] = sf_nom->GetBinWidth(k+1)/2.0 + sf_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_off[k] = sf_off[k]+err_off[k];
	yp_sysTot_off[nbins+k] = sf_off[nbins-1-k]-err_off[nbins-1-k];
     }   
   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_off[nbins+k] = xp_sysTot_off[nbins-k-1];
     }
   
   xp_sysTot_off[np-1] = xp_sysTot_off[0];
   yp_sysTot_off[np-1] = yp_sysTot_off[0];

   // effDATA
   double xp_effDATA_lt[np];
   double yp_effDATA_lt[np];
   for(int k=0;k<nbins;k++)
     {
	xp_effDATA_lt[k] = h_eff1DATA->GetBinWidth(k+1)/2.0 + h_eff1DATA->GetXaxis()->GetBinLowEdge(k+1);
	yp_effDATA_lt[k] = effDATA_lt[k]+effDATAstat_lt[k];
	yp_effDATA_lt[nbins+k] = effDATA_lt[nbins-1-k]-effDATAstat_lt[nbins-1-k];
     }   
   for(int k=0;k<nbins;k++)
     {
	xp_effDATA_lt[nbins+k] = xp_effDATA_lt[nbins-k-1];
     }
   
   xp_effDATA_lt[np-1] = xp_effDATA_lt[0];
   yp_effDATA_lt[np-1] = yp_effDATA_lt[0];

   // effMC
   double xp_effMC_lt[np];
   double yp_effMC_lt[np];
   for(int k=0;k<nbins;k++)
     {
	xp_effMC_lt[k] = h_eff1MC->GetBinWidth(k+1)/2.0 + h_eff1MC->GetXaxis()->GetBinLowEdge(k+1);
	yp_effMC_lt[k] = effMC_lt[k]+effMCstat_lt[k];
	yp_effMC_lt[nbins+k] = effMC_lt[nbins-1-k]-effMCstat_lt[nbins-1-k];
     }   
   for(int k=0;k<nbins;k++)
     {
	xp_effMC_lt[nbins+k] = xp_effMC_lt[nbins-k-1];
     }
   
   xp_effMC_lt[np-1] = xp_effMC_lt[0];
   yp_effMC_lt[np-1] = yp_effMC_lt[0];
   
   if( drawOfficial == 1 )
     {	
	TPolyLine *sysTot_lt = new TPolyLine(np,xp_sysTot_lt,yp_sysTot_lt);
	sysTot_lt->SetFillColor(0);
	sysTot_lt->SetLineColor(kRed);
	sysTot_lt->SetLineStyle(2);
	sysTot_lt->Draw("lSAME");
	
	hsflt->Draw("p same");
     }   
   else if( drawOfficial == 2 )
     {	
	TPolyLine *sysTot_off = new TPolyLine(np,xp_sysTot_off,yp_sysTot_off);
	sysTot_off->SetFillColor(0);
	sysTot_off->SetLineColor(kRed);
	sysTot_off->SetLineStyle(2);
	sysTot_off->Draw("lSAME");
	
	hsfoff->Draw("p same");
     }   

   hsfNom->Draw("e1p same");

   if( drawOfficial == 1 )
     {	
	hsflt->SetMarkerStyle(22);
	hsflt->SetMarkerColor(kRed);
	hsflt->SetLineColor(kRed);
     }   
   else if( drawOfficial == 2 )
     {	
	hsfoff->SetMarkerStyle(22);
	hsfoff->SetMarkerColor(kRed);
	hsfoff->SetLineColor(kRed);
     }

//   TLegend *leg = new TLegend(0.55,0.90,0.90,0.65);
   TLegend *leg = new TLegend(0.25,0.90,0.55,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   leg->AddEntry(hsfNom,"SF","p");

   if( drawOfficial == 1 )
     {	
	leg->AddEntry(hsflt,"SF (LT EPS13)","p");
	leg->AddEntry(sysTot_lt,"stat #oplus syst (LT EPS13)","f");
     }   
   else if( drawOfficial == 2 )
     {	
	leg->AddEntry(hsfoff,"SF (EPS13)","p");
	leg->AddEntry(sysTot_off,"stat #oplus syst (EPS13)","f");
     }   
   
   leg->Draw();

   c1->SetLogx(1);
   
   std::string fsave = "pics/SFSYS.eps";
   c1->Print(fsave.c_str());
   c1->Clear();

   // effDATA
   for(int i=0;i<npt;i++)
     {
	double v = h_eff1DATA->GetBinContent(i+1);
	double e = h_eff1DATA->GetBinError(i+1);
	h_eff1DATA->SetBinContent(i+1,v*cb[i]);
	h_eff1DATA->SetBinError(i+1,e*cb[i]);
     }  
   h_eff1DATA->Draw("p");
   h_eff1DATA->GetYaxis()->SetRangeUser(0.,1.2);
   if( drawOfficial == 1 )
     {	
	TPolyLine *sysTot_lt = new TPolyLine(np,xp_effDATA_lt,yp_effDATA_lt);
	sysTot_lt->SetFillColor(0);
	sysTot_lt->SetLineColor(kRed);
	sysTot_lt->SetLineStyle(2);
	sysTot_lt->Draw("SAMEl");
	
	h_eff1DATA->Draw("p same");
     }
   
   c1->SetLogx(1);
   
   fsave = "pics/EFFDATA.eps";
   c1->Print(fsave.c_str());
   c1->Clear();

   // effMC
   for(int i=0;i<npt;i++)
     {
	double v = h_eff1MC->GetBinContent(i+1);
	double e = h_eff1MC->GetBinError(i+1);	
	h_eff1MC->SetBinContent(i+1,v*cb[i]);
	// FIXME
	h_eff1MC->SetBinError(i+1,e*cb[i]);
     }  
   h_eff1MC->Draw("p");
   h_eff1MC->GetYaxis()->SetRangeUser(0.,1.2);
   if( drawOfficial == 1 )
     {	
	TPolyLine *sysTot_lt = new TPolyLine(np,xp_effMC_lt,yp_effMC_lt);
	sysTot_lt->SetFillColor(0);
	sysTot_lt->SetLineColor(kRed);
	sysTot_lt->SetLineStyle(2);
	sysTot_lt->Draw("SAMEl");
	
	h_eff1MC->Draw("p same");
     }
   
   c1->SetLogx(1);
   
   fsave = "pics/EFFMC.eps";
   c1->Print(fsave.c_str());
   c1->Clear();
   
   gApplication->Terminate();
}
