// https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagPOG#2012_Data_and_MC_EPS13_prescript
// EPS13 official SFs

const int npt = 16;

double pt[npt] = {
   25.,
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
   550.,
   700.
};

void SF_CSVL_withTTBAR(double pt)
{   
   return 0.997942*((1.+(0.00923753*pt))/(1.+(0.0096119*pt)));
}

double SF_CSVL_withTTBAR_error[] = {
 0.033299,
 0.0146768,
 0.013803,
 0.0170145,
 0.0166976,
 0.0137879,
 0.0149072,
 0.0153068,
 0.0133077,
 0.0123737,
 0.0157152,
 0.0175161,
 0.0209241,
 0.0278605,
 0.0346928,
 0.0350099 };

void SF_CSVM_withTTBAR(double pt)
{
   return (0.938887+(0.00017124*pt))+(-2.76366e-07*(pt*pt));
}

double SF_CSVM_withTTBAR_error[] = {
 0.0415707,
 0.0204209,
 0.0223227,
 0.0206655,
 0.0199325,
 0.0174121,
 0.0202332,
 0.0182446,
 0.0159777,
 0.0218531,
 0.0204688,
 0.0265191,
 0.0313175,
 0.0415417,
 0.0740446,
 0.0596716 };

void SF_CSVT_withTTBAR(double pt)
{   
   return (0.927563+(1.55479e-05*pt))+(-1.90666e-07*(pt*pt));
}

double SF_CSVT_withTTBAR_error[] = {
 0.0515703,
 0.0264008,
 0.0272757,
 0.0275565,
 0.0248745,
 0.0218456,
 0.0253845,
 0.0239588,
 0.0271791,
 0.0273912,
 0.0379822,
 0.0411624,
 0.0786307,
 0.0866832,
 0.0942053,
 0.102403 };

void SF_CSVL(double pt)
{   
   return 1.00572*((1.+(0.013676*pt))/(1.+(0.0143279*pt)));
}

double SF_CSVL_error[] = {
 0.033408,
 0.015446,
 0.0146992,
 0.0183964,
 0.0185363,
 0.0145547,
 0.0176743,
 0.0203609,
 0.0143342,
 0.0148771,
 0.0157936,
 0.0176496,
 0.0209156,
 0.0278529,
 0.0346877,
 0.0350101 };

void SF_CSVM(double pt)
{
   return (0.939158+(0.000158694*pt))+(-2.53962e-07*(pt*pt));
}

double SF_CSVM_error[] = {
 0.0415694,
 0.023429,
 0.0261074,
 0.0239251,
 0.0232416,
 0.0197251,
 0.0217319,
 0.0198108,
 0.0193,
 0.0276144,
 0.0205839,
 0.026915,
 0.0312739,
 0.0415054,
 0.0740561,
 0.0598311 };

void SF_CSVT(double pt)
{   
   return (0.9203+(-3.32421e-05*pt))+(-7.74664e-08*(pt*pt));
}

double SF_CSVT_error[] = {
 0.0511028,
 0.0306671,
 0.0317498,
 0.032779,
 0.0291528,
 0.0249308,
 0.0301118,
 0.032047,
 0.0348072,
 0.0357745,
 0.0378756,
 0.0412608,
 0.0777516,
 0.0860741,
 0.0942209,
 0.104106 };

void print()
{
   std::ofstream f_SF_CSVL_withTTBAR("CSVL_withTTBAR.txt");
   std::ofstream f_SF_CSVM_withTTBAR("CSVM_withTTBAR.txt");
   std::ofstream f_SF_CSVT_withTTBAR("CSVT_withTTBAR.txt");
   std::ofstream f_SF_CSVL("CSVL.txt");
   std::ofstream f_SF_CSVM("CSVM.txt");
   std::ofstream f_SF_CSVT("CSVT.txt");
   for(int i=0;i<npt;i++)
     {
	double x = pt[i];

	double SF_CSVL_withTTBAR_val = SF_CSVL_withTTBAR(x);
	double err_SF_CSVL_withTTBAR = SF_CSVL_withTTBAR_error[i];
	f_SF_CSVL_withTTBAR << SF_CSVL_withTTBAR_val << "   "  << err_SF_CSVL_withTTBAR << std::endl;

	double SF_CSVM_withTTBAR_val = SF_CSVM_withTTBAR(x);
	double err_SF_CSVM_withTTBAR = SF_CSVM_withTTBAR_error[i];
	f_SF_CSVM_withTTBAR << SF_CSVM_withTTBAR_val << "   "  << err_SF_CSVM_withTTBAR << std::endl;
	
	double SF_CSVT_withTTBAR_val = SF_CSVT_withTTBAR(x);
	double err_SF_CSVT_withTTBAR = SF_CSVT_withTTBAR_error[i];
	f_SF_CSVT_withTTBAR << SF_CSVT_withTTBAR_val << "   "  << err_SF_CSVT_withTTBAR << std::endl;

	double SF_CSVL_val = SF_CSVL(x);
	double err_SF_CSVL = SF_CSVL_error[i];
	f_SF_CSVL << SF_CSVL_val << "   "  << err_SF_CSVL << std::endl;

	double SF_CSVM_val = SF_CSVM(x);
	double err_SF_CSVM = SF_CSVM_error[i];
	f_SF_CSVM << SF_CSVM_val << "   "  << err_SF_CSVM << std::endl;
	
	double SF_CSVT_val = SF_CSVT(x);
	double err_SF_CSVT = SF_CSVT_error[i];
	f_SF_CSVT << SF_CSVT_val << "   "  << err_SF_CSVT << std::endl;
     }   
   f_SF_CSVL_withTTBAR.close();
   f_SF_CSVM_withTTBAR.close();
   f_SF_CSVT_withTTBAR.close();
   f_SF_CSVL.close();
   f_SF_CSVM.close();
   f_SF_CSVT.close();
   
   gApplication->Terminate();
}
