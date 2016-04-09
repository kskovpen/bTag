#ifndef SIMPLOTORIGIN_H
#define SIMPLOTORIGIN_H

#include "Common.h"

namespace SIMPLOT
{
   
   class Origin
     {

      public:
	
	Origin();
	virtual ~Origin();

	void init();
	void fill();
	void close();
	
	int pdgIdLabel(int pdgId);
	int partonIdLabel(int partonId);
	
	float DeltaR(float eta1,float phi1,float eta2,float phi2);

	struct GenSim
	  {   
	     int idx;
	     bool type;
	     float pt;
	     float eta;
	     float phi;
	     int pdgId;
	     int idxReco;
	     float drReco;
	  };

	static bool sortByPt(const GenSim &a, const GenSim &b)
	  {	     
	     return a.pt > b.pt;
	  };	

	bool BTVMuonSelection(int numberOfValidMuonHits,
			      int numberOfMatches,
			      int numberOfMatchedStations,
			      int trackerLayersWithMeasurement,
			      int numberOfValidHits,
			      int numberOfValidPixelHits,
			      int numberOfHits,
			      float normalizedChi2GlobalTrack,
			      float normalizedChi2InnerTrack,
			      bool isPFMuon,
			      bool isGlobalMuon
			     );

	bool NewMuonSelection(int numberOfValidMuonHits,
			      int numberOfMatches,
			      int numberOfMatchedStations,
			      int trackerLayersWithMeasurement,
			      int numberOfValidHits,
			      int numberOfValidPixelHits,
			      int numberOfHits,
			      float normalizedChi2GlobalTrack,
			      float normalizedChi2InnerTrack,
			      bool isPFMuon,
			      bool isGlobalMuon
			     );
	
      private:
	
	TFile *_fout;
	
	TH2F *h_mu1_RhoPhi;
	TH2F *h_mu2_RhoPhi;

	TH2F *h_muSim1_RhoPhi;
	TH2F *h_muSim2_RhoPhi;
	
	TH1F *h_mu1_id;
	TH1F *h_mu2_id;
	
	TH1F *h_mu1_partonId;
	TH1F *h_mu2_partonId;

	TH1F *h_muRec1_id;
	TH1F *h_muRec2_id;
	
	TH1F *h_mu1_pt;
	TH1F *h_mu2_pt;

	TH1F *h_muAll1_pt;
	TH1F *h_muAll2_pt;
	
	TH1F *h_mu1_rpv;
	TH1F *h_mu2_rpv;
	
	TH1F *h_muSim1_pt;
	TH1F *h_muSim2_pt;

	TH1F *h_muSim1_rpv;
	TH1F *h_muSim2_rpv;
	
	TH1F *h_punchThroughEff;

	TH1F *h_muRec1_pt;
	TH1F *h_muRec2_pt;

	TH1F *h_muSimMatchedRec1_pt;
	TH1F *h_muSimMatchedRec2_pt;

	TH1F *h_muGenMatchedRec1_pt;
	TH1F *h_muGenMatchedRec2_pt;

	TH1F *h_muAllMatchedRec1_pt;
	TH1F *h_muAllMatchedRec2_pt;

	TH1F *h_muAllBD1_pt;
	TH1F *h_muAllBD2_pt;
	
	TH1F *h_muAllOTHER1_pt;
	TH1F *h_muGenOTHER1_pt;
	TH1F *h_muSimOTHER1_pt;

	TH1F *h_muAllOTHER2_pt;
	TH1F *h_muGenOTHER2_pt;
	TH1F *h_muSimOTHER2_pt;
	
	TH1F *h_muAllPK1_pt;
	TH1F *h_muAllPK2_pt;	
	
	TH1F *h_muAllBDMatchedRec1_pt;
	TH1F *h_muAllBDMatchedRec2_pt;
	
	TH1F *h_muAllPKMatchedRec1_pt;
	TH1F *h_muAllPKMatchedRec2_pt;
	
	TH1F *h_muRecClosestMuGen1_dr;
	TH1F *h_muRecClosestMuGen2_dr;

	TH1F *h_muRecClosestMuSim1_dr;
	TH1F *h_muRecClosestMuSim2_dr;

	TH1F *h_muGenClosestMuRec1_dr;
	TH1F *h_muGenClosestMuRec2_dr;

	TH1F *h_muSimClosestMuRec1_dr;
	TH1F *h_muSimClosestMuRec2_dr;
	
	TH1F *h_muJet1_pt;
	TH1F *h_muJet2_pt;	

	TH1F *h_muBJet1_pt;
	TH1F *h_muBJet2_pt;	

	TH1F *h_muCJet1_pt;
	TH1F *h_muCJet2_pt;	

	TH1F *h_muLJet1_pt;
	TH1F *h_muLJet2_pt;
	
	TH1F *h_muPK1_gensim;
	TH1F *h_muPK2_gensim;
	TH1F *h_muPK21_gensim;
	
	TH1F *h_muOTHER1_gensim;
	TH1F *h_muOTHER2_gensim;
	TH1F *h_muNOTPK2_gensim;
	TH1F *h_muOTHER21_gensim;

	TH1F *h_muFake_pt;
	TH1F *h_muReal_pt;
	
	TH1F *h_muVal1_pt;
	TH1F *h_muVal2_pt;
	TH1F *h_muVal3_pt;

	TH1F *h_muValUncor1_pt;
	TH1F *h_muValUncor2_pt;
	TH1F *h_muValUncor3_pt;
	
	TH1F *h_muRecVal1_pt;
	TH1F *h_muRecVal2_pt;
	TH1F *h_muRecVal3_pt;

	TH1F *h_muRecValUncor1_pt;
	TH1F *h_muRecValUncor2_pt;
	TH1F *h_muRecValUncor3_pt;
	
	TH1F *h_muFake_trackerLayersWithMeasurement;
	TH1F *h_muFake_numberOfValidMuonHits;
	TH1F *h_muFake_numberOfMatches;
	TH1F *h_muFake_numberOfMatchedStations;
	TH1F *h_muFake_numberOfValidHits;
	TH1F *h_muFake_numberOfValidPixelHits;
	TH1F *h_muFake_numberOfHits;
	TH1F *h_muFake_normalizedChi2GlobalTrack;
	TH1F *h_muFake_normalizedChi2InnerTrack;
	
	TH1F *h_muReal_trackerLayersWithMeasurement;
	TH1F *h_muReal_numberOfValidMuonHits;
	TH1F *h_muReal_numberOfMatches;
	TH1F *h_muReal_numberOfMatchedStations;
	TH1F *h_muReal_numberOfValidHits;
	TH1F *h_muReal_numberOfValidPixelHits;
	TH1F *h_muReal_numberOfHits;
	TH1F *h_muReal_normalizedChi2GlobalTrack;
	TH1F *h_muReal_normalizedChi2InnerTrack;
	
	TH1F *h_muPythiaGeant_N;
	TH1F *h_muGeant_N;
     };
}

#endif
