std::ofstream fsf;

void makeFitPlotSFSYS()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x def.C");
   gROOT->ProcessLine(".x common.C");

//   const int nbTot = 16;
   const int nbTot = 17;
   bool showOnlyStat = 0;
   bool showOnlySys = 0;
   bool symSyst = 0;
   bool drawMinuitErr = 0;
   int drawOfficial = 0;
   bool drawSF = 1;
   bool isJ1 = 0;
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);

   std::string j1 = "";
   std::string wp = "TIGHT";
//   if( isJ1 ) j1 = "J1";
//   std::string app = "_RWMAX";
   std::string app = "_MAX";
//   std::string app = "_BARLOW";
   int sidx = -1; // -1: all, 666: stat, 667: Cb
   std::string csv = "#bf{CSVT}";
   
   std::string j1_add = "";
   if( isJ1 ) j1_add = "J1";
   std::string wp_add = "MEDIUM";
   std::string app_add = "_MAX";
   std::string addname = "J1";

   bool add = 0;
   
   const int nsys = 13;
   std::string sysIdxPos[nsys];
   sysIdxPos[0] = "1";
   sysIdxPos[1] = "2";
   sysIdxPos[2] = "3";
   sysIdxPos[3] = "4";
   sysIdxPos[4] = "5";
   sysIdxPos[5] = "6";
   sysIdxPos[6] = "7";
   sysIdxPos[7] = "8";
   sysIdxPos[8] = "9";
   sysIdxPos[9] = "10";
   sysIdxPos[10] = "11";
   sysIdxPos[11] = "12";
   sysIdxPos[12] = "13";
   std::string sysIdxNeg[nsys];
   sysIdxNeg[0] = "-1";
   sysIdxNeg[1] = "-2";
   sysIdxNeg[2] = "-3";
   sysIdxNeg[3] = "-4";
   sysIdxNeg[4] = "-5";
   sysIdxNeg[5] = "-6";
   sysIdxNeg[6] = "-7";
   sysIdxNeg[7] = "-8";
   sysIdxNeg[8] = "-9";
   sysIdxNeg[9] = "-10";
   sysIdxNeg[10] = "-11";
   sysIdxNeg[11] = "-12";
   sysIdxNeg[12] = "-13";

/*   const int nsys = 0;
   std::string sysIdxPos[nsys];
   std::string sysIdxPos[nsys];*/
   
//   const int nstat = 10;
   const int nstat = 100;
   std::string statIdx[nstat];
   for(int i=0;i<nstat;i++)
     {
	statIdx[i] = Form("%d",666+i);
     }   

   double cb_nosel[nbTot];
   double cberr_nosel[nbTot];
//   std::ifstream f_cb_nosel("../../cb_nosel.txt");
   std::ifstream f_cb_nosel("../../cb_d.txt");
   while( !f_cb_nosel.eof() )
     {
	int ptidx;
	f_cb_nosel >> ptidx >> cb_nosel[ptidx] >> cberr_nosel[nbTot];
     }   
   
   TFile *fsfNom;
   TH1D *hsfNom;
   TFile *fsfPos[nsys];
   TH1D *hsfPos[nsys];
   TFile *fsfNeg[nsys];
   TH1D *hsfNeg[nsys];
   TFile *fsfStat[nstat];
   TH1D *hsfStat[nstat];

   TFile *fsfNom_add;
   TH1D *hsfNom_add;
   TFile *fsfPos_add[nsys];
   TH1D *hsfPos_add[nsys];
   TFile *fsfNeg_add[nsys];
   TH1D *hsfNeg_add[nsys];
   TFile *fsfStat_add[nstat];
   TH1D *hsfStat_add[nstat];
   
   TH1D *heffMCNom;
   TH1D *heffMCPos[nsys];
   TH1D *heffMCNeg[nsys];
   TH1D *heffMCStat[nstat];

   TH1D *heffDATANom;
   TH1D *heffDATAPos[nsys];
   TH1D *heffDATANeg[nsys];
   TH1D *heffDATAStat[nstat];
   
   TFile *fparNom_before;
   TH1D *hparNom_before_p1;
   TH1D *hparNom_before_p2;
   TH1D *hparNom_before_p3;
   TFile *fparPos_before[nsys];
   TH1D *hparPos_before_p1[nsys];
   TH1D *hparPos_before_p2[nsys];
   TH1D *hparPos_before_p3[nsys];
   TFile *fparNeg_before[nsys];
   TH1D *hparNeg_before_p1[nsys];
   TH1D *hparNeg_before_p2[nsys];
   TH1D *hparNeg_before_p3[nsys];
   TFile *fparStat_before[nstat];
   TH1D *hparStat_before_p1[nstat];
   TH1D *hparStat_before_p2[nstat];
   TH1D *hparStat_before_p3[nstat];

   TFile *fparNom_after;
   TH1D *hparNom_after_p1;
   TH1D *hparNom_after_p2;
   TH1D *hparNom_after_p3;
   TFile *fparPos_after[nsys];
   TH1D *hparPos_after_p1[nsys];
   TH1D *hparPos_after_p2[nsys];
   TH1D *hparPos_after_p3[nsys];
   TFile *fparNeg_after[nsys];
   TH1D *hparNeg_after_p1[nsys];
   TH1D *hparNeg_after_p2[nsys];
   TH1D *hparNeg_after_p3[nsys];
   TFile *fparStat_after[nstat];
   TH1D *hparStat_after_p1[nstat];
   TH1D *hparStat_after_p2[nstat];
   TH1D *hparStat_after_p3[nstat];
   
   std::string fnameSys = "0";
   std::string fname = "results/SFSYS_"+j1+wp+app+"/fit_EFF_beauty_ALL_"+fnameSys+".root";
   fsfNom = TFile::Open(fname.c_str());
   hsfNom = (TH1D*)fsfNom->Get("h1c");
   heffMCNom = (TH1D*)fsfNom->Get("h_eff1MC");
   heffDATANom = (TH1D*)fsfNom->Get("h_eff1DATA");

   fname = "results/SFSYS_"+j1+wp+app+"/fit_FIT123_beforeBTAG_"+fnameSys+".root";
   fparNom_before = TFile::Open(fname.c_str());
   hparNom_before_p1 = (TH1D*)fparNom_before->Get("h_p1f1");
   hparNom_before_p2 = (TH1D*)fparNom_before->Get("h_p2f1");
   hparNom_before_p3 = (TH1D*)fparNom_before->Get("h_p3f1");

   fname = "results/SFSYS_"+j1+wp+app+"/fit_FIT123_afterBTAG_"+fnameSys+".root";
   fparNom_after = TFile::Open(fname.c_str());
   hparNom_after_p1 = (TH1D*)fparNom_after->Get("h_p1f1");
   hparNom_after_p2 = (TH1D*)fparNom_after->Get("h_p2f1");
   hparNom_after_p3 = (TH1D*)fparNom_after->Get("h_p3f1");
   
   for(int i=0;i<nsys;i++)
     {
	std::string fnameSys = sysIdxPos[i];
	std::string fname = "results/SFSYS_"+j1+wp+app+"/fit_EFF_beauty_ALL_"+fnameSys+".root";
	fsfPos[i] = TFile::Open(fname.c_str());
	hsfPos[i] = (TH1D*)fsfPos[i]->Get("h1c");
	heffMCPos[i] = (TH1D*)fsfPos[i]->Get("h_eff1MC");
	heffDATAPos[i] = (TH1D*)fsfPos[i]->Get("h_eff1DATA");
	
	fname = "results/SFSYS_"+j1+wp+app+"/fit_FIT123_beforeBTAG_"+fnameSys+".root";
	fparPos_before[i] = TFile::Open(fname.c_str());
	hparPos_before_p1[i] = (TH1D*)fparPos_before[i]->Get("h_p1f1");
	hparPos_before_p2[i] = (TH1D*)fparPos_before[i]->Get("h_p2f1");
	hparPos_before_p3[i] = (TH1D*)fparPos_before[i]->Get("h_p3f1");

	fname = "results/SFSYS_"+j1+wp+app+"/fit_FIT123_afterBTAG_"+fnameSys+".root";
	fparPos_after[i] = TFile::Open(fname.c_str());
	hparPos_after_p1[i] = (TH1D*)fparPos_after[i]->Get("h_p1f1");
	hparPos_after_p2[i] = (TH1D*)fparPos_after[i]->Get("h_p2f1");
	hparPos_after_p3[i] = (TH1D*)fparPos_after[i]->Get("h_p3f1");
     }
   for(int i=0;i<nsys;i++)
     {
	std::string fnameSys = sysIdxNeg[i];
	std::string fname = "results/SFSYS_"+j1+wp+app+"/fit_EFF_beauty_ALL_"+fnameSys+".root";
	fsfNeg[i] = TFile::Open(fname.c_str());
	hsfNeg[i] = (TH1D*)fsfNeg[i]->Get("h1c");
	heffMCNeg[i] = (TH1D*)fsfNeg[i]->Get("h_eff1MC");
	heffDATANeg[i] = (TH1D*)fsfNeg[i]->Get("h_eff1DATA");

	fname = "results/SFSYS_"+j1+wp+app+"/fit_FIT123_beforeBTAG_"+fnameSys+".root";
	fparNeg_before[i] = TFile::Open(fname.c_str());
	hparNeg_before_p1[i] = (TH1D*)fparNeg_before[i]->Get("h_p1f1");
	hparNeg_before_p2[i] = (TH1D*)fparNeg_before[i]->Get("h_p2f1");
	hparNeg_before_p3[i] = (TH1D*)fparNeg_before[i]->Get("h_p3f1");

	fname = "results/SFSYS_"+j1+wp+app+"/fit_FIT123_afterBTAG_"+fnameSys+".root";
	fparNeg_after[i] = TFile::Open(fname.c_str());
	hparNeg_after_p1[i] = (TH1D*)fparNeg_after[i]->Get("h_p1f1");
	hparNeg_after_p2[i] = (TH1D*)fparNeg_after[i]->Get("h_p2f1");
	hparNeg_after_p3[i] = (TH1D*)fparNeg_after[i]->Get("h_p3f1");
     }

   for(int i=0;i<nstat;i++)
     {
	std::string fnameStat = statIdx[i];
	std::string fname = "results/SFSYS_"+j1+wp+app+"/fit_EFF_beauty_ALL_"+fnameStat+".root";
	fsfStat[i] = TFile::Open(fname.c_str());
	hsfStat[i] = (TH1D*)fsfStat[i]->Get("h1c");
	heffMCStat[i] = (TH1D*)fsfStat[i]->Get("h_eff1MC");
	heffDATAStat[i] = (TH1D*)fsfStat[i]->Get("h_eff1DATA");

	fname = "results/SFSYS_"+j1+wp+app+"/fit_FIT123_beforeBTAG_"+fnameStat+".root";
	fparStat_before[i] = TFile::Open(fname.c_str());
	hparStat_before_p1[i] = (TH1D*)fparStat_before[i]->Get("h_p1f1");
	hparStat_before_p2[i] = (TH1D*)fparStat_before[i]->Get("h_p2f1");
	hparStat_before_p3[i] = (TH1D*)fparStat_before[i]->Get("h_p3f1");

	fname = "results/SFSYS_"+j1+wp+app+"/fit_FIT123_afterBTAG_"+fnameStat+".root";
	fparStat_after[i] = TFile::Open(fname.c_str());
	hparStat_after_p1[i] = (TH1D*)fparStat_after[i]->Get("h_p1f1");
	hparStat_after_p2[i] = (TH1D*)fparStat_after[i]->Get("h_p2f1");
	hparStat_after_p3[i] = (TH1D*)fparStat_after[i]->Get("h_p3f1");
     }
         
   std::string fnameSys_add = "0";
   std::string fname_add = "results/SFSYS_"+j1_add+wp_add+app_add+"/fit_EFF_beauty_ALL_"+fnameSys_add+".root";
   fsfNom_add = TFile::Open(fname_add.c_str());
   hsfNom_add = (TH1D*)fsfNom_add->Get("h1c");
   heffMCNom_add = (TH1D*)fsfNom_add->Get("h_eff1MC");
   heffDATANom_add = (TH1D*)fsfNom_add->Get("h_eff1DATA");

   fname_add = "results/SFSYS_"+j1_add+wp_add+app_add+"/fit_FIT123_beforeBTAG_"+fnameSys_add+".root";
   fparNom_before_add = TFile::Open(fname_add.c_str());
   hparNom_before_p1_add = (TH1D*)fparNom_before_add->Get("h_p1f1");
   hparNom_before_p2_add = (TH1D*)fparNom_before_add->Get("h_p2f1");
   hparNom_before_p3_add = (TH1D*)fparNom_before_add->Get("h_p3f1");

   fname_add = "results/SFSYS_"+j1_add+wp_add+app_add+"/fit_FIT123_afterBTAG_"+fnameSys_add+".root";
   fparNom_after_add = TFile::Open(fname_add.c_str());
   hparNom_after_p1_add = (TH1D*)fparNom_after_add->Get("h_p1f1");
   hparNom_after_p2_add = (TH1D*)fparNom_after_add->Get("h_p2f1");
   hparNom_after_p3_add = (TH1D*)fparNom_after_add->Get("h_p3f1");
   
   for(int i=0;i<nsys;i++)
     {
	std::string fnameSys = sysIdxPos[i];
	std::string fname = "results/SFSYS_"+j1_add+wp_add+app_add+"/fit_EFF_beauty_ALL_"+fnameSys+".root";
	fsfPos_add[i] = TFile::Open(fname.c_str());
	hsfPos_add[i] = (TH1D*)fsfPos_add[i]->Get("h1c");
     }
   for(int i=0;i<nsys;i++)
     {
	std::string fnameSys = sysIdxNeg[i];
	std::string fname = "results/SFSYS_"+j1_add+wp_add+app_add+"/fit_EFF_beauty_ALL_"+fnameSys+".root";
	fsfNeg_add[i] = TFile::Open(fname.c_str());
	hsfNeg_add[i] = (TH1D*)fsfNeg_add[i]->Get("h1c");
     }

   for(int i=0;i<nstat;i++)
     {
	std::string fnameStat = statIdx[i];
	std::string fname = "results/SFSYS_"+j1_add+wp_add+app_add+"/fit_EFF_beauty_ALL_"+fnameStat+".root";
	fsfStat_add[i] = TFile::Open(fname.c_str());
	hsfStat_add[i] = (TH1D*)fsfStat_add[i]->Get("h1c");
     }
   
   const int npt = 16;
   
   double sf_off[npt];
   double err_off[npt];
   std::string offname = "official/CSVM.txt";
   if( wp == "LOOSE" ) offname = "official/CSVL.txt";
   if( wp == "TIGHT" ) offname = "official/CSVT.txt";
   std::ifstream f_off(offname.c_str());
//   std::ifstream f_off("official/CSVM.txt");
//   std::ifstream f_off("official/CSVM_withTTBAR.txt");
   for(int i=0;i<npt;i++)
     {
	f_off >> sf_off[i] >> err_off[i];
     }   
   f_off.close();

   double sf_lt[npt];
   double err_lt[npt];
   double stat_lt[npt];
   double syst_lt[npt];
   std::string ltname = "official/LT_CSVM.txt";
   if( wp == "LOOSE" ) ltname = "official/LT_CSVL.txt";
   if( wp == "TIGHT" ) ltname = "official/LT_CSVT.txt";
//   std::ifstream f_lt("official/LT_CSVM.txt");
   std::ifstream f_lt(ltname.c_str());
   for(int i=0;i<npt;i++)
     {
	f_lt >> sf_lt[i] >> stat_lt[i] >> syst_lt[i] >> err_lt[i];
     }   
   f_lt.close();

   double effMC_lt[npt];
   double effMC_stat_lt[npt];
   double effDATA_lt[npt];
   double effDATA_stat_lt[npt];
   std::string ltname_eff = "official/LT_CSVM_EFF.txt";
   if( wp == "LOOSE" ) ltname_eff = "official/LT_CSVL_EFF.txt";
   if( wp == "TIGHT" ) ltname_eff = "official/LT_CSVT_EFF.txt";
   std::ifstream f_eff_lt(ltname_eff.c_str());
   for(int i=0;i<npt;i++)
     {
	f_eff_lt >> effDATA_lt[i] >> effDATA_stat_lt[i] >> effMC_lt[i] >> effMC_stat_lt[i];
     }   
   f_eff_lt.close();
   
   TH1D *sf_dist = new TH1D("sf_dist","sf_dist",30,0.9,1.1);
   TH1D *p1_dist = new TH1D("p1_dist","p1_dist",30,0.9,1.1);
   TH1D *p2_dist = new TH1D("p2_dist","p2_dist",30,0.9,1.1);
   TH1D *p3_dist = new TH1D("p3_dist","p3_dist",30,0.9,1.1);
   
   TH1D *sf_nom = (TH1D*)hsfNom->Clone("sf_nom");
   TH1D *effMC_nom = (TH1D*)heffMCNom->Clone("effMC_nom");
   TH1D *effDATA_nom = (TH1D*)heffDATANom->Clone("effDATA_nom");
   TH1D *p1_before_nom = (TH1D*)hparNom_before_p1->Clone("p1_before_nom");
   TH1D *p2_before_nom = (TH1D*)hparNom_before_p2->Clone("p2_before_nom");
   TH1D *p3_before_nom = (TH1D*)hparNom_before_p3->Clone("p3_before_nom");
   TH1D *p1_after_nom = (TH1D*)hparNom_after_p1->Clone("p1_after_nom");
   TH1D *p2_after_nom = (TH1D*)hparNom_after_p2->Clone("p2_after_nom");
   TH1D *p3_after_nom = (TH1D*)hparNom_after_p3->Clone("p3_after_nom");
   
   TH1D *sf_nom_add = (TH1D*)hsfNom_add->Clone("sf_nom_add");
   
   int nbins0 = sf_nom->GetXaxis()->GetNbins();
   nbins0 = (nbTot < nbins0) ? nbTot : nbins0;
   const int nbins = nbins0;
   
   double sfPos[nbins];
   double sfNeg[nbins];
   double sfNom[nbins];
   double sfStat[nbins];
   double sfupTot[nbins];
   double sfdownTot[nbins];

   double sfPos_add[nbins];
   double sfNeg_add[nbins];
   double sfNom_add[nbins];
   double sfStat_add[nbins];
   double sfupTot_add[nbins];
   double sfdownTot_add[nbins];
   
   double sfnomTable[nbins];
   double sfstatTable[nbins];
   double sfupTable[nbins][nsys+1];
   double sfdownTable[nbins][nsys+1];
   double sfsystupTable[nbins];
   double sfsystdownTable[nbins];

   double effMCPos[nbins];
   double effMCNeg[nbins];
   double effMCNom[nbins];
   double effMCStat[nbins];
   double effMCupTot[nbins];
   double effMCdownTot[nbins];

   double effDATAPos[nbins];
   double effDATANeg[nbins];
   double effDATANom[nbins];
   double effDATAStat[nbins];
   double effDATAupTot[nbins];
   double effDATAdownTot[nbins];
   
   double parPos_before_p1[nbins];
   double parNeg_before_p1[nbins];
   double parNom_before_p1[nbins];
   double parStat_before_p1[nbins];
   double parupTot_before_p1[nbins];
   double pardownTot_before_p1[nbins];

   double parPos_before_p2[nbins];
   double parNeg_before_p2[nbins];
   double parNom_before_p2[nbins];
   double parStat_before_p2[nbins];
   double parupTot_before_p2[nbins];
   double pardownTot_before_p2[nbins];
   
   double parPos_before_p3[nbins];
   double parNeg_before_p3[nbins];
   double parNom_before_p3[nbins];
   double parStat_before_p3[nbins];
   double parupTot_before_p3[nbins];
   double pardownTot_before_p3[nbins];

   double parPos_after_p1[nbins];
   double parNeg_after_p1[nbins];
   double parNom_after_p1[nbins];
   double parStat_after_p1[nbins];
   double parupTot_after_p1[nbins];
   double pardownTot_after_p1[nbins];

   double parPos_after_p2[nbins];
   double parNeg_after_p2[nbins];
   double parNom_after_p2[nbins];
   double parStat_after_p2[nbins];
   double parupTot_after_p2[nbins];
   double pardownTot_after_p2[nbins];
   
   double parPos_after_p3[nbins];
   double parNeg_after_p3[nbins];
   double parNom_after_p3[nbins];
   double parStat_after_p3[nbins];
   double parupTot_after_p3[nbins];
   double pardownTot_after_p3[nbins];
 
   // SF
   for(int j=1;j<=nbins;j++)
     {	     
	sfNom[j-1] = sf_nom->GetBinContent(j);

	sfupTot[j-1] = 0.;
	sfdownTot[j-1] = 0.;

	sfnomTable[j-1] = sfNom[j-1];
	
	for(int i=0;i<nsys;i++)
	  {
	     if( sidx >= 0 && sidx != i ) continue;
	     
	     double deltaMax = 0.;
	     double deltaMin = 0.;
	     sfPos[j-1] = hsfPos[i]->GetBinContent(j);
	     sfNeg[j-1] = hsfNeg[i]->GetBinContent(j);
	     double deltaMax = sfPos[j-1] - sfNom[j-1];
	     double deltaMin = sfNom[j-1] - sfNeg[j-1];
	     if( symSyst )
	       {		  
		  double max = (fabs(deltaMax) > fabs(deltaMin)) ? deltaMax : deltaMin;
		  deltaMax = max;
		  deltaMin = max;

		  sfupTot[j-1] += pow(deltaMax,2);
		  sfdownTot[j-1] += pow(deltaMin,2);		  
	       }
	     else
	       {		  
 		  if( deltaMin < 0 && deltaMax > 0 && fabs(deltaMin) > deltaMax )
		    {		  
		       deltaMax = fabs(deltaMin);
		       deltaMin = 0.;
		    }	     
		  if( deltaMax < 0 && deltaMin > 0 && fabs(deltaMax) > deltaMin )
		    {
		       deltaMin = fabs(deltaMax);
		       deltaMax = 0.;
		    }
		  if( deltaMax < 0 && deltaMin < 0 )
		    {		  
		       sfupTot[j-1] += pow(deltaMin,2);
		       sfdownTot[j-1] += pow(deltaMax,2);		       		       
		       
		       sfsystupTable[j-1] += pow(deltaMin,2);
		       sfsystdownTable[j-1] += pow(deltaMax,2);
		       
		       sfupTable[j-1][i] = fabs(deltaMin);
		       sfdownTable[j-1][i] = fabs(deltaMax);
		    }
		  else
		    {
		       sfupTot[j-1] += pow(deltaMax,2);
		       sfdownTot[j-1] += pow(deltaMin,2);

		       sfsystupTable[j-1] += pow(deltaMax,2);
		       sfsystdownTable[j-1] += pow(deltaMin,2);
		       
		       sfupTable[j-1][i] = fabs(deltaMax);
		       sfdownTable[j-1][i] = fabs(deltaMin);
		    }	     
	       }
	  }	
   
	if( sidx == 667 || sidx < 0 )
	  {
	     double cbsys = (1-cb_nosel[j-1])*0.5/cb_nosel[j-1];
	     sfupTot[j-1] += pow(cbsys*sfNom[j-1],2);
	     sfdownTot[j-1] += pow(cbsys*sfNom[j-1],2);
	     
	     sfupTable[j-1][nsys] = cbsys*sfNom[j-1];
	     sfdownTable[j-1][nsys] = cbsys*sfNom[j-1];

	     sfsystupTable[j-1] += pow(cbsys*sfNom[j-1],2);
	     sfsystdownTable[j-1] += pow(cbsys*sfNom[j-1],2);
	  }
	
	sfsystupTable[j-1] = sqrt(sfsystupTable[j-1]);
	sfsystdownTable[j-1] = sqrt(sfsystdownTable[j-1]);
	
	double statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     double sfcur = hsfStat[i]->GetBinContent(j);
	     statSum += sfcur;
	     if( j == 14 ) sf_dist->Fill(sfcur,1.);
	  }	
	double sfAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(sfAv - hsfStat[i]->GetBinContent(j),2)/double(nstat);
	  }	
	sfStat[j-1] = sqrt(statSum);
	
	sfstatTable[j-1] = sfStat[j-1];
	
	if( sidx < 0 )
	  {	     
	     if( showOnlyStat )
	       {
		  sfupTot[j-1] = sfStat[j-1];
		  sfdownTot[j-1] = sfStat[j-1];
	       }
	     else if( !showOnlySys )
	       {	     
		  sfupTot[j-1] = sqrt(sfupTot[j-1]+pow(sfStat[j-1],2));
		  sfdownTot[j-1] = sqrt(sfdownTot[j-1]+pow(sfStat[j-1],2));
	       }	
	  }
	if( sidx == 667 )
	  {	     
	     sfupTot[j-1] = sqrt(sfupTot[j-1]);
	     sfdownTot[j-1] = sqrt(sfdownTot[j-1]);
	  }
     }
	
   makeTable(nbins,nsys,sfnomTable,sfupTable,sfdownTable,sfstatTable,sfsystupTable,sfsystdownTable);
   
   int nsfp = nbins*2+1;
   const int np = nsfp;
   
   double xp_sysTot[np];
   double yp_sysTot[np];
   for(int k=0;k<nbins;k++)
     {
	xp_sysTot[k] = sf_nom->GetBinWidth(k+1)/2.0 + sf_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot[k] = sfNom[k]+sfupTot[k];
	yp_sysTot[nbins+k] = sfNom[nbins-1-k]-sfdownTot[nbins-1-k];	
     }   

   for(int k=0;k<nbins;k++)
     {
	xp_sysTot[nbins+k] = xp_sysTot[nbins-k-1];
     }
   
   xp_sysTot[np-1] = xp_sysTot[0];
   yp_sysTot[np-1] = yp_sysTot[0];

   TH1D *hsfNomInit = (TH1D*)hsfNom->Clone("hsfNomInit");
   
   for(int i=1;i<=nbins;i++)
     {
	hsfNom->SetBinError(i,sfStat[i-1]);
     }

   
   
   if( add )
     {	
	// SF add
	for(int j=1;j<=nbins;j++)
	  {	     
	     sfNom_add[j-1] = sf_nom_add->GetBinContent(j);
	     
	     sfupTot_add[j-1] = 0.;
	     sfdownTot_add[j-1] = 0.;
	     
	     for(int i=0;i<nsys;i++)
	       {
		  if( sidx >= 0 && sidx != i ) continue;
		  
		  double deltaMax = 0.;
		  double deltaMin = 0.;
		  sfPos_add[j-1] = hsfPos_add[i]->GetBinContent(j);
		  sfNeg_add[j-1] = hsfNeg_add[i]->GetBinContent(j);
		  double deltaMax = sfPos_add[j-1] - sfNom_add[j-1];
		  double deltaMin = sfNom_add[j-1] - sfNeg_add[j-1];
		  
		  if( deltaMin < 0 && deltaMax > 0 && fabs(deltaMin) > deltaMax )
		    {		  
		       deltaMax = fabs(deltaMin);
		       deltaMin = 0.;
		    }	     
		  if( deltaMax < 0 && deltaMin > 0 && fabs(deltaMax) > deltaMin )
		    {
		       deltaMin = fabs(deltaMax);
		       deltaMax = 0.;
		    }
		  if( deltaMax < 0 && deltaMin < 0 )
		    {		  
		       sfupTot_add[j-1] += pow(deltaMin,2);
		       sfdownTot_add[j-1] += pow(deltaMax,2);		       		       
		    }
		  else
		    {
		       sfupTot_add[j-1] += pow(deltaMax,2);
		       sfdownTot_add[j-1] += pow(deltaMin,2);
		    }
	       }	
	     
	     if( sidx == 667 || sidx < 0 )
	       {
		  double cbsys = (1-cb_nosel[j-1])*0.5/cb_nosel[j-1];
		  sfupTot_add[j-1] += pow(cbsys*sfNom_add[j-1],2);
		  sfdownTot_add[j-1] += pow(cbsys*sfNom_add[j-1],2);
	       }
	     
	     double statSum = 0.;
	     for(int i=0;i<nstat;i++)
	       {
		  double sfcur = hsfStat_add[i]->GetBinContent(j);
		  statSum += sfcur;
	       }	
	     double sfAv = statSum/double(nstat);
	     
	     statSum = 0.;
	     for(int i=0;i<nstat;i++)
	       {
		  statSum += pow(sfAv - hsfStat_add[i]->GetBinContent(j),2)/double(nstat);
	       }	
	     sfStat_add[j-1] = sqrt(statSum);
	     
	     if( sidx < 0 )
	       {	     
		  if( showOnlyStat )
		    {
		       sfupTot_add[j-1] = sfStat_add[j-1];
		       sfdownTot_add[j-1] = sfStat_add[j-1];
		    }
		  else if( !showOnlySys )
		    {	     
		       sfupTot_add[j-1] = sqrt(sfupTot_add[j-1]+pow(sfStat_add[j-1],2));
		       sfdownTot_add[j-1] = sqrt(sfdownTot_add[j-1]+pow(sfStat_add[j-1],2));
		    }	
	       }
	     if( sidx == 667 )
	       {	     
		  sfupTot_add[j-1] = sqrt(sfupTot_add[j-1]);
		  sfdownTot_add[j-1] = sqrt(sfdownTot_add[j-1]);
	       }
	  }      
     }   


   double xp_sysTot_add[np];
   double yp_sysTot_add[np];
   if( add )
     {	
	for(int k=0;k<nbins;k++)
	  {
	     xp_sysTot_add[k] = sf_nom_add->GetBinWidth(k+1)/2.0 + sf_nom_add->GetXaxis()->GetBinLowEdge(k+1);
	     yp_sysTot_add[k] = sfNom_add[k]+sfupTot_add[k];
	     yp_sysTot_add[nbins+k] = sfNom_add[nbins-1-k]-sfdownTot_add[nbins-1-k];
	  }   
	
	for(int k=0;k<nbins;k++)
	  {
	     xp_sysTot_add[nbins+k] = xp_sysTot_add[nbins-k-1];
	  }
	
	xp_sysTot_add[np-1] = xp_sysTot_add[0];
	yp_sysTot_add[np-1] = yp_sysTot_add[0];
     }   

   TH1D *hsfNomInit_add = (TH1D*)hsfNom_add->Clone("hsfNomInit_add");
   
   for(int i=1;i<=nbins;i++)
     {
	hsfNom_add->SetBinError(i,sfStat_add[i-1]);
     }
   
   
   double effMC_nom_err[nbins];
   
   // correct eff MC
   for(int j=1;j<=nbins;j++)
     {
	double v_effMC_nom = effMC_nom->GetBinContent(j);
	double v_effMC_nom_err = effMC_nom->GetBinError(j);
	effMC_nom_err[j-1] = v_effMC_nom_err;
	
	effMC_nom->SetBinContent(j,v_effMC_nom*cb_nosel[j-1]);
//	double v_effMC_nom_err_cb = v_effMC_nom*cb_nosel[j-1]*
//	  sqrt(pow(cberr_nosel[j-1]/cb_nosel[j-1],2)+pow(v_effMC_nom_err/v_effMC_nom,2));
	double v_effMC_nom_err_cb = v_effMC_nom*cb_nosel[j-1]*
	  sqrt(pow(v_effMC_nom_err/v_effMC_nom,2));
	effMC_nom->SetBinError(j,v_effMC_nom_err_cb);
	
	heffMCNom->SetBinContent(j,v_effMC_nom*cb_nosel[j-1]);
	heffMCNom->SetBinError(j,v_effMC_nom_err_cb);
	
	for(int is=0;is<nsys;is++)
	  {	     
	     double v_effMCPos = heffMCPos[is]->GetBinContent(j);
	     double v_effMCPos_err = heffMCPos[is]->GetBinError(j);
	     heffMCPos[is]->SetBinContent(j,v_effMCPos*cb_nosel[j-1]);
//	     double v_effMCPos_err_cb = v_effMCPos*cb_nosel[j-1]*
//	       sqrt(pow(cberr_nosel[j-1]/cb_nosel[j-1],2)+pow(v_effMCPos_err/v_effMCPos,2));
	     double v_effMCPos_err_cb = v_effMCPos*cb_nosel[j-1]*
	       sqrt(pow(v_effMCPos_err/v_effMCPos,2));
	     heffMCPos[is]->SetBinError(j,v_effMCPos_err_cb);

	     double v_effMCNeg = heffMCNeg[is]->GetBinContent(j);
	     double v_effMCNeg_err = heffMCNeg[is]->GetBinError(j);
	     heffMCNeg[is]->SetBinContent(j,v_effMCNeg*cb_nosel[j-1]);
//	     double v_effMCNeg_err_cb = v_effMCNeg*cb_nosel[j-1]*
//	       sqrt(pow(cberr_nosel[j-1]/cb_nosel[j-1],2)+pow(v_effMCNeg_err/v_effMCNeg,2));
	     double v_effMCNeg_err_cb = v_effMCNeg*cb_nosel[j-1]*
	       sqrt(pow(v_effMCNeg_err/v_effMCNeg,2));
	     heffMCNeg[is]->SetBinError(j,v_effMCNeg_err_cb);
	  }
	for(int is=0;is<nstat;is++)
	  {	     
	     double v_effMCStat = heffMCStat[is]->GetBinContent(j);
	     double v_effMCStat_err = heffMCStat[is]->GetBinError(j);
	     heffMCStat[is]->SetBinContent(j,v_effMCStat*cb_nosel[j-1]);
//	     double v_effMCStat_err_cb = v_effMCStat*cb_nosel[j-1]*
//	       sqrt(pow(cberr_nosel[j-1]/cb_nosel[j-1],2)+pow(v_effMCStat_err/v_effMCStat,2));
	     double v_effMCStat_err_cb = v_effMCStat*cb_nosel[j-1]*
	       sqrt(pow(v_effMCStat_err/v_effMCStat,2));
	     heffMCStat[is]->SetBinError(j,v_effMCStat_err_cb);
	  }	
     }

   // correct eff DATA
   
   double effDATA_nom_err[nbins];
   
   for(int j=1;j<=nbins;j++)
     {
	double v_effDATA_nom = effDATA_nom->GetBinContent(j);
	double v_effDATA_nom_err = effDATA_nom->GetBinError(j);
	effDATA_nom_err[j-1] = v_effDATA_nom_err;
	
	effDATA_nom->SetBinContent(j,v_effDATA_nom*cb_nosel[j-1]);
//	double v_effDATA_nom_err_cb = v_effDATA_nom*cb_nosel[j-1]*
//	  sqrt(pow(cberr_nosel[j-1]/cb_nosel[j-1],2)+pow(v_effDATA_nom_err/v_effDATA_nom,2));
	double v_effDATA_nom_err_cb = v_effDATA_nom*cb_nosel[j-1]*
	  sqrt(pow(v_effDATA_nom_err/v_effDATA_nom,2));
	effDATA_nom->SetBinError(j,v_effDATA_nom_err_cb);
	
	heffDATANom->SetBinContent(j,v_effDATA_nom*cb_nosel[j-1]);
	heffDATANom->SetBinError(j,v_effDATA_nom_err_cb);
	
	for(int is=0;is<nsys;is++)
	  {	     
	     double v_effDATAPos = heffDATAPos[is]->GetBinContent(j);
	     double v_effDATAPos_err = heffDATAPos[is]->GetBinError(j);
	     heffDATAPos[is]->SetBinContent(j,v_effDATAPos*cb_nosel[j-1]);
//	     double v_effDATAPos_err_cb = v_effDATAPos*cb_nosel[j-1]*
//	       sqrt(pow(cberr_nosel[j-1]/cb_nosel[j-1],2)+pow(v_effDATAPos_err/v_effDATAPos,2));
	     double v_effDATAPos_err_cb = v_effDATAPos*cb_nosel[j-1]*
	       sqrt(pow(v_effDATAPos_err/v_effDATAPos,2));
	     heffDATAPos[is]->SetBinError(j,v_effDATAPos_err_cb);

	     double v_effDATANeg = heffDATANeg[is]->GetBinContent(j);
	     double v_effDATANeg_err = heffDATANeg[is]->GetBinError(j);
	     heffDATANeg[is]->SetBinContent(j,v_effDATANeg*cb_nosel[j-1]);
//	     double v_effDATANeg_err_cb = v_effDATANeg*cb_nosel[j-1]*
//	       sqrt(pow(cberr_nosel[j-1]/cb_nosel[j-1],2)+pow(v_effDATANeg_err/v_effDATANeg,2));
	     double v_effDATANeg_err_cb = v_effDATANeg*cb_nosel[j-1]*
	       sqrt(pow(v_effDATANeg_err/v_effDATANeg,2));
	     heffDATANeg[is]->SetBinError(j,v_effDATANeg_err_cb);
	  }
	for(int is=0;is<nstat;is++)
	  {	     
	     double v_effDATAStat = heffDATAStat[is]->GetBinContent(j);
	     double v_effDATAStat_err = heffDATAStat[is]->GetBinError(j);
	     heffDATAStat[is]->SetBinContent(j,v_effDATAStat*cb_nosel[j-1]);
//	     double v_effDATAStat_err_cb = v_effDATAStat*cb_nosel[j-1]*
//	       sqrt(pow(cberr_nosel[j-1]/cb_nosel[j-1],2)+pow(v_effDATAStat_err/v_effDATAStat,2));
	     double v_effDATAStat_err_cb = v_effDATAStat*cb_nosel[j-1]*
	       sqrt(pow(v_effDATAStat_err/v_effDATAStat,2));
	     heffDATAStat[is]->SetBinError(j,v_effDATAStat_err_cb);
	  }	
     }
   
   // eff MC   
   for(int j=1;j<=nbins;j++)
     {	     
	effMCNom[j-1] = effMC_nom->GetBinContent(j);

	effMCupTot[j-1] = 0.;
	effMCdownTot[j-1] = 0.;

	for(int i=0;i<nsys;i++)
	  {
	     if( sidx >= 0 && sidx != i ) continue;
	     
	     double deltaMax = 0.;
	     double deltaMin = 0.;
	     effMCPos[j-1] = heffMCPos[i]->GetBinContent(j);
	     effMCNeg[j-1] = heffMCNeg[i]->GetBinContent(j);
	     double deltaMax = effMCPos[j-1] - effMCNom[j-1];
	     double deltaMin = effMCNom[j-1] - effMCNeg[j-1];
	     if( symSyst )
	       {		  
		  double max = (fabs(deltaMax) > fabs(deltaMin)) ? deltaMax : deltaMin;
		  deltaMax = max;
		  deltaMin = max;

		  effMCupTot[j-1] += pow(deltaMax,2);
		  effMCdownTot[j-1] += pow(deltaMin,2);		  
	       }
	     else
	       {		  
		  if( deltaMin < 0 && deltaMax > 0 && fabs(deltaMin) > deltaMax )
		    {		  
		       deltaMax = deltaMin;
		       deltaMin = 0.;
		    }	     
		  if( deltaMax < 0 && deltaMin > 0 && fabs(deltaMax) > deltaMin )
		    {		  
		       deltaMin = deltaMax;
		       deltaMax = 0.;
		    }
		  if( deltaMax < 0 && deltaMin < 0 )
		    {		  
		       effMCupTot[j-1] += pow(deltaMin,2);
		       effMCdownTot[j-1] += pow(deltaMax,2);
		    }
		  else
		    {
		       effMCupTot[j-1] += pow(deltaMax,2);
		       effMCdownTot[j-1] += pow(deltaMin,2);
		    }	     
	       }
	  }	
   
	if( sidx == 667 || sidx < 0 )
	  {
	     double cbsys = (1-cb_nosel[j-1])*0.5/cb_nosel[j-1];
//	     effMCupTot[j-1] += pow(cbsys*effMCNom[j-1],2);
//	     effMCdownTot[j-1] += pow(cbsys*effMCNom[j-1],2);
	  }
	
	double statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     double sfcur = heffMCStat[i]->GetBinContent(j);
	     statSum += sfcur;
	  }	
	double sfAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(sfAv - heffMCStat[i]->GetBinContent(j),2)/double(nstat);
	  }	
	effMCStat[j-1] = sqrt(statSum);
	
	if( sidx < 0 )
	  {	     
	     if( showOnlyStat )
	       {
		  effMCupTot[j-1] = effMCStat[j-1];
		  effMCdownTot[j-1] = effMCStat[j-1];
	       }
	     else if( !showOnlySys )
	       {	     
		  effMCupTot[j-1] = sqrt(effMCupTot[j-1]+pow(effMCStat[j-1],2));
		  effMCdownTot[j-1] = sqrt(effMCdownTot[j-1]+pow(effMCStat[j-1],2));
	       }	
	  }
	if( sidx == 667 )
	  {	     
	     effMCupTot[j-1] = sqrt(effMCupTot[j-1]);
	     effMCdownTot[j-1] = sqrt(effMCdownTot[j-1]);
	  }
     }   

   double xp_sysTot_effMC[np];
   double yp_sysTot_effMC[np];
   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_effMC[k] = effMC_nom->GetBinWidth(k+1)/2.0 + effMC_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_effMC[k] = effMCNom[k]+effMCupTot[k];
	yp_sysTot_effMC[nbins+k] = effMCNom[nbins-1-k]-effMCdownTot[nbins-1-k];
     }   

   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_effMC[nbins+k] = xp_sysTot_effMC[nbins-k-1];
     }
   
   xp_sysTot_effMC[np-1] = xp_sysTot_effMC[0];
   yp_sysTot_effMC[np-1] = yp_sysTot_effMC[0];

   TH1D *heffMCNomInit = (TH1D*)heffMCNom->Clone("heffMCNomInit");
   
//   for(int i=1;i<=nbins;i++)
//     {
//	heffMCNom->SetBinError(i,effMCStat[i-1]);
//     }
   
   // eff DATA
   for(int j=1;j<=nbins;j++)
     {	     
	effDATANom[j-1] = effDATA_nom->GetBinContent(j);

	effDATAupTot[j-1] = 0.;
	effDATAdownTot[j-1] = 0.;

	for(int i=0;i<nsys;i++)
	  {
	     if( sidx >= 0 && sidx != i ) continue;
	     
	     double deltaMax = 0.;
	     double deltaMin = 0.;
	     effDATAPos[j-1] = heffDATAPos[i]->GetBinContent(j);
	     effDATANeg[j-1] = heffDATANeg[i]->GetBinContent(j);
	     double deltaMax = effDATAPos[j-1] - effDATANom[j-1];
	     double deltaMin = effDATANom[j-1] - effDATANeg[j-1];
	     if( symSyst )
	       {		  
		  double max = (fabs(deltaMax) > fabs(deltaMin)) ? deltaMax : deltaMin;
		  deltaMax = max;
		  deltaMin = max;

		  effDATAupTot[j-1] += pow(deltaMax,2);
		  effDATAdownTot[j-1] += pow(deltaMin,2);		  
	       }
	     else
	       {		  
		  if( deltaMin < 0 && deltaMax > 0 && fabs(deltaMin) > deltaMax )
		    {		  
		       deltaMax = deltaMin;
		       deltaMin = 0.;
		    }	     
		  if( deltaMax < 0 && deltaMin > 0 && fabs(deltaMax) > deltaMin )
		    {		  
		       deltaMin = deltaMax;
		       deltaMax = 0.;
		    }
		  if( deltaMax < 0 && deltaMin < 0 )
		    {		  
		       effDATAupTot[j-1] += pow(deltaMin,2);
		       effDATAdownTot[j-1] += pow(deltaMax,2);
		    }
		  else
		    {
		       effDATAupTot[j-1] += pow(deltaMax,2);
		       effDATAdownTot[j-1] += pow(deltaMin,2);
		    }	     
	       }
	  }	
   
	if( sidx == 667 || sidx < 0 )
	  {
	     double cbsys = (1-cb_nosel[j-1])*0.5/cb_nosel[j-1];
//	     effDATAupTot[j-1] += pow(cbsys*effDATANom[j-1],2);
//	     effDATAdownTot[j-1] += pow(cbsys*effDATANom[j-1],2);
	  }
	
	double statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     double sfcur = heffDATAStat[i]->GetBinContent(j);
	     statSum += sfcur;
	  }	
	double sfAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(sfAv - heffDATAStat[i]->GetBinContent(j),2)/double(nstat);
	  }	
	effDATAStat[j-1] = sqrt(statSum);
	
	if( sidx < 0 )
	  {	     
	     if( showOnlyStat )
	       {
		  effDATAupTot[j-1] = effDATAStat[j-1];
		  effDATAdownTot[j-1] = effDATAStat[j-1];
	       }
	     else if( !showOnlySys )
	       {	     
		  effDATAupTot[j-1] = sqrt(effDATAupTot[j-1]+pow(effDATAStat[j-1],2));
		  effDATAdownTot[j-1] = sqrt(effDATAdownTot[j-1]+pow(effDATAStat[j-1],2));
	       }	
	  }
	if( sidx == 667 )
	  {	     
	     effDATAupTot[j-1] = sqrt(effDATAupTot[j-1]);
	     effDATAdownTot[j-1] = sqrt(effDATAdownTot[j-1]);
	  }
     }   
	
   double xp_sysTot_effDATA[np];
   double yp_sysTot_effDATA[np];
   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_effDATA[k] = effDATA_nom->GetBinWidth(k+1)/2.0 + effDATA_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_effDATA[k] = effDATANom[k]+effDATAupTot[k];
	yp_sysTot_effDATA[nbins+k] = effDATANom[nbins-1-k]-effDATAdownTot[nbins-1-k];
     }   

   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_effDATA[nbins+k] = xp_sysTot_effDATA[nbins-k-1];
     }
   
   xp_sysTot_effDATA[np-1] = xp_sysTot_effDATA[0];
   yp_sysTot_effDATA[np-1] = yp_sysTot_effDATA[0];

   TH1D *heffDATANomInit = (TH1D*)heffDATANom->Clone("heffDATANomInit");
   
   for(int i=1;i<=nbins;i++)
     {
	heffDATANom->SetBinError(i,effDATAStat[i-1]);
     }
   
   // p1 before
   for(int j=1;j<=nbins;j++)
     {	     
	parNom_before_p1[j-1] = p1_before_nom->GetBinContent(j);

	parupTot_before_p1[j-1] = 0.;
	pardownTot_before_p1[j-1] = 0.;
	
	for(int i=0;i<nsys;i++)
	  {
	     double deltaMax = 0.;
	     double deltaMin = 0.;
	     parPos_before_p1[j-1] = hparPos_before_p1[i]->GetBinContent(j);
	     parNeg_before_p1[j-1] = hparNeg_before_p1[i]->GetBinContent(j);
	     double deltaMax = parPos_before_p1[j-1] - parNom_before_p1[j-1];
	     double deltaMin = parNom_before_p1[j-1] - parNeg_before_p1[j-1];
	     if( symSyst )
	       {		  
		  double max = (fabs(deltaMax) > fabs(deltaMin)) ? deltaMax : deltaMin;
		  deltaMax = max;
		  deltaMin = max;

		  parupTot_before_p1[j-1] += pow(deltaMax,2);
		  pardownTot_before_p1[j-1] += pow(deltaMin,2);		  
	       }
	     else
	       {		  
		  if( deltaMin < 0 && deltaMax > 0 && fabs(deltaMin) > deltaMax )
		    {		  
		       deltaMax = deltaMin;
		       deltaMin = 0.;
		    }	     
		  if( deltaMax < 0 && deltaMin > 0 && fabs(deltaMax) > deltaMin )
		    {		  
		       deltaMin = deltaMax;
		       deltaMax = 0.;
		    }
		  if( deltaMax < 0 && deltaMin < 0 )
		    {		  
		       parupTot_before_p1[j-1] += pow(deltaMin,2);
		       pardownTot_before_p1[j-1] += pow(deltaMax,2);
		    }
		  else
		    {
		       parupTot_before_p1[j-1] += pow(deltaMax,2);
		       pardownTot_before_p1[j-1] += pow(deltaMin,2);		  
		    }	     
	       }	     
	  }
	
	double statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     double parcur = hparStat_before_p1[i]->GetBinContent(j);
	     statSum += parcur;
	     if( j == 14 ) p1_dist->Fill(parcur,1.);
	  }	
	double parAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(parAv - hparStat_before_p1[i]->GetBinContent(j),2)/double(nstat);
	  }	
	parStat_before_p1[j-1] = sqrt(statSum);

	if( showOnlyStat )
	  {
	     parupTot_before_p1[j-1] = parStat_before_p1[j-1];
	     pardownTot_before_p1[j-1] = parStat_before_p1[j-1];
	  }
	else if( !showOnlySys )
	  {	     
	     parupTot_before_p1[j-1] = sqrt(parupTot_before_p1[j-1]+pow(parStat_before_p1[j-1],2));
	     pardownTot_before_p1[j-1] = sqrt(pardownTot_before_p1[j-1]+pow(parStat_before_p1[j-1],2));
	  }	
     }   
	
   double xp_sysTot_before_p1[np];
   double yp_sysTot_before_p1[np];
   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_before_p1[k] = p1_before_nom->GetBinWidth(k+1)/2.0 + p1_before_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_before_p1[k] = parNom_before_p1[k]+parupTot_before_p1[k];
	yp_sysTot_before_p1[nbins+k] = parNom_before_p1[nbins-1-k]-pardownTot_before_p1[nbins-1-k];
     }   

   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_before_p1[nbins+k] = xp_sysTot_before_p1[nbins-k-1];
     }
   
   xp_sysTot_before_p1[np-1] = xp_sysTot_before_p1[0];
   yp_sysTot_before_p1[np-1] = yp_sysTot_before_p1[0];

   TH1D *hparNomInit_before_p1 = (TH1D*)hparNom_before_p1->Clone("hparNomInit_before_p1");
   
   for(int i=1;i<=nbins;i++)
     {
	hparNom_before_p1->SetBinError(i,parStat_before_p1[i-1]);
     }

   // p1 after
   for(int j=1;j<=nbins;j++)
     {	     
	parNom_after_p1[j-1] = p1_after_nom->GetBinContent(j);

	parupTot_after_p1[j-1] = 0.;
	pardownTot_after_p1[j-1] = 0.;
	
	for(int i=0;i<nsys;i++)
	  {
	     double deltaMax = 0.;
	     double deltaMin = 0.;
	     parPos_after_p1[j-1] = hparPos_after_p1[i]->GetBinContent(j);
	     parNeg_after_p1[j-1] = hparNeg_after_p1[i]->GetBinContent(j);
	     double deltaMax = parPos_after_p1[j-1] - parNom_after_p1[j-1];
	     double deltaMin = parNom_after_p1[j-1] - parNeg_after_p1[j-1];
	     if( symSyst )
	       {		  
		  double max = (fabs(deltaMax) > fabs(deltaMin)) ? deltaMax : deltaMin;
		  deltaMax = max;
		  deltaMin = max;

		  parupTot_after_p1[j-1] += pow(deltaMax,2);
		  pardownTot_after_p1[j-1] += pow(deltaMin,2);		  
	       }
	     else
	       {		  
		  if( deltaMin < 0 && deltaMax > 0 && fabs(deltaMin) > deltaMax )
		    {		  
		       deltaMax = deltaMin;
		       deltaMin = 0.;
		    }	     
		  if( deltaMax < 0 && deltaMin > 0 && fabs(deltaMax) > deltaMin )
		    {		  
		       deltaMin = deltaMax;
		       deltaMax = 0.;
		    }
		  if( deltaMax < 0 && deltaMin < 0 )
		    {		  
		       parupTot_after_p1[j-1] += pow(deltaMin,2);
		       pardownTot_after_p1[j-1] += pow(deltaMax,2);
		    }
		  else
		    {
		       parupTot_after_p1[j-1] += pow(deltaMax,2);
		       pardownTot_after_p1[j-1] += pow(deltaMin,2);		  
		    }	     
	       }	     
	  }
	
	double statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     double parcur = hparStat_after_p1[i]->GetBinContent(j);
	     statSum += parcur;
	     if( j == 14 ) p1_dist->Fill(parcur,1.);
	  }	
	double parAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(parAv - hparStat_after_p1[i]->GetBinContent(j),2)/double(nstat);
	  }	
	parStat_after_p1[j-1] = sqrt(statSum);

	if( showOnlyStat )
	  {
	     parupTot_after_p1[j-1] = parStat_after_p1[j-1];
	     pardownTot_after_p1[j-1] = parStat_after_p1[j-1];
	  }
	else if( !showOnlySys )
	  {	     
	     parupTot_after_p1[j-1] = sqrt(parupTot_after_p1[j-1]+pow(parStat_after_p1[j-1],2));
	     pardownTot_after_p1[j-1] = sqrt(pardownTot_after_p1[j-1]+pow(parStat_after_p1[j-1],2));
	  }	
     }   
	
   double xp_sysTot_after_p1[np];
   double yp_sysTot_after_p1[np];
   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_after_p1[k] = p1_after_nom->GetBinWidth(k+1)/2.0 + p1_after_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_after_p1[k] = parNom_after_p1[k]+parupTot_after_p1[k];
	yp_sysTot_after_p1[nbins+k] = parNom_after_p1[nbins-1-k]-pardownTot_after_p1[nbins-1-k];
     }   

   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_after_p1[nbins+k] = xp_sysTot_after_p1[nbins-k-1];
     }
   
   xp_sysTot_after_p1[np-1] = xp_sysTot_after_p1[0];
   yp_sysTot_after_p1[np-1] = yp_sysTot_after_p1[0];

   TH1D *hparNomInit_after_p1 = (TH1D*)hparNom_after_p1->Clone("hparNomInit_after_p1");
   
   for(int i=1;i<=nbins;i++)
     {
	hparNom_after_p1->SetBinError(i,parStat_after_p1[i-1]);
     }

   // p2 before
   for(int j=1;j<=nbins;j++)
     {	     
	parNom_before_p2[j-1] = p2_before_nom->GetBinContent(j);

	parupTot_before_p2[j-1] = 0.;
	pardownTot_before_p2[j-1] = 0.;
	
	for(int i=0;i<nsys;i++)
	  {
	     double deltaMax = 0.;
	     double deltaMin = 0.;
	     parPos_before_p2[j-1] = hparPos_before_p2[i]->GetBinContent(j);
	     parNeg_before_p2[j-1] = hparNeg_before_p2[i]->GetBinContent(j);
	     double deltaMax = parPos_before_p2[j-1] - parNom_before_p2[j-1];
	     double deltaMin = parNom_before_p2[j-1] - parNeg_before_p2[j-1];
	     if( symSyst )
	       {		  
		  double max = (fabs(deltaMax) > fabs(deltaMin)) ? deltaMax : deltaMin;
		  deltaMax = max;
		  deltaMin = max;

		  parupTot_before_p2[j-1] += pow(deltaMax,2);
		  pardownTot_before_p2[j-1] += pow(deltaMin,2);		  
	       }
	     else
	       {		  
		  if( deltaMin < 0 && deltaMax > 0 && fabs(deltaMin) > deltaMax )
		    {		  
		       deltaMax = deltaMin;
		       deltaMin = 0.;
		    }	     
		  if( deltaMax < 0 && deltaMin > 0 && fabs(deltaMax) > deltaMin )
		    {		  
		       deltaMin = deltaMax;
		       deltaMax = 0.;
		    }
		  if( deltaMax < 0 && deltaMin < 0 )
		    {		  
		       parupTot_before_p2[j-1] += pow(deltaMin,2);
		       pardownTot_before_p2[j-1] += pow(deltaMax,2);
		    }
		  else
		    {
		       parupTot_before_p2[j-1] += pow(deltaMax,2);
		       pardownTot_before_p2[j-1] += pow(deltaMin,2);		  
		    }	     
	       }	     
	  }
	
	double statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     double parcur = hparStat_before_p2[i]->GetBinContent(j);
	     statSum += parcur;
	     if( j == 14 ) p2_dist->Fill(parcur,1.);
	  }	
	double parAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(parAv - hparStat_before_p2[i]->GetBinContent(j),2)/double(nstat);
	  }	
	parStat_before_p2[j-1] = sqrt(statSum);

	if( showOnlyStat )
	  {
	     parupTot_before_p2[j-1] = parStat_before_p2[j-1];
	     pardownTot_before_p2[j-1] = parStat_before_p2[j-1];
	  }
	else if( !showOnlySys )
	  {	     
	     parupTot_before_p2[j-1] = sqrt(parupTot_before_p2[j-1]+pow(parStat_before_p2[j-1],2));
	     pardownTot_before_p2[j-1] = sqrt(pardownTot_before_p2[j-1]+pow(parStat_before_p2[j-1],2));
	  }	
     }   
	
   double xp_sysTot_before_p2[np];
   double yp_sysTot_before_p2[np];
   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_before_p2[k] = p2_before_nom->GetBinWidth(k+1)/2.0 + p2_before_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_before_p2[k] = parNom_before_p2[k]+parupTot_before_p2[k];
	yp_sysTot_before_p2[nbins+k] = parNom_before_p2[nbins-1-k]-pardownTot_before_p2[nbins-1-k];
     }   

   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_before_p2[nbins+k] = xp_sysTot_before_p2[nbins-k-1];
     }
   
   xp_sysTot_before_p2[np-1] = xp_sysTot_before_p2[0];
   yp_sysTot_before_p2[np-1] = yp_sysTot_before_p2[0];

   TH1D *hparNomInit_before_p2 = (TH1D*)hparNom_before_p2->Clone("hparNomInit_before_p2");
   
   for(int i=1;i<=nbins;i++)
     {
	hparNom_before_p2->SetBinError(i,parStat_before_p2[i-1]);
     }

   // p2 after
   for(int j=1;j<=nbins;j++)
     {	     
	parNom_after_p2[j-1] = p2_after_nom->GetBinContent(j);

	parupTot_after_p2[j-1] = 0.;
	pardownTot_after_p2[j-1] = 0.;
	
	for(int i=0;i<nsys;i++)
	  {
	     double deltaMax = 0.;
	     double deltaMin = 0.;
	     parPos_after_p2[j-1] = hparPos_after_p2[i]->GetBinContent(j);
	     parNeg_after_p2[j-1] = hparNeg_after_p2[i]->GetBinContent(j);
	     double deltaMax = parPos_after_p2[j-1] - parNom_after_p2[j-1];
	     double deltaMin = parNom_after_p2[j-1] - parNeg_after_p2[j-1];
	     if( symSyst )
	       {		  
		  double max = (fabs(deltaMax) > fabs(deltaMin)) ? deltaMax : deltaMin;
		  deltaMax = max;
		  deltaMin = max;

		  parupTot_after_p2[j-1] += pow(deltaMax,2);
		  pardownTot_after_p2[j-1] += pow(deltaMin,2);		  
	       }
	     else
	       {		  
		  if( deltaMin < 0 && deltaMax > 0 && fabs(deltaMin) > deltaMax )
		    {		  
		       deltaMax = deltaMin;
		       deltaMin = 0.;
		    }	     
		  if( deltaMax < 0 && deltaMin > 0 && fabs(deltaMax) > deltaMin )
		    {		  
		       deltaMin = deltaMax;
		       deltaMax = 0.;
		    }
		  if( deltaMax < 0 && deltaMin < 0 )
		    {		  
		       parupTot_after_p2[j-1] += pow(deltaMin,2);
		       pardownTot_after_p2[j-1] += pow(deltaMax,2);
		    }
		  else
		    {
		       parupTot_after_p2[j-1] += pow(deltaMax,2);
		       pardownTot_after_p2[j-1] += pow(deltaMin,2);		  
		    }	     
	       }	     
	  }
	
	double statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     double parcur = hparStat_after_p2[i]->GetBinContent(j);
	     statSum += parcur;
	     if( j == 14 ) p2_dist->Fill(parcur,1.);
	  }	
	double parAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(parAv - hparStat_after_p2[i]->GetBinContent(j),2)/double(nstat);
	  }	
	parStat_after_p2[j-1] = sqrt(statSum);

	if( showOnlyStat )
	  {
	     parupTot_after_p2[j-1] = parStat_after_p2[j-1];
	     pardownTot_after_p2[j-1] = parStat_after_p2[j-1];
	  }
	else if( !showOnlySys )
	  {	     
	     parupTot_after_p2[j-1] = sqrt(parupTot_after_p2[j-1]+pow(parStat_after_p2[j-1],2));
	     pardownTot_after_p2[j-1] = sqrt(pardownTot_after_p2[j-1]+pow(parStat_after_p2[j-1],2));
	  }	
     }   
	
   double xp_sysTot_after_p2[np];
   double yp_sysTot_after_p2[np];
   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_after_p2[k] = p2_after_nom->GetBinWidth(k+1)/2.0 + p2_after_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_after_p2[k] = parNom_after_p2[k]+parupTot_after_p2[k];
	yp_sysTot_after_p2[nbins+k] = parNom_after_p2[nbins-1-k]-pardownTot_after_p2[nbins-1-k];
     }   

   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_after_p2[nbins+k] = xp_sysTot_after_p2[nbins-k-1];
     }
   
   xp_sysTot_after_p2[np-1] = xp_sysTot_after_p2[0];
   yp_sysTot_after_p2[np-1] = yp_sysTot_after_p2[0];

   TH1D *hparNomInit_after_p2 = (TH1D*)hparNom_after_p2->Clone("hparNomInit_after_p2");
   
   for(int i=1;i<=nbins;i++)
     {
	hparNom_after_p2->SetBinError(i,parStat_after_p2[i-1]);
     }

   // p3 before
   for(int j=1;j<=nbins;j++)
     {	     
	parNom_before_p3[j-1] = p3_before_nom->GetBinContent(j);

	parupTot_before_p3[j-1] = 0.;
	pardownTot_before_p3[j-1] = 0.;
	
	for(int i=0;i<nsys;i++)
	  {
	     double deltaMax = 0.;
	     double deltaMin = 0.;
	     parPos_before_p3[j-1] = hparPos_before_p3[i]->GetBinContent(j);
	     parNeg_before_p3[j-1] = hparNeg_before_p3[i]->GetBinContent(j);
	     double deltaMax = parPos_before_p3[j-1] - parNom_before_p3[j-1];
	     double deltaMin = parNom_before_p3[j-1] - parNeg_before_p3[j-1];
	     if( symSyst )
	       {		  
		  double max = (fabs(deltaMax) > fabs(deltaMin)) ? deltaMax : deltaMin;
		  deltaMax = max;
		  deltaMin = max;

		  parupTot_before_p3[j-1] += pow(deltaMax,2);
		  pardownTot_before_p3[j-1] += pow(deltaMin,2);		  
	       }
	     else
	       {		  
		  if( deltaMin < 0 && deltaMax > 0 && fabs(deltaMin) > deltaMax )
		    {		  
		       deltaMax = deltaMin;
		       deltaMin = 0.;
		    }	     
		  if( deltaMax < 0 && deltaMin > 0 && fabs(deltaMax) > deltaMin )
		    {		  
		       deltaMin = deltaMax;
		       deltaMax = 0.;
		    }
		  if( deltaMax < 0 && deltaMin < 0 )
		    {		  
		       parupTot_before_p3[j-1] += pow(deltaMin,2);
		       pardownTot_before_p3[j-1] += pow(deltaMax,2);
		    }
		  else
		    {
		       parupTot_before_p3[j-1] += pow(deltaMax,2);
		       pardownTot_before_p3[j-1] += pow(deltaMin,2);		  
		    }	     
	       }	     
	  }
	
	double statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     double parcur = hparStat_before_p3[i]->GetBinContent(j);
	     statSum += parcur;
	     if( j == 14 ) p3_dist->Fill(parcur,1.);
	  }	
	double parAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(parAv - hparStat_before_p3[i]->GetBinContent(j),2)/double(nstat);
	  }	
	parStat_before_p3[j-1] = sqrt(statSum);

	if( showOnlyStat )
	  {
	     parupTot_before_p3[j-1] = parStat_before_p3[j-1];
	     pardownTot_before_p3[j-1] = parStat_before_p3[j-1];
	  }
	else if( !showOnlySys )
	  {	     
	     parupTot_before_p3[j-1] = sqrt(parupTot_before_p3[j-1]+pow(parStat_before_p3[j-1],2));
	     pardownTot_before_p3[j-1] = sqrt(pardownTot_before_p3[j-1]+pow(parStat_before_p3[j-1],2));
	  }	
     }   
	
   double xp_sysTot_before_p3[np];
   double yp_sysTot_before_p3[np];
   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_before_p3[k] = p3_before_nom->GetBinWidth(k+1)/2.0 + p3_before_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_before_p3[k] = parNom_before_p3[k]+parupTot_before_p3[k];
	yp_sysTot_before_p3[nbins+k] = parNom_before_p3[nbins-1-k]-pardownTot_before_p3[nbins-1-k];
     }   

   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_before_p3[nbins+k] = xp_sysTot_before_p3[nbins-k-1];
     }
   
   xp_sysTot_before_p3[np-1] = xp_sysTot_before_p3[0];
   yp_sysTot_before_p3[np-1] = yp_sysTot_before_p3[0];

   TH1D *hparNomInit_before_p3 = (TH1D*)hparNom_before_p3->Clone("hparNomInit_before_p3");
   
   for(int i=1;i<=nbins;i++)
     {
	hparNom_before_p3->SetBinError(i,parStat_before_p3[i-1]);
     }

   // p3 after
   for(int j=1;j<=nbins;j++)
     {	     
	parNom_after_p3[j-1] = p3_after_nom->GetBinContent(j);

	parupTot_after_p3[j-1] = 0.;
	pardownTot_after_p3[j-1] = 0.;
	
	for(int i=0;i<nsys;i++)
	  {
	     double deltaMax = 0.;
	     double deltaMin = 0.;
	     parPos_after_p3[j-1] = hparPos_after_p3[i]->GetBinContent(j);
	     parNeg_after_p3[j-1] = hparNeg_after_p3[i]->GetBinContent(j);
	     double deltaMax = parPos_after_p3[j-1] - parNom_after_p3[j-1];
	     double deltaMin = parNom_after_p3[j-1] - parNeg_after_p3[j-1];
	     if( symSyst )
	       {		  
		  double max = (fabs(deltaMax) > fabs(deltaMin)) ? deltaMax : deltaMin;
		  deltaMax = max;
		  deltaMin = max;

		  parupTot_after_p3[j-1] += pow(deltaMax,2);
		  pardownTot_after_p3[j-1] += pow(deltaMin,2);		  
	       }
	     else
	       {		  
		  if( deltaMin < 0 && deltaMax > 0 && fabs(deltaMin) > deltaMax )
		    {		  
		       deltaMax = deltaMin;
		       deltaMin = 0.;
		    }	     
		  if( deltaMax < 0 && deltaMin > 0 && fabs(deltaMax) > deltaMin )
		    {		  
		       deltaMin = deltaMax;
		       deltaMax = 0.;
		    }
		  if( deltaMax < 0 && deltaMin < 0 )
		    {		  
		       parupTot_after_p3[j-1] += pow(deltaMin,2);
		       pardownTot_after_p3[j-1] += pow(deltaMax,2);
		    }
		  else
		    {
		       parupTot_after_p3[j-1] += pow(deltaMax,2);
		       pardownTot_after_p3[j-1] += pow(deltaMin,2);		  
		    }	     
	       }	     
	  }
	
	double statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     double parcur = hparStat_after_p3[i]->GetBinContent(j);
	     statSum += parcur;
	     if( j == 14 ) p3_dist->Fill(parcur,1.);
	  }	
	double parAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(parAv - hparStat_after_p3[i]->GetBinContent(j),2)/double(nstat);
	  }	
	parStat_after_p3[j-1] = sqrt(statSum);

	if( showOnlyStat )
	  {
	     parupTot_after_p3[j-1] = parStat_after_p3[j-1];
	     pardownTot_after_p3[j-1] = parStat_after_p3[j-1];
	  }
	else if( !showOnlySys )
	  {	     
	     parupTot_after_p3[j-1] = sqrt(parupTot_after_p3[j-1]+pow(parStat_after_p3[j-1],2));
	     pardownTot_after_p3[j-1] = sqrt(pardownTot_after_p3[j-1]+pow(parStat_after_p3[j-1],2));
	  }	
     }   
	
   double xp_sysTot_after_p3[np];
   double yp_sysTot_after_p3[np];
   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_after_p3[k] = p3_after_nom->GetBinWidth(k+1)/2.0 + p3_after_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_after_p3[k] = parNom_after_p3[k]+parupTot_after_p3[k];
	yp_sysTot_after_p3[nbins+k] = parNom_after_p3[nbins-1-k]-pardownTot_after_p3[nbins-1-k];
     }   

   for(int k=0;k<nbins;k++)
     {
	xp_sysTot_after_p3[nbins+k] = xp_sysTot_after_p3[nbins-k-1];
     }
   
   xp_sysTot_after_p3[np-1] = xp_sysTot_after_p3[0];
   yp_sysTot_after_p3[np-1] = yp_sysTot_after_p3[0];

   TH1D *hparNomInit_after_p3 = (TH1D*)hparNom_after_p3->Clone("hparNomInit_after_p3");
   
   for(int i=1;i<=nbins;i++)
     {
	hparNom_after_p3->SetBinError(i,parStat_after_p3[i-1]);
     }
   
   // Draw
   
   std::string fSFname = "results/SF_"+wp+app+".root";
   TFile *fSF = new TFile(fSFname.c_str(),"RECREATE");
   
   hsfNom->GetYaxis()->SetTitle("SF_{b}");
   
   hsfNom->SetMarkerSize(0.8);
   if( nbTot <= 16 ) {hsfNom->SetBinContent(17,0.);hsfNom->SetBinError(17,0.);}
   
   if( sidx == 666 || sidx < 0 )
     hsfNom->Draw("e1p");
   else
     {
	for(int ib=0;ib<=hsfNom->GetXaxis()->GetNbins()+1;ib++)
	  {
	     hsfNom->SetBinError(ib,0.);
	  }	
	hsfNom->Draw("p");
     }   
//   hsfNomInit->SetLineStyle(2);
//   hsfNomInit->Draw("e1p same");

   hsfNom->GetYaxis()->SetRangeUser(0.40,1.30);
   
   TH1D *hsfoff = (TH1D*)hsfNom->Clone("hsfoff");
   hsfoff->Reset();
   TH1D *hsflt = (TH1D*)hsfNom->Clone("hsflt");
   hsflt->Reset();
   for(int i=0;i<npt;i++)
     {
	hsfoff->SetBinContent(i+1,sf_off[i]);
	if( drawMinuitErr ) hsfoff->SetBinError(i+1,err_off[i]);

	hsflt->SetBinContent(i+1,sf_lt[i]);
	if( drawMinuitErr ) hsflt->SetBinError(i+1,err_lt[i]);
     }   

   int nsfp_off = npt*2+1;
   const int np_off = nsfp_off;
   
   double xp_sysTot_lt[np_off];
   double yp_sysTot_lt[np_off];
   for(int k=0;k<npt;k++)
     {
	xp_sysTot_lt[k] = sf_nom->GetBinWidth(k+1)/2.0 + sf_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_lt[k] = sf_lt[k]+err_lt[k];
	yp_sysTot_lt[npt+k] = sf_lt[npt-1-k]-err_lt[npt-1-k];
     }   

   for(int k=0;k<npt;k++)
     {
	xp_sysTot_lt[npt+k] = xp_sysTot_lt[npt-k-1];
     }
   
   xp_sysTot_lt[np_off-1] = xp_sysTot_lt[0];
   yp_sysTot_lt[np_off-1] = yp_sysTot_lt[0];

   double xp_sysTot_off[np_off];
   double yp_sysTot_off[np_off];
   for(int k=0;k<npt;k++)
     {
	xp_sysTot_off[k] = sf_nom->GetBinWidth(k+1)/2.0 + sf_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_off[k] = sf_off[k]+err_off[k];
	yp_sysTot_off[npt+k] = sf_off[npt-1-k]-err_off[npt-1-k];
     }   

   for(int k=0;k<npt;k++)
     {
	xp_sysTot_off[npt+k] = xp_sysTot_off[npt-k-1];
     }
   
   xp_sysTot_off[np_off-1] = xp_sysTot_off[0];
   yp_sysTot_off[np_off-1] = yp_sysTot_off[0];

   TPolyLine *sysTot;
   if( sidx != 666 )
     {	
	sysTot = new TPolyLine(np,xp_sysTot,yp_sysTot);
	sysTot->SetFillColor(kYellow);
	if( sidx >= 0 ) sysTot->SetFillColor(kYellow+1);
	sysTot->Draw("fSAME");
     }   
   
   if( sidx < 0 )
     {	
	if( drawOfficial == 1 )
	  {
	     TPolyLine *sysTot_lt = new TPolyLine(np_off,xp_sysTot_lt,yp_sysTot_lt);
	     sysTot_lt->SetFillColor(0);
	     sysTot_lt->SetLineColor(kRed);
	     sysTot_lt->SetLineStyle(2);
	     sysTot_lt->Draw("lSAME");
	     
	     hsflt->Draw("p same");
	  }   
	else if( drawOfficial == 2 )
	  {	
	     TPolyLine *sysTot_off = new TPolyLine(np_off,xp_sysTot_off,yp_sysTot_off);
	     sysTot_off->SetFillColor(0);
	     sysTot_off->SetLineColor(kRed);
	     sysTot_off->SetLineStyle(2);
	     sysTot_off->Draw("lSAME");
	     
	     hsfoff->Draw("p same");
	  }   
     }

   hsfNom->Draw("e1p same");

   if( sidx < 0 )
     {	
	if( drawOfficial == 1 )
	  {	
	     hsflt->SetMarkerStyle(22);
	     hsflt->SetMarkerColor(kRed);
	     hsflt->SetLineColor(kRed);
	  }   
	else if( drawOfficial == 2 )
	  {	
	     hsfoff->SetMarkerStyle(22);
	     hsfoff->SetMarkerColor(kRed);
	     hsfoff->SetLineColor(kRed);
	  }
     }   

   sysTot->Write();
   
   fSF->Write();
   fSF->Close();
   
   TPolyLine *sysTot_add;
   
   // add
   if( add )
     {	
	hsfNom_add->SetMarkerSize(0.7);
	hsfNom_add->SetMarkerStyle(23);
	hsfNom_add->SetMarkerColor(kBlue);
	hsfNom_add->SetLineColor(kBlue);
	hsfNom_add->Draw("p same");   

	if( sidx != 666 )
	  {	
	     sysTot_add = new TPolyLine(np,xp_sysTot_add,yp_sysTot_add);
	     sysTot_add->SetFillColor(0);
	     sysTot_add->SetLineColor(kBlue);
	     sysTot_add->SetLineStyle(2);
	     sysTot_add->Draw("lSAME");
	  }   
     }   
   
   TLegend *leg;
   if( drawSF ) leg = new TLegend(0.35,0.50,0.65,0.20);
   else if( add ) leg = new TLegend(0.35,0.50,0.65,0.20);
   else leg = new TLegend(0.40,0.40,0.60,0.20);
//   TLegend *leg = new TLegend(0.25,0.90,0.55,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
//   leg->SetHeader(csv.c_str());
  
   TLatex *legl = new TLatex();
   legl->SetNDC();
   legl->SetTextAlign(22);
   legl->SetTextFont(63);
   legl->SetTextSizePixels(30);
   legl->DrawLatex(0.55,0.85,csv.c_str());
   
   if( drawSF ) leg->AddEntry(hsfNom,"Scale factor","p");
   else leg->AddEntry(hsfNom,"Efficiency","p");
   if( sidx < 0 || sidx == 666 )
     {	
	leg->AddEntry(hsfNom,"stat","l");
	if( sidx < 0 )
	  leg->AddEntry(sysTot,"stat #oplus syst","f");
     }
   else
     {
	leg->AddEntry(sysTot,"syst","f");
     }   
   if( sidx < 0 )
     {       
	if( drawOfficial == 1 )
	  {	
	     leg->AddEntry(hsflt,"Scale factor (LT EPS13)","p");
	     leg->AddEntry(sysTot_lt,"stat #oplus syst (LT EPS13)","f");
	  }   
	else if( drawOfficial == 2 )
	  {	
	     leg->AddEntry(hsfoff,"Scale factor (EPS13)","p");
	     leg->AddEntry(sysTot_off,"stat #oplus syst (EPS13)","f");
	  }   
     }   

   if( add )
     {
	std::string l1name = "Scale factor ("+addname+")";
	leg->AddEntry(hsfNom_add,l1name.c_str(),"p");
	std::string l2name = "stat ("+addname+")";
	hsfNom_add->SetLineStyle(2);
	leg->AddEntry(hsfNom_add,l2name.c_str(),"l");
	std::string l3name = "stat #oplus syst ("+addname+")";
	leg->AddEntry(sysTot_add,l3name.c_str(),"f");
     }   
   
   leg->Draw();

   c1->SetLogx(1);
   
   std::string fsave = "pics/SFSYS.eps";
   c1->Print(fsave.c_str());
   c1->Clear();

   c1->SetLogx(0);
   sf_dist->Draw("e1 hist");
   c1->Print("pics/sf_dist.eps");
   c1->Clear();

   c1->SetLogx(0);
   p1_dist->Draw("e1 hist");
   c1->Print("pics/p1_dist.eps");
   c1->Clear();

   // p1 before
   hparNom_before_p1->Draw("e1p");
//   hparNomInit_before_p1->SetLineStyle(2);
//   hparNomInit_before_p1->Draw("e1p same");

   if( nbTot <= 16 ) {hparNom_before_p1->SetBinContent(17,0.);hparNom_before_p1->SetBinError(17,0.);}
   
   hparNom_before_p1->SetMarkerSize(0.8);
   
   TPolyLine *sysTot_before_p1 = new TPolyLine(np,xp_sysTot_before_p1,yp_sysTot_before_p1);
   sysTot_before_p1->SetFillColor(kYellow);
   sysTot_before_p1->Draw("fSAME");

//   hparNomInit_before_p1->Draw("e1p same");
   hparNom_before_p1->Draw("e1p same");

   hparNom_before_p1->GetYaxis()->SetRangeUser(0.65,1.25);
   hparNomInit_before_p1->GetYaxis()->SetRangeUser(0.65,1.25);
   hparNom_before_p1->GetYaxis()->SetTitle("b-jet fit scale factor");
   leg->Draw();
   c1->SetLogx(1);
   c1->Print("pics/P1SYS_before.eps");
   c1->Clear();   

   // p1 after
   hparNom_after_p1->Draw("e1p");
//   hparNomInit_after_p1->SetLineStyle(2);
//   hparNomInit_after_p1->Draw("e1p same");

   if( nbTot <= 16 ) {hparNom_after_p1->SetBinContent(17,0.);hparNom_after_p1->SetBinError(17,0.);}
   
   hparNom_after_p1->SetMarkerSize(0.8);
   
   TPolyLine *sysTot_after_p1 = new TPolyLine(np,xp_sysTot_after_p1,yp_sysTot_after_p1);
   sysTot_after_p1->SetFillColor(kYellow);
   sysTot_after_p1->Draw("fSAME");

//   hparNomInit_after_p1->Draw("e1p same");
   hparNom_after_p1->Draw("e1p same");

   hparNomInit_after_p1->GetYaxis()->SetRangeUser(0.65,1.25);
   hparNom_after_p1->GetYaxis()->SetRangeUser(0.65,1.25);
   hparNom_after_p1->GetYaxis()->SetTitle("b-jet fit scale factor");
   leg->Draw();
   c1->SetLogx(1);
   c1->Print("pics/P1SYS_after.eps");
   c1->Clear();   

   // p2 before
   hparNom_before_p2->Draw("e1p");
//   hparNomInit_before_p2->SetLineStyle(2);
//   hparNomInit_before_p2->Draw("e1p same");

   if( nbTot <= 16 ) {hparNom_before_p2->SetBinContent(17,0.);hparNom_before_p2->SetBinError(17,0.);}
   
   hparNom_before_p2->SetMarkerSize(0.8);
   
   TPolyLine *sysTot_before_p2 = new TPolyLine(np,xp_sysTot_before_p2,yp_sysTot_before_p2);
   sysTot_before_p2->SetFillColor(kYellow);
   sysTot_before_p2->Draw("fSAME");

//   hparNomInit_before_p2->Draw("e1p same");
   hparNom_before_p2->Draw("e1p same");

   hparNom_before_p2->GetYaxis()->SetRangeUser(0.55,1.85);
   hparNomInit_before_p2->GetYaxis()->SetRangeUser(0.55,1.85);
   hparNom_before_p2->GetYaxis()->SetTitle("c-jet fit scale factor");
   leg->Draw();
   c1->SetLogx(1);
   c1->Print("pics/P2SYS_before.eps");
   c1->Clear();   

   // p2 after
   hparNom_after_p2->Draw("e1p");
//   hparNomInit_after_p2->SetLineStyle(2);
//   hparNomInit_after_p2->Draw("e1p same");

   if( nbTot <= 16 ) {hparNom_after_p2->SetBinContent(17,0.);hparNom_after_p2->SetBinError(17,0.);}
   
   hparNom_after_p2->SetMarkerSize(0.8);
   
   TPolyLine *sysTot_after_p2 = new TPolyLine(np,xp_sysTot_after_p2,yp_sysTot_after_p2);
   sysTot_after_p2->SetFillColor(kYellow);
   sysTot_after_p2->Draw("fSAME");

//   hparNomInit_after_p2->Draw("e1p same");
   hparNom_after_p2->Draw("e1p same");

   hparNomInit_after_p2->GetYaxis()->SetRangeUser(0.,5.00);
   hparNom_after_p2->GetYaxis()->SetRangeUser(0.,5.00);
   hparNom_after_p2->GetYaxis()->SetTitle("c-jet fit scale factor");
   leg->Draw();
   c1->SetLogx(1);
   c1->Print("pics/P2SYS_after.eps");
   c1->Clear();   

   // p3 before
   hparNom_before_p3->Draw("e1p");
//   hparNomInit_before_p3->SetLineStyle(2);
//   hparNomInit_before_p3->Draw("e1p same");

   if( nbTot <= 16 ) {hparNom_before_p3->SetBinContent(17,0.);hparNom_before_p3->SetBinError(17,0.);}
   
   hparNom_before_p3->SetMarkerSize(0.8);
   
   TPolyLine *sysTot_before_p3 = new TPolyLine(np,xp_sysTot_before_p3,yp_sysTot_before_p3);
   sysTot_before_p3->SetFillColor(kYellow);
   sysTot_before_p3->Draw("fSAME");

//   hparNomInit_before_p3->Draw("e1p same");
   hparNom_before_p3->Draw("e1p same");

   hparNom_before_p3->GetYaxis()->SetRangeUser(0.60,1.20);
   hparNomInit_before_p3->GetYaxis()->SetRangeUser(0.60,1.20);
   hparNom_before_p3->GetYaxis()->SetTitle("l-jet fit scale factor");
   leg->Draw();
   c1->SetLogx(1);
   c1->Print("pics/P3SYS_before.eps");
   c1->Clear();   

   // p3 after
   hparNom_after_p3->Draw("e1p");
//   hparNomInit_after_p3->SetLineStyle(2);
//   hparNomInit_after_p3->Draw("e1p same");

   if( nbTot <= 16 ) {hparNom_after_p3->SetBinContent(17,0.);hparNom_after_p3->SetBinError(17,0.);}
   
   hparNom_after_p3->SetMarkerSize(0.8);
   
   TPolyLine *sysTot_after_p3 = new TPolyLine(np,xp_sysTot_after_p3,yp_sysTot_after_p3);
   sysTot_after_p3->SetFillColor(kYellow);
   sysTot_after_p3->Draw("fSAME");

//   hparNomInit_after_p3->Draw("e1p same");
   hparNom_after_p3->Draw("e1p same");

   hparNomInit_after_p3->GetYaxis()->SetRangeUser(0.0,30.00);
   hparNom_after_p3->GetYaxis()->SetRangeUser(0.0,30.00);
   hparNom_after_p3->GetYaxis()->SetTitle("l-jet fit scale factor");
   leg->Draw();
   c1->SetLogx(1);
   c1->Print("pics/P3SYS_after.eps");
   c1->Clear();   

   // eff MC
   double xp_sysTot_effMC_lt[np_off];
   double yp_sysTot_effMC_lt[np_off];
   for(int k=0;k<npt;k++)
     {
	xp_sysTot_effMC_lt[k] = effMC_nom->GetBinWidth(k+1)/2.0 + effMC_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_effMC_lt[k] = effMC_lt[k]+effMC_stat_lt[k];
	yp_sysTot_effMC_lt[npt+k] = effMC_lt[npt-1-k]-effMC_stat_lt[npt-1-k];
     }   

   for(int k=0;k<npt;k++)
     {
	xp_sysTot_effMC_lt[npt+k] = xp_sysTot_effMC_lt[npt-k-1];
     }
   
   xp_sysTot_effMC_lt[np_off-1] = xp_sysTot_effMC_lt[0];
   yp_sysTot_effMC_lt[np_off-1] = yp_sysTot_effMC_lt[0];

   for(int i=0;i<npt;i++)
     {
	if( drawMinuitErr ) heffMCNom->SetBinError(i+1,effMC_nom_err[i]);
     }   
   
   heffMCNom->Draw("e1p");
//   hparNomInit_before_p1->SetLineStyle(2);
//   hparNomInit_before_p1->Draw("e1p same");

   if( nbTot <= 16 ) {heffMCNom->SetBinContent(17,0.);heffMCNom->SetBinError(17,0.);}
   
   heffMCNom->SetMarkerSize(0.8);
   
   TPolyLine *sysTot_effMC = new TPolyLine(np,xp_sysTot_effMC,yp_sysTot_effMC);
   sysTot_effMC->SetFillColor(kYellow);
   sysTot_effMC->Draw("fSAME");

   if( drawOfficial )
     {	
	TPolyLine *sysTot_effMC_lt = new TPolyLine(np,xp_sysTot_effMC_lt,yp_sysTot_effMC_lt);
	sysTot_effMC_lt->SetFillColor(0);
	sysTot_effMC_lt->SetLineColor(kRed);
	sysTot_effMC_lt->SetLineStyle(2);
	sysTot_effMC_lt->Draw("lSAME");
     }   
   
//   hparNomInit_before_p1->Draw("e1p same");
   heffMCNom->Draw("e1p same");

   heffMCNom->GetYaxis()->SetRangeUser(0.5,1.0);
   if( wp == "MEDIUM" ) heffMCNom->GetYaxis()->SetRangeUser(0.3,0.9);
   if( wp == "TIGHT" ) heffMCNom->GetYaxis()->SetRangeUser(0.1,0.7);
   heffMCNom->GetYaxis()->SetTitle("b-tagging efficiency (MC)");
   heffMCNom->GetXaxis()->SetTitle("P_{T} [TeV]");
   leg->Draw();
   c1->SetLogx(1);
   c1->Print("pics/EFFMC.eps");
   c1->Clear();   

   // eff DATA
   double xp_sysTot_effDATA_lt[np_off];
   double yp_sysTot_effDATA_lt[np_off];
   for(int k=0;k<npt;k++)
     {
	xp_sysTot_effDATA_lt[k] = effDATA_nom->GetBinWidth(k+1)/2.0 + effDATA_nom->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_effDATA_lt[k] = effDATA_lt[k]+effDATA_stat_lt[k];
	yp_sysTot_effDATA_lt[npt+k] = effDATA_lt[npt-1-k]-effDATA_stat_lt[npt-1-k];
     }   

   for(int k=0;k<npt;k++)
     {
	xp_sysTot_effDATA_lt[npt+k] = xp_sysTot_effDATA_lt[npt-k-1];
     }
   
   xp_sysTot_effDATA_lt[np_off-1] = xp_sysTot_effDATA_lt[0];
   yp_sysTot_effDATA_lt[np_off-1] = yp_sysTot_effDATA_lt[0];

   for(int i=0;i<npt;i++)
     {
	if( drawMinuitErr ) heffDATANom->SetBinError(i+1,effDATA_nom_err[i]);
     }   
   
   heffDATANom->Draw("e1p");
//   hparNomInit_before_p1->SetLineStyle(2);
//   hparNomInit_before_p1->Draw("e1p same");

   if( nbTot <= 16 ) {heffDATANom->SetBinContent(17,0.);heffDATANom->SetBinError(17,0.);}
   
   heffDATANom->SetMarkerSize(0.8);
   
   TPolyLine *sysTot_effDATA = new TPolyLine(np,xp_sysTot_effDATA,yp_sysTot_effDATA);
   sysTot_effDATA->SetFillColor(kYellow);
   sysTot_effDATA->Draw("fSAME");

   if( drawOfficial )
     {	
	TPolyLine *sysTot_effDATA_lt = new TPolyLine(np,xp_sysTot_effDATA_lt,yp_sysTot_effDATA_lt);
	sysTot_effDATA_lt->SetFillColor(0);
	sysTot_effDATA_lt->SetLineColor(kRed);
	sysTot_effDATA_lt->SetLineStyle(2);
	sysTot_effDATA_lt->Draw("lSAME");
     }   
   
//   hparNomInit_before_p1->Draw("e1p same");
   heffDATANom->Draw("e1p same");

   heffDATANom->GetYaxis()->SetRangeUser(0.5,1.0);
   if( wp == "MEDIUM" ) heffDATANom->GetYaxis()->SetRangeUser(0.3,0.9);
   if( wp == "TIGHT" ) heffDATANom->GetYaxis()->SetRangeUser(0.1,0.7);
   heffDATANom->GetYaxis()->SetTitle("b-tagging efficiency (Data)");
   leg->Draw();
   c1->SetLogx(1);
   c1->Print("pics/EFFDATA.eps");
   c1->Clear();   
   
   gApplication->Terminate();
}

void makeTable(int nb,
	       int nsys,
	       double sfnom[],
	       double sfup[][14],
	       double sfdown[][14],
	       double sfstat[],
	       double sfsystup[],
	       double sfsystdown[])
{
   std::ofstream fsf("results/sftable.tex");

   std::string header = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|} \n
\\hline";
   
   fsf << header << std::endl;
   
   std::string linh = 
     "$P_{T} [GeV]$ & SF & Stat & $N_{trk}$ & $N_{jets}$ \
& $P_{T} (\\mu)$ & $\\eta (jet)$ & Pileup & Gluon splitting & b-frag & $D \\to \\mu X$ \
& c-frag & $K_{S}^{0} (\\Lambda)$ & $N_{trk}^{gen}$ & JES & JER & $C_{b}$ & Syst \\\\ \\hline";

   fsf << linh << std::endl;
   
   for(int i=0;i<nb;i++)
     {
	std::string ptbin = "";
	if( i == 0 ) ptbin = "20-30";
	if( i == 1 ) ptbin = "30-40";
	if( i == 2 ) ptbin = "40-50";
	if( i == 3 ) ptbin = "50-60";
	if( i == 4 ) ptbin = "60-70";
	if( i == 5 ) ptbin = "70-80";
	if( i == 6 ) ptbin = "80-100";
	if( i == 7 ) ptbin = "100-120";
	if( i == 8 ) ptbin = "120-160";
	if( i == 9 ) ptbin = "160-210";
	if( i == 10 ) ptbin = "210-260";
	if( i == 11 ) ptbin = "260-320";
	if( i == 12 ) ptbin = "320-400";
	if( i == 13 ) ptbin = "400-500";
	if( i == 14 ) ptbin = "500-600";
	if( i == 15 ) ptbin = "600-800";
	if( i == 16 ) ptbin = "800-1000";
	
	std::string lin = "";
	lin += ptbin;
	lin += " & ";
	lin += std::string(Form("%.3f",sfnom[i]));
	lin += " & ";
	lin += "$\\pm$ "+std::string(Form("%.3f",sfstat[i]));
	lin += " & ";

	for(int j=0;j<=nsys;j++)
	  {
	     if( j != nsys )
	       {		  
		  lin += "+"+
		    std::string(Form("%.3f",sfup[i][j]))+" -"+
		    std::string(Form("%.3f",sfdown[i][j]));
		  lin += " & ";
	       }	     
	     else
	       {		  
		  lin += "$\\pm$ "+std::string(Form("%.3f",sfup[i][j]));
		  lin += " & ";
	       }	     
	  }

	lin += "+"+
	  std::string(Form("%.3f",sfsystup[i]))+" -"+
	  std::string(Form("%.3f",sfsystdown[i]));
	lin += " \\\\ ";
	
	fsf << lin << std::endl;
     }   

   std::string footer = "\\hline \n
\\end{tabular}";
   
   fsf << footer << std::endl;
   
   fsf.close();
}
