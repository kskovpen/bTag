#ifndef LTANAREWEIGHT_H
#define LTANAREWEIGHT_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "TFile.h"
#include "TH1.h"
#include "TH2.h"

namespace LTANA
{
   
   class Reweight
     {

      public:
	
	Reweight();
	virtual ~Reweight();
	
	void init(int doRW,
		  std::vector<float> jPtMin,
		  std::vector<float> jPtMax,
		  std::vector<std::string> sel,
		  std::vector<std::string> selb,
		  std::vector<std::string> rwName);

	void apply(float *sfj,int ibtag,int jPtBin,
		   int ntrk,int nseltrk,int njet,int nsv,float mupt,float jeta,float jpt);

	float getSF(std::vector<std::pair<float,float> > vBin,
		    std::vector<std::pair<float,float> > vSf,
		    float var);
	
//	float get2DSF(std::vector<std::pair<float,float> > vBinX,
//		      std::vector<std::pair<float,float> > vBinY,
//		      std::vector<std::pair<float,float> > vSf,
//		      float varX,
//		      float varY);
	
      private:
	
	// var / ptbin / bins / btag / x1,x2
	std::vector<std::vector<std::vector<std::vector<std::pair<float,float> > > > > rwBin;
	std::vector<std::vector<std::vector<std::vector<std::pair<float,float> > > > > rwSf;

	// var[0] / ptbin / bins / v1,v2
//	std::vector<std::vector<std::vector<std::pair<float,float> > > > rw2DBinX;
//	std::vector<std::vector<std::vector<std::pair<float,float> > > > rw2DBinY;
//	std::vector<std::vector<std::vector<std::pair<float,float> > > > rw2DSf;
	
	TFile *_fcor;
	
	std::vector<std::string> _rwName;
	int _rwN;
//	std::vector<std::string> _rwName2d;
//	int _rwN2d;
	std::vector<std::string> _selName;
	int _selN;	
	std::vector<std::string> _selbName;
	int _selbN;
	
	bool _doRW;
	
	std::vector<float> _jPtMin;
	std::vector<float> _jPtMax;
     };
}

#endif
