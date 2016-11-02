#include "TStyle.h"

void SetStyle();
TStyle* Style();

void addbin(TH1D *h);
double errfDATA(double v1,double ve1,double v2,double ve2);
double errfDATA_UNCOR(double v1,double ve1,double v2,double ve2);

void plot()
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

   std::string fpath = "output.root";
   
   std::string hname = "h_passFilt";
   std::string hname2 = "h_hasGenMu";
   
   TFile *f = TFile::Open(fpath.c_str());

   TH1D *h = (TH1D*)f->Get(hname.c_str());
   TH1D *h2 = (TH1D*)f->Get(hname2.c_str());

   float ng0 = h2->GetBinContent(1);
   float ng0err = h2->GetBinError(1);
   float ng1 = h2->GetBinContent(2);
   float ng1err = h2->GetBinError(2);
   float ng2 = h2->GetBinContent(3);
   float ng2err = h2->GetBinError(3);
   float ng3 = h2->GetBinContent(4);
   float ng3err = h2->GetBinError(4);
   
   float n0 = h->GetBinContent(1); // All
   float n0err = h->GetBinError(1);
   float n1 = h->GetBinContent(2); // Rec
   float n1err = h->GetBinError(2);
   float n2 = h->GetBinContent(3); // Filt
   float n2err = h->GetBinError(3);
   float n3 = h->GetBinContent(4); // Rec && Filt
   float n3err = h->GetBinError(4);
   float n4 = h->GetBinContent(5); // !Rec
   float n4err = h->GetBinError(5);
   float n5 = h->GetBinContent(6); // !Rec && Filt
   float n5err = h->GetBinError(6);

   float eff1 = n2/n0;
   float effErr1 = errfDATA(n2,n2err,n0,n0err);
   float eff2 = n3/n1;
   float effErr2 = errfDATA(n3,n3err,n1,n1err);
   float eff3 = n5/n4;
   float effErr3 = errfDATA(n5,n5err,n4,n4err);

   float effg1 = ng1/ng0;
   float effgErr1 = errfDATA(ng1,ng1err,ng0,ng0err);
   float effg2 = ng2/n1;
   float effgErr2 = errfDATA(ng2,ng2err,n1,n1err);
   float effg3 = ng3/n4;
   float effgErr3 = errfDATA(ng3,ng3err,n4,n4err);

   std::cout << "All = " << n0 << " Reco = " << n1 << std::endl;
   std::cout << "eff (Filt/All) = " << eff1*100. << " +- " << effErr1*100. << " %" << std::endl;
   std::cout << "eff (Filt/Reco) = " << eff2*100. << " +- " << effErr2*100. << " %" << std::endl;
   std::cout << "eff (Filt/!Reco) = " << eff3*100. << " +- " << effErr3*100. << " %" << std::endl;

   std::cout << "gen eff (Filt/All) = " << effg1*100. << " +- " << effgErr1*100. << " %" << std::endl;
   std::cout << "gen eff (Filt/Reco) = " << effg2*100. << " +- " << effgErr2*100. << " %" << std::endl;
   std::cout << "gen eff (Filt/!Reco) = " << effg3*100. << " +- " << effgErr3*100. << " %" << std::endl;
   
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

double errfDATA(double v1,double ve1,double v2,double ve2)
{   
   if( v2 == 0 ) return -666;
   
   double err = ve1*ve1/v2/v2 + v1*v1*ve2*ve2/v2/v2/v2/v2;
   
   err = sqrt(err);
   
   return err;
}
   
double errfDATA_UNCOR(double v1,double ve1,double v2,double ve2)
{   
   if( v2 == 0 ) return -666;
   
   double err = ve1*ve1/v1/v1+ve2*ve2/v2/v2;
   
   err = sqrt(err)*v1/v2;
   
   return err;
}
