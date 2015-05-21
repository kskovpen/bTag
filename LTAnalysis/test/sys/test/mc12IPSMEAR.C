TFile *fbatch_MC_J0;
TFile *fbatch_MC_J1;
TFile *fbatch_MC_J2;
TFile *fbatch_MC_J3;
TFile *fbatch_MC_J4;
TFile *fbatch_MC_J5;

TFile *fbatch_MC_J0_IPSMEAR;
TFile *fbatch_MC_J1_IPSMEAR;
TFile *fbatch_MC_J2_IPSMEAR;
TFile *fbatch_MC_J3_IPSMEAR;
TFile *fbatch_MC_J4_IPSMEAR;
TFile *fbatch_MC_J5_IPSMEAR;

std::string toolMC = "plot_PROC_d0v";
std::string fpathMC = "/gcf/atlas/data/JTNtuple_hist/run_"+toolMC+"/";
//std::string var = "d0SignJet1";
std::string var = "d0Sign1";

const int nflav = 4;
std::string flav[nflav] = {"ajet","bjet","cjet","ljet"};
const int npt = 15;
std::string pt[npt] = {
   "nosel",
     "pt20t30",
     "pt30t40",
     "pt40t50",
     "pt50t60",
     "pt60t75",
     "pt75t90",
     "pt90t110",
     "pt110t140",
     "pt140t200",
     "pt200t300",
     "pt300t400",
     "pt400t500",
     "pt500t700",
     "pt700t1000"
};

void mc12IPSMEAR()
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
	for(int j=0;j<npt;j++)
	  {
	     std::string varh = "h_j1_"+var+"_"+flav[i]+"_"+pt[j]+"_nosel_nosel";
	     
	     TH1F *h_MC;
	     TH1F *h_MC_J0;
	     TH1F *h_MC_J1;
	     TH1F *h_MC_J2;
	     TH1F *h_MC_J3;
	     TH1F *h_MC_J4;
	     //	TH1F *h_MC_J5;
	     TH1F *h_MC_IPSMEAR;
	     TH1F *h_MC_J0_IPSMEAR;
	     TH1F *h_MC_J1_IPSMEAR;
	     TH1F *h_MC_J2_IPSMEAR;
	     TH1F *h_MC_J3_IPSMEAR;
	     TH1F *h_MC_J4_IPSMEAR;
	     //	TH1F *h_MC_J5_IPSMEAR;
	     TH1F *h_DATA;
	     
	     std::string fname_J0 = "";
	     std::string fname_J1 = "";
	     std::string fname_J2 = "";
	     std::string fname_J3 = "";
	     std::string fname_J4 = "";
	     //	std::string fname_J5 = "";
	     
	     std::string fname_J0_IPSMEAR = "";
	     std::string fname_J1_IPSMEAR = "";
	     std::string fname_J2_IPSMEAR = "";
	     std::string fname_J3_IPSMEAR = "";
	     std::string fname_J4_IPSMEAR = "";
	     //	std::string fname_J5_IPSMEAR = "";
	     
	     fname_J0 = fpathMC+v_mc_filt[0];
	     fname_J1 = fpathMC+v_mc_filt[1];
	     fname_J2 = fpathMC+v_mc_filt[2];
	     fname_J3 = fpathMC+v_mc_filt[3];
	     fname_J4 = fpathMC+v_mc_filt[4];
	     //	fname_J5 = fpathMC+v_mc_filt[5];
	     
	     fname_J0_IPSMEAR = fpathMC+v_mc_filt_IPSMEAR[0];
	     fname_J1_IPSMEAR = fpathMC+v_mc_filt_IPSMEAR[1];
	     fname_J2_IPSMEAR = fpathMC+v_mc_filt_IPSMEAR[2];
	     fname_J3_IPSMEAR = fpathMC+v_mc_filt_IPSMEAR[3];
	     fname_J4_IPSMEAR = fpathMC+v_mc_filt_IPSMEAR[4];
	     //	fname_J5_IPSMEAR = fpathMC+v_mc_filt_IPSMEAR[5];
	     
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
	     
	     //	fbatch_MC_J5 = TFile::Open(fname_J5.c_str());
	     //	TH1F *hf_J5 = (TH1F*)fbatch_MC_J5->Get(varh.c_str());
	     //	h_MC_J5 = (TH1F*)hf_J5->Clone("h_MC_J5");
	     
	     fbatch_MC_J0_IPSMEAR = TFile::Open(fname_J0_IPSMEAR.c_str());
	     TH1F *hf_J0_IPSMEAR = (TH1F*)fbatch_MC_J0_IPSMEAR->Get(varh.c_str());
	     h_MC_J0_IPSMEAR = (TH1F*)hf_J0_IPSMEAR->Clone("h_MC_J0_IPSMEAR");
	     
	     fbatch_MC_J1_IPSMEAR = TFile::Open(fname_J1_IPSMEAR.c_str());
	     TH1F *hf_J1_IPSMEAR = (TH1F*)fbatch_MC_J1_IPSMEAR->Get(varh.c_str());
	     h_MC_J1_IPSMEAR = (TH1F*)hf_J1_IPSMEAR->Clone("h_MC_J1_IPSMEAR");
	     
	     fbatch_MC_J2_IPSMEAR = TFile::Open(fname_J2_IPSMEAR.c_str());   
	     TH1F *hf_J2_IPSMEAR = (TH1F*)fbatch_MC_J2_IPSMEAR->Get(varh.c_str());
	     h_MC_J2_IPSMEAR = (TH1F*)hf_J2_IPSMEAR->Clone("h_MC_J2_IPSMEAR");
	     
	     fbatch_MC_J3_IPSMEAR = TFile::Open(fname_J3_IPSMEAR.c_str());   
	     TH1F *hf_J3_IPSMEAR = (TH1F*)fbatch_MC_J3_IPSMEAR->Get(varh.c_str());
	     h_MC_J3_IPSMEAR = (TH1F*)hf_J3_IPSMEAR->Clone("h_MC_J3_IPSMEAR");
	     
	     fbatch_MC_J4_IPSMEAR = TFile::Open(fname_J4_IPSMEAR.c_str());
	     TH1F *hf_J4_IPSMEAR = (TH1F*)fbatch_MC_J4_IPSMEAR->Get(varh.c_str());
	     h_MC_J4_IPSMEAR = (TH1F*)hf_J4_IPSMEAR->Clone("h_MC_J4_IPSMEAR");
	     
	     //	fbatch_MC_J5_IPSMEAR = TFile::Open(fname_J5_IPSMEAR.c_str());
	     //	TH1F *hf_J5_IPSMEAR = (TH1F*)fbatch_MC_J5_IPSMEAR->Get(varh.c_str());
	     //	h_MC_J5_IPSMEAR = (TH1F*)hf_J5_IPSMEAR->Clone("h_MC_J5_IPSMEAR");
	     
	     TCanvas *c1 = new TCanvas();
	     
	     h_MC = (TH1F*)h_MC_J0->Clone("h_MC");
	     h_MC->Add(h_MC_J1);
	     h_MC->Add(h_MC_J2);
	     h_MC->Add(h_MC_J3);
	     h_MC->Add(h_MC_J4);
	     //	h_MC->Add(h_MC_J5);
	     
	     h_MC_IPSMEAR = (TH1F*)h_MC_J0_IPSMEAR->Clone("h_MC_IPSMEAR");
	     h_MC_IPSMEAR->Add(h_MC_J1_IPSMEAR);
	     h_MC_IPSMEAR->Add(h_MC_J2_IPSMEAR);
	     h_MC_IPSMEAR->Add(h_MC_J3_IPSMEAR);
	     h_MC_IPSMEAR->Add(h_MC_J4_IPSMEAR);
	     //	h_MC_IPSMEAR->Add(h_MC_J5_IPSMEAR);
	     
	     if( h_MC->Integral() > 0. ) h_MC->Scale(1./h_MC->Integral());
	     
	     if( h_MC_IPSMEAR->Integral() > 0. ) h_MC_IPSMEAR->Scale(1./h_MC_IPSMEAR->Integral());
	     
	     TH1F *h_MC_rebin = (TH1F*)h_MC->Rebin(1,"");
	     
	     TH1F *h_MC_rebin_IPSMEAR = (TH1F*)h_MC_IPSMEAR->Rebin(1,"");
	     
	     TLegend *leg = new TLegend(0.65,0.90,0.88,0.75);                                                     
	     leg->SetFillColor(253);                                                                              
	     leg->SetBorderSize(0);
	     
	     h_MC_rebin->SetLineColor(kBlack);
	     h_MC_rebin->SetMarkerColor(kBlack);
	     h_MC_rebin->SetMarkerSize(0.9);
	     h_MC_rebin->SetMarkerStyle(20);
	     
	     h_MC_rebin_IPSMEAR->SetLineColor(kRed);
	     h_MC_rebin_IPSMEAR->SetMarkerColor(kRed);
	     h_MC_rebin_IPSMEAR->SetMarkerSize(0.9);
	     h_MC_rebin_IPSMEAR->SetMarkerStyle(25);
	     
	     h_MC_rebin->Draw("hist e1");
	     h_MC_rebin_IPSMEAR->Draw("hist e1 same");
	     
//	     h_MC_rebin->GetXaxis()->SetTitle("S_{d_{0}}(t_{1})");
	     h_MC_rebin->GetXaxis()->SetTitle("d_{0}(t_{1})");
	     
	     leg->AddEntry(h_MC_rebin,"Default","lp");
	     leg->AddEntry(h_MC_rebin_IPSMEAR,"IP smeared","lp");
	     leg->Draw();
	     std::string fsave = "pics/mc12IPSMEAR_"+flav[i]+"_"+pt[j]+".eps";
	     c1->Print(fsave.c_str());
	  }
     }   
   
   gApplication->Terminate();
}

