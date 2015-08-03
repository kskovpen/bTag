TFile *fbatch_MCfilt[100];
TFile *fbatch_MCunfilt[100];

int nbm1d = 4;

std::string toolMCfilt = "plot_pA_v1";
std::string fpathMCfilt = "/gcf/atlas/data/JTNtuple_hist/run_"+toolMCfilt+"/";

std::string toolMCunfilt = "plot_pA_v1";
std::string fpathMCunfilt = "/gcf/atlas/data/JTNtuple_hist/run_"+toolMCunfilt+"/";

std::string ptr = "pt340t500";
std::string sel = "nosel";
std::string var = "d0SignJetMuonLoose";
std::string varStr = "S_{d_{0}}(#mu)";

std::string varh_bjet = "h_j1_"+var+"_bjet_"+ptr+"_"+sel;
std::string varh_cjet = "h_j1_"+var+"_cjet_"+ptr+"_"+sel;
std::string varh_ljet = "h_j1_"+var+"_ljet_"+ptr+"_"+sel;

void templateFiltComp()
{   
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine("#include <string>");
   gROOT->ProcessLine("#include <TH1F.h>");
   
   gROOT->ProcessLine(".x common.C");
   gROOT->ProcessLine(".x def.C");

   TH1F *h_MCfilt_bjet;
   TH1F *h_MCunfilt_bjet;
   TH1F *h_MCfilt_cjet;
   TH1F *h_MCunfilt_cjet;
   TH1F *h_MCfilt_ljet;
   TH1F *h_MCunfilt_ljet;
   
   for(int i=0;i<v_mc_filt.size();i++)
     {
	std::string fnameFilt = fpathMCfilt+v_mc_filt.at(i);
	std::string fnameUnfilt = fpathMCunfilt+v_mc_unfilt.at(i);
	fbatch_MCfilt[i] = TFile::Open(fnameFilt.c_str());
	fbatch_MCunfilt[i] = TFile::Open(fnameUnfilt.c_str());
	
	TH1F *hfFilt_bjet = (TH1F*)fbatch_MCfilt[i]->Get(varh_bjet.c_str());
	TH1F *hfUnfilt_bjet = (TH1F*)fbatch_MCunfilt[i]->Get(varh_bjet.c_str());
	TH1F *hfFilt_cjet = (TH1F*)fbatch_MCfilt[i]->Get(varh_cjet.c_str());
	TH1F *hfUnfilt_cjet = (TH1F*)fbatch_MCunfilt[i]->Get(varh_cjet.c_str());
	TH1F *hfFilt_ljet = (TH1F*)fbatch_MCfilt[i]->Get(varh_ljet.c_str());
	TH1F *hfUnfilt_ljet = (TH1F*)fbatch_MCunfilt[i]->Get(varh_ljet.c_str());
	if( i == 0 ) 
	  {
	     h_MCfilt_bjet = (TH1F*)hfFilt_bjet->Clone("h_MCfilt_bjet");
	     h_MCunfilt_bjet = (TH1F*)hfUnfilt_bjet->Clone("h_MCunfilt_bjet");
	     h_MCfilt_cjet = (TH1F*)hfFilt_cjet->Clone("h_MCfilt_cjet");
	     h_MCunfilt_cjet = (TH1F*)hfUnfilt_cjet->Clone("h_MCunfilt_cjet");
	     h_MCfilt_ljet = (TH1F*)hfFilt_ljet->Clone("h_MCfilt_ljet");
	     h_MCunfilt_ljet = (TH1F*)hfUnfilt_ljet->Clone("h_MCunfilt_ljet");
	  }	
	else 
	  {
	     h_MCfilt_bjet->Add(hfFilt_bjet);
	     h_MCunfilt_bjet->Add(hfUnfilt_bjet);
	     h_MCfilt_cjet->Add(hfFilt_cjet);
	     h_MCunfilt_cjet->Add(hfUnfilt_cjet);
	     h_MCfilt_ljet->Add(hfFilt_ljet);
	     h_MCunfilt_ljet->Add(hfUnfilt_ljet);
	  }   
     }

   TCanvas *c1 = new TCanvas();

   h_MCfilt_bjet->Rebin(nbm1d,"");
   h_MCunfilt_bjet->Rebin(nbm1d,"");
   h_MCfilt_cjet->Rebin(nbm1d,"");
   h_MCunfilt_cjet->Rebin(nbm1d,"");
   h_MCfilt_ljet->Rebin(nbm1d,"");
   h_MCunfilt_ljet->Rebin(nbm1d,"");
   
   h_MCfilt_bjet->SetLineColor(kRed);
   h_MCunfilt_bjet->SetLineColor(kBlack);
   h_MCfilt_cjet->SetLineColor(kRed);
   h_MCunfilt_cjet->SetLineColor(kBlack);
   h_MCfilt_ljet->SetLineColor(kRed);
   h_MCunfilt_ljet->SetLineColor(kBlack);

   h_MCfilt_bjet->SetMarkerColor(kRed);
   h_MCunfilt_bjet->SetMarkerColor(kBlack);
   h_MCfilt_cjet->SetMarkerColor(kRed);
   h_MCunfilt_cjet->SetMarkerColor(kBlack);
   h_MCfilt_ljet->SetMarkerColor(kRed);
   h_MCunfilt_ljet->SetMarkerColor(kBlack);

   h_MCfilt_bjet->SetMarkerStyle(20);
   h_MCunfilt_bjet->SetMarkerStyle(25);
   h_MCfilt_cjet->SetMarkerStyle(20);
   h_MCunfilt_cjet->SetMarkerStyle(25);
   h_MCfilt_ljet->SetMarkerStyle(20);
   h_MCunfilt_ljet->SetMarkerStyle(25);
   
   h_MCfilt_bjet->GetXaxis()->SetTitle(varStr.c_str());
   h_MCfilt_cjet->GetXaxis()->SetTitle(varStr.c_str());
   h_MCfilt_ljet->GetXaxis()->SetTitle(varStr.c_str());

   h_MCfilt_bjet->Scale(1./h_MCfilt_bjet->Integral());
   h_MCunfilt_bjet->Scale(1./h_MCunfilt_bjet->Integral());
   h_MCfilt_cjet->Scale(1./h_MCfilt_cjet->Integral());
   h_MCunfilt_cjet->Scale(1./h_MCunfilt_cjet->Integral());
   h_MCfilt_ljet->Scale(1./h_MCfilt_ljet->Integral());
   h_MCunfilt_ljet->Scale(1./h_MCunfilt_ljet->Integral());
   
   h_MCfilt_bjet->Draw("hist e1");
   h_MCunfilt_bjet->Draw("hist e1 same");
   
   double m1 = h_MCfilt_bjet->GetMaximum();
   double m2 = h_MCunfilt_bjet->GetMaximum();
   double k = 1.6;
   double m = (m1 >= m2) ? m1*k : m2*k;
   
   h_MCfilt_bjet->SetMaximum(m);
   
   TLegend *leg = new TLegend(0.65,0.90,0.88,0.75);                                                     
   leg->SetFillColor(253);                                                                              
   leg->SetBorderSize(0);   
   leg->AddEntry(h_MCfilt_bjet,"Filtered","p");
   leg->AddEntry(h_MCunfilt_bjet,"Unfiltered","p");   
   leg->Draw();

   std::string pname_bjet = "pics/templateFiltComp_bjet_"+var+"_"+ptr+"_"+sel+".eps";
   c1->Print(pname_bjet.c_str());

   leg->Clear();
   c1->Clear();
   
   h_MCfilt_cjet->Draw("hist e1 ");
   h_MCunfilt_cjet->Draw("hist e1 same");
   
   m1 = h_MCfilt_cjet->GetMaximum();
   m2 = h_MCunfilt_cjet->GetMaximum();
   m = (m1 >= m2) ? m1*k : m2*k;
   
   h_MCfilt_cjet->SetMaximum(m);
   
   TLegend *leg = new TLegend(0.65,0.90,0.88,0.75);                                                     
   leg->SetFillColor(253);                                                                              
   leg->SetBorderSize(0);   
   leg->AddEntry(h_MCfilt_cjet,"Filtered","p");
   leg->AddEntry(h_MCunfilt_cjet,"Unfiltered","p");
   leg->Draw();

   std::string pname_cjet = "pics/templateFiltComp_cjet_"+var+"_"+ptr+"_"+sel+".eps";
   c1->Print(pname_cjet.c_str());

   leg->Clear();
   c1->Clear();
   
   h_MCfilt_ljet->Draw("hist e1");
   h_MCunfilt_ljet->Draw("hist e1 same");
   
   m1 = h_MCfilt_ljet->GetMaximum();
   m2 = h_MCunfilt_ljet->GetMaximum();
   m = (m1 >= m2) ? m1*k : m2*k;
   
   h_MCfilt_ljet->SetMaximum(m);
   
   TLegend *leg = new TLegend(0.65,0.90,0.88,0.75);                                                     
   leg->SetFillColor(253);                                                                              
   leg->SetBorderSize(0);   
   leg->AddEntry(h_MCfilt_ljet,"Filtered","p");
   leg->AddEntry(h_MCunfilt_ljet,"Unfiltered","p");
   leg->Draw();

   std::string pname_ljet = "pics/templateFiltComp_ljet_"+var+"_"+ptr+"_"+sel+".eps";
   c1->Print(pname_ljet.c_str());
   
   gApplication->Terminate();
}

