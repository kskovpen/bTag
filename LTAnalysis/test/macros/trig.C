#include "TStyle.h"

void SetStyle();
TStyle* Style();
double errfMC(double v1,double ve1,double v2,double ve2);
double errfDATA(double v1,double ve1,double v2,double ve2);

void trig()
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

   std::string trigName = "HLT_BTagMu_DiJet20_Mu5";
//   std::string trigName = "HLT_BTagMu_Jet300_Mu5";
   
   std::string histnameAll = "hJetPtAll_"+trigName;
   std::string histnamePass = "hJetPtPass_"+trigName;
   std::string fpath = "../histMJTRIGGER_MERGED/";

   TFile *f[100];
   TFile *fData[100];
   TH1D *hAll;
   TH1D *hAllData;
   TH1D *hPass;
   TH1D *hPassData;
   
   std::vector<std::string> mcName;
   mcName.push_back("Pt-15to20");
   mcName.push_back("Pt-20to30");
   mcName.push_back("Pt-30to50");
   mcName.push_back("Pt-50to80");
   mcName.push_back("Pt-80to120");
   mcName.push_back("Pt-120to170");
   mcName.push_back("Pt-170to300");
   mcName.push_back("Pt-300to470");
   mcName.push_back("Pt-470to600");
   mcName.push_back("Pt-600to800");
   mcName.push_back("Pt-800to1000");
   
   int nSamp = mcName.size();

   std::vector<std::string> dataName;
   dataName.push_back("Run2015B_BTagMu");
   
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
	TH1D *hfAll = (TH1D*)f[i]->Get(histnameAll.c_str());

	TH1D *hfPass = (TH1D*)f[i]->Get(histnamePass.c_str());
	
	if( i == 0 )
	  {	     
	     hAll = (TH1D*)hfAll->Clone("hAll");
	     hPass = (TH1D*)hfPass->Clone("hPass");
	  }
	else
	  {
	     hAll->Add(hfAll);
	     hPass->Add(hfPass);
	  }
     }

   for(int i=0;i<nDataSamp;i++)
     {	
	TH1D *hfAll = (TH1D*)fData[i]->Get(histnameAll.c_str());

	TH1D *hfPass = (TH1D*)fData[i]->Get(histnamePass.c_str());
	
	if( i == 0 )
	  {	     
	     hAllData = (TH1D*)hfAll->Clone("hAllData");
	     hPassData = (TH1D*)hfPass->Clone("hPassData");
	  }
	else
	  {
	     hAllData->Add(hfAll);
	     hPassData->Add(hfPass);
	  }
     }

   const int nbins = hAll->GetXaxis()->GetNbins();
   
   float eff[nbins];
   float effErr[nbins];
   float pt[nbins];
   float ptErr[nbins];
   for(int i=1;i<nbins+1;i++)
     {
	float all = hAll->GetBinContent(i);
	float allErr = hAll->GetBinError(i);
	float pass = hPass->GetBinContent(i);
	float passErr = hPass->GetBinError(i);
	eff[i-1] = (all > 0.) ? pass/all : 0.;
	effErr[i-1] = errfMC(pass,passErr,all,allErr);
	pt[i-1] = hAll->GetBinCenter(i);
	ptErr[i-1] = pt[i-1]-hAll->GetBinLowEdge(i);
     }

   float effData[nbins];
   float effErrData[nbins];
   for(int i=1;i<nbins+1;i++)
     {
	float all = hAllData->GetBinContent(i);
	float allErr = hAllData->GetBinError(i);
	float pass = hPassData->GetBinContent(i);
	float passErr = hPassData->GetBinError(i);
	effData[i-1] = (all > 0.) ? pass/all : 0.;
	effErrData[i-1] = errfDATA(pass,passErr,all,allErr);
     }
   
   TGraphErrors *hEff = new TGraphErrors(nbins,pt,eff,ptErr,effErr);
   TGraphErrors *hEffData = new TGraphErrors(nbins,pt,effData,ptErr,effErrData);

   hEff->SetMarkerSize(0.7);
   hEff->SetMarkerStyle(20);
   hEff->SetMarkerColor(kBlue);
   hEff->SetLineColor(kBlue);

   hEffData->SetMarkerSize(0.7);
   hEffData->SetMarkerStyle(22);
   hEffData->SetMarkerColor(kRed);
   hEffData->SetLineColor(kRed);
   
   hEff->Draw("AP");
   hEffData->Draw("PS");
   
   hEff->GetXaxis()->SetTitle("Jet p_{T} [GeV]");
   hEff->GetYaxis()->SetTitle("Efficiency");

   leg->AddEntry(hEff,"MC","lp");
   leg->AddEntry(hEffData,"Data","lp");

   leg->Draw();

   hEff->GetHistogram()->SetMaximum(1.);
   hEff->GetHistogram()->SetMinimum(0.);
   hEff->GetXaxis()->SetLimits(20.,1000.);
   hEff->GetXaxis()->SetMoreLogLabels();
   hEff->GetXaxis()->SetNoExponent();

   c1->SetLogx(1);
   
   c1->Print("pics/trigEff.eps");

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

double errfMC(double v1,double ve1,double v2,double ve2)
{   
   if( v2 == 0 ) return -666;
   
   double err = pow(v2-v1,2)*ve1*ve1/pow(v2,4) +
     v1*v1*(ve2*ve2-ve1*ve1)/pow(v2,4);
   
   err = sqrt(err);
   
   return err;
}

double errfDATA(double v1,double ve1,double v2,double ve2)
{   
   if( v2 == 0 ) return -666;
   
   double err = ve1*ve1/v2/v2 + v1*v1*ve2*ve2/v2/v2/v2/v2;
   
   err = sqrt(err);
   
   return err;
}
