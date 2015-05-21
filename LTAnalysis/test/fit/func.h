#ifndef FITFUNC_H
#define FITFUNC_H

// use fcnSys for chi2
// use fcnSysM for covariance 

#include "TROOT.h"
#include "TStyle.h"
#include "TFile.h"
#include "TLine.h"
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
#include "TMatrixD.h"
#include "TMatrixDSym.h"
// general
#include "TDecompLU.h"
#include "TDecompQRH.h"
// symmetric
#include "TDecompChol.h"
#include "TDecompBK.h"

#include "TRandom3.h"

#include "TFractionFitter.h"

#include "atlasstyle-00-03-04_gcc491/AtlasStyle.h"
#include "atlasstyle-00-03-04_gcc491/AtlasUtils.h"
//#include "atlasstyle-00-03-04/AtlasLabels.h"

#include "addbin.h"
#include "addbin2D.h"
#include "removeMCNeg.h"
#include "removeMCSys.h"
#include "makeErrorBand.h"
#include "adjust.h"
#include "label.h"

#include "def.h"

#include <iostream>

const double PI = 3.141592653589793238462;
bool comflag;

void ATLASLabel(Double_t,Double_t,std::string,Color_t);

double fnorm(TH1D*,TH1D*);
void plotFracSys(TH1D*,TH1D*,TH1D*,std::string,std::string,int,std::string,bool);
void plotFracSysNew(TH1D*,TH1D*,TH1D*,std::string,std::string,int,bool);
double bbCorr(TH1D*,TH1D*);

double fsb = 1.;
double fsc = 1.;
double fsl = 1.;
/*double fsb = pow(10,-3);
double fsc = pow(10,-3);
double fsl = pow(10,-4);*/

bool replaceDataByMC = 0;

double fr = 1.;

bool doMergeBins = 1;

std::vector<int> vecM;
const int vecM_MAX = 100;
TMatrixD covM(vecM_MAX,vecM_MAX);
TMatrixD covMI(vecM_MAX,vecM_MAX);
TMatrixD *covMIp;
double cov[vecM_MAX][vecM_MAX];
double covFCUR;
double norm1D[vecM_MAX];
TVectorD *norm1Dp;
TVectorD vconv(vecM_MAX);

double parg[3];
double perg[3];

double fracB_MCDEFAULT = 1;
double fracC_MCDEFAULT = 1;
double fracL_MCDEFAULT = 1;

double fracB_MCDEFAULT_TRUE = 1;
double fracC_MCDEFAULT_TRUE = 1;
double fracL_MCDEFAULT_TRUE = 1;

TCanvas *c1;
TLegend *leg;
TFile *fcov;

bool doFracFit = 0;
int asymm = 1; // 0 - Barlow, 1 - symm
bool doSystSymm = 0; // cross-check for MINUIT errors

//int nbm1d = 2.5;
int nbm2d = 10;
int ibinMin = 1;
int ibinMax = 1000;
//int ibinMax = 10;

bool usePRETAGb = 0; // use pre-tag b-templates in post-tag fit
bool usePRETAGc = 0; // use pre-tag c-templates in post-tag fit
// set doSub=0 if to plot subtraction
int doSub = 0; // subtract b from ljet_data
int doSubC = 0; // subtract c-jets from ljet_data (works together with doSub)
int doCL = 0; // c+l
int doCorrNorm = 0; // correct normalisation for systematics shape (avoid incorrect normalisation due to spikes)

std::string untag = "UNTAGbc"; // UNTAGb, UNTAGbc
int ljetData = 0; // take l-jet template from data

int nbFitAdjust;
double dataFitAdjust;
double limFitAdjust = 0.;

int nbFitAdjust2d;
double dataFitAdjust2d;
double limFitAdjust2d = 0.;

int nbFitAdjustCL;
double dataFitAdjustCL;
double limFitAdjustCL = 0.;

std::string sysNameGL = "";

const std::string mainFIT = "h_j1_vBTsv0p_";
const std::string mainPTRW = "h_j1_pt_";

int iVARcur = -1;
int iPTcur = -1;
int iBTAGcur = -1;
std::string hname_bjet_cur = "";
std::string hname_cjet_cur = "";
std::string hname_ljet_cur = "";
std::string hname_ajet_cur = "";
std::string hname_ljet_data_cur = "";

std::string hname_bjet_nominal = "";
std::string hname_cjet_nominal = "";
std::string hname_ljet_nominal = "";
std::string hname_bjet_nominalInit = "";
std::string hname_cjet_nominalInit = "";
std::string hname_ljet_nominalInit = "";
std::string hname_bjet_nominalTrue = "";
std::string hname_cjet_nominalTrue = "";
std::string hname_ljet_nominalTrue = "";
std::string hname_bjet_sysUp = "";
std::string hname_cjet_sysUp = "";
std::string hname_ljet_sysUp = "";
std::string hname_bjet_sysDown = "";
std::string hname_cjet_sysDown = "";
std::string hname_ljet_sysDown = "";

int sysIdx = 0; // +-1 - +-nSysMax, shift nominal shape with sys, 0 - no sys

//const int nsys = 1;
//const int nsys = 5;
const int nsys = 10;
// !!
//const int nsys = 14;
// !!
//const int nsys = 11;
int nsysGL = nsys;

/*const int hnnPT = 19;
std::string hnamePT[hnnPT] = {
   "nosel",
     "pt20t30",
     "pt30t40",
     "pt40t50",
     "pt50t60",
     "pt60t70",
     "pt70t80",
     "pt80t100",
     "pt100t120",
     "pt120t160",
     "pt160t210",
     "pt210t260",
     "pt260t320",
     "pt320t400",
     "pt400t500",
     "pt500t600",
     "pt600t800",
     "pt800t1000",
     "pt1000t1400"
};*/


/*const int hnnPT = 31;
std::string hnamePT[hnnPT] = { "nosel","pt20t25","pt25t30","pt30t35","pt35t40",
   "pt40t45","pt45t50","pt50t55","pt55t60","pt60t65","pt65t70","pt70t75","pt75t80",
   "pt80t90","pt90t100","pt100t110","pt110t120","pt120t140","pt140t160",
   "pt160t185","pt185t210","pt210t235","pt235t260","pt260t290","pt290t320",
   "pt320t360","pt360t400",
   "pt400t450","pt450t500","pt500t585","pt585t670"};*/

const int hnnPT = 16;
std::string hnamePT[hnnPT] = {
   "nosel",
     "pt20t30",
     "pt30t40",
     "pt40t50",
     "pt50t60",
     "pt60t70",
     "pt70t80",
     "pt80t100",
     "pt100t120",
     "pt120t160",
     "pt160t210",
     "pt210t260",
     "pt260t320",
     "pt320t400",
     "pt400t500",
     "pt500t670"
};

/*
const int hnnPT = 10;
std::string hnamePT[hnnPT] = {
   "nosel",
     "pt20t40",
     "pt40t60",
     "pt60t80",
     "pt80t120",
     "pt120t210",
     "pt210t320",
     "pt320t500",
     "pt500t1000",
     "pt1000t1400"
};*/

/*const int hnnPT = 6;
std::string hnamePT[hnnPT] = {
   "nosel",
     "pt30t50",
     "pt50t80",
     "pt80t120",
     "pt120t210",
     "pt210t320"
//     "pt320t500"
//     "pt500t800"
};*/

double removeFromFit[hnnPT];
double removeFromFitMin[hnnPT];

/*int nbm1d[hnnPT] = {
   1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1
};*/

int nbm1d[hnnPT] = {
   1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1
};

/*
int nbm1d[hnnPT] = {
   1,1,1,1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,1,1,1,1
};*/

/*
int nbm1d[hnnPT] = {
   1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1,
     1
};*/

/*
int nbm1d[hnnPT] = {
   1,
     1,
     1,
     1,
     1,
     1
};*/

/*double covF[hnnPT] = {
   1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.
};*/

double covF[hnnPT] = {
   1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.
};

/*double covF[hnnPT] = {
   1,1,1,1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,1,1,1,1
};*/

/*
double covF[hnnPT] = {
   1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.,
     1.
};*/

/*
double covF[hnnPT] = {
   1.,
     1.,
     1.,
     1.,
     1.,
     1.
};*/

const int hnnETA = 1;
std::string hnameETA[hnnETA] = {
   "nosel"
//     "eta0p0t0p6"
//     "eta0p6t1p2",
//     "eta1p2t1p8",
//     "eta1p8t2p5"
};

const int hnnVAR = 2;
std::string hnameVAR[hnnVAR] = {
////   mainPTRW, // has to be the variable for pt rw
//     "h_j1_vBTsv0p_",
//     "h_j1_vPTsv0p_"
////     "h_j1_d0SignJet1_"
   "h_j1_pt_",
   "h_j1_JP_"
//     "h_j1_JPRW_"
//     "h_j1_d0Sign1_"
//     "h_j1_d0SignJet3_",
//     "h_j1_d0SignJet3_",
////     "h_j1_d0SignMuonTight_",
//     "h_j1_d0SignJetMuonTight_",
////     "h_j1_muonTightPtRel_",
////     "h_j1_muonTightPtRelSV_"
//     "h_j1_sv0mass_",
//     "h_j1_wSV0_",
//     "h_j1_wJetProb_"
//     "h_j2_vBTsv0p_",
//     "h_j2_vPTsv0p_"
//     "h_j2_sv0mass_",
//     "h_j2_wSV0_",
//     "h_j2_wJetProb_"
//     "h_j1_rsv0p_",
//     "h_j1_ntrk_",
//     "h_j1_drW_"
};   

// 2D FIT IS DONE AND APPLIED AFTERWARDS ONLY FOR THE LAST NAME
const int hnnVAR2D = 0;
std::string hnameVAR2D[hnnVAR2D] = {
//   "h_j1_sv0mass_vs_wSV0_",
//     "h_j1_vPTsv0p_vs_wSV0_",
//     "h_j1_vBTsv0p_vs_wSV0_",
//     "h_j1_vBTsv0p_vs_vPTsv0p_"
//     "h_j1_d0SignJetMuonLoose_vs_muonLoosePt_",
//     "h_j1_d0SignJet1_vs_d0SignJet2_"
//     "h_j1_d0SignJet1_vs_d0SignJetMuonTight_"
//   "h_j1_d0SignJet2_vs_d0SignJetMuonTight_"
//     "h_j1_d0SignJet1_vs_d0SignJet2_"
//     "h_j1_d0SignJet2_vs_d0SignJetMuonLoose_",
//     "h_j1_d0SignJet3_vs_d0SignJetMuonLoose_",
//     "h_j1_d0SignJet2_vs_MV1_",
//     "h_j1_d0SignJet2_vs_MV2_",
//     "h_j1_d0SignJet2_vs_JetFitterCOMBNN_",
//     "h_j1_d0SignJet2_vs_TrackCounting2D_",
//     "h_j1_d0SignJet2_vs_Comb_",
//     "h_j1_d0SignJet2_vs_NewGbbNN_",
//     "h_j1_d0SignJet2_vs_SV1_",
//     "h_j1_d0SignJet2_vs_SV2_",
//     "h_j1_d0SignJet2_vs_d0SignJet3_",
//     "h_j1_d0SignJet1_vs_d0SignJet2_"
//     "h_j1_d0SignJet1_vs_d0SignJetMuonLoose_"
//     "h_j1_d0Sign2_vs_d0Sign3_"
//     "h_j1_sv0mass_vs_wSV0_"
//   "h_j1_vBTsv0p_vs_vPTsv0p_"
//     "h_j2_sv0mass_vs_wSV0_"
};

const int hnnFLAV = 3;
std::string hnameFLAV[hnnFLAV] = {
   "bjet_",
     "cjet_",
     "ljet_"
//     "ajet_"
};   

const int hnnBTAG = 2;
std::string hnameBTAG[hnnBTAG] = {
   "_nosel",
//   "_sv0",
//   "_sv0pc5p65",
//     "_ip3dsv1c4p55",
//     "_ip3dsv1c1p70",
//     "_ip3dsv1cm0p80"
//     "_jetfittercombnnc1p10"
//     "_jetfittercombnnc0p65"
//     "_jetfittercombnncm0p95"
//     "_jetfittercombnncm2p60"
//     "_mv1c0p985"
////     "_mv1c0p0616"
//     "_combSvx0p679"
     "_combSvx0p244"
//   "_combSvx0p898"
//   "_TCHP1p19"
//   "_TCHP1p93"
//   "_TCHP3p41"
////     "_mv1c0p9925154"
//     "_mv1c0p596"
///     "_mv1c0p148"
};   

std::ofstream fout;
std::ofstream foutPTRW;
std::ofstream check;
std::ofstream foutSys;

std::string name_sys_low[nsys];
std::string name_sys_up[nsys];
double covFactor[nsys];
double binFactor[nsys][100];
//std::string name_sys_low[2];
//std::string name_sys_up[2];

// 1-D data fit
int nbins;
double 
  data[10000],
  data_err[10000],
  mc_bjet[10000],
  mc_cjet[10000],
  mc_ljet[10000],
  data_ljet[10000],
  mc_bcljet[10000],
  mc_cljet[10000],
  mc_bjet_err[10000],
  mc_cjet_err[10000],
  mc_ljet_err[10000],
  data_ljet_err[10000],
  mc_bcljet_err[10000],
  mc_cljet_err[10000],
  errorz[10000];

int nbins2dx;
int nbins2dy;
double 
  data_2d[1000][1000],
  data_err_2d[1000][1000],
  mc_bjet_2d[1000][1000],
  mc_cjet_2d[1000][1000],
  mc_ljet_2d[1000][1000],
  data_ljet_2d[1000][1000],
  mc_cljet_2d[1000][1000],
  mc_bcljet_2d[1000][1000],
  mc_bjet_err_2d[1000][1000],
  mc_cjet_err_2d[1000][1000],
  mc_ljet_err_2d[1000][1000],
  data_ljet_err_2d[1000][1000],
  mc_cljet_err_2d[1000][1000],
  mc_bcljet_err_2d[1000][1000],
  errorz_2d[1000][1000];

//TFile *fbatch_mc_filt[1000][100];
//TFile *fbatch_mc_unfilt[1000][100];
//TFile *fbatch_data[1000][100];
TFile *fbatch_mc_filt[1000];
TFile *fbatch_mc_unfilt[1000];
TFile *fbatch_data[1000];
TFile *fMCJ0[100];
TFile *fMCJ1[100];
TFile *fMCJ2[100];
TFile *fMCJ3[100];
TFile *fMCJ4[100];
TFile *fMCJ5[100];
TFile *fMCJ6[100];
TFile *fMCJ7[100];
TFile *fMCJ8[100];
TFile *fDATA[100];

TH1D *h_mc_merged[10000];
TH1D *h_mc_merged_sys_up[10000];
TH1D *h_mc_merged_sys_low[10000];

TH1D *h_draw_bjet_sys_up[nsys][10000];
TH1D *h_draw_bjet_sys_low[nsys][10000];
TH1D *h_draw_bjet_sys_up_comb[10000];
TH1D *h_draw_bjet_sys_low_comb[10000];

TH1D *h_draw_cjet_sys_up[nsys][10000];
TH1D *h_draw_cjet_sys_low[nsys][10000];
TH1D *h_draw_cjet_sys_up_comb[10000];
TH1D *h_draw_cjet_sys_low_comb[10000];

TH1D *h_draw_bjet_untag_sys_up[nsys][10000];
TH1D *h_draw_bjet_untag_sys_low[nsys][10000];
TH1D *h_draw_bjet_untag_sys_up_comb[10000];
TH1D *h_draw_bjet_untag_sys_low_comb[10000];

TH1D *h_draw_cjet_untag_sys_up[nsys][10000];
TH1D *h_draw_cjet_untag_sys_low[nsys][10000];
TH1D *h_draw_cjet_untag_sys_up_comb[10000];
TH1D *h_draw_cjet_untag_sys_low_comb[10000];
/*
TH1D *h_draw_bjet_notag_sys_up[nsys][10000];
TH1D *h_draw_bjet_notag_sys_low[nsys][10000];
TH1D *h_draw_bjet_notag_sys_up_comb[10000];
TH1D *h_draw_bjet_notag_sys_low_comb[10000];

TH1D *h_draw_cjet_notag_sys_up[nsys][10000];
TH1D *h_draw_cjet_notag_sys_low[nsys][10000];
TH1D *h_draw_cjet_notag_sys_up_comb[10000];
TH1D *h_draw_cjet_notag_sys_low_comb[10000];
*/
TH1D *h_draw_bjet_posttag_sys_up[nsys][10000];
TH1D *h_draw_bjet_posttag_sys_low[nsys][10000];
TH1D *h_draw_bjet_posttag_sys_up_comb[10000];
TH1D *h_draw_bjet_posttag_sys_low_comb[10000];

TH1D *h_draw_cjet_posttag_sys_up[nsys][10000];
TH1D *h_draw_cjet_posttag_sys_low[nsys][10000];
TH1D *h_draw_cjet_posttag_sys_up_comb[10000];
TH1D *h_draw_cjet_posttag_sys_low_comb[10000];

TH1D *h_draw_ljet_sys_up[nsys][10000];
TH1D *h_draw_ljet_sys_low[nsys][10000];
TH1D *h_draw_ljet_sys_up_comb[10000];
TH1D *h_draw_ljet_sys_low_comb[10000];

TH1D *h_draw_ljet_data_sys_up[nsys][10000];
TH1D *h_draw_ljet_data_sys_low[nsys][10000];
TH1D *h_draw_ljet_data_sys_up_comb[10000];
TH1D *h_draw_ljet_data_sys_low_comb[10000];

TH1D *h_draw_ajet_sys_up[nsys][10000];
TH1D *h_draw_ajet_sys_low[nsys][10000];
TH1D *h_draw_ajet_sys_up_comb[10000];
TH1D *h_draw_ajet_sys_low_comb[10000];

TH1D *h_draw_bcljet_comb[10000];
TH1D *h_draw_bcljet_sys_up_comb[10000];
TH1D *h_draw_bcljet_sys_low_comb[10000];

TH1D *h_draw_bcljet_combNATURAL[10000];
TH1D *h_draw_bcljet_sys_up_combNATURAL[10000];
TH1D *h_draw_bcljet_sys_low_combNATURAL[10000];

TH1D *h_draw_bjet_sys_up_combSum[10000];
TH1D *h_draw_bjet_sys_low_combSum[10000];

TH1D *h_draw_cjet_sys_up_combSum[10000];
TH1D *h_draw_cjet_sys_low_combSum[10000];

TH1D *h_draw_ljet_sys_up_combSum[10000];
TH1D *h_draw_ljet_sys_low_combSum[10000];

TH1D *h_draw_ljet_data_sys_up_combSum[10000];
TH1D *h_draw_ljet_data_sys_low_combSum[10000];

TH1D *h_draw_bcljet_sys_up_combSum[10000];
TH1D *h_draw_bcljet_sys_low_combSum[10000];

TGraphAsymmErrors* gr_mc_merged[10000];
TGraphAsymmErrors* gr_mc_bjet[10000];
TGraphAsymmErrors* gr_mc_cjet[10000];
TGraphAsymmErrors* gr_mc_ljet[10000];
TGraphAsymmErrors* gr_mc_ljet_data[10000];

TH1D *h_draw_bjet[100];
TH1D *h_draw_cjet[100];
TH1D *h_draw_bjet_untag[100];
TH1D *h_draw_cjet_untag[100];
//TH1D *h_draw_bjet_notag[100];
//TH1D *h_draw_cjet_notag[100];
TH1D *h_draw_bjet_posttag[100];
TH1D *h_draw_cjet_posttag[100];
TH1D *h_draw_ljet_posttag[100];
TH1D *h_draw_ajet_data_posttag[100];
TH1D *h_draw_bjet_notag[100];
TH1D *h_draw_cjet_notag[100];
TH1D *h_draw_ljet_notag[100];
TH1D *h_draw_ajet_data_notag[100];
TH1D *h_draw_ljet[100];
TH1D *h_draw_ljet_data[100];
TH1D *h_draw_bjet_data[100];
TH1D *h_draw_cjet_data[100];
TH1D *h_draw_cljet[100];
TH1D *h_draw_ajet[100];

TH1D *h_draw_ajet_data[100];

TH1D *h_draw_bjet_init[100];
TH1D *h_draw_cjet_init[100];
TH1D *h_draw_ljet_init[100];

TH1D *h_draw_bjet_true[100];
TH1D *h_draw_cjet_true[100];
TH1D *h_draw_ljet_true[100];

TH1D *h_draw_bjet_sysUp[100];
TH1D *h_draw_cjet_sysUp[100];
TH1D *h_draw_ljet_sysUp[100];

TH1D *h_draw_bjet_sysDown[100];
TH1D *h_draw_cjet_sysDown[100];
TH1D *h_draw_ljet_sysDown[100];

TH2D *h_draw_bjet_2d[100];
TH2D *h_draw_cjet_2d[100];
TH2D *h_draw_bjet_untag_2d[100];
TH2D *h_draw_cjet_untag_2d[100];
//TH2D *h_draw_bjet_notag_2d[100];
//TH2D *h_draw_cjet_notag_2d[100];
TH2D *h_draw_bjet_posttag_2d[100];
TH2D *h_draw_cjet_posttag_2d[100];
TH2D *h_draw_ljet_2d[100];
TH2D *h_draw_ljet_data_2d[100];
TH2D *h_draw_bjet_data_2d[100];
TH2D *h_draw_cjet_data_2d[100];
TH2D *h_draw_cljet_2d[100];
TH2D *h_draw_ajet_2d[100];

TH2D *h_draw_ajet_data_2d[100];

TH2D *h_draw_bjet_sys_up_2d[nsys][10000];
TH2D *h_draw_bjet_sys_low_2d[nsys][10000];
TH2D *h_draw_bjet_sys_up_comb_2d[10000];
TH2D *h_draw_bjet_sys_low_comb_2d[10000];

TH2D *h_draw_cjet_sys_up_2d[nsys][10000];
TH2D *h_draw_cjet_sys_low_2d[nsys][10000];
TH2D *h_draw_cjet_sys_up_comb_2d[10000];
TH2D *h_draw_cjet_sys_low_comb_2d[10000];

TH2D *h_draw_bjet_untag_sys_up_2d[nsys][10000];
TH2D *h_draw_bjet_untag_sys_low_2d[nsys][10000];
TH2D *h_draw_bjet_untag_sys_up_comb_2d[10000];
TH2D *h_draw_bjet_untag_sys_low_comb_2d[10000];

TH2D *h_draw_cjet_untag_sys_up_2d[nsys][10000];
TH2D *h_draw_cjet_untag_sys_low_2d[nsys][10000];
TH2D *h_draw_cjet_untag_sys_up_comb_2d[10000];
TH2D *h_draw_cjet_untag_sys_low_comb_2d[10000];
/*
TH2D *h_draw_bjet_notag_sys_up_2d[nsys][10000];
TH2D *h_draw_bjet_notag_sys_low_2d[nsys][10000];
TH2D *h_draw_bjet_notag_sys_up_comb_2d[10000];
TH2D *h_draw_bjet_notag_sys_low_comb_2d[10000];

TH2D *h_draw_cjet_notag_sys_up_2d[nsys][10000];
TH2D *h_draw_cjet_notag_sys_low_2d[nsys][10000];
TH2D *h_draw_cjet_notag_sys_up_comb_2d[10000];
TH2D *h_draw_cjet_notag_sys_low_comb_2d[10000];
*/
TH2D *h_draw_bjet_posttag_sys_up_2d[nsys][10000];
TH2D *h_draw_bjet_posttag_sys_low_2d[nsys][10000];
TH2D *h_draw_bjet_posttag_sys_up_comb_2d[10000];
TH2D *h_draw_bjet_posttag_sys_low_comb_2d[10000];

TH2D *h_draw_cjet_posttag_sys_up_2d[nsys][10000];
TH2D *h_draw_cjet_posttag_sys_low_2d[nsys][10000];
TH2D *h_draw_cjet_posttag_sys_up_comb_2d[10000];
TH2D *h_draw_cjet_posttag_sys_low_comb_2d[10000];

TH2D *h_draw_ljet_sys_up_2d[nsys][10000];
TH2D *h_draw_ljet_sys_low_2d[nsys][10000];
TH2D *h_draw_ljet_sys_up_comb_2d[10000];
TH2D *h_draw_ljet_sys_low_comb_2d[10000];

TH2D *h_draw_ljet_data_sys_up_2d[nsys][10000];
TH2D *h_draw_ljet_data_sys_low_2d[nsys][10000];
TH2D *h_draw_ljet_data_sys_up_comb_2d[10000];
TH2D *h_draw_ljet_data_sys_low_comb_2d[10000];

TH2D *h_draw_ajet_sys_up_2d[nsys][10000];
TH2D *h_draw_ajet_sys_low_2d[nsys][10000];
TH2D *h_draw_ajet_sys_up_comb_2d[10000];
TH2D *h_draw_ajet_sys_low_comb_2d[10000];

TH2D *h_draw_bcljet_comb_2d[10000];
TH2D *h_draw_bcljet_sys_up_comb_2d[10000];
TH2D *h_draw_bcljet_sys_low_comb_2d[10000];

TH2D *h_draw_bcljet_sys_up_combSum_2d[10000];
TH2D *h_draw_bcljet_sys_low_combSum_2d[10000];

double ntot_bjet[100];
double ntot_cjet[100];
double ntot_ljet[100];
double ntot_cljet[100];

double ntot_bjet_true[100];
double ntot_cjet_true[100];
double ntot_ljet_true[100];

double ntot_ajet_data[100];

double ntot_bjet_err[100];
double ntot_cjet_err[100];
double ntot_ljet_err[100];
double ntot_cljet_err[100];

double ntot_bjet_err_true[100];
double ntot_cjet_err_true[100];
double ntot_ljet_err_true[100];

double ntot_ajet_data_err[100];

double parval[3], parerr[3],
  parval2DIM[3], parerr2DIM[3],
  chis[100], chis2d[100], 
  chisMain[100], chis2DIM[100];

double parvalCL[2], parerrCL[2],
  parval2DIMCL[2], parerr2DIMCL[2],
  chisCL[100], chis2dCL[100], 
  chisMainCL[100], chis2DIMCL[100];

//std::string mainPath = "/opt/sbg/cms/ui5_data1/kskovpen/bTag/CMSSW_5_3_11/src/sysAna/run/hist/";
//std::string mainPath = "/opt/sbg/data/data4/cms/kskovpen/bTag/HISTO/hist/";
//std::string mainPath = "/opt/sbg/cms/ui5_data1/kskovpen/bTag/CMSSW_5_3_11/src/sysAna/run/histSYS/";
std::string mainPath = "../../histSYS/";

std::string fpathData = mainPath;
std::string fpathMC = mainPath;

// A hack to use vectors and pairs as input parameters in the functions
//#include <vector>
//#include <pair>
//typedef vector<std::string> vector_STRING;
//typedef pair<std::string,std::string> pair_STRING;

// FUNCTIONS AND METHODS

std::vector<std::string> setTit(std::string);
void ptRange(std::string,THStack*);
void applySys(int,
	      std::string,
	      std::string,
	      std::string,
	      std::string,
	      std::string,
	      double,
	      double,
	      double,
	      double,
	      double,
	      double,
	      bool,
	      bool);

void init()
{
   name_sys_low[0] = "";
   name_sys_up[0] = "";

//   name_sys_low[1]   = "_ntrk_low";
   
//   name_sys_up[1]   = "_ntrk_up";
   
/*   name_sys_low[1]   = "_ntrk_low";
   name_sys_low[2]   = "_njet_low";
   name_sys_low[3]   = "_mupt_low";
   name_sys_low[4]   = "_jeta_low";
   name_sys_low[5]   = "_pu_low";
   name_sys_low[6]   = "_gsplit_low";
   name_sys_low[7]   = "_bfrag_low";
   name_sys_low[8]   = "_cdfrag_low";
   name_sys_low[9]   = "_cfrag_low";
   name_sys_low[10]   = "_ksl_low";
   name_sys_low[11]   = "_ntrkgen_low";
   name_sys_low[12]   = "_jes_low";
   name_sys_low[13]   = "_jer_low";

   name_sys_up[1]   = "_ntrk_up";
   name_sys_up[2]   = "_njet_up";
   name_sys_up[3]   = "_mupt_up";
   name_sys_up[4]   = "_jeta_up";
   name_sys_up[5]   = "_pu_up";
   name_sys_up[6]   = "_gsplit_up";
   name_sys_up[7]   = "_bfrag_up";
   name_sys_up[8]   = "_cdfrag_up";
   name_sys_up[9]   = "_cfrag_up";
   name_sys_up[10]   = "_ksl_up";
   name_sys_up[11]   = "_ntrkgen_up";
   name_sys_up[12]   = "_jes_up";
   name_sys_up[13]   = "_jer_up";*/

   name_sys_low[1]   = "_pu_low";
   name_sys_low[2]   = "_gsplit_low";
   name_sys_low[3]   = "_bfrag_low";
   name_sys_low[4]   = "_cdfrag_low";
   name_sys_low[5]   = "_cfrag_low";
   name_sys_low[6]   = "_ksl_low";
   name_sys_low[7]   = "_ntrkgen_low";
   name_sys_low[8]   = "_jes_low";
   name_sys_low[9]   = "_jer_low";

   name_sys_up[1]   = "_pu_up";
   name_sys_up[2]   = "_gsplit_up";
   name_sys_up[3]   = "_bfrag_up";
   name_sys_up[4]   = "_cdfrag_up";
   name_sys_up[5]   = "_cfrag_up";
   name_sys_up[6]   = "_ksl_up";
   name_sys_up[7]   = "_ntrkgen_up";
   name_sys_up[8]   = "_jes_up";
   name_sys_up[9]   = "_jer_up";
   /*
   name_sys_low[1]   = "_ntrk_low";
   name_sys_low[2]   = "_njet_low";
   name_sys_low[3]   = "_mupt_low";
   name_sys_low[4]   = "_jeta_low";
   name_sys_low[5]   = "_pu_low";
   name_sys_low[6]   = "_bfrag_low";
   name_sys_low[7]   = "_jes_low";
   name_sys_low[8]   = "_jer_low";

   name_sys_up[1]   = "_ntrk_up";
   name_sys_up[2]   = "_njet_up";
   name_sys_up[3]   = "_mupt_up";
   name_sys_up[4]   = "_jeta_up";
   name_sys_up[5]   = "_pu_up";
   name_sys_up[6]   = "_bfrag_up";
   name_sys_up[7]   = "_jes_up";
   name_sys_up[8]   = "_jer_up";
*/  
   covFactor[0] = 1.; // dummy
   covFactor[1] = 1.;
   covFactor[2] = 1.;
   covFactor[3] = 1.;
   covFactor[4] = 1.;
   covFactor[5] = 1.;
   covFactor[6] = 1.;
   covFactor[7] = 1.;
   covFactor[8] = 1.;
   covFactor[9] = 1.;
//   covFactor[10] = 1.;
//   covFactor[11] = 1.;
//   covFactor[12] = 1.;
//   covFactor[13] = 1.;

   for(int is=0;is<nsys;is++)
     {
	for(int i=0;i<100;i++)
	  {
	     binFactor[is][i] = 1.;
	  }	
     }   
   
   // TTBAR
/*   covFactor[0] = 1.; // dummy
   covFactor[1] = 1.;
   covFactor[2] = 1.;
   covFactor[3] = 1.;
   covFactor[4] = 1.;
   covFactor[5] = 1.;
   covFactor[6] = 1.;
   covFactor[7] = 1.;
   covFactor[8] = 1.;
*/   
   // *percentage* of events to remove or merge (doMergeBins) in the fit

   removeFromFit[0] = 0.;
   removeFromFit[1] = 0.02;
   removeFromFit[2] = 0.02;
   removeFromFit[3] = 0.02;
   removeFromFit[4] = 0.02;
   removeFromFit[5] = 0.02;
   
   removeFromFit[6] = 0.02;      
   removeFromFit[7] = 0.02;   
   removeFromFit[8] = 0.02;
   removeFromFit[9] = 0.02;
   removeFromFit[10] = 0.02;
   removeFromFit[11] = 0.02;
   removeFromFit[12] = 0.02;
   removeFromFit[13] = 0.02;
   removeFromFit[14] = 0.02;
   removeFromFit[15] = 0.02;
/*   
   removeFromFit[16] = 0.02;
   removeFromFit[17] = 0.02;
   removeFromFit[18] = 0.02;
   removeFromFit[19] = 0.02;
   removeFromFit[20] = 0.02;
   removeFromFit[21] = 0.02;
   removeFromFit[22] = 0.02;
   removeFromFit[23] = 0.02;
   removeFromFit[24] = 0.02;
   removeFromFit[25] = 0.02;
   removeFromFit[26] = 0.02;
   removeFromFit[27] = 0.02;
   removeFromFit[28] = 0.02;
   removeFromFit[29] = 0.02;
   removeFromFit[30] = 0.02;*/

   removeFromFitMin[0] = 0.;
   removeFromFitMin[1] = 0.01;
   removeFromFitMin[2] = 0.01;
   removeFromFitMin[3] = 0.01;
   removeFromFitMin[4] = 0.01;
   removeFromFitMin[5] = 0.01;
   
   removeFromFitMin[6] = 0.01;      
   removeFromFitMin[7] = 0.01;
   removeFromFitMin[8] = 0.01;
   removeFromFitMin[9] = 0.01;
   removeFromFitMin[10] = 0.01;
   removeFromFitMin[11] = 0.01;
   removeFromFitMin[12] = 0.01;
   removeFromFitMin[13] = 0.01;
   removeFromFitMin[14] = 0.01;
   removeFromFitMin[15] = 0.01;
/*   
   removeFromFitMin[16] = 0.01;
   removeFromFitMin[17] = 0.01;
   removeFromFitMin[18] = 0.01;
   removeFromFitMin[19] = 0.01;
   removeFromFitMin[20] = 0.01;
   removeFromFitMin[21] = 0.01;
   removeFromFitMin[22] = 0.01;
   removeFromFitMin[23] = 0.01;
   removeFromFitMin[24] = 0.01;
   removeFromFitMin[25] = 0.01;
   removeFromFitMin[26] = 0.01;
   removeFromFitMin[27] = 0.01;
   removeFromFitMin[28] = 0.01;
   removeFromFitMin[29] = 0.01;
   removeFromFitMin[30] = 0.01;*/
   
//   removeFromFit[0] = 0.;
//   removeFromFit[1] = 0.;
   
/*
   removeFromFit[0] = 0.;
   removeFromFit[1] = 0.02;
   removeFromFit[2] = 0.02;
   removeFromFit[3] = 0.02;
   removeFromFit[4] = 0.02;
   removeFromFit[5] = 0.02;   
   removeFromFit[6] = 0.02;      
   removeFromFit[7] = 0.02;   
   removeFromFit[8] = 0.02;
   removeFromFit[9] = 0.02;*/
}

double funcDEF(double vdata,
	       double vmc_bjet,
	       double vmc_cjet,
	       double vmc_ljet,
	       double *par)
{
   double value = vdata-par[0]*vmc_bjet-par[1]*vmc_cjet-par[2]*vmc_ljet;
     
   return value;
}

double funcDEFM(
		double vdata1,
		double vdataErr1,
		double vmc_bjet1,
		double vmc_cjet1,
		double vmc_ljet1,
		double vdata2,
		double vdataErr2,
		double vmc_bjet2,
		double vmc_cjet2,
		double vmc_ljet2,
		double covEL,
		double norm1,
		double norm2,
		double *par)
{
   double value = ((vdata1-par[0]*vmc_bjet1-par[1]*vmc_cjet1-par[2]*vmc_ljet1)/norm1)*
     ((vdata2-par[0]*vmc_bjet2-par[1]*vmc_cjet2-par[2]*vmc_ljet2)/norm2)*
     covEL;
   
   return value;
}

double funcDEFMPLUS(
		    double vdata1,
		    double vdataErr1,
		    double vmc_bjet1,
		    double vmc_cjet1,
		    double vmc_ljet1,
		    double vdata2,
		    double vdataErr2,
		    double vmc_bjet2,
		    double vmc_cjet2,
		    double vmc_ljet2,
		    double covEL,
		    double norm1,
		    double norm2,
		    double *par)
{
   double value = ((vmc_bjet1/norm1)/norm2)*
     covEL;
   
   return value;
}

double funcCL(double vdata,
	      double vmc_bjet,
	      double vmc_cjet,
	      double vmc_ljet,
	      double *par)
{
   double value = vdata-par[0]*vmc_bjet-par[1]*(vmc_cjet+vmc_ljet);
   
   return value;
}

void fcn(int &npar, double *gin, double &f, double *par, int iflag)
{
   double chisq = 0;
   double delta;
   
   double bbData = 0;
   double bbMCb=0;
   double bbMCc=0;
   double bbMCl=0;
   
   double bbe = 0;
   
   double tot = 0.;
   int itot = 0;

   int nbBad = 0;

   for( int i=0;i<nbins;i++ )
     {	
	double mcV = 0;

	mcV = mc_bcljet[i];

	if( errorz[i] != 0 &&
	    mcV > limFitAdjust && 
	    data[i] > limFitAdjust  )
	  {
	     itot++;
	     tot += data[i];
	     if( doCL )
	       delta = funcCL(data[i],mc_bjet[i],mc_cjet[i],mc_ljet[i],par)/errorz[i];
	     else	       
	       delta = funcDEF(data[i],mc_bjet[i],mc_cjet[i],mc_ljet[i],par)/errorz[i];
	  }	     
	else
	  {
	     nbBad++;
	     delta = 0.;
	     bbData += data[i];
	     bbMCb += mc_bjet[i];
	     bbMCc += mc_cjet[i];
	     bbMCl += mc_ljet[i];
	     bbe += sqrt(pow(bbe,2) + pow(errorz[i],2));
	  }
	
	chisq += delta*delta;
     }
   
   nbFitAdjust = itot;
   dataFitAdjust = tot;

   if( bbe > 0 )
     {	
	if( doCL )
	  delta = funcCL(bbData,bbMCb,bbMCc,bbMCl,par)/bbe;
	else
	  delta = funcDEF(bbData,bbMCb,bbMCc,bbMCl,par)/bbe;
	
	chisq += delta*delta;
	nbFitAdjust++;
     }
   
   if( iflag == 3 )
     {	
/*	for(int i=0;i<nbins;i++)
	  std::cout <<
	  funcDEF(data[i],mc_bjet[i],mc_cjet[i],mc_ljet[i],par) << " " << errorz[i] << 
	  " " << pow(funcDEF(data[i],mc_bjet[i],mc_cjet[i],mc_ljet[i],par)/errorz[i],2) <<
	  std::endl;*/

//	std::cout << par[0] << " " << par[1] << " " << par[2] << std::endl;
//	std::cout << chisq/nbFitAdjust << std::endl;
     }
   
   f = chisq;
}

void fcnSys(int &npar, double *gin, double &f, double *par, int iflag)
{
   double chisq = 0;
   double delta;
   
   double bbData = 0;
   double bbMCb=0;
   double bbMCc=0;
   double bbMCl=0;
   
   double bbe = 0;
   
   double tot = 0.;
   int itot = 0;

   int nbBad = 0;
      
/*   if( doCL )
     applySys(iVARcur,
	      hname_bjet_cur,
	      hname_cjet_cur,
	      hname_ljet_cur,
	      hname_ajet_cur,
	      hname_ljet_data_cur,
	      par[0],
	      par[1],
	      par[1],
	      0.,
	      0.,
	      0.);
   else     
     applySys(iVARcur,
	      hname_bjet_cur,
	      hname_cjet_cur,
	      hname_ljet_cur,
	      hname_ajet_cur,
	      hname_ljet_data_cur,
	      par[0],
	      par[1],
	      par[2],
	      0.,
	      0.,
	      0.);*/

   if( doCL )
     applySys(iVARcur,
	      hname_bjet_cur,
	      hname_cjet_cur,
	      hname_ljet_cur,
	      hname_ajet_cur,
	      hname_ljet_data_cur,
	      parg[0],
	      parg[1],
	      parg[1],
	      0.,
	      0.,
	      0.,
	      0.,
	      0);
   else     
     applySys(iVARcur,
	      hname_bjet_cur,
	      hname_cjet_cur,
	      hname_ljet_cur,
	      hname_ajet_cur,
	      hname_ljet_data_cur,
	      parg[0],
	      parg[1],
	      parg[2],
	      0.,
	      0.,
	      0.,
	      0.,
	      0);
   
   TH1D *h_ljet_cur;
   if( ljetData == 0 )
     h_ljet_cur = h_draw_ljet[iVARcur];
   else
     h_ljet_cur = h_draw_ljet_data[iVARcur];

   double nb = vecM.size();
   
   for( int i=0;i<nb;i++ )
     {	
	int idx = vecM[i];
	
	double mc_bjet_cur = h_draw_bjet[iVARcur]->GetBinContent(idx);
	double mc_bjet_err_cur = h_draw_bjet[iVARcur]->GetBinError(idx);
	double mc_cjet_cur = h_draw_cjet[iVARcur]->GetBinContent(idx);
	double mc_cjet_err_cur = h_draw_cjet[iVARcur]->GetBinError(idx);
	double mc_ljet_cur = h_ljet_cur->GetBinContent(idx);
	double mc_ljet_err_cur = h_ljet_cur->GetBinError(idx);
	double data_cur = h_draw_ajet_data[iVARcur]->GetBinContent(idx);
	double data_err_cur = h_draw_ajet_data[iVARcur]->GetBinError(idx);
	
	double mc_bcljet_cur = h_draw_bcljet_comb[iVARcur]->GetBinContent(idx);
	double up = h_draw_bcljet_sys_up_combSum[iVARcur]->GetBinContent(idx) - 
	  mc_bcljet_cur;
	double down = mc_bcljet_cur -
	  h_draw_bcljet_sys_low_combSum[iVARcur]->GetBinContent(idx);
	double err = (up+down)/2.;
	double errorz_cur = sqrt(pow(data_err_cur,2)+
				 pow(err,2));
	
//	std::cout << 1./pow(errorz_cur,2) << std::endl;
	
/*	if( iflag == 3 )
	  {	
	       std::cout <<
	       funcDEF(data_cur,mc_bjet_cur,mc_cjet_cur,mc_ljet_cur,par) << " " << errorz_cur <<
	       " " << pow(funcDEF(data_cur,mc_bjet_cur,mc_cjet_cur,mc_ljet_cur,par)/errorz_cur,2) <<
	       std::endl;
	  }*/
	
	if( errorz_cur != 0 )
	  {
	     itot++;
	     tot += data_cur;
	     if( doCL )
	       delta = funcCL(data_cur,mc_bjet_cur,mc_cjet_cur,mc_ljet_cur,par)/errorz_cur;
	     else	       
	       delta = funcDEF(data_cur,mc_bjet_cur,mc_cjet_cur,mc_ljet_cur,par)/errorz_cur;
	  }
	
	chisq += delta*delta;
     }
   
   nbFitAdjust = itot-ibinMin+1;
   dataFitAdjust = tot;

   if( iflag == 1 )
     {	
	std::cout << "CHISQ INITIAL=" << chisq/nbFitAdjust << std::endl;
     }   
   if( iflag == 3 )
     {	
//	for(int i=0;i<nbins;i++)
//	  std::cout <<
//	  funcDEF(data_cur,mc_bjet_cur,mc_cjet_cur,mc_ljet_cur,par) << " " << errorz_cur <<
//	  " " << pow(funcDEF(data_cur,mc_bjet_cur,mc_cjet_cur,mc_ljet_cur,par)/errorz_cur,2) <<
//	  std::endl;

//	std::cout << "fit: " << par[0] << " " << par[1] << " " << par[2] << std::endl;
//	if( chisq/nbFitAdjust > 3. )	
	  std::cout << "CHISQ FINAL=" << chisq/(nbFitAdjust-3) << std::endl;
     }

//   exit(1);
   
   f = chisq;
}

void fcnSysM(int &npar, double *gin, double &f, double *par, int iflag)
{
   double chisq = 0;
   double delta;
   double deltaPlus;
   
   double bbData = 0;
   double bbMCb=0;
   double bbMCc=0;
   double bbMCl=0;
   
   double bbe = 0;
   
   double tot = 0.;
   int itot = 0;

   int nbBad = 0;

/*   if( doCL )
     applySys(iVARcur,
	      hname_bjet_cur,
	      hname_cjet_cur,
	      hname_ljet_cur,
	      hname_ajet_cur,
	      hname_ljet_data_cur,
	      parg[0],
	      parg[1],
	      parg[1],
	      0.,
	      0.,
	      0.);
   else     
     applySys(iVARcur,
	      hname_bjet_cur,
	      hname_cjet_cur,
	      hname_ljet_cur,
	      hname_ajet_cur,
	      hname_ljet_data_cur,
	      parg[0],
	      parg[1],
	      parg[2],
	      0.,
	      0.,
	      0.);*/
      
   TH1D *h_ljet_cur;
   if( ljetData == 0 )
     h_ljet_cur = h_draw_ljet[iVARcur];
   else
     h_ljet_cur = h_draw_ljet_data[iVARcur]; //FIXME

   double nb = vecM.size();

   double chiPos = 0.;
   double chiNeg = 0.;

   double chiPlus[100];
   double chiPlusPlus[100];

//   covMIp->Print();
   
   for( int i1=0;i1<nb;i1++ )
     {
	int idx1 = vecM[i1];
	
	double mc_bjet_cur1 = h_draw_bjet[iVARcur]->GetBinContent(idx1);
	double mc_bjet_err_cur1 = h_draw_bjet[iVARcur]->GetBinError(idx1);
	double mc_cjet_cur1 = h_draw_cjet[iVARcur]->GetBinContent(idx1);
	double mc_cjet_err_cur1 = h_draw_cjet[iVARcur]->GetBinError(idx1);
	double mc_ljet_cur1 = h_ljet_cur->GetBinContent(idx1);
	double mc_ljet_err_cur1 = h_ljet_cur->GetBinError(idx1);
	double data_cur1 = h_draw_ajet_data[iVARcur]->GetBinContent(idx1);
	double data_err_cur1 = h_draw_ajet_data[iVARcur]->GetBinError(idx1);
	
////	double mc_bcljet_cur1 = h_draw_bcljet_comb[iVARcur]->GetBinContent(idx1);

	deltaPlus = 0.;
	
	for( int i2=0;i2<nb;i2++ )
	  {
	     int idx2 = vecM[i2];

	     double mc_bjet_cur2 = h_draw_bjet[iVARcur]->GetBinContent(idx2);
	     double mc_bjet_err_cur2 = h_draw_bjet[iVARcur]->GetBinError(idx2);
	     double mc_cjet_cur2 = h_draw_cjet[iVARcur]->GetBinContent(idx2);
	     double mc_cjet_err_cur2 = h_draw_cjet[iVARcur]->GetBinError(idx2);
	     double mc_ljet_cur2 = h_ljet_cur->GetBinContent(idx2);
	     double mc_ljet_err_cur2 = h_ljet_cur->GetBinError(idx2);
	     double data_cur2 = h_draw_ajet_data[iVARcur]->GetBinContent(idx2);
	     double data_err_cur2 = h_draw_ajet_data[iVARcur]->GetBinError(idx2);

////	     double mc_bcljet_cur2 = h_draw_bcljet_comb[iVARcur]->GetBinContent(idx2);
	     
//		  itot++;
//		  tot += data_cur;
//		  if( doCL )
//		    delta = funcCL(data_cur,mc_bjet_cur,mc_cjet_cur,mc_ljet_cur,par)/errorz_cur;
//		  else	       	     
	     
	     delta = funcDEFM(data_cur1,
			      data_err_cur1,
			      mc_bjet_cur1,
			      mc_cjet_cur1,
			      mc_ljet_cur1,
			      data_cur2,
			      data_err_cur2,
			      mc_bjet_cur2,
			      mc_cjet_cur2,
			      mc_ljet_cur2,
			      (*covMIp)[i1][i2],
			      (*norm1Dp)[i1],
			      (*norm1Dp)[i2],
//			      norm1D[i1],
//			      norm1D[i2],
			      par);

	     double deltaN = funcDEFMPLUS(data_cur1,
					  data_err_cur1,
					  mc_bjet_cur1,
					  mc_cjet_cur1,
					  mc_ljet_cur1,
					  data_cur2,
					  data_err_cur2,
					  mc_bjet_cur2,
					  mc_cjet_cur2,
					  mc_ljet_cur2,
					  (*covMIp)[i1][i2],
					  (*norm1Dp)[i1],
					  (*norm1Dp)[i2],
					  par);
	     
	     deltaPlus += deltaN;	     
	     
	     if( delta >= 0. ) chiPos += delta;
	     else chiNeg += delta;
	     
//	     if( i1 == i2 && comflag )
/*	     if( comflag && iflag == 3 )
	       {
		  std::cout << i1+1 << " " << i2+1 << " delta=" << delta << " covMI=" << covMI[i1][i2] << 
		    " data=" << data_cur1 <<
		    " mc_bjet=" << mc_bjet_cur1 <<
		    " mc_cjet=" << mc_cjet_cur1 <<
		    " mc_ljet=" << mc_ljet_cur1 <<
		    " norm1=" << norm1D[i1] <<
		    " norm2=" << norm1D[i2] <<
		    " covMI=" << covMI[i1][i2] <<
		    std::endl;
	       }*/

	     chisq += delta;
//	     chisq += delta*delta;
	  }
	chiPlus[i1] = deltaPlus;
	chiPlusPlus[i1] = deltaPlus*mc_bjet_cur1;
     }
   
   double sum = 0.;
   for(int i1=0;i1<nb;i1++)
     {
	sum += chiPlusPlus[i1];
     }   

//   std::cout << "pos=" << chiPos << " neg=" << chiNeg << std::endl;   
   
//   nbFitAdjust = itot;
//   dataFitAdjust = tot;

   nbFitAdjust = nb;
//   nbFitAdjust = nb-ibinMin+1;
   // this is safe as when merging last bins ibinMax = nbFitAdjust
//   if( ibinMax < nbFitAdjust ) nbFitAdjust -= (nbFitAdjust-ibinMax);
   
   if( iflag == 1 )
     {	
	std::cout << "CHISQ INITIAL = "<< chisq/(nbFitAdjust-3.) << std::endl;
     }
   if( iflag == 3 )
     {	
	for(int i1=0;i1<nb;i1++)
	  {
	     check << hnamePT[iPTcur] << " " << i1 << " " << chiPlus[i1] << " " << sum << std::endl;
	  }	
	std::cout << "CHISQ FINAL = " << chisq/(nbFitAdjust-3.) << std::endl;
     }
   
//   exit(1);
   
   f = chisq;
}

void fcn2DIM(int &npar, double *gin, double &f, double *par, int iflag)
{
   double chisq = 0;
   double delta;
   
   double bbData = 0;
   double bbMCb=0;
   double bbMCc=0;
   double bbMCl=0;
   
   double bbe = 0;
   
   double tot = 0.;
   int itot = 0;
   
   for( int i=0;i<nbins2dx;i++ )
     {
	for( int j=0;j<nbins2dy;j++ )
	  {
	     double ljet = 0;
	     double mcV = 0;

	     mcV = mc_bcljet_2d[i][j];
	     ljet = mc_ljet_2d[i][j];
	     
	     if( errorz_2d[i][j] != 0 &&
		 mcV > limFitAdjust && 
		 data_2d[i][j] > limFitAdjust  )
	       {
		  itot++;
		  tot += data_2d[i][j];
		  delta = funcDEF(data_2d[i][j],mc_bjet_2d[i][j],mc_cjet_2d[i][j],ljet,par)/errorz_2d[i][j];
	       }
	     
	     else
	       {		  
		  delta = 0.;
		  bbData += data_2d[i][j];
		  bbMCb += mc_bjet_2d[i][j];
		  bbMCc += mc_cjet_2d[i][j];
		  bbMCl += ljet;
		  bbe += sqrt(pow(bbe,2) + pow(errorz_2d[i][j],2));
	       }
	     
	     chisq += delta*delta;
	  }	
     }	

   nbFitAdjust2d = itot;
   dataFitAdjust2d = tot;
   
   if( bbe > 0 )
     {
	delta = funcDEF(bbData,bbMCb,bbMCc,bbMCl,par)/bbe;	
	chisq += delta*delta;
	nbFitAdjust2d++;
     }
   
//   std::cout << chisq << " " << nbFitAdjust2d << std::endl;
   
   f = chisq;
}

double errf(double v1,double ve1,double v2,double ve2)
{
   if( (v1+v2) == 0 ) return -666;
   
   double err = sqrt(pow(v2*ve1/(v1+v2)/(v1+v2),2) +
		     pow(v1*ve2/(v1+v2)/(v1+v2),2));
   
   return err;
}

void totSys(TH1D *h_nom,TH1D *h_low,TH1D *h_up)
{   
   int nbins = h_nom->GetXaxis()->GetNbins();
   
   for(int ib=1;ib<=nbins;ib++)
     {
	double b_nom = h_nom->GetBinContent(ib);
	double b_cur_low = h_low->GetBinContent(ib);
	double b_cur_up = h_up->GetBinContent(ib);
	
	double del_low = b_cur_low - b_nom;
	double del_up = b_cur_up - b_nom;
	double del_low_res = del_low;
	double del_up_res = del_up;
	
	double del_min = (del_low < del_up) ? del_low : del_up;
	double del_max = (del_low > del_up) ? del_low : del_up;

	del_low_res = (del_min > 0.) ? 0. : del_min;
	del_up_res = (del_max < 0.) ? 0. : del_max;
	
	double sys_low = b_nom + del_low_res;
	double sys_up = b_nom + del_up_res;
	
	h_low->SetBinContent(ib,sys_low);
	h_up->SetBinContent(ib,sys_up);
     }
}

void combSys(TH1D *h_nom,TH1D** h_sys_low,TH1D** h_sys_up,TH1D *h_sys_low_comb,TH1D *h_sys_up_comb,int iv)
{
   int nbins = h_nom->GetXaxis()->GetNbins();
   
   double sys_up[10000];
   double sys_low[10000];
   
   for(int is=1;is<=nbins;is++)
     {
	sys_up[is-1] = 0.;
	sys_low[is-1] = 0.;
     }      
   
   for(int j=0;j<nsysGL;j++)
     {
	for(int ib=1;ib<=nbins;ib++)
	  {
	     double nom = h_nom->GetBinContent(ib);
	     double low = h_sys_low[iv*nsysGL+j]->GetBinContent(ib);
	     double up = h_sys_up[iv*nsysGL+j]->GetBinContent(ib);
	     double delta_low = nom - low;
	     double delta_up = up - nom;
	     sys_up[ib-1] = sqrt(pow(sys_up[ib-1],2) + pow(delta_up,2));
	     sys_low[ib-1] = sqrt(pow(sys_low[ib-1],2) + pow(delta_low,2));
	  }
     }      
   
   for(int ib=1;ib<=nbins;ib++)
     {
	double nom = h_nom->GetBinContent(ib);
	double err = h_nom->GetBinError(ib);
	
	sys_up[ib-1] = sqrt(pow(sys_up[ib-1],2) + pow(err,2));
	sys_low[ib-1] = sqrt(pow(sys_low[ib-1],2) + pow(err,2));
     }   
   
   for(int ib=1;ib<=nbins;ib++)
     {		
	double nom = h_nom->GetBinContent(ib);
	h_sys_low_comb->SetBinContent(ib,nom-sys_low[ib-1]);
	h_sys_up_comb->SetBinContent(ib,nom+sys_up[ib-1]);
     }
}

void combSysLinear(TH1D *h_nom_bjet,TH1D *h_nom_cjet,TH1D *h_nom_ljet,
		   TH1D *h_bjet_sys_low,TH1D *h_bjet_sys_up,
		   TH1D *h_cjet_sys_low,TH1D *h_cjet_sys_up,
		   TH1D *h_ljet_sys_low,TH1D *h_ljet_sys_up,
		   TH1D *h_comb,TH1D *h_sys_low_comb,TH1D *h_sys_up_comb)
{
   int nbins = h_nom_bjet->GetXaxis()->GetNbins();      

   double sys_up[10000];
   double sys_low[10000];
   double stat[10000];
   
   for(int is=1;is<=nbins;is++)
     {
	sys_up[is-1] = 0.;
	sys_low[is-1] = 0.;
	stat[is-1] = 0.;
     }

   for(int ib=1;ib<=nbins;ib++)
     {
	double nom_bjet = h_nom_bjet->GetBinContent(ib);
	double err_bjet = h_nom_bjet->GetBinError(ib);
	double low_bjet = h_bjet_sys_low->GetBinContent(ib);
	double up_bjet = h_bjet_sys_up->GetBinContent(ib);
	
	double nom_cjet = h_nom_cjet->GetBinContent(ib);
	double err_cjet = h_nom_cjet->GetBinError(ib);
	double low_cjet = h_cjet_sys_low->GetBinContent(ib);
	double up_cjet = h_cjet_sys_up->GetBinContent(ib);
	
	double nom_ljet = h_nom_ljet->GetBinContent(ib);
	double err_ljet = h_nom_ljet->GetBinError(ib);
	double low_ljet = h_ljet_sys_low->GetBinContent(ib);
	double up_ljet = h_ljet_sys_up->GetBinContent(ib);
	
	double delta_low = (nom_bjet - low_bjet) + (nom_cjet - low_cjet) + (nom_ljet - low_ljet);
	double delta_up = (up_bjet - nom_bjet) + (up_cjet - nom_cjet) + (up_ljet - nom_ljet);
	sys_up[ib-1] = sys_up[ib-1] + delta_up;
	sys_low[ib-1] = sys_low[ib-1] + delta_low;

	stat[ib-1] = sqrt(pow(err_bjet,2) + pow(err_cjet,2) + pow(err_ljet,2));
     }      
   
   for(int ib=1;ib<=nbins;ib++)
     {
	double nom_bjet = h_nom_bjet->GetBinContent(ib);
	double nom_cjet = h_nom_cjet->GetBinContent(ib);
	double nom_ljet = h_nom_ljet->GetBinContent(ib);
	double nom = nom_bjet + nom_cjet + nom_ljet;
	h_comb->SetBinContent(ib,nom);
	h_comb->SetBinError(ib,stat[ib-1]);
	h_sys_low_comb->SetBinContent(ib,nom-sys_low[ib-1]);
	h_sys_up_comb->SetBinContent(ib,nom+sys_up[ib-1]);
     }
}

void applySF(std::string fitname,
	     std::string varName,
	     std::string hnamePT,
	     std::string hnameETA,
	     std::string hnameBTAG,
	     int ivh,
	     int ipt,
	     TH1D* hb,
	     TH1D* hc,
	     TH1D* hl,
	     TH1D* hb_true,
	     TH1D* hc_true,
	     TH1D* hl_true,
	     TH1D* hdata,
	     TH1D* hcomb,
	     TH1D* hup,
	     TH1D* hlow,
	     TLegend *leg,
	     double sf1,
	     double sf2,
	     double sf3,
	     double sf1err,
	     double sf2err,
	     double sf3err,
	     double chisqi,
	     int ndfi)
{
   c1->Clear();
   
   THStack *h_draw_st_fit = new THStack();
   
   TH1D *h_draw_bjet_clone = (TH1D*)(hb)->Clone("h_draw_bjet_clone");
   TH1D *h_draw_cjet_clone = (TH1D*)(hc)->Clone("h_draw_cjet_clone");
   TH1D *h_draw_ljet_clone = (TH1D*)(hl)->Clone("h_draw_ljet_clone");
   
   TH1D *h_draw_ajet_data_clone = (TH1D*)(hdata)->Clone("h_draw_ajet_data_clone");

   TH1D *h_draw_bcljet_comb_clone = (TH1D*)(hcomb)->Clone("h_draw_bcljet_comb_clone");
   TH1D *h_draw_bcljet_sys_up_combSum_clone = (TH1D*)(hup)->Clone("h_draw_bcljet_sys_up_combSum_clone");
   TH1D *h_draw_bcljet_sys_low_combSum_clone = (TH1D*)(hlow)->Clone("h_draw_bcljet_sys_low_combSum_clone");

   TH1D *h_draw_bjet_clone_noscale = (TH1D*)(hb)->Clone("h_draw_bjet_clone_noscale");
   TH1D *h_draw_cjet_clone_noscale = (TH1D*)(hc)->Clone("h_draw_cjet_clone_noscale");
   TH1D *h_draw_ljet_clone_noscale = (TH1D*)(hl)->Clone("h_draw_ljet_clone_noscale");

   TH1D *h_draw_bjet_true_clone_noscale = (TH1D*)(hb_true)->Clone("h_draw_bjet_true_clone_noscale");
   TH1D *h_draw_cjet_true_clone_noscale = (TH1D*)(hc_true)->Clone("h_draw_cjet_true_clone_noscale");
   TH1D *h_draw_ljet_true_clone_noscale = (TH1D*)(hl_true)->Clone("h_draw_ljet_true_clone_noscale");
   
   TH1D *h_draw_ajet_data_clone_noscale = (TH1D*)(hdata)->Clone("h_draw_ajet_data_clone_noscale");

   TH1D *h_draw_bcljet_comb_clone_noscale = (TH1D*)(hcomb)->Clone("h_draw_bcljet_comb_clone_noscale");
   TH1D *h_draw_bcljet_sys_up_combSum_clone_noscale = (TH1D*)(hup)->Clone("h_draw_bcljet_sys_up_combSum_clone_noscale");
   TH1D *h_draw_bcljet_sys_low_combSum_clone_noscale = (TH1D*)(hlow)->Clone("h_draw_bcljet_sys_low_combSum_clone_noscale");
   
   h_draw_bjet_clone->Scale(sf1);
   h_draw_cjet_clone->Scale(sf2);
   h_draw_ljet_clone->Scale(sf3);
   
   h_draw_st_fit->Add(h_draw_ljet_clone);
   h_draw_st_fit->Add(h_draw_cjet_clone);
   h_draw_st_fit->Add(h_draw_bjet_clone);      
   
   if( h_draw_st_fit->GetMaximum() >= h_draw_ajet_data_clone->GetMaximum() )
     h_draw_st_fit->SetMaximum(h_draw_st_fit->GetMaximum()+h_draw_ajet_data_clone->GetMaximum()/2);
   else
     h_draw_st_fit->SetMaximum(h_draw_ajet_data_clone->GetMaximum()+h_draw_st_fit->GetMaximum()/2);     

   h_draw_ajet_data_clone->SetMarkerSize(0.8);
   h_draw_st_fit->Draw("hist e1");
   h_draw_ajet_data_clone->Draw("e1 same");

   std::vector<std::string> vstr = setTit(varName);
   std::string xAxisTit = vstr.at(0);
   std::string yAxisTit = vstr.at(1);
   
   h_draw_st_fit->GetHistogram()->SetTitle("");
   h_draw_st_fit->GetHistogram()->GetXaxis()->SetTitle(xAxisTit.c_str());
   h_draw_st_fit->GetHistogram()->GetYaxis()->SetTitle(yAxisTit.c_str());

/*   if( varName == "h_j_pt_" ||
       varName == "h_j1_pt_" ||
       varName == "h_j2_pt_" )
     {		       
	ptRange(hnamePT,
		h_draw_st_fit);
     }*/

   c1->Clear();
   
   h_draw_st_fit->Draw("hist e1");
   h_draw_st_fit->SetMinimum(0.0005);
   h_draw_ajet_data_clone->Draw("e1 same");   
   
   TGraphAsymmErrors *gr_mc_merged = makeErrorBand(h_draw_bcljet_comb_clone,
						   h_draw_bcljet_sys_up_combSum_clone,
						   h_draw_bcljet_sys_low_combSum_clone);

   h_draw_bcljet_comb_clone->SetLineColor(kBlack);
   h_draw_bcljet_comb_clone->Draw("hist same");

/*   for(int ib=1;ib<nbins+1;ib++)
     {       
	double v1 = h_draw_bcljet_comb_clone->GetBinContent(ib);
	double ve1 = h_draw_bcljet_comb_clone->GetBinError(ib);
	double d1 = h_draw_ajet_data_clone->GetBinContent(ib);
	double de1 = h_draw_ajet_data_clone->GetBinError(ib);
	
	double s = (v1-d1)*(v1-d1)/(ve1*ve1+de1*de1);
*/	
/*	std::cout << ib << " " << v1
	  << " +- " << ve1 <<
	  " " << d1 <<
	  " +- " << de1 << " " << s << std::endl;*/
//     }   
   
   gr_mc_merged->SetFillStyle(3004);
   gStyle->SetHatchesLineWidth(2);
   gr_mc_merged->Draw("2SAME");

   leg = new TLegend(0.50,0.90,0.88,0.60);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   leg->SetHeader(ptlabel(hnamePT).c_str());
   
   std::string label = "Data "+lumi;
   leg->AddEntry(h_draw_ajet_data_clone,label.c_str(),"lep");
   leg->AddEntry(h_draw_bjet_clone,"b-jets","f");
   leg->AddEntry(h_draw_cjet_clone,"c-jets","f");
   leg->AddEntry(h_draw_ljet_clone,"light-flavour jets","f");
//   leg->AddEntry(h_draw_ljet_clone,"non-b-jets","f");
   
   leg->Draw();
   
//   ATLASLabel(0.20,0.85,"Internal",1);
   
   std::string hname = varName + hnamePT + "_" + hnameETA + hnameBTAG;
	
   std::string fsave = "pics/"+hname+"_datamc_"+fitname+".eps";
//   c1->SetLogy(1);
   c1->Print(fsave.c_str());
   delete leg;
	     
   double eff1b = -666;
   double effe1b = -666;
   double eff1c = -666;
   double effe1c = -666;
   double eff1l = -666;
   double effe1l = -666;
   
   double n1b = -666;
   double ne1b = -666;
   double n1c = -666;
   double ne1c = -666;
   double n1l = -666;
   double ne1l = -666;

   if( h_draw_ajet_data_clone->Integral(0,h_draw_ajet_data_clone->GetXaxis()->GetNbins()+1) > 0 )
     {
	double inte1b = 0.;
	double inte1c = 0.;
	double inte1l = 0.;
	double inte2 = 0.;		     
	double int1b = h_draw_bjet_clone_noscale->IntegralAndError(0,h_draw_bjet_clone_noscale->GetXaxis()->GetNbins()+1,inte1b);
	double int1c = h_draw_cjet_clone_noscale->IntegralAndError(0,h_draw_cjet_clone_noscale->GetXaxis()->GetNbins()+1,inte1c);
	double int1l = h_draw_ljet_clone_noscale->IntegralAndError(0,h_draw_ljet_clone_noscale->GetXaxis()->GetNbins()+1,inte1l);
	double int2 = h_draw_ajet_data_clone_noscale->IntegralAndError(0,h_draw_ajet_data_clone_noscale->GetXaxis()->GetNbins()+1,inte2);
	eff1b = (int2 == 0) ? -666 : int1b/int2;
	eff1c = (int2 == 0) ? -666 : int1c/int2;
	eff1l = (int2 == 0) ? -666 : int1l/int2;
	effe1b = errf(int1b,inte1b,int2,inte2);
	effe1c = errf(int1c,inte1c,int2,inte2);
	effe1l = errf(int1l,inte1l,int2,inte2);
/*	double int1b = h_draw_bjet_true_clone_noscale->IntegralAndError(0,h_draw_bjet_clone_noscale->GetXaxis()->GetNbins()+1,inte1b);
	double int1c = h_draw_cjet_true_clone_noscale->IntegralAndError(0,h_draw_cjet_clone_noscale->GetXaxis()->GetNbins()+1,inte1c);
	double int1l = h_draw_ljet_true_clone_noscale->IntegralAndError(0,h_draw_ljet_clone_noscale->GetXaxis()->GetNbins()+1,inte1l);
	double int2 = h_draw_ajet_data_clone_noscale->IntegralAndError(0,h_draw_ajet_data_clone_noscale->GetXaxis()->GetNbins()+1,inte2);
	eff1b = (int2 == 0) ? -666 : int1b/int2;
	eff1c = (int2 == 0) ? -666 : int1c/int2;
	eff1l = (int2 == 0) ? -666 : int1l/int2;
	effe1b = errf(int1b,inte1b,int2,inte2);
	effe1c = errf(int1c,inte1c,int2,inte2);
	effe1l = errf(int1l,inte1l,int2,inte2); was commented out*/
	n1b = int1b;
	n1c = int1c;
	n1l = int1l;
	ne1b = inte1b;
	ne1c = inte1c;
	ne1l = inte1l;
     }	     
   
   fout.precision(10);
   fout.setf(std::ios::fixed,std::ios::floatfield);

   if( doFracFit )
     {
	fracB_MCDEFAULT = 1.;
	fracC_MCDEFAULT = 1.;
	fracL_MCDEFAULT = 1.;

	fracB_MCDEFAULT_TRUE = 1.;
	fracC_MCDEFAULT_TRUE = 1.;
	fracL_MCDEFAULT_TRUE = 1.;
     }   
   
   fout << "b" << ipt << "   " << hnameBTAG << "tag   "
     << hnamePT << "   " << hnameETA << "   " << fitname << "   " << varName << "   "
     << std::fixed << sf1 << "pm" << sf1err << "   "
     << sf2 << "pm" << sf2err << "   "
     << sf3 << "pm" << sf3err << "   "
     << eff1b << "pm" << effe1b << "   " 
     << eff1c << "pm" << effe1c << "   "
     << eff1l << "pm" << effe1l << "   "
     << n1b << "pm" << ne1b << "   " 
     << n1c << "pm" << ne1c << "   " 
     << n1l << "pm" << ne1l << "   "
//     << ntot_bjet_true[ivh] << "pm" << ntot_bjet_err_true[ivh] << "   "
//     << ntot_cjet_true[ivh] << "pm" << ntot_cjet_err_true[ivh] << "   "
//     << ntot_ljet_true[ivh] << "pm" << ntot_ljet_err_true[ivh] << "   "
//     << ntot_ajet_data[ivh] << "pm" << ntot_ajet_data_err[ivh] << "   " 
     << ntot_bjet[ivh] << "pm" << ntot_bjet_err[ivh] << "   "
     << ntot_cjet[ivh] << "pm" << ntot_cjet_err[ivh] << "   "
     << ntot_ljet[ivh] << "pm" << ntot_ljet_err[ivh] << "   "
     << ntot_ajet_data[ivh] << "pm" << ntot_ajet_data_err[ivh] << "   " 
     << chisqi << "   " << ndfi << "   "
     << usePRETAGb << "   " << usePRETAGc << "   " << fr << "   " 
     << fracB_MCDEFAULT_TRUE << "   " << fracC_MCDEFAULT_TRUE << "   " << fracL_MCDEFAULT_TRUE
//     << fracB_MCDEFAULT << "   " << fracC_MCDEFAULT << "   " << fracL_MCDEFAULT
     << std::endl;

   delete gr_mc_merged;
   
   delete h_draw_st_fit;
   
   delete h_draw_bjet_clone;
   delete h_draw_cjet_clone;
   delete h_draw_ljet_clone;
   
   delete h_draw_ajet_data_clone;
   
   delete h_draw_bcljet_comb_clone;
   delete h_draw_bcljet_sys_up_combSum_clone;
   delete h_draw_bcljet_sys_low_combSum_clone;
   
   delete h_draw_bjet_clone_noscale;
   delete h_draw_cjet_clone_noscale;
   delete h_draw_ljet_clone_noscale;

   delete h_draw_bjet_true_clone_noscale;
   delete h_draw_cjet_true_clone_noscale;
   delete h_draw_ljet_true_clone_noscale;
   
   delete h_draw_ajet_data_clone_noscale;
   
   delete h_draw_bcljet_comb_clone_noscale;
   delete h_draw_bcljet_sys_up_combSum_clone_noscale;
   delete h_draw_bcljet_sys_low_combSum_clone_noscale;
}

void applySFCL(std::string fitname,
	       std::string varName,
	       std::string hnamePT,
	       std::string hnameETA,
	       std::string hnameBTAG,
	       int ivh,
	       int ipt,
	       TH1D* hb,
	       TH1D* hcl,
	       TH1D* hdata,
	       TLegend *leg,
	       double sf1,
	       double sf2,
	       double sf1err,
	       double sf2err,
	       double chisqi,
	       int ndfi)
{
   c1->Clear();
   
   THStack *h_draw_st_fit = new THStack();
   
   TH1D *h_draw_bjet_clone = (TH1D*)(hb)->Clone("h_draw_bjet_clone");
   TH1D *h_draw_cljet_clone = (TH1D*)(hcl)->Clone("h_draw_cljet_clone");
		  
   TH1D *h_draw_ajet_data_clone = (TH1D*)(hdata)->Clone("h_draw_ajet_data_clone");
		  
   h_draw_bjet_clone->Scale(sf1);
   h_draw_cljet_clone->Scale(sf2);
	
   h_draw_st_fit->Add(h_draw_cljet_clone);
   h_draw_st_fit->Add(h_draw_bjet_clone);
   
   if( h_draw_st_fit->GetMaximum() >= h_draw_ajet_data_clone->GetMaximum() )
     h_draw_st_fit->SetMaximum(h_draw_st_fit->GetMaximum()+h_draw_ajet_data_clone->GetMaximum()/2);
   else
     h_draw_st_fit->SetMaximum(h_draw_ajet_data_clone->GetMaximum()+h_draw_st_fit->GetMaximum()/2);
   
   h_draw_st_fit->Draw("hist e1");
   h_draw_ajet_data_clone->Draw("e1 same");

   std::vector<std::string> vstr = setTit(varName);
   std::string xAxisTit = vstr.at(0);
   std::string yAxisTit = vstr.at(1);
   
   h_draw_st_fit->GetHistogram()->SetTitle("");
   h_draw_st_fit->GetHistogram()->GetXaxis()->SetTitle(xAxisTit.c_str());
   h_draw_st_fit->GetHistogram()->GetYaxis()->SetTitle(yAxisTit.c_str());

/*   if( varName == "h_j_pt_" ||
       varName == "h_j1_pt_" ||
       varName == "h_j2_pt_" )
     {		       
	ptRange(hnamePT,
		h_draw_st_fit);
     }*/
   
   c1->Clear();
   
   h_draw_st_fit->Draw("hist e1");
   h_draw_ajet_data_clone->Draw("e1 same");
   
   leg->Draw();
   
   std::string hname = varName + hnamePT + hnameETA + hnameBTAG;
	
   std::string fsave = "pics/"+hname+"_datamc_"+fitname+".eps";
//   c1->SetLogy(1);
   c1->Print(fsave.c_str());
	     
   double eff1b = -666;
   double effe1b = -666;
   double eff1cl = -666;
   double effe1cl = -666;
   
   double n1b = -666;
   double ne1b = -666;
   double n1cl = -666;
   double ne1cl = -666;

   if( h_draw_ajet_data_clone->Integral(0,h_draw_ajet_data_clone->GetXaxis()->GetNbins()+1) > 0 )
     {
	double inte1b = 0.;
	double inte1cl = 0.;
	double inte2 = 0.;
	double int1b = h_draw_bjet_clone->IntegralAndError(0,h_draw_bjet_clone->GetXaxis()->GetNbins()+1,inte1b);
	double int1cl = h_draw_cljet_clone->IntegralAndError(0,h_draw_cljet_clone->GetXaxis()->GetNbins()+1,inte1cl);
	double int2 = h_draw_ajet_data_clone->IntegralAndError(0,h_draw_ajet_data_clone->GetXaxis()->GetNbins()+1,inte2);
	eff1b = (int2 == 0) ? -666 : int1b/int2;
	eff1cl = (int2 == 0) ? -666 : int1cl/int2;
	effe1b = errf(int1b,inte1b,int2,inte2);
	effe1cl = errf(int1cl,inte1cl,int2,inte2);

	n1b = int1b;
	n1cl = int1cl;
	ne1b = inte1b;
	ne1cl = inte1cl;
     }	     
   
   fout << "b" << ipt << "   " << hnameBTAG << "tag   "
     << hnamePT << "   " << hnameETA << "   " << fitname << "   " << varName << "   "
     << std::fixed << sf1 << "pm" << sf1err << "   "
     << sf2 << "pm" << sf2err << "   "
     << 0 << "pm" << 0 << "   "
     << eff1b << "pm" << effe1b << "   " 
     << eff1cl << "pm" << effe1cl << "   "
     << 0 << "pm" << 0 << "   "
     << n1b << "pm" << ne1b << "   " 
     << n1cl << "pm" << ne1cl << "   "
     << 0 << "pm" << 0 << "   "
     << ntot_bjet[ivh] << "pm" << ntot_bjet_err[ivh] << "   "
     << ntot_cljet[ivh] << "pm" << ntot_cljet_err[ivh] << "   "
     << 0 << "pm" << 0 << "   "
     << ntot_ajet_data[ivh] << "pm" << ntot_ajet_data_err[ivh] << "   " 
     << chisqi << "   " << ndfi
     << std::endl;
   
   delete h_draw_st_fit;
   
   delete h_draw_bjet_clone;
   delete h_draw_cljet_clone;
   delete h_draw_ajet_data_clone;
}

void totSys2DIM(TH2D *h_nom,TH2D *h_low,TH2D *h_up)
{   
   int nbinsX = h_nom->GetXaxis()->GetNbins();
   int nbinsY = h_nom->GetYaxis()->GetNbins();
   
   for(int ibx=0;ibx<=nbinsX+1;ibx++)
     {	
	for(int iby=0;iby<=nbinsY+1;iby++)
	  {
	     double b_nom = h_nom->GetBinContent(ibx,iby);
	     double b_cur_low = h_low->GetBinContent(ibx,iby);
	     double b_cur_up = h_up->GetBinContent(ibx,iby);
	     
	     double del_low = b_cur_low - b_nom;
	     double del_up = b_cur_up - b_nom;
	     double del_low_res = del_low;
	     double del_up_res = del_up;
	     
	     double del_min = (del_low < del_up) ? del_low : del_up;
	     double del_max = (del_low > del_up) ? del_low : del_up;
	     
	     del_low_res = (del_min > 0.) ? 0. : del_min;
	     del_up_res = (del_max < 0.) ? 0. : del_max;
	     
	     double sys_low = b_nom + del_low_res;
	     double sys_up = b_nom + del_up_res;
	     
	     h_low->SetBinContent(ibx,iby,sys_low);
	     h_up->SetBinContent(ibx,iby,sys_up);
	  }
     }   
}

void combSys2DIM(TH2D *h_nom,TH2D** h_sys_low,TH2D** h_sys_up,TH2D *h_sys_low_comb,TH2D *h_sys_up_comb,int iv)
{
   int nbinsX = h_nom->GetXaxis()->GetNbins();
   int nbinsY = h_nom->GetYaxis()->GetNbins();
   
   double sys_up[1000][1000];
   double sys_low[1000][1000];
   
   for(int isx=0;isx<=nbinsX+1;isx++)
     {
	for(int isy=0;isy<=nbinsY+1;isy++)
	  {
	     sys_up[isx][isy] = 0.;
	     sys_low[isx][isy] = 0.;
	  }	
     }      
   
   for(int j=0;j<nsysGL;j++)
     {
	for(int ibx=0;ibx<=nbinsX+1;ibx++)
	  {	    
	     for(int iby=0;iby<=nbinsY+1;iby++)
	       {
		  double nom = h_nom->GetBinContent(ibx,iby);
		  double low = h_sys_low[iv*nsysGL+j]->GetBinContent(ibx,iby);
		  double up = h_sys_up[iv*nsysGL+j]->GetBinContent(ibx,iby);
		  double delta_low = nom - low;
		  double delta_up = up - nom;
		  sys_up[ibx][iby] = sqrt(pow(sys_up[ibx][iby],2) + pow(delta_up,2));
		  sys_low[ibx][iby] = sqrt(pow(sys_low[ibx][iby],2) + pow(delta_low,2));
	       }	     
	  }
     }      
   
   for(int ibx=0;ibx<=nbinsX+1;ibx++)
     {	
	for(int iby=0;iby<=nbinsY+1;iby++)
	  {
	     double nom = h_nom->GetBinContent(ibx,iby);
	     double err = h_nom->GetBinError(ibx,iby);
	     
	     sys_up[ibx][iby] = sqrt(pow(sys_up[ibx][iby],2) + pow(err,2));
	     sys_low[ibx][iby] = sqrt(pow(sys_low[ibx][iby],2) + pow(err,2));
	  }	
     }   
   
   for(int ibx=0;ibx<=nbinsX+1;ibx++)
     {		
	for(int iby=0;iby<=nbinsY+1;iby++)
	  {	     
	     double nom = h_nom->GetBinContent(ibx,iby);
	     h_sys_low_comb->SetBinContent(ibx,iby,nom-sys_low[ibx][iby]);
	     h_sys_up_comb->SetBinContent(ibx,iby,nom+sys_up[ibx][iby]);
	  }	
     }
}

void combSysLinear2DIM(TH2D *h_nom_bjet_2d,TH2D *h_nom_cjet_2d,TH2D *h_nom_ljet_2d,
		       TH2D *h_bjet_sys_low_2d,TH2D *h_bjet_sys_up_2d,
		       TH2D *h_cjet_sys_low_2d,TH2D *h_cjet_sys_up_2d,
		       TH2D *h_ljet_sys_low_2d,TH2D *h_ljet_sys_up_2d,
		       TH2D *h_comb_2d,TH2D *h_sys_low_comb_2d,TH2D *h_sys_up_comb_2d,
		       double sf1,double sf2,double sf3)
{
   int nbinsX = h_nom_bjet_2d->GetXaxis()->GetNbins();
   int nbinsY = h_nom_bjet_2d->GetYaxis()->GetNbins();

   double sys_up[1000][1000];
   double sys_low[1000][1000];
   double stat[1000][1000];

   for(int ix=0;ix<=nbinsX+1;ix++)
     {
	for(int iy=0;iy<=nbinsY+1;iy++)
	  {
	     sys_up[ix][iy] = 0.;
	     sys_low[ix][iy] = 0.;
	     stat[ix][iy] = 0.;
	  }	
     }
   
   for(int ibx=0;ibx<=nbinsX+1;ibx++)
     {
	for(int iby=0;iby<=nbinsY+1;iby++)
	  {	     
	     double nom_bjet = h_nom_bjet_2d->GetBinContent(ibx,iby);
	     double err_bjet = h_nom_bjet_2d->GetBinError(ibx,iby);
	     double low_bjet = h_bjet_sys_low_2d->GetBinContent(ibx,iby);
	     double up_bjet = h_bjet_sys_up_2d->GetBinContent(ibx,iby);
	     
	     double nom_cjet = h_nom_cjet_2d->GetBinContent(ibx,iby);
	     double err_cjet = h_nom_cjet_2d->GetBinError(ibx,iby);
	     double low_cjet = h_cjet_sys_low_2d->GetBinContent(ibx,iby);
	     double up_cjet = h_cjet_sys_up_2d->GetBinContent(ibx,iby);
	     
	     double nom_ljet = h_nom_ljet_2d->GetBinContent(ibx,iby);
	     double err_ljet = h_nom_ljet_2d->GetBinError(ibx,iby);
	     double low_ljet = h_ljet_sys_low_2d->GetBinContent(ibx,iby);
	     double up_ljet = h_ljet_sys_up_2d->GetBinContent(ibx,iby);
	     
	     double delta_low = (nom_bjet - low_bjet) + (nom_cjet - low_cjet) + (nom_ljet - low_ljet);
	     double delta_up = (up_bjet - nom_bjet) + (up_cjet - nom_cjet) + (up_ljet - nom_ljet);
	     sys_up[ibx][iby] = sys_up[ibx][iby] + delta_up;
	     sys_low[ibx][iby] = sys_low[ibx][iby] + delta_low;
	     
	     stat[ibx][iby] = sqrt(pow(err_bjet,2) + pow(err_cjet,2) + pow(err_ljet,2));
	  }	
     }      
   
   for(int ibx=0;ibx<=nbinsX+1;ibx++)
     {
	for(int iby=0;iby<=nbinsY+1;iby++)
	  {	     
	     double nom_bjet = h_nom_bjet_2d->GetBinContent(ibx,iby);
	     double nom_cjet = h_nom_cjet_2d->GetBinContent(ibx,iby);
	     double nom_ljet = h_nom_ljet_2d->GetBinContent(ibx,iby);
	     double nom = nom_bjet + nom_cjet + nom_ljet;
	     h_comb_2d->SetBinContent(ibx,iby,nom);
	     h_comb_2d->SetBinError(ibx,iby,stat[ibx][iby]);
	     h_sys_low_comb_2d->SetBinContent(ibx,iby,nom-sys_low[ibx][iby]);
	     h_sys_up_comb_2d->SetBinContent(ibx,iby,nom+sys_up[ibx][iby]);
	  }	
     }
}

void ptRange(std::string ptname,
	     THStack *hst)
{   
   if( ptname == "pt20t30" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.020,0.030);
     }
   if( ptname == "pt30t40" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.030,0.040);
     }		       
   if( ptname == "pt40t50" ) 
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.040,0.050);
     }		       
   if( ptname == "pt50t60" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.048,0.060);
     }		       
   if( ptname == "pt60t70" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.060,0.072);
     }		       
   if( ptname == "pt70t80" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.070,0.080);
     }		       
   if( ptname == "pt80t100" ) 
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.080,0.100);
     }		       
   if( ptname == "pt100t120" ) 
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.098,0.120);
     }		       
   if( ptname == "pt120t160" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.118,0.164);
     }		       
   if( ptname == "pt160t210" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.156,0.214);
     }		       
   if( ptname == "pt210t260" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.206,0.264);
     }		       
   if( ptname == "pt260t320" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.256,0.325);
     }		       
   if( ptname == "pt320t400" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.315,0.410);
     }		       
   if( ptname == "pt400t500" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.390,0.510);
     }		       
   if( ptname == "pt500t600" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.490,0.620);
     }		       
   if( ptname == "pt600t800" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.590,0.840);
     }		       
   if( ptname == "pt800t1000" )
     {
	hst->GetHistogram()->GetXaxis()->SetRangeUser(0.780,1.000);
     }
}

void doFit(double *par,double *err,double *chis,double nbjet,double ncjet,double nljet)
{
   double pval[3], perr[3];
   
   TMinuit *gMinuit = new TMinuit(1);
//   gMinuit->SetFCN(fcnSys);
   gMinuit->SetFCN(fcnSysM);
   gMinuit->SetPrintLevel(-1);
   
   Double_t arglist[10];
   Int_t ierflg = 0;
   
   arglist[0] = 1;
   gMinuit->mnexcm("SET ERR",arglist,1,ierflg);
   
   arglist[0] = 5000;
   arglist[1] = 0.1;
   
//   double nbs = 0.33/nbjet;
//   double ncs = 0.33/ncjet;
//   double nls = 0.33/nljet;
   double nbs = 1.;
   double ncs = 1.;
   double nls = 1.;
   
   double stp = pow(10,-4);
   
//   std::cout << "start: " << nbs << " " << ncs << " " << nls << std::endl;
   
   Double_t vstart[3] = {nbs,ncs,nls};
   Double_t step[3] = {stp,stp,stp};

   gMinuit->mnparm(0,"p1",vstart[0],step[0],0.00001,100,ierflg);
   gMinuit->mnparm(1,"p2",vstart[1],step[1],0.00001,100,ierflg);
   gMinuit->mnparm(2,"p3",vstart[2],step[2],0.00001,100,ierflg);

   parg[0] = 1.;
   parg[1] = 1.;
   parg[2] = 1.;
   perg[0] = 0.;
   perg[1] = 0.;
   perg[2] = 0.;

//   gMinuit->mnparm(2,"p3",1.2,step[1],0.00001,100,ierflg); 
//   gMinuit->FixParameter(2);
   
   if( h_draw_cjet[iVARcur]->Integral() < 0.001 )
     {
	if( h_draw_cjet[iVARcur]->GetEntries() < 3 )
	  gMinuit->mnparm(1,"p2",0.,step[1],0.00001,100,ierflg);

	gMinuit->FixParameter(1);
     }   
   if( h_draw_ljet[iVARcur]->Integral() < 0.001 )
     {
	if( h_draw_ljet[iVARcur]->GetEntries() < 3 )
	  gMinuit->mnparm(2,"p3",0.,step[2],0.00001,100,ierflg);
	
	gMinuit->FixParameter(2);
     }   
  
////   std::cout << parg[0] << " " << parg[1] << " " << parg[2] << std::endl;

   gMinuit->mnexcm("MIGRAD", arglist ,2,ierflg);
   
   gMinuit->GetParameter(0,parg[0],perg[0]);
   gMinuit->GetParameter(1,parg[1],perg[1]);
   gMinuit->GetParameter(2,parg[2],perg[2]);

   std::cout << parg[0] << "+" << perg[0] << std::endl;
   std::cout << parg[1] << "+" << perg[1] << std::endl;
   std::cout << parg[2] << "+" << perg[2] << std::endl;
         
//   std::cout << parg[0] << " " << parg[1] << " " << parg[2] << std::endl;
   
//   std::cout << "nom1=" << h_draw_bcljet_comb[iVARcur]->Integral() << std::endl;
//   std::cout << "sys1=" << h_draw_bcljet_sys_up_comb[iVARcur*nsysGL+1]->Integral() << std::endl;
   
////   std::cout << parg[0] << " " << parg[1] << " " << parg[2] << std::endl;
   
   applySys(iVARcur,
	    hname_bjet_cur,
	    hname_cjet_cur,
	    hname_ljet_cur,
	    hname_ajet_cur,
	    hname_ljet_data_cur,
	    parg[0],
	    parg[1],
	    parg[2],
	    0.,
	    0.,
	    0.,
	    true,
	    true);

  // std::cout << "nom2=" << h_draw_bcljet_comb[iVARcur]->Integral() << std::endl;
//   std::cout << "sys2=" << h_draw_bcljet_sys_up_comb[iVARcur*nsysGL+1]->Integral() << std::endl;
   
//   gMinuit->mnexcm("MIGRAD", arglist ,0,ierflg);
//   gMinuit->GetParameter(0,parg[0],perg[0]);
//   gMinuit->GetParameter(1,parg[1],perg[1]);
//   gMinuit->GetParameter(2,parg[2],perg[2]);
////   std::cout << parg[0] << " " << parg[1] << " " << parg[2] << std::endl;
//   gMinuit->mnexcm("MINOS", arglist ,0,ierflg);
   gMinuit->mnexcm("MIGRAD", arglist ,2,ierflg);
   gMinuit->mnexcm("MINOS", arglist ,2,ierflg);
   gMinuit->mnexcm("MIGRAD", arglist ,2,ierflg);
   gMinuit->mnexcm("MINOS", arglist ,2,ierflg);
//   gMinuit->mnexcm("HESSE", arglist ,0,ierflg);

//   std::cout << parg[0] << "+-" << perg[0] << " " <<
  //   parg[1] << "+-" << perg[1] << " " << parg[2] << "+-" << perg[2] << std::endl;
   
   double paramErrP[3];
   double paramErrM[3];
   double paramErrS[3];
   double paramErrG[3];
  
   gMinuit->mnerrs(0,paramErrP[0],paramErrM[0],paramErrS[0],paramErrG[0]);
   gMinuit->mnerrs(1,paramErrP[1],paramErrM[1],paramErrS[1],paramErrG[1]);
   gMinuit->mnerrs(2,paramErrP[2],paramErrM[2],paramErrS[2],paramErrG[2]);

//   std::cout << parg[0] << "+" << paramErrP[0] << "-" << paramErrM[0] << " +- " << paramErrS[0] << std::endl;
//   std::cout << parg[1] << "+" << paramErrP[1] << "-" << paramErrM[1] << " +- " << paramErrS[1] << std::endl;
//   std::cout << parg[2] << "+" << paramErrP[2] << "-" << paramErrM[2] << " +- " << paramErrS[2] << std::endl;
   
   arglist[0] = 3;
   gMinuit->mnexcm("CALL FCN",arglist,1,ierflg);
   
   double amin,edm,errdef;
   int nvpar,nparx,icstat;   
   gMinuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);
   chis[0] = amin;
   chis[1] = nbFitAdjust - gMinuit->GetNumFreePars();

///   gMinuit->mnmatu(1);
   
//   std::cout << chis[0] << " " << chis[1] << std::endl;
   
   gMinuit->GetParameter(0,pval[0],perr[0]);
   gMinuit->GetParameter(1,pval[1],perr[1]);
   gMinuit->GetParameter(2,pval[2],perr[2]);
   
   par[0] = pval[0];
   par[1] = pval[1];
   par[2] = pval[2];
   err[0] = perr[0];
   err[1] = perr[1];
   err[2] = perr[2];
   
   std::cout << par[0] << "+" << err[0] << std::endl;
   std::cout << par[1] << "+" << err[1] << std::endl;
   std::cout << par[2] << "+" << err[2] << std::endl;

   delete gMinuit;
}

void doFitFractionFitter(double *par,double *err,double *chis)
{      
   TH1D *h_bjet_FRAC = (TH1D*)h_draw_bjet[iVARcur]->Clone("h_bjet_FRAC");
   TH1D *h_cjet_FRAC = (TH1D*)h_draw_cjet[iVARcur]->Clone("h_cjet_FRAC");
   TH1D *h_ljet_FRAC = (TH1D*)h_draw_ljet[iVARcur]->Clone("h_ljet_FRAC");
   TH1D *h_ajet_data_FRAC = (TH1D*)h_draw_ajet_data[iVARcur]->Clone("h_ajet_data_FRAC");
 
   h_bjet_FRAC->Scale(1./h_bjet_FRAC->Integral());
   h_cjet_FRAC->Scale(1./h_cjet_FRAC->Integral());
   h_ljet_FRAC->Scale(1./h_ljet_FRAC->Integral());
   h_ajet_data_FRAC->Scale(1./h_ajet_data_FRAC->Integral());
   
   TH1D *h_weights_b = (TH1D*)h_bjet_FRAC->Clone("h_weights_b");
   h_weights_b->Clear();
   TH1D *h_weights_c = (TH1D*)h_cjet_FRAC->Clone("h_weights_c");
   h_weights_c->Clear();
   TH1D *h_weights_l = (TH1D*)h_ljet_FRAC->Clone("h_weights_l");
   h_weights_l->Clear();
   
   int nbFRAC = h_bjet_FRAC->GetXaxis()->GetNbins();
   
   double nFRACb = 0.;
   double nFRACc = 0.;
   double nFRACl = 0.;
   double nFRACd = 0.;
   double n0FRACb = 0.;
   double n0FRACc = 0.;
   double n0FRACl = 0.;
   double n0FRACd = 0.;
   for(int i=1;i<=nbFRAC;i++)
     {
	float b_cont = h_bjet_FRAC->GetBinContent(i);
	float b_err = h_bjet_FRAC->GetBinError(i);
	if( b_err > 0 ) nFRACb += pow(b_cont/b_err,2);
	n0FRACb += b_cont;
	float w_b = (b_cont > 0) ? b_err*b_err/b_cont : 1.;
	h_weights_b->SetBinContent(i,w_b);
	float c_cont = h_cjet_FRAC->GetBinContent(i);
	float c_err = h_cjet_FRAC->GetBinError(i);
	if( c_err > 0 ) nFRACc += pow(c_cont/c_err,2);
	n0FRACc += c_cont;
	float w_c = (c_cont > 0) ? c_err*c_err/c_cont : 1.;
	h_weights_c->SetBinContent(i,w_c);
	float l_cont = h_ljet_FRAC->GetBinContent(i);
	float l_err = h_ljet_FRAC->GetBinError(i);
	if( l_err > 0 ) nFRACl += pow(l_cont/l_err,2);
	n0FRACl += l_cont;
	float w_l = (l_cont > 0) ? l_err*l_err/l_cont : 1.;
	h_weights_l->SetBinContent(i,w_l);
	float a_data_cont = h_ajet_data_FRAC->GetBinContent(i);
	float a_data_err = h_ajet_data_FRAC->GetBinError(i);
	if( a_data_err > 0 ) nFRACd += pow(a_data_cont/a_data_err,2);
	n0FRACd += a_data_cont;
	
	b_cont = (b_err > 0) ? int(pow(b_cont/b_err,2)) : 0.;
	c_cont = (c_err > 0) ? int(pow(c_cont/c_err,2)) : 0.;
	l_cont = (l_err > 0) ? int(pow(l_cont/l_err,2)) : 0.;
	a_data_cont = (a_data_err > 0) ? int(pow(a_data_cont/a_data_err,2)) : 0.;
	h_bjet_FRAC->SetBinContent(i,b_cont);
	h_cjet_FRAC->SetBinContent(i,c_cont);
	h_ljet_FRAC->SetBinContent(i,l_cont);
	h_ajet_data_FRAC->SetBinContent(i,a_data_cont);
     }
/*   
   h_bjet_FRAC->Scale(nFRACb/n0FRACb);
   h_cjet_FRAC->Scale(nFRACc/n0FRACc);
   h_ljet_FRAC->Scale(nFRACl/n0FRACl);
   h_ajet_data_FRAC->Scale(nFRACd/n0FRACd);
  */ 
   TObjArray *mc = new TObjArray(3);
   mc->Add(h_bjet_FRAC);
   mc->Add(h_cjet_FRAC);
   mc->Add(h_ljet_FRAC);
   
   TFractionFitter* fit = new TFractionFitter(h_ajet_data_FRAC,mc,"Q");
   
   fit->Constrain(1,0.00001,10000.0);
   fit->Constrain(2,0.00001,10000.0);
   fit->Constrain(3,0.00001,10000.0);

   fit->SetWeight(0,h_weights_b);
   fit->SetWeight(1,h_weights_c);
   fit->SetWeight(2,h_weights_l);
   
   if( iPTcur == 0 ) fit->SetRangeX(1,1);
   else fit->SetRangeX(ibinMin,nbFRAC);
   
   Int_t status = fit->Fit();
   
   if( status == 0 )
     {	
	TH1F *result = (TH1F*)fit->GetPlot();
	float chi2 = fit->GetChisquare();
	float ndof = fit->GetNDF();
	chis[0] = chi2*ndof;
	chis[1] = ndof;
	std::cout << chi2 << std::endl;
	fit->GetResult(0,par[0],err[0]);
	fit->GetResult(1,par[1],err[1]);
	fit->GetResult(2,par[2],err[2]);
	std::cout << par[0] << " +- " << err[0] << std::endl;
	std::cout << par[1] << " +- " << err[1] << std::endl;
	std::cout << par[2] << " +- " << err[2] << std::endl;
	delete result;
     }
   else
     {
	std::cout << "FractionFitter fails" << std::endl;
	exit(1);
     }   

   delete h_bjet_FRAC;
   delete h_cjet_FRAC;
   delete h_ljet_FRAC;
   delete h_ajet_data_FRAC;

   delete h_weights_b;
   delete h_weights_c;
   delete h_weights_l;
   
   delete mc;
   delete fit;
}

void doFitCL(double *par,double *err,double *chis)
{   
   TMinuit *gMinuit = new TMinuit(1);
   gMinuit->SetFCN(fcnSys);
   gMinuit->SetPrintLevel(-1);
   
   Double_t arglist[10];
   Int_t ierflg = 0;
   
   arglist[0] = 1;
   gMinuit->mnexcm("SET ERR",arglist,1,ierflg);

   double nbs = 0.5;
   double ncls = 0.5;
   
//   double stp = pow(10,-4);
   double stp = pow(10,-6);
   
//   std::cout << "start: " << nbs << " " << ncs << " " << nls << std::endl;
   
   Double_t vstart[2] = {nbs,ncls};
   Double_t step[2] = {stp,stp};
   gMinuit->mnparm(0,"p1",vstart[0],step[0],0.00001,100,ierflg);
   gMinuit->mnparm(1,"p2",vstart[1],step[1],0.00001,100,ierflg);
   
   parg[0] = 1.;
   parg[1] = 1.;
   parg[2] = 1.;
   perg[0] = 1.;
   perg[1] = 1.;
   perg[2] = 1.;
   gMinuit->mnexcm("MIGRAD", arglist ,0,ierflg);
   gMinuit->GetParameter(0,parg[0],perg[0]);
   gMinuit->GetParameter(1,parg[1],perg[1]);
   gMinuit->mnexcm("MIGRAD", arglist ,0,ierflg);
   gMinuit->mnexcm("MINOS", arglist ,0,ierflg);
   gMinuit->mnexcm("MIGRAD", arglist ,0,ierflg);
   gMinuit->mnexcm("MINOS", arglist ,0,ierflg);

   arglist[0] = 3;
   gMinuit->mnexcm("CALL FCN",arglist,1,ierflg);
   
   double amin,edm,errdef;
   int nvpar,nparx,icstat;   
   gMinuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);
   chis[0] = amin;
   chis[1] = nbFitAdjust - gMinuit->GetNumFreePars();
   
   double pval[3], perr[3];
   gMinuit->GetParameter(0,pval[0],perr[0]);
   gMinuit->GetParameter(1,pval[1],perr[1]);
   
   par[0] = pval[0];
   par[1] = pval[1];
   par[2] = pval[1];
   err[0] = perr[0];
   err[1] = perr[1];
   err[2] = perr[1];
   
   delete gMinuit;
}
/*
void doFitCL(double *par,double *err,double *chis)
{   
   TMinuit *gMinuit = new TMinuit(1);
   gMinuit->SetFCN(fcnSys);
   gMinuit->SetPrintLevel(-1);
   
   Double_t arglist[10];
   Int_t ierflg = 0;
   
   arglist[0] = 1;
   gMinuit->mnexcm("SET ERR",arglist,1,ierflg);

   double nbs = 0.5;
   double ncls = 0.5;
   
//   double stp = pow(10,-4);
   double stp = pow(10,-6);
   
//   std::cout << "start: " << nbs << " " << ncs << " " << nls << std::endl;
   
   Double_t vstart[2] = {nbs,ncls};
   Double_t step[2] = {stp,stp};
   gMinuit->mnparm(0,"p1",vstart[0],step[0],0.00001,100,ierflg);
   gMinuit->mnparm(1,"p2",vstart[1],step[1],0.00001,100,ierflg);

   gMinuit->mnexcm("MIGRAD", arglist ,0,ierflg);
   gMinuit->mnexcm("MIGRAD", arglist ,0,ierflg);
   gMinuit->mnexcm("MIGRAD", arglist ,0,ierflg);
   gMinuit->mnexcm("MIGRAD", arglist ,0,ierflg);
   gMinuit->mnexcm("MINOS", arglist ,0,ierflg);

   arglist[0] = 3;
   gMinuit->mnexcm("CALL FCN",arglist,1,ierflg);
   
   double amin,edm,errdef;
   int nvpar,nparx,icstat;   
   gMinuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);
   chis[0] = amin;
   chis[1] = nbFitAdjust - gMinuit->GetNumFreePars();
   
   double pval[3], perr[3];
   gMinuit->GetParameter(0,pval[0],perr[0]);
   gMinuit->GetParameter(1,pval[1],perr[1]);
   
   par[0] = pval[0];
   par[1] = pval[1];
   par[2] = pval[1];
   err[0] = perr[0];
   err[1] = perr[1];
   err[2] = perr[1];
   
   delete gMinuit;
}
*/
void doFit2DIM(double *par,double *err,double *chis)
{   
   TMinuit *gMinuit = new TMinuit(1);
   gMinuit->SetFCN(fcn2DIM);
   gMinuit->SetPrintLevel(-1);
   
   Double_t arglist[10];
   Int_t ierflg = 0;
   
   arglist[0] = 1;
   gMinuit->mnexcm("SET ERR",arglist,1,ierflg);
   
   Double_t vstart[3] = {1.,1.,1.};
   Double_t step[3] = {0.0001,0.0001,0.0001};
   gMinuit->mnparm(0,"p1",vstart[0],step[0],0,100000,ierflg);
   gMinuit->mnparm(1,"p2",vstart[1],step[1],0,100000,ierflg);
   gMinuit->mnparm(2,"p3",vstart[2],step[2],0,100000,ierflg);
   
//   gMinuit->FixParameter(2);
   
   gMinuit->mnexcm("MIGRAD", arglist ,0,ierflg);
      
   
   double amin,edm,errdef;
   int nvpar,nparx,icstat;   
   gMinuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);
   chis[0] = amin;
   chis[1] = nbFitAdjust2d - gMinuit->GetNumFreePars();
//   std::cout << chis[0] << " " << chis[1] << std::endl;
//   chis[1] = nbins1 * nbins2 - gMinuit->GetNumFreePars();
   
   double pval[3], perr[3];
   gMinuit->GetParameter(0,pval[0],perr[0]);
   gMinuit->GetParameter(1,pval[1],perr[1]);
   gMinuit->GetParameter(2,pval[2],perr[2]);
   
   par[0] = pval[0];
   par[1] = pval[1];
   par[2] = pval[2];
   err[0] = perr[0];
   err[1] = perr[1];
   err[2] = perr[2];
   
   delete gMinuit;
}

void openData(int iVAR,
	      int iPT,
	      std::vector<std::string> *v_mc_filt,
	      std::vector<std::string> *v_mc_unfilt,
	      std::vector<std::string> v_data)
{
   // open MC
   for(int i=0;i<v_mc_filt->size();i++)
     {
	std::string fname_filt = fpathMC+v_mc_filt->at(i);
//	fbatch_mc_filt[i][iVAR] = TFile::Open(fname_filt.c_str());
	fbatch_mc_filt[i] = TFile::Open(fname_filt.c_str());
	std::string fname_unfilt = fpathMC+v_mc_unfilt->at(i);
//	fbatch_mc_unfilt[i][iVAR] = TFile::Open(fname_unfilt.c_str());
	fbatch_mc_unfilt[i] = TFile::Open(fname_unfilt.c_str());
     }
   // open DATA
   for(int i=0;i<v_data.size();i++)
     {
	std::string fname = fpathData+v_data.at(i);
//	fbatch_data[i][iVAR] = TFile::Open(fname.c_str());
	fbatch_data[i] = TFile::Open(fname.c_str());
     }   
}

void readData(int iVAR,
	      int iPT,
	      std::string hname_bjet,
	      std::string hname_cjet,
	      std::string hname_ljet,
	      std::string hname_ajet,
	      std::string hname_ljet_data,
	      std::string hname_bjet_untag,
	      std::string hname_cjet_untag,
//	      std::string hname_bjet_notag,
//	      std::string hname_cjet_notag,
	      std::string hname_bjet_posttag,
	      std::string hname_cjet_posttag,
	      std::string hname_ljet_posttag,
	      std::string hname_ajet_data_posttag,
	      std::string hname_bjet_notag,
	      std::string hname_cjet_notag,
	      std::string hname_ljet_notag,
	      std::string hname_ajet_data_notag,
	      std::vector<std::string> *v_mc_filt,
	      std::vector<std::string> *v_mc_unfilt,
	      std::vector<std::string> v_data)
{
   // read MC

   for(int i=0;i<v_mc_filt->size();i++)
     {
//	std::string fname_filt = fpathMC+v_mc_filt.at(i);
//	fbatch_mc_filt[i][iVAR] = TFile::Open(fname_filt.c_str());
//	std::string fname_unfilt = fpathMC+v_mc_unfilt.at(i);
//	fbatch_mc_unfilt[i][iVAR] = TFile::Open(fname_unfilt.c_str());
/*
	TH1F *hf_bjet = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(hname_bjet.c_str());
	TH1F *hf_cjet = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(hname_cjet.c_str());
	TH1F *hf_ljet = (TH1F*)fbatch_mc_unfilt[i][iVAR]->Get(hname_ljet.c_str());
	
	TH1F *hf_cljet = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(hname_cjet.c_str());
	TH1F *hf_bjet_untag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(hname_bjet_untag.c_str());
	TH1F *hf_cjet_untag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(hname_cjet_untag.c_str());
	//	     TH1F *hf_bjet_notag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(hname_bjet_notag.c_str());
	//	     TH1F *hf_cjet_notag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(hname_cjet_notag.c_str());
	TH1F *hf_bjet_posttag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(hname_bjet_posttag.c_str());
	TH1F *hf_cjet_posttag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(hname_cjet_posttag.c_str());
*/
	TH1D *hf_bjet = (TH1D*)fbatch_mc_filt[i]->Get(hname_bjet_nominal.c_str());
	TH1D *hf_cjet = (TH1D*)fbatch_mc_filt[i]->Get(hname_cjet_nominal.c_str());
	TH1D *hf_ljet = (TH1D*)fbatch_mc_unfilt[i]->Get(hname_ljet_nominal.c_str());
	
	TH1D *hf_bjet_sysUp = (TH1D*)fbatch_mc_filt[i]->Get(hname_bjet_sysUp.c_str());
	TH1D *hf_cjet_sysUp = (TH1D*)fbatch_mc_filt[i]->Get(hname_cjet_sysUp.c_str());
	TH1D *hf_ljet_sysUp = (TH1D*)fbatch_mc_unfilt[i]->Get(hname_ljet_sysUp.c_str());

	TH1D *hf_bjet_sysDown = (TH1D*)fbatch_mc_filt[i]->Get(hname_bjet_sysDown.c_str());
	TH1D *hf_cjet_sysDown = (TH1D*)fbatch_mc_filt[i]->Get(hname_cjet_sysDown.c_str());
	TH1D *hf_ljet_sysDown = (TH1D*)fbatch_mc_unfilt[i]->Get(hname_ljet_sysDown.c_str());
	
	TH1D *hf_bjet_init = (TH1D*)fbatch_mc_filt[i]->Get(hname_bjet_nominalInit.c_str());
	TH1D *hf_cjet_init = (TH1D*)fbatch_mc_filt[i]->Get(hname_cjet_nominalInit.c_str());
	TH1D *hf_ljet_init = (TH1D*)fbatch_mc_unfilt[i]->Get(hname_ljet_nominalInit.c_str());

	TH1D *hf_bjet_true = (TH1D*)fbatch_mc_filt[i]->Get(hname_bjet_nominalTrue.c_str());
	TH1D *hf_cjet_true = (TH1D*)fbatch_mc_filt[i]->Get(hname_cjet_nominalTrue.c_str());
	TH1D *hf_ljet_true = (TH1D*)fbatch_mc_unfilt[i]->Get(hname_ljet_nominalTrue.c_str());
	
	TH1D *hf_cljet = (TH1D*)fbatch_mc_filt[i]->Get(hname_cjet.c_str());
	TH1D *hf_bjet_untag = (TH1D*)fbatch_mc_filt[i]->Get(hname_bjet_untag.c_str());
	TH1D *hf_cjet_untag = (TH1D*)fbatch_mc_filt[i]->Get(hname_cjet_untag.c_str());
	//	     TH1F *hf_bjet_notag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(hname_bjet_notag.c_str());
	//	     TH1F *hf_cjet_notag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(hname_cjet_notag.c_str());
	TH1D *hf_bjet_posttag = (TH1D*)fbatch_mc_filt[i]->Get(hname_bjet_posttag.c_str());
	TH1D *hf_cjet_posttag = (TH1D*)fbatch_mc_filt[i]->Get(hname_cjet_posttag.c_str());
	TH1D *hf_ljet_posttag = (TH1D*)fbatch_mc_filt[i]->Get(hname_ljet_posttag.c_str());

	TH1D *hf_bjet_notag = (TH1D*)fbatch_mc_filt[i]->Get(hname_bjet_notag.c_str());
	TH1D *hf_cjet_notag = (TH1D*)fbatch_mc_filt[i]->Get(hname_cjet_notag.c_str());
	TH1D *hf_ljet_notag = (TH1D*)fbatch_mc_filt[i]->Get(hname_ljet_notag.c_str());
	
	if( i == 0 ) 
	  {
	     h_draw_bjet[iVAR] = (TH1D*)hf_bjet->Clone(hname_bjet_nominal.c_str());
	     h_draw_cjet[iVAR] = (TH1D*)hf_cjet->Clone(hname_cjet_nominal.c_str());
	     h_draw_ljet[iVAR] = (TH1D*)hf_ljet->Clone(hname_ljet_nominal.c_str());

	     h_draw_bjet_sysUp[iVAR] = (TH1D*)hf_bjet_sysUp->Clone(hname_bjet_sysUp.c_str());
	     h_draw_cjet_sysUp[iVAR] = (TH1D*)hf_cjet_sysUp->Clone(hname_cjet_sysUp.c_str());
	     h_draw_ljet_sysUp[iVAR] = (TH1D*)hf_ljet_sysUp->Clone(hname_ljet_sysUp.c_str());

	     h_draw_bjet_sysDown[iVAR] = (TH1D*)hf_bjet_sysDown->Clone(hname_bjet_sysDown.c_str());
	     h_draw_cjet_sysDown[iVAR] = (TH1D*)hf_cjet_sysDown->Clone(hname_cjet_sysDown.c_str());
	     h_draw_ljet_sysDown[iVAR] = (TH1D*)hf_ljet_sysDown->Clone(hname_ljet_sysDown.c_str());
	     
	     h_draw_bjet_init[iVAR] = (TH1D*)hf_bjet_init->Clone(hname_bjet_nominalInit.c_str());
	     h_draw_cjet_init[iVAR] = (TH1D*)hf_cjet_init->Clone(hname_cjet_nominalInit.c_str());
	     h_draw_ljet_init[iVAR] = (TH1D*)hf_ljet_init->Clone(hname_ljet_nominalInit.c_str());

	     h_draw_bjet_true[iVAR] = (TH1D*)hf_bjet_true->Clone(hname_bjet_nominalTrue.c_str());
	     h_draw_cjet_true[iVAR] = (TH1D*)hf_cjet_true->Clone(hname_cjet_nominalTrue.c_str());
	     h_draw_ljet_true[iVAR] = (TH1D*)hf_ljet_true->Clone(hname_ljet_nominalTrue.c_str());
	     
	     std::string hname_cljet = hname_cjet+"_plusl";
	     h_draw_cljet[iVAR] = (TH1D*)hf_cljet->Clone(hname_cljet.c_str());
	     h_draw_cljet[iVAR]->Add(h_draw_ljet[iVAR]);
	     
	     h_draw_bjet_untag[iVAR] = (TH1D*)hf_bjet_untag->Clone(hname_bjet_untag.c_str());
	     h_draw_cjet_untag[iVAR] = (TH1D*)hf_bjet_untag->Clone(hname_cjet_untag.c_str());
	     
	     //		  h_draw_bjet_notag[iVAR] = (TH1F*)hf_bjet_notag->Clone(hname_bjet_notag.c_str());
	     //		  h_draw_cjet_notag[iVAR] = (TH1F*)hf_bjet_notag->Clone(hname_cjet_notag.c_str());
	     
	     h_draw_bjet_posttag[iVAR] = (TH1D*)hf_bjet_posttag->Clone(hname_bjet_posttag.c_str());
	     h_draw_cjet_posttag[iVAR] = (TH1D*)hf_cjet_posttag->Clone(hname_cjet_posttag.c_str());
	     h_draw_ljet_posttag[iVAR] = (TH1D*)hf_ljet_posttag->Clone(hname_ljet_posttag.c_str());

	     h_draw_bjet_notag[iVAR] = (TH1D*)hf_bjet_notag->Clone(hname_bjet_notag.c_str());
	     h_draw_cjet_notag[iVAR] = (TH1D*)hf_cjet_notag->Clone(hname_cjet_notag.c_str());
	     h_draw_ljet_notag[iVAR] = (TH1D*)hf_ljet_notag->Clone(hname_ljet_notag.c_str());
	  }	
	else 
	  {
	     h_draw_ljet[iVAR]->Add(hf_ljet);
	     h_draw_cjet[iVAR]->Add(hf_cjet);
	     h_draw_bjet[iVAR]->Add(hf_bjet);

	     h_draw_ljet_sysUp[iVAR]->Add(hf_ljet_sysUp);
	     h_draw_cjet_sysUp[iVAR]->Add(hf_cjet_sysUp);
	     h_draw_bjet_sysUp[iVAR]->Add(hf_bjet_sysUp);

	     h_draw_ljet_sysDown[iVAR]->Add(hf_ljet_sysDown);
	     h_draw_cjet_sysDown[iVAR]->Add(hf_cjet_sysDown);
	     h_draw_bjet_sysDown[iVAR]->Add(hf_bjet_sysDown);
	     
	     h_draw_ljet_init[iVAR]->Add(hf_ljet_init);
	     h_draw_cjet_init[iVAR]->Add(hf_cjet_init);
	     h_draw_bjet_init[iVAR]->Add(hf_bjet_init);

	     h_draw_ljet_true[iVAR]->Add(hf_ljet_true);
	     h_draw_cjet_true[iVAR]->Add(hf_cjet_true);
	     h_draw_bjet_true[iVAR]->Add(hf_bjet_true);
	     
	     h_draw_bjet_untag[iVAR]->Add(hf_bjet_untag);
	     h_draw_cjet_untag[iVAR]->Add(hf_cjet_untag);
	     
	     //		  h_draw_bjet_notag[iVAR]->Add(hf_bjet_notag);
	     //		  h_draw_cjet_notag[iVAR]->Add(hf_cjet_notag);
	     
	     h_draw_bjet_posttag[iVAR]->Add(hf_bjet_posttag);
	     h_draw_cjet_posttag[iVAR]->Add(hf_cjet_posttag);
	     h_draw_ljet_posttag[iVAR]->Add(hf_ljet_posttag);

	     h_draw_bjet_notag[iVAR]->Add(hf_bjet_notag);
	     h_draw_cjet_notag[iVAR]->Add(hf_cjet_notag);
	     h_draw_ljet_notag[iVAR]->Add(hf_ljet_notag);
	     
	     h_draw_cljet[iVAR]->Add(hf_cjet);
	     h_draw_cljet[iVAR]->Add(hf_ljet);
	  }

	std::string cname_bjet = "";
	std::string cname_cjet = "";
	std::string cname_ljet = "";
	
	std::string cname_bjet_untag = "";
	std::string cname_cjet_untag = "";
	
	//	     std::string cname_bjet_notag = "";
	//	     std::string cname_cjet_notag = "";
	
	std::string cname_bjet_posttag = "";
	std::string cname_cjet_posttag = "";
	
	for(int j=0;j<nsysGL;j++)
	  {		  
	     cname_bjet = hname_bjet + name_sys_low[j];	     
	     cname_cjet = hname_cjet + name_sys_low[j];
	     cname_ljet = hname_ljet + name_sys_low[j];
	     cname_bjet_untag = hname_bjet_untag + name_sys_low[j];
	     cname_cjet_untag = hname_cjet_untag + name_sys_low[j];
	     //		  cname_bjet_notag = hname_bjet_notag + name_sys_low[j];
	     //		  cname_cjet_notag = hname_cjet_notag + name_sys_low[j];
	     cname_bjet_posttag = hname_bjet_posttag + name_sys_low[j];
	     cname_cjet_posttag = hname_cjet_posttag + name_sys_low[j];
/*	     
	     TH1F *hf_sys_low_bjet = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_bjet.c_str());
	     TH1F *hf_sys_low_cjet = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_cjet.c_str());
	     TH1F *hf_sys_low_ljet = (TH1F*)fbatch_mc_unfilt[i][iVAR]->Get(cname_ljet.c_str());
	     TH1F *hf_sys_low_bjet_untag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_bjet_untag.c_str());
	     TH1F *hf_sys_low_cjet_untag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_cjet_untag.c_str());
	     //		  TH1F *hf_sys_low_bjet_notag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_bjet_notag.c_str());
	     //		  TH1F *hf_sys_low_cjet_notag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_cjet_notag.c_str());
	     TH1F *hf_sys_low_bjet_posttag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_bjet_posttag.c_str());
	     TH1F *hf_sys_low_cjet_posttag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_cjet_posttag.c_str());
*/
	     TH1D *hf_sys_low_bjet = (TH1D*)fbatch_mc_filt[i]->Get(cname_bjet.c_str());
	     TH1D *hf_sys_low_cjet = (TH1D*)fbatch_mc_filt[i]->Get(cname_cjet.c_str());
	     TH1D *hf_sys_low_ljet = (TH1D*)fbatch_mc_unfilt[i]->Get(cname_ljet.c_str());
	     TH1D *hf_sys_low_bjet_untag = (TH1D*)fbatch_mc_filt[i]->Get(cname_bjet_untag.c_str());
	     TH1D *hf_sys_low_cjet_untag = (TH1D*)fbatch_mc_filt[i]->Get(cname_cjet_untag.c_str());
	     //		  TH1F *hf_sys_low_bjet_notag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_bjet_notag.c_str());
	     //		  TH1F *hf_sys_low_cjet_notag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_cjet_notag.c_str());
	     TH1D *hf_sys_low_bjet_posttag = (TH1D*)fbatch_mc_filt[i]->Get(cname_bjet_posttag.c_str());
	     TH1D *hf_sys_low_cjet_posttag = (TH1D*)fbatch_mc_filt[i]->Get(cname_cjet_posttag.c_str());
	     
	     cname_bjet = cname_bjet + "_cloneLOW";
	     cname_cjet = cname_cjet + "_cloneLOW";
	     cname_ljet = cname_ljet + "_cloneLOW";
	     cname_bjet_untag = cname_bjet_untag + "_cloneLOW";
	     cname_cjet_untag = cname_cjet_untag + "_cloneLOW";
	     //		  cname_bjet_notag = cname_bjet_notag + "_cloneLOW";
	     //		  cname_cjet_notag = cname_cjet_notag + "_cloneLOW";
	     cname_bjet_posttag = cname_bjet_posttag + "_cloneLOW";
	     cname_cjet_posttag = cname_cjet_posttag + "_cloneLOW";
	     
	     if( i == 0 ) 
	       {
		  h_draw_bjet_sys_low[j][iVAR] = (TH1D*)hf_sys_low_bjet->Clone(cname_bjet.c_str());
		  h_draw_cjet_sys_low[j][iVAR] = (TH1D*)hf_sys_low_cjet->Clone(cname_cjet.c_str());
		  h_draw_ljet_sys_low[j][iVAR] = (TH1D*)hf_sys_low_ljet->Clone(cname_ljet.c_str());
		  h_draw_bjet_untag_sys_low[j][iVAR] = (TH1D*)hf_sys_low_bjet_untag->Clone(cname_bjet_untag.c_str());
		  h_draw_cjet_untag_sys_low[j][iVAR] = (TH1D*)hf_sys_low_cjet_untag->Clone(cname_cjet_untag.c_str());
		  //		       h_draw_bjet_notag_sys_low[j][iVAR] = (TH1F*)hf_sys_low_bjet_notag->Clone(cname_bjet_notag.c_str());
		  //		       h_draw_cjet_notag_sys_low[j][iVAR] = (TH1F*)hf_sys_low_cjet_notag->Clone(cname_cjet_notag.c_str());
		  h_draw_bjet_posttag_sys_low[j][iVAR] = (TH1D*)hf_sys_low_bjet_posttag->Clone(cname_bjet_posttag.c_str());
		  h_draw_cjet_posttag_sys_low[j][iVAR] = (TH1D*)hf_sys_low_cjet_posttag->Clone(cname_cjet_posttag.c_str());
	       }
	     else 
	       {
		  h_draw_ljet_sys_low[j][iVAR]->Add(hf_sys_low_ljet);
		  h_draw_cjet_sys_low[j][iVAR]->Add(hf_sys_low_cjet);
		  h_draw_bjet_sys_low[j][iVAR]->Add(hf_sys_low_bjet);
		  h_draw_bjet_untag_sys_low[j][iVAR]->Add(hf_sys_low_bjet_untag);
		  h_draw_cjet_untag_sys_low[j][iVAR]->Add(hf_sys_low_cjet_untag);
		  //		       h_draw_bjet_notag_sys_low[j][iVAR]->Add(hf_sys_low_bjet_notag);
		  //		       h_draw_cjet_notag_sys_low[j][iVAR]->Add(hf_sys_low_cjet_notag);
		  h_draw_bjet_posttag_sys_low[j][iVAR]->Add(hf_sys_low_bjet_posttag);
		  h_draw_cjet_posttag_sys_low[j][iVAR]->Add(hf_sys_low_cjet_posttag);
	       }
	     
	     cname_bjet = hname_bjet + name_sys_up[j];
	     cname_cjet = hname_cjet + name_sys_up[j];
	     cname_ljet = hname_ljet + name_sys_up[j];
	     cname_bjet_untag = hname_bjet_untag + name_sys_up[j];
	     cname_cjet_untag = hname_cjet_untag + name_sys_up[j];
	     //		  cname_bjet_notag = hname_bjet_notag + name_sys_up[j];
	     //		  cname_cjet_notag = hname_cjet_notag + name_sys_up[j];
	     cname_bjet_posttag = hname_bjet_posttag + name_sys_up[j];
	     cname_cjet_posttag = hname_cjet_posttag + name_sys_up[j];
/*	     
	     TH1F *hf_sys_up_bjet = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_bjet.c_str());
	     TH1F *hf_sys_up_cjet = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_cjet.c_str());
	     TH1F *hf_sys_up_ljet = (TH1F*)fbatch_mc_unfilt[i][iVAR]->Get(cname_ljet.c_str());
	     TH1F *hf_sys_up_bjet_untag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_bjet_untag.c_str());
	     TH1F *hf_sys_up_cjet_untag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_cjet_untag.c_str());
	     //		  TH1F *hf_sys_up_bjet_notag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_bjet_notag.c_str());
	     //		  TH1F *hf_sys_up_cjet_notag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_cjet_notag.c_str());
	     TH1F *hf_sys_up_bjet_posttag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_bjet_posttag.c_str());
	     TH1F *hf_sys_up_cjet_posttag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_cjet_posttag.c_str());
*/
	     TH1D *hf_sys_up_bjet = (TH1D*)fbatch_mc_filt[i]->Get(cname_bjet.c_str());
	     TH1D *hf_sys_up_cjet = (TH1D*)fbatch_mc_filt[i]->Get(cname_cjet.c_str());
	     TH1D *hf_sys_up_ljet = (TH1D*)fbatch_mc_unfilt[i]->Get(cname_ljet.c_str());
	     TH1D *hf_sys_up_bjet_untag = (TH1D*)fbatch_mc_filt[i]->Get(cname_bjet_untag.c_str());
	     TH1D *hf_sys_up_cjet_untag = (TH1D*)fbatch_mc_filt[i]->Get(cname_cjet_untag.c_str());
	     //		  TH1F *hf_sys_up_bjet_notag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_bjet_notag.c_str());
	     //		  TH1F *hf_sys_up_cjet_notag = (TH1F*)fbatch_mc_filt[i][iVAR]->Get(cname_cjet_notag.c_str());
	     TH1D *hf_sys_up_bjet_posttag = (TH1D*)fbatch_mc_filt[i]->Get(cname_bjet_posttag.c_str());
	     TH1D *hf_sys_up_cjet_posttag = (TH1D*)fbatch_mc_filt[i]->Get(cname_cjet_posttag.c_str());
	     
	     cname_bjet = cname_bjet + "_cloneUP";
	     cname_cjet = cname_cjet + "_cloneUP";
	     cname_ljet = cname_ljet + "_cloneUP";
	     cname_bjet_untag = cname_bjet_untag + "_cloneUP";
	     cname_cjet_untag = cname_cjet_untag + "_cloneUP";
	     //		  cname_bjet_notag = cname_bjet_notag + "_cloneUP";
	     //		  cname_cjet_notag = cname_cjet_notag + "_cloneUP";
	     cname_bjet_posttag = cname_bjet_posttag + "_cloneUP";
	     cname_cjet_posttag = cname_cjet_posttag + "_cloneUP";
	     
	     if( i == 0 ) 
	       {
		  h_draw_bjet_sys_up[j][iVAR] = (TH1D*)hf_sys_up_bjet->Clone(cname_bjet.c_str());
		  h_draw_cjet_sys_up[j][iVAR] = (TH1D*)hf_sys_up_cjet->Clone(cname_cjet.c_str());
		  h_draw_ljet_sys_up[j][iVAR] = (TH1D*)hf_sys_up_ljet->Clone(cname_ljet.c_str());
		  h_draw_bjet_untag_sys_up[j][iVAR] = (TH1D*)hf_sys_up_bjet_untag->Clone(cname_bjet_untag.c_str());
		  h_draw_cjet_untag_sys_up[j][iVAR] = (TH1D*)hf_sys_up_cjet_untag->Clone(cname_cjet_untag.c_str());
		  //		       h_draw_bjet_notag_sys_up[j][iVAR] = (TH1F*)hf_sys_up_bjet_notag->Clone(cname_bjet_notag.c_str());
		  //		       h_draw_cjet_notag_sys_up[j][iVAR] = (TH1F*)hf_sys_up_cjet_notag->Clone(cname_cjet_notag.c_str());
		  h_draw_bjet_posttag_sys_up[j][iVAR] = (TH1D*)hf_sys_up_bjet_posttag->Clone(cname_bjet_posttag.c_str());
		  h_draw_cjet_posttag_sys_up[j][iVAR] = (TH1D*)hf_sys_up_cjet_posttag->Clone(cname_cjet_posttag.c_str());
	       }
	     else 
	       {
		  h_draw_ljet_sys_up[j][iVAR]->Add(hf_sys_up_ljet);
		  h_draw_cjet_sys_up[j][iVAR]->Add(hf_sys_up_cjet);
		  h_draw_bjet_sys_up[j][iVAR]->Add(hf_sys_up_bjet);
		  h_draw_bjet_untag_sys_up[j][iVAR]->Add(hf_sys_up_bjet_untag);
		  h_draw_cjet_untag_sys_up[j][iVAR]->Add(hf_sys_up_cjet_untag);
		  //		       h_draw_bjet_notag_sys_up[j][iVAR]->Add(hf_sys_up_bjet_notag);
		  //		       h_draw_cjet_notag_sys_up[j][iVAR]->Add(hf_sys_up_cjet_notag);
		  h_draw_bjet_posttag_sys_up[j][iVAR]->Add(hf_sys_up_bjet_posttag);
		  h_draw_cjet_posttag_sys_up[j][iVAR]->Add(hf_sys_up_cjet_posttag);
	       }
	     
	     delete hf_sys_low_bjet;
	     delete hf_sys_low_cjet;
	     delete hf_sys_low_ljet;	     
	     delete hf_sys_low_bjet_untag;
	     delete hf_sys_low_cjet_untag;
	     delete hf_sys_low_bjet_posttag;
	     delete hf_sys_low_cjet_posttag;

	     delete hf_sys_up_bjet;
	     delete hf_sys_up_cjet;
	     delete hf_sys_up_ljet;
	     delete hf_sys_up_bjet_untag;
	     delete hf_sys_up_cjet_untag;
	     delete hf_sys_up_bjet_posttag;
	     delete hf_sys_up_cjet_posttag;
	  }

	delete hf_bjet;
	delete hf_cjet;
	delete hf_ljet;
	
	delete hf_cljet;
	delete hf_bjet_untag;
	delete hf_cjet_untag;
	delete hf_bjet_posttag;
	delete hf_cjet_posttag;
     }   

   // read data

   if( sysIdx >= 666 )
     {
	TRandom3 *r_bjet = new TRandom3(sysIdx);
	int nbins_bjet = h_draw_bjet[iVAR]->GetXaxis()->GetNbins();
	for(int ibb=0;ibb<=nbins_bjet+1;ibb++)
	  {
	     double v = h_draw_bjet[iVAR]->GetBinContent(ibb);
	     double e = h_draw_bjet[iVAR]->GetBinError(ibb);
	     double v_t = h_draw_bjet_posttag[iVAR]->GetBinContent(ibb);
	     double e_t = h_draw_bjet_posttag[iVAR]->GetBinError(ibb);
	     double v_nt = h_draw_bjet_notag[iVAR]->GetBinContent(ibb);
	     double e_nt = h_draw_bjet_notag[iVAR]->GetBinError(ibb);
	     double rnd_bjet = r_bjet->Gaus(0,1);
	     double rnd_bjet_2 = r_bjet->Gaus(0,1);
	     double vNew = v;
	     if( iBTAGcur == 0 )
	       {
//		  vNew += sqrt(pow(e_t*rnd_bjet,2)+pow(e_nt*rnd_bjet_2,2));
		  vNew += e_t*rnd_bjet+e_nt*rnd_bjet_2;
	       }	     
	     else
	       {		  
		  vNew += e*rnd_bjet;
	       }	     
	     h_draw_bjet[iVAR]->SetBinContent(ibb,vNew);
	  }	
	delete r_bjet;
	
	TRandom3 *r_cjet = new TRandom3(sysIdx+1);
	int nbins_cjet = h_draw_cjet[iVAR]->GetXaxis()->GetNbins();
	for(int ibb=0;ibb<=nbins_cjet+1;ibb++)
	  {
	     double v = h_draw_cjet[iVAR]->GetBinContent(ibb);
	     double e = h_draw_cjet[iVAR]->GetBinError(ibb);
	     double v_t = h_draw_cjet_posttag[iVAR]->GetBinContent(ibb);
	     double e_t = h_draw_cjet_posttag[iVAR]->GetBinError(ibb);
	     double v_nt = h_draw_cjet_notag[iVAR]->GetBinContent(ibb);
	     double e_nt = h_draw_cjet_notag[iVAR]->GetBinError(ibb);
	     double rnd_cjet = r_cjet->Gaus(0,1);
	     double rnd_cjet_2 = r_cjet->Gaus(0,1);
	     double vNew = v;
	     if( iBTAGcur == 0 )
	       {
//		  vNew += sqrt(pow(e_t*rnd_cjet,2)+pow(e_nt*rnd_cjet_2,2));
		  vNew += e_t*rnd_cjet+e_nt*rnd_cjet_2;
	       }	     
	     else
	       {		  
		  vNew += e*rnd_cjet;
	       }	     
	     h_draw_cjet[iVAR]->SetBinContent(ibb,vNew);
	  }	
	delete r_cjet;

	TRandom3 *r_ljet = new TRandom3(sysIdx+2);
	int nbins_ljet = h_draw_ljet[iVAR]->GetXaxis()->GetNbins();
	for(int ibb=0;ibb<=nbins_ljet+1;ibb++)
	  {
	     double v = h_draw_ljet[iVAR]->GetBinContent(ibb);
	     double e = h_draw_ljet[iVAR]->GetBinError(ibb);
	     double v_t = h_draw_ljet_posttag[iVAR]->GetBinContent(ibb);
	     double e_t = h_draw_ljet_posttag[iVAR]->GetBinError(ibb);
	     double v_nt = h_draw_ljet_notag[iVAR]->GetBinContent(ibb);
	     double e_nt = h_draw_ljet_notag[iVAR]->GetBinError(ibb);
	     double rnd_ljet = r_ljet->Gaus(0,1);
	     double rnd_ljet_2 = r_ljet->Gaus(0,1);
	     double vNew = v;
	     if( iBTAGcur == 0 )
	       {
//		  vNew += sqrt(pow(e_t*rnd_ljet,2)+pow(e_nt*rnd_ljet_2,2));
		  vNew += e_t*rnd_ljet+e_nt*rnd_ljet_2;
	       }	     
	     else
	       {		  
		  vNew += e*rnd_ljet;
	       }	     
	     h_draw_ljet[iVAR]->SetBinContent(ibb,vNew);
	  }	
	delete r_ljet;
     }   

   if( !replaceDataByMC )
     {	
	for(int i=0;i<v_data.size();i++)
	  {
	     TH1D *hf_ajet = (TH1D*)fbatch_data[i]->Get(hname_ajet.c_str());
	     TH1D *hf_ljet_data = (TH1D*)fbatch_data[i]->Get(hname_ljet_data.c_str());
	     TH1D *hf_ajet_data_posttag = (TH1D*)fbatch_data[i]->Get(hname_ajet_data_posttag.c_str());
	     TH1D *hf_ajet_data_notag = (TH1D*)fbatch_data[i]->Get(hname_ajet_data_notag.c_str());
	     
	     if( i == 0 ) 
	       {
		  h_draw_ajet_data[iVAR] = (TH1D*)hf_ajet->Clone(hname_ajet.c_str());
		  h_draw_ljet_data[iVAR] = (TH1D*)hf_ljet_data->Clone(hname_ljet_data.c_str());
		  h_draw_ajet_data_posttag[iVAR] = (TH1D*)hf_ajet_data_posttag->Clone(hname_ajet_data_posttag.c_str());
		  h_draw_ajet_data_notag[iVAR] = (TH1D*)hf_ajet_data_notag->Clone(hname_ajet_data_notag.c_str());
	       }	
	     else 
	       {
		  h_draw_ajet_data[iVAR]->Add(hf_ajet);
		  h_draw_ljet_data[iVAR]->Add(hf_ljet_data);
		  h_draw_ajet_data_posttag[iVAR]->Add(hf_ajet_data_posttag);
		  h_draw_ajet_data_notag[iVAR]->Add(hf_ajet_data_notag);
	       }
	     
	     std::string cname_ljet_data = "";
	     
	     for(int j=0;j<nsysGL;j++)
	       {		  
		  cname_ljet_data = hname_ljet_data + name_sys_low[j];
		  
		  TH1D *hf_sys_low_ljet_data = (TH1D*)fbatch_data[i]->Get(cname_ljet_data.c_str());
		  
		  cname_ljet_data = cname_ljet_data + "_clone_low";
		  if( i == 0 ) 
		    {
		       h_draw_ljet_data_sys_low[j][iVAR] = (TH1D*)hf_sys_low_ljet_data->Clone(cname_ljet_data.c_str());
		    }
		  else 
		    {
		       h_draw_ljet_data_sys_low[j][iVAR]->Add(hf_sys_low_ljet_data);
		    }		 
		  
		  cname_ljet_data = hname_ljet_data + name_sys_up[j];
		  
		  TH1D *hf_sys_up_ljet_data = (TH1D*)fbatch_data[i]->Get(cname_ljet_data.c_str());
		  
		  cname_ljet_data = cname_ljet_data + "_clone_up";
		  if( i == 0 ) 
		    {
		       h_draw_ljet_data_sys_up[j][iVAR] = (TH1D*)hf_sys_up_ljet_data->Clone(cname_ljet_data.c_str());
		    }
		  else 
		    {
		       h_draw_ljet_data_sys_up[j][iVAR]->Add(hf_sys_up_ljet_data);
		    }
		  
		  delete hf_sys_low_ljet_data;
		  delete hf_sys_up_ljet_data;
	       }
	     
	     delete hf_ajet;
	     delete hf_ljet_data;
	  }   
     }
   else
     {
	for(int i=0;i<v_mc_filt->size();i++)
	  {
	     TH1D *hf_ajet = (TH1D*)fbatch_mc_filt[i]->Get(hname_ajet.c_str());
	     TH1D *hf_ljet_data = (TH1D*)fbatch_mc_filt[i]->Get(hname_ljet_data.c_str());
	     TH1D *hf_ajet_data_posttag = (TH1D*)fbatch_mc_filt[i]->Get(hname_ajet_data_posttag.c_str());
	     TH1D *hf_ajet_data_notag = (TH1D*)fbatch_mc_filt[i]->Get(hname_ajet_data_notag.c_str());
	     
	     if( i == 0 ) 
	       {
		  h_draw_ajet_data[iVAR] = (TH1D*)hf_ajet->Clone(hname_ajet.c_str());
		  h_draw_ljet_data[iVAR] = (TH1D*)hf_ljet_data->Clone(hname_ljet_data.c_str());
		  h_draw_ajet_data_posttag[iVAR] = (TH1D*)hf_ajet_data_posttag->Clone(hname_ajet_data_posttag.c_str());
		  h_draw_ajet_data_notag[iVAR] = (TH1D*)hf_ajet_data_notag->Clone(hname_ajet_data_notag.c_str());
	       }	
	     else 
	       {
		  h_draw_ajet_data[iVAR]->Add(hf_ajet);
		  h_draw_ljet_data[iVAR]->Add(hf_ljet_data);
		  h_draw_ajet_data_posttag[iVAR]->Add(hf_ajet_data_posttag);
		  h_draw_ajet_data_notag[iVAR]->Add(hf_ajet_data_notag);
	       }
	     
	     std::string cname_ljet_data = "";
	     
	     for(int j=0;j<nsysGL;j++)
	       {		  
		  cname_ljet_data = hname_ljet_data + name_sys_low[j];
		  
		  TH1D *hf_sys_low_ljet_data = (TH1D*)fbatch_mc_filt[i]->Get(cname_ljet_data.c_str());
		  
		  cname_ljet_data = cname_ljet_data + "_clone_low";
		  if( i == 0 ) 
		    {
		       h_draw_ljet_data_sys_low[j][iVAR] = (TH1D*)hf_sys_low_ljet_data->Clone(cname_ljet_data.c_str());
		    }
		  else 
		    {
		       h_draw_ljet_data_sys_low[j][iVAR]->Add(hf_sys_low_ljet_data);
		    }		 
		  
		  cname_ljet_data = hname_ljet_data + name_sys_up[j];
		  
		  TH1D *hf_sys_up_ljet_data = (TH1D*)fbatch_mc_filt[i]->Get(cname_ljet_data.c_str());
		  
		  cname_ljet_data = cname_ljet_data + "_clone_up";
		  if( i == 0 ) 
		    {
		       h_draw_ljet_data_sys_up[j][iVAR] = (TH1D*)hf_sys_up_ljet_data->Clone(cname_ljet_data.c_str());
		    }
		  else 
		    {
		       h_draw_ljet_data_sys_up[j][iVAR]->Add(hf_sys_up_ljet_data);
		    }
		  
		  delete hf_sys_low_ljet_data;
		  delete hf_sys_up_ljet_data;
	       }
	     
	     delete hf_ajet;
	     delete hf_ljet_data;
	  }   
     }
   
   if( sysIdx >= 666 )
     {
	TRandom3 *r_ajet_data = new TRandom3(sysIdx+10);
	int nbins_ajet_data = h_draw_ajet_data[iVAR]->GetXaxis()->GetNbins();
	for(int ibb=0;ibb<=nbins_ajet_data+1;ibb++)
	  {
	     double v = h_draw_ajet_data[iVAR]->GetBinContent(ibb);
	     double e = h_draw_ajet_data[iVAR]->GetBinError(ibb);
	     double v_t = h_draw_ajet_data_posttag[iVAR]->GetBinContent(ibb);
	     double e_t = h_draw_ajet_data_posttag[iVAR]->GetBinError(ibb);
	     double v_nt = h_draw_ajet_data_notag[iVAR]->GetBinContent(ibb);
	     double e_nt = h_draw_ajet_data_notag[iVAR]->GetBinError(ibb);
	     double rnd_ajet_data = r_ajet_data->Gaus(0,1);
	     double rnd_ajet_data_2 = r_ajet_data->Gaus(0,1);
	     double vNew = v;
	     if( iBTAGcur == 0 )
	       {
//		  std::cout << e << " " << e_t << " " << e_nt << std::endl;
//		  vNew += sqrt(pow(e_t*rnd_ajet_data,2)+pow(e_nt*rnd_ajet_data_2,2));
		  vNew += e_t*rnd_ajet_data+e_nt*rnd_ajet_data_2;
	       }	     
	     else
	       {		  
		  vNew += e*rnd_ajet_data;
	       }	     
	     h_draw_ajet_data[iVAR]->SetBinContent(ibb,vNew);
	  }	
	delete r_ajet_data;
     }   
   
   // bin optimisation
   
   addbin(h_draw_bjet[iVAR]);
   addbin(h_draw_cjet[iVAR]);
   addbin(h_draw_ljet[iVAR]);
   addbin(h_draw_bjet_init[iVAR]);
   addbin(h_draw_cjet_init[iVAR]);
   addbin(h_draw_ljet_init[iVAR]);
   addbin(h_draw_bjet_true[iVAR]);
   addbin(h_draw_cjet_true[iVAR]);
   addbin(h_draw_ljet_true[iVAR]);
   addbin(h_draw_bjet_sysUp[iVAR]);
   addbin(h_draw_cjet_sysUp[iVAR]);
   addbin(h_draw_ljet_sysUp[iVAR]);
   addbin(h_draw_bjet_sysDown[iVAR]);
   addbin(h_draw_cjet_sysDown[iVAR]);
   addbin(h_draw_ljet_sysDown[iVAR]);
   addbin(h_draw_bjet_untag[iVAR]);
   addbin(h_draw_cjet_untag[iVAR]);
   addbin(h_draw_bjet_posttag[iVAR]);
   addbin(h_draw_cjet_posttag[iVAR]);
   addbin(h_draw_ljet_posttag[iVAR]);
   addbin(h_draw_ajet_data_posttag[iVAR]);
   addbin(h_draw_bjet_notag[iVAR]);
   addbin(h_draw_cjet_notag[iVAR]);
   addbin(h_draw_ljet_notag[iVAR]);
   addbin(h_draw_ajet_data_notag[iVAR]);
   addbin(h_draw_ljet_data[iVAR]);
   addbin(h_draw_cljet[iVAR]);
   
   addbin(h_draw_ajet_data[iVAR]);
   
   TH1D *hadj = (TH1D*)h_draw_bjet_init[iVAR]->Clone("hadj");
   hadj->Add(h_draw_cjet_init[iVAR],1.);
   hadj->Add(h_draw_ljet_init[iVAR],1.);
   
   double vIntData = h_draw_ajet_data[iVAR]->Integral();
   double ibinMaxData = ibinMax;
   if( vIntData > 0. )
     {	
	int nb = h_draw_ajet_data[iVAR]->GetXaxis()->GetNbins();
	double vIntCur = 0.;
	for(int ib=0;ib<=nb+1;ib++)
	  {
	     double v = h_draw_ajet_data[iVAR]->GetBinContent(ib);
	     vIntCur += v;
	     if( vIntCur/vIntData >= (1.-removeFromFit[iPT]) )
	       {
		  ibinMaxData = ib;
		  break;
	       }	     
	  }   
     }   

   double vIntMC = hadj->Integral();
   double ibinMaxMC = ibinMax;
   if( vIntMC > 0. )
     {	
	int nb = hadj->GetXaxis()->GetNbins();
	double vIntCur = 0.;
	for(int ib=0;ib<=nb+1;ib++)
	  {
	     double v = hadj->GetBinContent(ib);
	     vIntCur += v;
	     if( vIntCur/vIntMC >= (1.-removeFromFit[iPT]) )
	       {
		  ibinMaxMC = ib;
		  break;
	       }	     
	  }   
     }   

   double ibinMinMC = ibinMin;
   if( vIntMC > 0. )
     {	
	int nb = hadj->GetXaxis()->GetNbins();
	double vIntCur = 0.;
	for(int ib=nb+1;ib>=0;ib--)
	  {
	     double v = hadj->GetBinContent(ib);
	     vIntCur += v;
	     if( (vIntMC-vIntCur)/vIntMC <= removeFromFitMin[iPT] )
	       {
		  ibinMinMC = ib;
		  break;
	       }	     
	  }   
     }   

   ibinMax = ibinMaxMC; // or ibinMaxData
   ibinMin = ibinMinMC; 
   std::cout << "Fit is done in the range of bins #" << ibinMin << "-" << ibinMax << std::endl;
   
   // adjust empty bins in data
   adjust(h_draw_ajet_data[iVAR]);
   
   removeMCNeg(h_draw_bjet[iVAR]);
   removeMCNeg(h_draw_cjet[iVAR]);
   removeMCNeg(h_draw_ljet[iVAR]);

   removeMCNeg(h_draw_bjet_init[iVAR]);
   removeMCNeg(h_draw_cjet_init[iVAR]);
   removeMCNeg(h_draw_ljet_init[iVAR]);

   removeMCNeg(h_draw_bjet_true[iVAR]);
   removeMCNeg(h_draw_cjet_true[iVAR]);
   removeMCNeg(h_draw_ljet_true[iVAR]);

   removeMCNeg(h_draw_bjet_sysUp[iVAR]);
   removeMCNeg(h_draw_cjet_sysUp[iVAR]);
   removeMCNeg(h_draw_ljet_sysUp[iVAR]);

   removeMCNeg(h_draw_bjet_sysDown[iVAR]);
   removeMCNeg(h_draw_cjet_sysDown[iVAR]);
   removeMCNeg(h_draw_ljet_sysDown[iVAR]);

   removeMCNeg(h_draw_bjet_untag[iVAR]);
   removeMCNeg(h_draw_cjet_untag[iVAR]);

   removeMCNeg(h_draw_bjet_posttag[iVAR]);
   removeMCNeg(h_draw_cjet_posttag[iVAR]);
   removeMCNeg(h_draw_ljet_posttag[iVAR]);

   removeMCNeg(h_draw_bjet_notag[iVAR]);
   removeMCNeg(h_draw_cjet_notag[iVAR]);
   removeMCNeg(h_draw_ljet_notag[iVAR]);
   
   for(int j=0;j<nsysGL;j++)
     {	     
	addbin(h_draw_bjet_sys_low[j][iVAR]);
	addbin(h_draw_bjet_sys_up[j][iVAR]);
	
	addbin(h_draw_cjet_sys_low[j][iVAR]);
	addbin(h_draw_cjet_sys_up[j][iVAR]);
	     
	addbin(h_draw_ljet_sys_low[j][iVAR]);
	addbin(h_draw_ljet_sys_up[j][iVAR]);
	
	addbin(h_draw_bjet_untag_sys_low[j][iVAR]);
	addbin(h_draw_bjet_untag_sys_up[j][iVAR]);
	
	addbin(h_draw_cjet_untag_sys_low[j][iVAR]);
	addbin(h_draw_cjet_untag_sys_up[j][iVAR]);

	addbin(h_draw_bjet_posttag_sys_low[j][iVAR]);
	addbin(h_draw_bjet_posttag_sys_up[j][iVAR]);
	
	addbin(h_draw_cjet_posttag_sys_low[j][iVAR]);
	addbin(h_draw_cjet_posttag_sys_up[j][iVAR]);
	
	addbin(h_draw_ljet_data_sys_low[j][iVAR]);
	addbin(h_draw_ljet_data_sys_up[j][iVAR]);
          
	removeMCNeg(h_draw_bjet_sys_low[j][iVAR]);
	removeMCNeg(h_draw_bjet_sys_up[j][iVAR]);
	
	removeMCNeg(h_draw_cjet_sys_low[j][iVAR]);
	removeMCNeg(h_draw_cjet_sys_up[j][iVAR]);
	     
	removeMCNeg(h_draw_ljet_sys_low[j][iVAR]);
	removeMCNeg(h_draw_ljet_sys_up[j][iVAR]);
	
	removeMCNeg(h_draw_bjet_untag_sys_low[j][iVAR]);
	removeMCNeg(h_draw_bjet_untag_sys_up[j][iVAR]);
	
	removeMCNeg(h_draw_cjet_untag_sys_low[j][iVAR]);
	removeMCNeg(h_draw_cjet_untag_sys_up[j][iVAR]);

	removeMCNeg(h_draw_bjet_posttag_sys_low[j][iVAR]);
	removeMCNeg(h_draw_bjet_posttag_sys_up[j][iVAR]);
	
	removeMCNeg(h_draw_cjet_posttag_sys_low[j][iVAR]);
	removeMCNeg(h_draw_cjet_posttag_sys_up[j][iVAR]);
	
	removeMCNeg(h_draw_ljet_data_sys_low[j][iVAR]);
	removeMCNeg(h_draw_ljet_data_sys_up[j][iVAR]);
     }	

   // merge last bins
   if( doMergeBins )
     {	
	double *xn;
	int nb0 = h_draw_bjet[iVAR]->GetXaxis()->GetNbins();
	bool doRebin = ( ibinMax < nb0 || ibinMin > 1 );
	const int arrs = ibinMax-(ibinMin-1)+1;
	//const int arrs = ibinMax+1;
	double xnew[arrs];

	xn = mergeBins(h_draw_bjet[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_bjet[iVAR] = (TH1D*)h_draw_bjet[iVAR]->Rebin(arrs-1,"",xn);

	xn = mergeBins(h_draw_cjet[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_cjet[iVAR] = (TH1D*)h_draw_cjet[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_ljet[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_ljet[iVAR] = (TH1D*)h_draw_ljet[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_bjet_init[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_bjet_init[iVAR] = (TH1D*)h_draw_bjet_init[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_cjet_init[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_cjet_init[iVAR] = (TH1D*)h_draw_cjet_init[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_ljet_init[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_ljet_init[iVAR] = (TH1D*)h_draw_ljet_init[iVAR]->Rebin(arrs-1,"",xn);

	xn = mergeBins(h_draw_bjet_true[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_bjet_true[iVAR] = (TH1D*)h_draw_bjet_true[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_cjet_true[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_cjet_true[iVAR] = (TH1D*)h_draw_cjet_true[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_ljet_true[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_ljet_true[iVAR] = (TH1D*)h_draw_ljet_true[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_bjet_sysUp[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_bjet_sysUp[iVAR] = (TH1D*)h_draw_bjet_sysUp[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_cjet_sysUp[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_cjet_sysUp[iVAR] = (TH1D*)h_draw_cjet_sysUp[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_ljet_sysUp[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_ljet_sysUp[iVAR] = (TH1D*)h_draw_ljet_sysUp[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_bjet_sysDown[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_bjet_sysDown[iVAR] = (TH1D*)h_draw_bjet_sysDown[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_cjet_sysDown[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_cjet_sysDown[iVAR] = (TH1D*)h_draw_cjet_sysDown[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_ljet_sysDown[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_ljet_sysDown[iVAR] = (TH1D*)h_draw_ljet_sysDown[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_bjet_untag[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_bjet_untag[iVAR] = (TH1D*)h_draw_bjet_untag[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_cjet_untag[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_cjet_untag[iVAR] = (TH1D*)h_draw_cjet_untag[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_bjet_posttag[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_bjet_posttag[iVAR] = (TH1D*)h_draw_bjet_posttag[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_cjet_posttag[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_cjet_posttag[iVAR] = (TH1D*)h_draw_cjet_posttag[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_ljet_posttag[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_ljet_posttag[iVAR] = (TH1D*)h_draw_ljet_posttag[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_ajet_data_posttag[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_ajet_data_posttag[iVAR] = (TH1D*)h_draw_ajet_data_posttag[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_bjet_notag[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_bjet_notag[iVAR] = (TH1D*)h_draw_bjet_notag[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_cjet_notag[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_cjet_notag[iVAR] = (TH1D*)h_draw_cjet_notag[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_ljet_notag[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_ljet_notag[iVAR] = (TH1D*)h_draw_ljet_notag[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_ajet_data_notag[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_ajet_data_notag[iVAR] = (TH1D*)h_draw_ajet_data_notag[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_ljet_data[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_ljet_data[iVAR] = (TH1D*)h_draw_ljet_data[iVAR]->Rebin(arrs-1,"",xn);
	
	xn = mergeBins(h_draw_cljet[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_cljet[iVAR] = (TH1D*)h_draw_cljet[iVAR]->Rebin(arrs-1,"",xn);
   
	xn = mergeBins(h_draw_ajet_data[iVAR],ibinMin,ibinMax,xnew);
	if( doRebin ) h_draw_ajet_data[iVAR] = (TH1D*)h_draw_ajet_data[iVAR]->Rebin(arrs-1,"",xn);
	
	for(int j=0;j<nsysGL;j++)
	  {	     
	     xn = mergeBins(h_draw_bjet_sys_low[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_bjet_sys_low[j][iVAR] = (TH1D*)h_draw_bjet_sys_low[j][iVAR]->Rebin(arrs-1,"",xn);
	     xn = mergeBins(h_draw_bjet_sys_up[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_bjet_sys_up[j][iVAR] = (TH1D*)h_draw_bjet_sys_up[j][iVAR]->Rebin(arrs-1,"",xn);

	     xn = mergeBins(h_draw_cjet_sys_low[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_cjet_sys_low[j][iVAR] = (TH1D*)h_draw_cjet_sys_low[j][iVAR]->Rebin(arrs-1,"",xn);
	     xn = mergeBins(h_draw_cjet_sys_up[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_cjet_sys_up[j][iVAR] = (TH1D*)h_draw_cjet_sys_up[j][iVAR]->Rebin(arrs-1,"",xn);

	     xn = mergeBins(h_draw_ljet_sys_low[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_ljet_sys_low[j][iVAR] = (TH1D*)h_draw_ljet_sys_low[j][iVAR]->Rebin(arrs-1,"",xn);
	     xn = mergeBins(h_draw_ljet_sys_up[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_ljet_sys_up[j][iVAR] = (TH1D*)h_draw_ljet_sys_up[j][iVAR]->Rebin(arrs-1,"",xn);
	     
	     xn = mergeBins(h_draw_bjet_untag_sys_low[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_bjet_untag_sys_low[j][iVAR] = (TH1D*)h_draw_bjet_untag_sys_low[j][iVAR]->Rebin(arrs-1,"",xn);
	     xn = mergeBins(h_draw_bjet_untag_sys_up[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_bjet_untag_sys_up[j][iVAR] = (TH1D*)h_draw_bjet_untag_sys_up[j][iVAR]->Rebin(arrs-1,"",xn);
	     
	     xn = mergeBins(h_draw_cjet_untag_sys_low[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_cjet_untag_sys_low[j][iVAR] = (TH1D*)h_draw_cjet_untag_sys_low[j][iVAR]->Rebin(arrs-1,"",xn);
	     xn = mergeBins(h_draw_cjet_untag_sys_up[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_cjet_untag_sys_up[j][iVAR] = (TH1D*)h_draw_cjet_untag_sys_up[j][iVAR]->Rebin(arrs-1,"",xn);
	     
	     xn = mergeBins(h_draw_bjet_posttag_sys_low[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_bjet_posttag_sys_low[j][iVAR] = (TH1D*)h_draw_bjet_posttag_sys_low[j][iVAR]->Rebin(arrs-1,"",xn);
	     xn = mergeBins(h_draw_bjet_posttag_sys_up[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_bjet_posttag_sys_up[j][iVAR] = (TH1D*)h_draw_bjet_posttag_sys_up[j][iVAR]->Rebin(arrs-1,"",xn);
	     
	     xn = mergeBins(h_draw_cjet_posttag_sys_low[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_cjet_posttag_sys_low[j][iVAR] = (TH1D*)h_draw_cjet_posttag_sys_low[j][iVAR]->Rebin(arrs-1,"",xn);
	     xn = mergeBins(h_draw_cjet_posttag_sys_up[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_cjet_posttag_sys_up[j][iVAR] = (TH1D*)h_draw_cjet_posttag_sys_up[j][iVAR]->Rebin(arrs-1,"",xn);
	     
	     xn = mergeBins(h_draw_ljet_data_sys_low[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_ljet_data_sys_low[j][iVAR] = (TH1D*)h_draw_ljet_data_sys_low[j][iVAR]->Rebin(arrs-1,"",xn);
	     xn = mergeBins(h_draw_ljet_data_sys_up[j][iVAR],ibinMin,ibinMax,xnew);
	     if( doRebin ) h_draw_ljet_data_sys_up[j][iVAR] = (TH1D*)h_draw_ljet_data_sys_up[j][iVAR]->Rebin(arrs-1,"",xn);
	  }
     }   
   
/*   if( hnameVAR[iVAR] == "h_j_pt_" ||
       hnameVAR[iVAR] == "h_j1_pt_" ||
       hnameVAR[iVAR] == "h_j2_pt_" )
     {
	h_draw_bjet[iVAR] = (TH1D*)h_draw_bjet[iVAR]->Rebin(Nbins,"",xbins);
	h_draw_cjet[iVAR] = (TH1D*)h_draw_cjet[iVAR]->Rebin(Nbins,"",xbins);
	h_draw_ljet[iVAR] = (TH1D*)h_draw_ljet[iVAR]->Rebin(Nbins,"",xbins);
	h_draw_bjet_untag[iVAR] = (TH1D*)h_draw_bjet_untag[iVAR]->Rebin(Nbins,"",xbins);
	h_draw_cjet_untag[iVAR] = (TH1D*)h_draw_cjet_untag[iVAR]->Rebin(Nbins,"",xbins);
	//	     h_draw_bjet_notag[iVAR] = (TH1F*)h_draw_bjet_notag[iVAR]->Rebin(Nbins,"",xbins);
	//	     h_draw_cjet_notag[iVAR] = (TH1F*)h_draw_cjet_notag[iVAR]->Rebin(Nbins,"",xbins);
	h_draw_bjet_posttag[iVAR] = (TH1D*)h_draw_bjet_posttag[iVAR]->Rebin(Nbins,"",xbins);
	h_draw_cjet_posttag[iVAR] = (TH1D*)h_draw_cjet_posttag[iVAR]->Rebin(Nbins,"",xbins);
	h_draw_ljet_data[iVAR] = (TH1D*)h_draw_ljet_data[iVAR]->Rebin(Nbins,"",xbins);
	
	for(int j=0;j<nsysGL;j++)
	  {		  	     
	     h_draw_bjet_sys_low[j][iVAR] = (TH1D*)h_draw_bjet_sys_low[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_cjet_sys_low[j][iVAR] = (TH1D*)h_draw_cjet_sys_low[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_ljet_sys_low[j][iVAR] = (TH1D*)h_draw_ljet_sys_low[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_bjet_untag_sys_low[j][iVAR] = (TH1D*)h_draw_bjet_untag_sys_low[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_cjet_untag_sys_low[j][iVAR] = (TH1D*)h_draw_cjet_untag_sys_low[j][iVAR]->Rebin(Nbins,"",xbins);
	     //		  h_draw_bjet_notag_sys_low[j][iVAR] = (TH1F*)h_draw_bjet_notag_sys_low[j][iVAR]->Rebin(Nbins,"",xbins);
	     //		  h_draw_cjet_notag_sys_low[j][iVAR] = (TH1F*)h_draw_cjet_notag_sys_low[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_bjet_posttag_sys_low[j][iVAR] = (TH1D*)h_draw_bjet_posttag_sys_low[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_cjet_posttag_sys_low[j][iVAR] = (TH1D*)h_draw_cjet_posttag_sys_low[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_ljet_data_sys_low[j][iVAR] = (TH1D*)h_draw_ljet_data_sys_low[j][iVAR]->Rebin(Nbins,"",xbins);
	     
	     h_draw_bjet_sys_up[j][iVAR] = (TH1D*)h_draw_bjet_sys_up[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_cjet_sys_up[j][iVAR] = (TH1D*)h_draw_cjet_sys_up[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_ljet_sys_up[j][iVAR] = (TH1D*)h_draw_ljet_sys_up[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_bjet_untag_sys_up[j][iVAR] = (TH1D*)h_draw_bjet_untag_sys_up[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_cjet_untag_sys_up[j][iVAR] = (TH1D*)h_draw_cjet_untag_sys_up[j][iVAR]->Rebin(Nbins,"",xbins);
	     //		  h_draw_bjet_notag_sys_up[j][iVAR] = (TH1F*)h_draw_bjet_notag_sys_up[j][iVAR]->Rebin(Nbins,"",xbins);
	     //		  h_draw_cjet_notag_sys_up[j][iVAR] = (TH1F*)h_draw_cjet_notag_sys_up[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_bjet_posttag_sys_up[j][iVAR] = (TH1D*)h_draw_bjet_posttag_sys_up[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_cjet_posttag_sys_up[j][iVAR] = (TH1D*)h_draw_cjet_posttag_sys_up[j][iVAR]->Rebin(Nbins,"",xbins);
	     h_draw_ljet_data_sys_up[j][iVAR] = (TH1D*)h_draw_ljet_data_sys_up[j][iVAR]->Rebin(Nbins,"",xbins);
	  }	     
	
	h_draw_cljet[iVAR] = (TH1D*)h_draw_cljet[iVAR]->Rebin(Nbins,"",xbins);
	h_draw_ajet_data[iVAR] = (TH1D*)h_draw_ajet_data[iVAR]->Rebin(Nbins,"",xbins);
     }
   else
     {
	h_draw_bjet[iVAR] = (TH1D*)h_draw_bjet[iVAR]->Rebin(nbm1d[iPT],"");
	h_draw_cjet[iVAR] = (TH1D*)h_draw_cjet[iVAR]->Rebin(nbm1d[iPT],"");
	h_draw_ljet[iVAR] = (TH1D*)h_draw_ljet[iVAR]->Rebin(nbm1d[iPT],"");
	h_draw_bjet_untag[iVAR] = (TH1D*)h_draw_bjet_untag[iVAR]->Rebin(nbm1d[iPT],"");
	h_draw_cjet_untag[iVAR] = (TH1D*)h_draw_cjet_untag[iVAR]->Rebin(nbm1d[iPT],"");
	//	     h_draw_bjet_notag[iVAR] = (TH1F*)h_draw_bjet_notag[iVAR]->Rebin(nbm1d,"");
	//	     h_draw_cjet_notag[iVAR] = (TH1F*)h_draw_cjet_notag[iVAR]->Rebin(nbm1d,"");
	h_draw_bjet_posttag[iVAR] = (TH1D*)h_draw_bjet_posttag[iVAR]->Rebin(nbm1d[iPT],"");
	h_draw_cjet_posttag[iVAR] = (TH1D*)h_draw_cjet_posttag[iVAR]->Rebin(nbm1d[iPT],"");
	h_draw_ljet_data[iVAR] = (TH1D*)h_draw_ljet_data[iVAR]->Rebin(nbm1d[iPT],"");
	
	for(int j=0;j<nsysGL;j++)
	  {		  	     
	     h_draw_bjet_sys_low[j][iVAR] = (TH1D*)h_draw_bjet_sys_low[j][iVAR]->Rebin(nbm1d[iPT],"");
	     h_draw_cjet_sys_low[j][iVAR] = (TH1D*)h_draw_cjet_sys_low[j][iVAR]->Rebin(nbm1d[iPT],"");
	     h_draw_ljet_sys_low[j][iVAR] = (TH1D*)h_draw_ljet_sys_low[j][iVAR]->Rebin(nbm1d[iPT],"");
	     h_draw_bjet_untag_sys_low[j][iVAR] = (TH1D*)h_draw_bjet_untag_sys_low[j][iVAR]->Rebin(nbm1d[iPT],"");
	     h_draw_cjet_untag_sys_low[j][iVAR] = (TH1D*)h_draw_cjet_untag_sys_low[j][iVAR]->Rebin(nbm1d[iPT],"");
	     //		  h_draw_bjet_notag_sys_low[j][iVAR] = (TH1F*)h_draw_bjet_notag_sys_low[j][iVAR]->Rebin(nbm1d,"");
	     //		  h_draw_cjet_notag_sys_low[j][iVAR] = (TH1F*)h_draw_cjet_notag_sys_low[j][iVAR]->Rebin(nbm1d,"");
	     h_draw_bjet_posttag_sys_low[j][iVAR] = (TH1D*)h_draw_bjet_posttag_sys_low[j][iVAR]->Rebin(nbm1d[iPT],"");
	     h_draw_cjet_posttag_sys_low[j][iVAR] = (TH1D*)h_draw_cjet_posttag_sys_low[j][iVAR]->Rebin(nbm1d[iPT],"");
	     h_draw_ljet_data_sys_low[j][iVAR] = (TH1D*)h_draw_ljet_data_sys_low[j][iVAR]->Rebin(nbm1d[iPT],"");
	     
	     h_draw_bjet_sys_up[j][iVAR] = (TH1D*)h_draw_bjet_sys_up[j][iVAR]->Rebin(nbm1d[iPT],"");
	     h_draw_cjet_sys_up[j][iVAR] = (TH1D*)h_draw_cjet_sys_up[j][iVAR]->Rebin(nbm1d[iPT],"");
	     h_draw_ljet_sys_up[j][iVAR] = (TH1D*)h_draw_ljet_sys_up[j][iVAR]->Rebin(nbm1d[iPT],"");
	     h_draw_bjet_untag_sys_up[j][iVAR] = (TH1D*)h_draw_bjet_untag_sys_up[j][iVAR]->Rebin(nbm1d[iPT],"");
	     h_draw_cjet_untag_sys_up[j][iVAR] = (TH1D*)h_draw_cjet_untag_sys_up[j][iVAR]->Rebin(nbm1d[iPT],"");
	     //		  h_draw_bjet_notag_sys_up[j][iVAR] = (TH1F*)h_draw_bjet_notag_sys_up[j][iVAR]->Rebin(nbm1d,"");
	     //		  h_draw_cjet_notag_sys_up[j][iVAR] = (TH1F*)h_draw_cjet_notag_sys_up[j][iVAR]->Rebin(nbm1d,"");
	     h_draw_bjet_posttag_sys_up[j][iVAR] = (TH1D*)h_draw_bjet_posttag_sys_up[j][iVAR]->Rebin(nbm1d[iPT],"");
	     h_draw_cjet_posttag_sys_up[j][iVAR] = (TH1D*)h_draw_cjet_posttag_sys_up[j][iVAR]->Rebin(nbm1d[iPT],"");
	     h_draw_ljet_data_sys_up[j][iVAR] = (TH1D*)h_draw_ljet_data_sys_up[j][iVAR]->Rebin(nbm1d[iPT],"");
	  }	     
	
	h_draw_cljet[iVAR] = (TH1D*)h_draw_cljet[iVAR]->Rebin(nbm1d[iPT],"");
	h_draw_ajet_data[iVAR] = (TH1D*)h_draw_ajet_data[iVAR]->Rebin(nbm1d[iPT],"");
     }
*/
   double bfr = h_draw_bjet_init[iVAR]->Integral();
   double cfr = h_draw_cjet_init[iVAR]->Integral();
   double lfr = h_draw_ljet_init[iVAR]->Integral();
   double afr = bfr+cfr+lfr;

   double bfr_true = h_draw_bjet_true[iVAR]->Integral();
   double cfr_true = h_draw_cjet_true[iVAR]->Integral();
   double lfr_true = h_draw_ljet_true[iVAR]->Integral();
   double afr_true = bfr_true+cfr_true+lfr_true;
   
   if( afr > 0 )
     {	
	fracB_MCDEFAULT = bfr/afr;
	fracC_MCDEFAULT = cfr/afr;
	fracL_MCDEFAULT = lfr/afr;

	fracB_MCDEFAULT_TRUE = bfr_true/afr_true;
	fracC_MCDEFAULT_TRUE = cfr_true/afr_true;
	fracL_MCDEFAULT_TRUE = lfr_true/afr_true;
     }
   else
     {
	std::cout << "Empty histograms" << std::endl;
	exit(1);
     }   
   
/*   if( doSub )
     {	     
	// subtract MC b+c from ljet_data
	     
	h_draw_ljet_data[iVAR]->Add(h_draw_bjet_untag[iVAR],-1.);
	if( doSubC )
	  h_draw_ljet_data[iVAR]->Add(h_draw_cjet_untag[iVAR],-1.);

	removeMCNeg(h_draw_ljet_data[iVAR]);

	float kSub = 0.3; // %
	
	for(int j=0;j<nsysGL;j++)
	  {
	     TH1D *h_draw_cjet_untag_sub_low;
	     TH1D *h_draw_cjet_untag_sub_up;
	     
	     TH1D *h_draw_bjet_untag_sub_low = (TH1D*)h_draw_bjet_untag[iVAR]->Clone("h_draw_bjet_untag_sub_low");
	     if( doSubC )
	       h_draw_cjet_untag_sub_low = (TH1D*)h_draw_cjet_untag[iVAR]->Clone("h_draw_cjet_untag_sub_low");
	     
	     TH1D *h_draw_bjet_untag_sub_up = (TH1D*)h_draw_bjet_untag[iVAR]->Clone("h_draw_bjet_untag_sub_up");
	     if( doSubC )
	       h_draw_cjet_untag_sub_up = (TH1D*)h_draw_cjet_untag[iVAR]->Clone("h_draw_cjet_untag_sub_up");
	     
	     float kSub = 0.3; // %
	     if( j > 0 ) kSub = 0.;
	     
	     h_draw_bjet_untag_sub_low->Scale(1+kSub);
	     if( doSubC )
	       h_draw_cjet_untag_sub_low->Scale(1+kSub);
		  
	     h_draw_bjet_untag_sub_up->Scale(1-kSub);
	     if( doSubC )
	       h_draw_cjet_untag_sub_up->Scale(1-kSub);
	     
	     h_draw_ljet_data_sys_low[j][iVAR]->Add(h_draw_bjet_untag_sub_low,-1.);
	     if( doSubC )
	       h_draw_ljet_data_sys_low[j][iVAR]->Add(h_draw_cjet_untag_sub_low,-1.);
	     
	     removeMCNeg(h_draw_ljet_data_sys_low[j][iVAR]);
	     
	     h_draw_ljet_data_sys_up[j][iVAR]->Add(h_draw_bjet_untag_sub_up,-1.);
	     if( doSubC )
	       h_draw_ljet_data_sys_up[j][iVAR]->Add(h_draw_cjet_untag_sub_up,-1.);
	     
	     removeMCNeg(h_draw_ljet_data_sys_up[j][iVAR]);
	     
	     delete h_draw_bjet_untag_sub_low;
	     if( doSubC )
	       delete h_draw_cjet_untag_sub_low;
	     
	     delete h_draw_bjet_untag_sub_up;
	     if( doSubC )
	       delete h_draw_cjet_untag_sub_up;
	  }
*/	
/*	for(int j=0;j<nsys;j++)	      	       
	  {		  
	     h_draw_ljet_data_sys_low[j][iVAR]->Add(h_draw_bjet_untag_sys_low[j][iVAR],-1.);
	     h_draw_ljet_data_sys_low[j][iVAR]->Add(h_draw_cjet_untag_sys_low[j][iVAR],-1.);
	     
	     removeMCNeg(h_draw_ljet_data_sys_low[j][iVAR]);
	     
	     h_draw_ljet_data_sys_up[j][iVAR]->Add(h_draw_bjet_untag_sys_up[j][iVAR],-1.);
	     h_draw_ljet_data_sys_up[j][iVAR]->Add(h_draw_cjet_untag_sys_up[j][iVAR],-1.);
	     
	     removeMCNeg(h_draw_ljet_data_sys_up[j][iVAR]);
	  }*/
//     }
   
   // prepare comb templates
	
   std::string h_bjet_comb_sys_up = hname_bjet + "_sys_up_comb";
   std::string h_bjet_comb_sys_low = hname_bjet + "_sys_low_comb";
   h_draw_bjet_sys_low_comb[iVAR] = (TH1D*)h_draw_bjet[iVAR]->Clone(h_bjet_comb_sys_low.c_str());
   h_draw_bjet_sys_up_comb[iVAR] = (TH1D*)h_draw_bjet[iVAR]->Clone(h_bjet_comb_sys_up.c_str());
   
   std::string h_cjet_comb_sys_up = hname_cjet + "_sys_up_comb";
   std::string h_cjet_comb_sys_low = hname_cjet + "_sys_low_comb";
   h_draw_cjet_sys_low_comb[iVAR] = (TH1D*)h_draw_cjet[iVAR]->Clone(h_cjet_comb_sys_low.c_str());
   h_draw_cjet_sys_up_comb[iVAR] = (TH1D*)h_draw_cjet[iVAR]->Clone(h_cjet_comb_sys_up.c_str());
   
   std::string h_ljet_comb_sys_up = hname_ljet + "_sys_up_comb";
   std::string h_ljet_comb_sys_low = hname_ljet + "_sys_low_comb";
   h_draw_ljet_sys_low_comb[iVAR] = (TH1D*)h_draw_ljet[iVAR]->Clone(h_ljet_comb_sys_low.c_str());
   h_draw_ljet_sys_up_comb[iVAR] = (TH1D*)h_draw_ljet[iVAR]->Clone(h_ljet_comb_sys_up.c_str());
   
   std::string h_ljet_data_comb_sys_up = hname_ljet_data + "_sys_up_comb";
   std::string h_ljet_data_comb_sys_low = hname_ljet_data + "_sys_low_comb";
   h_draw_ljet_data_sys_low_comb[iVAR] = (TH1D*)h_draw_ljet_data[iVAR]->Clone(h_ljet_data_comb_sys_low.c_str());
   h_draw_ljet_data_sys_up_comb[iVAR] = (TH1D*)h_draw_ljet_data[iVAR]->Clone(h_ljet_data_comb_sys_up.c_str());
   
   std::string h_bcljet_comb = hname_bjet + hname_cjet + hname_ljet + "_comb";
   h_draw_bcljet_comb[iVAR] = (TH1D*)h_draw_bjet[iVAR]->Clone(h_bcljet_comb.c_str());
   
   for(int isy=0;isy<nsysGL;isy++)
     {	     
	std::string h_bcljet_comb_sys_up = hname_bjet + hname_cjet + hname_ljet + "_sys_up_comb" + name_sys_up[isy];
	std::string h_bcljet_comb_sys_low = hname_bjet + hname_cjet + hname_ljet + "_sys_low_comb" + name_sys_low[isy];
	h_draw_bcljet_sys_low_comb[iVAR*nsysGL+isy] = (TH1D*)h_draw_bjet[iVAR]->Clone(h_bcljet_comb_sys_low.c_str());
	h_draw_bcljet_sys_up_comb[iVAR*nsysGL+isy] = (TH1D*)h_draw_bjet[iVAR]->Clone(h_bcljet_comb_sys_up.c_str());
     }	
   
   std::string h_bcljet_combSum_sys_up = hname_bjet + hname_cjet + hname_ljet + "_sys_up_comb_sum";
   std::string h_bcljet_combSum_sys_low = hname_bjet + hname_cjet + hname_ljet + "_sys_low_comb_sum";
   h_draw_bcljet_sys_low_combSum[iVAR] = (TH1D*)h_draw_bjet[iVAR]->Clone(h_bcljet_combSum_sys_low.c_str());
   h_draw_bcljet_sys_up_combSum[iVAR] = (TH1D*)h_draw_bjet[iVAR]->Clone(h_bcljet_combSum_sys_up.c_str());

   std::string h_bjet_combSum_sys_up = hname_bjet + "_sys_up_comb_sum";
   std::string h_bjet_combSum_sys_low = hname_bjet + "_sys_low_comb_sum";
   h_draw_bjet_sys_low_combSum[iVAR] = (TH1D*)h_draw_bjet[iVAR]->Clone(h_bjet_combSum_sys_low.c_str());
   h_draw_bjet_sys_up_combSum[iVAR] = (TH1D*)h_draw_bjet[iVAR]->Clone(h_bjet_combSum_sys_up.c_str());

   std::string h_cjet_combSum_sys_up = hname_cjet + "_sys_up_comb_sum";
   std::string h_cjet_combSum_sys_low = hname_cjet + "_sys_low_comb_sum";
   h_draw_cjet_sys_low_combSum[iVAR] = (TH1D*)h_draw_cjet[iVAR]->Clone(h_cjet_combSum_sys_low.c_str());
   h_draw_cjet_sys_up_combSum[iVAR] = (TH1D*)h_draw_cjet[iVAR]->Clone(h_cjet_combSum_sys_up.c_str());

   std::string h_ljet_combSum_sys_up = hname_ljet + "_sys_up_comb_sum";
   std::string h_ljet_combSum_sys_low = hname_ljet + "_sys_low_comb_sum";
   h_draw_ljet_sys_low_combSum[iVAR] = (TH1D*)h_draw_ljet[iVAR]->Clone(h_ljet_combSum_sys_low.c_str());
   h_draw_ljet_sys_up_combSum[iVAR] = (TH1D*)h_draw_ljet[iVAR]->Clone(h_ljet_combSum_sys_up.c_str());

   std::string h_ljet_data_combSum_sys_up = hname_ljet_data + "_sys_up_comb_sum";
   std::string h_ljet_data_combSum_sys_low = hname_ljet_data + "_sys_low_comb_sum";
   h_draw_ljet_data_sys_low_combSum[iVAR] = (TH1D*)h_draw_ljet_data[iVAR]->Clone(h_ljet_data_combSum_sys_low.c_str());
   h_draw_ljet_data_sys_up_combSum[iVAR] = (TH1D*)h_draw_ljet_data[iVAR]->Clone(h_ljet_data_combSum_sys_up.c_str());
   
/*   for(int i=0;i<v_mc_filt.size();i++)
     {
	fbatch_mc_filt[i][iVAR]->Close();
	fbatch_mc_unfilt[i][iVAR]->Close();
	delete fbatch_mc_filt[i][iVAR];
	delete fbatch_mc_unfilt[i][iVAR];
     }   
   for(int i=0;i<v_data.size();i++)
     {
	fbatch_data[i][iVAR]->Close();
	delete fbatch_data[i][iVAR];
     }*/
}

void closeData(int iVAR,
	       int iPT,
	       std::vector<std::string> *v_mc_filt,
	       std::vector<std::string> *v_mc_unfilt,
	       std::vector<std::string> v_data)
{
   for(int i=0;i<v_mc_filt->size();i++)
     {
//	fbatch_mc_filt[i][iVAR]->Close();
//	fbatch_mc_unfilt[i][iVAR]->Close();
//	delete fbatch_mc_filt[i][iVAR];
//	delete fbatch_mc_unfilt[i][iVAR];

	fbatch_mc_filt[i]->Close();
	fbatch_mc_unfilt[i]->Close();
	delete fbatch_mc_filt[i];
	delete fbatch_mc_unfilt[i];
     }   
   for(int i=0;i<v_data.size();i++)
     {
//	fbatch_data[i][iVAR]->Close();
//	delete fbatch_data[i][iVAR];

	fbatch_data[i]->Close();
	delete fbatch_data[i];
     }   
}

void applySys(int iVAR,
	      std::string hname_bjet,
	      std::string hname_cjet,
	      std::string hname_ljet,
	      std::string hname_ajet,
	      std::string hname_ljet_data,
	      double sf1,
	      double sf2,
	      double sf3,
	      double sf1err,
	      double sf2err,
	      double sf3err,
	      bool write,
	      bool dofac
	      )
{
   std::string c_bjet_fit = hname_bjet + "_fit";
   TH1D *h_bjet_fit = (TH1D*)h_draw_bjet[iVAR]->Clone(c_bjet_fit.c_str());
   std::string c_cjet_fit = hname_cjet + "_fit";
   TH1D *h_cjet_fit = (TH1D*)h_draw_cjet[iVAR]->Clone(c_cjet_fit.c_str());
   std::string c_ljet_fit = hname_ljet + "_fit";
   TH1D *h_ljet_fit = (TH1D*)h_draw_ljet[iVAR]->Clone(c_ljet_fit.c_str());   
   std::string c_ljet_data_fit = hname_ljet_data + "_fit";
   TH1D *h_ljet_data_fit = (TH1D*)h_draw_ljet_data[iVAR]->Clone(c_ljet_data_fit.c_str());
   
   h_bjet_fit->Scale(sf1);
   h_cjet_fit->Scale(sf2);
   h_ljet_fit->Scale(sf3);
   h_ljet_data_fit->Scale(sf3);
   
   TH1D *h_bjet_sys_low_fit[nsysGL];
   TH1D *h_bjet_sys_up_fit[nsysGL];
   TH1D *h_cjet_sys_low_fit[nsysGL];
   TH1D *h_cjet_sys_up_fit[nsysGL];
   TH1D *h_ljet_sys_low_fit[nsysGL];
   TH1D *h_ljet_sys_up_fit[nsysGL];
   TH1D *h_ljet_data_sys_low_fit[nsysGL];
   TH1D *h_ljet_data_sys_up_fit[nsysGL];

   std::string c_bjet_sys_up_fit = hname_bjet + "_sys_up_fit";
   std::string c_bjet_sys_low_fit = hname_bjet + "_sys_low_fit";

   std::string c_cjet_sys_up_fit = hname_cjet + "_sys_up_fit";
   std::string c_cjet_sys_low_fit = hname_cjet + "_sys_low_fit";

   std::string c_ljet_sys_up_fit = hname_ljet + "_sys_up_fit";
   std::string c_ljet_sys_low_fit = hname_ljet + "_sys_low_fit";

   std::string c_ljet_data_sys_up_fit = hname_ljet_data + "_sys_up_fit";
   std::string c_ljet_data_sys_low_fit = hname_ljet_data + "_sys_low_fit";
   
   for(int j=0;j<nsysGL;j++)
     {
	h_bjet_sys_low_fit[j] = (TH1D*)h_draw_bjet_sys_low[j][iVAR]->Clone((c_bjet_sys_low_fit+name_sys_low[j]).c_str());
	h_cjet_sys_low_fit[j] = (TH1D*)h_draw_cjet_sys_low[j][iVAR]->Clone((c_cjet_sys_low_fit+name_sys_low[j]).c_str());
	h_ljet_sys_low_fit[j] = (TH1D*)h_draw_ljet_sys_low[j][iVAR]->Clone((c_ljet_sys_low_fit+name_sys_low[j]).c_str());
	h_ljet_data_sys_low_fit[j] = (TH1D*)h_draw_ljet_data_sys_low[j][iVAR]->Clone((c_ljet_data_sys_low_fit+name_sys_low[j]).c_str());

	h_bjet_sys_up_fit[j] = (TH1D*)h_draw_bjet_sys_up[j][iVAR]->Clone((c_bjet_sys_up_fit+name_sys_up[j]).c_str());
	h_cjet_sys_up_fit[j] = (TH1D*)h_draw_cjet_sys_up[j][iVAR]->Clone((c_cjet_sys_up_fit+name_sys_up[j]).c_str());
	h_ljet_sys_up_fit[j] = (TH1D*)h_draw_ljet_sys_up[j][iVAR]->Clone((c_ljet_sys_up_fit+name_sys_up[j]).c_str());
	h_ljet_data_sys_up_fit[j] = (TH1D*)h_draw_ljet_data_sys_up[j][iVAR]->Clone((c_ljet_data_sys_up_fit+name_sys_up[j]).c_str());	
	
	if( ljetData == 0 )
	  {	     
	     h_bjet_sys_low_fit[j]->Scale(sf1);
	     h_cjet_sys_low_fit[j]->Scale(sf2);
	     h_ljet_sys_low_fit[j]->Scale(sf3);

	     h_bjet_sys_up_fit[j]->Scale(sf1);
	     h_cjet_sys_up_fit[j]->Scale(sf2);
	     h_ljet_sys_up_fit[j]->Scale(sf3);
	     
/*	     if( iVAR == 1 && iPTcur > 0 )
	       {	     
		  for(int b=0;b<=h_draw_bjet[iVAR]->GetXaxis()->GetNbins()+1;b++)
		    {
		       double vnom = h_draw_bjet[iVAR]->GetBinContent(b);
		       double vlow = h_bjet_sys_low_fit[j]->GetBinContent(b);
		       if( vnom < vlow ) 
			 {
			    std::cout << "Nominal histogram is less than low sys" << std::endl;
			    std::cout << h_draw_bjet[iVAR]->GetName() << std::endl;
			    std::cout << h_draw_bjet_sys_low[j][iVAR]->GetName() << std::endl;
			    std::cout << "b=" << b << " nom=" << vnom << " low=" << vlow << std::endl;
			    std::cout << sf1 << " " << sf2 << " " << sf3 << std::endl;
			    exit(1);
			 }		       
		    }
	       }*/
	  }
	else
	  { 
	     h_bjet_sys_low_fit[j]->Scale(sf1);
	     h_cjet_sys_low_fit[j]->Scale(sf2);
	     h_ljet_data_sys_low_fit[j]->Scale(sf3);

	     h_bjet_sys_up_fit[j]->Scale(sf1);
	     h_cjet_sys_up_fit[j]->Scale(sf2);
	     h_ljet_data_sys_up_fit[j]->Scale(sf3);
	  }
     }   
   
   for(int j=0;j<nsysGL;j++)
     {
	if( ljetData == 0 )
	  {
	     combSysLinear(h_bjet_fit,h_cjet_fit,h_ljet_fit,
			   h_bjet_sys_low_fit[j],h_bjet_sys_up_fit[j],
			   h_cjet_sys_low_fit[j],h_cjet_sys_up_fit[j],
			   h_ljet_sys_low_fit[j],h_ljet_sys_up_fit[j],
			   h_draw_bcljet_comb[iVAR],
			   h_draw_bcljet_sys_low_comb[iVAR*nsysGL+j],
			   h_draw_bcljet_sys_up_comb[iVAR*nsysGL+j]);
	  }
	else
	  {
	     combSysLinear(h_bjet_fit,h_cjet_fit,h_ljet_data_fit,
			   h_bjet_sys_low_fit[j],h_bjet_sys_up_fit[j],
			   h_cjet_sys_low_fit[j],h_cjet_sys_up_fit[j],
			   h_ljet_data_sys_low_fit[j],h_ljet_data_sys_up_fit[j],
			   h_draw_bcljet_comb[iVAR],
			   h_draw_bcljet_sys_low_comb[iVAR*nsysGL+j],
			   h_draw_bcljet_sys_up_comb[iVAR*nsysGL+j]);
	  }
	
	std::string nat_low = "h_draw_bcljet_sys_low_combNATURAL_"+name_sys_low[j];
	h_draw_bcljet_sys_low_combNATURAL[iVAR*nsysGL+j] = (TH1D*)h_draw_bcljet_sys_low_comb[iVAR*nsysGL+j]->Clone(nat_low.c_str());
	std::string nat_up = "h_draw_bcljet_sys_up_combNATURAL_"+name_sys_up[j];
	h_draw_bcljet_sys_up_combNATURAL[iVAR*nsysGL+j] = (TH1D*)h_draw_bcljet_sys_up_comb[iVAR*nsysGL+j]->Clone(nat_up.c_str());
	
	h_draw_bcljet_combNATURAL[iVAR] = (TH1D*)h_draw_bcljet_comb[iVAR]->Clone("h_draw_bcljet_combNATURAL");
	
	totSys(h_draw_bcljet_comb[iVAR],
	       h_draw_bcljet_sys_low_comb[iVAR*nsysGL+j],
	       h_draw_bcljet_sys_up_comb[iVAR*nsysGL+j]
	       );

	removeMCSys(h_draw_bcljet_comb[iVAR],
		    h_draw_bcljet_sys_up_comb[iVAR*nsysGL+j],
		    h_draw_bcljet_sys_low_comb[iVAR*nsysGL+j]);	
    }
   
   combSys(h_draw_bcljet_comb[iVAR],
	   h_draw_bcljet_sys_low_comb,
	   h_draw_bcljet_sys_up_comb,
	   h_draw_bcljet_sys_low_combSum[iVAR],
	   h_draw_bcljet_sys_up_combSum[iVAR],iVAR);
   
   totSys(h_draw_bcljet_comb[iVAR],
	  h_draw_bcljet_sys_low_combSum[iVAR],
	  h_draw_bcljet_sys_up_combSum[iVAR]);

   removeMCSys(h_draw_bcljet_comb[iVAR],
	       h_draw_bcljet_sys_up_combSum[iVAR],
	       h_draw_bcljet_sys_low_combSum[iVAR]);
   
   int nbinsl = h_draw_bcljet_comb[iVAR]->GetXaxis()->GetNbins();

   vecM.clear();
   
   int nel = h_draw_bcljet_comb[iVAR]->GetXaxis()->GetNbins();
   // get bins with nonzero contents
//   for(int i=ibinMin;i<=ibinMax;i++)
   for(int i=1;i<=nel;i++)
     {
	double cont = h_draw_bcljet_comb[iVAR]->GetBinContent(i);
	double contUp = h_draw_bcljet_sys_up_combSum[iVAR]->GetBinContent(i);
	double contDown = h_draw_bcljet_sys_low_combSum[iVAR]->GetBinContent(i);
	
//	if( cont > 0. && (contUp > 0. || contDown > 0.) )
//	  {
	     vecM.push_back(i);
//	  }	
     } 

   if( sysIdx == 0 )
     {	
	const int vecM_n = vecM.size();
	
	double norm[vecM_MAX][vecM_MAX];
	
	for(int i1=0;i1<vecM_MAX;i1++)
	  {
	     for(int i2=0;i2<vecM_MAX;i2++)
	       {
		  norm[i1][i2] = 0.;
	       }	
	  }   

	for(int i1=0;i1<vecM_MAX;i1++)
	  {
	     for(int i2=0;i2<vecM_MAX;i2++)
	       {
		  cov[i1][i2] = 0.;
	       }
	  }

	double bvMax = 10E-10;
	for(int i1=0;i1<vecM_n;i1++)
	  {
	     int idx1 = vecM[i1];
	     
	     double v_nom_i1 = h_draw_bcljet_combNATURAL[iVAR]->GetBinContent(idx1);
	     if( v_nom_i1 > bvMax ) bvMax = v_nom_i1;
	  }

	TH1D *h_SYM = (TH1D*)h_draw_bcljet_combNATURAL[iVAR]->Clone("h_SYM");
	TH1D *h_SYM_UP[nsysGL];
	TH1D *h_SYM_LOW[nsysGL];
	for(int is=0;is<nsysGL;is++)
	  {
	     std::string h_sym_up_name = "h_SYM_UP_"+std::string(Form("%d",is));
	     std::string h_sym_low_name = "h_SYM_LOW_"+std::string(Form("%d",is));
	     h_SYM_UP[is] = (TH1D*)h_draw_bcljet_sys_up_combNATURAL[iVAR*nsysGL+is]->Clone(h_sym_up_name.c_str());
	     h_SYM_LOW[is] = (TH1D*)h_draw_bcljet_sys_low_combNATURAL[iVAR*nsysGL+is]->Clone(h_sym_low_name.c_str());

	     std::string psysname = hname_bjet+name_sys_low[is]+"_sum";
	     
	     plotFracSys(h_SYM,
			 h_SYM_LOW[is],
			 h_SYM_UP[is],
			 psysname,
			 name_sys_low[is],
			 is,
			 "sum",1);
	     
	     psysname = hname_bjet+name_sys_low[is];
	     
	     adjustSys(h_SYM,h_SYM_LOW[is],h_SYM_UP[is],binFactor[is],dofac);

	     plotFracSysNew(h_SYM,
			    h_SYM_LOW[is],
			    h_SYM_UP[is],
			    psysname,
			    name_sys_low[is],
			    is,
			    dofac);
	  }	
	
	// compute covariance matrix
	for(int i1=0;i1<vecM_n;i1++)
	  {
	     int idx1 = vecM[i1];
	     
	     double siglin = 0.;
	     
	     for(int i2=0;i2<vecM_n;i2++)
	       {
		  int idx2 = vecM[i2];
		  
		  double cov_v = 0.;
		  double norm_i1_v = 0.;
		  double norm_i2_v = 0.;
		  
		  for(int is=0;is<nsysGL;is++)
		    {
		       double v_nom_i1 = h_SYM->GetBinContent(idx1);
		       double v_sysUp_i1 = h_SYM_UP[is]->GetBinContent(idx1);
		       double v_sysDown_i1 = h_SYM_LOW[is]->GetBinContent(idx1);

		       double v_nom_i2 = h_SYM->GetBinContent(idx2);
		       double v_sysUp_i2 = h_SYM_UP[is]->GetBinContent(idx2);
		       double v_sysDown_i2 = h_SYM_LOW[is]->GetBinContent(idx2);
		       
//		       double v_nom_i1 = h_draw_bcljet_combNATURAL[iVAR]->GetBinContent(idx1);
//		       double v_sysUp_i1 = h_draw_bcljet_sys_up_combNATURAL[iVAR*nsysGL+is]->GetBinContent(idx1);
//		       double v_sysDown_i1 = h_draw_bcljet_sys_low_combNATURAL[iVAR*nsysGL+is]->GetBinContent(idx1);
		       
//		       double v_nom_i2 = h_draw_bcljet_combNATURAL[iVAR]->GetBinContent(idx2);
//		       double v_sysUp_i2 = h_draw_bcljet_sys_up_combNATURAL[iVAR*nsysGL+is]->GetBinContent(idx2);
//		       double v_sysDown_i2 = h_draw_bcljet_sys_low_combNATURAL[iVAR*nsysGL+is]->GetBinContent(idx2);
		       
		       double sysUp_i1 = v_sysUp_i1 - v_nom_i1;
		       double sysDown_i1 = v_nom_i1 - v_sysDown_i1;
		       
		       double sysUp_i2 = v_sysUp_i2 - v_nom_i2;
		       double sysDown_i2 = v_nom_i2 - v_sysDown_i2;

		       if( asymm == 0 )
			 {			    
			    if( sysUp_i1*sysDown_i1 < 0 )
			      {
				 if( fabs(sysUp_i1) > fabs(sysDown_i1) )
				   sysDown_i1 = 0.;
				 else
				   sysUp_i1 = 0.;
			      }		  
			    if( sysUp_i2*sysDown_i2 < 0 )
			      {
				 if( fabs(sysUp_i2) > fabs(sysDown_i2) )
				   sysDown_i2 = 0.;
				 else
				   sysUp_i2 = 0.;
			      }		  
			 }		       

		       ///		  if( sysDown_i1 < 0 ) std::cout << "sysDown_i1=" << sysDown_i1 << std::endl;
		       ///		  if( sysDown_i2 < 0 ) std::cout << "sysDown_i2=" << sysDown_i2 << std::endl;
		       
		       // new
		       //		  if( sysDown_i1 < 0 ) sysDown_i1 = v_nom_i1;
		       //		  if( sysDown_i2 < 0 ) sysDown_i2 = v_nom_i2;
		       //		  if( sysUp_i1 > v_nom_i1 ) sysUp_i1 = v_nom_i1;
		       //		  if( sysUp_i2 > v_nom_i2 ) sysUp_i2 = v_nom_i2;
		       
		       if( i2 == 0 )
			 siglin += sysUp_i1 - sysDown_i1;
		       
//		       double stat_i1 = h_draw_bcljet_combNATURAL[iVAR]->GetBinError(idx1);
		       double stat_i1 = h_SYM->GetBinError(idx1);
		       
//		       double stat_i2 = h_draw_bcljet_combNATURAL[iVAR]->GetBinError(idx2);
		       double stat_i2 = h_SYM->GetBinError(idx2);
		       
		       double data_stat = h_draw_ajet_data[iVAR]->GetBinError(idx1);
		       if( i1 != i2 || is != 0 ) data_stat = 0.;
		       
		       //		  std::cout << "sys=" << is << " " << v_nom_i1 << " +" << v_sysUp_i1 << 
		       //		    " -" << v_sysDown_i1 << std::endl;
		       
		       //		  if( comflag)
		       //		    if( idx1 == 6 ) std::cout << "sigma = " << sysUp_i1 << " " << sysDown_i1 << std::endl;

//		       double sign_i1 = (sysUp_i1 > 0) ? 1. : -1.;
//		       double sign_i2 = (sysUp_i2 > 0) ? 1. : -1.;
		       
		       double sigma_i1 = sysUp_i1;
		       double sigma_i2 = sysUp_i2;
		       
//		       double sigma_i1 = (fabs(sysUp_i1) > fabs(sysDown_i1)) ? sysUp_i1 : sysDown_i1;
//		       double sigma_i2 = (fabs(sysUp_i2) > fabs(sysDown_i2)) ? sysUp_i2 : sysDown_i2;

//		       double sigma_i1 = (fabs(sysUp_i1) > fabs(sysDown_i1)) ? sign_i1*fabs(sysUp_i1) : sign_i1*fabs(sysDown_i1);
//		       double sigma_i2 = (fabs(sysUp_i2) > fabs(sysDown_i2)) ? sign_i2*fabs(sysUp_i2) : sign_i2*fabs(sysDown_i2);
		       
		       if( asymm == 0 )
			 {
			    sigma_i1 = sysUp_i1+sysDown_i1;
			    sigma_i2 = sysUp_i2+sysDown_i2;
			 }		       
		       
		       double alpha_i1 = sysUp_i1-sysDown_i1;
		       double alpha_i2 = sysUp_i2-sysDown_i2;
		       double val_i1 = h_draw_bcljet_comb[iVAR]->GetBinContent(idx1);
		       double val_i2 = h_draw_bcljet_comb[iVAR]->GetBinContent(idx2);
		       
		       sysUp_i1 = h_draw_bcljet_sys_up_combSum[iVAR]->GetBinContent(idx1) - 
			 val_i1;
		       sysDown_i1 = -h_draw_bcljet_sys_low_combSum[iVAR]->GetBinContent(idx1) +
			 val_i1;
		       
		       sysUp_i2 = h_draw_bcljet_sys_up_combSum[iVAR]->GetBinContent(idx2) - 
			 val_i2;
		       sysDown_i2 = -h_draw_bcljet_sys_low_combSum[iVAR]->GetBinContent(idx2) +
			 val_i2;
		       
		       double sigmaAv_i1 = (sysUp_i1+sysDown_i1)/2.;
		       double sigmaAv_i2 = (sysUp_i2+sysDown_i2)/2.;

		       double covAS = covFactor[is];
		       covAS *= binFactor[is][idx1]*binFactor[is][idx2];
//		       covAS *= 0.;
//		       covAS *= val_i1*val_i2/bvMax/bvMax;
//		       covAS *= val_i1*val_i2/bvMax/bvMax*(2-val_i1*val_i2/bvMax/bvMax);
//		       covAS *= (val_i1+val_i2)/2./bvMax;
//		       covAS *= sqrt(val_i1*val_i2/bvMax/bvMax);
//		       covAS *= sqrt(val_i1*val_i2/bvMax/bvMax)*(2-sqrt(val_i1*val_i2/bvMax/bvMax));
//		       covAS *= sqrt(val_i1*val_i2/bvMax/bvMax)/2.;
//		       covAS *= (sqrt(val_i1*val_i2/bvMax/bvMax)+1)/2.;
		       
//		       covAS /= 2.;
		       // covAS *= 2.;
		       if( covAS > 1. ) covAS = 1.;
		       
//		       covAS *= 1-fabs(i1-i2)/vecM_n;
//		       if( fabs(covAS) > 0.5 ) covAS = 0.5;
//		       if( val_i1/bvMax < 0.1 || val_i2/bvMax < 0.1 ) covAS *= 0.;
//		       covAS *= 1-fabs(val_i1-val_i2)/(val_i1+val_i2);
//		       covAS = 0.;
		       
		       if( i1 == i2 ) covAS = 1.;
		       
		       if( asymm == 0 )
			 {		       
			    cov_v += covAS*sigma_i1/2.*sigma_i2/2.+
			      covAS*alpha_i1/2.*alpha_i2/2.*(1.-2./PI)+
			      pow(data_stat,2);
			 }
		       else if( asymm == 1 )
			 {		       
			    cov_v += covAS*sigma_i1*sigma_i2+
			      pow(data_stat,2);
			 }		       
		       
		       if( i1 == i2 && is == 0 )
			 cov_v += pow(stat_i1,2);
		       
		       if( is != 0 )
			 {		       
			    stat_i1 = 0;
			    stat_i2 = 0;
			 }
		       
		       if( asymm == 0 )
			 {		       
			    norm_i1_v += covAS*sigma_i1/2.*sigma_i1/2.+
			      covAS*alpha_i1/2.*alpha_i1/2.*(1.-2./PI) +
			      pow(stat_i1,2)+pow(data_stat,2);
			    
			    norm_i2_v += covAS*sigma_i2/2.*sigma_i2/2.+
			      covAS*alpha_i2/2.*alpha_i2/2.*(1.-2./PI) +
			      pow(stat_i2,2)+pow(data_stat,2);
			 }
		       else if( asymm == 1 )
			 {		       
			    norm_i1_v += covAS*sigma_i1*sigma_i1+
			      pow(stat_i1,2)+pow(data_stat,2);
			    norm_i2_v += covAS*sigma_i2*sigma_i2+
			      pow(stat_i2,2)+pow(data_stat,2);
			 }
		    }
		  
		  //	     if( i1 == i2 )
		  //	       std::cout << "raw: " << 1./cov_v << std::endl;
		  
		  norm[i1][i2] = sqrt(norm_i1_v)*sqrt(norm_i2_v);
		  //	     cov[i1][i2] = cov_v / norm[i1][i2] * covFCUR;
		  
		  if( i1 == i2 ) 
		    {
		       norm1D[i1] = sqrt(norm_i1_v);
		    }

		  cov[i1][i2] = cov_v * covFCUR;
		  //	     std::cout << i1 << " " << i2 << " " << cov_v << std::endl;
	       }	     
	     
	     // adjust template shape FIXME
//	     double avern = h_draw_bcljet_comb[iVAR]->GetBinContent(idx1);
//	     double averb = avern + 1./sqrt(2*PI)*siglin;
//	     h_draw_bcljet_comb[iVAR]->SetBinContent(idx1,averb);
	  }

	delete h_SYM;
	for(int is=0;is<nsysGL;is++)
	  {
	     delete h_SYM_UP[is];
	     delete h_SYM_LOW[is];
	  }	
	
	for(int i1=0;i1<vecM_n;i1++)
	  {
	     for(int i2=0;i2<vecM_n;i2++)
	       {
		  // 20140117
//		  cov[i1][i2] = cov[i1][i2] / norm1D[i1] / norm1D[i2] * covFCUR;
		  cov[i1][i2] = cov[i1][i2] / norm1D[i1] / norm1D[i2];
	       }
	  }   
	
	//   exit(1);
   	// 
	covM.ResizeTo(vecM_n,vecM_n);
	covMI.ResizeTo(vecM_n,vecM_n);
	for(int i1=0;i1<vecM_n;i1++)
	  {
	     for(int i2=0;i2<vecM_n;i2++)
	       {
		  covM[i1][i2] = cov[i1][i2];
	       }	
	  }
	
	TMatrixDSym covMSym;
	TMatrixDSym covMISym;
//	TMatrixD covMSym;
//	TMatrixD covMISym;
	covMSym.ResizeTo(vecM_n,vecM_n);
	covMISym.ResizeTo(vecM_n,vecM_n);
	for(int i1=0;i1<vecM_n;i1++)
	  {
	     for(int i2=0;i2<vecM_n;i2++)
	       {
		  covMSym[i1][i2] = cov[i1][i2];
		  covMISym[i1][i2] = cov[i1][i2];
	       }	
	  }
//	TDecompChol lu(covMSym);
//	lu.Invert(covMISym);
	TDecompBK lu(covMSym);
	lu.Invert(covMISym);
//	double det;
//	covMSym.Invert(&det);
//	std::cout << "Determinant = " << det << std::endl;
   
//   covMISym.Invert();
//   covMSym.Print();
//   covMISym.Print();
//   std::cout << "Determinant = " << covMSym.Determinant() << " " <<
//     covMISym.Determinant() << std::endl;
   
/*   TDecompLU lu(covM);
   if( ! lu.Decompose() )
     {
	std::cout << "Matrix decomposition failed" << std::endl;
	exit(1);
     }*/
   
   // invert covariance matrix
   // http://root.cern.ch/drupal/content/how-invert-matrix
//   lu.Invert(covMI);
   
//   covM.Print();
//   covMI.Print();

//   covMI.Print();
//   std::cout << "DETERMINANT=" << covM.Determinant() << std::endl;
//   std::cout << "INVERSE:" << std::endl;
//   covMI.Print();
//   std::cout << "DETERMINANT=" << covMI.Determinant() << std::endl;
//   exit(1);
	TMatrixD unityM = covMSym*covMISym;
//   unityM.Print();
	if( fabs(unityM.Determinant()-1) > 10E-6 )
	  {
	     std::cout << "Inversion of covariance matrix failed" << std::endl;
	     std::cout << unityM.Determinant()-1 << std::endl;
	     exit(1);
	  }      
	//   exit(1);
	// 
	for(int i1=0;i1<vecM_n;i1++)
	  {
	     for(int i2=0;i2<vecM_n;i2++)
	       {
		  covMI[i1][i2] = covMISym[i1][i2];
		  //	     covMI[i1][i2] /= norm[i1][i2]*covFCUR;
	       }	
	  }
	
	if( covMI.Determinant() < 0 )
	  {
	     covMSym.Print();
//	     covMI.Print();
	     std::cout << "Determinant is negative: " << covMSym.Determinant() << std::endl;
	     exit(1);
	  }

	for(int ie=0;ie<vecM_MAX;ie++)
	  {
	     vconv[ie] = norm1D[ie];
	  }

	norm1Dp = &vconv;

	if( write )
	  {	     
	     if( iPTcur == 0 && iBTAGcur == 0 )
	       fcov = new TFile("results/cov.root","RECREATE");
	     else
	       fcov = new TFile("results/cov.root","UPDATE");

	     std::string matrixName = "covMI_"+hnamePT[iPTcur]+hnameBTAG[iBTAGcur];
	     covMI.Write(matrixName.c_str());
	     std::string normName = "norm_"+hnamePT[iPTcur]+hnameBTAG[iBTAGcur];
	     vconv.Write(normName.c_str());
	     fcov->Close();
	  }
	     
	covMIp = &covMI;
     }
   else
     {
        fcov = TFile::Open("results/cov.root");
	std::string matrixName = "covMI_"+hnamePT[iPTcur]+hnameBTAG[iBTAGcur];
	covMIp = (TMatrixD*)fcov->Get(matrixName.c_str());
	std::string normName = "norm_"+hnamePT[iPTcur]+hnameBTAG[iBTAGcur];
	norm1Dp = (TVectorD*)fcov->Get(normName.c_str());
     }
  
   delete h_bjet_fit;
   delete h_cjet_fit;
   delete h_ljet_fit;
   delete h_ljet_data_fit;
   
   for(int is=0;is<nsysGL;is++)
     {	
	delete h_bjet_sys_low_fit[is];
	delete h_bjet_sys_up_fit[is];
	delete h_cjet_sys_low_fit[is];
	delete h_cjet_sys_up_fit[is];
	delete h_ljet_sys_low_fit[is];
	delete h_ljet_sys_up_fit[is];
	delete h_ljet_data_sys_low_fit[is];
	delete h_ljet_data_sys_up_fit[is];
     }   
}

void applySys2DIM(int iVAR2D,
		  std::string hname_bjet,
		  std::string hname_cjet,
		  std::string hname_ljet,
		  std::string hname_ajet,
		  std::string hname_ljet_data,
		  double sf1,
		  double sf2,
		  double sf3,
		  double sf1err,
		  double sf2err,
		  double sf3err
		  )
{
   std::string c_bjet_fit = hname_bjet + "_fit_2d";
   TH2D *h_bjet_fit_2d = (TH2D*)h_draw_bjet_2d[iVAR2D]->Clone(c_bjet_fit.c_str());
   std::string c_cjet_fit = hname_cjet + "_fit_2d";
   TH2D *h_cjet_fit_2d = (TH2D*)h_draw_cjet_2d[iVAR2D]->Clone(c_cjet_fit.c_str());
   std::string c_ljet_fit = hname_ljet + "_fit_2d";
   TH2D *h_ljet_fit_2d = (TH2D*)h_draw_ljet_2d[iVAR2D]->Clone(c_ljet_fit.c_str());   
   std::string c_ljet_data_fit = hname_ljet_data + "_fit_2d";
   TH2D *h_ljet_data_fit_2d = (TH2D*)h_draw_ljet_data_2d[iVAR2D]->Clone(c_ljet_data_fit.c_str());   
   
   h_bjet_fit_2d->Scale(sf1);
   h_cjet_fit_2d->Scale(sf2);
   h_ljet_fit_2d->Scale(sf3);
   h_ljet_data_fit_2d->Scale(sf3);
   
   TH2D *h_bjet_sys_low_fit_2d[nsysGL];
   TH2D *h_bjet_sys_up_fit_2d[nsysGL];
   TH2D *h_cjet_sys_low_fit_2d[nsysGL];
   TH2D *h_cjet_sys_up_fit_2d[nsysGL];
   TH2D *h_ljet_sys_low_fit_2d[nsysGL];
   TH2D *h_ljet_sys_up_fit_2d[nsysGL];
   TH2D *h_ljet_data_sys_low_fit_2d[nsysGL];
   TH2D *h_ljet_data_sys_up_fit_2d[nsysGL];

   std::string c_bjet_sys_up_fit = hname_bjet + "_sys_up_fit_2d";
   std::string c_bjet_sys_low_fit = hname_bjet + "_sys_low_fit_2d";

   std::string c_cjet_sys_up_fit = hname_cjet + "_sys_up_fit_2d";
   std::string c_cjet_sys_low_fit = hname_cjet + "_sys_low_fit_2d";

   std::string c_ljet_sys_up_fit = hname_ljet + "_sys_up_fit_2d";
   std::string c_ljet_sys_low_fit = hname_ljet + "_sys_low_fit_2d";

   std::string c_ljet_data_sys_up_fit = hname_ljet_data + "_sys_up_fit_2d";
   std::string c_ljet_data_sys_low_fit = hname_ljet_data + "_sys_low_fit_2d";
   
   for(int j=0;j<nsysGL;j++)
     {
	h_bjet_sys_low_fit_2d[j] = (TH2D*)h_draw_bjet_sys_low_2d[j][iVAR2D]->Clone((c_bjet_sys_low_fit+name_sys_low[j]).c_str());
	h_cjet_sys_low_fit_2d[j] = (TH2D*)h_draw_cjet_sys_low_2d[j][iVAR2D]->Clone((c_cjet_sys_low_fit+name_sys_low[j]).c_str());
	h_ljet_sys_low_fit_2d[j] = (TH2D*)h_draw_ljet_sys_low_2d[j][iVAR2D]->Clone((c_ljet_sys_low_fit+name_sys_low[j]).c_str());
	h_ljet_data_sys_low_fit_2d[j] = (TH2D*)h_draw_ljet_data_sys_low_2d[j][iVAR2D]->Clone((c_ljet_data_sys_low_fit+name_sys_low[j]).c_str());

	h_bjet_sys_up_fit_2d[j] = (TH2D*)h_draw_bjet_sys_up_2d[j][iVAR2D]->Clone((c_bjet_sys_up_fit+name_sys_up[j]).c_str());
	h_cjet_sys_up_fit_2d[j] = (TH2D*)h_draw_cjet_sys_up_2d[j][iVAR2D]->Clone((c_cjet_sys_up_fit+name_sys_up[j]).c_str());
	h_ljet_sys_up_fit_2d[j] = (TH2D*)h_draw_ljet_sys_up_2d[j][iVAR2D]->Clone((c_ljet_sys_up_fit+name_sys_up[j]).c_str());
	h_ljet_data_sys_up_fit_2d[j] = (TH2D*)h_draw_ljet_data_sys_up_2d[j][iVAR2D]->Clone((c_ljet_data_sys_up_fit+name_sys_up[j]).c_str());

	if( ljetData == 0 )
	  {	     
	     h_bjet_sys_low_fit_2d[j]->Scale(sf1);
	     h_cjet_sys_low_fit_2d[j]->Scale(sf2);
	     h_ljet_sys_low_fit_2d[j]->Scale(sf3);
	     
	     h_bjet_sys_up_fit_2d[j]->Scale(sf1);
	     h_cjet_sys_up_fit_2d[j]->Scale(sf2);
	     h_ljet_sys_up_fit_2d[j]->Scale(sf3);
	  }
	else
	  {
	     h_bjet_sys_low_fit_2d[j]->Scale(sf1);
	     h_cjet_sys_low_fit_2d[j]->Scale(sf2);
	     h_ljet_data_sys_low_fit_2d[j]->Scale(sf3);
	     
	     h_bjet_sys_up_fit_2d[j]->Scale(sf1);
	     h_cjet_sys_up_fit_2d[j]->Scale(sf2);
	     h_ljet_data_sys_up_fit_2d[j]->Scale(sf3);
	  }
	
	double integLow = h_bjet_sys_low_fit_2d[j]->Integral(0,h_bjet_sys_low_fit_2d[j]->GetXaxis()->GetNbins()+1,
							     0,h_bjet_sys_low_fit_2d[j]->GetYaxis()->GetNbins()+1)+
	  h_cjet_sys_low_fit_2d[j]->Integral(0,h_cjet_sys_low_fit_2d[j]->GetXaxis()->GetNbins()+1,
					     0,h_cjet_sys_low_fit_2d[j]->GetYaxis()->GetNbins()+1)+
	  h_ljet_sys_low_fit_2d[j]->Integral(0,h_ljet_sys_low_fit_2d[j]->GetXaxis()->GetNbins()+1,
					     0,h_ljet_sys_low_fit_2d[j]->GetYaxis()->GetNbins()+1);

	double integUp = h_bjet_sys_up_fit_2d[j]->Integral(0,h_bjet_sys_up_fit_2d[j]->GetXaxis()->GetNbins()+1,
							   0,h_bjet_sys_up_fit_2d[j]->GetYaxis()->GetNbins()+1)+
	  h_cjet_sys_up_fit_2d[j]->Integral(0,h_cjet_sys_up_fit_2d[j]->GetXaxis()->GetNbins()+1,
					    0,h_cjet_sys_up_fit_2d[j]->GetYaxis()->GetNbins()+1)+
	  h_ljet_sys_up_fit_2d[j]->Integral(0,h_ljet_sys_up_fit_2d[j]->GetXaxis()->GetNbins()+1,
					    0,h_ljet_sys_up_fit_2d[j]->GetYaxis()->GetNbins()+1);

	double integLow_data = h_bjet_sys_low_fit_2d[j]->Integral(0,h_bjet_sys_low_fit_2d[j]->GetXaxis()->GetNbins()+1,
							     0,h_bjet_sys_low_fit_2d[j]->GetYaxis()->GetNbins()+1)+
	  h_cjet_sys_low_fit_2d[j]->Integral(0,h_cjet_sys_low_fit_2d[j]->GetXaxis()->GetNbins()+1,
					     0,h_cjet_sys_low_fit_2d[j]->GetYaxis()->GetNbins()+1)+
	  h_ljet_data_sys_low_fit_2d[j]->Integral(0,h_ljet_data_sys_low_fit_2d[j]->GetXaxis()->GetNbins()+1,
						  0,h_ljet_data_sys_low_fit_2d[j]->GetYaxis()->GetNbins()+1);

	double integUp_data = h_bjet_sys_up_fit_2d[j]->Integral(0,h_bjet_sys_up_fit_2d[j]->GetXaxis()->GetNbins()+1,
							   0,h_bjet_sys_up_fit_2d[j]->GetYaxis()->GetNbins()+1)+
	  h_cjet_sys_up_fit_2d[j]->Integral(0,h_cjet_sys_up_fit_2d[j]->GetXaxis()->GetNbins()+1,
					    0,h_cjet_sys_up_fit_2d[j]->GetYaxis()->GetNbins()+1)+
	  h_ljet_data_sys_up_fit_2d[j]->Integral(0,h_ljet_data_sys_up_fit_2d[j]->GetXaxis()->GetNbins()+1,
						 0,h_ljet_data_sys_up_fit_2d[j]->GetYaxis()->GetNbins()+1);

	if( ljetData == 0 )
	  {	     
	     h_bjet_sys_low_fit_2d[j]->Scale(1./integLow);
	     h_cjet_sys_low_fit_2d[j]->Scale(1./integLow);
	     h_ljet_sys_low_fit_2d[j]->Scale(1./integLow);
	     
	     h_bjet_sys_up_fit_2d[j]->Scale(1./integUp);
	     h_cjet_sys_up_fit_2d[j]->Scale(1./integUp);
	     h_ljet_sys_up_fit_2d[j]->Scale(1./integUp);
	  }
	else
	  {
	     h_bjet_sys_low_fit_2d[j]->Scale(1./integLow_data);
	     h_cjet_sys_low_fit_2d[j]->Scale(1./integLow_data);
	     h_ljet_data_sys_low_fit_2d[j]->Scale(1./integLow_data);
	     
	     h_bjet_sys_up_fit_2d[j]->Scale(1./integUp_data);
	     h_cjet_sys_up_fit_2d[j]->Scale(1./integUp_data);
	     h_ljet_data_sys_up_fit_2d[j]->Scale(1./integUp_data);
	  }
	
/*	if( ljetData == 0 )
	  {	     
	     h_bjet_sys_low_fit_2d[j]->Scale(sf1/integLow);
	     h_cjet_sys_low_fit_2d[j]->Scale(sf2/integLow);
	     h_ljet_sys_low_fit_2d[j]->Scale(sf3/integLow);
	     
	     h_bjet_sys_up_fit_2d[j]->Scale(sf1/integUp);
	     h_cjet_sys_up_fit_2d[j]->Scale(sf2/integUp);
	     h_ljet_sys_up_fit_2d[j]->Scale(sf3/integUp);
	  }
	else
	  {
	     h_bjet_sys_low_fit_2d[j]->Scale(sf1/integLow_data);
	     h_cjet_sys_low_fit_2d[j]->Scale(sf2/integLow_data);
	     h_ljet_data_sys_low_fit_2d[j]->Scale(sf3/integLow_data);
	     
	     h_bjet_sys_up_fit_2d[j]->Scale(sf1/integUp_data);
	     h_cjet_sys_up_fit_2d[j]->Scale(sf2/integUp_data);
	     h_ljet_data_sys_up_fit_2d[j]->Scale(sf3/integUp_data);
	  }*/
     }   

   for(int j=0;j<nsysGL;j++)
     {
	if( ljetData == 0 )
	  {	     
	     combSysLinear2DIM(h_bjet_fit_2d,h_cjet_fit_2d,h_ljet_fit_2d,
			       h_bjet_sys_low_fit_2d[j],h_bjet_sys_up_fit_2d[j],
			       h_cjet_sys_low_fit_2d[j],h_cjet_sys_up_fit_2d[j],
			       h_ljet_sys_low_fit_2d[j],h_ljet_sys_up_fit_2d[j],
			       h_draw_bcljet_comb_2d[iVAR2D],
			       h_draw_bcljet_sys_low_comb_2d[iVAR2D*nsysGL+j],
			       h_draw_bcljet_sys_up_comb_2d[iVAR2D*nsysGL+j],
			       sf1,sf2,sf3);
	  }
	else
	  {
	     combSysLinear2DIM(h_bjet_fit_2d,h_cjet_fit_2d,h_ljet_fit_2d,
			       h_bjet_sys_low_fit_2d[j],h_bjet_sys_up_fit_2d[j],
			       h_cjet_sys_low_fit_2d[j],h_cjet_sys_up_fit_2d[j],
			       h_ljet_data_sys_low_fit_2d[j],h_ljet_data_sys_up_fit_2d[j],
			       h_draw_bcljet_comb_2d[iVAR2D],
			       h_draw_bcljet_sys_low_comb_2d[iVAR2D*nsysGL+j],
			       h_draw_bcljet_sys_up_comb_2d[iVAR2D*nsysGL+j],
			       sf1,sf2,sf3);
	  }	
	
	totSys2DIM(h_draw_bcljet_comb_2d[iVAR2D],
		   h_draw_bcljet_sys_low_comb_2d[iVAR2D*nsysGL+j],
		   h_draw_bcljet_sys_up_comb_2d[iVAR2D*nsysGL+j]);	
     }
   
   combSys2DIM(h_draw_bcljet_comb_2d[iVAR2D],
	       h_draw_bcljet_sys_low_comb_2d,
	       h_draw_bcljet_sys_up_comb_2d,
	       h_draw_bcljet_sys_low_combSum_2d[iVAR2D],
	       h_draw_bcljet_sys_up_combSum_2d[iVAR2D],iVAR2D);
   
   totSys2DIM(h_draw_bcljet_comb_2d[iVAR2D],
	      h_draw_bcljet_sys_low_combSum_2d[iVAR2D],
	      h_draw_bcljet_sys_up_combSum_2d[iVAR2D]);
}

/*
void readData2D(bool local,
		int iVAR,
		std::string hname_bjet,
		std::string hname_cjet,
		std::string hname_ljet,
		std::string hname_ajet,
		std::vector<std::string> v_mc_filt,
		std::vector<std::string> v_mc_unfilt,
		std::vector<std::string> v_data)
{
   if( ! local )
     {		  	     
	for(int i=0;i<v_mc_filt.size();i++)
	  {
	     std::string fname_filt = fpathMC+v_mc_filt.at(i);
	     fbatch_mc_filt[i][iVAR] = TFile::Open(fname_filt.c_str());
	     std::string fname_unfilt = fpathMC+v_mc_unfilt.at(i);
	     fbatch_mc_unfilt[i][iVAR] = TFile::Open(fname_unfilt.c_str());
	     
	     TH2F *hf_bjet = (TH2F*)fbatch_mc_filt[i][iVAR]->Get(hname_bjet.c_str());
	     TH2F *hf_cjet = (TH2F*)fbatch_mc_filt[i][iVAR]->Get(hname_cjet.c_str());
	     TH2F *hf_ljet = (TH2F*)fbatch_mc_unfilt[i][iVAR]->Get(hname_ljet.c_str());

	     TH2F *hf_cljet = (TH2F*)fbatch_mc_filt[i][iVAR]->Get(hname_cjet.c_str());
	     if( i == 0 ) 
	       {
		  h_draw_bjet_2d[iVAR] = (TH2F*)hf_bjet->Clone(hname_bjet.c_str());
		  h_draw_cjet_2d[iVAR] = (TH2F*)hf_cjet->Clone(hname_cjet.c_str());
		  h_draw_ljet_2d[iVAR] = (TH2F*)hf_ljet->Clone(hname_ljet.c_str());
		  
		  std::string hname_cljet = hname_cjet+"_plusl";
		  h_draw_cljet_2d[iVAR] = (TH2F*)hf_cljet->Clone(hname_cljet.c_str());
		  h_draw_cljet_2d[iVAR]->Add(hf_ljet);
	       }	
	     else 
	       {
		  h_draw_bjet_2d[iVAR]->Add(hf_bjet);
		  h_draw_cjet_2d[iVAR]->Add(hf_cjet);
		  h_draw_ljet_2d[iVAR]->Add(hf_ljet);
		  
		  h_draw_cljet_2d[iVAR]->Add(hf_cjet);
		  h_draw_cljet_2d[iVAR]->Add(hf_ljet);
	       }
	  }   
	
	for(int i=0;i<v_data.size();i++)
	  {
	     std::string fname = fpathData+v_data.at(i);
	     fbatch_data[i][iVAR] = TFile::Open(fname.c_str());
	     
	     TH2F *hf_ajet = (TH2F*)fbatch_data[i][iVAR]->Get(hname_ajet.c_str());
	     if( i == 0 ) 
	       {
		  h_draw_ajet_data_2d[iVAR] = (TH2F*)hf_ajet->Clone(hname_ajet.c_str());
	       }	
	     else 
	       {
		  h_draw_ajet_data_2d[iVAR]->Add(hf_ajet);
	       }
	  }
     }
   else
     {
	fMCJ0[iVAR] = TFile::Open(flocalMCJ0.c_str());
	fMCJ1[iVAR] = TFile::Open(flocalMCJ1.c_str());
	fMCJ2[iVAR] = TFile::Open(flocalMCJ2.c_str());
	fMCJ3[iVAR] = TFile::Open(flocalMCJ3.c_str());
	fMCJ4[iVAR] = TFile::Open(flocalMCJ4.c_str());
	fMCJ5[iVAR] = TFile::Open(flocalMCJ5.c_str());
	fMCJ6[iVAR] = TFile::Open(flocalMCJ6.c_str());
	fMCJ7[iVAR] = TFile::Open(flocalMCJ7.c_str());
	fMCJ8[iVAR] = TFile::Open(flocalMCJ8.c_str());
	fDATA[iVAR] = TFile::Open(flocalDATA.c_str());
	
	TH2F *hfMCJ0 = (TH2F*)fMCJ0[iVAR]->Get(hname_ajet.c_str());
	TH2F *hfMCJ1 = (TH2F*)fMCJ1[iVAR]->Get(hname_ajet.c_str());
	TH2F *hfMCJ2 = (TH2F*)fMCJ2[iVAR]->Get(hname_ajet.c_str());
	TH2F *hfMCJ3 = (TH2F*)fMCJ3[iVAR]->Get(hname_ajet.c_str());
	TH2F *hfMCJ4 = (TH2F*)fMCJ4[iVAR]->Get(hname_ajet.c_str());
	TH2F *hfMCJ5 = (TH2F*)fMCJ5[iVAR]->Get(hname_ajet.c_str());
	TH2F *hfMCJ6 = (TH2F*)fMCJ6[iVAR]->Get(hname_ajet.c_str());
	TH2F *hfMCJ7 = (TH2F*)fMCJ7[iVAR]->Get(hname_ajet.c_str());
	TH2F *hfMCJ8 = (TH2F*)fMCJ8[iVAR]->Get(hname_ajet.c_str());
	TH2F *hfDATA = (TH2F*)fDATA[iVAR]->Get(hname_ajet.c_str());
	
	TH2F *hfMCJ0_bjet = (TH2F*)fMCJ0[iVAR]->Get(hname_bjet.c_str());
	TH2F *hfMCJ1_bjet = (TH2F*)fMCJ1[iVAR]->Get(hname_bjet.c_str());
	TH2F *hfMCJ2_bjet = (TH2F*)fMCJ2[iVAR]->Get(hname_bjet.c_str());
	TH2F *hfMCJ3_bjet = (TH2F*)fMCJ3[iVAR]->Get(hname_bjet.c_str());
	TH2F *hfMCJ4_bjet = (TH2F*)fMCJ4[iVAR]->Get(hname_bjet.c_str());
	TH2F *hfMCJ5_bjet = (TH2F*)fMCJ5[iVAR]->Get(hname_bjet.c_str());
	TH2F *hfMCJ6_bjet = (TH2F*)fMCJ6[iVAR]->Get(hname_bjet.c_str());
	TH2F *hfMCJ7_bjet = (TH2F*)fMCJ7[iVAR]->Get(hname_bjet.c_str());
	TH2F *hfMCJ8_bjet = (TH2F*)fMCJ8[iVAR]->Get(hname_bjet.c_str());
	
	TH2F *hfMCJ0_cjet = (TH2F*)fMCJ0[iVAR]->Get(hname_cjet.c_str());
	TH2F *hfMCJ1_cjet = (TH2F*)fMCJ1[iVAR]->Get(hname_cjet.c_str());
	TH2F *hfMCJ2_cjet = (TH2F*)fMCJ2[iVAR]->Get(hname_cjet.c_str());
	TH2F *hfMCJ3_cjet = (TH2F*)fMCJ3[iVAR]->Get(hname_cjet.c_str());
	TH2F *hfMCJ4_cjet = (TH2F*)fMCJ4[iVAR]->Get(hname_cjet.c_str());
	TH2F *hfMCJ5_cjet = (TH2F*)fMCJ5[iVAR]->Get(hname_cjet.c_str());
	TH2F *hfMCJ6_cjet = (TH2F*)fMCJ6[iVAR]->Get(hname_cjet.c_str());
	TH2F *hfMCJ7_cjet = (TH2F*)fMCJ7[iVAR]->Get(hname_cjet.c_str());
	TH2F *hfMCJ8_cjet = (TH2F*)fMCJ8[iVAR]->Get(hname_cjet.c_str());
	
	TH2F *hfMCJ0_ljet = (TH2F*)fMCJ0[iVAR]->Get(hname_ljet.c_str());
	TH2F *hfMCJ1_ljet = (TH2F*)fMCJ1[iVAR]->Get(hname_ljet.c_str());
	TH2F *hfMCJ2_ljet = (TH2F*)fMCJ2[iVAR]->Get(hname_ljet.c_str());
	TH2F *hfMCJ3_ljet = (TH2F*)fMCJ3[iVAR]->Get(hname_ljet.c_str());
	TH2F *hfMCJ4_ljet = (TH2F*)fMCJ4[iVAR]->Get(hname_ljet.c_str());
	TH2F *hfMCJ5_ljet = (TH2F*)fMCJ5[iVAR]->Get(hname_ljet.c_str());
	TH2F *hfMCJ6_ljet = (TH2F*)fMCJ6[iVAR]->Get(hname_ljet.c_str());
	TH2F *hfMCJ7_ljet = (TH2F*)fMCJ7[iVAR]->Get(hname_ljet.c_str());
	TH2F *hfMCJ8_ljet = (TH2F*)fMCJ8[iVAR]->Get(hname_ljet.c_str());
	
	h_draw_ajet_data_2d[iVAR] = (TH2F*)hfDATA->Clone(hname_ajet.c_str());
	
	h_draw_ajet_2d[iVAR] = (TH2F*)hfMCJ0->Clone(hname_ajet.c_str());
	h_draw_ajet_2d[iVAR]->Add(hfMCJ1,1.);
	h_draw_ajet_2d[iVAR]->Add(hfMCJ2,1.);
	h_draw_ajet_2d[iVAR]->Add(hfMCJ3,1.);
	h_draw_ajet_2d[iVAR]->Add(hfMCJ4,1.);
	h_draw_ajet_2d[iVAR]->Add(hfMCJ5,1.);
	h_draw_ajet_2d[iVAR]->Add(hfMCJ6,1.);
	h_draw_ajet_2d[iVAR]->Add(hfMCJ7,1.);
	h_draw_ajet_2d[iVAR]->Add(hfMCJ8,1.);
	
	h_draw_bjet_2d[iVAR] = (TH2F*)hfMCJ0_bjet->Clone(hname_bjet.c_str());
	h_draw_bjet_2d[iVAR]->Add(hfMCJ1_bjet,1.);
	h_draw_bjet_2d[iVAR]->Add(hfMCJ2_bjet,1.);
	h_draw_bjet_2d[iVAR]->Add(hfMCJ3_bjet,1.);
	h_draw_bjet_2d[iVAR]->Add(hfMCJ4_bjet,1.);
	h_draw_bjet_2d[iVAR]->Add(hfMCJ5_bjet,1.);
	h_draw_bjet_2d[iVAR]->Add(hfMCJ6_bjet,1.);
	h_draw_bjet_2d[iVAR]->Add(hfMCJ7_bjet,1.);
	h_draw_bjet_2d[iVAR]->Add(hfMCJ8_bjet,1.);
	
	h_draw_cjet_2d[iVAR] = (TH2F*)hfMCJ0_cjet->Clone(hname_cjet.c_str());
	h_draw_cjet_2d[iVAR]->Add(hfMCJ1_cjet,1.);
	h_draw_cjet_2d[iVAR]->Add(hfMCJ2_cjet,1.);
	h_draw_cjet_2d[iVAR]->Add(hfMCJ3_cjet,1.);
	h_draw_cjet_2d[iVAR]->Add(hfMCJ4_cjet,1.);
	h_draw_cjet_2d[iVAR]->Add(hfMCJ5_cjet,1.);
	h_draw_cjet_2d[iVAR]->Add(hfMCJ6_cjet,1.);
	h_draw_cjet_2d[iVAR]->Add(hfMCJ7_cjet,1.);
	h_draw_cjet_2d[iVAR]->Add(hfMCJ8_cjet,1.);
	
	h_draw_ljet_2d[iVAR] = (TH2F*)hfMCJ0_ljet->Clone(hname_ljet.c_str());
	h_draw_ljet_2d[iVAR]->Add(hfMCJ1_ljet,1.);
	h_draw_ljet_2d[iVAR]->Add(hfMCJ2_ljet,1.);
	h_draw_ljet_2d[iVAR]->Add(hfMCJ3_ljet,1.);
	h_draw_ljet_2d[iVAR]->Add(hfMCJ4_ljet,1.);
	h_draw_ljet_2d[iVAR]->Add(hfMCJ5_ljet,1.);
	h_draw_ljet_2d[iVAR]->Add(hfMCJ6_ljet,1.);
	h_draw_ljet_2d[iVAR]->Add(hfMCJ7_ljet,1.);
	h_draw_ljet_2d[iVAR]->Add(hfMCJ8_ljet,1.);
     }
}
*/
/*void readData2D(bool local,
		int iVAR2D,
		std::string hname_bjet,
		std::string hname_cjet,
		std::string hname_ljet,
		std::string hname_ajet,
		std::vector<std::string> v_mc_filt,
		std::vector<std::string> v_mc_unfilt,
		std::vector<std::string> v_data)
{
   for(int i=0;i<v_mc_filt.size();i++)
     {
	std::string fname_filt = fpathMC+v_mc_filt.at(i);
	fbatch_mc_filt[i][iVAR2D] = TFile::Open(fname_filt.c_str());
	std::string fname_unfilt = fpathMC+v_mc_unfilt.at(i);
	fbatch_mc_unfilt[i][iVAR2D] = TFile::Open(fname_unfilt.c_str());
	
	TH2F *hf_bjet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(hname_bjet.c_str());
	TH2F *hf_cjet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(hname_cjet.c_str());
	TH2F *hf_ljet = (TH2F*)fbatch_mc_unfilt[i][iVAR2D]->Get(hname_ljet.c_str());
	
	TH2F *hf_cljet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(hname_cjet.c_str());
	if( i == 0 ) 
	  {
	     h_draw_bjet_2d[iVAR2D] = (TH2F*)hf_bjet->Clone(hname_bjet.c_str());
	     h_draw_cjet_2d[iVAR2D] = (TH2F*)hf_cjet->Clone(hname_cjet.c_str());
	     h_draw_ljet_2d[iVAR2D] = (TH2F*)hf_ljet->Clone(hname_ljet.c_str());
	     
	     std::string hname_cljet = hname_cjet+"_plusl";
	     h_draw_cljet_2d[iVAR2D] = (TH2F*)hf_cljet->Clone(hname_cljet.c_str());
	     h_draw_cljet_2d[iVAR2D]->Add(h_draw_ljet[iVAR2D]);
	  }	
	else 
	  {
	     h_draw_bjet_2d[iVAR2D]->Add(hf_bjet);
	     h_draw_cjet_2d[iVAR2D]->Add(hf_cjet);
	     h_draw_ljet_2d[iVAR2D]->Add(hf_ljet);
	     
	     h_draw_cljet_2d[iVAR2D]->Add(hf_cjet);
	     h_draw_cljet_2d[iVAR2D]->Add(hf_ljet);
	  }
	
	std::string cname_bjet = "";
	std::string cname_cjet = "";
	std::string cname_ljet = "";
	
	for(int j=0;j<nsys;j++)
	  {		  
	     cname_bjet = hname_bjet + name_sys_low[j];
	     cname_cjet = hname_cjet + name_sys_low[j];
	     cname_ljet = hname_ljet + name_sys_low[j];
	     TH2F *hf_sys_low_bjet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(cname_bjet.c_str());
	     TH2F *hf_sys_low_cjet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(cname_cjet.c_str());
	     TH2F *hf_sys_low_ljet = (TH2F*)fbatch_mc_unfilt[i][iVAR2D]->Get(cname_ljet.c_str());
	     cname_bjet = cname_bjet + "_clone";
	     cname_cjet = cname_cjet + "_clone";
	     cname_ljet = cname_ljet + "_clone";
	     if( i == 0 ) 
	       {
		  h_draw_bjet_sys_low_2d[j][iVAR2D] = (TH2F*)hf_sys_low_bjet->Clone(cname_bjet.c_str());
		  h_draw_cjet_sys_low_2d[j][iVAR2D] = (TH2F*)hf_sys_low_cjet->Clone(cname_cjet.c_str());
		  h_draw_ljet_sys_low_2d[j][iVAR2D] = (TH2F*)hf_sys_low_ljet->Clone(cname_ljet.c_str());
	       }
	     else 
	       {
		  h_draw_bjet_sys_low_2d[j][iVAR2D]->Add(hf_sys_low_bjet);
		  h_draw_cjet_sys_low_2d[j][iVAR2D]->Add(hf_sys_low_cjet);
		  h_draw_ljet_sys_low_2d[j][iVAR2D]->Add(hf_sys_low_ljet);
	       }		 
	     
	     cname_bjet = hname_bjet + name_sys_up[j];
	     cname_cjet = hname_cjet + name_sys_up[j];
	     cname_ljet = hname_ljet + name_sys_up[j];
	     TH2F *hf_sys_up_bjet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(cname_bjet.c_str());
	     TH2F *hf_sys_up_cjet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(cname_cjet.c_str());
	     TH2F *hf_sys_up_ljet = (TH2F*)fbatch_mc_unfilt[i][iVAR2D]->Get(cname_ljet.c_str());
	     cname_bjet = cname_bjet + "_clone";
	     cname_cjet = cname_cjet + "_clone";
	     cname_ljet = cname_ljet + "_clone";
	     if( i == 0 ) 
	       {
		  h_draw_bjet_sys_up_2d[j][iVAR2D] = (TH2F*)hf_sys_up_bjet->Clone(cname_bjet.c_str());
		  h_draw_cjet_sys_up_2d[j][iVAR2D] = (TH2F*)hf_sys_up_cjet->Clone(cname_cjet.c_str());
		  h_draw_ljet_sys_up_2d[j][iVAR2D] = (TH2F*)hf_sys_up_ljet->Clone(cname_ljet.c_str());
	       }
	     else 
	       {
		  h_draw_bjet_sys_up_2d[j][iVAR2D]->Add(hf_sys_up_bjet);
		  h_draw_cjet_sys_up_2d[j][iVAR2D]->Add(hf_sys_up_cjet);
		  h_draw_ljet_sys_up_2d[j][iVAR2D]->Add(hf_sys_up_ljet);
	       }		  
	  }
     }
   
   for(int i=0;i<v_data.size();i++)
     {
	std::string fname = fpathData+v_data.at(i);
	fbatch_data[i][iVAR2D] = TFile::Open(fname.c_str());
	
	TH2F *hf_ajet = (TH2F*)fbatch_data[i][iVAR2D]->Get(hname_ajet.c_str());
	if( i == 0 ) 
	  {
	     h_draw_ajet_data_2d[iVAR2D] = (TH2F*)hf_ajet->Clone(hname_ajet.c_str());
	  }	
	else 
	  {
	     h_draw_ajet_data_2d[iVAR2D]->Add(hf_ajet);
	  }
     }   
   
   addbin2D(h_draw_bjet_2d[iVAR2D]);
   addbin2D(h_draw_cjet_2d[iVAR2D]);
   addbin2D(h_draw_ljet_2d[iVAR2D]);
   addbin2D(h_draw_cljet_2d[iVAR2D]);
   
   addbin2D(h_draw_ajet_data_2d[iVAR2D]);
   
   for(int j=0;j<nsys;j++)
     {	     
	addbin2D(h_draw_bjet_sys_low_2d[j][iVAR2D]);
	addbin2D(h_draw_bjet_sys_up_2d[j][iVAR2D]);
	
	addbin2D(h_draw_cjet_sys_low_2d[j][iVAR2D]);
	addbin2D(h_draw_cjet_sys_up_2d[j][iVAR2D]);
	
	addbin2D(h_draw_ljet_sys_low_2d[j][iVAR2D]);
	addbin2D(h_draw_ljet_sys_up_2d[j][iVAR2D]);
     }	
   
   h_draw_bjet_2d[iVAR2D] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
   h_draw_cjet_2d[iVAR2D] = (TH2F*)h_draw_cjet_2d[iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
   h_draw_ljet_2d[iVAR2D] = (TH2F*)h_draw_ljet_2d[iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	
   for(int j=0;j<nsys;j++)
     {		  	     
	h_draw_bjet_sys_low_2d[j][iVAR2D] = (TH2F*)h_draw_bjet_sys_low_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_cjet_sys_low_2d[j][iVAR2D] = (TH2F*)h_draw_cjet_sys_low_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_ljet_sys_low_2d[j][iVAR2D] = (TH2F*)h_draw_ljet_sys_low_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	
	h_draw_bjet_sys_up_2d[j][iVAR2D] = (TH2F*)h_draw_bjet_sys_up_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_cjet_sys_up_2d[j][iVAR2D] = (TH2F*)h_draw_cjet_sys_up_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_ljet_sys_up_2d[j][iVAR2D] = (TH2F*)h_draw_ljet_sys_up_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
     }	     
   
   h_draw_cljet_2d[iVAR2D] = (TH2F*)h_draw_cljet_2d[iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
   h_draw_ajet_data_2d[iVAR2D] = (TH2F*)h_draw_ajet_data_2d[iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
   
   std::string h_bjet_comb_sys_up = hname_bjet + "_sys_up_comb";
   std::string h_bjet_comb_sys_low = hname_bjet + "_sys_low_comb";
   h_draw_bjet_sys_low_comb_2d[iVAR2D] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bjet_comb_sys_low.c_str());
   h_draw_bjet_sys_up_comb_2d[iVAR2D] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bjet_comb_sys_up.c_str());
   
   std::string h_cjet_comb_sys_up = hname_cjet + "_sys_up_comb";
   std::string h_cjet_comb_sys_low = hname_cjet + "_sys_low_comb";
   h_draw_cjet_sys_low_comb_2d[iVAR2D] = (TH2F*)h_draw_cjet_2d[iVAR2D]->Clone(h_cjet_comb_sys_low.c_str());
   h_draw_cjet_sys_up_comb_2d[iVAR2D] = (TH2F*)h_draw_cjet_2d[iVAR2D]->Clone(h_cjet_comb_sys_up.c_str());
   
   std::string h_ljet_comb_sys_up = hname_ljet + "_sys_up_comb";
   std::string h_ljet_comb_sys_low = hname_ljet + "_sys_low_comb";
   h_draw_ljet_sys_low_comb_2d[iVAR2D] = (TH2F*)h_draw_ljet_2d[iVAR2D]->Clone(h_ljet_comb_sys_low.c_str());
   h_draw_ljet_sys_up_comb_2d[iVAR2D] = (TH2F*)h_draw_ljet_2d[iVAR2D]->Clone(h_ljet_comb_sys_up.c_str());
   
   std::string h_bcljet_comb = hname_bjet + hname_cjet + hname_ljet + "_comb";
   h_draw_bcljet_comb_2d[iVAR2D] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bcljet_comb.c_str());
   
   for(int isy=0;isy<nsys;isy++)
     {	     
	std::string h_bcljet_comb_sys_up = hname_bjet + hname_cjet + hname_ljet + "_sys_up_comb" + name_sys_up[isy];
	std::string h_bcljet_comb_sys_low = hname_bjet + hname_cjet + hname_ljet + "_sys_low_comb" + name_sys_low[isy];
	h_draw_bcljet_sys_low_comb_2d[iVAR2D*50+isy] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bcljet_comb_sys_low.c_str());
	h_draw_bcljet_sys_up_comb_2d[iVAR2D*50+isy] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bcljet_comb_sys_up.c_str());
     }	
   
   std::string h_bcljet_combSum_sys_up = hname_bjet + hname_cjet + hname_ljet + "_sys_up_comb";
   std::string h_bcljet_combSum_sys_low = hname_bjet + hname_cjet + hname_ljet + "_sys_low_comb";
   h_draw_bcljet_sys_low_combSum_2d[iVAR2D] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bcljet_combSum_sys_low.c_str());
   h_draw_bcljet_sys_up_combSum_2d[iVAR2D] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bcljet_combSum_sys_up.c_str());
}*/
/*
void readData2D(int iVAR2D,
		std::string hname_bjet,
		std::string hname_cjet,
		std::string hname_ljet,
		std::string hname_ajet,
		std::string hname_ljet_data,
		std::string hname_bjet_untag,
		std::string hname_cjet_untag,
		std::vector<std::string> v_mc_filt,
		std::vector<std::string> v_mc_unfilt,
		std::vector<std::string> v_data)
{
   for(int i=0;i<v_mc_filt.size();i++)
     {
	std::string fname_filt = fpathMC+v_mc_filt.at(i);
	fbatch_mc_filt[i][iVAR2D] = TFile::Open(fname_filt.c_str());
	std::string fname_unfilt = fpathMC+v_mc_unfilt.at(i);
	fbatch_mc_unfilt[i][iVAR2D] = TFile::Open(fname_unfilt.c_str());
	
	TH2F *hf_bjet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(hname_bjet.c_str());
	TH2F *hf_cjet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(hname_cjet.c_str());
	TH2F *hf_ljet = (TH2F*)fbatch_mc_unfilt[i][iVAR2D]->Get(hname_ljet.c_str());
	
	TH2F *hf_cljet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(hname_cjet.c_str());
	TH2F *hf_bjet_untag = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(hname_bjet_untag.c_str());
	TH2F *hf_cjet_untag = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(hname_cjet_untag.c_str());
	
	if( i == 0 ) 
	  {
	     h_draw_bjet_2d[iVAR2D] = (TH2F*)hf_bjet->Clone(hname_bjet.c_str());
	     h_draw_cjet_2d[iVAR2D] = (TH2F*)hf_cjet->Clone(hname_cjet.c_str());
	     h_draw_ljet_2d[iVAR2D] = (TH2F*)hf_ljet->Clone(hname_ljet.c_str());
	     h_draw_bjet_untag_2d[iVAR2D] = (TH2F*)hf_bjet_untag->Clone(hname_bjet_untag.c_str());
	     h_draw_cjet_untag_2d[iVAR2D] = (TH2F*)hf_cjet_untag->Clone(hname_cjet_untag.c_str());
	  }	
	else 
	  {
	     h_draw_ljet_2d[iVAR2D]->Add(hf_ljet);
	     h_draw_cjet_2d[iVAR2D]->Add(hf_cjet);
	     h_draw_bjet_2d[iVAR2D]->Add(hf_bjet);
	     h_draw_bjet_untag_2d[iVAR2D]->Add(hf_bjet_untag);
	     h_draw_cjet_untag_2d[iVAR2D]->Add(hf_cjet_untag);
	  }

	std::string cname_bjet = "";
	std::string cname_cjet = "";
	std::string cname_ljet = "";
	std::string cname_bjet_untag = "";
	std::string cname_cjet_untag = "";
	
	for(int j=0;j<nsys;j++)
	  {		  
	     cname_bjet = hname_bjet + name_sys_low[j];
	     cname_cjet = hname_cjet + name_sys_low[j];
	     cname_ljet = hname_ljet + name_sys_low[j];
	     cname_bjet_untag = hname_bjet_untag + name_sys_low[j];
	     cname_cjet_untag = hname_cjet_untag + name_sys_low[j];
	     TH2F *hf_sys_low_bjet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(cname_bjet.c_str());
	     TH2F *hf_sys_low_cjet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(cname_cjet.c_str());
	     TH2F *hf_sys_low_ljet = (TH2F*)fbatch_mc_unfilt[i][iVAR2D]->Get(cname_ljet.c_str());
	     TH2F *hf_sys_low_bjet_untag = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(cname_bjet_untag.c_str());
	     TH2F *hf_sys_low_cjet_untag = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(cname_cjet_untag.c_str());
	     cname_bjet = cname_bjet + "_clone_2d";
	     cname_cjet = cname_cjet + "_clone_2d";
	     cname_ljet = cname_ljet + "_clone_2d";
	     cname_bjet_untag = cname_bjet_untag + "_clone_2d";
	     cname_cjet_untag = cname_cjet_untag + "_clone_2d";
	     if( i == 0 ) 
	       {
		  h_draw_bjet_sys_low_2d[j][iVAR2D] = (TH2F*)hf_sys_low_bjet->Clone(cname_bjet.c_str());
		  h_draw_cjet_sys_low_2d[j][iVAR2D] = (TH2F*)hf_sys_low_cjet->Clone(cname_cjet.c_str());
		  h_draw_ljet_sys_low_2d[j][iVAR2D] = (TH2F*)hf_sys_low_ljet->Clone(cname_ljet.c_str());
		  h_draw_bjet_untag_sys_low_2d[j][iVAR2D] = (TH2F*)hf_sys_low_bjet_untag->Clone(cname_bjet_untag.c_str());
		  h_draw_cjet_untag_sys_low_2d[j][iVAR2D] = (TH2F*)hf_sys_low_cjet_untag->Clone(cname_cjet_untag.c_str());
	       }
	     else 
	       {
		  h_draw_ljet_sys_low_2d[j][iVAR2D]->Add(hf_sys_low_ljet);
		  h_draw_cjet_sys_low_2d[j][iVAR2D]->Add(hf_sys_low_cjet);
		  h_draw_bjet_sys_low_2d[j][iVAR2D]->Add(hf_sys_low_bjet);
		  h_draw_cjet_untag_sys_low_2d[j][iVAR2D]->Add(hf_sys_low_cjet_untag);
		  h_draw_bjet_untag_sys_low_2d[j][iVAR2D]->Add(hf_sys_low_bjet_untag);
	       }		 
	     
	     cname_bjet = hname_bjet + name_sys_up[j];
	     cname_cjet = hname_cjet + name_sys_up[j];
	     cname_ljet = hname_ljet + name_sys_up[j];
	     cname_bjet_untag = hname_bjet_untag + name_sys_up[j];
	     cname_cjet_untag = hname_cjet_untag + name_sys_up[j];
	     TH2F *hf_sys_up_bjet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(cname_bjet.c_str());
	     TH2F *hf_sys_up_cjet = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(cname_cjet.c_str());
	     TH2F *hf_sys_up_ljet = (TH2F*)fbatch_mc_unfilt[i][iVAR2D]->Get(cname_ljet.c_str());
	     TH2F *hf_sys_up_bjet_untag = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(cname_bjet_untag.c_str());
	     TH2F *hf_sys_up_cjet_untag = (TH2F*)fbatch_mc_filt[i][iVAR2D]->Get(cname_cjet_untag.c_str());
	     cname_bjet = cname_bjet + "_clone_2d";
	     cname_cjet = cname_cjet + "_clone_2d";
	     cname_ljet = cname_ljet + "_clone_2d";
	     cname_bjet_untag = cname_bjet_untag + "_clone_2d";
	     cname_cjet_untag = cname_cjet_untag + "_clone_2d";
	     if( i == 0 ) 
	       {
		  h_draw_bjet_sys_up_2d[j][iVAR2D] = (TH2F*)hf_sys_up_bjet->Clone(cname_bjet.c_str());
		  h_draw_cjet_sys_up_2d[j][iVAR2D] = (TH2F*)hf_sys_up_cjet->Clone(cname_cjet.c_str());
		  h_draw_ljet_sys_up_2d[j][iVAR2D] = (TH2F*)hf_sys_up_ljet->Clone(cname_ljet.c_str());
		  h_draw_bjet_untag_sys_up_2d[j][iVAR2D] = (TH2F*)hf_sys_up_bjet_untag->Clone(cname_bjet_untag.c_str());
		  h_draw_cjet_untag_sys_up_2d[j][iVAR2D] = (TH2F*)hf_sys_up_cjet_untag->Clone(cname_cjet_untag.c_str());
	       }
	     else 
	       {
		  h_draw_ljet_sys_up_2d[j][iVAR2D]->Add(hf_sys_up_ljet);
		  h_draw_cjet_sys_up_2d[j][iVAR2D]->Add(hf_sys_up_cjet);
		  h_draw_bjet_sys_up_2d[j][iVAR2D]->Add(hf_sys_up_bjet);
		  h_draw_cjet_untag_sys_up_2d[j][iVAR2D]->Add(hf_sys_up_cjet_untag);
		  h_draw_bjet_untag_sys_up_2d[j][iVAR2D]->Add(hf_sys_up_bjet_untag);
	       }		  
	  }
     }
   
   for(int i=0;i<v_data.size();i++)
     {
	std::string fname = fpathData+v_data.at(i);
	fbatch_data[i][iVAR2D] = TFile::Open(fname.c_str());
	
	TH2F *hf_ajet = (TH2F*)fbatch_data[i][iVAR2D]->Get(hname_ajet.c_str());
	TH2F *hf_ljet_data = (TH2F*)fbatch_data[i][iVAR2D]->Get(hname_ljet_data.c_str());
	if( i == 0 ) 
	  {
	     h_draw_ajet_data_2d[iVAR2D] = (TH2F*)hf_ajet->Clone(hname_ajet.c_str());
	     h_draw_ljet_data_2d[iVAR2D] = (TH2F*)hf_ljet_data->Clone(hname_ljet_data.c_str());
	  }	
	else 
	  {
	     h_draw_ajet_data_2d[iVAR2D]->Add(hf_ajet);
	     h_draw_ljet_data_2d[iVAR2D]->Add(hf_ljet_data);
	  }

	std::string cname_ljet_data = "";
	
	for(int j=0;j<nsys;j++)
	  {		  
	     cname_ljet_data = hname_ljet_data + name_sys_low[j];
	     TH2F *hf_sys_low_ljet_data = (TH2F*)fbatch_data[i][iVAR2D]->Get(cname_ljet_data.c_str());
	     cname_ljet_data = cname_ljet_data + "_clone_2d";
	     if( i == 0 ) 
	       {
		  h_draw_ljet_data_sys_low_2d[j][iVAR2D] = (TH2F*)hf_sys_low_ljet_data->Clone(cname_ljet_data.c_str());
	       }
	     else 
	       {
		  h_draw_ljet_data_sys_low_2d[j][iVAR2D]->Add(hf_sys_low_ljet_data);
	       }		 
	     
	     cname_ljet_data = hname_ljet_data + name_sys_up[j];
	     TH2F *hf_sys_up_ljet_data = (TH2F*)fbatch_data[i][iVAR2D]->Get(cname_ljet_data.c_str());
	     cname_ljet_data = cname_ljet_data + "_clone_2d";
	     if( i == 0 ) 
	       {
		  h_draw_ljet_data_sys_up_2d[j][iVAR2D] = (TH2F*)hf_sys_up_ljet_data->Clone(cname_ljet_data.c_str());
	       }
	     else 
	       {
		  h_draw_ljet_data_sys_up_2d[j][iVAR2D]->Add(hf_sys_up_ljet_data);
	       }		  
	  }
     }   
   
   addbin2D(h_draw_bjet_2d[iVAR2D]);
   addbin2D(h_draw_cjet_2d[iVAR2D]);
   addbin2D(h_draw_ljet_2d[iVAR2D]);
   addbin2D(h_draw_ljet_data_2d[iVAR2D]);
   addbin2D(h_draw_cljet_2d[iVAR2D]);
   addbin2D(h_draw_bjet_untag_2d[iVAR2D]);
   addbin2D(h_draw_cjet_untag_2d[iVAR2D]);
   
   addbin2D(h_draw_ajet_data_2d[iVAR2D]);
   
   for(int j=0;j<nsys;j++)
     {	     
	addbin2D(h_draw_bjet_sys_low_2d[j][iVAR2D]);
	addbin2D(h_draw_bjet_sys_up_2d[j][iVAR2D]);
	
	addbin2D(h_draw_cjet_sys_low_2d[j][iVAR2D]);
	addbin2D(h_draw_cjet_sys_up_2d[j][iVAR2D]);
	
	addbin2D(h_draw_ljet_sys_low_2d[j][iVAR2D]);
	addbin2D(h_draw_ljet_sys_up_2d[j][iVAR2D]);

	addbin2D(h_draw_bjet_untag_sys_low_2d[j][iVAR2D]);
	addbin2D(h_draw_bjet_untag_sys_up_2d[j][iVAR2D]);
	
	addbin2D(h_draw_cjet_untag_sys_low_2d[j][iVAR2D]);
	addbin2D(h_draw_cjet_untag_sys_up_2d[j][iVAR2D]);
	
	addbin2D(h_draw_ljet_data_sys_low_2d[j][iVAR2D]);
	addbin2D(h_draw_ljet_data_sys_up_2d[j][iVAR2D]);
     }	
   
   h_draw_bjet_2d[iVAR2D] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
   h_draw_cjet_2d[iVAR2D] = (TH2F*)h_draw_cjet_2d[iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
   h_draw_ljet_2d[iVAR2D] = (TH2F*)h_draw_ljet_2d[iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
   h_draw_ljet_data_2d[iVAR2D] = (TH2F*)h_draw_ljet_data_2d[iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
   h_draw_bjet_untag_2d[iVAR2D] = (TH2F*)h_draw_bjet_untag_2d[iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
   h_draw_cjet_untag_2d[iVAR2D] = (TH2F*)h_draw_cjet_untag_2d[iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
   
   for(int j=0;j<nsys;j++)
     {		  	    
	h_draw_bjet_sys_low_2d[j][iVAR2D] = (TH2F*)h_draw_bjet_sys_low_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_cjet_sys_low_2d[j][iVAR2D] = (TH2F*)h_draw_cjet_sys_low_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_ljet_sys_low_2d[j][iVAR2D] = (TH2F*)h_draw_ljet_sys_low_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_ljet_data_sys_low_2d[j][iVAR2D] = (TH2F*)h_draw_ljet_data_sys_low_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_bjet_untag_sys_low_2d[j][iVAR2D] = (TH2F*)h_draw_bjet_untag_sys_low_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_cjet_untag_sys_low_2d[j][iVAR2D] = (TH2F*)h_draw_cjet_untag_sys_low_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	
	h_draw_bjet_sys_up_2d[j][iVAR2D] = (TH2F*)h_draw_bjet_sys_up_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_cjet_sys_up_2d[j][iVAR2D] = (TH2F*)h_draw_cjet_sys_up_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_ljet_sys_up_2d[j][iVAR2D] = (TH2F*)h_draw_ljet_sys_up_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_ljet_data_sys_up_2d[j][iVAR2D] = (TH2F*)h_draw_ljet_data_sys_up_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_bjet_untag_sys_up_2d[j][iVAR2D] = (TH2F*)h_draw_bjet_untag_sys_up_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
	h_draw_cjet_untag_sys_up_2d[j][iVAR2D] = (TH2F*)h_draw_cjet_untag_sys_up_2d[j][iVAR2D]->Rebin2D(nbm2d,nbm2d,"");
     }	     
   
   h_draw_ajet_data_2d[iVAR2D] = (TH2F*)h_draw_ajet_data_2d[iVAR2D]->Rebin2D(nbm2d,nbm2d,"");

   if( doSub )
     {	     
	// subtract MC b+c from ljet_data
	     
	h_draw_ljet_data_2d[iVAR2D]->Add(h_draw_bjet_untag_2d[iVAR2D],-1.);
	h_draw_ljet_data_2d[iVAR2D]->Add(h_draw_cjet_untag_2d[iVAR2D],-1.);

	for(int j=0;j<nsys;j++)	      	       
	  {		  
	     h_draw_ljet_data_sys_low_2d[j][iVAR2D]->Add(h_draw_bjet_untag_sys_low_2d[j][iVAR2D],-1.);
	     h_draw_ljet_data_sys_low_2d[j][iVAR2D]->Add(h_draw_cjet_untag_sys_low_2d[j][iVAR2D],-1.);
	     
	     h_draw_ljet_data_sys_up_2d[j][iVAR2D]->Add(h_draw_bjet_untag_sys_up_2d[j][iVAR2D],-1.);
	     h_draw_ljet_data_sys_up_2d[j][iVAR2D]->Add(h_draw_cjet_untag_sys_up_2d[j][iVAR2D],-1.);
	  }
     }	
   
   std::string h_bjet_comb_sys_up = hname_bjet + "_sys_up_comb_2d";
   std::string h_bjet_comb_sys_low = hname_bjet + "_sys_low_comb_2d";
   h_draw_bjet_sys_low_comb_2d[iVAR2D] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bjet_comb_sys_low.c_str());
   h_draw_bjet_sys_up_comb_2d[iVAR2D] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bjet_comb_sys_up.c_str());
   
   std::string h_cjet_comb_sys_up = hname_cjet + "_sys_up_comb_2d";
   std::string h_cjet_comb_sys_low = hname_cjet + "_sys_low_comb_2d";
   h_draw_cjet_sys_low_comb_2d[iVAR2D] = (TH2F*)h_draw_cjet_2d[iVAR2D]->Clone(h_cjet_comb_sys_low.c_str());
   h_draw_cjet_sys_up_comb_2d[iVAR2D] = (TH2F*)h_draw_cjet_2d[iVAR2D]->Clone(h_cjet_comb_sys_up.c_str());

   std::string h_bjet_untag_comb_sys_up = hname_bjet_untag + "_sys_up_comb_2d";
   std::string h_bjet_untag_comb_sys_low = hname_bjet_untag + "_sys_low_comb_2d";
   h_draw_bjet_untag_sys_low_comb_2d[iVAR2D] = (TH2F*)h_draw_bjet_untag_2d[iVAR2D]->Clone(h_bjet_untag_comb_sys_low.c_str());
   h_draw_bjet_untag_sys_up_comb_2d[iVAR2D] = (TH2F*)h_draw_bjet_untag_2d[iVAR2D]->Clone(h_bjet_untag_comb_sys_up.c_str());
   
   std::string h_cjet_untag_comb_sys_up = hname_cjet_untag + "_sys_up_comb_2d";
   std::string h_cjet_untag_comb_sys_low = hname_cjet_untag + "_sys_low_comb_2d";
   h_draw_cjet_untag_sys_low_comb_2d[iVAR2D] = (TH2F*)h_draw_cjet_untag_2d[iVAR2D]->Clone(h_cjet_untag_comb_sys_low.c_str());
   h_draw_cjet_untag_sys_up_comb_2d[iVAR2D] = (TH2F*)h_draw_cjet_untag_2d[iVAR2D]->Clone(h_cjet_untag_comb_sys_up.c_str());
   
   std::string h_ljet_comb_sys_up = hname_ljet + "_sys_up_comb_2d";
   std::string h_ljet_comb_sys_low = hname_ljet + "_sys_low_comb_2d";
   h_draw_ljet_sys_low_comb_2d[iVAR2D] = (TH2F*)h_draw_ljet_2d[iVAR2D]->Clone(h_ljet_comb_sys_low.c_str());
   h_draw_ljet_sys_up_comb_2d[iVAR2D] = (TH2F*)h_draw_ljet_2d[iVAR2D]->Clone(h_ljet_comb_sys_up.c_str());

   std::string h_ljet_data_comb_sys_up = hname_ljet_data + "_sys_up_comb_2d";
   std::string h_ljet_data_comb_sys_low = hname_ljet_data + "_sys_low_comb_2d";
   h_draw_ljet_data_sys_low_comb_2d[iVAR2D] = (TH2F*)h_draw_ljet_data_2d[iVAR2D]->Clone(h_ljet_data_comb_sys_low.c_str());
   h_draw_ljet_data_sys_up_comb_2d[iVAR2D] = (TH2F*)h_draw_ljet_data_2d[iVAR2D]->Clone(h_ljet_data_comb_sys_up.c_str());
   
   std::string h_bcljet_comb = hname_bjet + hname_cjet + hname_ljet + "_comb_2d";
   h_draw_bcljet_comb_2d[iVAR2D] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bcljet_comb.c_str());
   
   for(int isy=0;isy<nsys;isy++)
     {	     
	std::string h_bcljet_comb_sys_up = hname_bjet + hname_cjet + hname_ljet + "_sys_up_comb_2d" + name_sys_up[isy];
	std::string h_bcljet_comb_sys_low = hname_bjet + hname_cjet + hname_ljet + "_sys_low_comb_2d" + name_sys_low[isy];
	h_draw_bcljet_sys_low_comb_2d[iVAR2D*nsys+isy] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bcljet_comb_sys_low.c_str());
	h_draw_bcljet_sys_up_comb_2d[iVAR2D*nsys+isy] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bcljet_comb_sys_up.c_str());
     }	
   
   std::string h_bcljet_combSum_sys_up = hname_bjet + hname_cjet + hname_ljet + "_sys_up_comb_2d";
   std::string h_bcljet_combSum_sys_low = hname_bjet + hname_cjet + hname_ljet + "_sys_low_comb_2d";
   h_draw_bcljet_sys_low_combSum_2d[iVAR2D] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bcljet_combSum_sys_low.c_str());
   h_draw_bcljet_sys_up_combSum_2d[iVAR2D] = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone(h_bcljet_combSum_sys_up.c_str());
}
*/
std::vector<std::string> setTit(std::string var)
{
   std::vector<std::string> v;
   v.clear();
   
   std::string titX = "";
   std::string titY = "";
   std::string titZ = "";

   if( var == "h_j1_pt_" ||
       var == "h_j2_pt_" ||
       var == "h_j_pt_" ) 
     {titX = "P_{T} [TeV]";}

   if( var == "h_j1_JPRW_" ||
       var == "h_j2_JPRW_" ||
       var == "h_j_JPRW_" ||
       var == "h_j1_JP_" ||
       var == "h_j2_JP_" ||
       var == "h_j_JP_" )
     {titX = "JP discriminator";}
   
   if( var == "h_j1_vBTsv0p_" ||
       var == "h_j2_vBTsv0p_" ||
       var == "h_j_vBTsv0p_" ) 
     {titX = "B^{T}";}
   
   if( var == "h_j1_vPTsv0p_" ||
       var == "h_j2_vPTsv0p_" ||
       var == "h_j_vPTsv0p_" )
     {titX = "#Pi^{T}";}

   if( var == "h_j1_vBTsv0p_vs_vPTsv0p_" ||
       var == "h_j2_vBTsv0p_vs_vPTsv0p_" ||
       var == "h_j_vBTsv0p_vs_vPTsv0p_" )
     {titX = "#Pi^{T}";
	titY = "B^{T}";}
   
   if( var == "h_j1_d0SignJet1_" )
     {titX = "S_{d_{0}}(t_{1})";}

   if( var == "h_j1_d0SignJet2_" )
     {titX = "S_{d_{0}}(t_{2})";}

   if( var == "h_j1_d0SignJet3_" )
     {titX = "S_{d_{0}}(t_{3})";}

   if( var == "h_j1_d0SignJetMuonLoose_" )
     {titX = "S_{d_{0}}(#mu)";}

   if( var == "h_j1_d0SignJetMuonLoose_vs_muonLoosePt_" )
     {titX = "P_{T}(#mu) [GeV]";
	titY = "S_{d_{0}}(#mu)";}

   if( var == "h_j1_d0SignJet1_vs_d0SignJetMuonLoose_" )
     {titX = "S_{d_{0}}(#mu)";
	titY = "S_{d_{0}}(t_{1})";}

   if( var == "h_j1_d0SignJet2_vs_d0SignJetMuonLoose_" )
     {titX = "S_{d_{0}}(#mu)";
	titY = "S_{d_{0}}(t_{2})";}
   
   if( var == "h_j1_d0SignJet3_vs_d0SignJetMuonLoose_" )
     {titX = "S_{d_{0}}(#mu)";
	titY = "S_{d_{0}}(t_{3})";}

   if( var == "h_j1_d0SignJetMuonTight_" )
     {titX = "S_{d_{0}}(#mu)";}

   if( var == "h_j1_d0SignJetMuonTight_vs_muonTightPt_" )
     {titX = "P_{T}(#mu) [GeV]";
	titY = "S_{d_{0}}(#mu)";}

   if( var == "h_j1_d0SignJet1_vs_d0SignJetMuonTight_" )
     {titX = "S_{d_{0}}(#mu)";
	titY = "S_{d_{0}}(t_{1})";}

   if( var == "h_j1_d0SignJet2_vs_d0SignJetMuonTight_" )
     {titX = "S_{d_{0}}(#mu)";
	titY = "S_{d_{0}}(t_{2})";}
   
   if( var == "h_j1_d0SignJet3_vs_d0SignJetMuonTight_" )
     {titX = "S_{d_{0}}(#mu)";
	titY = "S_{d_{0}}(t_{3})";}
   
   if( var == "h_j1_d0SignJet1_vs_d0SignJet2_" )
     {titX = "S_{d_{0}}(t_{2})";
	titY = "S_{d_{0}}(t_{1})";}

   if( var == "h_j1_d0SignJet1_vs_d0SignJet3_" )
     {titX = "S_{d_{0}}(t_{3})";
	titY = "S_{d_{0}}(t_{1})";}

   if( var == "h_j1_d0SignJet2_vs_d0SignJet3_" )
     {titX = "S_{d_{0}}(t_{3})";
	titY = "S_{d_{0}}(t_{2})";}

   if( var == "h_j1_d0SignJet1_vs_JetFitterCOMBNN_" )
     {titX = "JetFitterCOMBNN";
	titY = "S_{d_{0}}(t_{1})";}

   if( var == "h_j1_d0SignJet2_vs_JetFitterCOMBNN_" )
     {titX = "JetFitterCOMBNN";
	titY = "S_{d_{0}}(t_{2})";}

   if( var == "h_j1_d0SignJet3_vs_JetFitterCOMBNN_" )
     {titX = "JetFitterCOMBNN";
	titY = "S_{d_{0}}(t_{3})";}

   if( var == "h_j1_d0SignJetMuonLoose_vs_JetFitterCOMBNN_" )
     {titX = "JetFitterCOMBNN";
	titY = "S_{d_{0}}(#mu)";}

   if( var == "h_j1_d0SignJet1_vs_Comb_" )
     {titX = "IP3D+SV1";
	titY = "S_{d_{0}}(t_{1})";}

   if( var == "h_j1_d0SignJet2_vs_Comb_" )
     {titX = "IP3D+SV1";
	titY = "S_{d_{0}}(t_{2})";}

   if( var == "h_j1_d0SignJet3_vs_Comb_" )
     {titX = "IP3D+SV1";
	titY = "S_{d_{0}}(t_{3})";}

   if( var == "h_j1_d0SignJetMuonLoose_vs_Comb_" )
     {titX = "IP3D+SV1";
	titY = "S_{d_{0}}(#mu)";}

   if( var == "h_j1_d0SignJetMuonTight_vs_Comb_" )
     {titX = "IP3D+SV1";
	titY = "S_{d_{0}}(#mu)";}
   
   if( var == "h_j1_d0SignJet1_vs_MV1_" )
     {titX = "MV1";
	titY = "S_{d_{0}}(t_{1})";}

   if( var == "h_j1_d0SignJet2_vs_MV1_" )
     {titX = "MV1";
	titY = "S_{d_{0}}(t_{2})";}

   if( var == "h_j1_d0SignJet3_vs_MV1_" )
     {titX = "MV1";
	titY = "S_{d_{0}}(t_{3})";}

   if( var == "h_j1_d0SignJetMuonLoose_vs_MV1_" )
     {titX = "MV1";
	titY = "S_{d_{0}}(#mu)";}

   if( var == "h_j1_d0SignJetMuonTight_vs_MV1_" )
     {titX = "MV1";
	titY = "S_{d_{0}}(#mu)";}
   
   if( var == "h_j1_d0SignJet1_vs_MV2_" )
     {titX = "MV2";
	titY = "S_{d_{0}}(t_{1})";}

   if( var == "h_j1_d0SignJet2_vs_MV2_" )
     {titX = "MV2";
	titY = "S_{d_{0}}(t_{2})";}

   if( var == "h_j1_d0SignJet3_vs_MV2_" )
     {titX = "MV2";
	titY = "S_{d_{0}}(t_{3})";}

   if( var == "h_j1_d0SignJetMuonLoose_vs_MV2_" )
     {titX = "MV2";
	titY = "S_{d_{0}}(#mu)";}

   if( var == "h_j1_d0SignJetMuonTight_vs_MV2_" )
     {titX = "MV2";
	titY = "S_{d_{0}}(#mu)";}
   
   if( var == "h_j1_d0SignJet1_vs_TrackCounting2D_" )
     {titX = "TrackCounting2D";
	titY = "S_{d_{0}}(t_{1})";}

   if( var == "h_j1_d0SignJet2_vs_TrackCounting2D_" )
     {titX = "TrackCounting2D";
	titY = "S_{d_{0}}(t_{2})";}

   if( var == "h_j1_d0SignJet3_vs_TrackCounting2D_" )
     {titX = "TrackCounting2D";
	titY = "S_{d_{0}}(t_{3})";}

   if( var == "h_j1_d0SignJetMuonLoose_vs_TrackCounting2D_" )
     {titX = "TrackCounting2D";
	titY = "S_{d_{0}}(#mu)";}

   if( var == "h_j1_d0SignJetMuonTight_vs_TrackCounting2D_" )
     {titX = "TrackCounting2D";
	titY = "S_{d_{0}}(#mu)";}
   
   if( var == "h_j1_d0SignJet1_vs_SV1_" )
     {titX = "SV1";
	titY = "S_{d_{0}}(t_{1})";}

   if( var == "h_j1_d0SignJet2_vs_SV1_" )
     {titX = "SV1";
	titY = "S_{d_{0}}(t_{2})";}

   if( var == "h_j1_d0SignJet3_vs_SV1_" )
     {titX = "SV1";
	titY = "S_{d_{0}}(t_{3})";}

   if( var == "h_j1_d0SignJetMuonLoose_vs_SV1_" )
     {titX = "SV1";
	titY = "S_{d_{0}}(#mu)";}

   if( var == "h_j1_d0SignJetMuonTight_vs_SV1_" )
     {titX = "SV1";
	titY = "S_{d_{0}}(#mu)";}
   
   if( var == "h_j1_d0SignJet1_vs_SV2_" )
     {titX = "SV2";
	titY = "S_{d_{0}}(t_{1})";}

   if( var == "h_j1_d0SignJet2_vs_SV2_" )
     {titX = "SV2";
	titY = "S_{d_{0}}(t_{2})";}

   if( var == "h_j1_d0SignJet3_vs_SV2_" )
     {titX = "SV2";
	titY = "S_{d_{0}}(t_{3})";}

   if( var == "h_j1_d0SignJetMuonLoose_vs_SV2_" )
     {titX = "SV2";
	titY = "S_{d_{0}}(#mu)";}

   if( var == "h_j1_d0SignJetMuonTight_vs_SV2_" )
     {titX = "SV2";
	titY = "S_{d_{0}}(#mu)";}
   
   if( var == "h_j1_d0SignJet1_vs_NewGbbNN_" )
     {titX = "NewGbbNN";
	titY = "S_{d_{0}}(t_{1})";}

   if( var == "h_j1_d0SignJet2_vs_NewGbbNN_" )
     {titX = "NewGbbNN";
	titY = "S_{d_{0}}(t_{2})";}

   if( var == "h_j1_d0SignJet3_vs_NewGbbNN_" )
     {titX = "NewGbbNN";
	titY = "S_{d_{0}}(t_{3})";}

   if( var == "h_j1_d0SignJetMuonLoose_vs_NewGbbNN_" )
     {titX = "NewGbbNN";
	titY = "S_{d_{0}}(#mu)";}

   if( var == "h_j1_d0SignJetMuonTight_vs_NewGbbNN_" )
     {titX = "NewGbbNN";
	titY = "S_{d_{0}}(#mu)";}
   
   v.push_back(titX);
   v.push_back(titY);
   v.push_back(titZ);
   
   return v;
}

void ATLASLabel(Double_t x,Double_t y,std::string text,Color_t color)
{
  TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
  l.SetNDC();
//  l.SetTextFont(72);
   l.SetTextFont(62);
  l.SetTextColor(color);

//   double delx = 0.115*696*gPad->GetWh()/(472*gPad->GetWw());
  double delx = 0.080*696*gPad->GetWh()/(472*gPad->GetWw());

  l.DrawLatex(x,y,"CMS");
  if (text.c_str()) {
    TLatex p; 
    p.SetNDC();
    p.SetTextFont(42);
    p.SetTextColor(color);
    p.DrawLatex(x+delx,y,text.c_str());
    //    p.DrawLatex(x,y,"#sqrt{s}=900GeV");
  }
}

double fnorm(TH1D *hnom,TH1D *hsys)
{   
   float s1 = 0.;
   float s2 = 0.;
   for(int ib0=1;ib0<hnom->GetXaxis()->GetNbins()+1;ib0++)
     {
	float b0 = hnom->GetBinContent(ib0);
	float b = hsys->GetBinContent(ib0);
	float e = b0-b;
	s1 += (e != 1e-10) ? b*b0/e/e : 0.;
	s2 += (e != 1e-10) ? b*b/e/e : 0.;
     }			    
   float f = (s2 > 0) ? s1/s2 : 0.;
   if( f > 0. )
     hsys->Scale(f);
   
   return f;
}

void plotFracSys(TH1D *hnom,TH1D *hsysDown,TH1D *hsysUp,std::string pname,std::string sname,int isys,std::string flav,bool onlyDraw)
{   
   TH1D *hsysDownf = (TH1D*)hnom->Clone("hsysDownf");
   TH1D *hsysUpf = (TH1D*)hnom->Clone("hsysUpf");

   TH1D *hsysDownf_cov = (TH1D*)hnom->Clone("hsysDownf_cov");
   TH1D *hsysUpf_cov = (TH1D*)hnom->Clone("hsysUpf_cov");
   
   std::string syslabel = "";
   if( sname == "" ) return;
   else if( sname == "_ntrk_low" ) syslabel = "N_{trk}";
   else if( sname == "_nseltrk_low" ) syslabel = "N_{trk}";
   else if( sname == "_pu_low" ) syslabel = "Pileup";
   else if( sname == "_gsplit_low" ) syslabel = "g split";
   else if( sname == "_bfrag_low" ) syslabel = "b frag";
   else if( sname == "_cdfrag_low" ) syslabel = "D #rightarrow #mu X";
   else if( sname == "_cfrag_low" ) syslabel = "c #rightarrow D";
   else if( sname == "_ksl_low" ) syslabel = "K_{S}^{0} (#Lambda)";
   else if( sname == "_ntrkgen_low" ) syslabel = "N_{trk}^{gen}";
   else if( sname == "_jes_low" ) syslabel = "JES";
   else if( sname == "_jer_low" ) syslabel = "JER";
   else if( sname == "_njet_low" ) syslabel = "N_{jet}";
   else if( sname == "_mupt_low" ) syslabel = "p_{T} (#mu)";
   else if( sname == "_jeta_low" ) syslabel = "#eta (jet)";
   else if( sname == "_pt_low" ) syslabel = "p_{T} (jet)";
   else std::cout << "Unknown systematics" << std::endl;
   
   int hnbins = hnom->GetXaxis()->GetNbins();
   for(int ib0=1;ib0<hnbins+1;ib0++)
     {
	float b0 = hnom->GetBinContent(ib0);
	float b0err = hnom->GetBinError(ib0);
	float bDown = hsysDown->GetBinContent(ib0);
	float bUp = hsysUp->GetBinContent(ib0);
	float bDown_cov = bDown;
	float bUp_cov = bUp;
	
	if( b0 > 0. && b0/b0err > 3. )
	  {	     
	     bDown = (b0-bDown)/b0;
	     bUp = (b0-bUp)/b0;
	     
	     bDown_cov = (b0-bDown_cov)/b0;
	     bUp_cov = (bUp_cov-b0)/b0;
	  }
	else
	  {
	     bDown = 0.;
	     bUp = 0.;

	     bDown_cov = 0.;
	     bUp_cov = 0.;
	  }
	
	hsysDownf->SetBinContent(ib0,1.+bDown);
	hsysDownf->SetBinError(ib0,0.);
	hsysUpf->SetBinContent(ib0,1.+bUp);
	hsysUpf->SetBinError(ib0,0.);

	hsysDownf_cov->SetBinContent(ib0,bDown_cov);
	hsysDownf_cov->SetBinError(ib0,0.);
	hsysUpf_cov->SetBinContent(ib0,bUp_cov);
	hsysUpf_cov->SetBinError(ib0,0.);
     }	

   if( !onlyDraw )
     {	
	double corr = bbCorr(hsysDownf_cov,hsysUpf_cov);
	if( flav == "all" ) 
	  {
	     covFactor[isys] = corr;
	  }	
   
	// FIXME: valid only for iVAR = 1 (has to be JP)
	if( iVARcur == 1 ) 
	  foutSys << hnamePT[iPTcur] << " " << hnameBTAG[iBTAGcur] << " " <<
	  name_sys_low[isys] << " " << flav << " " << std::setprecision(2) << corr << std::endl;
     }
   
   c1->Clear();
   c1->SetLogy(0);
   hsysDownf->SetFillStyle(0);
   hsysUpf->SetFillStyle(0);
   hsysDownf->SetLineColor(kBlue);
   hsysDownf->SetLineStyle(9);
   hsysDownf->SetLineWidth(2);
   hsysUpf->SetLineColor(kRed);
   hsysUpf->SetLineStyle(1);
   hsysUpf->SetLineWidth(2);
   hsysDownf->Draw("hist");
   hsysUpf->Draw("hist same");
   TLine *l1 = new TLine(0,1.0,2.5,1.0);
   l1->SetLineStyle(2);
   l1->SetLineWidth(1);
   l1->Draw("same");
   double ymin = 0.5;
   double ymax = 1.5;
   if( iPTcur == 1 )
     {	
/*	if( isys == 1 ) {ymin=0.4;ymax=1.6;} // ntrk
	if( isys == 2 ) {ymin=0.8;ymax=1.2;} // njet
	if( isys == 3 ) {ymin=0.92;ymax=1.08;} // mupt
	if( isys == 4 ) {ymin=0.92;ymax=1.08;} // jeta
	if( isys == 5 ) {ymin=0.97;ymax=1.03;} // pu
	if( isys == 6 ) {ymin=0.99;ymax=1.01;} // gsplit
	if( isys == 7 ) {ymin=0.85;ymax=1.15;} // bfrag
	if( isys == 8 ) {ymin=0.99;ymax=1.01;} // cdfrag
	if( isys == 9 ) {ymin=0.65;ymax=1.35;} // cfrag
	if( isys == 10 ) {ymin=0.8;ymax=1.2;} // ksl
	if( isys == 11 ) {ymin=0.85;ymax=1.15;} // ntrkgen
	if( isys == 12 ) {ymin=0.9;ymax=1.1;} // jes
	if( isys == 13 ) {ymin=0.95;ymax=1.05;} // jer
*/
	if( isys == 1 ) {ymin=0.4;ymax=1.6;} // ntrk
	if( isys == 2 ) {ymin=0.98;ymax=1.02;} // njet
	if( isys == 3 ) {ymin=0.99;ymax=1.01;} // mupt
	if( isys == 4 ) {ymin=0.98;ymax=1.02;} // jeta
	if( isys == 5 ) {ymin=0.97;ymax=1.03;} // pu
	if( isys == 6 ) {ymin=0.85;ymax=1.15;} // bfrag
	if( isys == 7 ) {ymin=0.9;ymax=1.1;} // jes
	if( isys == 8 ) {ymin=0.95;ymax=1.05;} // jer
     }
   else if( iPTcur == 3 )
     {	
	if( isys == 1 ) {ymin=0.4;ymax=1.6;} // ntrk
	if( isys == 2 ) {ymin=0.995;ymax=1.005;} // njet
	if( isys == 3 ) {ymin=0.99;ymax=1.01;} // mupt
	if( isys == 4 ) {ymin=0.95;ymax=1.05;} // jeta
	if( isys == 5 ) {ymin=0.97;ymax=1.03;} // pu
	if( isys == 6 ) {ymin=0.85;ymax=1.15;} // bfrag
	if( isys == 7 ) {ymin=0.95;ymax=1.05;} // jes
	if( isys == 8 ) {ymin=0.95;ymax=1.05;} // jer
     }
   else if( iPTcur == 8 )
     {
	if( isys == 1 ) {ymin=0.75;ymax=1.25;} // ntrk
	if( isys == 2 ) {ymin=0.97;ymax=1.03;} // njet
	if( isys == 3 ) {ymin=0.94;ymax=1.06;} // mupt
	if( isys == 4 ) {ymin=0.94;ymax=1.06;} // jeta
	if( isys == 5 ) {ymin=0.99;ymax=1.01;} // pu
	if( isys == 6 ) {ymin=0.7;ymax=1.3;} // gsplit
	if( isys == 7 ) {ymin=0.9;ymax=1.1;} // bfrag
	if( isys == 8 ) {ymin=0.98;ymax=1.02;} // cdfrag
	if( isys == 9 ) {ymin=0.8;ymax=1.2;} // cfrag
	if( isys == 10 ) {ymin=0.8;ymax=1.2;} // ksl
	if( isys == 11 ) {ymin=0.85;ymax=1.15;} // ntrkgen
	if( isys == 12 ) {ymin=0.97;ymax=1.03;} // jes
	if( isys == 13 ) {ymin=0.97;ymax=1.03;} // jer
     }
   else if( iPTcur == 15 )
     {
	if( isys == 1 ) {ymin=0.93;ymax=1.07;} // ntrk
	if( isys == 2 ) {ymin=0.98;ymax=1.02;} // njet
	if( isys == 3 ) {ymin=0.99;ymax=1.01;} // mupt
	if( isys == 4 ) {ymin=0.99;ymax=1.01;} // jeta
	if( isys == 5 ) {ymin=0.99;ymax=1.01;} // pu
	if( isys == 6 ) {ymin=0.5;ymax=1.5;} // gsplit
	if( isys == 7 ) {ymin=0.9;ymax=1.1;} // bfrag
	if( isys == 8 ) {ymin=0.98;ymax=1.02;} // cdfrag
	if( isys == 9 ) {ymin=0.9;ymax=1.1;} // cfrag
	if( isys == 10 ) {ymin=0.8;ymax=1.2;} // ksl
	if( isys == 11 ) {ymin=0.85;ymax=1.15;} // ntrkgen
	if( isys == 12 ) {ymin=0.96;ymax=1.04;} // jes
	if( isys == 13 ) {ymin=0.98;ymax=1.02;} // jer
     }   
   hsysDownf->GetYaxis()->SetRangeUser(ymin,ymax);
   hsysDownf->GetXaxis()->SetTitle("JP discriminator");
   hsysDownf->GetYaxis()->SetTitle("#sigma(A)/A");
   TLegend *legf = new TLegend(0.65,0.90,0.87,0.65);
   legf->SetHeader(syslabel.c_str());
   legf->SetFillColor(253);
   legf->SetBorderSize(0);   
   legf->AddEntry(hsysDownf,"- #sigma","l");
   legf->AddEntry(hsysUpf,"+ #sigma","l");
   legf->Draw();
   std::string picname = "pics/"+pname+".eps";
   c1->Print(picname.c_str());
   c1->Clear();
   
   delete hsysDownf;
   delete hsysUpf;
   delete hsysDownf_cov;
   delete hsysUpf_cov;
   delete l1;
   delete legf;
}

void plotFracSysNew(TH1D *hnom,TH1D *hsysDown,TH1D *hsysUp,std::string pname,std::string sname,int isys,bool dofac)
{   
   TH1D *hsysDownf = (TH1D*)hnom->Clone("hsysDownf");
   TH1D *hsysUpf = (TH1D*)hnom->Clone("hsysUpf");

   TH1D *hsysDownf_cov = (TH1D*)hnom->Clone("hsysDownf_cov");
   TH1D *hsysUpf_cov = (TH1D*)hnom->Clone("hsysUpf_cov");
   
   std::string syslabel = "";
   if( sname == "" ) return;
   else if( sname == "_ntrk_low" ) syslabel = "N_{trk}";
   else if( sname == "_nseltrk_low" ) syslabel = "N_{trk}";
   else if( sname == "_pu_low" ) syslabel = "Pileup";
   else if( sname == "_gsplit_low" ) syslabel = "g split";
   else if( sname == "_bfrag_low" ) syslabel = "b frag";
   else if( sname == "_cdfrag_low" ) syslabel = "D #rightarrow #mu X";
   else if( sname == "_cfrag_low" ) syslabel = "c #rightarrow D";
   else if( sname == "_ksl_low" ) syslabel = "K_{S}^{0} (#Lambda)";
   else if( sname == "_ntrkgen_low" ) syslabel = "N_{trk}^{gen}";
   else if( sname == "_jes_low" ) syslabel = "JES";
   else if( sname == "_jer_low" ) syslabel = "JER";
   else if( sname == "_njet_low" ) syslabel = "N_{jet}";
   else if( sname == "_mupt_low" ) syslabel = "p_{T} (#mu)";
   else if( sname == "_jeta_low" ) syslabel = "#eta (jet)";
   else if( sname == "_pt_low" ) syslabel = "p_{T} (jet)";
   else std::cout << "Unknown systematics: " << isys << " " << sname << std::endl;
   
   int hnbins = hnom->GetXaxis()->GetNbins();
   for(int ib0=1;ib0<hnbins+1;ib0++)
     {
	float b0 = hnom->GetBinContent(ib0);
	float b0err = hnom->GetBinError(ib0);
	float bDown = hsysDown->GetBinContent(ib0);
	float bUp = hsysUp->GetBinContent(ib0);
	float bDown_cov = bDown;
	float bUp_cov = bUp;
	
	if( b0 > 0. && b0/b0err > 3. )
	  {	     
	     bDown = (b0-bDown)/b0;
	     bUp = (b0-bUp)/b0;
	     
	     bDown_cov = (b0-bDown_cov)/b0;
	     bUp_cov = (bUp_cov-b0)/b0;
	  }
	else
	  {
	     bDown = 0.;
	     bUp = 0.;

	     bDown_cov = 0.;
	     bUp_cov = 0.;
	  }
	
	hsysDownf->SetBinContent(ib0,1.+bDown);
	hsysDownf->SetBinError(ib0,0.);
	hsysUpf->SetBinContent(ib0,1.+bUp);
	hsysUpf->SetBinError(ib0,0.);

	hsysDownf_cov->SetBinContent(ib0,bDown_cov);
	hsysDownf_cov->SetBinError(ib0,0.);
	hsysUpf_cov->SetBinContent(ib0,bUp_cov);
	hsysUpf_cov->SetBinError(ib0,0.);
     }	

   c1->Clear();
   c1->SetLogy(0);
   hsysDownf->SetFillStyle(0);
   hsysUpf->SetFillStyle(0);
   hsysDownf->SetLineColor(kBlue);
   hsysDownf->SetLineStyle(9);
   hsysDownf->SetLineWidth(2);
   hsysUpf->SetLineColor(kRed);
   hsysUpf->SetLineStyle(1);
   hsysUpf->SetLineWidth(2);
   hsysDownf->Draw("hist");
   hsysUpf->Draw("hist same");
   TLine *l1 = new TLine(0,1.0,2.5,1.0);
   l1->SetLineStyle(2);
   l1->SetLineWidth(1);
   l1->Draw("same");
   double ymin = 0.5;
   double ymax = 1.5;
   if( iPTcur == 1 )
     {	
/*	if( isys == 1 ) {ymin=0.4;ymax=1.6;} // ntrk
	if( isys == 2 ) {ymin=0.8;ymax=1.2;} // njet
	if( isys == 3 ) {ymin=0.92;ymax=1.08;} // mupt
	if( isys == 4 ) {ymin=0.92;ymax=1.08;} // jeta
	if( isys == 5 ) {ymin=0.97;ymax=1.03;} // pu
	if( isys == 6 ) {ymin=0.99;ymax=1.01;} // gsplit
	if( isys == 7 ) {ymin=0.85;ymax=1.15;} // bfrag
	if( isys == 8 ) {ymin=0.99;ymax=1.01;} // cdfrag
	if( isys == 9 ) {ymin=0.65;ymax=1.35;} // cfrag
	if( isys == 10 ) {ymin=0.8;ymax=1.2;} // ksl
	if( isys == 11 ) {ymin=0.85;ymax=1.15;} // ntrkgen
	if( isys == 12 ) {ymin=0.9;ymax=1.1;} // jes
	if( isys == 13 ) {ymin=0.95;ymax=1.05;} // jer
*/
	if( isys == 1 ) {ymin=0.4;ymax=1.6;} // ntrk
	if( isys == 2 ) {ymin=0.98;ymax=1.02;} // njet
	if( isys == 3 ) {ymin=0.99;ymax=1.01;} // mupt
	if( isys == 4 ) {ymin=0.98;ymax=1.02;} // jeta
	if( isys == 5 ) {ymin=0.97;ymax=1.03;} // pu
	if( isys == 6 ) {ymin=0.85;ymax=1.15;} // bfrag
	if( isys == 7 ) {ymin=0.9;ymax=1.1;} // jes
	if( isys == 8 ) {ymin=0.95;ymax=1.05;} // jer
     }
   else if( iPTcur == 3 )
     {	
	if( isys == 1 ) {ymin=0.4;ymax=1.6;} // ntrk
	if( isys == 2 ) {ymin=0.995;ymax=1.005;} // njet
	if( isys == 3 ) {ymin=0.99;ymax=1.01;} // mupt
	if( isys == 4 ) {ymin=0.95;ymax=1.05;} // jeta
	if( isys == 5 ) {ymin=0.97;ymax=1.03;} // pu
	if( isys == 6 ) {ymin=0.85;ymax=1.15;} // bfrag
	if( isys == 7 ) {ymin=0.95;ymax=1.05;} // jes
	if( isys == 8 ) {ymin=0.95;ymax=1.05;} // jer
     }
   else if( iPTcur == 8 )
     {
	if( isys == 1 ) {ymin=0.75;ymax=1.25;} // ntrk
	if( isys == 2 ) {ymin=0.97;ymax=1.03;} // njet
	if( isys == 3 ) {ymin=0.94;ymax=1.06;} // mupt
	if( isys == 4 ) {ymin=0.94;ymax=1.06;} // jeta
	if( isys == 5 ) {ymin=0.99;ymax=1.01;} // pu
	if( isys == 6 ) {ymin=0.7;ymax=1.3;} // gsplit
	if( isys == 7 ) {ymin=0.9;ymax=1.1;} // bfrag
	if( isys == 8 ) {ymin=0.98;ymax=1.02;} // cdfrag
	if( isys == 9 ) {ymin=0.8;ymax=1.2;} // cfrag
	if( isys == 10 ) {ymin=0.8;ymax=1.2;} // ksl
	if( isys == 11 ) {ymin=0.85;ymax=1.15;} // ntrkgen
	if( isys == 12 ) {ymin=0.97;ymax=1.03;} // jes
	if( isys == 13 ) {ymin=0.97;ymax=1.03;} // jer
     }
   else if( iPTcur == 15 )
     {
	if( isys == 1 ) {ymin=0.93;ymax=1.07;} // ntrk
	if( isys == 2 ) {ymin=0.98;ymax=1.02;} // njet
	if( isys == 3 ) {ymin=0.99;ymax=1.01;} // mupt
	if( isys == 4 ) {ymin=0.99;ymax=1.01;} // jeta
	if( isys == 5 ) {ymin=0.99;ymax=1.01;} // pu
	if( isys == 6 ) {ymin=0.5;ymax=1.5;} // gsplit
	if( isys == 7 ) {ymin=0.9;ymax=1.1;} // bfrag
	if( isys == 8 ) {ymin=0.98;ymax=1.02;} // cdfrag
	if( isys == 9 ) {ymin=0.9;ymax=1.1;} // cfrag
	if( isys == 10 ) {ymin=0.8;ymax=1.2;} // ksl
	if( isys == 11 ) {ymin=0.85;ymax=1.15;} // ntrkgen
	if( isys == 12 ) {ymin=0.96;ymax=1.04;} // jes
	if( isys == 13 ) {ymin=0.98;ymax=1.02;} // jer
     }   
   hsysDownf->GetYaxis()->SetRangeUser(ymin,ymax);
   hsysDownf->GetXaxis()->SetTitle("JP discriminator");
   hsysDownf->GetYaxis()->SetTitle("#sigma(A)/A");
   TLegend *legf = new TLegend(0.65,0.90,0.87,0.65);
   legf->SetHeader(syslabel.c_str());
   legf->SetFillColor(253);
   legf->SetBorderSize(0);   
   legf->AddEntry(hsysDownf,"- #sigma","l");
   legf->AddEntry(hsysUpf,"+ #sigma","l");
   legf->Draw();
   std::string picname = "pics/"+pname+"_sym.eps";
   c1->Print(picname.c_str());
   c1->Clear();

   if( dofac )
     {	
	int nBins = hnom->GetXaxis()->GetNbins();
	TH1D *h_binFactor = (TH1D*)hnom->Clone("h_binFactor");
	h_binFactor->Clear();
	for(int i=1;i<=nBins;i++)
	  {
	     h_binFactor->SetBinContent(i,binFactor[isys][i]);
	  }   
	h_binFactor->Draw("hist");
	h_binFactor->SetMaximum(1.1);
	picname = "pics/"+pname+"_binFactor.eps";
	c1->Print(picname.c_str());	
	delete h_binFactor;
     }   
   
   delete hsysDownf;
   delete hsysUpf;
   delete hsysDownf_cov;
   delete hsysUpf_cov;
   delete l1;
   delete legf;
}

double bbCorr(TH1D *hsysDown,TH1D *hsysUp)
{
   double nbins = hsysDown->GetXaxis()->GetNbins();
   
   std::vector<int> bb;
   bb.clear();
   
   for(int ib=1;ib<=nbins;ib++)
     {
	double v1 = hsysDown->GetBinContent(ib);
	double v2 = hsysUp->GetBinContent(ib);
	
	if( v1 != 0 || v2 != 0 ) bb.push_back(ib);
     }   
   
   int sz = bb.size();
         
   double rho = 0.;

   if( sz < 2 ) return 1.;
   
   for(int ib1=1;ib1<=sz-1;ib1++)
     {
	for(int ib2=ib1+1;ib2<=sz;ib2++)
	  {	     
	     int id1 = bb[ib1-1];
	     int id2 = bb[ib2-1];
	     
	     double si_Down = hsysDown->GetBinContent(id1);
	     double sj_Down = hsysDown->GetBinContent(id2);
	     
	     double si_Up = hsysUp->GetBinContent(id1);
	     double sj_Up = hsysUp->GetBinContent(id2);
	     
	     double rhoij = (si_Down*sj_Down + si_Up*sj_Up);
	     double norm1 = sqrt(si_Down*si_Down+si_Up*si_Up);
	     double norm2 = sqrt(sj_Down*sj_Down+sj_Up*sj_Up);
	     if( norm1 > 0 && norm2 > 0 ) rhoij /= (norm1*norm2);
	     else rhoij = 0.;	     
	     
	     rho += fabs(rhoij);
	  }
     }   
   
   rho /= (sz*(sz-1)/2);
   
   return rho;
}

#endif
