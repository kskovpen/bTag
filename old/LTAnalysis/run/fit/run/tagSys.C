void tagSys()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x common.C");
   gROOT->ProcessLine(".x def.C");
   
   gROOT->ProcessLine(".L addbin.C");

   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   
   gStyle->SetHistTopMargin(0);

   std::string fpathMC = "../../histSYS/MC/data.root";
   
   TFile *fMC = TFile::Open(fpathMC.c_str());

   TLegend *leg = new TLegend(0.65,0.90,0.85,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   const int npt = 17;
   std::string ptname[npt] = {
      "pt20t30",
      "pt30t40",
      "pt40t50",
      "pt50t60",
      "pt60t70",
      "pt70t80",
      "pt80t100",
      "pt100t120",
      "pt120t160",
      "pt160t210",
      "pt210t260",
      "pt260t320",
      "pt320t400",
      "pt400t500",
      "pt500t600",
      "pt600t800",
      "pt800t1000"
   };
   const int nflav = 4;   
   std::string flav[nflav] = {
      "bjet",
      "cjet",
      "ljet",
      "ajet"
   };   
   std::string btagname = "combSvx0p244";
//   std::string btagname = "combSvx0p679";
//   std::string btagname = "combSvx0p898";

   TH1D *h_trk[nflav][npt];
   TH1D *h_trk_untag[nflav][npt];
   TH1D *h_trk_tag[nflav][npt];

   TH1D *h_JP[nflav][npt];
   TH1D *h_JP_untag[nflav][npt];
   TH1D *h_JP_tag[nflav][npt];
   
   for(int ifl=0;ifl<nflav;ifl++)
     {	
	for(int ipt=0;ipt<npt;ipt++)
	  {
	     // ntrk
	     std::string hname_trk = "h_j1_ntrk_"+flav[ifl]+"_"+ptname[ipt]+"_nosel_nosel";
	     std::string hname_trk_tag = "h_j1_ntrk_"+flav[ifl]+"_"+ptname[ipt]+"_nosel_"+btagname;
	     std::string hname_trk_untag = "h_j1_ntrk_"+flav[ifl]+"_"+ptname[ipt]+"_nosel_UNTAGbc";
	     h_trk[ifl][ipt] = (TH1D*)fMC->Get(hname_trk.c_str());
	     h_trk_tag[ifl][ipt] = (TH1D*)fMC->Get(hname_trk_tag.c_str());
	     h_trk_untag[ifl][ipt] = (TH1D*)fMC->Get(hname_trk_untag.c_str());

	     addbin(h_trk[ifl][ipt]);
	     addbin(h_trk_tag[ifl][ipt]);
	     addbin(h_trk_untag[ifl][ipt]);
	     
	     double int_trk = h_trk[ifl][ipt]->Integral();
	     double int_trk_tag = h_trk_tag[ifl][ipt]->Integral();
	     double int_trk_untag = h_trk_untag[ifl][ipt]->Integral();
	     
	     if( int_trk > 0. ) h_trk[ifl][ipt]->Scale(1./int_trk);
	     if( int_trk_tag > 0. ) h_trk_tag[ifl][ipt]->Scale(1./int_trk_tag);
	     if( int_trk_untag > 0. ) h_trk_untag[ifl][ipt]->Scale(1./int_trk_untag);
	     
	     h_trk[ifl][ipt]->Draw("hist");
	     h_trk_tag[ifl][ipt]->Draw("e1p same");
	     leg->AddEntry(h_trk[ifl][ipt],"All jets","l");
	     leg->AddEntry(h_trk_tag[ifl][ipt],"Tagged jets","lp");
	     leg->Draw();
	     h_trk[ifl][ipt]->GetXaxis()->SetTitle("Number of tracks");
	     h_trk[ifl][ipt]->SetMarkerSize(0);
	     h_trk_tag[ifl][ipt]->SetMarkerSize(0.7);
	     h_trk_tag[ifl][ipt]->SetMarkerColor(kRed);
	     h_trk_tag[ifl][ipt]->SetLineColor(kRed);
	     double m1 = h_trk[ifl][ipt]->GetMaximum();
	     double m2 = h_trk_tag[ifl][ipt]->GetMaximum();
	     if( m2 > m1 ) h_trk[ifl][ipt]->SetMaximum(1.2*m2);
	     else h_trk[ifl][ipt]->SetMaximum(1.2*m1);
	     std::string fsave_trk_all_tag = "pics/trk_all_tag_"+flav[ifl]+"_"+ptname[ipt]+".eps";
	     c1->Print(fsave_trk_all_tag.c_str());
	     c1->Clear();
	     leg->Clear();

	     h_trk_untag[ifl][ipt]->Draw("hist");
	     h_trk_tag[ifl][ipt]->Draw("e1p same");
	     leg->AddEntry(h_trk_untag[ifl][ipt],"Untagged jets","l");
	     leg->AddEntry(h_trk_tag[ifl][ipt],"Tagged jets","lp");
	     leg->Draw();
	     h_trk_untag[ifl][ipt]->GetXaxis()->SetTitle("Number of tracks");
	     h_trk_untag[ifl][ipt]->SetMarkerSize(0);
	     double m1 = h_trk_untag[ifl][ipt]->GetMaximum();
	     double m2 = h_trk_tag[ifl][ipt]->GetMaximum();
	     if( m2 > m1 ) h_trk_untag[ifl][ipt]->SetMaximum(1.2*m2);
	     else h_trk_untag[ifl][ipt]->SetMaximum(1.2*m1);
	     std::string fsave_trk_untag_tag = "pics/trk_untag_tag_"+flav[ifl]+"_"+ptname[ipt]+".eps";
	     c1->Print(fsave_trk_untag_tag.c_str());
	     c1->Clear();
	     leg->Clear();

	     // JP
	     std::string hname_JP = "h_j1_JP_"+flav[ifl]+"_"+ptname[ipt]+"_nosel_nosel";
	     std::string hname_JP_tag = "h_j1_JP_"+flav[ifl]+"_"+ptname[ipt]+"_nosel_"+btagname;
	     std::string hname_JP_untag = "h_j1_JP_"+flav[ifl]+"_"+ptname[ipt]+"_nosel_UNTAGbc";
	     h_JP[ifl][ipt] = (TH1D*)fMC->Get(hname_JP.c_str());
	     h_JP_tag[ifl][ipt] = (TH1D*)fMC->Get(hname_JP_tag.c_str());
	     h_JP_untag[ifl][ipt] = (TH1D*)fMC->Get(hname_JP_untag.c_str());

	     addbin(h_JP[ifl][ipt]);
	     addbin(h_JP_tag[ifl][ipt]);
	     addbin(h_JP_untag[ifl][ipt]);
	     
	     double int_JP = h_JP[ifl][ipt]->Integral();
	     double int_JP_tag = h_JP_tag[ifl][ipt]->Integral();
	     double int_JP_untag = h_JP_untag[ifl][ipt]->Integral();
	     
	     if( int_JP > 0. ) h_JP[ifl][ipt]->Scale(1./int_JP);
	     if( int_JP_tag > 0. ) h_JP_tag[ifl][ipt]->Scale(1./int_JP_tag);
	     if( int_JP_untag > 0. ) h_JP_untag[ifl][ipt]->Scale(1./int_JP_untag);
	     
	     h_JP[ifl][ipt]->Draw("hist");
	     h_JP_tag[ifl][ipt]->Draw("e1p same");
	     leg->AddEntry(h_JP[ifl][ipt],"All jets","l");
	     leg->AddEntry(h_JP_tag[ifl][ipt],"Tagged jets","lp");
	     leg->Draw();
	     h_JP[ifl][ipt]->GetXaxis()->SetTitle("Jet probability");
	     h_JP[ifl][ipt]->SetMarkerSize(0);
	     h_JP_tag[ifl][ipt]->SetMarkerSize(0.7);
	     h_JP_tag[ifl][ipt]->SetMarkerColor(kRed);
	     h_JP_tag[ifl][ipt]->SetLineColor(kRed);
	     double m1 = h_JP[ifl][ipt]->GetMaximum();
	     double m2 = h_JP_tag[ifl][ipt]->GetMaximum();
	     if( m2 > m1 ) h_JP[ifl][ipt]->SetMaximum(1.2*m2);
	     else h_JP[ifl][ipt]->SetMaximum(1.2*m1);
	     std::string fsave_JP_all_tag = "pics/JP_all_tag_"+flav[ifl]+"_"+ptname[ipt]+".eps";
	     c1->Print(fsave_JP_all_tag.c_str());
	     c1->Clear();
	     leg->Clear();

	     h_JP_untag[ifl][ipt]->Draw("hist");
	     h_JP_tag[ifl][ipt]->Draw("e1p same");
	     leg->AddEntry(h_JP_untag[ifl][ipt],"Untagged jets","l");
	     leg->AddEntry(h_JP_tag[ifl][ipt],"Tagged jets","lp");
	     leg->Draw();
	     h_JP_untag[ifl][ipt]->GetXaxis()->SetTitle("Jet probability");
	     h_JP_untag[ifl][ipt]->SetMarkerSize(0);
	     double m1 = h_JP_untag[ifl][ipt]->GetMaximum();
	     double m2 = h_JP_tag[ifl][ipt]->GetMaximum();
	     if( m2 > m1 ) h_JP_untag[ifl][ipt]->SetMaximum(1.2*m2);
	     else h_JP_untag[ifl][ipt]->SetMaximum(1.2*m1);
	     std::string fsave_JP_untag_tag = "pics/JP_untag_tag_"+flav[ifl]+"_"+ptname[ipt]+".eps";
	     c1->Print(fsave_JP_untag_tag.c_str());
	     c1->Clear();
	     leg->Clear();
	  }	
     }   

   for(int ipt=0;ipt<npt;ipt++)
     {
	h_trk[0][ipt]->Draw("hist");
	h_trk[1][ipt]->Draw("e1p same");
	h_trk[2][ipt]->Draw("e1p same");
	h_trk[1][ipt]->SetLineColor(kRed);
	h_trk[1][ipt]->SetMarkerColor(kRed);
	h_trk[2][ipt]->SetLineColor(kBlue);
	h_trk[2][ipt]->SetMarkerColor(kBlue);
	leg->AddEntry(h_trk[0][ipt],"b-jets","l");
	leg->AddEntry(h_trk[1][ipt],"c-jets","lp");
	leg->AddEntry(h_trk[2][ipt],"l-jets","lp");
	leg->Draw();
	std::string fsave_trk_all = "pics/trk_all_"+ptname[ipt]+".eps";
	c1->Print(fsave_trk_all.c_str());
	c1->Clear();
	leg->Clear();

	h_JP[0][ipt]->Draw("hist");
	h_JP[1][ipt]->Draw("e1p same");
	h_JP[2][ipt]->Draw("e1p same");
	h_JP[1][ipt]->SetLineColor(kRed);
	h_JP[1][ipt]->SetMarkerColor(kRed);
	h_JP[2][ipt]->SetLineColor(kBlue);
	h_JP[2][ipt]->SetMarkerColor(kBlue);
	leg->AddEntry(h_JP[0][ipt],"b-jets","l");
	leg->AddEntry(h_JP[1][ipt],"c-jets","lp");
	leg->AddEntry(h_JP[2][ipt],"l-jets","lp");
	leg->Draw();
	std::string fsave_JP_all = "pics/JP_all_"+ptname[ipt]+".eps";
	c1->Print(fsave_JP_all.c_str());
	c1->Clear();
	leg->Clear();
     }
   
   gApplication->Terminate();
}
