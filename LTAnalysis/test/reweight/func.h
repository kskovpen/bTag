#ifndef RWFUNC_H
#define RWFUNC_H

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

#include "atlasstyle-00-03-04_gcc491/AtlasStyle.h"
#include "atlasstyle-00-03-04_gcc491/AtlasUtils.h"

#include "addbin.h"
#include "addbin2D.h"
#include "ratioErr.h"
#include "ratio.h"
#include "makeErrorBand.h"

TFile *fdata[1000];
TFile *fmc[1000];

void openData(std::string);
void readData(std::string,int,std::string);
void calcSF_3d(int,std::string,TH3D*,TH3D*);
void calcSF_2d(int,std::string,TH2D*,TH2D*);
void calcSF_1d(int,std::string,TH1D*,TH1D*);

double errf_UNCOR(double,double,double,double);

//const int nvar1d = 4;
const int nvar1d = 1;
const int nvar2d = 1;
const int nvar3d = 1;

bool overwrite;

TH3D *h_data_3d[nvar3d], *h_mc_3d[nvar3d];
TH3D *h_sf_3d[nvar3d];
TH2D *h_data_2d[nvar2d], *h_mc_2d[nvar2d];
TH2D *h_sf_2d[nvar2d];
TH1D *h_data_1d[nvar1d], *h_mc_1d[nvar1d];
TH1D *h_sf_1d[nvar1d];
TLegend *leg;

//const int nptbin = 19;
//std::string ptbin[nptbin] = { "nosel","pt20t30","pt30t40","pt40t50","pt50t60","pt60t70","pt70t80",
//   "pt80t100","pt100t120","pt120t160","pt160t210","pt210t260","pt260t320","pt320t400",
//   "pt400t500","pt500t600","pt600t800","pt800t1000","pt1000t1400"};
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
   "pt400t450","pt450t500","pt500t585","pt585t670","pt670t1000"};*/
//const int nptbin = 10;
//std::string ptbin[nptbin] = { "nosel","pt20t40","pt40t60","pt60t80",
//   "pt80t120","pt120t210","pt210t320","pt320t500",
//   "pt500t1000","pt1000t1400"};
//const int nptbin = 6;
//std::string ptbin[nptbin] = { "nosel","pt30t50","pt50t80","pt80t120","pt120t210","pt210t320" };
const int nflav = 4;
std::string flav[nflav] = {"ajet_","bjet_","cjet_","ljet_"};
//const int nbtag = 3;
//std::string btag[nbtag] = {"_nosel","_combSvx0p679","_UNTAGbc"};
//std::string btag[nbtag] = {"_nosel","_combSvx0p244","_UNTAGbc"};
//std::string btag[nbtag] = {"_nosel","_combSvx0p898","_UNTAGbc"};
//const int nbtag = 5;
const int nbtag = 3;
//std::string btag[nbtag] = {"_nosel","_combSvx0p244","_combSvx0p679","_combSvx0p898","_UNTAGbc"};
//std::string btag[nbtag] = {"_nosel","_TCHP1p19","_TCHP1p93","_TCHP3p41","_UNTAGbc"};
//std::string btag[nbtag] = {"_nosel","_combSvx0p244","_combSvx0p679","_combSvx0p898",
//   "_TCHP1p19","_TCHP1p93","_TCHP3p41","_UNTAGbc"};
std::string btag[nbtag] = {"_nosel","_combSvx0p244","_UNTAGbc"};
std::string var3d[nvar3d] = {
   "h_j1_ntrk_vs_pt_vs_mupt_"
};
std::string var3dx[nvar3d] = {
   "3d_ntrk_pt_mupt"
};

std::string var2d[nvar2d] = {
   "h_j1_nseltrk_vs_njet_"
};
std::string var2dx[nvar2d] = {
   "2d_nseltrk_vs_njet"
};

std::string var1d[nvar1d] = {
//   "h_j1_nsv_"
//   "h_j1_ntrk_"
//   "h_j1_njet_"
//   "h_j1_mupt_"
//   "h_j1_eta_"
//   "h_j1_pt_"
   "h_j1_nseltrk_"
};
std::string var1dx[nvar1d] = {
//   "1d_nsv"
//   "1d_ntrk"
//   "1d_njet"
//   "1d_mupt"
//   "1d_eta"
//   "1d_pt"
   "1d_nseltrk"
};

void openData(std::string fpath)
{   
   for(int i=0;i<v_mc_filt->size();i++)
     {
	std::string fname = fpath+v_mc_filt->at(i);
	fmc[i] = TFile::Open(fname.c_str());
     }

   for(int i=0;i<v_data.size();i++)
     {
	std::string fname = fpath+v_data.at(i);
	fdata[i] = TFile::Open(fname.c_str());
     }   
}

void readData(std::string histName,int ivar,std::string type)
{
   for(int i=0;i<v_mc_filt->size();i++)
     {   
	std::string hname = histName;
	if( type == "3d" )
	  {	     
	     TH3D *hf = (TH3D*)fmc[i]->Get(hname.c_str());
	     if( i == 0 )
	       {
		  std::string hnameClone = hname + "_clone";
		  h_mc_3d[ivar] = (TH3D*)hf->Clone(hnameClone.c_str());
	       }	  
	     else
	       {
		  h_mc_3d[ivar]->Add(hf);
	       }
	  }	
	if( type == "2d" )
	  {	     
	     TH2D *hf = (TH2D*)fmc[i]->Get(hname.c_str());
	     if( i == 0 )
	       {
		  std::string hnameClone = hname + "_clone";
		  h_mc_2d[ivar] = (TH2D*)hf->Clone(hnameClone.c_str());
	       }	  
	     else
	       {
		  h_mc_2d[ivar]->Add(hf);
	       }
	  }	
	if( type == "1d" )
	  {	     
	     TH1D *hf = (TH1D*)fmc[i]->Get(hname.c_str());
	     if( i == 0 )
	       {
		  std::string hnameClone = hname + "_clone";
		  h_mc_1d[ivar] = (TH1D*)hf->Clone(hnameClone.c_str());
	       }	  
	     else
	       {
		  h_mc_1d[ivar]->Add(hf);
	       }
	  }	
     }
   
   for(int i=0;i<v_data.size();i++)
     {   
	std::string hname = histName;
	if( type == "3d" )
	  {	     
	     TH3D *hf = (TH3D*)fdata[i]->Get(hname.c_str());
	     if( i == 0 )
	       {
		  std::string hnameClone = hname + "_clone";
		  h_data_3d[ivar] = (TH3D*)hf->Clone(hnameClone.c_str());
	       }	  
	     else
	       {
		  h_data_3d[ivar]->Add(hf);
	       }
	  }
	if( type == "2d" )
	  {	     
	     TH2D *hf = (TH2D*)fdata[i]->Get(hname.c_str());
	     if( i == 0 )
	       {
		  std::string hnameClone = hname + "_clone";
		  h_data_2d[ivar] = (TH2D*)hf->Clone(hnameClone.c_str());
	       }	  
	     else
	       {
		  h_data_2d[ivar]->Add(hf);
	       }
	  }	
	if( type == "1d" )
	  {	     
	     TH1D *hf = (TH1D*)fdata[i]->Get(hname.c_str());
	     if( i == 0 )
	       {
		  std::string hnameClone = hname + "_clone";
		  h_data_1d[ivar] = (TH1D*)hf->Clone(hnameClone.c_str());
	       }	  
	     else
	       {
		  h_data_1d[ivar]->Add(hf);
	       }
	  }	
     }
}   

void calcSF_3d(int ivar,std::string name,TH3D *hMC,TH3D *hDATA)
{
   h_sf_3d[ivar] = (TH3D*)hMC->Clone(name.c_str());
   
   for(int i=0;i<=h_sf_3d[ivar]->GetXaxis()->GetNbins()+1;i++)
     {
	for(int j=0;j<=h_sf_3d[ivar]->GetYaxis()->GetNbins()+1;j++)
	  {
	     for(int k=0;k<=h_sf_3d[ivar]->GetZaxis()->GetNbins()+1;k++)
	       {
		  double v_mc = hMC->GetBinContent(i,j,k);
		  double v_data = hDATA->GetBinContent(i,j,k);
		  
		  double v_mc_err = hMC->GetBinError(i,j,k);
		  double v_data_err = hDATA->GetBinError(i,j,k);
		  
		  double v_sf = (v_mc > 0) ? v_data/v_mc : 1.;
		  //		  if( v_mc_err > 0 && v_mc/v_mc_err < 5. ) v_sf = 1.;
		  //		  if( v_data_err > 0 && v_data/v_data_err < 5. ) v_sf = 1.;
		  
		  h_sf_3d[ivar]->SetBinContent(i,j,k,v_sf);
	       }
	  }	
     }   
}

void calcSF_2d(int ivar,std::string name,TH2D *hMC,TH2D *hDATA)
{
   h_sf_2d[ivar] = (TH2D*)hMC->Clone(name.c_str());
   
   for(int i=0;i<=h_sf_2d[ivar]->GetXaxis()->GetNbins()+1;i++)
     {
	for(int j=0;j<=h_sf_2d[ivar]->GetYaxis()->GetNbins()+1;j++)
	  {
	     double v_mc = hMC->GetBinContent(i,j);
	     double v_data = hDATA->GetBinContent(i,j);
	     
	     double v_mc_err = hMC->GetBinError(i,j);
	     double v_data_err = hDATA->GetBinError(i,j);
	     
	     double v_sf = (v_mc > 0) ? v_data/v_mc : 1.;
	     //		  if( v_mc_err > 0 && v_mc/v_mc_err < 5. ) v_sf = 1.;
	     //		  if( v_data_err > 0 && v_data/v_data_err < 5. ) v_sf = 1.;
	     
	     h_sf_2d[ivar]->SetBinContent(i,j,v_sf);
	  }	
     }   
}
void calcSF_1d(int ivar,std::string name,TH1D *hMC,TH1D *hDATA)
{
   h_sf_1d[ivar] = (TH1D*)hMC->Clone(name.c_str());
   
   for(int i=0;i<=h_sf_1d[ivar]->GetXaxis()->GetNbins()+1;i++)
     {
	double v_mc = hMC->GetBinContent(i);
	double v_data = hDATA->GetBinContent(i);
	
	double v_mc_err = hMC->GetBinError(i);
	double v_data_err = hDATA->GetBinError(i);
		  
	double v_sf = (v_mc > 0) ? v_data/v_mc : 1.;
	double v_sf_err = errf_UNCOR(v_data,v_data_err,v_mc,v_mc_err);
	
//	if( v_mc_err > 0 && v_mc/v_mc_err < 5. ) {v_sf = 1.; v_sf_err = 0.;}
//	if( v_data_err > 0 && v_data/v_data_err < 5. ) {v_sf = 1.; v_sf_err = 0.;}
	
	h_sf_1d[ivar]->SetBinContent(i,v_sf);
	h_sf_1d[ivar]->SetBinError(i,v_sf_err);
     }   
}

double errf_UNCOR(double v1,double ve1,double v2,double ve2)
{
   if( v2 == 0 || v1 == 0 ) return 0;

   double err = ve1*ve1/v1/v1+ve2*ve2/v2/v2;
   
   err = sqrt(err)*v1/v2;
   
   return err;   
}

#endif
