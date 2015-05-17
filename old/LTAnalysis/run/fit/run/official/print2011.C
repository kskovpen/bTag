// https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagPOG#2012_Data_and_MC_EPS13_prescript
// EPS13 official SFs

const int npt = 14;

double pt[npt] = {
   35.,
   45.,
   55.,
   65.,
   75.,
   90.,
   110.,
   140.,
   185.,
   235.,
   290.,
   360.,
   450.,
   585.
};

void SF_CSVL(double pt)
{   
   return 1.02658*((1.+(0.0195388*pt))/(1.+(0.0209145*pt)));
}

double SF_CSVL_error[] = {
   0.0188743,
   0.0161816,
   0.0139824,
   0.0152644,
   0.0161226,
   0.0157396,
   0.0161619,
   0.0168747,
   0.0257175,
   0.026424,
   0.0264928,
   0.0315127,
   0.030734,
   0.0438259
};

void SF_CSVM(double pt)
{   
   return 0.6981*((1.+(0.414063*pt))/(1.+(0.300155*pt)));
}

double SF_CSVM_error[] = {
   0.0295675,
   0.0295095,
   0.0210867,
   0.0219349,
   0.0227033,
   0.0204062,
   0.0185857,
   0.0256242,
   0.0383341,
   0.0409675,
   0.0420284,
   0.0541299,
   0.0578761,
   0.0655432
};

void SF_CSVT(double pt)
{   
   return 0.901615*((1.+(0.552628*pt))/(1.+(0.547195*pt)));
}

double SF_CSVT_error[] = {
   0.0364717,
   0.0362281,
   0.0232876,
   0.0249618,
   0.0261482,
   0.0290466,
   0.0300033,
   0.0453252,
   0.0685143,
   0.0653621,
   0.0712586,
   0.094589,
   0.0777011,
   0.0866563
};

void SF_TCHPM(double pt)
{   
   return 0.616456*((1.+(0.145816*pt))/(1.+(0.0904067*pt)));
}

double SF_TCHPM_error[] = {
   0.0365776,
   0.036307,
   0.0261062,
   0.0270308,
   0.0276016,
   0.0175067,
   0.0179022,
   0.0198104,
   0.0197836,
   0.024912,
   0.0273767,
   0.0398119,
   0.0418751,
   0.0605975
};

void SF_TCHPT(double pt)
{   
   return 0.895596*((1.+(9.43219e-05*pt))/(1.+(-4.63927e-05*pt)));
}

double SF_TCHPT_error[] = {
   0.0543376,
   0.0534339,
   0.0266156,
   0.0271337,
   0.0276364,
   0.0308838,
   0.0381656,
   0.0336979,
   0.0336773,
   0.0347688,
   0.0376865,
   0.0556052,
   0.0598105,
   0.0861122
};

void print2011()
{
   std::ofstream f_SF_CSVL("CSVL_2011.txt");
   std::ofstream f_SF_CSVM("CSVM_2011.txt");
   std::ofstream f_SF_CSVT("CSVT_2011.txt");

   std::ofstream f_SF_TCHPM("TCHPM_2011.txt");
   std::ofstream f_SF_TCHPT("TCHPT_2011.txt");
   
   for(int i=0;i<npt;i++)
     {
	double x = pt[i];

	double SF_CSVL_val = SF_CSVL(x);
	double err_SF_CSVL = SF_CSVL_error[i];
	f_SF_CSVL << SF_CSVL_val << "   "  << err_SF_CSVL << std::endl;

	double SF_CSVM_val = SF_CSVM(x);
	double err_SF_CSVM = SF_CSVM_error[i];
	f_SF_CSVM << SF_CSVM_val << "   "  << err_SF_CSVM << std::endl;

	double SF_CSVT_val = SF_CSVT(x);
	double err_SF_CSVT = SF_CSVT_error[i];
	f_SF_CSVT << SF_CSVT_val << "   "  << err_SF_CSVT << std::endl;

	double SF_TCHPM_val = SF_TCHPM(x);
	double err_SF_TCHPM = SF_TCHPM_error[i];
	f_SF_TCHPM << SF_TCHPM_val << "   "  << err_SF_TCHPM << std::endl;

	double SF_TCHPT_val = SF_TCHPT(x);
	double err_SF_TCHPT = SF_TCHPT_error[i];
	f_SF_TCHPT << SF_TCHPT_val << "   "  << err_SF_TCHPT << std::endl;
     }   
   
   f_SF_CSVL.close();
   f_SF_CSVM.close();
   f_SF_CSVT.close();

   f_SF_TCHPM.close();
   f_SF_TCHPT.close();
   
   gApplication->Terminate();
}
