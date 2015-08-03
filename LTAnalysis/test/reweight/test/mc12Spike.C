TFile *fbatch_MC_J0;
TFile *fbatch_MC_J1;
TFile *fbatch_MC_J2;
TFile *fbatch_MC_J3;
TFile *fbatch_MC_J4;
TFile *fbatch_MC_J5;

std::string toolMC = "plot_PROC_v2";
std::string fpathMC = "/gcf/atlas/data/JTNtuple_hist/run_"+toolMC+"/";

const int nflav = 4;
std::string flav[nflav] = {"ajet","bjet","cjet","ljet"};
const int nfilt = 1;
std::string filt[nfilt] = {"filt"};

void mc12Spike()
{   
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine("#include <string>");
   gROOT->ProcessLine("#include <TH1F.h>");
   
   gROOT->ProcessLine(".x common.C");
   gROOT->ProcessLine(".x def.C");

   for(int i=0;i<nflav;i++)
     {	   
	for(int j=0;j<nfilt;j++)
	  {	     
	     std::string varh = "h_j1_pt_"+flav[i]+"_nosel_nosel_nosel";
	     
	     TH1F *h_MC_J0;
	     TH1F *h_MC_J1;
	     TH1F *h_MC_J2;
	     TH1F *h_MC_J3;
	     TH1F *h_MC_J4;
	     TH1F *h_MC_J5;
	     TH1F *h_DATA;
	     
	     std::string fname_J0 = "";
	     std::string fname_J1 = "";
	     std::string fname_J2 = "";
	     std::string fname_J3 = "";
	     std::string fname_J4 = "";
	     std::string fname_J5 = "";
	     
	     if( j != 0 )
	       {	     	
		  fname_J0 = fpathMC+v_mc_unfilt[0];
		  fname_J1 = fpathMC+v_mc_unfilt[1];
		  fname_J2 = fpathMC+v_mc_unfilt[2];
		  fname_J3 = fpathMC+v_mc_unfilt[3];
		  fname_J4 = fpathMC+v_mc_unfilt[4];
		  fname_J5 = fpathMC+v_mc_unfilt[5];
	       }
	     else
	       {
		  fname_J0 = fpathMC+v_mc_filt[0];
		  fname_J1 = fpathMC+v_mc_filt[1];
		  fname_J2 = fpathMC+v_mc_filt[2];
		  fname_J3 = fpathMC+v_mc_filt[3];
		  fname_J4 = fpathMC+v_mc_filt[4];
		  fname_J5 = fpathMC+v_mc_filt[5];
	       }	
	     
	     fbatch_MC_J0 = TFile::Open(fname_J0.c_str());   
	     TH1F *hf_J0 = (TH1F*)fbatch_MC_J0->Get(varh.c_str());
	     h_MC_J0 = (TH1F*)hf_J0->Clone("h_MC_J0");
	     
	     fbatch_MC_J1 = TFile::Open(fname_J1.c_str());   
	     TH1F *hf_J1 = (TH1F*)fbatch_MC_J1->Get(varh.c_str());
	     h_MC_J1 = (TH1F*)hf_J1->Clone("h_MC_J1");
	     
	     fbatch_MC_J2 = TFile::Open(fname_J2.c_str());   
	     TH1F *hf_J2 = (TH1F*)fbatch_MC_J2->Get(varh.c_str());
	     h_MC_J2 = (TH1F*)hf_J2->Clone("h_MC_J2");
	     
	     fbatch_MC_J3 = TFile::Open(fname_J3.c_str());   
	     TH1F *hf_J3 = (TH1F*)fbatch_MC_J3->Get(varh.c_str());
	     h_MC_J3 = (TH1F*)hf_J3->Clone("h_MC_J3");

	     fbatch_MC_J4 = TFile::Open(fname_J4.c_str());   
	     TH1F *hf_J4 = (TH1F*)fbatch_MC_J4->Get(varh.c_str());
	     h_MC_J4 = (TH1F*)hf_J4->Clone("h_MC_J4");

	     fbatch_MC_J5 = TFile::Open(fname_J5.c_str());
	     TH1F *hf_J5 = (TH1F*)fbatch_MC_J5->Get(varh.c_str());
	     h_MC_J5 = (TH1F*)hf_J5->Clone("h_MC_J5");
	     
	     TCanvas *c1 = new TCanvas();
	     
//	if( h_MC_J0->Integral() > 0. ) h_MC_J0->Scale(1./h_MC_J0->Integral());
//	if( h_MC_J1->Integral() > 0. ) h_MC_J1->Scale(1./h_MC_J1->Integral());
//	if( h_MC_J2->Integral() > 0. ) h_MC_J2->Scale(1./h_MC_J2->Integral());
//	if( h_MC_J3->Integral() > 0. ) h_MC_J3->Scale(1./h_MC_J3->Integral());
	
//	     TH1F *h_MC_J0_rebin = (TH1F*)h_MC_J0->Rebin(4,"");
//	     TH1F *h_MC_J1_rebin = (TH1F*)h_MC_J1->Rebin(4,"");
//	     TH1F *h_MC_J2_rebin = (TH1F*)h_MC_J2->Rebin(4,"");
//	     TH1F *h_MC_J3_rebin = (TH1F*)h_MC_J3->Rebin(4,"");
//	     TH1F *h_MC_J4_rebin = (TH1F*)h_MC_J4->Rebin(4,"");
//	     TH1F *h_MC_J5_rebin = (TH1F*)h_MC_J5->Rebin(4,"");

	     TH1F *h_MC_J0_rebin = (TH1F*)h_MC_J0->Rebin(1,"");
	     TH1F *h_MC_J1_rebin = (TH1F*)h_MC_J1->Rebin(1,"");
	     TH1F *h_MC_J2_rebin = (TH1F*)h_MC_J2->Rebin(1,"");
	     TH1F *h_MC_J3_rebin = (TH1F*)h_MC_J3->Rebin(1,"");
	     TH1F *h_MC_J4_rebin = (TH1F*)h_MC_J4->Rebin(1,"");
	     TH1F *h_MC_J5_rebin = (TH1F*)h_MC_J5->Rebin(1,"");
	     
	     double ymax = h_MC_J0_rebin->GetMaximum();
	     if( h_MC_J1_rebin->GetMaximum() > ymax ) ymax = h_MC_J1_rebin->GetMaximum();
	     if( h_MC_J2_rebin->GetMaximum() > ymax ) ymax = h_MC_J2_rebin->GetMaximum();
	     if( h_MC_J3_rebin->GetMaximum() > ymax ) ymax = h_MC_J3_rebin->GetMaximum();
	     if( h_MC_J4_rebin->GetMaximum() > ymax ) ymax = h_MC_J4_rebin->GetMaximum();
	     if( h_MC_J5_rebin->GetMaximum() > ymax ) ymax = h_MC_J5_rebin->GetMaximum();
	     ymax *= 1.2;
	     
	     h_MC_J5_rebin->SetMaximum(ymax);
	     h_MC_J5_rebin->GetXaxis()->SetRangeUser(0.018,2.0);
	     
	     TLegend *leg = new TLegend(0.65,0.90,0.88,0.75);                                                     
	     leg->SetFillColor(253);                                                                              
	     leg->SetBorderSize(0);
	     
	     h_MC_J0_rebin->SetLineColor(kMagenta);
	     h_MC_J1_rebin->SetLineColor(kYellow);
	     h_MC_J2_rebin->SetLineColor(kRed);
	     h_MC_J3_rebin->SetLineColor(kBlue);
	     h_MC_J4_rebin->SetLineColor(kGreen);
	     h_MC_J5_rebin->SetLineColor(kOrange);
	     
	     h_MC_J0_rebin->SetMarkerColor(kMagenta);
	     h_MC_J1_rebin->SetMarkerColor(kYellow);
	     h_MC_J2_rebin->SetMarkerColor(kRed);
	     h_MC_J3_rebin->SetMarkerColor(kBlue);
	     h_MC_J4_rebin->SetMarkerColor(kGreen);
	     h_MC_J5_rebin->SetMarkerColor(kOrange);
	     
	     h_MC_J0_rebin->SetMarkerSize(0.7);
	     h_MC_J1_rebin->SetMarkerSize(0.7);
	     h_MC_J2_rebin->SetMarkerSize(0.7);
	     h_MC_J3_rebin->SetMarkerSize(0.7);
	     h_MC_J4_rebin->SetMarkerSize(0.7);
	     h_MC_J5_rebin->SetMarkerSize(0.7);
	     
	     h_MC_J0_rebin->SetMarkerStyle(20);
	     h_MC_J1_rebin->SetMarkerStyle(21);
	     h_MC_J2_rebin->SetMarkerStyle(22);
	     h_MC_J3_rebin->SetMarkerStyle(23);
	     h_MC_J4_rebin->SetMarkerStyle(24);
	     h_MC_J5_rebin->SetMarkerStyle(25);

	     TH1F *h_MC_JX_rebin = (TH1F*)h_MC_J5_rebin->Clone("h_MC_JX_rebin");

	     h_MC_JX_rebin->SetLineColor(kBlack);
	     h_MC_JX_rebin->SetMarkerColor(kBlack);
	     h_MC_JX_rebin->SetMarkerSize(0.7);
	     h_MC_JX_rebin->SetMarkerStyle(21);
	     
	     h_MC_JX_rebin->Add(h_MC_J0_rebin);
	     h_MC_JX_rebin->Add(h_MC_J1_rebin);
	     h_MC_JX_rebin->Add(h_MC_J2_rebin);
	     h_MC_JX_rebin->Add(h_MC_J3_rebin);
	     h_MC_JX_rebin->Add(h_MC_J4_rebin);
	     
	     h_MC_JX_rebin->Draw("hist e1");
	     h_MC_J5_rebin->Draw("hist e1 same");
	     h_MC_J0_rebin->Draw("hist e1 same");
	     h_MC_J1_rebin->Draw("hist e1 same");
	     h_MC_J2_rebin->Draw("hist e1 same");
	     h_MC_J3_rebin->Draw("hist e1 same");
	     h_MC_J4_rebin->Draw("hist e1 same");
	     
	     h_MC_JX_rebin->GetXaxis()->SetTitle("P_{T} [TeV]");
	     
	     leg->AddEntry(h_MC_JX_rebin,"Total","f");
	     leg->AddEntry(h_MC_J0,"J0","f");
	     leg->AddEntry(h_MC_J1,"J1","f");
	     leg->AddEntry(h_MC_J2,"J2","f");
	     leg->AddEntry(h_MC_J3,"J3","f");
	     leg->AddEntry(h_MC_J4,"J4","f");
	     leg->AddEntry(h_MC_J5,"J5","f");
	     leg->Draw();
	     c1->SetLogy(1);
//	     c1->SetLogx(1);
	     std::string fsave = "pics/mc12Spike_"+flav[i]+"_"+filt[j]+".eps";
	     c1->Print(fsave.c_str());
	     
	     h_MC_JX_rebin->GetXaxis()->SetRangeUser(0.015,0.050);
	     //	h_MC_J2_rebin->SetMaximum(h_MC_J1_rebin->GetMaximum()*1.2);
	     //	h_MC_J2_rebin->SetMinimum(0.00000001);
	     fsave = "pics/mc12Spike_"+flav[i]+"_"+filt[j]+"_zoom1.eps";
	     c1->Print(fsave.c_str());
	     
	     h_MC_JX_rebin->GetXaxis()->SetRangeUser(0.05,0.15);
	     //	h_MC_J2_rebin->SetMaximum(h_MC_J1_rebin->GetMaximum()*1.2);
	     //	h_MC_J2_rebin->SetMinimum(0.00000001);
	     fsave = "pics/mc12Spike_"+flav[i]+"_"+filt[j]+"_zoom2.eps";
	     c1->Print(fsave.c_str());
	
	     h_MC_JX_rebin->GetXaxis()->SetRangeUser(0.15,0.30);
	     //	h_MC_J2_rebin->SetMaximum(h_MC_J2_rebin->GetMaximum()*1.2);
	     //	h_MC_J2_rebin->SetMinimum(0.00000001);
	     fsave = "pics/mc12Spike_"+flav[i]+"_"+filt[j]+"_zoom3.eps";
	     c1->Print(fsave.c_str());
	  }	
     }
   
   gApplication->Terminate();
}

