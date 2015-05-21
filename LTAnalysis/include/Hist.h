#ifndef LTANAHIST_H
#define LTANAHIST_H

#include "Common.h"

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

	float getVar(std::string sys,int ijet,std::string varName,int ibin);
	std::vector<float> getVarVec(std::string sys,int ijet,std::string varName,int ibin);
	float getPt(std::string sys);
	double DeltaR(double eta1,double phi1,double eta2,double phi2);
	
	std::string flav[1000];
	std::string jets[1000];
	std::string sys[1000];
	std::string sys_low[1000];
	std::string sys_up[1000];
	std::string histname_jet[1000];
	std::vector<std::string> sel;
	std::string eta[1000];
	std::vector<std::string> selb;
	std::string seladd[1000];
	std::vector<std::string> name_rw;
	std::string name_rw_2d;
	std::string name_rw_3d;
	
	std::string histname_jet_2d[1000];
	std::string histname_jet_3d[1000];
	
	std::vector<std::string> hname;
	
	int sel_n;
	int eta_n;
	int selb_n;
	int seladd_n;
	int flav_n;
	int histname_jet_n;
	int histname_jet_2d_n;
	int histname_jet_3d_n;
	int sys_n;
	int sys_low_n;
	int sys_up_n;
	int n_jets;
	int rw_n;
	
	float Jet_Proba_New;
	int ntrkgen;

	double muptcut;
	
	std::vector<float> jPtMin;
	std::vector<float> jPtMax;
	
	std::vector<int> muidx;
	
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
	std::string histNAMES[5][33][1][10][1][10][25];
	std::string histNAMES_2d[5][33][1][10][1][10][25];
	std::string histNAMES_3d[5][33][1][10][1][10][25];
	
	TLorentzVector *v_mu;
	TLorentzVector *v_jet;
	
	TRandom3 *rnd;
	
	TFile *_fout;
	
	Syst *syst;
	Reweight *rw;
     };
}

#endif
