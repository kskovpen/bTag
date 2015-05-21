#ifndef SYSFUNC_H
#define SYSFUNC_H

#include "def.h"

#include "TROOT.h"
#include "TStyle.h"
#include "TFile.h"
#include "Riostream.h"
#include "TCanvas.h"
#include "TError.h"
#include "TMinuit.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "THStack.h"
#include "TLegend.h"
#include "TLatex.h"

#include "atlasstyle-00-03-04/AtlasStyle.h"
#include "atlasstyle-00-03-04/AtlasUtils.h"

#include "addbin.h"
#include "addbin2D.h"
#include "ratioErr.h"
#include "ratio.h"
#include "makeErrorBand.h"
#include "label.h"

TFile *fdata[1000];
TFile *fmc_NOMINAL[1000];
TFile *fmc_RW[1000];
TFile *fmc_RW2[1000];

void openData_NOMINAL(std::string);
void openData_RW(std::string,std::string);
void readData(std::string,TH1D*,int);
void readDataJP(std::string,bool,int);
void calcSF(int,std::string,TH1D*,TH1D*);
void plotCOMP(TH1D*,TH1D*,TH1D*,std::string,std::string);
void applySF(TH2D*,TH1D*,TH1D*,TH1D*,std::string);
void doSys(TH1D*,TH1D*,TH1D*,TH1D*,TH1D*);
void plotSF(TH1D*,TH1D*,TH1D*,TH1D*,TH1D*,std::string);
void plotSYS(TH1D*,TH1D*,TH1D*,TH1D*,TH1D*,TH1D*,std::string);
void valSys(TH1D*,TH1D*,TH1D*);
void multiSF(TH1D*,TH1D*);

const int nvar = 1;
double rb[nvar] = {1};
//const int nvar = 6;
//double rb[nvar] = {1,1,1,1,1,1};
std::string rw = "";

bool sanityTest = 0; // produce but don't apply SF
bool doErrSym = 0;
bool useCorMC = 0;

std::string PTname;

TH1D *h_data[nvar], *h_mc_NOMINAL[nvar];
TH1D *h_mc_RW[nvar], *h_mc_RW2[nvar];

TH1D *h_untag_NOMINAL;
TH1D *h_untag_RW;
TH1D *h_untag_RW2;

TH1D *h_mc_JP_rw_noscale;
TH1D *h_sf[nvar];
TLegend *leg;

const int nptbin = 17;
std::string ptbin[nptbin] = { "nosel","pt20t30","pt30t40","pt40t50","pt50t60","pt60t70","pt70t80",
   "pt80t100","pt100t120","pt120t160","pt160t210","pt210t260","pt260t320","pt320t400",
   "pt400t500","pt500t670","pt670t1000"};

/*const int nptbin = 32;
std::string ptbin[nptbin] = { "nosel","pt20t25","pt25t30","pt30t35","pt35t40",
   "pt40t45","pt45t50","pt50t55","pt55t60","pt60t65","pt65t70","pt70t75","pt75t80",
   "pt80t90","pt90t100","pt100t110","pt110t120","pt120t140","pt140t160",
   "pt160t185","pt185t210","pt210t235","pt235t260","pt260t290","pt290t320",
   "pt320t360","pt360t400",
   "pt400t450","pt450t500","pt500t585","pt585t670","pt670t1000"};
*/
//const int nptbin = 10;
//std::string ptbin[nptbin] = { "nosel","pt20t40","pt40t60","pt60t80",
//   "pt80t120","pt120t210","pt210t320","pt320t500",
//   "pt500t1000","pt1000t1400"};
//const int nptbin = 6;
//std::string ptbin[nptbin] = { "nosel","pt30t50","pt50t80","pt80t120","pt120t210","pt210t320"};
const int nflav = 4;
std::string flav[nflav] = {"ajet_","bjet_","cjet_","ljet_"};
//const int nbtag = 3;
//std::string btag[nbtag] = {"_nosel","_combSvx0p679","_UNTAGbc"};
//std::string btag[nbtag] = {"_nosel","_combSvx0p244","_UNTAGbc"};
//std::string btag[nbtag] = {"_nosel","_combSvx0p898","_UNTAGbc"};
//const int nbtag = 8;
//std::string btag[nbtag] = {"_nosel","_combSvx0p244","_combSvx0p679","_combSvx0p898",
//   "_TCHP1p19","_TCHP1p93","_TCHP3p41","_UNTAGbc"};
const int nbtag = 3;
std::string btag[nbtag] = {"_nosel","_combSvx0p244","_UNTAGbc"};
std::string var1d[nvar] = {
   "h_j1_JP" // has to be JP
//   "h_j1_nseltrk"
//   "h_j1_pt"
//   "h_j1_njet"
//   "h_j1_nsv",
//   "h_j1_svntrk",
//   "h_j1_mupt"
//   "h_j1_nseltrk"
//   "h_j1_ntrk"
//   "h_j1_njet"
//   "h_j1_nsv"
//   "h_j1_eta"
};
std::string titx[nvar] = {
   "Jet probability"
//   "Number of tracks"
//   "(P_{T} - P_{T}^{bin}_{min})/ P_{T}^{bin}"
//   "Number of tracks",
//   "Number of tracks"
//   "Number of jets"
//   "P_{T} (#mu) [GeV]"
//   "Number of jets",
//   "Number of SV"
//   "#eta (jet)"
};

void openData_NOMINAL(std::string fpath)
{   
   for(int i=0;i<v_mc_filt->size();i++)
     {
	std::string fname = fpath+v_mc_filt->at(i);
	fmc_NOMINAL[i] = TFile::Open(fname.c_str());
     }

   for(int i=0;i<v_data.size();i++)
     {
	std::string fname = fpath+v_data.at(i);
	fdata[i] = TFile::Open(fname.c_str());
     }   
}

void openData_RW(std::string fpath1,std::string fpath2)
{   
   for(int i=0;i<v_mc_filt->size();i++)
     {
	std::string fname = fpath1+v_mc_filt->at(i);
	fmc_RW[i] = TFile::Open(fname.c_str());
     }

   for(int i=0;i<v_mc_filt->size();i++)
     {
	std::string fname = fpath2+v_mc_filt->at(i);
	fmc_RW2[i] = TFile::Open(fname.c_str());
     }
}

void readData(std::string histName,int ivar,int idx)
{
   // 0 - RW
   // 1 - NOMINAL
   // 2 - RW2
   
   for(int i=0;i<v_mc_filt->size();i++)
     {   
	std::string hname = histName;
	TH1D *hf;
	if( idx == 1 )
	  hf = (TH1D*)fmc_NOMINAL[i]->Get(hname.c_str());
	else if( idx == 0 )
	  hf = (TH1D*)fmc_RW[i]->Get(hname.c_str());
	else if( idx == 2 )
	  hf = (TH1D*)fmc_RW2[i]->Get(hname.c_str());
	
	if( i == 0 )
	  {
	     std::string hnameClone = hname + "_clone";
	     if( idx == 1 )
	       {
		  hnameClone += "_NOMINAL";
		  h_mc_NOMINAL[ivar] = (TH1D*)hf->Clone(hnameClone.c_str());
	       }	     
	     else if( idx == 0 )
	       {		  
		  hnameClone += "_RW";
		  h_mc_RW[ivar] = (TH1D*)hf->Clone(hnameClone.c_str());
	       }	     
	     else if( idx == 2 )
	       {		  
		  hnameClone += "_RW2";
		  h_mc_RW2[ivar] = (TH1D*)hf->Clone(hnameClone.c_str());
	       }	     
	  }	
	else
	  {
	     if( idx == 1 )
	       {		  
		  h_mc_NOMINAL[ivar]->Add(hf);
	       }	     
	     else if( idx == 0 )
	       {		  
		  h_mc_RW[ivar]->Add(hf);
	       }	     
	     else if( idx == 2 )
	       {		  
		  h_mc_RW2[ivar]->Add(hf);
	       }	     
	  }
     }

   if( idx == 1 )
     {	
	for(int i=0;i<v_data.size();i++)
	  {   
	     std::string hname = histName;
	     TH1D *hf = (TH1D*)fdata[i]->Get(hname.c_str());
	     if( i == 0 )
	       {
		  std::string hnameClone = hname + "_clone";
		  h_data[ivar] = (TH1D*)hf->Clone(hnameClone.c_str());
	       }	     
	     else
	       {
		  h_data[ivar]->Add(hf);
	       }
	  }
     }   

   if( idx == 1 )
     {	
	h_mc_NOMINAL[ivar] = (TH1D*)h_mc_NOMINAL[ivar]->Rebin(rb[ivar]);
	h_data[ivar] = (TH1D*)h_data[ivar]->Rebin(rb[ivar]);
     }   
   else if( idx == 0 )
     {
	h_mc_RW[ivar] = (TH1D*)h_mc_RW[ivar]->Rebin(rb[ivar]);
     }   
   else if( idx == 2 )
     {
	h_mc_RW2[ivar] = (TH1D*)h_mc_RW2[ivar]->Rebin(rb[ivar]);
     }   
}   

void readDataJP(std::string histName,bool isMC,int idx)
{
   if( isMC )
     {	
	for(int i=0;i<v_mc_filt->size();i++)
	  {   
	     std::string hname = histName;
	     TH1D *hf;
	     if( idx == 1 )
	       hf = (TH1D*)fmc_NOMINAL[i]->Get(hname.c_str());
	     else if( idx == 0 )
	       hf = (TH1D*)fmc_RW[i]->Get(hname.c_str());
	     else if( idx == 2 )
	       hf = (TH1D*)fmc_RW2[i]->Get(hname.c_str());

	     if( i == 0 )
	       {
		  std::string hnameClone = hname + "_clone";
		  if( idx == 1 )
		    {
		       hnameClone += "_NOMINAL";
		       h_untag_NOMINAL = (TH1D*)hf->Clone(hnameClone.c_str());
		    }	     
		  else if( idx == 0 )
		    {		  
		       hnameClone += "_RW";
		       h_untag_RW = (TH1D*)hf->Clone(hnameClone.c_str());
		    }	     
		  else if( idx == 2 )
		    {		  
		       hnameClone += "_RW2";
		       h_untag_RW2 = (TH1D*)hf->Clone(hnameClone.c_str());
		    }	     
	       }	  
	     else
	       {
		  if( idx == 1 )
		    {		       
		       h_untag_NOMINAL->Add(hf);
		    }		  
		  else if( idx == 0 )
		    {		       
		       h_untag_RW->Add(hf);
		    }		  
		  else if( idx == 2 )
		    {		       
		       h_untag_RW2->Add(hf);
		    }		  
	       }
	  }	
     }
   else
     {   	
	for(int i=0;i<v_data.size();i++)
	  {   
	     std::string hname = histName;
	     TH1D *hf = (TH1D*)fdata[i]->Get(hname.c_str());
	     if( i == 0 )
	       {
		  std::string hnameClone = hname + "_clone";
		  h_untag_NOMINAL = (TH1D*)hf->Clone(hnameClone.c_str());
	       }	     
	     else
	       {
		  h_untag_NOMINAL->Add(hf);
	       }
	  }
     }   
}   

void calcSF(int ivar,std::string name,TH1D *hMC,TH1D *hDATA)
{
   h_sf[ivar] = (TH1D*)hMC->Clone(name.c_str());
   
   for(int i=0;i<=h_sf[ivar]->GetXaxis()->GetNbins()+1;i++)
     {
	double v_mc = hMC->GetBinContent(i);
	double v_data = hDATA->GetBinContent(i);
	
	double v_mc_err = hMC->GetBinError(i);
	double v_data_err = hDATA->GetBinError(i);
	
	double v_sf = (v_mc > 0) ? v_data/v_mc : 1.;
	if( v_mc_err > 0 && v_mc/v_mc_err < 5. ) v_sf = 1.;
	if( v_data_err > 0 && v_data/v_data_err < 5. ) v_sf = 1.;
	
	h_sf[ivar]->SetBinContent(i,v_sf);
     }   
}
   
void plotCOMP(TH1D *hMC,TH1D *hDATA,std::string nname,std::string xTitle)
{
   TCanvas *c5 = new TCanvas("c5","c5",0,0,600,500);
   TPad *c5_1;
   c5->Range(0,0,1,1);
   c5_1 = new TPad("c5_1","main",0.01,0.33,0.99,0.99);
   c5_1->Draw();
   c5_1->cd();
		       
   hMC->SetLineColor(kBlue);
   hMC->SetMarkerSize(0);
   
   hDATA->SetMarkerSize(0.7);
   
   hMC->Draw("e1 hist");
   hDATA->Draw("e1p same");
   
   hMC->GetXaxis()->SetTitle(xTitle.c_str());
   
   double m1 = hMC->GetMaximum();
   double m2 = hDATA->GetMaximum();
   if( m1 > m2 ) hMC->SetMaximum(m1*1.15);
   else hMC->SetMaximum(m2*1.15);
   hMC->SetMinimum(0.0);
   
   // FIXME
//   hMC->GetXaxis()->SetRangeUser(0.,30.);
   
   TLegend *leg5 = new TLegend(0.70,0.90,0.92,0.70);
   leg5->SetHeader(ptlabel(PTname).c_str());
   leg5->SetFillColor(253);
   leg5->SetBorderSize(0);
   leg5->AddEntry(hDATA,"Data","lp");
   leg5->AddEntry(hMC,"MC","l");
   leg5->Draw();
   
   ratio(c5,hDATA,hMC);
		       
   std::string pname = "pics/sf_"+nname+".eps";
   c5->Print(pname.c_str());
   c5->Clear();
   delete leg5;   
}

void applySF(TH2D *hDEF,TH1D* hNEW,TH1D *hSF,TH1D *hNEWNOSCALE,std::string ax)
{
   if( ax == "y" )
     {	
	int nbx = hDEF->GetXaxis()->GetNbins();
	int nby = hDEF->GetYaxis()->GetNbins();
	
	for(int iy=0;iy<=nby+1;iy++)
	  {
	     double v_mc_rw = 0.;
	     double v_mc_sum = 0.;
	     for(int ix=0;ix<=nbx+1;ix++)
	       {
		  double v_mc = hDEF->GetBinContent(ix,iy);
		  double v_sf = hSF->GetBinContent(ix);
		  if( !sanityTest )
		    {				 
		       v_mc_rw += v_mc*v_sf;
		       v_mc_sum += v_mc;
		    }	
		  else
		    {
		       v_mc_rw += v_mc;
		       v_mc_sum += v_mc;
		    }			    
	       }			       
	     hNEW->SetBinContent(iy,v_mc_rw);
	     double v = hNEWNOSCALE->GetBinContent(iy);
	     double v_noscale = (v_mc_sum > 0) ? v*v_mc_rw/v_mc_sum : 0.;
	     hNEWNOSCALE->SetBinContent(iy,v_noscale);
	  }   
	if( hNEW->Integral(0,nby+1) > 0 ) hNEW->Scale(1./hNEW->Integral(0,nby+1));
     }
   else
     {
	int nbx = hDEF->GetXaxis()->GetNbins();
	int nby = hDEF->GetYaxis()->GetNbins();
	
	for(int ix=0;ix<=nbx+1;ix++)
	  {
	     double v_mc_rw = 0.;
	     double v_mc_sum = 0.;
	     for(int iy=0;iy<=nby+1;iy++)
	       {
		  double v_mc = hDEF->GetBinContent(ix,iy);
		  double v_sf = hSF->GetBinContent(iy);
		  if( !sanityTest )
		    {				 
		       v_mc_rw += v_mc*v_sf;
		       v_mc_sum += v_mc;
		    }	
		  else
		    {
		       v_mc_rw += v_mc;
		       v_mc_sum += v_mc;
		    }			    
	       }			       
	     hNEW->SetBinContent(ix,v_mc_rw);
	     double v = hNEWNOSCALE->GetBinContent(ix);
	     double v_noscale = (v_mc_sum > 0) ? v*v_mc_rw/v_mc_sum : 0.;
	     hNEWNOSCALE->SetBinContent(ix,v_noscale);
	  }   
	if( hNEW->Integral(0,nbx+1) > 0 ) hNEW->Scale(1./hNEW->Integral(0,nbx+1));
     }   
}

void doSys(TH1D *hINIT,TH1D *hRW,TH1D *hRW2,TH1D *hLOW,TH1D *hUP)
{
   int nby = hINIT->GetXaxis()->GetNbins();

   bool onlyRW = 1;
   
   for(int iy=0;iy<=nby+1;iy++)
     {
	double v_mc = hINIT->GetBinContent(iy);
	double v_mc_err = hINIT->GetBinError(iy);

	double v_mc_rw = hRW->GetBinContent(iy);
	double v_mc_rw_err = hRW->GetBinError(iy);
	double delta = v_mc-v_mc_rw;
	double deltaAbs = fabs(delta);
	
	double v_mc_rw2 = hRW2->GetBinContent(iy);
	double v_mc_rw_err2 = hRW2->GetBinError(iy);
	double delta2 = v_mc-v_mc_rw2;
	double deltaAbs2 = fabs(delta2);
	
	double v_up;
	double v_low;
	
	if( useCorMC )
	  {			    
	     v_up = v_mc_rw;
	     v_low = v_mc_rw;
	     if( doErrSym )
	       {		  
		  v_up = v_mc_rw+deltaAbs;
		  v_low = v_mc_rw-deltaAbs;
	       }	     
	     else
	       {
		  v_up = v_mc_rw+delta;
		  if( deltaAbs > v_mc_rw && delta < 0 ) v_up = 0.;
		  if( deltaAbs > v_mc_rw && delta >= 0 ) v_up = 2*v_mc_rw;
		  
		  v_low = v_mc_rw;
	       }	     
	     hLOW->SetBinContent(iy,v_low);
	     hLOW->SetBinError(iy,v_mc_rw_err);
	     hUP->SetBinContent(iy,v_up);
	  }
	else
	  {
	     v_up = v_mc;
	     v_low = v_mc;
	     if( doErrSym )
	       {
		  if( onlyRW )
		    {		       
		       v_up = v_mc+deltaAbs;
		       v_low = v_mc-deltaAbs;
		    }
		  else
		    {
		       double deltaAbsMax = (deltaAbs > deltaAbs2) ? deltaAbs : deltaAbs2;
		       v_up = v_mc+deltaAbsMax;
		       v_low = v_mc-deltaAbsMax;
		    }		  
	       }	     
	     else
	       {
		  if( onlyRW )
		    {		       
		       v_up = v_mc-delta;
		       if( deltaAbs > v_mc && delta > 0 ) v_up = 0.;
		       if( deltaAbs > v_mc && delta <= 0 ) v_up = 2*v_mc;
		       
		       v_low = v_mc;
		    }
		  else
		    {
		       v_up = v_mc-delta;
		       if( deltaAbs > v_mc && delta > 0 ) v_up = 0.;
		       if( deltaAbs > v_mc && delta <= 0 ) v_up = 2*v_mc;
		       
		       v_low = v_mc-delta2;
		       if( deltaAbs2 > v_mc && delta2 > 0 ) v_low = 0.;
		       if( deltaAbs2 > v_mc && delta2 <= 0 ) v_low = 2*v_mc;		       
		    }		  
	       }	     
	     hLOW->SetBinContent(iy,v_low);
	     hLOW->SetBinError(iy,v_mc_err);
	     hUP->SetBinContent(iy,v_up);
	  }		       
     }   
}

void plotSF(TH1D *hRW,TH1D *hNORW,TH1D *hLOW,TH1D *hUP,TH1D *hDATA,std::string nname)
{
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   TPad *c1_1;
   c1->Range(0,0,1,1);
   c1_1 = new TPad("c1_1","main",0.01,0.33,0.99,0.99);
   c1_1->Draw();
   c1_1->cd();

   hNORW->SetLineColor(kBlue);
   hNORW->SetMarkerSize(0);
   hRW->SetLineColor(kRed);
   hRW->SetMarkerSize(0);
   hRW->SetLineStyle(2);
   hDATA->SetLineColor(kBlack);
   hDATA->SetMarkerSize(0.7);
   
   hNORW->Draw("hist e1");
   hRW->Draw("hist e1 same");
   hDATA->Draw("e1p same");	
   
   double h_m1 = hNORW->GetMaximum();
   double h_m2 = hRW->GetMaximum();
   if( h_m1 > h_m2 ) hNORW->SetMaximum(h_m1*1.15);
   else hNORW->SetMaximum(h_m2*1.15);
   
   TLegend *legsfrw = new TLegend(0.65,0.90,0.92,0.65);
   legsfrw->SetFillColor(253);
   legsfrw->SetBorderSize(0);
   legsfrw->SetHeader(ptlabel(PTname).c_str());
   legsfrw->AddEntry(hNORW,"MC","lp");
   legsfrw->AddEntry(hRW,"MC(RW)","lp");
   legsfrw->AddEntry(hDATA,"Data","lp");
   legsfrw->Draw();
   
   hNORW->GetXaxis()->SetTitle("JP discriminator");
   hRW->GetXaxis()->SetTitle("JP discriminator");
   
//   c1_1->SetLogy(1);
   
   ratioErr(c1,hRW,hNORW,hLOW,hUP,rw);
   
   std::string pname = "pics/sfrw_"+nname+".eps";
   c1->Print(pname.c_str());
   c1->Clear();
   
   delete legsfrw;
   delete c1;
}

void plotSYS(TH1D *hRW,TH1D *hRW2,TH1D *hNORW,TH1D *hLOW,TH1D *hUP,TH1D *hDATA,std::string nname)
{   
   TCanvas *c2 = new TCanvas("c2","c2",0,0,600,500);
   
   hRW->SetLineColor(kRed);
   hRW->SetMarkerSize(0);
   hRW->SetLineStyle(2);
		  
   hRW->Draw("hist e1");

   hRW2->SetLineColor(kMagenta);
   hRW2->SetMarkerSize(0);
   hRW2->SetLineStyle(3);
		  
   hRW2->Draw("hist e1 same");

   TGraphAsymmErrors *gr_mc_merged;
   
/*   if( useCorMC )
     gr_mc_merged = makeErrorBand(hRW,
				  hUP,
				  hLOW);
   else
     gr_mc_merged = makeErrorBand(hNORW,
				  hUP,
				  hLOW);
   
   gr_mc_merged->SetFillStyle(3004);
   gStyle->SetHatchesLineWidth(2);
   gr_mc_merged->Draw("2SAME"); FIXME*/
   
   hNORW->Draw("hist same");
		  
   hRW->SetMaximum(hRW->GetMaximum()*1.15);
   
   hRW->GetXaxis()->SetTitle("JP discriminator");
   
   //		  c2->SetLogy(1);
		  
   std::string pname2 = "pics/valsys_"+nname+".eps";
   c2->Print(pname2.c_str());
   c2->Clear();
   delete c2;
   
   TCanvas *c3 = new TCanvas("c3","c3",0,0,600,500);

   TH1D *hRW_scale = (TH1D*)hRW->Clone();
   TH1D *hRW2_scale = (TH1D*)hRW2->Clone();
   
   hNORW->SetLineColor(kBlue);
   hNORW->SetMarkerSize(0);
   hRW_scale->SetLineColor(kRed);
   hRW_scale->SetMarkerSize(0);
   hRW_scale->SetLineStyle(2);
   hRW2_scale->SetLineColor(kMagenta);
   hRW2_scale->SetMarkerSize(0);
   hRW2_scale->SetLineStyle(3);
   hDATA->SetLineColor(kBlack);
   hDATA->SetMarkerSize(0.7);

   int nby = hNORW->GetXaxis()->GetNbins();
   
   if( hNORW->Integral(0,nby+1) > 0 ) hNORW->Scale(1./hNORW->Integral(0,nby+1));
   hNORW->Draw("hist e1");
   if( hRW_scale->Integral(0,nby+1) > 0 ) hRW_scale->Scale(1./hRW_scale->Integral(0,nby+1));
   hRW_scale->Draw("hist e1 same");
   if( hRW2_scale->Integral(0,nby+1) > 0 ) hRW2_scale->Scale(1./hRW2_scale->Integral(0,nby+1));
   hRW2_scale->Draw("hist e1 same");
   if( hDATA->Integral(0,nby+1) > 0 ) hDATA->Scale(1./hDATA->Integral(0,nby+1));
   hDATA->Draw("e1p same");
   
   double h_m1 = hNORW->GetMaximum();
   double h_m2 = hRW_scale->GetMaximum();
   double h_m3 = hRW2_scale->GetMaximum();
   if( h_m1 > h_m2 ) hNORW->SetMaximum(h_m1*1.15);
   else hNORW->SetMaximum(h_m2*1.15);   
   if( h_m3 > h_m1 && h_m3 > h_m2 ) hNORW->SetMaximum(h_m3*1.15);
   
   leg->Clear();
   leg->AddEntry(hNORW,"MC","lp");
   leg->AddEntry(hRW_scale,"MC(RW)","lp");
   leg->AddEntry(hRW2_scale,"MC2(RW)","lp");
   leg->AddEntry(hDATA,"Data","lp");
   leg->Draw();
   
   hNORW->GetXaxis()->SetTitle("JP discriminator");
   
//   c3->SetLogy(1);
   
   std::string pname3 = "pics/val_"+nname+".eps";
   c3->Print(pname3.c_str());
   c3->Clear();
   delete c3;
}

void valSys(TH1D *hNOM,TH1D *hLOW,TH1D *hUP)
{   
   for(int b=0;b<=hNOM->GetXaxis()->GetNbins()+1;b++)
     {
	double vnom = hNOM->GetBinContent(b);
	double vlow = hLOW->GetBinContent(b);
	double vup = hUP->GetBinContent(b);
	if( vnom < vlow ) 
	  {
	     if( fabs(vnom-vlow) < 10E-6 )
	       {
		  vlow = vnom;
		  hLOW->SetBinContent(b,vlow);
	       }
/*FIXME	     else
	       {				 
		  std::cout << "Validation failed" << std::endl;
		  std::cout << b << " vnom=" << vnom << " vlow=" << vlow << std::endl;
		  exit(1);
	       }*/
	  }
     }
}

void multiSF(TH1D* h1,TH1D* h2)
{
   int nb = h1->GetXaxis()->GetNbins();
   for(int i=0;i<=nb+1;i++)
     {
	double sfNew = h1->GetBinContent(i)*h2->GetBinContent(i);
	h1->SetBinContent(i,sfNew);
     }   
}

#endif
