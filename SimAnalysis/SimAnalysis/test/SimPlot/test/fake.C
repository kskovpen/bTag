#include "TStyle.h"

void SetStyle();
TStyle* Style();

void addbin(TH1D *h);

void fake()
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

   std::string fpath = "histTEST_MERGED/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/data.root";

//   std::string histnameFake = "h_muFake_pt";
//   std::string histnameReal = "h_muReal_pt";

//   std::string histnameFake = "h_muFake_trackerLayersWithMeasurement";
//   std::string histnameReal = "h_muReal_trackerLayersWithMeasurement";

//   std::string histnameFake = "h_muFake_numberOfValidMuonHits";
//   std::string histnameReal = "h_muReal_numberOfValidMuonHits";

//   std::string histnameFake = "h_muFake_numberOfMatches";
//   std::string histnameReal = "h_muReal_numberOfMatches";

//   std::string histnameFake = "h_muFake_numberOfMatchedStations";
//   std::string histnameReal = "h_muReal_numberOfMatchedStations";

//   std::string histnameFake = "h_muFake_numberOfValidHits";
//   std::string histnameReal = "h_muReal_numberOfValidHits";

//   std::string histnameFake = "h_muFake_numberOfValidPixelHits";
//   std::string histnameReal = "h_muReal_numberOfValidPixelHits";

   std::string histnameFake = "h_muFake_numberOfHits";
   std::string histnameReal = "h_muReal_numberOfHits";

//   std::string histnameFake = "h_muFake_normalizedChi2GlobalTrack";
//   std::string histnameReal = "h_muReal_normalizedChi2GlobalTrack";

//   std::string histnameFake = "h_muFake_normalizedChi2InnerTrack";
//   std::string histnameReal = "h_muReal_normalizedChi2InnerTrack";
   
   TFile *f;

   TH1D *hFake;
   TH1D *hReal;
   
   f = TFile::Open(fpath.c_str());
   
     {	
	TH1D *hFake_c = (TH1D*)f->Get(histnameFake.c_str());
	hFake_c->SetMarkerSize(0.0);

	TH1D *hReal_c = (TH1D*)f->Get(histnameReal.c_str());
	hReal_c->SetMarkerSize(0.0);

	hFake = (TH1D*)hFake_c->Clone("hFake");
	hReal = (TH1D*)hReal_c->Clone("hReal");
     }
   
   addbin(hFake);
   addbin(hReal);
   
   std::cout << hReal->Integral() << std::endl;
   std::cout << hFake->Integral() << std::endl;
   
   double iFake = hFake->Integral();
   double iReal = hReal->Integral();
//   double iAll = iFake+iReal;
   
//   hFake->Scale(1./iAll);
//   hReal->Scale(1./iAll);
   
   hFake->SetLineColor(9);
   hFake->SetFillColor(9);
   hReal->SetLineColor(46);
   hReal->SetFillColor(46);
   
   THStack *hst = new THStack();
   hst->Add(hReal);
   hst->Add(hFake);
   
   hst->Draw("hist e1");

   float max = hst->GetMaximum();
   
   hst->SetMaximum(1.3*max);
   hst->SetMinimum(0.);

   if( histnameFake == "h_muFake_pt" ) hst->GetXaxis()->SetTitle("p_{T} [GeV]");
   
   hst->GetYaxis()->SetTitle("Number of muons");
   
   leg->AddEntry(hFake,"Fake","f");
   leg->AddEntry(hReal,"Real","f");
   
   leg->Draw();
   
   c1->Print("pics/fake.eps");
   c1->Clear();

   TH1F *hRealScaled = (TH1F*)hReal->Clone("hRealScaled");
   hRealScaled->Scale(1./iReal);

   TH1F *hFakeScaled = (TH1F*)hFake->Clone("hFakeScaled");
   hFakeScaled->Scale(1./iFake);

   hFakeScaled->SetLineColor(9);
   hFakeScaled->SetFillColor(0);
   hRealScaled->SetLineColor(46);
   hRealScaled->SetFillColor(0);
   
   hRealScaled->Draw("hist e1");
   hFakeScaled->Draw("hist e1 same");

   float max1 = hRealScaled->GetMaximum();
   float max2 = hFakeScaled->GetMaximum();
   max = (max1 > max2) ? max1 : max2;
   
   hRealScaled->SetMaximum(1.3*max);
   hRealScaled->SetMinimum(0.);

   if( histnameFake == "h_muFake_pt" ) hRealScaled->GetXaxis()->SetTitle("p_{T} [GeV]");
   if( histnameFake == "h_muFake_trackerLayersWithMeasurement" ) hRealScaled->GetXaxis()->SetTitle("trackerLayersWithMeasurement");
   if( histnameFake == "h_muFake_numberOfValidMuonHits" ) hRealScaled->GetXaxis()->SetTitle("numberOfValidMuonHits");
   if( histnameFake == "h_muFake_numberOfMatches" ) hRealScaled->GetXaxis()->SetTitle("numberOfMatches");
   if( histnameFake == "h_muFake_numberOfMatchedStations" ) hRealScaled->GetXaxis()->SetTitle("numberOfMatchedStations");
   if( histnameFake == "h_muFake_numberOfValidHits" ) hRealScaled->GetXaxis()->SetTitle("numberOfValidHits");
   if( histnameFake == "h_muFake_numberOfValidPixelHits" ) hRealScaled->GetXaxis()->SetTitle("numberOfValidPixelHits");
   if( histnameFake == "h_muFake_numberOfHits" ) hRealScaled->GetXaxis()->SetTitle("numberOfHits");
   if( histnameFake == "h_muFake_normalizedChi2GlobalTrack" ) hRealScaled->GetXaxis()->SetTitle("normalizedChi2GlobalTrack");
   if( histnameFake == "h_muFake_normalizedChi2InnerTrack" ) hRealScaled->GetXaxis()->SetTitle("normalizedChi2InnerTrack");
   
   hRealScaled->GetYaxis()->SetTitle("Normalized to unity");
   
   leg->Draw();
   
   c1->Print("pics/fakeComp.eps");
   c1->Clear();
   
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
