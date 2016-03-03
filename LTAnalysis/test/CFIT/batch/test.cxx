#include "cfit.h"
#include <iostream>
#include <vector>
#include <sstream>

bool inclSYS = 0;
int nStat = 100;
std::string varName = "JP";
//std::string jName = "j1";
std::string jName = "jSub";
bool doSFc = 0;
//std::string varName = "muPtRel";

void getResults(CFIT::cfit *cf,float *par,float *err);
void process(CFIT::cfit *cf,float *par_notag,float *err_notag,float *par_tag,float *err_tag,std::string sysVar,int statVariation);
double errfMC(double v1,double ve1,double v2,double ve2);
double errfDATA_UNCOR(double v1,double ve1,double v2,double ve2);
std::string getPtHeader(std::string pt,bool isTag);

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
std::vector<float> nmccErr_notag;
std::vector<float> nmccErr_tag;

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
//   if( inclSYS ) nSYS = 7;
   
//   if( inclSYS ) nSYS = 9; // AK4
//   if( inclSYS ) nSYS = 4; // AK4 inclusive
   if( inclSYS ) nSYS = 6; // Boosted
   
//   if( inclSYS ) nSYS = 0;
   std::string sys_down[100];
   std::string sys_up[100];
   std::string sys[100];

/*   if( inclSYS )
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
	sys[9] = "jes";
     }*/
/*   if( inclSYS ) // AK4
     {	
	sys[0] = "ntrk";
	sys[1] = "njet";
	sys[2] = "mupt";
	sys[3] = "gsplit";
	sys[4] = "bfrag";
	sys[5] = "cdfrag";
        sys[6] = "cfrag";
        sys[7] = "ksl";
	sys[8] = "jes";
     }*/
/*   if( inclSYS ) // AK4 inclusive
     {	
	sys[0] = "ntrk";
//	sys[1] = "njet";
//	sys[1] = "mupt";
//	sys[3] = "gsplit";
	sys[1] = "bfrag";
	sys[2] = "cdfrag";
//        sys[6] = "cfrag";
//        sys[7] = "ksl";
	sys[3] = "jes";
     }*/
   if( inclSYS ) // Boosted
     {	
	sys[0] = "ntrk";
	sys[1] = "gsplit";
	sys[2] = "bfrag";
	sys[3] = "cdfrag";
        sys[4] = "cfrag";
	sys[5] = "jes";
     }
/*   if( inclSYS )
     {	
	sys[0] = "ntrk";
     }*/

   CFIT::cfit *cf = new CFIT::cfit("JP discriminator");
   cf->SetVerbose(0);
   cf->ProducePlots(1);
   std::string tagReal = tag;
   if( tagReal == "CSVL" ) tagReal = "CSVv2L";
   else if( tagReal == "CSVM" ) tagReal = "CSVv2M";
   else if( tagReal == "CSVT" ) tagReal = "CSVv2T";
   else if( tagReal == "CMVAL" ) tagReal = "cMVAv2L";
   else if( tagReal == "CMVAM" ) tagReal = "cMVAv2M";
   else if( tagReal == "CMVAT" ) tagReal = "cMVAv2T";
   cf->SetTagName(tagReal);
   cf->SetLegendHeader(getPtHeader(pt,0));
   cf->SetLegendHeaderTag(getPtHeader(pt,1));
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

   std::string hname_data = "h_"+jName+"_"+varName+"_ajet_"+pt+"_nosel_nosel__DATA";
   cf->SetData(hname_data.c_str());
   std::string hname_data_tag = "h_"+jName+"_"+varName+"_ajet_"+pt+"_nosel_"+tag+"__DATA";
   cf->SetDataTag(hname_data_tag.c_str());
   std::string hname_data_untag = "h_"+jName+"_"+varName+"_ajet_"+pt+"_nosel_UNTAG"+tag+"__DATA";
   cf->SetDataUntag(hname_data_untag.c_str());
   
   std::string hname_bjets = "h_"+jName+"_"+varName+"_bjet_"+pt+"_nosel_nosel";
   cf->AddTemplate("b jets",hname_bjets.c_str());
   std::string hname_cjets = "h_"+jName+"_"+varName+"_cjet_"+pt+"_nosel_nosel";
   cf->AddTemplate("charm",hname_cjets.c_str());
   std::string hname_ljets = "h_"+jName+"_"+varName+"_ljet_"+pt+"_nosel_nosel";
   cf->AddTemplate("light flavour",hname_ljets.c_str());
   
   std::string hname_bjet_tag = "h_"+jName+"_"+varName+"_bjet_"+pt+"_nosel_"+tag;
   cf->AddTemplateTag("b jets",hname_bjet_tag.c_str());
   std::string hname_cjet_tag = "h_"+jName+"_"+varName+"_cjet_"+pt+"_nosel_"+tag;
   cf->AddTemplateTag("charm",hname_cjet_tag.c_str());
   std::string hname_ljet_tag = "h_"+jName+"_"+varName+"_ljet_"+pt+"_nosel_"+tag;
   cf->AddTemplateTag("light flavour",hname_ljet_tag.c_str());

   std::string hname_bjet_untag = "h_"+jName+"_"+varName+"_bjet_"+pt+"_nosel_UNTAG"+tag;
   cf->AddTemplateUntag("b jets",hname_bjet_untag);
   std::string hname_cjet_untag = "h_"+jName+"_"+varName+"_cjet_"+pt+"_nosel_UNTAG"+tag;
   cf->AddTemplateUntag("charm",hname_cjet_untag);
   std::string hname_ljet_untag = "h_"+jName+"_"+varName+"_ljet_"+pt+"_nosel_UNTAG"+tag;
   cf->AddTemplateUntag("light flavour",hname_ljet_untag);

   std::cout << "Run systematic variations" << std::endl;
   
   if( !inclSYS )
     {	
	process(cf,par_notag,err_notag,par_tag,err_tag,"",-1);
	
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
	     
	     process(cf,par_notag,err_notag,par_tag,err_tag,sysVar,-1);

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
	cf->SetMatrixOption("READ");
	cf->ProducePlots(0);

	std::cout << "Statistics variation " << isys << std::endl;
	
	process(cf,par_notag,err_notag,par_tag,err_tag,"",isys);
	
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

	     std::string hname_data = "h_"+jName+"_"+varName+"_ajet_"+pt+"_nosel_nosel__DATA";
	     cf->SetData(hname_data.c_str());
	     std::string hname_data_tag = "h_"+jName+"_"+varName+"_ajet_"+pt+"_nosel_"+tag+"__DATA";
	     cf->SetDataTag(hname_data_tag.c_str());
	     std::string hname_data_untag = "h_"+jName+"_"+varName+"_ajet_"+pt+"_nosel_UNTAG"+tag+"__DATA";
	     cf->SetDataUntag(hname_data_untag.c_str());
	     
	     std::string hname_bjets = "h_"+jName+"_"+varName+"_bjet_"+pt+"_nosel_nosel";
	     cf->AddTemplate("b jets",hname_bjets.c_str());
	     std::string hname_cjets = "h_"+jName+"_"+varName+"_cjet_"+pt+"_nosel_nosel";
	     cf->AddTemplate("charm",hname_cjets.c_str());
	     std::string hname_ljets = "h_"+jName+"_"+varName+"_ljet_"+pt+"_nosel_nosel";
	     cf->AddTemplate("light flavour",hname_ljets.c_str());
	     
	     std::string hname_bjet_tag = "h_"+jName+"_"+varName+"_bjet_"+pt+"_nosel_"+tag;
	     cf->AddTemplateTag("b jets",hname_bjet_tag.c_str());
	     std::string hname_cjet_tag = "h_"+jName+"_"+varName+"_cjet_"+pt+"_nosel_"+tag;
	     cf->AddTemplateTag("charm",hname_cjet_tag.c_str());
	     std::string hname_ljet_tag = "h_"+jName+"_"+varName+"_ljet_"+pt+"_nosel_"+tag;
	     cf->AddTemplateTag("light flavour",hname_ljet_tag.c_str());
	     
	     std::string hname_bjet_untag = "h_"+jName+"_"+varName+"_bjet_"+pt+"_nosel_UNTAG"+tag;
	     cf->AddTemplateUntag("b jets",hname_bjet_untag);
	     std::string hname_cjet_untag = "h_"+jName+"_"+varName+"_cjet_"+pt+"_nosel_UNTAG"+tag;
	     cf->AddTemplateUntag("charm",hname_cjet_untag);
	     std::string hname_ljet_untag = "h_"+jName+"_"+varName+"_ljet_"+pt+"_nosel_UNTAG"+tag;
	     cf->AddTemplateUntag("light flavour",hname_ljet_untag);
	  }

	process(cf,par_notag,err_notag,par_tag,err_tag,"",-1);
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
	float nmc = (nmcb_notag[i]+nmcc_notag[i]+nmcl_notag[i]);
	
	float nmc_tag = (nmcb_tag[i]+nmcc_tag[i]+nmcl_tag[i]);
	
	float frb_notag_new = nmc/ndata_notag[i]*par_notag_bjet[i]*frb_notag[i];
	float frc_notag_new = nmc/ndata_notag[i]*par_notag_cjet[i]*frc_notag[i];
	float frl_notag_new = nmc/ndata_notag[i]*par_notag_ljet[i]*frl_notag[i];

	float frb_tag_new = nmc_tag/ndata_tag[i]*par_tag_bjet[i]*frb_tag[i];
	float frc_tag_new = nmc_tag/ndata_tag[i]*par_tag_cjet[i]*frc_tag[i];
	float frl_tag_new = nmc_tag/ndata_tag[i]*par_tag_ljet[i]*frl_tag[i];
	
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
	  std::to_string(frb_notag_new)+dl+
	  std::to_string(frb_tag_new)+dl+
	  std::to_string(frc_notag_new)+dl+
	  std::to_string(frc_tag_new)+dl+
	  std::to_string(frl_notag_new)+dl+
	  std::to_string(frl_tag_new)+dl+
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
     }   

   fout.close();
   
   delete cf;
}

void process(CFIT::cfit *cf,float *par_notag,float *err_notag,float *par_tag,float *err_tag,std::string sysVar,int statVariation)
{   
   // pre-tag fit
   cf->SetSysVariation(sysVar);
   if( statVariation >= 0 ) cf->SetStatVariation(statVariation);
   cf->Run();   
   getResults(cf,par_notag,err_notag);
   chi2_notag.push_back(cf->GetChisq());
   ndof_notag.push_back(cf->GetNDOF());
   ndata_notag.push_back(cf->GetNData());
   nmcb_notag.push_back(cf->GetNTemplate("b jets"));
   nmcbErr_notag.push_back(cf->GetErrTemplate("b jets"));
   nmcc_notag.push_back(cf->GetNTemplate("charm"));
   nmccErr_notag.push_back(cf->GetErrTemplate("charm"));
   nmcl_notag.push_back(cf->GetNTemplate("light flavour"));
   nmc_notag.push_back(cf->GetNTemplate("b jets")+cf->GetNTemplate("charm")+cf->GetNTemplate("light flavour"));
   
   // post-tag fit
   cf->SetSysVariation(sysVar);
   if( statVariation >= 0 ) cf->SetStatVariation(statVariation);
   cf->Run("tag");   
   getResults(cf,par_tag,err_tag);
   chi2_tag.push_back(cf->GetChisq());
   ndof_tag.push_back(cf->GetNDOF());
   ndata_tag.push_back(cf->GetNData());
   nmcb_tag.push_back(cf->GetNTemplate("b jets"));
   nmcbErr_tag.push_back(cf->GetErrTemplate("b jets"));
   nmcc_tag.push_back(cf->GetNTemplate("charm"));
   nmccErr_tag.push_back(cf->GetErrTemplate("charm"));
   nmcl_tag.push_back(cf->GetNTemplate("light flavour"));
   nmc_tag.push_back(cf->GetNTemplate("b jets")+cf->GetNTemplate("charm")+cf->GetNTemplate("light flavour"));

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
   if( doSFc ) errMCErr_val = errfMC(nmcc_tag.back(),nmccErr_tag.back(),
				     nmcc_notag.back(),nmccErr_notag.back());
   
   if( !doSFc ) effMC.push_back(nmcb_tag.back()/nmcb_notag.back());
   else effMC.push_back(nmcc_tag.back()/nmcc_notag.back());

//   effDATA.push_back(ndata_tag.back()/ndata_notag.back()*par_tag[0]/par_notag[0]*frb_tag.back()/frb_notag.back());

   if( !doSFc ) effDATA.push_back(nmc_tag.back()/nmc_notag.back()*
				  par_tag[0]/par_notag[0]*
				  frb_tag.back()/frb_notag.back());
   else effDATA.push_back(nmc_tag.back()/nmc_notag.back()*
				  par_tag[1]/par_notag[1]*
				  frc_tag.back()/frc_notag.back());
   
   float effMCErr_val = errfMC(nmcb_tag.back(),nmcbErr_tag.back(),
			       nmcb_notag.back(),nmcbErr_notag.back());
   if( doSFc ) effMCErr_val = errfMC(nmcc_tag.back(),nmccErr_tag.back(),
				     nmcc_notag.back(),nmccErr_notag.back());

   float effDATAErr_val = errfDATA_UNCOR(par_tag[0],err_tag[0],
					 par_notag[0],err_notag[0]);
   if( doSFc ) effDATAErr_val = errfDATA_UNCOR(par_tag[1],err_tag[1],
					       par_notag[1],err_notag[1]);

   effDATAErr_val *= nmc_tag.back()/nmc_notag.back();
   if( !doSFc ) effDATAErr_val *= frb_tag.back()/frb_notag.back();
   else effDATAErr_val *= frc_tag.back()/frc_notag.back();
   
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

   double vDiff = fabs(ve2*ve2-ve1*ve1);
   
   double err = pow(v2-v1,2)*ve1*ve1/pow(v2,4) +
     v1*v1*vDiff/pow(v2,4);
   
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

std::string getPtHeader(std::string pt,bool isTag)
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
   if( pt == "pt20t30" ) ptHeader = "20<p_{T}<30 GeV";
   else if( pt == "pt30t50" ) ptHeader = "30<p_{T}<50 GeV";
   else if( pt == "pt50t70" ) ptHeader = "50<p_{T}<70 GeV";
   else if( pt == "pt70t100" ) ptHeader = "70<p_{T}<100 GeV";
   else if( pt == "pt100t140" ) ptHeader = "100<p_{T}<140 GeV";
   else if( pt == "pt140t200" ) ptHeader = "140<p_{T}<200 GeV";
   else if( pt == "pt200t300" ) ptHeader = "200<p_{T}<300 GeV";
   else if( pt == "pt300t670" ) ptHeader = "300<p_{T}<670 GeV";
   else if( pt == "pt670t1000" ) ptHeader = "670<p_{T}<1000 GeV";
   
   else if( pt == "pt50t450" ) ptHeader = "50<p_{T}<450 GeV";
   else if( pt == "pt450t510" ) ptHeader = "450<p_{T}<510 GeV";
   else if( pt == "pt510t600" ) ptHeader = "510<p_{T}<600 GeV";
   else if( pt == "pt600t900" ) ptHeader = "600<p_{T}<900 GeV";
   
   else if( pt == "pt0t150" ) ptHeader = "0<p_{T}<150 GeV";
   else if( pt == "pt150t215" ) ptHeader = "150<p_{T}<215 GeV";
   else if( pt == "pt215t290" ) ptHeader = "215<p_{T}<290 GeV";
   else if( pt == "pt290t360" ) ptHeader = "290<p_{T}<360 GeV";
   else if( pt == "pt360t430" ) ptHeader = "360<p_{T}<430 GeV";
   else if( pt == "pt430t570" ) ptHeader = "430<p_{T}<570 GeV";
   
   else if( pt == "pt200t220" ) ptHeader = "200<p_{T}<220 GeV";
   else if( pt == "pt220t250" ) ptHeader = "220<p_{T}<250 GeV";
   else if( pt == "pt250t300" ) ptHeader = "250<p_{T}<300 GeV";
   else if( pt == "pt300t400" ) ptHeader = "300<p_{T}<400 GeV";
   else if( pt == "pt400t650" ) ptHeader = "400<p_{T}<650 GeV";
   
   else if( pt == "pt30t80" ) ptHeader = "30<p_{T}<80 GeV";
   else if( pt == "pt80t140" ) ptHeader = "80<p_{T}<140 GeV";
   else if( pt == "pt140t180" ) ptHeader = "140<p_{T}<180 GeV";
   else if( pt == "pt180t240" ) ptHeader = "180<p_{T}<240 GeV";
   else if( pt == "pt240t420" ) ptHeader = "240<p_{T}<420 GeV";
   
   else
     {
	std::cout << "pT label is unknown" << std::endl;
	exit(1);
     }
   
   if( isTag ) ptHeader = "tagged jets ("+ptHeader+")";
   else ptHeader = "all jets ("+ptHeader+")";
   
   return ptHeader;
}
