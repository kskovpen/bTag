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

   muptcut = 5.;

   name_rw.push_back("1d_nseltrk");
   
   hname.clear();

   int nbins = 100;

   histNameDefined_jet[0] = "h_j1_pt_";
   histNameDefined_jet[1] = "h_j1_nseltrk_";
   histNameDefined_jet[2] = "h_j1_eta_";
   histNameDefined_jet[3] = "h_j1_ntrk_";
   histNameDefined_jet[4] = "h_j1_njet_";
   histNameDefined_jet[5] = "h_j1_nsv_";
   histNameDefined_jet[6] = "h_j1_mupt_";
   histNameDefined_jet[7] = "h_j1_JP_";

   hist_jet.push_back(HIST_J1_PT);
   hist_jet.push_back(HIST_J1_NSELTRK);
   hist_jet.push_back(HIST_J1_ETA);
   hist_jet.push_back(HIST_J1_NTRK);
   hist_jet.push_back(HIST_J1_NJET);
   hist_jet.push_back(HIST_J1_NSV);
   hist_jet.push_back(HIST_J1_MUPT);
   hist_jet.push_back(HIST_J1_JP);
   
   hist_jet_n = hist_jet.size();

   for(int ih=0;ih<hist_jet_n;ih++)
     {
	int idx = hist_jet[ih];
	histName_jet[ih] = histNameDefined_jet[idx];
     }   
   
   sel.push_back("nosel");
   sel.push_back("pt20t30");
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
   sel.push_back("pt670t1000");
   sel_n = sel.size();

   jPtMin.push_back(20); jPtMax.push_back(30);
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
   jPtMin.push_back(670); jPtMax.push_back(1000);

   eta_n = 1;
   eta[0] = "nosel";

   selbNameDefined[0] = "nosel";
   selbNameDefined[1] = "combSvx0p244";
   selbNameDefined[2] = "combSvx0p679";
   selbNameDefined[3] = "combSvx0p898";
   selbNameDefined[4] = "TCHP1p19";
   selbNameDefined[5] = "TCHP1p93";
   selbNameDefined[6] = "TCHP3p41";
   selbNameDefined[7] = "UNTAGbc";
   
   selb.push_back(BTAG_NONE);
   selb.push_back(BTAG_CSVL);
   selb.push_back(BTAG_CSVM);
   selb.push_back(BTAG_CSVT);
//   selb.push_back(BTAG_TCHPL);
//   selb.push_back(BTAG_TCHPM);
   selb.push_back(BTAG_TCHPT);
   selb.push_back(BTAG_UNTAG);
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
   sys.push_back(SYS_PU_UP);
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
   sys.push_back(SYS_JER_DOWN);
   
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

   std::vector<double*> set_hist_jet;
   set_hist_jet.clear();

   set_hist_jet.push_back(RANGE::set_j_pt);
   set_hist_jet.push_back(RANGE::set_j_nseltrk);
   set_hist_jet.push_back(RANGE::set_j_eta);
   set_hist_jet.push_back(RANGE::set_j_ntrk);
   set_hist_jet.push_back(RANGE::set_j_njet);
   set_hist_jet.push_back(RANGE::set_j_nsv);

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
				      if( hist_jet[h] == HIST_J1_MUPT )
					_s_Jet->push_back(std::make_pair(names,RANGE::set_j_mupt[ss]));
				      else if( hist_jet[h] == HIST_J1_JP )
					{
					   if( selb[ssb] == BTAG_NONE ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_nosel[ss]));
					   else if( selb[ssb] == BTAG_CSVL ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVL[ss]));
					   else if( selb[ssb] == BTAG_CSVM ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVM[ss]));
					   else if( selb[ssb] == BTAG_CSVT ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVT[ss]));
					   else if( selb[ssb] == BTAG_TCHPT ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_TCHPT[ss]));
					   else _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_nosel[ss]));
					}				      
				      else
					_s_Jet->push_back(std::make_pair(names,set_hist_jet.at(h)));
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

   if( !isdata )
     {	
	rw = new LTANA::Reweight();
	rw->init(doRW,jPtMin,jPtMax,sel,selbName,name_rw);
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
	double w015 = 1901694/(580700000*0.0035);
	double w020 =12133278/(235400000*0.0045);
	double w030 =11610144/(53470000*0.01);
	double w050 = 9887094/(6317000*0.0245);
	double w080 =10497146/(781100*0.0345);
	double w120 = 7913447/(116000*0.0545);
	double w170 = 8116425/(24690*0.0625);
	double w300 = 7870022/(1153*0.0923);
	double w470 = 3812536/(71.81*0.086);
	double w600 = 4149919/(15.15*0.094);
	double w800 = 3945269/(1.863*0.1033);
	double w1000= 4133903/(0.3392*0.094);
	
	w015 = w080 / w015;
	w020 = w080 / w020;
	w030 = w080 / w030;
	w050 = w080 / w050;
	w120 = w080 / w120;
	w170 = w080 / w170;
	w300 = w080 / w300;
	w470 = w080 / w470;
	w600 = w080 / w600;
	w800 = w080 / w800;
	w1000= w080 / w1000;
	w080 = 1.;
	
	if( pthat >=  15. && pthat <  20. ) w = w015;
	else if ( pthat >=  20. && pthat <  30. ) w = w020;
	else if ( pthat >=  30. && pthat <  50. ) w = w030;
	else if ( pthat >=  50. && pthat <  80. ) w = w050;
	else if ( pthat >=  80. && pthat < 120. ) w = w080;
	else if ( pthat >= 120. && pthat < 170. ) w = w120;
	else if ( pthat >= 170. && pthat < 300. ) w = w170;
	else if ( pthat >= 300. && pthat < 470. ) w = w300;
	else if ( pthat >= 470. && pthat < 600. ) w = w470;
	else if ( pthat >= 600. && pthat < 800. ) w = w600;
	else if ( pthat >= 800. && pthat < 1000.) w = w800;
	else if ( pthat >= 1000. )                w = w1000;	
     }   
   
   float mc_weight = ntP->mcweight;
   if( !isdata ) w *= mc_weight;
   
   int npu = ntP->nPU;
   int npv = ntP->nPV;
   if( npu > 34 ) npu = 34;

//   int jmax = 0; // highest-Pt jet
   int jmax = -1; // all jets
      
   int jidx = -1; // only the highest-Pt jet
//   int jidx = -1; // all jets

   // Event
   
   if( ntP->nMuon == 0 ) return;

   int ntNJET = ntP->nJet;

   // 'overcut' for trigger selection
   int nJet20 = 0;
   for( int ij=0;ij<ntNJET;ij++ )
     {
	if( ntP->Jet_pt[ij] > 20. ) nJet20++;
     }	
   if( nJet20 < 2 ) return;
   
   bool filterPTHAT = false;
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
   if( filterPTHAT || filterNJET || filterPT ) return;
   
   // Trigger
   
   bool passTrigJet20 = passTrig(35);
   bool passTrigJet40 = passTrig(41);
   bool passTrigJet70 = passTrig(44);
   bool passTrigJet110 = passTrig(47);
   bool passTrigJet300 = passTrig(50);
   bool passTrigJet300_HLT = passTrig(18);

   passTrigJet300 = passTrigJet300_HLT;
   
   int bitIdx;
   int trigIdx;
   
   int njet20 = 0, njet40 = 0, njet70 = 0,
     njet110 = 0, njet300 = 0;
   
   for(int ij=0;ij<ntNJET;ij++)
     {
	float jpt = ntP->Jet_pt[ij];
	float jeta = fabs(ntP->Jet_eta[ij]);

	if( jeta > 2.4 ) continue;
	
	if( jpt > 20. )  njet20++;
	if( jpt > 50. )  njet40++;
	if( jpt > 80. )  njet70++;
	if( jpt > 120. ) njet110++;
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
	
	int nAwayTag = 0;
	for(int ijj=0;ijj<nJetMax;ijj++)	  
	  {
	     if( ijj == ij ) continue;
	     float jbtCombSvx = ntP->Jet_CombSvx[ijj];
//	     if( jbtCombSvx >= 0.244 ) nAwayTag++;
	     if( jbtCombSvx >= 0.679 ) nAwayTag++;
//	     if( jbtCombSvx >= 0.898 ) nAwayTag++;
	  }
	if( nAwayTag == 0 ) continue;

	Jet_Proba_New = ntP->Jet_Proba[ij];
	if( Jet_Proba_New == 0. ) Jet_Proba_New = -1.;

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
	float residual = 1.;
	if( ntP->Run > 0 ) residual = ntP->Jet_residual[ij];
	float jpt = ntP->Jet_pt[ij] * residual;

	if( isdata && sp2011 && jpt < 320. ) continue;
	if( isdata && !sp2011 && jpt >= 320. ) continue;
	
	if( jpt < 20. || jpt > 1500. ) passSel = false;
	if( fabs(jeta) > 2.4 ) passSel = false;
	
	int njet = ntNJET;
	
	int nsv = ntP->nSV;
	int nsvj = ntP->Jet_nLastSV[ij];
	
	int ntrk = ntP->Jet_ntracks[ij];
	int nseltrk = ntP->Jet_nseltracks[ij];
	
	if( !sp2011 )
	  {	     
	     if( isdata )
	       {
		  if( jpt <= 50 && !passTrigJet20 ) passSel = false;
		  if( jpt > 50 && jpt <= 80 && !passTrigJet40 && !passTrigJet20 ) passSel = false;
		  if( jpt > 80 && jpt <= 120 && !passTrigJet70 && !passTrigJet40 ) passSel = false;
		  if( jpt > 120 && jpt <= 320 && !passTrigJet110 && !passTrigJet70 ) passSel = false;
		  if( jpt > 320 ) 
		    {
		       if( ntP->Run < 190000 && !passTrigJet110 && !passTrigJet70 ) passSel = false;
		       if( ntP->Run > 190000 && !passTrigJet300 ) passSel = false;
		    }	
	       }
	     else
	       {   
		  if( jpt <= 50 && !passTrigJet20 ) passSel = false;
		  if( jpt > 50 && jpt <= 80 && !passTrigJet40 ) passSel = false;
		  if( jpt > 80 && jpt <= 120 && !passTrigJet70 ) passSel = false;
		  if( jpt > 120 && !passTrigJet110 ) passSel = false;
	       }
	  }
	
	if( jpt >= 320 && !passTrigJet300 ) passSel = false; 

	muidx.clear();

	for(int imu=0;imu<ntP->nMuon;imu++)
	  {
	     if( ntP->Muon_IdxJet[imu] == ij )
	       {	     
		  if( ntP->Muon_isGlobal[imu] == 0 ) continue;
		  if( ntP->Muon_pt[imu] < muptcut ) continue;
		  if( ntP->Muon_nMuHit[imu] == 0 ) continue;
		  if( ntP->Muon_nTkHit[imu] < 11 ) continue;
		  if( ntP->Muon_nPixHit[imu] < 2 ) continue;
		  if( ntP->Muon_nOutHit[imu] > 2 ) continue;
		  if( ntP->Muon_nMatched[imu] < 2 ) continue;
		  if( ntP->Muon_chi2[imu] > 10. ) continue;
		  if( ntP->Muon_chi2Tk[imu] > 10. ) continue;
		  if( fabs(ntP->Muon_eta[imu]) > 2.4 ) continue;
		  muidx.push_back(imu);
	       }
	  }
	bool passMuonInJet = (muidx.size() > 0);
   
	float drjmu = -666;
	if( passMuonInJet )
	  {
	     for(int im=0;im<muidx.size();im++)
	       {		  
		  float mupt = ntP->Muon_pt[muidx[im]];
		  float mueta = ntP->Muon_eta[muidx[im]];
		  float muphi = ntP->Muon_phi[muidx[im]];
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
	     float jbtTCHP = ntP->Jet_Ip3P[ij];

	     std::vector<bool> selbch_res;
	     for(int ibt=0;ibt<selb_n;ibt++) 
	       {
		  if( selb[ibt] == BTAG_NONE ) selbch_res.push_back(1);
		  else
		    {		       
		       bool passBTAG = (
					(selb[ibt] == BTAG_CSVL && jbtCombSvx >= 0.244) ||
					(selb[ibt] == BTAG_CSVM && jbtCombSvx >= 0.679) ||
					(selb[ibt] == BTAG_CSVT && jbtCombSvx >= 0.898) ||
					(selb[ibt] == BTAG_TCHPL && jbtTCHP >= 1.19) ||
					(selb[ibt] == BTAG_TCHPM && jbtTCHP >= 1.93) ||
					(selb[ibt] == BTAG_TCHPT && jbtTCHP >= 3.41) ||
					(selb[ibt] == BTAG_UNTAG && jbtCombSvx < 0.898)
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
		  if( flavchI == 3 ) sfj *= 1.27;
		  
		  // additional scaling to study the effect on SF
//		  if( flavchI == 1 ) sfj *= 0.80;
//		  if( flavchI == 1 ) sfj *= 1.20;
//		  if( flavchI == 2 ) sfj *= 0.80;
//		  if( flavchI == 2 ) sfj *= 1.20;
//		  if( flavchI == 3 ) sfj *= 0.80;
//		  if( flavchI == 3 ) sfj *= 1.20;
		  
		  // pileup reweighting sys
		  sfj *= syst->Pileup(npu,sys[isys]);

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
		  
		  // generated ntrk in b- and c- hadron decays sys (HAS TO BE CALLED THE LAST !)
		  sfj *= syst->GenNTrk(ij,flavchI,sys[isys]);

		  float mupt = -1.;
		  if( muidx.size() > 0 )
		    mupt = ntP->Muon_pt[muidx[0]];

		  int jPtBin = 0;   

		  if( jPT >= jPtMin[0] && jPT <= jPtMax[0] )   {selch = "pt20t30"; jPtBin = 1;}
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
		  if( jPT > jPtMin[14] )  {selch = "pt500t670"; jPtBin = 15;}

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
	       var = ntP->Muon_pt[muidx[0]];
	     else fillThis = false;
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
	  }
     }   

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
