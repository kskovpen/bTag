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
     };
}

#endif
