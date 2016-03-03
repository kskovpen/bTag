#include "../include/HistBoost.h"
#include "../include/RangesFat.h"
#include "../include/RangesSub.h"

LTANA::HistBoost::HistBoost()
{
}

LTANA::HistBoost::~HistBoost()
{
}

void LTANA::HistBoost::init()
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
   TFile *fPileup = TFile::Open("/home-pbs/kskovpen/bTagRun2/CMSSW_7_4_6_patch6/src/LTAnalysis/test/macros/npv.root");
   _h_pileup = (TH1D*)fPileup->Get("h_npv");
   
   _fout->cd();
   
   muptcut = 6.;

//   name_rw.push_back("1d_pt");
//   name_rw.push_back("1d_nseltrk");
//   name_rw.push_back("1d_njet");
//   name_rw.push_back("1d_mupt");
//   name_rw.push_back("1d_csvAway");
//   name_rw.push_back("1d_drAway");
//   name_rw.push_back("1d_jpAway");
//   name_rw.push_back("1d_eta");
   
//   name_rw_2d.push_back("2d_pt_vs_jeta");
   
//   name_rw_FatJet.push_back("FatJet_1d_pt");
//   name_rw_FatJet.push_back("FatJet_1d_nseltrk");
//   name_rw_FatJet.push_back("FatJet_1d_mass");
//   name_rw_FatJet.push_back("FatJet_1d_mupt");
   
//   name_rw_SubJet.push_back("SubJet_1d_pt");
//   name_rw_SubJet.push_back("SubJet_1d_nseltrk");
//   name_rw_SubJet.push_back("SubJet_1d_mass");
//   name_rw_SubJet.push_back("SubJet_1d_mupt");
   
   hname_FatJet.clear();
   hname_2d_FatJet.clear();

   hname_SubJet.clear();
   hname_2d_SubJet.clear();
   
   int nbins = 100;

   histNameDefined_FatJet[0] = "h_jFat_pt_";
   histNameDefined_FatJet[1] = "h_jFat_nseltrk_";
   histNameDefined_FatJet[2] = "h_jFat_eta_";
   histNameDefined_FatJet[3] = "h_jFat_ntrk_";
   histNameDefined_FatJet[4] = "h_jFat_njet_";
   histNameDefined_FatJet[5] = "h_jFat_nsv_";
   histNameDefined_FatJet[6] = "h_jFat_mupt_";
   histNameDefined_FatJet[7] = "h_jFat_JP_";
   histNameDefined_FatJet[8] = "h_pthat_";
   histNameDefined_FatJet[9] = "h_npv_";
   histNameDefined_FatJet[10] = "h_jFat_CSVIVF_";
   histNameDefined_FatJet[11] = "h_jFat_muPtRel_";
   histNameDefined_FatJet[12] = "h_jFat_ntrkGen_";
   histNameDefined_FatJet[13] = "h_jFat_drAway_";
   histNameDefined_FatJet[14] = "h_jFat_csvAway_";
   histNameDefined_FatJet[15] = "h_jFat_tchpAway_";
   histNameDefined_FatJet[16] = "h_jFat_jpAway_";
   histNameDefined_FatJet[17] = "h_jFat_ptAway_";
   histNameDefined_FatJet[18] = "h_jFat_etaAway_";
   histNameDefined_FatJet[19] = "h_jFat_tau21_";
   histNameDefined_FatJet[20] = "h_jFat_softDropMass_";
   histNameDefined_FatJet[21] = "h_jFat_mass_";
   histNameDefined_FatJet[22] = "h_jFat_drJ4J8MIN_";

   histNameDefined_SubJet[0] = "h_jSub_pt_";
   histNameDefined_SubJet[1] = "h_jSub_nseltrk_";
   histNameDefined_SubJet[2] = "h_jSub_eta_";
   histNameDefined_SubJet[3] = "h_jSub_ntrk_";
   histNameDefined_SubJet[4] = "h_jSub_njet_";
   histNameDefined_SubJet[5] = "h_jSub_nsv_";
   histNameDefined_SubJet[6] = "h_jSub_mupt_";
   histNameDefined_SubJet[7] = "h_jSub_JP_";
   histNameDefined_SubJet[8] = "h_jSub_CSVIVF_";
   histNameDefined_SubJet[9] = "h_jSub_muPtRel_";
   histNameDefined_SubJet[10] = "h_jSub_ntrkGen_";
   histNameDefined_SubJet[11] = "h_jSub_drAway_";
   histNameDefined_SubJet[12] = "h_jSub_csvAway_";
   histNameDefined_SubJet[13] = "h_jSub_tchpAway_";
   histNameDefined_SubJet[14] = "h_jSub_jpAway_";
   histNameDefined_SubJet[15] = "h_jSub_ptAway_";
   histNameDefined_SubJet[16] = "h_jSub_etaAway_";
   histNameDefined_SubJet[17] = "h_jSub_mass_";
   
   hist_FatJet.push_back(HISTFAT_J1_PT);
/*   hist_FatJet.push_back(HISTFAT_J1_NSELTRK);
   hist_FatJet.push_back(HISTFAT_J1_ETA);
   hist_FatJet.push_back(HISTFAT_J1_NTRK);
   hist_FatJet.push_back(HISTFAT_J1_NJET);
   hist_FatJet.push_back(HISTFAT_J1_MUPT);*/
   hist_FatJet.push_back(HISTFAT_J1_JP);
/*   hist_FatJet.push_back(HISTFAT_J1_TAU21);
   hist_FatJet.push_back(HISTFAT_J1_SOFTDROPMASS);
   hist_FatJet.push_back(HISTFAT_J1_MASS);
   hist_FatJet.push_back(HISTFAT_J1_DRJ4J8MIN);*/

   hist_SubJet.push_back(HISTSUB_J1_PT);
/*   hist_SubJet.push_back(HISTSUB_J1_NSELTRK);
   hist_SubJet.push_back(HISTSUB_J1_ETA);
   hist_SubJet.push_back(HISTSUB_J1_NTRK);
   hist_SubJet.push_back(HISTSUB_J1_NJET);
   hist_SubJet.push_back(HISTSUB_J1_MUPT);*/
   hist_SubJet.push_back(HISTSUB_J1_JP);
//   hist_SubJet.push_back(HISTSUB_J1_MASS);
   
   //   hist_jet.push_back(HISTFAT_PTHAT);
//   hist_jet.push_back(HISTFAT_J1_NTRKGEN);
//   hist_jet.push_back(HISTFAT_NPV);
//   hist_jet.push_back(HISTFAT_J1_DRAWAY);
//   hist_jet.push_back(HISTFAT_J1_CSVAWAY);
//   hist_jet.push_back(HISTFAT_J1_JPAWAY);
//   hist_jet.push_back(HISTFAT_J1_PTAWAY);
//   hist_jet.push_back(HISTFAT_J1_ETAAWAY);
/*   hist_jet.push_back(HISTFAT_PTHAT);
   hist_jet.push_back(HISTFAT_NPV);
   hist_jet.push_back(HISTFAT_J1_CSVIVF);
   hist_jet.push_back(HISTFAT_J1_MUPTREL);
   hist_jet.push_back(HISTFAT_J1_NTRKGEN);
   hist_jet.push_back(HISTFAT_J1_AWAYDR);
 */
   
   hist_FatJet_n = hist_FatJet.size();
   for(int ih=0;ih<hist_FatJet_n;ih++)
     {
	int idx = hist_FatJet[ih];
	histName_FatJet[ih] = histNameDefined_FatJet[idx];
     }   

   hist_SubJet_n = hist_SubJet.size();
   for(int ih=0;ih<hist_SubJet_n;ih++)
     {
	int idx = hist_SubJet[ih];
	histName_SubJet[ih] = histNameDefined_SubJet[idx];
     }   
   
   histNameDefined_FatJet_2d[0] = "h_jFat_pt_vs_jeta_";
   histNameDefined_FatJet_2d[1] = "h_jFat_JP_vs_CSV_";
   histNameDefined_FatJet_2d[2] = "h_jFat_JP_vs_CMVA_";

   histNameDefined_SubJet_2d[0] = "h_jSub_pt_vs_jeta_";
   histNameDefined_SubJet_2d[1] = "h_jSub_JP_vs_CSV_";
   histNameDefined_SubJet_2d[2] = "h_jSub_JP_vs_CMVA_";
   
//   hist_jet_2d.push_back(HISTFAT_2D_J1_JP_VS_CSV);
//   hist_jet_2d.push_back(HISTFAT_2D_J1_JP_VS_CMVA);
//   hist_jet_2d.push_back(HISTFAT_2D_J1_PT_VS_JETA);

   hist_FatJet_2d_n = hist_FatJet_2d.size();
   for(int ih=0;ih<hist_FatJet_2d_n;ih++)
     {
	int idx = hist_FatJet_2d[ih];
	histName_2d_FatJet[ih] = histNameDefined_FatJet_2d[idx];
     }   

   hist_SubJet_2d_n = hist_SubJet_2d.size();
   for(int ih=0;ih<hist_SubJet_2d_n;ih++)
     {
	int idx = hist_SubJet_2d[ih];
	histName_2d_SubJet[ih] = histNameDefined_SubJet_2d[idx];
     }   
   
   sel_FatJet.push_back("nosel");
   sel_FatJet.push_back("pt200t220");
   sel_FatJet.push_back("pt220t250");
   sel_FatJet.push_back("pt250t300");
   sel_FatJet.push_back("pt300t400");
   sel_FatJet.push_back("pt400t650");
   sel_FatJet_n = sel_FatJet.size();
   
   sel_SubJet.push_back("nosel");
   sel_SubJet.push_back("pt30t80");
   sel_SubJet.push_back("pt80t140");
   sel_SubJet.push_back("pt140t180");
   sel_SubJet.push_back("pt180t240");
   sel_SubJet.push_back("pt240t420");
   sel_SubJet_n = sel_SubJet.size();
   
   jPtMin_FatJet.push_back(200); jPtMax_FatJet.push_back(220);
   jPtMin_FatJet.push_back(220); jPtMax_FatJet.push_back(250);
   jPtMin_FatJet.push_back(250); jPtMax_FatJet.push_back(300);
   jPtMin_FatJet.push_back(300); jPtMax_FatJet.push_back(400);
   jPtMin_FatJet.push_back(400); jPtMax_FatJet.push_back(650);

   jPtMin_SubJet.push_back(30); jPtMax_SubJet.push_back(80);
   jPtMin_SubJet.push_back(80); jPtMax_SubJet.push_back(140);
   jPtMin_SubJet.push_back(140); jPtMax_SubJet.push_back(180);
   jPtMin_SubJet.push_back(180); jPtMax_SubJet.push_back(240);
   jPtMin_SubJet.push_back(240); jPtMax_SubJet.push_back(420);
   
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
   
   selb.push_back(BTAGBOOST_NONE);
   selb.push_back(BTAGBOOST_CSVL);
   selb.push_back(BTAGBOOST_CSVM);
   selb.push_back(BTAGBOOST_CSVT);
   selb.push_back(BTAGBOOST_UNTAGCSVL);
   selb.push_back(BTAGBOOST_UNTAGCSVM);
   selb.push_back(BTAGBOOST_UNTAGCSVT);
   selb.push_back(BTAGBOOST_CMVAL);
   selb.push_back(BTAGBOOST_CMVAM);
   selb.push_back(BTAGBOOST_CMVAT);
   selb.push_back(BTAGBOOST_UNTAGCMVAL);
   selb.push_back(BTAGBOOST_UNTAGCMVAM);
   selb.push_back(BTAGBOOST_UNTAGCMVAT);
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
   systSub = new LTANA::Syst();
   systSub->init("sub");

   systFat = new LTANA::Syst();
   systFat->init();
   
   // systematics to include
   
   sys_FatJet.push_back(SYS_NONE);
//   sys_FatJet.push_back(SYS_PU_UP);
//   sys_FatJet.push_back(SYS_PU_DOWN);
/*   sys_FatJet.push_back(SYS_GSPLIT_UP);
   sys_FatJet.push_back(SYS_GSPLIT_DOWN);
   sys_FatJet.push_back(SYS_BFRAG_UP);
   sys_FatJet.push_back(SYS_BFRAG_DOWN);
   sys_FatJet.push_back(SYS_CDFRAG_UP);
   sys_FatJet.push_back(SYS_CDFRAG_DOWN);
   sys_FatJet.push_back(SYS_CFRAG_UP);
   sys_FatJet.push_back(SYS_CFRAG_DOWN);
   sys_FatJet.push_back(SYS_KSL_UP);
   sys_FatJet.push_back(SYS_KSL_DOWN);
//   sys_FatJet.push_back(SYS_NTRKGEN_UP);
//   sys_FatJet.push_back(SYS_NTRKGEN_DOWN);
   sys_FatJet.push_back(SYS_JES_UP);
   sys_FatJet.push_back(SYS_JES_DOWN);*/
//   sys_FatJet.push_back(SYS_JER_UP);
//   sys_FatJet.push_back(SYS_JER_DOWN);
   
   sys_SubJet.push_back(SYS_NONE);
//   sys_SubJet.push_back(SYS_PU_UP);
//   sys_SubJet.push_back(SYS_PU_DOWN);
/*   sys_SubJet.push_back(SYS_GSPLIT_UP);
   sys_SubJet.push_back(SYS_GSPLIT_DOWN);
   sys_SubJet.push_back(SYS_BFRAG_UP);
   sys_SubJet.push_back(SYS_BFRAG_DOWN);
   sys_SubJet.push_back(SYS_CDFRAG_UP);
   sys_SubJet.push_back(SYS_CDFRAG_DOWN);
   sys_SubJet.push_back(SYS_CFRAG_UP);
   sys_SubJet.push_back(SYS_CFRAG_DOWN);
   sys_SubJet.push_back(SYS_KSL_UP);
   sys_SubJet.push_back(SYS_KSL_DOWN);
//   sys_SubJet.push_back(SYS_NTRKGEN_UP);
//   sys_SubJet.push_back(SYS_NTRKGEN_DOWN);
   sys_SubJet.push_back(SYS_JES_UP);
   sys_SubJet.push_back(SYS_JES_DOWN);*/
//   sys_SubJet.push_back(SYS_JER_UP);
//   sys_SubJet.push_back(SYS_JER_DOWN);
   
   sys_FatJet_n = sys_FatJet.size();
   sys_SubJet_n = sys_SubJet.size();
  
   for(int is=0;is<sys_FatJet_n;is++)
     {
	int idx = sys_FatJet[is];
	if( sys_FatJet[is] >= 1000 )
	  {	     
	     idx = idx/1000;
	     sysNameFat[is] = systFat->sysNameDown()[idx];
	  }	
	else
	  {
	     sysNameFat[is] = systFat->sysNameUp()[idx];
	  }
     }   

   for(int is=0;is<sys_SubJet_n;is++)
     {
	int idx = sys_SubJet[is];
	if( sys_SubJet[is] >= 1000 )
	  {	     
	     idx = idx/1000;
	     sysNameSub[is] = systSub->sysNameDown()[idx];
	  }	
	else
	  {
	     sysNameSub[is] = systSub->sysNameUp()[idx];
	  }
     }   
   
   _s_FatJet = new std::vector<std::pair<std::vector<std::string>,double*> >();
   _m1d_FatJet = new std::map<std::string, TH1D*>();

   _s2_FatJet = new std::vector<std::pair<std::vector<std::string>,double*> >();
   _m2d_FatJet = new std::map<std::string, TH2D*>();

   _s_SubJet = new std::vector<std::pair<std::vector<std::string>,double*> >();
   _m1d_SubJet = new std::map<std::string, TH1D*>();

   _s2_SubJet = new std::vector<std::pair<std::vector<std::string>,double*> >();
   _m2d_SubJet = new std::map<std::string, TH2D*>();
   
   std::string titl;

   // Fat jets
   for(int j=0;j<flav_n;j++)
     {	
	for(int ss=0;ss<sel_FatJet_n;ss++)
	  {
	     for(int se=0;se<eta_n;se++)
	       {
		  for(int ssb=0;ssb<selb_n;ssb++)
		    {
		       for(int ssa=0;ssa<seladd_n;ssa++)
			 {
			    for(int h=0;h<hist_FatJet_n;h++)
			      {
				 std::string hn = histName_FatJet[h]+flav[j]+"_"+sel_FatJet[ss]+"_"+eta[se]+"_"+selbName[ssb]+seladd[ssa];
				 hname_FatJet.push_back(hn);
				 
				 for(int s=0;s<sys_FatJet_n;s++)
				   {
				      titl = hn+sysNameFat[s];
				      std::vector<std::string> names;
				      names.clear();
				      names.push_back(titl);
				      names.push_back(sysNameFat[s]);
				      
				      int histId = hist_FatJet[h];

				      if( histId == HISTFAT_J1_PT ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_pt));
				      else if( histId == HISTFAT_J1_NSELTRK ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_nseltrk));
				      else if( histId == HISTFAT_J1_ETA ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_eta));
				      else if( histId == HISTFAT_J1_NTRK ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_ntrk));
				      else if( histId == HISTFAT_J1_NJET ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_njet));
				      else if( histId == HISTFAT_J1_NSV ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_nsv));
				      else if( histId == HISTFAT_J1_MUPT ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_mupt));
				      else if( histId == HISTFAT_PTHAT ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_pthat));
				      else if( histId == HISTFAT_NPV ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_npv));
				      else if( histId == HISTFAT_J1_CSVIVF ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_CSVIVF));
				      else if( histId == HISTFAT_J1_MUPTREL ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_muptrel));
				      else if( histId == HISTFAT_J1_NTRKGEN ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_ntrkgen));
				      else if( histId == HISTFAT_J1_DRAWAY ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_draway));
				      else if( histId == HISTFAT_J1_CSVAWAY ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_csvaway));
				      else if( histId == HISTFAT_J1_TCHPAWAY ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_tchpaway));
				      else if( histId == HISTFAT_J1_JPAWAY ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_jpaway));
				      else if( histId == HISTFAT_J1_PTAWAY ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_ptaway));
				      else if( histId == HISTFAT_J1_ETAAWAY ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_etaaway));
				      else if( histId == HISTFAT_J1_TAU21 ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_tau21));
				      else if( histId == HISTFAT_J1_SOFTDROPMASS ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_softdropmass));
				      else if( histId == HISTFAT_J1_MASS ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_mass));
				      else if( histId == HISTFAT_J1_DRJ4J8MIN ) _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_drJ4J8MIN));
				      else if( histId == HISTFAT_J1_JP )
					{
/*					   if( selb[ssb] == BTAG_NONE ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_nosel[ss]));
					   else if( selb[ssb] == BTAG_CSVL ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVL[ss]));
					   else if( selb[ssb] == BTAG_CSVM ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVM[ss]));
					   else if( selb[ssb] == BTAG_CSVT ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVT[ss]));
					   else if( selb[ssb] == BTAG_TCHPT ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_TCHPT[ss]));
					   else _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_nosel[ss]));*/
					   _s_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_JP_COMMON[ss]));
					}
				      else
					{
					   std::cout << "Range settings are not known for " << histName_FatJet[h] << std::endl;
					   exit(1);
					}
				   }				 
			      }
			    
			    for(int h=0;h<hist_FatJet_2d_n;h++)
			      {
				 std::string hn = histName_2d_FatJet[h]+flav[j]+"_"+sel_FatJet[ss]+"_"+eta[se]+"_"+selbName[ssb]+seladd[ssa];
				 hname_2d_FatJet.push_back(hn);
				 
				 for(int s=0;s<sys_FatJet_n;s++)
				   {
				      titl = hn+sysNameFat[s];
				      std::vector<std::string> names;
				      names.clear();
				      names.push_back(titl);
				      names.push_back(sysNameFat[s]);

				      int histId = hist_FatJet_2d[h];
				      
				      if( histId == HISTFAT_2D_J1_PT_VS_JETA ) _s2_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_2d_pt_vs_jeta[ss]));
				      else if( histId == HISTFAT_2D_J1_JP_VS_CSV ) _s2_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_2d_JP_vs_CSV));
				      else if( histId == HISTFAT_2D_J1_JP_VS_CMVA ) _s2_FatJet->push_back(std::make_pair(names,RANGEFAT::set_j_2d_JP_vs_CMVA));
				      else
					{
					   std::cout << "Range settings are not known for " << histName_2d_FatJet[h] << std::endl;
					   exit(1);
					}
				   }				 
			      }			    
			 }
		    }		  
	       }
	  }
     }   
   
   // Sub jets
   for(int j=0;j<flav_n;j++)
     {	
	for(int ss=0;ss<sel_SubJet_n;ss++)
	  {
	     for(int se=0;se<eta_n;se++)
	       {
		  for(int ssb=0;ssb<selb_n;ssb++)
		    {
		       for(int ssa=0;ssa<seladd_n;ssa++)
			 {
			    for(int h=0;h<hist_SubJet_n;h++)
			      {
				 std::string hn = histName_SubJet[h]+flav[j]+"_"+sel_SubJet[ss]+"_"+eta[se]+"_"+selbName[ssb]+seladd[ssa];
				 hname_SubJet.push_back(hn);
				 
				 for(int s=0;s<sys_SubJet_n;s++)
				   {
				      titl = hn+sysNameSub[s];
				      std::vector<std::string> names;
				      names.clear();
				      names.push_back(titl);
				      names.push_back(sysNameSub[s]);
				      
				      int histId = hist_SubJet[h];

				      if( histId == HISTSUB_J1_PT ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_pt));
				      else if( histId == HISTSUB_J1_NSELTRK ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_nseltrk));
				      else if( histId == HISTSUB_J1_ETA ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_eta));
				      else if( histId == HISTSUB_J1_NTRK ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_ntrk));
				      else if( histId == HISTSUB_J1_NJET ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_njet));
				      else if( histId == HISTSUB_J1_NSV ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_nsv));
				      else if( histId == HISTSUB_J1_MUPT ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_mupt));
				      else if( histId == HISTSUB_J1_CSVIVF ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_CSVIVF));
				      else if( histId == HISTSUB_J1_MUPTREL ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_muptrel));
				      else if( histId == HISTSUB_J1_NTRKGEN ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_ntrkgen));
				      else if( histId == HISTSUB_J1_DRAWAY ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_draway));
				      else if( histId == HISTSUB_J1_CSVAWAY ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_csvaway));
				      else if( histId == HISTSUB_J1_TCHPAWAY ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_tchpaway));
				      else if( histId == HISTSUB_J1_JPAWAY ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_jpaway));
				      else if( histId == HISTSUB_J1_PTAWAY ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_ptaway));
				      else if( histId == HISTSUB_J1_ETAAWAY ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_etaaway));
				      else if( histId == HISTSUB_J1_MASS ) _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_mass));
				      else if( histId == HISTSUB_J1_JP )
					{
/*					   if( selb[ssb] == BTAG_NONE ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_nosel[ss]));
					   else if( selb[ssb] == BTAG_CSVL ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVL[ss]));
					   else if( selb[ssb] == BTAG_CSVM ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVM[ss]));
					   else if( selb[ssb] == BTAG_CSVT ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_CSVT[ss]));
					   else if( selb[ssb] == BTAG_TCHPT ) _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_TCHPT[ss]));
					   else _s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP_nosel[ss]));*/
					   _s_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_JP_COMMON[ss]));
					}
				      else
					{
					   std::cout << "Range settings are not known for " << histName_SubJet[h] << std::endl;
					   exit(1);
					}
				   }				 
			      }
			    
			    for(int h=0;h<hist_SubJet_2d_n;h++)
			      {
				 std::string hn = histName_2d_SubJet[h]+flav[j]+"_"+sel_SubJet[ss]+"_"+eta[se]+"_"+selbName[ssb]+seladd[ssa];
				 hname_2d_SubJet.push_back(hn);
				 
				 for(int s=0;s<sys_SubJet_n;s++)
				   {
				      titl = hn+sysNameSub[s];
				      std::vector<std::string> names;
				      names.clear();
				      names.push_back(titl);
				      names.push_back(sysNameSub[s]);

				      int histId = hist_SubJet_2d[h];
				      
				      if( histId == HISTSUB_2D_J1_PT_VS_JETA ) _s2_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_2d_pt_vs_jeta[ss]));
				      else if( histId == HISTSUB_2D_J1_JP_VS_CSV ) _s2_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_2d_JP_vs_CSV));
				      else if( histId == HISTSUB_2D_J1_JP_VS_CMVA ) _s2_SubJet->push_back(std::make_pair(names,RANGESUB::set_j_2d_JP_vs_CMVA));
				      else
					{
					   std::cout << "Range settings are not known for " << histName_2d_SubJet[h] << std::endl;
					   exit(1);
					}
				   }				 
			      }			    
			 }
		    }		  
	       }
	  }
     }   
   
   for(int i=0;i<_s_FatJet->size();i++)
     {
	TH1D *_h1d = new TH1D(_s_FatJet->at(i).first.at(0).c_str(),
			      _s_FatJet->at(i).first.at(0).c_str(),
			      _s_FatJet->at(i).second[0],
			      _s_FatJet->at(i).second[1],
			      _s_FatJet->at(i).second[2]);
	
	_h1d->Sumw2();
	
	_m1d_FatJet->insert(std::pair<std::string,TH1D*>(_s_FatJet->at(i).first.at(0),_h1d));
     }

   for(int i=0;i<_s2_FatJet->size();i++)
     {
	TH2D *_h2d = new TH2D(_s2_FatJet->at(i).first.at(0).c_str(),
			      _s2_FatJet->at(i).first.at(0).c_str(),
			      _s2_FatJet->at(i).second[0],
			      _s2_FatJet->at(i).second[1],
			      _s2_FatJet->at(i).second[2],
			      _s2_FatJet->at(i).second[3],
			      _s2_FatJet->at(i).second[4],
			      _s2_FatJet->at(i).second[5]);
	
	_h2d->Sumw2();
	
	_m2d_FatJet->insert(std::pair<std::string,TH2D*>(_s2_FatJet->at(i).first.at(0),_h2d));
     }

   for(int i=0;i<_s_SubJet->size();i++)
     {
	TH1D *_h1d = new TH1D(_s_SubJet->at(i).first.at(0).c_str(),
			      _s_SubJet->at(i).first.at(0).c_str(),
			      _s_SubJet->at(i).second[0],
			      _s_SubJet->at(i).second[1],
			      _s_SubJet->at(i).second[2]);
	
	_h1d->Sumw2();
	
	_m1d_SubJet->insert(std::pair<std::string,TH1D*>(_s_SubJet->at(i).first.at(0),_h1d));
     }

   for(int i=0;i<_s2_SubJet->size();i++)
     {
	TH2D *_h2d = new TH2D(_s2_SubJet->at(i).first.at(0).c_str(),
			      _s2_SubJet->at(i).first.at(0).c_str(),
			      _s2_SubJet->at(i).second[0],
			      _s2_SubJet->at(i).second[1],
			      _s2_SubJet->at(i).second[2],
			      _s2_SubJet->at(i).second[3],
			      _s2_SubJet->at(i).second[4],
			      _s2_SubJet->at(i).second[5]);
	
	_h2d->Sumw2();
	
	_m2d_SubJet->insert(std::pair<std::string,TH2D*>(_s2_SubJet->at(i).first.at(0),_h2d));
     }
   
   if( !isdata )
     {	
	rw_FatJet = new LTANA::Reweight();
	rw_FatJet->init(doRW,jPtMin_FatJet,jPtMax_FatJet,sel_FatJet,selbName,name_rw_FatJet,name_rw_2d_FatJet);

	rw_SubJet = new LTANA::Reweight();
	rw_SubJet->init(doRW,jPtMin_SubJet,jPtMax_SubJet,sel_SubJet,selbName,name_rw_SubJet,name_rw_2d_SubJet);
     }   
  
   for(int j=0;j<flav_n;j++)
     {	
	for(int ss=0;ss<sel_FatJet_n;ss++)
	  {
	     for(int se=0;se<eta_n;se++)
	       {   
		  for(int ssb=0;ssb<selb_n;ssb++)
		    {
		       for(int ssa=0;ssa<seladd_n;ssa++)
			 {
			    for(int s=0;s<sys_FatJet_n;s++)
			      {
				 for(int h=0;h<hist_FatJet_n;h++)
				   {
				      histNAMES_FatJet[j][ss][se][ssb][ssa][h][s] =
					histName_FatJet[h]+flav[j]+"_"+sel_FatJet[ss]+"_"+eta[se]+"_"+selbName[ssb]+seladd[ssa]+sysNameFat[s];
				   }

				 for(int h=0;h<hist_FatJet_2d_n;h++)
				   {
				      histNAMES_2d_FatJet[j][ss][se][ssb][ssa][h][s] =
					histName_2d_FatJet[h]+flav[j]+"_"+sel_FatJet[ss]+"_"+eta[se]+"_"+selbName[ssb]+seladd[ssa]+sysNameFat[s];
				   }
			      }			    
			 }		       
		    }		  
	       }
	  }
     }

   for(int j=0;j<flav_n;j++)
     {	
	for(int ss=0;ss<sel_SubJet_n;ss++)
	  {
	     for(int se=0;se<eta_n;se++)
	       {   
		  for(int ssb=0;ssb<selb_n;ssb++)
		    {
		       for(int ssa=0;ssa<seladd_n;ssa++)
			 {
			    for(int s=0;s<sys_SubJet_n;s++)
			      {
				 for(int h=0;h<hist_SubJet_n;h++)
				   {
				      histNAMES_SubJet[j][ss][se][ssb][ssa][h][s] =
					histName_SubJet[h]+flav[j]+"_"+sel_SubJet[ss]+"_"+eta[se]+"_"+selbName[ssb]+seladd[ssa]+sysNameSub[s];
				   }

				 for(int h=0;h<hist_SubJet_2d_n;h++)
				   {
				      histNAMES_2d_SubJet[j][ss][se][ssb][ssa][h][s] =
					histName_2d_SubJet[h]+flav[j]+"_"+sel_SubJet[ss]+"_"+eta[se]+"_"+selbName[ssb]+seladd[ssa]+sysNameSub[s];
				   }
			      }			    
			 }		       
		    }		  
	       }
	  }
     }
   
   std::cout << "Initialisation done" << std::endl;
}

void LTANA::HistBoost::fill()
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
   
   int npu = ntP->nPU;
   int npv = ntP->nPV;
   if( npu > 34 ) npu = 34;

//   int jmax = 0; // highest-Pt jet
   int jmax = -1; // all jets
      
//   int jidx = 0; // only the highest-Pt jet
   int jidx = -1; // all jets

   // Event

   int ntNJET8 = ntPSub->FatJetInfo_nJet;
   int ntNJET4 = ntP->nJet;

   // 'overcut' for trigger selection
/*   int nJet30 = 0;
   for( int ij=0;ij<ntNJET;ij++ )
     {
	if( ntPSub->FatJetInfo_Jet_pt[ij] > 30. ) nJet30++;
     }	
   if( nJet30 < 2 ) return;*/

   int nFatJet200 = 0;
   int nFatJet400 = 0;
   for( int ij=0;ij<ntNJET8;ij++ )
     {
	if( ntPSub->FatJetInfo_Jet_pt[ij] > 200. ) nFatJet200++;
	if( ntPSub->FatJetInfo_Jet_pt[ij] > 400. ) nFatJet400++;
     }	
   if( nFatJet200 < 1 ) return;
//   if( nFatJet400 < 1 ) return;
   
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
   
   bool passTrigPFJet40 = passTrig(2);
   bool passTrigPFJet60 = passTrig(87);
   bool passTrigPFJet80 = passTrig(7);
   bool passTrigPFJet140 = passTrig(12);
   bool passTrigPFJet200 = passTrig(15);
   bool passTrigPFJet260 = passTrig(17);
   bool passTrigPFJet320 = passTrig(19);
   bool passTrigPFJet400 = passTrig(21);
   bool passTrigPFJet450 = passTrig(88);
   bool passTrigPFJet500 = passTrig(89);
   
   int bitIdx;
   int trigIdx;

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
     njet110 = 0, njet300 = 0;

   int nMuJet20 = 0, nMuJet40 = 0, nMuJet70 = 0,
     nMuJet110 = 0, nMuJet300 = 0;
   
   int njetPF40 = 0, njetPF60 = 0, njetPF80 = 0,
     njetPF140 = 0, njetPF200 = 0,
     njetPF260 = 0, njetPF320 = 0, njetPF400 = 0, njetPF450 = 0, njetPF500 = 0;

   int idxMuJet = -1;
   for(int ij=0;ij<ntNJET4;ij++)
     {
	float jpt = ntP->Jet_pt[ij];
	float jeta = ntP->Jet_eta[ij];
	float jphi = ntP->Jet_phi[ij];

	if( fabs(jpt) < 30. ) continue;
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
		  if( idxMuJet < 0 ) idxMuJet = ij;
	       }
	  }

	if( jpt > 30 && jpt <= 50 )  njet20++;
	if( jpt > 30 && jpt <= 50 && nMuJet ) nMuJet20++;
	if( jpt > 50 && jpt <= 80 )  njet40++;
	if( jpt > 50 && jpt <= 80 && nMuJet ) nMuJet40++;
	if( jpt > 80 && jpt <= 120 )  njet70++;
	if( jpt > 80 && jpt <= 120 && nMuJet ) nMuJet70++;
	if( jpt > 120 && jpt <= 320 ) njet110++;
	if( jpt > 120 && jpt <= 320 && nMuJet ) nMuJet110++;
	if( jpt > 320 ) njet300++;
	if( jpt > 320 && nMuJet ) nMuJet300++;
	
/*	if( jpt > 50 && jpt <= 70 )  njetPF40++;
	if( jpt > 70 && jpt <= 100 )  njetPF60++;
	if( jpt > 100 && jpt <= 160 ) njetPF80++;
	if( jpt > 160 && jpt <= 220 ) njetPF140++;*/
	if( jpt > 220 && jpt <= 310 ) njetPF200++;
	if( jpt > 310 && jpt <= 360 ) njetPF260++;
	if( jpt > 360 && jpt <= 450 ) njetPF320++;
	if( jpt > 450 ) njetPF400++;
/*	if( jpt > 500 && jpt <= 550 ) njetPF450++;
	if( jpt > 550 ) njetPF500++;*/
     }      
   if( njet20 < 2 || nMuJet20 < 1 ) passTrigJet20 = false;
   if( njet40 < 2 || nMuJet40 < 1 ) passTrigJet40 = false;
   if( njet70 < 2 || nMuJet70 < 1 ) passTrigJet70 = false;
   if( njet110 < 2 || nMuJet110 < 1 ) passTrigJet110 = false;  
   if( njet300 == 0 || nMuJet300 < 1 ) passTrigJet300 = false;

   if( njetPF40 == 0 ) passTrigPFJet40 = false;
   if( njetPF60 == 0 ) passTrigPFJet60 = false;
   if( njetPF80 == 0 ) passTrigPFJet80 = false;
   if( njetPF140 == 0 ) passTrigPFJet140 = false;
   if( njetPF200 == 0 ) passTrigPFJet200 = false;
   if( njetPF260 == 0 ) passTrigPFJet260 = false;
   if( njetPF320 == 0 ) passTrigPFJet320 = false;
   if( njetPF400 == 0 ) passTrigPFJet400 = false;
   if( njetPF450 == 0 ) passTrigPFJet450 = false;
   if( njetPF500 == 0 ) passTrigPFJet500 = false;
   
   if( sample == 0 )
     {
	if( 
	   !passTrigJet20 &&
	   !passTrigJet40 &&
	   !passTrigJet70 &&
	   !passTrigJet110 &&
	   !passTrigJet300 
	  ) return;
     }
   else
     {
	if( 
//	   !passTrigPFJet40 &&
//	   !passTrigPFJet60 &&
//	   !passTrigPFJet80 &&
//	   !passTrigPFJet140 && 
	   !passTrigPFJet200 &&
	   !passTrigPFJet260 &&
	   !passTrigPFJet320 &&
	   !passTrigPFJet400
//	   !passTrigPFJet450
//	   !passTrigPFJet500
	  ) return;	
     }

   drj4j8Min = 666.;
   for(int ij4=0;ij4<ntP->nJet;ij4++)
     {
	if( ij4 != idxMuJet ) continue;
	
	double j4pt = ntP->Jet_pt[ij4];
	if( j4pt < 30 ) continue;
	
	double j4eta = ntP->Jet_eta[ij4];
	double j4phi = ntP->Jet_phi[ij4];
	
	if( fabs(j4eta) > 2.4 ) continue;
	
	for(int ij8=0;ij8<ntPSub->FatJetInfo_nJet;ij8++)
	  {
	     double j8pt = ntPSub->FatJetInfo_Jet_pt[ij8];
	     if( j8pt < 200 ) continue;
//	     if( j8pt < 400 ) continue;
	     
	     double j8eta = ntPSub->FatJetInfo_Jet_eta[ij8];
	     double j8phi = ntPSub->FatJetInfo_Jet_phi[ij8];
	     
	     if( fabs(j8eta) > 2.4 ) continue;
	     
	     Helper *helper = new Helper();
	     float j4j8dr = helper->DeltaR(j4eta,j4phi,j8eta,j8phi);
	     delete helper;
	     
	     if( j4j8dr < drj4j8Min ) drj4j8Min = j4j8dr;
	  }
     }
   
   // Loop on Fat jets
  
   int nFatJetMax = (jmax >= 0 && ntNJET8 >= jmax) ? jmax+1 : ntNJET8;

   // find away tag fat jet
   int idxMuFatJet = -1;
   for(int ij=0;ij<nFatJetMax;ij++)
     {
	if( ij != jidx && jidx >= 0 ) continue;

	float jFatptTR = ntPSub->FatJetInfo_Jet_pt[ij];
	float jFatetaTR = fabs(ntPSub->FatJetInfo_Jet_eta[ij]);

	if( jFatptTR < 200. ) continue;
//	if( jFatptTR < 400. ) continue;
	if( jFatetaTR > 2.4 ) continue;
	
	if( ntPSub->FatJetInfo_Jet_CombIVF[ij] < 0.800 ) continue;
	
	for(int imu=0;imu<ntPSub->FatJetInfo_nPFMuon;imu++)
	  {
	     if( ntPSub->FatJetInfo_PFMuon_IdxJet[imu] == ij )
	       {	     
		  if( ntPSub->FatJetInfo_PFMuon_isGlobal[imu] == 0 ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_pt[imu] < muptcut ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_nMuHit[imu] == 0 ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_nTkHit[imu] < 11 ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_nPixHit[imu] < 2 ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_nOutHit[imu] > 2 ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_nMatched[imu] < 2 ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_chi2[imu] > 10. ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_chi2Tk[imu] > 10. ) continue;
		  if( fabs(ntPSub->FatJetInfo_PFMuon_eta[imu]) > 2.4 ) continue;		  
		  idxMuFatJet = ij;
		  break;
	       }
	  }
     }   
   
   v_mu_FatJet = new TLorentzVector(0,0,0,0);
   
   for(int ij=0;ij<nFatJetMax;ij++)
     {
	if( ij != jidx && jidx >= 0 ) continue;
	
//	if( idxMuFatJet < 0 ) break;
//	if( idxMuFatJet == ij ) continue;

/*	Helper *helper = new Helper();
	float drAway = helper->DeltaR(ntPSub->FatJetInfo_Jet_eta[ij],
				      ntPSub->FatJetInfo_Jet_phi[ij],
				      ntPSub->FatJetInfo_Jet_eta[idxMuFatJet],
				      ntPSub->FatJetInfo_Jet_phi[idxMuFatJet]);
	delete helper;
	if( drAway < 1.5 ) continue;
*/
	if( ntPSub->FatJetInfo_Jet_Proba[ij] == 0 ) continue;
//	if( ntPSub->FatJetInfo_Jet_Proba[ij] < 0.5 ) continue;

	float jFatptTR = ntPSub->FatJetInfo_Jet_pt[ij];
	float jFatetaTR = fabs(ntPSub->FatJetInfo_Jet_eta[ij]);

	if( jFatptTR < 200. ) continue;
//	if( jFatptTR < 400. ) continue;
	if( jFatetaTR > 2.4 ) continue;

	FatJet_tau21 = (ntPSub->FatJetInfo_Jet_tau1[ij] != 0.) ? ntPSub->FatJetInfo_Jet_tau2[ij]/ntPSub->FatJetInfo_Jet_tau1[ij] : -666.;
//	if( FatJet_tau21 >= 0.5 ) continue;

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
	     
	     float jbtCombIVF = ntPSub->FatJetInfo_Jet_CombIVF[ijj];
	     float jbtJP = ntPSub->FatJetInfo_Jet_Proba[ijj];
	     float jbtTCHP = ntPSub->FatJetInfo_Jet_Ip3P[ijj];
	     float pt = ntPSub->FatJetInfo_Jet_pt[ijj];
	     float eta = ntPSub->FatJetInfo_Jet_eta[ijj];
	     
	     if( pt < 20. ) continue;
	     if( fabs(eta) > 2.4 ) continue;
	     
	     Helper *helper = new Helper();
	     float dr = helper->DeltaR(ntPSub->FatJetInfo_Jet_eta[ij],
				       ntPSub->FatJetInfo_Jet_phi[ij],
				       ntPSub->FatJetInfo_Jet_eta[ijj],
				       ntPSub->FatJetInfo_Jet_phi[ijj]);
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
//        if( discAway >= 0.935 ) passAway = 1;
	
	if( !passAway ) continue;*/
	// end of away-tag selection
	
	bool passSel = true;
	
	float jFateta = ntPSub->FatJetInfo_Jet_eta[ij];
	float jFatphi = ntPSub->FatJetInfo_Jet_phi[ij];
	float jFatm = ntPSub->FatJetInfo_Jet_mass[ij];
//	float residual = 1.;
//	if( ntP->Run > 0 ) residual = ntP->Jet_residual[ij];
//	float jpt = ntP->Jet_pt[ij] * residual;

	float jFatpt = ntPSub->FatJetInfo_Jet_pt[ij];
	
	if( jFatpt < 200. ) passSel = false;
//	if( jFatpt < 400. ) passSel = false;
	if( fabs(jFateta) > 2.4 ) passSel = false;

	int nFatjet = ntNJET8;
	
	int nsv = ntP->nSV;

	systFat->JEC(ij,0);
	v_FatJet = systFat->v_jet();
	
	muidx.clear();
	for(int imu=0;imu<ntPSub->FatJetInfo_nPFMuon;imu++)
	  {
	     if( ntPSub->FatJetInfo_PFMuon_IdxJet[imu] == ij )
	       {	     
		  if( ntPSub->FatJetInfo_PFMuon_isGlobal[imu] == 0 ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_pt[imu] < muptcut ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_nMuHit[imu] == 0 ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_nTkHit[imu] < 11 ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_nPixHit[imu] < 2 ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_nOutHit[imu] > 2 ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_nMatched[imu] < 2 ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_chi2[imu] > 10. ) continue;
		  if( ntPSub->FatJetInfo_PFMuon_chi2Tk[imu] > 10. ) continue;
		  if( fabs(ntPSub->FatJetInfo_PFMuon_eta[imu]) > 2.4 ) continue;
		  muidx.push_back(imu);
	       }
	  }
	bool passMuonInJet = (muidx.size() > 0);
   
	float drjmu = 666.;
	
	v_mu_FatJet->SetPtEtaPhiM(0,0,0,0);

	muIdx = -1;
	if( passMuonInJet )
	  {
	     for(int im=0;im<muidx.size();im++)
	       {		  
		  float mupt = ntPSub->FatJetInfo_PFMuon_pt[muidx[im]];
		  float mueta = ntPSub->FatJetInfo_PFMuon_eta[muidx[im]];
		  float muphi = ntPSub->FatJetInfo_PFMuon_phi[muidx[im]];
		  float mum = 0.10566;
		  v_mu_FatJet->SetPtEtaPhiM(mupt,mueta,muphi,mum);
		  drjmu = v_FatJet->DeltaR(*v_mu_FatJet);
		  muIdx = im;
		  if( drjmu < 0.8 ) break;
	       }	     
	  }	
	
	if( drjmu > 0.8 ) passSel = false;
	
	float mupt = -1.;
	if( muIdx >= 0 )
	  mupt = ntPSub->FatJetInfo_PFMuon_pt[muidx[muIdx]];

	// END SELECTION

	// Fat jets
	if( passSel )
	  {
	     int Fatntrk = ntPSub->FatJetInfo_Jet_ntracks[ij];
	     int Fatnseltrk = ntPSub->FatJetInfo_Jet_nseltracks[ij];

	     float jFatMass = ntPSub->FatJetInfo_Jet_mass[ij];
	     
	     FatJet_Proba_New = ntPSub->FatJetInfo_Jet_Proba[ij];
	     if( FatJet_Proba_New == 0. ) FatJet_Proba_New = -666.;

	     int jFatFlavour = abs(ntPSub->FatJetInfo_Jet_flavour[ij]);
	     if( jFatFlavour >= 1 && jFatFlavour <= 3 ) jFatFlavour = 1;
	     
	     std::string flavch = "NOTFOUND";
	     int FatflavchI = 0;
	     if( jFatFlavour == 5 )  {flavch = "bjet"; FatflavchI = 1;}
	     if( jFatFlavour == 4 )  {flavch = "cjet"; FatflavchI = 2;}
	     if( jFatFlavour == 1 || jFatFlavour == 21 )  {flavch = "ljet"; FatflavchI = 3;}
	     if( jFatFlavour == 0 )  {flavch = "ljet"; FatflavchI = 3;}	     
	     
	     std::string selch = "NOTFOUND";
	     std::string etach = "NOTFOUND";
	     std::string selbch = "NOTFOUND";
	     
	     float jbtCombSvx = ntPSub->FatJetInfo_Jet_CombSvx[ij];
	     float jbtCombIVF = ntPSub->FatJetInfo_Jet_CombIVF[ij];
	     float jbtTCHP = ntPSub->FatJetInfo_Jet_Ip3P[ij];
	     float jbtCMVA = ntPSub->FatJetInfo_Jet_cMVAv2[ij];

	     std::vector<bool> selbch_res;
	     for(int ibt=0;ibt<selb_n;ibt++) 
	       {
		  if( selb[ibt] == BTAGBOOST_NONE ) selbch_res.push_back(1);
		  else
		    {		       
		       bool passBTAG = (
					(selb[ibt] == BTAGBOOST_CSVL && jbtCombIVF >= 0.460) ||
					(selb[ibt] == BTAGBOOST_CSVM && jbtCombIVF >= 0.800) ||
					(selb[ibt] == BTAGBOOST_CSVT && jbtCombIVF >= 0.935) ||
					(selb[ibt] == BTAGBOOST_UNTAGCSVL && jbtCombIVF < 0.460) ||
					(selb[ibt] == BTAGBOOST_UNTAGCSVM && jbtCombIVF < 0.800) ||
					(selb[ibt] == BTAGBOOST_UNTAGCSVT && jbtCombIVF < 0.935) ||
					(selb[ibt] == BTAGBOOST_CMVAL && jbtCMVA >= -0.715) ||
					(selb[ibt] == BTAGBOOST_CMVAM && jbtCMVA >= 0.185) ||
					(selb[ibt] == BTAGBOOST_CMVAT && jbtCMVA >= 0.875) ||
					(selb[ibt] == BTAGBOOST_UNTAGCMVAL && jbtCMVA < -0.715) ||
					(selb[ibt] == BTAGBOOST_UNTAGCMVAM && jbtCMVA < 0.185) ||
					(selb[ibt] == BTAGBOOST_UNTAGCMVAT && jbtCMVA < 0.875)
					);
		       if( passBTAG ) selbch_res.push_back(1);
		       else selbch_res.push_back(0);
		    }
	       }
	     
	     bool selach_res[seladd_n];
	     for( int ibt=0;ibt<seladd_n;ibt++ ) selach_res[ibt] = false;

	     selach_res[0] = true;

	     for(int isys=0;isys<sys_FatJet_n;isys++)
	       {	
		  float jPT = getPt(sys_FatJet[isys],0);
		  
		  float sfj = w;
		    
		  // l-jets are underestimated in MC by 1.27
		  if( FatflavchI == 3 && !isdata ) sfj *= 1.27;

		  // additional scaling to study the effect on SF
//		  if( flavchI == 1 ) sfj *= 0.80;
//		  if( flavchI == 1 ) sfj *= 1.20;
//		  if( flavchI == 2 ) sfj *= 0.80;
//		  if( flavchI == 2 ) sfj *= 1.20;
//		  if( flavchI == 3 ) sfj *= 0.80;
//		  if( flavchI == 3 ) sfj *= 1.20;
		  
		  // pileup reweighting sys
		  sfj *= systFat->Pileup(npv,sys_FatJet[isys],_h_pileup);
//		  sfj *= syst->Pileup(npu,sys[isys]);

		  // gluon splitting sys
		  sfj *= systFat->GluonSplitting(ij,FatflavchI,sys_FatJet[isys]);
		  
		  // b fragmentation sys
		  sfj *= systFat->bFrag(ij,FatflavchI,sys_FatJet[isys]);
		  
		  // c->D fragmentation sys
		  sfj *= systFat->cdFrag(ij,FatflavchI,sys_FatJet[isys]);
		  
		  // c fragmentation sys
		  sfj *= systFat->cFrag(ij,FatflavchI,sys_FatJet[isys]);
		  
		  // K0s Lambda sys
		  sfj *= systFat->Ks(ij,FatflavchI,sys_FatJet[isys]);
		  
		  // generated ntrk in b- and c- hadron decays sys
		  sfj *= systFat->GenNTrk(ij,FatflavchI,sys_FatJet[isys]);

		  int jPtBin = 0;

		  if( jPT >= jPtMin_FatJet[0] && jPT <= jPtMax_FatJet[0] )   {selch = "pt200t220"; jPtBin = 1;}
		  if( jPT >= jPtMin_FatJet[1] && jPT <= jPtMax_FatJet[1] )   {selch = "pt220t250"; jPtBin = 2;}
		  if( jPT >= jPtMin_FatJet[2] && jPT <= jPtMax_FatJet[2] )   {selch = "pt250t300"; jPtBin = 3;}
		  if( jPT >= jPtMin_FatJet[3] && jPT <= jPtMax_FatJet[3] )   {selch = "pt300t400"; jPtBin = 4;}
		  if( jPT > jPtMin_FatJet[4] )   {selch = "pt400t650"; jPtBin = 5;}

		  double jPtMinCur = 0.;
		  double jPtMaxCur = 1500.;
		  
		  if( jPtBin > 0 )
		    {		       
		       jPtMinCur = jPtMin_FatJet[jPtBin-1];
		       jPtMaxCur = jPtMax_FatJet[jPtBin-1];
		    }		  
		  
		  bool jeta_res[eta_n];
		  for( int ibt=0;ibt<eta_n;ibt++ ) jeta_res[ibt] = false;
		  		  
		  jeta_res[0] = true;

		  // 1d
		  std::vector<std::string> histNAMESSEL;
		  std::vector<float> sfJ;
		  std::vector<int> histSYS;
		  std::vector<int> histVAR;

		  for(int ih=0;ih<hist_FatJet_n;ih++)
		    {
		       for(int ihb=0;ihb<selb_n;ihb++)
			 {
			    if( !selbch_res[ihb] ) continue;
			    
			    float sfjj = sfj;

			    if( !isdata ) 
			      {
				 rw_FatJet->apply(&sfjj,ihb,jPtBin,Fatntrk,Fatnseltrk,nFatjet,nsv,mupt,jFateta,jPT,csvAway,drAway,jpAway,jFatMass);
			      }			    

			    for(int iha=0;iha<seladd_n;iha++)
			      {
				 if( !selach_res[iha] ) continue;
			    
				 for(int ihe=0;ihe<eta_n;ihe++)
				   {
				      if( !jeta_res[ihe] ) continue;
				      
				      histNAMESSEL.push_back(histNAMES_FatJet[FatflavchI][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL.push_back(histNAMES_FatJet[0][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL.push_back(histNAMES_FatJet[FatflavchI][0][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL.push_back(histNAMES_FatJet[0][0][ihe][ihb][iha][ih][isys]);
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
		       TH1D *h = _m1d_FatJet->find(histNAMESSEL.at(ih))->second;

		       int hidx = int(ih/4);
		       fillThis = true;
		       float var;
		       std::vector<float> varv;
		       int varId = hist_FatJet[histVAR[hidx]];
		       var = getVar(sys_FatJet[histSYS[hidx]],ij,varId,jPtBin,0);
		       
		       if( fillThis )
			 {
			    float sfc = sfJ[hidx];
			    h->Fill(var,sfc);
			 }		       
		    }
		  
		  histNAMESSEL.clear();

		  // 2d
		  std::vector<std::string> histNAMESSEL_2d;
		  std::vector<float> sfJ_2d;
		  std::vector<int> histSYS_2d;
		  std::vector<int> histVAR_2d;

		  for(int ih=0;ih<hist_FatJet_2d_n;ih++)
		    {
		       for(int ihb=0;ihb<selb_n;ihb++)
			 {
			    if( !selbch_res[ihb] ) continue;
			    
			    float sfjj = sfj;

			    if( !isdata )
			      {
				 rw_FatJet->apply(&sfjj,ihb,jPtBin,Fatntrk,Fatnseltrk,nFatjet,nsv,mupt,jFateta,jPT,csvAway,drAway,jpAway,jFatMass);
			      }			    

			    for(int iha=0;iha<seladd_n;iha++)
			      {
				 if( !selach_res[iha] ) continue;
			    
				 for(int ihe=0;ihe<eta_n;ihe++)
				   {
				      if( !jeta_res[ihe] ) continue;
				      
				      histNAMESSEL_2d.push_back(histNAMES_2d_FatJet[FatflavchI][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_2d.push_back(histNAMES_2d_FatJet[0][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_2d.push_back(histNAMES_2d_FatJet[FatflavchI][0][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_2d.push_back(histNAMES_2d_FatJet[0][0][ihe][ihb][iha][ih][isys]);
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
		       TH2D *h = _m2d_FatJet->find(histNAMESSEL_2d.at(ih))->second;

		       int hidx = int(ih/4);
		       fillThis = true;
		       int varId = hist_FatJet_2d[histVAR_2d[hidx]];
		       std::vector<float> var = getVar2d(sys_FatJet[histSYS_2d[hidx]],ij,varId,jPtBin,0);
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

	// Sub jets
	if( passSel )
	  {
	     int nSubJets = ntPSub->SoftDropSubJetInfo_nJet;

	     // find the highest-pT subjet containing muon
	     int idxSubJetWithMuon = -1;
	     for(int isj=0;isj<nSubJets;isj++)
	       {		  		  
		  int fJetIdx = ntPSub->SoftDropSubJetInfo_Jet_FatJetIdx[isj];
		  if( ij != fJetIdx ) continue;

		  float jSubptTR = ntPSub->SoftDropSubJetInfo_Jet_pt[isj];
		  float jSubetaTR = fabs(ntPSub->SoftDropSubJetInfo_Jet_eta[isj]);
		  
		  if( jSubptTR < 30. ) continue;
		  if( jSubetaTR > 2.4 ) continue;

		  if( ntPSub->SoftDropSubJetInfo_Jet_CombIVF[isj] < 0.800 ) continue;

		  for(int imuSub=0;imuSub<ntPSub->SoftDropSubJetInfo_nPFMuon;imuSub++)
		    {
		       if( ntPSub->SoftDropSubJetInfo_PFMuon_IdxJet[imuSub] == isj )
			 {	     
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_isGlobal[imuSub] == 0 ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_pt[imuSub] < muptcut ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_nMuHit[imuSub] == 0 ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_nTkHit[imuSub] < 11 ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_nPixHit[imuSub] < 2 ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_nOutHit[imuSub] > 2 ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_nMatched[imuSub] < 2 ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_chi2[imuSub] > 10. ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_chi2Tk[imuSub] > 10. ) continue;
			    if( fabs(ntPSub->SoftDropSubJetInfo_PFMuon_eta[imuSub]) > 2.4 ) continue;
			    idxSubJetWithMuon = isj;
			    break;
			 }
		    }

		  // don't change it
		  if( ntPSub->SoftDropSubJetInfo_Jet_Proba[isj] == 0 ) continue;
		  
		  if( idxSubJetWithMuon >= 0 ) break;
	       }	     

	     int nSubJetSelected = 0;
	     for(int isj=0;isj<nSubJets;isj++)
	       {
//		  if( idxSubJetWithMuon < 0 ) break;
		    
//		  if( idxSubJetWithMuon == isj ) continue;
		  
//		  if( nSubJetSelected >= 1 ) break;
		  
		  int fJetIdx = ntPSub->SoftDropSubJetInfo_Jet_FatJetIdx[isj];
		  if( ij != fJetIdx ) continue;

		  float jSubptTR = ntPSub->SoftDropSubJetInfo_Jet_pt[isj];
		  float jSubetaTR = fabs(ntPSub->SoftDropSubJetInfo_Jet_eta[isj]);
		  
		  if( jSubptTR < 30. ) continue;
		  if( jSubetaTR > 2.4 ) continue;
		  
		  if( ntPSub->SoftDropSubJetInfo_Jet_Proba[isj] == 0 ) continue;

		  float jSubMass = ntPSub->SoftDropSubJetInfo_Jet_mass[isj];
		  
		  std::vector<int> muidxSub;
		  muidxSub.clear();
		  for(int imuSub=0;imuSub<ntPSub->SoftDropSubJetInfo_nPFMuon;imuSub++)
		    {
		       if( ntPSub->SoftDropSubJetInfo_PFMuon_IdxJet[imuSub] == isj )
			 {	     
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_isGlobal[imuSub] == 0 ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_pt[imuSub] < muptcut ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_nMuHit[imuSub] == 0 ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_nTkHit[imuSub] < 11 ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_nPixHit[imuSub] < 2 ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_nOutHit[imuSub] > 2 ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_nMatched[imuSub] < 2 ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_chi2[imuSub] > 10. ) continue;
			    if( ntPSub->SoftDropSubJetInfo_PFMuon_chi2Tk[imuSub] > 10. ) continue;
			    if( fabs(ntPSub->SoftDropSubJetInfo_PFMuon_eta[imuSub]) > 2.4 ) continue;
			    muidxSub.push_back(imuSub);
			 }
		    }
		  bool passMuonInSubJet = (muidxSub.size() > 0);
		  
		  systSub->JEC(isj,1);
		  v_SubJet = systSub->v_jet();

		  TLorentzVector *v_mu_SubJet = new TLorentzVector(0,0,0,0);
		  int muIdxSub = -1;
		  float drjmuSub = 666.;
		  if( passMuonInSubJet )
		    {
		       for(int imSub=0;imSub<muidxSub.size();imSub++)
			 {		  
			    float mupt = ntPSub->SoftDropSubJetInfo_PFMuon_pt[muidxSub[imSub]];
			    float mueta = ntPSub->SoftDropSubJetInfo_PFMuon_eta[muidxSub[imSub]];
			    float muphi = ntPSub->SoftDropSubJetInfo_PFMuon_phi[muidxSub[imSub]];
			    float mum = 0.10566;
			    v_mu_SubJet->SetPtEtaPhiM(mupt,mueta,muphi,mum);
			    drjmuSub = v_SubJet->DeltaR(*v_mu_SubJet);
			    muIdxSub = imSub;
			    if( drjmuSub < 0.4 ) break;
			 }	     
		    }	
		  delete v_mu_SubJet;
		  
		  if( drjmuSub > 0.4 ) passMuonInSubJet = false;
		  
		  if( !passMuonInSubJet ) continue;
		  
		  int Subntrk = ntPSub->SoftDropSubJetInfo_Jet_ntracks[isj];
		  int Subnseltrk = ntPSub->SoftDropSubJetInfo_Jet_nseltracks[isj];
		  int jSubeta = ntPSub->SoftDropSubJetInfo_Jet_eta[isj];		  
		  
		  SubJet_Proba_New = ntPSub->SoftDropSubJetInfo_Jet_Proba[isj];
		  if( SubJet_Proba_New == 0. ) SubJet_Proba_New = -666.;
		  
		  int jSubFlavour = abs(ntPSub->SoftDropSubJetInfo_Jet_flavour[isj]);
		  if( jSubFlavour >= 1 && jSubFlavour <= 3 ) jSubFlavour = 1;
		  
		  std::string flavch = "NOTFOUND";
		  int SubflavchI = 0;
		  if( jSubFlavour == 5 )  {flavch = "bjet"; SubflavchI = 1;}
		  if( jSubFlavour == 4 )  {flavch = "cjet"; SubflavchI = 2;}
		  if( jSubFlavour == 1 || jSubFlavour == 21 )  {flavch = "ljet"; SubflavchI = 3;}
		  if( jSubFlavour == 0 )  {flavch = "ljet"; SubflavchI = 3;}
		  
		  std::string selch = "NOTFOUND";
		  std::string etach = "NOTFOUND";
		  std::string selbch = "NOTFOUND";
	     
		  float jbtCombSvx = ntPSub->SoftDropSubJetInfo_Jet_CombSvx[isj];
		  float jbtCombIVF = ntPSub->SoftDropSubJetInfo_Jet_CombIVF[isj];
		  float jbtTCHP = ntPSub->SoftDropSubJetInfo_Jet_Ip3P[isj];
		  float jbtCMVA = ntPSub->SoftDropSubJetInfo_Jet_cMVAv2[isj];

		  std::vector<bool> selbch_res;
		  for(int ibt=0;ibt<selb_n;ibt++)
		    {
		       if( selb[ibt] == BTAGBOOST_NONE ) selbch_res.push_back(1);
		       else
			 {		       
			    bool passBTAG = (
					     (selb[ibt] == BTAGBOOST_CSVL && jbtCombIVF >= 0.460) ||
					     (selb[ibt] == BTAGBOOST_CSVM && jbtCombIVF >= 0.800) ||
					     (selb[ibt] == BTAGBOOST_CSVT && jbtCombIVF >= 0.935) ||
					     (selb[ibt] == BTAGBOOST_UNTAGCSVL && jbtCombIVF < 0.460) ||
					     (selb[ibt] == BTAGBOOST_UNTAGCSVM && jbtCombIVF < 0.800) ||
					     (selb[ibt] == BTAGBOOST_UNTAGCSVT && jbtCombIVF < 0.935) ||
					     (selb[ibt] == BTAGBOOST_CMVAL && jbtCMVA >= -0.715) ||
					     (selb[ibt] == BTAGBOOST_CMVAM && jbtCMVA >= 0.185) ||
					     (selb[ibt] == BTAGBOOST_CMVAT && jbtCMVA >= 0.875) ||
					     (selb[ibt] == BTAGBOOST_UNTAGCMVAL && jbtCMVA < -0.715) ||
					     (selb[ibt] == BTAGBOOST_UNTAGCMVAM && jbtCMVA < 0.185) ||
					     (selb[ibt] == BTAGBOOST_UNTAGCMVAT && jbtCMVA < 0.875)
					);
			    if( passBTAG ) selbch_res.push_back(1);
			    else selbch_res.push_back(0);
			 }
		    }
		  
		  bool selach_res[seladd_n];
		  for( int ibt=0;ibt<seladd_n;ibt++ ) selach_res[ibt] = false;

		  selach_res[0] = true;

		  for(int isys=0;isys<sys_SubJet_n;isys++)
		    {	
		       float jSubPT = getPt(sys_SubJet[isys],1);
		  
		       float sfj = w;
		       
		       // l-jets are underestimated in MC by 1.27
		       if( SubflavchI == 3 && !isdata ) sfj *= 1.27;

		       // pileup reweighting sys
		       sfj *= systSub->Pileup(npv,sys_SubJet[isys],_h_pileup);
		       
		       // gluon splitting sys
		       sfj *= systSub->GluonSplitting(isj,SubflavchI,sys_SubJet[isys],"sub");
		       
		       // b fragmentation sys
		       sfj *= systSub->bFrag(isj,SubflavchI,sys_SubJet[isys],"sub");
		       
		       // c->D fragmentation sys
		       sfj *= systSub->cdFrag(isj,SubflavchI,sys_SubJet[isys],"sub");
		       
		       // c fragmentation sys
		       sfj *= systSub->cFrag(isj,SubflavchI,sys_SubJet[isys],"sub");
		       
		       // K0s Lambda sys
		       sfj *= systSub->Ks(isj,SubflavchI,sys_SubJet[isys],"sub");
		  
		       // generated ntrk in b- and c- hadron decays sys
		       sfj *= systSub->GenNTrk(isj,SubflavchI,sys_SubJet[isys],"sub");
		       
		       int jPtBinSubJet = 0;

		       if( jSubPT >= jPtMin_SubJet[0] && jSubPT <= jPtMax_SubJet[0] )   {selch = "pt30t80"; jPtBinSubJet = 1;}
		       if( jSubPT >= jPtMin_SubJet[1] && jSubPT <= jPtMax_SubJet[1] )   {selch = "pt80t140"; jPtBinSubJet = 2;}
		       if( jSubPT >= jPtMin_SubJet[2] && jSubPT <= jPtMax_SubJet[2] )   {selch = "pt140t180"; jPtBinSubJet = 3;}
		       if( jSubPT >= jPtMin_SubJet[3] && jSubPT <= jPtMax_SubJet[3] )   {selch = "pt180t240"; jPtBinSubJet = 4;}
		       if( jSubPT > jPtMin_SubJet[4] )  {selch = "pt240t420"; jPtBinSubJet = 5;}
		       
		       double jPtMinCurSubJet = 0.;
		       double jPtMaxCurSubJet = 1500.;
		      
		       if( jPtBinSubJet > 0 )
			 {		       
			    jPtMinCurSubJet = jPtMin_SubJet[jPtBinSubJet-1];
			    jPtMaxCurSubJet = jPtMax_SubJet[jPtBinSubJet-1];
			 }		  
		  
		       bool jeta_res[eta_n];
		       for( int ibt=0;ibt<eta_n;ibt++ ) jeta_res[ibt] = false;
		  		  
		       jeta_res[0] = true;

		       // 1d
		       std::vector<std::string> histNAMESSEL;
		       std::vector<float> sfJ;
		       std::vector<int> histSYS;
		       std::vector<int> histVAR;
		       
		       for(int ih=0;ih<hist_SubJet_n;ih++)
			 {
			    for(int ihb=0;ihb<selb_n;ihb++)
			      {
				 if( !selbch_res[ihb] ) continue;
				 
				 float sfjj = sfj;
				 
				 if( !isdata ) 
				   {
				      rw_SubJet->apply(&sfjj,ihb,jPtBinSubJet,Subntrk,Subnseltrk,nSubJets,nsv,mupt,jSubeta,jSubPT,csvAway,drAway,jpAway,jSubMass);
				   }			    

				 for(int iha=0;iha<seladd_n;iha++)
				   {
				      if( !selach_res[iha] ) continue;
				      
				      for(int ihe=0;ihe<eta_n;ihe++)
					{
					   if( !jeta_res[ihe] ) continue;
					   
					   histNAMESSEL.push_back(histNAMES_SubJet[SubflavchI][jPtBinSubJet][ihe][ihb][iha][ih][isys]);
					   histNAMESSEL.push_back(histNAMES_SubJet[0][jPtBinSubJet][ihe][ihb][iha][ih][isys]);
					   histNAMESSEL.push_back(histNAMES_SubJet[SubflavchI][0][ihe][ihb][iha][ih][isys]);
					   histNAMESSEL.push_back(histNAMES_SubJet[0][0][ihe][ihb][iha][ih][isys]);
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
			    TH1D *h = _m1d_SubJet->find(histNAMESSEL.at(ih))->second;

			    int hidx = int(ih/4);
			    fillThis = true;
			    float var;
			    std::vector<float> varv;
			    int varId = hist_SubJet[histVAR[hidx]];
			    var = getVar(sys_SubJet[histSYS[hidx]],isj,varId,jPtBinSubJet,1);
			    
			    if( fillThis )
			      {
				 float sfc = sfJ[hidx];
				 h->Fill(var,sfc);
			      }		       
			 }
		       
		       histNAMESSEL.clear();

		       // 2d
		       std::vector<std::string> histNAMESSEL_2d;
		       std::vector<float> sfJ_2d;
		       std::vector<int> histSYS_2d;
		       std::vector<int> histVAR_2d;

		       for(int ih=0;ih<hist_SubJet_2d_n;ih++)
			 {
			    for(int ihb=0;ihb<selb_n;ihb++)
			      {
				 if( !selbch_res[ihb] ) continue;
				 
				 float sfjj = sfj;
				 
				 if( !isdata )
				   {
				      rw_SubJet->apply(&sfjj,ihb,jPtBinSubJet,Subntrk,Subnseltrk,nSubJets,nsv,mupt,jSubeta,jSubPT,csvAway,drAway,jpAway,jSubMass);
				   }			    
				 
				 for(int iha=0;iha<seladd_n;iha++)
				   {
				      if( !selach_res[iha] ) continue;
				      
				      for(int ihe=0;ihe<eta_n;ihe++)
					{
					   if( !jeta_res[ihe] ) continue;
				      
					   histNAMESSEL_2d.push_back(histNAMES_2d_SubJet[SubflavchI][jPtBinSubJet][ihe][ihb][iha][ih][isys]);
					   histNAMESSEL_2d.push_back(histNAMES_2d_SubJet[0][jPtBinSubJet][ihe][ihb][iha][ih][isys]);
					   histNAMESSEL_2d.push_back(histNAMES_2d_SubJet[SubflavchI][0][ihe][ihb][iha][ih][isys]);
					   histNAMESSEL_2d.push_back(histNAMES_2d_SubJet[0][0][ihe][ihb][iha][ih][isys]);
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
			    TH2D *h = _m2d_SubJet->find(histNAMESSEL_2d.at(ih))->second;
			    
			    int hidx = int(ih/4);
			    fillThis = true;
			    int varId = hist_SubJet_2d[histVAR_2d[hidx]];
			    std::vector<float> var = getVar2d(sys_SubJet[histSYS_2d[hidx]],isj,varId,jPtBinSubJet,1);
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
		
		  systSub->clear();
		  
		  nSubJetSelected++;
	       }	     
	  }

	systFat->clear();
     }   
   
   delete v_mu_FatJet;
}

void LTANA::HistBoost::close()
{
   _fout->Write();
   _fout->Close();
}

float LTANA::HistBoost::getVar(int isys,int ijet,int varId,int ibin,bool isSub)
{
   float var = -666;
   
   int nJets = 0;
   if( isSub ) nJets = ntPSub->SoftDropSubJetInfo_nJet;
   else nJets = ntPSub->FatJetInfo_nJet;
   
   if( ijet <= nJets )
     {	   
	if( varId == HISTFAT_J1_JP || varId == HISTSUB_J1_JP )
	  {
	     if( isSub ) var = SubJet_Proba_New;
	     else var = FatJet_Proba_New;
	     if( var == 0. ) var = -666.;
	  }	     
	if( varId == HISTFAT_J1_NTRK || varId == HISTSUB_J1_NTRK )
	  {
	     if( isSub ) var = ntPSub->SoftDropSubJetInfo_Jet_ntracks[ijet];
	     else var = ntPSub->FatJetInfo_Jet_ntracks[ijet];
	  }	     
	if( varId == HISTFAT_J1_NSELTRK || varId == HISTSUB_J1_NSELTRK )
	  {		  
	     if( isSub ) var = ntPSub->SoftDropSubJetInfo_Jet_nseltracks[ijet];
	     else var = ntPSub->FatJetInfo_Jet_nseltracks[ijet];
	  }	     
	if( varId == HISTFAT_J1_ETA || varId == HISTSUB_J1_ETA )
	  {		  
	     if( isSub ) var = ntPSub->SoftDropSubJetInfo_Jet_eta[ijet];
	     else var = ntPSub->FatJetInfo_Jet_eta[ijet];
	  }	     
	if( varId == HISTFAT_J1_MUPT || varId == HISTSUB_J1_MUPT )
	  {
	     if( muIdx >= 0 )
	       var = ntPSub->FatJetInfo_PFMuon_pt[muidx[muIdx]];
	     else fillThis = false;
	  }
	if( varId == HISTFAT_J1_MASS || varId == HISTSUB_J1_MASS )
	  {
	     if( isSub ) var = ntPSub->SoftDropSubJetInfo_Jet_mass[ijet];
	     else var = ntPSub->FatJetInfo_Jet_mass[ijet];
	  }	     
	if( varId == HISTFAT_J1_TAU21 )
	  {
	     var = FatJet_tau21;
	  }	     
	if( varId == HISTFAT_J1_SOFTDROPMASS )
	  {
	     var = ntPSub->FatJetInfo_Jet_massSoftDrop[ijet];
	  }	     
/*	if( varId == HISTFAT_J1_MUPTREL )
	  {
	     if( muidx.size() > 0 )
	       var = ntPSub->FatJetInfo_PFMuon_ptrel[muidx[0]];
	     else fillThis = false;
	  }
	if( varId == HISTFAT_J1_DRAWAY )
	  {		  
	     var = drAway;
	  }	     
	if( varId == HISTFAT_J1_CSVAWAY )
	  {		  
	     var = csvAway;
	  }	     
	if( varId == HISTFAT_J1_TCHPAWAY )
	  {
	     var = tchpAway;
	  }	     
	if( varId == HISTFAT_J1_JPAWAY )
	  {		  
	     var = jpAway;
	  }	     
	if( varId == HISTFAT_J1_ETAAWAY )
	  {		  
	     var = etaAway;
	  }
	if( varId == HISTFAT_J1_NTRKGEN )
	  {
	     if( !isdata )
	       {		  
		  Helper *helper = new Helper();
		  int flav = abs(ntPSub->FatJetInfo_Jet_flavour[ijet]);
		  
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
			    if( dR > 0.8 ) continue;
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
	  }*/
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
	if( varId == HISTFAT_J1_NJET || varId == HISTSUB_J1_NJET )
	  {
	     if( ijet == 0 )
	       {		  
		  if( isSub ) var = ntPSub->SoftDropSubJetInfo_nJet;
		  else var = ntPSub->FatJetInfo_nJet;
	       }	     
	     else fillThis = false;
	  }	     
	if( varId == HISTFAT_J1_DRJ4J8MIN )
	  {
	     if( ijet == 0 )
	       {		  
		  var = drj4j8Min;
	       }	     
	     else fillThis = false;
	  }	     
/*	if( varId == HISTFAT_J1_NSV )
	  {
	     if( ijet == 0 )
	       var = ntP->nSV;
	     else fillThis = false;
	  }	     
	if( varId == HISTFAT_PTHAT )
	  {
	     if( ijet == 0 )
	       var = ntP->pthat;
	     else fillThis = false;
	  }	     
	if( varId == HISTFAT_NPV )
	  {
	     if( ijet == 0 )
	       var = ntP->nPV;
	     else fillThis = false;
	  }	     
	if( varId == HISTFAT_J1_CSVIVF )
	  {
	     var = ntPSub->FatJetInfo_Jet_CombIVF[ijet];
	  }*/

	if( varId == HISTFAT_J1_PT || varId == HISTSUB_J1_PT )
	  {	
	     double jptmax = 1500.;
	     double jptmin = 0.;
	     if( ibin > 0 ) 
	       {
		  if( isSub )
		    {		       
		       jptmax = jPtMax_SubJet[ibin-1];
		       jptmin = jPtMin_SubJet[ibin-1];
		    }
		  else
		    {
		       jptmax = jPtMax_FatJet[ibin-1];
		       jptmin = jPtMin_FatJet[ibin-1];
		    }		  
		  
		  var = (getPt(isys,isSub)-jptmin)/(jptmax-jptmin);
	       }	     
	  }

/*	if( varId == HISTFAT_J1_PTAWAY )
	  {	
	     double jptmax = 1250.;
	     double jptmin = 0.;
	     if( ibin > 0 ) 
	       {
		  jptmax = jPtMax_FatJet[ibin-1];
		  jptmin = jPtMin_FatJet[ibin-1];
	       }	     

	     var = (ptAway-jptmin)/(jptmax-jptmin);
	  }*/
     }   

   return var;
}

std::vector<float> LTANA::HistBoost::getVar2d(int isys,int ijet,int varId,int ibin,bool isSub)
{
   float varX = -666;
   float varY = -666;

   int nJets = 0;
   if( isSub ) nJets = ntPSub->SoftDropSubJetInfo_nJet;
   else nJets = ntPSub->FatJetInfo_nJet;

   if( ijet <= nJets )
     {	   
	if( varId == HISTFAT_2D_J1_PT_VS_JETA || varId == HISTSUB_2D_J1_PT_VS_JETA )
	  {
	     double jptmax = 1500.;
	     double jptmin = 0.;
	     if( ibin > 0 ) 
	       {
		  if( isSub )
		    {		       
		       jptmax = jPtMax_SubJet[ibin-1];
		       jptmin = jPtMin_SubJet[ibin-1];
		    }
		  else
		    {
		       jptmax = jPtMax_FatJet[ibin-1];
		       jptmin = jPtMin_FatJet[ibin-1];		       
		    }		  
	       }	     

	     if( isSub ) varX = ntPSub->SoftDropSubJetInfo_Jet_eta[ijet];
	     else varX = ntPSub->FatJetInfo_Jet_eta[ijet];
	     varY = (getPt(isys,isSub)-jptmin)/(jptmax-jptmin);
	  }	     
	else if( varId == HISTFAT_2D_J1_JP_VS_CSV || varId == HISTSUB_2D_J1_JP_VS_CSV )
	  {
	     if( isSub )
	       {		  
		  varX = ntPSub->SoftDropSubJetInfo_Jet_CombIVF[ijet];
		  varY = SubJet_Proba_New;
	       }
	     else
	       {
		  varX = ntPSub->FatJetInfo_Jet_CombIVF[ijet];
		  varY = FatJet_Proba_New;
	       }	     
	  }
	else if( varId == HISTFAT_2D_J1_JP_VS_CMVA || varId == HISTSUB_2D_J1_JP_VS_CMVA )
	  {
	     if( isSub )
	       {		  
		  varX = ntPSub->SoftDropSubJetInfo_Jet_cMVAv2[ijet];
		  varY = SubJet_Proba_New;
	       }
	     else
	       {
		  varX = ntPSub->FatJetInfo_Jet_cMVAv2[ijet];
		  varY = FatJet_Proba_New;
	       }	     
	  }	     
     }   

   std::vector<float> var;
   var.push_back(varX);
   var.push_back(varY);
   
   return var;
}

std::vector<float> LTANA::HistBoost::getVarVec(int isys,int ijet,int varId,int ibin)
{
   std::vector<float> var;
   var.clear();

   if( ibin-1 < 0 ) return var;

   if( ijet <= ntPSub->FatJetInfo_nJet )
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

float LTANA::HistBoost::getPt(int isys,bool isSub)
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
	if( isSub ) var = systSub->v_jet()->Pt();
	else var = systFat->v_jet()->Pt();
     }
   else if( isys == SYS_JES_UP )
     {
	if( isSub ) var = systSub->v_jet_sys_jesTotalUp()->Pt();
	else var = systFat->v_jet_sys_jesTotalUp()->Pt();
     }   
   else if( isys == SYS_JES_DOWN )
     {
	if( isSub ) var = systSub->v_jet_sys_jesTotalDown()->Pt();
	else var = systFat->v_jet_sys_jesTotalDown()->Pt();
     }   
   else if( isys == SYS_JER_UP )
     {
	if( isSub ) var = systSub->v_jet_sys_jerTotalUp()->Pt();
	else var = systFat->v_jet_sys_jerTotalUp()->Pt();
     }   
   else if( isys == SYS_JER_DOWN )
     {
	if( isSub ) var = systSub->v_jet_sys_jerTotalDown()->Pt();
	else var = systFat->v_jet_sys_jerTotalDown()->Pt();
     }   

   return var;
}

bool LTANA::HistBoost::passTrig(int trigIdx)
{
   int bitIdx = trigIdx/32;
   if ( ntP->BitTrigger[bitIdx] & ( 1 << (trigIdx - bitIdx*32) ) ) return true;
   else return false;
}
