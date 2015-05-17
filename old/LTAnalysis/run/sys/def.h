#ifndef SYSDEF_H
#define SYSDEF_H

#include <vector>
#include "Riostream.h" 

//   const int kb = 391;
//   const int kc = 600;
//   const int kl = 414;

   const int kb = 2;
   const int kc = 4;
   const int kl = 3;

   std::vector<std::string> 
     v_data,
     v_mc_DEFAULT;

   std::vector<std::string> *v_mc_filt,*v_mc_unfilt;
   
   std::string pref = "/data.root";

   std::string lumi = "";

void def()
{
   // 2012
/*   v_data.push_back("BTag_Run2012A-22Jan2013_V02-03-02"+pref);
   v_data.push_back("BTag_Run2012B-22Jan2013_V02-03-02"+pref);
   v_data.push_back("BTag_Run2012C-22Jan2013_V02-03-02"+pref);
   v_data.push_back("BTag_Run2012D-22Jan2013_V02-03-02"+pref);

   v_mc_DEFAULT.push_back("Pt-15to20"+pref);
   v_mc_DEFAULT.push_back("Pt-20to30"+pref);
   v_mc_DEFAULT.push_back("Pt-30to50"+pref);
   v_mc_DEFAULT.push_back("Pt-50to80"+pref);
   v_mc_DEFAULT.push_back("Pt-80to120"+pref);
   v_mc_DEFAULT.push_back("Pt-120to170"+pref);
   v_mc_DEFAULT.push_back("Pt-170to300"+pref);
   v_mc_DEFAULT.push_back("Pt-300to470"+pref);
   v_mc_DEFAULT.push_back("Pt-470to600"+pref);
   v_mc_DEFAULT.push_back("Pt-600to800"+pref);
   v_mc_DEFAULT.push_back("Pt-800to1000"+pref);*/

   // 2011
   v_data.push_back("BTag_Run2011A"+pref);
   v_data.push_back("BTag_Run2011B"+pref);
   v_data.push_back("METBTag_Run2011A"+pref);
   v_data.push_back("Jet_Run2011A"+pref);
   v_data.push_back("Jet_Run2011B"+pref);

   v_mc_DEFAULT.push_back("Pt-15to20"+pref);
   v_mc_DEFAULT.push_back("Pt-20to30"+pref);
   v_mc_DEFAULT.push_back("Pt-30to50"+pref);
   v_mc_DEFAULT.push_back("Pt-50to80"+pref);
   v_mc_DEFAULT.push_back("Pt-80to120"+pref);
   v_mc_DEFAULT.push_back("Pt-120to170"+pref);
   v_mc_DEFAULT.push_back("Pt-170to300"+pref);
   v_mc_DEFAULT.push_back("Pt-300to470"+pref);
   v_mc_DEFAULT.push_back("Pt-470to600"+pref);
   v_mc_DEFAULT.push_back("Pt-600to800"+pref);
   v_mc_DEFAULT.push_back("Pt-800to1000"+pref);
   
   // ttbar
   /*
   v_data.push_back("Run2012A-v1"+pref);
   v_data.push_back("Run2012B-v1"+pref);
   v_data.push_back("Run2012C-v1"+pref);
   v_data.push_back("Run2012D-v1"+pref);

   v_mc_DEFAULT.push_back("TTJets-v1"+pref);
   v_mc_DEFAULT.push_back("T_tW-channel-v1"+pref);
   v_mc_DEFAULT.push_back("Tbar_tW-channel-v1"+pref);
   v_mc_DEFAULT.push_back("DYJetsToLL_M10to50-v1"+pref);
   v_mc_DEFAULT.push_back("DYJetsToLL_Msup50-v1"+pref);
*/   
   v_mc_filt = &v_mc_DEFAULT;
   v_mc_unfilt = &v_mc_DEFAULT;
}

#endif

   
