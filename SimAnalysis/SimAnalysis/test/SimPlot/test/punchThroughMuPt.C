#include "TStyle.h"

void SetStyle();
TStyle* Style();

void addbin(TH1D *h);

void punchThroughMuPt()
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

   std::string fpath = "plotIncl/";
   std::string histname1 = "h_mu1_pt";
   std::string histname2 = "h_muSim1_pt";

   TFile *f[100];

   TH1D *h1;
   TH1D *h2;
   
   std::vector<std::string> hName;   
   hName.push_back("output");
   int nSamp_h = hName.size();
  
   for(int i=0;i<nSamp_h;i++)
     {
	std::string fname = fpath+hName.at(i)+".root";
	f[i] = TFile::Open(fname.c_str());
     }
   
   for(int i=0;i<nSamp_h;i++)
     {	
	TH1D *h1_c = (TH1D*)f[i]->Get(histname1.c_str());
	h1_c->SetMarkerSize(0.0);

	TH1D *h2_c = (TH1D*)f[i]->Get(histname2.c_str());
	h2_c->SetMarkerSize(0.0);
	
	if( i == 0 )
	  {	     
	     h1 = (TH1D*)h1_c->Clone("h1");
	     h2 = (TH1D*)h2_c->Clone("h2");
	  }
	else
	  {
	     h1->Add(h1_c);
	     h2->Add(h2_c);
	  }
     }

   addbin(h1);
   addbin(h2);
   
   double ih1 = h1->Integral();
   double ih2 = h2->Integral();

   h1->SetLineColor(kRed);
   h1->SetFillColor(kRed);
   h2->SetLineColor(kBlue);
   h2->SetFillColor(kBlue);

   THStack *hcomb = new THStack("hcomb","");
   hcomb->Add(h1);
   hcomb->Add(h2);      
   
   hcomb->Draw("hist e1");
   hcomb->SetMaximum(1.3*hcomb->GetMaximum());

   hcomb->GetXaxis()->SetTitle("p_{T} [GeV]");
   hcomb->GetYaxis()->SetTitle("Number of events");
   
   leg->AddEntry(h1,"Generation","f");
   leg->AddEntry(h2,"Simulation","f");
   leg->Draw();   

   c1->Print("pics/punchThroughMuPtStack.eps");
   c1->Clear();
   
   h2->SetFillColor(0);
   
   h1->Scale(1./h1->Integral());
   h2->Scale(1./h2->Integral());
   
   h1->Draw("hist e1");
   h2->Draw("hist e1 same");

   float m1 = h1->GetMaximum();
   float m2 = h2->GetMaximum();
   float mmax = (m1 > m2) ? m1 : m2;
   
   h1->SetMaximum(1.3*mmax);

   h1->GetXaxis()->SetTitle("p_{T} [GeV]");
   h1->GetYaxis()->SetTitle("Normalized to unity");
   
   leg->Draw();
   
   c1->Print("pics/punchThroughMuPt.eps");
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
