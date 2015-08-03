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
   v_data.push_back("Run2015B_BTagMu_JPCalib"+pref);
   
   v_mc_DEFAULT.push_back("Pt-15to20_JPCalib"+pref);
   v_mc_DEFAULT.push_back("Pt-20to30_JPCalib"+pref);
   v_mc_DEFAULT.push_back("Pt-30to50_JPCalib"+pref);
   v_mc_DEFAULT.push_back("Pt-50to80_JPCalib"+pref);
   v_mc_DEFAULT.push_back("Pt-80to120_JPCalib"+pref);
   v_mc_DEFAULT.push_back("Pt-120to170_JPCalib"+pref);
   v_mc_DEFAULT.push_back("Pt-170to300_JPCalib"+pref);
   v_mc_DEFAULT.push_back("Pt-300to470_JPCalib"+pref);
   v_mc_DEFAULT.push_back("Pt-470to600_JPCalib"+pref);
   v_mc_DEFAULT.push_back("Pt-600to800_JPCalib"+pref);
   v_mc_DEFAULT.push_back("Pt-800to1000_JPCalib"+pref);

   v_mc_filt = &v_mc_DEFAULT;
   v_mc_unfilt = &v_mc_DEFAULT;
}

#endif

   
