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
   Int_t           PU_bunch[1000];   //[nPU]
   Float_t         PU_z[1000];   //[nPU]
   Float_t         PU_sumpT_low[1000];   //[nPU]
   Float_t         PU_sumpT_high[1000];   //[nPU]
   Int_t           PU_ntrks_low[1000];   //[nPU]
   Int_t           PU_ntrks_high[1000];   //[nPU]
   Int_t           ncQuarks;
   Float_t         cQuark_pT[1000];   //[ncQuarks]
   Float_t         cQuark_eta[1000];   //[ncQuarks]
   Float_t         cQuark_phi[1000];   //[ncQuarks]
   Int_t           cQuark_pdgID[1000];   //[ncQuarks]
   Int_t           cQuark_status[1000];   //[ncQuarks]
   Int_t           cQuark_fromGSP[1000];   //[ncQuarks]
   Int_t           nbQuarks;
   Float_t         bQuark_pT[1000];   //[nbQuarks]
   Float_t         bQuark_eta[1000];   //[nbQuarks]
   Float_t         bQuark_phi[1000];   //[nbQuarks]
   Int_t           bQuark_pdgID[1000];   //[nbQuarks]
   Int_t           bQuark_status[1000];   //[nbQuarks]
   Int_t           bQuark_fromGSP[1000];   //[nbQuarks]
   Int_t           nBHadrons;
   Float_t         BHadron_pT[1000];   //[nBHadrons]
   Float_t         BHadron_eta[1000];   //[nBHadrons]
   Float_t         BHadron_phi[1000];   //[nBHadrons]
   Float_t         BHadron_mass[1000];   //[nBHadrons]
   Int_t           BHadron_pdgID[1000];   //[nBHadrons]
   Int_t           BHadron_mother[1000];   //[nBHadrons]
   Int_t           BHadron_hasBdaughter[1000];   //[nBHadrons]
   Float_t         BHadron_SVx[1000];   //[nBHadrons]
   Float_t         BHadron_SVy[1000];   //[nBHadrons]
   Float_t         BHadron_SVz[1000];   //[nBHadrons]
   Int_t           BHadron_nCharged[1000];   //[nBHadrons]
   Int_t           BHadron_DHadron1[1000];   //[nBHadrons]
   Int_t           BHadron_DHadron2[1000];   //[nBHadrons]
   Int_t           nDHadrons;
   Int_t           nDaughters;
   Float_t         DHadron_pT[1000];   //[nDHadrons]
   Float_t         DHadron_eta[1000];   //[nDHadrons]
   Float_t         DHadron_phi[1000];   //[nDHadrons]
   Int_t           DHadron_pdgID[1000];   //[nDHadrons]
   Float_t         DHadron_mass[1000];   //[nDHadrons]
   Float_t         DHadron_SVx[1000];   //[nDHadrons]
   Float_t         DHadron_SVy[1000];   //[nDHadrons]
   Float_t         DHadron_SVz[1000];   //[nDHadrons]
   Int_t           DHadron_nDaughters[1000];   //[nDHadrons]
   Int_t           DHadron_DaughtersPdgID[1000];   //[nDaughters]
   Int_t           DHadron_nChargedDaughters[1000];   //[nDHadrons]
   Int_t           DHadron_nCharged[1000];   //[nDHadrons]
   Int_t           nGenlep;
   Float_t         Genlep_pT[1000];   //[nGenlep]
   Float_t         Genlep_eta[1000];   //[nGenlep]
   Float_t         Genlep_phi[1000];   //[nGenlep]
   Int_t           Genlep_pdgID[1000];   //[nGenlep]
   Int_t           Genlep_status[1000];   //[nGenlep]
   Int_t           Genlep_mother[1000];   //[nGenlep]
   Int_t           nGenquark;
   Float_t         Genquark_pT[1000];   //[nGenquark]
   Float_t         Genquark_eta[1000];   //[nGenquark]
   Float_t         Genquark_phi[1000];   //[nGenquark]
   Int_t           Genquark_pdgID[1000];   //[nGenquark]
   Int_t           Genquark_mother[1000];   //[nGenquark]
   Int_t           nGenPruned;
   Float_t         GenPruned_pT[1000];   //[nGenPruned]
   Float_t         GenPruned_eta[1000];   //[nGenPruned]
   Float_t         GenPruned_phi[1000];   //[nGenPruned]
   Float_t         GenPruned_mass[1000];   //[nGenPruned]
   Int_t           GenPruned_pdgID[1000];   //[nGenPruned]
   Int_t           GenPruned_status[1000];   //[nGenPruned]
   Int_t           GenPruned_mother[1000];   //[nGenPruned]
   Int_t           nGenV0;
   Float_t         GenV0_pT[1000];   //[nGenV0]
   Float_t         GenV0_eta[1000];   //[nGenV0]
   Float_t         GenV0_phi[1000];   //[nGenV0]
   Int_t           GenV0_pdgID[1000];   //[nGenV0]
   Float_t         GenV0_SVx[1000];   //[nGenV0]
   Float_t         GenV0_SVy[1000];   //[nGenV0]
   Float_t         GenV0_SVz[1000];   //[nGenV0]
   Int_t           GenV0_nCharged[1000];   //[nGenV0]
   Int_t           nJet;
   Float_t         Jet_pt[1000];   //[nJet]
   Float_t         Jet_genpt[1000];   //[nJet]
   Float_t         Jet_residual[1000];   //[nJet]
   Float_t         Jet_jes[1000];   //[nJet]
   Float_t         Jet_eta[1000];   //[nJet]
   Float_t         Jet_phi[1000];   //[nJet]
   Float_t         Jet_mass[1000];   //[nJet]
   Int_t           Jet_ntracks[1000];   //[nJet]
   Int_t           Jet_nseltracks[1000];   //[nJet]
   Int_t           Jet_flavour[1000];   //[nJet]
   Int_t           Jet_nbHadrons[1000];   //[nJet]
   Int_t           Jet_ncHadrons[1000];   //[nJet]
   Float_t         Jet_Ip2N[1000];   //[nJet]
   Float_t         Jet_Ip2P[1000];   //[nJet]
   Float_t         Jet_Ip3N[1000];   //[nJet]
   Float_t         Jet_Ip3P[1000];   //[nJet]
   Float_t         Jet_ProbaN[1000];   //[nJet]
   Float_t         Jet_ProbaP[1000];   //[nJet]
   Float_t         Jet_Proba[1000];   //[nJet]
   Float_t         Jet_BprobN[1000];   //[nJet]
   Float_t         Jet_BprobP[1000];   //[nJet]
   Float_t         Jet_Bprob[1000];   //[nJet]
   Float_t         Jet_SvxN[1000];   //[nJet]
   Float_t         Jet_Svx[1000];   //[nJet]
   Float_t         Jet_SvxNHP[1000];   //[nJet]
   Float_t         Jet_SvxHP[1000];   //[nJet]
   Float_t         Jet_CombSvxN[1000];   //[nJet]
   Float_t         Jet_CombSvxP[1000];   //[nJet]
   Float_t         Jet_CombSvx[1000];   //[nJet]
   Float_t         Jet_CombIVF[1000];   //[nJet]
   Float_t         Jet_CombIVF_P[1000];   //[nJet]
   Float_t         Jet_CombIVF_N[1000];   //[nJet]
   Float_t         Jet_SoftMuN[1000];   //[nJet]
   Float_t         Jet_SoftMuP[1000];   //[nJet]
   Float_t         Jet_SoftMu[1000];   //[nJet]
   Float_t         Jet_SoftElN[1000];   //[nJet]
   Float_t         Jet_SoftElP[1000];   //[nJet]
   Float_t         Jet_SoftEl[1000];   //[nJet]
   Float_t         Jet_DoubleSV[1000];   //[nJet]
   Int_t           Jet_hist1[1000];   //[nJet]
   Int_t           Jet_hist2[1000];   //[nJet]
   Int_t           Jet_hist3[1000];   //[nJet]
   Int_t           Jet_histJet[1000];   //[nJet]
   Int_t           Jet_histSvx[1000];   //[nJet]
   Int_t           Jet_nFirstTrack[1000];   //[nJet]
   Int_t           Jet_nLastTrack[1000];   //[nJet]
   Int_t           Jet_nFirstSV[1000];   //[nJet]
   Int_t           Jet_nLastSV[1000];   //[nJet]
   Int_t           Jet_SV_multi[1000];   //[nJet]
   Int_t           Jet_nFirstTrkInc[1000];   //[nJet]
   Int_t           Jet_nLastTrkInc[1000];   //[nJet]
   Int_t           Jet_nSM[1000];   //[nJet]
   Int_t           Jet_nFirstSM[1000];   //[nJet]
   Int_t           Jet_nLastSM[1000];   //[nJet]
   Int_t           Jet_nSE[1000];   //[nJet]
   Int_t           Jet_nFirstSE[1000];   //[nJet]
   Int_t           Jet_nLastSE[1000];   //[nJet]
   Int_t           Jet_looseID[1000];   //[nJet]
   Int_t           Jet_tightID[1000];   //[nJet]
   Int_t           nTrkInc;
   Float_t         TrkInc_pt[1000];   //[nTrkInc]
   Float_t         TrkInc_eta[1000];   //[nTrkInc]
   Float_t         TrkInc_phi[1000];   //[nTrkInc]
   Float_t         TrkInc_ptrel[1000];   //[nTrkInc]
   Float_t         TrkInc_IPsig[1000];   //[nTrkInc]
   Float_t         TrkInc_IP[1000];   //[nTrkInc]
   Int_t           nPFElectron;
   Int_t           PFElectron_IdxJet[1000];   //[nPFElectron]
   Float_t         PFElectron_pt[1000];   //[nPFElectron]
   Float_t         PFElectron_eta[1000];   //[nPFElectron]
   Float_t         PFElectron_phi[1000];   //[nPFElectron]
   Float_t         PFElectron_ptrel[1000];   //[nPFElectron]
   Float_t         PFElectron_deltaR[1000];   //[nPFElectron]
   Float_t         PFElectron_ratio[1000];   //[nPFElectron]
   Float_t         PFElectron_ratioRel[1000];   //[nPFElectron]
   Float_t         PFElectron_IP[1000];   //[nPFElectron]
   Float_t         PFElectron_IP2D[1000];   //[nPFElectron]
   Int_t           nPFMuon;
   Int_t           PFMuon_IdxJet[1000];   //[nPFMuon]
   Int_t           PFMuon_nMuHit[1000];   //[nPFMuon]
   Int_t           PFMuon_nTkHit[1000];   //[nPFMuon]
   Int_t           PFMuon_nPixHit[1000];   //[nPFMuon]
   Int_t           PFMuon_nOutHit[1000];   //[nPFMuon]
   Int_t           PFMuon_nTkLwM[1000];   //[nPFMuon]
   Int_t           PFMuon_nPixLwM[1000];   //[nPFMuon]
   Int_t           PFMuon_nMatched[1000];   //[nPFMuon]
   Float_t         PFMuon_chi2[1000];   //[nPFMuon]
   Float_t         PFMuon_chi2Tk[1000];   //[nPFMuon]
   Int_t           PFMuon_isGlobal[1000];   //[nPFMuon]
   Int_t           PFMuon_hist[1000];   //[nPFMuon]
   Float_t         PFMuon_pt[1000];   //[nPFMuon]
   Float_t         PFMuon_eta[1000];   //[nPFMuon]
   Float_t         PFMuon_phi[1000];   //[nPFMuon]
   Float_t         PFMuon_ptrel[1000];   //[nPFMuon]
   Float_t         PFMuon_deltaR[1000];   //[nPFMuon]
   Float_t         PFMuon_ratio[1000];   //[nPFMuon]
   Float_t         PFMuon_ratioRel[1000];   //[nPFMuon]
   Float_t         PFMuon_IP[1000];   //[nPFMuon]
   Float_t         PFMuon_IP2D[1000];   //[nPFMuon]
   Float_t         PFMuon_dz[1000];   //[nPFMuon]
   Int_t           PFMuon_GoodQuality[1000];   //[nPFMuon]
   Int_t           nSV;
   Float_t         SV_x[1000];   //[nSV]
   Float_t         SV_y[1000];   //[nSV]
   Float_t         SV_z[1000];   //[nSV]
   Float_t         SV_ex[1000];   //[nSV]
   Float_t         SV_ey[1000];   //[nSV]
   Float_t         SV_ez[1000];   //[nSV]
   Float_t         SV_chi2[1000];   //[nSV]
   Float_t         SV_ndf[1000];   //[nSV]
   Float_t         SV_flight[1000];   //[nSV]
   Float_t         SV_flightErr[1000];   //[nSV]
   Float_t         SV_deltaR_jet[1000];   //[nSV]
   Float_t         SV_deltaR_sum_jet[1000];   //[nSV]
   Float_t         SV_deltaR_sum_dir[1000];   //[nSV]
   Float_t         SV_vtx_pt[1000];   //[nSV]
   Float_t         SV_flight2D[1000];   //[nSV]
   Float_t         SV_flight2DErr[1000];   //[nSV]
   Float_t         SV_totCharge[1000];   //[nSV]
   Float_t         SV_vtxDistJetAxis[1000];   //[nSV]
   Int_t           SV_nTrk[1000];   //[nSV]
   Float_t         SV_mass[1000];   //[nSV]
   Float_t         SV_vtx_eta[1000];   //[nSV]
   Float_t         SV_vtx_phi[1000];   //[nSV]
   Float_t         SV_EnergyRatio[1000];   //[nSV]
   Float_t         SV_dir_x[1000];   //[nSV]
   Float_t         SV_dir_y[1000];   //[nSV]
   Float_t         SV_dir_z[1000];   //[nSV]
   Int_t           Jet_nFirstTrkTagVarCSV[1000];   //[nJet]
   Int_t           Jet_nLastTrkTagVarCSV[1000];   //[nJet]
   Int_t           Jet_nFirstTrkEtaRelTagVarCSV[1000];   //[nJet]
   Int_t           Jet_nLastTrkEtaRelTagVarCSV[1000];   //[nJet]
   Float_t         TagVarCSV_trackJetPt[1000];   //[nJet]
   Float_t         TagVarCSV_jetNTracks[1000];   //[nJet]
   Float_t         TagVarCSV_jetNTracksEtaRel[1000];   //[nJet]
   Float_t         TagVarCSV_trackSumJetEtRatio[1000];   //[nJet]
   Float_t         TagVarCSV_trackSumJetDeltaR[1000];   //[nJet]
   Float_t         TagVarCSV_trackSip2dValAboveCharm[1000];   //[nJet]
   Float_t         TagVarCSV_trackSip2dSigAboveCharm[1000];   //[nJet]
   Float_t         TagVarCSV_trackSip3dValAboveCharm[1000];   //[nJet]
   Float_t         TagVarCSV_trackSip3dSigAboveCharm[1000];   //[nJet]
   Float_t         TagVarCSV_vertexCategory[1000];   //[nJet]
   Float_t         TagVarCSV_jetNSecondaryVertices[1000];   //[nJet]
   Float_t         TagVarCSV_vertexMass[1000];   //[nJet]
   Float_t         TagVarCSV_vertexNTracks[1000];   //[nJet]
   Float_t         TagVarCSV_vertexEnergyRatio[1000];   //[nJet]
   Float_t         TagVarCSV_vertexJetDeltaR[1000];   //[nJet]
   Float_t         TagVarCSV_flightDistance2dVal[1000];   //[nJet]
   Float_t         TagVarCSV_flightDistance2dSig[1000];   //[nJet]
   Float_t         TagVarCSV_flightDistance3dVal[1000];   //[nJet]
   Float_t         TagVarCSV_flightDistance3dSig[1000];   //[nJet]
   Int_t           nTrkTagVarCSV;
   Int_t           nTrkEtaRelTagVarCSV;
   Float_t         TagVarCSV_trackMomentum[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackEta[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackPhi[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackPtRel[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackPPar[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackDeltaR[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackPtRatio[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackPParRatio[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackSip2dVal[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackSip2dSig[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackSip3dVal[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackSip3dSig[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackDecayLenVal[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackDecayLenSig[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackJetDistVal[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackJetDistSig[1000];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackEtaRel[1000];   //[nTrkEtaRelTagVarCSV]

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
   TBranch        *b_PU_bunch;   //!
   TBranch        *b_PU_z;   //!
   TBranch        *b_PU_sumpT_low;   //!
   TBranch        *b_PU_sumpT_high;   //!
   TBranch        *b_PU_ntrks_low;   //!
   TBranch        *b_PU_ntrks_high;   //!
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
   TBranch        *b_nGenPruned;   //!
   TBranch        *b_GenPruned_pT;   //!
   TBranch        *b_GenPruned_eta;   //!
   TBranch        *b_GenPruned_phi;   //!
   TBranch        *b_GenPruned_mass;   //!
   TBranch        *b_GenPruned_pdgID;   //!
   TBranch        *b_GenPruned_status;   //!
   TBranch        *b_GenPruned_mother;   //!
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
   TBranch        *b_Jet_nbHadrons;   //!
   TBranch        *b_Jet_ncHadrons;   //!
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
   TBranch        *b_Jet_CombIVF;   //!
   TBranch        *b_Jet_CombIVF_P;   //!
   TBranch        *b_Jet_CombIVF_N;   //!
   TBranch        *b_Jet_SoftMuN;   //!
   TBranch        *b_Jet_SoftMuP;   //!
   TBranch        *b_Jet_SoftMu;   //!
   TBranch        *b_Jet_SoftElN;   //!
   TBranch        *b_Jet_SoftElP;   //!
   TBranch        *b_Jet_SoftEl;   //!
   TBranch        *b_Jet_DoubleSV;   //!
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
   TBranch        *b_Jet_nSM;   //!
   TBranch        *b_Jet_nFirstSM;   //!
   TBranch        *b_Jet_nLastSM;   //!
   TBranch        *b_Jet_nSE;   //!
   TBranch        *b_Jet_nFirstSE;   //!
   TBranch        *b_Jet_nLastSE;   //!
   TBranch        *b_Jet_looseID;   //!
   TBranch        *b_Jet_tightID;   //!
   TBranch        *b_nTrkInc;   //!
   TBranch        *b_TrkInc_pt;   //!
   TBranch        *b_TrkInc_eta;   //!
   TBranch        *b_TrkInc_phi;   //!
   TBranch        *b_TrkInc_ptrel;   //!
   TBranch        *b_TrkInc_IPsig;   //!
   TBranch        *b_TrkInc_IP;   //!
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
   TBranch        *b_PFMuon_nMuHit;   //!
   TBranch        *b_PFMuon_nTkHit;   //!
   TBranch        *b_PFMuon_nPixHit;   //!
   TBranch        *b_PFMuon_nOutHit;   //!
   TBranch        *b_PFMuon_nTkLwM;   //!
   TBranch        *b_PFMuon_nPixLwM;   //!
   TBranch        *b_PFMuon_nMatched;   //!
   TBranch        *b_PFMuon_chi2;   //!
   TBranch        *b_PFMuon_chi2Tk;   //!
   TBranch        *b_PFMuon_isGlobal;   //!
   TBranch        *b_PFMuon_hist;   //!
   TBranch        *b_PFMuon_pt;   //!
   TBranch        *b_PFMuon_eta;   //!
   TBranch        *b_PFMuon_phi;   //!
   TBranch        *b_PFMuon_ptrel;   //!
   TBranch        *b_PFMuon_deltaR;   //!
   TBranch        *b_PFMuon_ratio;   //!
   TBranch        *b_PFMuon_ratioRel;   //!
   TBranch        *b_PFMuon_IP;   //!
   TBranch        *b_PFMuon_IP2D;   //!
   TBranch        *b_PFMuon_dz;   //!
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
   TBranch        *b_SV_vtx_pt;   //!
   TBranch        *b_SV_flight2D;   //!
   TBranch        *b_SV_flight2DErr;   //!
   TBranch        *b_SV_totCharge;   //!
   TBranch        *b_SV_vtxDistJetAxis;   //!
   TBranch        *b_SV_nTrk;   //!
   TBranch        *b_SV_mass;   //!
   TBranch        *b_SV_vtx_eta;   //!
   TBranch        *b_SV_vtx_phi;   //!
   TBranch        *b_SV_EnergyRatio;   //!
   TBranch        *b_SV_dir_x;   //!
   TBranch        *b_SV_dir_y;   //!
   TBranch        *b_SV_dir_z;   //!
   TBranch        *b_Jet_nFirstTrkTagVarCSV;   //!
   TBranch        *b_Jet_nLastTrkTagVarCSV;   //!
   TBranch        *b_Jet_nFirstTrkEtaRelTagVarCSV;   //!
   TBranch        *b_Jet_nLastTrkEtaRelTagVarCSV;   //!
   TBranch        *b_TagVarCSV_trackJetPt;   //!
   TBranch        *b_TagVarCSV_jetNTracks;   //!
   TBranch        *b_TagVarCSV_jetNTracksEtaRel;   //!
   TBranch        *b_TagVarCSV_trackSumJetEtRatio;   //!
   TBranch        *b_TagVarCSV_trackSumJetDeltaR;   //!
   TBranch        *b_TagVarCSV_trackSip2dValAboveCharm;   //!
   TBranch        *b_TagVarCSV_trackSip2dSigAboveCharm;   //!
   TBranch        *b_TagVarCSV_trackSip3dValAboveCharm;   //!
   TBranch        *b_TagVarCSV_trackSip3dSigAboveCharm;   //!
   TBranch        *b_TagVarCSV_vertexCategory;   //!
   TBranch        *b_TagVarCSV_jetNSecondaryVertices;   //!
   TBranch        *b_TagVarCSV_vertexMass;   //!
   TBranch        *b_TagVarCSV_vertexNTracks;   //!
   TBranch        *b_TagVarCSV_vertexEnergyRatio;   //!
   TBranch        *b_TagVarCSV_vertexJetDeltaR;   //!
   TBranch        *b_TagVarCSV_flightDistance2dVal;   //!
   TBranch        *b_TagVarCSV_flightDistance2dSig;   //!
   TBranch        *b_TagVarCSV_flightDistance3dVal;   //!
   TBranch        *b_TagVarCSV_flightDistance3dSig;   //!
   TBranch        *b_nTrkTagVarCSV;   //!
   TBranch        *b_nTrkEtaRelTagVarCSV;   //!
   TBranch        *b_TagVarCSV_trackMomentum;   //!
   TBranch        *b_TagVarCSV_trackEta;   //!
   TBranch        *b_TagVarCSV_trackPhi;   //!
   TBranch        *b_TagVarCSV_trackPtRel;   //!
   TBranch        *b_TagVarCSV_trackPPar;   //!
   TBranch        *b_TagVarCSV_trackDeltaR;   //!
   TBranch        *b_TagVarCSV_trackPtRatio;   //!
   TBranch        *b_TagVarCSV_trackPParRatio;   //!
   TBranch        *b_TagVarCSV_trackSip2dVal;   //!
   TBranch        *b_TagVarCSV_trackSip2dSig;   //!
   TBranch        *b_TagVarCSV_trackSip3dVal;   //!
   TBranch        *b_TagVarCSV_trackSip3dSig;   //!
   TBranch        *b_TagVarCSV_trackDecayLenVal;   //!
   TBranch        *b_TagVarCSV_trackDecayLenSig;   //!
   TBranch        *b_TagVarCSV_trackJetDistVal;   //!
   TBranch        *b_TagVarCSV_trackJetDistSig;   //!
   TBranch        *b_TagVarCSV_trackEtaRel;   //!

   Tree(TChain *ch=0,char* fname="physics.root",std::string treename="physics");
   virtual ~Tree();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *tree);
   virtual void     registerInputBranches(TChain *tree);
};

}
   
#endif
