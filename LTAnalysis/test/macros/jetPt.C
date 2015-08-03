#include "TStyle.h"

void SetStyle();
TStyle* Style();

void jetPt()
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

   TLegend *leg = new TLegend(0.65,0.40,0.90,0.20);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);

   std::string histname = "h_j1_pt_ajet_nosel_nosel_nosel";
   std::string fpathMC = "../histMJTEST_MERGED/";

   TFile *f[100];
   TH1D *h_merged;
   TH1D *h[100];
   
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
   
   for(int i=0;i<nSamp;i++)
     {
	std::string fname = fpathMC+mcName.at(i)+"/data.root";
	f[i] = TFile::Open(fname.c_str());
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
   
   h_merged->SetLineStyle(1);
   h_merged->SetLineWidth(4);
   h_merged->Draw("hist e1");
   
   h_merged->GetXaxis()->SetTitle("Jet p_{T} [GeV]");
   h_merged->GetYaxis()->SetTitle("Number of events");
   
   for(int i=0;i<nSamp;i++)
     {
	h[i]->Draw("hist e1 same");
     }   
   
//   leg->AddEntry(h0,"20-30 GeV","lp");
//   leg->AddEntry(h1,"20-25 GeV","lp");
//   leg->AddEntry(h2,"25-30 GeV","lp");

//   h1->GetXaxis()->SetTitle("Jet Probability");

   h_merged->SetMinimum(0.01);
   
   c1->SetLogx(1);
   c1->SetLogy(1);
   
//   leg->Draw();
   c1->Print("pics/jetPt.eps");

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
