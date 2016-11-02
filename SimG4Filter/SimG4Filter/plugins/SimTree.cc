#include "SimG4Filter/SimG4Filter/interface/SimTree.hh"

void SimTree::Init()
{
   simTrkId.clear();
   simTrkPt.clear();
   simTrkEta.clear();
   simTrkPhi.clear();
   
   nSimHitRPC.clear();
   nSimHitCSC.clear();
   nSimHitDT.clear();

   nSimHitRPCRECO.clear();
   nSimHitRPC2RECO.clear();
   nSimHitCSCStripRECO.clear();
   nSimHitCSCWireRECO.clear();
   nSimHitDTRECO.clear();
   
   muGenPt.clear();
   muGenEta.clear();
   muGenPhi.clear();
   muGenStatus.clear();
   muGenId.clear();

   muRecPt.clear();
   muRecEta.clear();
   muRecPhi.clear();
   muRecNumberOfValidMuonRPCHits.clear();
   muRecNumberOfValidMuonCSCHits.clear();
   muRecNumberOfValidMuonDTHits.clear();
   muRecNumberOfValidMuonHits.clear();
   muRecNumberOfMatches.clear();
   muRecNumberOfValidHits.clear();
   muRecNumberOfValidPixelHits.clear();
   muRecNumberOfHits.clear();
   muRecNormalizedChi2GlobalTrack.clear();
   muRecNormalizedChi2InnerTrack.clear();
}

void SimTree::CreateBranches(int buffersize = 32000)
{
   tree->Branch("simTrkId", "std::vector<int>", &simTrkId, buffersize);
   tree->Branch("simTrkPt", "std::vector<float>", &simTrkPt, buffersize);
   tree->Branch("simTrkEta", "std::vector<float>", &simTrkEta, buffersize);
   tree->Branch("simTrkPhi", "std::vector<float>", &simTrkPhi, buffersize);
   
   tree->Branch("nSimHitRPC", "std::vector<int>", &nSimHitRPC, buffersize);
   tree->Branch("nSimHitCSC", "std::vector<int>", &nSimHitCSC, buffersize);
   tree->Branch("nSimHitDT", "std::vector<int>", &nSimHitDT, buffersize);

   tree->Branch("nSimHitRPCRECO", "std::vector<int>", &nSimHitRPCRECO, buffersize);
   tree->Branch("nSimHitRPC2RECO", "std::vector<int>", &nSimHitRPC2RECO, buffersize);
   tree->Branch("nSimHitCSCStripRECO", "std::vector<int>", &nSimHitCSCStripRECO, buffersize);
   tree->Branch("nSimHitCSCWireRECO", "std::vector<int>", &nSimHitCSCWireRECO, buffersize);
   tree->Branch("nSimHitDTRECO", "std::vector<int>", &nSimHitDTRECO, buffersize);
   
   tree->Branch("muGenPt", "std::vector<float>", &muGenPt, buffersize);
   tree->Branch("muGenEta", "std::vector<float>", &muGenEta, buffersize);
   tree->Branch("muGenPhi", "std::vector<float>", &muGenPhi, buffersize);
   tree->Branch("muGenStatus", "std::vector<int>", &muGenStatus, buffersize);
   tree->Branch("muGenId", "std::vector<int>", &muGenId, buffersize);

   tree->Branch("muRecPt", "std::vector<float>", &muRecPt, buffersize);
   tree->Branch("muRecEta", "std::vector<float>", &muRecEta, buffersize);
   tree->Branch("muRecPhi", "std::vector<float>", &muRecPhi, buffersize);
   tree->Branch("muRecNumberOfValidMuonRPCHits", "std::vector<int>", &muRecNumberOfValidMuonRPCHits, buffersize);
   tree->Branch("muRecNumberOfValidMuonCSCHits", "std::vector<int>", &muRecNumberOfValidMuonCSCHits, buffersize);
   tree->Branch("muRecNumberOfValidMuonDTHits", "std::vector<int>", &muRecNumberOfValidMuonDTHits, buffersize);
   tree->Branch("muRecNumberOfValidMuonHits", "std::vector<int>", &muRecNumberOfValidMuonHits, buffersize);
   tree->Branch("muRecNumberOfMatches", "std::vector<int>", &muRecNumberOfMatches, buffersize);
   tree->Branch("muRecNumberOfValidHits", "std::vector<int>", &muRecNumberOfValidHits, buffersize);
   tree->Branch("muRecNumberOfValidPixelHits", "std::vector<int>", &muRecNumberOfValidPixelHits, buffersize);
   tree->Branch("muRecNumberOfHits", "std::vector<int>", &muRecNumberOfHits, buffersize);
   tree->Branch("muRecNormalizedChi2GlobalTrack", "std::vector<int>", &muRecNormalizedChi2GlobalTrack, buffersize);
   tree->Branch("muRecNormalizedChi2InnerTrack", "std::vector<int>", &muRecNormalizedChi2InnerTrack, buffersize);
}
