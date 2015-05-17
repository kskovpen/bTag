#ifndef FITDEF_H
#define FITDEF_H

   const int kb = 625;
//   const int kb = 391;
   const int kc = 591;
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
   // non-merged
   if( !extSys )
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
     }
   else
     {
	v_data.push_back("DATA"+pref);
	
	v_mc_DEFAULT.push_back("MC"+pref);
     }   
   
   // merged
/*   v_data.push_back("BTag_Run2012A-22Jan2013"+pref);
   v_data.push_back("BTag_Run2012B-22Jan2013"+pref);
   v_data.push_back("BTag_Run2012C-22Jan2013"+pref);
   v_data.push_back("BTag_Run2012D-22Jan2013"+pref);

   v_mc_DEFAULT.push_back("JetTree_mc_subjets_Pt-15to20"+pref);
   v_mc_DEFAULT.push_back("JetTree_mc_subjets_Pt-20to30"+pref);
   v_mc_DEFAULT.push_back("JetTree_mc_subjets_Pt-30to50"+pref);
   v_mc_DEFAULT.push_back("JetTree_mc_subjets_Pt-50to80"+pref);
   v_mc_DEFAULT.push_back("JetTree_mc_subjets_Pt-80to120"+pref);
   v_mc_DEFAULT.push_back("JetTree_mc_subjets_Pt-120to170"+pref);
   v_mc_DEFAULT.push_back("JetTree_mc_subjets_Pt-170to300"+pref);
   v_mc_DEFAULT.push_back("JetTree_mc_subjets_Pt-300to470"+pref);
   v_mc_DEFAULT.push_back("JetTree_mc_subjets_Pt-470to600"+pref);
   v_mc_DEFAULT.push_back("JetTree_mc_subjets_Pt-600to800"+pref);
   v_mc_DEFAULT.push_back("JetTree_mc_subjets_Pt-800to1000"+pref);
*/   

   v_mc_filt = &v_mc_DEFAULT;
   v_mc_unfilt = &v_mc_DEFAULT;
}

const int Nbins = 240;
double xbins[Nbins+1] = {
   0,
   0.010,0.015,
   0.020,
   0.021,0.022,0.023,0.024,0.025,0.026,0.027,0.028,0.029,0.030, // pt20t30
   0.031,0.032,0.033,0.034,0.035,0.036,0.037,0.038,0.039,0.040, // pt30t40
   0.041,0.042,0.043,0.044,0.045,0.046,0.047,0.048,0.049,0.050, // pt40t50
   0.051,0.052,0.053,0.054,0.055,0.056,0.057,0.058,0.059,0.060, // pt50t60
   0.061,0.062,0.063,0.064,0.065,0.066,0.067,0.068,0.069,0.070, // pt60t70
   0.071,0.072,0.073,0.074,0.075,0.076,0.077,0.078,0.079,0.080, // pt70t80
   0.081,0.082,0.083,0.084,0.085,0.086,0.087,0.088,0.089,0.090, // pt80t100
   0.091,0.092,0.093,0.094,0.095,0.096,0.097,0.098,0.099,0.100,
   0.101,0.102,0.103,0.104,0.105,0.106,0.107,0.108,0.109,0.110, // pt100t120
   0.111,0.112,0.113,0.114,0.115,0.116,0.117,0.118,0.119,0.120,
   0.120,0.122,0.124,0.126,0.128,0.130,0.132,0.134,0.136,0.138, // pt120t160
   0.140,0.142,0.144,0.146,0.148,0.150,0.152,0.154,0.156,0.158,
   0.160,0.162,0.164,0.166,0.168,0.170,0.172,0.174,0.176,0.178, // pt160t210
   0.180,0.182,0.184,0.186,0.188,0.190,0.192,0.194,0.196,0.198,
   0.200,0.202,0.204,0.206,0.208,
   0.210,0.212,0.214,0.216,0.218,0.220,0.222,0.224,0.226,0.228, // pt210t260
   0.230,0.232,0.234,0.236,0.238,0.240,0.242,0.244,0.246,0.248,
   0.250,0.252,0.254,0.256,0.258,
   0.260,0.264,0.268,0.272,0.276,0.280,0.284,0.288,0.292,0.296, // pt260t320
   0.300,0.304,0.308,0.312,0.316,
   0.320,0.325,0.330,0.335,0.340,0.345,0.350,0.355,0.360,0.365, // pt320t400
   0.370,0.375,0.380,0.385,0.390,0.395,
   0.400,0.410,0.420,0.430,0.440,0.450,0.460,0.470,0.480,0.490, // pt400t500
   0.500,0.510,0.520,0.530,0.540,0.550,0.560,0.570,0.580,0.590, // pt500t600
   0.600,0.620,0.640,0.660,0.680,0.700,0.720,0.740,0.760,0.780, // pt600t800
   0.800,0.840,0.880,0.920,0.960, // pt800t1000
   1.00};

#endif

   
