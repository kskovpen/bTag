#include "TStyle.h"

void SetStyle();
TStyle* Style();

void addbin(TH1D *h);

void comp()
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
   std::string fpathMu = "plotMu/";
   std::string histname = "h_mu2_pt";
   std::string histnameNorm = "h_mu2_id";

   TFile *f[100];
   TFile *fMu[100];

   TH1D *h;
   TH1D *hMu;
   TH1D *hNorm;
   TH1D *hMuNorm;
   
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
	std::string fname = fpathMu+hName.at(i)+".root";
	fMu[i] = TFile::Open(fname.c_str());
     }
   
   for(int i=0;i<nSamp_h;i++)
     {	
	TH1D *h_c = (TH1D*)f[i]->Get(histname.c_str());
	h_c->SetMarkerSize(0.0);

	TH1D *hNorm_c = (TH1D*)f[i]->Get(histnameNorm.c_str());
	hNorm_c->SetMarkerSize(0.0);
	
	if( i == 0 )
	  {	     
	     h = (TH1D*)h_c->Clone("h");
	     hNorm = (TH1D*)hNorm_c->Clone("hNorm");
	  }
	else
	  {
	     h->Add(h_c);
	     hNorm->Add(hNorm_c);
	  }
     }

   for(int i=0;i<nSamp_h;i++)
     {	
	TH1D *hMu_c = (TH1D*)fMu[i]->Get(histname.c_str());
	hMu_c->SetMarkerSize(0.0);

	TH1D *hMuNorm_c = (TH1D*)fMu[i]->Get(histnameNorm.c_str());
	hMuNorm_c->SetMarkerSize(0.0);
	
	if( i == 0 )
	  {	     
	     hMu = (TH1D*)hMu_c->Clone("hMu");
	     hMuNorm = (TH1D*)hMuNorm_c->Clone("hMuNorm");
	  }
	else
	  {
	     hMu->Add(hMu_c);
	     hMuNorm->Add(hMuNorm_c);
	  }
     }
   
   addbin(h);
   addbin(hNorm);
   addbin(hMu);
   addbin(hMuNorm);
   
   double ih = h->Integral();   
   double ihNorm = hNorm->Integral();
   double ihMu = hMu->Integral();   
   double ihMuNorm = hMuNorm->Integral();
//   std::cout << ih << " " << ihMu << " " << ih/ihMu << std::endl;

   std::cout << ihMu/ih << std::endl;
   
/*   double v1 = hNorm->GetBinContent(1)+
     hNorm->GetBinContent(2)+
     hNorm->GetBinContent(4)+
     hNorm->GetBinContent(5)+
     hNorm->GetBinContent(7);
   double v2 = hMuNorm->GetBinContent(1)+
     hMuNorm->GetBinContent(2)+
     hMuNorm->GetBinContent(4)+
     hMuNorm->GetBinContent(5)+
     hMuNorm->GetBinContent(7);
   double fAdd = v2/v1;
   std::cout << fAdd << std::endl;*/
   
//   h->Scale(fAdd);
   
   h->SetLineColor(kRed);
   h->SetFillColor(kRed);
   hMu->SetLineColor(kBlue);
   
   h->Draw("hist e1");
   hMu->Draw("hist e1 same");

   float m1 = h->GetMaximum();
   float m2 = hMu->GetMaximum();
   float mmax = (m1 > m2) ? m1 : m2;
   
   h->SetMaximum(1.3*mmax);

   if( histname == "h_mu1_pt" || histname == "h_mu2_pt" ||
       histname == "h_muSim1_pt" || histname == "h_muSim2_pt" ||
       histname == "h_muAll1_pt" || histname == "h_muAll2_pt" )
     {	
	h->GetXaxis()->SetTitle("p_{T} [GeV]");
	h->GetYaxis()->SetTitle("Number of muons");
     }
   else if( histname == "h_mu1_id" || histname == "h_mu2_id" )
     {	
	h->GetXaxis()->SetBinLabel(1,"B");
	h->GetXaxis()->SetBinLabel(2,"D");
	h->GetXaxis()->SetBinLabel(3,"K");
	h->GetXaxis()->SetBinLabel(4,"#Lambda");
	h->GetXaxis()->SetBinLabel(5,"#tau");
	h->GetXaxis()->SetBinLabel(6,"#pi");
	h->GetXaxis()->SetBinLabel(7,"others");
	h->GetYaxis()->SetTitle("Number of muons");
     }
   else if( histname == "h_mu1_partonId" || histname == "h_mu2_partonId" )
     {	
	h->GetXaxis()->SetBinLabel(1,"Gluon");
	h->GetXaxis()->SetBinLabel(2,"Light");
	h->GetXaxis()->SetBinLabel(3,"Charm");
	h->GetXaxis()->SetBinLabel(4,"Bottom");
	h->GetYaxis()->SetTitle("Number of muons");
     }
   
   leg->AddEntry(h,"Inclusive","f");
   leg->AddEntry(hMu,"Mu-enriched","f");
   
   leg->Draw();
   
   c1->Print("pics/comp.eps");
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
