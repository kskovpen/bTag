TFile *fbatch_mc[100];
TFile *fbatch_data[100];

std::string toolData = "plot_BDEFGHIJKLM_tag_mv1c0p91";
std::string toolMC = "plot_BDEFGHIJKLM_tag_mv1c0p91";
std::string fpathData = "/gcf/atlas/data/JTNtuple_hist/run_"+toolData+"/";
std::string fpathMC = "/gcf/atlas/data/JTNtuple_hist/run_"+toolMC+"/";

void purw()
{   
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine("#include <string>");
   gROOT->ProcessLine("#include <TH1F.h>");
   
   gROOT->ProcessLine(".x common.C");
   gROOT->ProcessLine(".x def.C");

   TH1F *h_draw_MC;
   TH1F *h_draw_MC_rw;
   TH1F *h_draw_DATA;
   
   for(int i=0;i<v_mc.size();i++)
     {
	std::string fname = fpathMC+v_mc.at(i);
	fbatch_mc[i] = TFile::Open(fname.c_str());
	
	TH1F *hf = (TH1F*)fbatch_mc[i]->Get("h_ev_mu");
	TH1F *hf_rw = (TH1F*)fbatch_mc[i]->Get("h_ev_mu_rw");
	if( i == 0 ) 
	  {
	     h_draw_MC = (TH1F*)hf->Clone("h_ev_mu");
	     h_draw_MC_rw = (TH1F*)hf_rw->Clone("h_ev_mu_rw");
	  }	
	else 
	  {
	     h_draw_MC->Add(hf);
	     h_draw_MC_rw->Add(hf_rw);
	  }   
     }

   TFile f_DATA("/home/kskovpen/work/testarea/JetTag/17.2.0.2/JTRun/run/mu/lumicalc/jt/ilumicalc_histograms_None_BDEFGHIJKLM.root");
   h_draw_DATA = (TH1F*)f_DATA.Get("avgintperbx");
   TH1F *h_draw_DATA_cp = h_draw_DATA->Clone("h_draw_DATA_cp");
   h_draw_DATA_cp->Scale(1./h_draw_DATA_cp->Integral());
   
   h_draw_MC->Scale(1./h_draw_MC->Integral());
   h_draw_MC_rw->Scale(1./h_draw_MC_rw->Integral());
   
   TCanvas *c1 = new TCanvas();

   h_draw_MC->Rebin(10);
   h_draw_MC_rw->Rebin(10);
   
   h_draw_DATA_cp->Rebin(10);
   
   h_draw_DATA_cp->SetLineColor(kRed);
   
   h_draw_MC->SetLineColor(kBlack);
   h_draw_MC_rw->SetLineColor(kBlue);

   h_draw_DATA_cp->Draw("hist");
   h_draw_MC->Draw("hist same");
   h_draw_MC_rw->Draw("hist same");

   h_draw_DATA_cp->GetXaxis()->SetRangeUser(0.,25.);
   h_draw_DATA_cp->GetYaxis()->SetTitle("");

   TLegend *leg = new TLegend(0.65,0.90,0.88,0.75);                                                     
   leg->SetFillColor(253);                                                                              
   leg->SetBorderSize(0);
   
   leg->AddEntry(h_draw_DATA_cp,"DATA","f");
   leg->AddEntry(h_draw_MC,"MC","f");
   leg->AddEntry(h_draw_MC_rw,"MC(weighted)","f");
   
   leg->Draw();
   
   c1->Print("pics/purw.eps");
   
   gApplication->Terminate();
}

