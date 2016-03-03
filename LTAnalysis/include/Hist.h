#ifndef LTANAHIST_H
#define LTANAHIST_H

#include "Common.h"

#define HIST_J1_PT 0
#define HIST_J1_NSELTRK 1
#define HIST_J1_ETA 2
#define HIST_J1_NTRK 3
#define HIST_J1_NJET 4
#define HIST_J1_NSV 5
#define HIST_J1_MUPT 6
#define HIST_J1_JP 7
#define HIST_PTHAT 8
#define HIST_NPV 9
#define HIST_J1_CSVIVF 10
#define HIST_J1_MUPTREL 11
#define HIST_J1_NTRKGEN 12
#define HIST_J1_DRAWAY 13
#define HIST_J1_CSVAWAY 14
#define HIST_J1_TCHPAWAY 15
#define HIST_J1_JPAWAY 16
#define HIST_J1_PTAWAY 17
#define HIST_J1_ETAAWAY 18
#define HIST_J1_HASMUON 19

#define HIST_2D_J1_PT_VS_JETA 0
#define HIST_2D_J1_JP_VS_CSV 1
#define HIST_2D_J1_JP_VS_CMVA 2

#define BTAG_NONE 0
#define BTAG_CSVL 1
#define BTAG_CSVM 2
#define BTAG_CSVT 3
#define BTAG_TCHPL 4
#define BTAG_TCHPM 5
#define BTAG_TCHPT 6
#define BTAG_UNTAGCSVL 7
#define BTAG_UNTAGCSVM 8
#define BTAG_UNTAGCSVT 9
#define BTAG_CMVAL 10
#define BTAG_CMVAM 11
#define BTAG_CMVAT 12
#define BTAG_UNTAGCMVAL 13
#define BTAG_UNTAGCMVAM 14
#define BTAG_UNTAGCMVAT 15

namespace LTANA
{
   
   class Hist
     {

      public:
	Hist();
	virtual ~Hist();

	bool passTrig(int trigIdx);
	
	void init();
	void fill();
	void close();

	float getVar(int isys,int ijet,int varId,int ibin);
	std::vector<float> getVar2d(int isys,int ijet,int varId,int ibin);
	std::vector<float> getVarVec(int isys,int ijet,int varId,int ibin);
	float getPt(int isys);
	
	std::string flav[1000];
	std::string jets[1000];
	std::vector<int> sys;
	int sys_down[1000];
	int sys_up[1000];
	std::vector<int> hist_jet;
	std::vector<int> hist_jet_2d;
	std::vector<std::string> sel;
	std::string eta[1000];
	std::vector<int> selb;
	std::string seladd[1000];
	std::vector<std::string> name_rw;
	std::vector<std::string> name_rw_2d;
	
	std::string histname_jet_2d[1000];
	std::string histname_jet_3d[1000];
	
	std::vector<std::string> hname;
	std::vector<std::string> hname_2d;
	
	int sel_n;
	int eta_n;
	int selb_n;
	int seladd_n;
	int flav_n;
	int hist_jet_n;
	int hist_jet_2d_n;
	int sys_n;
	int sys_down_n;
	int sys_up_n;
	int n_jets;
	int rw_n;
	
	float Jet_Proba_New;
	int ntrkgen;
	float drAway;
	float csvAway;
	float tchpAway;
	float jpAway;
	float ptAway;
	float etaAway;

	double muptcut;
	
	std::vector<float> jPtMin;
	std::vector<float> jPtMax;
	
	std::vector<int> muidx;
	bool hasMuon;
	
	bool fillThis;
	
      protected:

	std::map<std::string, TH1D*> *_m1d_Jet;
	std::map<std::string, TH2D*> *_m2d_Jet;
	std::map<std::string, TH3D*> *_m3d_Jet;

	std::vector<std::pair<std::vector<std::string>,double*> > *_s_Jet;	
	std::vector<std::pair<std::vector<std::string>,double*> > *_s2_Jet;
	std::vector<std::pair<std::vector<std::string>,double*> > *_s3_Jet;
	
      private:

	// [FLAVOUR][PT][ETA][BTAG][ADDSEL][VAR][2*(NSYS-1)+1]
	std::string histNAMES[5][15][1][20][1][10][25];
	std::string histNAMES_2d[5][15][1][20][1][10][25];
	std::string histNAMES_3d[5][15][1][20][1][10][25];

	TLorentzVector *v_mu;
	TLorentzVector *v_jet;
	
	TRandom3 *rnd;
	
	TFile *_fout;

	TH1D *_h_pileup;
	
	TTree *ttree;
	int t_eventId;
	int t_runId;
	int t_lumiId;
	float t_j1Pt;
	float t_j1Eta;
	float t_j2Pt;
	float t_j2Eta;
	float t_j3Pt;
	float t_j3Eta;
	float t_j4Pt;
	float t_j4Eta;
	
	Syst *syst;
	Reweight *rw;
	
	std::string sysName[1000];
	
	std::string histNameDefined_jet[1000];
	std::string histName_jet[1000];

	std::string histNameDefined_jet_2d[1000];
	std::string histName_jet_2d[1000];
	
	std::string selbNameDefined[1000];
	std::vector<std::string> selbName;
     };
}

#endif
