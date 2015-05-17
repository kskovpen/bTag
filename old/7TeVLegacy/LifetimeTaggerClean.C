// The measured b-tagging efficiencies and scale factors for 7 TeV Legacy samples with LT method (AN-2014/069)
// 
// contact: Kirill.Skovpen@cern.ch
//
// All uncertainties are absolute uncertainties wrt central values
// 
// eff_JP - efficiency in data
// effMC_JP - efficiency in MC
// eff_stat_JP - stat uncertainty for efficiency in data
// effMC_stat_JP - stat uncertainty for efficiency in MC
// sf_JP - scale factor
// sf_stat_JP - stat uncertainty for scale factor
// sf_syst_up_JP, sf_syst_down_JP - total syst uncertainty for scale factor
// 
// breakdown of systematic uncertainty (to be summed in quadrature):
// 
// ntrk - syst uncertainty due to number of tracks in a jet
// njet - syst uncertainty due to number of jets
// mupt - syst uncertainty due to muon pt
// jeta - syst uncertainty due to jet eta
// pu - pileup uncertainty
// gsplit - gluon splitting
// bfrag - b-quark fragmentation function
// dmux - branching ratios of D->muX
// cfrag - c->D fragmentation rate
// ksl - K0S(Lambda) production fraction
// ntrkgen - number of generated tracks from b- and c-hadron decays
// jes - jet energy scale
// jer - jet energy resolution
// cb - Cb factor uncertainty (jets with no JP information)
// add - additional uncertainty (dependence on correlation factor, variation of selection criteria)

//float x[20], ex[20];
 x[4][0]  =  25.; ex[4][0]  =  5.; 
 x[4][1]  =  35.; ex[4][1]  =  5.;
 x[4][2]  =  45.; ex[4][2]  =  5.;
 x[4][3]  =  55.; ex[4][3]  =  5.;
 x[4][4]  =  65.; ex[4][4]  =  5.;
 x[4][5]  =  75.; ex[4][5]  =  5.;
 x[4][6]  =  90.; ex[4][6]  = 10.;
 x[4][7]  = 110.; ex[4][7]  = 10.;
 x[4][8]  = 140.; ex[4][8]  = 20.;
 x[4][9]  = 185.; ex[4][9]  = 25.;
 x[4][10] = 235.; ex[4][10] = 25.; 
 x[4][11] = 290.; ex[4][11] = 30.;
 x[4][12] = 360.; ex[4][12] = 40.;
 x[4][13] = 450.; ex[4][13] = 50.;
 x[4][14] = 585.; ex[4][14] = 85.;


void ReadLifetimeTaggerMeasurements(TString Tagger) {

  if (Tagger=="CSVL") {
    
// CSVL : JP
eff_JP[0] = ; eff_stat_JP[0] = ; effMC_JP[0] = ; effMC_stat_JP[0] = ; sf_JP[0] = ; sf_stat_JP[0] = ;
eff_JP[1] = ; eff_stat_JP[1] = ; effMC_JP[1] = ; effMC_stat_JP[1] = ; sf_JP[1] = ; sf_stat_JP[1] = ; 
eff_JP[2] = ; eff_stat_JP[2] = ; effMC_JP[2] = ; effMC_stat_JP[2] = ; sf_JP[2] = ; sf_stat_JP[2] = ; 
eff_JP[3] = ; eff_stat_JP[3] = ; effMC_JP[3] = ; effMC_stat_JP[3] = ; sf_JP[3] = ; sf_stat_JP[3] = ; 
eff_JP[4] = ; eff_stat_JP[4] = ; effMC_JP[4] = ; effMC_stat_JP[4] = ; sf_JP[4] = ; sf_stat_JP[4] = ; 
eff_JP[5] = ; eff_stat_JP[5] = ; effMC_JP[5] = ; effMC_stat_JP[5] = ; sf_JP[5] = ; sf_stat_JP[5] = ; 
eff_JP[6] = ; eff_stat_JP[6] = ; effMC_JP[6] = ; effMC_stat_JP[6] = ; sf_JP[6] = ; sf_stat_JP[6] = ; 
eff_JP[7] = ; eff_stat_JP[7] = ; effMC_JP[7] = ; effMC_stat_JP[7] = ; sf_JP[7] = ; sf_stat_JP[7] = ; 
eff_JP[8] = ; eff_stat_JP[8] = ; effMC_JP[8] = ; effMC_stat_JP[8] = ; sf_JP[8] = ; sf_stat_JP[8] = ; 
eff_JP[9] = ; eff_stat_JP[9] = ; effMC_JP[9] = ; effMC_stat_JP[9] = ; sf_JP[9] = ; sf_stat_JP[9] = ; 
eff_JP[10] = ; eff_stat_JP[10] = ; effMC_JP[10] = ; effMC_stat_JP[10] = ; sf_JP[10] = ; sf_stat_JP[10] = ;
eff_JP[11] = ; eff_stat_JP[11] = ; effMC_JP[11] = ; effMC_stat_JP[11] = ; sf_JP[11] = ; sf_stat_JP[11] = ;
eff_JP[12] = ; eff_stat_JP[12] = ; effMC_JP[12] = ; effMC_stat_JP[12] = ; sf_JP[12] = ; sf_stat_JP[12] = ;
eff_JP[13] = ; eff_stat_JP[13] = ; effMC_JP[13] = ; effMC_stat_JP[13] = ; sf_JP[13] = ; sf_stat_JP[13] = ;
eff_JP[14] = ; eff_stat_JP[14] = ; effMC_JP[14] = ; effMC_stat_JP[14] = ; sf_JP[14] = ; sf_stat_JP[14] = ;
sf_syst_up_JP[0] = ; sf_syst_down_JP[0] = ;
ntrk_up_JP[0] = ; ntrk_down_JP[0] = ; njet_up_JP[0] = ; njet_down_JP[0] = ; mupt_up_JP[0] = ; mupt_down_JP[0] = ; jeta_up_JP[0] = ; jeta_down_JP[0] = ; pu_up_JP[0] = ; pu_down_JP[0] = ; gsplit_up_JP[0] = ; gsplit_down_JP[0] = ; bfrag_up_JP[0] = ; bfrag_down_JP[0] = ; dmux_up_JP[0] = ; dmux_down_JP[0] = ; cfrag_up_JP[0] = ; cfrag_down_JP[0] = ; ksl_up_JP[0] = ; ksl_down_JP[0] = ; ntrkgen_up_JP[0] = ; ntrkgen_down_JP[0] = ; jes_up_JP[0] = ; jes_down_JP[0] = ; jer_up_JP[0] = ; jer_down_JP[0] = ; cb_up_JP[0] = ; cb_down_JP[0] = ; add_up_JP[0] = ; add_down_JP[0] = ;
sf_syst_up_JP[1] = ; sf_syst_down_JP[1] = ;
ntrk_up_JP[1] = ; ntrk_down_JP[1] = ; njet_up_JP[1] = ; njet_down_JP[1] = ; mupt_up_JP[1] = ; mupt_down_JP[1] = ; jeta_up_JP[1] = ; jeta_down_JP[1] = ; pu_up_JP[1] = ; pu_down_JP[1] = ; gsplit_up_JP[1] = ; gsplit_down_JP[1] = ; bfrag_up_JP[1] = ; bfrag_down_JP[1] = ; dmux_up_JP[1] = ; dmux_down_JP[1] = ; cfrag_up_JP[1] = ; cfrag_down_JP[1] = ; ksl_up_JP[1] = ; ksl_down_JP[1] = ; ntrkgen_up_JP[1] = ; ntrkgen_down_JP[1] = ; jes_up_JP[1] = ; jes_down_JP[1] = ; jer_up_JP[1] = ; jer_down_JP[1] = ; cb_up_JP[1] = ; cb_down_JP[1] = ; add_up_JP[1] = ; add_down_JP[1] = ;
sf_syst_up_JP[2] = ; sf_syst_down_JP[2] = ;
ntrk_up_JP[2] = ; ntrk_down_JP[2] = ; njet_up_JP[2] = ; njet_down_JP[2] = ; mupt_up_JP[2] = ; mupt_down_JP[2] = ; jeta_up_JP[2] = ; jeta_down_JP[2] = ; pu_up_JP[2] = ; pu_down_JP[2] = ; gsplit_up_JP[2] = ; gsplit_down_JP[2] = ; bfrag_up_JP[2] = ; bfrag_down_JP[2] = ; dmux_up_JP[2] = ; dmux_down_JP[2] = ; cfrag_up_JP[2] = ; cfrag_down_JP[2] = ; ksl_up_JP[2] = ; ksl_down_JP[2] = ; ntrkgen_up_JP[2] = ; ntrkgen_down_JP[2] = ; jes_up_JP[2] = ; jes_down_JP[2] = ; jer_up_JP[2] = ; jer_down_JP[2] = ; cb_up_JP[2] = ; cb_down_JP[2] = ; add_up_JP[2] = ; add_down_JP[2] = ;
sf_syst_up_JP[3] = ; sf_syst_down_JP[3] = ;
ntrk_up_JP[3] = ; ntrk_down_JP[3] = ; njet_up_JP[3] = ; njet_down_JP[3] = ; mupt_up_JP[3] = ; mupt_down_JP[3] = ; jeta_up_JP[3] = ; jeta_down_JP[3] = ; pu_up_JP[3] = ; pu_down_JP[3] = ; gsplit_up_JP[3] = ; gsplit_down_JP[3] = ; bfrag_up_JP[3] = ; bfrag_down_JP[3] = ; dmux_up_JP[3] = ; dmux_down_JP[3] = ; cfrag_up_JP[3] = ; cfrag_down_JP[3] = ; ksl_up_JP[3] = ; ksl_down_JP[3] = ; ntrkgen_up_JP[3] = ; ntrkgen_down_JP[3] = ; jes_up_JP[3] = ; jes_down_JP[3] = ; jer_up_JP[3] = ; jer_down_JP[3] = ; cb_up_JP[3] = ; cb_down_JP[3] = ; add_up_JP[3] = ; add_down_JP[3] = ;
sf_syst_up_JP[4] = ; sf_syst_down_JP[4] = ;
ntrk_up_JP[4] = ; ntrk_down_JP[4] = ; njet_up_JP[4] = ; njet_down_JP[4] = ; mupt_up_JP[4] = ; mupt_down_JP[4] = ; jeta_up_JP[4] = ; jeta_down_JP[4] = ; pu_up_JP[4] = ; pu_down_JP[4] = ; gsplit_up_JP[4] = ; gsplit_down_JP[4] = ; bfrag_up_JP[4] = ; bfrag_down_JP[4] = ; dmux_up_JP[4] = ; dmux_down_JP[4] = ; cfrag_up_JP[4] = ; cfrag_down_JP[4] = ; ksl_up_JP[4] = ; ksl_down_JP[4] = ; ntrkgen_up_JP[4] = ; ntrkgen_down_JP[4] = ; jes_up_JP[4] = ; jes_down_JP[4] = ; jer_up_JP[4] = ; jer_down_JP[4] = ; cb_up_JP[4] = ; cb_down_JP[4] = ; add_up_JP[4] = ; add_down_JP[4] = ;
sf_syst_up_JP[5] = ; sf_syst_down_JP[5] = ;
ntrk_up_JP[5] = ; ntrk_down_JP[5] = ; njet_up_JP[5] = ; njet_down_JP[5] = ; mupt_up_JP[5] = ; mupt_down_JP[5] = ; jeta_up_JP[5] = ; jeta_down_JP[5] = ; pu_up_JP[5] = ; pu_down_JP[5] = ; gsplit_up_JP[5] = ; gsplit_down_JP[5] = ; bfrag_up_JP[5] = ; bfrag_down_JP[5] = ; dmux_up_JP[5] = ; dmux_down_JP[5] = ; cfrag_up_JP[5] = ; cfrag_down_JP[5] = ; ksl_up_JP[5] = ; ksl_down_JP[5] = ; ntrkgen_up_JP[5] = ; ntrkgen_down_JP[5] = ; jes_up_JP[5] = ; jes_down_JP[5] = ; jer_up_JP[5] = ; jer_down_JP[5] = ; cb_up_JP[5] = ; cb_down_JP[4] = ; add_up_JP[5] = ; add_down_JP[5] = ;
sf_syst_up_JP[6] = ; sf_syst_down_JP[6] = ;
ntrk_up_JP[6] = ; ntrk_down_JP[6] = ; njet_up_JP[6] = ; njet_down_JP[6] = ; mupt_up_JP[6] = ; mupt_down_JP[6] = ; jeta_up_JP[6] = ; jeta_down_JP[6] = ; pu_up_JP[6] = ; pu_down_JP[6] = ; gsplit_up_JP[6] = ; gsplit_down_JP[6] = ; bfrag_up_JP[6] = ; bfrag_down_JP[6] = ; dmux_up_JP[6] = ; dmux_down_JP[6] = ; cfrag_up_JP[6] = ; cfrag_down_JP[6] = ; ksl_up_JP[6] = ; ksl_down_JP[6] = ; ntrkgen_up_JP[6] = ; ntrkgen_down_JP[6] = ; jes_up_JP[6] = ; jes_down_JP[6] = ; jer_up_JP[6] = ; jer_down_JP[6] = ; cb_up_JP[6] = ; cb_down_JP[6] = ; add_up_JP[6] = ; add_down_JP[6] = ;
sf_syst_up_JP[7] = ; sf_syst_down_JP[7] = ;
ntrk_up_JP[7] = ; ntrk_down_JP[7] = ; njet_up_JP[7] = ; njet_down_JP[7] = ; mupt_up_JP[7] = ; mupt_down_JP[7] = ; jeta_up_JP[7] = ; jeta_down_JP[7] = ; pu_up_JP[7] = ; pu_down_JP[7] = ; gsplit_up_JP[7] = ; gsplit_down_JP[7] = ; bfrag_up_JP[7] = ; bfrag_down_JP[7] = ; dmux_up_JP[7] = ; dmux_down_JP[7] = ; cfrag_up_JP[7] = ; cfrag_down_JP[7] = ; ksl_up_JP[7] = ; ksl_down_JP[7] = ; ntrkgen_up_JP[7] = ; ntrkgen_down_JP[7] = ; jes_up_JP[7] = ; jes_down_JP[7] = ; jer_up_JP[7] = ; jer_down_JP[7] = ; cb_up_JP[7] = ; cb_down_JP[7] = ; add_up_JP[7] = ; add_down_JP[7] = ;
sf_syst_up_JP[8] = ; sf_syst_down_JP[8] = ;
ntrk_up_JP[8] = ; ntrk_down_JP[8] = ; njet_up_JP[8] = ; njet_down_JP[8] = ; mupt_up_JP[8] = ; mupt_down_JP[8] = ; jeta_up_JP[8] = ; jeta_down_JP[8] = ; pu_up_JP[8] = ; pu_down_JP[8] = ; gsplit_up_JP[8] = ; gsplit_down_JP[8] = ; bfrag_up_JP[8] = ; bfrag_down_JP[8] = ; dmux_up_JP[8] = ; dmux_down_JP[8] = ; cfrag_up_JP[8] = ; cfrag_down_JP[8] = ; ksl_up_JP[8] = ; ksl_down_JP[8] = ; ntrkgen_up_JP[8] = ; ntrkgen_down_JP[8] = ; jes_up_JP[8] = ; jes_down_JP[8] = ; jer_up_JP[8] = ; jer_down_JP[8] = ; cb_up_JP[8] = ; cb_down_JP[8] = ; add_up_JP[8] = ; add_down_JP[8] = ;
sf_syst_up_JP[9] = ; sf_syst_down_JP[9] = ;
ntrk_up_JP[9] = ; ntrk_down_JP[9] = ; njet_up_JP[9] = ; njet_down_JP[9] = ; mupt_up_JP[9] = ; mupt_down_JP[9] = ; jeta_up_JP[9] = ; jeta_down_JP[9] = ; pu_up_JP[9] = ; pu_down_JP[9] = ; gsplit_up_JP[9] = ; gsplit_down_JP[9] = ; bfrag_up_JP[9] = ; bfrag_down_JP[9] = ; dmux_up_JP[9] = ; dmux_down_JP[9] = ; cfrag_up_JP[9] = ; cfrag_down_JP[9] = ; ksl_up_JP[9] = ; ksl_down_JP[9] = ; ntrkgen_up_JP[9] = ; ntrkgen_down_JP[9] = ; jes_up_JP[9] = ; jes_down_JP[9] = ; jer_up_JP[9] = ; jer_down_JP[9] = ; cb_up_JP[9] = ; cb_down_JP[9] = ; add_up_JP[9] = ; add_down_JP[9] = ;
sf_syst_up_JP[10] = ; sf_syst_down_JP[10] = ;
ntrk_up_JP[10] = ; ntrk_down_JP[10] = ; njet_up_JP[10] = ; njet_down_JP[10] = ; mupt_up_JP[10] = ; mupt_down_JP[10] = ; jeta_up_JP[10] = ; jeta_down_JP[10] = ; pu_up_JP[10] = ; pu_down_JP[10] = ; gsplit_up_JP[10] = ; gsplit_down_JP[10] = ; bfrag_up_JP[10] = ; bfrag_down_JP[10] = ; dmux_up_JP[10] = ; dmux_down_JP[10] = ; cfrag_up_JP[10] = ; cfrag_down_JP[10] = ; ksl_up_JP[10] = ; ksl_down_JP[10] = ; ntrkgen_up_JP[10] = ; ntrkgen_down_JP[10] = ; jes_up_JP[10] = ; jes_down_JP[10] = ; jer_up_JP[10] = ; jer_down_JP[10] = ; cb_up_JP[10] = ; cb_down_JP[10] = ; add_up_JP[10] = ; add_down_JP[10] = ;
sf_syst_up_JP[11] = ; sf_syst_down_JP[11] = ;
ntrk_up_JP[11] = ; ntrk_down_JP[11] = ; njet_up_JP[11] = ; njet_down_JP[11] = ; mupt_up_JP[11] = ; mupt_down_JP[11] = ; jeta_up_JP[11] = ; jeta_down_JP[11] = ; pu_up_JP[11] = ; pu_down_JP[11] = ; gsplit_up_JP[11] = ; gsplit_down_JP[11] = ; bfrag_up_JP[11] = ; bfrag_down_JP[11] = ; dmux_up_JP[11] = ; dmux_down_JP[11] = ; cfrag_up_JP[11] = ; cfrag_down_JP[11] = ; ksl_up_JP[11] = ; ksl_down_JP[11] = ; ntrkgen_up_JP[11] = ; ntrkgen_down_JP[11] = ; jes_up_JP[11] = ; jes_down_JP[11] = ; jer_up_JP[11] = ; jer_down_JP[11] = ; cb_up_JP[11] = ; cb_down_JP[11] = ; add_up_JP[11] = ; add_down_JP[11] = ;
sf_syst_up_JP[12] = ; sf_syst_down_JP[12] = ;
ntrk_up_JP[12] = ; ntrk_down_JP[12] = ; njet_up_JP[12] = ; njet_down_JP[12] = ; mupt_up_JP[12] = ; mupt_down_JP[12] = ; jeta_up_JP[12] = ; jeta_down_JP[12] = ; pu_up_JP[12] = ; pu_down_JP[12] = ; gsplit_up_JP[12] = ; gsplit_down_JP[12] = ; bfrag_up_JP[12] = ; bfrag_down_JP[12] = ; dmux_up_JP[12] = ; dmux_down_JP[12] = ; cfrag_up_JP[12] = ; cfrag_down_JP[12] = ; ksl_up_JP[12] = ; ksl_down_JP[12] = ; ntrkgen_up_JP[12] = ; ntrkgen_down_JP[12] = ; jes_up_JP[12] = ; jes_down_JP[12] = ; jer_up_JP[12] = ; jer_down_JP[12] = ; cb_up_JP[12] = ; cb_down_JP[12] = ; add_up_JP[12] = ; add_down_JP[12] = ;
sf_syst_up_JP[13] = ; sf_syst_down_JP[13] = ;
ntrk_up_JP[13] = ; ntrk_down_JP[13] = ; njet_up_JP[13] = ; njet_down_JP[13] = ; mupt_up_JP[13] = ; mupt_down_JP[13] = ; jeta_up_JP[13] = ; jeta_down_JP[13] = ; pu_up_JP[13] = ; pu_down_JP[13] = ; gsplit_up_JP[13] = ; gsplit_down_JP[13] = ; bfrag_up_JP[13] = ; bfrag_down_JP[13] = ; dmux_up_JP[13] = ; dmux_down_JP[13] = ; cfrag_up_JP[13] = ; cfrag_down_JP[13] = ; ksl_up_JP[13] = ; ksl_down_JP[13] = ; ntrkgen_up_JP[13] = ; ntrkgen_down_JP[13] = ; jes_up_JP[13] = ; jes_down_JP[13] = ; jer_up_JP[13] = ; jer_down_JP[13] = ; cb_up_JP[13] = ; cb_down_JP[13] = ; add_up_JP[13] = ; add_down_JP[13] = ;
sf_syst_up_JP[14] = ; sf_syst_down_JP[14] = ;
ntrk_up_JP[14] = ; ntrk_down_JP[14] = ; njet_up_JP[14] = ; njet_down_JP[14] = ; mupt_up_JP[14] = ; mupt_down_JP[14] = ; jeta_up_JP[14] = ; jeta_down_JP[14] = ; pu_up_JP[14] = ; pu_down_JP[14] = ; gsplit_up_JP[14] = ; gsplit_down_JP[14] = ; bfrag_up_JP[14] = ; bfrag_down_JP[14] = ; dmux_up_JP[14] = ; dmux_down_JP[14] = ; cfrag_up_JP[14] = ; cfrag_down_JP[14] = ; ksl_up_JP[14] = ; ksl_down_JP[14] = ; ntrkgen_up_JP[14] = ; ntrkgen_down_JP[14] = ; jes_up_JP[14] = ; jes_down_JP[14] = ; jer_up_JP[14] = ; jer_down_JP[14] = ; cb_up_JP[14] = ; cb_down_JP[14] = ; add_up_JP[14] = ; add_down_JP[14] = ;

  } else if (Tagger=="CSVM") {
    
// CSVM : JP
eff_JP[0] = ; eff_stat_JP[0] = ; effMC_JP[0] = ; effMC_stat_JP[0] = ; sf_JP[0] = ; sf_stat_JP[0] = ;
eff_JP[1] = ; eff_stat_JP[1] = ; effMC_JP[1] = ; effMC_stat_JP[1] = ; sf_JP[1] = ; sf_stat_JP[1] = ; 
eff_JP[2] = ; eff_stat_JP[2] = ; effMC_JP[2] = ; effMC_stat_JP[2] = ; sf_JP[2] = ; sf_stat_JP[2] = ; 
eff_JP[3] = ; eff_stat_JP[3] = ; effMC_JP[3] = ; effMC_stat_JP[3] = ; sf_JP[3] = ; sf_stat_JP[3] = ; 
eff_JP[4] = ; eff_stat_JP[4] = ; effMC_JP[4] = ; effMC_stat_JP[4] = ; sf_JP[4] = ; sf_stat_JP[4] = ; 
eff_JP[5] = ; eff_stat_JP[5] = ; effMC_JP[5] = ; effMC_stat_JP[5] = ; sf_JP[5] = ; sf_stat_JP[5] = ; 
eff_JP[6] = ; eff_stat_JP[6] = ; effMC_JP[6] = ; effMC_stat_JP[6] = ; sf_JP[6] = ; sf_stat_JP[6] = ; 
eff_JP[7] = ; eff_stat_JP[7] = ; effMC_JP[7] = ; effMC_stat_JP[7] = ; sf_JP[7] = ; sf_stat_JP[7] = ; 
eff_JP[8] = ; eff_stat_JP[8] = ; effMC_JP[8] = ; effMC_stat_JP[8] = ; sf_JP[8] = ; sf_stat_JP[8] = ; 
eff_JP[9] = ; eff_stat_JP[9] = ; effMC_JP[9] = ; effMC_stat_JP[9] = ; sf_JP[9] = ; sf_stat_JP[9] = ; 
eff_JP[10] = ; eff_stat_JP[10] = ; effMC_JP[10] = ; effMC_stat_JP[10] = ; sf_JP[10] = ; sf_stat_JP[10] = ;
eff_JP[11] = ; eff_stat_JP[11] = ; effMC_JP[11] = ; effMC_stat_JP[11] = ; sf_JP[11] = ; sf_stat_JP[11] = ;
eff_JP[12] = ; eff_stat_JP[12] = ; effMC_JP[12] = ; effMC_stat_JP[12] = ; sf_JP[12] = ; sf_stat_JP[12] = ;
eff_JP[13] = ; eff_stat_JP[13] = ; effMC_JP[13] = ; effMC_stat_JP[13] = ; sf_JP[13] = ; sf_stat_JP[13] = ;
eff_JP[14] = ; eff_stat_JP[14] = ; effMC_JP[14] = ; effMC_stat_JP[14] = ; sf_JP[14] = ; sf_stat_JP[14] = ;
sf_syst_up_JP[0] = ; sf_syst_down_JP[0] = ;
ntrk_up_JP[0] = ; ntrk_down_JP[0] = ; njet_up_JP[0] = ; njet_down_JP[0] = ; mupt_up_JP[0] = ; mupt_down_JP[0] = ; jeta_up_JP[0] = ; jeta_down_JP[0] = ; pu_up_JP[0] = ; pu_down_JP[0] = ; gsplit_up_JP[0] = ; gsplit_down_JP[0] = ; bfrag_up_JP[0] = ; bfrag_down_JP[0] = ; dmux_up_JP[0] = ; dmux_down_JP[0] = ; cfrag_up_JP[0] = ; cfrag_down_JP[0] = ; ksl_up_JP[0] = ; ksl_down_JP[0] = ; ntrkgen_up_JP[0] = ; ntrkgen_down_JP[0] = ; jes_up_JP[0] = ; jes_down_JP[0] = ; jer_up_JP[0] = ; jer_down_JP[0] = ; cb_up_JP[0] = ; cb_down_JP[0] = ; add_up_JP[0] = ; add_down_JP[0] = ;
sf_syst_up_JP[1] = ; sf_syst_down_JP[1] = ;
ntrk_up_JP[1] = ; ntrk_down_JP[1] = ; njet_up_JP[1] = ; njet_down_JP[1] = ; mupt_up_JP[1] = ; mupt_down_JP[1] = ; jeta_up_JP[1] = ; jeta_down_JP[1] = ; pu_up_JP[1] = ; pu_down_JP[1] = ; gsplit_up_JP[1] = ; gsplit_down_JP[1] = ; bfrag_up_JP[1] = ; bfrag_down_JP[1] = ; dmux_up_JP[1] = ; dmux_down_JP[1] = ; cfrag_up_JP[1] = ; cfrag_down_JP[1] = ; ksl_up_JP[1] = ; ksl_down_JP[1] = ; ntrkgen_up_JP[1] = ; ntrkgen_down_JP[1] = ; jes_up_JP[1] = ; jes_down_JP[1] = ; jer_up_JP[1] = ; jer_down_JP[1] = ; cb_up_JP[1] = ; cb_down_JP[1] = ; add_up_JP[1] = ; add_down_JP[1] = ;
sf_syst_up_JP[2] = ; sf_syst_down_JP[2] = ;
ntrk_up_JP[2] = ; ntrk_down_JP[2] = ; njet_up_JP[2] = ; njet_down_JP[2] = ; mupt_up_JP[2] = ; mupt_down_JP[2] = ; jeta_up_JP[2] = ; jeta_down_JP[2] = ; pu_up_JP[2] = ; pu_down_JP[2] = ; gsplit_up_JP[2] = ; gsplit_down_JP[2] = ; bfrag_up_JP[2] = ; bfrag_down_JP[2] = ; dmux_up_JP[2] = ; dmux_down_JP[2] = ; cfrag_up_JP[2] = ; cfrag_down_JP[2] = ; ksl_up_JP[2] = ; ksl_down_JP[2] = ; ntrkgen_up_JP[2] = ; ntrkgen_down_JP[2] = ; jes_up_JP[2] = ; jes_down_JP[2] = ; jer_up_JP[2] = ; jer_down_JP[2] = ; cb_up_JP[2] = ; cb_down_JP[2] = ; add_up_JP[2] = ; add_down_JP[2] = ;
sf_syst_up_JP[3] = ; sf_syst_down_JP[3] = ;
ntrk_up_JP[3] = ; ntrk_down_JP[3] = ; njet_up_JP[3] = ; njet_down_JP[3] = ; mupt_up_JP[3] = ; mupt_down_JP[3] = ; jeta_up_JP[3] = ; jeta_down_JP[3] = ; pu_up_JP[3] = ; pu_down_JP[3] = ; gsplit_up_JP[3] = ; gsplit_down_JP[3] = ; bfrag_up_JP[3] = ; bfrag_down_JP[3] = ; dmux_up_JP[3] = ; dmux_down_JP[3] = ; cfrag_up_JP[3] = ; cfrag_down_JP[3] = ; ksl_up_JP[3] = ; ksl_down_JP[3] = ; ntrkgen_up_JP[3] = ; ntrkgen_down_JP[3] = ; jes_up_JP[3] = ; jes_down_JP[3] = ; jer_up_JP[3] = ; jer_down_JP[3] = ; cb_up_JP[3] = ; cb_down_JP[3] = ; add_up_JP[3] = ; add_down_JP[3] = ;
sf_syst_up_JP[4] = ; sf_syst_down_JP[4] = ;
ntrk_up_JP[4] = ; ntrk_down_JP[4] = ; njet_up_JP[4] = ; njet_down_JP[4] = ; mupt_up_JP[4] = ; mupt_down_JP[4] = ; jeta_up_JP[4] = ; jeta_down_JP[4] = ; pu_up_JP[4] = ; pu_down_JP[4] = ; gsplit_up_JP[4] = ; gsplit_down_JP[4] = ; bfrag_up_JP[4] = ; bfrag_down_JP[4] = ; dmux_up_JP[4] = ; dmux_down_JP[4] = ; cfrag_up_JP[4] = ; cfrag_down_JP[4] = ; ksl_up_JP[4] = ; ksl_down_JP[4] = ; ntrkgen_up_JP[4] = ; ntrkgen_down_JP[4] = ; jes_up_JP[4] = ; jes_down_JP[4] = ; jer_up_JP[4] = ; jer_down_JP[4] = ; cb_up_JP[4] = ; cb_down_JP[4] = ; add_up_JP[4] = ; add_down_JP[4] = ;
sf_syst_up_JP[5] = ; sf_syst_down_JP[5] = ;
ntrk_up_JP[5] = ; ntrk_down_JP[5] = ; njet_up_JP[5] = ; njet_down_JP[5] = ; mupt_up_JP[5] = ; mupt_down_JP[5] = ; jeta_up_JP[5] = ; jeta_down_JP[5] = ; pu_up_JP[5] = ; pu_down_JP[5] = ; gsplit_up_JP[5] = ; gsplit_down_JP[5] = ; bfrag_up_JP[5] = ; bfrag_down_JP[5] = ; dmux_up_JP[5] = ; dmux_down_JP[5] = ; cfrag_up_JP[5] = ; cfrag_down_JP[5] = ; ksl_up_JP[5] = ; ksl_down_JP[5] = ; ntrkgen_up_JP[5] = ; ntrkgen_down_JP[5] = ; jes_up_JP[5] = ; jes_down_JP[5] = ; jer_up_JP[5] = ; jer_down_JP[5] = ; cb_up_JP[5] = ; cb_down_JP[4] = ; add_up_JP[5] = ; add_down_JP[5] = ;
sf_syst_up_JP[6] = ; sf_syst_down_JP[6] = ;
ntrk_up_JP[6] = ; ntrk_down_JP[6] = ; njet_up_JP[6] = ; njet_down_JP[6] = ; mupt_up_JP[6] = ; mupt_down_JP[6] = ; jeta_up_JP[6] = ; jeta_down_JP[6] = ; pu_up_JP[6] = ; pu_down_JP[6] = ; gsplit_up_JP[6] = ; gsplit_down_JP[6] = ; bfrag_up_JP[6] = ; bfrag_down_JP[6] = ; dmux_up_JP[6] = ; dmux_down_JP[6] = ; cfrag_up_JP[6] = ; cfrag_down_JP[6] = ; ksl_up_JP[6] = ; ksl_down_JP[6] = ; ntrkgen_up_JP[6] = ; ntrkgen_down_JP[6] = ; jes_up_JP[6] = ; jes_down_JP[6] = ; jer_up_JP[6] = ; jer_down_JP[6] = ; cb_up_JP[6] = ; cb_down_JP[6] = ; add_up_JP[6] = ; add_down_JP[6] = ;
sf_syst_up_JP[7] = ; sf_syst_down_JP[7] = ;
ntrk_up_JP[7] = ; ntrk_down_JP[7] = ; njet_up_JP[7] = ; njet_down_JP[7] = ; mupt_up_JP[7] = ; mupt_down_JP[7] = ; jeta_up_JP[7] = ; jeta_down_JP[7] = ; pu_up_JP[7] = ; pu_down_JP[7] = ; gsplit_up_JP[7] = ; gsplit_down_JP[7] = ; bfrag_up_JP[7] = ; bfrag_down_JP[7] = ; dmux_up_JP[7] = ; dmux_down_JP[7] = ; cfrag_up_JP[7] = ; cfrag_down_JP[7] = ; ksl_up_JP[7] = ; ksl_down_JP[7] = ; ntrkgen_up_JP[7] = ; ntrkgen_down_JP[7] = ; jes_up_JP[7] = ; jes_down_JP[7] = ; jer_up_JP[7] = ; jer_down_JP[7] = ; cb_up_JP[7] = ; cb_down_JP[7] = ; add_up_JP[7] = ; add_down_JP[7] = ;
sf_syst_up_JP[8] = ; sf_syst_down_JP[8] = ;
ntrk_up_JP[8] = ; ntrk_down_JP[8] = ; njet_up_JP[8] = ; njet_down_JP[8] = ; mupt_up_JP[8] = ; mupt_down_JP[8] = ; jeta_up_JP[8] = ; jeta_down_JP[8] = ; pu_up_JP[8] = ; pu_down_JP[8] = ; gsplit_up_JP[8] = ; gsplit_down_JP[8] = ; bfrag_up_JP[8] = ; bfrag_down_JP[8] = ; dmux_up_JP[8] = ; dmux_down_JP[8] = ; cfrag_up_JP[8] = ; cfrag_down_JP[8] = ; ksl_up_JP[8] = ; ksl_down_JP[8] = ; ntrkgen_up_JP[8] = ; ntrkgen_down_JP[8] = ; jes_up_JP[8] = ; jes_down_JP[8] = ; jer_up_JP[8] = ; jer_down_JP[8] = ; cb_up_JP[8] = ; cb_down_JP[8] = ; add_up_JP[8] = ; add_down_JP[8] = ;
sf_syst_up_JP[9] = ; sf_syst_down_JP[9] = ;
ntrk_up_JP[9] = ; ntrk_down_JP[9] = ; njet_up_JP[9] = ; njet_down_JP[9] = ; mupt_up_JP[9] = ; mupt_down_JP[9] = ; jeta_up_JP[9] = ; jeta_down_JP[9] = ; pu_up_JP[9] = ; pu_down_JP[9] = ; gsplit_up_JP[9] = ; gsplit_down_JP[9] = ; bfrag_up_JP[9] = ; bfrag_down_JP[9] = ; dmux_up_JP[9] = ; dmux_down_JP[9] = ; cfrag_up_JP[9] = ; cfrag_down_JP[9] = ; ksl_up_JP[9] = ; ksl_down_JP[9] = ; ntrkgen_up_JP[9] = ; ntrkgen_down_JP[9] = ; jes_up_JP[9] = ; jes_down_JP[9] = ; jer_up_JP[9] = ; jer_down_JP[9] = ; cb_up_JP[9] = ; cb_down_JP[9] = ; add_up_JP[9] = ; add_down_JP[9] = ;
sf_syst_up_JP[10] = ; sf_syst_down_JP[10] = ;
ntrk_up_JP[10] = ; ntrk_down_JP[10] = ; njet_up_JP[10] = ; njet_down_JP[10] = ; mupt_up_JP[10] = ; mupt_down_JP[10] = ; jeta_up_JP[10] = ; jeta_down_JP[10] = ; pu_up_JP[10] = ; pu_down_JP[10] = ; gsplit_up_JP[10] = ; gsplit_down_JP[10] = ; bfrag_up_JP[10] = ; bfrag_down_JP[10] = ; dmux_up_JP[10] = ; dmux_down_JP[10] = ; cfrag_up_JP[10] = ; cfrag_down_JP[10] = ; ksl_up_JP[10] = ; ksl_down_JP[10] = ; ntrkgen_up_JP[10] = ; ntrkgen_down_JP[10] = ; jes_up_JP[10] = ; jes_down_JP[10] = ; jer_up_JP[10] = ; jer_down_JP[10] = ; cb_up_JP[10] = ; cb_down_JP[10] = ; add_up_JP[10] = ; add_down_JP[10] = ;
sf_syst_up_JP[11] = ; sf_syst_down_JP[11] = ;
ntrk_up_JP[11] = ; ntrk_down_JP[11] = ; njet_up_JP[11] = ; njet_down_JP[11] = ; mupt_up_JP[11] = ; mupt_down_JP[11] = ; jeta_up_JP[11] = ; jeta_down_JP[11] = ; pu_up_JP[11] = ; pu_down_JP[11] = ; gsplit_up_JP[11] = ; gsplit_down_JP[11] = ; bfrag_up_JP[11] = ; bfrag_down_JP[11] = ; dmux_up_JP[11] = ; dmux_down_JP[11] = ; cfrag_up_JP[11] = ; cfrag_down_JP[11] = ; ksl_up_JP[11] = ; ksl_down_JP[11] = ; ntrkgen_up_JP[11] = ; ntrkgen_down_JP[11] = ; jes_up_JP[11] = ; jes_down_JP[11] = ; jer_up_JP[11] = ; jer_down_JP[11] = ; cb_up_JP[11] = ; cb_down_JP[11] = ; add_up_JP[11] = ; add_down_JP[11] = ;
sf_syst_up_JP[12] = ; sf_syst_down_JP[12] = ;
ntrk_up_JP[12] = ; ntrk_down_JP[12] = ; njet_up_JP[12] = ; njet_down_JP[12] = ; mupt_up_JP[12] = ; mupt_down_JP[12] = ; jeta_up_JP[12] = ; jeta_down_JP[12] = ; pu_up_JP[12] = ; pu_down_JP[12] = ; gsplit_up_JP[12] = ; gsplit_down_JP[12] = ; bfrag_up_JP[12] = ; bfrag_down_JP[12] = ; dmux_up_JP[12] = ; dmux_down_JP[12] = ; cfrag_up_JP[12] = ; cfrag_down_JP[12] = ; ksl_up_JP[12] = ; ksl_down_JP[12] = ; ntrkgen_up_JP[12] = ; ntrkgen_down_JP[12] = ; jes_up_JP[12] = ; jes_down_JP[12] = ; jer_up_JP[12] = ; jer_down_JP[12] = ; cb_up_JP[12] = ; cb_down_JP[12] = ; add_up_JP[12] = ; add_down_JP[12] = ;
sf_syst_up_JP[13] = ; sf_syst_down_JP[13] = ;
ntrk_up_JP[13] = ; ntrk_down_JP[13] = ; njet_up_JP[13] = ; njet_down_JP[13] = ; mupt_up_JP[13] = ; mupt_down_JP[13] = ; jeta_up_JP[13] = ; jeta_down_JP[13] = ; pu_up_JP[13] = ; pu_down_JP[13] = ; gsplit_up_JP[13] = ; gsplit_down_JP[13] = ; bfrag_up_JP[13] = ; bfrag_down_JP[13] = ; dmux_up_JP[13] = ; dmux_down_JP[13] = ; cfrag_up_JP[13] = ; cfrag_down_JP[13] = ; ksl_up_JP[13] = ; ksl_down_JP[13] = ; ntrkgen_up_JP[13] = ; ntrkgen_down_JP[13] = ; jes_up_JP[13] = ; jes_down_JP[13] = ; jer_up_JP[13] = ; jer_down_JP[13] = ; cb_up_JP[13] = ; cb_down_JP[13] = ; add_up_JP[13] = ; add_down_JP[13] = ;
sf_syst_up_JP[14] = ; sf_syst_down_JP[14] = ;
ntrk_up_JP[14] = ; ntrk_down_JP[14] = ; njet_up_JP[14] = ; njet_down_JP[14] = ; mupt_up_JP[14] = ; mupt_down_JP[14] = ; jeta_up_JP[14] = ; jeta_down_JP[14] = ; pu_up_JP[14] = ; pu_down_JP[14] = ; gsplit_up_JP[14] = ; gsplit_down_JP[14] = ; bfrag_up_JP[14] = ; bfrag_down_JP[14] = ; dmux_up_JP[14] = ; dmux_down_JP[14] = ; cfrag_up_JP[14] = ; cfrag_down_JP[14] = ; ksl_up_JP[14] = ; ksl_down_JP[14] = ; ntrkgen_up_JP[14] = ; ntrkgen_down_JP[14] = ; jes_up_JP[14] = ; jes_down_JP[14] = ; jer_up_JP[14] = ; jer_down_JP[14] = ; cb_up_JP[14] = ; cb_down_JP[14] = ; add_up_JP[14] = ; add_down_JP[14] = ;

  } else if (Tagger=="CSVT") {
    
// CSVT : JP
eff_JP[0] = ; eff_stat_JP[0] = ; effMC_JP[0] = ; effMC_stat_JP[0] = ; sf_JP[0] = ; sf_stat_JP[0] = ;
eff_JP[1] = ; eff_stat_JP[1] = ; effMC_JP[1] = ; effMC_stat_JP[1] = ; sf_JP[1] = ; sf_stat_JP[1] = ; 
eff_JP[2] = ; eff_stat_JP[2] = ; effMC_JP[2] = ; effMC_stat_JP[2] = ; sf_JP[2] = ; sf_stat_JP[2] = ; 
eff_JP[3] = ; eff_stat_JP[3] = ; effMC_JP[3] = ; effMC_stat_JP[3] = ; sf_JP[3] = ; sf_stat_JP[3] = ; 
eff_JP[4] = ; eff_stat_JP[4] = ; effMC_JP[4] = ; effMC_stat_JP[4] = ; sf_JP[4] = ; sf_stat_JP[4] = ; 
eff_JP[5] = ; eff_stat_JP[5] = ; effMC_JP[5] = ; effMC_stat_JP[5] = ; sf_JP[5] = ; sf_stat_JP[5] = ; 
eff_JP[6] = ; eff_stat_JP[6] = ; effMC_JP[6] = ; effMC_stat_JP[6] = ; sf_JP[6] = ; sf_stat_JP[6] = ; 
eff_JP[7] = ; eff_stat_JP[7] = ; effMC_JP[7] = ; effMC_stat_JP[7] = ; sf_JP[7] = ; sf_stat_JP[7] = ; 
eff_JP[8] = ; eff_stat_JP[8] = ; effMC_JP[8] = ; effMC_stat_JP[8] = ; sf_JP[8] = ; sf_stat_JP[8] = ; 
eff_JP[9] = ; eff_stat_JP[9] = ; effMC_JP[9] = ; effMC_stat_JP[9] = ; sf_JP[9] = ; sf_stat_JP[9] = ; 
eff_JP[10] = ; eff_stat_JP[10] = ; effMC_JP[10] = ; effMC_stat_JP[10] = ; sf_JP[10] = ; sf_stat_JP[10] = ;
eff_JP[11] = ; eff_stat_JP[11] = ; effMC_JP[11] = ; effMC_stat_JP[11] = ; sf_JP[11] = ; sf_stat_JP[11] = ;
eff_JP[12] = ; eff_stat_JP[12] = ; effMC_JP[12] = ; effMC_stat_JP[12] = ; sf_JP[12] = ; sf_stat_JP[12] = ;
eff_JP[13] = ; eff_stat_JP[13] = ; effMC_JP[13] = ; effMC_stat_JP[13] = ; sf_JP[13] = ; sf_stat_JP[13] = ;
eff_JP[14] = ; eff_stat_JP[14] = ; effMC_JP[14] = ; effMC_stat_JP[14] = ; sf_JP[14] = ; sf_stat_JP[14] = ;
sf_syst_up_JP[0] = ; sf_syst_down_JP[0] = ;
ntrk_up_JP[0] = ; ntrk_down_JP[0] = ; njet_up_JP[0] = ; njet_down_JP[0] = ; mupt_up_JP[0] = ; mupt_down_JP[0] = ; jeta_up_JP[0] = ; jeta_down_JP[0] = ; pu_up_JP[0] = ; pu_down_JP[0] = ; gsplit_up_JP[0] = ; gsplit_down_JP[0] = ; bfrag_up_JP[0] = ; bfrag_down_JP[0] = ; dmux_up_JP[0] = ; dmux_down_JP[0] = ; cfrag_up_JP[0] = ; cfrag_down_JP[0] = ; ksl_up_JP[0] = ; ksl_down_JP[0] = ; ntrkgen_up_JP[0] = ; ntrkgen_down_JP[0] = ; jes_up_JP[0] = ; jes_down_JP[0] = ; jer_up_JP[0] = ; jer_down_JP[0] = ; cb_up_JP[0] = ; cb_down_JP[0] = ; add_up_JP[0] = ; add_down_JP[0] = ;
sf_syst_up_JP[1] = ; sf_syst_down_JP[1] = ;
ntrk_up_JP[1] = ; ntrk_down_JP[1] = ; njet_up_JP[1] = ; njet_down_JP[1] = ; mupt_up_JP[1] = ; mupt_down_JP[1] = ; jeta_up_JP[1] = ; jeta_down_JP[1] = ; pu_up_JP[1] = ; pu_down_JP[1] = ; gsplit_up_JP[1] = ; gsplit_down_JP[1] = ; bfrag_up_JP[1] = ; bfrag_down_JP[1] = ; dmux_up_JP[1] = ; dmux_down_JP[1] = ; cfrag_up_JP[1] = ; cfrag_down_JP[1] = ; ksl_up_JP[1] = ; ksl_down_JP[1] = ; ntrkgen_up_JP[1] = ; ntrkgen_down_JP[1] = ; jes_up_JP[1] = ; jes_down_JP[1] = ; jer_up_JP[1] = ; jer_down_JP[1] = ; cb_up_JP[1] = ; cb_down_JP[1] = ; add_up_JP[1] = ; add_down_JP[1] = ;
sf_syst_up_JP[2] = ; sf_syst_down_JP[2] = ;
ntrk_up_JP[2] = ; ntrk_down_JP[2] = ; njet_up_JP[2] = ; njet_down_JP[2] = ; mupt_up_JP[2] = ; mupt_down_JP[2] = ; jeta_up_JP[2] = ; jeta_down_JP[2] = ; pu_up_JP[2] = ; pu_down_JP[2] = ; gsplit_up_JP[2] = ; gsplit_down_JP[2] = ; bfrag_up_JP[2] = ; bfrag_down_JP[2] = ; dmux_up_JP[2] = ; dmux_down_JP[2] = ; cfrag_up_JP[2] = ; cfrag_down_JP[2] = ; ksl_up_JP[2] = ; ksl_down_JP[2] = ; ntrkgen_up_JP[2] = ; ntrkgen_down_JP[2] = ; jes_up_JP[2] = ; jes_down_JP[2] = ; jer_up_JP[2] = ; jer_down_JP[2] = ; cb_up_JP[2] = ; cb_down_JP[2] = ; add_up_JP[2] = ; add_down_JP[2] = ;
sf_syst_up_JP[3] = ; sf_syst_down_JP[3] = ;
ntrk_up_JP[3] = ; ntrk_down_JP[3] = ; njet_up_JP[3] = ; njet_down_JP[3] = ; mupt_up_JP[3] = ; mupt_down_JP[3] = ; jeta_up_JP[3] = ; jeta_down_JP[3] = ; pu_up_JP[3] = ; pu_down_JP[3] = ; gsplit_up_JP[3] = ; gsplit_down_JP[3] = ; bfrag_up_JP[3] = ; bfrag_down_JP[3] = ; dmux_up_JP[3] = ; dmux_down_JP[3] = ; cfrag_up_JP[3] = ; cfrag_down_JP[3] = ; ksl_up_JP[3] = ; ksl_down_JP[3] = ; ntrkgen_up_JP[3] = ; ntrkgen_down_JP[3] = ; jes_up_JP[3] = ; jes_down_JP[3] = ; jer_up_JP[3] = ; jer_down_JP[3] = ; cb_up_JP[3] = ; cb_down_JP[3] = ; add_up_JP[3] = ; add_down_JP[3] = ;
sf_syst_up_JP[4] = ; sf_syst_down_JP[4] = ;
ntrk_up_JP[4] = ; ntrk_down_JP[4] = ; njet_up_JP[4] = ; njet_down_JP[4] = ; mupt_up_JP[4] = ; mupt_down_JP[4] = ; jeta_up_JP[4] = ; jeta_down_JP[4] = ; pu_up_JP[4] = ; pu_down_JP[4] = ; gsplit_up_JP[4] = ; gsplit_down_JP[4] = ; bfrag_up_JP[4] = ; bfrag_down_JP[4] = ; dmux_up_JP[4] = ; dmux_down_JP[4] = ; cfrag_up_JP[4] = ; cfrag_down_JP[4] = ; ksl_up_JP[4] = ; ksl_down_JP[4] = ; ntrkgen_up_JP[4] = ; ntrkgen_down_JP[4] = ; jes_up_JP[4] = ; jes_down_JP[4] = ; jer_up_JP[4] = ; jer_down_JP[4] = ; cb_up_JP[4] = ; cb_down_JP[4] = ; add_up_JP[4] = ; add_down_JP[4] = ;
sf_syst_up_JP[5] = ; sf_syst_down_JP[5] = ;
ntrk_up_JP[5] = ; ntrk_down_JP[5] = ; njet_up_JP[5] = ; njet_down_JP[5] = ; mupt_up_JP[5] = ; mupt_down_JP[5] = ; jeta_up_JP[5] = ; jeta_down_JP[5] = ; pu_up_JP[5] = ; pu_down_JP[5] = ; gsplit_up_JP[5] = ; gsplit_down_JP[5] = ; bfrag_up_JP[5] = ; bfrag_down_JP[5] = ; dmux_up_JP[5] = ; dmux_down_JP[5] = ; cfrag_up_JP[5] = ; cfrag_down_JP[5] = ; ksl_up_JP[5] = ; ksl_down_JP[5] = ; ntrkgen_up_JP[5] = ; ntrkgen_down_JP[5] = ; jes_up_JP[5] = ; jes_down_JP[5] = ; jer_up_JP[5] = ; jer_down_JP[5] = ; cb_up_JP[5] = ; cb_down_JP[4] = ; add_up_JP[5] = ; add_down_JP[5] = ;
sf_syst_up_JP[6] = ; sf_syst_down_JP[6] = ;
ntrk_up_JP[6] = ; ntrk_down_JP[6] = ; njet_up_JP[6] = ; njet_down_JP[6] = ; mupt_up_JP[6] = ; mupt_down_JP[6] = ; jeta_up_JP[6] = ; jeta_down_JP[6] = ; pu_up_JP[6] = ; pu_down_JP[6] = ; gsplit_up_JP[6] = ; gsplit_down_JP[6] = ; bfrag_up_JP[6] = ; bfrag_down_JP[6] = ; dmux_up_JP[6] = ; dmux_down_JP[6] = ; cfrag_up_JP[6] = ; cfrag_down_JP[6] = ; ksl_up_JP[6] = ; ksl_down_JP[6] = ; ntrkgen_up_JP[6] = ; ntrkgen_down_JP[6] = ; jes_up_JP[6] = ; jes_down_JP[6] = ; jer_up_JP[6] = ; jer_down_JP[6] = ; cb_up_JP[6] = ; cb_down_JP[6] = ; add_up_JP[6] = ; add_down_JP[6] = ;
sf_syst_up_JP[7] = ; sf_syst_down_JP[7] = ;
ntrk_up_JP[7] = ; ntrk_down_JP[7] = ; njet_up_JP[7] = ; njet_down_JP[7] = ; mupt_up_JP[7] = ; mupt_down_JP[7] = ; jeta_up_JP[7] = ; jeta_down_JP[7] = ; pu_up_JP[7] = ; pu_down_JP[7] = ; gsplit_up_JP[7] = ; gsplit_down_JP[7] = ; bfrag_up_JP[7] = ; bfrag_down_JP[7] = ; dmux_up_JP[7] = ; dmux_down_JP[7] = ; cfrag_up_JP[7] = ; cfrag_down_JP[7] = ; ksl_up_JP[7] = ; ksl_down_JP[7] = ; ntrkgen_up_JP[7] = ; ntrkgen_down_JP[7] = ; jes_up_JP[7] = ; jes_down_JP[7] = ; jer_up_JP[7] = ; jer_down_JP[7] = ; cb_up_JP[7] = ; cb_down_JP[7] = ; add_up_JP[7] = ; add_down_JP[7] = ;
sf_syst_up_JP[8] = ; sf_syst_down_JP[8] = ;
ntrk_up_JP[8] = ; ntrk_down_JP[8] = ; njet_up_JP[8] = ; njet_down_JP[8] = ; mupt_up_JP[8] = ; mupt_down_JP[8] = ; jeta_up_JP[8] = ; jeta_down_JP[8] = ; pu_up_JP[8] = ; pu_down_JP[8] = ; gsplit_up_JP[8] = ; gsplit_down_JP[8] = ; bfrag_up_JP[8] = ; bfrag_down_JP[8] = ; dmux_up_JP[8] = ; dmux_down_JP[8] = ; cfrag_up_JP[8] = ; cfrag_down_JP[8] = ; ksl_up_JP[8] = ; ksl_down_JP[8] = ; ntrkgen_up_JP[8] = ; ntrkgen_down_JP[8] = ; jes_up_JP[8] = ; jes_down_JP[8] = ; jer_up_JP[8] = ; jer_down_JP[8] = ; cb_up_JP[8] = ; cb_down_JP[8] = ; add_up_JP[8] = ; add_down_JP[8] = ;
sf_syst_up_JP[9] = ; sf_syst_down_JP[9] = ;
ntrk_up_JP[9] = ; ntrk_down_JP[9] = ; njet_up_JP[9] = ; njet_down_JP[9] = ; mupt_up_JP[9] = ; mupt_down_JP[9] = ; jeta_up_JP[9] = ; jeta_down_JP[9] = ; pu_up_JP[9] = ; pu_down_JP[9] = ; gsplit_up_JP[9] = ; gsplit_down_JP[9] = ; bfrag_up_JP[9] = ; bfrag_down_JP[9] = ; dmux_up_JP[9] = ; dmux_down_JP[9] = ; cfrag_up_JP[9] = ; cfrag_down_JP[9] = ; ksl_up_JP[9] = ; ksl_down_JP[9] = ; ntrkgen_up_JP[9] = ; ntrkgen_down_JP[9] = ; jes_up_JP[9] = ; jes_down_JP[9] = ; jer_up_JP[9] = ; jer_down_JP[9] = ; cb_up_JP[9] = ; cb_down_JP[9] = ; add_up_JP[9] = ; add_down_JP[9] = ;
sf_syst_up_JP[10] = ; sf_syst_down_JP[10] = ;
ntrk_up_JP[10] = ; ntrk_down_JP[10] = ; njet_up_JP[10] = ; njet_down_JP[10] = ; mupt_up_JP[10] = ; mupt_down_JP[10] = ; jeta_up_JP[10] = ; jeta_down_JP[10] = ; pu_up_JP[10] = ; pu_down_JP[10] = ; gsplit_up_JP[10] = ; gsplit_down_JP[10] = ; bfrag_up_JP[10] = ; bfrag_down_JP[10] = ; dmux_up_JP[10] = ; dmux_down_JP[10] = ; cfrag_up_JP[10] = ; cfrag_down_JP[10] = ; ksl_up_JP[10] = ; ksl_down_JP[10] = ; ntrkgen_up_JP[10] = ; ntrkgen_down_JP[10] = ; jes_up_JP[10] = ; jes_down_JP[10] = ; jer_up_JP[10] = ; jer_down_JP[10] = ; cb_up_JP[10] = ; cb_down_JP[10] = ; add_up_JP[10] = ; add_down_JP[10] = ;
sf_syst_up_JP[11] = ; sf_syst_down_JP[11] = ;
ntrk_up_JP[11] = ; ntrk_down_JP[11] = ; njet_up_JP[11] = ; njet_down_JP[11] = ; mupt_up_JP[11] = ; mupt_down_JP[11] = ; jeta_up_JP[11] = ; jeta_down_JP[11] = ; pu_up_JP[11] = ; pu_down_JP[11] = ; gsplit_up_JP[11] = ; gsplit_down_JP[11] = ; bfrag_up_JP[11] = ; bfrag_down_JP[11] = ; dmux_up_JP[11] = ; dmux_down_JP[11] = ; cfrag_up_JP[11] = ; cfrag_down_JP[11] = ; ksl_up_JP[11] = ; ksl_down_JP[11] = ; ntrkgen_up_JP[11] = ; ntrkgen_down_JP[11] = ; jes_up_JP[11] = ; jes_down_JP[11] = ; jer_up_JP[11] = ; jer_down_JP[11] = ; cb_up_JP[11] = ; cb_down_JP[11] = ; add_up_JP[11] = ; add_down_JP[11] = ;
sf_syst_up_JP[12] = ; sf_syst_down_JP[12] = ;
ntrk_up_JP[12] = ; ntrk_down_JP[12] = ; njet_up_JP[12] = ; njet_down_JP[12] = ; mupt_up_JP[12] = ; mupt_down_JP[12] = ; jeta_up_JP[12] = ; jeta_down_JP[12] = ; pu_up_JP[12] = ; pu_down_JP[12] = ; gsplit_up_JP[12] = ; gsplit_down_JP[12] = ; bfrag_up_JP[12] = ; bfrag_down_JP[12] = ; dmux_up_JP[12] = ; dmux_down_JP[12] = ; cfrag_up_JP[12] = ; cfrag_down_JP[12] = ; ksl_up_JP[12] = ; ksl_down_JP[12] = ; ntrkgen_up_JP[12] = ; ntrkgen_down_JP[12] = ; jes_up_JP[12] = ; jes_down_JP[12] = ; jer_up_JP[12] = ; jer_down_JP[12] = ; cb_up_JP[12] = ; cb_down_JP[12] = ; add_up_JP[12] = ; add_down_JP[12] = ;
sf_syst_up_JP[13] = ; sf_syst_down_JP[13] = ;
ntrk_up_JP[13] = ; ntrk_down_JP[13] = ; njet_up_JP[13] = ; njet_down_JP[13] = ; mupt_up_JP[13] = ; mupt_down_JP[13] = ; jeta_up_JP[13] = ; jeta_down_JP[13] = ; pu_up_JP[13] = ; pu_down_JP[13] = ; gsplit_up_JP[13] = ; gsplit_down_JP[13] = ; bfrag_up_JP[13] = ; bfrag_down_JP[13] = ; dmux_up_JP[13] = ; dmux_down_JP[13] = ; cfrag_up_JP[13] = ; cfrag_down_JP[13] = ; ksl_up_JP[13] = ; ksl_down_JP[13] = ; ntrkgen_up_JP[13] = ; ntrkgen_down_JP[13] = ; jes_up_JP[13] = ; jes_down_JP[13] = ; jer_up_JP[13] = ; jer_down_JP[13] = ; cb_up_JP[13] = ; cb_down_JP[13] = ; add_up_JP[13] = ; add_down_JP[13] = ;
sf_syst_up_JP[14] = ; sf_syst_down_JP[14] = ;
ntrk_up_JP[14] = ; ntrk_down_JP[14] = ; njet_up_JP[14] = ; njet_down_JP[14] = ; mupt_up_JP[14] = ; mupt_down_JP[14] = ; jeta_up_JP[14] = ; jeta_down_JP[14] = ; pu_up_JP[14] = ; pu_down_JP[14] = ; gsplit_up_JP[14] = ; gsplit_down_JP[14] = ; bfrag_up_JP[14] = ; bfrag_down_JP[14] = ; dmux_up_JP[14] = ; dmux_down_JP[14] = ; cfrag_up_JP[14] = ; cfrag_down_JP[14] = ; ksl_up_JP[14] = ; ksl_down_JP[14] = ; ntrkgen_up_JP[14] = ; ntrkgen_down_JP[14] = ; jes_up_JP[14] = ; jes_down_JP[14] = ; jer_up_JP[14] = ; jer_down_JP[14] = ; cb_up_JP[14] = ; cb_down_JP[14] = ; add_up_JP[14] = ; add_down_JP[14] = ;

  } else if (Tagger=="TCHPT") {
    
// TCHPT : JP
eff_JP[0] = ; eff_stat_JP[0] = ; effMC_JP[0] = ; effMC_stat_JP[0] = ; sf_JP[0] = ; sf_stat_JP[0] = ;
eff_JP[1] = ; eff_stat_JP[1] = ; effMC_JP[1] = ; effMC_stat_JP[1] = ; sf_JP[1] = ; sf_stat_JP[1] = ; 
eff_JP[2] = ; eff_stat_JP[2] = ; effMC_JP[2] = ; effMC_stat_JP[2] = ; sf_JP[2] = ; sf_stat_JP[2] = ; 
eff_JP[3] = ; eff_stat_JP[3] = ; effMC_JP[3] = ; effMC_stat_JP[3] = ; sf_JP[3] = ; sf_stat_JP[3] = ; 
eff_JP[4] = ; eff_stat_JP[4] = ; effMC_JP[4] = ; effMC_stat_JP[4] = ; sf_JP[4] = ; sf_stat_JP[4] = ; 
eff_JP[5] = ; eff_stat_JP[5] = ; effMC_JP[5] = ; effMC_stat_JP[5] = ; sf_JP[5] = ; sf_stat_JP[5] = ; 
eff_JP[6] = ; eff_stat_JP[6] = ; effMC_JP[6] = ; effMC_stat_JP[6] = ; sf_JP[6] = ; sf_stat_JP[6] = ; 
eff_JP[7] = ; eff_stat_JP[7] = ; effMC_JP[7] = ; effMC_stat_JP[7] = ; sf_JP[7] = ; sf_stat_JP[7] = ; 
eff_JP[8] = ; eff_stat_JP[8] = ; effMC_JP[8] = ; effMC_stat_JP[8] = ; sf_JP[8] = ; sf_stat_JP[8] = ; 
eff_JP[9] = ; eff_stat_JP[9] = ; effMC_JP[9] = ; effMC_stat_JP[9] = ; sf_JP[9] = ; sf_stat_JP[9] = ; 
eff_JP[10] = ; eff_stat_JP[10] = ; effMC_JP[10] = ; effMC_stat_JP[10] = ; sf_JP[10] = ; sf_stat_JP[10] = ;
eff_JP[11] = ; eff_stat_JP[11] = ; effMC_JP[11] = ; effMC_stat_JP[11] = ; sf_JP[11] = ; sf_stat_JP[11] = ;
eff_JP[12] = ; eff_stat_JP[12] = ; effMC_JP[12] = ; effMC_stat_JP[12] = ; sf_JP[12] = ; sf_stat_JP[12] = ;
eff_JP[13] = ; eff_stat_JP[13] = ; effMC_JP[13] = ; effMC_stat_JP[13] = ; sf_JP[13] = ; sf_stat_JP[13] = ;
eff_JP[14] = ; eff_stat_JP[14] = ; effMC_JP[14] = ; effMC_stat_JP[14] = ; sf_JP[14] = ; sf_stat_JP[14] = ;
sf_syst_up_JP[0] = ; sf_syst_down_JP[0] = ;
ntrk_up_JP[0] = ; ntrk_down_JP[0] = ; njet_up_JP[0] = ; njet_down_JP[0] = ; mupt_up_JP[0] = ; mupt_down_JP[0] = ; jeta_up_JP[0] = ; jeta_down_JP[0] = ; pu_up_JP[0] = ; pu_down_JP[0] = ; gsplit_up_JP[0] = ; gsplit_down_JP[0] = ; bfrag_up_JP[0] = ; bfrag_down_JP[0] = ; dmux_up_JP[0] = ; dmux_down_JP[0] = ; cfrag_up_JP[0] = ; cfrag_down_JP[0] = ; ksl_up_JP[0] = ; ksl_down_JP[0] = ; ntrkgen_up_JP[0] = ; ntrkgen_down_JP[0] = ; jes_up_JP[0] = ; jes_down_JP[0] = ; jer_up_JP[0] = ; jer_down_JP[0] = ; cb_up_JP[0] = ; cb_down_JP[0] = ; add_up_JP[0] = ; add_down_JP[0] = ;
sf_syst_up_JP[1] = ; sf_syst_down_JP[1] = ;
ntrk_up_JP[1] = ; ntrk_down_JP[1] = ; njet_up_JP[1] = ; njet_down_JP[1] = ; mupt_up_JP[1] = ; mupt_down_JP[1] = ; jeta_up_JP[1] = ; jeta_down_JP[1] = ; pu_up_JP[1] = ; pu_down_JP[1] = ; gsplit_up_JP[1] = ; gsplit_down_JP[1] = ; bfrag_up_JP[1] = ; bfrag_down_JP[1] = ; dmux_up_JP[1] = ; dmux_down_JP[1] = ; cfrag_up_JP[1] = ; cfrag_down_JP[1] = ; ksl_up_JP[1] = ; ksl_down_JP[1] = ; ntrkgen_up_JP[1] = ; ntrkgen_down_JP[1] = ; jes_up_JP[1] = ; jes_down_JP[1] = ; jer_up_JP[1] = ; jer_down_JP[1] = ; cb_up_JP[1] = ; cb_down_JP[1] = ; add_up_JP[1] = ; add_down_JP[1] = ;
sf_syst_up_JP[2] = ; sf_syst_down_JP[2] = ;
ntrk_up_JP[2] = ; ntrk_down_JP[2] = ; njet_up_JP[2] = ; njet_down_JP[2] = ; mupt_up_JP[2] = ; mupt_down_JP[2] = ; jeta_up_JP[2] = ; jeta_down_JP[2] = ; pu_up_JP[2] = ; pu_down_JP[2] = ; gsplit_up_JP[2] = ; gsplit_down_JP[2] = ; bfrag_up_JP[2] = ; bfrag_down_JP[2] = ; dmux_up_JP[2] = ; dmux_down_JP[2] = ; cfrag_up_JP[2] = ; cfrag_down_JP[2] = ; ksl_up_JP[2] = ; ksl_down_JP[2] = ; ntrkgen_up_JP[2] = ; ntrkgen_down_JP[2] = ; jes_up_JP[2] = ; jes_down_JP[2] = ; jer_up_JP[2] = ; jer_down_JP[2] = ; cb_up_JP[2] = ; cb_down_JP[2] = ; add_up_JP[2] = ; add_down_JP[2] = ;
sf_syst_up_JP[3] = ; sf_syst_down_JP[3] = ;
ntrk_up_JP[3] = ; ntrk_down_JP[3] = ; njet_up_JP[3] = ; njet_down_JP[3] = ; mupt_up_JP[3] = ; mupt_down_JP[3] = ; jeta_up_JP[3] = ; jeta_down_JP[3] = ; pu_up_JP[3] = ; pu_down_JP[3] = ; gsplit_up_JP[3] = ; gsplit_down_JP[3] = ; bfrag_up_JP[3] = ; bfrag_down_JP[3] = ; dmux_up_JP[3] = ; dmux_down_JP[3] = ; cfrag_up_JP[3] = ; cfrag_down_JP[3] = ; ksl_up_JP[3] = ; ksl_down_JP[3] = ; ntrkgen_up_JP[3] = ; ntrkgen_down_JP[3] = ; jes_up_JP[3] = ; jes_down_JP[3] = ; jer_up_JP[3] = ; jer_down_JP[3] = ; cb_up_JP[3] = ; cb_down_JP[3] = ; add_up_JP[3] = ; add_down_JP[3] = ;
sf_syst_up_JP[4] = ; sf_syst_down_JP[4] = ;
ntrk_up_JP[4] = ; ntrk_down_JP[4] = ; njet_up_JP[4] = ; njet_down_JP[4] = ; mupt_up_JP[4] = ; mupt_down_JP[4] = ; jeta_up_JP[4] = ; jeta_down_JP[4] = ; pu_up_JP[4] = ; pu_down_JP[4] = ; gsplit_up_JP[4] = ; gsplit_down_JP[4] = ; bfrag_up_JP[4] = ; bfrag_down_JP[4] = ; dmux_up_JP[4] = ; dmux_down_JP[4] = ; cfrag_up_JP[4] = ; cfrag_down_JP[4] = ; ksl_up_JP[4] = ; ksl_down_JP[4] = ; ntrkgen_up_JP[4] = ; ntrkgen_down_JP[4] = ; jes_up_JP[4] = ; jes_down_JP[4] = ; jer_up_JP[4] = ; jer_down_JP[4] = ; cb_up_JP[4] = ; cb_down_JP[4] = ; add_up_JP[4] = ; add_down_JP[4] = ;
sf_syst_up_JP[5] = ; sf_syst_down_JP[5] = ;
ntrk_up_JP[5] = ; ntrk_down_JP[5] = ; njet_up_JP[5] = ; njet_down_JP[5] = ; mupt_up_JP[5] = ; mupt_down_JP[5] = ; jeta_up_JP[5] = ; jeta_down_JP[5] = ; pu_up_JP[5] = ; pu_down_JP[5] = ; gsplit_up_JP[5] = ; gsplit_down_JP[5] = ; bfrag_up_JP[5] = ; bfrag_down_JP[5] = ; dmux_up_JP[5] = ; dmux_down_JP[5] = ; cfrag_up_JP[5] = ; cfrag_down_JP[5] = ; ksl_up_JP[5] = ; ksl_down_JP[5] = ; ntrkgen_up_JP[5] = ; ntrkgen_down_JP[5] = ; jes_up_JP[5] = ; jes_down_JP[5] = ; jer_up_JP[5] = ; jer_down_JP[5] = ; cb_up_JP[5] = ; cb_down_JP[4] = ; add_up_JP[5] = ; add_down_JP[5] = ;
sf_syst_up_JP[6] = ; sf_syst_down_JP[6] = ;
ntrk_up_JP[6] = ; ntrk_down_JP[6] = ; njet_up_JP[6] = ; njet_down_JP[6] = ; mupt_up_JP[6] = ; mupt_down_JP[6] = ; jeta_up_JP[6] = ; jeta_down_JP[6] = ; pu_up_JP[6] = ; pu_down_JP[6] = ; gsplit_up_JP[6] = ; gsplit_down_JP[6] = ; bfrag_up_JP[6] = ; bfrag_down_JP[6] = ; dmux_up_JP[6] = ; dmux_down_JP[6] = ; cfrag_up_JP[6] = ; cfrag_down_JP[6] = ; ksl_up_JP[6] = ; ksl_down_JP[6] = ; ntrkgen_up_JP[6] = ; ntrkgen_down_JP[6] = ; jes_up_JP[6] = ; jes_down_JP[6] = ; jer_up_JP[6] = ; jer_down_JP[6] = ; cb_up_JP[6] = ; cb_down_JP[6] = ; add_up_JP[6] = ; add_down_JP[6] = ;
sf_syst_up_JP[7] = ; sf_syst_down_JP[7] = ;
ntrk_up_JP[7] = ; ntrk_down_JP[7] = ; njet_up_JP[7] = ; njet_down_JP[7] = ; mupt_up_JP[7] = ; mupt_down_JP[7] = ; jeta_up_JP[7] = ; jeta_down_JP[7] = ; pu_up_JP[7] = ; pu_down_JP[7] = ; gsplit_up_JP[7] = ; gsplit_down_JP[7] = ; bfrag_up_JP[7] = ; bfrag_down_JP[7] = ; dmux_up_JP[7] = ; dmux_down_JP[7] = ; cfrag_up_JP[7] = ; cfrag_down_JP[7] = ; ksl_up_JP[7] = ; ksl_down_JP[7] = ; ntrkgen_up_JP[7] = ; ntrkgen_down_JP[7] = ; jes_up_JP[7] = ; jes_down_JP[7] = ; jer_up_JP[7] = ; jer_down_JP[7] = ; cb_up_JP[7] = ; cb_down_JP[7] = ; add_up_JP[7] = ; add_down_JP[7] = ;
sf_syst_up_JP[8] = ; sf_syst_down_JP[8] = ;
ntrk_up_JP[8] = ; ntrk_down_JP[8] = ; njet_up_JP[8] = ; njet_down_JP[8] = ; mupt_up_JP[8] = ; mupt_down_JP[8] = ; jeta_up_JP[8] = ; jeta_down_JP[8] = ; pu_up_JP[8] = ; pu_down_JP[8] = ; gsplit_up_JP[8] = ; gsplit_down_JP[8] = ; bfrag_up_JP[8] = ; bfrag_down_JP[8] = ; dmux_up_JP[8] = ; dmux_down_JP[8] = ; cfrag_up_JP[8] = ; cfrag_down_JP[8] = ; ksl_up_JP[8] = ; ksl_down_JP[8] = ; ntrkgen_up_JP[8] = ; ntrkgen_down_JP[8] = ; jes_up_JP[8] = ; jes_down_JP[8] = ; jer_up_JP[8] = ; jer_down_JP[8] = ; cb_up_JP[8] = ; cb_down_JP[8] = ; add_up_JP[8] = ; add_down_JP[8] = ;
sf_syst_up_JP[9] = ; sf_syst_down_JP[9] = ;
ntrk_up_JP[9] = ; ntrk_down_JP[9] = ; njet_up_JP[9] = ; njet_down_JP[9] = ; mupt_up_JP[9] = ; mupt_down_JP[9] = ; jeta_up_JP[9] = ; jeta_down_JP[9] = ; pu_up_JP[9] = ; pu_down_JP[9] = ; gsplit_up_JP[9] = ; gsplit_down_JP[9] = ; bfrag_up_JP[9] = ; bfrag_down_JP[9] = ; dmux_up_JP[9] = ; dmux_down_JP[9] = ; cfrag_up_JP[9] = ; cfrag_down_JP[9] = ; ksl_up_JP[9] = ; ksl_down_JP[9] = ; ntrkgen_up_JP[9] = ; ntrkgen_down_JP[9] = ; jes_up_JP[9] = ; jes_down_JP[9] = ; jer_up_JP[9] = ; jer_down_JP[9] = ; cb_up_JP[9] = ; cb_down_JP[9] = ; add_up_JP[9] = ; add_down_JP[9] = ;
sf_syst_up_JP[10] = ; sf_syst_down_JP[10] = ;
ntrk_up_JP[10] = ; ntrk_down_JP[10] = ; njet_up_JP[10] = ; njet_down_JP[10] = ; mupt_up_JP[10] = ; mupt_down_JP[10] = ; jeta_up_JP[10] = ; jeta_down_JP[10] = ; pu_up_JP[10] = ; pu_down_JP[10] = ; gsplit_up_JP[10] = ; gsplit_down_JP[10] = ; bfrag_up_JP[10] = ; bfrag_down_JP[10] = ; dmux_up_JP[10] = ; dmux_down_JP[10] = ; cfrag_up_JP[10] = ; cfrag_down_JP[10] = ; ksl_up_JP[10] = ; ksl_down_JP[10] = ; ntrkgen_up_JP[10] = ; ntrkgen_down_JP[10] = ; jes_up_JP[10] = ; jes_down_JP[10] = ; jer_up_JP[10] = ; jer_down_JP[10] = ; cb_up_JP[10] = ; cb_down_JP[10] = ; add_up_JP[10] = ; add_down_JP[10] = ;
sf_syst_up_JP[11] = ; sf_syst_down_JP[11] = ;
ntrk_up_JP[11] = ; ntrk_down_JP[11] = ; njet_up_JP[11] = ; njet_down_JP[11] = ; mupt_up_JP[11] = ; mupt_down_JP[11] = ; jeta_up_JP[11] = ; jeta_down_JP[11] = ; pu_up_JP[11] = ; pu_down_JP[11] = ; gsplit_up_JP[11] = ; gsplit_down_JP[11] = ; bfrag_up_JP[11] = ; bfrag_down_JP[11] = ; dmux_up_JP[11] = ; dmux_down_JP[11] = ; cfrag_up_JP[11] = ; cfrag_down_JP[11] = ; ksl_up_JP[11] = ; ksl_down_JP[11] = ; ntrkgen_up_JP[11] = ; ntrkgen_down_JP[11] = ; jes_up_JP[11] = ; jes_down_JP[11] = ; jer_up_JP[11] = ; jer_down_JP[11] = ; cb_up_JP[11] = ; cb_down_JP[11] = ; add_up_JP[11] = ; add_down_JP[11] = ;
sf_syst_up_JP[12] = ; sf_syst_down_JP[12] = ;
ntrk_up_JP[12] = ; ntrk_down_JP[12] = ; njet_up_JP[12] = ; njet_down_JP[12] = ; mupt_up_JP[12] = ; mupt_down_JP[12] = ; jeta_up_JP[12] = ; jeta_down_JP[12] = ; pu_up_JP[12] = ; pu_down_JP[12] = ; gsplit_up_JP[12] = ; gsplit_down_JP[12] = ; bfrag_up_JP[12] = ; bfrag_down_JP[12] = ; dmux_up_JP[12] = ; dmux_down_JP[12] = ; cfrag_up_JP[12] = ; cfrag_down_JP[12] = ; ksl_up_JP[12] = ; ksl_down_JP[12] = ; ntrkgen_up_JP[12] = ; ntrkgen_down_JP[12] = ; jes_up_JP[12] = ; jes_down_JP[12] = ; jer_up_JP[12] = ; jer_down_JP[12] = ; cb_up_JP[12] = ; cb_down_JP[12] = ; add_up_JP[12] = ; add_down_JP[12] = ;
sf_syst_up_JP[13] = ; sf_syst_down_JP[13] = ;
ntrk_up_JP[13] = ; ntrk_down_JP[13] = ; njet_up_JP[13] = ; njet_down_JP[13] = ; mupt_up_JP[13] = ; mupt_down_JP[13] = ; jeta_up_JP[13] = ; jeta_down_JP[13] = ; pu_up_JP[13] = ; pu_down_JP[13] = ; gsplit_up_JP[13] = ; gsplit_down_JP[13] = ; bfrag_up_JP[13] = ; bfrag_down_JP[13] = ; dmux_up_JP[13] = ; dmux_down_JP[13] = ; cfrag_up_JP[13] = ; cfrag_down_JP[13] = ; ksl_up_JP[13] = ; ksl_down_JP[13] = ; ntrkgen_up_JP[13] = ; ntrkgen_down_JP[13] = ; jes_up_JP[13] = ; jes_down_JP[13] = ; jer_up_JP[13] = ; jer_down_JP[13] = ; cb_up_JP[13] = ; cb_down_JP[13] = ; add_up_JP[13] = ; add_down_JP[13] = ;
sf_syst_up_JP[14] = ; sf_syst_down_JP[14] = ;
ntrk_up_JP[14] = ; ntrk_down_JP[14] = ; njet_up_JP[14] = ; njet_down_JP[14] = ; mupt_up_JP[14] = ; mupt_down_JP[14] = ; jeta_up_JP[14] = ; jeta_down_JP[14] = ; pu_up_JP[14] = ; pu_down_JP[14] = ; gsplit_up_JP[14] = ; gsplit_down_JP[14] = ; bfrag_up_JP[14] = ; bfrag_down_JP[14] = ; dmux_up_JP[14] = ; dmux_down_JP[14] = ; cfrag_up_JP[14] = ; cfrag_down_JP[14] = ; ksl_up_JP[14] = ; ksl_down_JP[14] = ; ntrkgen_up_JP[14] = ; ntrkgen_down_JP[14] = ; jes_up_JP[14] = ; jes_down_JP[14] = ; jer_up_JP[14] = ; jer_down_JP[14] = ; cb_up_JP[14] = ; cb_down_JP[14] = ; add_up_JP[14] = ; add_down_JP[14] = ;
     
  } else cout << "Unmeasured tagger: " << Tagger << " for LT" << endl;


}

