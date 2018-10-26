#ifndef testCalib_h
#define testCalib_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>

#include "BTagCalibrationStandalone.h"

class testCalib {

 public:
   
   testCalib();

 private:

   void getBtagSF(std::string sysType,BTagCalibrationReader reader);

};


#endif

