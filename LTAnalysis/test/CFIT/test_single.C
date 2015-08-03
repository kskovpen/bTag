void getResults(CFIT::cfit *cf,float *par,float *err);

void test_single()
{
   gROOT->SetBatch();

   float par_notag[100];
   float err_notag[100];

   float par_tag[100];
   float err_tag[100];
   
   // create an instance of CFIT
   CFIT::cfit *cf = new CFIT::cfit();
   // no verbose
   cf->SilentMode();
   // set systematics correlation optimization
   cf->SetOptimization(OPT_MORPH_SGN_SIGMA);
   // set morphing for systematic correlations
   // NOTE: applied only if optimization with morphing is selected above
   cf->SetMorphing(OPTMORPH_GEOMETRIC);
//   cf->SetMorphing(OPTMORPH_CUTOFF);
   // produce plots with results
   cf->ProducePlots();
   
   // input file
   cf->SetInputFile("../histCFIT/data.root");

   // systematics
   cf->AddSys("NTRK","_ntrk_down","_ntrk_up");
   cf->AddSys("NJET","_njet_down","_njet_up");
   cf->AddSys("MUPT","_mupt_down","_mupt_up");
   cf->AddSys("JETA","_jeta_down","_jeta_up");
   cf->AddSys("PU","_pu_down","_pu_up");
   cf->AddSys("GSPLIT","_gsplit_down","_gsplit_up");
   cf->AddSys("BFRAG","_bfrag_down","_bfrag_up");
   cf->AddSys("CDFRAG","_cdfrag_down","_cdfrag_up");
   cf->AddSys("CFRAG","_cfrag_down","_cfrag_up");
   cf->AddSys("KSL","_ksl_down","_ksl_up");
   cf->AddSys("NTRKGEN","_ntrkgen_down","_ntrkgen_up");
   cf->AddSys("JES","_jes_down","_jes_up");
   cf->AddSys("JER","_jer_down","_jer_up");

   // write/read correlation matrix to/from file
   cf->SetMatrixOption("WRITE");
   
   cf->SetSysVariation("_bfrag_down");

   // input histograms
   
   cf->SetData("h_j1_JP_ajet_pt320t400_nosel_nosel__DATA");
   
   cf->AddTemplate("b-jets","h_j1_JP_bjet_pt320t400_nosel_nosel");
   cf->AddTemplate("c-jets","h_j1_JP_cjet_pt320t400_nosel_nosel");
   cf->AddTemplate("udsg-jets","h_j1_JP_ljet_pt320t400_nosel_nosel");

   cf->Run();
   
   getResults(cf,par_notag,err_notag);
   float chi2_notag = cf->GetChisq();
   float ndata_notag = cf->GetNData();
   float nmcb_notag = cf->GetNTemplate("b-jets");
   float nmc_notag = cf->GetNTemplate("b-jets")+cf->GetNTemplate("c-jets")+cf->GetNTemplate("udsg-jets");

   // print results
   
   std::cout << "notag chi2=" << chi2_notag << std::endl;
   for(int i=0;i<3;i++)
     {
	std::cout << par_notag[i] << " +- " << err_notag[i] << std::endl;
     }   

   gApplication->Terminate();
}

// get fitted parameters from CFIT
void getResults(CFIT::cfit *cf,float *par,float *err)
{   
   float chi2 = cf->GetChisq();
   int nPar = cf->GetNPar();
   for(int i=0;i<nPar;i++)
     {
	par[i] = cf->GetPar(i);
	err[i] = cf->GetParErr(i);	
     }
}
