void getResults(CFIT::cfit *cf,float *par,float *err);

void test2()
{
   gROOT->SetBatch();

   float par[100];
   float err[100];
   
   // create an instance of CFIT
   CFIT::cfit *cf = new CFIT::cfit();
   // no verbose
   cf->SilentMode();
   // set systematics correlation optimization
   cf->SetOptimization(OPT_MORPH_SGN_SIGMA);
   // set morphing for systematic correlations
   // NOTE: applied only if optimization with morphing is selected above
   cf->SetMorphing(OPTMORPH_GEOMETRIC);
   // produce plots with results
   cf->ProducePlots();
   
   // input file
   cf->SetInputFile("input2.root");

   // systematics
   cf->AddSys("SYS1","_sys1_down","_sys1_up");
   cf->AddSys("SYS2","_sys2_down","_sys2_up");

   // write/read correlation matrix to/from file
   cf->SetMatrixOption("WRITE");

   // input histograms
   
   cf->SetData("data");
   
   cf->AddTemplate("sample1","h0");
   cf->AddTemplate("sample2","h1");
   cf->AddTemplate("sample3","h2");

   cf->Run();
   
   getResults(cf,par,err);
   float chi2 = cf->GetChisq();
   
   // print results
   
   std::cout << "chi2=" << chi2 << std::endl;
   for(int i=0;i<3;i++)
     {
	std::cout << par[i] << " +- " << err[i] << std::endl;
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
