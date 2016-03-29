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
   
   Tree(TChain *ch=0,char* fname="physics.root",std::string treename="physics");
   virtual ~Tree();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *tree);
   virtual void     registerInputBranches(TChain *tree);
};

}
   
#endif
