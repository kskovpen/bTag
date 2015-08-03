#include "cfit.h"
#include <iostream>
#include <vector>
#include <sstream>

bool inclSYS = 1;
int nStat = 100;
std::string varName = "JP";
//std::string varName = "muPtRel";

void getResults(CFIT::cfit *cf,float *par,float *err);
void process(CFIT::cfit *cf,float *par_notag,float *err_notag,float *par_tag,float *err_tag,std::string sysVar);
double errfMC(double v1,double ve1,double v2,double ve2);
double errfDATA_UNCOR(double v1,double ve1,double v2,double ve2);
std::string getPtHeader(std::string pt);

std::vector<int> run;
std::vector<float> par_notag_bjet;
std::vector<float> par_notag_cjet;
std::vector<float> par_notag_ljet;
std::vector<float> err_notag_bjet;
std::vector<float> err_notag_cjet;
std::vector<float> err_notag_ljet;
std::vector<float> par_tag_bjet;
std::vector<float> par_tag_cjet;
std::vector<float> par_tag_ljet;
std::vector<float> err_tag_bjet;
std::vector<float> err_tag_cjet;
std::vector<float> err_tag_ljet;

std::vector<float> chi2_notag;
std::vector<float> chi2_tag;

std::vector<int> ndof_notag;
std::vector<int> ndof_tag;

std::vector<float> ndata_notag;
std::vector<float> ndata_tag;

std::vector<float> nmcb_notag;
std::vector<float> nmcb_tag;
std::vector<float> nmcc_notag;
std::vector<float> nmcc_tag;
std::vector<float> nmcl_notag;
std::vector<float> nmcl_tag;

std::vector<float> nmcbErr_notag;
std::vector<float> nmcbErr_tag;

std::vector<float> nmc_notag;
std::vector<float> nmc_tag;

std::vector<float> frb_notag;
std::vector<float> frb_tag;
std::vector<float> frc_notag;
std::vector<float> frc_tag;
std::vector<float> frl_notag;
std::vector<float> frl_tag;

std::vector<float> effMC;
std::vector<float> effMCErr;
std::vector<float> effDATA;
std::vector<float> effDATAErr;
std::vector<float> SF;
std::vector<float> SFErr;

int main(int argc,char *argv[])
{
   if( argc < 6 )
     {
	std::cout << "Please specify input parameters" << std::endl;
	exit(1);
     }
   
   std::string fname = std::string(argv[1]);
   std::string pt = std::string(argv[2]);
   std::string tag = std::string(argv[3]);
   std::string outdir = std::string(argv[4]);
   std::string dirname = std::string(argv[5]);

   std::string foutName = outdir+"/"+dirname+"/"+pt+"_"+tag+".csv";
   std::ofstream fout(foutName.c_str());
   fout << "ptMin,ptMax,tag,run,\
nDATA,nDATATag,nMCb,nMCbTag,nMCc,\
nMCcTag,nMCl,nMClTag,pb,pbTag,frb,\
frbTag,frc,frcTag,frl,frlTag,chi2,\
chi2Tag,effMC,effData,SF,\
effMCErr,effDataErr,SFErr,pbErr,pbTagErr,\
pc,pcErr,pcTag,pcTagErr,pl,plErr,plTag,plTagErr,ndof,ndofTag\
\n";
   
   float par_notag[100];
   float err_notag[100];

   float par_tag[100];
   float err_tag[100];

   int nSYS = 0;
//   if( inclSYS ) nSYS = 13;
   if( inclSYS ) nSYS = 9;
//   if( inclSYS ) nSYS = 1;
   std::string sys_down[100];
   std::string sys_up[100];
   std::string sys[100];
/*   if( inclSYS )
     {	
	sys[0] = "ntrk";
	sys[1] = "njet";
	sys[2] = "mupt";
        sys[3] = "jeta";
	sys[4] = "pu";
	sys[5] = "gsplit";
	sys[6] = "bfrag";
	sys[7] = "cdfrag";
        sys[8] = "cfrag";
        sys[9] = "ksl";
        sys[10] = "ntrkgen";
        sys[11] = "jes";
        sys[12] = "jer";
     }*/
/*   if( inclSYS )
     {
	sys[0] = "ntrkgen";
     }*/
   if( inclSYS )
     {	
	sys[0] = "ntrk";
	sys[1] = "njet";
	sys[2] = "mupt";
	sys[3] = "gsplit";
	sys[4] = "bfrag";
	sys[5] = "cdfrag";
        sys[6] = "cfrag";
        sys[7] = "ksl";
        sys[8] = "ntrkgen";
     }

   CFIT::cfit *cf = new CFIT::cfit("JP discriminator");
   cf->SetVerbose(0);
   cf->ProducePlots(1);
   cf->SetLegendHeader(getPtHeader(pt));
   cf->SetOptimization(OPT_MORPH_SGN_SIGMA);
   cf->SetCovarianceMode(COV_MAX);
//   cf->SetOptimization(OPT_NOCORR);
   cf->SetMorphing(OPTMORPH_CUTOFF,0.5);
//   cf->SetMorphing(OPTMORPH_GEOMETRIC);
   
   cf->SetInputFile(fname.c_str());

   for(int is=0;is<nSYS;is++)
     {
	sys_down[is] = "_"+sys[is]+"_down";
	sys_up[is] = "_"+sys[is]+"_up";
	cf->AddSys(sys[is].c_str(),sys_down[is].c_str(),sys_up[is].c_str());
     }
   
   std::string mname = "matrix_"+pt;
   cf->SetMatrixName(mname.c_str());
   cf->SetMatrixOption("WRITE");

   std::string hname_data = "h_j1_"+varName+"_ajet_"+pt+"_nosel_nosel__DATA";
   cf->SetData(hname_data.c_str());
   std::string hname_data_tag = "h_j1_"+varName+"_ajet_"+pt+"_nosel_"+tag+"__DATA";
   cf->SetDataTag(hname_data_tag.c_str());
   std::string hname_data_untag = "h_j1_"+varName+"_ajet_"+pt+"_nosel_UNTAG"+tag+"__DATA";
   cf->SetDataUntag(hname_data_untag.c_str());
   
   std::string hname_bjets = "h_j1_"+varName+"_bjet_"+pt+"_nosel_nosel";
   cf->AddTemplate("b-jets",hname_bjets.c_str());
   std::string hname_cjets = "h_j1_"+varName+"_cjet_"+pt+"_nosel_nosel";
   cf->AddTemplate("c-jets",hname_cjets.c_str());
   std::string hname_ljets = "h_j1_"+varName+"_ljet_"+pt+"_nosel_nosel";
   cf->AddTemplate("udsg-jets",hname_ljets.c_str());
   
   std::string hname_bjet_tag = "h_j1_"+varName+"_bjet_"+pt+"_nosel_"+tag;
   cf->AddTemplateTag("b-jets",hname_bjet_tag.c_str());
   std::string hname_cjet_tag = "h_j1_"+varName+"_cjet_"+pt+"_nosel_"+tag;
   cf->AddTemplateTag("c-jets",hname_cjet_tag.c_str());
   std::string hname_ljet_tag = "h_j1_"+varName+"_ljet_"+pt+"_nosel_"+tag;
   cf->AddTemplateTag("udsg-jets",hname_ljet_tag.c_str());

   std::string hname_bjet_untag = "h_j1_"+varName+"_bjet_"+pt+"_nosel_UNTAG"+tag;
   cf->AddTemplateUntag("b-jets",hname_bjet_untag);
   std::string hname_cjet_untag = "h_j1_"+varName+"_cjet_"+pt+"_nosel_UNTAG"+tag;
   cf->AddTemplateUntag("c-jets",hname_cjet_untag);
   std::string hname_ljet_untag = "h_j1_"+varName+"_ljet_"+pt+"_nosel_UNTAG"+tag;
   cf->AddTemplateUntag("udsg-jets",hname_ljet_untag);

   std::cout << "Run systematic variations" << std::endl;
   
   if( !inclSYS )
     {	
	process(cf,par_notag,err_notag,par_tag,err_tag,"");
	
	run.push_back(0);
	par_notag_bjet.push_back(par_notag[0]);
	par_notag_cjet.push_back(par_notag[1]);
	par_notag_ljet.push_back(par_notag[2]);
	err_notag_bjet.push_back(err_notag[0]);
	err_notag_cjet.push_back(err_notag[1]);
	err_notag_ljet.push_back(err_notag[2]);
	par_tag_bjet.push_back(par_tag[0]);
	par_tag_cjet.push_back(par_tag[1]);
	par_tag_ljet.push_back(par_tag[2]);
	err_tag_bjet.push_back(err_tag[0]);
	err_tag_cjet.push_back(err_tag[1]);
	err_tag_ljet.push_back(err_tag[2]);
     }
   else
     {
	// nosys and sys
	for(int is=0;is<=2*nSYS;is++)
	  {
	     // if( is != 0 ) continue;
	     //	if( is != 0 && is != 1 ) continue;
	     int iss = is;			
	     
	     std::string sysVar = "";
	     
	     if( iss > nSYS )
	       {
		  iss = -(iss-nSYS);
	       }
	     if( iss != 0 )
	       {
		  cf->SetMatrixOption("READ");
		  
		  if( iss > 0 )
		    sysVar = sys_up[iss-1];
		  else
		    sysVar = sys_down[abs(iss)-1];
		  
		  std::cout << "Systematics variation " << sysVar << std::endl;
	       }

	     if( iss != 0 ) cf->ProducePlots(0);
	     
	     process(cf,par_notag,err_notag,par_tag,err_tag,sysVar);
	     
	     run.push_back(iss);
	     par_notag_bjet.push_back(par_notag[0]);
	     par_notag_cjet.push_back(par_notag[1]);
	     par_notag_ljet.push_back(par_notag[2]);
	     err_notag_bjet.push_back(err_notag[0]);
	     err_notag_cjet.push_back(err_notag[1]);
	     err_notag_ljet.push_back(err_notag[2]);
	     par_tag_bjet.push_back(par_tag[0]);
	     par_tag_cjet.push_back(par_tag[1]);
	     par_tag_ljet.push_back(par_tag[2]);
	     err_tag_bjet.push_back(err_tag[0]);
	     err_tag_cjet.push_back(err_tag[1]);
	     err_tag_ljet.push_back(err_tag[2]);	     
	  }
     }
   
   std::cout << "Run statistical variations" << std::endl;
   
   for(int is=0;is<nStat;is++)
     {	
	int isys = 666+is;
	cf->SetStatVariation(isys);
	cf->SetMatrixOption("READ");
	cf->ProducePlots(0);

	std::cout << "Statistics variation " << isys << std::endl;
	
	process(cf,par_notag,err_notag,par_tag,err_tag,"");
	
	run.push_back(isys);
	par_notag_bjet.push_back(par_notag[0]);
	par_notag_cjet.push_back(par_notag[1]);
	par_notag_ljet.push_back(par_notag[2]);
	err_notag_bjet.push_back(err_notag[0]);
	err_notag_cjet.push_back(err_notag[1]);
	err_notag_ljet.push_back(err_notag[2]);
	par_tag_bjet.push_back(par_tag[0]);
	par_tag_cjet.push_back(par_tag[1]);
	par_tag_ljet.push_back(par_tag[2]);
	err_tag_bjet.push_back(err_tag[0]);
	err_tag_cjet.push_back(err_tag[1]);
	err_tag_ljet.push_back(err_tag[2]);
     }
   
   // additional systematics variations
   for(int i=100;i<=104;i++)
     {
	// recalculate correlation matrix according to optimisation settings
	cf->SetMatrixOption("WRITE");
	cf->ProducePlots(0);
	
	if( i == 100 ) cf->SetOptimization(OPT_NOCORR);
	if( i == 101 ) cf->SetMorphing(OPTMORPH_CUTOFF,0.25);
	if( i == 102 ) cf->SetMorphing(OPTMORPH_CUTOFF,0.75);
//	if( i == 103 ) cf->SetMorphing(OPTMORPH_CUTOFF,0.5);
	if( i == 103 ) cf->SetMorphing(OPTMORPH_GEOMETRIC);
	if( i == 104 )
	  {
	     delete cf;
	     cf = new CFIT::cfit();
	     
	     cf->SetVerbose(0);
	     cf->ProducePlots(0);
	     cf->SetOptimization(OPT_MORPH_SGN_SIGMA);
	     cf->SetCovarianceMode(COV_MAX);
	     cf->SetMorphing(OPTMORPH_CUTOFF,0.5);
//	     cf->SetMorphing(OPTMORPH_GEOMETRIC);
	     
	     cf->SetInputFile(fname.c_str());
   
	     std::string mname = "matrix_"+pt;
	     cf->SetMatrixName(mname.c_str());
	     cf->SetMatrixOption("WRITE");

	     std::string hname_data = "h_j1_"+varName+"_ajet_"+pt+"_nosel_nosel__DATA";
	     cf->SetData(hname_data.c_str());
	     std::string hname_data_tag = "h_j1_"+varName+"_ajet_"+pt+"_nosel_"+tag+"__DATA";
	     cf->SetDataTag(hname_data_tag.c_str());
	     std::string hname_data_untag = "h_j1_"+varName+"_ajet_"+pt+"_nosel_UNTAG"+tag+"__DATA";
	     cf->SetDataUntag(hname_data_untag.c_str());
	     
	     std::string hname_bjets = "h_j1_"+varName+"_bjet_"+pt+"_nosel_nosel";
	     cf->AddTemplate("b-jets",hname_bjets.c_str());
	     std::string hname_cjets = "h_j1_"+varName+"_cjet_"+pt+"_nosel_nosel";
	     cf->AddTemplate("c-jets",hname_cjets.c_str());
	     std::string hname_ljets = "h_j1_"+varName+"_ljet_"+pt+"_nosel_nosel";
	     cf->AddTemplate("udsg-jets",hname_ljets.c_str());
	     
	     std::string hname_bjet_tag = "h_j1_"+varName+"_bjet_"+pt+"_nosel_"+tag;
	     cf->AddTemplateTag("b-jets",hname_bjet_tag.c_str());
	     std::string hname_cjet_tag = "h_j1_"+varName+"_cjet_"+pt+"_nosel_"+tag;
	     cf->AddTemplateTag("c-jets",hname_cjet_tag.c_str());
	     std::string hname_ljet_tag = "h_j1_"+varName+"_ljet_"+pt+"_nosel_"+tag;
	     cf->AddTemplateTag("udsg-jets",hname_ljet_tag.c_str());
	     
	     std::string hname_bjet_untag = "h_j1_"+varName+"_bjet_"+pt+"_nosel_UNTAG"+tag;
	     cf->AddTemplateUntag("b-jets",hname_bjet_untag);
	     std::string hname_cjet_untag = "h_j1_"+varName+"_cjet_"+pt+"_nosel_UNTAG"+tag;
	     cf->AddTemplateUntag("c-jets",hname_cjet_untag);
	     std::string hname_ljet_untag = "h_j1_"+varName+"_ljet_"+pt+"_nosel_UNTAG"+tag;
	     cf->AddTemplateUntag("udsg-jets",hname_ljet_untag);
	  }

	process(cf,par_notag,err_notag,par_tag,err_tag,"");
	run.push_back(i);
	par_notag_bjet.push_back(par_notag[0]);
	par_notag_cjet.push_back(par_notag[1]);
	par_notag_ljet.push_back(par_notag[2]);
	err_notag_bjet.push_back(err_notag[0]);
	err_notag_cjet.push_back(err_notag[1]);
	err_notag_ljet.push_back(err_notag[2]);
	par_tag_bjet.push_back(par_tag[0]);
	par_tag_cjet.push_back(par_tag[1]);
	par_tag_ljet.push_back(par_tag[2]);
	err_tag_bjet.push_back(err_tag[0]);
	err_tag_cjet.push_back(err_tag[1]);
	err_tag_ljet.push_back(err_tag[2]);
	
	// restore initial settings
	cf->SetOptimization(OPT_MORPH_SGN_SIGMA);
	cf->SetMorphing(OPTMORPH_CUTOFF,0.5);
//	cf->SetMorphing(OPTMORPH_GEOMETRIC);
     }
      
   std::stringstream ss(pt);
   std::string item;
   int idx = 0;
   std::string ptMin = "";
   std::string ptMax = "";
   while( std::getline(ss,item,'t') )
     {
	if( idx == 1 ) ptMin = item;
	if( idx == 2 ) ptMax = item;
	idx++;
     }
      
   std::string dl = ",";
   int nRun = SF.size();
   for(int i=0;i<nRun;i++)
     {	
	std::string strOut = ptMin+dl+ptMax+dl+tag+dl+
	  std::to_string(run[i])+dl+
	  std::to_string(ndata_notag[i])+dl+
	  std::to_string(ndata_tag[i])+dl+
	  std::to_string(nmcb_notag[i])+dl+
	  std::to_string(nmcb_tag[i])+dl+
	  std::to_string(nmcc_notag[i])+dl+
	  std::to_string(nmcc_tag[i])+dl+
	  std::to_string(nmcl_notag[i])+dl+
	  std::to_string(nmcl_tag[i])+dl+
	  std::to_string(par_notag_bjet[i])+dl+
	  std::to_string(par_tag_bjet[i])+dl+
	  std::to_string(frb_notag[i])+dl+
	  std::to_string(frb_tag[i])+dl+
	  std::to_string(frc_notag[i])+dl+
	  std::to_string(frc_tag[i])+dl+
	  std::to_string(frl_notag[i])+dl+
	  std::to_string(frl_tag[i])+dl+
	  std::to_string(chi2_notag[i])+dl+
	  std::to_string(chi2_tag[i])+dl+
	  std::to_string(effMC[i])+dl+
	  std::to_string(effDATA[i])+dl+
	  std::to_string(SF[i])+dl+
	  std::to_string(effMCErr[i])+dl+
	  std::to_string(effDATAErr[i])+dl+
	  std::to_string(SFErr[i])+dl+
	  std::to_string(err_notag_bjet[i])+dl+
	  std::to_string(err_tag_bjet[i])+dl+
	  std::to_string(par_notag_cjet[i])+dl+
	  std::to_string(err_notag_cjet[i])+dl+
	  std::to_string(par_tag_cjet[i])+dl+
	  std::to_string(err_tag_cjet[i])+dl+
	  std::to_string(par_notag_ljet[i])+dl+
	  std::to_string(err_notag_ljet[i])+dl+
	  std::to_string(par_tag_ljet[i])+dl+
	  std::to_string(err_tag_ljet[i])+dl+
	  std::to_string(ndof_notag[i])+dl+
	  std::to_string(ndof_tag[i])+
	  "\n";
	fout << strOut.c_str();

	float nmc = (nmcb_notag[i]+nmcc_notag[i]+nmcl_notag[i]);

	float frbNew = nmc/ndata_notag[i]*par_notag_bjet[i]*frb_notag[i];
	float frcNew = nmc/ndata_notag[i]*par_notag_cjet[i]*frc_notag[i];
	float frlNew = nmc/ndata_notag[i]*par_notag_ljet[i]*frl_notag[i];
     }

   fout.close();
   
   delete cf;
}

void process(CFIT::cfit *cf,float *par_notag,float *err_notag,float *par_tag,float *err_tag,std::string sysVar)
{   
   // pre-tag fit
   cf->SetSysVariation(sysVar);
   cf->Run();   
   getResults(cf,par_notag,err_notag);
   chi2_notag.push_back(cf->GetChisq());
   ndof_notag.push_back(cf->GetNDOF());
   ndata_notag.push_back(cf->GetNData());
   nmcb_notag.push_back(cf->GetNTemplate("b-jets"));
   nmcbErr_notag.push_back(cf->GetErrTemplate("b-jets"));
   nmcc_notag.push_back(cf->GetNTemplate("c-jets"));
   nmcl_notag.push_back(cf->GetNTemplate("udsg-jets"));
   nmc_notag.push_back(cf->GetNTemplate("b-jets")+cf->GetNTemplate("c-jets")+cf->GetNTemplate("udsg-jets"));
   
   // post-tag fit
   cf->SetSysVariation(sysVar);
   cf->Run("tag");   
   getResults(cf,par_tag,err_tag);
   chi2_tag.push_back(cf->GetChisq());
   ndof_tag.push_back(cf->GetNDOF());
   ndata_tag.push_back(cf->GetNData());
   nmcb_tag.push_back(cf->GetNTemplate("b-jets"));
   nmcbErr_tag.push_back(cf->GetErrTemplate("b-jets"));
   nmcc_tag.push_back(cf->GetNTemplate("c-jets"));
   nmcl_tag.push_back(cf->GetNTemplate("udsg-jets"));
   nmc_tag.push_back(cf->GetNTemplate("b-jets")+cf->GetNTemplate("c-jets")+cf->GetNTemplate("udsg-jets"));

   std::cout << "notag chi2=" << chi2_notag.back() << std::endl;
   for(int i=0;i<3;i++)
     {
	std::cout << par_notag[i] << " +- " << err_notag[i] << std::endl;
     }   
   
   std::cout << "tag chi2=" << chi2_tag.back() << std::endl;
   for(int i=0;i<3;i++)
     {
	std::cout << par_tag[i] << " +- " << err_tag[i] << std::endl;
     }   
   
   frb_notag.push_back(nmcb_notag.back()/nmc_notag.back());
   frb_tag.push_back(nmcb_tag.back()/nmc_tag.back());

   frc_notag.push_back(nmcc_notag.back()/nmc_notag.back());
   frc_tag.push_back(nmcc_tag.back()/nmc_tag.back());

   frl_notag.push_back(nmcl_notag.back()/nmc_notag.back());
   frl_tag.push_back(nmcl_tag.back()/nmc_tag.back());

   float errMCErr_val = errfMC(nmcb_tag.back(),nmcbErr_tag.back(),
			       nmcb_notag.back(),nmcbErr_notag.back());
   
   effMC.push_back(nmcb_tag.back()/nmcb_notag.back());

//   effDATA.push_back(ndata_tag.back()/ndata_notag.back()*par_tag[0]/par_notag[0]*frb_tag.back()/frb_notag.back());
   effDATA.push_back(nmc_tag.back()/nmc_notag.back()*
		     par_tag[0]/par_notag[0]*
		     frb_tag.back()/frb_notag.back());
   
   float effMCErr_val = errfMC(nmcb_tag.back(),nmcbErr_tag.back(),
			       nmcb_notag.back(),nmcbErr_notag.back());   

   float effDATAErr_val = errfDATA_UNCOR(par_tag[0],err_tag[0],
					 par_notag[0],err_notag[0]);
   effDATAErr_val *= nmc_tag.back()/nmc_notag.back();
   effDATAErr_val *= frb_tag.back()/frb_notag.back();
   
   effMCErr.push_back(effMCErr_val);
   effDATAErr.push_back(effDATAErr_val);
   
   std::cout << "effMC = " << effMC.back() << " +- " << effMCErr.back() << std::endl;
   std::cout << "effDATA = " << effDATA.back() << " +- " << effDATAErr.back() << std::endl;

   float SFErr_val = errfDATA_UNCOR(effDATA.back(),effDATAErr.back(),
				    effMC.back(),effMCErr.back());
   
   SF.push_back(effDATA.back()/effMC.back());
   SFErr.push_back(SFErr_val);
   
   std::cout << "sf = " << SF.back() << " +- " << SFErr.back() << std::endl;
}

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

double errfMC(double v1,double ve1,double v2,double ve2)
{
   if( v2 == 0 ) return -666;
   
   double err = pow(v2-v1,2)*ve1*ve1/pow(v2,4) +
     v1*v1*(ve2*ve2-ve1*ve1)/pow(v2,4);
   
   err = sqrt(err);
   
   return err;
}

double errfDATA(double v1,double ve1,double v2,double ve2)
{
   if( v2 == 0 ) return -666;
   
   double err = ve1*ve1/v2/v2 + v1*v1*ve2*ve2/v2/v2/v2/v2;
   
   err = sqrt(err);
   
   return err;
}

double errfDATA_UNCOR(double v1,double ve1,double v2,double ve2)
{
   if( v2 == 0 ) return -666;
   
   double err = ve1*ve1/v1/v1+ve2*ve2/v2/v2;
   
   err = sqrt(err)*v1/v2;
   
   return err;
}

std::string getPtHeader(std::string pt)
{
   std::string ptHeader = "";
/*   if( pt == "pt20t30" ) ptHeader = "p_{T} 20-30 GeV";
   else if( pt == "pt30t40" ) ptHeader = "p_{T} 30-40 GeV";
   else if( pt == "pt40t50" ) ptHeader = "p_{T} 40-50 GeV";
   else if( pt == "pt50t60" ) ptHeader = "p_{T} 50-60 GeV";
   else if( pt == "pt60t70" ) ptHeader = "p_{T} 60-70 GeV";
   else if( pt == "pt70t80" ) ptHeader = "p_{T} 70-80 GeV";
   else if( pt == "pt80t100" ) ptHeader = "p_{T} 80-100 GeV";
   else if( pt == "pt100t120" ) ptHeader = "p_{T} 100-120 GeV";
   else if( pt == "pt120t160" ) ptHeader = "p_{T} 120-160 GeV";
   else if( pt == "pt160t210" ) ptHeader = "p_{T} 160-210 GeV";
   else if( pt == "pt210t260" ) ptHeader = "p_{T} 210-260 GeV";
   else if( pt == "pt260t320" ) ptHeader = "p_{T} 260-320 GeV";
   else if( pt == "pt320t400" ) ptHeader = "p_{T} 320-400 GeV";
   else if( pt == "pt400t500" ) ptHeader = "p_{T} 400-500 GeV";
   else if( pt == "pt500t670" ) ptHeader = "p_{T} 500-670 GeV";*/
   if( pt == "pt20t30" ) ptHeader = "p_{T} 20-30 GeV";
   else if( pt == "pt30t50" ) ptHeader = "p_{T} 30-50 GeV";
   else if( pt == "pt50t70" ) ptHeader = "p_{T} 50-70 GeV";
   else if( pt == "pt70t100" ) ptHeader = "p_{T} 70-100 GeV";
   else if( pt == "pt100t140" ) ptHeader = "p_{T} 100-140 GeV";
   else if( pt == "pt140t200" ) ptHeader = "p_{T} 140-200 GeV";
   else if( pt == "pt200t300" ) ptHeader = "p_{T} 200-300 GeV";
   else if( pt == "pt300t670" ) ptHeader = "p_{T} 300-670 GeV";
   else
     {
	std::cout << "pT label is unknown" << std::endl;
	exit(1);
     }   
   return ptHeader;
}
