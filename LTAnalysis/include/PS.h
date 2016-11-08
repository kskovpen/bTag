#ifndef LTANAPS_H
#define LTANAPS_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

#include "TFile.h"
#include "TH1.h"
#include "TH2.h"

#define NMAX 10000

namespace LTANA
{
   
   class PS
     {

      public:
	
	PS();
	virtual ~PS();
	
	void init(bool doPS);
	
	double getPSWeight(std::string trigName,int run,int lb);

      private:
		
	void fillPS();

	int _psBTagMu_DiJet20_Mu5[NMAX], _runBTagMu_DiJet20_Mu5[NMAX], _lbBTagMu_DiJet20_Mu5[NMAX];
	int _psBTagMu_DiJet40_Mu5[NMAX], _runBTagMu_DiJet40_Mu5[NMAX], _lbBTagMu_DiJet40_Mu5[NMAX];
	int _psBTagMu_DiJet70_Mu5[NMAX], _runBTagMu_DiJet70_Mu5[NMAX], _lbBTagMu_DiJet70_Mu5[NMAX];
	int _psBTagMu_DiJet110_Mu5[NMAX], _runBTagMu_DiJet110_Mu5[NMAX], _lbBTagMu_DiJet110_Mu5[NMAX];
//	int _psBTagMu_DiJet170_Mu5[NMAX], _runBTagMu_DiJet170_Mu5[NMAX], _lbBTagMu_DiJet170_Mu5[NMAX];
	int _psBTagMu_Jet300_Mu5[NMAX], _runBTagMu_Jet300_Mu5[NMAX], _lbBTagMu_Jet300_Mu5[NMAX];
	
	std::ifstream _fBTagMu_DiJet20_Mu5;
	std::ifstream _fBTagMu_DiJet40_Mu5;
	std::ifstream _fBTagMu_DiJet70_Mu5;
	std::ifstream _fBTagMu_DiJet110_Mu5;
//	std::ifstream _fBTagMu_DiJet170_Mu5;
	std::ifstream _fBTagMu_Jet300_Mu5;
	
	bool _doPS;
	int _nElem[100];
     };
}

#endif
