{
//   const int kb = 391;
//   const int kc = 600;
//   const int kl = 632;

   const int kb = 2;
   const int kc = 4;
   const int kl = 3;
   
   std::vector<std::string> 
     v_data,
     v_mc_filt,
     v_mc_unfilt,
     v_mc_filt_IPSMEAR,
     v_mc_unfilt_IPSMEAR;
   
   std::string pref = "/hist/data.root";
   
   std::string lumi = "A-L";
   
   v_data.push_back("data12_8TeV.periodA"+pref);
   v_data.push_back("data12_8TeV.periodB"+pref);
   v_data.push_back("data12_8TeV.periodC"+pref);
   v_data.push_back("data12_8TeV.periodD"+pref);
   v_data.push_back("data12_8TeV.periodE"+pref);
   v_data.push_back("data12_8TeV.periodG"+pref);
   v_data.push_back("data12_8TeV.periodH"+pref);
   v_data.push_back("data12_8TeV.periodI"+pref);
   v_data.push_back("data12_8TeV.periodJ"+pref);
   v_data.push_back("data12_8TeV.periodL"+pref);

//   v_mc_filt.push_back("mc12_8TeV.129280.Pythia8EvtGen_AU2CT10_jetjet_JZ0W_mufilter"+pref);
   v_mc_filt.push_back("mc12_8TeV.129281.Pythia8EvtGen_AU2CT10_jetjet_JZ1W_mufilter"+pref);
   v_mc_filt.push_back("mc12_8TeV.129282.Pythia8EvtGen_AU2CT10_jetjet_JZ2W_mufilter"+pref);
   v_mc_filt.push_back("mc12_8TeV.129283.Pythia8EvtGen_AU2CT10_jetjet_JZ3W_mufilter"+pref);
   v_mc_filt.push_back("mc12_8TeV.129284.Pythia8EvtGen_AU2CT10_jetjet_JZ4W_mufilter"+pref);
   v_mc_filt.push_back("mc12_8TeV.129285.Pythia8EvtGen_AU2CT10_jetjet_JZ5W_mufilter"+pref);
   
   v_mc_unfilt.push_back("mc12_8TeV.129270.Pythia8EvtGen_AU2CT10_jetjet_JZ0W"+pref);
   v_mc_unfilt.push_back("mc12_8TeV.129271.Pythia8EvtGen_AU2CT10_jetjet_JZ1W"+pref);
   v_mc_unfilt.push_back("mc12_8TeV.129272.Pythia8EvtGen_AU2CT10_jetjet_JZ2W"+pref);
   v_mc_unfilt.push_back("mc12_8TeV.129273.Pythia8EvtGen_AU2CT10_jetjet_JZ3W"+pref);
   v_mc_unfilt.push_back("mc12_8TeV.129274.Pythia8EvtGen_AU2CT10_jetjet_JZ4W"+pref);

//   v_mc_filt_IPSMEAR.push_back("mc12_8TeV.129280.Pythia8EvtGen_AU2CT10_jetjet_JZ0W_mufilter_IPSMEAR"+pref);
   v_mc_filt_IPSMEAR.push_back("mc12_8TeV.129281.Pythia8EvtGen_AU2CT10_jetjet_JZ1W_mufilter_IPSMEAR"+pref);
   v_mc_filt_IPSMEAR.push_back("mc12_8TeV.129282.Pythia8EvtGen_AU2CT10_jetjet_JZ2W_mufilter_IPSMEAR"+pref);
   v_mc_filt_IPSMEAR.push_back("mc12_8TeV.129283.Pythia8EvtGen_AU2CT10_jetjet_JZ3W_mufilter_IPSMEAR"+pref);
   v_mc_filt_IPSMEAR.push_back("mc12_8TeV.129284.Pythia8EvtGen_AU2CT10_jetjet_JZ4W_mufilter_IPSMEAR"+pref);
   v_mc_filt_IPSMEAR.push_back("mc12_8TeV.129285.Pythia8EvtGen_AU2CT10_jetjet_JZ5W_mufilter_IPSMEAR"+pref);
   
   v_mc_unfilt_IPSMEAR.push_back("mc12_8TeV.129270.Pythia8EvtGen_AU2CT10_jetjet_JZ0W_IPSMEAR"+pref);
   v_mc_unfilt_IPSMEAR.push_back("mc12_8TeV.129271.Pythia8EvtGen_AU2CT10_jetjet_JZ1W_IPSMEAR"+pref);
   v_mc_unfilt_IPSMEAR.push_back("mc12_8TeV.129272.Pythia8EvtGen_AU2CT10_jetjet_JZ2W_IPSMEAR"+pref);
   v_mc_unfilt_IPSMEAR.push_back("mc12_8TeV.129273.Pythia8EvtGen_AU2CT10_jetjet_JZ3W_IPSMEAR"+pref);
   v_mc_unfilt_IPSMEAR.push_back("mc12_8TeV.129274.Pythia8EvtGen_AU2CT10_jetjet_JZ4W_IPSMEAR"+pref);
   
const int Nbins = 153;
double xbins[Nbins+1] = {
   0,0.005,0.010,0.015,0.016,0.017,0.018,0.019,
     0.020,0.021,0.022,0.023,0.024,0.025,
     0.026,0.027,0.028,0.029,0.030,
     0.031,0.032,0.033,0.034,0.035,0.036,
     0.037,0.038,0.039,0.040,0.041,0.042,
     0.043,0.044,0.045,0.046,0.047,0.048,
     0.049,0.050,0.051,0.052,0.053,0.054,
     0.055,0.056,0.057,0.058,0.059,0.060,
     0.061,0.062,0.063,0.064,0.065,0.066,
     0.067,0.068,0.069,0.070,0.071,0.072,
     0.073,0.074,0.075,0.076,0.077,0.078,
     0.079,0.080,0.081,0.082,0.083,0.084,
     0.085,0.086,0.087,0.088,0.089,0.090,
     0.091,0.092,0.093,0.094,0.095,0.096,
     0.097,0.098,0.099,0.100,0.102,0.104,
     0.106,0.110,0.115,0.120,0.125,
     0.130,0.135,0.140,0.145,0.150,
     0.155,0.160,0.165,0.170,0.175,
     0.180,0.185,0.190,0.195,0.200,
     0.205,0.210,0.215,0.220,0.225,
     0.230,0.235,0.240,0.245,0.250,
     0.255,0.260,0.270,0.280,0.290,
     0.300,0.310,0.320,0.330,0.340,
     0.360,0.380,0.400,0.420,0.440,
     0.460,0.480,0.500,0.550,0.600,
     0.650,0.700,0.750,0.800,0.850,
     0.900,0.950,1.000,1.250,1.500,
     1.750,2.000,2.500};
}   

   
