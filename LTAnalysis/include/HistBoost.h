#ifndef LTANAHISTBOOST_H
#define LTANAHISTBOOST_H

#include "Common.h"

#define HISTFAT_J1_PT 0
#define HISTFAT_J1_NSELTRK 1
#define HISTFAT_J1_ETA 2
#define HISTFAT_J1_NTRK 3
#define HISTFAT_J1_NJET 4
#define HISTFAT_J1_NSV 5
#define HISTFAT_J1_MUPT 6
#define HISTFAT_J1_JP 7
#define HISTFAT_PTHAT 8
#define HISTFAT_NPV 9
#define HISTFAT_J1_CSVIVF 10
#define HISTFAT_J1_MUPTREL 11
#define HISTFAT_J1_NTRKGEN 12
#define HISTFAT_J1_DRAWAY 13
#define HISTFAT_J1_CSVAWAY 14
#define HISTFAT_J1_TCHPAWAY 15
#define HISTFAT_J1_JPAWAY 16
#define HISTFAT_J1_PTAWAY 17
#define HISTFAT_J1_ETAAWAY 18
#define HISTFAT_J1_TAU21 19
#define HISTFAT_J1_SOFTDROPMASS 20
#define HISTFAT_J1_MASS 21
#define HISTFAT_J1_DRJ4J8MIN 22

#define HISTSUB_J1_PT 0
#define HISTSUB_J1_NSELTRK 1
#define HISTSUB_J1_ETA 2
#define HISTSUB_J1_NTRK 3
#define HISTSUB_J1_NJET 4
#define HISTSUB_J1_NSV 5
#define HISTSUB_J1_MUPT 6
#define HISTSUB_J1_JP 7
#define HISTSUB_J1_CSVIVF 8
#define HISTSUB_J1_MUPTREL 9
#define HISTSUB_J1_NTRKGEN 10
#define HISTSUB_J1_DRAWAY 11
#define HISTSUB_J1_CSVAWAY 12
#define HISTSUB_J1_TCHPAWAY 13
#define HISTSUB_J1_JPAWAY 14
#define HISTSUB_J1_PTAWAY 15
#define HISTSUB_J1_ETAAWAY 16
#define HISTSUB_J1_MASS 17

#define HISTFAT_2D_J1_PT_VS_JETA 0
#define HISTFAT_2D_J1_JP_VS_CSV 1
#define HISTFAT_2D_J1_JP_VS_CMVA 2

#define HISTSUB_2D_J1_PT_VS_JETA 0
#define HISTSUB_2D_J1_JP_VS_CSV 1
#define HISTSUB_2D_J1_JP_VS_CMVA 2

#define BTAGBOOST_NONE 0
#define BTAGBOOST_CSVL 1
#define BTAGBOOST_CSVM 2
#define BTAGBOOST_CSVT 3
#define BTAGBOOST_TCHPL 4
#define BTAGBOOST_TCHPM 5
#define BTAGBOOST_TCHPT 6
#define BTAGBOOST_UNTAGCSVL 7
#define BTAGBOOST_UNTAGCSVM 8
#define BTAGBOOST_UNTAGCSVT 9
#define BTAGBOOST_CMVAL 10
#define BTAGBOOST_CMVAM 11
#define BTAGBOOST_CMVAT 12
#define BTAGBOOST_UNTAGCMVAL 13
#define BTAGBOOST_UNTAGCMVAM 14
#define BTAGBOOST_UNTAGCMVAT 15

namespace LTANA
{
   
   class HistBoost
     {

      public:
	HistBoost();
	virtual ~HistBoost();

	bool passTrig(int trigIdx);
	
	void init();
	void fill();
	void close();

	float getVar(int isys,int ijet,int varId,int ibin,bool isSub);
	std::vector<float> getVar2d(int isys,int ijet,int varId,int ibin,bool isSub);
	std::vector<float> getVarVec(int isys,int ijet,int varId,int ibin);
	float getPt(int isys,bool isSub);
	
	std::string flav[1000];
	std::string jets[1000];
	std::vector<int> sys_FatJet;
	std::vector<int> sys_SubJet;
	int sys_down[1000];
	int sys_up[1000];
	
	std::vector<int> hist_FatJet;
	std::vector<int> hist_FatJet_2d;

	std::vector<int> hist_SubJet;
	std::vector<int> hist_SubJet_2d;
	
	std::vector<std::string> sel_FatJet;
	std::vector<std::string> sel_SubJet;
	
	std::string eta[1000];
	std::vector<int> selb;
	std::string seladd[1000];
	std::vector<std::string> name_rw_FatJet;
	std::vector<std::string> name_rw_2d_FatJet;
	std::vector<std::string> name_rw_SubJet;
	std::vector<std::string> name_rw_2d_SubJet;
	
	std::string histname_FatJet_2d[1000];
	std::string histname_FatJet_3d[1000];

	std::string histname_SubJet_2d[1000];
	std::string histname_SubJet_3d[1000];
	
	std::vector<std::string> hname_FatJet;
	std::vector<std::string> hname_2d_FatJet;

	std::vector<std::string> hname_SubJet;
	std::vector<std::string> hname_2d_SubJet;
	
	int sel_FatJet_n;
	int sel_SubJet_n;
	int eta_n;
	int selb_n;
	int seladd_n;
	int flav_n;
	
	int hist_FatJet_n;
	int hist_FatJet_2d_n;

	int hist_SubJet_n;
	int hist_SubJet_2d_n;
	
	int sys_FatJet_n;
	int sys_SubJet_n;
	int sys_down_n;
	int sys_up_n;
	int n_jets;
	int rw_n;
	
	float FatJet_Proba_New;
	float FatJet_tau21;
	float SubJet_Proba_New;
	int ntrkgen;
	float drAway;
	float csvAway;
	float tchpAway;
	float jpAway;
	float ptAway;
	float etaAway;

	double muptcut;
	
	std::vector<float> jPtMin_FatJet;
	std::vector<float> jPtMax_FatJet;

	std::vector<float> jPtMin_SubJet;
	std::vector<float> jPtMax_SubJet;
	
	std::vector<int> muidx;
	int muIdx;
	
	bool fillThis;
	
	double drj4j8Min;
	
      protected:

	std::map<std::string, TH1D*> *_m1d_FatJet;
	std::map<std::string, TH2D*> *_m2d_FatJet;
	std::map<std::string, TH3D*> *_m3d_FatJet;

	std::map<std::string, TH1D*> *_m1d_SubJet;
	std::map<std::string, TH2D*> *_m2d_SubJet;
	std::map<std::string, TH3D*> *_m3d_SubJet;
	
	std::vector<std::pair<std::vector<std::string>,double*> > *_s_FatJet;
	std::vector<std::pair<std::vector<std::string>,double*> > *_s2_FatJet;
	std::vector<std::pair<std::vector<std::string>,double*> > *_s3_FatJet;

	std::vector<std::pair<std::vector<std::string>,double*> > *_s_SubJet;
	std::vector<std::pair<std::vector<std::string>,double*> > *_s2_SubJet;
	std::vector<std::pair<std::vector<std::string>,double*> > *_s3_SubJet;
	
      private:

	// [FLAVOUR][PT][ETA][BTAG][ADDSEL][VAR][2*(NSYS-1)+1]
/*	std::string histNAMES_FatJet[5][10][1][16][1][2][25];
	std::string histNAMES_2d_FatJet[5][10][1][16][1][2][25];
	std::string histNAMES_3d_FatJet[5][10][1][16][1][2][25];

	std::string histNAMES_SubJet[5][10][1][16][1][2][25];
	std::string histNAMES_2d_SubJet[5][10][1][16][1][2][25];
	std::string histNAMES_3d_SubJet[5][10][1][16][1][2][25];*/

	std::string histNAMES_FatJet[5][14][1][16][1][12][4];
	std::string histNAMES_2d_FatJet[5][14][1][16][1][12][4];
	std::string histNAMES_3d_FatJet[5][14][1][16][1][12][4];

	std::string histNAMES_SubJet[5][14][1][16][1][12][4];
	std::string histNAMES_2d_SubJet[5][14][1][16][1][12][4];
	std::string histNAMES_3d_SubJet[5][14][1][16][1][12][4];

	TLorentzVector *v_mu_FatJet;
	TLorentzVector *v_FatJet;

	TLorentzVector *v_mu_SubJet;
	TLorentzVector *v_SubJet;
	
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
	
	Syst *systFat;
	Syst *systSub;
	Reweight *rw_FatJet;
	Reweight *rw_SubJet;
	
	std::string sysNameFat[1000];
	std::string sysNameSub[1000];
	
	std::string histNameDefined_FatJet[1000];
	std::string histName_FatJet[1000];

	std::string histNameDefined_FatJet_2d[1000];
	std::string histName_2d_FatJet[1000];

	std::string histNameDefined_SubJet[1000];
	std::string histName_SubJet[1000];

	std::string histNameDefined_SubJet_2d[1000];
	std::string histName_2d_SubJet[1000];
	
	std::string selbNameDefined[1000];
	std::vector<std::string> selbName;
     };
}

#endif
