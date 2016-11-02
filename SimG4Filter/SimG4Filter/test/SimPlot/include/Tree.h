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

   std::vector<int> *simTrkId;
   std::vector<float> *simTrkPt;
   std::vector<float> *simTrkEta;
   std::vector<float> *simTrkPhi;

   std::vector<int> *nSimHitRPC;
   std::vector<int> *nSimHitCSC;
   std::vector<int> *nSimHitDT;

   std::vector<int> *nSimHitRPCRECO;
   std::vector<int> *nSimHitRPC2RECO;
   std::vector<int> *nSimHitCSCStripRECO;
   std::vector<int> *nSimHitCSCWireRECO;
   std::vector<int> *nSimHitDTRECO;
   
   std::vector<float> *muGenPt;
   std::vector<float> *muGenEta;
   std::vector<float> *muGenPhi;
   std::vector<int> *muGenStatus;

   std::vector<float> *muRecPt;
   std::vector<float> *muRecEta;
   std::vector<float> *muRecPhi;
   std::vector<int> *muRecNumberOfValidMuonRPCHits;
   std::vector<int> *muRecNumberOfValidMuonCSCHits;
   std::vector<int> *muRecNumberOfValidMuonDTHits;
   std::vector<int> *muRecNumberOfValidMuonHits;
   std::vector<int> *muRecNumberOfMatches;
   std::vector<int> *muRecNumberOfValidHits;
   std::vector<int> *muRecNumberOfValidPixelHits;
   std::vector<int> *muRecNumberOfHits;
   std::vector<int> *muRecNormalizedChi2GlobalTrack;
   std::vector<int> *muRecNormalizedChi2InnerTrack;
   
   // List of branches
   TBranch        *b_simTrkId;
   TBranch        *b_simTrkPt;
   TBranch        *b_simTrkEta;
   TBranch        *b_simTrkPhi;
   
   TBranch        *b_nSimHitRPC;
   TBranch        *b_nSimHitCSC;
   TBranch        *b_nSimHitDT;
   
   TBranch        *b_nSimHitRPCRECO;
   TBranch        *b_nSimHitRPC2RECO;
   TBranch        *b_nSimHitCSCStripRECO;
   TBranch        *b_nSimHitCSCWireRECO;
   TBranch        *b_nSimHitDTRECO;
   
   TBranch        *b_muGenPt;
   TBranch        *b_muGenEta;
   TBranch        *b_muGenPhi;
   TBranch        *b_muGenStatus;

   TBranch        *b_muRecPt;
   TBranch        *b_muRecEta;
   TBranch        *b_muRecPhi;
   TBranch        *b_muRecNumberOfValidMuonRPCHits;
   TBranch        *b_muRecNumberOfValidMuonCSCHits;
   TBranch        *b_muRecNumberOfValidMuonDTHits;
   TBranch        *b_muRecNumberOfValidMuonHits;
   TBranch        *b_muRecNumberOfMatches;
   TBranch        *b_muRecNumberOfValidHits;
   TBranch        *b_muRecNumberOfValidPixelHits;
   TBranch        *b_muRecNumberOfHits;
   TBranch        *b_muRecNormalizedChi2GlobalTrack;
   TBranch        *b_muRecNormalizedChi2InnerTrack;
   
   Tree(TChain *ch=0,char* fname="physics.root",std::string treename="physics");
   virtual ~Tree();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *tree);
   virtual void     registerInputBranches(TChain *tree);
};

}
   
#endif
