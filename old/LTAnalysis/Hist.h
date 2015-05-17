#ifndef LTANAHIST_H
#define LTANAHIST_H

#include "common.h"

namespace LTANA
{
   
   class Hist
     {

      public:
	Hist();
	virtual ~Hist();

//	void setEvent(std::vector<JTRUN::Event> *v)                  {_v_Event = v;};
//	void setJet(std::vector<JTRUN::Jet> *v)                      {_v_Jet = v;};

//	float deltaPhi(float phi1,float phi2);	

	bool passTrig(int trigIdx);
	
	void init();
	void fill();
	void close();
	void printout();
//	void totSys();
//	TLorentzVector jet_tlv(std::string sys,int ijet);
	float getVar(std::string sys,int ijet,std::string varName,int ibin);
	std::vector<float> getVarVec(std::string sys,int ijet,std::string varName,int ibin);
	std::pair<float,float> getVar2d(std::string sys,int ijet,std::string varName,int ibin);
	std::vector<float> getVar3d(std::string sys,int ijet,std::string varName,int ibin);
	float getPt(std::string sys);
	double DeltaR(double eta1,double phi1,double eta2,double phi2);
//	std::pair<float,float> getVar2d(std::string sys,int ijet,std::string varName);
//	float sfIP(float d0s);

	void initRePU();
	void initRePU2011();
	float WeightPU[60];
	float WeightPUmin[60];
	float WeightPUmax[60];
	
	double getSF(std::vector<std::pair<double,double> > vBin,
		     std::vector<std::pair<double,double> > vSf,
		     double var);
	double get2DSF(std::vector<std::pair<double,double> > vBinX,
		       std::vector<std::pair<double,double> > vBinY,
		       std::vector<std::pair<double,double> > vSf,
		       double varX,
		       double varY);
	double get3DSF(std::vector<std::pair<double,double> > vBinX,
		       std::vector<std::pair<double,double> > vBinY,
		       std::vector<std::pair<double,double> > vBinZ,
		       std::vector<std::pair<double,double> > vSf,
		       double varX,
		       double varY,
		       double varZ);
	
	std::string flav[1000];
	std::string jets[1000];
	std::string sys[1000];
	std::string sys_low[1000];
	std::string sys_up[1000];
	std::string histname_jet[1000];
	std::string sel[1000];
	std::string eta[1000];
	std::string selb[1000];
	std::string seladd[1000];
	std::string name_rw[1000];
	std::string name_rw_2d;
	std::string name_rw_3d;
	
	std::string histname_jet_2d[1000];
	std::string histname_jet_3d[1000];
	
	std::vector<std::string> hname;
	
	// var / ptbin / bins / x1,x2
	std::vector<std::vector<std::vector<std::pair<double,double> > > > rwBin;
	std::vector<std::vector<std::vector<std::pair<double,double> > > > rwSf;
	std::vector<std::vector<std::vector<std::pair<double,double> > > > rwBin_btag;
	std::vector<std::vector<std::vector<std::pair<double,double> > > > rwSf_btag;

	// var[0] / ptbin / bins / v1,v2
	std::vector<std::vector<std::vector<std::pair<double,double> > > > rw3DBinX;
	std::vector<std::vector<std::vector<std::pair<double,double> > > > rw3DBinY;
	std::vector<std::vector<std::vector<std::pair<double,double> > > > rw3DBinZ;
	std::vector<std::vector<std::vector<std::pair<double,double> > > > rw3DSf;
	
	// var[0] / ptbin / bins / v1,v2
	std::vector<std::vector<std::vector<std::pair<double,double> > > > rw2DBinX;
	std::vector<std::vector<std::vector<std::pair<double,double> > > > rw2DBinY;
	std::vector<std::vector<std::vector<std::pair<double,double> > > > rw2DSf;
	
	/*
	std::vector<float> psSf;
*/
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

	int nPtRelPtBins;
	float BTemplateCorrections[100][20][2];
	double muptcut;
	
	double jPtMin[100];
	double jPtMax[100];
	
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
/*DEFAULT	std::string histNAMES[5][19][1][10][1][10][25];
	std::string histNAMES_2d[5][19][1][10][1][10][25];
	std::string histNAMES_3d[5][19][1][10][1][10][25];*/
//	std::string histNAMES[5][19][1][10][1][20][1];
//	std::string histNAMES_2d[5][19][1][10][1][20][1];
//	std::string histNAMES_3d[5][19][1][10][1][20][1];
	std::string histNAMES[5][33][1][10][1][10][25];
	std::string histNAMES_2d[5][33][1][10][1][10][25];
	std::string histNAMES_3d[5][33][1][10][1][10][25];

	JetCorrectionUncertainty *jesTotal;
	
	double cJER[5];
	double cJER_down[5];
	double cJER_up[5];
	
	TLorentzVector *v_jet;
	TLorentzVector *v_jet_sys_jesTotalUp;
	TLorentzVector *v_jet_sys_jesTotalLow;
	TLorentzVector *v_jet_sys_jerTotalUp;
	TLorentzVector *v_jet_sys_jerTotalLow;
	TLorentzVector *v_mu;
	
//	std::ofstream _fevc;
	
	TRandom3 *rnd;
	
	TFile *_fout;
/*	TTree *_treePRESCALE;
	TTree *_treeBEAM;
	TTree *_treeSPLOT;
	TFile *_fd0s;
	TGraphErrors *_gd0s;
//	TTree *_treeTrig;
	std::ofstream _fevc;
	TRandom3 *rnd;
	
	float jPt;
	int   jPtBin;
	float PRESCALE;
	
	float sd0t1;
	float sd0t2;
	float cosphi;
	
	float ptrel;
	int fl;*/
     };
}

#endif
