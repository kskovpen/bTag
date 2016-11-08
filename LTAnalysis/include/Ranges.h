#ifndef SYSRANGES
#define SYSRANGES

namespace RANGE
{   
   double set_j_pt[3] = {25,0.,1.0};
//   double set_j_pt[3] = {80,30.,1000.};
   double set_j_BJP[3] = {25,0.,12.};
   double set_j_CSVIVF[3] = {30,0.,1.};
   double set_j_ntrk[3] = {60,0.,60.};
   double set_j_eta[3] = {30,-2.4,2.4};
   double set_j_phi[3] = {30,-3.2,3.2};
   double set_j_mass[3] = {30,0.,100.};
   double set_j_mueta[3] = {30,-5.,5.};
   double set_j_muphi[3] = {30,-3.2,3.2};
   double set_j_muptrel[3] = {50,0.,4.};
   double set_j_svntrk[3] = {25,0.,25.};
   double set_j_svmass[3] = {30,0.,100.};
   double set_j_njet[3] = {12,0.,12.};
   double set_j_nmuon[3] = {5,0.,5.};
   double set_j_nsv[3] = {5,0.,5.};
   double set_j_nsvj[3] = {5,0.,5.};
   double set_j_nseltrk[3] = {60,0.,60.};
   
   double set_pthat[3] = {80,30.,1000.};
   double set_npv[3] = {50,0.,50.};
   double set_j_ntrkgen[3] = {31,-1.,30.};
   double set_j_draway[3] = {30,0.,5.};
   double set_j_csvaway[3] = {30,0.,1.};
   double set_j_tchpaway[3] = {30,-5.,10.};
   double set_j_jpaway[3] = {30,0.,1.6};
   double set_j_ptaway[3] = {25,0.,1.0};
   double set_j_etaaway[3] = {25,-3.0,3.0};
   double set_j_hasmuon[3] = {2,-0.5,1.5};

   double set_j_JP_nosel[17][3] = {
      {25,0.,2.5}, // nosel	 
      {30,0.,1.3}, // pt20t30
      {30,0.,1.5}, // pt30t40
      {30,0.,1.6}, // pt40t50
      {30,0.,1.6}, // pt50t60
      {30,0.,1.7}, // pt60t70
      {30,0.,1.8}, // pt70t80
      {30,0.,2.0}, // pt80t100
      {30,0.,2.0}, // pt100t120
      {30,0.,2.0}, // pt120t160
      {30,0.,2.0}, // pt160t210
      {30,0.,2.0}, // pt210t260
      {30,0.,2.0}, // pt260t320
      {30,0.,2.0}, // pt320t400
      {30,0.,2.0}, // pt400t500
      {30,0.,2.0}, // pt500t670
      {30,0.,2.0}  // pt670t1000
   };

   double set_j_JP_CSVL[17][3] = {
      {25,0.,2.5}, // nosel	 
      {30,0.,1.4}, // pt20t30
      {30,0.,1.6}, // pt30t40
      {30,0.,1.8}, // pt40t50
      {30,0.,1.9}, // pt50t60
      {30,0.,2.0}, // pt60t70
      {30,0.,2.0}, // pt70t80
      {30,0.,2.1}, // pt80t100
      {30,0.,2.2}, // pt100t120
      {30,0.,2.3}, // pt120t160
      {30,0.,2.3}, // pt160t210
      {30,0.,2.3}, // pt210t260
      {30,0.,2.3}, // pt260t320
      {30,0.,2.3}, // pt320t400
      {30,0.,2.3}, // pt400t500
      {30,0.,2.3}, // pt500t670
      {30,0.,2.3}  // pt670t1000
   };

   double set_j_JP_CSVM[17][3] = {
      {25,0.,2.5}, // nosel	 
      {30,0.,1.6}, // pt20t30
      {30,0.,1.7}, // pt30t40
      {30,0.,1.8}, // pt40t50
      {30,0.,2.0}, // pt50t60
      {30,0.,2.1}, // pt60t70
      {30,0.,2.2}, // pt70t80
      {30,0.,2.3}, // pt80t100
      {30,0.,2.3}, // pt100t120
      {30,0.,2.4}, // pt120t160
      {30,0.,2.4}, // pt160t210
      {30,0.,2.5}, // pt210t260
      {30,0.,2.5}, // pt260t320
      {30,0.,2.5}, // pt320t400
      {30,0.,2.5}, // pt400t500
      {30,0.,2.5}, // pt500t670
      {30,0.,2.5}  // pt670t1000
   };

   double set_j_JP_CSVT[17][3] = {
      {25,0.,2.5}, // nosel	 
      {30,0.,1.7}, // pt20t30
      {30,0.,1.9}, // pt30t40
      {30,0.,2.0}, // pt40t50
      {30,0.,2.1}, // pt50t60
      {30,0.,2.2}, // pt60t70
      {30,0.,2.3}, // pt70t80
      {30,0.,2.4}, // pt80t100
      {30,0.,2.5}, // pt100t120
      {30,0.,2.5}, // pt120t160
      {30,0.,2.6}, // pt160t210
      {30,0.,2.7}, // pt210t260
      {30,0.,2.7}, // pt260t320
      {30,0.,2.7}, // pt320t400
      {30,0.,2.7}, // pt400t500
      {30,0.,2.7}, // pt500t670
      {30,0.,2.5}  // pt670t1000
   };

   double set_j_JP_TCHPT[17][3] = {
      {25,0.,2.5}, // nosel	 
      {30,0.,1.8}, // pt20t30
      {30,0.,2.0}, // pt30t40
      {30,0.,2.1}, // pt40t50
      {30,0.,2.2}, // pt50t60
      {30,0.,2.3}, // pt60t70
      {30,0.,2.3}, // pt70t80
      {30,0.,2.4}, // pt80t100
      {30,0.,2.5}, // pt100t120
      {30,0.,2.6}, // pt120t160
      {30,0.,2.6}, // pt160t210
      {30,0.,2.6}, // pt210t260
      {30,0.,2.6}, // pt260t320
      {30,0.,2.6}, // pt320t400
      {30,0.,2.6}, // pt400t500
      {30,0.,2.6}, // pt500t670
      {30,0.,2.5}  // pt670t1000
   };

   double set_j_JP_COMMON[10][3] = {
      {25,0.,2.5}, // nosel
      {25,0.,1.7}, // pt20t30
      {35,0.,1.9}, // pt30t50
      {35,0.,2.1}, // pt50t70
      {35,0.,2.2}, // pt70t100
      {35,0.,2.3}, // pt100t140
      {30,0.,2.4}, // pt140t200
      {30,0.,2.5}, // pt200t300
      {25,0.,2.6}, // pt300t670
      {25,0.,2.7} // pt670t1000
   };

/*   double set_j_JP_COMMON[10][3] = {
      {20,0.5,2.5}, // nosel
      {20,0.5,1.7}, // pt20t30
      {30,0.5,1.9}, // pt30t50
      {30,0.5,2.1}, // pt50t70
      {30,0.5,2.2}, // pt70t100
      {30,0.5,2.3}, // pt100t140
      {25,0.5,2.4}, // pt140t200
      {25,0.5,2.5}, // pt200t300
      {20,0.5,2.6}, // pt300t670
      {20,0.5,2.7} // pt670t1000
   };*/
   
   // CSVM
/*   double set_j_JP_COMMON[10][3] = {
      {25,0.,2.5}, // nosel
      {12,0.,1.7}, // pt20t30
      {12,0.,1.9}, // pt30t50
      {12,0.,2.0}, // pt50t70
      {12,0.,2.1}, // pt70t100
      {12,0.,2.2}, // pt100t140
      {12,0.,2.3}, // pt140t250
      {12,0.,2.4}, // pt250t450
      {12,0.,2.4}, // pt450t670
      {12,0.,2.4} // pt670t1000
   };*/

   // CSVT
/*   double set_j_JP_COMMON[10][3] = {
      {25,0.,2.5}, // nosel
      {12,0.,1.7}, // pt20t30
      {12,0.,1.9}, // pt30t50
      {12,0.,2.0}, // pt50t70
      {12,0.,2.1}, // pt70t100
      {12,0.,2.2}, // pt100t140
      {12,0.,2.3}, // pt140t250
      {12,0.,2.4}, // pt250t450
      {12,0.,2.4}, // pt450t670
      {12,0.,2.4} // pt670t1000
   };*/
   
/*   double set_j_JP_COMMON[17][3] = {
      {25,0.,2.5}, // nosel
      {25,0.,1.7}, // pt20t30
      {25,0.,1.9}, // pt30t40
      {25,0.,2.0}, // pt40t50
      {25,0.,2.1}, // pt50t60
      {25,0.,2.2}, // pt60t70
      {25,0.,2.3}, // pt70t80
      {25,0.,2.4}, // pt80t100
      {25,0.,2.5}, // pt100t120
      {25,0.,2.5}, // pt120t160
      {25,0.,2.6}, // pt160t210
      {25,0.,2.7}, // pt210t260
      {25,0.,2.7}, // pt260t320
      {25,0.,2.7}, // pt320t400
      {25,0.,2.7}, // pt400t500
      {25,0.,2.7}, // pt500t670
      {25,0.,2.5}  // pt670t1000
   };*/

   double set_j_mupt[17][3] = {
      {30,0.,110.}, // nosel	 
      {30,0.,25.}, // pt20t30
      {30,0.,25.}, // pt30t40
      {30,0.,30.}, // pt40t50
      {30,0.,30.}, // pt50t60
      {30,0.,35.}, // pt60t70
      {30,0.,40.}, // pt70t80
      {30,0.,45.}, // pt80t100
      {30,0.,50.}, // pt100t120
      {30,0.,55.}, // pt120t160
      {30,0.,70.}, // pt160t210
      {30,0.,90.}, // pt210t260
      {30,0.,100.}, // pt260t320
      {30,0.,110.}, // pt320t400
      {30,0.,110.}, // pt400t500
      {30,0.,110.}, // pt500t670
      {30,0.,110.}  // pt670t1000
   };
   
   double set_j_2d_JP_vs_pt[6] = {
      25,0.,1.0,
      25,0.,2.5
   };
   
   double set_j_2d_JP_vs_mupt[6] = {
      50,0.,100.,
      25,0.,2.5
   };
   
   double set_j_2d_JP_vs_nseltrk[6] = {
      60,0.,60.,
      25,0.,2.5
   };

   double set_j_2d_JP_vs_njet[6] = {
      12,0.,12.,
      25,0.,2.5
   };
   
   double set_j_2d_JP_vs_jeta[6] = {
      25,-3.,3.,
      25,0.,2.5
   };

   double set_j_2d_JP_vs_nsv[6] = {
      5,0.,5.,
      25,0.,2.5
   };

   double set_j_2d_JP_vs_CSV[6] = {
      25,-0.1,1.1,
      25,0.,2.5
   };

   double set_j_2d_JP_vs_CMVA[6] = {
//      25,-0.1,1.1,
      25,-1.1,1.1,
      25,0.,2.5
   };
   
   double set_j_2d_BJP_vs_CSV[6] = {
      25,-1.3,1.3,
      25,0.,12.
   };
   
   double set_j_2d_nseltrk_vs_njet[6] = {
      12,0.,12.,
      60,0.,60.
   };
   double set_j_2d_nseltrk_vs_ntrkgen[6] = {
      21,-1.,20.,
      60,0.,60.
   };

   double set_j_2d_nseltrk_vs_mupt[6] = {
      50,0.,100.,
      50,0.,60.
   };

   double set_j_2d_nseltrk_vs_jeta[6] = {
      25,-3.,3.,
      50,0.,60.
   };

   double set_j_2d_njet_vs_mupt[6] = {
      50,0.,100.,
      12,0.,12.
   };

   double set_j_2d_njet_vs_jeta[6] = {
      25,-3.,3.,
      12,0.,12.
   };

   double set_j_2d_mupt_vs_jeta[6] = {
      25,-3.,3.,
      50,0.,100.
   };

   double set_j_2d_nseltrk_vs_nsv[6] = {
      5,0.,5.,
      50,0.,60.
   };

   double set_j_2d_njet_vs_nsv[6] = {
      5,0.,5.,
      12,0.,12.
   };

   double set_j_2d_mupt_vs_nsv[6] = {
      5,0.,5.,
      50,0.,100.
   };

   double set_j_2d_jeta_vs_nsv[6] = {
      5,0.,5.,
      25,-3.,3.
   };

   double set_j_2d_pt_vs_nseltrk[6] = {
      50,0.,60.,
      25,0.,1.
   };
   
   double set_j_2d_pt_vs_njet[6] = {
      12,0.,12.,
      25,0.,1.
   };
   
   double set_j_2d_pt_vs_mupt[6] = {
      50,0.,100.,
      25,0.,1.
   };

   double set_j_2d_pt_vs_jeta[10][6] = {
      {15,-2.4,2.4,7,0.,1.}, // nosel
      {3,-2.4,2.4,3,0.,1.}, // pt20t30
      {15,-2.4,2.4,7,0.,1.}, // pt30t50
      {20,-2.4,2.4,10,0.,1.}, // pt50t70
      {25,-2.4,2.4,15,0.,1.}, // pt70t100
      {17,-2.4,2.4,10,0.,1.}, // pt100t140
      {17,-2.4,2.4,10,0.,1.}, // pt140t200
      {13,-2.4,2.4,6,0.,1.}, // pt200t300
      {8,-2.4,2.4,6,0.,1.}, // pt300t670
      {10,-2.4,2.4,5,0.,1.}  // pt670t1000
   };

   double set_j_2d_pt_vs_nsv[6] = {
      5,0.,5.,
      25,0.,1.
   };
   
   // z y x
   double set_j_3d_ntrk_vs_pt_vs_mupt[9] = {
      30,0.,30.,
      25,0.,1.,
      25,0.,25.
   };
}

#endif
