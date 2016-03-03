#include "cfit.h"

void getResults(CFIT::cfit *cf,float *par,float *err);

int main()
{
   float par_notag[100];
   float err_notag[100];

   float par_tag[100];
   float err_tag[100];

   CFIT::cfit *cf = new CFIT::cfit();

   // verbose
   cf->SetVerbose(0);
   // set systematics correlation optimization
//   cf->SetOptimization(OPT_MORPH_SGN_SIGMA);
   // set morphing for systematic correlations
   // NOTE: applied only if optimization with morphing is selected above
   //   cf->SetMorphing(OPTMORPH_GEOMETRIC);
//   cf->SetMorphing(OPTMORPH_CUTOFF,0.5);
//   cf->SetCovarianceMode(COV_BARLOW);
//   cf->SetCovarianceMode(COV_MAX);
   // produce plots with results
   cf->ProducePlots(1);
   
   // input file
   cf->SetInputFile("test.root");
   
   // systematics
//   cf->AddSys("NTRK","_ntrk_down","_ntrk_up");
//   cf->AddSys("NJET","_njet_down","_njet_up");
//   cf->AddSys("MUPT","_mupt_down","_mupt_up");
//   cf->AddSys("JETA","_jeta_down","_jeta_up");
//   cf->AddSys("PU","_pu_down","_pu_up");
//   cf->AddSys("GSPLIT","_gsplit_down","_gsplit_up");
//   cf->AddSys("BFRAG","_bfrag_down","_bfrag_up");
//   cf->AddSys("CDFRAG","_cdfrag_down","_cdfrag_up");
//   cf->AddSys("CFRAG","_cfrag_down","_cfrag_up");
//   cf->AddSys("KSL","_ksl_down","_ksl_up");
//   cf->AddSys("NTRKGEN","_ntrkgen_down","_ntrkgen_up");
//   cf->AddSys("JES","_jes_down","_jes_up");
//   cf->AddSys("JER","_jer_down","_jer_up");

   // input histograms

   cf->SetData("h_data_art");
   cf->SetDataTag("h_data_art_tag");
   cf->SetDataUntag("h_data_art_untag");
   
   cf->AddTemplate("b-jets","h_mc1");
   cf->AddTemplate("c-jets","h_mc2");
   cf->AddTemplate("udsg-jets","h_mc3");
   
   cf->AddTemplateTag("b-jets","h_mc1_tag");
   cf->AddTemplateTag("c-jets","h_mc2_tag");
   cf->AddTemplateTag("udsg-jets","h_mc3_tag");
   
   cf->AddTemplateUntag("b-jets","h_mc1_untag");
   cf->AddTemplateUntag("c-jets","h_mc2_untag");
   cf->AddTemplateUntag("udsg-jets","h_mc3_untag");

   float sf[1000];
   float effmc[1000];
   float effdata[1000];

   int nIter = 20;
   
   for(int i=0;i<nIter;i++)
//   while(1)
     {
//	usleep(10000);
	// create an instance of CFIT
//	CFIT::cfit *cf = new CFIT::cfit();
	
	// verbose
/*	cf->SetVerbose(1);
	// set systematics correlation optimization
	cf->SetOptimization(OPT_MORPH_SGN_SIGMA);
	// set morphing for systematic correlations
	// NOTE: applied only if optimization with morphing is selected above
	//   cf->SetMorphing(OPTMORPH_GEOMETRIC);
	cf->SetMorphing(OPTMORPH_CUTOFF);
	// produce plots with results
	cf->ProducePlots();
   
	// input file
	cf->SetInputFile("../../histCFIT/data.root");
	
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
*/	
	// write/read correlation matrix to/from file
//	cf->SetMatrixOption("READ");
//	cf->SetMatrixOption("WRITE");

	// input histograms

/*	cf->SetData("h_j1_JP_ajet_pt320t400_nosel_nosel__DATA");
	cf->SetDataTag("h_j1_JP_ajet_pt320t400_nosel_CSVL__DATA");
	cf->SetDataUntag("h_j1_JP_ajet_pt320t400_nosel_UNTAGCSVL__DATA");
   
	cf->AddTemplate("b-jets","h_j1_JP_bjet_pt320t400_nosel_nosel");
	cf->AddTemplate("c-jets","h_j1_JP_cjet_pt320t400_nosel_nosel");
	cf->AddTemplate("udsg-jets","h_j1_JP_ljet_pt320t400_nosel_nosel");
	
	cf->AddTemplateTag("b-jets","h_j1_JP_bjet_pt320t400_nosel_CSVL");
	cf->AddTemplateTag("c-jets","h_j1_JP_cjet_pt320t400_nosel_CSVL");
	cf->AddTemplateTag("udsg-jets","h_j1_JP_ljet_pt320t400_nosel_CSVL");
	
	cf->AddTemplateUntag("b-jets","h_j1_JP_bjet_pt320t400_nosel_UNTAGCSVL");
	cf->AddTemplateUntag("c-jets","h_j1_JP_cjet_pt320t400_nosel_UNTAGCSVL");
	cf->AddTemplateUntag("udsg-jets","h_j1_JP_ljet_pt320t400_nosel_UNTAGCSVL");
*/	
	// set systematic or statistic variation in the templates
	//   cf->SetStatVariation(666);
//	cf->SetSysVariation("_gsplit_up");
	
	if( i > 0 ) cf->SetStatVariation(665+i);
	
	// pre-tag fit

	cf->Run();
	
	getResults(cf,par_notag,err_notag);
	float chi2_notag = cf->GetChisq();
	float ndata_notag = cf->GetNData();
	float nmcb_notag = cf->GetNTemplate("b-jets");
	float nmc_notag = cf->GetNTemplate("b-jets")+cf->GetNTemplate("c-jets")+cf->GetNTemplate("udsg-jets");
//   float nmc_notag = cf->GetNTemplate("b-jets");
//	float nmc_notag = cf->GetNTemplate("b-jets")+cf->GetNTemplate("c-jets");

	// post-tag fit

	if( i > 0 ) cf->SetStatVariation(665+i);
	
	cf->Run("tag");
	
	getResults(cf,par_tag,err_tag);
	float chi2_tag = cf->GetChisq();
	float ndata_tag = cf->GetNData();
	float nmcb_tag = cf->GetNTemplate("b-jets");
	float nmc_tag = cf->GetNTemplate("b-jets")+cf->GetNTemplate("c-jets")+cf->GetNTemplate("udsg-jets");
//   float nmc_tag = cf->GetNTemplate("b-jets");
//	float nmc_tag = cf->GetNTemplate("b-jets")+cf->GetNTemplate("c-jets");

	// print results

   int nPar = cf->GetNPar(); 
   
	std::cout << "notag chi2=" << chi2_notag << std::endl;
	for(int i=0;i<nPar;i++)
	  {
	     std::cout << par_notag[i] << " +- " << err_notag[i] << std::endl;
	  }   
	
	std::cout << "tag chi2=" << chi2_tag << std::endl;
	for(int i=0;i<nPar;i++)
	  {
	     std::cout << par_tag[i] << " +- " << err_tag[i] << std::endl;
	  }   
	
	float fr_notag = nmcb_notag/nmc_notag;
	float fr_tag = nmcb_tag/nmc_tag;
	
	float effMC = nmcb_tag/nmcb_notag;

	float effDATA = nmc_tag/nmc_notag*
	  par_tag[0]/par_notag[0]*
	  fr_tag/fr_notag;
	
	std::cout << "effMC = " << effMC << std::endl;
	std::cout << "effDATA = " << effDATA << std::endl;
	std::cout << "sf = " << effDATA/effMC << std::endl;
	
	sf[i] = effDATA/effMC;
	effmc[i] = effMC;
	effdata[i] = effDATA;
     }   
   
   float sfMean = 0;
   float effmcMean = 0;
   float effdataMean = 0;
   for(int i=0;i<nIter;i++)
     {
	sfMean += sf[i];
	effmcMean += effmc[i];
	effdataMean += effdata[i];
     }   
   sfMean /= float(nIter);
   effmcMean /= float(nIter);
   effdataMean /= float(nIter);
   
   float sfStat = 0;
   float effmcStat = 0;
   float effdataStat = 0;
   for(int i=0;i<nIter;i++)
     {	
	sfStat += pow(sfMean-sf[i],2)/float(nIter);
	effmcStat += pow(effmcMean-effmc[i],2)/float(nIter);
	effdataStat += pow(effdataMean-effdata[i],2)/float(nIter);
     }   
   sfStat = sqrt(sfStat);
   effmcStat = sqrt(effmcStat);
   effdataStat = sqrt(effdataStat);

   std::cout << "===========" << std::endl;
   std::cout << "SF = " << sfMean << " +- " << sfStat << std::endl;
   std::cout << "Eff (MC) = " << effmcMean << " +- " << effmcStat << std::endl;
   std::cout << "Eff (Data) = " << effdataMean << " +- " << effdataStat << std::endl;
   
	delete cf;
//     }  
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
