#ifndef CFIT_H
#define CFIT_H

#include "TROOT.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

namespace CFIT
{
   
   class cfit
     {
	
      public:
	
	cfit();
	~cfit();
	
      protected:
	
	TFile *dfile;
	
//	std::unique_ptr<TH1D> h_data;
	TH1D *h_data;

	ClassDef(CFIT::cfit,1)
     };
}

#endif
