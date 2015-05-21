void produceSF(std::string wp,
	       std::string app,
	       std::string j1,
	       std::string flav)
{
   gROOT->SetBatch();
   bool symSyst = 0;

   bool printTotSys = 0;
   
   std::size_t found2011 = app.find("2011FINAL");
   bool fl_found2011 = (found2011 != std::string::npos);

   std::size_t foundNOSYS = app.find("SYS");
   bool fl_foundNOSYS = (foundNOSYS != std::string::npos);
   
   int nbTot = 17;
   if( flav == "charm" ) nbTot = 14;
   if( app == "TTBAR" ) nbTot = 7;
   if( fl_found2011 ) nbTot = 15;
//   if( fl_found2011 ) nbTot = 29;
   if( app == "BINV2" ) nbTot = 9;
   if( app == "BINV2" && flav == "charm" ) nbTot = 7;
   
   int sidx = -1; 

   int nsys = 13;
   if( app == "TTBAR" ) nsys = 8;
  
//   nsys = 0;
//   if( fl_foundNOSYS ) nsys = 0;
   if( fl_foundNOSYS ) nsys = 1;
   
   std::string sysIdxPos[100];
   std::string sysIdxNeg[100];
   for(int i=0;i<nsys;i++)
     {
	sysIdxPos[i] = std::string(Form("%d",i+1));
	sysIdxNeg[i] = std::string(Form("-%d",i+1));
     }
   
   const int nstat = 100;
   std::string statIdx[nstat];
   for(int i=0;i<nstat;i++)
     {
	statIdx[i] = Form("%d",666+i);
     }   

   double cb_nosel[30];
   double cberr_nosel[30];
   std::string cbname = "../../cb.txt";
   if( wp == "LOOSE" && flav == "beauty" ) cbname = "../../cb_combSvx0p244_bjet.txt";
   if( wp == "MEDIUM" && flav == "beauty" ) cbname = "../../cb_combSvx0p679_bjet.txt";
   if( wp == "TIGHT" && flav == "beauty" ) cbname = "../../cb_combSvx0p898_bjet.txt";
   if( wp == "LOOSE" && flav == "charm" ) cbname = "../../cb_combSvx0p244_cjet.txt";
   if( wp == "MEDIUM" && flav == "charm" ) cbname = "../../cb_combSvx0p679_cjet.txt";
   if( wp == "TIGHT" && flav == "charm" ) cbname = "../../cb_combSvx0p898_cjet.txt";
   
   if( fl_found2011 )
     {
	if( wp == "LOOSE" && flav == "beauty" ) cbname = "../../cb_combSvx0p244_bjet_2011.txt";
	if( wp == "MEDIUM" && flav == "beauty" ) cbname = "../../cb_combSvx0p679_bjet_2011.txt";
	if( wp == "TIGHT" && flav == "beauty" ) cbname = "../../cb_combSvx0p898_bjet_2011.txt";
	if( wp == "LOOSE" && flav == "charm" ) cbname = "../../cb_combSvx0p244_cjet_2011.txt";
	if( wp == "MEDIUM" && flav == "charm" ) cbname = "../../cb_combSvx0p679_cjet_2011.txt";
	if( wp == "TIGHT" && flav == "charm" ) cbname = "../../cb_combSvx0p898_cjet_2011.txt";	
     }   

   if( app == "2011TCHv2" || app == "2011TCHP_FINAL" )
     {
	if( wp == "LOOSE" && flav == "beauty" ) cbname = "../../cb_TCHP1p19_bjet_2011.txt";
	if( wp == "MEDIUM" && flav == "beauty" ) cbname = "../../cb_TCHP1p93_bjet_2011.txt";
	if( wp == "TIGHT" && flav == "beauty" ) cbname = "../../cb_TCHP3p41_bjet_2011.txt";
	if( wp == "LOOSE" && flav == "charm" ) cbname = "../../cb_TCHP1p19_cjet_2011.txt";
	if( wp == "MEDIUM" && flav == "charm" ) cbname = "../../cb_TCHP1p93_cjet_2011.txt";
	if( wp == "TIGHT" && flav == "charm" ) cbname = "../../cb_TCHP3p41_cjet_2011.txt";	
     }   
   
   if( app == "TTBAR" ) 
     {
	if( wp == "LOOSE" && flav == "beauty" ) cbname = "../../cb_combSvx0p244_bjet_ttbar.txt";
	if( wp == "MEDIUM" && flav == "beauty" ) cbname = "../../cb_combSvx0p679_bjet_ttbar.txt";
	if( wp == "TIGHT" && flav == "beauty" ) cbname = "../../cb_combSvx0p898_bjet_ttbar.txt";
	if( wp == "LOOSE" && flav == "charm" ) cbname = "../../cb_combSvx0p244_cjet_ttbar.txt";
	if( wp == "MEDIUM" && flav == "charm" ) cbname = "../../cb_combSvx0p679_cjet_ttbar.txt";
	if( wp == "TIGHT" && flav == "charm" ) cbname = "../../cb_combSvx0p898_cjet_ttbar.txt";
     }   
   
   std::ifstream f_cb_nosel(cbname.c_str());
   while( !f_cb_nosel.eof() )
     {
	int ptidx;
	f_cb_nosel >> ptidx >> cb_nosel[ptidx] >> cberr_nosel[ptidx];
     }
   
   TFile *fsfNom;
   TH1D *hsfNom;
   TFile *fsfPos[100];
   TH1D *hsfPos[100];
   TFile *fsfNeg[100];
   TH1D *hsfNeg[100];
   TFile *fsfStat[nstat];
   TH1D *hsfStat[nstat];
   
   TH1D *heffMCNom;
   TH1D *heffMCPos[100];
   TH1D *heffMCNeg[100];
   TH1D *heffMCStat[nstat];

   TH1D *heffDATANom;
   TH1D *heffDATAPos[100];
   TH1D *heffDATANeg[100];
   TH1D *heffDATAStat[nstat];
   
   TFile *fparNom_before;
   TH1D *hparNom_before_p1;
   TH1D *hparNom_before_p2;
   TH1D *hparNom_before_p3;
   TFile *fparPos_before[100];
   TH1D *hparPos_before_p1[100];
   TH1D *hparPos_before_p2[100];
   TH1D *hparPos_before_p3[100];
   TFile *fparNeg_before[100];
   TH1D *hparNeg_before_p1[100];
   TH1D *hparNeg_before_p2[100];
   TH1D *hparNeg_before_p3[100];
   TFile *fparStat_before[nstat];
   TH1D *hparStat_before_p1[nstat];
   TH1D *hparStat_before_p2[nstat];
   TH1D *hparStat_before_p3[nstat];

   TFile *fparNom_after;
   TH1D *hparNom_after_p1;
   TH1D *hparNom_after_p2;
   TH1D *hparNom_after_p3;
   TFile *fparPos_after[100];
   TH1D *hparPos_after_p1[100];
   TH1D *hparPos_after_p2[100];
   TH1D *hparPos_after_p3[100];
   TFile *fparNeg_after[100];
   TH1D *hparNeg_after_p1[100];
   TH1D *hparNeg_after_p2[100];
   TH1D *hparNeg_after_p3[100];
   TFile *fparStat_after[nstat];
   TH1D *hparStat_after_p1[nstat];
   TH1D *hparStat_after_p2[nstat];
   TH1D *hparStat_after_p3[nstat];
   
   std::string fnameSys = "0";
   std::string fname = "results/SFSYS_"+j1+wp+"_"+app+"/fit_EFF_"+flav+"_ALL_"+fnameSys+".root";
   fsfNom = TFile::Open(fname.c_str());
   hsfNom = (TH1D*)fsfNom->Get("h1c");
   heffMCNom = (TH1D*)fsfNom->Get("h_eff1MC");
   heffDATANom = (TH1D*)fsfNom->Get("h_eff1DATA");

   fname = "results/SFSYS_"+j1+wp+"_"+app+"/fit_FIT123_beforeBTAG_"+fnameSys+".root";
   fparNom_before = TFile::Open(fname.c_str());
   hparNom_before_p1 = (TH1D*)fparNom_before->Get("h_p1f1");
   hparNom_before_p2 = (TH1D*)fparNom_before->Get("h_p2f1");
   hparNom_before_p3 = (TH1D*)fparNom_before->Get("h_p3f1");

   fname = "results/SFSYS_"+j1+wp+"_"+app+"/fit_FIT123_afterBTAG_"+fnameSys+".root";
   fparNom_after = TFile::Open(fname.c_str());
   hparNom_after_p1 = (TH1D*)fparNom_after->Get("h_p1f1");
   hparNom_after_p2 = (TH1D*)fparNom_after->Get("h_p2f1");
   hparNom_after_p3 = (TH1D*)fparNom_after->Get("h_p3f1");
   
   for(int i=0;i<nsys;i++)
     {
	std::string fnameSys = sysIdxPos[i];
	std::string fname = "results/SFSYS_"+j1+wp+"_"+app+"/fit_EFF_"+flav+"_ALL_"+fnameSys+".root";
	fsfPos[i] = TFile::Open(fname.c_str());
	hsfPos[i] = (TH1D*)fsfPos[i]->Get("h1c");
	heffMCPos[i] = (TH1D*)fsfPos[i]->Get("h_eff1MC");
	heffDATAPos[i] = (TH1D*)fsfPos[i]->Get("h_eff1DATA");
	
	fname = "results/SFSYS_"+j1+wp+"_"+app+"/fit_FIT123_beforeBTAG_"+fnameSys+".root";
	fparPos_before[i] = TFile::Open(fname.c_str());
	hparPos_before_p1[i] = (TH1D*)fparPos_before[i]->Get("h_p1f1");
	hparPos_before_p2[i] = (TH1D*)fparPos_before[i]->Get("h_p2f1");
	hparPos_before_p3[i] = (TH1D*)fparPos_before[i]->Get("h_p3f1");

	fname = "results/SFSYS_"+j1+wp+"_"+app+"/fit_FIT123_afterBTAG_"+fnameSys+".root";
	fparPos_after[i] = TFile::Open(fname.c_str());
	hparPos_after_p1[i] = (TH1D*)fparPos_after[i]->Get("h_p1f1");
	hparPos_after_p2[i] = (TH1D*)fparPos_after[i]->Get("h_p2f1");
	hparPos_after_p3[i] = (TH1D*)fparPos_after[i]->Get("h_p3f1");
     }
   for(int i=0;i<nsys;i++)
     {
	std::string fnameSys = sysIdxNeg[i];
	std::string fname = "results/SFSYS_"+j1+wp+"_"+app+"/fit_EFF_"+flav+"_ALL_"+fnameSys+".root";
	fsfNeg[i] = TFile::Open(fname.c_str());
	hsfNeg[i] = (TH1D*)fsfNeg[i]->Get("h1c");
	heffMCNeg[i] = (TH1D*)fsfNeg[i]->Get("h_eff1MC");
	heffDATANeg[i] = (TH1D*)fsfNeg[i]->Get("h_eff1DATA");

	fname = "results/SFSYS_"+j1+wp+"_"+app+"/fit_FIT123_beforeBTAG_"+fnameSys+".root";
	fparNeg_before[i] = TFile::Open(fname.c_str());
	hparNeg_before_p1[i] = (TH1D*)fparNeg_before[i]->Get("h_p1f1");
	hparNeg_before_p2[i] = (TH1D*)fparNeg_before[i]->Get("h_p2f1");
	hparNeg_before_p3[i] = (TH1D*)fparNeg_before[i]->Get("h_p3f1");

	fname = "results/SFSYS_"+j1+wp+"_"+app+"/fit_FIT123_afterBTAG_"+fnameSys+".root";
	fparNeg_after[i] = TFile::Open(fname.c_str());
	hparNeg_after_p1[i] = (TH1D*)fparNeg_after[i]->Get("h_p1f1");
	hparNeg_after_p2[i] = (TH1D*)fparNeg_after[i]->Get("h_p2f1");
	hparNeg_after_p3[i] = (TH1D*)fparNeg_after[i]->Get("h_p3f1");
     }

   for(int i=0;i<nstat;i++)
     {
	std::string fnameStat = statIdx[i];
	std::string fname = "results/SFSYS_"+j1+wp+"_"+app+"/fit_EFF_"+flav+"_ALL_"+fnameStat+".root";
	fsfStat[i] = TFile::Open(fname.c_str());
	hsfStat[i] = (TH1D*)fsfStat[i]->Get("h1c");
	heffMCStat[i] = (TH1D*)fsfStat[i]->Get("h_eff1MC");
	heffDATAStat[i] = (TH1D*)fsfStat[i]->Get("h_eff1DATA");

//	std::cout << statIdx[i] << " " << hsfStat[i]->Print("all") << std::endl;
	
	fname = "results/SFSYS_"+j1+wp+"_"+app+"/fit_FIT123_beforeBTAG_"+fnameStat+".root";
	fparStat_before[i] = TFile::Open(fname.c_str());
	hparStat_before_p1[i] = (TH1D*)fparStat_before[i]->Get("h_p1f1");
	hparStat_before_p2[i] = (TH1D*)fparStat_before[i]->Get("h_p2f1");
	hparStat_before_p3[i] = (TH1D*)fparStat_before[i]->Get("h_p3f1");

	fname = "results/SFSYS_"+j1+wp+"_"+app+"/fit_FIT123_afterBTAG_"+fnameStat+".root";
	fparStat_after[i] = TFile::Open(fname.c_str());
	hparStat_after_p1[i] = (TH1D*)fparStat_after[i]->Get("h_p1f1");
	hparStat_after_p2[i] = (TH1D*)fparStat_after[i]->Get("h_p2f1");
	hparStat_after_p3[i] = (TH1D*)fparStat_after[i]->Get("h_p3f1");
     }
   
   TH1D *sf_nom = (TH1D*)hsfNom->Clone("sf_nom");
   TH1D *effMC_nom = (TH1D*)heffMCNom->Clone("effMC_nom");
   TH1D *effDATA_nom = (TH1D*)heffDATANom->Clone("effDATA_nom");
   TH1D *p1_before_nom = (TH1D*)hparNom_before_p1->Clone("p1_before_nom");
   TH1D *p2_before_nom = (TH1D*)hparNom_before_p2->Clone("p2_before_nom");
   TH1D *p3_before_nom = (TH1D*)hparNom_before_p3->Clone("p3_before_nom");
   TH1D *p1_after_nom = (TH1D*)hparNom_after_p1->Clone("p1_after_nom");
   TH1D *p2_after_nom = (TH1D*)hparNom_after_p2->Clone("p2_after_nom");
   TH1D *p3_after_nom = (TH1D*)hparNom_after_p3->Clone("p3_after_nom");
   
   int nbins0 = sf_nom->GetXaxis()->GetNbins();
   int nbinsd = nbins0;
   nbins0 = (nbTot < nbins0) ? nbTot : nbins0;
   const int nbins = nbins0;
   
   double sfPos[nbins];
   double sfNeg[nbins];
   double sfNom[nbins];
   double sfStat[nbins];
   double sfupTot[nbins];
   double sfdownTot[nbins];
   
   double sfnomTable[nbins];
   double sfstatTable[nbins];
   double sfupTable[nbins][100];
   double sfdownTable[nbins][100];
   double sfPosTable[nbins][100];
   double sfNegTable[nbins][100];
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

	sfsystupTable[j-1] = 0.;
	sfsystdownTable[j-1] = 0.;
	
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
		  sfPosTable[j-1][i] = deltaMax;
		  sfNegTable[j-1][i] = -deltaMin;
		  
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
	     
	     sfPosTable[j-1][nsys] = sfupTable[j-1][nsys];
	     sfNegTable[j-1][nsys] = sfdownTable[j-1][nsys];
	     
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
	  }	
	double sfAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(sfAv - hsfStat[i]->GetBinContent(j),2)/double(nstat);
	  }	

	sfStat[j-1] = sqrt(statSum);
	sfstatTable[j-1] = sfStat[j-1];
	
	sfupTot[j-1] = sqrt(sfupTot[j-1]+pow(sfStat[j-1],2));
	sfdownTot[j-1] = sqrt(sfdownTot[j-1]+pow(sfStat[j-1],2));
     }
   
   std::string tSFname = "results/SF_"+wp+"_"+app+"_"+flav+".tex";
//   makeTable(tSFname,app,nbins,nsys,sfnomTable,sfupTable,sfdownTable,sfstatTable,sfsystupTable,sfsystdownTable,0,0,printTotSys);
   makeTable(tSFname,app,nbins,nsys,sfnomTable,sfPosTable,sfNegTable,sfstatTable,sfsystupTable,sfsystdownTable,1,0,printTotSys);
  
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
   
   double effMC_nom_err[nbins];
   
   // correct eff MC
   for(int j=1;j<=nbins;j++)
     {
	double v_effMC_nom = effMC_nom->GetBinContent(j);
	double v_effMC_nom_err = effMC_nom->GetBinError(j);
	effMC_nom_err[j-1] = v_effMC_nom_err;
	
	effMC_nom->SetBinContent(j,v_effMC_nom*cb_nosel[j-1]);
	double v_effMC_nom_err_cb = v_effMC_nom*cb_nosel[j-1]*
	  sqrt(pow(v_effMC_nom_err/v_effMC_nom,2));
	effMC_nom->SetBinError(j,v_effMC_nom_err_cb);
	
	heffMCNom->SetBinContent(j,v_effMC_nom*cb_nosel[j-1]);
	heffMCNom->SetBinError(j,v_effMC_nom_err_cb);

/*	effMC_nom->SetBinContent(j,v_effMC_nom);
	double v_effMC_nom_err = v_effMC_nom*
	  sqrt(pow(v_effMC_nom_err/v_effMC_nom,2));
	effMC_nom->SetBinError(j,v_effMC_nom_err);
	
	heffMCNom->SetBinContent(j,v_effMC_nom);
	heffMCNom->SetBinError(j,v_effMC_nom_err);*/
	
	for(int is=0;is<nsys;is++)
	  {	     
	     double v_effMCPos = heffMCPos[is]->GetBinContent(j);
	     double v_effMCPos_err = heffMCPos[is]->GetBinError(j);
	     heffMCPos[is]->SetBinContent(j,v_effMCPos*cb_nosel[j-1]);
	     double v_effMCPos_err_cb = v_effMCPos*cb_nosel[j-1]*
	       sqrt(pow(v_effMCPos_err/v_effMCPos,2));
	     heffMCPos[is]->SetBinError(j,v_effMCPos_err_cb);

	     double v_effMCNeg = heffMCNeg[is]->GetBinContent(j);
	     double v_effMCNeg_err = heffMCNeg[is]->GetBinError(j);
	     heffMCNeg[is]->SetBinContent(j,v_effMCNeg*cb_nosel[j-1]);
	     double v_effMCNeg_err_cb = v_effMCNeg*cb_nosel[j-1]*
	       sqrt(pow(v_effMCNeg_err/v_effMCNeg,2));
	     heffMCNeg[is]->SetBinError(j,v_effMCNeg_err_cb);
	  }
	for(int is=0;is<nstat;is++)
	  {	     
	     double v_effMCStat = heffMCStat[is]->GetBinContent(j);
	     double v_effMCStat_err = heffMCStat[is]->GetBinError(j);
	     heffMCStat[is]->SetBinContent(j,v_effMCStat*cb_nosel[j-1]);
	     double v_effMCStat_err_cb = v_effMCStat*cb_nosel[j-1]*
	       sqrt(pow(v_effMCStat_err/v_effMCStat,2));
	     heffMCStat[is]->SetBinError(j,v_effMCStat_err_cb);
	  }

/*	for(int is=0;is<nsys;is++)
	  {	     
	     double v_effMCPos = heffMCPos[is]->GetBinContent(j);
	     double v_effMCPos_err = heffMCPos[is]->GetBinError(j);
	     heffMCPos[is]->SetBinContent(j,v_effMCPos);
	     double v_effMCPos_err = v_effMCPos*
	       sqrt(pow(v_effMCPos_err/v_effMCPos,2));
	     heffMCPos[is]->SetBinError(j,v_effMCPos_err);

	     double v_effMCNeg = heffMCNeg[is]->GetBinContent(j);
	     double v_effMCNeg_err = heffMCNeg[is]->GetBinError(j);
	     heffMCNeg[is]->SetBinContent(j,v_effMCNeg);
	     double v_effMCNeg_err = v_effMCNeg*
	       sqrt(pow(v_effMCNeg_err/v_effMCNeg,2));
	     heffMCNeg[is]->SetBinError(j,v_effMCNeg_err);
	  }
	for(int is=0;is<nstat;is++)
	  {	     
	     double v_effMCStat = heffMCStat[is]->GetBinContent(j);
	     double v_effMCStat_err = heffMCStat[is]->GetBinError(j);
	     heffMCStat[is]->SetBinContent(j,v_effMCStat);
	     double v_effMCStat_err = v_effMCStat*
	       sqrt(pow(v_effMCStat_err/v_effMCStat,2));
	     heffMCStat[is]->SetBinError(j,v_effMCStat_err);
	  }*/
     }

   // correct eff DATA
   
   double effDATA_nom_err[nbins];
   
   for(int j=1;j<=nbins;j++)
     {
	double v_effDATA_nom = effDATA_nom->GetBinContent(j);
	double v_effDATA_nom_err = effDATA_nom->GetBinError(j);
	effDATA_nom_err[j-1] = v_effDATA_nom_err;
	
	effDATA_nom->SetBinContent(j,v_effDATA_nom*cb_nosel[j-1]);
	double v_effDATA_nom_err_cb = v_effDATA_nom*cb_nosel[j-1]*
	  sqrt(pow(v_effDATA_nom_err/v_effDATA_nom,2));
	effDATA_nom->SetBinError(j,v_effDATA_nom_err_cb);
	
	heffDATANom->SetBinContent(j,v_effDATA_nom*cb_nosel[j-1]);
	heffDATANom->SetBinError(j,v_effDATA_nom_err_cb);

/*	effDATA_nom->SetBinContent(j,v_effDATA_nom);
	double v_effDATA_nom_err = v_effDATA_nom*
	  sqrt(pow(v_effDATA_nom_err/v_effDATA_nom,2));
	effDATA_nom->SetBinError(j,v_effDATA_nom_err);
	
	heffDATANom->SetBinContent(j,v_effDATA_nom);
	heffDATANom->SetBinError(j,v_effDATA_nom_err);*/
	
	for(int is=0;is<nsys;is++)
	  {	     
	     double v_effDATAPos = heffDATAPos[is]->GetBinContent(j);
	     double v_effDATAPos_err = heffDATAPos[is]->GetBinError(j);
	     heffDATAPos[is]->SetBinContent(j,v_effDATAPos*cb_nosel[j-1]);
	     double v_effDATAPos_err_cb = v_effDATAPos*cb_nosel[j-1]*
	       sqrt(pow(v_effDATAPos_err/v_effDATAPos,2));
	     heffDATAPos[is]->SetBinError(j,v_effDATAPos_err_cb);

	     double v_effDATANeg = heffDATANeg[is]->GetBinContent(j);
	     double v_effDATANeg_err = heffDATANeg[is]->GetBinError(j);
	     heffDATANeg[is]->SetBinContent(j,v_effDATANeg*cb_nosel[j-1]);
	     double v_effDATANeg_err_cb = v_effDATANeg*cb_nosel[j-1]*
	       sqrt(pow(v_effDATANeg_err/v_effDATANeg,2));
	     heffDATANeg[is]->SetBinError(j,v_effDATANeg_err_cb);
	  }
	for(int is=0;is<nstat;is++)
	  {	     
	     double v_effDATAStat = heffDATAStat[is]->GetBinContent(j);
	     double v_effDATAStat_err = heffDATAStat[is]->GetBinError(j);
	     heffDATAStat[is]->SetBinContent(j,v_effDATAStat*cb_nosel[j-1]);
	     double v_effDATAStat_err_cb = v_effDATAStat*cb_nosel[j-1]*
	       sqrt(pow(v_effDATAStat_err/v_effDATAStat,2));
	     heffDATAStat[is]->SetBinError(j,v_effDATAStat_err_cb);
	  }

/*	for(int is=0;is<nsys;is++)
	  {	     
	     double v_effDATAPos = heffDATAPos[is]->GetBinContent(j);
	     double v_effDATAPos_err = heffDATAPos[is]->GetBinError(j);
	     heffDATAPos[is]->SetBinContent(j,v_effDATAPos);
	     double v_effDATAPos_err = v_effDATAPos*
	       sqrt(pow(v_effDATAPos_err/v_effDATAPos,2));
	     heffDATAPos[is]->SetBinError(j,v_effDATAPos_err);

	     double v_effDATANeg = heffDATANeg[is]->GetBinContent(j);
	     double v_effDATANeg_err = heffDATANeg[is]->GetBinError(j);
	     heffDATANeg[is]->SetBinContent(j,v_effDATANeg);
	     double v_effDATANeg_err = v_effDATANeg*
	       sqrt(pow(v_effDATANeg_err/v_effDATANeg,2));
	     heffDATANeg[is]->SetBinError(j,v_effDATANeg_err);
	  }
	for(int is=0;is<nstat;is++)
	  {	     
	     double v_effDATAStat = heffDATAStat[is]->GetBinContent(j);
	     double v_effDATAStat_err = heffDATAStat[is]->GetBinError(j);
	     heffDATAStat[is]->SetBinContent(j,v_effDATAStat);
	     double v_effDATAStat_err = v_effDATAStat*
	       sqrt(pow(v_effDATAStat_err/v_effDATAStat,2));
	     heffDATAStat[is]->SetBinError(j,v_effDATAStat_err);
	  }*/
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
	     effMCupTot[j-1] = sqrt(effMCupTot[j-1]+pow(effMCStat[j-1],2));
	     effMCdownTot[j-1] = sqrt(effMCdownTot[j-1]+pow(effMCStat[j-1],2));
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
	     effDATAupTot[j-1] = sqrt(effDATAupTot[j-1]+pow(effDATAStat[j-1],2));
	     effDATAdownTot[j-1] = sqrt(effDATAdownTot[j-1]+pow(effDATAStat[j-1],2));
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
	  }	
	double parAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(parAv - hparStat_before_p1[i]->GetBinContent(j),2)/double(nstat);
	  }	
	parStat_before_p1[j-1] = sqrt(statSum);

	parupTot_before_p1[j-1] = sqrt(parupTot_before_p1[j-1]+pow(parStat_before_p1[j-1],2));
	pardownTot_before_p1[j-1] = sqrt(pardownTot_before_p1[j-1]+pow(parStat_before_p1[j-1],2));
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
	  }	
	double parAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(parAv - hparStat_after_p1[i]->GetBinContent(j),2)/double(nstat);
	  }	
	parStat_after_p1[j-1] = sqrt(statSum);

	parupTot_after_p1[j-1] = sqrt(parupTot_after_p1[j-1]+pow(parStat_after_p1[j-1],2));
	pardownTot_after_p1[j-1] = sqrt(pardownTot_after_p1[j-1]+pow(parStat_after_p1[j-1],2));
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
	  }	
	double parAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(parAv - hparStat_before_p2[i]->GetBinContent(j),2)/double(nstat);
	  }	
	parStat_before_p2[j-1] = sqrt(statSum);

	parupTot_before_p2[j-1] = sqrt(parupTot_before_p2[j-1]+pow(parStat_before_p2[j-1],2));
	pardownTot_before_p2[j-1] = sqrt(pardownTot_before_p2[j-1]+pow(parStat_before_p2[j-1],2));
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
	  }	
	double parAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(parAv - hparStat_after_p2[i]->GetBinContent(j),2)/double(nstat);
	  }	
	parStat_after_p2[j-1] = sqrt(statSum);

	parupTot_after_p2[j-1] = sqrt(parupTot_after_p2[j-1]+pow(parStat_after_p2[j-1],2));
	pardownTot_after_p2[j-1] = sqrt(pardownTot_after_p2[j-1]+pow(parStat_after_p2[j-1],2));
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
	  }	
	double parAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(parAv - hparStat_before_p3[i]->GetBinContent(j),2)/double(nstat);
	  }	
	parStat_before_p3[j-1] = sqrt(statSum);

	parupTot_before_p3[j-1] = sqrt(parupTot_before_p3[j-1]+pow(parStat_before_p3[j-1],2));
	pardownTot_before_p3[j-1] = sqrt(pardownTot_before_p3[j-1]+pow(parStat_before_p3[j-1],2));
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
	  }	
	double parAv = statSum/double(nstat);
	
	statSum = 0.;
	for(int i=0;i<nstat;i++)
	  {
	     statSum += pow(parAv - hparStat_after_p3[i]->GetBinContent(j),2)/double(nstat);
	  }	
	parStat_after_p3[j-1] = sqrt(statSum);

	parupTot_after_p3[j-1] = sqrt(parupTot_after_p3[j-1]+pow(parStat_after_p3[j-1],2));
	pardownTot_after_p3[j-1] = sqrt(pardownTot_after_p3[j-1]+pow(parStat_after_p3[j-1],2));
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
   
   TPolyLine *sysTot_effMC = new TPolyLine(np,xp_sysTot_effMC,yp_sysTot_effMC);
   sysTot_effMC->SetFillColor(kYellow);

   TPolyLine *sysTot_effDATA = new TPolyLine(np,xp_sysTot_effDATA,yp_sysTot_effDATA);
   sysTot_effDATA->SetFillColor(kYellow);

   TPolyLine *sysTot_before_p1 = new TPolyLine(np,xp_sysTot_before_p1,yp_sysTot_before_p1);
   sysTot_before_p1->SetFillColor(kYellow);

   TPolyLine *sysTot_before_p2 = new TPolyLine(np,xp_sysTot_before_p2,yp_sysTot_before_p2);
   sysTot_before_p2->SetFillColor(kYellow);

   TPolyLine *sysTot_before_p3 = new TPolyLine(np,xp_sysTot_before_p3,yp_sysTot_before_p3);
   sysTot_before_p3->SetFillColor(kYellow);

   TPolyLine *sysTot_after_p1 = new TPolyLine(np,xp_sysTot_after_p1,yp_sysTot_after_p1);
   sysTot_after_p1->SetFillColor(kYellow);

   TPolyLine *sysTot_after_p2 = new TPolyLine(np,xp_sysTot_after_p2,yp_sysTot_after_p2);
   sysTot_after_p2->SetFillColor(kYellow);

   TPolyLine *sysTot_after_p3 = new TPolyLine(np,xp_sysTot_after_p3,yp_sysTot_after_p3);
   sysTot_after_p3->SetFillColor(kYellow);
   
   std::string fSFname = "results/SF_"+j1+wp+"_"+app+"_"+flav+".root";
   TFile *fSF = new TFile(fSFname.c_str(),"RECREATE");
   
   // save SF
   if( nbTot < nbinsd )
     {
	for(int ib=nbTot+1;ib<=nbinsd;ib++)
	  {
	     hsfNom->SetBinContent(ib,0.);
	     hsfNom->SetBinError(ib,0.);
	  }	
     }   
   hsfNom->Write("hSF");
   TPolyLine *sysTot;
   sysTot = new TPolyLine(np,xp_sysTot,yp_sysTot);
   sysTot->SetFillColor(kYellow);
   sysTot->Write("hSFSYS");

   // save DATA eff
   if( nbTot < nbinsd )
     {
	for(int ib=nbTot+1;ib<=nbinsd;ib++)
	  {
	     heffDATANom->SetBinContent(ib,0.);
	     heffDATANom->SetBinError(ib,0.);
	  }	
     }   
   heffDATANom->Write("hEFFDATA");
   sysTot_effDATA->Write("hEFFDATASYS");

   // save MC eff
   if( nbTot < nbinsd )
     {
	for(int ib=nbTot+1;ib<=nbinsd;ib++)
	  {
	     effMC_nom->SetBinContent(ib,0.);
	     effMC_nom->SetBinError(ib,0.);
	  }	
     }   
   effMC_nom->Write("hEFFMC");
   sysTot_effMC->Write("hEFFMCSYS");

   hparNom_before_p1->Write("hP1BEFORE");
   sysTot_before_p1->Write("hP1BEFORESYS");

   hparNom_before_p2->Write("hP2BEFORE");
   sysTot_before_p2->Write("hP2BEFORESYS");

   hparNom_before_p3->Write("hP3BEFORE");
   sysTot_before_p3->Write("hP3BEFORESYS");

   hparNom_after_p1->Write("hP1AFTER");
   sysTot_after_p1->Write("hP1AFTERSYS");

   hparNom_after_p2->Write("hP2AFTER");
   sysTot_after_p2->Write("hP2AFTERSYS");

   hparNom_after_p3->Write("hP3AFTER");
   sysTot_after_p3->Write("hP3AFTERSYS");
   
   fSF->Write();
   fSF->Close();
      
   gApplication->Terminate();
}

void makeTable(std::string fname,
	       std::string app,
	       int nb,
	       int nsys,
	       double sfnom[],
	       double sfup[][100],
	       double sfdown[][100],
	       double sfstat[],
	       double sfsystup[],
	       double sfsystdown[],
	       bool nativeSign,
	       bool singleRW,
	       bool printTotSys)
{
   std::ofstream fsf(fname.c_str());

   if( app != "TTBAR" )
     {	   
	std::string header = "";
	
	if( singleRW )
	  header = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|} \n
\\hline";
	else
	  header = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|} \n
\\hline";
   
	fsf << header << std::endl;
   
	std::string linh = "";
	
	if( singleRW )
	  linh = 
	  "$P_{T} [GeV]$ & SF & Stat & $RW$ \
& Pileup & Gluon splitting & b-frag & $D \\to \\mu X$ \
& c-frag & $K_{S}^{0} (\\Lambda)$ & $N_{trk}^{gen}$ & JES & JER & $C_{b}$ & Syst \\\\ \\hline";
	else
	  linh = 
	  "$P_{T} [GeV]$ & SF & Stat & $N_{trk}$ & $N_{jets}$ \
& $P_{T} (\\mu)$ & $\\eta (jet)$ & Pileup & Gluon splitting & b-frag & $D \\to \\mu X$ \
& c-frag & $K_{S}^{0} (\\Lambda)$ & $N_{trk}^{gen}$ & JES & JER & $C_{b}$ & Add & Syst \\\\ \\hline";

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
	     if( i == 14 ) ptbin = "500-670";
	     if( i == 15 ) ptbin = "670-1000";
	
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
		       if( nativeSign )
			 {
			    std::string signup = "+";
			    if( sfup[i][j] < 0. ) signup = "-";
			    std::string signdown = "+";
			    if( sfdown[i][j] < 0. ) signdown = "-";
			    lin += 
			      signup+std::string(Form("%.3f",fabs(sfup[i][j])))+" "+
			      signdown+std::string(Form("%.3f",fabs(sfdown[i][j])));
			 }		       
		       else
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

	     lin += "$\\pm$ XXX"+std::string(Form("%d",i))+"XXX";
	     lin += " & ";

	     if( printTotSys )
	       {		  
		  lin += "+"+
		    std::string(Form("%.3f",sfsystup[i]))+" -"+
		    std::string(Form("%.3f",sfsystdown[i]));
		  lin += " \\\\ ";
	       }	     
	     else
	       {		  
		  lin += "+YYY"+std::string(Form("%d",i))+"YYY -ZZZ"+std::string(Form("%d",i))+"ZZZ";
		  lin += " \\\\ ";
	       }	     
	     
	     fsf << lin << std::endl;
	  }   

	std::string footer = "\\hline \n
\\end{tabular}";
   
	fsf << footer << std::endl;
     }

   else
     {
	std::string header = "";
	
	if( singleRW )
	  header = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|} \n
\\hline";
	else
	  header = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|} \n
\\hline";
   
	fsf << header << std::endl;
   
	std::string linh = "";
	
	if( singleRW )
	  linh =
	  "$P_{T} [GeV]$ & SF & Stat & $N_{trk}$ \
& Pileup & b-frag \
& JES & JER & $C_{b}$ & Syst \\\\ \\hline";
	else
	  linh =
	  "$P_{T} [GeV]$ & SF & Stat & $N_{trk}$ & $N_{jets}$ \
& $P_{T} (\\mu)$ & $\\eta (jet)$ & Pileup & b-frag \
& JES & JER & $C_{b}$ & Add & Syst \\\\ \\hline";

	fsf << linh << std::endl;
   
	for(int i=0;i<nb;i++)
	  {
	     std::string ptbin = "";
	     if( i == 0 ) ptbin = "30-50";
	     if( i == 1 ) ptbin = "50-80";
	     if( i == 2 ) ptbin = "80-120";
	     if( i == 3 ) ptbin = "120-210";
	     if( i == 4 ) ptbin = "210-320";
	
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
		       if( nativeSign )
			 {			    
			    std::string signup = "+";
			    if( sfup[i][j] < 0. ) signup = "-";
			    std::string signdown = "+";
			    if( sfdown[i][j] < 0. ) signdown = "-";
			    lin += 
			      signup+std::string(Form("%.3f",fabs(sfup[i][j])))+" "+
			      signdown+std::string(Form("%.3f",fabs(sfdown[i][j])));
			 }		       
		       else
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
     }
   
   fsf.close();
}
