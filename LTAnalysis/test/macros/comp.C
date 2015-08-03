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

//   std::string varName = "j1_JP";
   std::string varName = "j1_pt";
   std::string ptBin = "pt30t50";
//   std::string xtit = "JP discriminator";
   std::string xtit = "(p_{T}-p_{T}_{bin}^{min})/(p_{T}_{bin}^{max}-p_{T}_{bin}^{min})";
//   std::string xtit = "#eta";
   std::string btag = "nosel";

   leg->SetHeader("p_{T} 30-50 GeV");
   
   std::string histnameData = "h_"+varName+"_ajet_"+ptBin+"_nosel_"+btag;
   std::string histnameMCb = "h_"+varName+"_bjet_"+ptBin+"_nosel_"+btag;
   std::string histnameMCc = "h_"+varName+"_cjet_"+ptBin+"_nosel_"+btag;
   std::string histnameMCl = "h_"+varName+"_ljet_"+ptBin+"_nosel_"+btag;

//   std::string fpath = "../histMJCSVT_MERGED/";
   std::string fpath = "../histMJTEST_MERGED/";

   TFile *f[100];
   TFile *fData[100];

   TH1D *hMCb;
   TH1D *hMCc;
   TH1D *hMCl;
   TH1D *hData;
   
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
	TH1D *hb_c = (TH1D*)f[i]->Get(histnameMCb.c_str());
	hb_c->SetMarkerSize(0.0);

	TH1D *hc_c = (TH1D*)f[i]->Get(histnameMCc.c_str());
	hc_c->SetMarkerSize(0.0);

	TH1D *hl_c = (TH1D*)f[i]->Get(histnameMCl.c_str());
	hl_c->SetMarkerSize(0.0);
	
	if( i == 0 )
	  {	     
	     hMCb = (TH1D*)hb_c->Clone("hb");
	     hMCc = (TH1D*)hc_c->Clone("hc");
	     hMCl = (TH1D*)hl_c->Clone("hl");
	  }
	else
	  {
	     hMCb->Add(hb_c);
	     hMCc->Add(hc_c);
	     hMCl->Add(hl_c);
	  }
     }
   
   for(int i=0;i<nDataSamp;i++)
     {	
	TH1D *hData_c = (TH1D*)fData[i]->Get(histnameData.c_str());
	
	if( i == 0 )
	  {	     
	     hData = (TH1D*)hData_c->Clone("hData");
	  }
	else
	  {
	     hData->Add(hData_c);
	  }
     }

   addbin(hMCb);
   addbin(hMCc);
   addbin(hMCl);
   addbin(hData);
   
   double iMCb = hMCb->Integral();
   double iMCc = hMCc->Integral();
   double iMCl = hMCl->Integral();
   double iMC = iMCb+iMCc+iMCl;

   hMCb->SetLineColor(kRed);
   hMCb->SetFillColor(kRed);

   hMCc->SetLineColor(kGreen);
   hMCc->SetFillColor(kGreen);

   hMCl->SetLineColor(kBlue);
   hMCl->SetFillColor(kBlue);
   
   if( iMC > 0. ) hMCb->Scale(1./iMC);
   if( iMC > 0. ) hMCc->Scale(1./iMC);
   if( iMC > 0. ) hMCl->Scale(1./iMC);
   
   double iData = hData->Integral();
   
   THStack *hMC = new THStack();
   hMC->Add(hMCl);
   hMC->Add(hMCc);
   hMC->Add(hMCb);
   
   if( iData > 0. ) hData->Scale(1./iData);
   
   hMC->Draw("hist e1");
   
   hData->SetMarkerSize(0.7);
   
   hData->Draw("e1 same");

   float m1 = hMC->GetMaximum();
   float m2 = hData->GetMaximum();
   float mmax = (m1 > m2) ? m1 : m2;
   
   hMC->SetMaximum(1.3*mmax);
   
   hMC->GetXaxis()->SetTitle(xtit.c_str());
   hMC->GetYaxis()->SetTitle("");

   leg->AddEntry(hMCb,"b-jets","f");
   leg->AddEntry(hMCc,"c-jets","f");
   leg->AddEntry(hMCl,"udsg-jets","f");
   leg->AddEntry(hData,"Data","lp");

   leg->Draw();
   
   c1->Print("pics/comp.eps");
   
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
