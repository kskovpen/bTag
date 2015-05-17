#include "Hist.h"
#include "Ranges.h"

LTANA::Hist::Hist()
{
}

LTANA::Hist::~Hist()
{
}

void LTANA::Hist::init()
{
   rnd = new TRandom3(666);

/*   _fd0s = new TFile("/home/kskovpen/work/testarea/WRHN2012/ANALYSIS_v09/17.2.4.4/SKYPlot/run/macro/d0s.root");
   _gd0s = (TGraphErrors*)_fd0s->Get("sf");
*/   
   std::string foutName = std::string(foutname)+".root";
   
   _fout = new TFile(foutName.c_str(),"RECREATE");
//   std::string fevcName = "ev.txt";
//   _fevc.open(fevcName.c_str());

   muptcut = 5.;
//   muptcut = 8.;

   rw_n = 0;
//   name_rw[0] = "1d_eta";
//   name_rw[0] = "1d_njet";
//   name_rw[0] = "1d_ntrk";
//   name_rw[3] = "1d_njet";
//   name_rw[0] = "1d_nseltrk";
//   name_rw[0] = "1d_njet";
//   name_rw[0] = "1d_mupt";
//   name_rw[0] = "1d_eta";
//   name_rw[0] = "1d_pt";
//   name_rw[4] = "1d_pt";
//   name_rw[0] = "1d_nsv";
//   name_rw[1] = "1d_nseltrk";

   name_rw_2d = "2d_nseltrk_vs_njet";
   
   name_rw_3d = "3d_ntrk_pt_mupt";
   
   if( year2011 ) initRePU2011();
   else initRePU();
   
   hname.clear();

//   psSf.clear();

   int nbins = 100;
//   int nbins3d = 10;

   histname_jet_3d_n = 0;
//   histname_jet_3d[0] = "h_j1_ntrk_vs_pt_vs_mupt_";

//   histname_jet_2d_n = 4;
////   histname_jet_2d_n = 0;
//   histname_jet_2d[0] = "h_j1_JP_vs_pt_";
//   histname_jet_2d[1] = "h_j1_JP_vs_mupt_";
//   histname_jet_2d[2] = "h_j1_JP_vs_ntrk_";
//   histname_jet_2d[3] = "h_j1_ntrk_vs_mupt_";
   
//   histname_jet_2d_n = 22;
//   histname_jet_2d_n = 12;
   histname_jet_2d_n = 0;
/*   histname_jet_2d[0] = "h_j1_JP_vs_CSV_";
   histname_jet_2d[1] = "h_j1_JP_vs_nseltrk_";
   histname_jet_2d[2] = "h_j1_nseltrk_vs_ntrkgen_";
   histname_jet_2d[3] = "h_j1_nseltrk_vs_njet_";
   histname_jet_2d[4] = "h_j1_nseltrk_vs_mupt_";
   histname_jet_2d[5] = "h_j1_nseltrk_vs_jeta_";   
//   histname_jet_2d[6] = "h_j1_nseltrk_vs_njet_";
//   histname_jet_2d[7] = "h_j1_nseltrk_vs_mupt_";
//   histname_jet_2d[8] = "h_j1_nseltrk_vs_jeta_";
   histname_jet_2d[6] = "h_j1_njet_vs_mupt_";
   histname_jet_2d[7] = "h_j1_njet_vs_jeta_";
   histname_jet_2d[8] = "h_j1_mupt_vs_jeta_";
//   histname_jet_2d[7] = "h_j1_nseltrk_vs_nsv_";
//   histname_jet_2d[8] = "h_j1_njet_vs_nsv_";
//   histname_jet_2d[9] = "h_j1_mupt_vs_nsv_";
//   histname_jet_2d[10] = "h_j1_jeta_vs_nsv_";
//   histname_jet_2d[12] = "h_j1_JP_vs_nseltrk_";
   histname_jet_2d[9] = "h_j1_JP_vs_njet_";
   histname_jet_2d[10] = "h_j1_JP_vs_mupt_";
   histname_jet_2d[11] = "h_j1_JP_vs_jeta_";
//   histname_jet_2d[15] = "h_j1_JP_vs_nsv_";
//   histname_jet_2d[16] = "h_j1_JP_vs_pt_";
//   histname_jet_2d[17] = "h_j1_pt_vs_nseltrk_";
//   histname_jet_2d[18] = "h_j1_pt_vs_njet_";
//   histname_jet_2d[19] = "h_j1_pt_vs_mupt_";
//   histname_jet_2d[20] = "h_j1_pt_vs_jeta_";
//   histname_jet_2d[21] = "h_j1_pt_vs_nsv_";
*/   
//   histname_jet_n = 0;
//   histname_jet_n = 10;
   histname_jet_n = 8;
//   histname_jet_n = 2;

   histname_jet[0] = "h_j1_pt_";
   histname_jet[1] = "h_j1_nseltrk_";
   histname_jet[2] = "h_j1_eta_";
   histname_jet[3] = "h_j1_ntrk_";
   histname_jet[4] = "h_j1_njet_";
   histname_jet[5] = "h_j1_nsv_";
   histname_jet[6] = "h_j1_mupt_"; // has to be the last*/
   histname_jet[7] = "h_j1_JP_";
//   histname_jet[1] = "h_j1_JP_";

/*   histname_jet[4] = "h_j1_mupt_";
   histname_jet[5] = "h_j1_eta_";
   histname_jet[6] = "h_j1_phi_";
   histname_jet[7] = "h_j1_mass_";
//   histname_jet[7] = "h_j1_mueta_";
//   histname_jet[8] = "h_j1_muphi_";
//   histname_jet[9] = "h_j1_muptrel_";
   histname_jet[8] = "h_j1_svntrk_";
   histname_jet[9] = "h_j1_svmass_";
//   histname_jet[12] = "h_j1_npv_";
//   histname_jet[13] = "h_j1_npu_";
   histname_jet[10] = "h_j1_nmuon_";
   histname_jet[11] = "h_j1_nsv_";
  */
//   histname_jet[2] = "h_j1_pthat_";

/*   sel_n = 19;
   sel[0] = "nosel";
   sel[1] = "pt20t30";
   sel[2] = "pt30t40";
   sel[3] = "pt40t50";
   sel[4] = "pt50t60";
   sel[5] = "pt60t70";
   sel[6] = "pt70t80";
   sel[7] = "pt80t100";
   sel[8] = "pt100t120";
   sel[9] = "pt120t160";
   sel[10] = "pt160t210";
   sel[11] = "pt210t260";
   sel[12] = "pt260t320";
   sel[13] = "pt320t400";
   sel[14] = "pt400t500";
   sel[15] = "pt500t600";
   sel[16] = "pt600t800";
   sel[17] = "pt800t1000";
   sel[18] = "pt1000t1400";*/

   sel_n = 17;
   sel[0] = "nosel";
   sel[1] = "pt20t30";
   sel[2] = "pt30t40";
   sel[3] = "pt40t50";
   sel[4] = "pt50t60";
   sel[5] = "pt60t70";
   sel[6] = "pt70t80";
   sel[7] = "pt80t100";
   sel[8] = "pt100t120";
   sel[9] = "pt120t160";
   sel[10] = "pt160t210";
   sel[11] = "pt210t260";
   sel[12] = "pt260t320";
   sel[13] = "pt320t400";
   sel[14] = "pt400t500";
   sel[15] = "pt500t670";
   sel[16] = "pt670t1000";
/*
   sel_n = 32;
   sel[0] = "nosel";
   sel[1] = "pt20t25";
   sel[2] = "pt25t30";
   sel[3] = "pt30t35";
   sel[4] = "pt35t40";
   sel[5] = "pt40t45";
   sel[6] = "pt45t50";
   sel[7] = "pt50t55";
   sel[8] = "pt55t60";
   sel[9] = "pt60t65";
   sel[10] = "pt65t70";
   sel[11] = "pt70t75";
   sel[12] = "pt75t80";
   sel[13] = "pt80t90";
   sel[14] = "pt90t100";
   sel[15] = "pt100t110";
   sel[16] = "pt110t120";
   sel[17] = "pt120t140";
   sel[18] = "pt140t160";
   sel[19] = "pt160t185";
   sel[20] = "pt185t210";
   sel[21] = "pt210t235";
   sel[22] = "pt235t260";
   sel[23] = "pt260t290";
   sel[24] = "pt290t320";
   sel[25] = "pt320t360";
   sel[26] = "pt360t400";
   sel[27] = "pt400t450";
   sel[28] = "pt450t500";
   sel[29] = "pt500t585";
   sel[30] = "pt585t670";
   sel[31] = "pt670t1000";
*/
   /*
   sel_n = 10;
   sel[0] = "nosel";
   sel[1] = "pt20t40";
   sel[2] = "pt40t60";
   sel[3] = "pt60t80";
   sel[4] = "pt80t120";
   sel[5] = "pt120t210";
   sel[6] = "pt210t320";
   sel[7] = "pt320t500";
   sel[8] = "pt500t1000";
   sel[9] = "pt1000t1400";
*/  
//   sel[18] = "pt20t25";
//   sel[19] = "pt25t30";

/*   jPtMin[0] = 20; jPtMax[0] = 30;
   jPtMin[1] = 30; jPtMax[1] = 40;
   jPtMin[2] = 40; jPtMax[2] = 50;
   jPtMin[3] = 50; jPtMax[3] = 60;
   jPtMin[4] = 60; jPtMax[4] = 70;
   jPtMin[5] = 70; jPtMax[5] = 80;
   jPtMin[6] = 80; jPtMax[6] = 100;
   jPtMin[7] = 100; jPtMax[7] = 120;
   jPtMin[8] = 120; jPtMax[8] = 160;
   jPtMin[9] = 160; jPtMax[9] = 210;
   jPtMin[10] = 210; jPtMax[10] = 260;
   jPtMin[11] = 260; jPtMax[11] = 320;
   jPtMin[12] = 320; jPtMax[12] = 400;
   jPtMin[13] = 400; jPtMax[13] = 500;
   jPtMin[14] = 500; jPtMax[14] = 600;
   jPtMin[15] = 600; jPtMax[15] = 800;
   jPtMin[16] = 800; jPtMax[16] = 1000;
   jPtMin[17] = 1000; jPtMax[17] = 1400;*/
   
   jPtMin[0] = 20; jPtMax[0] = 30;
   jPtMin[1] = 30; jPtMax[1] = 40;
   jPtMin[2] = 40; jPtMax[2] = 50;
   jPtMin[3] = 50; jPtMax[3] = 60;
   jPtMin[4] = 60; jPtMax[4] = 70;
   jPtMin[5] = 70; jPtMax[5] = 80;
   jPtMin[6] = 80; jPtMax[6] = 100;
   jPtMin[7] = 100; jPtMax[7] = 120;
   jPtMin[8] = 120; jPtMax[8] = 160;
   jPtMin[9] = 160; jPtMax[9] = 210;
   jPtMin[10] = 210; jPtMax[10] = 260;
   jPtMin[11] = 260; jPtMax[11] = 320;
   jPtMin[12] = 320; jPtMax[12] = 400;
   jPtMin[13] = 400; jPtMax[13] = 500;
   jPtMin[14] = 500; jPtMax[14] = 670;
   jPtMin[15] = 670; jPtMax[15] = 1000;
/*
   jPtMin[0] = 20; jPtMax[0] = 25;
   jPtMin[1] = 25; jPtMax[1] = 30;
   jPtMin[2] = 30; jPtMax[2] = 35;
   jPtMin[3] = 35; jPtMax[3] = 40;
   jPtMin[4] = 40; jPtMax[4] = 45;
   jPtMin[5] = 45; jPtMax[5] = 50;
   jPtMin[6] = 50; jPtMax[6] = 55;
   jPtMin[7] = 55; jPtMax[7] = 60;
   jPtMin[8] = 60; jPtMax[8] = 65;
   jPtMin[9] = 65; jPtMax[9] = 70;
   jPtMin[10] = 70; jPtMax[10] = 75;
   jPtMin[11] = 75; jPtMax[11] = 80;
   jPtMin[12] = 80; jPtMax[12] = 90;
   jPtMin[13] = 90; jPtMax[13] = 100;
   jPtMin[14] = 100; jPtMax[14] = 110;
   jPtMin[15] = 110; jPtMax[15] = 120;
   jPtMin[16] = 120; jPtMax[16] = 140;
   jPtMin[17] = 140; jPtMax[17] = 160;
   jPtMin[18] = 160; jPtMax[18] = 185;
   jPtMin[19] = 185; jPtMax[19] = 210;
   jPtMin[20] = 210; jPtMax[20] = 235;
   jPtMin[21] = 235; jPtMax[21] = 260;
   jPtMin[22] = 260; jPtMax[22] = 290;
   jPtMin[23] = 290; jPtMax[23] = 320;
   jPtMin[24] = 320; jPtMax[24] = 360;
   jPtMin[25] = 360; jPtMax[25] = 400;
   jPtMin[26] = 400; jPtMax[26] = 450;
   jPtMin[27] = 450; jPtMax[27] = 500;
   jPtMin[28] = 500; jPtMax[28] = 585;
   jPtMin[29] = 585; jPtMax[29] = 670;
   jPtMin[30] = 670; jPtMax[30] = 1000;
*/  
//   jPtMin[17] = 20; jPtMax[17] = 25;
//   jPtMin[18] = 25; jPtMax[18] = 30;
    /*
   jPtMin[0] = 20; jPtMax[0] = 40;
   jPtMin[1] = 40; jPtMax[1] = 60;
   jPtMin[2] = 60; jPtMax[2] = 80;
   jPtMin[3] = 80; jPtMax[3] = 120;
   jPtMin[4] = 120; jPtMax[4] = 210;
   jPtMin[5] = 210; jPtMax[5] = 320;
   jPtMin[6] = 320; jPtMax[6] = 500;
   jPtMin[7] = 500; jPtMax[7] = 1000;
   jPtMin[8] = 1000; jPtMax[8] = 1400;
*/
   eta_n = 1;
   eta[0] = "nosel";

   selb_n = 3;
   selb[0] = "nosel";
   selb[1] = "combSvx0p244"; // Loose
//   selb[2] = "combSvx0p679"; // Medium
//   selb[3] = "combSvx0p898"; // Tight
//   selb[4] = "TCHP1p19"; // Loose
//   selb[5] = "TCHP1p93"; // Medium
//   selb[6] = "TCHP3p41"; // Tight
   selb[2] = "UNTAGbc";

   seladd_n = 1;
   seladd[0] = "";
//   seladd[1] = "_ntrkGE1";
//   seladd[2] = "_ntrkGE2";
//   seladd[3] = "_ntrkGE4";
//   seladd[4] = "_ntrkGE7";
//   seladd[5] = "_ntrkGE10";
   
   flav_n = 4;
   flav[0] = "ajet";
   flav[1] = "bjet";
   flav[2] = "cjet";
   flav[3] = "ljet";
   
   sys_low_n = 10;
//   sys_low_n = 1;
   sys_low[0]   = "";
   sys_low[1]   = "_pu_low";
   sys_low[2]   = "_gsplit_low";
   sys_low[3]   = "_bfrag_low";
   sys_low[4]   = "_cdfrag_low";
   sys_low[5]   = "_cfrag_low";
   sys_low[6]   = "_ksl_low";
   sys_low[7]   = "_ntrkgen_low";
   sys_low[8]   = "_jes_low";
   sys_low[9]   = "_jer_low";

   sys_up_n = sys_low_n-1;
   sys_up[0]   = "_pu_up";
   sys_up[1]   = "_gsplit_up";
   sys_up[2]   = "_bfrag_up";
   sys_up[3]   = "_cdfrag_up";
   sys_up[4]   = "_cfrag_up";
   sys_up[5]   = "_ksl_up";
   sys_up[6]   = "_ntrkgen_up";
   sys_up[7]   = "_jes_up";
   sys_up[8]   = "_jer_up";

   sys_n = sys_low_n + sys_up_n;
   
   for(int is1=0;is1<sys_low_n;is1++)
     {
	sys[is1] = sys_low[is1];
     }   
   for(int is2=0;is2<sys_up_n;is2++)
     {
	sys[sys_low_n+is2] = sys_up[is2];
     }   

   rwBin.clear();
   rwSf.clear();
   rwBin_btag.clear();
   rwSf_btag.clear();
   
   _s_Jet = new std::vector<std::pair<std::vector<std::string>,double*> >();
   _m1d_Jet = new std::map<std::string, TH1D*>();

   _s2_Jet = new std::vector<std::pair<std::vector<std::string>,double*> >();
   _m2d_Jet = new std::map<std::string, TH2D*>();

   _s3_Jet = new std::vector<std::pair<std::vector<std::string>,double*> >();
   _m3d_Jet = new std::map<std::string, TH3D*>();

   std::vector<double*> set_hist_jet;
   set_hist_jet.clear();

   std::vector<double*> set_hist_jet_2d;
   set_hist_jet_2d.clear();

   std::vector<double*> set_hist_jet_3d;
   set_hist_jet_3d.clear();

   set_hist_jet.push_back(RANGE::set_j_pt);
////   set_hist_jet.push_back(RANGE::set_j_JP);
//   set_hist_jet.push_back(RANGE::set_j_ntrk);
//   set_hist_jet.push_back(RANGE::set_j_njet);
//   set_hist_jet.push_back(RANGE::set_j_eta);
   
////   set_hist_jet.push_back(RANGE::set_j_mupt);
//   set_hist_jet.push_back(RANGE::set_j_eta);
//   set_hist_jet.push_back(RANGE::set_j_phi);
//   set_hist_jet.push_back(RANGE::set_j_mass);
//   set_hist_jet.push_back(set_j_mueta);
//   set_hist_jet.push_back(set_j_muphi);
//   set_hist_jet.push_back(set_j_muptrel);
//   set_hist_jet.push_back(RANGE::set_j_svntrk);
//   set_hist_jet.push_back(RANGE::set_j_svmass);
//   set_hist_jet.push_back(set_j_npv);
//   set_hist_jet.push_back(set_j_npu);
//   set_hist_jet.push_back(RANGE::set_j_nmuon);
//   set_hist_jet.push_back(RANGE::set_j_nsv);
   set_hist_jet.push_back(RANGE::set_j_nseltrk);
   set_hist_jet.push_back(RANGE::set_j_eta);
   set_hist_jet.push_back(RANGE::set_j_ntrk);
   set_hist_jet.push_back(RANGE::set_j_njet);
   set_hist_jet.push_back(RANGE::set_j_nsv);
   
//   set_hist_jet_2d.push_back(set_j_2d_ntrk_vs_pt);
//   set_hist_jet_2d.push_back(set_j_2d_ntrk_vs_mupt);

   set_hist_jet_2d.push_back(RANGE::set_j_2d_JP_vs_CSV);
   set_hist_jet_2d.push_back(RANGE::set_j_2d_JP_vs_nseltrk);
   set_hist_jet_2d.push_back(RANGE::set_j_2d_nseltrk_vs_ntrkgen);
   set_hist_jet_2d.push_back(RANGE::set_j_2d_nseltrk_vs_njet);
   set_hist_jet_2d.push_back(RANGE::set_j_2d_nseltrk_vs_jeta);
   set_hist_jet_2d.push_back(RANGE::set_j_2d_nseltrk_vs_mupt);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_nseltrk_vs_njet);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_nseltrk_vs_mupt);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_nseltrk_vs_jeta);
   set_hist_jet_2d.push_back(RANGE::set_j_2d_njet_vs_mupt);
   set_hist_jet_2d.push_back(RANGE::set_j_2d_njet_vs_jeta);
   set_hist_jet_2d.push_back(RANGE::set_j_2d_mupt_vs_jeta);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_nseltrk_vs_nsv);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_njet_vs_nsv);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_mupt_vs_nsv);
  // set_hist_jet_2d.push_back(RANGE::set_j_2d_jeta_vs_nsv);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_JP_vs_nseltrk);
   set_hist_jet_2d.push_back(RANGE::set_j_2d_JP_vs_njet);
   set_hist_jet_2d.push_back(RANGE::set_j_2d_JP_vs_mupt);
   set_hist_jet_2d.push_back(RANGE::set_j_2d_JP_vs_jeta);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_JP_vs_nsv);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_JP_vs_pt);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_pt_vs_nseltrk);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_pt_vs_njet);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_pt_vs_mupt);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_pt_vs_jeta);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_pt_vs_nsv);
   
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_JP_vs_pt);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_JP_vs_mupt);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_JP_vs_ntrk);
//   set_hist_jet_2d.push_back(RANGE::set_j_2d_ntrk_vs_mupt);
   
//   set_hist_jet_3d.push_back(set_j_3d_ntrk_vs_pt_vs_mupt);
   
//   set_hist_event.push_back(set_event_mjjMax);

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

			    for(int h=0;h<histname_jet_2d_n;h++)
			      {
				 std::string hn = histname_jet_2d[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selb[ssb]+seladd[ssa];
				 hname.push_back(hn);
				 
				 for(int s=0;s<sys_n;s++)
				   {
				      titl = hn+sys[s];
				      std::vector<std::string> names;
				      names.clear();
				      names.push_back(titl);
				      names.push_back(sys[s]);

				      _s2_Jet->push_back(std::make_pair(names,set_hist_jet_2d.at(h)));
				   }				 
			      }

			    for(int h=0;h<histname_jet_3d_n;h++)
			      {
				 std::string hn = histname_jet_3d[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selb[ssb]+seladd[ssa];
				 hname.push_back(hn);
				 
				 for(int s=0;s<sys_n;s++)
				   {
				      titl = hn+sys[s];
				      std::vector<std::string> names;
				      names.clear();
				      names.push_back(titl);
				      names.push_back(sys[s]);

				      _s3_Jet->push_back(std::make_pair(names,set_hist_jet_3d.at(h)));
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

   for(int i=0;i<_s3_Jet->size();i++)
     {
	TH3D *_h3d = new TH3D(_s3_Jet->at(i).first.at(0).c_str(),
			      _s3_Jet->at(i).first.at(0).c_str(),
			      _s3_Jet->at(i).second[0],
			      _s3_Jet->at(i).second[1],
			      _s3_Jet->at(i).second[2],
			      _s3_Jet->at(i).second[3],
			      _s3_Jet->at(i).second[4],
			      _s3_Jet->at(i).second[5],
			      _s3_Jet->at(i).second[6],
			      _s3_Jet->at(i).second[7],
			      _s3_Jet->at(i).second[8]);
	
	_h3d->Sumw2();
	
	_m3d_Jet->insert(std::pair<std::string,TH3D*>(_s3_Jet->at(i).first.at(0),_h3d));
     }
   
   if( doRW )
     {       
	std::cout << "Read corrections" << std::endl;
	
	TFile fcor("corrections.root");
	
	if( !fcor.IsOpen() )
	  {
	     std::cout << "Input file with RW factors can not be opened !" << std::endl;
	     exit(1);
	  }
	if( doRW == 1 )
	  {	     
	     for(int isf=0;isf<rw_n;isf++)
	       {
		  std::vector<std::vector<std::pair<double,double> > > v_ptBin;
		  std::vector<std::vector<std::pair<double,double> > > v_ptSf;
		  v_ptBin.clear();
		  v_ptSf.clear();
		  
		  for(int ipt=0;ipt<sel_n;ipt++)
		    {		       
		       std::string sfname = "sf_"+sel[ipt]+"_nosel_"+name_rw[isf];
		       TH1D *hSF = (TH1D*)fcor.Get(sfname.c_str());
		       std::cout << sfname << std::endl;
		       
		       std::vector<std::pair<double,double> > v_valBin;
		       std::vector<std::pair<double,double> > v_valSf;
		       v_valBin.clear();
		       v_valSf.clear();
		       
		       int nb = hSF->GetXaxis()->GetNbins();
		       for(int ib=0;ib<=nb+1;ib++)
			 {		  
			    float pt1 = hSF->GetXaxis()->GetBinLowEdge(ib);
			    float pt2 = hSF->GetXaxis()->GetBinUpEdge(ib);
			    float sf = hSF->GetBinContent(ib);
			    float sferr = hSF->GetBinError(ib);
			    
			    std::pair<double,double> binfo = std::make_pair(pt1,pt2);
			    std::pair<double,double> sfinfo = std::make_pair(sf,sferr);
			    v_valBin.push_back(binfo);
			    v_valSf.push_back(sfinfo);
			 }
		       v_ptBin.push_back(v_valBin);
		       v_ptSf.push_back(v_valSf);
		    }	     
		  rwBin.push_back(v_ptBin);
		  rwSf.push_back(v_ptSf);
		  //
		  v_ptBin.clear();
		  v_ptSf.clear();
		  
		  for(int ipt=0;ipt<sel_n;ipt++)
		    {		       
		       std::string sfname = "sf_"+sel[ipt]+"_"+selb[1]+"_"+name_rw[isf];
		       TH1D *hSF = (TH1D*)fcor.Get(sfname.c_str());
		       std::cout << sfname << std::endl;
		       
		       std::vector<std::pair<double,double> > v_valBin;
		       std::vector<std::pair<double,double> > v_valSf;
		       v_valBin.clear();
		       v_valSf.clear();
		       
		       int nb = hSF->GetXaxis()->GetNbins();
		       for(int ib=1;ib<=nb;ib++)
			 {		  
			    float pt1 = hSF->GetXaxis()->GetBinLowEdge(ib);
			    float pt2 = hSF->GetXaxis()->GetBinUpEdge(ib);
			    float sf = hSF->GetBinContent(ib);
			    float sferr = hSF->GetBinError(ib);
			    
			    std::pair<double,double> binfo = std::make_pair(pt1,pt2);
			    std::pair<double,double> sfinfo = std::make_pair(sf,sferr);
			    v_valBin.push_back(binfo);
			    v_valSf.push_back(sfinfo);
			 }
		       v_ptBin.push_back(v_valBin);
		       v_ptSf.push_back(v_valSf);
		    }	     
		  rwBin_btag.push_back(v_ptBin);
		  rwSf_btag.push_back(v_ptSf);
	       }		
	  }
	if( doRW == 2 )
	  {
	     std::vector<std::vector<std::pair<double,double> > > v_pt2DBinX;
	     std::vector<std::vector<std::pair<double,double> > > v_pt2DBinY;
	     std::vector<std::vector<std::pair<double,double> > > v_pt2DSf;
	     v_pt2DBinX.clear();
	     v_pt2DBinY.clear();
	     v_pt2DSf.clear();
		  
	     for(int ipt=0;ipt<sel_n;ipt++)
	       {		       
		  std::string sfname = "sf_"+sel[ipt]+"_nosel_"+name_rw_2d;
		  TH2D *hSF = (TH2D*)fcor.Get(sfname.c_str());
		  std::cout << sfname << std::endl;
		       
		  std::vector<std::pair<double,double> > v_val2DBinX;
		  std::vector<std::pair<double,double> > v_val2DBinY;
		  std::vector<std::pair<double,double> > v_val2DSf;
		  v_val2DBinX.clear();
		  v_val2DBinY.clear();
		  v_val2DSf.clear();
		       
		  int nbX = hSF->GetXaxis()->GetNbins();
		  for(int ib=0;ib<=nbX+1;ib++)
		    {		  
		       float pt1 = hSF->GetXaxis()->GetBinLowEdge(ib);
		       float pt2 = hSF->GetXaxis()->GetBinUpEdge(ib);
		       
		       std::pair<double,double> binfo = std::make_pair(pt1,pt2);
		       v_val2DBinX.push_back(binfo);
		    }
		  v_pt2DBinX.push_back(v_val2DBinX);

		  int nbY = hSF->GetYaxis()->GetNbins();
		  for(int ib=0;ib<=nbY+1;ib++)
		    {		  
		       float pt1 = hSF->GetYaxis()->GetBinLowEdge(ib);
		       float pt2 = hSF->GetYaxis()->GetBinUpEdge(ib);
		       
		       std::pair<double,double> binfo = std::make_pair(pt1,pt2);
		       v_val2DBinY.push_back(binfo);
		    }
		  v_pt2DBinY.push_back(v_val2DBinY);

		  for(int ibx=0;ibx<=nbX+1;ibx++)
		    {		  
		       for(int iby=0;iby<=nbY+1;iby++)
			 {		  
			    float sf = hSF->GetBinContent(ibx,iby);
			    float sferr = hSF->GetBinError(ibx,iby);
			    
			    std::pair<double,double> sfinfo = std::make_pair(sf,sferr);
			    v_val2DSf.push_back(sfinfo);
			 }		       
		    }
		  
		  v_pt2DSf.push_back(v_val2DSf);
	       }
	     
	     rw2DBinX.push_back(v_pt2DBinX);
	     rw2DBinY.push_back(v_pt2DBinY);
	     
	     rw2DSf.push_back(v_pt2DSf);
	  }	
	if( doRW == 3 )
	  {
	     std::vector<std::vector<std::pair<double,double> > > v_pt3DBinX;
	     std::vector<std::vector<std::pair<double,double> > > v_pt3DBinY;
	     std::vector<std::vector<std::pair<double,double> > > v_pt3DBinZ;
	     std::vector<std::vector<std::pair<double,double> > > v_pt3DSf;
	     v_pt3DBinX.clear();
	     v_pt3DBinY.clear();
	     v_pt3DBinZ.clear();
	     v_pt3DSf.clear();
		  
	     for(int ipt=0;ipt<sel_n;ipt++)
	       {		       
		  std::string sfname = "sf_"+sel[ipt]+"_nosel_"+name_rw_3d;
		  TH3D *hSF = (TH3D*)fcor.Get(sfname.c_str());
		  std::cout << sfname << std::endl;
		       
		  std::vector<std::pair<double,double> > v_val3DBinX;
		  std::vector<std::pair<double,double> > v_val3DBinY;
		  std::vector<std::pair<double,double> > v_val3DBinZ;
		  std::vector<std::pair<double,double> > v_val3DSf;
		  v_val3DBinX.clear();
		  v_val3DBinY.clear();
		  v_val3DBinZ.clear();
		  v_val3DSf.clear();
		       
		  int nbX = hSF->GetXaxis()->GetNbins();
		  for(int ib=0;ib<=nbX+1;ib++)
		    {		  
		       float pt1 = hSF->GetXaxis()->GetBinLowEdge(ib);
		       float pt2 = hSF->GetXaxis()->GetBinUpEdge(ib);
		       
		       std::pair<double,double> binfo = std::make_pair(pt1,pt2);
		       v_val3DBinX.push_back(binfo);
		    }
		  v_pt3DBinX.push_back(v_val3DBinX);

		  int nbY = hSF->GetYaxis()->GetNbins();
		  for(int ib=0;ib<=nbY+1;ib++)
		    {		  
		       float pt1 = hSF->GetYaxis()->GetBinLowEdge(ib);
		       float pt2 = hSF->GetYaxis()->GetBinUpEdge(ib);
		       
		       std::pair<double,double> binfo = std::make_pair(pt1,pt2);
		       v_val3DBinY.push_back(binfo);
		    }
		  v_pt3DBinY.push_back(v_val3DBinY);

		  int nbZ = hSF->GetZaxis()->GetNbins();
		  for(int ib=0;ib<=nbZ+1;ib++)
		    {		  
		       float pt1 = hSF->GetZaxis()->GetBinLowEdge(ib);
		       float pt2 = hSF->GetZaxis()->GetBinUpEdge(ib);
		       
		       std::pair<double,double> binfo = std::make_pair(pt1,pt2);
		       v_val3DBinZ.push_back(binfo);
		    }
		  v_pt3DBinZ.push_back(v_val3DBinZ);
		  
		  for(int ibx=0;ibx<=nbX+1;ibx++)
		    {		  
		       for(int iby=0;iby<=nbY+1;iby++)
			 {		  
			    for(int ibz=0;ibz<=nbZ+1;ibz++)
			      {		  
				 float sf = hSF->GetBinContent(ibx,iby,ibz);
				 float sferr = hSF->GetBinError(ibx,iby,ibz);
				 
				 std::pair<double,double> sfinfo = std::make_pair(sf,sferr);
				 v_val3DSf.push_back(sfinfo);
			      }
			 }		       
		    }
		  
		  v_pt3DSf.push_back(v_val3DSf);
	       }
	     
	     rw3DBinX.push_back(v_pt3DBinX);
	     rw3DBinY.push_back(v_pt3DBinY);
	     rw3DBinZ.push_back(v_pt3DBinZ);
	     
	     rw3DSf.push_back(v_pt3DSf);
	  }	
	fcor.Close();
     }
/*
   // read out LUMI after PRESCALE
   ifstream infilePS;
   
   if( doLUMI )
     {       
	infilePS.open("/home/kskovpen/work/testarea/JetTag/ANALYSIS_v12/17.2.4.4/JTPlot2012Lite/run/macro/fit/run/LUMIPRESCALE.txt");
	
	if( !infilePS.is_open() )
	  {
	     std::cout << "Input file with LUMI data can not be opened !" << std::endl;
	     exit(1);
	  }   
	while( !infilePS.eof() )
	  {
	     int nbin;
	     float sf;
	     infilePS >> nbin >> sf;
	     psSf.push_back(sf);
	  }
	infilePS.close();
     }*/
   
   jesTotal = new JetCorrectionUncertainty(*(new JetCorrectorParameters("/home-pbs/kskovpen/bTag/CMSSW_7_4_0/src/LTAnalysis/run/Summer13_V5_DATA_UncertaintySources_AK5PF.txt", "Total")));

   // JER taken from https://twiki.cern.ch/twiki/bin/view/CMS/JetResolution
   
   cJER[0] = 1.052; // 0.0-0.5
   cJER[1] = 1.057; // 0.5-1.1
   cJER[2] = 1.096; // 1.1-1.7
   cJER[3] = 1.134; // 1.7-2.3
   cJER[4] = 1.288; // 2.3-5.0
   
   cJER_down[0] = 0.990;
   cJER_down[1] = 1.001;
   cJER_down[2] = 1.032;
   cJER_down[3] = 1.042;
   cJER_down[4] = 1.089;

   cJER_up[0] = 1.115;
   cJER_up[1] = 1.114;
   cJER_up[2] = 1.161;
   cJER_up[3] = 1.228;
   cJER_up[4] = 1.488;
   
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

				 for(int h=0;h<histname_jet_2d_n;h++)
				   {
				      histNAMES_2d[j][ss][se][ssb][ssa][h][s] =
					histname_jet_2d[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selb[ssb]+seladd[ssa]+sys[s];
				   }

				 for(int h=0;h<histname_jet_3d_n;h++)
				   {
				      histNAMES_3d[j][ss][se][ssb][ssa][h][s] =
					histname_jet_3d[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selb[ssb]+seladd[ssa]+sys[s];
				   }
			      }			    
			 }		       
		    }		  
	       }
	  }
     }

   if( !isdata )
     {	
	nPtRelPtBins = 15;
	TString PtRelPtBin[] = {
	   "Pt2030", "Pt3040", "Pt4050", "Pt5060", "Pt6070"
	   , "Pt7080", "Pt80100", "Pt100120", "Pt120160", "Pt160210"
	   , "Pt210260", "Pt260320", "Pt320400", "Pt400500", "Pt500" 
	};
	
	for( int ptb=0;ptb<nPtRelPtBins;ptb++ )
	  {      
	     for(int ib=0;ib<100;ib++ )
	       {
		  BTemplateCorrections[ib][ptb][0] = 1.;
		  BTemplateCorrections[ib][ptb][1] = 1.;
	       }
	     
	     std::ifstream MnusCorrectionsFile; 
	     MnusCorrectionsFile.open("./PtRelFall12/EnergyFraction_" + PtRelPtBin[ptb] + "_m5.txt");
	     while( MnusCorrectionsFile )
	       {
		  float xBin, efcorr;
		  MnusCorrectionsFile >> xBin >> efcorr;
		  if ( efcorr > 4. ) efcorr = 1.;
		  int ib = int(xBin/0.02);
		  BTemplateCorrections[ib][ptb][0] = efcorr;
	       }
	     
	     std::ifstream PlusCorrectionsFile; 
	     PlusCorrectionsFile.open("./PtRelFall12/EnergyFraction_" + PtRelPtBin[ptb] + "_p5.txt");
	     while( PlusCorrectionsFile )
	       {
		  float xBin, efcorr;
		  PlusCorrectionsFile >> xBin >> efcorr;
		  if ( efcorr > 4. ) efcorr = 1.;
		  int ib = int(xBin/0.02);
		  BTemplateCorrections[ib][ptb][1] = efcorr;
	       }
	  }
     }   
	
   std::cout << "Initialisation done" << std::endl;
}

void LTANA::Hist::fill()
{
//   double w = noe/(xsec*eff);
   float pthat = ntP->pthat;
//   if( !isdata ) w = (9238642/(1024000.0*0.0395))/w;

   double ran = rnd->Rndm();
//   if( ran >= 0.5 ) return;
////   if( ran < 0.5 ) return;
   
   double w = 1.;
   
   if( !isdata )
     {	
	double w015 = 1722681/(7.022E8*0.0039);
	double w020 = 8486904/(2.87E8*0.0065);
	double w030 = 9560265/(6.609E7*0.0122);
	double w050 =10365230/(8082000.0*0.0218);
	double w080 = 9238642/(1024000.0*0.0395);
	double w120 = 8501935/(157800.0*0.0473);
	double w170 = 7670288/(34020.0*0.0676);
	double w300 = 7839607/(1757.0*0.0864);
	double w470 = 3783069/(115.2*0.1024);
	double w600 = 4119000/(27.01*0.0996);
	double w800 = 4107853/(3.57*0.1033);
	double w1000= 3873970/(0.774*0.1097);

	if( year2011 )
	  {
	     w015 = 1901694/(580700000*0.0035);
	     w020 =12133278/(235400000*0.0045);
	     w030 =11610144/(53470000*0.01);
	     w050 = 9887094/(6317000*0.0245);
	     w080 =10497146/(781100*0.0345);
	     w120 = 7913447/(116000*0.0545);
	     w170 = 8116425/(24690*0.0625);
	     w300 = 7870022/(1153*0.0923);
	     w470 = 3812536/(71.81*0.086);
	     w600 = 4149919/(15.15*0.094);
	     w800 = 3945269/(1.863*0.1033);
	     w1000= 4133903/(0.3392*0.094);
	  }	
	
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
   if( year2011 )
     {
	if( npu > 34 ) npu = 34;
     }   
   else
     {
	if( ntP->Run < 0 ) npu = int(ntP->nPUtrue);
	if( npu > 49 ) npu = 49;
     }   
//   float wPU = WeightPU[npu];
//   if( !isdata ) w *= wPU;

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

   if( year2011 ) passTrigJet300 = passTrigJet300_HLT;
   
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
   
//   if( njet300 == 0 && year2011 && sp2011 ) return;
//   if( njet300 > 0 && year2011 && !sp2011 ) return;
   
	/*
	 bool trigr = 0;
   // new trigger selection
   if( njet20 > 1 && passTrigJet20 ) trigr = 1;
   if( njet40 > 1 && passTrigJet40 ) trigr = 1;
   if( njet70 > 1 && passTrigJet70 ) trigr = 1;
   if( njet110 > 1 && passTrigJet110 ) trigr = 1;
   if( njet300 > 0 && passTrigJet300 ) trigr = 1;
   if( !trigr ) return;
*/   
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

	ntrkgen = 0;
	
//	std::cout << "jet#" << ij << " " << ntP->nTrkInc << std::endl;
	
	v_jet = new TLorentzVector(0,0,0,0);
	v_jet_sys_jesTotalUp = new TLorentzVector(0,0,0,0);
	v_jet_sys_jesTotalLow = new TLorentzVector(0,0,0,0);
	v_jet_sys_jerTotalUp = new TLorentzVector(0,0,0,0);
	v_jet_sys_jerTotalLow = new TLorentzVector(0,0,0,0);
	v_mu = new TLorentzVector(0,0,0,0);

	bool passSel = true;
	
	float jeta = ntP->Jet_eta[ij];
	float jphi = ntP->Jet_phi[ij];
	float jm = ntP->Jet_mass[ij];
	float residual = 1.;
	if( ntP->Run > 0 ) residual = ntP->Jet_residual[ij];
	float jpt = ntP->Jet_pt[ij] * residual;

	if( isdata && year2011 && sp2011 && jpt < 320. ) continue;
	if( isdata && year2011 && !sp2011 && jpt >= 320. ) continue;
	
	// JER

	v_jet_sys_jerTotalUp->SetPtEtaPhiM(jpt,jeta,jphi,jm);
	v_jet_sys_jerTotalLow->SetPtEtaPhiM(jpt,jeta,jphi,jm);
	
	if( !isdata )
	  {	    
	     int etaIdx = -1;
	     if( fabs(jeta) >= 0. && fabs(jeta) < 0.5 ) etaIdx = 0;
	     if( fabs(jeta) >= 0.5 && fabs(jeta) < 1.1 ) etaIdx = 1;
	     if( fabs(jeta) >= 1.1 && fabs(jeta) < 1.7 ) etaIdx = 2;
	     if( fabs(jeta) >= 1.7 && fabs(jeta) < 2.3 ) etaIdx = 3;
	     if( fabs(jeta) >= 2.3 && fabs(jeta) < 5.0 ) etaIdx = 4;
	
	     double jpt_c = jpt;
	     if( etaIdx >= 0 )
	       {		  
		  double genpt = ntP->Jet_genpt[ij];
		  if( genpt >= 0. )
		    {
		       jpt_c = genpt + cJER[etaIdx]*(jpt-genpt);
		       
		       double jpt_c_down = genpt + cJER_down[etaIdx]*(jpt-genpt);
		       double jpt_c_up = genpt + cJER_up[etaIdx]*(jpt-genpt);
		       
		       if( jpt_c < 0. ) jpt_c = 0.;
		       if( jpt_c_down < 0. ) jpt_c_down = 0.;
		       if( jpt_c_up < 0. ) jpt_c_up = 0.;
		       
		       v_jet_sys_jerTotalUp->SetPtEtaPhiM(jpt_c_up,jeta,jphi,jm);
		       v_jet_sys_jerTotalLow->SetPtEtaPhiM(jpt_c_down,jeta,jphi,jm);
		  
//		  std::cout << jpt_c << "-" << jpt_c_down << "+" << jpt_c_up << std::endl;
		    }
	       }	     
	     
	     jpt = jpt_c;
	  }	
	     
	v_jet->SetPtEtaPhiM(jpt,jeta,jphi,jm);

	if( jpt < 20. || jpt > 1500. ) passSel = false;
	if( fabs(jeta) > 2.4 ) passSel = false;

//	if( ntP->Evt == 983779189 && ij == 1 )
//	  std::cout << "jet#" << ij << " pt=" << ntP->Jet_pt[ij] <<
//	  " eta=" << ntP->Jet_eta[ij] <<
//	  " passSel=" << passSel << std::endl;
	
	int njet = ntNJET;
	
	int nsv = ntP->nSV;
	int nsvj = ntP->Jet_nLastSV[ij];
	
	int ntrk = ntP->Jet_ntracks[ij];
	int nseltrk = ntP->Jet_nseltracks[ij];
////	if( ntrk == 0 ) passSel = false;
	
	v_jet_sys_jesTotalUp->SetPtEtaPhiM(jpt,jeta,jphi,jm);
	v_jet_sys_jesTotalLow->SetPtEtaPhiM(jpt,jeta,jphi,jm);

	// JES
	jesTotal->setJetPt(jpt);
	jesTotal->setJetEta(jeta);
	double uncert = jesTotal->getUncertainty(true);
	
	v_jet_sys_jesTotalUp->SetPtEtaPhiE(jpt*(1.+uncert),
					   jeta,
					   v_jet->Phi(),
					   v_jet->E()*(1.+uncert));
	
	v_jet_sys_jesTotalLow->SetPtEtaPhiE(jpt*(1.-uncert),
					    jeta,
					    v_jet->Phi(),
					    v_jet->E()*(1.-uncert));
	
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
	
	if( year2011 )
	  {
	     if( jpt >= 320 && !passTrigJet300 ) passSel = false; 
	  }	

	// muon-in-jet
//	std::vector<int> muidx;
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
	
/*	if( passMuonInJet )
	  {	     
	     float mupt = ntP->Muon_pt[muidx[0]];
	     float mueta = ntP->Muon_eta[muidx[0]];
	     float muphi = ntP->Muon_phi[muidx[0]];
	     float mum = 0.10566;
	     v_mu->SetPtEtaPhiM(mupt,mueta,muphi,mum);
	  }*/
	
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
//	     if( fabs(jFlavour) == 5 && ntP->Jet_CombSvx[ij] >= 0.679 )
//	       _fevc << ntP->Evt << " " << ntP->Jet_Proba[ij]*10. << " " << jpt << " " << w*WeightPU[npu] << std::endl;
	     
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
	     
//	     if( ntP->Jet_Proba[ij] == 0. && ntP->Jet_CombSvx[ij] > 0.244 )
//	       std::cout << ntP->Jet_CombSvx[ij] << std::endl;

	     bool selach_res[seladd_n];
	     for( int ibt=0;ibt<seladd_n;ibt++ ) selach_res[ibt] = false;

	     selach_res[0] = true;
//	     if( ntrk >= 1 ) selach_res[1] = true;
//	     if( ntrk >= 2 ) selach_res[2] = true;
//	     if( ntrk >= 4 ) selach_res[3] = true;
//	     if( ntrk >= 7 ) selach_res[4] = true;
//	     if( ntrk >= 10 ) selach_res[5] = true;
	     
	     for(int isys=0;isys<sys_n;isys++)
	       {	
		  float jPT = getPt(sys[isys]);
		  
		  double sfj = w;
		  
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
		  float wPU = WeightPU[npu];
		  if( sys[isys] == "_pu_up" ) wPU = WeightPUmax[npu];
		  if( sys[isys] == "_pu_low" ) wPU = WeightPUmin[npu];
		  if( !isdata ) sfj *= wPU;

		  // gluon splitting sys
		  if( (sys[isys] == "_gsplit_low" || sys[isys] == "_gsplit_up") &&
		      !isdata )
		    {		       
		       bool GSPc = false, GSPb = false;
		       
		       if( flavch == "cjet" )
			 {
			    for( int k=0;k<ntP->ncQuarks;k++ )
			      {
				 if( ntP->cQuark_status[k] != 2 ) continue;
				 double dRqj = DeltaR(ntP->Jet_eta[ij],
						      ntP->Jet_phi[ij], 
						      ntP->cQuark_eta[k], 
						      ntP->cQuark_phi[k]);
				 if( k == ntP->ncQuarks-1 ) continue;
				 if( dRqj > 0.5 ) continue;
				 for( int l=k+1;l<ntP->ncQuarks;l++ )
				   {
				      if( ntP->cQuark_status[l] != 2 ) continue;
				      double dRqj2 = DeltaR(ntP->Jet_eta[ij], 
							    ntP->Jet_phi[ij], 
							    ntP->cQuark_eta[l], 
							    ntP->cQuark_phi[l]);
				      if( ntP->cQuark_pdgID[k] * ntP->cQuark_pdgID[l] > 0 ) continue;
				      if( dRqj2 < 0.5 ) GSPc = true;
				   }			    
			      }		       
			 }		  
		       
		       if( flavch == "bjet" )
			 {
			    for( int k=0;k<ntP->nbQuarks;k++ )
			      {
				 if( ntP->bQuark_status[k] != 2 ) continue;
				 double dRqj = DeltaR(ntP->Jet_eta[ij],
						      ntP->Jet_phi[ij], 
						      ntP->bQuark_eta[k], 
						      ntP->bQuark_phi[k]);
				 if( k == ntP->nbQuarks-1 ) continue;
				 if( dRqj > 0.5 ) continue;
				 for( int l=k+1;l<ntP->nbQuarks;l++ )
				   {
				      if( ntP->bQuark_status[l] != 2 ) continue;
				      double dRqj2 = DeltaR(ntP->Jet_eta[ij], 
							    ntP->Jet_phi[ij], 
							    ntP->bQuark_eta[l], 
							    ntP->bQuark_phi[l]);
				      if( ntP->bQuark_pdgID[k] * ntP->bQuark_pdgID[l] > 0 ) continue;
				      if( dRqj2 < 0.5 ) GSPb = true;
				   }			    
			      }		       
			 }		  
		  
		       if( 
			  sys[isys] == "_gsplit_low" && 
			  ((GSPc && flavch == "cjet") || (GSPb && flavch == "bjet"))
			 ) sfj *= 0.5;
		       if( 
			  sys[isys] == "_gsplit_up" &&
			  ((GSPc && flavch == "cjet") || (GSPb && flavch == "bjet"))
			 ) sfj *= 1.5;
		    }
		  
		  // b fragmentation sys
		  if( (sys[isys] == "_bfrag_low" || sys[isys] == "_bfrag_up") &&
		      !isdata )
		    {		       
		       float WeightBFrag = 1.;
		       float EnergyFraction = 0.; 
		       int iB = -1, iptBin = 0, efbin = -1;
		       if( flavch == "bjet" && ( sys[isys] == "_bfrag_low" || sys[isys] == "_bfrag_up" ) )
			 {
			    if( jPT > 500 ) iptBin = 14;
			    else if( jPT > 400 ) iptBin = 13;
			    else if( jPT > 320 ) iptBin = 12;  
			    else if( jPT > 260 ) iptBin = 11;
			    else if( jPT > 210 ) iptBin = 10;
			    else if( jPT > 160 ) iptBin =  9;
			    else if( jPT > 120 ) iptBin =  8;  
			    else if( jPT > 100 ) iptBin =  7;  
			    else if( jPT >  80 ) iptBin =  6;  
			    else if( jPT >  70 ) iptBin =  5;  
			    else if( jPT >  60 ) iptBin =  4;  
			    else if( jPT >  50 ) iptBin =  3;  
			    else if( jPT >  40 ) iptBin =  2;  
			    else if( jPT >  30 ) iptBin =  1;  
			    else                 iptBin =  0;
			    
			    float B_Mass = 0.;
			    for( int ib=0;ib<ntP->nBHadrons;ib++ )
			      {
				 if( DeltaR(ntP->Jet_eta[ij],
					    ntP->Jet_phi[ij], 
					    ntP->BHadron_eta[ib], 
					    ntP->BHadron_phi[ib]) < 0.5 )
				   {
				      if( ntP->BHadron_mass[ib] > B_Mass ) 
					{
					   B_Mass = ntP->BHadron_mass[ib];
					   iB = ib;
					}				 
				   }			    
			      }
			    
			    if( iB >= 0 ) 
			      {
				 EnergyFraction = ntP->BHadron_pT[iB]/ntP->Jet_genpt[ij];
				 efbin = int( EnergyFraction / 0.02 );
				 if( efbin >= 0 && efbin < 100 ) 
				   {
				      if( sys[isys] == "_bfrag_low" ) WeightBFrag = BTemplateCorrections[efbin][iptBin][0];
				      if( sys[isys] == "_bfrag_up" ) WeightBFrag = BTemplateCorrections[efbin][iptBin][1];
				   }			    
			      }
			    
			    sfj *= WeightBFrag;
			 }
		    }		  
		  
		  // c->D fragmentation sys
		  if( (sys[isys] == "_cdfrag_low" || sys[isys] == "_cdfrag_up") &&
		      !isdata )
		    {		       
		       if( flavch == "cjet" || flavch == "bjet" )
			 {
			    bool isDplusMu = false, isDzeroMu = false, isDsubsMu = false;
			    
			    int ndaughters = 0;
			    for( int k=0;k<ntP->nDHadrons;k++ )
			      {
				 double dR = DeltaR(ntP->DHadron_eta[k], 
						    ntP->DHadron_phi[k], 
						    ntP->Jet_eta[ij], 
						    ntP->Jet_phi[ij]);
				 if( dR > 0.4 ) continue;
				 bool isSemiMu = false;
				 int nd = ntP->DHadron_nDaughters[k];
				 for( int kk=0;kk<nd;kk++ )
				   {
				      if( abs(ntP->DHadron_DaughtersPdgID[kk+ndaughters]) == 13 ) isSemiMu = true;
				   }
			    
				 ndaughters += nd;
				 
				 if( !isSemiMu ) continue;
				 if( abs(ntP->DHadron_pdgID[k]) == 411 ) isDplusMu = true;
				 if( abs(ntP->DHadron_pdgID[k]) == 421 ) isDzeroMu = true;
				 if( abs(ntP->DHadron_pdgID[k]) == 431 ) isDsubsMu = true;
			      }
			    
			    // weight for D->mu decay: Pythia vs PDG2013
			    if( sys[isys] == "_cdfrag_low" )
			      {			    
				 if( isDplusMu ) sfj *= 0.176 / 0.172;
				 if( isDzeroMu ) sfj *= 0.067 / 0.077;
				 if( isDsubsMu ) sfj *= 0.067 / 0.080;
			      }		       
			 }
		    }		  
		  
		  // c fragmentation sys
		  int nChargedGen1_c = -1, nChargedGen2_c = -1;
		  if( !isdata )
		    {
		       if( flavch == "cjet" )
			 {
			    bool hasCquark = 0;
			    for( int c=0;c<ntP->ncQuarks;c++ )
			      {
				 double dRc = DeltaR(ntP->cQuark_eta[c], 
						     ntP->cQuark_phi[c], 
						     ntP->Jet_eta[ij], 
						     ntP->Jet_phi[ij]);
				 if( dRc < 0.3 ) hasCquark = 1;
			      }
			    
			    if( hasCquark )
			      {				 
				 bool isDplus = false, isDzero = false, isDsubs = false, isDbary = false;
				 for( int k=0;k<ntP->nDHadrons;k++ )
				   {
				      double dR = DeltaR(ntP->DHadron_eta[k], 
							 ntP->DHadron_phi[k], 
							 ntP->Jet_eta[ij], 
							 ntP->Jet_phi[ij]);
				      if( dR > 0.4 ) continue;
				 
				      if( nChargedGen1_c >= 0 && nChargedGen2_c < 0 ) nChargedGen2_c = ntP->DHadron_nCharged[k];
				      if( nChargedGen1_c < 0 )  nChargedGen1_c = ntP->DHadron_nCharged[k];
				      
				      if( abs(ntP->DHadron_pdgID[k]) == 411 ) isDplus = true;
				      if( abs(ntP->DHadron_pdgID[k]) == 421 ) isDzero = true;
				      if( abs(ntP->DHadron_pdgID[k]) == 431 ) isDsubs = true;
				      if((abs(ntP->DHadron_pdgID[k])/1000)%10 == 4 ) isDbary = true;
				   }		       
				 
				 // weight for c->D fragmentation rate: Pythia vs PDG2008
				 if( sys[isys] == "_cfrag_low" )
				   {
				      // DB
				      if( isDplus ) sfj *= 1.37; // PDG2008(0.246+-0.020)
				      if( isDzero ) sfj *= 0.91; // PDG2008(0.565+-0.032)
				      if( isDsubs ) sfj *= 0.67; // PDG2008(0.080+-0.017)
				      // 0.185072, 0.58923, 0.115961
				   }		       
			      }			    
			 }
		    }		  
		  
		  // K0s Lambda sys
		  if( (sys[isys] == "_ksl_low" || sys[isys] == "_ksl_up") &&
		      !isdata )
		    {		       
		       int nK0s = 0, nLambda = 0;
		       if( flavch == "ljet" )
			 {
			    for( int k=0;k<ntP->nGenV0;k++ )
			      {
				 double dR = DeltaR(ntP->GenV0_eta[k], 
						    ntP->GenV0_phi[k], 
						    ntP->Jet_eta[ij], 
						    ntP->Jet_phi[ij]);
				 if( dR > 0.3 ) continue;
				 int pdgid = abs(ntP->GenV0_pdgID[k]);
				 if( pdgid == 310 )  nK0s++;
				 if( pdgid == 3122 ) nLambda++;
			      }
			    if( sys[isys] == "_ksl_up" )
			      {			    
				 if( nK0s > 0 )    sfj *= 1.3;
				 if( nLambda > 0 ) sfj *= 1.5;
			      }
			 }
		    }		  
		  
		  // generated ntrk in b- and c- hadron decays sys
		  if( !isdata )
		    {		       		  
		       // Weight in number of generated tracks from c-hadrons (+_3%)
		       float WeightCtrkMin[] = 
			 {
			    1.83175, 1.09414, 0.969433, 0.957613, 0.944791, 0.93478, 0.951504, 0.933117, 0.933552, 1,
			    1, 1, 1, 1, 1, 1, 1, 1, 1, 1
			 };
		       float WeightCtrkMax[] = 
			 {
			    0.941931, 0.935278, 0.959889, 1.05731, 1.11384, 1.28445, 1, 1, 1, 1,
			    1, 1, 1, 1, 1, 1, 1, 1, 1, 1
			 };
		       // Weight in number of generated tracks from b-hadrons (+_3%)
		       float WeightBtrkMin[] = 
			 {
			    3.4573, 1.70516, 1.12162, 1.05566, 0.945077, 0.996961, 0.925635, 0.987391, 0.917369, 0.969089,
			    0.904673, 0.947409, 0.894847, 0.939174, 0.887052, 1, 1, 1, 1, 1
			 };
		       float WeightBtrkMax[] = 
			 {
			    1.06921, 0.876405, 0.89011, 0.937056, 0.960934, 1.09521, 1.00306, 1.17408, 1.01393, 1.22725,
			    1.04056, 1.35842, 1.08842, 1.55228, 1.11446, 1, 1, 1, 1, 1
			 };

		       int nChargedGen1_b = -1, nChargedGen2_b = -1;
		       
		       if( flavch == "bjet" )
			 {
			    for( int k=0;k<ntP->nBHadrons;k++ )
			      {
				 if( ntP->BHadron_hasBdaughter[k] == 1 ) continue;
				 double dR = DeltaR(ntP->BHadron_eta[k], 
						    ntP->BHadron_phi[k], 
						    ntP->Jet_eta[ij], 
						    ntP->Jet_phi[ij]);
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
		       
		       // Weight in track multiplicity from c-hadron and b-hadron decays
		       int nchgen1_b = nChargedGen1_b, nchgen2_b = nChargedGen2_b;
		       if( nchgen1_b > 19 ) nchgen1_b = 19;
		       if( nchgen2_b > 19 ) nchgen2_b = 19;

		       int nchgen1_c = nChargedGen1_c, nchgen2_c = nChargedGen2_c;
		       if( nchgen1_c > 19 ) nchgen1_c = 19;
		       if( nchgen2_c > 19 ) nchgen2_c = 19;
		       
		       if( sys[isys] == "_ntrkgen_low" )
			 {
			    if( flavch == "cjet" )
			      {
				 if( nchgen1_c >= 0 ) sfj *= WeightCtrkMin[nchgen1_c];
				 if( nchgen2_c >= 0 ) sfj *= WeightCtrkMin[nchgen2_c];
			      }
			    if( flavch == "bjet" )
			      {
				 if( nchgen1_b >= 0 ) sfj *= WeightBtrkMin[nchgen1_b];
				 if( nchgen2_b >= 0 ) sfj *= WeightBtrkMin[nchgen2_b];
			      }
			 }
		       if( sys[isys] == "_ntrkgen_up" )
			 {
			    if( flavch == "cjet" )
			      {			    
				 if( nchgen1_c >= 0 ) sfj *= WeightCtrkMax[nchgen1_c];
				 if( nchgen2_c >= 0 ) sfj *= WeightCtrkMax[nchgen2_c];
			      }		       
			    if( flavch == "bjet" )
			      {			    
				 if( nchgen1_b >= 0 ) sfj *= WeightBtrkMax[nchgen1_b];
				 if( nchgen2_b >= 0 ) sfj *= WeightBtrkMax[nchgen2_b];
			      }
			 }
		       
		       if( flavch == "bjet" ) ntrkgen = nChargedGen1_b;
		       else if( flavch == "cjet" ) ntrkgen = nChargedGen1_c;		       
		    } 
		  // end sys
		  
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
		  if( jPT > jPtMin[14] && jPT <= jPtMax[14] )  {selch = "pt500t600"; jPtBin = 15;}
		  if( jPT > jPtMin[15] && jPT <= jPtMax[15] )  {selch = "pt600t800"; jPtBin = 16;}
		  if( jPT > jPtMin[16] && jPT <= jPtMax[16] )  {selch = "pt800t1000"; jPtBin = 17;}
		  if( jPT > jPtMin[17] && jPT <= jPtMax[17] )  {selch = "pt1000t1400"; jPtBin = 18;}*/

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
/*
		  if( jPT >= jPtMin[0] && jPT <= jPtMax[0] )   {selch = "pt20t25"; jPtBin = 1;}
		  if( jPT >= jPtMin[1] && jPT <= jPtMax[1] )   {selch = "pt25t30"; jPtBin = 2;}
		  if( jPT > jPtMin[2] && jPT <= jPtMax[2] )   {selch = "pt30t35"; jPtBin = 3;}
		  if( jPT > jPtMin[3] && jPT <= jPtMax[3] )   {selch = "pt35t40"; jPtBin = 4;}
		  if( jPT > jPtMin[4] && jPT <= jPtMax[4] )   {selch = "pt40t45"; jPtBin = 5;}
		  if( jPT > jPtMin[5] && jPT <= jPtMax[5] )   {selch = "pt45t50"; jPtBin = 6;}
		  if( jPT > jPtMin[6] && jPT <= jPtMax[6] )   {selch = "pt50t55"; jPtBin = 7;}
		  if( jPT > jPtMin[7] && jPT <= jPtMax[7] )   {selch = "pt55t60"; jPtBin = 8;}
		  if( jPT > jPtMin[8] && jPT <= jPtMax[8] )   {selch = "pt60t65"; jPtBin = 9;}
		  if( jPT > jPtMin[9] && jPT <= jPtMax[9] )   {selch = "pt65t70"; jPtBin = 10;}
		  if( jPT > jPtMin[10] && jPT <= jPtMax[10] )   {selch = "pt70t75"; jPtBin = 11;}
		  if( jPT > jPtMin[11] && jPT <= jPtMax[11] )   {selch = "pt75t80"; jPtBin = 12;}
		  if( jPT > jPtMin[12] && jPT <= jPtMax[12] )   {selch = "pt80t90"; jPtBin = 13;}
		  if( jPT > jPtMin[13] && jPT <= jPtMax[13] )   {selch = "pt90t100"; jPtBin = 14;}
		  if( jPT > jPtMin[14] && jPT <= jPtMax[14] )  {selch = "pt100t110"; jPtBin = 15;}
		  if( jPT > jPtMin[15] && jPT <= jPtMax[15] )  {selch = "pt110t120"; jPtBin = 16;}
		  if( jPT > jPtMin[16] && jPT <= jPtMax[16] )  {selch = "pt120t140"; jPtBin = 17;}
		  if( jPT > jPtMin[17] && jPT <= jPtMax[17] )  {selch = "pt140t160"; jPtBin = 18;}
		  if( jPT > jPtMin[18] && jPT <= jPtMax[18] )  {selch = "pt160t185"; jPtBin = 19;}
		  if( jPT > jPtMin[19] && jPT <= jPtMax[19] )  {selch = "pt185t210"; jPtBin = 20;}
		  if( jPT > jPtMin[20] && jPT <= jPtMax[20] )  {selch = "pt210t235"; jPtBin = 21;}
		  if( jPT > jPtMin[21] && jPT <= jPtMax[21] )  {selch = "pt235t260"; jPtBin = 22;}
		  if( jPT > jPtMin[22] && jPT <= jPtMax[22] )  {selch = "pt260t290"; jPtBin = 23;}
		  if( jPT > jPtMin[23] && jPT <= jPtMax[23] )  {selch = "pt290t320"; jPtBin = 24;}
		  if( jPT > jPtMin[24] && jPT <= jPtMax[24] )  {selch = "pt320t360"; jPtBin = 25;}
		  if( jPT > jPtMin[25] && jPT <= jPtMax[25] )  {selch = "pt360t400"; jPtBin = 26;}
		  if( jPT > jPtMin[26] && jPT <= jPtMax[26] )  {selch = "pt400t450"; jPtBin = 27;}
		  if( jPT > jPtMin[27] && jPT <= jPtMax[27] )  {selch = "pt450t500"; jPtBin = 28;}
		  if( jPT > jPtMin[28] && jPT <= jPtMax[28] )  {selch = "pt500t585"; jPtBin = 29;}
		  if( jPT > jPtMin[29] )  {selch = "pt585t670"; jPtBin = 30;}
*/		  
//		  if( jPT > jPtMin[14] && jPT <= jPtMax[14] )  {selch = "pt500t670"; jPtBin = 15;}
//		  if( jPT > jPtMin[15] && jPT <= jPtMax[15] )  {selch = "pt670t1000"; jPtBin = 16;}
		  
//		  if( jPT > jPtMin[17] && jPT <= jPtMax[17] )  {selch = "pt20t25"; jPtBin = 18;}
//		  if( jPT > jPtMin[18] && jPT <= jPtMax[18] )  {selch = "pt25t30"; jPtBin = 19;}
/*
		  if( jPT >= jPtMin[0] && jPT <= jPtMax[0] )   {selch = "pt20t40"; jPtBin = 1;}
		  if( jPT >= jPtMin[1] && jPT <= jPtMax[1] )   {selch = "pt40t60"; jPtBin = 2;}
		  if( jPT >= jPtMin[2] && jPT <= jPtMax[2] )   {selch = "pt60t80"; jPtBin = 3;}
		  if( jPT >= jPtMin[3] && jPT <= jPtMax[3] )   {selch = "pt80t120"; jPtBin = 4;}
		  if( jPT >= jPtMin[4] && jPT <= jPtMax[4] )   {selch = "pt120t210"; jPtBin = 5;}
		  if( jPT >= jPtMin[5] && jPT <= jPtMax[5] )   {selch = "pt210t320"; jPtBin = 6;}
		  if( jPT >= jPtMin[6] && jPT <= jPtMax[6] )   {selch = "pt320t500"; jPtBin = 7;}
		  if( jPT >= jPtMin[7] && jPT <= jPtMax[7] )   {selch = "pt500t1000"; jPtBin = 8;}
		  if( jPT >= jPtMin[8] && jPT <= jPtMax[8] )   {selch = "pt1000t1400"; jPtBin = 9;}
*/		  
		  double jPtMinCur = 0.;
		  double jPtMaxCur = 1250.;
		  
		  if( jPtBin > 0 )
		    {		       
		       jPtMinCur = jPtMin[jPtBin-1];
		       jPtMaxCur = jPtMax[jPtBin-1];
		    }		  

		  double mupt = -1.;
		  if( muidx.size() > 0 )
		    mupt = ntP->Muon_pt[muidx[0]];
		  
		  bool jeta_res[eta_n];
		  for( int ibt=0;ibt<eta_n;ibt++ ) jeta_res[ibt] = false;
		  		  
		  jeta_res[0] = true;
//		  if( fabs(jeta) >= 0.0 && fabs(jeta) <= 0.6 )  jetaI = 1;
//		  if( fabs(jeta) > 0.6 && fabs(jeta) <= 1.2 )   jetaI = 2;
//		  if( fabs(jeta) > 1.2 && fabs(jeta) <= 1.8 )   jetaI = 3;
//		  if( fabs(jeta) > 1.8 && fabs(jeta) <= 2.5 )   jetaI = 4;

		  // apply RW
		  double rwSF = 1.;
		  double rwSF_btag = rwSF;
		  double sfj_btag = sfj;
		  if( doRW == 1 && !isdata )
		    {
		       for(int iv=0;iv<rw_n;iv++)
			 {			    
			    std::vector<std::pair<double,double> > rwBinFound =
			      rwBin[iv][jPtBin];
			    std::vector<std::pair<double,double> > rwSfFound =
			      rwSf[iv][jPtBin];

			    std::vector<std::pair<double,double> > rwBinFound_btag =
			      rwBin_btag[iv][jPtBin];
			    std::vector<std::pair<double,double> > rwSfFound_btag =
			      rwSf_btag[iv][jPtBin];
			    
			    if( strcmp(name_rw[iv].c_str(),"1d_ntrk") == 0 )
			      {		
				 rwSF *= getSF(rwBinFound,rwSfFound,ntrk);
				 rwSF_btag *= getSF(rwBinFound_btag,rwSfFound_btag,ntrk);
			      }
			    if( strcmp(name_rw[iv].c_str(),"1d_nseltrk") == 0 )
			      {		
				 rwSF *= getSF(rwBinFound,rwSfFound,nseltrk);
				 rwSF_btag *= getSF(rwBinFound_btag,rwSfFound_btag,nseltrk);
			      }
			    if( strcmp(name_rw[iv].c_str(),"1d_njet") == 0 )
			      {		
				 rwSF *= getSF(rwBinFound,rwSfFound,njet);
				 rwSF_btag *= getSF(rwBinFound_btag,rwSfFound_btag,njet);
			      }
			    if( strcmp(name_rw[iv].c_str(),"1d_nsv") == 0 )
			      {		
				 rwSF *= getSF(rwBinFound,rwSfFound,nsv);
				 rwSF_btag *= getSF(rwBinFound_btag,rwSfFound_btag,nsv);
			      }
			    if( strcmp(name_rw[iv].c_str(),"1d_mupt") == 0 )
			      {
				 if( muidx.size() > 0 )
				   {				      
				      rwSF *= getSF(rwBinFound,rwSfFound,mupt);
				      rwSF_btag *= getSF(rwBinFound_btag,rwSfFound_btag,mupt);
				   }				 
			      }
			    if( strcmp(name_rw[iv].c_str(),"1d_eta") == 0 )
			      {		
				 double jeta = ntP->Jet_eta[ij];
				 rwSF *= getSF(rwBinFound,rwSfFound,jeta);
				 rwSF_btag *= getSF(rwBinFound_btag,rwSfFound_btag,jeta);
			      }
			    if( strcmp(name_rw[iv].c_str(),"1d_pt") == 0 )
			      {		
				 double jptmax = 1250.;
				 double jptmin = 0.;
				 if( jPtBin > 0 ) 
				   {
				      jptmax = jPtMax[jPtBin-1];
				      jptmin = jPtMin[jPtBin-1];
				   }	     
				 double vPT = (jPT-jptmin)/(jptmax-jptmin);
				 
				 rwSF *= getSF(rwBinFound,rwSfFound,vPT);
				 rwSF_btag *= getSF(rwBinFound_btag,rwSfFound_btag,vPT);
			      }
			 }		       
		    }
		  if( doRW == 2 && !isdata )
		    {
		       std::vector<std::pair<double,double> > rw2DBinXFound =
			 rw2DBinX[0][jPtBin];
		       std::vector<std::pair<double,double> > rw2DBinYFound =
			 rw2DBinY[0][jPtBin];
		       std::vector<std::pair<double,double> > rw2DSfFound =
			 rw2DSf[0][jPtBin];

		       if( 
			  strcmp(name_rw_2d.c_str(),"2d_ntrk_vs_mupt") == 0
			 )
			 {
			    rwSF *= get2DSF(rw2DBinXFound,rw2DBinYFound,
					    rw2DSfFound,
					    mupt,
					    ntrk);
			 }
		       else if(
			       strcmp(name_rw_2d.c_str(),"2d_nseltrk_vs_njet") == 0
			      )
			 {
			    rwSF *= get2DSF(rw2DBinXFound,rw2DBinYFound,
					    rw2DSfFound,
					    njet,
					    nseltrk);
			 }
		    }
		  if( doRW == 3 && !isdata )
		    {
		       std::vector<std::pair<double,double> > rw3DBinXFound =
			 rw3DBinX[0][jPtBin];
		       std::vector<std::pair<double,double> > rw3DBinYFound =
			 rw3DBinY[0][jPtBin];
		       std::vector<std::pair<double,double> > rw3DBinZFound =
			 rw3DBinZ[0][jPtBin];
		       std::vector<std::pair<double,double> > rw3DSfFound =
			 rw3DSf[0][jPtBin];

		       if( 
			  strcmp(name_rw_3d.c_str(),"3d_ntrk_pt_mupt") == 0
			 )
			 {
			    rwSF *= get3DSF(rw3DBinXFound,rw3DBinYFound,rw3DBinZFound,
					    rw3DSfFound,
					    mupt,
					    (jPT-jPtMinCur)/(jPtMaxCur-jPtMinCur),
					    ntrk);
			 }
		    }
		  sfj *= rwSF;
		  sfj_btag *= rwSF_btag;
		  
		  // 1d
		  std::vector<std::string> histNAMESSEL;
		  std::vector<int> histSYS;
		  std::vector<int> histVAR;
		  std::vector<double> sfarr;
		  sfarr.clear();
		  for(int ih=0;ih<histname_jet_n;ih++)
		    {
		       for(int ihb=0;ihb<selb_n;ihb++)
			 {
			    if( !selbch_res[ihb] ) continue;

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
				      histSYS.push_back(isys);
				      histVAR.push_back(ih);
/*				      if( ihb != 1 )
					{					   
					   sfarr.push_back(sfj);
					   sfarr.push_back(sfj);
					   sfarr.push_back(sfj);
					   sfarr.push_back(sfj);
					}				      
				      else
					{					   
					   sfarr.push_back(sfj_btag);
					   sfarr.push_back(sfj_btag);
					   sfarr.push_back(sfj_btag);
					   sfarr.push_back(sfj_btag);
					}*/
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
			    //			 h->Fill(var,sfarr[ih]);
			    if( single ) 
			      {
				 h->Fill(var,sfj);
			      }
			    else 
			      {
				 int varvs = varv.size();
				 for(int iv=0;iv<varvs;iv++)
				   {
				      h->Fill(varv[iv],sfj);
				   }				 
			      }			    
			 }		       
		    }
		  histNAMESSEL.clear();

		  // 2d
		  std::vector<std::string> histNAMESSEL_2d;
		  std::vector<int> histSYS_2d;
		  std::vector<int> histVAR_2d;
		  for(int ih=0;ih<histname_jet_2d_n;ih++)
		    {
		       for(int ihb=0;ihb<selb_n;ihb++)
			 {
			    if( !selbch_res[ihb] ) continue;

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
				      histSYS_2d.push_back(isys);
				      histVAR_2d.push_back(ih);
				   }				 
			      }
			 }		       
		    }

		  int nHISTSEL_2d = histNAMESSEL_2d.size();
		  for(int ih=0;ih<nHISTSEL_2d;ih++)
		    {		       
		       TH2D *h_2d = _m2d_Jet->find(histNAMESSEL_2d.at(ih))->second;
		       
		       int hidx = int(ih/4);
		       fillThis = true;
		       std::pair<float,float> var = getVar2d(sys[histSYS_2d[hidx]],ij,histname_jet_2d[histVAR_2d[hidx]],jPtBin);
		       float varX = var.first;
		       float varY = var.second;
		       
		       if( fillThis )
			 h_2d->Fill(varX,varY,sfj);
		    }		  
		  histNAMESSEL_2d.clear();
		  
		  // 3d
		  std::vector<std::string> histNAMESSEL_3d;
		  std::vector<int> histSYS_3d;
		  std::vector<int> histVAR_3d;
		  for(int ih=0;ih<histname_jet_3d_n;ih++)
		    {
		       for(int ihb=0;ihb<selb_n;ihb++)
			 {
			    if( !selbch_res[ihb] ) continue;

			    for(int iha=0;iha<seladd_n;iha++)
			      {
				 if( !selach_res[iha] ) continue;
			    
				 for(int ihe=0;ihe<eta_n;ihe++)
				   {
				      if( !jeta_res[ihe] ) continue;
				      
				      histNAMESSEL_3d.push_back(histNAMES_3d[flavchI][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_3d.push_back(histNAMES_3d[0][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_3d.push_back(histNAMES_3d[flavchI][0][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_3d.push_back(histNAMES_3d[0][0][ihe][ihb][iha][ih][isys]);
				      histSYS_3d.push_back(isys);
				      histVAR_3d.push_back(ih);
				   }				 
			      }
			 }		       
		    }

		  int nHISTSEL_3d = histNAMESSEL_3d.size();
		  for(int ih=0;ih<nHISTSEL_3d;ih++)
		    {		       
		       TH3D *h_3d = _m3d_Jet->find(histNAMESSEL_3d.at(ih))->second;
		       
		       int hidx = int(ih/4);
		       fillThis = true;
		       std::vector<float> var = getVar3d(sys[histSYS_3d[hidx]],ij,histname_jet_3d[histVAR_3d[hidx]],jPtBin);
		       float varX = var[0];
		       float varY = var[1];
		       float varZ = var[2];
		       
		       if( fillThis )
			 h_3d->Fill(varX,varY,varZ,sfj);
		    }		  
		  histNAMESSEL_3d.clear();		  
	       }
	  }
	
	delete v_mu;
	delete v_jet;
	delete v_jet_sys_jesTotalUp;
	delete v_jet_sys_jesTotalLow;	
	delete v_jet_sys_jerTotalUp;
	delete v_jet_sys_jerTotalLow;	
     }
   
/*   bool ign = false;
   double ran = rnd->Rndm();
   if( ran > 0.5 && hst == 1 ) ign = true;
   if( ran <= 0.5 && hst == 2 ) ign = true;
   if( ran <= 0.90 && hst == 3 ) ign = true;
   if( ign ) return;
   
   long int runNumber = _v_Event->at(0).RunNumber();
   
   double SF_xsec       = _v_Event->at(0).SF_xsec();
   double SF_pu         = _v_Event->at(0).SF_pu();
   double SF_PRESCALE   = _v_Event->at(0).SF_PRESCALE();
   
   // LF mis-tag
//   bool trigPass        = _v_Event->at(0).trigPass_OR();
  
   // HF
//   bool trigPass        = _v_Event->at(0).trigPass_MUCOMB();

//   if( ! trigPass ) return;
   
   double weight        = _v_Event->at(0).mcevt_weight();

   bool failSel = false;

   // determine jet index
   // max Pt   
   int jidx = 0;

   JTRUN::Jet *j0 = &(_v_Jet->at(jidx));
   TLorentzVector j0lv = j0->lv();
   if( j0->hasMuon() ) j0lv = j0->lvSMC();
   else return;

   float jetPt = j0lv.Pt();
   
   // JZX samples could have very large weights causing spikes in distributions
   bool wSpike = false;

   if( (!strcmp(dsid,"129271")) && weight > 50 ) wSpike = true;
   if( (!strcmp(dsid,"129272")) && weight > 100 ) wSpike = true;
   if( (!strcmp(dsid,"129273")) && weight > 200 ) wSpike = true;
   if( (!strcmp(dsid,"129274")) && weight > 300 ) wSpike = true;

   if( (!strcmp(dsid,"129281")) && weight > 50 ) wSpike = true;
   if( (!strcmp(dsid,"129282")) && weight > 100 ) wSpike = true;
   if( (!strcmp(dsid,"129283")) && weight > 200 ) wSpike = true;
   if( (!strcmp(dsid,"129284")) && weight > 300 ) wSpike = true;

   if( wSpike ) failSel = true;

   double sf = 
     SF_xsec*
     SF_pu*
     weight;
   
   // FOR NOW
//   sf = 1.;

   // label of the truth particle - 15=tau lepton, 5=b quark, 4= cquark, 0=anything else

   if( _v_Jet->size() < 2 ) failSel = true;

   int njets = _v_Event->at(0).nJetAna();
   if( njets < 2 ) failSel = true;

   if( !doPS )
     {	
	for(int i=0;i<_s_Event->size();i++)
	  {
	     std::string name = _s_Event->at(i).first;
	     TH1D *h = _m1d_Event->find(name)->second;
	     
	     if( name == "h_ev_mu_rw" ) h->Fill(_v_Event->at(0).mu(),SF_pu);
	     if( name == "h_ev_mu" ) h->Fill(_v_Event->at(0).mu(),1.);
	  }
     }   

   bool spike = false;
   
   if( (!strcmp(dsid,"129270")) && jetPt > 30 ) spike = true;
   if( (!strcmp(dsid,"129271")) && jetPt > 100 ) spike = true;
   if( (!strcmp(dsid,"129272")) && jetPt > 230 ) spike = true;
   if( (!strcmp(dsid,"129273")) && jetPt > 550 ) spike = true;
   if( (!strcmp(dsid,"129274")) && jetPt > 1100 ) spike = true;

   if( (!strcmp(dsid,"129280")) && jetPt > 30 ) spike = true;
   if( (!strcmp(dsid,"129281")) && jetPt > 100 ) spike = true;
   if( (!strcmp(dsid,"129282")) && jetPt > 230 ) spike = true;
   if( (!strcmp(dsid,"129283")) && jetPt > 550 ) spike = true;
   if( (!strcmp(dsid,"129284")) && jetPt > 1100 ) spike = true;
   
   if( spike ) failSel = true;

//   if( njets != 2 ) return;

//   bool muonJet = _v_Event->at(0).muonJet();
//   if( ! muonJet ) return;

//   if( ! _v_Event->at(0).muonJet10() ) return;
   
//   if( _v_Jet->at(0).flavor_truth_label() == 5 )
//   std::cout << _v_Jet->at(0).flavor_component_sv0p_mass() << std::endl;
//     {
//	if( _v_Jet->at(0).flavor_weight_SV0() < 5.65 ) return;
//	if( _v_Jet->at(1).flavor_weight_SV0() < 5.65 ) return;

   bool inregionEta = ( fabs(j0lv.PseudoRapidity()) < 2.5 );
   if( !inregionEta ) return;
   
   bool inregionJVF = ( fabs(j0lv.PseudoRapidity()) < 2.4 &&
			j0lv.Pt() < 50 );
   
   if( inregionJVF && fabs(j0->jvtxf()) < cutJVF ) failSel = true;

   bool passMuon = false;
      
   if( jetPt >= 15 && jetPt < 40 &&
       _v_Jet->at(jidx).muonPt() > 4 ) passMuon = true;
   if( jetPt >= 40 && jetPt < 110 &&
       _v_Jet->at(jidx).muonPt() > 6 ) passMuon = true;
   if( jetPt >= 110 && jetPt < 2000 &&
       _v_Jet->at(jidx).muonPt() > 8 ) passMuon = true;

//   bool passMuonPtRel = false;   
//   if( _v_Jet->at(jidx).muonPtRel() > 0.5 ) passMuonPtRel = true;
   
//   if( !passMuon || !passMuonPtRel ) failSel = true;

   if( !passMuon ) failSel = true;
   
//   if( !passMuon || !_v_Jet->at(jidx).flavor_component_sv0p_isValid() ) failSel = true;
   
//   if( ! _v_Jet->at(1).flavor_component_sv0p_isValid() ) return;
//   if( _v_Jet->at(1).flavor_weight_SV0() < 1. ) return;
//	if( ! _v_Jet->at(0).flavor_component_sv0p_isValid() ) return;
//	if( ! _v_Jet->at(1).flavor_component_sv0p_isValid() ) return;
//	if( ! _v_Jet->at(0).flavor_component_assoctrk_index_n() ) return;
//	if( ! _v_Jet->at(1).flavor_component_assoctrk_index_n() ) return;
//	if( ! _v_Jet->at(0).flavor_component_sv0p_trk_index_n() ) return;
//	if( ! _v_Jet->at(1).flavor_component_sv0p_trk_index_n() ) return;
//	if( _v_Jet->at(0).flavor_weight_Comb() > 1.70 ) leadB = true;
//	if( _v_Jet->at(1).flavor_weight_Comb() > 1.70 ) sublB = true;
//   if( _v_Jet->at(0).flavor_component_sv0p_trk_index_n() < 4 ) return;
//	if( _v_Jet->at(1).flavor_component_sv0p_trk_index_n() < 4 ) return;
//	if( ! _v_Jet->at(1).hasMuon() ) return;
//	if( ! _v_Jet->at(0).hasMuon() ) return;
//	if( fabs(_v_Jet->at(0).maxd0track()) < 0.15 || fabs(_v_Jet->at(1).maxd0track()) < 0.15 ) return;
//	if( _v_Jet->at(0).flavor_component_sv0p_mass() + _v_Jet->at(1).flavor_component_sv0p_mass() < 2 ) return;
//     }

   if( j0lv.Pt() < 20. ) failSel = true;

   j0lv.Delete();
   
   if( failSel ) return;

   std::map<int,int> jetb;
   jetb.clear();
   
   for(int ij=0;ij<_v_Jet->size();ij++)
     {
	JTRUN::Jet jj = _v_Jet->at(ij);

//	if( ij == 0)
//	std::cout << jj.d0SignJet1_SMC() << 
//	  " (-)" << jj.d0SignJet1_SMC_sys_ALL_LOW() <<
//	  " (+)" << jj.d0SignJet1_SMC_sys_ALL_UP() <<
//	  " " << jj.hasMuon() <<
//	  std::endl;
//	std::cout << jj.lvSMC().Pt() <<
//	  " (-)" << jj.lvSMC_sys_ALL_LOW().Pt() <<
//	  " (+)" << jj.lvSMC_sys_ALL_UP().Pt() <<
//	  " " << jj.hasMuon() <<
//	  std::endl;
	
	if( jj.flavor_component_assoctrk_index_n() < 1 ) continue;
	
	std::string flavch = "NOTFOUND";
	int jmclabel = jj.flavor_truth_label();
	if( fabs(jmclabel) == 5 )  flavch = "bjet";
	if( fabs(jmclabel) == 4 )  flavch = "cjet";
//	if( fabs(jmclabel) == 15 ) flavch = "tjet";
	if( fabs(jmclabel) == 0 )  flavch = "ljet";

	double j1j2_sv0mass[100];
	TLorentzVector j1j2_m[100];
	for(int ivar=0;ivar<100;ivar++)
	  {
	     j1j2_sv0mass[ivar] = 0.;
	  }	
	
	int is1 = _s_Jet->size();
	int is2 = _s2_Jet->size();
	int is3 = _s3_Jet->size();
	int is = (is1 >= is2) ? is1 : is2;
	is = (is >= is3) ? is : is3;

//	for(int i=0;i<_s_Jet->size();i++)
	for(int i=0;i<is;i++)
	  {
	     bool fl1d = true;
	     bool fl2d = true;
	     bool fl3d = true;
	     if( i >= is1 ) fl1d = false;
	     if( i >= is2 ) fl2d = false;
	     if( i >= is3 ) fl3d = false;
	       
	     TH1D *h = 0;
	     TH2D *h2 = 0;
	     TH3D *h3 = 0;
	     std::string name = "";
	     std::string name2 = "";
	     std::string name3 = "";
	     std::string sysname = "";

	     if( !doPS )
	       {		  
		  if( fl1d )
		    {		  
		       name    = _s_Jet->at(i).first.at(0);	     
		       sysname = _s_Jet->at(i).first.at(1);
		       h = _m1d_Jet->find(name)->second;
		    }	     

		  if( fl2d )
		    {		  
		       name2    = _s2_Jet->at(i).first.at(0);
		       sysname = _s2_Jet->at(i).first.at(1);
		       h2 = _m2d_Jet->find(name2)->second;
		    }	     
		  
		  if( fl3d )
		    {		  
		       name3    = _s3_Jet->at(i).first.at(0);
		       sysname = _s3_Jet->at(i).first.at(1);
		       h3 = _m3d_Jet->find(name3)->second;
		    }
	       }
	     else
	       {
		  sysname = "";
	       }	     

	     TLorentzVector jet = jet_tlv(sysname,ij);
	     double jpt = jet.Pt();
	     double jpt0 = jet_tlv("",ij).Pt();
	     double jptHIGHEST = jet_tlv("",0).Pt();

	     bool inregionEta = ( fabs(jet.PseudoRapidity()) < 2.5 );
	     if( !inregionEta ) return;
	     
	     bool inregionJVF = ( fabs(jet.PseudoRapidity()) < 2.4 &&
				  jpt < 50 );
	     
	     if( inregionJVF && fabs(jj.jvtxf()) < cutJVF ) continue;
	     
	     bool passMuon = false;
	     if( jpt >= 15 && jpt < 40 &&
		 jj.muonPt() > 4 ) passMuon = true;
	     if( jpt >= 40 && jpt < 110 &&
		 jj.muonPt() > 6 ) passMuon = true;
	     if( jpt >= 110 && jpt < 2000 &&
		 jj.muonPt() > 8 ) passMuon = true;
	     if( !passMuon ) continue;
*/	     
/*	     double ptrwSF = 1.;
	     
	     if( ptrw && !isdata )
	       {	
		  for( int ib=0;ib<ptrwBin.size();ib++ )
		    {
		       double blow = ptrwBin.at(ib).first;
		       double bup = ptrwBin.at(ib).second;
		       
		       if( jet.Pt()/1000. > blow && jet.Pt()/1000. < bup )
			 {
			    ptrwSF = ptrwSf.at(ib).first;
			 }	
		    }   
	       }

	     double sfj = sf*ptrwSF;*/
/*	     
	     std::string selch = "NOTFOUND";
	     std::string etach = "NOTFOUND";
	     std::string selbch = "NOTFOUND";

	     jPtBin = 0;
	     float sfLUMI = 1.;

//	     jPt = jpt0;
//	     jPt = jpt;
	     jPt = jptHIGHEST;
	     
	     if( doLUMI )
	       {		  
		  if( jpt >= 20 && jpt <= 30 )   {selch = "pt20t30"; jPtBin = 1; sfLUMI = psSf[1];}
		  if( jpt > 30 && jpt <= 40 )   {selch = "pt30t40"; jPtBin = 2; sfLUMI = psSf[2];}
		  if( jpt > 40 && jpt <= 50 )   {selch = "pt40t50"; jPtBin = 3; sfLUMI = psSf[3];}
		  if( jpt > 50 && jpt <= 60 )   {selch = "pt50t60"; jPtBin = 4; sfLUMI = psSf[4];}
		  if( jpt > 60 && jpt <= 75 )   {selch = "pt60t75"; jPtBin = 5; sfLUMI = psSf[5];}
		  if( jpt > 75 && jpt <= 90 )   {selch = "pt75t90"; jPtBin = 6; sfLUMI = psSf[6];}
		  if( jpt > 90 && jpt <= 110 )   {selch = "pt90t110"; jPtBin = 7; sfLUMI = psSf[7];}
		  if( jpt > 110 && jpt <= 140 )  {selch = "pt110t140"; jPtBin = 8; sfLUMI = psSf[8];}
		  if( jpt > 140 && jpt <= 200 )  {selch = "pt140t200"; jPtBin = 9; sfLUMI = psSf[9];}
		  if( jpt > 200 && jpt <= 300 )  {selch = "pt200t300"; jPtBin = 10; sfLUMI = psSf[10];}
		  if( jpt > 300 && jpt <= 400 )  {selch = "pt300t400"; jPtBin = 11; sfLUMI = psSf[11];}
		  if( jpt > 400 && jpt <= 500 )  {selch = "pt400t500"; jPtBin = 12; sfLUMI = psSf[12];}
		  if( jpt > 500 && jpt <= 700 )  {selch = "pt500t700"; jPtBin = 13; sfLUMI = psSf[13];}
		  if( jpt > 700 && jpt <= 1000 )  {selch = "pt700t1000"; jPtBin = 14; sfLUMI = psSf[14];}
		  if( jpt > 1000 && jpt <= 1500 )  {selch = "pt1000t1500"; jPtBin = 15; sfLUMI = psSf[15];}
		  if( jpt > 1500 && jpt <= 2000 )  {selch = "pt1500t2000"; jPtBin = 16; sfLUMI = psSf[16];}

		  // use only one jet per Pt bin
		  if( i == 0 && !highPT )
		    {		       
		       std::map<int,int>::iterator it = jetb.find(jPtBin);
		       if( it == jetb.end() )
			 jetb.insert(std::pair<int,int>(jPtBin,ij));
		       else
			 break;
		    }
	       }
	     
	     PRESCALE = (SF_PRESCALE > 0.) ? 1./SF_PRESCALE : 0.;

	     if( !isdata )		    	       
	       {
		  sfj *= sfLUMI; // works only for the highest-PT jet !
	       }
//	     if( isdata )
//	       {
//		  sfj /= sfLUMI; // works only for the highest-PT jet !
//	       }
	     _treePRESCALE->Fill();
	     if( doPS ) return;

	     sd0t1 = -666;
	     sd0t2 = -666;
	     cosphi = -666;
	     
	     if( _v_Jet->size() > 0 )
	       sd0t1 = _v_Jet->at(0).d0SignJet1();
	     if( _v_Jet->size() > 1 )
	       sd0t2 = _v_Jet->at(1).d0SignJet1();
	     
	     double phi1 = -666;
	     double phi2 = -666;
	     if( _v_Jet->size() > 0 )
	       phi1 = _v_Jet->at(0).phi1();
	     if( _v_Jet->size() > 1 )
	       phi2 = _v_Jet->at(1).phi1();
	     
	     cosphi = deltaPhi(phi1,phi2);
	     if( _v_Jet->size() > 0 )
	       ptrel = _v_Jet->at(0).muonPtRel();
	     fl = jmclabel;

	     double jeta = jet.PseudoRapidity();
	     if( fabs(jeta) >= 0.0 && fabs(jeta) <= 0.6 )  etach = "eta0p0t0p6";
	     if( fabs(jeta) > 0.6 && fabs(jeta) <= 1.2 )   etach = "eta0p6t1p2";
	     if( fabs(jeta) > 1.2 && fabs(jeta) <= 1.8 )   etach = "eta1p2t1p8";
	     if( fabs(jeta) > 1.8 && fabs(jeta) <= 2.5 )   etach = "eta1p8t2p5";
	     
	     double jbtsv0 = jj.flavor_weight_SV0();
	     double jbtsv1 = jj.flavor_weight_SV1();
	     double jbtsv2 = jj.flavor_weight_SV2();
	     
	     double jbtip3dsv1 = jj.flavor_weight_Comb();
	     double jbtjetfittercombnn = jj.flavor_weight_JetFitterCOMBNN();
	     double jbtmv1 = jj.flavor_weight_MV1();
	     double pb = jj.flavor_component_jfitcomb_pb();
	     double pc = jj.flavor_component_jfitcomb_pc();
	     double jbtjetfittercombnnc = (pc != 0.) ? log(pb/pc) : 0.;
	     
	     int jbtsvvalid = jj.flavor_component_svp_isValid();
	     int jbtsv0valid = jj.flavor_component_sv0p_isValid();
	     
	     const int ntaggers = 5;
	     bool selbch_res[ntaggers];
	     for( int ibt=0;ibt<ntaggers;ibt++ ) selbch_res[ibt] = false;

//	     if( jbtsv0valid )   selbch_res[1] = true;
////	     if( jbtmv1 > 0.985 )   selbch_res[1] = true;	
////	     if( jbtmv1 > 0.0616 )   selbch_res[1] = true;
	     
	     if( jbtmv1 > 0.3900 )   selbch_res[1] = true;
	     if( jbtmv1 > 0.8119 )   selbch_res[2] = true;
	     if( jbtmv1 > 0.9867 )   selbch_res[3] = true;
	     
////	     if( jbtmv1 > 0.9925154 )   selbch_res[3] = true;
//	     if( jbtmv1 > 0.148 )   selbch_res[2] = true;
//	     if( jbtsv0 > 5.70 )   selbch_res[6] = true;
//	     if( jbtjetfittercombnn > 1.10 )   selbch_res[2] = true;
//	     if( jbtjetfittercombnn > 0.65 )   selbch_res[3] = true;
//	     if( jbtjetfittercombnn > -0.95 )   selbch_res[4] = true;
//	     if( jbtjetfittercombnn > -2.60 )   selbch_res[5] = true;

	     bool jsv = false;
	     for(int ijet=0;ijet<_v_Jet->size();ijet++)
	       {	   
		  JTRUN::Jet JET = _v_Jet->at(ijet);
		  if( ijet != ij )
		    {		       
		       jsv = JET.flavor_component_sv0p_isValid();
		       if( jsv ) break;
		    }		  
	       }		  
	     

	     // UNTAGbc
	     bool untagbc = true;
	       {
		  // the highest-Pt jet is untagged
		  JTRUN::Jet JET = _v_Jet->at(0);
		  float w1 = JET.flavor_weight_JetFitterCOMBNN();
		  float mv1w = JET.flavor_weight_MV1();
		  float pb = JET.flavor_component_jfitcomb_pb();
		  float pc = JET.flavor_component_jfitcomb_pc();
		  float pu = JET.flavor_component_jfitcomb_pu();
		  float pbC = JET.flavor_component_jfitc_pb();
		  float pcC = JET.flavor_component_jfitc_pc();
		  float puC = JET.flavor_component_jfitc_pu();
		  float w2a = (pb != 0.) ? log(pc/pb) : 0.;
		  float w2b = (pu != 0.) ? log(pc/pu) : 0.;
		  float w2aC = (pb != 0.) ? log(pcC/pbC) : 0.;
		  float w2bC = (pu != 0.) ? log(pcC/puC) : 0.;
		  if( w1 > -4.350 ) untagbc = false;
//		  if( w1 > -3.60 || (w2a > -1. && w2b > 1.) || JET.hasMuon() ) untagbc = false;
	       }		  
	     if( untagbc )
	       selbch_res[4] = true;
//	     selbch_res[1] = true;

	     if( isdata ) fl = untagbc;
	     
	     _treeBEAM->Fill();
	     _treeSPLOT->Fill();
	     if( doBEAM || doSPLOT ) return;
	     
	     for( int itag=0;itag<ntaggers;itag++ )
	       {
		  if( itag == 0 || selbch_res[itag] ) selbch = selb[itag];
		  else continue;

		  const int ipref = 8;
		  std::string pref1 = flavch+"_"+selch+"_"+etach+"_"+selbch+sysname;
		  std::string pref2 = "ajet_"+selch+"_"+etach+"_"+selbch+sysname;
		  std::string pref3 = flavch+"_nosel_"+etach+"_"+selbch+sysname;
		  std::string pref4 = "ajet_nosel_"+etach+"_"+selbch+sysname;
		  std::string pref5 = "ajet_nosel_nosel_"+selbch+sysname;
		  std::string pref6 = "ajet_"+selch+"_nosel_"+selbch+sysname;
		  std::string pref7 = flavch+"_nosel_nosel_"+selbch+sysname;
		  std::string pref8 = flavch+"_"+selch+"_nosel_"+selbch+sysname;
		  std::string prefa[ipref] = {pref1,pref2,pref3,pref4,pref5,pref6,pref7,pref8};

		  for(int ip=0;ip<ipref;ip++)
		    {		       
		       std::string pf = prefa[ip]; 
		       
		       if( fl1d )
			 {
			    std::string nameSubStr = name.substr(0,name.length() - pf.length());
			    int pos = name.find(pf.c_str());
			    if( pos >= 0 )
			      {
//				 std::cout << pf << std::endl;
//				 std::cout << nameSubStr << pf << " " << ip << " " << ij << std::endl;

				 float var = getVar(sysname,ij,nameSubStr);

				 if( ij == jidx && jj.nTracksSel() > 2 && jj.hasMuon() && highPT ) {h->Fill(var,sfj);}
				 if( jj.nTracksSel() > 2 && jj.hasMuon() && !highPT ) {h->Fill(var,sfj);}

//				 if( jj.nTracksSel() > 1 && !highPT ) {h->Fill(var,sfj);}
				 
			      }
			 }
		       		       
		       if( fl2d )
			 {
			    std::string nameSubStr = name2.substr(0,name2.length() - pf.length());
			    int pos = name2.find(pf.c_str());
			    if( pos >= 0 )
			      {
				 std::pair<float,float> pvar = getVar2d(sysname,ij,nameSubStr);
				 float varX = pvar.first;
				 float varY = pvar.second;

				 if( ij == jidx && jj.nTracksSel() > 2 && jj.hasMuon() && highPT ) {h2->Fill(varX,varY,sfj);}
				 if( jj.nTracksSel() > 2 && jj.hasMuon() && !highPT ) {h2->Fill(varX,varY,sfj);}
				 
				 //				 std::cout << name2 << " " << nameSubStr << std::endl;
//				 std::cout << pf << std::endl;
//				 std::cout << nameSubStr << pf << std::endl;
			      }
			 }
		       
		    }		  
	       }
	  }
     }*/
}

void LTANA::Hist::close()
{
   _fout->Write();
   _fout->Close();
//   _fevc.close();
   
//   delete rnd;
}

void LTANA::Hist::printout()
{
}
/*
TLorentzVector SYSANA::Hist::jet_tlv(std::string sys,int ijet)
{
   TLorentzVector vjet;
   vjet.SetPxPyPzE(0,0,0,0);
   
   if( ijet <= _v_Jet->size() )
     {	   
	if( (sys == "" ||
	     sys == "_smearDIR_low" ||
	     sys == "_sys_up" || sys == "_sys_low") || isdata )
	  {
	     vjet = _v_Jet->at(ijet).lv();
	     if( _v_Jet->at(ijet).hasMuon() && !doPS )
	       vjet = _v_Jet->at(ijet).lvSMC();
	  }
	else if( sys == "_jes_low" )
	  {
	     vjet = _v_Jet->at(ijet).lv_sys_MULTIJES_LOW();
	     if( _v_Jet->at(ijet).hasMuon() )
	       vjet = _v_Jet->at(ijet).lvSMC_sys_MULTIJES_LOW();
	  }	
	else if( sys == "_jes_up" )
	  {
	     vjet = _v_Jet->at(ijet).lv_sys_MULTIJES_UP();
	     if( _v_Jet->at(ijet).hasMuon() )
	       vjet = _v_Jet->at(ijet).lvSMC_sys_MULTIJES_UP();
	  }	
	else if( sys == "_jer_low" )
	  {
	     vjet = _v_Jet->at(ijet).lv_sys_JER_LOW();
	     if( _v_Jet->at(ijet).hasMuon() )
	       vjet = _v_Jet->at(ijet).lvSMC_sys_JER_LOW();
	  }	
	else if( sys == "_jer_up" )
	  {
	     vjet = _v_Jet->at(ijet).lv_sys_JER_UP();
	     if( _v_Jet->at(ijet).hasMuon() )
	       vjet = _v_Jet->at(ijet).lvSMC_sys_JER_UP();
	  }	
	else if( sys == "_smcALL_low" )
	  {
	     if( _v_Jet->at(ijet).hasMuon() )
	       vjet = _v_Jet->at(ijet).lvSMC_sys_ALL_LOW();
	     else
	       vjet = _v_Jet->at(ijet).lv();
	  }	
	else if( sys == "_smcALL_up" )
	  {
	     if( _v_Jet->at(ijet).hasMuon() )	       
	       vjet = _v_Jet->at(ijet).lvSMC_sys_ALL_UP();
	     else
	       vjet = _v_Jet->at(ijet).lv();
	  }	
	else if( sys == "_smearDIR_up" )
	  {
	     if( _v_Jet->at(ijet).hasMuon() )	       
	       vjet = _v_Jet->at(ijet).lvSMC_sys_SMEARDIR();
	     else
	       vjet = _v_Jet->at(ijet).lv();
	  }	
	else
	  {
	     std::cout << "Jet lv not found: " << sys << std::endl;
	     exit(1);
	  }
     }   

   return vjet;
}*/

float LTANA::Hist::getVar(std::string sys,int ijet,std::string varName,int ibin)
{
   float var = -666;

//   if( ibin-1 < 0 ) return var;
   
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
//	     for(int im=0;im<muidx.size();im++)
//	       {		  
//		  var = ntP->Muon_pt[muidx[im]];
//	       }	     
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

/*	if( (sys == "" ||
	     sys == "_smearDIR_low" ||
	     sys == "_sys_up" || sys == "_sys_low" ||
	     sys == "_pu_up" || sys == "_pu_low" ||
	     sys == "_gsplit_up" || sys == "_gsplit_low" ||
	     sys == "_bfrag_up" || sys == "_bfrag_low" ||
	     sys == "_cdfrag_up" || sys == "_cdfrag_low" ||
	     sys == "_cfrag_up" || sys == "_cfrag_low" ||
	     sys == "_ksl_up" || sys == "_ksl_low" ||
	     sys == "_ntrkgen_up" || sys == "_ntrkgen_low"
	    ) || isdata )
	  {*/
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
/*	  }
	else if( sys == "_jes_up" )
	  {
	     if( strcmp(varName.c_str(),"h_j1_pt_") == 0 )
	       {		  
		  var = v_jet_sys_jesTotalUp->Pt()/1000.;
	       }	     
	  }	
	else if( sys == "_jes_low" )
	  {
	     if( strcmp(varName.c_str(),"h_j1_pt_") == 0 )
	       {		  
		  var = v_jet_sys_jesTotalLow->Pt()/1000.;
	       }	     
	  }	
	else if( sys == "_jer_up" )
	  {
	     if( strcmp(varName.c_str(),"h_j1_pt_") == 0 )
	       {		  
		  var = v_jet_sys_jerTotalUp->Pt()/1000.;
	       }	     
	  }	
	else if( sys == "_jer_low" )
	  {
	     if( strcmp(varName.c_str(),"h_j1_pt_") == 0 )
	       {		  
		  var = v_jet_sys_jerTotalLow->Pt()/1000.;
	       }	     
	  }	
	else
	  {
	     std::cout << "No such systematic found: " << sys << std::endl;
	     exit(1);
	  }*/
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

std::pair<float,float> LTANA::Hist::getVar2d(std::string sys,int ijet,std::string varName,int ibin)
{
   float varX = -666;
   float varY = -666;
   
   if( ijet <= ntP->nJet )
     {	   
	if( strcmp(varName.c_str(),"h_j1_JP_vs_nseltrk_") == 0 )
	  {		  
	     varX = ntP->Jet_nseltracks[ijet];
	     varY = Jet_Proba_New;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_nseltrk_vs_ntrkgen_") == 0 )
	  {		  
	     varY = ntP->Jet_nseltracks[ijet];
	     varX = ntrkgen;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_JP_vs_njet_") == 0 )
	  {
	     varX = ntP->nJet;
	     varY = Jet_Proba_New;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_JP_vs_jeta_") == 0 )
	  {
	     varX = ntP->Jet_eta[ijet];
	     varY = Jet_Proba_New;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_JP_vs_nsv_") == 0 )
	  {
	     varX = ntP->nSV;
	     varY = Jet_Proba_New;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_JP_vs_pt_") == 0 )
	  {	     
	     double jptmax = 1250.;
	     double jptmin = 0.;
	     if( ibin > 0 ) 
	       {
		  jptmax = jPtMax[ibin-1];
		  jptmin = jPtMin[ibin-1];
	       }	     

	     varX = (getPt(sys)-jptmin)/(jptmax-jptmin);
	     varY = Jet_Proba_New;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_JP_vs_CSV_") == 0 )
	  {
	     varX = ntP->Jet_CombSvx[ijet];
	     varY = Jet_Proba_New;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_BJP_vs_CSV_") == 0 )
	  {
	     varX = ntP->Jet_CombSvx[ijet];
	     varY = ntP->Jet_Bprob[ijet];
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_pt_vs_nseltrk_") == 0 )
	  {	    
	     double jptmax = 1250.;
	     double jptmin = 0.;
	     if( ibin > 0 ) 
	       {
		  jptmax = jPtMax[ibin-1];
		  jptmin = jPtMin[ibin-1];
	       }	     

	     varY = (getPt(sys)-jptmin)/(jptmax-jptmin);
	     varX = ntP->Jet_nseltracks[ijet];
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_pt_vs_njet_") == 0 )
	  {	    
	     double jptmax = 1250.;
	     double jptmin = 0.;
	     if( ibin > 0 ) 
	       {
		  jptmax = jPtMax[ibin-1];
		  jptmin = jPtMin[ibin-1];
	       }	     

	     varY = (getPt(sys)-jptmin)/(jptmax-jptmin);
	     varX = ntP->nJet;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_pt_vs_jeta_") == 0 )
	  {	    
	     double jptmax = 1250.;
	     double jptmin = 0.;
	     if( ibin > 0 ) 
	       {
		  jptmax = jPtMax[ibin-1];
		  jptmin = jPtMin[ibin-1];
	       }	     

	     varY = (getPt(sys)-jptmin)/(jptmax-jptmin);
	     varX = ntP->Jet_eta[ijet];
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_JP_vs_mupt_") == 0 )
	  {		  
	     // highest-Pt muon in a jet
	     if( muidx.size() > 0 )
	       varX = ntP->Muon_pt[muidx[0]];
	     else fillThis = false;
	     varY = Jet_Proba_New;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_njet_vs_mupt_") == 0 )
	  {		  
	     // highest-Pt muon in a jet
	     if( muidx.size() > 0 )
	       varX = ntP->Muon_pt[muidx[0]];
	     else fillThis = false;
	     varY = ntP->nJet;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_mupt_vs_jeta_") == 0 )
	  {		  
	     // highest-Pt muon in a jet
	     if( muidx.size() > 0 )
	       varY = ntP->Muon_pt[muidx[0]];
	     else fillThis = false;
	     varX = ntP->Jet_eta[ijet];
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_njet_vs_jeta_") == 0 )
	  {		  
	     varX = ntP->Jet_eta[ijet];
	     varY = ntP->nJet;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_nseltrk_vs_mupt_") == 0 )
	  {		  
	     if( muidx.size() > 0 )
	       varX = ntP->Muon_pt[muidx[0]];
	     else fillThis = false;
	     varY = ntP->Jet_nseltracks[ijet];
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_nseltrk_vs_njet_") == 0 )
	  {		  
	     varX = ntP->nJet;
	     varY = ntP->Jet_nseltracks[ijet];
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_nseltrk_vs_jeta_") == 0 )
	  {		  
	     varX = ntP->Jet_eta[ijet];
	     varY = ntP->Jet_nseltracks[ijet];
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_pt_vs_mupt_") == 0 )
	  {	     	     
	     // highest-Pt muon in a jet
	     if( muidx.size() > 0 )
	       varX = ntP->Muon_pt[muidx[0]];
	     else fillThis = false;

	     double jptmax = 1250.;
	     double jptmin = 0.;
	     if( ibin > 0 )
	       {
		  jptmax = jPtMax[ibin-1];
		  jptmin = jPtMin[ibin-1];
	       }	     
	     
	     varY = (getPt(sys)-jptmin)/(jptmax-jptmin);
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_nseltrk_vs_nsv_") == 0 )
	  {		  
	     varX = ntP->nSV;
	     varY = ntP->Jet_nseltracks[ijet];
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_njet_vs_nsv_") == 0 )
	  {
	     if( ijet == 0 )
	       {		  
		  varX = ntP->nSV;
		  varY = ntP->nJet;
	       }
	     else fillThis = false;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_mupt_vs_nsv_") == 0 )
	  {		  
	     // highest-Pt muon in a jet
	     if( muidx.size() > 0 )
	       varY = ntP->Muon_pt[muidx[0]];
	     else fillThis = false;
	     varX = ntP->nSV;
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_jeta_vs_nsv_") == 0 )
	  {		  
	     varX = ntP->nSV;
	     varY = ntP->Jet_eta[ijet];
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_pt_vs_nsv_") == 0 )
	  {	    
	     double jptmax = 1250.;
	     double jptmin = 0.;
	     if( ibin > 0 ) 
	       {
		  jptmax = jPtMax[ibin-1];
		  jptmin = jPtMin[ibin-1];
	       }	     

	     varY = (getPt(sys)-jptmin)/(jptmax-jptmin);
	     varX = ntP->nSV;
	  }	     
	else
	  {
	     std::cout << "Not found:" << varName << std::endl;
	     exit(1);
	  }	
     }   
   
   return std::make_pair(varX,varY);
}

std::vector<float> LTANA::Hist::getVar3d(std::string sys,int ijet,std::string varName,int ibin)
{
   float varX = -666;
   float varY = -666;
   float varZ = -666;
   
   if( ijet <= ntP->nJet )
     {	   
	if( strcmp(varName.c_str(),"h_j1_ntrk_vs_pt_vs_mupt_") == 0 )
	  {		  
	     varZ = ntP->Jet_ntracks[ijet];
	     
	     double jptmax = 1250.;
	     double jptmin = 0.;
	     if( ibin > 0 ) 
	       {
		  jptmax = jPtMax[ibin-1];
		  jptmin = jPtMin[ibin-1];
	       }	     
	     varY = (getPt(sys)-jptmin)/(jptmax-jptmin);

	     // highest-Pt muon in a jet
	     if( muidx.size() > 0 )
	       varX = ntP->Muon_pt[muidx[0]];
	  }	     
     }   

   std::vector<float> res;
   res.push_back(varX);
   res.push_back(varY);
   res.push_back(varZ);
   return res;
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
   else if( sys == "_jes_up" )
     {
	var = v_jet_sys_jesTotalUp->Pt();
     }	
   else if( sys == "_jes_low" )
     {
	var = v_jet_sys_jesTotalLow->Pt();
     }
   else if( sys == "_jer_up" )
     {
	var = v_jet_sys_jerTotalUp->Pt();
     }	
   else if( sys == "_jer_low" )
     {
	var = v_jet_sys_jerTotalLow->Pt();
     }	
   else
     {
	std::cout << "No jet Pt for: " << sys << std::endl;
	exit(1);
     }	

   return var;
}

bool LTANA::Hist::passTrig(int trigIdx)
{
   int bitIdx = trigIdx/32;
   if ( ntP->BitTrigger[bitIdx] & ( 1 << (trigIdx - bitIdx*32) ) ) return true;
   else return false;
}

void LTANA::Hist::initRePU()
{   
   WeightPU[0] = 0.243019;
   WeightPU[1] = 0.315341;
   WeightPU[2] = 0.325947;
   WeightPU[3] = 0.211569;
   WeightPU[4] = 0.18514;
   WeightPU[5] = 0.5576;
   WeightPU[6] = 0.443999;
   WeightPU[7] = 0.445924;
   WeightPU[8] = 0.62719;
   WeightPU[9] = 0.942706;
   WeightPU[10] = 1.33418;
   WeightPU[11] = 1.68355;
   WeightPU[12] = 1.73385;
   WeightPU[13] = 1.55081;
   WeightPU[14] = 1.32517;
   WeightPU[15] = 1.15726;
   WeightPU[16] = 1.07075;
   WeightPU[17] = 1.04477;
   WeightPU[18] = 1.06226;
   WeightPU[19] = 1.10593;
   WeightPU[20] = 1.14746;
   WeightPU[21] = 1.17303;
   WeightPU[22] = 1.18548;
   WeightPU[23] = 1.18546;
   WeightPU[24] = 1.16609;
   WeightPU[25] = 1.12119;
   WeightPU[26] = 1.05037;
   WeightPU[27] = 0.957803;
   WeightPU[28] = 0.848249;
   WeightPU[29] = 0.727987;
   WeightPU[30] = 0.604889;
   WeightPU[31] = 0.486587;
   WeightPU[32] = 0.378377;
   WeightPU[33] = 0.283843;
   WeightPU[34] = 0.204733;
   WeightPU[35] = 0.14144;
   WeightPU[36] = 0.0936249;
   WeightPU[37] = 0.0595571;
   WeightPU[38] = 0.0365776;
   WeightPU[39] = 0.0218727;
   WeightPU[40] = 0.0128692;
   WeightPU[41] = 0.00754778;
   WeightPU[42] = 0.00448146;
   WeightPU[43] = 0.00273972;
   WeightPU[44] = 0.00175546;
   WeightPU[45] = 0.00119153;
   WeightPU[46] = 0.000859364;
   WeightPU[47] = 0.000655574;
   WeightPU[48] = 0.000523753;
   WeightPU[49] = 0.000433495;
   WeightPU[50] = 0.000368473;
   WeightPU[51] = 0.000319238;
   WeightPU[52] = 0.000280556;
   WeightPU[53] = 0.000249037;
   WeightPU[54] = 0.000222259;
   WeightPU[55] = 0.000198889;
   WeightPU[56] = 0.000177947;
   WeightPU[57] = 0.000158848;
   WeightPU[58] = 0.000141149;
   WeightPU[59] = 0.00026219;
   WeightPUmin[0] = 0.259393;
   WeightPUmin[1] = 0.434519;
   WeightPUmin[2] = 0.37735;
   WeightPUmin[3] = 0.225517;
   WeightPUmin[4] = 0.302279;
   WeightPUmin[5] = 1.08521;
   WeightPUmin[6] = 0.721086;
   WeightPUmin[7] = 0.680151;
   WeightPUmin[8] = 0.921338;
   WeightPUmin[9] = 1.31871;
   WeightPUmin[10] = 1.81825;
   WeightPUmin[11] = 2.10762;
   WeightPUmin[12] = 1.99973;
   WeightPUmin[13] = 1.72798;
   WeightPUmin[14] = 1.45569;
   WeightPUmin[15] = 1.24972;
   WeightPUmin[16] = 1.13635;
   WeightPUmin[17] = 1.09583;
   WeightPUmin[18] = 1.10338;
   WeightPUmin[19] = 1.13794;
   WeightPUmin[20] = 1.1715;
   WeightPUmin[21] = 1.18818;
   WeightPUmin[22] = 1.18252;
   WeightPUmin[23] = 1.14739;
   WeightPUmin[24] = 1.07844;
   WeightPUmin[25] = 0.980643;
   WeightPUmin[26] = 0.862823;
   WeightPUmin[27] = 0.733342;
   WeightPUmin[28] = 0.600672;
   WeightPUmin[29] = 0.47406;
   WeightPUmin[30] = 0.360466;
   WeightPUmin[31] = 0.263462;
   WeightPUmin[32] = 0.184235;
   WeightPUmin[33] = 0.12289;
   WeightPUmin[34] = 0.0781201;
   WeightPUmin[35] = 0.0473791;
   WeightPUmin[36] = 0.0275978;
   WeightPUmin[37] = 0.0155869;
   WeightPUmin[38] = 0.00863213;
   WeightPUmin[39] = 0.0047608;
   WeightPUmin[40] = 0.0026632;
   WeightPUmin[41] = 0.00154222;
   WeightPUmin[42] = 0.000941929;
   WeightPUmin[43] = 0.000613648;
   WeightPUmin[44] = 0.000427372;
   WeightPUmin[45] = 0.0003153;
   WeightPUmin[46] = 0.000243402;
   WeightPUmin[47] = 0.000194427;
   WeightPUmin[48] = 0.000159188;
   WeightPUmin[49] = 0.000132601;
   WeightPUmin[50] = 0.000111769;
   WeightPUmin[51] = 9.48293e-05;
   WeightPUmin[52] = 8.0714e-05;
   WeightPUmin[53] = 6.86993e-05;
   WeightPUmin[54] = 5.82656e-05;
   WeightPUmin[55] = 4.9159e-05;
   WeightPUmin[56] = 4.11881e-05;
   WeightPUmin[57] = 3.42326e-05;
   WeightPUmin[58] = 2.81834e-05;
   WeightPUmin[59] = 4.83047e-05;
   WeightPUmax[0] = 0.22856;
   WeightPUmax[1] = 0.219793;
   WeightPUmax[2] = 0.293184;
   WeightPUmax[3] = 0.192268;
   WeightPUmax[4] = 0.129795;
   WeightPUmax[5] = 0.289582;
   WeightPUmax[6] = 0.265823;
   WeightPUmax[7] = 0.295872;
   WeightPUmax[8] = 0.425999;
   WeightPUmax[9] = 0.673774;
   WeightPUmax[10] = 0.977477;
   WeightPUmax[11] = 1.29103;
   WeightPUmax[12] = 1.45043;
   WeightPUmax[13] = 1.37586;
   WeightPUmax[14] = 1.20079;
   WeightPUmax[15] = 1.06208;
   WeightPUmax[16] = 0.998691;
   WeightPUmax[17] = 0.989323;
   WeightPUmax[18] = 1.01604;
   WeightPUmax[19] = 1.06718;
   WeightPUmax[20] = 1.11675;
   WeightPUmax[21] = 1.14975;
   WeightPUmax[22] = 1.16997;
   WeightPUmax[23] = 1.18467;
   WeightPUmax[24] = 1.19447;
   WeightPUmax[25] = 1.19354;
   WeightPUmax[26] = 1.17375;
   WeightPUmax[27] = 1.13066;
   WeightPUmax[28] = 1.06431;
   WeightPUmax[29] = 0.97763;
   WeightPUmax[30] = 0.874494;
   WeightPUmax[31] = 0.760469;
   WeightPUmax[32] = 0.642338;
   WeightPUmax[33] = 0.52728;
   WeightPUmax[34] = 0.420179;
   WeightPUmax[35] = 0.32374;
   WeightPUmax[36] = 0.240607;
   WeightPUmax[37] = 0.172234;
   WeightPUmax[38] = 0.118674;
   WeightPUmax[39] = 0.0789503;
   WeightPUmax[40] = 0.0509717;
   WeightPUmax[41] = 0.0321675;
   WeightPUmax[42] = 0.0200234;
   WeightPUmax[43] = 0.0124268;
   WeightPUmax[44] = 0.00780142;
   WeightPUmax[45] = 0.00502405;
   WeightPUmax[46] = 0.00336762;
   WeightPUmax[47] = 0.00237717;
   WeightPUmax[48] = 0.00177511;
   WeightPUmax[49] = 0.00139811;
   WeightPUmax[50] = 0.00115293;
   WeightPUmax[51] = 0.000985738;
   WeightPUmax[52] = 0.000867016;
   WeightPUmax[53] = 0.000779338;
   WeightPUmax[54] = 0.000711555;
   WeightPUmax[55] = 0.000657417;
   WeightPUmax[56] = 0.000612393;
   WeightPUmax[57] = 0.000573434;
   WeightPUmax[58] = 0.000538038;
   WeightPUmax[59] = 0.00106137;
}

void LTANA::Hist::initRePU2011()
{   
   WeightPU[0] = 0.42814;
   WeightPU[1] = 0.852011;
   WeightPU[2] = 1.23782;
   WeightPU[3] = 1.50857;
   WeightPU[4] = 1.67743;
   WeightPU[5] = 1.71335;
   WeightPU[6] = 1.63117;
   WeightPU[7] = 1.4899;
   WeightPU[8] = 1.31817;
   WeightPU[9] = 1.13156;
   WeightPU[10] = 0.959846;
   WeightPU[11] = 0.793424;
   WeightPU[12] = 0.658323;
   WeightPU[13] = 0.536642;
   WeightPU[14] = 0.442476;
   WeightPU[15] = 0.364995;
   WeightPU[16] = 0.301626;
   WeightPU[17] = 0.245887;
   WeightPU[18] = 0.199188;
   WeightPU[19] = 0.158801;
   WeightPU[20] = 0.125015;
   WeightPU[21] = 0.0965054;
   WeightPU[22] = 0.0743175;
   WeightPU[23] = 0.0552261;
   WeightPU[24] = 0.0410448;
   WeightPU[25] = 0.0300012;
   WeightPU[26] = 0.0216022;
   WeightPU[27] = 0.01554;
   WeightPU[28] = 0.0109019;
   WeightPU[29] = 0.0077661;
   WeightPU[30] = 0.00527189;
   WeightPU[31] = 0.00367071;
   WeightPU[32] = 0.00247471;
   WeightPU[33] = 0.0016687;
   WeightPU[34] = 0.00223246;
   WeightPUmin[0] = 0.508648;
   WeightPUmin[1] = 1.00906;
   WeightPUmin[2] = 1.45877;
   WeightPUmin[3] = 1.76461;
   WeightPUmin[4] = 1.94019;
   WeightPUmin[5] = 1.9487;
   WeightPUmin[6] = 1.80937;
   WeightPUmin[7] = 1.59264;
   WeightPUmin[8] = 1.33497;
   WeightPUmin[9] = 1.06071;
   WeightPUmin[10] = 0.80788;
   WeightPUmin[11] = 0.577805;
   WeightPUmin[12] = 0.397835;
   WeightPUmin[13] = 0.257752;
   WeightPUmin[14] = 0.162172;
   WeightPUmin[15] = 0.0985342;
   WeightPUmin[16] = 0.0582882;
   WeightPUmin[17] = 0.0332803;
   WeightPUmin[18] = 0.0185821;
   WeightPUmin[19] = 0.0100938;
   WeightPUmin[20] = 0.0053696;
   WeightPUmin[21] = 0.00278412;
   WeightPUmin[22] = 0.00143351;
   WeightPUmin[23] = 0.000709667;
   WeightPUmin[24] = 0.000350299;
   WeightPUmin[25] = 0.00016959;
   WeightPUmin[26] = 8.06722e-05;
   WeightPUmin[27] = 3.82429e-05;
   WeightPUmin[28] = 1.76357e-05;
   WeightPUmin[29] = 8.23732e-06;
   WeightPUmin[30] = 3.65711e-06;
   WeightPUmin[31] = 1.66109e-06;
   WeightPUmin[32] = 7.28646e-07;
   WeightPUmin[33] = 3.18864e-07;
   WeightPUmin[34] = 2.06626e-07;
   WeightPUmax[0] = 0.321623;
   WeightPUmax[1] = 0.633854;
   WeightPUmax[2] = 0.929572;
   WeightPUmax[3] = 1.1604;
   WeightPUmax[4] = 1.34017;
   WeightPUmax[5] = 1.44133;
   WeightPUmax[6] = 1.46356;
   WeightPUmax[7] = 1.44183;
   WeightPUmax[8] = 1.3872;
   WeightPUmax[9] = 1.30012;
   WeightPUmax[10] = 1.20261;
   WeightPUmax[11] = 1.07688;
   WeightPUmax[12] = 0.957174;
   WeightPUmax[13] = 0.824407;
   WeightPUmax[14] = 0.708206;
   WeightPUmax[15] = 0.601179;
   WeightPUmax[16] = 0.506317;
   WeightPUmax[17] = 0.417744;
   WeightPUmax[18] = 0.340911;
   WeightPUmax[19] = 0.272991;
   WeightPUmax[20] = 0.215471;
   WeightPUmax[21] = 0.166586;
   WeightPUmax[22] = 0.128399;
   WeightPUmax[23] = 0.0954633;
   WeightPUmax[24] = 0.0709704;
   WeightPUmax[25] = 0.0518837;
   WeightPUmax[26] = 0.0373623;
   WeightPUmax[27] = 0.0268788;
   WeightPUmax[28] = 0.0188572;
   WeightPUmax[29] = 0.0134334;
   WeightPUmax[30] = 0.00911912;
   WeightPUmax[31] = 0.00634949;
   WeightPUmax[32] = 0.0042807;
   WeightPUmax[33] = 0.00288649;
   WeightPUmax[34] = 0.00107161;
}

double LTANA::Hist::getSF(std::vector<std::pair<double,double> > vBin,
			  std::vector<std::pair<double,double> > vSf,
			  double var)
{
   double sf = 1.;
   
   for( int ib=0;ib<vBin.size();ib++ )
     {
	double blow = vBin.at(ib).first;
	double bup = vBin.at(ib).second;
	
	if( var >= blow && var < bup )
	  {
	     sf = vSf.at(ib).first;
	     break;
	  }	
     }   
   
   return sf;
}

double LTANA::Hist::get2DSF(std::vector<std::pair<double,double> > vBinX,
			    std::vector<std::pair<double,double> > vBinY,
			    std::vector<std::pair<double,double> > vSf,
			    double varX,
			    double varY)
{
   double sf = 1.;

   int idx = -1;
   int idy = -1;

   int nbx = vBinX.size();
   int nby = vBinY.size();
   
   for( int ib=0;ib<vBinX.size();ib++ )
     {
	double blow = vBinX.at(ib).first;
	double bup = vBinX.at(ib).second;
	
	if( varX >= blow && varX < bup )
	  {
	     idx = ib;
	     break;
	  }	
     }   

   for( int ib=0;ib<vBinY.size();ib++ )
     {
	double blow = vBinY.at(ib).first;
	double bup = vBinY.at(ib).second;
	
	if( varY >= blow && varY < bup )
	  {
	     idy = ib;
	     break;
	  }	
     }   
   
   int id2D = idx*nby+idy;

   if( idx >= 0 && idy >= 0 )
     sf = vSf.at(id2D).first;
   
   return sf;
}

double LTANA::Hist::get3DSF(std::vector<std::pair<double,double> > vBinX,
			    std::vector<std::pair<double,double> > vBinY,
			    std::vector<std::pair<double,double> > vBinZ,
			    std::vector<std::pair<double,double> > vSf,
			    double varX,
			    double varY,
			    double varZ)
{
   double sf = 1.;

   int idx = -1;
   int idy = -1;
   int idz = -1;

   int nbx = vBinX.size();
   int nby = vBinY.size();
   int nbz = vBinZ.size();
   
   for( int ib=0;ib<vBinX.size();ib++ )
     {
	double blow = vBinX.at(ib).first;
	double bup = vBinX.at(ib).second;
	
	if( varX >= blow && varX < bup )
	  {
	     idx = ib;
	     break;
	  }	
     }   

   for( int ib=0;ib<vBinY.size();ib++ )
     {
	double blow = vBinY.at(ib).first;
	double bup = vBinY.at(ib).second;
	
	if( varY >= blow && varY < bup )
	  {
	     idy = ib;
	     break;
	  }	
     }   

   for( int ib=0;ib<vBinZ.size();ib++ )
     {
	double blow = vBinZ.at(ib).first;
	double bup = vBinZ.at(ib).second;
	
	if( varZ >= blow && varZ < bup )
	  {
	     idz = ib;
	     break;
	  }	
     }   
   
   int id3D = idx*nby*nbz+idy*nbz+idz;

   if( idx >= 0 && idy >= 0 && idz >= 0 )
     sf = vSf.at(id3D).first;
   
//   std::cout << idx+1 << " " << idy+1 << " " << idz+1 << " " << sf << std::endl;
   
   return sf;
}

double LTANA::Hist::DeltaR(double eta1, double phi1, double eta2, double phi2) 
{
   double DeltaPhi = TMath::Abs(phi2 - phi1);
   if (DeltaPhi > 3.141593 ) DeltaPhi -= 2.*3.141593;
   return TMath::Sqrt( (eta2-eta1)*(eta2-eta1) + DeltaPhi*DeltaPhi );
}
