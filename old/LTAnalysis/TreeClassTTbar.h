//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Feb  2 09:43:20 2014 by ROOT version 5.32/00
// from TTree ttree/ttree
// found on file: TrackTree_9_1_4Z3.root
//////////////////////////////////////////////////////////

#ifndef TreeClassTTbar_h
#define TreeClassTTbar_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <vector>
#include <iostream>
#include <fstream>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxTrack = 1;

using namespace std;

namespace LTANA
{
   
class TreeClassTTbar {
public :
   TChain          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           BitTrigger;
   Int_t           nJet;
   Int_t           Run;
   Int_t           Evt;
   Int_t           LumiBlock;
   Int_t           nPV;
   Float_t         PVz;
   Float_t         pthat;
   Float_t         PVzSim;
   Int_t           nPUtrue;
   Int_t           nPU;
   Int_t           ttbar_chan;
   Float_t         lepton1_pT;
   Float_t         lepton1_eta;
   Float_t         lepton1_phi;
   Float_t         lepton2_pT;
   Float_t         lepton2_eta;
   Float_t         lepton2_phi;
   Float_t         met;
   Float_t         mll;
   Int_t           trig_ttbar;
   Int_t           nTrack;
   Float_t         Track_dxy[500];   //[nTrack]
   Float_t         Track_dz[500];   //[nTrack]
   Float_t         Track_zIP[500];   //[nTrack]
   Float_t         Track_length[500];   //[nTrack]
   Float_t         Track_dist[500];   //[nTrack]
   Float_t         Track_IP2D[500];   //[nTrack]
   Float_t         Track_IP2Dsig[500];   //[nTrack]
   Float_t         Track_IP2Derr[500];   //[nTrack]
   Float_t         Track_IP[500];   //[nTrack]
   Float_t         Track_IPsig[500];   //[nTrack]
   Float_t         Track_IPerr[500];   //[nTrack]
   Float_t         Track_Proba[500];   //[nTrack]
   Float_t         Track_p[500];   //[nTrack]
   Float_t         Track_pt[500];   //[nTrack]
   Float_t         Track_eta[500];   //[nTrack]
   Float_t         Track_phi[500];   //[nTrack]
   Float_t         Track_chi2[500];   //[nTrack]
   Int_t           Track_charge[500];   //[nTrack]
   Int_t           Track_history[500];   //[nTrack]
   Int_t           Track_nHitStrip[500];   //[nTrack]
   Int_t           Track_nHitPixel[500];   //[nTrack]
   Int_t           Track_nHitAll[500];   //[nTrack]
   Int_t           Track_nHitTIB[500];   //[nTrack]
   Int_t           Track_nHitTID[500];   //[nTrack]
   Int_t           Track_nHitTOB[500];   //[nTrack]
   Int_t           Track_nHitTEC[500];   //[nTrack]
   Int_t           Track_nHitPXB[500];   //[nTrack]
   Int_t           Track_nHitPXF[500];   //[nTrack]
   Int_t           Track_isHitL1[500];   //[nTrack]
   Int_t           Track_PV[500];   //[nTrack]
   Int_t           Track_SV[500];   //[nTrack]
   Float_t         Track_PVweight[500];   //[nTrack]
   Float_t         Track_SVweight[500];   //[nTrack]
   Int_t           Track_isfromSV[500];   //[nTrack]
   Int_t           Track_category[500];   //[nTrack]
   Float_t         PV_x[50];   //[nPV]
   Float_t         PV_y[50];   //[nPV]
   Float_t         PV_z[50];   //[nPV]
   Float_t         PV_ex[50];   //[nPV]
   Float_t         PV_ey[50];   //[nPV]
   Float_t         PV_ez[50];   //[nPV]
   Float_t         PV_chi2[50];   //[nPV]
   Float_t         PV_ndf[50];   //[nPV]
   Int_t           PV_isgood[50];   //[nPV]
   Int_t           PV_isfake[50];   //[nPV]
   Int_t           nSV;
   Float_t         SV_x[50];   //[nSV]
   Float_t         SV_y[50];   //[nSV]
   Float_t         SV_z[50];   //[nSV]
   Float_t         SV_ex[50];   //[nSV]
   Float_t         SV_ey[50];   //[nSV]
   Float_t         SV_ez[50];   //[nSV]
   Float_t         SV_chi2[50];   //[nSV]
   Float_t         SV_ndf[50];   //[nSV]
   Float_t         SV_flight[50];   //[nSV]
   Float_t         SV_flightErr[50];   //[nSV]
   Float_t         SV_deltaR_jet[50];   //[nSV]
   Float_t         SV_deltaR_sum_jet[50];   //[nSV]
   Float_t         SV_deltaR_sum_dir[50];   //[nSV]
   Float_t         SV_energy_ratio[50];   //[nSV]
   Float_t         SV_aboveC[50];   //[nSV]
   Float_t         SV_vtx_pt[50];   //[nSV]
   Float_t         SV_flight2D[50];   //[nSV]
   Float_t         SV_flight2DErr[50];   //[nSV]
   Float_t         SV_totCharge[50];   //[nSV]
   Float_t         SV_vtxDistJetAxis[50];   //[nSV]
   Int_t           SV_nTrk[50];   //[nSV]
   Int_t           SV_nTrk_firstVxt[50];   //[nSV]
   Float_t         SV_mass[50];   //[nSV]
   Float_t         SV_vtx_eta[50];   //[nSV]
   Float_t         SV_vtx_phi[50];   //[nSV]
   Float_t         Jet_pt[50];   //[nJet]
   Float_t         Jet_genpt[50];   //[nJet]
   Float_t         Jet_residual[50];   //[nJet]
   Float_t         Jet_jes[50];   //[nJet]
   Float_t         Jet_eta[50];   //[nJet]
   Float_t         Jet_phi[50];   //[nJet]
   Int_t           Jet_ntracks[50];   //[nJet]
   Int_t           Jet_flavour[50];   //[nJet]
   Float_t         Jet_Ip2N[50];   //[nJet]
   Float_t         Jet_Ip2P[50];   //[nJet]
   Float_t         Jet_Ip3N[50];   //[nJet]
   Float_t         Jet_Ip3P[50];   //[nJet]
   Float_t         Jet_ProbaN[50];   //[nJet]
   Float_t         Jet_ProbaP[50];   //[nJet]
   Float_t         Jet_BprobN[50];   //[nJet]
   Float_t         Jet_BprobP[50];   //[nJet]
   Float_t         Jet_SvxN[50];   //[nJet]
   Float_t         Jet_Svx[50];   //[nJet]
   Float_t         Jet_SvxNHP[50];   //[nJet]
   Float_t         Jet_SvxHP[50];   //[nJet]
   Float_t         Jet_SvxMass[50];   //[nJet]
   Float_t         Jet_CombSvxN[50];   //[nJet]
   Float_t         Jet_CombSvxP[50];   //[nJet]
   Float_t         Jet_CombSvx[50];   //[nJet]
   Float_t         Jet_RetCombSvxN[50];   //[nJet]
   Float_t         Jet_RetCombSvxP[50];   //[nJet]
   Float_t         Jet_RetCombSvx[50];   //[nJet]
   Float_t         Jet_CombCSVJP_N[50];   //[nJet]
   Float_t         Jet_CombCSVJP_P[50];   //[nJet]
   Float_t         Jet_CombCSVJP[50];   //[nJet]
   Float_t         Jet_CombCSVSL_N[50];   //[nJet]
   Float_t         Jet_CombCSVSL_P[50];   //[nJet]
   Float_t         Jet_CombCSVSL[50];   //[nJet]
   Float_t         Jet_CombCSVJPSL_N[50];   //[nJet]
   Float_t         Jet_CombCSVJPSL_P[50];   //[nJet]
   Float_t         Jet_CombCSVJPSL[50];   //[nJet]
   Float_t         Jet_SimpIVF_HP[50];   //[nJet]
   Float_t         Jet_SimpIVF_HE[50];   //[nJet]
   Float_t         Jet_DoubIVF_HE[50];   //[nJet]
   Float_t         Jet_CombIVF[50];   //[nJet]
   Float_t         Jet_CombIVF_P[50];   //[nJet]
   Float_t         Jet_SoftMuN[50];   //[nJet]
   Float_t         Jet_SoftMuP[50];   //[nJet]
   Float_t         Jet_SoftMu[50];   //[nJet]
   Float_t         Jet_SoftElN[50];   //[nJet]
   Float_t         Jet_SoftElP[50];   //[nJet]
   Float_t         Jet_SoftEl[50];   //[nJet]
   Int_t           Jet_hist1[50];   //[nJet]
   Int_t           Jet_hist2[50];   //[nJet]
   Int_t           Jet_hist3[50];   //[nJet]
   Int_t           Jet_histJet[50];   //[nJet]
   Int_t           Jet_histSvx[50];   //[nJet]
   Int_t           Jet_nFirstTrack[50];   //[nJet]
   Int_t           Jet_nLastTrack[50];   //[nJet]
   Int_t           Jet_nFirstSV[50];   //[nJet]
   Int_t           Jet_nLastSV[50];   //[nJet]
   Int_t           Jet_SV_multi[50];   //[nJet]
   Int_t           Jet_nFirstTrkInc[50];   //[nJet]
   Int_t           Jet_nLastTrkInc[50];   //[nJet]
   Int_t           Jet_VtxCat[50];   //[nJet]
   Int_t           nMuon;
   Int_t           Muon_IdxJet[50];   //[nMuon]
   Int_t           Muon_nMuHit[50];   //[nMuon]
   Int_t           Muon_nTkHit[50];   //[nMuon]
   Int_t           Muon_nPixHit[50];   //[nMuon]
   Int_t           Muon_nOutHit[50];   //[nMuon]
   Int_t           Muon_isGlobal[50];   //[nMuon]
   Int_t           Muon_nMatched[50];   //[nMuon]
   Float_t         Muon_chi2[50];   //[nMuon]
   Float_t         Muon_chi2Tk[50];   //[nMuon]
   Float_t         Muon_pt[50];   //[nMuon]
   Float_t         Muon_eta[50];   //[nMuon]
   Float_t         Muon_phi[50];   //[nMuon]
   Float_t         Muon_ptrel[50];   //[nMuon]
   Float_t         Muon_vz[50];   //[nMuon]
   Int_t           Muon_hist[50];   //[nMuon]
   Float_t         Muon_IPsig[50];   //[nMuon]
   Float_t         Muon_IP[50];   //[nMuon]
   Float_t         Muon_IP2Dsig[50];   //[nMuon]
   Float_t         Muon_IP2D[50];   //[nMuon]
   Float_t         Muon_Proba[50];   //[nMuon]
   Float_t         Muon_deltaR[50];   //[nMuon]
   Float_t         Muon_ratio[50];   //[nMuon]
   Int_t           nPFElectron;
   Int_t           PFElectron_IdxJet[50];   //[nPFElectron]
   Float_t         PFElectron_pt[50];   //[nPFElectron]
   Float_t         PFElectron_eta[50];   //[nPFElectron]
   Float_t         PFElectron_phi[50];   //[nPFElectron]
   Float_t         PFElectron_ptrel[50];   //[nPFElectron]
   Float_t         PFElectron_deltaR[50];   //[nPFElectron]
   Float_t         PFElectron_ratio[50];   //[nPFElectron]
   Float_t         PFElectron_ratioRel[50];   //[nPFElectron]
   Float_t         PFElectron_IPsig[50];   //[nPFElectron]
   Int_t           nPFMuon;
   Int_t           PFMuon_IdxJet[50];   //[nPFMuon]
   Float_t         PFMuon_pt[50];   //[nPFMuon]
   Float_t         PFMuon_eta[50];   //[nPFMuon]
   Float_t         PFMuon_phi[50];   //[nPFMuon]
   Float_t         PFMuon_ptrel[50];   //[nPFMuon]
   Float_t         PFMuon_deltaR[50];   //[nPFMuon]
   Float_t         PFMuon_ratio[50];   //[nPFMuon]
   Float_t         PFMuon_ratioRel[50];   //[nPFMuon]
   Float_t         PFMuon_IPsig[50];   //[nPFMuon]
   Int_t           PFMuon_GoodQuality[50];   //[nPFMuon]
   Int_t           nTrkInc;
   Float_t         TrkInc_pt[50];   //[nTrkInc]
   Float_t         TrkInc_eta[50];   //[nTrkInc]
   Float_t         TrkInc_phi[50];   //[nTrkInc]
   Float_t         TrkInc_ptrel[50];   //[nTrkInc]
   Float_t         TrkInc_IPsig[50];   //[nTrkInc]
   Float_t         TrkInc_IP[50];   //[nTrkInc]
   Int_t           nCFromGSplit;
   Float_t         cFromGSplit_pT[50];   //[nCFromGSplit]
   Float_t         cFromGSplit_eta[50];   //[nCFromGSplit]
   Float_t         cFromGSplit_phi[50];   //[nCFromGSplit]
   Int_t           nBFromGSplit;
   Float_t         bFromGSplit_pT[50];   //[nBFromGSplit]
   Float_t         bFromGSplit_eta[50];   //[nBFromGSplit]
   Float_t         bFromGSplit_phi[50];   //[nBFromGSplit]
   Float_t         mcweight;
   Int_t           nBHadrons;
   Float_t         BHadron_pT[50];   //[nBHadrons]
   Float_t         BHadron_eta[50];   //[nBHadrons]
   Float_t         BHadron_phi[50];   //[nBHadrons]
   Float_t         BHadron_mass[50];   //[nBHadrons]
   Int_t           BHadron_pdgID[50];   //[nBHadrons]
   Int_t           nGenlep;
   Float_t         Genlep_pT[50];   //[nGenlep]
   Float_t         Genlep_eta[50];   //[nGenlep]
   Float_t         Genlep_phi[50];   //[nGenlep]
   Int_t           Genlep_pdgID[50];   //[nGenlep]
   Int_t           Genlep_mother[50];   //[nGenlep]
   Int_t           nGenquark;
   Float_t         Genquark_pT[50];   //[nGenquark]
   Float_t         Genquark_eta[50];   //[nGenquark]
   Float_t         Genquark_phi[50];   //[nGenquark]
   Int_t           Genquark_pdgID[50];   //[nGenquark]
   Int_t           Genquark_mother[50];   //[nGenquark]

   // List of branches
   TBranch        *b_BitTrigger;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Run;   //!
   TBranch        *b_Evt;   //!
   TBranch        *b_LumiBlock;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_pthat;   //!
   TBranch        *b_PVzSim;   //!
   TBranch        *b_nPUtrue;   //!
   TBranch        *b_nPU;   //!
   TBranch        *b_ttbar_chan;   //!
   TBranch        *b_lepton1_pT;   //!
   TBranch        *b_lepton1_eta;   //!
   TBranch        *b_lepton1_phi;   //!
   TBranch        *b_lepton2_pT;   //!
   TBranch        *b_lepton2_eta;   //!
   TBranch        *b_lepton2_phi;   //!
   TBranch        *b_met;   //!
   TBranch        *b_mll;   //!
   TBranch        *b_trig_ttbar;   //!
   TBranch        *b_nTrack;   //!
   TBranch        *b_Track_dxy;   //!
   TBranch        *b_Track_dz;   //!
   TBranch        *b_Track_zIP;   //!
   TBranch        *b_Track_length;   //!
   TBranch        *b_Track_dist;   //!
   TBranch        *b_Track_IP2D;   //!
   TBranch        *b_Track_IP2Dsig;   //!
   TBranch        *b_Track_IP2Derr;   //!
   TBranch        *b_Track_IP;   //!
   TBranch        *b_Track_IPsig;   //!
   TBranch        *b_Track_IPerr;   //!
   TBranch        *b_Track_Proba;   //!
   TBranch        *b_Track_p;   //!
   TBranch        *b_Track_pt;   //!
   TBranch        *b_Track_eta;   //!
   TBranch        *b_Track_phi;   //!
   TBranch        *b_Track_chi2;   //!
   TBranch        *b_Track_charge;   //!
   TBranch        *b_Track_history;   //!
   TBranch        *b_Track_nHitStrip;   //!
   TBranch        *b_Track_nHitPixel;   //!
   TBranch        *b_Track_nHitAll;   //!
   TBranch        *b_Track_nHitTIB;   //!
   TBranch        *b_Track_nHitTID;   //!
   TBranch        *b_Track_nHitTOB;   //!
   TBranch        *b_Track_nHitTEC;   //!
   TBranch        *b_Track_nHitPXB;   //!
   TBranch        *b_Track_nHitPXF;   //!
   TBranch        *b_Track_isHitL1;   //!
   TBranch        *b_Track_PV;   //!
   TBranch        *b_Track_SV;   //!
   TBranch        *b_Track_PVweight;   //!
   TBranch        *b_Track_SVweight;   //!
   TBranch        *b_Track_isfromSV;   //!
   TBranch        *b_Track_category;   //!
   TBranch        *b_PV_x;   //!
   TBranch        *b_PV_y;   //!
   TBranch        *b_PV_z;   //!
   TBranch        *b_PV_ex;   //!
   TBranch        *b_PV_ey;   //!
   TBranch        *b_PV_ez;   //!
   TBranch        *b_PV_chi2;   //!
   TBranch        *b_PV_ndf;   //!
   TBranch        *b_PV_isgood;   //!
   TBranch        *b_PV_isfake;   //!
   TBranch        *b_nSV;   //!
   TBranch        *b_SV_x;   //!
   TBranch        *b_SV_y;   //!
   TBranch        *b_SV_z;   //!
   TBranch        *b_SV_ex;   //!
   TBranch        *b_SV_ey;   //!
   TBranch        *b_SV_ez;   //!
   TBranch        *b_SV_chi2;   //!
   TBranch        *b_SV_ndf;   //!
   TBranch        *b_SV_flight;   //!
   TBranch        *b_SV_flightErr;   //!
   TBranch        *b_SV_deltaR_jet;   //!
   TBranch        *b_SV_deltaR_sum_jet;   //!
   TBranch        *b_SV_deltaR_sum_dir;   //!
   TBranch        *b_SV_energy_ratio;   //!
   TBranch        *b_SV_aboveC;   //!
   TBranch        *b_SV_vtx_pt;   //!
   TBranch        *b_SV_flight2D;   //!
   TBranch        *b_SV_flight2DErr;   //!
   TBranch        *b_SV_totCharge;   //!
   TBranch        *b_SV_vtxDistJetAxis;   //!
   TBranch        *b_SV_nTrk;   //!
   TBranch        *b_SV_nTrk_firstVxt;   //!
   TBranch        *b_SV_mass;   //!
   TBranch        *b_SV_vtx_eta;   //!
   TBranch        *b_SV_vtx_phi;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_genpt;   //!
   TBranch        *b_Jet_residual;   //!
   TBranch        *b_Jet_jes;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_ntracks;   //!
   TBranch        *b_Jet_flavour;   //!
   TBranch        *b_Jet_Ip2N;   //!
   TBranch        *b_Jet_Ip2P;   //!
   TBranch        *b_Jet_Ip3N;   //!
   TBranch        *b_Jet_Ip3P;   //!
   TBranch        *b_Jet_ProbaN;   //!
   TBranch        *b_Jet_ProbaP;   //!
   TBranch        *b_Jet_BprobN;   //!
   TBranch        *b_Jet_BprobP;   //!
   TBranch        *b_Jet_SvxN;   //!
   TBranch        *b_Jet_Svx;   //!
   TBranch        *b_Jet_SvxNHP;   //!
   TBranch        *b_Jet_SvxHP;   //!
   TBranch        *b_Jet_SvxMass;   //!
   TBranch        *b_Jet_CombSvxN;   //!
   TBranch        *b_Jet_CombSvxP;   //!
   TBranch        *b_Jet_CombSvx;   //!
   TBranch        *b_Jet_RetCombSvxN;   //!
   TBranch        *b_Jet_RetCombSvxP;   //!
   TBranch        *b_Jet_RetCombSvx;   //!
   TBranch        *b_Jet_CombCSVJP_N;   //!
   TBranch        *b_Jet_CombCSVJP_P;   //!
   TBranch        *b_Jet_CombCSVJP;   //!
   TBranch        *b_Jet_CombCSVSL_N;   //!
   TBranch        *b_Jet_CombCSVSL_P;   //!
   TBranch        *b_Jet_CombCSVSL;   //!
   TBranch        *b_Jet_CombCSVJPSL_N;   //!
   TBranch        *b_Jet_CombCSVJPSL_P;   //!
   TBranch        *b_Jet_CombCSVJPSL;   //!
   TBranch        *b_Jet_SimpIVF_HP;   //!
   TBranch        *b_Jet_SimpIVF_HE;   //!
   TBranch        *b_Jet_DoubIVF_HE;   //!
   TBranch        *b_Jet_CombIVF;   //!
   TBranch        *b_Jet_CombIVF_P;   //!
   TBranch        *b_Jet_SoftMuN;   //!
   TBranch        *b_Jet_SoftMuP;   //!
   TBranch        *b_Jet_SoftMu;   //!
   TBranch        *b_Jet_SoftElN;   //!
   TBranch        *b_Jet_SoftElP;   //!
   TBranch        *b_Jet_SoftEl;   //!
   TBranch        *b_Jet_hist1;   //!
   TBranch        *b_Jet_hist2;   //!
   TBranch        *b_Jet_hist3;   //!
   TBranch        *b_Jet_histJet;   //!
   TBranch        *b_Jet_histSvx;   //!
   TBranch        *b_Jet_nFirstTrack;   //!
   TBranch        *b_Jet_nLastTrack;   //!
   TBranch        *b_Jet_nFirstSV;   //!
   TBranch        *b_Jet_nLastSV;   //!
   TBranch        *b_Jet_SV_multi;   //!
   TBranch        *b_Jet_nFirstTrkInc;   //!
   TBranch        *b_Jet_nLastTrkInc;   //!
   TBranch        *b_Jet_VtxCat;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Muon_IdxJet;   //!
   TBranch        *b_Muon_nMuHit;   //!
   TBranch        *b_Muon_nTkHit;   //!
   TBranch        *b_Muon_nPixHit;   //!
   TBranch        *b_Muon_nOutHit;   //!
   TBranch        *b_Muon_isGlobal;   //!
   TBranch        *b_Muon_nMatched;   //!
   TBranch        *b_Muon_chi2;   //!
   TBranch        *b_Muon_chi2Tk;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_ptrel;   //!
   TBranch        *b_Muon_vz;   //!
   TBranch        *b_Muon_hist;   //!
   TBranch        *b_Muon_IPsig;   //!
   TBranch        *b_Muon_IP;   //!
   TBranch        *b_Muon_IP2Dsig;   //!
   TBranch        *b_Muon_IP2D;   //!
   TBranch        *b_Muon_Proba;   //!
   TBranch        *b_Muon_deltaR;   //!
   TBranch        *b_Muon_ratio;   //!
   TBranch        *b_nPFElectron;   //!
   TBranch        *b_PFElectron_IdxJet;   //!
   TBranch        *b_PFElectron_pt;   //!
   TBranch        *b_PFElectron_eta;   //!
   TBranch        *b_PFElectron_phi;   //!
   TBranch        *b_PFElectron_ptrel;   //!
   TBranch        *b_PFElectron_deltaR;   //!
   TBranch        *b_PFElectron_ratio;   //!
   TBranch        *b_PFElectron_ratioRel;   //!
   TBranch        *b_PFElectron_IPsig;   //!
   TBranch        *b_nPFMuon;   //!
   TBranch        *b_PFMuon_IdxJet;   //!
   TBranch        *b_PFMuon_pt;   //!
   TBranch        *b_PFMuon_eta;   //!
   TBranch        *b_PFMuon_phi;   //!
   TBranch        *b_PFMuon_ptrel;   //!
   TBranch        *b_PFMuon_deltaR;   //!
   TBranch        *b_PFMuon_ratio;   //!
   TBranch        *b_PFMuon_ratioRel;   //!
   TBranch        *b_PFMuon_IPsig;   //!
   TBranch        *b_PFMuon_GoodQuality;   //!
   TBranch        *b_nTrkInc;   //!
   TBranch        *b_TrkInc_pt;   //!
   TBranch        *b_TrkInc_eta;   //!
   TBranch        *b_TrkInc_phi;   //!
   TBranch        *b_TrkInc_ptrel;   //!
   TBranch        *b_TrkInc_IPsig;   //!
   TBranch        *b_TrkInc_IP;   //!
   TBranch        *b_nCFromGSplit;   //!
   TBranch        *b_cFromGSplit_pT;   //!
   TBranch        *b_cFromGSplit_eta;   //!
   TBranch        *b_cFromGSplit_phi;   //!
   TBranch        *b_nBFromGSplit;   //!
   TBranch        *b_bFromGSplit_pT;   //!
   TBranch        *b_bFromGSplit_eta;   //!
   TBranch        *b_bFromGSplit_phi;   //!
   TBranch        *b_mcweight;   //!
   TBranch        *b_nBHadrons;   //!
   TBranch        *b_BHadron_pT;   //!
   TBranch        *b_BHadron_eta;   //!
   TBranch        *b_BHadron_phi;   //!
   TBranch        *b_BHadron_mass;   //!
   TBranch        *b_BHadron_pdgID;   //!
   TBranch        *b_nGenlep;   //!
   TBranch        *b_Genlep_pT;   //!
   TBranch        *b_Genlep_eta;   //!
   TBranch        *b_Genlep_phi;   //!
   TBranch        *b_Genlep_pdgID;   //!
   TBranch        *b_Genlep_mother;   //!
   TBranch        *b_nGenquark;   //!
   TBranch        *b_Genquark_pT;   //!
   TBranch        *b_Genquark_eta;   //!
   TBranch        *b_Genquark_phi;   //!
   TBranch        *b_Genquark_pdgID;   //!
   TBranch        *b_Genquark_mother;   //!

////   TreeClass(TChain *ch=0,TTree *tree=0,char* fname="physics.root",std::string treename="physics");
   TreeClassTTbar(TChain *ch=0,char* fname="physics.root",std::string treename="physics");
   virtual ~TreeClassTTbar();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
////   virtual void     Init(TTree *tree);
   virtual void     Init(TChain *tree);
////   virtual void     registerInputBranches(TTree *tree);
   virtual void     registerInputBranches(TChain *tree);
};

}
   
#endif
