#include "TStyle.h"

void SetStyle();
TStyle* Style();

void addbin(TH1D *h);

void sf()
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

   TLegend *leg = new TLegend(0.65,0.90,0.90,0.70);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);

   std::string ptHat = "800to1000";
   
   std::string fpathM = "histTEST_MERGED/QCD_Pt-"+ptHat+"_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/data.root";
   std::string fpathI = "histTEST_MERGED/QCD_Pt_"+ptHat+"_TuneCUETP8M1_13TeV_pythia8/data.root";   
   
   std::string histnameM = "h_muPythiaGeant_N";
   std::string histnameI = "h_muGeant_N";

   
   TFile *fM;
   TFile *fI;

   TH1D *hM;
   TH1D *hI;
   
   fM = TFile::Open(fpathM.c_str());
   fI = TFile::Open(fpathI.c_str());
   
     {	
	TH1D *hM_c = (TH1D*)fM->Get(histnameM.c_str());
	hM_c->SetMarkerSize(0.0);

	hM = (TH1D*)hM_c->Clone("hM");
     }

     {	
	TH1D *hI_c = (TH1D*)fI->Get(histnameI.c_str());
	hI_c->SetMarkerSize(0.0);

	hI = (TH1D*)hI_c->Clone("hI");
     }
   
   hM->SetLineColor(9);
   hM->SetFillColor(9);
   
   hI->SetLineColor(46);
   hI->SetFillColor(46);
   
   hM->Draw("hist e1");
  
   float max = hM->GetMaximum();
   
   hM->SetMaximum(1.3*max);
   hM->SetMinimum(0.);
   
   c1->Print("pics/sfM.eps");
   c1->Clear();

   hI->Draw("hist e1");
  
   max = hI->GetMaximum();
   
   hI->SetMaximum(1.3*max);
   hI->SetMinimum(0.);
   
   c1->Print("pics/sfI.eps");
   c1->Clear();

   float g1 = hI->GetBinContent(2);
   float g2 = hI->GetBinContent(3);
   float g3 = hI->GetBinContent(4);
   
   float x3 = hM->GetBinContent(1);
   float x5 = hM->GetBinContent(3);
   float x6 = hM->GetBinContent(5);
   float x8 = hM->GetBinContent(11);
   float x9 = hM->GetBinContent(12);
   float x10 = hM->GetBinContent(13);

   float y1 = hM->GetBinContent(2);
   float y2 = hM->GetBinContent(7);
   float y3 = hM->GetBinContent(8);
   float y4 = hM->GetBinContent(14);
   float y5 = hM->GetBinContent(15);
   float y6 = hM->GetBinContent(16);
   
   float z1 = hM->GetBinContent(10);
   float z2 = hM->GetBinContent(17);
   float z3 = hM->GetBinContent(18);
   
   float h1 = hM->GetBinContent(19);

   float w1 = (g1-y1)/x3;
   float w2 = (g2-x5*w1-y2-y3*w1-z1)/x6;
   float w3 = (g3-w1*x8-w2*x9-y4-w1*y5-w2*y6-z2-w1*z3-h1)/x10;
   
   std::cout << "w1 = ( g1 - y1 ) / x3" << std::endl;
   std::cout << "w1 = ( " << g1 << " - " << y1 << " ) / " << x3 << std::endl;
   
   std::cout << "w2 = ( g2 - x5 * w1 - y2 - y3 * w1 - z1 ) / x6" << std::endl;
   std::cout << "w2 = ( " << g2 << " - " << x5 << " * " << w1 << " - " << y2 << " - " << y3 << " * " << w1 << " - " << z1 << " ) / " << x6 << std::endl;
   
   std::cout << "w3 = ( g3 - w1 * x8 - w2 * x9 - y4 - w1 * y5 - w2 * y6 - z2 - w1 * z3 - h1 ) / x10" << std::endl;
   std::cout << "w3 = ( " << g3 << " - " << w1 << " * " << x8 << " - " << w2 << " * " << x9 << " - " << y4 << " - " << w1 << " * " << y5 << " - " << w2 << " * " << y6 << " - " << z2 << " - " << w1 << " * " << z3 << " - " << h1 << " ) / " << x10 << std::endl;

   std::cout << "w1 = " << w1 << std::endl;
   std::cout << "w2 = " << w2 << std::endl;
   std::cout << "w3 = " << w3 << std::endl;
   
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

void addbin(TH1D *h)
{   
   // Add overflow and underflow bins
   Int_t x_nbins = h->GetXaxis()->GetNbins();
   h->SetBinContent(1,h->GetBinContent(0)+h->GetBinContent(1));
   h->SetBinError(1,TMath::Sqrt(pow(h->GetBinError(0),2)+pow(h->GetBinError(1),2)));
   h->SetBinContent(x_nbins,h->GetBinContent(x_nbins)+h->GetBinContent(x_nbins+1));
   h->SetBinError(x_nbins,TMath::Sqrt(pow(h->GetBinError(x_nbins),2)+
				      pow(h->GetBinError(x_nbins+1),2)));
   // Set overflow and underflow bins to 0
   h->SetBinContent(0,0.);
   h->SetBinError(0,0.);
   h->SetBinContent(x_nbins+1,0.);
   h->SetBinError(x_nbins+1,0.);
}
