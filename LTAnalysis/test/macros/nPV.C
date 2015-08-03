#include "TStyle.h"

void SetStyle();
TStyle* Style();

void nPV()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   SetStyle();
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   c1->Draw();
   c1->cd();

   TPad *c1_1;
   
   gStyle->SetHistTopMargin(0);

   TFile *fout = new TFile("npv.root","RECREATE");
   
   TLegend *leg = new TLegend(0.65,0.40,0.90,0.20);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);

   std::string histname = "h_npv_ajet_nosel_nosel_nosel";
   std::string fpath = "../histMJTEST_MERGED/";

   TFile *f[100];
   TFile *fData[100];
   TH1D *h_merged;
   TH1D *hData_merged;
   TH1D *h[100];
   TH1D *hData[100];
   
   std::vector<std::string> mcName;
   mcName.push_back("Pt-15to20_JPCalib");
   mcName.push_back("Pt-20to30_JPCalib");
   mcName.push_back("Pt-30to50_JPCalib");
   mcName.push_back("Pt-50to80_JPCalib");
   mcName.push_back("Pt-80to120_JPCalib");
   mcName.push_back("Pt-120to170_JPCalib");
   mcName.push_back("Pt-170to300_JPCalib");
   mcName.push_back("Pt-300to470_JPCalib");
   mcName.push_back("Pt-470to600_JPCalib");
   mcName.push_back("Pt-600to800_JPCalib");
   mcName.push_back("Pt-800to1000_JPCalib");
   
   int nSamp = mcName.size();

   std::vector<std::string> dataName;
   dataName.push_back("Run2015B_BTagMu_JPCalib");
   
   int nDataSamp = dataName.size();
   
   for(int i=0;i<nSamp;i++)
     {
	std::string fname = fpath+mcName.at(i)+"/data.root";
	f[i] = TFile::Open(fname.c_str());
     }

   for(int i=0;i<nDataSamp;i++)
     {
	std::string fname = fpath+dataName.at(i)+"/data.root";
	fData[i] = TFile::Open(fname.c_str());
     }
   
   for(int i=0;i<nSamp;i++)
     {	
	h[i] = (TH1D*)f[i]->Get(histname.c_str());
	h[i]->SetMarkerSize(0.0);
	h[i]->SetLineStyle(2);
	
	if( i == 0 )
	  {	     
	     h_merged = (TH1D*)h[i]->Clone("h_merged");
	  }
	else
	  {
	     h_merged->Add(h[i]);
	  }
     }

   for(int i=0;i<nDataSamp;i++)
     {	
	hData[i] = (TH1D*)fData[i]->Get(histname.c_str());
	hData[i]->SetMarkerSize(0.0);
	hData[i]->SetLineStyle(2);
	
	if( i == 0 )
	  {	     
	     hData_merged = (TH1D*)hData[i]->Clone("h_merged");
	  }
	else
	  {
	     hData_merged->Add(hData[i]);
	  }
     }

   h_merged->Scale(1./h_merged->Integral(0,h_merged->GetXaxis()->GetNbins()+1));
   hData_merged->Scale(1./hData_merged->Integral(0,hData_merged->GetXaxis()->GetNbins()+1));
   
   h_merged->SetLineStyle(1);
   h_merged->SetLineWidth(4);
   h_merged->Draw("hist e1");
   
   hData_merged->Draw("hist e1 same");

   fout->cd();
   TH1D *h_npv = (TH1D*)hData_merged->Clone("h_npv");
   h_npv->Divide(h_merged);
   
   float m1 = h_merged->GetMaximum();
   float m2 = hData_merged->GetMaximum();
   float mmax = (m1 > m2) ? m1 : m2;
   
   h_merged->SetMaximum(1.3*mmax);
   
   h_merged->GetXaxis()->SetTitle("Number of primary vertices");
   h_merged->GetYaxis()->SetTitle("Number of events");
   
   h_merged->SetMinimum(0.01);

   leg->AddEntry(h_merged,"MC","lp");
   leg->AddEntry(hData_merged,"Data","lp");

   leg->Draw();
   
   c1->Print("pics/nPV.eps");

   fout->Write();
   fout->Close();
   
   gApplication->Terminate();
}

void SetStyle()
{
  static TStyle* style = 0;
//  std::cout << "\nApplying ATLAS style settings...\n" << std::endl ;
  if( style==0 ) style = Style();
  gROOT->SetStyle("STYLE");
  gROOT->ForceStyle();
}

TStyle* Style() 
{
  TStyle *style = new TStyle("STYLE","User style");

  // use plain black on white colors
  Int_t icol=0; // WHITE
  style->SetFrameBorderMode(icol);
  style->SetFrameFillColor(icol);
  style->SetCanvasBorderMode(icol);
  style->SetCanvasColor(icol);
  style->SetPadBorderMode(icol);
  style->SetPadColor(icol);
  style->SetStatColor(icol);
  //style->SetFillColor(icol); // don't use: white fill color for *all* objects

  // set the paper & margin sizes
  style->SetPaperSize(20,26);

  // set margin sizes
  style->SetPadTopMargin(0.05);
  style->SetPadRightMargin(0.05);
  style->SetPadBottomMargin(0.16);
  style->SetPadLeftMargin(0.16);

  // set title offsets (for axis label)
  style->SetTitleXOffset(1.4);
  style->SetTitleYOffset(1.4);

  // use large fonts
  //Int_t font=72; // Helvetica italics
  Int_t font=42; // Helvetica
  Double_t tsize=0.05;
  style->SetTextFont(font);

  style->SetTextSize(tsize);
  style->SetLabelFont(font,"x");
  style->SetTitleFont(font,"x");
  style->SetLabelFont(font,"y");
  style->SetTitleFont(font,"y");
  style->SetLabelFont(font,"z");
  style->SetTitleFont(font,"z");
  
  style->SetLabelSize(tsize,"x");
  style->SetTitleSize(tsize,"x");
  style->SetLabelSize(tsize,"y");
  style->SetTitleSize(tsize,"y");
  style->SetLabelSize(tsize,"z");
  style->SetTitleSize(tsize,"z");

  // use bold lines and markers
  style->SetMarkerStyle(20);
  style->SetMarkerSize(1.2);
  style->SetHistLineWidth(2.);
  style->SetLineStyleString(2,"[12 12]"); // postscript dashes

  // get rid of X error bars 
  //style->SetErrorX(0.001);
  // get rid of error bar caps
  style->SetEndErrorSize(0.);

  // do not display any of the standard histogram decorations
  style->SetOptTitle(0);
  //style->SetOptStat(1111);
  style->SetOptStat(0);
  //style->SetOptFit(1111);
  style->SetOptFit(0);

  // put tick marks on top and RHS of plots
  style->SetPadTickX(1);
  style->SetPadTickY(1);

  return style;
}
