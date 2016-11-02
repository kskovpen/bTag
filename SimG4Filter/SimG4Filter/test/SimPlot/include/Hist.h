#ifndef SIMPLOTHIST_H
#define SIMPLOTHIST_H

#include "Common.h"

namespace SIMPLOT
{
   
   class Hist
     {

      public:
	
	Hist();
	virtual ~Hist();

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
			      int numberOfValidHits,
			      int numberOfValidPixelHits,
			      int numberOfHits,
			      float normalizedChi2GlobalTrack,
			      float normalizedChi2InnerTrack,
			      bool isPFMuon,
			      bool isGlobalMuon
			     );

/*	bool BTVDoubleMuonSelection(int numberOfValidMuonHits,
				    int numberOfMatches,
				    int numberOfValidHits,
				    int numberOfValidPixelHits,
				    int numberOfHits,
				    float normalizedChi2GlobalTrack,
				    float normalizedChi2InnerTrack,
				    bool isPFMuon,
				    bool isGlobalMuon
				   );*/
	
      private:
	
	TFile *_fout;
	
	TH1F *h_passFilt;
	TH1F *h_hasGenMu;
	TH1F *h_hasRecMu;
     };
}

#endif
