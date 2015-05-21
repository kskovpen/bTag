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

   histname_jet_n = 8;

   histname_jet[0] = "h_j1_pt_";
   histname_jet[1] = "h_j1_nseltrk_";
   histname_jet[2] = "h_j1_eta_";
   histname_jet[3] = "h_j1_ntrk_";
   histname_jet[4] = "h_j1_njet_";
   histname_jet[5] = "h_j1_nsv_";
   histname_jet[6] = "h_j1_mupt_"; // has to be the last*/
   histname_jet[7] = "h_j1_JP_";
//   histname_jet[1] = "h_j1_JP_";

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

   selb.push_back("nosel");
   selb.push_back("combSvx0p244"); // Loose
//   selb[2] = "combSvx0p679"; // Medium
//   selb[3] = "combSvx0p898"; // Tight
//   selb[4] = "TCHP1p19"; // Loose
//   selb[5] = "TCHP1p93"; // Medium
//   selb[6] = "TCHP3p41"; // Tight
   selb.push_back("UNTAGbc");
   selb_n = selb.size();

   seladd_n = 1;
   seladd[0] = "";
   
   flav_n = 4;
   flav[0] = "ajet";
   flav[1] = "bjet";
   flav[2] = "cjet";
   flav[3] = "ljet";
   
//   sys_low_n = 10;
   sys_low_n = 1;
   sys_low[0]   = "";
/*   sys_low[1]   = "_pu_low";
   sys_low[2]   = "_gsplit_low";
   sys_low[3]   = "_bfrag_low";
   sys_low[4]   = "_cdfrag_low";
   sys_low[5]   = "_cfrag_low";
   sys_low[6]   = "_ksl_low";
   sys_low[7]   = "_ntrkgen_low";
   sys_low[8]   = "_jes_low";
   sys_low[9]   = "_jer_low";*/

   sys_up_n = sys_low_n-1;
/*   sys_up[0]   = "_pu_up";
   sys_up[1]   = "_gsplit_up";
   sys_up[2]   = "_bfrag_up";
   sys_up[3]   = "_cdfrag_up";
   sys_up[4]   = "_cfrag_up";
   sys_up[5]   = "_ksl_up";
   sys_up[6]   = "_ntrkgen_up";
   sys_up[7]   = "_jes_up";
   sys_up[8]   = "_jer_up";*/

   sys_n = sys_low_n + sys_up_n;
   
   for(int is1=0;is1<sys_low_n;is1++)
     {
	sys[is1] = sys_low[is1];
     }   
   for(int is2=0;is2<sys_up_n;is2++)
     {
	sys[sys_low_n+is2] = sys_up[is2];
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
			    for(int h=0;h<histname_jet_n;h++)
			      {
				 std::string hn = histname_jet[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selb[ssb]+seladd[ssa];
				 hname.push_back(hn);
				 
				 for(int s=0;s<sys_n;s++)
				   {
				      titl = hn+sys[s];
				      std::vector<std::string> names;
				      names.clear();
				      names.push_back(titl);
				      names.push_back(sys[s]);
				      if( h == 6 )
					_s_Jet->push_back(std::make_pair(names,RANGE::set_j_mupt[ss]));
				      else if( h == 7 )
//				      else if( h == 1 )
					{
					   if( ssb == 0 ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_nosel[ss]));
					   else if( ssb == 1 ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVL[ss]));
					   else if( ssb == 2 ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVM[ss]));
					   else if( ssb == 3 ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVT[ss]));
					   else if( ssb == 6 ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_TCHPT[ss]));
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
	rw->init(doRW,jPtMin,jPtMax,sel,selb,name_rw);
     }   

   // Init systematics
   syst = new LTANA::Syst();
   syst->init();

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
				 for(int h=0;h<histname_jet_n;h++)
				   {
				      histNAMES[j][ss][se][ssb][ssa][h][s] =
					histname_jet[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selb[ssb]+seladd[ssa]+sys[s];
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
	     bool selbch_res[selb_n];
	     for( int ibt=0;ibt<selb_n;ibt++ ) selbch_res[ibt] = false;
	     
	     float jbtCombSvx = ntP->Jet_CombSvx[ij];
	     float jbtTCHP = ntP->Jet_Ip3P[ij];
	     
	     selbch_res[0] = true;
	     if( jbtCombSvx >= 0.244 ) selbch_res[1] = true;
//	     if( jbtCombSvx >= 0.679 ) selbch_res[2] = true;
//	     if( jbtCombSvx >= 0.898 ) selbch_res[3] = true;
//	     if( jbtTCHP >= 1.19 ) selbch_res[4] = true;
//	     if( jbtTCHP >= 1.93 ) selbch_res[5] = true;
//	     if( jbtTCHP >= 3.41 ) selbch_res[6] = true;
	     if( jbtCombSvx < 0.898 ) selbch_res[2] = true;
//	     if( jbtTCHP < 3.41 ) selbch_res[4] = true;

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

		  for(int ih=0;ih<histname_jet_n;ih++)
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
		       std::string varName = histname_jet[histVAR[hidx]];
		       if( strcmp(varName.c_str(),"h_j1_svntrk_") == 0 ||
			   strcmp(varName.c_str(),"h_j1_svmass_") == 0 )
			 {			    
			    varv = getVarVec(sys[histSYS[hidx]],ij,varName,jPtBin);
			    single = 0;
			 }		       
		       else
			 var = getVar(sys[histSYS[hidx]],ij,varName,jPtBin);
		       
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

float LTANA::Hist::getVar(std::string sys,int ijet,std::string varName,int ibin)
{
   float var = -666;
   
   if( ijet <= ntP->nJet )
     {	   
	if( strcmp(varName.c_str(),"h_j1_JP_") == 0 )
	  {
	     var = Jet_Proba_New;
	     if( var == 0. ) var = -666.;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_BJP_") == 0 )
	  {		  
	     var = ntP->Jet_Bprob[ijet];
	     if( var == 0. ) var = -666.;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_pthat_") == 0 )
	  {		  
	     var = ntP->pthat/1000.;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_ntrk_") == 0 )
	  {		  
	     var = ntP->Jet_ntracks[ijet];
	  }	     
	if( strcmp(varName.c_str(),"h_j1_nseltrk_") == 0 )
	  {		  
	     var = ntP->Jet_nseltracks[ijet];
	  }	     
	if( strcmp(varName.c_str(),"h_j1_eta_") == 0 )
	  {		  
	     var = ntP->Jet_eta[ijet];
	  }	     
	if( strcmp(varName.c_str(),"h_j1_phi_") == 0 )
	  {		  
	     var = ntP->Jet_phi[ijet];
	  }	     
	if( strcmp(varName.c_str(),"h_j1_mass_") == 0 )
	  {		  
	     var = ntP->Jet_mass[ijet];
	  }	     
	if( strcmp(varName.c_str(),"h_j1_mupt_") == 0 )
	  {
	     if( muidx.size() > 0 )
	       var = ntP->Muon_pt[muidx[0]];
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_mueta_") == 0 )
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
	  }	     
	if( strcmp(varName.c_str(),"h_j1_npv_") == 0 )
	  {
	     if( ijet == 0 )
	       var = ntP->nPV;
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_npu_") == 0 )
	  {
	     if( ijet == 0 )
	       var = ntP->nPU;
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_njet_") == 0 )
	  {
	     if( ijet == 0 )
	       var = ntP->nJet;
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_nmuon_") == 0 )
	  {
	     if( ijet == 0 )
	       var = ntP->nMuon;
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_nsv_") == 0 )
	  {
	     if( ijet == 0 )
	       var = ntP->nSV;
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_nsvj_") == 0 )
	  {
	     var = ntP->Jet_nLastSV[ijet];
	  }	     

	if( strcmp(varName.c_str(),"h_j1_pt_") == 0 )
	  {	
	     double jptmax = 1250.;
	     double jptmin = 0.;
	     if( ibin > 0 ) 
	       {
		  jptmax = jPtMax[ibin-1];
		  jptmin = jPtMin[ibin-1];
	       }	     
	     
	     var = (getPt(sys)-jptmin)/(jptmax-jptmin);
	  }	     
     }   

   return var;
}

std::vector<float> LTANA::Hist::getVarVec(std::string sys,int ijet,std::string varName,int ibin)
{
   std::vector<float> var;
   var.clear();

   if( ibin-1 < 0 ) return var;
   
   if( ijet <= ntP->nJet )
     {	   
	if( strcmp(varName.c_str(),"h_j1_svntrk_") == 0 )
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
	  }	     
     }   

   return var;
}

float LTANA::Hist::getPt(std::string sys)
{
   float var = -666;
   
   if( (sys == "" ||
	sys == "_sys_up" || sys == "_sys_low" ||
	sys == "_pu_up" || sys == "_pu_low" ||
	sys == "_gsplit_up" || sys == "_gsplit_low" ||
	sys == "_bfrag_up" || sys == "_bfrag_low" ||
	sys == "_cdfrag_up" || sys == "_cdfrag_low" ||
	sys == "_cfrag_up" || sys == "_cfrag_low" ||
	sys == "_ksl_up" || sys == "_ksl_low" ||
	sys == "_ntrkgen_up" || sys == "_ntrkgen_low"
       )
       ||
       isdata )
     {
	var = v_jet->Pt();
     }

   return var;
}

bool LTANA::Hist::passTrig(int trigIdx)
{
   int bitIdx = trigIdx/32;
   if ( ntP->BitTrigger[bitIdx] & ( 1 << (trigIdx - bitIdx*32) ) ) return true;
   else return false;
}
