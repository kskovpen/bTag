#ifndef SIMTREE_H
#define SIMTREE_H

#include <TTree.h>
#include <TLorentzVector.h>
#include <string>
#include <iostream>
#include <vector>

#include <boost/any.hpp>
using boost::any_cast;
typedef std::map<std::string, std::map<std::string, boost::any> >  t_map;

#define DEFVAL -666

class SimTree
{
 public:

   SimTree(TTree* _tree) {tree = _tree;};
   TTree* tree;

   void Init();
   void CreateBranches(int buffersize);
   
   std::vector<int> simTrkId;
   std::vector<float> simTrkPt;
   std::vector<float> simTrkEta;
   std::vector<float> simTrkPhi;
   
   std::vector<int> nSimHitRPC;
   std::vector<int> nSimHitCSC;
   std::vector<int> nSimHitDT;

   std::vector<int> nSimHitRPCRECO;
   std::vector<int> nSimHitRPC2RECO;
   std::vector<int> nSimHitCSCStripRECO;
   std::vector<int> nSimHitCSCWireRECO;
   std::vector<int> nSimHitDTRECO;
   
   std::vector<float> muGenPt;
   std::vector<float> muGenEta;
   std::vector<float> muGenPhi;
   std::vector<int> muGenStatus;
   std::vector<int> muGenId;

   std::vector<float> muRecPt;
   std::vector<float> muRecEta;
   std::vector<float> muRecPhi;
   std::vector<int> muRecNumberOfValidMuonRPCHits;
   std::vector<int> muRecNumberOfValidMuonCSCHits;
   std::vector<int> muRecNumberOfValidMuonDTHits;
   std::vector<int> muRecNumberOfValidMuonHits;
   std::vector<int> muRecNumberOfMatches;
   std::vector<int> muRecNumberOfValidHits;
   std::vector<int> muRecNumberOfValidPixelHits;
   std::vector<int> muRecNumberOfHits;
   std::vector<int> muRecNormalizedChi2GlobalTrack;
   std::vector<int> muRecNormalizedChi2InnerTrack;
};

#endif
