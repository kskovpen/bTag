#ifndef Tree_h
#define Tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

namespace SIMPLOT
{   

class Tree {
public :
   TChain *fChain;
   Int_t           fCurrent;

   std::vector<int>         *momId;
   std::vector<float>         *muPt;
   std::vector<float>         *muEta;
   std::vector<float>         *muPhi;
   std::vector<int>         *muStatus;
   std::vector<int>         *partonId;
   
   std::vector<float>         *muPosX;
   std::vector<float>         *muPosY;
   std::vector<float>         *muPosZ;
   std::vector<float>         *muRpv;

   std::vector<float>         *muSimPosX;
   std::vector<float>         *muSimPosY;
   std::vector<float>         *muSimPosZ;
   std::vector<float>         *muSimRpv;
   
   std::vector<float>         *muSimPt;
   std::vector<float>         *muSimEta;
   std::vector<float>         *muSimPhi;
   std::vector<int>           *muSimMomId;

   std::vector<float>         *recomuonPt;
   std::vector<float>         *recomuonEta;
   std::vector<float>         *recomuonPhi;

   std::vector<bool>          *recomuonIsPFMuon;
   std::vector<bool>          *recomuonIsGlobalMuon;
   std::vector<int>           *recomuonNumberOfValidMuonHits;
   std::vector<int>           *recomuonNumberOfMatches;
   std::vector<int>           *recomuonNumberOfValidHits;
   std::vector<int>           *recomuonNumberOfValidPixelHits;
   std::vector<int>           *recomuonNumberOfHits;
   std::vector<float>         *recomuonNormalizedChi2GlobalTrack;
   std::vector<float>         *recomuonNormalizedChi2InnerTrack;
   std::vector<int>           *recomuonNumberOfValidMuonHitsGlobalTrack;
   std::vector<int>           *recomuonTrackerLayersWithMeasurement;
   std::vector<int>           *recomuonNumberOfMatchedStations;
   
   std::vector<float>         *patmuonPt;
   std::vector<float>         *patmuonEta;
   std::vector<float>         *patmuonPhi;

   std::vector<bool>          *patmuonIsPFMuon;
   std::vector<bool>          *patmuonIsGlobalMuon;
   std::vector<int>           *patmuonNumberOfValidMuonHits;
   std::vector<int>           *patmuonNumberOfMatches;
   std::vector<int>           *patmuonNumberOfValidHits;
   std::vector<int>           *patmuonNumberOfValidPixelHits;
   std::vector<int>           *patmuonNumberOfHits;
   std::vector<float>         *patmuonNormalizedChi2GlobalTrack;
   std::vector<float>         *patmuonNormalizedChi2InnerTrack;
   std::vector<int>           *patmuonNumberOfValidMuonHitsGlobalTrack;
   std::vector<int>           *patmuonTrackerLayersWithMeasurement;
   std::vector<int>           *patmuonNumberOfMatchedStations;
   
   std::vector<float>         *patjetPt;
   std::vector<float>         *patjetEta;
   std::vector<float>         *patjetPhi;
   std::vector<int>           *patjetPartonFlavour;
   std::vector<int>           *patjetHadronFlavour;
   
   // List of branches
   TBranch        *b_momId;
   TBranch        *b_muPt;
   TBranch        *b_muEta;
   TBranch        *b_muPhi;
   TBranch        *b_muStatus;
   TBranch        *b_partonId;
   
   TBranch        *b_muPosX;
   TBranch        *b_muPosY;
   TBranch        *b_muPosZ;
   TBranch        *b_muRpv;

   TBranch        *b_muSimPosX;
   TBranch        *b_muSimPosY;
   TBranch        *b_muSimPosZ;
   TBranch        *b_muSimRpv;
   
   TBranch        *b_muSimPt;
   TBranch        *b_muSimEta;
   TBranch        *b_muSimPhi;
   TBranch        *b_muSimMomId;

   TBranch        *b_recomuonPt;
   TBranch        *b_recomuonEta;
   TBranch        *b_recomuonPhi;

   TBranch        *b_recomuonIsPFMuon;
   TBranch        *b_recomuonIsGlobalMuon;
   TBranch        *b_recomuonNumberOfValidMuonHits;
   TBranch        *b_recomuonNumberOfMatches;
   TBranch        *b_recomuonNumberOfValidHits;
   TBranch        *b_recomuonNumberOfValidPixelHits;
   TBranch        *b_recomuonNumberOfHits;
   TBranch        *b_recomuonNormalizedChi2GlobalTrack;
   TBranch        *b_recomuonNormalizedChi2InnerTrack;
   TBranch        *b_recomuonNumberOfValidMuonHitsGlobalTrack;
   TBranch        *b_recomuonTrackerLayersWithMeasurement;
   TBranch        *b_recomuonNumberOfMatchedStations;
   
   TBranch        *b_patmuonPt;
   TBranch        *b_patmuonEta;
   TBranch        *b_patmuonPhi;

   TBranch        *b_patmuonIsPFMuon;
   TBranch        *b_patmuonIsGlobalMuon;
   TBranch        *b_patmuonNumberOfValidMuonHits;
   TBranch        *b_patmuonNumberOfMatches;
   TBranch        *b_patmuonNumberOfValidHits;
   TBranch        *b_patmuonNumberOfValidPixelHits;
   TBranch        *b_patmuonNumberOfHits;
   TBranch        *b_patmuonNormalizedChi2GlobalTrack;
   TBranch        *b_patmuonNormalizedChi2InnerTrack;
   TBranch        *b_patmuonNumberOfValidMuonHitsGlobalTrack;
   TBranch        *b_patmuonTrackerLayersWithMeasurement;
   TBranch        *b_patmuonNumberOfMatchedStations;
   
   TBranch        *b_patjetPt;
   TBranch        *b_patjetEta;
   TBranch        *b_patjetPhi;
   TBranch        *b_patjetPartonFlavour;
   TBranch        *b_patjetHadronFlavour;
   
   Tree(TChain *ch=0,char* fname="physics.root",std::string treename="physics");
   virtual ~Tree();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *tree);
   virtual void     registerInputBranches(TChain *tree);
};

}
   
#endif
