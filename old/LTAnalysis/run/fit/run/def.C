{
   const int kb = 2;
   const int kc = 4;
   const int kl = 3;
   
   std::vector<std::string> 
     v_data,
     v_mc_filt,
     v_mc_unfilt;
   
   std::string pref = "/data.root";
   
   std::string lumi = "A-L";
   
   v_mc_filt.push_back("Pt-15to20"+pref);
   v_mc_filt.push_back("Pt-20to30"+pref);
   v_mc_filt.push_back("Pt-30to50"+pref);
   v_mc_filt.push_back("Pt-50to80"+pref);
   v_mc_filt.push_back("Pt-80to120"+pref);
   v_mc_filt.push_back("Pt-120to170"+pref);
   v_mc_filt.push_back("Pt-170to300"+pref);
   v_mc_filt.push_back("Pt-300to470"+pref);
   v_mc_filt.push_back("Pt-470to600"+pref);
   v_mc_filt.push_back("Pt-600to800"+pref);
   v_mc_filt.push_back("Pt-800to1000"+pref);
}   

   
