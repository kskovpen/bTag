#include "../include/Tree.h"

SIMPLOT::Tree::Tree(TChain *ch,char *fname,std::string treename)
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

SIMPLOT::Tree::~Tree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SIMPLOT::Tree::GetEntry(Long64_t entry)
{
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

Long64_t SIMPLOT::Tree::LoadTree(Long64_t entry)
{
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
   }
   return centry;
}

void SIMPLOT::Tree::registerInputBranches(TChain *tr)
{
   tr->SetBranchStatus("*",1);
   
   std::cout << "Successfully initialized input branches" << std::endl;
}

void SIMPLOT::Tree::Init(TChain *tree)
{
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;

   momId = 0;
   muPt = 0;
   muEta = 0;
   muPhi = 0;
   muStatus = 0;
   partonId = 0;

   muPosX = 0;
   muPosY = 0;
   muPosZ = 0;
   muRpv = 0;

   muSimPosX = 0;
   muSimPosY = 0;
   muSimPosZ = 0;
   muSimRpv = 0;
   
   muSimPt = 0;
   muSimEta = 0;
   muSimPhi = 0;
   muSimMomId = 0;

   recomuonPt = 0;
   recomuonEta = 0;
   recomuonPhi = 0;

   recomuonIsPFMuon = 0;
   recomuonIsGlobalMuon = 0;
   recomuonNumberOfValidMuonHits = 0;
   recomuonNumberOfMatches = 0;
   recomuonNumberOfValidHits = 0;
   recomuonNumberOfValidPixelHits = 0;
   recomuonNumberOfHits = 0;
   recomuonNormalizedChi2GlobalTrack = 0;
   recomuonNormalizedChi2InnerTrack = 0;
   recomuonNumberOfValidMuonHitsGlobalTrack = 0;
   recomuonTrackerLayersWithMeasurement = 0;
   recomuonNumberOfMatchedStations = 0;
   
   patmuonPt = 0;
   patmuonEta = 0;
   patmuonPhi = 0;

   patmuonIsPFMuon = 0;
   patmuonIsGlobalMuon = 0;
   patmuonNumberOfValidMuonHits = 0;
   patmuonNumberOfMatches = 0;
   patmuonNumberOfValidHits = 0;
   patmuonNumberOfValidPixelHits = 0;
   patmuonNumberOfHits = 0;
   patmuonNormalizedChi2GlobalTrack = 0;
   patmuonNormalizedChi2InnerTrack = 0;
   patmuonNumberOfValidMuonHitsGlobalTrack = 0;
   patmuonTrackerLayersWithMeasurement = 0;
   patmuonNumberOfMatchedStations = 0;
   
   patjetPt = 0;
   patjetEta = 0;
   patjetPhi = 0;
   patjetPartonFlavour = 0;
   patjetHadronFlavour = 0;
   
   fChain->SetBranchAddress("momId", &momId, &b_momId);
   fChain->SetBranchAddress("muPt", &muPt, &b_muPt);
   fChain->SetBranchAddress("muEta", &muEta, &b_muEta);
   fChain->SetBranchAddress("muPhi", &muPhi, &b_muPhi);
   fChain->SetBranchAddress("muStatus", &muStatus, &b_muStatus);
   fChain->SetBranchAddress("partonId", &partonId, &b_partonId);

   fChain->SetBranchAddress("muPosX", &muPosX, &b_muPosX);
   fChain->SetBranchAddress("muPosY", &muPosY, &b_muPosY);
   fChain->SetBranchAddress("muPosZ", &muPosZ, &b_muPosZ);
   fChain->SetBranchAddress("muRpv", &muRpv, &b_muRpv);

   fChain->SetBranchAddress("muSimPosX", &muSimPosX, &b_muSimPosX);
   fChain->SetBranchAddress("muSimPosY", &muSimPosY, &b_muSimPosY);
   fChain->SetBranchAddress("muSimPosZ", &muSimPosZ, &b_muSimPosZ);
   fChain->SetBranchAddress("muSimRpv", &muSimRpv, &b_muSimRpv);
   
   fChain->SetBranchAddress("muSimPt", &muSimPt, &b_muSimPt);
   fChain->SetBranchAddress("muSimEta", &muSimEta, &b_muSimEta);
   fChain->SetBranchAddress("muSimPhi", &muSimPhi, &b_muSimPhi);
   fChain->SetBranchAddress("muSimMomId", &muSimMomId, &b_muSimMomId);

   fChain->SetBranchAddress("recomuonPt", &recomuonPt, &b_recomuonPt);
   fChain->SetBranchAddress("recomuonEta", &recomuonEta, &b_recomuonEta);
   fChain->SetBranchAddress("recomuonPhi", &recomuonPhi, &b_recomuonPhi);

   fChain->SetBranchAddress("recomuonIsPFMuon", &recomuonIsPFMuon, &b_recomuonIsPFMuon);
   fChain->SetBranchAddress("recomuonIsGlobalMuon", &recomuonIsGlobalMuon, &b_recomuonIsGlobalMuon);
   fChain->SetBranchAddress("recomuonNumberOfValidMuonHits", &recomuonNumberOfValidMuonHits, &b_recomuonNumberOfValidMuonHits);
   fChain->SetBranchAddress("recomuonNumberOfMatches", &recomuonNumberOfMatches, &b_recomuonNumberOfMatches);
   fChain->SetBranchAddress("recomuonNumberOfValidHits", &recomuonNumberOfValidHits, &b_recomuonNumberOfValidHits);
   fChain->SetBranchAddress("recomuonNumberOfValidPixelHits", &recomuonNumberOfValidPixelHits, &b_recomuonNumberOfValidPixelHits);
   fChain->SetBranchAddress("recomuonNumberOfHits", &recomuonNumberOfHits, &b_recomuonNumberOfHits);
   fChain->SetBranchAddress("recomuonNormalizedChi2GlobalTrack", &recomuonNormalizedChi2GlobalTrack, &b_recomuonNormalizedChi2GlobalTrack);
   fChain->SetBranchAddress("recomuonNormalizedChi2InnerTrack", &recomuonNormalizedChi2InnerTrack, &b_recomuonNormalizedChi2InnerTrack);
   fChain->SetBranchAddress("recomuonNumberOfValidMuonHitsGlobalTrack", &recomuonNumberOfValidMuonHitsGlobalTrack, &b_recomuonNumberOfValidMuonHitsGlobalTrack);
   fChain->SetBranchAddress("recomuonTrackerLayersWithMeasurement", &recomuonTrackerLayersWithMeasurement, &b_recomuonTrackerLayersWithMeasurement);
   fChain->SetBranchAddress("recomuonNumberOfMatchedStations", &recomuonNumberOfMatchedStations, &b_recomuonNumberOfMatchedStations);
   
   fChain->SetBranchAddress("patmuonPt", &patmuonPt, &b_patmuonPt);
   fChain->SetBranchAddress("patmuonEta", &patmuonEta, &b_patmuonEta);
   fChain->SetBranchAddress("patmuonPhi", &patmuonPhi, &b_patmuonPhi);
   
   fChain->SetBranchAddress("patmuonIsPFMuon", &patmuonIsPFMuon, &b_patmuonIsPFMuon);
   fChain->SetBranchAddress("patmuonIsGlobalMuon", &patmuonIsGlobalMuon, &b_patmuonIsGlobalMuon);
   fChain->SetBranchAddress("patmuonNumberOfValidMuonHits", &patmuonNumberOfValidMuonHits, &b_patmuonNumberOfValidMuonHits);
   fChain->SetBranchAddress("patmuonNumberOfMatches", &patmuonNumberOfMatches, &b_patmuonNumberOfMatches);
   fChain->SetBranchAddress("patmuonNumberOfValidHits", &patmuonNumberOfValidHits, &b_patmuonNumberOfValidHits);
   fChain->SetBranchAddress("patmuonNumberOfValidPixelHits", &patmuonNumberOfValidPixelHits, &b_patmuonNumberOfValidPixelHits);
   fChain->SetBranchAddress("patmuonNumberOfHits", &patmuonNumberOfHits, &b_patmuonNumberOfHits);
   fChain->SetBranchAddress("patmuonNormalizedChi2GlobalTrack", &patmuonNormalizedChi2GlobalTrack, &b_patmuonNormalizedChi2GlobalTrack);
   fChain->SetBranchAddress("patmuonNormalizedChi2InnerTrack", &patmuonNormalizedChi2InnerTrack, &b_patmuonNormalizedChi2InnerTrack);
   fChain->SetBranchAddress("patmuonNumberOfValidMuonHitsGlobalTrack", &patmuonNumberOfValidMuonHitsGlobalTrack, &b_patmuonNumberOfValidMuonHitsGlobalTrack);
   fChain->SetBranchAddress("patmuonTrackerLayersWithMeasurement", &patmuonTrackerLayersWithMeasurement, &b_patmuonTrackerLayersWithMeasurement);
   fChain->SetBranchAddress("patmuonNumberOfMatchedStations", &patmuonNumberOfMatchedStations, &b_patmuonNumberOfMatchedStations);
   
   fChain->SetBranchAddress("patjetPt", &patjetPt, &b_patjetPt);
   fChain->SetBranchAddress("patjetEta", &patjetEta, &b_patjetEta);
   fChain->SetBranchAddress("patjetPhi", &patjetPhi, &b_patjetPhi);
   fChain->SetBranchAddress("patjetPartonFlavour", &patjetPartonFlavour, &b_patjetPartonFlavour);
   fChain->SetBranchAddress("patjetHadronFlavour", &patjetHadronFlavour, &b_patjetHadronFlavour);
}
