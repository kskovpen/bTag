#include "../include/Tree.h"

LTANA::Tree::Tree(TChain *ch,char *fname,std::string treename)
{
   ch = new TChain(treename.c_str());
   
   std::ifstream infile;
   infile.open(fname);
   std::string ifile = "";
   while( getline(infile, ifile) )
     {	
	std::string fnameStr = std::string(ifile);

	ch->Add(fnameStr.c_str());
	std::cout << "file: " << fnameStr << std::endl;
     }   
   infile.close();
   Init(ch);
}

LTANA::Tree::~Tree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t LTANA::Tree::GetEntry(Long64_t entry)
{
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

Long64_t LTANA::Tree::LoadTree(Long64_t entry)
{
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
   }
   return centry;
}

void LTANA::Tree::registerInputBranches(TChain *tr)
{
   tr->SetBranchStatus("*",1);
   
   std::cout << "Successfully initialized input branches" << std::endl;
}

void LTANA::Tree::Init(TChain *tree)
{
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;

   fChain->SetBranchAddress("nBitTrigger", &nBitTrigger, &b_nBitTrigger);
   fChain->SetBranchAddress("BitTrigger", BitTrigger, &b_BitTrigger);
   fChain->SetBranchAddress("Run", &Run, &b_Run);
   fChain->SetBranchAddress("Evt", &Evt, &b_Evt);
   fChain->SetBranchAddress("LumiBlock", &LumiBlock, &b_LumiBlock);
   fChain->SetBranchAddress("pthat", &pthat, &b_pthat);
   fChain->SetBranchAddress("mcweight", &mcweight, &b_mcweight);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("PVez", &PVez, &b_PVez);
   fChain->SetBranchAddress("GenPVz", &GenPVz, &b_GenPVz);
   fChain->SetBranchAddress("nPUtrue", &nPUtrue, &b_nPUtrue);
   fChain->SetBranchAddress("nPU", &nPU, &b_nPU);
   fChain->SetBranchAddress("PU_bunch", PU_bunch, &b_PU_bunch);
   fChain->SetBranchAddress("PU_z", PU_z, &b_PU_z);
   fChain->SetBranchAddress("PU_sumpT_low", PU_sumpT_low, &b_PU_sumpT_low);
   fChain->SetBranchAddress("PU_sumpT_high", PU_sumpT_high, &b_PU_sumpT_high);
   fChain->SetBranchAddress("PU_ntrks_low", PU_ntrks_low, &b_PU_ntrks_low);
   fChain->SetBranchAddress("PU_ntrks_high", PU_ntrks_high, &b_PU_ntrks_high);
   fChain->SetBranchAddress("ncQuarks", &ncQuarks, &b_ncQuarks);
   fChain->SetBranchAddress("cQuark_pT", cQuark_pT, &b_cQuark_pT);
   fChain->SetBranchAddress("cQuark_eta", cQuark_eta, &b_cQuark_eta);
   fChain->SetBranchAddress("cQuark_phi", cQuark_phi, &b_cQuark_phi);
   fChain->SetBranchAddress("cQuark_pdgID", cQuark_pdgID, &b_cQuark_pdgID);
   fChain->SetBranchAddress("cQuark_status", cQuark_status, &b_cQuark_status);
   fChain->SetBranchAddress("cQuark_fromGSP", cQuark_fromGSP, &b_cQuark_fromGSP);
   fChain->SetBranchAddress("nbQuarks", &nbQuarks, &b_nbQuarks);
   fChain->SetBranchAddress("bQuark_pT", bQuark_pT, &b_bQuark_pT);
   fChain->SetBranchAddress("bQuark_eta", bQuark_eta, &b_bQuark_eta);
   fChain->SetBranchAddress("bQuark_phi", bQuark_phi, &b_bQuark_phi);
   fChain->SetBranchAddress("bQuark_pdgID", bQuark_pdgID, &b_bQuark_pdgID);
   fChain->SetBranchAddress("bQuark_status", bQuark_status, &b_bQuark_status);
   fChain->SetBranchAddress("bQuark_fromGSP", bQuark_fromGSP, &b_bQuark_fromGSP);
   fChain->SetBranchAddress("nBHadrons", &nBHadrons, &b_nBHadrons);
   fChain->SetBranchAddress("BHadron_pT", BHadron_pT, &b_BHadron_pT);
   fChain->SetBranchAddress("BHadron_eta", BHadron_eta, &b_BHadron_eta);
   fChain->SetBranchAddress("BHadron_phi", BHadron_phi, &b_BHadron_phi);
   fChain->SetBranchAddress("BHadron_mass", BHadron_mass, &b_BHadron_mass);
   fChain->SetBranchAddress("BHadron_pdgID", BHadron_pdgID, &b_BHadron_pdgID);
   fChain->SetBranchAddress("BHadron_mother", BHadron_mother, &b_BHadron_mother);
   fChain->SetBranchAddress("BHadron_hasBdaughter", BHadron_hasBdaughter, &b_BHadron_hasBdaughter);
   fChain->SetBranchAddress("BHadron_SVx", BHadron_SVx, &b_BHadron_SVx);
   fChain->SetBranchAddress("BHadron_SVy", BHadron_SVy, &b_BHadron_SVy);
   fChain->SetBranchAddress("BHadron_SVz", BHadron_SVz, &b_BHadron_SVz);
   fChain->SetBranchAddress("BHadron_nCharged", BHadron_nCharged, &b_BHadron_nCharged);
   fChain->SetBranchAddress("BHadron_DHadron1", BHadron_DHadron1, &b_BHadron_DHadron1);
   fChain->SetBranchAddress("BHadron_DHadron2", BHadron_DHadron2, &b_BHadron_DHadron2);
   fChain->SetBranchAddress("nDHadrons", &nDHadrons, &b_nDHadrons);
   fChain->SetBranchAddress("nDaughters", &nDaughters, &b_nDaughters);
   fChain->SetBranchAddress("DHadron_pT", DHadron_pT, &b_DHadron_pT);
   fChain->SetBranchAddress("DHadron_eta", DHadron_eta, &b_DHadron_eta);
   fChain->SetBranchAddress("DHadron_phi", DHadron_phi, &b_DHadron_phi);
   fChain->SetBranchAddress("DHadron_pdgID", DHadron_pdgID, &b_DHadron_pdgID);
   fChain->SetBranchAddress("DHadron_mass", DHadron_mass, &b_DHadron_mass);
   fChain->SetBranchAddress("DHadron_SVx", DHadron_SVx, &b_DHadron_SVx);
   fChain->SetBranchAddress("DHadron_SVy", DHadron_SVy, &b_DHadron_SVy);
   fChain->SetBranchAddress("DHadron_SVz", DHadron_SVz, &b_DHadron_SVz);
   fChain->SetBranchAddress("DHadron_nDaughters", DHadron_nDaughters, &b_DHadron_nDaughters);
   fChain->SetBranchAddress("DHadron_DaughtersPdgID", DHadron_DaughtersPdgID, &b_DHadron_DaughtersPdgID);
   fChain->SetBranchAddress("DHadron_nChargedDaughters", DHadron_nChargedDaughters, &b_DHadron_nChargedDaughters);
   fChain->SetBranchAddress("DHadron_nCharged", DHadron_nCharged, &b_DHadron_nCharged);
   fChain->SetBranchAddress("nGenlep", &nGenlep, &b_nGenlep);
   fChain->SetBranchAddress("Genlep_pT", Genlep_pT, &b_Genlep_pT);
   fChain->SetBranchAddress("Genlep_eta", Genlep_eta, &b_Genlep_eta);
   fChain->SetBranchAddress("Genlep_phi", Genlep_phi, &b_Genlep_phi);
   fChain->SetBranchAddress("Genlep_pdgID", Genlep_pdgID, &b_Genlep_pdgID);
   fChain->SetBranchAddress("Genlep_status", Genlep_status, &b_Genlep_status);
   fChain->SetBranchAddress("Genlep_mother", Genlep_mother, &b_Genlep_mother);
   fChain->SetBranchAddress("nGenquark", &nGenquark, &b_nGenquark);
   fChain->SetBranchAddress("Genquark_pT", Genquark_pT, &b_Genquark_pT);
   fChain->SetBranchAddress("Genquark_eta", Genquark_eta, &b_Genquark_eta);
   fChain->SetBranchAddress("Genquark_phi", Genquark_phi, &b_Genquark_phi);
   fChain->SetBranchAddress("Genquark_pdgID", Genquark_pdgID, &b_Genquark_pdgID);
   fChain->SetBranchAddress("Genquark_mother", Genquark_mother, &b_Genquark_mother);
   fChain->SetBranchAddress("nGenPruned", &nGenPruned, &b_nGenPruned);
   fChain->SetBranchAddress("GenPruned_pT", GenPruned_pT, &b_GenPruned_pT);
   fChain->SetBranchAddress("GenPruned_eta", GenPruned_eta, &b_GenPruned_eta);
   fChain->SetBranchAddress("GenPruned_phi", GenPruned_phi, &b_GenPruned_phi);
   fChain->SetBranchAddress("GenPruned_mass", GenPruned_mass, &b_GenPruned_mass);
   fChain->SetBranchAddress("GenPruned_pdgID", GenPruned_pdgID, &b_GenPruned_pdgID);
   fChain->SetBranchAddress("GenPruned_status", GenPruned_status, &b_GenPruned_status);
   fChain->SetBranchAddress("GenPruned_mother", GenPruned_mother, &b_GenPruned_mother);
   fChain->SetBranchAddress("nGenV0", &nGenV0, &b_nGenV0);
   fChain->SetBranchAddress("GenV0_pT", GenV0_pT, &b_GenV0_pT);
   fChain->SetBranchAddress("GenV0_eta", GenV0_eta, &b_GenV0_eta);
   fChain->SetBranchAddress("GenV0_phi", GenV0_phi, &b_GenV0_phi);
   fChain->SetBranchAddress("GenV0_pdgID", GenV0_pdgID, &b_GenV0_pdgID);
   fChain->SetBranchAddress("GenV0_SVx", GenV0_SVx, &b_GenV0_SVx);
   fChain->SetBranchAddress("GenV0_SVy", GenV0_SVy, &b_GenV0_SVy);
   fChain->SetBranchAddress("GenV0_SVz", GenV0_SVz, &b_GenV0_SVz);
   fChain->SetBranchAddress("GenV0_nCharged", GenV0_nCharged, &b_GenV0_nCharged);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_genpt", Jet_genpt, &b_Jet_genpt);
   fChain->SetBranchAddress("Jet_residual", Jet_residual, &b_Jet_residual);
   fChain->SetBranchAddress("Jet_jes", Jet_jes, &b_Jet_jes);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_mass", Jet_mass, &b_Jet_mass);
   fChain->SetBranchAddress("Jet_ntracks", Jet_ntracks, &b_Jet_ntracks);
   fChain->SetBranchAddress("Jet_nseltracks", Jet_nseltracks, &b_Jet_nseltracks);
   fChain->SetBranchAddress("Jet_flavour", Jet_flavour, &b_Jet_flavour);
   fChain->SetBranchAddress("Jet_nbHadrons", Jet_nbHadrons, &b_Jet_nbHadrons);
   fChain->SetBranchAddress("Jet_ncHadrons", Jet_ncHadrons, &b_Jet_ncHadrons);
   fChain->SetBranchAddress("Jet_Ip2N", Jet_Ip2N, &b_Jet_Ip2N);
   fChain->SetBranchAddress("Jet_Ip2P", Jet_Ip2P, &b_Jet_Ip2P);
   fChain->SetBranchAddress("Jet_Ip3N", Jet_Ip3N, &b_Jet_Ip3N);
   fChain->SetBranchAddress("Jet_Ip3P", Jet_Ip3P, &b_Jet_Ip3P);
   fChain->SetBranchAddress("Jet_ProbaN", Jet_ProbaN, &b_Jet_ProbaN);
   fChain->SetBranchAddress("Jet_ProbaP", Jet_ProbaP, &b_Jet_ProbaP);
   fChain->SetBranchAddress("Jet_Proba", Jet_Proba, &b_Jet_Proba);
   fChain->SetBranchAddress("Jet_BprobN", Jet_BprobN, &b_Jet_BprobN);
   fChain->SetBranchAddress("Jet_BprobP", Jet_BprobP, &b_Jet_BprobP);
   fChain->SetBranchAddress("Jet_Bprob", Jet_Bprob, &b_Jet_Bprob);
   fChain->SetBranchAddress("Jet_SvxN", Jet_SvxN, &b_Jet_SvxN);
   fChain->SetBranchAddress("Jet_Svx", Jet_Svx, &b_Jet_Svx);
   fChain->SetBranchAddress("Jet_SvxNHP", Jet_SvxNHP, &b_Jet_SvxNHP);
   fChain->SetBranchAddress("Jet_SvxHP", Jet_SvxHP, &b_Jet_SvxHP);
   fChain->SetBranchAddress("Jet_CombSvxN", Jet_CombSvxN, &b_Jet_CombSvxN);
   fChain->SetBranchAddress("Jet_CombSvxP", Jet_CombSvxP, &b_Jet_CombSvxP);
   fChain->SetBranchAddress("Jet_CombSvx", Jet_CombSvx, &b_Jet_CombSvx);
   fChain->SetBranchAddress("Jet_CombIVF", Jet_CombIVF, &b_Jet_CombIVF);
   fChain->SetBranchAddress("Jet_CombIVF_P", Jet_CombIVF_P, &b_Jet_CombIVF_P);
   fChain->SetBranchAddress("Jet_CombIVF_N", Jet_CombIVF_N, &b_Jet_CombIVF_N);
   fChain->SetBranchAddress("Jet_SoftMuN", Jet_SoftMuN, &b_Jet_SoftMuN);
   fChain->SetBranchAddress("Jet_SoftMuP", Jet_SoftMuP, &b_Jet_SoftMuP);
   fChain->SetBranchAddress("Jet_SoftMu", Jet_SoftMu, &b_Jet_SoftMu);
   fChain->SetBranchAddress("Jet_SoftElN", Jet_SoftElN, &b_Jet_SoftElN);
   fChain->SetBranchAddress("Jet_SoftElP", Jet_SoftElP, &b_Jet_SoftElP);
   fChain->SetBranchAddress("Jet_SoftEl", Jet_SoftEl, &b_Jet_SoftEl);
   fChain->SetBranchAddress("Jet_DoubleSV", Jet_DoubleSV, &b_Jet_DoubleSV);
   fChain->SetBranchAddress("Jet_hist1", Jet_hist1, &b_Jet_hist1);
   fChain->SetBranchAddress("Jet_hist2", Jet_hist2, &b_Jet_hist2);
   fChain->SetBranchAddress("Jet_hist3", Jet_hist3, &b_Jet_hist3);
   fChain->SetBranchAddress("Jet_histJet", Jet_histJet, &b_Jet_histJet);
   fChain->SetBranchAddress("Jet_histSvx", Jet_histSvx, &b_Jet_histSvx);
//   fChain->SetBranchAddress("Jet_nFirstTrack", Jet_nFirstTrack, &b_Jet_nFirstTrack);
//   fChain->SetBranchAddress("Jet_nLastTrack", Jet_nLastTrack, &b_Jet_nLastTrack);
//   fChain->SetBranchAddress("Jet_nFirstSV", Jet_nFirstSV, &b_Jet_nFirstSV);
//   fChain->SetBranchAddress("Jet_nLastSV", Jet_nLastSV, &b_Jet_nLastSV);
   fChain->SetBranchAddress("Jet_SV_multi", Jet_SV_multi, &b_Jet_SV_multi);
//   fChain->SetBranchAddress("Jet_nFirstTrkInc", Jet_nFirstTrkInc, &b_Jet_nFirstTrkInc);
//   fChain->SetBranchAddress("Jet_nLastTrkInc", Jet_nLastTrkInc, &b_Jet_nLastTrkInc);
   fChain->SetBranchAddress("Jet_nSM", Jet_nSM, &b_Jet_nSM);
   fChain->SetBranchAddress("Jet_nFirstSM", Jet_nFirstSM, &b_Jet_nFirstSM);
   fChain->SetBranchAddress("Jet_nLastSM", Jet_nLastSM, &b_Jet_nLastSM);
   fChain->SetBranchAddress("Jet_nSE", Jet_nSE, &b_Jet_nSE);
   fChain->SetBranchAddress("Jet_nFirstSE", Jet_nFirstSE, &b_Jet_nFirstSE);
   fChain->SetBranchAddress("Jet_nLastSE", Jet_nLastSE, &b_Jet_nLastSE);
   fChain->SetBranchAddress("Jet_looseID", Jet_looseID, &b_Jet_looseID);
   fChain->SetBranchAddress("Jet_tightID", Jet_tightID, &b_Jet_tightID);
//   fChain->SetBranchAddress("nTrkInc", &nTrkInc, &b_nTrkInc);
//   fChain->SetBranchAddress("TrkInc_pt", &TrkInc_pt, &b_TrkInc_pt);
//   fChain->SetBranchAddress("TrkInc_eta", &TrkInc_eta, &b_TrkInc_eta);
//   fChain->SetBranchAddress("TrkInc_phi", &TrkInc_phi, &b_TrkInc_phi);
//   fChain->SetBranchAddress("TrkInc_ptrel", &TrkInc_ptrel, &b_TrkInc_ptrel);
//   fChain->SetBranchAddress("TrkInc_IPsig", &TrkInc_IPsig, &b_TrkInc_IPsig);
//   fChain->SetBranchAddress("TrkInc_IP", &TrkInc_IP, &b_TrkInc_IP);
   fChain->SetBranchAddress("nPFElectron", &nPFElectron, &b_nPFElectron);
   fChain->SetBranchAddress("PFElectron_IdxJet", PFElectron_IdxJet, &b_PFElectron_IdxJet);
   fChain->SetBranchAddress("PFElectron_pt", PFElectron_pt, &b_PFElectron_pt);
   fChain->SetBranchAddress("PFElectron_eta", PFElectron_eta, &b_PFElectron_eta);
   fChain->SetBranchAddress("PFElectron_phi", PFElectron_phi, &b_PFElectron_phi);
   fChain->SetBranchAddress("PFElectron_ptrel", PFElectron_ptrel, &b_PFElectron_ptrel);
   fChain->SetBranchAddress("PFElectron_deltaR", PFElectron_deltaR, &b_PFElectron_deltaR);
   fChain->SetBranchAddress("PFElectron_ratio", PFElectron_ratio, &b_PFElectron_ratio);
   fChain->SetBranchAddress("PFElectron_ratioRel", PFElectron_ratioRel, &b_PFElectron_ratioRel);
   fChain->SetBranchAddress("PFElectron_IP", PFElectron_IP, &b_PFElectron_IP);
   fChain->SetBranchAddress("PFElectron_IP2D", PFElectron_IP2D, &b_PFElectron_IP2D);
   fChain->SetBranchAddress("nPFMuon", &nPFMuon, &b_nPFMuon);
   fChain->SetBranchAddress("PFMuon_IdxJet", PFMuon_IdxJet, &b_PFMuon_IdxJet);
   fChain->SetBranchAddress("PFMuon_nMuHit", PFMuon_nMuHit, &b_PFMuon_nMuHit);
   fChain->SetBranchAddress("PFMuon_nTkHit", PFMuon_nTkHit, &b_PFMuon_nTkHit);
   fChain->SetBranchAddress("PFMuon_nPixHit", PFMuon_nPixHit, &b_PFMuon_nPixHit);
   fChain->SetBranchAddress("PFMuon_nOutHit", PFMuon_nOutHit, &b_PFMuon_nOutHit);
   fChain->SetBranchAddress("PFMuon_nTkLwM", PFMuon_nTkLwM, &b_PFMuon_nTkLwM);
   fChain->SetBranchAddress("PFMuon_nPixLwM", PFMuon_nPixLwM, &b_PFMuon_nPixLwM);
   fChain->SetBranchAddress("PFMuon_nMatched", PFMuon_nMatched, &b_PFMuon_nMatched);
   fChain->SetBranchAddress("PFMuon_chi2", PFMuon_chi2, &b_PFMuon_chi2);
   fChain->SetBranchAddress("PFMuon_chi2Tk", PFMuon_chi2Tk, &b_PFMuon_chi2Tk);
   fChain->SetBranchAddress("PFMuon_isGlobal", PFMuon_isGlobal, &b_PFMuon_isGlobal);
   fChain->SetBranchAddress("PFMuon_hist", PFMuon_hist, &b_PFMuon_hist);
   fChain->SetBranchAddress("PFMuon_pt", PFMuon_pt, &b_PFMuon_pt);
   fChain->SetBranchAddress("PFMuon_eta", PFMuon_eta, &b_PFMuon_eta);
   fChain->SetBranchAddress("PFMuon_phi", PFMuon_phi, &b_PFMuon_phi);
   fChain->SetBranchAddress("PFMuon_ptrel", PFMuon_ptrel, &b_PFMuon_ptrel);
   fChain->SetBranchAddress("PFMuon_deltaR", PFMuon_deltaR, &b_PFMuon_deltaR);
   fChain->SetBranchAddress("PFMuon_ratio", PFMuon_ratio, &b_PFMuon_ratio);
   fChain->SetBranchAddress("PFMuon_ratioRel", PFMuon_ratioRel, &b_PFMuon_ratioRel);
   fChain->SetBranchAddress("PFMuon_IP", PFMuon_IP, &b_PFMuon_IP);
   fChain->SetBranchAddress("PFMuon_IP2D", PFMuon_IP2D, &b_PFMuon_IP2D);
   fChain->SetBranchAddress("PFMuon_dz", PFMuon_dz, &b_PFMuon_dz);
   fChain->SetBranchAddress("PFMuon_GoodQuality", PFMuon_GoodQuality, &b_PFMuon_GoodQuality);
//   fChain->SetBranchAddress("nSV", &nSV, &b_nSV);
//   fChain->SetBranchAddress("SV_x", SV_x, &b_SV_x);
//   fChain->SetBranchAddress("SV_y", SV_y, &b_SV_y);
//   fChain->SetBranchAddress("SV_z", SV_z, &b_SV_z);
//   fChain->SetBranchAddress("SV_ex", SV_ex, &b_SV_ex);
//   fChain->SetBranchAddress("SV_ey", SV_ey, &b_SV_ey);
//   fChain->SetBranchAddress("SV_ez", SV_ez, &b_SV_ez);
//   fChain->SetBranchAddress("SV_chi2", SV_chi2, &b_SV_chi2);
//   fChain->SetBranchAddress("SV_ndf", SV_ndf, &b_SV_ndf);
//   fChain->SetBranchAddress("SV_flight", SV_flight, &b_SV_flight);
//   fChain->SetBranchAddress("SV_flightErr", SV_flightErr, &b_SV_flightErr);
//   fChain->SetBranchAddress("SV_deltaR_jet", SV_deltaR_jet, &b_SV_deltaR_jet);
//   fChain->SetBranchAddress("SV_deltaR_sum_jet", SV_deltaR_sum_jet, &b_SV_deltaR_sum_jet);
//   fChain->SetBranchAddress("SV_deltaR_sum_dir", SV_deltaR_sum_dir, &b_SV_deltaR_sum_dir);
//   fChain->SetBranchAddress("SV_vtx_pt", SV_vtx_pt, &b_SV_vtx_pt);
//   fChain->SetBranchAddress("SV_flight2D", SV_flight2D, &b_SV_flight2D);
//   fChain->SetBranchAddress("SV_flight2DErr", SV_flight2DErr, &b_SV_flight2DErr);
//   fChain->SetBranchAddress("SV_totCharge", SV_totCharge, &b_SV_totCharge);
//   fChain->SetBranchAddress("SV_vtxDistJetAxis", SV_vtxDistJetAxis, &b_SV_vtxDistJetAxis);
//   fChain->SetBranchAddress("SV_nTrk", SV_nTrk, &b_SV_nTrk);
//   fChain->SetBranchAddress("SV_mass", SV_mass, &b_SV_mass);
//   fChain->SetBranchAddress("SV_vtx_eta", SV_vtx_eta, &b_SV_vtx_eta);
//   fChain->SetBranchAddress("SV_vtx_phi", SV_vtx_phi, &b_SV_vtx_phi);
//   fChain->SetBranchAddress("SV_EnergyRatio", SV_EnergyRatio, &b_SV_EnergyRatio);
//   fChain->SetBranchAddress("SV_dir_x", SV_dir_x, &b_SV_dir_x);
//   fChain->SetBranchAddress("SV_dir_y", SV_dir_y, &b_SV_dir_y);
//   fChain->SetBranchAddress("SV_dir_z", SV_dir_z, &b_SV_dir_z);
//   fChain->SetBranchAddress("Jet_nFirstTrkTagVarCSV", Jet_nFirstTrkTagVarCSV, &b_Jet_nFirstTrkTagVarCSV);
//   fChain->SetBranchAddress("Jet_nLastTrkTagVarCSV", Jet_nLastTrkTagVarCSV, &b_Jet_nLastTrkTagVarCSV);
//   fChain->SetBranchAddress("Jet_nFirstTrkEtaRelTagVarCSV", Jet_nFirstTrkEtaRelTagVarCSV, &b_Jet_nFirstTrkEtaRelTagVarCSV);
//   fChain->SetBranchAddress("Jet_nLastTrkEtaRelTagVarCSV", Jet_nLastTrkEtaRelTagVarCSV, &b_Jet_nLastTrkEtaRelTagVarCSV);
//   fChain->SetBranchAddress("TagVarCSV_trackJetPt", TagVarCSV_trackJetPt, &b_TagVarCSV_trackJetPt);
//   fChain->SetBranchAddress("TagVarCSV_jetNTracks", TagVarCSV_jetNTracks, &b_TagVarCSV_jetNTracks);
//   fChain->SetBranchAddress("TagVarCSV_jetNTracksEtaRel", TagVarCSV_jetNTracksEtaRel, &b_TagVarCSV_jetNTracksEtaRel);
//   fChain->SetBranchAddress("TagVarCSV_trackSumJetEtRatio", TagVarCSV_trackSumJetEtRatio, &b_TagVarCSV_trackSumJetEtRatio);
//   fChain->SetBranchAddress("TagVarCSV_trackSumJetDeltaR", TagVarCSV_trackSumJetDeltaR, &b_TagVarCSV_trackSumJetDeltaR);
//   fChain->SetBranchAddress("TagVarCSV_trackSip2dValAboveCharm", TagVarCSV_trackSip2dValAboveCharm, &b_TagVarCSV_trackSip2dValAboveCharm);
//   fChain->SetBranchAddress("TagVarCSV_trackSip2dSigAboveCharm", TagVarCSV_trackSip2dSigAboveCharm, &b_TagVarCSV_trackSip2dSigAboveCharm);
//   fChain->SetBranchAddress("TagVarCSV_trackSip3dValAboveCharm", TagVarCSV_trackSip3dValAboveCharm, &b_TagVarCSV_trackSip3dValAboveCharm);
//   fChain->SetBranchAddress("TagVarCSV_trackSip3dSigAboveCharm", TagVarCSV_trackSip3dSigAboveCharm, &b_TagVarCSV_trackSip3dSigAboveCharm);
//   fChain->SetBranchAddress("TagVarCSV_vertexCategory", TagVarCSV_vertexCategory, &b_TagVarCSV_vertexCategory);
//   fChain->SetBranchAddress("TagVarCSV_jetNSecondaryVertices", TagVarCSV_jetNSecondaryVertices, &b_TagVarCSV_jetNSecondaryVertices);
//   fChain->SetBranchAddress("TagVarCSV_vertexMass", TagVarCSV_vertexMass, &b_TagVarCSV_vertexMass);
//   fChain->SetBranchAddress("TagVarCSV_vertexNTracks", TagVarCSV_vertexNTracks, &b_TagVarCSV_vertexNTracks);
//   fChain->SetBranchAddress("TagVarCSV_vertexEnergyRatio", TagVarCSV_vertexEnergyRatio, &b_TagVarCSV_vertexEnergyRatio);
//   fChain->SetBranchAddress("TagVarCSV_vertexJetDeltaR", TagVarCSV_vertexJetDeltaR, &b_TagVarCSV_vertexJetDeltaR);
//   fChain->SetBranchAddress("TagVarCSV_flightDistance2dVal", TagVarCSV_flightDistance2dVal, &b_TagVarCSV_flightDistance2dVal);
//   fChain->SetBranchAddress("TagVarCSV_flightDistance2dSig", TagVarCSV_flightDistance2dSig, &b_TagVarCSV_flightDistance2dSig);
//   fChain->SetBranchAddress("TagVarCSV_flightDistance3dVal", TagVarCSV_flightDistance3dVal, &b_TagVarCSV_flightDistance3dVal);
//   fChain->SetBranchAddress("TagVarCSV_flightDistance3dSig", TagVarCSV_flightDistance3dSig, &b_TagVarCSV_flightDistance3dSig);
//   fChain->SetBranchAddress("nTrkTagVarCSV", &nTrkTagVarCSV, &b_nTrkTagVarCSV);
//   fChain->SetBranchAddress("nTrkEtaRelTagVarCSV", &nTrkEtaRelTagVarCSV, &b_nTrkEtaRelTagVarCSV);
//   fChain->SetBranchAddress("TagVarCSV_trackMomentum", TagVarCSV_trackMomentum, &b_TagVarCSV_trackMomentum);
//   fChain->SetBranchAddress("TagVarCSV_trackEta", TagVarCSV_trackEta, &b_TagVarCSV_trackEta);
//   fChain->SetBranchAddress("TagVarCSV_trackPhi", TagVarCSV_trackPhi, &b_TagVarCSV_trackPhi);
//   fChain->SetBranchAddress("TagVarCSV_trackPtRel", TagVarCSV_trackPtRel, &b_TagVarCSV_trackPtRel);
//   fChain->SetBranchAddress("TagVarCSV_trackPPar", TagVarCSV_trackPPar, &b_TagVarCSV_trackPPar);
//   fChain->SetBranchAddress("TagVarCSV_trackDeltaR", TagVarCSV_trackDeltaR, &b_TagVarCSV_trackDeltaR);
//   fChain->SetBranchAddress("TagVarCSV_trackPtRatio", TagVarCSV_trackPtRatio, &b_TagVarCSV_trackPtRatio);
//   fChain->SetBranchAddress("TagVarCSV_trackPParRatio", TagVarCSV_trackPParRatio, &b_TagVarCSV_trackPParRatio);
//   fChain->SetBranchAddress("TagVarCSV_trackSip2dVal", TagVarCSV_trackSip2dVal, &b_TagVarCSV_trackSip2dVal);
//   fChain->SetBranchAddress("TagVarCSV_trackSip2dSig", TagVarCSV_trackSip2dSig, &b_TagVarCSV_trackSip2dSig);
//   fChain->SetBranchAddress("TagVarCSV_trackSip3dVal", TagVarCSV_trackSip3dVal, &b_TagVarCSV_trackSip3dVal);
//   fChain->SetBranchAddress("TagVarCSV_trackSip3dSig", TagVarCSV_trackSip3dSig, &b_TagVarCSV_trackSip3dSig);
//   fChain->SetBranchAddress("TagVarCSV_trackDecayLenVal", TagVarCSV_trackDecayLenVal, &b_TagVarCSV_trackDecayLenVal);
//   fChain->SetBranchAddress("TagVarCSV_trackDecayLenSig", TagVarCSV_trackDecayLenSig, &b_TagVarCSV_trackDecayLenSig);
//   fChain->SetBranchAddress("TagVarCSV_trackJetDistVal", TagVarCSV_trackJetDistVal, &b_TagVarCSV_trackJetDistVal);
//   fChain->SetBranchAddress("TagVarCSV_trackJetDistSig", TagVarCSV_trackJetDistSig, &b_TagVarCSV_trackJetDistSig);
//   fChain->SetBranchAddress("TagVarCSV_trackEtaRel", TagVarCSV_trackEtaRel, &b_TagVarCSV_trackEtaRel);
}
