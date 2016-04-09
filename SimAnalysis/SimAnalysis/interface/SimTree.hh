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

//   int el_n;

   std::vector<float> primVtxX;
   std::vector<float> primVtxY;
   std::vector<float> primVtxZ;
   
   std::vector<int> momId;
   std::vector<float> momPt;
   std::vector<float> momEta;
   std::vector<float> momPhi;
   
   std::vector<float> muR;
   std::vector<float> muRpv;
   std::vector<float> muPosX;
   std::vector<float> muPosY;
   std::vector<float> muPosZ;
   std::vector<float> muPt;
   std::vector<float> muEta;
   std::vector<float> muPhi;
   std::vector<int> muStatus;

   std::vector<int> muSimMomId;
   std::vector<float> muSimR;
   std::vector<float> muSimRpv;
   std::vector<float> muSimPosX;
   std::vector<float> muSimPosY;
   std::vector<float> muSimPosZ;
   std::vector<float> muSimPt;
   std::vector<float> muSimEta;
   std::vector<float> muSimPhi;
   
   std::vector<int> partonId;
   std::vector<float> partonPt;
   std::vector<float> partonEta;
   std::vector<float> partonPhi;
   
   std::vector<float> pfjetPt;
   std::vector<float> pfjetEta;
   std::vector<float> pfjetPhi;
   
   std::vector<float> patjetPt;
   std::vector<float> patjetEta;
   std::vector<float> patjetPhi;
   std::vector<int> patjetPartonFlavour;
   std::vector<int> patjetHadronFlavour;

   std::vector<float> recomuonPt;
   std::vector<float> recomuonEta;
   std::vector<float> recomuonPhi;

   std::vector<bool> recomuonIsPFMuon;
   std::vector<bool> recomuonIsGlobalMuon;
   std::vector<int> recomuonNumberOfValidMuonHits;
   std::vector<int> recomuonNumberOfMatches;
   std::vector<int> recomuonNumberOfValidHits;
   std::vector<int> recomuonNumberOfValidPixelHits;
   std::vector<int> recomuonNumberOfHits;
   std::vector<float> recomuonNormalizedChi2GlobalTrack;
   std::vector<float> recomuonNormalizedChi2InnerTrack;
   std::vector<int> recomuonNumberOfValidMuonHitsGlobalTrack;
   std::vector<int> recomuonTrackerLayersWithMeasurement;
   std::vector<int> recomuonNumberOfMatchedStations;
   
   std::vector<float> patmuonPt;
   std::vector<float> patmuonEta;
   std::vector<float> patmuonPhi;

   std::vector<bool> patmuonIsPFMuon;
   std::vector<bool> patmuonIsGlobalMuon;
   std::vector<int> patmuonNumberOfValidMuonHits;
   std::vector<int> patmuonNumberOfMatches;
   std::vector<int> patmuonNumberOfValidHits;
   std::vector<int> patmuonNumberOfValidPixelHits;
   std::vector<int> patmuonNumberOfHits;
   std::vector<float> patmuonNormalizedChi2GlobalTrack;
   std::vector<float> patmuonNormalizedChi2InnerTrack;
   std::vector<int> patmuonNumberOfValidMuonHitsGlobalTrack;
   std::vector<int> patmuonTrackerLayersWithMeasurement;
   std::vector<int> patmuonNumberOfMatchedStations;
};

#endif
