void drawMCJXPtComp()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x common.C");
   gROOT->ProcessLine(".x def.C");

   std::string hname = "j1_pt_bjet_nosel_nosel";

/*   
   std::string flocalMCJ0 = "../hist/outputMCJ0.root";
   std::string flocalMCJ1 = "../hist/outputMCJ1.root";
   std::string flocalMCJ2 = "../hist/outputMCJ2.root";
   std::string flocalMCJ3 = "../hist/outputMCJ3.root";
   std::string flocalMCJ4 = "../hist/outputMCJ4.root";
   std::string flocalMCJ5 = "../hist/outputMCJ5.root";
   std::string flocalMCJ6 = "../hist/outputMCJ6.root";
   std::string flocalMCJ7 = "../hist/outputMCJ7.root";
   std::string flocalMCJ8 = "../hist/outputMCJ8.root";
*/

   std::string flocalMCJ0 = "/gcf/atlas/data/JTNtuple_hist/run_plot_SEL0/mc11_7TeV.105009.J0_pythia_jetjet/hist/data.root";
   std::string flocalMCJ1 = "/gcf/atlas/data/JTNtuple_hist/run_plot_SEL0/mc11_7TeV.105010.J1_pythia_jetjet/hist/data.root";
   std::string flocalMCJ2 = "/gcf/atlas/data/JTNtuple_hist/run_plot_SEL0/mc11_7TeV.105011.J2_pythia_jetjet/hist/data.root";
   std::string flocalMCJ3 = "/gcf/atlas/data/JTNtuple_hist/run_plot_SEL0/mc11_7TeV.105012.J3_pythia_jetjet/hist/data.root";
   std::string flocalMCJ4 = "/gcf/atlas/data/JTNtuple_hist/run_plot_SEL0/mc11_7TeV.105013.J4_pythia_jetjet/hist/data.root";
   std::string flocalMCJ5 = "/gcf/atlas/data/JTNtuple_hist/run_plot_SEL0/mc11_7TeV.105014.J5_pythia_jetjet/hist/data.root";
   std::string flocalMCJ6 = "/gcf/atlas/data/JTNtuple_hist/run_plot_SEL0/mc11_7TeV.105015.J6_pythia_jetjet/hist/data.root";
   std::string flocalMCJ7 = "/gcf/atlas/data/JTNtuple_hist/run_plot_SEL0/mc11_7TeV.105016.J7_pythia_jetjet/hist/data.root";
   std::string flocalMCJ8 = "/gcf/atlas/data/JTNtuple_hist/run_plot_SEL0/mc11_7TeV.105017.J8_pythia_jetjet/hist/data.root";
   
   bool norm1 = true; // normalize to unity
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   
   gStyle->SetHistTopMargin(0);
   
   TH1F *h_draw = new TH1F();

   TFile *fMCJ0 = TFile::Open(flocalMCJ0.c_str());
   TFile *fMCJ1 = TFile::Open(flocalMCJ1.c_str());
   TFile *fMCJ2 = TFile::Open(flocalMCJ2.c_str());
   TFile *fMCJ3 = TFile::Open(flocalMCJ3.c_str());
   TFile *fMCJ4 = TFile::Open(flocalMCJ4.c_str());
   TFile *fMCJ5 = TFile::Open(flocalMCJ5.c_str());
   TFile *fMCJ6 = TFile::Open(flocalMCJ6.c_str());
   TFile *fMCJ7 = TFile::Open(flocalMCJ7.c_str());
   TFile *fMCJ8 = TFile::Open(flocalMCJ8.c_str());

   std::string hisname = "h_"+hname;

   TH1F *hfMCJ0 = (TH1F*)fMCJ0->Get(hisname.c_str());
   TH1F *hfMCJ1 = (TH1F*)fMCJ1->Get(hisname.c_str());
   TH1F *hfMCJ2 = (TH1F*)fMCJ2->Get(hisname.c_str());
   TH1F *hfMCJ3 = (TH1F*)fMCJ3->Get(hisname.c_str());
   TH1F *hfMCJ4 = (TH1F*)fMCJ4->Get(hisname.c_str());
   TH1F *hfMCJ5 = (TH1F*)fMCJ5->Get(hisname.c_str());
   TH1F *hfMCJ6 = (TH1F*)fMCJ6->Get(hisname.c_str());
   TH1F *hfMCJ7 = (TH1F*)fMCJ7->Get(hisname.c_str());
   TH1F *hfMCJ8 = (TH1F*)fMCJ8->Get(hisname.c_str());
/*   
   if( hfMCJ0->Integral() > 0 ) hfMCJ0->Scale(1./hfMCJ0->Integral());
   if( hfMCJ1->Integral() > 0 ) hfMCJ1->Scale(1./hfMCJ1->Integral());
   if( hfMCJ2->Integral() > 0 ) hfMCJ2->Scale(1./hfMCJ2->Integral());
   if( hfMCJ3->Integral() > 0 ) hfMCJ3->Scale(1./hfMCJ3->Integral());
   if( hfMCJ4->Integral() > 0 ) hfMCJ4->Scale(1./hfMCJ4->Integral());
   if( hfMCJ5->Integral() > 0 ) hfMCJ5->Scale(1./hfMCJ5->Integral());
   if( hfMCJ6->Integral() > 0 ) hfMCJ6->Scale(1./hfMCJ6->Integral());
   if( hfMCJ7->Integral() > 0 ) hfMCJ7->Scale(1./hfMCJ7->Integral());
   if( hfMCJ8->Integral() > 0 ) hfMCJ8->Scale(1./hfMCJ8->Integral());
*/
   hfMCJ0->SetLineColor(kGreen);
   hfMCJ0->SetFillColor(kGreen);
   hfMCJ0->SetMarkerSize(0);
   
   hfMCJ1->SetLineColor(kGreen-6);
   hfMCJ1->SetFillColor(kGreen-6);
   hfMCJ1->SetMarkerSize(0);
   
   hfMCJ2->SetLineColor(kMagenta);
   hfMCJ2->SetFillColor(kMagenta);
   hfMCJ2->SetMarkerSize(0);

   hfMCJ3->SetLineColor(kMagenta-6);
   hfMCJ3->SetFillColor(kMagenta-6);
   hfMCJ3->SetMarkerSize(0);

   hfMCJ4->SetLineColor(kBlue);
   hfMCJ4->SetFillColor(kBlue);
   hfMCJ4->SetMarkerSize(0);

   hfMCJ5->SetLineColor(kBlue-6);
   hfMCJ5->SetFillColor(kBlue-6);
   hfMCJ5->SetMarkerSize(0);

   hfMCJ6->SetLineColor(kRed);
   hfMCJ6->SetFillColor(kRed);
   hfMCJ6->SetMarkerSize(0);

   hfMCJ7->SetLineColor(kRed-6);
   hfMCJ7->SetFillColor(kRed-6);
   hfMCJ7->SetMarkerSize(0);

   hfMCJ8->SetLineColor(kOrange);
   hfMCJ8->SetFillColor(kOrange);
   hfMCJ8->SetMarkerSize(0);

   THStack *hst = new THStack();

   hst->Add(hfMCJ0);
   hst->Add(hfMCJ1);
   hst->Add(hfMCJ2);
   hst->Add(hfMCJ3);
   hst->Add(hfMCJ4);
   hst->Add(hfMCJ5);
   hst->Add(hfMCJ6);
   hst->Add(hfMCJ7);
   hst->Add(hfMCJ8);

   hst->Draw("hist e1");

   hst->GetHistogram()->GetXaxis()->SetTitle("P_{T} [TeV]");
   hst->GetHistogram()->GetYaxis()->SetTitle("Number of events");
   
//   hst->GetHistogram()->GetYaxis()->SetRangeUser(0.1,1.2);
   
/*   
   hfMCJ0->Draw("hist e1");
   hfMCJ1->Draw("hist e1 same");
   hfMCJ2->Draw("hist e1 same");
   hfMCJ3->Draw("hist e1 same");
   hfMCJ4->Draw("hist e1 same");
   hfMCJ5->Draw("hist e1 same");
   hfMCJ6->Draw("hist e1 same");
   hfMCJ7->Draw("hist e1 same");
   hfMCJ8->Draw("hist e1 same");
*/
   
//   c1->SetLogx(1);
   c1->SetLogy(1);

   TLegend *leg = new TLegend(0.82,0.90,0.90,0.60);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   leg->AddEntry(hfMCJ8,"J8","f");
   leg->AddEntry(hfMCJ7,"J7","f");
   leg->AddEntry(hfMCJ6,"J6","f");
   leg->AddEntry(hfMCJ5,"J5","f");
   leg->AddEntry(hfMCJ4,"J4","f");
   leg->AddEntry(hfMCJ3,"J3","f");
   leg->AddEntry(hfMCJ2,"J2","f");
   leg->AddEntry(hfMCJ1,"J1","f");
   leg->AddEntry(hfMCJ0,"J0","f");
   
   leg->Draw();
   
   std::string fsave = "pics/"+hname+".eps";
   c1->Print(fsave.c_str());
	     
   gApplication->Terminate();
}
