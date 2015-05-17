TFile *fbatch_MCc[100];
TFile *fbatch_MCb[100];
TFile *fbatch_DATA[100];

int nbm1d = 2.77;

std::string toolDATA = "plot_4p7_v1_4trk";
std::string fpathDATA = "/gcf/atlas/data/JTNtuple_hist/run_"+toolDATA+"/";

std::string toolMCc = "plot_4p7_mc11b_v1_4trk";
std::string fpathMCc = "/gcf/atlas/data/JTNtuple_hist/run_"+toolMCc+"/";

std::string toolMCb = "plot_4p7_v1_4trk";
std::string fpathMCb = "/gcf/atlas/data/JTNtuple_hist/run_"+toolMCb+"/";

std::string varh = "h_j1_vPTsv0p_ljet_pt340t500_sv0";
//std::string varhDATA = "h_j1_vBTsv0p_ajet_pt340t500_sv0";

void mc11bc()
{   
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine("#include <string>");
   gROOT->ProcessLine("#include <TH1F.h>");
   
   gROOT->ProcessLine(".x common.C");
   gROOT->ProcessLine(".x def.C");

   TH1F *h_MCc;
   TH1F *h_MCb;
//   TH1F *h_DATA;
   
   for(int i=0;i<v_mc.size();i++)
     {
	std::string fnameC = fpathMCc+v_mc.at(i);
	std::string fnameB = fpathMCb+v_mc.at(i);
	fbatch_MCc[i] = TFile::Open(fnameC.c_str());
	fbatch_MCb[i] = TFile::Open(fnameB.c_str());
	
	TH1F *hfC = (TH1F*)fbatch_MCc[i]->Get(varh.c_str());
	TH1F *hfB = (TH1F*)fbatch_MCb[i]->Get(varh.c_str());
	if( i == 0 ) 
	  {
	     h_MCc = (TH1F*)hfC->Clone("h_MCc");
	     h_MCb = (TH1F*)hfB->Clone("h_MCb");
	  }	
	else 
	  {
	     h_MCc->Add(hfC);
	     h_MCb->Add(hfB);
	  }   
     }
/*
   for(int i=0;i<v_data.size();i++)
     {
	std::string fname = fpathDATA+v_data.at(i);
	fbatch_DATA[i] = TFile::Open(fname.c_str());
	
	TH1F *hf = (TH1F*)fbatch_DATA[i]->Get(varhDATA.c_str());
	if( i == 0 )
	  {
	     h_DATA = (TH1F*)hf->Clone("h_DATA");
	  }	
	else 
	  {
	     h_DATA->Add(hf);
	  }   
     }   
*/   
   TCanvas *c1 = new TCanvas();

   h_MCc->Rebin(nbm1d,"");
   h_MCb->Rebin(nbm1d,"");
//   h_DATA->Rebin(nbm1d,"");
   
//   h_DATA->SetLineColor(kRed);
   
   h_MCc->SetLineColor(kBlack);
   h_MCb->SetLineColor(kBlue);

   h_MCc->GetXaxis()->SetTitle("#Pi^{T}");
//   h_MCc->GetXaxis()->SetTitle("B^{T}");
   
//   std::cout << h_DATA->Integral() << " " << h_MCc->Integral() << " " << h_MCb->Integral() << std::endl;
   
//   h_DATA->Scale(1./h_DATA->Integral());
   h_MCc->Scale(1./h_MCc->Integral());
   h_MCb->Scale(1./h_MCb->Integral());
   
//   h_DATA->Draw("hist");
   h_MCc->Draw("hist");
   h_MCb->Draw("hist same");
   
   double m1 = h_MCc->GetMaximum();
   double m2 = h_MCb->GetMaximum();
   double k = 1.4;
   double m = (m1 >= m2) ? m1*k : m2*k;
   
   h_MCc->SetMaximum(m);
   
   TLegend *leg = new TLegend(0.65,0.90,0.88,0.75);                                                     
   leg->SetFillColor(253);                                                                              
   leg->SetBorderSize(0);
   
//   leg->AddEntry(h_DATA,"DATA","f");
   leg->AddEntry(h_MCc,"MC11c","f");
   leg->AddEntry(h_MCb,"MC11b","f");
   
   leg->Draw();
   
   c1->Print("pics/mc11bc.eps");
   
   gApplication->Terminate();
}

