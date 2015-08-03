#include "../include/Hist.h"
#include "../include/Ranges.h"

LTANA::Hist::Hist()
{
}

LTANA::Hist::~Hist()
{
}

void LTANA::Hist::init()
{
   rnd = new TRandom3(666);
   
   std::string foutName = std::string(foutname)+".root";

   _fout = new TFile(foutName.c_str(),"RECREATE");

   TFile *fPileup = TFile::Open("/home-pbs/kskovpen/bTagRun2/CMSSW_7_4_6_patch6/src/LTAnalysis/test/macros/npv.root");
   _h_pileup = (TH1D*)fPileup->Get("h_npv");
   
   _fout->cd();
   
   muptcut = 5.;

//   name_rw.push_back("1d_pt");
//   name_rw.push_back("1d_nseltrk");
//   name_rw.push_back("1d_njet");
//   name_rw.push_back("1d_mupt");
//   name_rw.push_back("1d_eta");
   
//   name_rw_2d.push_back("2d_pt_vs_jeta");
   
   hname.clear();
   hname_2d.clear();

   int nbins = 100;

   histNameDefined_jet[0] = "h_j1_pt_";
   histNameDefined_jet[1] = "h_j1_nseltrk_";
   histNameDefined_jet[2] = "h_j1_eta_";
   histNameDefined_jet[3] = "h_j1_ntrk_";
   histNameDefined_jet[4] = "h_j1_njet_";
   histNameDefined_jet[5] = "h_j1_nsv_";
   histNameDefined_jet[6] = "h_j1_mupt_";
   histNameDefined_jet[7] = "h_j1_JP_";
   histNameDefined_jet[8] = "h_pthat_";
   histNameDefined_jet[9] = "h_npv_";
   histNameDefined_jet[10] = "h_j1_CSVIVF_";
   histNameDefined_jet[11] = "h_j1_muPtRel_";
   histNameDefined_jet[12] = "h_j1_ntrkGen_";

   hist_jet.push_back(HIST_J1_PT);
   hist_jet.push_back(HIST_J1_NSELTRK);
   hist_jet.push_back(HIST_J1_ETA);
   hist_jet.push_back(HIST_J1_NTRK);
   hist_jet.push_back(HIST_J1_NJET);
   hist_jet.push_back(HIST_J1_NSV);
   hist_jet.push_back(HIST_J1_MUPT);
   hist_jet.push_back(HIST_J1_JP);
/*   hist_jet.push_back(HIST_PTHAT);
   hist_jet.push_back(HIST_NPV);
   hist_jet.push_back(HIST_J1_CSVIVF);
   hist_jet.push_back(HIST_J1_MUPTREL);
   hist_jet.push_back(HIST_J1_NTRKGEN);*/
   
   hist_jet_n = hist_jet.size();
   for(int ih=0;ih<hist_jet_n;ih++)
     {
	int idx = hist_jet[ih];
	histName_jet[ih] = histNameDefined_jet[idx];
     }   

   histNameDefined_jet_2d[0] = "h_j1_pt_vs_jeta_";
   
//   hist_jet_2d.push_back(HIST_2D_J1_PT_VS_JETA);

   hist_jet_2d_n = hist_jet_2d.size();
   for(int ih=0;ih<hist_jet_2d_n;ih++)
     {
	int idx = hist_jet_2d[ih];
	histName_jet_2d[ih] = histNameDefined_jet_2d[idx];
     }   
   
   sel.push_back("nosel");
/*   sel.push_back("pt20t30");
   sel.push_back("pt30t40");
   sel.push_back("pt40t50");
   sel.push_back("pt50t60");
   sel.push_back("pt60t70");
   sel.push_back("pt70t80");
   sel.push_back("pt80t100");
   sel.push_back("pt100t120");
   sel.push_back("pt120t160");
   sel.push_back("pt160t210");
   sel.push_back("pt210t260");
   sel.push_back("pt260t320");
   sel.push_back("pt320t400");
   sel.push_back("pt400t500");
   sel.push_back("pt500t670");
   sel.push_back("pt670t1000");*/
   sel.push_back("pt20t30");
   sel.push_back("pt30t50");
   sel.push_back("pt50t70");
   sel.push_back("pt70t100");
   sel.push_back("pt100t140");
   sel.push_back("pt140t200");
   sel.push_back("pt200t300");
   sel.push_back("pt300t670");
   sel.push_back("pt670t1000");
   sel_n = sel.size();

/*   jPtMin.push_back(20); jPtMax.push_back(30);
   jPtMin.push_back(30); jPtMax.push_back(40);
   jPtMin.push_back(40); jPtMax.push_back(50);
   jPtMin.push_back(50); jPtMax.push_back(60);
   jPtMin.push_back(60); jPtMax.push_back(70);
   jPtMin.push_back(70); jPtMax.push_back(80);
   jPtMin.push_back(80); jPtMax.push_back(100);
   jPtMin.push_back(100); jPtMax.push_back(120);
   jPtMin.push_back(120); jPtMax.push_back(160);
   jPtMin.push_back(160); jPtMax.push_back(210);
   jPtMin.push_back(210); jPtMax.push_back(260);
   jPtMin.push_back(260); jPtMax.push_back(320);
   jPtMin.push_back(320); jPtMax.push_back(400);
   jPtMin.push_back(400); jPtMax.push_back(500);
   jPtMin.push_back(500); jPtMax.push_back(670);
   jPtMin.push_back(670); jPtMax.push_back(1000);*/

   jPtMin.push_back(20); jPtMax.push_back(30);
   jPtMin.push_back(30); jPtMax.push_back(50);
   jPtMin.push_back(50); jPtMax.push_back(70);
   jPtMin.push_back(70); jPtMax.push_back(100);
   jPtMin.push_back(100); jPtMax.push_back(140);
   jPtMin.push_back(140); jPtMax.push_back(200);
   jPtMin.push_back(200); jPtMax.push_back(300);
   jPtMin.push_back(300); jPtMax.push_back(670);
   jPtMin.push_back(670); jPtMax.push_back(1000);
   
   eta_n = 1;
   eta[0] = "nosel";

   selbNameDefined[0] = "nosel";
   selbNameDefined[1] = "CSVL";
   selbNameDefined[2] = "CSVM";
   selbNameDefined[3] = "CSVT";
   selbNameDefined[4] = "TCHPL";
   selbNameDefined[5] = "TCHPM";
   selbNameDefined[6] = "TCHPT";
   selbNameDefined[7] = "UNTAGCSVL";
   selbNameDefined[8] = "UNTAGCSVM";
   selbNameDefined[9] = "UNTAGCSVT";
   
   selb.push_back(BTAG_NONE);
   selb.push_back(BTAG_CSVL);
//   selb.push_back(BTAG_CSVM);
//   selb.push_back(BTAG_CSVT);
   selb.push_back(BTAG_UNTAGCSVL);
//   selb.push_back(BTAG_UNTAGCSVM);
//   selb.push_back(BTAG_UNTAGCSVT);
   selb_n = selb.size();

   for(int isb=0;isb<selb_n;isb++)
     {
	int idx = selb[isb];
	selbName.push_back(selbNameDefined[idx]);
     }   
   
   seladd_n = 1;
   seladd[0] = "";
   
   flav_n = 4;
   flav[0] = "ajet";
   flav[1] = "bjet";
   flav[2] = "cjet";
   flav[3] = "ljet";

   // Init systematics
   syst = new LTANA::Syst();
   syst->init();
   
   // systematics to include
   sys.push_back(SYS_NONE);
/*   sys.push_back(SYS_PU_UP);
   sys.push_back(SYS_PU_DOWN);
   sys.push_back(SYS_GSPLIT_UP);
   sys.push_back(SYS_GSPLIT_DOWN);
   sys.push_back(SYS_BFRAG_UP);
   sys.push_back(SYS_BFRAG_DOWN);
   sys.push_back(SYS_CDFRAG_UP);
   sys.push_back(SYS_CDFRAG_DOWN);
   sys.push_back(SYS_CFRAG_UP);
   sys.push_back(SYS_CFRAG_DOWN);
   sys.push_back(SYS_KSL_UP);
   sys.push_back(SYS_KSL_DOWN);
   sys.push_back(SYS_NTRKGEN_UP);
   sys.push_back(SYS_NTRKGEN_DOWN);
   sys.push_back(SYS_JES_UP);
   sys.push_back(SYS_JES_DOWN);
   sys.push_back(SYS_JER_UP);
   sys.push_back(SYS_JER_DOWN);*/

   sys_n = sys.size();
  
   for(int is=0;is<sys_n;is++)
     {
	int idx = sys[is];
	if( sys[is] >= 1000 )
	  {	     
	     idx = idx/1000;
	     sysName[is] = syst->sysNameDown()[idx];
	  }	
	else
	  {
	     sysName[is] = syst->sysNameUp()[idx];
	  }
     }   

   _s_Jet = new std::vector<std::pair<std::vector<std::string>,double*> >();
   _m1d_Jet = new std::map<std::string, TH1D*>();

   _s2_Jet = new std::vector<std::pair<std::vector<std::string>,double*> >();
   _m2d_Jet = new std::map<std::string, TH2D*>();
   
   std::string titl;
   
   for(int j=0;j<flav_n;j++)
     {	
	for(int ss=0;ss<sel_n;ss++)
	  {
	     for(int se=0;se<eta_n;se++)
	       {
		  for(int ssb=0;ssb<selb_n;ssb++)
		    {
		       for(int ssa=0;ssa<seladd_n;ssa++)
			 {
			    for(int h=0;h<hist_jet_n;h++)
			      {
				 std::string hn = histName_jet[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selbName[ssb]+seladd[ssa];
				 hname.push_back(hn);
				 
				 for(int s=0;s<sys_n;s++)
				   {
				      titl = hn+sysName[s];
				      std::vector<std::string> names;
				      names.clear();
				      names.push_back(titl);
				      names.push_back(sysName[s]);
				      
				      int histId = hist_jet[h];
				      
				      if( histId == HIST_J1_PT ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_pt));
				      else if( histId == HIST_J1_NSELTRK ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_nseltrk));
				      else if( histId == HIST_J1_ETA ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_eta));
				      else if( histId == HIST_J1_NTRK ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_ntrk));
				      else if( histId == HIST_J1_NJET ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_njet));
				      else if( histId == HIST_J1_NSV ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_nsv));
				      else if( histId == HIST_J1_MUPT ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_mupt[ss]));
				      else if( histId == HIST_PTHAT ) _s_Jet->push_back(std::make_pair(names,RANGE::set_pthat));
				      else if( histId == HIST_NPV ) _s_Jet->push_back(std::make_pair(names,RANGE::set_npv));
				      else if( histId == HIST_J1_CSVIVF ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_CSVIVF));
				      else if( histId == HIST_J1_MUPTREL ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_muptrel));
				      else if( histId == HIST_J1_NTRKGEN ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_ntrkgen));
				      else if( histId == HIST_J1_JP )
					{
/*					   if( selb[ssb] == BTAG_NONE ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_nosel[ss]));
					   else if( selb[ssb] == BTAG_CSVL ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVL[ss]));
					   else if( selb[ssb] == BTAG_CSVM ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVM[ss]));
					   else if( selb[ssb] == BTAG_CSVT ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVT[ss]));
					   else if( selb[ssb] == BTAG_TCHPT ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_TCHPT[ss]));
					   else _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_nosel[ss]));*/
					   _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_COMMON[ss]));
					}
				      else
					{
					   std::cout << "Range settings are not known for " << histName_jet[h] << std::endl;
					   exit(1);
					}
				   }				 
			      }
			    
			    for(int h=0;h<hist_jet_2d_n;h++)
			      {
				 std::string hn = histName_jet_2d[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selbName[ssb]+seladd[ssa];
				 hname_2d.push_back(hn);
				 
				 for(int s=0;s<sys_n;s++)
				   {
				      titl = hn+sysName[s];
				      std::vector<std::string> names;
				      names.clear();
				      names.push_back(titl);
				      names.push_back(sysName[s]);
				      
				      int histId = hist_jet_2d[h];
				      
				      if( histId == HIST_2D_J1_PT_VS_JETA ) _s2_Jet->push_back(std::make_pair(names,RANGE::set_j_2d_pt_vs_jeta[ss]));
				      else
					{
					   std::cout << "Range settings are not known for " << histName_jet_2d[h] << std::endl;
					   exit(1);
					}
				   }				 
			      }			    
			 }
		    }		  
	       }
	  }
     }   
   
   for(int i=0;i<_s_Jet->size();i++)
     {
	TH1D *_h1d = new TH1D(_s_Jet->at(i).first.at(0).c_str(),
			      _s_Jet->at(i).first.at(0).c_str(),
			      _s_Jet->at(i).second[0],
			      _s_Jet->at(i).second[1],
			      _s_Jet->at(i).second[2]);
	
	_h1d->Sumw2();
	
	_m1d_Jet->insert(std::pair<std::string,TH1D*>(_s_Jet->at(i).first.at(0),_h1d));
     }

   for(int i=0;i<_s2_Jet->size();i++)
     {
	TH2D *_h2d = new TH2D(_s2_Jet->at(i).first.at(0).c_str(),
			      _s2_Jet->at(i).first.at(0).c_str(),
			      _s2_Jet->at(i).second[0],
			      _s2_Jet->at(i).second[1],
			      _s2_Jet->at(i).second[2],
			      _s2_Jet->at(i).second[3],
			      _s2_Jet->at(i).second[4],
			      _s2_Jet->at(i).second[5]);
	
	_h2d->Sumw2();
	
	_m2d_Jet->insert(std::pair<std::string,TH2D*>(_s2_Jet->at(i).first.at(0),_h2d));
     }
   
   if( !isdata )
     {	
	rw = new LTANA::Reweight();
	rw->init(doRW,jPtMin,jPtMax,sel,selbName,name_rw,name_rw_2d);
     }   

   for(int j=0;j<flav_n;j++)
     {	
	for(int ss=0;ss<sel_n;ss++)
	  {
	     for(int se=0;se<eta_n;se++)
	       {   
		  for(int ssb=0;ssb<selb_n;ssb++)
		    {
		       for(int ssa=0;ssa<seladd_n;ssa++)
			 {
			    for(int s=0;s<sys_n;s++)
			      {
				 for(int h=0;h<hist_jet_n;h++)
				   {
				      histNAMES[j][ss][se][ssb][ssa][h][s] =
					histName_jet[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selbName[ssb]+seladd[ssa]+sysName[s];
				   }

				 for(int h=0;h<hist_jet_2d_n;h++)
				   {
				      histNAMES_2d[j][ss][se][ssb][ssa][h][s] =
					histName_jet_2d[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selbName[ssb]+seladd[ssa]+sysName[s];
				   }
			      }			    
			 }		       
		    }		  
	       }
	  }
     }

   std::cout << "Initialisation done" << std::endl;
}

void LTANA::Hist::fill()
{
   float pthat = ntP->pthat;

   double ran = rnd->Rndm();
   
   double w = 1.;
   
   if( !isdata )
     {
	w = noe/(xsec*eff);
	double ILexp = 40.;
	w = ILexp/w;
     }   
   
   float mc_weight = ntP->mcweight;
   if( !isdata ) w *= mc_weight;
   
   int npu = ntP->nPU;
   int npv = ntP->nPV;
   if( npu > 34 ) npu = 34;

//   int jmax = 0; // highest-Pt jet
   int jmax = -1; // all jets
      
//   int jidx = 0; // only the highest-Pt jet
   int jidx = -1; // all jets

   // Event
   
   if( ntP->nPFMuon == 0 ) return;

   int ntNJET = ntP->nJet;

   // 'overcut' for trigger selection
   int nJet20 = 0;
   for( int ij=0;ij<ntNJET;ij++ )
     {
	if( ntP->Jet_pt[ij] > 20. ) nJet20++;
     }	
   if( nJet20 < 2 ) return;
   
/*   bool filterPTHAT = false;
   bool filterNJET = false;
   bool filterPT = false;
   if( pthat > 0 && pthat < 170. )
     {
	for( int ij=0;ij<ntNJET;ij++ )
	  {
	     if ( ntP->Jet_pt[ij] > pthat * 7. ) filterPTHAT = true;
	  }	
     }   
   if( ntNJET > 15 ) filterNJET = true;
   for( int ij=0;ij<ntNJET;ij++ )
     {
	if( ntP->Jet_pt[ij] > 1600. ) filterPT = true;
     }   
   if( filterPTHAT || filterNJET || filterPT ) return;*/
   
   // Trigger
   
   bool passTrigJet20 = passTrig(35);
   bool passTrigJet40 = passTrig(41);
   bool passTrigJet70 = passTrig(44);
   bool passTrigJet110 = passTrig(47);
   bool passTrigJet300 = passTrig(50);
   
   int bitIdx;
   int trigIdx;
   
   int njet20 = 0, njet40 = 0, njet70 = 0,
     njet110 = 0, njet300 = 0;
   
   for(int ij=0;ij<ntNJET;ij++)
     {
	float jpt = ntP->Jet_pt[ij];
	float jeta = fabs(ntP->Jet_eta[ij]);

	if( jeta > 2.4 ) continue;
	
	if( jpt > 20. && jpt <= 50. )  njet20++;
	if( jpt > 50. && jpt <= 80. )  njet40++;
	if( jpt > 80. && jpt <= 120. )  njet70++;
	if( jpt > 120. && jpt <= 320. ) njet110++;
	if( jpt > 320. ) njet300++;
     }      
   if( njet20 == 0 ) passTrigJet20 = false;
   if( njet40 == 0 ) passTrigJet40 = false;
   if( njet70 == 0 ) passTrigJet70 = false;
   if( njet110 == 0 ) passTrigJet110 = false;
   if( njet300 == 0 ) passTrigJet300 = false;
   
   if( !passTrigJet20 &&
       !passTrigJet40 &&
       !passTrigJet70 &&
       !passTrigJet110 &&
       !passTrigJet300 ) return;
   
   // Loop on jets
   
   int nJetMax = (jmax >= 0 && ntNJET >= jmax) ? jmax+1 : ntNJET;

   for(int ij=0;ij<nJetMax;ij++)
     {
	if( ij != jidx && jidx >= 0 ) continue;

	if( ntP->Jet_Proba[ij] == 0 ) continue;

	float jptTR = ntP->Jet_pt[ij];
	float jetaTR = fabs(ntP->Jet_eta[ij]);

	if( jetaTR > 2.4 ) continue;

//	if( jptTR > 20. && !passTrigJet20 ) continue;
	
//	if( jptTR > 20. && jptTR <= 50. && !passTrigJet20 ) continue;
//	else if( jptTR > 50. && jptTR <= 80. && !passTrigJet40 ) continue;
//	else if( jptTR > 80. && jptTR <= 120. && !passTrigJet70 ) continue;
//	else if( jptTR > 120. && jptTR <= 320. && !passTrigJet110 ) continue;
//	else if( jptTR > 320. && !passTrigJet300 ) continue;

	// FIXME
/*	int nAwayTag = 0;
	for(int ijj=0;ijj<nJetMax;ijj++)	  
	  {
	     if( ijj == ij ) continue;
	     float jbtCombIVF = ntP->Jet_CombIVF[ijj];
	     if( jbtCombIVF >= 0.605 ) nAwayTag++;
//	     if( jbtCombIVF >= 0.890 ) nAwayTag++;
//	     if( jbtCombIVF >= 0.970 ) nAwayTag++;
	  }
	if( nAwayTag == 0 ) continue;*/

	Jet_Proba_New = ntP->Jet_Proba[ij];
	if( Jet_Proba_New == 0. ) Jet_Proba_New = -666.;

	v_mu = new TLorentzVector(0,0,0,0);

	int jFlavour = ntP->Jet_flavour[ij];
	if( jFlavour >= 1 && jFlavour <= 3 ) jFlavour = 1;
	
	std::string flavch = "NOTFOUND";
	int flavchI = 0;
	if( jFlavour == 5 )  {flavch = "bjet"; flavchI = 1;}
	if( jFlavour == 4 )  {flavch = "cjet"; flavchI = 2;}
	if( jFlavour == 1 || jFlavour == 21 )  {flavch = "ljet"; flavchI = 3;}

	std::string selch = "NOTFOUND";
	std::string etach = "NOTFOUND";
	std::string selbch = "NOTFOUND";
	
	syst->JEC(ij);

	v_jet = syst->v_jet();
	
	bool passSel = true;
	
	float jeta = ntP->Jet_eta[ij];
	float jphi = ntP->Jet_phi[ij];
	float jm = ntP->Jet_mass[ij];
//	float residual = 1.;
//	if( ntP->Run > 0 ) residual = ntP->Jet_residual[ij];
//	float jpt = ntP->Jet_pt[ij] * residual;

	float jpt = ntP->Jet_pt[ij];
	
	if( jpt < 20. || jpt > 1500. ) passSel = false;
	if( fabs(jeta) > 2.4 ) passSel = false;
	
	int njet = ntNJET;
	
	int nsv = ntP->nSV;
	int nsvj = ntP->Jet_nLastSV[ij];
	
	int ntrk = ntP->Jet_ntracks[ij];
	int nseltrk = ntP->Jet_nseltracks[ij];

	muidx.clear();

	for(int imu=0;imu<ntP->nPFMuon;imu++)
	  {
	     if( ntP->PFMuon_IdxJet[imu] == ij )
	       {	     
		  if( ntP->PFMuon_isGlobal[imu] == 0 ) continue;
		  if( ntP->PFMuon_pt[imu] < muptcut ) continue;
		  if( ntP->PFMuon_nMuHit[imu] == 0 ) continue;
		  if( ntP->PFMuon_nTkHit[imu] < 11 ) continue;
		  if( ntP->PFMuon_nPixHit[imu] < 2 ) continue;
		  if( ntP->PFMuon_nOutHit[imu] > 2 ) continue;
		  if( ntP->PFMuon_nMatched[imu] < 2 ) continue;
		  if( ntP->PFMuon_chi2[imu] > 10. ) continue;
		  if( ntP->PFMuon_chi2Tk[imu] > 10. ) continue;
		  if( fabs(ntP->PFMuon_eta[imu]) > 2.4 ) continue;
		  muidx.push_back(imu);
	       }
	  }
	bool passMuonInJet = (muidx.size() > 0);
   
	float drjmu = -666;
	if( passMuonInJet )
	  {
	     for(int im=0;im<muidx.size();im++)
	       {		  
		  float mupt = ntP->PFMuon_pt[muidx[im]];
		  float mueta = ntP->PFMuon_eta[muidx[im]];
		  float muphi = ntP->PFMuon_phi[muidx[im]];
		  float mum = 0.10566;
		  v_mu->SetPtEtaPhiM(mupt,mueta,muphi,mum);
		  drjmu = v_jet->DeltaR(*v_mu);
		  if( drjmu < 0.4 ) break;
	       }	     
	  }	
	
	if( drjmu > 0.4 || drjmu < 0 ) passSel = false;
	
	// END SELECTION
	
	if( passSel )
	  {
	     float jbtCombSvx = ntP->Jet_CombSvx[ij];
	     float jbtCombIVF = ntP->Jet_CombIVF[ij];
	     float jbtTCHP = ntP->Jet_Ip3P[ij];

	     std::vector<bool> selbch_res;
	     for(int ibt=0;ibt<selb_n;ibt++) 
	       {
		  if( selb[ibt] == BTAG_NONE ) selbch_res.push_back(1);
		  else
		    {		       
		       bool passBTAG = (
					(selb[ibt] == BTAG_CSVL && jbtCombIVF >= 0.605) ||
					(selb[ibt] == BTAG_CSVM && jbtCombIVF >= 0.890) ||
					(selb[ibt] == BTAG_CSVT && jbtCombIVF >= 0.970) ||
					(selb[ibt] == BTAG_UNTAGCSVL && jbtCombIVF < 0.605) ||
					(selb[ibt] == BTAG_UNTAGCSVM && jbtCombIVF < 0.890) ||
					(selb[ibt] == BTAG_UNTAGCSVT && jbtCombIVF < 0.970)
					);
		       if( passBTAG ) selbch_res.push_back(1);
		       else selbch_res.push_back(0);
		    }
	       }	     
	     
	     bool selach_res[seladd_n];
	     for( int ibt=0;ibt<seladd_n;ibt++ ) selach_res[ibt] = false;

	     selach_res[0] = true;
	     
	     for(int isys=0;isys<sys_n;isys++)
	       {	
		  float jPT = getPt(sys[isys]);
		  
		  float sfj = w;
		  
		  // l-jets are underestimated in MC by 1.27
//		  if( flavchI == 3 ) sfj *= 1.27;
		  
		  // additional scaling to study the effect on SF
//		  if( flavchI == 1 ) sfj *= 0.80;
//		  if( flavchI == 1 ) sfj *= 1.20;
//		  if( flavchI == 2 ) sfj *= 0.80;
//		  if( flavchI == 2 ) sfj *= 1.20;
//		  if( flavchI == 3 ) sfj *= 0.80;
//		  if( flavchI == 3 ) sfj *= 1.20;
		  
		  // pileup reweighting sys
		  sfj *= syst->Pileup(npv,sys[isys],_h_pileup);
//		  sfj *= syst->Pileup(npu,sys[isys]);

		  // gluon splitting sys
		  sfj *= syst->GluonSplitting(ij,flavchI,sys[isys]);
		  
		  // b fragmentation sys
		  sfj *= syst->bFrag(ij,flavchI,sys[isys]);
		  
		  // c->D fragmentation sys
		  sfj *= syst->cdFrag(ij,flavchI,sys[isys]);
		  
		  // c fragmentation sys
		  sfj *= syst->cFrag(ij,flavchI,sys[isys]);
		  
		  // K0s Lambda sys
		  sfj *= syst->Ks(ij,flavchI,sys[isys]);
		  
		  // generated ntrk in b- and c- hadron decays sys
		  sfj *= syst->GenNTrk(ij,flavchI,sys[isys]);

		  float mupt = -1.;
		  if( muidx.size() > 0 )
		    mupt = ntP->PFMuon_pt[muidx[0]];
		  
		  int jPtBin = 0;   

/*		  if( jPT >= jPtMin[0] && jPT <= jPtMax[0] )   {selch = "pt20t30"; jPtBin = 1;}
		  if( jPT > jPtMin[1] && jPT <= jPtMax[1] )   {selch = "pt30t40"; jPtBin = 2;}
		  if( jPT > jPtMin[2] && jPT <= jPtMax[2] )   {selch = "pt40t50"; jPtBin = 3;}
		  if( jPT > jPtMin[3] && jPT <= jPtMax[3] )   {selch = "pt50t60"; jPtBin = 4;}
		  if( jPT > jPtMin[4] && jPT <= jPtMax[4] )   {selch = "pt60t70"; jPtBin = 5;}
		  if( jPT > jPtMin[5] && jPT <= jPtMax[5] )   {selch = "pt70t80"; jPtBin = 6;}
		  if( jPT > jPtMin[6] && jPT <= jPtMax[6] )   {selch = "pt80t100"; jPtBin = 7;}
		  if( jPT > jPtMin[7] && jPT <= jPtMax[7] )  {selch = "pt100t120"; jPtBin = 8;}
		  if( jPT > jPtMin[8] && jPT <= jPtMax[8] )  {selch = "pt120t160"; jPtBin = 9;}
		  if( jPT > jPtMin[9] && jPT <= jPtMax[9] )  {selch = "pt160t210"; jPtBin = 10;}
		  if( jPT > jPtMin[10] && jPT <= jPtMax[10] )  {selch = "pt210t260"; jPtBin = 11;}
		  if( jPT > jPtMin[11] && jPT <= jPtMax[11] )  {selch = "pt260t320"; jPtBin = 12;}
		  if( jPT > jPtMin[12] && jPT <= jPtMax[12] )  {selch = "pt320t400"; jPtBin = 13;}
		  if( jPT > jPtMin[13] && jPT <= jPtMax[13] )  {selch = "pt400t500"; jPtBin = 14;}
		  if( jPT > jPtMin[14] )  {selch = "pt500t670"; jPtBin = 15;}*/

		  if( jPT >= jPtMin[0] && jPT <= jPtMax[0] )   {selch = "pt20t30"; jPtBin = 1;}
		  if( jPT > jPtMin[1] && jPT <= jPtMax[1] )   {selch = "pt30t50"; jPtBin = 2;}
		  if( jPT > jPtMin[2] && jPT <= jPtMax[2] )  {selch = "pt50t70"; jPtBin = 3;}
		  if( jPT > jPtMin[3] && jPT <= jPtMax[3] )  {selch = "pt70t100"; jPtBin = 4;}
		  if( jPT > jPtMin[4] && jPT <= jPtMax[4] )  {selch = "pt100t140"; jPtBin = 5;}
		  if( jPT > jPtMin[5] && jPT <= jPtMax[5] )  {selch = "pt140t200"; jPtBin = 6;}
		  if( jPT > jPtMin[6] && jPT <= jPtMax[6] )  {selch = "pt200t300"; jPtBin = 7;}
		  if( jPT > jPtMin[7] )  {selch = "pt300t670"; jPtBin = 8;}
		  
		  double jPtMinCur = 0.;
		  double jPtMaxCur = 1250.;
		  
		  if( jPtBin > 0 )
		    {		       
		       jPtMinCur = jPtMin[jPtBin-1];
		       jPtMaxCur = jPtMax[jPtBin-1];
		    }		  
		  
		  bool jeta_res[eta_n];
		  for( int ibt=0;ibt<eta_n;ibt++ ) jeta_res[ibt] = false;
		  		  
		  jeta_res[0] = true;

		  // 1d
		  std::vector<std::string> histNAMESSEL;
		  std::vector<float> sfJ;
		  std::vector<int> histSYS;
		  std::vector<int> histVAR;

		  for(int ih=0;ih<hist_jet_n;ih++)
		    {
		       for(int ihb=0;ihb<selb_n;ihb++)
			 {
			    if( !selbch_res[ihb] ) continue;
			    
			    float sfjj = sfj;

			    if( !isdata ) 
			      {
				 rw->apply(&sfjj,ihb,jPtBin,ntrk,nseltrk,njet,nsv,mupt,jeta,jPT);
			      }			    

			    for(int iha=0;iha<seladd_n;iha++)
			      {
				 if( !selach_res[iha] ) continue;
			    
				 for(int ihe=0;ihe<eta_n;ihe++)
				   {
				      if( !jeta_res[ihe] ) continue;
				      
				      histNAMESSEL.push_back(histNAMES[flavchI][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL.push_back(histNAMES[0][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL.push_back(histNAMES[flavchI][0][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL.push_back(histNAMES[0][0][ihe][ihb][iha][ih][isys]);
				      sfJ.push_back(sfjj);
				      histSYS.push_back(isys);
				      histVAR.push_back(ih);
				   }
			      }
			 }		       
		    }
		  
		  int nHISTSEL = histNAMESSEL.size();
		  for(int ih=0;ih<nHISTSEL;ih++)
		    {		       
		       TH1D *h = _m1d_Jet->find(histNAMESSEL.at(ih))->second;

		       int hidx = int(ih/4);
		       fillThis = true;
		       float var;
		       std::vector<float> varv;
		       bool single = 1;
		       int varId = hist_jet[histVAR[hidx]];
/*		       if( varId == HIST_J1_SVNTRK ||
			   varId == HIST_J1_SVMASS )
			 {			    
			    varv = getVarVec(sys[histSYS[hidx]],ij,varId,jPtBin);
			    single = 0;
			 }		       
		       else*/
			 var = getVar(sys[histSYS[hidx]],ij,varId,jPtBin);
		       
		       if( fillThis )
			 {
			    float sfc = sfJ[hidx];
			    
			    if( single ) 
			      {
				 h->Fill(var,sfc);
			      }
			    else 
			      {
				 int varvs = varv.size();
				 for(int iv=0;iv<varvs;iv++)
				   {
				      h->Fill(varv[iv],sfc);
				   }				 
			      }			    
			 }		       
		    }
		  
		  histNAMESSEL.clear();

		  // 2d
		  std::vector<std::string> histNAMESSEL_2d;
		  std::vector<float> sfJ_2d;
		  std::vector<int> histSYS_2d;
		  std::vector<int> histVAR_2d;

		  for(int ih=0;ih<hist_jet_2d_n;ih++)
		    {
		       for(int ihb=0;ihb<selb_n;ihb++)
			 {
			    if( !selbch_res[ihb] ) continue;
			    
			    float sfjj = sfj;

			    if( !isdata ) 
			      {
				 rw->apply(&sfjj,ihb,jPtBin,ntrk,nseltrk,njet,nsv,mupt,jeta,jPT);
			      }			    

			    for(int iha=0;iha<seladd_n;iha++)
			      {
				 if( !selach_res[iha] ) continue;
			    
				 for(int ihe=0;ihe<eta_n;ihe++)
				   {
				      if( !jeta_res[ihe] ) continue;
				      
				      histNAMESSEL_2d.push_back(histNAMES_2d[flavchI][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_2d.push_back(histNAMES_2d[0][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_2d.push_back(histNAMES_2d[flavchI][0][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_2d.push_back(histNAMES_2d[0][0][ihe][ihb][iha][ih][isys]);
				      sfJ_2d.push_back(sfjj);
				      histSYS_2d.push_back(isys);
				      histVAR_2d.push_back(ih);
				   }
			      }
			 }		       
		    }
		  
		  int nHISTSEL_2d = histNAMESSEL_2d.size();
		  for(int ih=0;ih<nHISTSEL_2d;ih++)
		    {		       
		       TH2D *h = _m2d_Jet->find(histNAMESSEL_2d.at(ih))->second;

		       int hidx = int(ih/4);
		       fillThis = true;
		       int varId = hist_jet_2d[histVAR_2d[hidx]];
		       std::vector<float> var = getVar2d(sys[histSYS_2d[hidx]],ij,varId,jPtBin);
		       float varX = var[0];
		       float varY = var[1];
		       
		       if( fillThis )
			 {
			    float sfc = sfJ_2d[hidx];
			    
			    h->Fill(varX,varY,sfc);
			 }		       
		    }
		  
		  histNAMESSEL_2d.clear();
	       }	     
	  }	
	
	syst->clear();
	
	delete v_mu;
     }   
}

void LTANA::Hist::close()
{
   _fout->Write();
   _fout->Close();
}

float LTANA::Hist::getVar(int isys,int ijet,int varId,int ibin)
{
   float var = -666;
   
   if( ijet <= ntP->nJet )
     {	   
	if( varId == HIST_J1_JP )
	  {
	     var = Jet_Proba_New;
	     if( var == 0. ) var = -666.;
	  }	     
/*	if( varId == HIST_J1_BJP )
	  {		  
	     var = ntP->Jet_Bprob[ijet];
	     if( var == 0. ) var = -666.;
	  }*/
/*	if( strcmp(varName.c_str(),"h_j1_pthat_") == 0 )
	  {		  
	     var = ntP->pthat/1000.;
	  }*/
	if( varId == HIST_J1_NTRK )
	  {		  
	     var = ntP->Jet_ntracks[ijet];
	  }	     
	if( varId == HIST_J1_NSELTRK )
	  {		  
	     var = ntP->Jet_nseltracks[ijet];
	  }	     
	if( varId == HIST_J1_ETA )
	  {		  
	     var = ntP->Jet_eta[ijet];
	  }	     
/*	if( strcmp(varName.c_str(),"h_j1_phi_") == 0 )
	  {		  
	     var = ntP->Jet_phi[ijet];
	  }*/
/*	if( strcmp(varName.c_str(),"h_j1_mass_") == 0 )
	  {		  
	     var = ntP->Jet_mass[ijet];
	  }*/
	if( varId == HIST_J1_MUPT )
	  {
	     if( muidx.size() > 0 )
	       var = ntP->PFMuon_pt[muidx[0]];
	     else fillThis = false;
	  }	     
	if( varId == HIST_J1_MUPTREL )
	  {
	     if( muidx.size() > 0 )
	       var = ntP->PFMuon_ptrel[muidx[0]];
	     else fillThis = false;
	  }
	if( varId == HIST_J1_NTRKGEN )
	  {
	     if( !isdata )
	       {		  
		  Helper *helper = new Helper();
		  int flav = ntP->Jet_flavour[ijet];
		  
		  int nChargedGen1_b = -1, nChargedGen2_b = -1;
		  
		  if( flav == 1 )
		    {
		       for( int k=0;k<ntP->nBHadrons;k++ )
			 {
			    if( ntP->BHadron_hasBdaughter[k] == 1 ) continue;
			    double dR = helper->DeltaR(ntP->BHadron_eta[k], 
						       ntP->BHadron_phi[k], 
						       ntP->Jet_eta[ijet],
						       ntP->Jet_phi[ijet]);
			    if( dR > 0.4 ) continue;
			    int k1 = ntP->BHadron_DHadron1[k];
			    int k2 = ntP->BHadron_DHadron2[k];
			    if( nChargedGen1_b >= 0 && nChargedGen2_b < 0 ) 
			      {
				 nChargedGen2_b  = ntP->BHadron_nCharged[k];
				 if( k1 >= 0 ) nChargedGen2_b += ntP->DHadron_nCharged[k1];
				 if( k2 >= 0 ) nChargedGen2_b += ntP->DHadron_nCharged[k2];
			      }
			    if( nChargedGen1_b < 0 ) 
			      {
				 nChargedGen1_b  = ntP->BHadron_nCharged[k];
				 if( k1 >= 0 ) nChargedGen1_b += ntP->DHadron_nCharged[k1];
				 if( k2 >= 0 ) nChargedGen1_b += ntP->DHadron_nCharged[k2];
			      }
			 }
		    }	     
		  
		  int nchgen1_b = nChargedGen1_b, nchgen2_b = nChargedGen2_b;
		  if( nchgen1_b > 19 ) nchgen1_b = 19;
		  if( nchgen2_b > 19 ) nchgen2_b = 19;
	     
		  var = nchgen1_b;
		  delete helper;
	       }	     
	  }
/*	if( strcmp(varName.c_str(),"h_j1_mueta_") == 0 )
	  {
	     if( muidx.size() > 0 )
	       var = ntP->Muon_eta[muidx[0]];
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_muphi_") == 0 )
	  {
	     if( muidx.size() > 0 )
	       var = ntP->Muon_phi[muidx[0]];
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_muptrel_") == 0 )
	  {
	     if( muidx.size() > 0 )
	       var = ntP->Muon_ptrel[muidx[0]];
	     else fillThis = false;
	  }*/
/*	if( varId == HIST_J1_NPV )
	  {
	     if( ijet == 0 )
	       var = ntP->nPV;
	     else fillThis = false;
	  }*/
/*	if( strcmp(varName.c_str(),"h_j1_npu_") == 0 )
	  {
	     if( ijet == 0 )
	       var = ntP->nPU;
	     else fillThis = false;
	  }*/
	if( varId == HIST_J1_NJET )
	  {
	     if( ijet == 0 )
	       var = ntP->nJet;
	     else fillThis = false;
	  }	     
/*	if( strcmp(varName.c_str(),"h_j1_nmuon_") == 0 )
	  {
	     if( ijet == 0 )
	       var = ntP->nMuon;
	     else fillThis = false;
	  }*/
	if( varId == HIST_J1_NSV )
	  {
	     if( ijet == 0 )
	       var = ntP->nSV;
	     else fillThis = false;
	  }	     
	if( varId == HIST_PTHAT )
	  {
	     if( ijet == 0 )
	       var = ntP->pthat;
	     else fillThis = false;
	  }	     
	if( varId == HIST_NPV )
	  {
	     if( ijet == 0 )
	       var = ntP->nPV;
	     else fillThis = false;
	  }	     
	if( varId == HIST_J1_CSVIVF )
	  {
	     var = ntP->Jet_CombIVF[ijet];
	  }	     
/*	if( strcmp(varName.c_str(),"h_j1_nsvj_") == 0 )
	  {
	     var = ntP->Jet_nLastSV[ijet];
	  }*/

	if( varId == HIST_J1_PT )
	  {	
	     double jptmax = 1250.;
	     double jptmin = 0.;
	     if( ibin > 0 ) 
	       {
		  jptmax = jPtMax[ibin-1];
		  jptmin = jPtMin[ibin-1];
	       }	     
	     
	     var = (getPt(isys)-jptmin)/(jptmax-jptmin);

//	     var = getPt(isys);
	  }
     }   

   return var;
}

std::vector<float> LTANA::Hist::getVar2d(int isys,int ijet,int varId,int ibin)
{
   float varX = -666;
   float varY = -666;
   
   if( ijet <= ntP->nJet )
     {	   
	if( varId == HIST_2D_J1_PT_VS_JETA )
	  {
	     double jptmax = 1250.;
	     double jptmin = 0.;
	     if( ibin > 0 ) 
	       {
		  jptmax = jPtMax[ibin-1];
		  jptmin = jPtMin[ibin-1];
	       }	     
	     
	     varX = ntP->Jet_eta[ijet];
	     varY = (getPt(isys)-jptmin)/(jptmax-jptmin);
	  }	     
     }   

   std::vector<float> var;
   var.push_back(varX);
   var.push_back(varY);
   
   return var;
}

std::vector<float> LTANA::Hist::getVarVec(int isys,int ijet,int varId,int ibin)
{
   std::vector<float> var;
   var.clear();

   if( ibin-1 < 0 ) return var;
   
   if( ijet <= ntP->nJet )
     {	   
/*	if( strcmp(varName.c_str(),"h_j1_svntrk_") == 0 )
	  {
	     if( ijet == 0 )
	       {
		  for(int isv=0;isv<ntP->nSV;isv++)
		    var.push_back(ntP->SV_nTrk[isv]);
	       }	     
	     else fillThis = false;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_svmass_") == 0 )
	  {
	     if( ijet == 0 )
	       {
		  for(int isv=0;isv<ntP->nSV;isv++)
		    var.push_back(ntP->SV_mass[isv]);
	       }	     
	     else fillThis = false;
	  }*/
     }   

   return var;
}

float LTANA::Hist::getPt(int isys)
{
   float var = -666;
   
   if( (isys == SYS_NONE ||
	isys == SYS_PU_UP || isys == SYS_PU_DOWN ||
	isys == SYS_GSPLIT_UP || isys == SYS_GSPLIT_DOWN ||
	isys == SYS_BFRAG_UP || isys == SYS_BFRAG_DOWN ||
	isys == SYS_CDFRAG_UP || isys == SYS_CDFRAG_DOWN ||
	isys == SYS_CFRAG_UP || isys == SYS_CFRAG_DOWN ||
	isys == SYS_KSL_UP || isys == SYS_KSL_DOWN ||
	isys == SYS_NTRKGEN_UP || isys == SYS_NTRKGEN_DOWN
       )
       ||
       isdata )
     {
	var = syst->v_jet()->Pt();
     }
   else if( isys == SYS_JES_UP )
     {
	var = syst->v_jet_sys_jesTotalUp()->Pt();
     }   
   else if( isys == SYS_JES_DOWN )
     {
	var = syst->v_jet_sys_jesTotalDown()->Pt();
     }   
   else if( isys == SYS_JER_UP )
     {
	var = syst->v_jet_sys_jerTotalUp()->Pt();
     }   
   else if( isys == SYS_JER_DOWN )
     {
	var = syst->v_jet_sys_jerTotalDown()->Pt();
     }   

   return var;
}

bool LTANA::Hist::passTrig(int trigIdx)
{
   int bitIdx = trigIdx/32;
   if ( ntP->BitTrigger[bitIdx] & ( 1 << (trigIdx - bitIdx*32) ) ) return true;
   else return false;
}
