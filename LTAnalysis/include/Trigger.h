#ifndef LTANATRIGGER_H
#define LTANATRIGGER_H

#include "Common.h"

namespace LTANA
{
   
   class Trigger
     {

      public:
	Trigger();
	virtual ~Trigger();

	bool passTrig(int trigIdx);
	
	void init();
	void fill();
	void close();
	
      private:
	
	TRandom3 *rnd;
	
	TFile *_fout;
	
	TH1D *hJetPtAll_HLT_BTagMu_DiJet20_Mu5;
	TH1D *hJetPtPass_HLT_BTagMu_DiJet20_Mu5;

	TH1D *hJetPtAll_HLT_BTagMu_DiJet40_Mu5;
	TH1D *hJetPtPass_HLT_BTagMu_DiJet40_Mu5;

	TH1D *hJetPtAll_HLT_BTagMu_DiJet70_Mu5;
	TH1D *hJetPtPass_HLT_BTagMu_DiJet70_Mu5;

	TH1D *hJetPtAll_HLT_BTagMu_DiJet110_Mu5;
	TH1D *hJetPtPass_HLT_BTagMu_DiJet110_Mu5;

	TH1D *hJetPtAll_HLT_BTagMu_Jet300_Mu5;
	TH1D *hJetPtPass_HLT_BTagMu_Jet300_Mu5;
     };
}

#endif
