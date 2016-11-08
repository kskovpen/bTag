#include "../include/PU.h"

#include "TSystem.h"

LTANA::PU::PU()
{
}

LTANA::PU::~PU()
{
   if( _doPileup ) 
     {
	_fpuNom->Close();
	_fpuUp->Close();
	_fpuDown->Close();
     }   
}

void LTANA::PU::init(bool doPileup)
{
   std::string fnameNom = "/home-pbs/kskovpen/bTag2016/CMSSW_7_4_6_patch6/src/LTAnalysis/test/PileupNom.root";
   std::string fnameUp = "/home-pbs/kskovpen/bTag2016/CMSSW_7_4_6_patch6/src/LTAnalysis/test/PileupUp.root";
   std::string fnameDown = "/home-pbs/kskovpen/bTag2016/CMSSW_7_4_6_patch6/src/LTAnalysis/test/PileupDown.root";
   
   bool existNom = !(gSystem->AccessPathName(fnameNom.c_str()));
   bool existUp = !(gSystem->AccessPathName(fnameUp.c_str()));
   bool existDown = !(gSystem->AccessPathName(fnameDown.c_str()));

   if( !existNom || !existUp || !existDown )
     {
	std::cout << "Input file with pileup factors can not be opened, no corrections will be applied" << std::endl;
	doPileup = 0;
     }
   else 
     {
	std::cout << "Read pileup" << std::endl;
	_fpuNom = TFile::Open(fnameNom.c_str(),"READ");
	_fpuUp = TFile::Open(fnameUp.c_str(),"READ");
	_fpuDown = TFile::Open(fnameDown.c_str(),"READ");
     }   
   
   if( doPileup )
     {	    
	_fpuNom->GetObject("pileup",_hpuNom);
	_fpuUp->GetObject("pileup",_hpuUp);
	_fpuDown->GetObject("pileup",_hpuDown);
     }
   
   _doPileup = doPileup;
   
   _weights.clear();
   _weightsUp.clear();
   _weightsDown.clear();
   
   if( _doPileup ) calcWeights();
}

void LTANA::PU::calcWeights()
{
   // https://github.com/cms-sw/cmssw/blob/CMSSW_8_0_X/SimGeneral/MixingModule/python/mix_2016_25ns_SpringMC_PUScenarioV1_PoissonOOTPU_cfi.py
   
   double npuSpring16_25ns[50] = {
      0.000829312873542,
      0.00124276120498,
      0.00339329181587,
      0.00408224735376,
      0.00383036590008,
      0.00659159288946,
      0.00816022734493,
      0.00943640833116,
      0.0137777376066,
      0.017059392038,
      0.0213193035468,
      0.0247343174676,
      0.0280848773878,
      0.0323308476564,
      0.0370394341409,
      0.0456917721191,
      0.0558762890594,
      0.0576956187107,
      0.0625325287017,
      0.0591603758776,
      0.0656650815128,
      0.0678329011676,
      0.0625142146389,
      0.0548068448797,
      0.0503893295063,
      0.040209818868,
      0.0374446988111,
      0.0299661572042,
      0.0272024759921,
      0.0219328403791,
      0.0179586571619,
      0.0142926728247,
      0.00839941654725,		
      0.00522366397213,
      0.00224457976761,
      0.000779274977993,
      0.000197066585944,
      0.0000716031761328,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0};
   
   std::vector<double> puf(50.,0.);
   std::vector<double> pufUp(50.,0.);
   std::vector<double> pufDown(50.,0.);
   
   double tot = 0;
   double totUp = 0;
   double totDown = 0;
   for(unsigned int npu=0;npu<50;++npu)
     {	
	const double npuEst = _hpuNom->GetBinContent(_hpuNom->GetXaxis()->FindBin(npu));
	puf[npu] = (npuSpring16_25ns[npu]) ? npuEst / npuSpring16_25ns[npu] : 0.;
	tot += npuEst;

	const double npuEstUp = _hpuUp->GetBinContent(_hpuUp->GetXaxis()->FindBin(npu));
	pufUp[npu] = (npuSpring16_25ns[npu]) ? npuEstUp / npuSpring16_25ns[npu] : 0.;
	totUp += npuEstUp;

	const double npuEstDown = _hpuDown->GetBinContent(_hpuDown->GetXaxis()->FindBin(npu));
	pufDown[npu] = (npuSpring16_25ns[npu]) ? npuEstDown / npuSpring16_25ns[npu] : 0.;
	totDown += npuEstDown;
     }
   
   for(unsigned int npu=0;npu<50;++npu)
     {	
	puf[npu] /= tot;
	pufUp[npu] /= totUp;
	pufDown[npu] /= totDown;
     }

   _weights = puf;
   _weightsUp = pufUp;
   _weightsDown = pufDown;
}

double LTANA::PU::getPUWeight(int nPU,std::string opt)
{
  double w = 1.;
   
  if( _doPileup ) 
     {
	if( nPU >= 50 ) 
	  {
	     w = _weights.back();
	     if( opt == "up" ) w = _weightsUp.back();
	     if( opt == "down" ) w = _weightsDown.back();
	  } 
	else 
	  {
	     w = _weights.at(nPU);
	     if( opt == "up" ) w = _weightsUp.at(nPU);
	     if( opt == "down" ) w = _weightsDown.at(nPU);
	  }
     }
   
   return w;
}
