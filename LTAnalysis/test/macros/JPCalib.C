#include "TStyle.h"

void SetStyle();
TStyle* Style();

void addbin(TH1D *h);

void JPCalib()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   SetStyle();

   std::string ptName = "p_{T} 200-300 GeV";
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   c1->Draw();
   c1->cd();

   TPad *c1_1;
   
   gStyle->SetHistTopMargin(0);

   TLegend *leg = new TLegend(0.45,0.90,0.90,0.60);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);

   std::string varName = "j1_JP";
   std::string ptBin = "pt200t300";
   std::string xtit = "JP discriminator";

   leg->SetHeader(ptName.c_str());
   
   std::string histnameData = "h_"+varName+"_ajet_"+ptBin+"_nosel_nosel";
   
   std::string histnameMCb = "h_"+varName+"_bjet_"+ptBin+"_nosel_nosel";
   std::string histnameMCc = "h_"+varName+"_cjet_"+ptBin+"_nosel_nosel";
   std::string histnameMCl = "h_"+varName+"_ljet_"+ptBin+"_nosel_nosel";

   std::string fpathNoCalib = "../histMJCSVL_MERGED/";
   std::string fpathCalib = "../histMJCSVL_MERGED/";

   TFile *fNoCalib[100];
   TFile *fDataNoCalib[100];
   TFile *fCalib[100];
   TFile *fDataCalib[100];

   TH1D *hMCNoCalibMerged;
   TH1D *hMCbNoCalib;
   TH1D *hMCcNoCalib;
   TH1D *hMClNoCalib;
   TH1D *hDataNoCalib;
   TH1D *hMCCalibMerged;
   TH1D *hMCbCalib;
   TH1D *hMCcCalib;
   TH1D *hMClCalib;
   TH1D *hDataCalib;
   
   std::vector<std::string> mcName_JPCalib;
   mcName_JPCalib.push_back("Pt-15to20_JPCalib");
   mcName_JPCalib.push_back("Pt-20to30_JPCalib");
   mcName_JPCalib.push_back("Pt-30to50_JPCalib");
   mcName_JPCalib.push_back("Pt-50to80_JPCalib");
   mcName_JPCalib.push_back("Pt-80to120_JPCalib");
   mcName_JPCalib.push_back("Pt-120to170_JPCalib");
   mcName_JPCalib.push_back("Pt-170to300_JPCalib");
   mcName_JPCalib.push_back("Pt-300to470_JPCalib");
   mcName_JPCalib.push_back("Pt-470to600_JPCalib");
   mcName_JPCalib.push_back("Pt-600to800_JPCalib");
   mcName_JPCalib.push_back("Pt-800to1000_JPCalib");

   std::vector<std::string> mcName_JPNoCalib;
   mcName_JPNoCalib.push_back("Pt-15to20_JPNoCalib");
   mcName_JPNoCalib.push_back("Pt-20to30_JPNoCalib");
   mcName_JPNoCalib.push_back("Pt-30to50_JPNoCalib");
   mcName_JPNoCalib.push_back("Pt-50to80_JPNoCalib");
   mcName_JPNoCalib.push_back("Pt-80to120_JPNoCalib");
   mcName_JPNoCalib.push_back("Pt-120to170_JPNoCalib");
   mcName_JPNoCalib.push_back("Pt-170to300_JPNoCalib");
   mcName_JPNoCalib.push_back("Pt-300to470_JPNoCalib");
   mcName_JPNoCalib.push_back("Pt-470to600_JPNoCalib");
   mcName_JPNoCalib.push_back("Pt-600to800_JPNoCalib");
   mcName_JPNoCalib.push_back("Pt-800to1000_JPNoCalib");
   
   int nSamp = mcName_JPCalib.size();

   std::vector<std::string> dataName_JPCalib;
   dataName_JPCalib.push_back("Run2015B_BTagMu_JPCalib");

   std::vector<std::string> dataName_JPNoCalib;
   dataName_JPNoCalib.push_back("Run2015B_BTagMu_JPNoCalib");
   
   int nDataSamp = dataName_JPCalib.size();
   
   for(int i=0;i<nSamp;i++)
     {
	std::string fnameNoCalib = fpathNoCalib+mcName_JPNoCalib.at(i)+"/data.root";
	fNoCalib[i] = TFile::Open(fnameNoCalib.c_str());

	std::string fnameCalib = fpathCalib+mcName_JPCalib.at(i)+"/data.root";
	fCalib[i] = TFile::Open(fnameCalib.c_str());
     }

   for(int i=0;i<nDataSamp;i++)
     {
	std::string fnameNoCalib = fpathNoCalib+dataName_JPNoCalib.at(i)+"/data.root";
	fDataNoCalib[i] = TFile::Open(fnameNoCalib.c_str());

	std::string fnameCalib = fpathCalib+dataName_JPCalib.at(i)+"/data.root";
	fDataCalib[i] = TFile::Open(fnameCalib.c_str());
     }
   
   for(int i=0;i<nSamp;i++)
     {	
	TH1D *hb_c_NoCalib = (TH1D*)fNoCalib[i]->Get(histnameMCb.c_str());
	hb_c_NoCalib->SetMarkerSize(0.0);
	TH1D *hc_c_NoCalib = (TH1D*)fNoCalib[i]->Get(histnameMCc.c_str());
	hc_c_NoCalib->SetMarkerSize(0.0);
	TH1D *hl_c_NoCalib = (TH1D*)fNoCalib[i]->Get(histnameMCl.c_str());
	hl_c_NoCalib->SetMarkerSize(0.0);

	TH1D *hb_c_Calib = (TH1D*)fCalib[i]->Get(histnameMCb.c_str());
	hb_c_Calib->SetMarkerSize(0.0);
	TH1D *hc_c_Calib = (TH1D*)fCalib[i]->Get(histnameMCc.c_str());
	hc_c_Calib->SetMarkerSize(0.0);
	TH1D *hl_c_Calib = (TH1D*)fCalib[i]->Get(histnameMCl.c_str());
	hl_c_Calib->SetMarkerSize(0.0);
	
	if( i == 0 )
	  {	     
	     hMCbNoCalib = (TH1D*)hb_c_NoCalib->Clone("hbNoCalib");
	     hMCcNoCalib = (TH1D*)hc_c_NoCalib->Clone("hcNoCalib");
	     hMClNoCalib = (TH1D*)hl_c_NoCalib->Clone("hlNoCalib");

	     hMCbCalib = (TH1D*)hb_c_Calib->Clone("hbCalib");
	     hMCcCalib = (TH1D*)hc_c_Calib->Clone("hcCalib");
	     hMClCalib = (TH1D*)hl_c_Calib->Clone("hlCalib");
	  }
	else
	  {
	     hMCbNoCalib->Add(hb_c_NoCalib);
	     hMCcNoCalib->Add(hc_c_NoCalib);
	     hMClNoCalib->Add(hl_c_NoCalib);

	     hMCbCalib->Add(hb_c_Calib);
	     hMCcCalib->Add(hc_c_Calib);
	     hMClCalib->Add(hl_c_Calib);
	  }
     }
   
   for(int i=0;i<nDataSamp;i++)
     {	
	TH1D *hData_c_NoCalib = (TH1D*)fDataNoCalib[i]->Get(histnameData.c_str());
	TH1D *hData_c_Calib = (TH1D*)fDataCalib[i]->Get(histnameData.c_str());
	
	if( i == 0 )
	  {	     
	     hDataNoCalib = (TH1D*)hData_c_NoCalib->Clone("hDataNoCalib");
	     hDataCalib = (TH1D*)hData_c_Calib->Clone("hDataCalib");
	  }
	else
	  {
	     hDataNoCalib->Add(hData_c_NoCalib);
	     hDataCalib->Add(hData_c_Calib);
	  }
     }

   addbin(hMCbNoCalib);
   addbin(hMCcNoCalib);
   addbin(hMClNoCalib);
   addbin(hDataNoCalib);
   addbin(hMCbCalib);
   addbin(hMCcCalib);
   addbin(hMClCalib);
   addbin(hDataCalib);
   
   double iMCbNoCalib = hMCbNoCalib->Integral();
   double iMCcNoCalib = hMCcNoCalib->Integral();
   double iMClNoCalib = hMClNoCalib->Integral();
   double iMCNoCalib = iMCbNoCalib+iMCcNoCalib+iMClNoCalib;
   double iMCbCalib = hMCbCalib->Integral();
   double iMCcCalib = hMCcCalib->Integral();
   double iMClCalib = hMClCalib->Integral();
   double iMCCalib = iMCbCalib+iMCcCalib+iMClCalib;

/*   hMCbNoCalib->SetLineColor(kRed);
   hMCbNoCalib->SetFillColor(kRed);
   hMCcNoCalib->SetLineColor(kGreen);
   hMCcNoCalib->SetFillColor(kGreen);
   hMClNoCalib->SetLineColor(kBlue);
   hMClNoCalib->SetFillColor(kBlue);

   hMCbCalib->SetLineColor(kRed);
   hMCbCalib->SetFillColor(kRed);
   hMCcCalib->SetLineColor(kGreen);
   hMCcCalib->SetFillColor(kGreen);
   hMClCalib->SetLineColor(kBlue);
   hMClCalib->SetFillColor(kBlue);
*/   
   if( iMCNoCalib > 0. ) hMCbNoCalib->Scale(1./iMCNoCalib);
   if( iMCNoCalib > 0. ) hMCcNoCalib->Scale(1./iMCNoCalib);
   if( iMCNoCalib > 0. ) hMClNoCalib->Scale(1./iMCNoCalib);
   if( iMCCalib > 0. ) hMCbCalib->Scale(1./iMCCalib);
   if( iMCCalib > 0. ) hMCcCalib->Scale(1./iMCCalib);
   if( iMCCalib > 0. ) hMClCalib->Scale(1./iMCCalib);
   
   double iDataNoCalib = hDataNoCalib->Integral();
   double iDataCalib = hDataCalib->Integral();

   hMCNoCalibMerged = (TH1D*)hMCbNoCalib->Clone("hMCNoCalibMerged");
   hMCNoCalibMerged->Add(hMCcNoCalib);
   hMCNoCalibMerged->Add(hMClNoCalib);

   hMCCalibMerged = (TH1D*)hMCbCalib->Clone("hMCCalibMerged");
   hMCCalibMerged->Add(hMCcCalib);
   hMCCalibMerged->Add(hMClCalib);
   
   THStack *hMCNoCalib = new THStack();
   hMCNoCalib->Add(hMClNoCalib);
   hMCNoCalib->Add(hMCcNoCalib);
   hMCNoCalib->Add(hMCbNoCalib);

   THStack *hMCCalib = new THStack();
   hMCCalib->Add(hMClCalib);
   hMCCalib->Add(hMCcCalib);
   hMCCalib->Add(hMCbCalib);
   
   if( iDataNoCalib > 0. ) hDataNoCalib->Scale(1./iDataNoCalib);
   if( iDataCalib > 0. ) hDataCalib->Scale(1./iDataCalib);

   hDataNoCalib->SetMarkerSize(0.0);
   hDataCalib->SetMarkerSize(0.0);
   
   // MC
     {	
	hMCNoCalibMerged->SetLineColor(kBlack);
	hMCCalibMerged->SetLineColor(kRed);
	
	hMCNoCalibMerged->Draw("hist e1");   
	hMCCalibMerged->Draw("hist e1 same");

	float m1 = hMCNoCalibMerged->GetMaximum();
	float m2 = hMCCalibMerged->GetMaximum();
	float mmax = (m1 > m2) ? m1 : m2;
	
	hMCNoCalibMerged->SetMaximum(1.3*mmax);
	
	hMCNoCalibMerged->GetXaxis()->SetTitle(xtit.c_str());
	hMCNoCalibMerged->GetYaxis()->SetTitle("");
	
	leg->AddEntry(hMCNoCalibMerged,"Default calibration","lp");
	leg->AddEntry(hMCCalibMerged,"JPcalib_MC74X_25ns_v1","lp");
	
	leg->Draw();
	
	c1->Print("pics/JPCalibMC.eps");
	leg->Clear();
	c1->Clear();
     }   

   // Data
     {	
	hDataNoCalib->SetLineColor(kBlack);
	hDataCalib->SetLineColor(kRed);

	hDataNoCalib->Draw("hist e1");   
	hDataCalib->Draw("hist e1 same");

	float m1 = hDataNoCalib->GetMaximum();
	float m2 = hDataCalib->GetMaximum();
	float mmax = (m1 > m2) ? m1 : m2;
	
	hDataNoCalib->SetMaximum(1.3*mmax);
	
	hDataNoCalib->GetXaxis()->SetTitle(xtit.c_str());
	hDataNoCalib->GetYaxis()->SetTitle("");

	leg->SetHeader(ptName.c_str());
	
	leg->AddEntry(hDataNoCalib,"Default calibration","lp");
	leg->AddEntry(hDataCalib,"JPcalib_Data74X_2015B_v1","lp");
	
	leg->Draw();
	
	c1->Print("pics/JPCalibData.eps");
	leg->Clear();
	c1->Clear();
     }   
   
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
