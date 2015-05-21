#ifndef Tree_h
#define Tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

namespace LTANA
{   

class Tree {
public :
   TChain *fChain;
   Int_t           fCurrent;

   // Declaration of leaf types
   Int_t           nBitTrigger;
   Int_t           BitTrigger[3];   //[nBitTrigger]
   Int_t           Run;
   Int_t           Evt;
   Int_t           LumiBlock;
   Float_t         pthat;
   Float_t         mcweight;
   Int_t           nPV;
   Float_t         PVz;
   Float_t         PVez;
   Float_t         GenPVz;
   Float_t         nPUtrue;
   Int_t           nPU;
   Int_t           ncQuarks;
   Float_t         cQuark_pT[100];   //[ncQuarks]
   Float_t         cQuark_eta[100];   //[ncQuarks]
   Float_t         cQuark_phi[100];   //[ncQuarks]
   Int_t           cQuark_pdgID[100];   //[ncQuarks]
   Int_t           cQuark_status[100];   //[ncQuarks]
   Int_t           cQuark_fromGSP[100];   //[ncQuarks]
   Int_t           nbQuarks;
   Float_t         bQuark_pT[100];   //[nbQuarks]
   Float_t         bQuark_eta[100];   //[nbQuarks]
   Float_t         bQuark_phi[100];   //[nbQuarks]
   Int_t           bQuark_pdgID[100];   //[nbQuarks]
   Int_t           bQuark_status[100];   //[nbQuarks]
   Int_t           bQuark_fromGSP[100];   //[nbQuarks]
   Int_t           nBHadrons;
   Float_t         BHadron_pT[100];   //[nBHadrons]
   Float_t         BHadron_eta[100];   //[nBHadrons]
   Float_t         BHadron_phi[100];   //[nBHadrons]
   Float_t         BHadron_mass[100];   //[nBHadrons]
   Int_t           BHadron_pdgID[100];   //[nBHadrons]
   Int_t           BHadron_mother[100];   //[nBHadrons]
   Int_t           BHadron_hasBdaughter[100];   //[nBHadrons]
   Float_t         BHadron_SVx[100];   //[nBHadrons]
   Float_t         BHadron_SVy[100];   //[nBHadrons]
   Float_t         BHadron_SVz[100];   //[nBHadrons]
   Int_t           BHadron_nCharged[100];   //[nBHadrons]
   Int_t           BHadron_DHadron1[100];   //[nBHadrons]
   Int_t           BHadron_DHadron2[100];   //[nBHadrons]
   Int_t           nDHadrons;
   Int_t           nDaughters;
   Float_t         DHadron_pT[100];   //[nDHadrons]
   Float_t         DHadron_eta[100];   //[nDHadrons]
   Float_t         DHadron_phi[100];   //[nDHadrons]
   Int_t           DHadron_pdgID[100];   //[nDHadrons]
   Float_t         DHadron_mass[100];   //[nDHadrons]
   Float_t         DHadron_SVx[100];   //[nDHadrons]
   Float_t         DHadron_SVy[100];   //[nDHadrons]
   Float_t         DHadron_SVz[100];   //[nDHadrons]
   Int_t           DHadron_nDaughters[100];   //[nDHadrons]
   Int_t           DHadron_DaughtersPdgID[120];   //[nDaughters]
   Int_t           DHadron_nChargedDaughters[100];   //[nDHadrons]
   Int_t           DHadron_nCharged[100];   //[nDHadrons]
   Int_t           nGenlep;
   Float_t         Genlep_pT[100];   //[nGenlep]
   Float_t         Genlep_eta[100];   //[nGenlep]
   Float_t         Genlep_phi[100];   //[nGenlep]
   Int_t           Genlep_pdgID[100];   //[nGenlep]
   Int_t           Genlep_status[100];   //[nGenlep]
   Int_t           Genlep_mother[100];   //[nGenlep]
   Int_t           nGenquark;
   Float_t         Genquark_pT[100];   //[nGenquark]
   Float_t         Genquark_eta[100];   //[nGenquark]
   Float_t         Genquark_phi[100];   //[nGenquark]
   Int_t           Genquark_pdgID[100];   //[nGenquark]
   Int_t           Genquark_mother[100];   //[nGenquark]
   Int_t           nGenV0;
   Float_t         GenV0_pT[100];   //[nGenV0]
   Float_t         GenV0_eta[100];   //[nGenV0]
   Float_t         GenV0_phi[100];   //[nGenV0]
   Int_t           GenV0_pdgID[100];   //[nGenV0]
   Float_t         GenV0_SVx[100];   //[nGenV0]
   Float_t         GenV0_SVy[100];   //[nGenV0]
   Float_t         GenV0_SVz[100];   //[nGenV0]
   Int_t           GenV0_nCharged[100];   //[nGenV0]
   Int_t           nJet;
   Float_t         Jet_pt[100];   //[nJet]
   Float_t         Jet_genpt[100];   //[nJet]
   Float_t         Jet_residual[100];   //[nJet]
   Float_t         Jet_jes[100];   //[nJet]
   Float_t         Jet_eta[100];   //[nJet]
   Float_t         Jet_phi[100];   //[nJet]
   Float_t         Jet_mass[100];   //[nJet]
   Int_t           Jet_ntracks[100];   //[nJet]
   Int_t           Jet_nseltracks[100];   //[nJet]
   Int_t           Jet_flavour[100];   //[nJet]
   Float_t         Jet_Ip2N[100];   //[nJet]
   Float_t         Jet_Ip2P[100];   //[nJet]
   Float_t         Jet_Ip3N[100];   //[nJet]
   Float_t         Jet_Ip3P[100];   //[nJet]
   Float_t         Jet_ProbaN[100];   //[nJet]
   Float_t         Jet_ProbaP[100];   //[nJet]
   Float_t         Jet_Proba[100];   //[nJet]
   Float_t         Jet_BprobN[100];   //[nJet]
   Float_t         Jet_BprobP[100];   //[nJet]
   Float_t         Jet_Bprob[100];   //[nJet]
   Float_t         Jet_SvxN[100];   //[nJet]
   Float_t         Jet_Svx[100];   //[nJet]
   Float_t         Jet_SvxNHP[100];   //[nJet]
   Float_t         Jet_SvxHP[100];   //[nJet]
   Float_t         Jet_CombSvxN[100];   //[nJet]
   Float_t         Jet_CombSvxP[100];   //[nJet]
   Float_t         Jet_CombSvx[100];   //[nJet]
   Float_t         Jet_RetCombSvxN[100];   //[nJet]
   Float_t         Jet_RetCombSvxP[100];   //[nJet]
   Float_t         Jet_RetCombSvx[100];   //[nJet]
   Float_t         Jet_CombCSVJP_N[100];   //[nJet]
   Float_t         Jet_CombCSVJP_P[100];   //[nJet]
   Float_t         Jet_CombCSVJP[100];   //[nJet]
   Float_t         Jet_CombCSVSL_N[100];   //[nJet]
   Float_t         Jet_CombCSVSL_P[100];   //[nJet]
   Float_t         Jet_CombCSVSL[100];   //[nJet]
   Float_t         Jet_CombCSVJPSL_N[100];   //[nJet]
   Float_t         Jet_CombCSVJPSL_P[100];   //[nJet]
   Float_t         Jet_CombCSVJPSL[100];   //[nJet]
   Float_t         Jet_SoftMuN[100];   //[nJet]
   Float_t         Jet_SoftMuP[100];   //[nJet]
   Float_t         Jet_SoftMu[100];   //[nJet]
   Float_t         Jet_SoftElN[100];   //[nJet]
   Float_t         Jet_SoftElP[100];   //[nJet]
   Float_t         Jet_SoftEl[100];   //[nJet]
   Int_t           Jet_hist1[100];   //[nJet]
   Int_t           Jet_hist2[100];   //[nJet]
   Int_t           Jet_hist3[100];   //[nJet]
   Int_t           Jet_histJet[100];   //[nJet]
   Int_t           Jet_histSvx[100];   //[nJet]
   Int_t           Jet_nFirstTrack[100];   //[nJet]
   Int_t           Jet_nLastTrack[100];   //[nJet]
   Int_t           Jet_nFirstSV[100];   //[nJet]
   Int_t           Jet_nLastSV[100];   //[nJet]
   Int_t           Jet_SV_multi[100];   //[nJet]
   Int_t           Jet_nFirstTrkInc[100];   //[nJet]
   Int_t           Jet_nLastTrkInc[100];   //[nJet]
   Int_t           Jet_VtxCat[100];   //[nJet]
   Int_t           Jet_looseID[100];   //[nJet]
   Int_t           Jet_tightID[100];   //[nJet]
   Int_t           nTrkInc;
   Float_t         TrkInc_pt[100];   //[nTrkInc]
   Float_t         TrkInc_eta[100];   //[nTrkInc]
   Float_t         TrkInc_phi[100];   //[nTrkInc]
   Float_t         TrkInc_ptrel[100];   //[nTrkInc]
   Float_t         TrkInc_IPsig[100];   //[nTrkInc]
   Float_t         TrkInc_IP[100];   //[nTrkInc]
   Int_t           nMuon;
   Int_t           Muon_IdxJet[100];   //[nMuon]
   Int_t           Muon_nMuHit[100];   //[nMuon]
   Int_t           Muon_nTkHit[100];   //[nMuon]
   Int_t           Muon_nPixHit[100];   //[nMuon]
   Int_t           Muon_nOutHit[100];   //[nMuon]
   Int_t           Muon_isGlobal[100];   //[nMuon]
   Int_t           Muon_nMatched[100];   //[nMuon]
   Float_t         Muon_chi2[100];   //[nMuon]
   Float_t         Muon_chi2Tk[100];   //[nMuon]
   Float_t         Muon_pt[100];   //[nMuon]
   Float_t         Muon_eta[100];   //[nMuon]
   Float_t         Muon_phi[100];   //[nMuon]
   Float_t         Muon_ptrel[100];   //[nMuon]
   Float_t         Muon_vz[100];   //[nMuon]
   Int_t           Muon_hist[100];   //[nMuon]
   Int_t           Muon_TrackIdx[100];   //[nMuon]
   Float_t         Muon_IPsig[100];   //[nMuon]
   Float_t         Muon_IP[100];   //[nMuon]
   Float_t         Muon_IP2Dsig[100];   //[nMuon]
   Float_t         Muon_IP2D[100];   //[nMuon]
   Float_t         Muon_Proba[100];   //[nMuon]
   Float_t         Muon_deltaR[100];   //[nMuon]
   Float_t         Muon_ratio[100];   //[nMuon]
   Float_t         Muon_ratioRel[100];   //[nMuon]
   Int_t           nPFElectron;
   Int_t           PFElectron_IdxJet[100];   //[nPFElectron]
   Float_t         PFElectron_pt[100];   //[nPFElectron]
   Float_t         PFElectron_eta[100];   //[nPFElectron]
   Float_t         PFElectron_phi[100];   //[nPFElectron]
   Float_t         PFElectron_ptrel[100];   //[nPFElectron]
   Float_t         PFElectron_deltaR[100];   //[nPFElectron]
   Float_t         PFElectron_ratio[100];   //[nPFElectron]
   Float_t         PFElectron_ratioRel[100];   //[nPFElectron]
   Float_t         PFElectron_IP[100];   //[nPFElectron]
   Float_t         PFElectron_IP2D[100];   //[nPFElectron]
   Int_t           nPFMuon;
   Int_t           PFMuon_IdxJet[100];   //[nPFMuon]
   Float_t         PFMuon_pt[100];   //[nPFMuon]
   Float_t         PFMuon_eta[100];   //[nPFMuon]
   Float_t         PFMuon_phi[100];   //[nPFMuon]
   Float_t         PFMuon_ptrel[100];   //[nPFMuon]
   Float_t         PFMuon_deltaR[100];   //[nPFMuon]
   Float_t         PFMuon_ratio[100];   //[nPFMuon]
   Float_t         PFMuon_ratioRel[100];   //[nPFMuon]
   Float_t         PFMuon_IP[100];   //[nPFMuon]
   Float_t         PFMuon_IP2D[100];   //[nPFMuon]
   Int_t           PFMuon_GoodQuality[100];   //[nPFMuon]
   Int_t           nSV;
   Float_t         SV_x[100];   //[nSV]
   Float_t         SV_y[100];   //[nSV]
   Float_t         SV_z[100];   //[nSV]
   Float_t         SV_ex[100];   //[nSV]
   Float_t         SV_ey[100];   //[nSV]
   Float_t         SV_ez[100];   //[nSV]
   Float_t         SV_chi2[100];   //[nSV]
   Float_t         SV_ndf[100];   //[nSV]
   Float_t         SV_flight[100];   //[nSV]
   Float_t         SV_flightErr[100];   //[nSV]
   Float_t         SV_deltaR_jet[100];   //[nSV]
   Float_t         SV_deltaR_sum_jet[100];   //[nSV]
   Float_t         SV_deltaR_sum_dir[100];   //[nSV]
   Float_t         SV_energy_ratio[100];   //[nSV]
   Float_t         SV_aboveC[100];   //[nSV]
   Float_t         SV_vtx_pt[100];   //[nSV]
   Float_t         SV_flight2D[100];   //[nSV]
   Float_t         SV_flight2DErr[100];   //[nSV]
   Float_t         SV_totCharge[100];   //[nSV]
   Float_t         SV_vtxDistJetAxis[100];   //[nSV]
   Int_t           SV_nTrk[100];   //[nSV]
   Int_t           SV_nTrk_firstVxt[100];   //[nSV]
   Float_t         SV_mass[100];   //[nSV]
   Float_t         SV_vtx_eta[100];   //[nSV]
   Float_t         SV_vtx_phi[100];   //[nSV]

   // List of branches
   TBranch        *b_nBitTrigger;   //!
   TBranch        *b_BitTrigger;   //!
   TBranch        *b_Run;   //!
   TBranch        *b_Evt;   //!
   TBranch        *b_LumiBlock;   //!
   TBranch        *b_pthat;   //!
   TBranch        *b_mcweight;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_PVez;   //!
   TBranch        *b_GenPVz;   //!
   TBranch        *b_nPUtrue;   //!
   TBranch        *b_nPU;   //!
   TBranch        *b_ncQuarks;   //!
   TBranch        *b_cQuark_pT;   //!
   TBranch        *b_cQuark_eta;   //!
   TBranch        *b_cQuark_phi;   //!
   TBranch        *b_cQuark_pdgID;   //!
   TBranch        *b_cQuark_status;   //!
   TBranch        *b_cQuark_fromGSP;   //!
   TBranch        *b_nbQuarks;   //!
   TBranch        *b_bQuark_pT;   //!
   TBranch        *b_bQuark_eta;   //!
   TBranch        *b_bQuark_phi;   //!
   TBranch        *b_bQuark_pdgID;   //!
   TBranch        *b_bQuark_status;   //!
   TBranch        *b_bQuark_fromGSP;   //!
   TBranch        *b_nBHadrons;   //!
   TBranch        *b_BHadron_pT;   //!
   TBranch        *b_BHadron_eta;   //!
   TBranch        *b_BHadron_phi;   //!
   TBranch        *b_BHadron_mass;   //!
   TBranch        *b_BHadron_pdgID;   //!
   TBranch        *b_BHadron_mother;   //!
   TBranch        *b_BHadron_hasBdaughter;   //!
   TBranch        *b_BHadron_SVx;   //!
   TBranch        *b_BHadron_SVy;   //!
   TBranch        *b_BHadron_SVz;   //!
   TBranch        *b_BHadron_nCharged;   //!
   TBranch        *b_BHadron_DHadron1;   //!
   TBranch        *b_BHadron_DHadron2;   //!
   TBranch        *b_nDHadrons;   //!
   TBranch        *b_nDaughters;   //!
   TBranch        *b_DHadron_pT;   //!
   TBranch        *b_DHadron_eta;   //!
   TBranch        *b_DHadron_phi;   //!
   TBranch        *b_DHadron_pdgID;   //!
   TBranch        *b_DHadron_mass;   //!
   TBranch        *b_DHadron_SVx;   //!
   TBranch        *b_DHadron_SVy;   //!
   TBranch        *b_DHadron_SVz;   //!
   TBranch        *b_DHadron_nDaughters;   //!
   TBranch        *b_DHadron_DaughtersPdgID;   //!
   TBranch        *b_DHadron_nChargedDaughters;   //!
   TBranch        *b_DHadron_nCharged;   //!
   TBranch        *b_nGenlep;   //!
   TBranch        *b_Genlep_pT;   //!
   TBranch        *b_Genlep_eta;   //!
   TBranch        *b_Genlep_phi;   //!
   TBranch        *b_Genlep_pdgID;   //!
   TBranch        *b_Genlep_status;   //!
   TBranch        *b_Genlep_mother;   //!
   TBranch        *b_nGenquark;   //!
   TBranch        *b_Genquark_pT;   //!
   TBranch        *b_Genquark_eta;   //!
   TBranch        *b_Genquark_phi;   //!
   TBranch        *b_Genquark_pdgID;   //!
   TBranch        *b_Genquark_mother;   //!
   TBranch        *b_nGenV0;   //!
   TBranch        *b_GenV0_pT;   //!
   TBranch        *b_GenV0_eta;   //!
   TBranch        *b_GenV0_phi;   //!
   TBranch        *b_GenV0_pdgID;   //!
   TBranch        *b_GenV0_SVx;   //!
   TBranch        *b_GenV0_SVy;   //!
   TBranch        *b_GenV0_SVz;   //!
   TBranch        *b_GenV0_nCharged;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_genpt;   //!
   TBranch        *b_Jet_residual;   //!
   TBranch        *b_Jet_jes;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_ntracks;   //!
   TBranch        *b_Jet_nseltracks;   //!
   TBranch        *b_Jet_flavour;   //!
   TBranch        *b_Jet_Ip2N;   //!
   TBranch        *b_Jet_Ip2P;   //!
   TBranch        *b_Jet_Ip3N;   //!
   TBranch        *b_Jet_Ip3P;   //!
   TBranch        *b_Jet_ProbaN;   //!
   TBranch        *b_Jet_ProbaP;   //!
   TBranch        *b_Jet_Proba;   //!
   TBranch        *b_Jet_BprobN;   //!
   TBranch        *b_Jet_BprobP;   //!
   TBranch        *b_Jet_Bprob;   //!
   TBranch        *b_Jet_SvxN;   //!
   TBranch        *b_Jet_Svx;   //!
   TBranch        *b_Jet_SvxNHP;   //!
   TBranch        *b_Jet_SvxHP;   //!
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
   TBranch        *b_Jet_looseID;   //!
   TBranch        *b_Jet_tightID;   //!
   TBranch        *b_nTrkInc;   //!
   TBranch        *b_TrkInc_pt;   //!
   TBranch        *b_TrkInc_eta;   //!
   TBranch        *b_TrkInc_phi;   //!
   TBranch        *b_TrkInc_ptrel;   //!
   TBranch        *b_TrkInc_IPsig;   //!
   TBranch        *b_TrkInc_IP;   //!
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
   TBranch        *b_Muon_TrackIdx;   //!
   TBranch        *b_Muon_IPsig;   //!
   TBranch        *b_Muon_IP;   //!
   TBranch        *b_Muon_IP2Dsig;   //!
   TBranch        *b_Muon_IP2D;   //!
   TBranch        *b_Muon_Proba;   //!
   TBranch        *b_Muon_deltaR;   //!
   TBranch        *b_Muon_ratio;   //!
   TBranch        *b_Muon_ratioRel;   //!
   TBranch        *b_nPFElectron;   //!
   TBranch        *b_PFElectron_IdxJet;   //!
   TBranch        *b_PFElectron_pt;   //!
   TBranch        *b_PFElectron_eta;   //!
   TBranch        *b_PFElectron_phi;   //!
   TBranch        *b_PFElectron_ptrel;   //!
   TBranch        *b_PFElectron_deltaR;   //!
   TBranch        *b_PFElectron_ratio;   //!
   TBranch        *b_PFElectron_ratioRel;   //!
   TBranch        *b_PFElectron_IP;   //!
   TBranch        *b_PFElectron_IP2D;   //!
   TBranch        *b_nPFMuon;   //!
   TBranch        *b_PFMuon_IdxJet;   //!
   TBranch        *b_PFMuon_pt;   //!
   TBranch        *b_PFMuon_eta;   //!
   TBranch        *b_PFMuon_phi;   //!
   TBranch        *b_PFMuon_ptrel;   //!
   TBranch        *b_PFMuon_deltaR;   //!
   TBranch        *b_PFMuon_ratio;   //!
   TBranch        *b_PFMuon_ratioRel;   //!
   TBranch        *b_PFMuon_IP;   //!
   TBranch        *b_PFMuon_IP2D;   //!
   TBranch        *b_PFMuon_GoodQuality;   //!
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

   Tree(TChain *ch=0,char* fname="physics.root",std::string treename="physics");
   virtual ~Tree();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *tree);
   virtual void     registerInputBranches(TChain *tree);
};

}
   
#endif
