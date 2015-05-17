#include "TreeClassTTbar.h"

////LTANA::TreeClass::TreeClass(TChain *ch,TTree *tree,char *fname,std::string treename)
LTANA::TreeClassTTbar::TreeClassTTbar(TChain *ch,char *fname,std::string treename)
{
////   std::string fnameStr = std::string(fname);

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
   
////   TFile *f = TFile::Open(fnameStr.c_str());
////   tree = (TTree*)f->Get(treename.c_str());
////   Init(tree);
}

LTANA::TreeClassTTbar::~TreeClassTTbar()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t LTANA::TreeClassTTbar::GetEntry(Long64_t entry)
{
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

Long64_t LTANA::TreeClassTTbar::LoadTree(Long64_t entry)
{
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
   }
   return centry;
}

/////void LTANA::TreeClass::registerInputBranches(TTree *tr)
void LTANA::TreeClassTTbar::registerInputBranches(TChain *tr)
{
   tr->SetBranchStatus("*",1);
   
   std::cout << "Successfully initialized input branches" << std::endl;
}

void LTANA::TreeClassTTbar::Init(TChain *tree)
{
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("BitTrigger", &BitTrigger, &b_BitTrigger);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Run", &Run, &b_Run);
   fChain->SetBranchAddress("Evt", &Evt, &b_Evt);
   fChain->SetBranchAddress("LumiBlock", &LumiBlock, &b_LumiBlock);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("pthat", &pthat, &b_pthat);
   fChain->SetBranchAddress("PVzSim", &PVzSim, &b_PVzSim);
   fChain->SetBranchAddress("nPUtrue", &nPUtrue, &b_nPUtrue);
   fChain->SetBranchAddress("nPU", &nPU, &b_nPU);
   fChain->SetBranchAddress("ttbar_chan", &ttbar_chan, &b_ttbar_chan);
   fChain->SetBranchAddress("lepton1_pT", &lepton1_pT, &b_lepton1_pT);
   fChain->SetBranchAddress("lepton1_eta", &lepton1_eta, &b_lepton1_eta);
   fChain->SetBranchAddress("lepton1_phi", &lepton1_phi, &b_lepton1_phi);
   fChain->SetBranchAddress("lepton2_pT", &lepton2_pT, &b_lepton2_pT);
   fChain->SetBranchAddress("lepton2_eta", &lepton2_eta, &b_lepton2_eta);
   fChain->SetBranchAddress("lepton2_phi", &lepton2_phi, &b_lepton2_phi);
   fChain->SetBranchAddress("met", &met, &b_met);
   fChain->SetBranchAddress("mll", &mll, &b_mll);
   fChain->SetBranchAddress("trig_ttbar", &trig_ttbar, &b_trig_ttbar);
   fChain->SetBranchAddress("nTrack", &nTrack, &b_nTrack);
   fChain->SetBranchAddress("Track_dxy", Track_dxy, &b_Track_dxy);
   fChain->SetBranchAddress("Track_dz", Track_dz, &b_Track_dz);
   fChain->SetBranchAddress("Track_zIP", Track_zIP, &b_Track_zIP);
   fChain->SetBranchAddress("Track_length", Track_length, &b_Track_length);
   fChain->SetBranchAddress("Track_dist", Track_dist, &b_Track_dist);
   fChain->SetBranchAddress("Track_IP2D", Track_IP2D, &b_Track_IP2D);
   fChain->SetBranchAddress("Track_IP2Dsig", Track_IP2Dsig, &b_Track_IP2Dsig);
   fChain->SetBranchAddress("Track_IP2Derr", Track_IP2Derr, &b_Track_IP2Derr);
   fChain->SetBranchAddress("Track_IP", Track_IP, &b_Track_IP);
   fChain->SetBranchAddress("Track_IPsig", Track_IPsig, &b_Track_IPsig);
   fChain->SetBranchAddress("Track_IPerr", Track_IPerr, &b_Track_IPerr);
   fChain->SetBranchAddress("Track_Proba", Track_Proba, &b_Track_Proba);
   fChain->SetBranchAddress("Track_p", Track_p, &b_Track_p);
   fChain->SetBranchAddress("Track_pt", Track_pt, &b_Track_pt);
   fChain->SetBranchAddress("Track_eta", Track_eta, &b_Track_eta);
   fChain->SetBranchAddress("Track_phi", Track_phi, &b_Track_phi);
   fChain->SetBranchAddress("Track_chi2", Track_chi2, &b_Track_chi2);
   fChain->SetBranchAddress("Track_charge", Track_charge, &b_Track_charge);
   fChain->SetBranchAddress("Track_history", Track_history, &b_Track_history);
   fChain->SetBranchAddress("Track_nHitStrip", Track_nHitStrip, &b_Track_nHitStrip);
   fChain->SetBranchAddress("Track_nHitPixel", Track_nHitPixel, &b_Track_nHitPixel);
   fChain->SetBranchAddress("Track_nHitAll", Track_nHitAll, &b_Track_nHitAll);
   fChain->SetBranchAddress("Track_nHitTIB", Track_nHitTIB, &b_Track_nHitTIB);
   fChain->SetBranchAddress("Track_nHitTID", Track_nHitTID, &b_Track_nHitTID);
   fChain->SetBranchAddress("Track_nHitTOB", Track_nHitTOB, &b_Track_nHitTOB);
   fChain->SetBranchAddress("Track_nHitTEC", Track_nHitTEC, &b_Track_nHitTEC);
   fChain->SetBranchAddress("Track_nHitPXB", Track_nHitPXB, &b_Track_nHitPXB);
   fChain->SetBranchAddress("Track_nHitPXF", Track_nHitPXF, &b_Track_nHitPXF);
   fChain->SetBranchAddress("Track_isHitL1", Track_isHitL1, &b_Track_isHitL1);
   fChain->SetBranchAddress("Track_PV", Track_PV, &b_Track_PV);
   fChain->SetBranchAddress("Track_SV", Track_SV, &b_Track_SV);
   fChain->SetBranchAddress("Track_PVweight", Track_PVweight, &b_Track_PVweight);
   fChain->SetBranchAddress("Track_SVweight", Track_SVweight, &b_Track_SVweight);
   fChain->SetBranchAddress("Track_isfromSV", Track_isfromSV, &b_Track_isfromSV);
   fChain->SetBranchAddress("Track_category", Track_category, &b_Track_category);
   fChain->SetBranchAddress("PV_x", PV_x, &b_PV_x);
   fChain->SetBranchAddress("PV_y", PV_y, &b_PV_y);
   fChain->SetBranchAddress("PV_z", PV_z, &b_PV_z);
   fChain->SetBranchAddress("PV_ex", PV_ex, &b_PV_ex);
   fChain->SetBranchAddress("PV_ey", PV_ey, &b_PV_ey);
   fChain->SetBranchAddress("PV_ez", PV_ez, &b_PV_ez);
   fChain->SetBranchAddress("PV_chi2", PV_chi2, &b_PV_chi2);
   fChain->SetBranchAddress("PV_ndf", PV_ndf, &b_PV_ndf);
   fChain->SetBranchAddress("PV_isgood", PV_isgood, &b_PV_isgood);
   fChain->SetBranchAddress("PV_isfake", PV_isfake, &b_PV_isfake);
   fChain->SetBranchAddress("nSV", &nSV, &b_nSV);
   fChain->SetBranchAddress("SV_x", SV_x, &b_SV_x);
   fChain->SetBranchAddress("SV_y", SV_y, &b_SV_y);
   fChain->SetBranchAddress("SV_z", SV_z, &b_SV_z);
   fChain->SetBranchAddress("SV_ex", SV_ex, &b_SV_ex);
   fChain->SetBranchAddress("SV_ey", SV_ey, &b_SV_ey);
   fChain->SetBranchAddress("SV_ez", SV_ez, &b_SV_ez);
   fChain->SetBranchAddress("SV_chi2", SV_chi2, &b_SV_chi2);
   fChain->SetBranchAddress("SV_ndf", SV_ndf, &b_SV_ndf);
   fChain->SetBranchAddress("SV_flight", SV_flight, &b_SV_flight);
   fChain->SetBranchAddress("SV_flightErr", SV_flightErr, &b_SV_flightErr);
   fChain->SetBranchAddress("SV_deltaR_jet", SV_deltaR_jet, &b_SV_deltaR_jet);
   fChain->SetBranchAddress("SV_deltaR_sum_jet", SV_deltaR_sum_jet, &b_SV_deltaR_sum_jet);
   fChain->SetBranchAddress("SV_deltaR_sum_dir", SV_deltaR_sum_dir, &b_SV_deltaR_sum_dir);
   fChain->SetBranchAddress("SV_energy_ratio", SV_energy_ratio, &b_SV_energy_ratio);
   fChain->SetBranchAddress("SV_aboveC", SV_aboveC, &b_SV_aboveC);
   fChain->SetBranchAddress("SV_vtx_pt", SV_vtx_pt, &b_SV_vtx_pt);
   fChain->SetBranchAddress("SV_flight2D", SV_flight2D, &b_SV_flight2D);
   fChain->SetBranchAddress("SV_flight2DErr", SV_flight2DErr, &b_SV_flight2DErr);
   fChain->SetBranchAddress("SV_totCharge", SV_totCharge, &b_SV_totCharge);
   fChain->SetBranchAddress("SV_vtxDistJetAxis", SV_vtxDistJetAxis, &b_SV_vtxDistJetAxis);
   fChain->SetBranchAddress("SV_nTrk", SV_nTrk, &b_SV_nTrk);
   fChain->SetBranchAddress("SV_nTrk_firstVxt", SV_nTrk_firstVxt, &b_SV_nTrk_firstVxt);
   fChain->SetBranchAddress("SV_mass", SV_mass, &b_SV_mass);
   fChain->SetBranchAddress("SV_vtx_eta", SV_vtx_eta, &b_SV_vtx_eta);
   fChain->SetBranchAddress("SV_vtx_phi", SV_vtx_phi, &b_SV_vtx_phi);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_genpt", Jet_genpt, &b_Jet_genpt);
   fChain->SetBranchAddress("Jet_residual", Jet_residual, &b_Jet_residual);
   fChain->SetBranchAddress("Jet_jes", Jet_jes, &b_Jet_jes);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_ntracks", Jet_ntracks, &b_Jet_ntracks);
   fChain->SetBranchAddress("Jet_flavour", Jet_flavour, &b_Jet_flavour);
   fChain->SetBranchAddress("Jet_Ip2N", Jet_Ip2N, &b_Jet_Ip2N);
   fChain->SetBranchAddress("Jet_Ip2P", Jet_Ip2P, &b_Jet_Ip2P);
   fChain->SetBranchAddress("Jet_Ip3N", Jet_Ip3N, &b_Jet_Ip3N);
   fChain->SetBranchAddress("Jet_Ip3P", Jet_Ip3P, &b_Jet_Ip3P);
   fChain->SetBranchAddress("Jet_ProbaN", Jet_ProbaN, &b_Jet_ProbaN);
   fChain->SetBranchAddress("Jet_ProbaP", Jet_ProbaP, &b_Jet_ProbaP);
   fChain->SetBranchAddress("Jet_BprobN", Jet_BprobN, &b_Jet_BprobN);
   fChain->SetBranchAddress("Jet_BprobP", Jet_BprobP, &b_Jet_BprobP);
   fChain->SetBranchAddress("Jet_SvxN", Jet_SvxN, &b_Jet_SvxN);
   fChain->SetBranchAddress("Jet_Svx", Jet_Svx, &b_Jet_Svx);
   fChain->SetBranchAddress("Jet_SvxNHP", Jet_SvxNHP, &b_Jet_SvxNHP);
   fChain->SetBranchAddress("Jet_SvxHP", Jet_SvxHP, &b_Jet_SvxHP);
   fChain->SetBranchAddress("Jet_SvxMass", Jet_SvxMass, &b_Jet_SvxMass);
   fChain->SetBranchAddress("Jet_CombSvxN", Jet_CombSvxN, &b_Jet_CombSvxN);
   fChain->SetBranchAddress("Jet_CombSvxP", Jet_CombSvxP, &b_Jet_CombSvxP);
   fChain->SetBranchAddress("Jet_CombSvx", Jet_CombSvx, &b_Jet_CombSvx);
   fChain->SetBranchAddress("Jet_RetCombSvxN", Jet_RetCombSvxN, &b_Jet_RetCombSvxN);
   fChain->SetBranchAddress("Jet_RetCombSvxP", Jet_RetCombSvxP, &b_Jet_RetCombSvxP);
   fChain->SetBranchAddress("Jet_RetCombSvx", Jet_RetCombSvx, &b_Jet_RetCombSvx);
   fChain->SetBranchAddress("Jet_CombCSVJP_N", Jet_CombCSVJP_N, &b_Jet_CombCSVJP_N);
   fChain->SetBranchAddress("Jet_CombCSVJP_P", Jet_CombCSVJP_P, &b_Jet_CombCSVJP_P);
   fChain->SetBranchAddress("Jet_CombCSVJP", Jet_CombCSVJP, &b_Jet_CombCSVJP);
   fChain->SetBranchAddress("Jet_CombCSVSL_N", Jet_CombCSVSL_N, &b_Jet_CombCSVSL_N);
   fChain->SetBranchAddress("Jet_CombCSVSL_P", Jet_CombCSVSL_P, &b_Jet_CombCSVSL_P);
   fChain->SetBranchAddress("Jet_CombCSVSL", Jet_CombCSVSL, &b_Jet_CombCSVSL);
   fChain->SetBranchAddress("Jet_CombCSVJPSL_N", Jet_CombCSVJPSL_N, &b_Jet_CombCSVJPSL_N);
   fChain->SetBranchAddress("Jet_CombCSVJPSL_P", Jet_CombCSVJPSL_P, &b_Jet_CombCSVJPSL_P);
   fChain->SetBranchAddress("Jet_CombCSVJPSL", Jet_CombCSVJPSL, &b_Jet_CombCSVJPSL);
   fChain->SetBranchAddress("Jet_SimpIVF_HP", Jet_SimpIVF_HP, &b_Jet_SimpIVF_HP);
   fChain->SetBranchAddress("Jet_SimpIVF_HE", Jet_SimpIVF_HE, &b_Jet_SimpIVF_HE);
   fChain->SetBranchAddress("Jet_DoubIVF_HE", Jet_DoubIVF_HE, &b_Jet_DoubIVF_HE);
   fChain->SetBranchAddress("Jet_CombIVF", Jet_CombIVF, &b_Jet_CombIVF);
   fChain->SetBranchAddress("Jet_CombIVF_P", Jet_CombIVF_P, &b_Jet_CombIVF_P);
   fChain->SetBranchAddress("Jet_SoftMuN", Jet_SoftMuN, &b_Jet_SoftMuN);
   fChain->SetBranchAddress("Jet_SoftMuP", Jet_SoftMuP, &b_Jet_SoftMuP);
   fChain->SetBranchAddress("Jet_SoftMu", Jet_SoftMu, &b_Jet_SoftMu);
   fChain->SetBranchAddress("Jet_SoftElN", Jet_SoftElN, &b_Jet_SoftElN);
   fChain->SetBranchAddress("Jet_SoftElP", Jet_SoftElP, &b_Jet_SoftElP);
   fChain->SetBranchAddress("Jet_SoftEl", Jet_SoftEl, &b_Jet_SoftEl);
   fChain->SetBranchAddress("Jet_hist1", Jet_hist1, &b_Jet_hist1);
   fChain->SetBranchAddress("Jet_hist2", Jet_hist2, &b_Jet_hist2);
   fChain->SetBranchAddress("Jet_hist3", Jet_hist3, &b_Jet_hist3);
   fChain->SetBranchAddress("Jet_histJet", Jet_histJet, &b_Jet_histJet);
   fChain->SetBranchAddress("Jet_histSvx", Jet_histSvx, &b_Jet_histSvx);
   fChain->SetBranchAddress("Jet_nFirstTrack", Jet_nFirstTrack, &b_Jet_nFirstTrack);
   fChain->SetBranchAddress("Jet_nLastTrack", Jet_nLastTrack, &b_Jet_nLastTrack);
   fChain->SetBranchAddress("Jet_nFirstSV", Jet_nFirstSV, &b_Jet_nFirstSV);
   fChain->SetBranchAddress("Jet_nLastSV", Jet_nLastSV, &b_Jet_nLastSV);
   fChain->SetBranchAddress("Jet_SV_multi", Jet_SV_multi, &b_Jet_SV_multi);
   fChain->SetBranchAddress("Jet_nFirstTrkInc", Jet_nFirstTrkInc, &b_Jet_nFirstTrkInc);
   fChain->SetBranchAddress("Jet_nLastTrkInc", Jet_nLastTrkInc, &b_Jet_nLastTrkInc);
   fChain->SetBranchAddress("Jet_VtxCat", Jet_VtxCat, &b_Jet_VtxCat);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("Muon_IdxJet", Muon_IdxJet, &b_Muon_IdxJet);
   fChain->SetBranchAddress("Muon_nMuHit", Muon_nMuHit, &b_Muon_nMuHit);
   fChain->SetBranchAddress("Muon_nTkHit", Muon_nTkHit, &b_Muon_nTkHit);
   fChain->SetBranchAddress("Muon_nPixHit", Muon_nPixHit, &b_Muon_nPixHit);
   fChain->SetBranchAddress("Muon_nOutHit", Muon_nOutHit, &b_Muon_nOutHit);
   fChain->SetBranchAddress("Muon_isGlobal", Muon_isGlobal, &b_Muon_isGlobal);
   fChain->SetBranchAddress("Muon_nMatched", Muon_nMatched, &b_Muon_nMatched);
   fChain->SetBranchAddress("Muon_chi2", Muon_chi2, &b_Muon_chi2);
   fChain->SetBranchAddress("Muon_chi2Tk", Muon_chi2Tk, &b_Muon_chi2Tk);
   fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon_ptrel", Muon_ptrel, &b_Muon_ptrel);
   fChain->SetBranchAddress("Muon_vz", Muon_vz, &b_Muon_vz);
   fChain->SetBranchAddress("Muon_hist", Muon_hist, &b_Muon_hist);
   fChain->SetBranchAddress("Muon_IPsig", Muon_IPsig, &b_Muon_IPsig);
   fChain->SetBranchAddress("Muon_IP", Muon_IP, &b_Muon_IP);
   fChain->SetBranchAddress("Muon_IP2Dsig", Muon_IP2Dsig, &b_Muon_IP2Dsig);
   fChain->SetBranchAddress("Muon_IP2D", Muon_IP2D, &b_Muon_IP2D);
   fChain->SetBranchAddress("Muon_Proba", Muon_Proba, &b_Muon_Proba);
   fChain->SetBranchAddress("Muon_deltaR", Muon_deltaR, &b_Muon_deltaR);
   fChain->SetBranchAddress("Muon_ratio", Muon_ratio, &b_Muon_ratio);
   fChain->SetBranchAddress("nPFElectron", &nPFElectron, &b_nPFElectron);
   fChain->SetBranchAddress("PFElectron_IdxJet", PFElectron_IdxJet, &b_PFElectron_IdxJet);
   fChain->SetBranchAddress("PFElectron_pt", PFElectron_pt, &b_PFElectron_pt);
   fChain->SetBranchAddress("PFElectron_eta", PFElectron_eta, &b_PFElectron_eta);
   fChain->SetBranchAddress("PFElectron_phi", PFElectron_phi, &b_PFElectron_phi);
   fChain->SetBranchAddress("PFElectron_ptrel", PFElectron_ptrel, &b_PFElectron_ptrel);
   fChain->SetBranchAddress("PFElectron_deltaR", PFElectron_deltaR, &b_PFElectron_deltaR);
   fChain->SetBranchAddress("PFElectron_ratio", PFElectron_ratio, &b_PFElectron_ratio);
   fChain->SetBranchAddress("PFElectron_ratioRel", PFElectron_ratioRel, &b_PFElectron_ratioRel);
   fChain->SetBranchAddress("PFElectron_IPsig", PFElectron_IPsig, &b_PFElectron_IPsig);
   fChain->SetBranchAddress("nPFMuon", &nPFMuon, &b_nPFMuon);
   fChain->SetBranchAddress("PFMuon_IdxJet", PFMuon_IdxJet, &b_PFMuon_IdxJet);
   fChain->SetBranchAddress("PFMuon_pt", PFMuon_pt, &b_PFMuon_pt);
   fChain->SetBranchAddress("PFMuon_eta", PFMuon_eta, &b_PFMuon_eta);
   fChain->SetBranchAddress("PFMuon_phi", PFMuon_phi, &b_PFMuon_phi);
   fChain->SetBranchAddress("PFMuon_ptrel", PFMuon_ptrel, &b_PFMuon_ptrel);
   fChain->SetBranchAddress("PFMuon_deltaR", PFMuon_deltaR, &b_PFMuon_deltaR);
   fChain->SetBranchAddress("PFMuon_ratio", PFMuon_ratio, &b_PFMuon_ratio);
   fChain->SetBranchAddress("PFMuon_ratioRel", PFMuon_ratioRel, &b_PFMuon_ratioRel);
   fChain->SetBranchAddress("PFMuon_IPsig", PFMuon_IPsig, &b_PFMuon_IPsig);
   fChain->SetBranchAddress("PFMuon_GoodQuality", PFMuon_GoodQuality, &b_PFMuon_GoodQuality);
   fChain->SetBranchAddress("nTrkInc", &nTrkInc, &b_nTrkInc);
   fChain->SetBranchAddress("TrkInc_pt", &TrkInc_pt, &b_TrkInc_pt);
   fChain->SetBranchAddress("TrkInc_eta", &TrkInc_eta, &b_TrkInc_eta);
   fChain->SetBranchAddress("TrkInc_phi", &TrkInc_phi, &b_TrkInc_phi);
   fChain->SetBranchAddress("TrkInc_ptrel", &TrkInc_ptrel, &b_TrkInc_ptrel);
   fChain->SetBranchAddress("TrkInc_IPsig", &TrkInc_IPsig, &b_TrkInc_IPsig);
   fChain->SetBranchAddress("TrkInc_IP", &TrkInc_IP, &b_TrkInc_IP);
   fChain->SetBranchAddress("nCFromGSplit", &nCFromGSplit, &b_nCFromGSplit);
   fChain->SetBranchAddress("cFromGSplit_pT", &cFromGSplit_pT, &b_cFromGSplit_pT);
   fChain->SetBranchAddress("cFromGSplit_eta", &cFromGSplit_eta, &b_cFromGSplit_eta);
   fChain->SetBranchAddress("cFromGSplit_phi", &cFromGSplit_phi, &b_cFromGSplit_phi);
   fChain->SetBranchAddress("nBFromGSplit", &nBFromGSplit, &b_nBFromGSplit);
   fChain->SetBranchAddress("bFromGSplit_pT", &bFromGSplit_pT, &b_bFromGSplit_pT);
   fChain->SetBranchAddress("bFromGSplit_eta", &bFromGSplit_eta, &b_bFromGSplit_eta);
   fChain->SetBranchAddress("bFromGSplit_phi", &bFromGSplit_phi, &b_bFromGSplit_phi);
   fChain->SetBranchAddress("mcweight", &mcweight, &b_mcweight);
   fChain->SetBranchAddress("nBHadrons", &nBHadrons, &b_nBHadrons);
   fChain->SetBranchAddress("BHadron_pT", &BHadron_pT, &b_BHadron_pT);
   fChain->SetBranchAddress("BHadron_eta", &BHadron_eta, &b_BHadron_eta);
   fChain->SetBranchAddress("BHadron_phi", &BHadron_phi, &b_BHadron_phi);
   fChain->SetBranchAddress("BHadron_mass", &BHadron_mass, &b_BHadron_mass);
   fChain->SetBranchAddress("BHadron_pdgID", &BHadron_pdgID, &b_BHadron_pdgID);
   fChain->SetBranchAddress("nGenlep", &nGenlep, &b_nGenlep);
   fChain->SetBranchAddress("Genlep_pT", &Genlep_pT, &b_Genlep_pT);
   fChain->SetBranchAddress("Genlep_eta", &Genlep_eta, &b_Genlep_eta);
   fChain->SetBranchAddress("Genlep_phi", &Genlep_phi, &b_Genlep_phi);
   fChain->SetBranchAddress("Genlep_pdgID", &Genlep_pdgID, &b_Genlep_pdgID);
   fChain->SetBranchAddress("Genlep_mother", &Genlep_mother, &b_Genlep_mother);
   fChain->SetBranchAddress("nGenquark", &nGenquark, &b_nGenquark);
   fChain->SetBranchAddress("Genquark_pT", &Genquark_pT, &b_Genquark_pT);
   fChain->SetBranchAddress("Genquark_eta", &Genquark_eta, &b_Genquark_eta);
   fChain->SetBranchAddress("Genquark_phi", &Genquark_phi, &b_Genquark_phi);
   fChain->SetBranchAddress("Genquark_pdgID", &Genquark_pdgID, &b_Genquark_pdgID);
   fChain->SetBranchAddress("Genquark_mother", &Genquark_mother, &b_Genquark_mother);
}
