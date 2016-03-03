#ifndef LTANASYST_H
#define LTANASYST_H

#include "Common.h"

#include "Helper.h"

// JES
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"

#define SYS_NONE 0

#define SYS_PU_UP 1
#define SYS_GSPLIT_UP 2
#define SYS_BFRAG_UP 3
#define SYS_CDFRAG_UP 4
#define SYS_CFRAG_UP 5
#define SYS_KSL_UP 6
#define SYS_NTRKGEN_UP 7
#define SYS_JES_UP 8
#define SYS_JER_UP 9
#define SYS_NTRK_UP 10
#define SYS_NJET_UP 11
#define SYS_MUPT_UP 12
#define SYS_JETA_UP 13

#define SYS_PU_DOWN 1000
#define SYS_GSPLIT_DOWN 2000
#define SYS_BFRAG_DOWN 3000
#define SYS_CDFRAG_DOWN 4000
#define SYS_CFRAG_DOWN 5000
#define SYS_KSL_DOWN 6000
#define SYS_NTRKGEN_DOWN 7000
#define SYS_JES_DOWN 8000
#define SYS_JER_DOWN 9000
#define SYS_NTRK_DOWN 10000
#define SYS_NJET_DOWN 11000
#define SYS_MUPT_DOWN 12000
#define SYS_JETA_DOWN 13000

namespace LTANA
{
   
   class Syst
     {

      public:
	Syst();
	virtual ~Syst();
	
	void init(std::string jtype = "");
	void JEC(int ij,bool isSub = 0);
	float Pileup(int npu,int isys,TH1D *h_pu);
	float GluonSplitting(int ij,int flavch,int isys,std::string jtype = "");
	float bFrag(int ij,int flavch,int isys,std::string jtype = "");
	float cdFrag(int ij,int flavch,int isys,std::string jtype = "");
	float cFrag(int ij,int flavch,int isys,std::string jtype = "");
	float Ks(int ij,int flavch,int isys,std::string jtype = "");
	float GenNTrk(int ij,int flavch,int isys,std::string jtype = "");
	void clear();

	int nPtRelPtBins;
	float BTemplateCorrections[100][20][2];

	float WeightPU[60];
	float WeightPUmin[60];
	float WeightPUmax[60];
	
	TLorentzVector* v_jet() {return _v_jet;};
	TLorentzVector* v_jet_sys_jesTotalUp() {return _v_jet_sys_jesTotalUp;};
	TLorentzVector* v_jet_sys_jesTotalDown() {return _v_jet_sys_jesTotalDown;};
	TLorentzVector* v_jet_sys_jerTotalUp() {return _v_jet_sys_jerTotalUp;};
	TLorentzVector* v_jet_sys_jerTotalDown() {return _v_jet_sys_jerTotalDown;};
	
	std::string *sysNameDown() {return _sysNameDown;};
	std::string *sysNameUp() {return _sysNameUp;};
	
      private:

	JetCorrectionUncertainty *jesTotal;
	
	double cJER[5];
	double cJER_down[5];
	double cJER_up[5];
	
	Helper *helper;
	
	TLorentzVector *_v_jet;
	TLorentzVector *_v_jet_sys_jesTotalUp;
	TLorentzVector *_v_jet_sys_jesTotalDown;
	TLorentzVector *_v_jet_sys_jerTotalUp;
	TLorentzVector *_v_jet_sys_jerTotalDown;
	
	std::string _sysNameDown[100];
	std::string _sysNameUp[100];
     };
}

#endif
