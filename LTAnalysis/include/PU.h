#ifndef LTANAPU_H
#define LTANAPU_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "TFile.h"
#include "TH1.h"
#include "TH2.h"

namespace LTANA
{
   
   class PU
     {

      public:
	
	PU();
	virtual ~PU();
	
	void init(bool doPileup);
	
	double getPUWeight(int nPU,std::string opt = "");

      private:
		
	TFile *_fpuNom;
	TFile *_fpuUp;
	TFile *_fpuDown;
	
	TH1D *_hpuNom;
	TH1D *_hpuUp;
	TH1D *_hpuDown;

	bool _doPileup;
	
	void calcWeights();

	std::vector<double> _weights;
	std::vector<double> _weightsUp;
	std::vector<double> _weightsDown;
     };
}

#endif
