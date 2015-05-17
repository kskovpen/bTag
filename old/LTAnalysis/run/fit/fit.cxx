#include "func.h"

int main(int argc, char *argv[])
{
   if( argc > 2 )
     {
	sysNameGL = argv[1];
	sysIdx = atoi(argv[2]);
     }
   else
     {
	std::cout << "Please specify systematics name" << std::endl;
	exit(1);
     }   

   // modify systematics array according to input parameters
   std::string nameSysLow = "";
   std::string nameSysUp = "";
   if( strcmp(sysNameGL.c_str(),"ALL") == 0 ) 
     {
	nsysGL = nsys;
     }
   else if( strcmp(sysNameGL.c_str(),"NONE") == 0 )
     {
	nsysGL = 1;
	nameSysLow = "";
	nameSysUp = "";
     }	
   else if( strcmp(sysNameGL.c_str(),"NTRK") == 0 )
     {
	nsysGL = 1;
	nameSysLow = "_ntrk_low";
	nameSysUp = "_ntrk_up";
     }	
   else if( strcmp(sysNameGL.c_str(),"JESup") == 0 )
     {
	nsysGL = 1;
	nameSysLow = "";
	nameSysUp = "_jes_up";
     }	
   else if( strcmp(sysNameGL.c_str(),"JESdown") == 0 )
     {
	nsysGL = 1;
	nameSysLow = "_jes_low";
	nameSysUp = "";
     }	
   else if( strcmp(sysNameGL.c_str(),"JER") == 0 )
     {
	nsysGL = 1;
	nameSysLow = "_jer_low";
	nameSysUp = "_jer_up";
     }	
   else if( strcmp(sysNameGL.c_str(),"JERup") == 0 )
     {
	nsysGL = 1;
	nameSysLow = "";
	nameSysUp = "_jer_up";
     }	
   else if( strcmp(sysNameGL.c_str(),"JERdown") == 0 )
     {
	nsysGL = 1;
	nameSysLow = "_jer_low";
	nameSysUp = "";
     }	
   else if( strcmp(sysNameGL.c_str(),"JETDIR") == 0 )
     {
	nsysGL = 1;
	nameSysLow = "_smearDir_low";
	nameSysUp = "_smearDir_up";
     }	
   else if( strcmp(sysNameGL.c_str(),"JETDIRup") == 0 )
     {
	nsysGL = 1;
	nameSysLow = "";
	nameSysUp = "_smearDir_up";
     }	
   else if( strcmp(sysNameGL.c_str(),"JETDIRdown") == 0 )
     {
	nsysGL = 1;
	nameSysLow = "_smearDir_low";
	nameSysUp = "";
     }	
   else if( strcmp(sysNameGL.c_str(),"SMCALL") == 0 )
     {
	nsysGL = 1;
	nameSysLow = "_smcALL_low";
	nameSysUp = "_smcALL_up";
     }	
   else if( strcmp(sysNameGL.c_str(),"SMCALLup") == 0 )
     {
	nsysGL = 1;
	nameSysLow = "";
	nameSysUp = "_smcALL_up";
     }	
   else if( strcmp(sysNameGL.c_str(),"SMCALLdown") == 0 )
     {
	nsysGL = 1;
	nameSysLow = "_smcALL_low";
	nameSysUp = "";
     }	
   else
     {
	std::cout << "Please specify correct systematics name" << std::endl;
	exit(1);
     }	

   std::cout << "Run with " << sysNameGL << " systematics" << std::endl;
   
//   gROOT->ProcessLine(".L atlasstyle-00-03-04/AtlasStyle.C");
//   gROOT->ProcessLine(".L atlasstyle-00-03-04/AtlasUtils.C");
//   gROOT->ProcessLine(".L atlasstyle-00-03-04/AtlasLabels.C");
   
   SetAtlasStyle();

   def();
   init();

//   if( strcmp(sysNameGL.c_str(),"ALL") != 0 )
//     {
//	name_sys_low[0] = nameSysLow;
//	name_sys_up[0] = nameSysUp;
//     }
   
   // suppress verbose from Print
   gErrorIgnoreLevel = 5000;
   
   std::cout.precision(10);

   c1 = new TCanvas("c1","c1",0,0,600,500);
   
   gStyle->SetHistTopMargin(0);

   TH1::AddDirectory(kFALSE);
   TH2::AddDirectory(kFALSE);
   
   std::string foutStr = "results/eff"+sysNameGL+".txt";
   fout.open(foutStr.c_str());

   std::string foutSysStr = "results/sysCorr.txt";
   foutSys.open(foutSysStr.c_str());
   
   openData(0,
	    0,
	    v_mc_filt,
	    v_mc_unfilt,
	    v_data);
   
   check.open("check.txt");
   
   for(int iBTAG=0;iBTAG<hnnBTAG;iBTAG++)
     {   
	for(int iETA=0;iETA<hnnETA;iETA++)
	  {
	     std::string fsysName = "results/sys"+hnameBTAG[iBTAG]+"_"+sysNameGL+".txt";
	     std::ofstream fsys(fsysName.c_str());
	     
	     for(int iPT=0;iPT<hnnPT;iPT++)
	       {
		  std::cout << "Working on BTAG=" << hnameBTAG[iBTAG] << 
		    ", PT=" << hnamePT[iPT] << 
		    ", ETA=" << hnameETA[iETA] << std::endl;

		  covFCUR = covF[iPT];
		  
		  std::vector<std::pair<TH1D*,std::string> > v_draw_bjet_2dfit;
		  std::vector<std::pair<TH1D*,std::string> > v_draw_cjet_2dfit;
		  std::vector<std::pair<TH1D*,std::string> > v_draw_ljet_2dfit;
		  std::vector<std::pair<TH1D*,std::string> > v_draw_cljet_2dfit;
		  std::vector<std::pair<TH1D*,std::string> > v_draw_ajet_data_2dfit;	     
		  
		  std::vector<std::pair<TH1D*,std::string> > v_draw_bcljet_comb_2dfit;
		  std::vector<std::pair<TH1D*,std::string> > v_draw_bcljet_sys_up_combSum_2dfit;
		  std::vector<std::pair<TH1D*,std::string> > v_draw_bcljet_sys_low_combSum_2dfit;
		  
		  v_draw_bjet_2dfit.clear();
		  v_draw_cjet_2dfit.clear();
		  v_draw_ljet_2dfit.clear();
		  v_draw_cljet_2dfit.clear();
		  v_draw_ajet_data_2dfit.clear();
		  
		  v_draw_bcljet_comb_2dfit.clear();
		  v_draw_bcljet_sys_up_combSum_2dfit.clear();
		  v_draw_bcljet_sys_low_combSum_2dfit.clear();
		  
		  double p1FIT = 1.;
		  double p1FITerr = 0.;
		  double p2FIT = 1.;
		  double p2FITerr = 0.;
		  double p3FIT = 1.;
		  double p3FITerr = 0.;

		  for(int iVAR=0;iVAR<hnnVAR;iVAR++)
		    {
		       // FIXME
		       if( iVAR == 0 ) continue;
			 
		       c1->Clear();

		       comflag = false;
		       if( iVAR == 1 && iBTAG == 1 && iETA == 0 && iPT == 11 )
			 comflag = true;
		       
//		       h_draw_bjet[iVAR] = new TH1D();
//		       h_draw_bjet_posttag[iVAR] = new TH1D();
//		       h_draw_cjet[iVAR] = new TH1D();
//		       h_draw_ljet[iVAR] = new TH1D();
//		       h_draw_cljet[iVAR] = new TH1D();
		       
//		       h_draw_ajet_data[iVAR] = new TH1D();

		       std::string hname_bjet = "";
		       std::string hname_cjet = "";

		       std::string hname_bjet_true = "";
		       std::string hname_cjet_true = "";
		       std::string hname_ljet_true = "";
		       
		       std::string ljet_data_name = hnameVAR[iVAR];
		       if( ljet_data_name == "h_j1_muonTightPtRelSV_" ) ljet_data_name = "h_j1_muonTightPtRel_";
		       if( ljet_data_name == "h_j1_d0SignJet1SV_" ) ljet_data_name = "h_j1_d0SignJet1_";

		       std::string bjet_untag_name = hnameVAR[iVAR];
		       if( bjet_untag_name == "h_j1_muonTightPtRelSV_" ) bjet_untag_name = "h_j1_muonTightPtRel_";
		       if( bjet_untag_name == "h_j1_d0SignJet1SV_" ) bjet_untag_name = "h_j1_d0SignJet1_";

		       std::string cjet_untag_name = hnameVAR[iVAR];
		       if( cjet_untag_name == "h_j1_muonTightPtRelSV_" ) cjet_untag_name = "h_j1_muonTightPtRel_";
		       if( cjet_untag_name == "h_j1_d0SignJet1SV_" ) cjet_untag_name = "h_j1_d0SignJet1_";

		       std::string bjet_name = hnameVAR[iVAR];
//		       if( bjet_name == "h_j1_muonTightPtRelSV_" ) bjet_name = "h_j1_muonTightPtRel_";
//		       if( bjet_name == "h_j1_d0SignJet1SV_" ) bjet_name = "h_j1_d0SignJet1_";

		       std::string cjet_name = hnameVAR[iVAR];
//		       if( cjet_name == "h_j1_muonTightPtRelSV_" ) cjet_name = "h_j1_muonTightPtRel_";
//		       if( cjet_name == "h_j1_d0SignJet1SV_" ) cjet_name = "h_j1_d0SignJet1_";

		       if( usePRETAGb )
			 {			    
			    hname_bjet = bjet_name + "bjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + "_nosel";
			    hname_bjet_true = bjet_name + "bjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + "_nosel_true_up";
			 }		       
		       else
			 {			    
			    hname_bjet = bjet_name + "bjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];
			    hname_bjet_true = bjet_name + "bjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG]+"_true_up";
			 }		       

		       if( usePRETAGc )
			 {			    
			    hname_cjet = cjet_name + "cjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + "_nosel";
			    hname_cjet_true = cjet_name + "cjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + "_nosel_true_up";
			 }		       
		       else
			 {			    
			    hname_cjet = cjet_name + "cjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];
			    hname_cjet_true = cjet_name + "cjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG]+"_true_up";
			 }		       
		       
		       hname_ljet_true = hnameVAR[iVAR] + "ljet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG]+"_true_up";
		       std::string hname_ljet = hnameVAR[iVAR] + "ljet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];
		       std::string hname_ljet_data = ljet_data_name + "ajet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + "_" + untag;
		       std::string hname_bjet_untag = bjet_untag_name + "bjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + "_" + untag;
		       std::string hname_cjet_untag = cjet_untag_name + "cjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + "_" + untag;
//		       std::string hname_bjet_notag = hnameVAR[iVAR] + "bjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + "_nosel";
//		       std::string hname_cjet_notag = hnameVAR[iVAR] + "cjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + "_nosel";
		       std::string hname_bjet_posttag = hnameVAR[iVAR] + "bjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[1];
		       std::string hname_cjet_posttag = hnameVAR[iVAR] + "cjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[1];
		       std::string hname_ljet_posttag = hnameVAR[iVAR] + "ljet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[1];
		       std::string hname_ajet_data_posttag = hnameVAR[iVAR] + "ajet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[1];
		       std::string hname = hnameVAR[iVAR] + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];

		       std::string notag_name = "_UNTAGbc";
		       std::string hname_bjet_notag = hnameVAR[iVAR] + "bjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + notag_name;
		       std::string hname_cjet_notag = hnameVAR[iVAR] + "cjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + notag_name;
		       std::string hname_ljet_notag = hnameVAR[iVAR] + "ljet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + notag_name;
		       std::string hname_ajet_data_notag = hnameVAR[iVAR] + "ajet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + notag_name;
		       
		       std::string hname_ajet = hnameVAR[iVAR] + "ajet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];

		       hname_bjet_nominal = hname_bjet;
		       hname_cjet_nominal = hname_cjet;
		       hname_ljet_nominal = hname_ljet;

		       hname_bjet_nominalInit = hname_bjet;
		       hname_cjet_nominalInit = hname_cjet;
		       hname_ljet_nominalInit = hname_ljet;

		       hname_bjet_nominalTrue = hname_bjet_true;
		       hname_cjet_nominalTrue = hname_cjet_true;
		       hname_ljet_nominalTrue = hname_ljet_true;
		       
		       hname_bjet_sysUp = hname_bjet;
		       hname_cjet_sysUp = hname_cjet;
		       hname_ljet_sysUp = hname_ljet;

		       hname_bjet_sysDown = hname_bjet;
		       hname_cjet_sysDown = hname_cjet;
		       hname_ljet_sysDown = hname_ljet;
		       
		       // systematics for SF
		       if( sysIdx < 666 )
			 {			    
			    if( sysIdx > 0 )
			      {
				 hname_bjet_nominal += name_sys_up[sysIdx];
				 hname_cjet_nominal += name_sys_up[sysIdx];
				 hname_ljet_nominal += name_sys_up[sysIdx];

				 hname_bjet_sysUp += name_sys_up[sysIdx];
				 hname_cjet_sysUp += name_sys_up[sysIdx];
				 hname_ljet_sysUp += name_sys_up[sysIdx];
			      }		       		       
			    if( sysIdx < 0 )
			      {
				 int sysIdxPos = -sysIdx;
				 hname_bjet_nominal += name_sys_low[sysIdxPos];
				 hname_cjet_nominal += name_sys_low[sysIdxPos];
				 hname_ljet_nominal += name_sys_low[sysIdxPos];

				 hname_bjet_sysDown += name_sys_low[sysIdxPos];
				 hname_cjet_sysDown += name_sys_low[sysIdxPos];
				 hname_ljet_sysDown += name_sys_low[sysIdxPos];
			      }
			 }
		       
		       iVARcur = iVAR;
		       iPTcur = iPT;
		       iBTAGcur = iBTAG;
		       hname_bjet_cur = hname_bjet;
		       hname_cjet_cur = hname_cjet;
		       hname_ljet_cur = hname_ljet;
		       hname_ajet_cur = hname_ajet;
		       hname_ljet_data_cur = hname_ljet_data;
		       
		       std::vector<std::string> vstr = setTit(hnameVAR[iVAR]);
		       std::string xAxisTit = vstr.at(0);
		       std::string yAxisTit = vstr.at(1);
		       
//		       openData(iVAR,
//				iPT,
//				v_mc_filt,
//				v_mc_unfilt,
//				v_data);
		       
		       readData(iVAR,
				iPT,
				hname_bjet,
				hname_cjet,
				hname_ljet,
				hname_ajet,
				hname_ljet_data,
				hname_bjet_untag,
				hname_cjet_untag,
//				hname_bjet_notag,
//				hname_cjet_notag,
				hname_bjet_posttag,
				hname_cjet_posttag,
				hname_ljet_posttag,
				hname_ajet_data_posttag,
				hname_bjet_notag,
				hname_cjet_notag,
				hname_ljet_notag,
				hname_ajet_data_notag,
				v_mc_filt,
				v_mc_unfilt,
				v_data);

		       // symmetrise sys variation (choose max)
		       if( doSystSymm )
			 {			    
			    if( sysIdx != 0 && sysIdx < 666 )
			      {			    
				 TH1D *h_nom = (TH1D*)h_draw_bjet_init[iVAR]->Clone("h_nom");
				 TH1D *h_sysUp = (TH1D*)h_draw_bjet_sysUp[iVAR]->Clone("h_sysUp");
				 TH1D *h_sysDown = (TH1D*)h_draw_bjet_sysDown[iVAR]->Clone("h_sysDown");
				 std::string sysname = "";
				 if( sysIdx < 0 ) sysname = name_sys_low[-sysIdx];
				 else sysname = name_sys_up[sysIdx];
				 double intn = h_nom->Integral(1,h_nom->GetXaxis()->GetNbins());
				 double intu = h_sysUp->Integral(1,h_sysUp->GetXaxis()->GetNbins());
				 double intd = h_sysDown->Integral(1,h_sysDown->GetXaxis()->GetNbins());
				 if( intn > 0 ) h_nom->Scale(1./intn);
				 
/*				 if( 
				    sysname == "_ntrk_low" || sysname == "_ntrk_up" ||
				    sysname == "_val_low" || sysname == "_val_up" ||
				    sysname == "_njet_low" || sysname == "_njet_up" ||
				    sysname == "_mupt_low" || sysname == "_mupt_up" ||
				    sysname == "_jeta_low" || sysname == "_jeta_up" ||
				    sysname == "_pt_low" || sysname == "_pt_up"
				   )
				   {
				      if( intn > 0 ) h_sysUp->Scale(1./intn);
				      if( intn > 0 ) h_sysDown->Scale(1./intn);
				   }			    
				 else
				   {*/
				      if( intu > 0 ) h_sysUp->Scale(1./intu);
				      if( intd > 0 ) h_sysDown->Scale(1./intd);
//				   }			    
				 
				 int nb = h_nom->GetXaxis()->GetNbins();
				 for(int iu=1;iu<=nb;iu++)
				   {
				      double v = h_nom->GetBinContent(iu);
				      double v_i = h_draw_bjet_init[iVAR]->GetBinContent(iu);
				      double up = h_sysUp->GetBinContent(iu) - v;
				      double down = v - h_sysDown->GetBinContent(iu);
				      double max = (fabs(up) > fabs(down)) ? up : down;
				      double rel = (v > 0) ? max/v : 0.;
				      double v_c_new = (sysIdx > 0) ? v_i*(1+rel) : v_i*(1-rel);
				      h_draw_bjet[iVAR]->SetBinContent(iu,v_c_new);
				   }			    
				 
				 delete h_sysUp;
				 delete h_sysDown;
				 delete h_nom;
			      }		       

			    if( sysIdx != 0 && sysIdx < 666 )
			      {			    
				 TH1D *h_nom = (TH1D*)h_draw_cjet_init[iVAR]->Clone("h_nom");
				 TH1D *h_sysUp = (TH1D*)h_draw_cjet_sysUp[iVAR]->Clone("h_sysUp");
				 TH1D *h_sysDown = (TH1D*)h_draw_cjet_sysDown[iVAR]->Clone("h_sysDown");
				 std::string sysname = "";
				 if( sysIdx < 0 ) sysname = name_sys_low[-sysIdx];
				 else sysname = name_sys_up[sysIdx];
				 double intn = h_nom->Integral(1,h_nom->GetXaxis()->GetNbins());
				 double intu = h_sysUp->Integral(1,h_sysUp->GetXaxis()->GetNbins());
				 double intd = h_sysDown->Integral(1,h_sysDown->GetXaxis()->GetNbins());
				 if( intn > 0 ) h_nom->Scale(1./intn);
				 
/*				 if( 
				    sysname == "_ntrk_low" || sysname == "_ntrk_up" ||
				    sysname == "_val_low" || sysname == "_val_up" ||
				    sysname == "_njet_low" || sysname == "_njet_up" ||
				    sysname == "_mupt_low" || sysname == "_mupt_up" ||
				    sysname == "_jeta_low" || sysname == "_jeta_up" ||
				    sysname == "_pt_low" || sysname == "_pt_up"
				   )
				   {
				      if( intn > 0 ) h_sysUp->Scale(1./intn);
				      if( intn > 0 ) h_sysDown->Scale(1./intn);
				   }			    
				 else
				   {*/
				      if( intu > 0 ) h_sysUp->Scale(1./intu);
				      if( intd > 0 ) h_sysDown->Scale(1./intd);
//				   }			    
				 
				 int nb = h_nom->GetXaxis()->GetNbins();
				 for(int iu=1;iu<=nb;iu++)
				   {
				      double v = h_nom->GetBinContent(iu);
				      double v_i = h_draw_cjet_init[iVAR]->GetBinContent(iu);
				      double up = h_sysUp->GetBinContent(iu) - v;
				      double down = v - h_sysDown->GetBinContent(iu);
				      double max = (fabs(up) > fabs(down)) ? up : down;
				      double rel = (v > 0) ? max/v : 0.;
				      double v_c_new = (sysIdx > 0) ? v_i*(1+rel) : v_i*(1-rel);
				      h_draw_cjet[iVAR]->SetBinContent(iu,v_c_new);
				   }			    
				 
				 delete h_sysUp;
				 delete h_sysDown;
				 delete h_nom;
			      }		       

			    if( sysIdx != 0 && sysIdx < 666 )
			      {			    
				 TH1D *h_nom = (TH1D*)h_draw_ljet_init[iVAR]->Clone("h_nom");
				 TH1D *h_sysUp = (TH1D*)h_draw_ljet_sysUp[iVAR]->Clone("h_sysUp");
				 TH1D *h_sysDown = (TH1D*)h_draw_ljet_sysDown[iVAR]->Clone("h_sysDown");
				 std::string sysname = "";
				 if( sysIdx < 0 ) sysname = name_sys_low[-sysIdx];
				 else sysname = name_sys_up[sysIdx];
				 double intn = h_nom->Integral(1,h_nom->GetXaxis()->GetNbins());
				 double intu = h_sysUp->Integral(1,h_sysUp->GetXaxis()->GetNbins());
				 double intd = h_sysDown->Integral(1,h_sysDown->GetXaxis()->GetNbins());
				 if( intn > 0 ) h_nom->Scale(1./intn);
				 
/*				 if( 
				    sysname == "_ntrk_low" || sysname == "_ntrk_up" ||
				    sysname == "_val_low" || sysname == "_val_up" ||
				    sysname == "_njet_low" || sysname == "_njet_up" ||
				    sysname == "_mupt_low" || sysname == "_mupt_up" ||
				    sysname == "_jeta_low" || sysname == "_jeta_up" ||
				    sysname == "_pt_low" || sysname == "_pt_up"
				   )
				   {
				      if( intn > 0 ) h_sysUp->Scale(1./intn);
				      if( intn > 0 ) h_sysDown->Scale(1./intn);
				   }			    
				 else
				   {*/
				      if( intu > 0 ) h_sysUp->Scale(1./intu);
				      if( intd > 0 ) h_sysDown->Scale(1./intd);
//				   }			    
				 
				 int nb = h_nom->GetXaxis()->GetNbins();
				 for(int iu=1;iu<=nb;iu++)
				   {
				      double v = h_nom->GetBinContent(iu);
				      double v_i = h_draw_ljet_init[iVAR]->GetBinContent(iu);
				      double up = h_sysUp->GetBinContent(iu) - v;
				      double down = v - h_sysDown->GetBinContent(iu);
				      double max = (fabs(up) > fabs(down)) ? up : down;
				      double rel = (v > 0) ? max/v : 0.;
				      double v_c_new = (sysIdx > 0) ? v_i*(1+rel) : v_i*(1-rel);
				      h_draw_ljet[iVAR]->SetBinContent(iu,v_c_new);
				   }			    
			    
				 delete h_sysUp;
				 delete h_sysDown;
				 delete h_nom;
			      }		       
			 }		       
		       
//		       if( h_draw_bjet[iVAR]->GetXaxis()->GetNbins()+1 < ibinMax )
//			 ibinMax = h_draw_bjet[iVAR]->GetXaxis()->GetNbins()+1;
		       
/*		       if( iVAR == 1 && iPTcur > 0 )
			 {	     
			    for(int b=0;b<=h_draw_bjet[iVAR]->GetXaxis()->GetNbins()+1;b++)
			      {
				 double vnom = h_draw_bjet[iVAR]->GetBinContent(b);
				 double vlow = h_draw_bjet_sys_low[1][iVAR]->GetBinContent(b);
				 if( vnom < vlow ) 
				   {
				      std::cout << "Nominal histogram is less than low sys" << std::endl;
				      std::cout << h_draw_bjet[iVAR]->GetName() << std::endl;
				      std::cout << h_draw_bjet_sys_low[1][iVAR]->GetName() << std::endl;
				      std::cout << "b=" << b << " nom=" << vnom << " low=" << vlow << std::endl;
				      exit(1);
				   }		       
			      }
			 }*/
		       
//		       closeData(iVAR,
//				 iPT,
//				 v_mc_filt,
//				 v_mc_unfilt,
//				 v_data);
		       
		       TH1D *h_ljet;
		       TH1D *h_ljet_noscale;
		       if( ljetData == 0 )
			 {			    
			    h_ljet = h_draw_ljet[iVAR];
			    h_ljet_noscale = (TH1D*)h_draw_ljet[iVAR]->Clone("h_ljet_noscale");
			 }		       
		       else
			 {			    
			    h_ljet = h_draw_ljet_data[iVAR];
			    h_ljet_noscale = (TH1D*)h_draw_ljet_data[iVAR]->Clone("h_ljet_noscale");
			 }		       
		       
		       h_draw_bjet[iVAR]->SetLineColor(kb);
		       h_draw_cjet[iVAR]->SetLineColor(kc);
		       h_draw_ljet[iVAR]->SetLineColor(kl);
		       h_draw_ljet_data[iVAR]->SetLineColor(kl);
		       h_draw_cljet[iVAR]->SetLineColor(41);
		       h_draw_bjet_untag[iVAR]->SetLineColor(kb);
		       h_draw_cjet_untag[iVAR]->SetLineColor(kc);
		       h_ljet_noscale->SetLineColor(kl);
		       
		       h_draw_bjet[iVAR]->SetMarkerSize(0);
		       h_draw_cjet[iVAR]->SetMarkerSize(0);
		       h_draw_ljet[iVAR]->SetMarkerSize(0);
		       h_draw_ljet_data[iVAR]->SetMarkerSize(0);
		       h_draw_cljet[iVAR]->SetMarkerSize(0);
		       h_draw_bjet_untag[iVAR]->SetMarkerSize(0);
		       h_draw_cjet_untag[iVAR]->SetMarkerSize(0);
		       h_ljet_noscale->SetMarkerSize(0);

		       h_draw_bjet[iVAR]->SetFillColor(kb);
		       h_draw_cjet[iVAR]->SetFillColor(kc);
		       h_ljet->SetFillColor(kl);
		       h_draw_cljet[iVAR]->SetFillColor(41);
		       h_draw_bjet_untag[iVAR]->SetFillColor(kb);
		       h_draw_cjet_untag[iVAR]->SetFillColor(kc);
		       h_ljet_noscale->SetFillColor(kl);

		       TH1D *h_draw_bjet_sys_low_temp[1000];
		       TH1D *h_draw_bjet_sys_up_temp[1000];
		       TH1D *h_draw_cjet_sys_low_temp[1000];
		       TH1D *h_draw_cjet_sys_up_temp[1000];
		       TH1D *h_draw_ljet_sys_low_temp[1000];
		       TH1D *h_draw_ljet_sys_up_temp[1000];
		       TH1D *h_draw_ljet_data_sys_low_temp[1000];
		       TH1D *h_draw_ljet_data_sys_up_temp[1000];
		       
		       TH1D *h_draw_bjet_temp = (TH1D*)h_draw_bjet[iVAR]->Clone("h_draw_bjet_temp");
		       TH1D *h_draw_cjet_temp = (TH1D*)h_draw_cjet[iVAR]->Clone("h_draw_cjet_temp");
		       TH1D *h_draw_ljet_temp = (TH1D*)h_draw_ljet[iVAR]->Clone("h_draw_ljet_temp");
		       TH1D *h_draw_ljet_data_temp = (TH1D*)h_draw_ljet_data[iVAR]->Clone("h_draw_ljet_data_temp");

		       TH1D *h_draw_bjet_sys_low_combSum_temp = (TH1D*)h_draw_bjet_temp->Clone("h_draw_bjet_sys_low_combSum_temp");
		       TH1D *h_draw_cjet_sys_low_combSum_temp = (TH1D*)h_draw_cjet_temp->Clone("h_draw_cjet_sys_low_combSum_temp");
		       TH1D *h_draw_ljet_sys_low_combSum_temp = (TH1D*)h_draw_ljet_temp->Clone("h_draw_ljet_sys_low_combSum_temp");
		       TH1D *h_draw_ljet_data_sys_low_combSum_temp = (TH1D*)h_draw_ljet_data_temp->Clone("h_draw_ljet_data_sys_low_combSum_temp");

		       TH1D *h_draw_bjet_sys_up_combSum_temp = (TH1D*)h_draw_bjet_temp->Clone("h_draw_bjet_sys_up_combSum_temp");
		       TH1D *h_draw_cjet_sys_up_combSum_temp = (TH1D*)h_draw_cjet_temp->Clone("h_draw_cjet_sys_up_combSum_temp");
		       TH1D *h_draw_ljet_sys_up_combSum_temp = (TH1D*)h_draw_ljet_temp->Clone("h_draw_ljet_sys_up_combSum_temp");
		       TH1D *h_draw_ljet_data_sys_up_combSum_temp = (TH1D*)h_draw_ljet_data_temp->Clone("h_draw_ljet_data_sys_up_combSum_temp");
		       
		       float nev_bjet = h_draw_bjet_temp->Integral();
		       float nev_cjet = h_draw_cjet_temp->Integral();
		       float nev_ljet = h_draw_ljet_temp->Integral();
		       float nev_ljet_data = h_draw_ljet_data_temp->Integral();
		       
		       if( nev_bjet > 0. ) h_draw_bjet_temp->Scale(1./nev_bjet);
		       if( nev_cjet > 0. ) h_draw_cjet_temp->Scale(1./nev_cjet);
		       if( nev_ljet > 0. ) h_draw_ljet_temp->Scale(1./nev_ljet);
		       if( nev_ljet_data > 0. ) h_draw_ljet_data_temp->Scale(1./nev_ljet_data);
		       
		       for(int is=0;is<nsysGL;is++)
			 {
			    std::string bjet_low_temp = name_sys_low[is] + "_temp";
			    h_draw_bjet_sys_low_temp[iVAR*nsysGL+is] = (TH1D*)h_draw_bjet_sys_low[is][iVAR]->Clone(bjet_low_temp.c_str());
			    std::string bjet_up_temp = name_sys_up[is] + "_temp";
			    h_draw_bjet_sys_up_temp[iVAR*nsysGL+is] = (TH1D*)h_draw_bjet_sys_up[is][iVAR]->Clone(bjet_up_temp.c_str());

			    float nev_bjet_low = h_draw_bjet_sys_low_temp[iVAR*nsysGL+is]->Integral();
			    float nev_bjet_up = h_draw_bjet_sys_up_temp[iVAR*nsysGL+is]->Integral();
			    if( nev_bjet_low > 0. ) h_draw_bjet_sys_low_temp[iVAR*nsysGL+is]->Scale(1./nev_bjet_low);
			    if( nev_bjet_up > 0. ) h_draw_bjet_sys_up_temp[iVAR*nsysGL+is]->Scale(1./nev_bjet_up);
//			    if( nev_bjet_low > 0. ) h_draw_bjet_sys_low_temp[iVAR*nsysGL+is]->Scale(1./nev_bjet);
//			    if( nev_bjet_up > 0. ) h_draw_bjet_sys_up_temp[iVAR*nsysGL+is]->Scale(1./nev_bjet);

//			    if( doCorrNorm )
//			      {				 
//				 double fb_low = fnorm(h_draw_bjet_temp,h_draw_bjet_sys_low_temp[iVAR*nsysGL+is]);
//				 double fb_up = fnorm(h_draw_bjet_temp,h_draw_bjet_sys_up_temp[iVAR*nsysGL+is]);
//			      }
			    			    
			    totSys(h_draw_bjet_temp,
				   h_draw_bjet_sys_low_temp[iVAR*nsysGL+is],
				   h_draw_bjet_sys_up_temp[iVAR*nsysGL+is]);

//			    removeMCSys(h_draw_bjet_temp,
//					h_draw_bjet_sys_up_temp[iVAR*nsysGL+is],
//					h_draw_bjet_sys_low_temp[iVAR*nsysGL+is]);

			      {				 
				 double uncSys = 0.;
				 double nbinsSys = h_draw_bjet_temp->GetXaxis()->GetNbins();
				 double errSys = 0.;
				 double intSys = h_draw_bjet_temp->IntegralAndError(1,nbinsSys,errSys);
				 for(int ibh=1;ibh<=nbinsSys;ibh++)
				   {
				      double sysNom = h_draw_bjet_temp->GetBinContent(ibh);
				      double sysLow = sysNom - h_draw_bjet_sys_low_temp[iVAR*nsysGL+is]->GetBinContent(ibh);
				      double sysUp = h_draw_bjet_sys_up_temp[iVAR*nsysGL+is]->GetBinContent(ibh) - sysNom;
				      double sysMax = (sysLow > sysUp) ? sysLow : sysUp;
				      uncSys += sysMax + sysNom;
				      //				 uncSys += (sysNom > 0) ? sysMax/sysNom : 0.;
				      //				 double ferr = (sysNom > 0) ? sysMax/sysNom : 0.;
				      //				 std::cout << ibh << " " << ferr << " " << sysNom << "+-" << sysMax << std::endl;
				   }
				 //			    uncSys /= float(nbinsSys);
				 uncSys = (intSys > 0.) ? (uncSys/intSys)-1. : 0.;
				 
				 std::string namesys_bjet = name_sys_low[is];
				 if( namesys_bjet == "" ) namesys_bjet = "nosys";
				 
				 fsys << "bjet   " << hnameVAR[iVAR] << "   " << namesys_bjet << "   " <<
				   hnamePT[iPT] << "   " <<
				   uncSys << "   " << errSys << std::endl;
			      }
			    
			    std::string cjet_low_temp = name_sys_low[is] + "_temp";
			    h_draw_cjet_sys_low_temp[iVAR*nsysGL+is] = (TH1D*)h_draw_cjet_sys_low[is][iVAR]->Clone(cjet_low_temp.c_str());
			    std::string cjet_up_temp = name_sys_up[is] + "_temp";
			    h_draw_cjet_sys_up_temp[iVAR*nsysGL+is] = (TH1D*)h_draw_cjet_sys_up[is][iVAR]->Clone(cjet_up_temp.c_str());

			    float nev_cjet_low = h_draw_cjet_sys_low_temp[iVAR*nsysGL+is]->Integral();
			    float nev_cjet_up = h_draw_cjet_sys_up_temp[iVAR*nsysGL+is]->Integral();
			    if( nev_cjet_low > 0. ) h_draw_cjet_sys_low_temp[iVAR*nsysGL+is]->Scale(1./nev_cjet_low);
			    if( nev_cjet_up > 0. ) h_draw_cjet_sys_up_temp[iVAR*nsysGL+is]->Scale(1./nev_cjet_up);
////3nov			    if( nev_cjet_low > 0. ) h_draw_cjet_sys_low_temp[iVAR*nsysGL+is]->Scale(1./nev_cjet);
////			    if( nev_cjet_up > 0. ) h_draw_cjet_sys_up_temp[iVAR*nsysGL+is]->Scale(1./nev_cjet);

//			    if( doCorrNorm )
//			      {				 
//				 double fc_low = fnorm(h_draw_cjet_temp,h_draw_cjet_sys_low_temp[iVAR*nsysGL+is]);
//				 double fc_up = fnorm(h_draw_cjet_temp,h_draw_cjet_sys_up_temp[iVAR*nsysGL+is]);
//			      }			    
			    
			    totSys(h_draw_cjet_temp,
				   h_draw_cjet_sys_low_temp[iVAR*nsysGL+is],
				   h_draw_cjet_sys_up_temp[iVAR*nsysGL+is]);

//			    removeMCSys(h_draw_cjet_temp,
//					h_draw_cjet_sys_up_temp[iVAR*nsysGL+is],
//					h_draw_cjet_sys_low_temp[iVAR*nsysGL+is]);

			      {				 
				 double uncSys = 0.;
				 double nbinsSys = h_draw_cjet_temp->GetXaxis()->GetNbins();
				 double errSys = 0.;
				 double intSys = h_draw_cjet_temp->IntegralAndError(1,nbinsSys,errSys);
				 for(int ibh=1;ibh<=nbinsSys;ibh++)
				   {
				      double sysNom = h_draw_cjet_temp->GetBinContent(ibh);
				      double sysLow = sysNom - h_draw_cjet_sys_low_temp[iVAR*nsysGL+is]->GetBinContent(ibh);
				      double sysUp = h_draw_cjet_sys_up_temp[iVAR*nsysGL+is]->GetBinContent(ibh) - sysNom;
				      double sysMax = (sysLow > sysUp) ? sysLow : sysUp;
				      uncSys += sysMax + sysNom;
				      //				 uncSys += (sysNom > 0) ? sysMax/sysNom : 0.;
				      //				 double ferr = (sysNom > 0) ? sysMax/sysNom : 0.;
				      //				 std::cout << ibh << " " << ferr << " " << sysNom << "+-" << sysMax << std::endl;
				   }
				 //			    uncSys /= float(nbinsSys);
				 uncSys = (intSys > 0.) ? (uncSys/intSys)-1. : 0.;
			    
				 std::string namesys_cjet = name_sys_low[is];
				 if( namesys_cjet == "" ) namesys_cjet = "nosys";
			    
				 fsys << "cjet   " << hnameVAR[iVAR] << "   " << namesys_cjet << "   " <<
				   hnamePT[iPT] << "   " <<
				   uncSys << "   " << errSys << std::endl;
			      }			    
			    
			    std::string ljet_low_temp = name_sys_low[is] + "_temp";
			    h_draw_ljet_sys_low_temp[iVAR*nsysGL+is] = (TH1D*)h_draw_ljet_sys_low[is][iVAR]->Clone(ljet_low_temp.c_str());
			    std::string ljet_up_temp = name_sys_up[is] + "_temp";
			    h_draw_ljet_sys_up_temp[iVAR*nsysGL+is] = (TH1D*)h_draw_ljet_sys_up[is][iVAR]->Clone(ljet_up_temp.c_str());

			    float nev_ljet_low = h_draw_ljet_sys_low_temp[iVAR*nsysGL+is]->Integral();
			    float nev_ljet_up = h_draw_ljet_sys_up_temp[iVAR*nsysGL+is]->Integral();
			    if( nev_ljet_low > 0. ) h_draw_ljet_sys_low_temp[iVAR*nsysGL+is]->Scale(1./nev_ljet_low);
			    if( nev_ljet_up > 0. ) h_draw_ljet_sys_up_temp[iVAR*nsysGL+is]->Scale(1./nev_ljet_up);
////3nov			    if( nev_ljet_low > 0. ) h_draw_ljet_sys_low_temp[iVAR*nsysGL+is]->Scale(1./nev_ljet);
////			    if( nev_ljet_up > 0. ) h_draw_ljet_sys_up_temp[iVAR*nsysGL+is]->Scale(1./nev_ljet);
			    
//			    if( doCorrNorm )
//			      {				 
//				 double fl_low = fnorm(h_draw_ljet_temp,h_draw_ljet_sys_low_temp[iVAR*nsysGL+is]);
//				 double fl_up = fnorm(h_draw_ljet_temp,h_draw_ljet_sys_up_temp[iVAR*nsysGL+is]);
//			      }			    
			    
			    totSys(h_draw_ljet_temp,
				   h_draw_ljet_sys_low_temp[iVAR*nsysGL+is],
				   h_draw_ljet_sys_up_temp[iVAR*nsysGL+is]);
			    
//			    removeMCSys(h_draw_ljet_temp,
//					h_draw_ljet_sys_up_temp[iVAR*nsysGL+is],
//					h_draw_ljet_sys_low_temp[iVAR*nsysGL+is]);
			      
			      {				 
				 double uncSys = 0.;
				 double nbinsSys = h_draw_ljet_temp->GetXaxis()->GetNbins();
				 double errSys = 0.;
				 double intSys = h_draw_ljet_temp->IntegralAndError(1,nbinsSys,errSys);
				 for(int ibh=1;ibh<=nbinsSys;ibh++)
				   {
				      double sysNom = h_draw_ljet_temp->GetBinContent(ibh);
				      double sysLow = sysNom - h_draw_ljet_sys_low_temp[iVAR*nsysGL+is]->GetBinContent(ibh);
				      double sysUp = h_draw_ljet_sys_up_temp[iVAR*nsysGL+is]->GetBinContent(ibh) - sysNom;
				      double sysMax = (sysLow > sysUp) ? sysLow : sysUp;
				      uncSys += sysMax + sysNom;
				      //				 uncSys += (sysNom > 0) ? sysMax/sysNom : 0.;
				      //				 double ferr = (sysNom > 0) ? sysMax/sysNom : 0.;
				      //				 std::cout << ibh << " " << ferr << " " << sysNom << "+-" << sysMax << std::endl;
				   }
				 //			    uncSys /= float(nbinsSys);
				 uncSys = (intSys > 0.) ? (uncSys/intSys)-1. : 0.;
				 
				 std::string namesys_ljet = name_sys_low[is];
				 if( namesys_ljet == "" ) namesys_ljet = "nosys";
				 
				 fsys << "ljet   " << hnameVAR[iVAR] << "   " << namesys_ljet << "   " <<
				   hnamePT[iPT] << "   " <<
				   uncSys << "   " << errSys << std::endl;
			      }			    
			    
			    std::string ljet_data_low_temp = name_sys_low[is] + "_temp";
			    h_draw_ljet_data_sys_low_temp[iVAR*nsysGL+is] = (TH1D*)h_draw_ljet_data_sys_low[is][iVAR]->Clone(ljet_data_low_temp.c_str());
			    std::string ljet_data_up_temp = name_sys_up[is] + "_temp";
			    h_draw_ljet_data_sys_up_temp[iVAR*nsysGL+is] = (TH1D*)h_draw_ljet_data_sys_up[is][iVAR]->Clone(ljet_data_up_temp.c_str());

			    float nev_ljet_data_low = h_draw_ljet_data_sys_low_temp[iVAR*nsysGL+is]->Integral();
			    float nev_ljet_data_up = h_draw_ljet_data_sys_up_temp[iVAR*nsysGL+is]->Integral();
			    if( nev_ljet_data_low > 0. ) h_draw_ljet_data_sys_low_temp[iVAR*nsysGL+is]->Scale(1./nev_ljet_data_low);
			    if( nev_ljet_data_up > 0. ) h_draw_ljet_data_sys_up_temp[iVAR*nsysGL+is]->Scale(1./nev_ljet_data_up);
/////			    if( nev_ljet_data_low > 0. ) h_draw_ljet_data_sys_low_temp[iVAR*nsysGL+is]->Scale(1./nev_ljet_data);
/////			    if( nev_ljet_data_up > 0. ) h_draw_ljet_data_sys_up_temp[iVAR*nsysGL+is]->Scale(1./nev_ljet_data);
			    
//			    if( doCorrNorm )
//			      {				 
//				 double fl_data_low = fnorm(h_draw_ljet_data_temp,h_draw_ljet_data_sys_low_temp[iVAR*nsysGL+is]);
//				 double fl_data_up = fnorm(h_draw_ljet_data_temp,h_draw_ljet_data_sys_up_temp[iVAR*nsysGL+is]);
//			      }			    
			    
			    totSys(h_draw_ljet_data_temp,
				   h_draw_ljet_data_sys_low_temp[iVAR*nsysGL+is],
				   h_draw_ljet_data_sys_up_temp[iVAR*nsysGL+is]);

//			    removeMCSys(h_draw_ljet_data_temp,
//					h_draw_ljet_data_sys_up_temp[iVAR*nsysGL+is],
//					h_draw_ljet_data_sys_low_temp[iVAR*nsysGL+is]);
			 }

		       combSys(h_draw_bjet_temp,
			       h_draw_bjet_sys_low_temp,
			       h_draw_bjet_sys_up_temp,
			       h_draw_bjet_sys_low_combSum_temp,
			       h_draw_bjet_sys_up_combSum_temp,iVAR);

		       combSys(h_draw_cjet_temp,
			       h_draw_cjet_sys_low_temp,
			       h_draw_cjet_sys_up_temp,
			       h_draw_cjet_sys_low_combSum_temp,
			       h_draw_cjet_sys_up_combSum_temp,iVAR);

		       combSys(h_draw_ljet_temp,
			       h_draw_ljet_sys_low_temp,
			       h_draw_ljet_sys_up_temp,
			       h_draw_ljet_sys_low_combSum_temp,
			       h_draw_ljet_sys_up_combSum_temp,iVAR);

		       combSys(h_draw_ljet_data_temp,
			       h_draw_ljet_data_sys_low_temp,
			       h_draw_ljet_data_sys_up_temp,
			       h_draw_ljet_data_sys_low_combSum_temp,
			       h_draw_ljet_data_sys_up_combSum_temp,iVAR);
		       
		       totSys(h_draw_bjet_temp,
			      h_draw_bjet_sys_low_combSum_temp,
			      h_draw_bjet_sys_up_combSum_temp);

		       totSys(h_draw_cjet_temp,
			      h_draw_cjet_sys_low_combSum_temp,
			      h_draw_cjet_sys_up_combSum_temp);
	     
		       totSys(h_draw_ljet_temp,
			      h_draw_ljet_sys_low_combSum_temp,
			      h_draw_ljet_sys_up_combSum_temp);
	
		       totSys(h_draw_ljet_data_temp,
			      h_draw_ljet_data_sys_low_combSum_temp,
			      h_draw_ljet_data_sys_up_combSum_temp);

		       // bjet
			 {			    
			    h_draw_bjet_temp->Draw("hist e1");

			    TGraphAsymmErrors *gr_mc_merged = makeErrorBand(h_draw_bjet_temp,
									    h_draw_bjet_sys_up_combSum_temp,
									    h_draw_bjet_sys_low_combSum_temp);

//			    for(int i=0;i<h_draw_bjet_temp->GetXaxis()->GetNbins();i++)
//			      {
//				 double x,y;
//				 gr_mc_merged->GetPoint(i,x,y);
//				 std::cout << "kskovpen: " << h_draw_bjet_temp->GetBinContent(i+1) << " " <<
//				   y << std::endl;
//			      }			    
			    
			    gr_mc_merged->SetFillStyle(3004);
			    gStyle->SetHatchesLineWidth(2);
			    gr_mc_merged->Draw("2SAME");

			    std::vector<std::string> vstr = setTit(hnameVAR[iVAR]);
			    std::string xAxisTit = vstr.at(0);
			    std::string yAxisTit = vstr.at(1);
			    
			    h_draw_bjet_temp->SetTitle("");
			    h_draw_bjet_temp->GetXaxis()->SetTitle(xAxisTit.c_str());
			    h_draw_bjet_temp->GetYaxis()->SetTitle(yAxisTit.c_str());
			    
			    leg = new TLegend(0.65,0.90,0.88,0.75);
			    leg->SetFillColor(253);
			    leg->SetBorderSize(0);			    
			    leg->AddEntry(h_draw_bjet_temp,"b-jets","f");
			    leg->Draw();

			    double mh_up = h_draw_bjet_sys_up_combSum_temp->GetMaximum();
			    h_draw_bjet_temp->SetMaximum(mh_up*1.1);
			    
//			    ATLASLabel(0.20,0.85,"Internal",1);
			    
			    std::string hname = hnameVAR[iVAR] + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];
			    
			    std::string fsave = "pics/"+hname+"_datamc_nofit_bjet_"+sysNameGL+".eps";
			    c1->Print(fsave.c_str());
			    delete leg;
			    
			    delete gr_mc_merged;
			 }		       
		       
		       // cjet
			 {			    
			    h_draw_cjet_temp->Draw("hist e1");

			    TGraphAsymmErrors *gr_mc_merged = makeErrorBand(h_draw_cjet_temp,
									    h_draw_cjet_sys_up_combSum_temp,
									    h_draw_cjet_sys_low_combSum_temp);

			    h_draw_cjet_temp->Draw("hist same");
			    
			    gr_mc_merged->SetFillStyle(3004);
			    gStyle->SetHatchesLineWidth(2);
			    gr_mc_merged->Draw("2SAME");

			    std::vector<std::string> vstr = setTit(hnameVAR[iVAR]);
			    std::string xAxisTit = vstr.at(0);
			    std::string yAxisTit = vstr.at(1);
			    
			    h_draw_cjet_temp->SetTitle("");
			    h_draw_cjet_temp->GetXaxis()->SetTitle(xAxisTit.c_str());
			    h_draw_cjet_temp->GetYaxis()->SetTitle(yAxisTit.c_str());
			    
			    leg = new TLegend(0.65,0.90,0.88,0.75);
			    leg->SetFillColor(253);
			    leg->SetBorderSize(0);			    
			    leg->AddEntry(h_draw_cjet_temp,"c-jets","f");
			    leg->Draw();

			    double mh_up = h_draw_cjet_sys_up_combSum_temp->GetMaximum();
			    h_draw_cjet_temp->SetMaximum(mh_up*1.1);

//			    ATLASLabel(0.20,0.85,"Internal",1);
			    
			    std::string hname = hnameVAR[iVAR] + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];
			    
			    std::string fsave = "pics/"+hname+"_datamc_nofit_cjet_"+sysNameGL+".eps";
			    c1->Print(fsave.c_str());
			    delete leg;
			    
			    delete gr_mc_merged;
			 }		       

		       // ljet
			 {			    
			    h_draw_ljet_temp->Draw("hist e1");

			    TGraphAsymmErrors *gr_mc_merged = makeErrorBand(h_draw_ljet_temp,
									    h_draw_ljet_sys_up_combSum_temp,
									    h_draw_ljet_sys_low_combSum_temp);

			    h_draw_ljet_temp->Draw("hist same");
			    
			    gr_mc_merged->SetFillStyle(3004);
			    gStyle->SetHatchesLineWidth(2);
			    gr_mc_merged->Draw("2SAME");

			    std::vector<std::string> vstr = setTit(hnameVAR[iVAR]);
			    std::string xAxisTit = vstr.at(0);
			    std::string yAxisTit = vstr.at(1);
			    
			    h_draw_ljet_temp->SetTitle("");
			    h_draw_ljet_temp->GetXaxis()->SetTitle(xAxisTit.c_str());
			    h_draw_ljet_temp->GetYaxis()->SetTitle(yAxisTit.c_str());
			    
			    leg = new TLegend(0.65,0.90,0.88,0.75);
			    leg->SetFillColor(253);
			    leg->SetBorderSize(0);
			    leg->AddEntry(h_draw_ljet_temp,"light-flavour jets","f");
//			    leg->AddEntry(h_draw_ljet_temp,"non-b-jets","f");
			    leg->Draw();

			    double mh_up = h_draw_ljet_sys_up_combSum_temp->GetMaximum();
			    h_draw_ljet_temp->SetMaximum(mh_up*1.1);

//			    ATLASLabel(0.20,0.85,"Internal",1);
			    
			    std::string hname = hnameVAR[iVAR] + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];
			    
			    std::string fsave = "pics/"+hname+"_datamc_nofit_ljet_mc_"+sysNameGL+".eps";
			    c1->Print(fsave.c_str());
			    delete leg;
			    
			    delete gr_mc_merged;
			 }		       
		       
		       // ljet_data
			 {			    
			    h_draw_ljet_data_temp->Draw("hist e1");

			    TGraphAsymmErrors *gr_mc_merged = makeErrorBand(h_draw_ljet_data_temp,
									    h_draw_ljet_data_sys_up_combSum_temp,
									    h_draw_ljet_data_sys_low_combSum_temp);

			    h_draw_ljet_data_temp->Draw("hist same");
			    
			    gr_mc_merged->SetFillStyle(3004);
			    gStyle->SetHatchesLineWidth(2);
			    gr_mc_merged->Draw("2SAME");

			    std::vector<std::string> vstr = setTit(hnameVAR[iVAR]);
			    std::string xAxisTit = vstr.at(0);
			    std::string yAxisTit = vstr.at(1);
			    
			    h_draw_ljet_data_temp->SetTitle("");
			    h_draw_ljet_data_temp->GetXaxis()->SetTitle(xAxisTit.c_str());
			    h_draw_ljet_data_temp->GetYaxis()->SetTitle(yAxisTit.c_str());
			    
			    leg = new TLegend(0.65,0.90,0.88,0.75);
			    leg->SetFillColor(253);
			    leg->SetBorderSize(0);
			    leg->AddEntry(h_draw_ljet_data_temp,"light-flavour jets","f");
//			    leg->AddEntry(h_draw_ljet_data_temp,"non-b-jets","f");
			    leg->Draw();

			    double mh_up = h_draw_ljet_data_sys_up_combSum_temp->GetMaximum();
			    h_draw_ljet_data_temp->SetMaximum(mh_up*1.1);

//			    ATLASLabel(0.20,0.85,"Internal",1);
			    
			    std::string hname = hnameVAR[iVAR] + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];
			    
			    std::string fsave = "pics/"+hname+"_datamc_nofit_ljet_"+sysNameGL+".eps";
			    c1->Print(fsave.c_str());
			    delete leg;
			    
			    delete gr_mc_merged;
			 }		       

		       for(int is=0;is<nsysGL;is++)
			 {
			    delete h_draw_bjet_sys_low_temp[iVAR*nsysGL+is];
			    delete h_draw_bjet_sys_up_temp[iVAR*nsysGL+is];
			    delete h_draw_cjet_sys_low_temp[iVAR*nsysGL+is];
			    delete h_draw_cjet_sys_up_temp[iVAR*nsysGL+is];
			    delete h_draw_ljet_sys_low_temp[iVAR*nsysGL+is];
			    delete h_draw_ljet_sys_up_temp[iVAR*nsysGL+is];
			    delete h_draw_ljet_data_sys_low_temp[iVAR*nsysGL+is];
			    delete h_draw_ljet_data_sys_up_temp[iVAR*nsysGL+is];
			 }

		       delete h_draw_bjet_temp;
		       delete h_draw_cjet_temp;
		       delete h_draw_ljet_temp;
		       delete h_draw_ljet_data_temp;
		       
		       delete h_draw_bjet_sys_low_combSum_temp;
		       delete h_draw_cjet_sys_low_combSum_temp;
		       delete h_draw_ljet_sys_low_combSum_temp;
		       delete h_draw_ljet_data_sys_low_combSum_temp;

		       delete h_draw_bjet_sys_up_combSum_temp;
		       delete h_draw_cjet_sys_up_combSum_temp;
		       delete h_draw_ljet_sys_up_combSum_temp;
		       delete h_draw_ljet_data_sys_up_combSum_temp;

		       TH1D *h_draw_bjet_ptrw = (TH1D*)h_draw_bjet[iVAR]->Clone("h_draw_bjet_ptrw");
		       TH1D *h_draw_cjet_ptrw = (TH1D*)h_draw_cjet[iVAR]->Clone("h_draw_cjet_ptrw");
		       TH1D *h_draw_ljet_ptrw = (TH1D*)h_draw_ljet[iVAR]->Clone("h_draw_ljet_ptrw");
		       
		       double int_bjet_ptrw = h_draw_bjet_ptrw->Integral();
		       double int_cjet_ptrw = h_draw_cjet_ptrw->Integral();
		       double int_ljet_ptrw = h_draw_ljet_ptrw->Integral();

		       if( usePRETAGb )
			 {			    
			    ntot_bjet[iVAR] = h_draw_bjet_posttag[iVAR]->IntegralAndError(0,h_draw_bjet_posttag[iVAR]->GetXaxis()->GetNbins()+1,ntot_bjet_err[iVAR]);
			 }		       
		       else
			 {			    
			    ntot_bjet[iVAR] = h_draw_bjet[iVAR]->IntegralAndError(0,h_draw_bjet[iVAR]->GetXaxis()->GetNbins()+1,ntot_bjet_err[iVAR]);
			    ntot_bjet_true[iVAR] = h_draw_bjet_true[iVAR]->IntegralAndError(0,h_draw_bjet_true[iVAR]->GetXaxis()->GetNbins()+1,ntot_bjet_err_true[iVAR]);
			 }		       
		       
		       if( usePRETAGc )
			 {			    
			    ntot_cjet[iVAR] = h_draw_cjet_posttag[iVAR]->IntegralAndError(0,h_draw_cjet_posttag[iVAR]->GetXaxis()->GetNbins()+1,ntot_cjet_err[iVAR]);
			 }		       
		       else
			 {			    
			    ntot_cjet[iVAR] = h_draw_cjet[iVAR]->IntegralAndError(0,h_draw_cjet[iVAR]->GetXaxis()->GetNbins()+1,ntot_cjet_err[iVAR]);
			    ntot_cjet_true[iVAR] = h_draw_cjet_true[iVAR]->IntegralAndError(0,h_draw_cjet_true[iVAR]->GetXaxis()->GetNbins()+1,ntot_cjet_err_true[iVAR]);
			 }		       
			 
		       ntot_ljet[iVAR] = h_ljet->IntegralAndError(0,h_ljet->GetXaxis()->GetNbins()+1,ntot_ljet_err[iVAR]);
		       ntot_cljet[iVAR] = h_draw_cljet[iVAR]->IntegralAndError(0,h_draw_cljet[iVAR]->GetXaxis()->GetNbins()+1,ntot_cljet_err[iVAR]);
		       
		       ntot_ljet_true[iVAR] = h_draw_ljet_true[iVAR]->IntegralAndError(0,h_draw_ljet_true[iVAR]->GetXaxis()->GetNbins()+1,ntot_ljet_err_true[iVAR]);
		       
		       ntot_ajet_data[iVAR] = h_draw_ajet_data[iVAR]->IntegralAndError(0,h_draw_ajet_data[iVAR]->GetXaxis()->GetNbins()+1,ntot_ajet_data_err[iVAR]);
		       
		       double intbjet = h_draw_bjet[iVAR]->Integral(0,h_draw_bjet[iVAR]->GetXaxis()->GetNbins()+1);
		       double intcjet = h_draw_cjet[iVAR]->Integral(0,h_draw_cjet[iVAR]->GetXaxis()->GetNbins()+1);
		       double intljet = h_ljet->Integral(0,h_ljet->GetXaxis()->GetNbins()+1);
		       double intljetMC = h_draw_ljet[iVAR]->Integral(0,h_draw_ljet[iVAR]->GetXaxis()->GetNbins()+1);
		       double intdata = h_draw_ajet_data[iVAR]->Integral(0,h_draw_ajet_data[iVAR]->GetXaxis()->GetNbins()+1);

		       double intbjet_true = h_draw_bjet_true[iVAR]->Integral(0,h_draw_bjet_true[iVAR]->GetXaxis()->GetNbins()+1);
		       double intcjet_true = h_draw_cjet_true[iVAR]->Integral(0,h_draw_cjet_true[iVAR]->GetXaxis()->GetNbins()+1);
		       double intljet_true = h_draw_ljet_true[iVAR]->Integral(0,h_draw_ljet_true[iVAR]->GetXaxis()->GetNbins()+1);
		       
		       fr = 1.;
//		       if( intljetMC && doCL ) fr = intcjet/intljetMC;
		       
		       double intSum = 1 + fr + 1;
		       
////		       if( intbjet > 0. ) h_draw_bjet[iVAR]->Scale(1./intbjet/intSum);
////		       if( intcjet > 0. ) h_draw_cjet[iVAR]->Scale(fr/intcjet/intSum);
////		       if( intljet > 0. ) h_ljet->Scale(1./intljet/intSum);

		       // Normalisation of histograms
		       
		       if( intbjet > 0. ) h_draw_bjet[iVAR]->Scale(1./intbjet);
		       if( intcjet > 0. ) h_draw_cjet[iVAR]->Scale(fr/intcjet);
		       if( intljet > 0. ) h_ljet->Scale(1./intljet);

		       if( intbjet_true > 0. ) h_draw_bjet_true[iVAR]->Scale(1./intbjet_true);
		       if( intcjet_true > 0. ) h_draw_cjet_true[iVAR]->Scale(fr/intcjet_true);
		       if( intljet_true > 0. ) h_draw_ljet_true[iVAR]->Scale(1./intljet_true);
		       
		       for(int is=0;is<nsysGL;is++)
			 {			    
			    TH1D *h_ljet_sys_low = h_draw_ljet_data_sys_low[is][iVAR];
			    if( !ljetData ) h_ljet_sys_low = h_draw_ljet_sys_low[is][iVAR];

			    TH1D *h_ljet_sys_up = h_draw_ljet_data_sys_up[is][iVAR];
			    if( !ljetData ) h_ljet_sys_up = h_draw_ljet_sys_up[is][iVAR];
			  
			    double intbjet_sys_low = h_draw_bjet_sys_low[is][iVAR]->Integral();
			    double intcjet_sys_low = h_draw_cjet_sys_low[is][iVAR]->Integral();
			    double intljet_sys_low = h_ljet_sys_low->Integral();
			    
			    double intbjet_sys_up = h_draw_bjet_sys_up[is][iVAR]->Integral();
			    double intcjet_sys_up = h_draw_cjet_sys_up[is][iVAR]->Integral();
			    double intljet_sys_up = h_ljet_sys_up->Integral();
			    
//			    if( intbjet_sys_low > 0. ) h_draw_bjet_sys_low[is][iVAR]->Scale(1./intbjet_sys_low/intSum);
//			    if( intcjet_sys_low > 0. ) h_draw_cjet_sys_low[is][iVAR]->Scale(fr/intcjet_sys_low/intSum);
//			    if( intljet_sys_low > 0. ) h_ljet_sys_low->Scale(1./intljet_sys_low/intSum);

//			    if( intbjet_sys_up > 0. ) h_draw_bjet_sys_up[is][iVAR]->Scale(1./intbjet_sys_up/intSum);
//			    if( intcjet_sys_up > 0. ) h_draw_cjet_sys_up[is][iVAR]->Scale(fr/intcjet_sys_up/intSum);
//			    if( intljet_sys_up > 0. ) h_ljet_sys_up->Scale(1./intljet_sys_up/intSum);

			    std::string sysnameLow = name_sys_low[is];
			    
/*			    bool isCustomSys = (
						sysnameLow == "_ntrk_low" || 
						sysnameLow == "_val_low" || 
						sysnameLow == "_njet_low" || 
						sysnameLow == "_mupt_low" || 
						sysnameLow == "_jeta_low" || 
						sysnameLow == "_pt_low" 
					       );
			    
			    if( !isCustomSys )
			      {				 */

/*			    if( name_sys_low[is] == "_ntrk_low" || 
				name_sys_low[is] == "_njet_low" ||
				name_sys_low[is] == "_mupt_low" ||
				name_sys_low[is] == "_jeta_low" )
			      {				 
			         if( intbjet > 0. ) h_draw_bjet_sys_low[is][iVAR]->Scale(1./intbjet);
				 if( intcjet > 0. ) h_draw_cjet_sys_low[is][iVAR]->Scale(fr/intcjet);
				 if( intljet > 0. ) h_ljet_sys_low->Scale(1./intljet);
				 
				 if( intbjet > 0. ) h_draw_bjet_sys_up[is][iVAR]->Scale(1./intbjet);
				 if( intcjet > 0. ) h_draw_cjet_sys_up[is][iVAR]->Scale(fr/intcjet);
				 if( intljet > 0. ) h_ljet_sys_up->Scale(1./intljet);
			      }
			    else
			      {*/
			         if( intbjet_sys_low > 0. ) h_draw_bjet_sys_low[is][iVAR]->Scale(1./intbjet_sys_low);
				 if( intcjet_sys_low > 0. ) h_draw_cjet_sys_low[is][iVAR]->Scale(fr/intcjet_sys_low);
				 if( intljet_sys_low > 0. ) h_ljet_sys_low->Scale(1./intljet_sys_low);
				 
				 if( intbjet_sys_up > 0. ) h_draw_bjet_sys_up[is][iVAR]->Scale(1./intbjet_sys_up);
				 if( intcjet_sys_up > 0. ) h_draw_cjet_sys_up[is][iVAR]->Scale(fr/intcjet_sys_up);
				 if( intljet_sys_up > 0. ) h_ljet_sys_up->Scale(1./intljet_sys_up);
//			      }			    
			    
/*			      }			    
			    else
			      {				 
				 if( intbjet_sys_low > 0. ) h_draw_bjet_sys_low[is][iVAR]->Scale(1./intbjet);
				 if( intcjet_sys_low > 0. ) h_draw_cjet_sys_low[is][iVAR]->Scale(fr/intcjet);
				 if( intljet_sys_low > 0. ) h_ljet_sys_low->Scale(1./intljet);
				 
				 if( intbjet_sys_up > 0. ) h_draw_bjet_sys_up[is][iVAR]->Scale(1./intbjet);
				 if( intcjet_sys_up > 0. ) h_draw_cjet_sys_up[is][iVAR]->Scale(fr/intcjet);
				 if( intljet_sys_up > 0. ) h_ljet_sys_up->Scale(1./intljet);
			      }*/
			    
//			    if( doCorrNorm )
//			      {				 
//				 double fb_low = fnorm(h_draw_bjet[iVAR],h_draw_bjet_sys_low[is][iVAR]);
//				 double fc_low = fnorm(h_draw_cjet[iVAR],h_draw_cjet_sys_low[is][iVAR]);
//				 double fl_low = fnorm(h_ljet,h_ljet_sys_low);
				 
//				 double fb_up = fnorm(h_draw_bjet[iVAR],h_draw_bjet_sys_up[is][iVAR]);
//				 double fc_up = fnorm(h_draw_cjet[iVAR],h_draw_cjet_sys_up[is][iVAR]);
//				 double fl_up = fnorm(h_ljet,h_ljet_sys_up);
//			      }
			 }

		       // monitor systematics
		       for(int iss=1;iss<nsys;iss++)
			 {
			    std::string psysname = hname+"_datamc_nofit_bjet"+name_sys_low[iss];
			    plotFracSys(h_draw_bjet[iVAR],
					h_draw_bjet_sys_low[iss][iVAR],
					h_draw_bjet_sys_up[iss][iVAR],
					psysname,
					name_sys_low[iss],
					iss,
					"bjet",0);
			    psysname = hname+"_datamc_nofit_cjet"+name_sys_low[iss];
			    plotFracSys(h_draw_cjet[iVAR],
					h_draw_cjet_sys_low[iss][iVAR],
					h_draw_cjet_sys_up[iss][iVAR],
					psysname,
					name_sys_low[iss],
					iss,
					"cjet",0);
			    psysname = hname+"_datamc_nofit_ljet"+name_sys_low[iss];
			    plotFracSys(h_draw_ljet[iVAR],
					h_draw_ljet_sys_low[iss][iVAR],
					h_draw_ljet_sys_up[iss][iVAR],
					psysname,
					name_sys_low[iss],
					iss,
					"ljet",0);
			 }		       
		       
		       // inject additional systematics for data-derived light jet template
/*		       float sysData = 0.05;
		       h_draw_ljet_data_sys_low[0][iVAR]->Scale(1-sysData);
		       h_draw_ljet_data_sys_up[0][iVAR]->Scale(1+sysData);
		       h_draw_bjet_sys_low[0][iVAR]->Scale(1-sysData);
		       h_draw_bjet_sys_up[0][iVAR]->Scale(1+sysData);
		       h_draw_cjet_sys_low[0][iVAR]->Scale(1-sysData);
		       h_draw_cjet_sys_up[0][iVAR]->Scale(1+sysData);*/
		       
		       if( intdata > 0 ) h_draw_ajet_data[iVAR]->Scale(1./intdata);
		       
		       applySys(iVAR,
				hname_bjet,
				hname_cjet,
				hname_ljet,
				hname_ajet,
				hname_ljet_data,
				1.,
				1.,
				1.,
				0.,
				0.,
				0.,
			        false,
				true);
		       // change to true for the first bool variable if not using any additional applySys in func.h

		       // monitor bcl systematics
		       for(int iss=1;iss<nsys;iss++)
			 {
			    std::string psysname = hname+"_datamc_nofit_bcljet"+name_sys_low[iss];
			    plotFracSys(h_draw_bcljet_combNATURAL[iVAR],
					h_draw_bcljet_sys_low_combNATURAL[iVAR*nsysGL+iss],
					h_draw_bcljet_sys_up_combNATURAL[iVAR*nsysGL+iss],
					psysname,
					name_sys_low[iss],
					iss,
					"all",0);
			 }
		       
		       applySF("nofit",
			       hnameVAR[iVAR],
			       hnamePT[iPT],
			       hnameETA[iETA],
			       hnameBTAG[iBTAG],
			       iVAR,
			       iPT,
			       h_draw_bjet[iVAR],
			       h_draw_cjet[iVAR],
			       h_ljet,
			       h_draw_bjet_true[iVAR],
			       h_draw_cjet_true[iVAR],
			       h_draw_ljet_true[iVAR],
			       h_draw_ajet_data[iVAR],
			       h_draw_bcljet_comb[iVAR],
			       h_draw_bcljet_sys_up_combSum[iVAR],
			       h_draw_bcljet_sys_low_combSum[iVAR],
			       leg,
			       1.,
			       1.,
			       1.,
			       0.,
			       0.,
			       0.,
			       chis[0],
			       chis[1]);

		       // calculate PT re-weighting SF and re-bin PT histograms
		       // 
/*		       if( hnameVAR[iVAR] == mainPTRW && hnameETA[iETA] == "nosel" &&
			   hnameBTAG[iBTAG] == "_nosel" )
			 {
			    //		       if( hnamePT[iPT] == "nosel" )
			      {
				 std::string ptrwfn = "results/ptrw_" + hnamePT[iPT] + ".txt";
				 foutPTRW.open(ptrwfn.c_str());
			    
				 TH1D *hb = (TH1D*)h_draw_bjet_ptrw->Clone("hb");
				 TH1D *hc = (TH1D*)h_draw_cjet_ptrw->Clone("hc");
				 TH1D *hl = (TH1D*)h_draw_ljet_ptrw->Clone("hl");
				 TH1D *hd = (TH1D*)h_draw_ajet_data[iVAR]->Clone("hd");
				 
				 TH1D *hptsf = (TH1D*)hb->Clone("hptsf");
				 
				 double hbInt = hb->Integral();
				 double hcInt = hc->Integral();
				 double hlInt = hl->Integral();				 
				 
				 double sum = hb->Integral() + hc->Integral() + hl->Integral();
				 
				 if( hb->Integral() > 0 ) hb->Scale(1./sum);
				 if( hc->Integral() > 0 ) hc->Scale(1./sum);
				 if( hl->Integral() > 0 ) hl->Scale(1./sum);
				 if( hd->Integral() > 0 ) hd->Scale(1./hd->Integral());
				 
				 for( int ibpt=0;ibpt<hb->GetXaxis()->GetNbins();ibpt++ )
				   {			    
				      double bLE = hb->GetXaxis()->GetBinLowEdge(ibpt+1);
				      double bUE = hb->GetXaxis()->GetBinUpEdge(ibpt+1);
				      
				      double vpt1b = 0.;
				      double vpt1c = 0.;
				      double vpt1l = 0.;
				      double vpt1berr = 0.;
				      double vpt1cerr = 0.;
				      double vpt1lerr = 0.;
				      
				      if( hb->GetBinError(ibpt+1) > 0. )
					vpt1b = hb->GetBinContent(ibpt+1) / pow(hb->GetBinError(ibpt+1),2);
				      if( hc->GetBinError(ibpt+1) > 0. )
					vpt1c = hc->GetBinContent(ibpt+1) / pow(hc->GetBinError(ibpt+1),2);
				      if( hl->GetBinError(ibpt+1) > 0. )
					vpt1l = hl->GetBinContent(ibpt+1) / pow(hl->GetBinError(ibpt+1),2);

				      if( hb->GetBinError(ibpt+1) > 0. )
					vpt1berr = 1./pow(hb->GetBinError(ibpt+1),2);
				      if( hc->GetBinError(ibpt+1) > 0. )
					vpt1cerr = 1./pow(hc->GetBinError(ibpt+1),2);
				      if( hl->GetBinError(ibpt+1) > 0. )
					vpt1lerr = 1./pow(hl->GetBinError(ibpt+1),2);
				      
				      double sumf = vpt1berr + vpt1cerr + vpt1lerr;
				      
				      double vpt1 = 0.;
				      if( sumf > 0. )
					vpt1 = (vpt1b +
						vpt1c +
						vpt1l)/sumf;
				      
				      double vpt1err = sqrt(pow(hb->GetBinError(ibpt+1),2) +
							    pow(hc->GetBinError(ibpt+1),2) +
							    pow(hl->GetBinError(ibpt+1),2));
				      
				      double vpt2 = hd->GetBinContent(ibpt+1);
				 
				      double vpt2err = hd->GetBinError(ibpt+1);
				 
				      double ptsf = ( vpt1 != 0 ) ? vpt2/vpt1 : 1.;
				      double ptsferr = ( vpt1 != 0 ) ? sqrt(pow(vpt2err/vpt1,2) + 
									    pow(vpt2*vpt1err/(vpt1*vpt1),2)) : 0.;
				 
				      foutPTRW << ibpt << " " << bLE << " " << bUE 
					<< "   " << ptsf << "   " << ptsferr <<
					std::endl;
				      
				      if( !(ptsf == 1 && ptsferr == 0) )
					{				 
					   hptsf->SetBinContent(ibpt+1,ptsf);
					   hptsf->SetBinError(ibpt+1,ptsferr);
					}			    
				   }
				 
				 hptsf->GetYaxis()->SetRangeUser(0.1,20.);
				 hptsf->GetXaxis()->SetRangeUser(0.09,2.);
				 hptsf->SetLineColor(kBlack);
				 hptsf->SetMarkerColor(kBlack);
				 hptsf->GetXaxis()->SetTitle("P_{T} [TeV]");
				 hptsf->GetYaxis()->SetTitle("Data/MC");
				 hptsf->Draw("e1 hist");
				 c1->Print("pics/ptsf.eps");
				 
				 delete hb;
				 delete hc;
				 delete hl;
				 delete hd;
				 delete hptsf;
			      }		       
			    
			    foutPTRW.close();
			 }
*/
		       delete h_draw_bjet_ptrw;
		       delete h_draw_cjet_ptrw;
		       delete h_draw_ljet_ptrw;
		       
		       c1->Clear();
		       
		       THStack *h_draw_st = new THStack();

		       // overlaid		       

		       c1->Clear();
		  
		       TLegend *legOL = new TLegend(0.50,0.90,0.88,0.60);
		       legOL->SetFillColor(253);
		       legOL->SetBorderSize(0);

		       legOL->SetHeader(ptlabel(hnamePT[iPT]).c_str());
		       
		       TH1D *hb = (TH1D*)h_draw_bjet[iVAR]->Clone("hb");
		       TH1D *hc = (TH1D*)h_draw_cjet[iVAR]->Clone("hc");
		       TH1D *hl = (TH1D*)h_draw_ljet[iVAR]->Clone("hl");
		       TH1D *hl_data = (TH1D*)h_draw_ljet_data[iVAR]->Clone("hl_data");
		       TH1D *hb_untag = (TH1D*)h_draw_bjet_untag[iVAR]->Clone("hb_untag");
		       TH1D *hc_untag = (TH1D*)h_draw_cjet_untag[iVAR]->Clone("hc_untag");
		       TH1D *hl_data_noscale = (TH1D*)h_ljet_noscale->Clone("hl_data_noscale");
		       TH1D *hb_untag_noscale = (TH1D*)h_draw_bjet_untag[iVAR]->Clone("hb_untag_noscale");
		       TH1D *hc_untag_noscale = (TH1D*)h_draw_cjet_untag[iVAR]->Clone("hc_untag_noscale");
		       
		       if( hb->Integral() > 0 ) hb->Scale(1./hb->Integral());
		       if( hc->Integral() > 0 ) hc->Scale(1./hc->Integral());
		       if( hl->Integral() > 0 ) hl->Scale(1./hl->Integral());
		       if( hl_data->Integral() > 0 ) hl_data->Scale(1./hl_data->Integral());
		       if( hb_untag->Integral() > 0 ) hb_untag->Scale(1./hb_untag->Integral());
		       if( hc_untag->Integral() > 0 ) hc_untag->Scale(1./hc_untag->Integral());
		       
		       THStack *hbst = new THStack();
		       THStack *hcst = new THStack();
		       THStack *hlst = new THStack();
		       THStack *hlst_data = new THStack();
		       THStack *hbst_untag = new THStack();
		       THStack *hcst_untag = new THStack();
		       THStack *hlst_data_noscale = new THStack();
		       THStack *hbst_untag_noscale = new THStack();
		       THStack *hcst_untag_noscale = new THStack();

		       hb->SetFillColor(kb);

//		       hb->SetFillStyle(0);
		       hc->SetFillStyle(0);
		       hl->SetFillStyle(0);
		       hl_data->SetFillStyle(0);

		       hb->SetLineColor(kBlack);
		       hb_untag->SetLineColor(kBlack);
		       hb_untag_noscale->SetLineColor(kBlack);
		       
		       hlst->Add(hl);
		       hcst->Add(hc);
		       hbst->Add(hb);
		       
		       hc_untag->SetFillStyle(0);
		       
		       hlst_data->Add(hl_data);
		       hbst_untag->Add(hb_untag);
		       hcst_untag->Add(hc_untag);
		       
		       hl_data_noscale->SetFillStyle(0);
		       hl_data_noscale->SetMarkerStyle(20);
		       hl_data_noscale->SetMarkerSize(1.0);
		       hl_data_noscale->SetLineColor(kBlack);
		       hc_untag_noscale->SetFillStyle(0);
		       hb_untag_noscale->SetLineColor(kBlack);
		       
		       hlst_data_noscale->Add(hl_data_noscale);
		       hbst_untag_noscale->Add(hb_untag_noscale);
		       hcst_untag_noscale->Add(hc_untag_noscale);

		       c1->Clear();
		       
		       hbst->Draw("hist e1");
		       hcst->Draw("hist e1 same");
		       hlst->Draw("hist e1 same");
		       hlst_data->Draw("hist e1 same");
		       
		       legOL->AddEntry(hb,"b-jets","f");
		       legOL->AddEntry(hc,"c-jets","f");
		       legOL->AddEntry(hl,"light-flavour jets","f");
//		       legOL->AddEntry(hl,"non-b-jets","f");

		       if( hnameVAR[iVAR] == "h_j_pt_" ||
			   hnameVAR[iVAR] == "h_j1_pt_" ||
			   hnameVAR[iVAR] == "h_j2_pt_" )
			 {		       
			    hbst->SetMaximum(0.6);
			    hcst->SetMaximum(0.6);
			    hlst->SetMaximum(0.6);
			    
			    ptRange(hnamePT[iPT],
				    hbst);
			    ptRange(hnamePT[iPT],
				    hcst);
			    ptRange(hnamePT[iPT],
				    hlst);
			    ptRange(hnamePT[iPT],
				    hlst_data);
			 }
		       else
			 {
			    double m1 = hbst->GetMaximum();
			    double m2 = hcst->GetMaximum();
			    double m3 = hlst->GetMaximum();
			    double m = m1;
			    if( m2 > m && m2 > m3 ) m = m2;
			    if( m3 > m && m3 > m2 ) m = m3;
			    
			    hbst->SetMaximum(m*1.4);
			    hcst->SetMaximum(m*1.4);
			    hlst->SetMaximum(m*1.4);
			 }		  
		       
		       hbst->SetTitle("");
		       hbst->GetXaxis()->SetTitle(xAxisTit.c_str());
		       hbst->GetYaxis()->SetTitle(yAxisTit.c_str());
		       
		       hbst->Draw("hist e1");
		       hcst->Draw("hist e1 same");
		       hlst->Draw("hist e1 same");
		       
		       legOL->Draw();

//		       ATLASLabel(0.20,0.85,"Internal",1);
		       
		       std::string fsave = "pics/"+hname+"_mc_OL_"+sysNameGL+".eps";
		       c1->Print(fsave.c_str());
		       c1->Clear();		       
		       
		       hbst->Draw("hist e1");
		       hcst->Draw("hist e1 same");
		       hlst_data->Draw("hist e1 same");
		       
			 {			    
			    double m1 = hbst->GetMaximum();
			    double m2 = hcst->GetMaximum();
			    double m3 = hlst_data->GetMaximum();
			    double m = m1;
			    if( m2 > m && m2 > m3 ) m = m2;
			    if( m3 > m && m3 > m2 ) m = m3;
			    
			    hbst->SetMaximum(m*1.4);
			    hcst->SetMaximum(m*1.4);
			    hlst_data->SetMaximum(m*1.4);
			 }		       
		       
		       legOL->Clear();
		       legOL->AddEntry(hb,"b-jets","f");
		       legOL->AddEntry(hc,"c-jets","f");
		       legOL->AddEntry(hl_data,"light-flavour jets","f");
//		       legOL->AddEntry(hl_data,"non-b-jets","f");
		       legOL->Draw();

//		       ATLASLabel(0.20,0.85,"Internal",1);
		       
		       fsave = "pics/"+hname+"_ljet_OL_"+sysNameGL+".eps";
		       c1->Print(fsave.c_str());
		       c1->Clear();

		       hlst_data_noscale->Draw("hist e1");
		       hbst_untag_noscale->Draw("hist e1 same");
		       hcst_untag_noscale->Draw("hist e1 same");
		       
		       hlst_data_noscale->SetTitle("");
		       hlst_data_noscale->GetXaxis()->SetTitle(xAxisTit.c_str());
		       hlst_data_noscale->GetYaxis()->SetTitle("");
		       
			 {			    
			    double m1 = hbst_untag_noscale->GetMaximum();
			    double m2 = hcst_untag_noscale->GetMaximum();
			    double m3 = hlst_data_noscale->GetMaximum();
			    double m = m1;
			    if( m2 > m && m2 > m3 ) m = m2;
			    if( m3 > m && m3 > m2 ) m = m3;
			    
			    hbst_untag_noscale->SetMaximum(m*1.4);
			    hcst_untag_noscale->SetMaximum(m*1.4);
			    hlst_data_noscale->SetMaximum(m*1.4);
			 }
		       
		       legOL->Clear();
//		       legOL->AddEntry(hb_untag_noscale,"b-jets (Untag)","f");
//		       legOL->AddEntry(hc_untag_noscale,"c-jets (Untag)","f");
//		       legOL->AddEntry(hl_data_noscale,"Data (Untag)","f");
		       legOL->AddEntry(hb_untag_noscale,"b-jets","f");
		       legOL->AddEntry(hc_untag_noscale,"c-jets","f");
		       legOL->AddEntry(hl_data_noscale,"Data","lp");
		       legOL->Draw();

//		       ATLASLabel(0.20,0.85,"Internal",1);
			 
		       // set doSub to 0 !!
		       fsave = "pics/"+hname+"_ljet_untag_IL_"+sysNameGL+".eps";
		       c1->Print(fsave.c_str());
		       c1->Clear();
		       
		       hbst_untag->Draw("hist e1");
		       hlst_data->Draw("hist e1 same");
		       hcst_untag->Draw("hist e1 same");
		       
		       hlst_data->SetTitle("");
		       hlst_data->GetXaxis()->SetTitle(xAxisTit.c_str());
		       hlst_data->GetYaxis()->SetTitle(yAxisTit.c_str());
		       
			 {			    
			    double m1 = hbst_untag->GetMaximum();
			    double m2 = hcst_untag->GetMaximum();
			    double m3 = hlst_data->GetMaximum();
			    double m = m1;
			    if( m2 > m && m2 > m3 ) m = m2;
			    if( m3 > m && m3 > m2 ) m = m3;
			    
			    hbst_untag->SetMaximum(m*1.4);
			    hcst_untag->SetMaximum(m*1.4);
			    hlst_data->SetMaximum(m*1.4);
			 }
		       
		       legOL->Clear();
//		       legOL->AddEntry(hb_untag,"b-jets (Untag)","f");
//		       legOL->AddEntry(hc_untag,"c-jets (Untag)","f");
//		       legOL->AddEntry(hl_data,"Data (Untag)","f");
		       legOL->AddEntry(hb_untag,"b-jets","f");
		       legOL->AddEntry(hc_untag,"c-jets","f");
		       legOL->AddEntry(hl_data,"Data","lp");
		       legOL->Draw();

//		       ATLASLabel(0.20,0.85,"Internal",1);
			 
		       // set doSub to 0 !!
		       fsave = "pics/"+hname+"_ljet_untag_OL_"+sysNameGL+".eps";
		       c1->Print(fsave.c_str());
		       c1->Clear();
		       
		       delete h_ljet_noscale;
		       delete hb;
		       delete hc;
		       delete hl;
		       delete hl_data;
		       delete hb_untag;
		       delete hc_untag;
		       delete hl_data_noscale;
		       delete hb_untag_noscale;
		       delete hc_untag_noscale;
		       
		       delete hbst;
		       delete hcst;
		       delete hlst;
		       delete hlst_data;
		       delete hbst_untag;
		       delete hcst_untag;
		       delete hlst_data_noscale;
		       delete hbst_untag_noscale;
		       delete hcst_untag_noscale;
		       delete legOL;

		       h_draw_ljet_data[iVAR]->SetLineColor(kl);
		       h_draw_ljet_data[iVAR]->SetFillColor(kl);
/*		       
		       h_draw_bjet[iVAR]->SetFillColor(kb);
		       h_draw_cjet[iVAR]->SetFillColor(kc);
		       h_ljet->SetFillColor(kl);
		       h_draw_cljet[iVAR]->SetFillColor(41);
		       h_draw_bjet_untag[iVAR]->SetFillColor(kb);
		       h_draw_cjet_untag[iVAR]->SetFillColor(kc);
*/
		       THStack *h_draw_st_untag = new THStack();
		       
		       h_draw_st_untag->Add(h_ljet);
		       h_draw_st_untag->Add(h_draw_cjet_untag[iVAR]);
		       h_draw_st_untag->Add(h_draw_bjet_untag[iVAR]);
		       
		       h_draw_st_untag->Draw("hist e1");

//		       ATLASLabel(0.20,0.85,"Internal",1);
		       
		       fsave = "pics/"+hname+"_untag_datamc_"+sysNameGL+".eps";
		       c1->Print(fsave.c_str());
		       c1->Clear();
		       
		       delete h_draw_st_untag;

		       if( hnameVAR[iVAR] == mainPTRW ) continue;
		       
		       h_draw_st->Add(h_ljet);
		       h_draw_st->Add(h_draw_cjet[iVAR]);
		       h_draw_st->Add(h_draw_bjet[iVAR]);
		       
		       v_draw_bjet_2dfit.push_back(std::make_pair(h_draw_bjet[iVAR],hnameVAR[iVAR]));
		       v_draw_cjet_2dfit.push_back(std::make_pair(h_draw_cjet[iVAR],hnameVAR[iVAR]));
		       v_draw_ljet_2dfit.push_back(std::make_pair(h_ljet,hnameVAR[iVAR]));
		       v_draw_cljet_2dfit.push_back(std::make_pair(h_draw_cljet[iVAR],hnameVAR[iVAR]));
		       v_draw_ajet_data_2dfit.push_back(std::make_pair(h_draw_ajet_data[iVAR],hnameVAR[iVAR]));
		       
		       v_draw_bcljet_comb_2dfit.push_back(std::make_pair(h_draw_bcljet_comb[iVAR],hnameVAR[iVAR]));
		       v_draw_bcljet_sys_low_combSum_2dfit.push_back(std::make_pair(h_draw_bcljet_sys_low_combSum[iVAR],hnameVAR[iVAR]));
		       v_draw_bcljet_sys_up_combSum_2dfit.push_back(std::make_pair(h_draw_bcljet_sys_up_combSum[iVAR],hnameVAR[iVAR]));		       
		       
		       // 1-D data fit

		       nbins = h_draw_bjet[iVAR]->GetXaxis()->GetNbins();

		       // scale

		       double nbjet = h_draw_bjet[iVAR]->Integral();
		       double ncjet = h_draw_cjet[iVAR]->Integral();
		       double nljet = h_ljet->Integral();

//		       h_draw_bjet[iVAR]->Scale(fracB_MCDEFAULT);
//		       h_draw_cjet[iVAR]->Scale(fracC_MCDEFAULT);
//		       h_ljet->Scale(fracL_MCDEFAULT);
		       
		       h_draw_bjet[iVAR]->Scale(fracB_MCDEFAULT_TRUE);
		       h_draw_cjet[iVAR]->Scale(fracC_MCDEFAULT_TRUE);
		       h_ljet->Scale(fracL_MCDEFAULT_TRUE);

		       h_draw_bjet_true[iVAR]->Scale(fracB_MCDEFAULT_TRUE);
		       h_draw_cjet_true[iVAR]->Scale(fracC_MCDEFAULT_TRUE);
		       h_draw_ljet_true[iVAR]->Scale(fracL_MCDEFAULT_TRUE);
   
		       for(int is=0;is<nsysGL;is++)
			 {			    
			    h_draw_bjet_sys_low[is][iVAR]->Scale(fracB_MCDEFAULT_TRUE);
			    h_draw_cjet_sys_low[is][iVAR]->Scale(fracC_MCDEFAULT_TRUE);
			    h_draw_ljet_sys_low[is][iVAR]->Scale(fracL_MCDEFAULT_TRUE);
			    h_draw_ljet_data_sys_low[is][iVAR]->Scale(fracL_MCDEFAULT_TRUE);

			    h_draw_bjet_sys_up[is][iVAR]->Scale(fracB_MCDEFAULT_TRUE);
			    h_draw_cjet_sys_up[is][iVAR]->Scale(fracC_MCDEFAULT_TRUE);
			    h_draw_ljet_sys_up[is][iVAR]->Scale(fracL_MCDEFAULT_TRUE);
			    h_draw_ljet_data_sys_up[is][iVAR]->Scale(fracL_MCDEFAULT_TRUE);
			    
//			    h_draw_bjet_sys_low[is][iVAR]->Scale(fracB_MCDEFAULT);
//			    h_draw_cjet_sys_low[is][iVAR]->Scale(fracC_MCDEFAULT);
//			    h_draw_ljet_sys_low[is][iVAR]->Scale(fracL_MCDEFAULT);
//			    h_draw_ljet_data_sys_low[is][iVAR]->Scale(fracL_MCDEFAULT);

//			    h_draw_bjet_sys_up[is][iVAR]->Scale(fracB_MCDEFAULT);
//			    h_draw_cjet_sys_up[is][iVAR]->Scale(fracC_MCDEFAULT);
//			    h_draw_ljet_sys_up[is][iVAR]->Scale(fracL_MCDEFAULT);
//			    h_draw_ljet_data_sys_up[is][iVAR]->Scale(fracL_MCDEFAULT);
			 }		       

		       applySys(iVARcur,
				hname_bjet_cur,
				hname_cjet_cur,
				hname_ljet_cur,
				hname_ajet_cur,
				hname_ljet_data_cur,
				1.,
				1.,
				1.,
				0.,
				0.,
				0.,
			        false,
				true);

		       if( doFracFit )
			 {
			    doFitFractionFitter(parval,parerr,chis);
			 }		       
		       else
			 {			    
			    // FIXME
//			    if( doCL )
//			      doFitCL(parval,parerr,chis);
//			    else

			    doFit(parval,parerr,chis,nbjet,ncjet,nljet);
		       
			    //		       covMI.Print();
//			    std::cout << covMI.Determinant() << std::endl;
			 }		       
		       
		       if( hnameVAR[iVAR] == mainFIT )
			 {
			    p1FIT = parval[0];
			    p1FITerr = parerr[0];
			    p2FIT = parval[1];
			    p2FITerr = parerr[1];
			    p3FIT = parval[2];
			    p3FITerr = parerr[2];
			    chisMain[0] = chis[0];
			    chisMain[1] = chis[1];
			 }

		       // after 1-D fit
		       
		       if( doCL )
			 {			    
			    applySF("1dfit",
				    hnameVAR[iVAR],
				    hnamePT[iPT],
				    hnameETA[iETA],
				    hnameBTAG[iBTAG],
				    iVAR,
				    iPT,
				    h_draw_bjet[iVAR],
				    h_draw_cjet[iVAR],
				    h_ljet,
				    h_draw_bjet_true[iVAR],
				    h_draw_cjet_true[iVAR],
				    h_draw_ljet_true[iVAR],
				    h_draw_ajet_data[iVAR],
				    h_draw_bcljet_comb[iVAR],
				    h_draw_bcljet_sys_up_combSum[iVAR],
				    h_draw_bcljet_sys_low_combSum[iVAR],
				    leg,
				    parval[0],
				    parval[1],
				    parval[1],
				    parerr[0],
				    parerr[1],
				    parerr[1],
				    chis[0],
				    chis[1]);
			 }		       
		       else
			 {
			    if( !doFracFit )
			      {				 
				 applySys(iVAR,
					  hname_bjet,
					  hname_cjet,
					  hname_ljet,
					  hname_ajet,
					  hname_ljet_data,
					  parval[0],
					  parval[1],
					  parval[2],
					  parerr[0],
					  parerr[1],
					  parerr[2],
					  0.,true);

				 applySF("1dfit",
					 hnameVAR[iVAR],
					 hnamePT[iPT],
					 hnameETA[iETA],
					 hnameBTAG[iBTAG],
					 iVAR,
					 iPT,
					 h_draw_bjet[iVAR],
					 h_draw_cjet[iVAR],
					 h_ljet,
					 h_draw_bjet_true[iVAR],
					 h_draw_cjet_true[iVAR],
					 h_draw_ljet_true[iVAR],
					 h_draw_ajet_data[iVAR],
					 h_draw_bcljet_comb[iVAR],
					 h_draw_bcljet_sys_up_combSum[iVAR],
					 h_draw_bcljet_sys_low_combSum[iVAR],
					 leg,
					 parval[0],
					 parval[1],
					 parval[2],
					 parerr[0],
					 parerr[1],
					 parerr[2],
					 chis[0],
					 chis[1]);
			      }
			    else
			      {
				 applySys(iVAR,
					  hname_bjet,
					  hname_cjet,
					  hname_ljet,
					  hname_ajet,
					  hname_ljet_data,
					  parval[0]/fracB_MCDEFAULT,
					  parval[1]/fracC_MCDEFAULT,
					  parval[2]/fracL_MCDEFAULT,
					  parerr[0]/fracB_MCDEFAULT,
					  parerr[1]/fracC_MCDEFAULT,
					  parerr[2]/fracL_MCDEFAULT,
					  0.,true);
				 
				 applySF("1dfit",
					 hnameVAR[iVAR],
					 hnamePT[iPT],
					 hnameETA[iETA],
					 hnameBTAG[iBTAG],
					 iVAR,
					 iPT,
					 h_draw_bjet[iVAR],
					 h_draw_cjet[iVAR],
					 h_ljet,
					 h_draw_bjet_true[iVAR],
					 h_draw_cjet_true[iVAR],
					 h_draw_ljet_true[iVAR],
					 h_draw_ajet_data[iVAR],
					 h_draw_bcljet_comb[iVAR],
					 h_draw_bcljet_sys_up_combSum[iVAR],
					 h_draw_bcljet_sys_low_combSum[iVAR],
					 leg,
					 parval[0]/fracB_MCDEFAULT,
					 parval[1]/fracC_MCDEFAULT,
					 parval[2]/fracL_MCDEFAULT,
					 parerr[0]/fracB_MCDEFAULT,
					 parerr[1]/fracC_MCDEFAULT,
					 parerr[2]/fracL_MCDEFAULT,
					 chis[0],
					 chis[1]);				 
			      }
			 }

		       delete h_draw_st;
		       
		    } // end VAR loop 
		  
		  // RUN OVER 2D DISTRIBUTIONS
/*
		  for(int iVAR2D=0;iVAR2D<hnnVAR2D;iVAR2D++)
		    {	
		       c1->Clear();
		       
		       h_draw_bjet_2d[iVAR2D] = new TH2F();
		       h_draw_cjet_2d[iVAR2D] = new TH2F();
		       h_draw_ljet_2d[iVAR2D] = new TH2F();
		       h_draw_ljet_data_2d[iVAR2D] = new TH2F();
		       h_draw_cljet_2d[iVAR2D] = new TH2F();
		       h_draw_bjet_untag_2d[iVAR2D] = new TH2F();
		       h_draw_cjet_untag_2d[iVAR2D] = new TH2F();
		       
		       h_draw_ajet_data_2d[iVAR2D] = new TH2F();
		       
		       std::string hname_bjet = hnameVAR2D[iVAR2D] + hnameFLAV[0] + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];
		       std::string hname_cjet = hnameVAR2D[iVAR2D] + hnameFLAV[1] + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];
		       std::string hname_ljet = hnameVAR2D[iVAR2D] + hnameFLAV[2] + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];
		       std::string hname_ljet_data = hnameVAR2D[iVAR2D] + "ajet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + "_" + untag;
		       std::string hname = hnameVAR2D[iVAR2D] + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];
		       std::string hname_bjet_untag = hnameVAR2D[iVAR2D] + "bjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + "_" + untag;
		       std::string hname_cjet_untag = hnameVAR2D[iVAR2D] + "cjet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + "_" + untag;

		       std::string hname_ajet = hnameVAR2D[iVAR2D] + "ajet_" + hnamePT[iPT] + "_" + hnameETA[iETA] + hnameBTAG[iBTAG];
		       
		       std::vector<std::string> vstr = setTit(hnameVAR2D[iVAR2D]);
		       std::string xAxisTit = vstr.at(0);
		       std::string yAxisTit = vstr.at(1);
		       
		       readData2D(iVAR2D,
				  hname_bjet,
				  hname_cjet,
				  hname_ljet,
				  hname_ajet,
				  hname_ljet_data,
				  hname_bjet_untag,
				  hname_cjet_untag,
				  v_mc_filt,
				  v_mc_unfilt,
				  v_data);
		       
		       applySys2DIM(iVAR2D,
				    hname_bjet,
				    hname_cjet,
				    hname_ljet,
				    hname_ajet,
				    hname_ljet_data,
				    1.,
				    1.,
				    1.,
				    0.,
				    0.,
				    0.,
				    false);

		       TH2F *h_ljet_2d;
		       if( ljetData == 0 )
			 h_ljet_2d = h_draw_ljet_2d[iVAR2D];
		       else
			 h_ljet_2d = h_draw_ljet_data_2d[iVAR2D];
		  
		       h_draw_bjet_2d[iVAR2D]->SetLineColor(kb);
		       h_draw_cjet_2d[iVAR2D]->SetLineColor(kc);
		       h_ljet_2d->SetLineColor(kl);
		       h_draw_cljet_2d[iVAR2D]->SetLineColor(41);
		       
		       h_draw_bjet_2d[iVAR2D]->SetMarkerSize(0);
		       h_draw_cjet_2d[iVAR2D]->SetMarkerSize(0);
		       h_ljet_2d->SetMarkerSize(0);
		       h_draw_cljet_2d[iVAR2D]->SetMarkerSize(0);
		       
		       c1->Clear();

//		  addbin2D(h_draw_bjet_2d[iVAR2D]);
//		  addbin2D(h_draw_cjet_2d[iVAR2D]);
//		  addbin2D(h_draw_ljet_2d[iVAR2D]);
//		  addbin2D(h_draw_cljet_2d[iVAR2D]);
		  
//		  addbin2D(h_draw_ajet_data_2d[iVAR2D]);
*/		  
/*		       TLegend *legOL = new TLegend(0.75,0.30,0.90,0.20);
		       legOL->SetFillColor(253);
		       legOL->SetBorderSize(0);
		       
		       double integ = 
			 h_ljet_2d->Integral(0,h_ljet_2d->GetXaxis()->GetNbins()+1,
					     0,h_ljet_2d->GetYaxis()->GetNbins()+1) +
			 h_draw_cjet_2d[iVAR2D]->Integral(0,h_draw_cjet_2d[iVAR2D]->GetXaxis()->GetNbins()+1,
							  0,h_draw_cjet_2d[iVAR2D]->GetYaxis()->GetNbins()+1) +
			 h_draw_bjet_2d[iVAR2D]->Integral(0,h_draw_bjet_2d[iVAR2D]->GetXaxis()->GetNbins()+1,
							  0,h_draw_bjet_2d[iVAR2D]->GetYaxis()->GetNbins()+1);
		       
		       if( integ > 0 ) h_ljet_2d->Scale(1./integ);
		       if( integ > 0 ) h_draw_cjet_2d[iVAR2D]->Scale(1./integ);
		       if( integ > 0 ) h_draw_bjet_2d[iVAR2D]->Scale(1./integ);
		       
		       if( h_draw_ajet_data_2d[iVAR2D]->Integral(0,h_draw_ajet_data_2d[iVAR2D]->GetXaxis()->GetNbins()+1,
								 0,h_draw_ajet_data_2d[iVAR2D]->GetYaxis()->GetNbins()+1) > 0 ) 
			 h_draw_ajet_data_2d[iVAR2D]->Scale(1./h_draw_ajet_data_2d[iVAR2D]->Integral(0,h_draw_ajet_data_2d[iVAR2D]->GetXaxis()->GetNbins()+1,
												     0,h_draw_ajet_data_2d[iVAR2D]->GetYaxis()->GetNbins()+1));
*/		       
/*		       TH2F *h_ljet_2DIM = (TH2F*)h_ljet_2d->Clone("h_ljet_2DIM");
		       TH2F *h_cjet_2DIM = (TH2F*)h_draw_cjet_2d[iVAR2D]->Clone("h_cjet_2DIM");
		       TH2F *h_bjet_2DIM = (TH2F*)h_draw_bjet_2d[iVAR2D]->Clone("h_bjet_2DIM");
		       TH2F *h_cljet_2DIM = (TH2F*)h_draw_cljet_2d[iVAR2D]->Clone("h_cljet_2DIM");
		       TH2F *h_ajet_data_2DIM = (TH2F*)h_draw_ajet_data_2d[iVAR2D]->Clone("h_ajet_data_2DIM");*/
/*		       
		       h_draw_bjet_2d[iVAR2D]->Draw("BOX");		  
		       legOL->AddEntry(h_draw_bjet_2d[iVAR2D],"Beauty","f");
		       double cfc = h_draw_bjet_2d[iVAR2D]->GetCorrelationFactor();
		       TLatex cfcl;
		       cfcl.SetTextSize(0.04);
		       cfcl.DrawLatex(0.1,0.5,Form("#rho_{c} = %.2f",cfc));
		       h_draw_bjet_2d[iVAR2D]->SetTitle("");
		       h_draw_bjet_2d[iVAR2D]->GetXaxis()->SetTitle(xAxisTit.c_str());
		       h_draw_bjet_2d[iVAR2D]->GetYaxis()->SetTitle(yAxisTit.c_str());
		       legOL->Draw();		  
		       std::string fsave = "pics/"+hname+"_bjet_mc.eps";		  
		       c1->Print(fsave.c_str());
		       c1->Clear();
		       legOL->Clear();
		       
		       h_draw_cjet_2d[iVAR2D]->Draw("BOX");		  
		       legOL->AddEntry(h_draw_cjet_2d[iVAR2D],"Charm","f");
		       h_draw_cjet_2d[iVAR2D]->SetTitle("");
		       h_draw_cjet_2d[iVAR2D]->GetXaxis()->SetTitle(xAxisTit.c_str());
		       h_draw_cjet_2d[iVAR2D]->GetYaxis()->SetTitle(yAxisTit.c_str());
		       legOL->Draw();		  
		       fsave = "pics/"+hname+"_cjet_mc.eps";
		       c1->Print(fsave.c_str());
		       c1->Clear();
		       legOL->Clear();
		       
		       h_ljet_2d->Draw("BOX");
		       legOL->AddEntry(h_ljet_2d,"Light","f");
		       h_ljet_2d->SetTitle("");
		       h_ljet_2d->GetXaxis()->SetTitle(xAxisTit.c_str());
		       h_ljet_2d->GetYaxis()->SetTitle(yAxisTit.c_str());
		       legOL->Draw();		  
		       fsave = "pics/"+hname+"_ljet_mc.eps";
		       c1->Print(fsave.c_str());
		       c1->Clear();
		       legOL->Clear();

		       h_draw_cljet_2d[iVAR2D]->Draw("BOX");		  
		       legOL->AddEntry(h_draw_cljet_2d[iVAR2D],"Non-beauty","f");
		       h_draw_cljet_2d[iVAR2D]->SetTitle("");
		       h_draw_cljet_2d[iVAR2D]->GetXaxis()->SetTitle(xAxisTit.c_str());
		       h_draw_cljet_2d[iVAR2D]->GetYaxis()->SetTitle(yAxisTit.c_str());
		       legOL->Draw();		  
		       fsave = "pics/"+hname+"_cljet_mc.eps";
		       c1->Print(fsave.c_str());
		       c1->Clear();
		       legOL->Clear();
		       
		       delete legOL;		  
*/		  
		       // 2-D data fit

//		       nbins2dx = h_bjet_2DIM->GetXaxis()->GetNbins();
//		       nbins2dy = h_bjet_2DIM->GetYaxis()->GetNbins();
/*		  
		  double integComb = h_draw_bcljet_comb_2d[iVAR2D]->Integral(0,h_draw_bcljet_comb_2d[iVAR2D]->GetXaxis()->GetNbins()+1,
									     0,h_draw_bcljet_comb_2d[iVAR2D]->GetYaxis()->GetNbins()+1);
		  if( integComb > 0 ) h_draw_bcljet_comb_2d[iVAR2D]->Scale(1./integComb);

		  double integCombUp = h_draw_bcljet_sys_up_combSum_2d[iVAR2D]->Integral(0,h_draw_bcljet_sys_up_combSum_2d[iVAR2D]->GetXaxis()->GetNbins()+1,											 
											 0,h_draw_bcljet_sys_up_combSum_2d[iVAR2D]->GetYaxis()->GetNbins()+1);
		  if( integCombUp > 0 ) h_draw_bcljet_sys_up_combSum_2d[iVAR2D]->Scale(1./integCombUp);

		  double integCombLow = h_draw_bcljet_sys_low_combSum_2d[iVAR2D]->Integral(0,h_draw_bcljet_sys_low_combSum_2d[iVAR2D]->GetXaxis()->GetNbins()+1,
											   0,h_draw_bcljet_sys_low_combSum_2d[iVAR2D]->GetYaxis()->GetNbins()+1);
		  if( integCombLow > 0 ) h_draw_bcljet_sys_low_combSum_2d[iVAR2D]->Scale(1./integCombLow);
 */
/*		       for(int ibx=0;ibx<=h_draw_bcljet_comb_2d[iVAR2D]->GetXaxis()->GetNbins()+1;ibx++)
			 {
			    for(int iby=0;iby<=h_draw_bcljet_comb_2d[iVAR2D]->GetYaxis()->GetNbins()+1;iby++)
			      {			    
				 double downerr = h_draw_bcljet_comb_2d[iVAR2D]->GetBinContent(ibx,iby)-
				   h_draw_bcljet_sys_low_combSum_2d[iVAR2D]->GetBinContent(ibx,iby);
				 double uperr = h_draw_bcljet_sys_up_combSum_2d[iVAR2D]->GetBinContent(ibx,iby)-
				   h_draw_bcljet_comb_2d[iVAR2D]->GetBinContent(ibx,iby);
				 double staterr = sqrt(pow(h_draw_bjet_2d[iVAR2D]->GetBinError(ibx,iby),2)+
						       pow(h_draw_cjet_2d[iVAR2D]->GetBinError(ibx,iby),2)+
						       pow(h_draw_ljet_2d[iVAR2D]->GetBinError(ibx,iby),2));
				 if( ((downerr-staterr)<-10E-8 || (uperr-staterr)<-10E-8) && nsys > 0 )
				   std::cout << "bin#" << ibx << "," << iby<< ": DOWN=" << downerr << 
				   " UP=" << uperr << " STAT=" << staterr << std::endl;
			      }		       
			 }		  
		       
		       for(int ibx=1;ibx<nbins2dx+1;ibx++)
			 {
			    for(int iby=1;iby<nbins2dy+1;iby++)
			      {
				 mc_bjet_2d[ibx-1][iby-1] = h_bjet_2DIM->GetBinContent(ibx,iby);
				 mc_bjet_err_2d[ibx-1][iby-1] = h_bjet_2DIM->GetBinError(ibx,iby);
				 mc_cjet_2d[ibx-1][iby-1] = h_cjet_2DIM->GetBinContent(ibx,iby);
				 mc_cjet_err_2d[ibx-1][iby-1] = h_cjet_2DIM->GetBinError(ibx,iby);
				 mc_ljet_2d[ibx-1][iby-1] = h_ljet_2DIM->GetBinContent(ibx,iby);
				 mc_ljet_err_2d[ibx-1][iby-1] = h_ljet_2DIM->GetBinError(ibx,iby);
				 mc_cljet_2d[ibx-1][iby-1] = h_cljet_2DIM->GetBinContent(ibx,iby);
				 mc_cljet_err_2d[ibx-1][iby-1] = h_cljet_2DIM->GetBinError(ibx,iby);
				 data_2d[ibx-1][iby-1] = h_ajet_data_2DIM->GetBinContent(ibx,iby);
				 data_err_2d[ibx-1][iby-1] = h_ajet_data_2DIM->GetBinError(ibx,iby);
				 //			    errorz_2d[ibx-1][iby-1] = sqrt(pow(mc_bjet_err_2d[ibx-1][iby-1],2) +
				 //							   pow(mc_cjet_err_2d[ibx-1][iby-1],2) +
				 //							   pow(mc_ljet_err_2d[ibx-1][iby-1],2) +
				 //							   pow(data_err_2d[ibx-1][iby-1],2));
				 mc_bcljet_2d[ibx-1][iby-1] = h_draw_bcljet_comb_2d[iVAR2D]->GetBinContent(ibx,iby);
				 double up = h_draw_bcljet_sys_up_combSum_2d[iVAR2D]->GetBinContent(ibx,iby) - 
				   mc_bcljet_2d[ibx-1][iby-1];
				 double down = mc_bcljet_2d[ibx-1][iby-1] -
				   h_draw_bcljet_sys_low_combSum_2d[iVAR2D]->GetBinContent(ibx,iby);
				 double err = (up+down)/2.;
				 errorz_2d[ibx-1][iby-1] = sqrt(pow(data_err_2d[ibx-1][iby-1],2)+
								pow(err,2));
			      }	     
			 }		  
		       
		       doFit2DIM(parval2DIM,parerr2DIM,chis2DIM);
		       
		    } // end VAR2D loop

		  // apply 2DIM fit

		  for(int ivh=0;ivh<v_draw_bjet_2dfit.size();ivh++)
		    {	     	
		       std::string varName = v_draw_bjet_2dfit.at(ivh).second;

		       applySys(ivh,
				v_draw_bjet_2dfit.at(ivh).second,
				v_draw_cjet_2dfit.at(ivh).second,
				v_draw_ljet_2dfit.at(ivh).second,
				"",
				v_draw_ljet_2dfit.at(ivh).second,
				parval2DIM[0],
				parval2DIM[1],
				parval2DIM[2],
				parerr2DIM[0],
				parerr2DIM[1],
				parerr2DIM[2],
				true);
		       
		       applySF("2DIMfit",
			       varName,
			       hnamePT[iPT],
			       hnameETA[iETA],
			       hnameBTAG[iBTAG],
			       ivh,
			       iPT,
			       v_draw_bjet_2dfit.at(ivh).first,
			       v_draw_cjet_2dfit.at(ivh).first,
			       v_draw_ljet_2dfit.at(ivh).first,
			       v_draw_ajet_data_2dfit.at(ivh).first,
			       v_draw_bcljet_comb_2dfit.at(ivh).first,
			       v_draw_bcljet_sys_up_combSum_2dfit.at(ivh).first,
			       v_draw_bcljet_sys_low_combSum_2dfit.at(ivh).first,
			       leg,
			       parval2DIM[0],
			       parval2DIM[1],
			       parval2DIM[2],
			       parerr2DIM[0],
			       parerr2DIM[1],
			       parerr2DIM[2],
			       chis2DIM[0],
			       chis2DIM[1]);
		    }	     
*/		  
		  for(int ivh=0;ivh<v_draw_bjet_2dfit.size();ivh++)
		    {	     	
		       std::string varName = v_draw_bjet_2dfit.at(ivh).second;
		    }	     
	     
		  for(int iv=0;iv<hnnVAR;iv++)
		    {	     
		       delete h_draw_bjet[iv];
		       delete h_draw_bjet_posttag[iv];
		       delete h_draw_cjet_posttag[iv];
		       delete h_draw_ljet_posttag[iv];
		       delete h_draw_ajet_data_posttag[iv];
		       delete h_draw_bjet_notag[iv];
		       delete h_draw_cjet_notag[iv];
		       delete h_draw_ljet_notag[iv];
		       delete h_draw_ajet_data_notag[iv];
		       delete h_draw_cjet[iv];
		       delete h_draw_ljet[iv];
		       delete h_draw_ljet_data[iv];
		       delete h_draw_cljet[iv];
		       
		       delete h_draw_ajet_data[iv];
		       
		       delete h_draw_bjet_untag[iv];
		       delete h_draw_cjet_untag[iv];
		       
		       delete h_draw_bjet_sys_low_comb[iv];
		       delete h_draw_cjet_sys_low_comb[iv];
		       delete h_draw_ljet_sys_low_comb[iv];
		       delete h_draw_ljet_data_sys_low_comb[iv];

		       delete h_draw_bjet_sys_up_comb[iv];
		       delete h_draw_cjet_sys_up_comb[iv];		       
		       delete h_draw_ljet_sys_up_comb[iv];
		       delete h_draw_ljet_data_sys_up_comb[iv];

		       delete h_draw_bcljet_comb[iv];
		       delete h_draw_bcljet_combNATURAL[iv];
		       
		       delete h_draw_bjet_sys_low_combSum[iv];
		       delete h_draw_cjet_sys_low_combSum[iv];
		       delete h_draw_ljet_sys_low_combSum[iv];
		       delete h_draw_ljet_data_sys_low_combSum[iv];
		       delete h_draw_bcljet_sys_low_combSum[iv];

		       delete h_draw_bjet_sys_up_combSum[iv];
		       delete h_draw_cjet_sys_up_combSum[iv];
		       delete h_draw_ljet_sys_up_combSum[iv];
		       delete h_draw_ljet_data_sys_up_combSum[iv];
		       delete h_draw_bcljet_sys_up_combSum[iv];
		       
		       for(int is=0;is<nsysGL;is++)
			 {
			    delete h_draw_bcljet_sys_low_comb[iv*nsysGL+is];
			    delete h_draw_bcljet_sys_up_comb[iv*nsysGL+is];

			    delete h_draw_bcljet_sys_low_combNATURAL[iv*nsysGL+is];
			    delete h_draw_bcljet_sys_up_combNATURAL[iv*nsysGL+is];
			    
			    delete h_draw_ljet_data_sys_low[is][iv];			    
			    delete h_draw_bjet_sys_low[is][iv];
			    delete h_draw_cjet_sys_low[is][iv];
			    delete h_draw_ljet_sys_low[is][iv];
			    delete h_draw_bjet_untag_sys_low[is][iv];
			    delete h_draw_cjet_untag_sys_low[is][iv];
			    delete h_draw_bjet_posttag_sys_low[is][iv];
			    delete h_draw_cjet_posttag_sys_low[is][iv];

			    delete h_draw_ljet_data_sys_up[is][iv];			    
			    delete h_draw_bjet_sys_up[is][iv];
			    delete h_draw_cjet_sys_up[is][iv];
			    delete h_draw_ljet_sys_up[is][iv];
			    delete h_draw_bjet_untag_sys_up[is][iv];
			    delete h_draw_cjet_untag_sys_up[is][iv];
			    delete h_draw_bjet_posttag_sys_up[is][iv];
			    delete h_draw_cjet_posttag_sys_up[is][iv];
			 }
		    }		  
		  
		  delete gMinuit;
		  
		  if( fcov->IsOpen() ) fcov->Close();

/*		  TList * openFileList = (TList*) gROOT->GetListOfFiles();
		  std::string fcl[1000];
		  int ifile = 0;
		  for (Int_t iFile = 0; iFile < openFileList->GetEntries(); iFile++)
		    {
		       fcl[iFile] = openFileList->At(iFile)->GetName();
		       ifile++;
		    }
		  for(int ie=0;ie<ifile;ie++)
		    {
		       TFile * currFile = (TFile*) openFileList->FindObject(fcl[ie].c_str());
		       currFile->Close();
		    }*/
		  
	       } // end PTBIN loop
	     fsys.close();
	  } // end ETABIN loop	
     } // end BTAG loop

   closeData(0,
	     0,
	     v_mc_filt,
	     v_mc_unfilt,
	     v_data);
   
   fout.close();
   foutSys.close();
}
