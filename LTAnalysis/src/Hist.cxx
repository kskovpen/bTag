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

/*   ttree = new TTree("EventTree","EventTree");
   ttree->Branch("eventId",&t_eventId,"eventId/I");
   ttree->Branch("runId",&t_runId,"runId/I");
   ttree->Branch("lumiId",&t_lumiId,"lumiId/I");
   ttree->Branch("j1Pt",&t_j1Pt,"j1Pt/F");
   ttree->Branch("j1Eta",&t_j1Eta,"j1Eta/F");
   ttree->Branch("j2Pt",&t_j2Pt,"j2Pt/F");
   ttree->Branch("j2Eta",&t_j2Eta,"j2Eta/F");
   ttree->Branch("j3Pt",&t_j3Pt,"j3Pt/F");
   ttree->Branch("j3Eta",&t_j3Eta,"j3Eta/F");
   ttree->Branch("j4Pt",&t_j4Pt,"j4Pt/F");
   ttree->Branch("j4Eta",&t_j4Eta,"j4Eta/F");
*/   
   TFile *fPileup = TFile::Open("/user/kskovpen/analysis/bTag/CMSSW_8_0_12/src/LTAnalysis/test/macros/npv.root");
   _h_pileup = (TH1D*)fPileup->Get("h_npv");
   
   _fout->cd();
   
   muptcut = 5.;

//   name_rw.push_back("1d_pt");
//   name_rw.push_back("1d_nseltrk");
//   name_rw.push_back("1d_njet");
//   name_rw.push_back("1d_mupt");
//   name_rw.push_back("1d_csvAway");
//   name_rw.push_back("1d_drAway");
//   name_rw.push_back("1d_jpAway");
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
   histNameDefined_jet[13] = "h_j1_drAway_";
   histNameDefined_jet[14] = "h_j1_csvAway_";
   histNameDefined_jet[15] = "h_j1_tchpAway_";
   histNameDefined_jet[16] = "h_j1_jpAway_";
   histNameDefined_jet[17] = "h_j1_ptAway_";
   histNameDefined_jet[18] = "h_j1_etaAway_";
   histNameDefined_jet[19] = "h_j1_hasMuon_";

   hist_jet.push_back(HIST_J1_PT);
   hist_jet.push_back(HIST_J1_NSELTRK);
   hist_jet.push_back(HIST_J1_ETA);
   hist_jet.push_back(HIST_J1_NTRK);
   hist_jet.push_back(HIST_J1_NJET);
//   hist_jet.push_back(HIST_J1_NSV);
   hist_jet.push_back(HIST_J1_MUPT);
   hist_jet.push_back(HIST_J1_JP);
//   hist_jet.push_back(HIST_J1_HASMUON);
//   hist_jet.push_back(HIST_PTHAT);
//   hist_jet.push_back(HIST_J1_NTRKGEN);
//   hist_jet.push_back(HIST_NPV);
//   hist_jet.push_back(HIST_J1_DRAWAY);
//   hist_jet.push_back(HIST_J1_CSVAWAY);
//   hist_jet.push_back(HIST_J1_JPAWAY);
//   hist_jet.push_back(HIST_J1_PTAWAY);
//   hist_jet.push_back(HIST_J1_ETAAWAY);
/*   hist_jet.push_back(HIST_PTHAT);
   hist_jet.push_back(HIST_NPV);*/
   hist_jet.push_back(HIST_J1_CSVIVF);
/*   hist_jet.push_back(HIST_J1_MUPTREL);
   hist_jet.push_back(HIST_J1_NTRKGEN);
   hist_jet.push_back(HIST_J1_AWAYDR);
 */
   
   hist_jet_n = hist_jet.size();
   for(int ih=0;ih<hist_jet_n;ih++)
     {
	int idx = hist_jet[ih];
	histName_jet[ih] = histNameDefined_jet[idx];
     }   

   histNameDefined_jet_2d[0] = "h_j1_pt_vs_jeta_";
   histNameDefined_jet_2d[1] = "h_j1_JP_vs_CSV_";
   histNameDefined_jet_2d[2] = "h_j1_JP_vs_CMVA_";
   
//   hist_jet_2d.push_back(HIST_2D_J1_JP_VS_CSV);
//   hist_jet_2d.push_back(HIST_2D_J1_JP_VS_CMVA);
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
   selbNameDefined[10] = "CMVAL";
   selbNameDefined[11] = "CMVAM";
   selbNameDefined[12] = "CMVAT";
   selbNameDefined[13] = "UNTAGCMVAL";
   selbNameDefined[14] = "UNTAGCMVAM";
   selbNameDefined[15] = "UNTAGCMVAT";
   
   selb.push_back(BTAG_NONE);
   selb.push_back(BTAG_CSVL);
   selb.push_back(BTAG_CSVM);
   selb.push_back(BTAG_CSVT);
   selb.push_back(BTAG_UNTAGCSVL);
   selb.push_back(BTAG_UNTAGCSVM);
   selb.push_back(BTAG_UNTAGCSVT);
   selb.push_back(BTAG_CMVAL);
   selb.push_back(BTAG_CMVAM);
   selb.push_back(BTAG_CMVAT);
   selb.push_back(BTAG_UNTAGCMVAL);
   selb.push_back(BTAG_UNTAGCMVAM);
   selb.push_back(BTAG_UNTAGCMVAT);
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
				      else if( histId == HIST_J1_DRAWAY ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_draway));
				      else if( histId == HIST_J1_CSVAWAY ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_csvaway));
				      else if( histId == HIST_J1_TCHPAWAY ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_tchpaway));
				      else if( histId == HIST_J1_JPAWAY ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_jpaway));
				      else if( histId == HIST_J1_PTAWAY ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_ptaway));
				      else if( histId == HIST_J1_ETAAWAY ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_etaaway));
				      else if( histId == HIST_J1_HASMUON ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_hasmuon));
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
				      else if( histId == HIST_2D_J1_JP_VS_CSV ) _s2_Jet->push_back(std::make_pair(names,RANGE::set_j_2d_JP_vs_CSV));
				      else if( histId == HIST_2D_J1_JP_VS_CMVA ) _s2_Jet->push_back(std::make_pair(names,RANGE::set_j_2d_JP_vs_CMVA));
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

//   if( !isdata )
//     {
//	pu = new LTANA::PU();
//	pu->init(doPU);
//     }   

   if( isdata )
     {
	ps = new LTANA::PS();
	ps->init(doPS);
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
	double ILexp = 1000.;
	w = ILexp/w;
     }   
   
   float mc_weight = ntP->mcweight;
   if( !isdata ) w *= mc_weight;
   
//   int npu = ntP->nPU;
   int npu = ntP->nPUtrue+1;
   int npv = ntP->nPV;
//   if( npu > 34 ) npu = 34;

//   int jmax = 0; // highest-Pt jet
   int jmax = -1; // all jets
      
//   int jidx = 0; // only the highest-Pt jet
   int jidx = -1; // all jets

   // Event
   
   if( ntP->nPFMuon == 0 ) return;

   int ntNJET = ntP->nJet;

   // 'overcut' for trigger selection
   int nJet30 = 0;
   for( int ij=0;ij<ntNJET;ij++ )
     {
	if( ntP->Jet_pt[ij] > 30. ) nJet30++;
     }	
   if( nJet30 < 2 ) return;
   
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
//   bool passTrigJet170 = passTrig(90);
   bool passTrigJet300 = passTrig(50);
   
   bool passTrigPFJet40 = passTrig(2);
   bool passTrigPFJet60 = passTrig(87);
   bool passTrigPFJet80 = passTrig(7);
   bool passTrigPFJet140 = passTrig(12);
   bool passTrigPFJet200 = passTrig(15);
   bool passTrigPFJet260 = passTrig(17);
   bool passTrigPFJet320 = passTrig(19);

//   if( !isdata )
//     {
//	passTrigJet20 = 1;
//	passTrigJet40 = 1;
//	passTrigJet70 = 1;
//	passTrigJet110 = 1;
//	passTrigJet300 = 1;
//     }   
   
   int bitIdx;
   int trigIdx;
   
   int runIdx = ntP->Run;

   const int runN1 = 59;
   int runIdx1[runN1] = {273158,273302,273402,273403,273404,273405,273406,273408,273409,273410,273411,273425,273446,273447,273448,273449,273450,273492,273493,273494,273502,273503,273554,273555,273725,273728,273730,274094,274146,274159,274160,274161,274172,274198,274199,274200,274241,274244,274251,274283,274317,274319,274337,274339,274344,274345,274954,274955,274970,274971,275000,275001,275074,275290,275310,275311,275376,275837,275847};
   const int runN2 = 31;
   int runIdx2[runN2] = {274240,274250,274284,274286,274316,274335,274336,274338,274382,274388,274422,274441,274442,274969,274999,275073,275125,275291,275292,275293,275309,275338,275375,275778,275782,275836,275918,275920,275921,275923,275931};
   const int runN3 = 43;
   int runIdx3[runN3] = {274314,274315,274387,274420,274421,274440,274968,274998,275059,275066,275067,275124,275282,275283,275284,275319,275337,275344,275345,275370,275371,275657,275658,275659,275761,275767,275772,275773,275774,275776,275777,275832,275833,275834,275835,275886,275890,275911,275912,275913,275963,276092,276097};

   // TIME
/*   const int runN1 = 63;
   int runIdx1[runN1] = {273158,273302,273402,273403,273404,273405,273406,273408,273409,273410,273411,273425,273446,273447,273448,273449,273450,273492,273493,273494,273502,273503,273554,273555,273725,273728,273730,274094,274146,274159,274160,274161,274172,274198,274199,274200,274240,274241,274244,274250,274251,274283,274284,274286,274314,274315,274316,274317,274319,274335,274336,274337,274338,274339,274344,274345,274382,274387,274388,274420,274421,274422,274440};
   const int runN2 = 34;
   int runIdx2[runN2] = {274441,274442,274954,274955,274968,274969,274970,274971,274998,274999,275000,275001,275059,275066,275067,275068,275073,275074,275124,275125,275282,275283,275284,275290,275291,275292,275293,275309,275310,275311,275319,275337,275338,275344};
   const int runN3 = 37;
   int runIdx3[runN3] = {275345,275370,275371,275375,275376,275657,275658,275659,275761,275767,275772,275773,275774,275776,275777,275778,275782,275832,275833,275834,275835,275836,275837,275847,275886,275890,275911,275912,275913,275918,275920,275921,275923,275931,275963,276092,276097};
*/   
   bool is1 = 0;
   bool is2 = 0;
   bool is3 = 0;
   
   for(int i=0;i<runN1;i++)
     {
	if( runIdx == runIdx1[i] ) {is1 = 1; break;}
     }   
   for(int i=0;i<runN2;i++)
     {
	if( runIdx == runIdx2[i] ) {is2 = 1; break;}
     }   
   for(int i=0;i<runN3;i++)
     {
	if( runIdx == runIdx3[i] ) {is3 = 1; break;}
     }   
   
//   if( isdata && !is3 ) return;
//   if( isdata && !(runIdx < 276098) ) return;

/*   if( ntP->Evt == 401543665 && ntP->Run == 251643 )
     {
	TLorentzVector mu1;
	mu1.SetPtEtaPhiM(ntP->PFMuon_pt[0],ntP->PFMuon_eta[0],ntP->PFMuon_phi[0],140.);
	TLorentzVector mu2;
	mu2.SetPtEtaPhiM(ntP->PFMuon_pt[1],ntP->PFMuon_eta[1],ntP->PFMuon_phi[1],140.);
	TLorentzVector v1;
	v1.SetPtEtaPhiM(ntP->Jet_pt[0],ntP->Jet_eta[0],ntP->Jet_phi[0],ntP->Jet_mass[0]);	
	TLorentzVector v2;
	v2.SetPtEtaPhiM(ntP->Jet_pt[1],ntP->Jet_eta[1],ntP->Jet_phi[1],ntP->Jet_mass[1]);
	std::cout << v1.DeltaR(mu1) << std::endl;
	std::cout << v1.DeltaR(mu2) << std::endl;
	std::cout << v2.DeltaR(mu1) << std::endl;
	std::cout << v2.DeltaR(mu2) << std::endl;
     }*/
   
   // Fill the tree for Fireworks
/*   if( ntNJET == 4 )
     {
	float jpt1 = ntP->Jet_pt[0];
	float jeta1 = ntP->Jet_eta[0];
	float jpt2 = ntP->Jet_pt[1];
	float jeta2 = ntP->Jet_eta[1];
	float jpt3 = ntP->Jet_pt[2];
	float jeta3 = ntP->Jet_eta[2];
	float jpt4 = ntP->Jet_pt[3];
	float jeta4 = ntP->Jet_eta[3];
	float jbtCombIVF1 = ntP->Jet_CombIVF[0];
	float jbtCombIVF2 = ntP->Jet_CombIVF[1];
	float jbtCombIVF3 = ntP->Jet_CombIVF[2];
	float jbtCombIVF4 = ntP->Jet_CombIVF[3];
	
	if( !(jpt1 < 20. || jpt2 < 20. || jpt3 < 20. || jpt4 < 20. ||
	      fabs(jeta1) > 2.4 || fabs(jeta2) > 2.4 ||
	      fabs(jeta3) > 2.4 || fabs(jeta4) > 2.4 ||
	      jbtCombIVF1 < 0.890 || jbtCombIVF2 < 0.890 ||
	      jbtCombIVF3 < 0.890 || jbtCombIVF4 < 0.890) )
	  {	     
	     t_eventId = ntP->Evt;
	     t_runId = ntP->Run;
	     t_lumiId = ntP->LumiBlock;
	     t_j1Pt = jpt1;
	     t_j2Pt = jpt2;
	     t_j3Pt = jpt3;
	     t_j4Pt = jpt4;
	     t_j1Eta = jeta1;
	     t_j2Eta = jeta2;
	     t_j3Eta = jeta3;
	     t_j4Eta = jeta4;
	     
	     ttree->Fill();
	  }	
     }*/

   int njet20 = 0, njet40 = 0, njet70 = 0,
     njet110 = 0, njet170 = 0, njet300 = 0;

   int nMuJet20 = 0, nMuJet40 = 0, nMuJet70 = 0,
     nMuJet110 = 0, nMuJet170 = 0, nMuJet300 = 0;
   
   int njetPF40 = 0, njetPF60 = 0, njetPF80 = 0,
     njetPF140 = 0, njetPF200 = 0,
     njetPF260 = 0, njetPF320 = 0;

   int nMuJet = 0;
   for(int ij=0;ij<ntNJET;ij++)
     {
	float jpt = ntP->Jet_pt[ij];
	float jeta = ntP->Jet_eta[ij];
	float jphi = ntP->Jet_phi[ij];
	
	if( fabs(jeta) > 2.4 ) continue;

	bool nMuJet = 0;
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
		  
		  float mueta = ntP->PFMuon_eta[imu];
		  float muphi = ntP->PFMuon_phi[imu];
		  
		  Helper *helper = new Helper();
		  float dr = helper->DeltaR(jeta,
					    jphi,
					    mueta,
					    muphi);
		  delete helper;

		  if( dr > 0.4 ) continue;
		  
		  nMuJet = 1;
	       }
	  }

	if( jpt > 30. && jpt < 50. )  njet20++;
	if( jpt > 30 && jpt < 50. && nMuJet ) nMuJet20++;
	if( jpt > 50. && jpt < 80. )  njet40++;
	if( jpt > 50 && jpt < 80. && nMuJet ) nMuJet40++;
	if( jpt > 80. && jpt < 120. )  njet70++;
	if( jpt > 80 && jpt < 120. && nMuJet ) nMuJet70++;
	if( jpt > 120. && jpt < 320. ) njet110++;
	if( jpt > 120 && jpt < 320. && nMuJet ) nMuJet110++;
//	if( jpt > 180. ) njet170++;
//	if( jpt > 180 && nMuJet ) nMuJet170++;
	if( jpt > 320. ) njet300++;
	if( jpt > 320. && nMuJet ) nMuJet300++;
	
	if( jpt > 50. )  njetPF40++;
	if( jpt > 70. )  njetPF60++;
	if( jpt > 100. ) njetPF80++;
	if( jpt > 160. ) njetPF140++;
	if( jpt > 220. ) njetPF200++;
	if( jpt > 310. ) njetPF260++;
	if( jpt > 360. ) njetPF320++;	
     }      
   if( njet20 < 2 || nMuJet20 < 1 ) passTrigJet20 = false;
   if( njet40 < 2 || nMuJet40 < 1 ) passTrigJet40 = false;
   if( njet70 < 2 || nMuJet70 < 1 ) passTrigJet70 = false;
   if( njet110 < 2 || nMuJet110 < 1 ) passTrigJet110 = false;
//   if( njet170 < 2 || nMuJet170 < 1 ) passTrigJet170 = false;
   if( njet300 == 0 || nMuJet300 < 1 ) passTrigJet300 = false;

   double psw = 1.;
   if( isdata )
     {	
	if( passTrigJet300 ) psw = ps->getPSWeight("BTagMu_Jet300_Mu5",ntP->Run,ntP->LumiBlock);
	else if( passTrigJet110 ) psw = ps->getPSWeight("BTagMu_DiJet110_Mu5",ntP->Run,ntP->LumiBlock);
	else if( passTrigJet70 ) psw = ps->getPSWeight("BTagMu_DiJet70_Mu5",ntP->Run,ntP->LumiBlock);
	else if( passTrigJet40 ) psw = ps->getPSWeight("BTagMu_DiJet40_Mu5",ntP->Run,ntP->LumiBlock);
	else if( passTrigJet20 ) psw = ps->getPSWeight("BTagMu_DiJet20_Mu5",ntP->Run,ntP->LumiBlock);
	
//	std::cout << passTrigJet20 << " " << passTrigJet40 << " " << passTrigJet70 << " " << passTrigJet110 << " " << passTrigJet300 << std::endl;
//	std::cout << psw << " " << ntP->Run << " " << ntP->LumiBlock << std::endl;
	
//	if( passTrigJet170 ) psw = ps->getPSWeight("BTagMu_DiJet170_Mu5",ntP->Run,ntP->LumiBlock);
     }
   w *= psw;
   
   if( njetPF40 == 0 ) passTrigPFJet40 = false;
   if( njetPF60 == 0 ) passTrigPFJet60 = false;
   if( njetPF80 == 0 ) passTrigPFJet80 = false;
   if( njetPF140 == 0 ) passTrigPFJet140 = false;
   if( njetPF200 == 0 ) passTrigPFJet200 = false;
   if( njetPF260 == 0 ) passTrigPFJet260 = false;
   if( njetPF320 == 0 ) passTrigPFJet320 = false;
   
   if( sample == 0 )
     {
	if( !passTrigJet20 &&
	    !passTrigJet40 &&
	    !passTrigJet70 &&
	    !passTrigJet110 &&
//	    !passTrigJet170 &&
	    !passTrigJet300 ) return;
     }
   else
     {
	if( !passTrigPFJet40 &&
	    !passTrigPFJet60 &&
	    !passTrigPFJet80 &&
	    !passTrigPFJet140 &&
	    !passTrigPFJet200 &&
	    !passTrigPFJet260 &&
	    !passTrigPFJet320 ) return;
     }
   
   // Loop on jets
   
   int nJetMax = (jmax >= 0 && ntNJET >= jmax) ? jmax+1 : ntNJET;
   
   bool foundHighestJet = 0;
   
   for(int ij=0;ij<nJetMax;ij++)
     {
//	if( foundHighestJet == 1 ) break; //FIXME
	
	if( ij != jidx && jidx >= 0 ) continue;

	if( ntP->Jet_Proba[ij] == 0 ) continue;
//	if( ntP->Jet_Proba[ij] < 0.5 ) continue;

	float jptTR = ntP->Jet_pt[ij];
	float jetaTR = fabs(ntP->Jet_eta[ij]);

	if( jetaTR > 2.4 ) continue;

//	if( jptTR > 20. && !passTrigJet20 ) continue;
	
//	if( jptTR > 20. && jptTR <= 50. && !passTrigJet20 ) continue;
//	else if( jptTR > 50. && jptTR <= 80. && !passTrigJet40 ) continue;
//	else if( jptTR > 80. && jptTR <= 120. && !passTrigJet70 ) continue;
//	else if( jptTR > 120. && jptTR <= 320. && !passTrigJet110 ) continue;
//	else if( jptTR > 320. && !passTrigJet300 ) continue;

	// start of away-tag selection
/*	bool passAway = 0;
	int idxAway = -1;
	drAway = -666;
	csvAway = -666;
	tchpAway = -666;
	jpAway = -666;
	ptAway = -666;
	etaAway = -666;
	float discMax = -666.;
	float drMin = 1.5;
	for(int ijj=0;ijj<nJetMax;ijj++)	  
	  {
	     if( ijj == ij ) continue;
	     
	     float jbtCombIVF = ntP->Jet_CombIVF[ijj];
	     float jbtJP = ntP->Jet_Proba[ijj];
	     float jbtTCHP = ntP->Jet_Ip3P[ijj];
	     float pt = ntP->Jet_pt[ijj];
	     float eta = ntP->Jet_eta[ijj];
	     
	     if( pt < 20. ) continue;
	     if( fabs(eta) > 2.4 ) continue;
	     
	     Helper *helper = new Helper();
	     float dr = helper->DeltaR(ntP->Jet_eta[ij],
				       ntP->Jet_phi[ij],
				       ntP->Jet_eta[ijj],
				       ntP->Jet_phi[ijj]);
	     delete helper;
	     
	     if( jbtCombIVF > discMax && dr > drMin ) 
	       {
		  csvAway = jbtCombIVF;
		  jpAway = jbtJP;
		  tchpAway = jbtTCHP;
		  idxAway = ijj;
		  discMax = jbtCombIVF;
		  drAway = dr;
		  ptAway = pt;
		  etaAway = eta;
	       }
	  }

	if( idxAway >= 0 ) passAway = 1;
	
//	if( discAway >= 0. ) passAway = 1;
//        if( discAway >= 0.460 ) passAway = 1;
	if( csvAway < 0.800 ) passAway = 0;
//	if( csvAway < 0.935 ) passAway = 0;
//        if( discAway >= 0.935 ) passAway = 1;
	
	if( !passAway ) continue;*/
	// end of away-tag selection
	
	Jet_Proba_New = ntP->Jet_Proba[ij];
	if( Jet_Proba_New == 0. ) Jet_Proba_New = -666.;

	v_mu = new TLorentzVector(0,0,0,0);

	int jFlavour = abs(ntP->Jet_flavour[ij]);
	if( jFlavour >= 1 && jFlavour <= 3 ) jFlavour = 1;
	
	std::string flavch = "NOTFOUND";
	int flavchI = 0;
	if( jFlavour == 5 )  {flavch = "bjet"; flavchI = 1;}
	if( jFlavour == 4 )  {flavch = "cjet"; flavchI = 2;}
	if( jFlavour == 1 || jFlavour == 21 )  {flavch = "ljet"; flavchI = 3;}
	if( jFlavour == 0 )  {flavch = "ljet"; flavchI = 3;}

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
	
	if( jpt < 20. ) passSel = false;
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
//	     if( ntP->PFMuon_IdxJet[imu] == idxAway )
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

	// cMVAv2 FIXME
/*	bool hasMuon = 0;
	bool otherJetHasMuon = 0;
	for(int imu=0;imu<ntP->nPFMuon;imu++)
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
	     
	     if( ntP->PFMuon_IdxJet[imu] == ij )
	       {		  
		  hasMuon = 1;
	       }
	     else otherJetHasMuon = 1;
	  }*/
	//

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
		  
		  // FIXME
/*		  float jetpt = ntP->Jet_pt[idxAway];
		  float jeteta = ntP->Jet_eta[idxAway];
		  float jetphi = ntP->Jet_phi[idxAway];
		  float jetm = ntP->Jet_phi[idxAway];
		  
		  TLorentzVector *vjet = new TLorentzVector(0,0,0,0);
		  vjet->SetPtEtaPhiM(jetpt,jeteta,jetphi,jetm);
		  drjmu = vjet->DeltaR(*v_mu);
		  delete vjet;*/
		  
		  drjmu = v_jet->DeltaR(*v_mu);
		  if( drjmu < 0.4 ) break;
	       }	     
	  }	

//	if( !(otherJetHasMuon && !hasMuon) ) passSel = false;
	if( drjmu > 0.4 || drjmu < 0 ) passSel = false;
	
	// END SELECTION
	
	if( passSel )
	  {
//	     foundHighestJet = 1; //FIXME
	     
	     float jbtCombSvx = ntP->Jet_CombSvx[ij];
	     float jbtCombIVF = ntP->Jet_CombIVF[ij];
	     float jbtTCHP = ntP->Jet_Ip3P[ij];
	     float jbtCMVA = ntP->Jet_cMVAv2[ij];

	     std::vector<bool> selbch_res;
	     for(int ibt=0;ibt<selb_n;ibt++) 
	       {
		  if( selb[ibt] == BTAG_NONE ) selbch_res.push_back(1);
		  else
		    {		       
		       bool passBTAG = (
					(selb[ibt] == BTAG_CSVL && jbtCombIVF >= 0.460) ||
					(selb[ibt] == BTAG_CSVM && jbtCombIVF >= 0.800) ||
					(selb[ibt] == BTAG_CSVT && jbtCombIVF >= 0.935) ||
					(selb[ibt] == BTAG_UNTAGCSVL && jbtCombIVF < 0.460) ||
					(selb[ibt] == BTAG_UNTAGCSVM && jbtCombIVF < 0.800) ||
					(selb[ibt] == BTAG_UNTAGCSVT && jbtCombIVF < 0.935) ||
					(selb[ibt] == BTAG_CMVAL && jbtCMVA >= -0.715) ||
					(selb[ibt] == BTAG_CMVAM && jbtCMVA >= 0.185) ||
					(selb[ibt] == BTAG_CMVAT && jbtCMVA >= 0.875) ||
					(selb[ibt] == BTAG_UNTAGCMVAL && jbtCMVA < -0.715) ||
					(selb[ibt] == BTAG_UNTAGCMVAM && jbtCMVA < 0.185) ||
					(selb[ibt] == BTAG_UNTAGCMVAT && jbtCMVA < 0.875)
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
//		  if( flavchI == 3 && !isdata ) sfj *= 1.27; // mind this factor
		  
		  // additional scaling to study the effect on SF
//		  if( flavchI == 1 ) sfj *= 0.80;
//		  if( flavchI == 1 ) sfj *= 1.20;
//		  if( flavchI == 2 ) sfj *= 0.80;
//		  if( flavchI == 2 ) sfj *= 1.20;
//		  if( flavchI == 3 ) sfj *= 0.80;
//		  if( flavchI == 3 ) sfj *= 1.20;
		  
		  // pileup reweighting sys
		  sfj *= syst->Pileup(npv,sys[isys],_h_pileup);
////		  sfj *= syst->Pileup(npu,sys[isys],_h_pileup);
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
				 rw->apply(&sfjj,ihb,jPtBin,ntrk,nseltrk,njet,nsv,mupt,jeta,jPT,csvAway,drAway,jpAway,-1);
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
				 rw->apply(&sfjj,ihb,jPtBin,ntrk,nseltrk,njet,nsv,mupt,jeta,jPT,csvAway,drAway,jpAway,-1);
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
	if( varId == HIST_J1_DRAWAY )
	  {		  
	     var = drAway;
	  }	     
	if( varId == HIST_J1_CSVAWAY )
	  {		  
	     var = csvAway;
	  }	     
	if( varId == HIST_J1_TCHPAWAY )
	  {
	     var = tchpAway;
	  }	     
	if( varId == HIST_J1_JPAWAY )
	  {		  
	     var = jpAway;
	  }	     
	if( varId == HIST_J1_ETAAWAY )
	  {		  
	     var = etaAway;
	  }	     
	if( varId == HIST_J1_HASMUON )
	  {		  
	     var = hasMuon;
	  }	     
	if( varId == HIST_J1_NTRKGEN )
	  {
	     if( !isdata )
	       {		  
		  Helper *helper = new Helper();
		  int flav = abs(ntP->Jet_flavour[ijet]);
		  
		  int FlavDec = 0;
		  if( flav >= 1 && flav <= 3 ) FlavDec = 3;
		  
		  if( flav == 5 )  
		    {
		       FlavDec = 1;
		    }		  
		  if( flav == 4 )  
		    {
		       FlavDec = 2;
		    }		  
		  if( flav == 1 || flav == 21 || flav == 0 )
//		  if( flav == 0 )
		    {
		       FlavDec = 3;
		    }		  
		  
		  int nChargedGen1_b = -1, nChargedGen2_b = -1;
		  
		  if( FlavDec == 1 )
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

	if( varId == HIST_J1_PTAWAY )
	  {	
	     double jptmax = 1250.;
	     double jptmin = 0.;
	     if( ibin > 0 ) 
	       {
		  jptmax = jPtMax[ibin-1];
		  jptmin = jPtMin[ibin-1];
	       }	     

	     var = (ptAway-jptmin)/(jptmax-jptmin);
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
	else if( varId == HIST_2D_J1_JP_VS_CSV )
	  {
	     varX = ntP->Jet_CombIVF[ijet];
	     varY = Jet_Proba_New;
	  }
	else if( varId == HIST_2D_J1_JP_VS_CMVA )
	  {
	     varX = ntP->Jet_cMVAv2[ijet];
	     varY = Jet_Proba_New;
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
