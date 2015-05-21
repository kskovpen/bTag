#ifndef LTANASYST_H
#define LTANASYST_H

#include "Common.h"

#include "Helper.h"

// JES
#include "../../CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "../../CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"

namespace LTANA
{
   
   class Syst
     {

      public:
	Syst();
	virtual ~Syst();
	
	void init();
	void JEC(int ij);
	float Pileup(int npu,std::string sysName);
	float GluonSplitting(int ij,int flavch,std::string sysName);
	float bFrag(int ij,int flavch,std::string sysName);
	float cdFrag(int ij,int flavch,std::string sysName);
	float cFrag(int ij,int flavch,std::string sysName);
	float Ks(int ij,int flavch,std::string sysName);
	float GenNTrk(int ij,int flavch,std::string sysName);
	void clear();

	int nPtRelPtBins;
	float BTemplateCorrections[100][20][2];

	float WeightPU[60];
	float WeightPUmin[60];
	float WeightPUmax[60];
	
	void initRePU();
	
	TLorentzVector* v_jet() {return _v_jet;};
	TLorentzVector* v_jet_sys_jesTotalUp() {return _v_jet_sys_jesTotalUp;};
	TLorentzVector* v_jet_sys_jesTotalLow() {return _v_jet_sys_jesTotalLow;};
	TLorentzVector* v_jet_sys_jerTotalUp() {return _v_jet_sys_jerTotalUp;};
	TLorentzVector* v_jet_sys_jerTotalLow() {return _v_jet_sys_jerTotalLow;};
	
      private:

	JetCorrectionUncertainty *jesTotal;
	
	double cJER[5];
	double cJER_down[5];
	double cJER_up[5];
	
	Helper *helper;
	
	TLorentzVector *_v_jet;
	TLorentzVector *_v_jet_sys_jesTotalUp;
	TLorentzVector *_v_jet_sys_jesTotalLow;
	TLorentzVector *_v_jet_sys_jerTotalUp;
	TLorentzVector *_v_jet_sys_jerTotalLow;
	
	int _nChargedGen1_c;
	int _nChargedGen2_c;
     };
}

#endif
