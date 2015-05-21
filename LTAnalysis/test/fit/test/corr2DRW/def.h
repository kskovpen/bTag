#ifndef FITDEF_H
#define FITDEF_H

   const int kb = 625;
//   const int kb = 391;
   const int kc = 600;
   const int kl = 414;

   bool extSys = 1;

//   const int kb = 2;
//   const int kc = 4;
//   const int kl = 3;

   std::vector<std::string> 
     v_data,
     v_mc_DEFAULT;

   std::vector<std::string> *v_mc_filt,*v_mc_unfilt;
   
   std::string pref = "/data.root";

   std::string lumi = "";

void def()
{
   v_data.push_back("BTag_Run2012A-22Jan2013_V02-03-02"+pref);
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
   v_mc_DEFAULT.push_back("Pt-800to1000"+pref);

   v_mc_filt = &v_mc_DEFAULT;
   v_mc_unfilt = &v_mc_DEFAULT;
}

#endif

   
