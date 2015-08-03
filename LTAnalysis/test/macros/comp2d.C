#include "TStyle.h"

void SetStyle();
TStyle* Style();

void addbin2D(TH2D *h);

void comp2d()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   SetStyle();
   
   gStyle->SetPalette(1,0);
   gStyle->SetHistTopMargin(0);   
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   c1->Draw();
   c1->cd();

   c1->SetRightMargin(0.15);                                                                                           
   c1->SetTopMargin(0.15);

   TLegend *leg = new TLegend(0.65,0.90,0.90,0.70);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);

//   std::string varName = "j1_JP";
   std::string varName = "j1_pt_vs_jeta";
   std::string ptBin = "pt30t50";
   std::string xtit = "#eta";
   std::string ytit = "(p_{T}-p_{T}_{bin}^{min})/(p_{T}_{bin}^{max}-p_{T}_{bin}^{min})";
   std::string btag = "nosel";

   leg->SetHeader("p_{T} 30-50 GeV");
   
   std::string histnameData = "h_"+varName+"_ajet_"+ptBin+"_nosel_"+btag;
   std::string histnameMC = "h_"+varName+"_ajet_"+ptBin+"_nosel_"+btag;

   std::string fpath = "../histMJPTETA_MERGED/";

   TFile *f[100];
   TFile *fData[100];

   TH2D *hMC;
   TH2D *hData;
   
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
	TH2D *hMC_c = (TH2D*)f[i]->Get(histnameMC.c_str());
	
	if( i == 0 )
	  {	     
	     hMC = (TH2D*)hMC_c->Clone("hMC");
	  }
	else
	  {
	     hMC->Add(hMC_c);
	  }
     }
   
   for(int i=0;i<nDataSamp;i++)
     {	
	TH2D *hData_c = (TH2D*)fData[i]->Get(histnameData.c_str());
	
	if( i == 0 )
	  {	     
	     hData = (TH2D*)hData_c->Clone("hData");
	  }
	else
	  {
	     hData->Add(hData_c);
	  }
     }

   addbin2D(hMC);
   addbin2D(hData);
   
   double iMC = hMC->Integral();
   if( iMC > 0. ) hMC->Scale(1./iMC);
   
//   double iData = hData->Integral();   
//   if( iData > 0. ) hData->Scale(1./iData);
   
   hData->Draw("COLZ");
//   hMC->Draw("BOX");
//   hData->Draw("BOX same");
   
/*   hMC->GetXaxis()->SetTitle(xtit.c_str());
   hMC->GetYaxis()->SetTitle(ytit.c_str());

   leg->AddEntry(hMC,"MC","f");
   leg->AddEntry(hData,"Data","f");*/

   hData->GetXaxis()->SetTitle(xtit.c_str());
   hData->GetYaxis()->SetTitle(ytit.c_str());
   
//   leg->Draw();
   
   c1->Print("pics/comp2d.eps");
   
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

void addbin2D(TH2D *h)
{   
   // Add overflow and underflow bins
   Int_t x_nbins = h->GetXaxis()->GetNbins();
   Int_t y_nbins = h->GetYaxis()->GetNbins();
   
   for(int iy=1;iy<y_nbins+1;iy++)
     {	
	h->SetBinContent(1,iy,h->GetBinContent(0,iy)+h->GetBinContent(1,iy));
	h->SetBinError(1,iy,TMath::Sqrt(pow(h->GetBinError(0,iy),2)+pow(h->GetBinError(1,iy),2)));
	h->SetBinContent(x_nbins,iy,h->GetBinContent(x_nbins,iy)+h->GetBinContent(x_nbins+1,iy));
	h->SetBinError(x_nbins,iy,TMath::Sqrt(pow(h->GetBinError(x_nbins,iy),2)+
					      pow(h->GetBinError(x_nbins+1,iy),2)));
	// Set overflow and underflow bins to 0
	h->SetBinContent(0,iy,0.);
	h->SetBinError(0,iy,0.);
	h->SetBinContent(x_nbins+1,iy,0.);
	h->SetBinError(x_nbins+1,iy,0.);
     }   

   for(int ix=1;ix<x_nbins+1;ix++)
     {	
	h->SetBinContent(ix,1,h->GetBinContent(ix,0)+h->GetBinContent(ix,1));
	h->SetBinError(ix,1,TMath::Sqrt(pow(h->GetBinError(ix,0),2)+pow(h->GetBinError(ix,1),2)));
	h->SetBinContent(ix,y_nbins,h->GetBinContent(ix,y_nbins)+h->GetBinContent(ix,y_nbins+1));
	h->SetBinError(ix,y_nbins,TMath::Sqrt(pow(h->GetBinError(ix,y_nbins),2)+
					      pow(h->GetBinError(ix,y_nbins+1),2)));
	// Set overflow and underflow bins to 0
	h->SetBinContent(ix,0,0.);
	h->SetBinError(ix,0,0.);
	h->SetBinContent(ix,y_nbins+1,0.);
	h->SetBinError(ix,y_nbins+1,0.);
     }   
}
