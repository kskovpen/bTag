TStyle* PlotStyle();
TStyle* PlotStyleCMS();
void SetPlotStyle();
float getCb(std::string,std::string,int);
std::string getSysName(int);
TLatex* CMSLABEL();

std::string SFver = "20160229";
bool inclCB = 1;
//bool inclCB = 0;
bool doSFc = 0;

void combine()
{
   gROOT->SetBatch(1);

   SetPlotStyle();

   std::string tag = "CSVM";
   std::string tagName = "CSVv2M";
//   std::string tag = "CMVAT";
//   std::string tagName = "cMVAv2T";

//   const int nPT = 15;
/*   const int nPT = 14;
   std::string pt[nPT] = 
     {
	"pt20t30",
	"pt30t40",
	"pt40t50",
	"pt50t60",
	"pt60t70",
	"pt70t80",
	"pt80t100",
	"pt100t120",
	"pt120t160",
	"pt160t210",
	"pt210t260",
	"pt260t320",
	"pt320t400",
	"pt400t500"
//	"pt500t670"
     };*/
   
/*   const int nPT = 7;
   std::string pt[nPT] =
     {
	"pt30t50",
	"pt50t70",
	"pt70t100",
	"pt100t140",
	"pt140t200",
	"pt200t300",
	"pt300t670"
     };*/

/*   const int nPT = 5;
   std::string pt[nPT] =
     {
	"pt200t220",
	"pt220t250",
	"pt250t300",
	"pt300t400",
	"pt400t650"
     };*/

   const int nPT = 5;
   std::string pt[nPT] =
     {
	"pt30t80",
	"pt80t140",
	"pt140t180",
	"pt180t240",
	"pt240t420"
     };

/*   int ptb[nPT+1] =
     {
	30,50,70,100,140,200,300,670
     };*/

/*   int ptb[nPT+1] =
     {
	200,220,250,300,400,650
     };*/

   int ptb[nPT+1] =
     {
	30,80,140,180,240,420
     };
   
   float xbins[nPT];
   for(int j=0;j<=nPT;j++)
     {
	xbins[j] = ptb[j]/1000.;
     }
   
   TH1F *h_SF = new TH1F("h_SF","h_SF",nPT,xbins);
   TH1F *h_SF_TOTAL_UP = new TH1F("h_SF_TOTAL_UP","h_SF_TOTAL_UP",nPT,xbins);
   TH1F *h_SF_TOTAL_DOWN = new TH1F("h_SF_TOTAL_DOWN","h_SF_TOTAL_DOWN",nPT,xbins);
   
   TH1F *h_frb = new TH1F("h_frb","h_frb",nPT,xbins);
   TH1F *h_frb_TOTAL_UP = new TH1F("h_frb_TOTAL_UP","h_frb_TOTAL_UP",nPT,xbins);
   TH1F *h_frb_TOTAL_DOWN = new TH1F("h_frb_TOTAL_DOWN","h_frb_TOTAL_DOWN",nPT,xbins);
   TH1F *h_frc = new TH1F("h_frc","h_frc",nPT,xbins);
   TH1F *h_frc_TOTAL_UP = new TH1F("h_frc_TOTAL_UP","h_frc_TOTAL_UP",nPT,xbins);
   TH1F *h_frc_TOTAL_DOWN = new TH1F("h_frc_TOTAL_DOWN","h_frc_TOTAL_DOWN",nPT,xbins);
   TH1F *h_frl = new TH1F("h_frl","h_frl",nPT,xbins);
   TH1F *h_frl_TOTAL_UP = new TH1F("h_frl_TOTAL_UP","h_frl_TOTAL_UP",nPT,xbins);
   TH1F *h_frl_TOTAL_DOWN = new TH1F("h_frl_TOTAL_DOWN","h_frl_TOTAL_DOWN",nPT,xbins);
   
   TH1F *h_frb_tag = new TH1F("h_frb_tag","h_frb_tag",nPT,xbins);
   TH1F *h_frb_tag_TOTAL_UP = new TH1F("h_frb_tag_TOTAL_UP","h_frb_tag_TOTAL_UP",nPT,xbins);
   TH1F *h_frb_tag_TOTAL_DOWN = new TH1F("h_frb_tag_TOTAL_DOWN","h_frb_tag_TOTAL_DOWN",nPT,xbins);
   TH1F *h_frc_tag = new TH1F("h_frc_tag","h_frc_tag",nPT,xbins);
   TH1F *h_frc_tag_TOTAL_UP = new TH1F("h_frc_tag_TOTAL_UP","h_frc_tag_TOTAL_UP",nPT,xbins);
   TH1F *h_frc_tag_TOTAL_DOWN = new TH1F("h_frc_tag_TOTAL_DOWN","h_frc_tag_TOTAL_DOWN",nPT,xbins);
   TH1F *h_frl_tag = new TH1F("h_frl_tag","h_frl_tag",nPT,xbins);
   TH1F *h_frl_tag_TOTAL_UP = new TH1F("h_frl_tag_TOTAL_UP","h_frl_tag_TOTAL_UP",nPT,xbins);
   TH1F *h_frl_tag_TOTAL_DOWN = new TH1F("h_frl_tag_TOTAL_DOWN","h_frl_tag_TOTAL_DOWN",nPT,xbins);
   
   std::string head = "CSV;OperatingPoint,measurementType,sysType,jetFlavor,etaMin,etaMax,ptMin,ptMax,discrMin,discrMax,formula";
   std::string fname = "results/CSV_13TEV_"+SFver+"_"+tagName+"_LT.csv";
   std::ofstream sfComb(fname.c_str());
   sfComb << head << std::endl;

   std::vector<std::vector<float> > Comb_sigma_syst;
   std::vector<std::vector<std::string> > Comb_sigma_syst_name;
   std::vector<float> Comb_sf;
   std::vector<int> Comb_op;
   std::vector<std::string> Comb_type;
   std::vector<int> Comb_flav;
   std::vector<float> Comb_etaMin;
   std::vector<float> Comb_etaMax;
   std::vector<float> Comb_discMin;
   std::vector<float> Comb_discMax;
   std::vector<int> Comb_ptMin;
   std::vector<int> Comb_ptMax;
   
   for(int ipt=0;ipt<nPT;ipt++)
     {
	if( tag == "CSVL" || tag == "CMVAL" ) Comb_op.push_back(0);
	else if( tag == "CSVM" || tag == "CMVAM" ) Comb_op.push_back(1);
	else if( tag == "CSVT" || tag == "CMVAT" ) Comb_op.push_back(2);
	
	Comb_type.push_back("lt");
	Comb_flav.push_back(0);
	Comb_etaMin.push_back(0.0);
	Comb_etaMax.push_back(2.4);
	Comb_discMin.push_back(0.0);
	Comb_discMax.push_back(1.0);
	
	std::vector<int> run;
	std::vector<float> sf;
	std::vector<float> frb;
	std::vector<float> frbTag;
	std::vector<float> frc;
	std::vector<float> frcTag;
	std::vector<float> frl;
	std::vector<float> frlTag;
	
	int idxNom = -666;

	for(int is=0;is<=2;is++) // FIXME !!!
	  {
	     std::string prefix;
	     if( is == 0 ) prefix = "results_"+tag+"_MJBOOSTS1_SUB/";
	     else if( is == 1 ) prefix = "results_"+tag+"_MJBOOSTS2_SUB/";
//	     if( is == 0 ) prefix = "results/";
//	     if( is == 0 ) prefix = "results_"+tag+"_MJ/";
//	     else if( is == 1 ) prefix = "results_"+tag+"_MJAWAY/";
//	     else if( is == 2 ) prefix = "results_"+tag+"_MJ1/";
//	     else if( is == 2 ) prefix = "results_"+tag+"_MJIAWAY/";
	     else continue;
	     
	     // read result files
	     std::string fname = prefix+pt[ipt]+"_"+tag+".csv";
	     std::ifstream f(fname.c_str());
	     if( !f.is_open() ) continue;
	     std::cout << fname << std::endl;
	     
	     int iline = 0;
	     while( !f.eof() )
	       {	     
		  std::string line;
		  f >> line;
		  if( iline == 0 ) {iline++; continue;}
		  std::stringstream ss(line);
		  std::string item;
		  int idx = 0;
		  while( std::getline(ss,item,',') )
		    {
		       int run_v = -1;
		       if( idx == 3 ) run_v = atoi(item.c_str());
		       
		       if( is == 0 && idx == 3 && run_v == 0 ) idxNom = iline-1;

		       if( (iline == 1 && is == 1) || 
			   (iline == 1 && is == 2) ||
			   (iline == 1 && is == 3) ||
			   is == 0 )
			 {			    
			    if( is == 1 ) run_v = 200;
			    if( is == 2 ) run_v = 201;
			    if( is == 3 ) run_v = 202;
			    
			    if( idx == 3 ) run.push_back(run_v);
			    
			    if( idx == 24 ) 
			      {
				 sf.push_back(atof(item.c_str())); // FIXME IF FORMAT CHANGES
			      }

			    if( idx == 14 ) frb.push_back(atof(item.c_str()));
			    if( idx == 15 ) frbTag.push_back(atof(item.c_str()));
			    if( idx == 16 ) frc.push_back(atof(item.c_str()));
			    if( idx == 17 ) frcTag.push_back(atof(item.c_str()));
			    if( idx == 18 ) frl.push_back(atof(item.c_str()));
			    if( idx == 19 ) frlTag.push_back(atof(item.c_str()));
			    
			    if( iline == 1 && is == 0 && (run_v < 100 || run_v >= 666) )
			      {
				 if( idx == 0 ) Comb_ptMin.push_back(atoi(item.c_str()));
				 if( idx == 1 ) Comb_ptMax.push_back(atoi(item.c_str()));
			      }		  
			 }		       
		       
		       idx++;
		    }
		  
		  iline++;
	       }
	     
	     f.close();
	  }	
	
	// do calculations
	int nRES = run.size();
	
	float sigma_syst_up = 0.;
	float sigma_syst_down = 0.;
	float sigma_total_up = 0.;
	float sigma_total_down = 0.;
	float sigma_stat = 0.;
	float sf_stat_sum = 0.;
	float istat = 0;

	float frb_sigma_total_up = 0.;
	float frb_sigma_total_down = 0.;
	float frc_sigma_total_up = 0.;
	float frc_sigma_total_down = 0.;
	float frl_sigma_total_up = 0.;
	float frl_sigma_total_down = 0.;
	
	float frb_sigma_syst_up = 0.;
	float frb_sigma_syst_down = 0.;
	float frc_sigma_syst_up = 0.;
	float frc_sigma_syst_down = 0.;
	float frl_sigma_syst_up = 0.;
	float frl_sigma_syst_down = 0.;

	float frb_tag_sigma_total_up = 0.;
	float frb_tag_sigma_total_down = 0.;
	float frc_tag_sigma_total_up = 0.;
	float frc_tag_sigma_total_down = 0.;
	float frl_tag_sigma_total_up = 0.;
	float frl_tag_sigma_total_down = 0.;
	
	float frb_tag_sigma_syst_up = 0.;
	float frb_tag_sigma_syst_down = 0.;
	float frc_tag_sigma_syst_up = 0.;
	float frc_tag_sigma_syst_down = 0.;
	float frl_tag_sigma_syst_up = 0.;
	float frl_tag_sigma_syst_down = 0.;
	
	float frb_stat_sum = 0.;
	float sigma_frb_stat = 0.;
	float frc_stat_sum = 0.;
	float sigma_frc_stat = 0.;
	float frl_stat_sum = 0.;
	float sigma_frl_stat = 0.;

	float frbTag_stat_sum = 0.;
	float sigma_frbTag_stat = 0.;
	float frcTag_stat_sum = 0.;
	float sigma_frcTag_stat = 0.;
	float frlTag_stat_sum = 0.;
	float sigma_frlTag_stat = 0.;
	
	std::vector<float> sigma_syst_sep;
	std::vector<std::string> sigma_syst_name;
	float sigma_syst_add = 0.;
	float frb_sigma_syst_add = 0.;
	float frc_sigma_syst_add = 0.;
	float frl_sigma_syst_add = 0.;

	float frb_tag_sigma_syst_add = 0.;
	float frc_tag_sigma_syst_add = 0.;
	float frl_tag_sigma_syst_add = 0.;
	
	std::vector<float> frb_sigma_syst_sep;
	std::vector<float> frc_sigma_syst_sep;
	std::vector<float> frl_sigma_syst_sep;

	std::vector<float> frb_tag_sigma_syst_sep;
	std::vector<float> frc_tag_sigma_syst_sep;
	std::vector<float> frl_tag_sigma_syst_sep;
	
	std::vector<std::string> frb_sigma_syst_name;
	std::vector<std::string> frc_sigma_syst_name;
	std::vector<std::string> frl_sigma_syst_name;

	std::vector<std::string> frb_tag_sigma_syst_name;
	std::vector<std::string> frc_tag_sigma_syst_name;
	std::vector<std::string> frl_tag_sigma_syst_name;
	
	for(int i=0;i<nRES;i++)
	  {
	     if( i == idxNom )
	       {
		  sigma_syst_sep.push_back(sf[idxNom]);
		  sigma_syst_name.push_back(getSysName(run[i]));
		  continue;
	       }	     
	     
	     if( run[i] < 666 )
	       {	
		  float delta = sf[idxNom]-sf[i];
		  bool isUp = (delta < 0);
		  float err = delta*delta;
		  if( run[i] < 100 )
		    {		       
		       if( isUp ) sigma_syst_up += err;		  
		       else sigma_syst_down += err;
		    }
		  if( run[i] >= 100 && run[i] <= 202 )
		    {
		       sigma_syst_up += pow(delta,2);
		       sigma_syst_down += pow(delta,2);
		    }		  

		  if( run[i] < 100 )
		    {		       
		       if( isUp ) sigma_syst_sep.push_back(sf[idxNom]+sqrt(err));
		       else sigma_syst_sep.push_back(sf[idxNom]-sqrt(err));
		       sigma_syst_name.push_back(getSysName(run[i]));
		    }		  		  
		  if( run[i] >= 100 && run[i] <= 202 )
		    {
		       sigma_syst_add += pow(delta,2);
		    }	
		  
		  // frb
		  float delta_frb = frb[idxNom]-frb[i];
		  bool isUp_frb = (delta_frb < 0);
		  float err_frb = delta_frb*delta_frb;
		  if( isUp_frb ) frb_sigma_syst_up += err_frb;
		  else frb_sigma_syst_down += err_frb;
		  if( run[i] < 100 )
		    {		       
		       if( isUp_frb ) frb_sigma_syst_sep.push_back(frb[idxNom]+sqrt(err_frb));
		       else frb_sigma_syst_sep.push_back(frb[idxNom]-sqrt(err_frb));
		       frb_sigma_syst_name.push_back(getSysName(run[i]));
		    }		  		  
		  if( run[i] >= 100 && run[i] <= 202 )
		    {
		       frb_sigma_syst_add += pow(delta_frb,2);
		    }	

		  // frbTag
		  float delta_frb_tag = frbTag[idxNom]-frbTag[i];
		  bool isUp_frb_tag = (delta_frb_tag < 0);
		  float err_frb_tag = delta_frb_tag*delta_frb_tag;
		  if( isUp_frb_tag ) frb_tag_sigma_syst_up += err_frb_tag;
		  else frb_tag_sigma_syst_down += err_frb_tag;
		  if( run[i] < 100 )
		    {		       
		       if( isUp_frb_tag ) frb_tag_sigma_syst_sep.push_back(frbTag[idxNom]+sqrt(err_frb_tag));
		       else frb_tag_sigma_syst_sep.push_back(frbTag[idxNom]-sqrt(err_frb_tag));
		       frb_tag_sigma_syst_name.push_back(getSysName(run[i]));
		    }		  		  
		  if( run[i] >= 100 && run[i] <= 202 )
		    {
		       frb_tag_sigma_syst_add += pow(delta_frb_tag,2);
		    }	
		  
		  // frc
		  float delta_frc = frc[idxNom]-frc[i];
		  bool isUp_frc = (delta_frc < 0);
		  float err_frc = delta_frc*delta_frc;
		  if( isUp_frc ) frc_sigma_syst_up += err_frc;
		  else frc_sigma_syst_down += err_frc;
		  if( run[i] < 100 )
		    {		       
		       if( isUp_frc ) frc_sigma_syst_sep.push_back(frc[idxNom]+sqrt(err_frc));
		       else frc_sigma_syst_sep.push_back(frc[idxNom]-sqrt(err_frc));
		       frc_sigma_syst_name.push_back(getSysName(run[i]));
		    }		  		  
		  if( run[i] >= 100 && run[i] <= 202 )
		    {
		       frc_sigma_syst_add += pow(delta_frc,2);
		    }	

		  // frcTag
		  float delta_frc_tag = frcTag[idxNom]-frcTag[i];
		  bool isUp_frc_tag = (delta_frc_tag < 0);
		  float err_frc_tag = delta_frc_tag*delta_frc_tag;
		  if( isUp_frc_tag ) frc_tag_sigma_syst_up += err_frc_tag;
		  else frc_tag_sigma_syst_down += err_frc_tag;
		  if( run[i] < 100 )
		    {		       
		       if( isUp_frc_tag ) frc_tag_sigma_syst_sep.push_back(frcTag[idxNom]+sqrt(err_frc_tag));
		       else frc_tag_sigma_syst_sep.push_back(frcTag[idxNom]-sqrt(err_frc_tag));
		       frc_tag_sigma_syst_name.push_back(getSysName(run[i]));
		    }		  		  
		  if( run[i] >= 100 && run[i] <= 202 )
		    {
		       frc_tag_sigma_syst_add += pow(delta_frc_tag,2);
		    }	
		  
		  // frl
		  float delta_frl = frl[idxNom]-frl[i];
		  bool isUp_frl = (delta_frl < 0);
		  float err_frl = delta_frl*delta_frl;
		  if( isUp_frl ) frl_sigma_syst_up += err_frl;
		  else frl_sigma_syst_down += err_frl;
		  if( run[i] < 100 )
		    {		       
		       if( isUp_frl ) frl_sigma_syst_sep.push_back(frl[idxNom]+sqrt(err_frl));
		       else frl_sigma_syst_sep.push_back(frl[idxNom]-sqrt(err_frl));
		       frl_sigma_syst_name.push_back(getSysName(run[i]));
		    }		  		  
		  if( run[i] >= 100 && run[i] <= 202 )
		    {
		       frl_sigma_syst_add += pow(delta_frl,2);
		    }	

		  // frlTag
		  float delta_frl_tag = frlTag[idxNom]-frlTag[i];
		  bool isUp_frl_tag = (delta_frl_tag < 0);
		  float err_frl_tag = delta_frl_tag*delta_frl_tag;
		  if( isUp_frl_tag ) frl_tag_sigma_syst_up += err_frl_tag;
		  else frl_tag_sigma_syst_down += err_frl_tag;
		  if( run[i] < 100 )
		    {		       
		       if( isUp_frl_tag ) frl_tag_sigma_syst_sep.push_back(frlTag[idxNom]+sqrt(err_frl_tag));
		       else frl_tag_sigma_syst_sep.push_back(frlTag[idxNom]-sqrt(err_frl_tag));
		       frl_tag_sigma_syst_name.push_back(getSysName(run[i]));
		    }		  		  
		  if( run[i] >= 100 && run[i] <= 202 )
		    {
		       frl_tag_sigma_syst_add += pow(delta_frl_tag,2);
		    }	
	       }
	     else
	       {
		  sf_stat_sum += sf[i];
		  frb_stat_sum += frb[i];
		  frc_stat_sum += frc[i];
		  frl_stat_sum += frl[i];
		  frbTag_stat_sum += frbTag[i];
		  frcTag_stat_sum += frcTag[i];
		  frlTag_stat_sum += frlTag[i];
		  istat++;
	       }	     
	  }
	sigma_syst_add = sqrt(sigma_syst_add);
	frb_sigma_syst_add = sqrt(frb_sigma_syst_add);
	frc_sigma_syst_add = sqrt(frc_sigma_syst_add);
	frl_sigma_syst_add = sqrt(frl_sigma_syst_add);

	frb_tag_sigma_syst_add = sqrt(frb_tag_sigma_syst_add);
	frc_tag_sigma_syst_add = sqrt(frc_tag_sigma_syst_add);
	frl_tag_sigma_syst_add = sqrt(frl_tag_sigma_syst_add);
	
	Comb_sf.push_back(sf[idxNom]);
	
	sf_stat_sum /= istat;	
	frb_stat_sum /= istat;
	frc_stat_sum /= istat;
	frl_stat_sum /= istat;
	frbTag_stat_sum /= istat;
	frcTag_stat_sum /= istat;
	frlTag_stat_sum /= istat;

	float sfcbsys = 0.;
	// add Cb systematics
	if( inclCB )
	  {	     
	     float cb = getCb(tag,"bjet",ipt+1);
//	     float cb = getCb(tag,"bjet",ipt+1+1); //FIXME if include 20-30 bin
	     float cbsys = (1-cb)*0.5/cb;
	     sfcbsys = pow(cbsys*sf[idxNom],2);
	     
	     sigma_syst_up += sfcbsys;
	     sigma_syst_down += sfcbsys;
	  }
	
	// add add
//	sigma_syst_up += sigma_syst_add*sigma_syst_add;
//	sigma_syst_down += sigma_syst_add*sigma_syst_add;
	
	for(int i=0;i<istat;i++)
	  {	     
	     sigma_stat += pow(sf_stat_sum-sf[i],2)/istat;
	     sigma_frb_stat += pow(frb_stat_sum-frb[i],2)/istat;
	     sigma_frc_stat += pow(frc_stat_sum-frc[i],2)/istat;
	     sigma_frl_stat += pow(frl_stat_sum-frl[i],2)/istat;
	     sigma_frbTag_stat += pow(frbTag_stat_sum-frbTag[i],2)/istat;
	     sigma_frcTag_stat += pow(frcTag_stat_sum-frcTag[i],2)/istat;
	     sigma_frlTag_stat += pow(frlTag_stat_sum-frlTag[i],2)/istat;
	  }
	sigma_stat = sqrt(sigma_stat);
	sigma_frb_stat = sqrt(sigma_frb_stat);
	sigma_frc_stat = sqrt(sigma_frc_stat);
	sigma_frl_stat = sqrt(sigma_frl_stat);
	sigma_frbTag_stat = sqrt(sigma_frbTag_stat);
	sigma_frcTag_stat = sqrt(sigma_frcTag_stat);
	sigma_frlTag_stat = sqrt(sigma_frlTag_stat);
	
	sigma_syst_up = sqrt(sigma_syst_up);
	sigma_syst_down = sqrt(sigma_syst_down);

	frb_sigma_syst_up = sqrt(frb_sigma_syst_up);
	frb_sigma_syst_down = sqrt(frb_sigma_syst_down);
	frc_sigma_syst_up = sqrt(frc_sigma_syst_up);
	frc_sigma_syst_down = sqrt(frc_sigma_syst_down);
	frl_sigma_syst_up = sqrt(frl_sigma_syst_up);
	frl_sigma_syst_down = sqrt(frl_sigma_syst_down);

	frb_tag_sigma_syst_up = sqrt(frb_tag_sigma_syst_up);
	frb_tag_sigma_syst_down = sqrt(frb_tag_sigma_syst_down);
	frc_tag_sigma_syst_up = sqrt(frc_tag_sigma_syst_up);
	frc_tag_sigma_syst_down = sqrt(frc_tag_sigma_syst_down);
	frl_tag_sigma_syst_up = sqrt(frl_tag_sigma_syst_up);
	frl_tag_sigma_syst_down = sqrt(frl_tag_sigma_syst_down);
	
	sigma_total_up = sqrt(sigma_stat*sigma_stat+sigma_syst_up*sigma_syst_up);
	sigma_total_down = sqrt(sigma_stat*sigma_stat+sigma_syst_down*sigma_syst_down);

	frb_sigma_total_up = sqrt(sigma_frb_stat*sigma_frb_stat+frb_sigma_syst_up*frb_sigma_syst_up);
	frb_sigma_total_down = sqrt(sigma_frb_stat*sigma_frb_stat+frb_sigma_syst_down*frb_sigma_syst_down);
	frc_sigma_total_up = sqrt(sigma_frc_stat*sigma_frc_stat+frc_sigma_syst_up*frc_sigma_syst_up);
	frc_sigma_total_down = sqrt(sigma_frc_stat*sigma_frc_stat+frc_sigma_syst_down*frc_sigma_syst_down);
	frl_sigma_total_up = sqrt(sigma_frl_stat*sigma_frl_stat+frl_sigma_syst_up*frl_sigma_syst_up);
	frl_sigma_total_down = sqrt(sigma_frl_stat*sigma_frl_stat+frl_sigma_syst_down*frl_sigma_syst_down);

	frb_tag_sigma_total_up = sqrt(sigma_frbTag_stat*sigma_frbTag_stat+frb_tag_sigma_syst_up*frb_tag_sigma_syst_up);
	frb_tag_sigma_total_down = sqrt(sigma_frbTag_stat*sigma_frbTag_stat+frb_tag_sigma_syst_down*frb_tag_sigma_syst_down);
	frc_tag_sigma_total_up = sqrt(sigma_frcTag_stat*sigma_frcTag_stat+frc_tag_sigma_syst_up*frc_tag_sigma_syst_up);
	frc_tag_sigma_total_down = sqrt(sigma_frcTag_stat*sigma_frcTag_stat+frc_tag_sigma_syst_down*frc_tag_sigma_syst_down);
	frl_tag_sigma_total_up = sqrt(sigma_frlTag_stat*sigma_frlTag_stat+frl_tag_sigma_syst_up*frl_tag_sigma_syst_up);
	frl_tag_sigma_total_down = sqrt(sigma_frlTag_stat*sigma_frlTag_stat+frl_tag_sigma_syst_down*frl_tag_sigma_syst_down);
	
	float SF = sf[idxNom];
	float SF_STAT = SF+sigma_stat;
	float SF_SYST_UP = SF+sigma_syst_up;
	float SF_SYST_DOWN = SF-sigma_syst_down;
	float SF_TOTAL_UP = SF+sigma_total_up;
	float SF_TOTAL_DOWN = SF-sigma_total_down;
	
	h_SF->SetBinContent(ipt+1,SF);
	h_SF->SetBinError(ipt+1,sigma_stat);
	
	h_SF_TOTAL_UP->SetBinContent(ipt+1,SF_TOTAL_UP);
	h_SF_TOTAL_DOWN->SetBinContent(ipt+1,SF_TOTAL_DOWN);

	float FRB = frb[idxNom];
	float FRB_STAT = FRB+sigma_frb_stat;
	float FRB_SYST_UP = FRB+frb_sigma_syst_up;
	float FRB_SYST_DOWN = FRB-frb_sigma_syst_down;
	float FRB_TOTAL_UP = FRB+frb_sigma_total_up;
	float FRB_TOTAL_DOWN = FRB-frb_sigma_total_down;
	
	h_frb->SetBinContent(ipt+1,FRB);
	h_frb->SetBinError(ipt+1,sigma_frb_stat);
	h_frb_TOTAL_UP->SetBinContent(ipt+1,FRB_TOTAL_UP);
	h_frb_TOTAL_DOWN->SetBinContent(ipt+1,FRB_TOTAL_DOWN);

	float FRC = frc[idxNom];
	float FRC_STAT = FRC+sigma_frc_stat;
	float FRC_SYST_UP = FRC+frc_sigma_syst_up;
	float FRC_SYST_DOWN = FRC-frc_sigma_syst_down;
	float FRC_TOTAL_UP = FRC+frc_sigma_total_up;
	float FRC_TOTAL_DOWN = FRC-frc_sigma_total_down;
	
	h_frc->SetBinContent(ipt+1,FRC);
	h_frc->SetBinError(ipt+1,sigma_frc_stat);
	h_frc_TOTAL_UP->SetBinContent(ipt+1,FRC_TOTAL_UP);
	h_frc_TOTAL_DOWN->SetBinContent(ipt+1,FRC_TOTAL_DOWN);

	float FRL = frl[idxNom];
	float FRL_STAT = FRL+sigma_frl_stat;
	float FRL_SYST_UP = FRL+frl_sigma_syst_up;
	float FRL_SYST_DOWN = FRL-frl_sigma_syst_down;
	float FRL_TOTAL_UP = FRL+frl_sigma_total_up;
	float FRL_TOTAL_DOWN = FRL-frl_sigma_total_down;
	
	h_frl->SetBinContent(ipt+1,FRL);
	h_frl->SetBinError(ipt+1,sigma_frl_stat);
	h_frl_TOTAL_UP->SetBinContent(ipt+1,FRL_TOTAL_UP);
	h_frl_TOTAL_DOWN->SetBinContent(ipt+1,FRL_TOTAL_DOWN);

	float FRB_TAG = frbTag[idxNom];
	float FRB_TAG_STAT = FRB_TAG+sigma_frbTag_stat;
	float FRB_TAG_SYST_UP = FRB_TAG+frb_tag_sigma_syst_up;
	float FRB_TAG_SYST_DOWN = FRB_TAG-frb_tag_sigma_syst_down;
	float FRB_TAG_TOTAL_UP = FRB_TAG+frb_tag_sigma_total_up;
	float FRB_TAG_TOTAL_DOWN = FRB_TAG-frb_tag_sigma_total_down;
	
	h_frb_tag->SetBinContent(ipt+1,FRB_TAG);
	h_frb_tag->SetBinError(ipt+1,sigma_frbTag_stat);
	h_frb_tag_TOTAL_UP->SetBinContent(ipt+1,FRB_TAG_TOTAL_UP);
	h_frb_tag_TOTAL_DOWN->SetBinContent(ipt+1,FRB_TAG_TOTAL_DOWN);

	float FRC_TAG = frcTag[idxNom];
	float FRC_TAG_STAT = FRC_TAG+sigma_frcTag_stat;
	float FRC_TAG_SYST_UP = FRC_TAG+frc_tag_sigma_syst_up;
	float FRC_TAG_SYST_DOWN = FRC_TAG-frc_tag_sigma_syst_down;
	float FRC_TAG_TOTAL_UP = FRC_TAG+frc_tag_sigma_total_up;
	float FRC_TAG_TOTAL_DOWN = FRC_TAG-frc_tag_sigma_total_down;
	
	h_frc_tag->SetBinContent(ipt+1,FRC_TAG);
	h_frc_tag->SetBinError(ipt+1,sigma_frcTag_stat);
	h_frc_tag_TOTAL_UP->SetBinContent(ipt+1,FRC_TAG_TOTAL_UP);
	h_frc_tag_TOTAL_DOWN->SetBinContent(ipt+1,FRC_TAG_TOTAL_DOWN);

	float FRL_TAG = frlTag[idxNom];
	float FRL_TAG_STAT = FRL_TAG+sigma_frlTag_stat;
	float FRL_TAG_SYST_UP = FRL_TAG+frl_tag_sigma_syst_up;
	float FRL_TAG_SYST_DOWN = FRL_TAG-frl_tag_sigma_syst_down;
	float FRL_TAG_TOTAL_UP = FRL_TAG+frl_tag_sigma_total_up;
	float FRL_TAG_TOTAL_DOWN = FRL_TAG-frl_tag_sigma_total_down;
	
	h_frl_tag->SetBinContent(ipt+1,FRL_TAG);
	h_frl_tag->SetBinError(ipt+1,sigma_frlTag_stat);
	h_frl_tag_TOTAL_UP->SetBinContent(ipt+1,FRL_TAG_TOTAL_UP);
	h_frl_tag_TOTAL_DOWN->SetBinContent(ipt+1,FRL_TAG_TOTAL_DOWN);
	
	// additional uncertainties
	
	// stat
	sigma_syst_name.push_back("up_statistic");
	sigma_syst_sep.push_back(SF+sigma_stat);
	sigma_syst_name.push_back("down_statistic");
	sigma_syst_sep.push_back(SF-sigma_stat);
	
	// cb
	sigma_syst_name.push_back("up_cb");
	sigma_syst_sep.push_back(SF+sqrt(sfcbsys));
	sigma_syst_name.push_back("down_cb");
	sigma_syst_sep.push_back(SF-sqrt(sfcbsys));

	// add
	sigma_syst_name.push_back("up_add");
	sigma_syst_sep.push_back(SF+sigma_syst_add);
	sigma_syst_name.push_back("down_add");
	sigma_syst_sep.push_back(SF-sigma_syst_add);

	// total
	sigma_syst_name.push_back("up");
	sigma_syst_sep.push_back(SF_TOTAL_UP);
	sigma_syst_name.push_back("down");
	sigma_syst_sep.push_back(SF_TOTAL_DOWN);
	
	Comb_sigma_syst.push_back(sigma_syst_sep);
	Comb_sigma_syst_name.push_back(sigma_syst_name);
     }
   
   // draw SF
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   c1->SetGrid(1);
   
   std::string csv = "#bf{"+tagName+"}";
   
   const int np = 2*(nPT+2)+1;
   double xp_sysTot_SF[np];
   double yp_sysTot_SF[np];
   for(int k=0;k<nPT+2;k++)
     {
	float addw = h_SF->GetBinWidth(k)/2.0;
	if( k == 0 ) addw = 0.0;
	if( k == nPT+1 ) addw = h_SF->GetBinWidth(k-1);
	
	int ib = k+1;
	if( k > 0 ) ib--;
	if( k == nPT+1 ) ib--;
	
	xp_sysTot_SF[k] = addw + h_SF->GetXaxis()->GetBinLowEdge(ib);
	yp_sysTot_SF[k] = h_SF_TOTAL_UP->GetBinContent(ib);
	yp_sysTot_SF[nPT+2+k] = h_SF_TOTAL_DOWN->GetBinContent(nPT-(ib-1));
     }      
   for(int k=0;k<nPT+2;k++)
     {
	xp_sysTot_SF[nPT+2+k] = xp_sysTot_SF[nPT+2-k-1];
     }	
   xp_sysTot_SF[np-1] = xp_sysTot_SF[0];   
   yp_sysTot_SF[np-1] = yp_sysTot_SF[0];
   
   TPolyLine *sysTot_SF = new TPolyLine(np,xp_sysTot_SF,yp_sysTot_SF);
   sysTot_SF->SetFillColor(kYellow);
	
   if( !doSFc ) h_SF->GetYaxis()->SetTitle("SF_{b}");
   else h_SF->GetYaxis()->SetTitle("SF_{c}");
   h_SF->GetXaxis()->SetTitle("p_{T} [TeV]");
   h_SF->SetMarkerSize(0.8);

   h_SF->Draw("e1p");
	
   h_SF->GetXaxis()->SetMoreLogLabels();
   h_SF->GetXaxis()->SetNoExponent();
   h_SF->GetYaxis()->SetRangeUser(0.40,1.30);
	
   sysTot_SF->Draw("fSAME");
   h_SF->Draw("e1p same");
   
   TLegend *leg;
   leg = new TLegend(0.35,0.45,0.70,0.20);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   TLatex *legl = new TLatex();
   legl->SetNDC();
   legl->SetTextAlign(22);
   legl->SetTextFont(63);
   legl->SetTextSizePixels(30);
   legl->DrawLatex(0.55,0.82,csv.c_str());
   
   leg->AddEntry(h_SF,"Scale factor","p");
   leg->AddEntry(h_SF,"stat","l");
   leg->AddEntry(sysTot_SF,"stat #oplus syst","f");
   
   c1->RedrawAxis("g");
   
   leg->Draw();
   
//   c1->SetLogx(1);
//   TLatex *lab = CMSLABEL();
//   lab->Draw("same");
   
   TLatex *tex = new TLatex(0.1969,0.906825,"CMS");
   tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(61);
   tex->SetTextSize(0.07475);
   tex->SetLineWidth(2);
   tex->Draw();

   TLatex *tex2 = new TLatex(0.1969,0.817125,"Preliminary");
   tex2->SetNDC();
   tex2->SetTextAlign(13);
   tex2->SetTextFont(52);
   tex2->SetTextSize(0.05681);
   tex2->SetLineWidth(2);
   tex2->Draw();

   TLatex *text1 = new TLatex(0.98,0.95125,"#sqrt{s} = 13 TeV, 25 ns");
   text1->SetNDC();
   text1->SetTextAlign(31);
   text1->SetTextFont(42);
   text1->SetTextSize(0.04875);
   text1->SetLineWidth(2);
   text1->Draw();
   
   std::string picname = "pics/SF_"+tag+".eps";
   c1->Print(picname.c_str());
   c1->Clear();
   
   delete sysTot_SF;
   
   delete c1;
   delete leg;
   delete legl;

   // draw fractions noTag
   TCanvas *c2 = new TCanvas("c2","c2",0,0,600,500);
   c2->SetGrid(1);

   // frb
   double xp_sysTot_FRB[np];
   double yp_sysTot_FRB[np];
   for(int k=0;k<nPT+2;k++)
     {
	float addw = h_frb->GetBinWidth(k)/2.0;
	if( k == 0 ) addw = 0.0;
	if( k == nPT+1 ) addw = h_frb->GetBinWidth(k-1);
	
	int ib = k+1;
	if( k > 0 ) ib--;
	if( k == nPT+1 ) ib--;
	
	xp_sysTot_FRB[k] = addw + h_frb->GetXaxis()->GetBinLowEdge(ib);
	yp_sysTot_FRB[k] = h_frb_TOTAL_UP->GetBinContent(ib);
	yp_sysTot_FRB[nPT+2+k] = h_frb_TOTAL_DOWN->GetBinContent(nPT-(ib-1));
     }      
   for(int k=0;k<nPT+2;k++)
     {
	xp_sysTot_FRB[nPT+2+k] = xp_sysTot_FRB[nPT+2-k-1];
     }	
   xp_sysTot_FRB[np-1] = xp_sysTot_FRB[0];
   yp_sysTot_FRB[np-1] = yp_sysTot_FRB[0];
   
   TPolyLine *sysTot_FRB = new TPolyLine(np,xp_sysTot_FRB,yp_sysTot_FRB);
   sysTot_FRB->SetFillColor(kRed);
   sysTot_FRB->SetLineColor(kRed);
//   sysTot_FRB->SetFillStyle(0);
   
   // frc
   double xp_sysTot_FRC[np];
   double yp_sysTot_FRC[np];
   for(int k=0;k<nPT+2;k++)
     {
	float addw = h_frc->GetBinWidth(k)/2.0;
	if( k == 0 ) addw = 0.0;
	if( k == nPT+1 ) addw = h_frc->GetBinWidth(k-1);
	
	int ib = k+1;
	if( k > 0 ) ib--;
	if( k == nPT+1 ) ib--;
	
	xp_sysTot_FRC[k] = addw + h_frc->GetXaxis()->GetBinLowEdge(ib);
	yp_sysTot_FRC[k] = h_frc_TOTAL_UP->GetBinContent(ib);
	yp_sysTot_FRC[nPT+2+k] = h_frc_TOTAL_DOWN->GetBinContent(nPT-(ib-1));
     }      
   for(int k=0;k<nPT+2;k++)
     {
	xp_sysTot_FRC[nPT+2+k] = xp_sysTot_FRC[nPT+2-k-1];
     }	
   xp_sysTot_FRC[np-1] = xp_sysTot_FRC[0];
   yp_sysTot_FRC[np-1] = yp_sysTot_FRC[0];
   
   TPolyLine *sysTot_FRC = new TPolyLine(np,xp_sysTot_FRC,yp_sysTot_FRC);
   sysTot_FRC->SetFillColor(kGreen);
   sysTot_FRC->SetLineColor(kGreen);
//   sysTot_FRC->SetFillStyle(0);

   // frl
   double xp_sysTot_FRL[np];
   double yp_sysTot_FRL[np];
   for(int k=0;k<nPT+2;k++)
     {
	float addw = h_frl->GetBinWidth(k)/2.0;
	if( k == 0 ) addw = 0.0;
	if( k == nPT+1 ) addw = h_frl->GetBinWidth(k-1);
	
	int ib = k+1;
	if( k > 0 ) ib--;
	if( k == nPT+1 ) ib--;
	
	xp_sysTot_FRL[k] = addw + h_frl->GetXaxis()->GetBinLowEdge(ib);
	yp_sysTot_FRL[k] = h_frl_TOTAL_UP->GetBinContent(ib);
	yp_sysTot_FRL[nPT+2+k] = h_frl_TOTAL_DOWN->GetBinContent(nPT-(ib-1));
     }      
   for(int k=0;k<nPT+2;k++)
     {
	xp_sysTot_FRL[nPT+2+k] = xp_sysTot_FRL[nPT+2-k-1];
     }	
   xp_sysTot_FRL[np-1] = xp_sysTot_FRL[0];
   yp_sysTot_FRL[np-1] = yp_sysTot_FRL[0];
   
   TPolyLine *sysTot_FRL = new TPolyLine(np,xp_sysTot_FRL,yp_sysTot_FRL);
   sysTot_FRL->SetFillColor(kBlue);
   sysTot_FRL->SetLineColor(kBlue);
   
   h_frb->GetYaxis()->SetTitle("Fit fraction");
   h_frb->GetXaxis()->SetTitle("p_{T} [TeV]");
   
   h_frb->SetMarkerSize(1.0);
   h_frc->SetMarkerSize(1.0);
   h_frl->SetMarkerSize(1.0);

   h_frb->SetMarkerStyle(20);
   h_frc->SetMarkerStyle(22);
   h_frl->SetMarkerStyle(24);
   
   h_frb->SetMarkerColor(0);
   h_frc->SetMarkerColor(0);
   h_frl->SetMarkerColor(0);

   h_frb->SetLineColor(0);
   h_frc->SetLineColor(0);
   h_frl->SetLineColor(0);
   
   h_frb->Draw("e1p");
   h_frc->Draw("e1p same");
   h_frl->Draw("e1p same");
	
   h_frb->GetXaxis()->SetMoreLogLabels();
   h_frb->GetXaxis()->SetNoExponent();
   h_frb->GetYaxis()->SetRangeUser(0.00,1.50);

   sysTot_FRB->Draw("fSAME");
   sysTot_FRC->Draw("fSAME");
   sysTot_FRL->Draw("fSAME");
   h_frb->Draw("e1p same");
   h_frc->Draw("e1p same");
   h_frl->Draw("e1p same");
   
   TLegend *leg2;
   leg2 = new TLegend(0.70,0.85,0.95,0.70);
   leg2->SetFillColor(253);
   leg2->SetBorderSize(0);
   
   TLatex *legl2 = new TLatex();
   legl2->SetNDC();
   legl2->SetTextAlign(22);
   legl2->SetTextFont(63);
   legl2->SetTextSizePixels(30);
//   legl2->DrawLatex(0.55,0.82,csv.c_str());
   legl2->DrawLatex(0.55,0.82,"Pre-tag");
   
   TH1D *h_frb_clone = (TH1D*)h_frb->Clone("h_frb_clone");
   TH1D *h_frc_clone = (TH1D*)h_frc->Clone("h_frc_clone");
   TH1D *h_frl_clone = (TH1D*)h_frl->Clone("h_frl_clone");
   
   h_frb_clone->SetMarkerColor(2);
   h_frc_clone->SetMarkerColor(3);
   h_frl_clone->SetMarkerColor(4);
  
   h_frb_clone->SetLineColor(2);
   h_frc_clone->SetLineColor(3);
   h_frl_clone->SetLineColor(4);

   leg2->AddEntry(h_frb_clone,"b-jets","lp");
   leg2->AddEntry(h_frc_clone,"c-jets","lp");
   leg2->AddEntry(h_frl_clone,"udsg-jets","lp");
   
   c2->RedrawAxis("g");
   
   leg2->Draw();
   
   c2->SetLogx(1);

   tex->Draw();
   tex2->Draw();
   text1->Draw();
   
   picname = "pics/Fr_noTag.eps";
   c2->Print(picname.c_str());
   c2->Clear();

   // draw fractions Tag
   TCanvas *c3 = new TCanvas("c3","c3",0,0,600,500);
   c3->SetGrid(1);

   // frb
   double xp_sysTot_FRB_TAG[np];
   double yp_sysTot_FRB_TAG[np];
   for(int k=0;k<nPT+2;k++)
     {
	float addw = h_frb_tag->GetBinWidth(k)/2.0;
	if( k == 0 ) addw = 0.0;
	if( k == nPT+1 ) addw = h_frb_tag->GetBinWidth(k-1);
	
	int ib = k+1;
	if( k > 0 ) ib--;
	if( k == nPT+1 ) ib--;
	
	xp_sysTot_FRB_TAG[k] = addw + h_frb_tag->GetXaxis()->GetBinLowEdge(ib);
	yp_sysTot_FRB_TAG[k] = h_frb_tag_TOTAL_UP->GetBinContent(ib);
	yp_sysTot_FRB_TAG[nPT+2+k] = h_frb_tag_TOTAL_DOWN->GetBinContent(nPT-(ib-1));
     }      
   for(int k=0;k<nPT+2;k++)
     {
	xp_sysTot_FRB_TAG[nPT+2+k] = xp_sysTot_FRB_TAG[nPT+2-k-1];
     }	
   xp_sysTot_FRB_TAG[np-1] = xp_sysTot_FRB_TAG[0];
   yp_sysTot_FRB_TAG[np-1] = yp_sysTot_FRB_TAG[0];
   
   TPolyLine *sysTot_FRB_TAG = new TPolyLine(np,xp_sysTot_FRB_TAG,yp_sysTot_FRB_TAG);
   sysTot_FRB_TAG->SetFillColor(kRed);
   sysTot_FRB_TAG->SetLineColor(kRed);
   
   // frc
   double xp_sysTot_FRC_TAG[np];
   double yp_sysTot_FRC_TAG[np];
   for(int k=0;k<nPT+2;k++)
     {
	float addw = h_frc_tag->GetBinWidth(k)/2.0;
	if( k == 0 ) addw = 0.0;
	if( k == nPT+1 ) addw = h_frc_tag->GetBinWidth(k-1);
	
	int ib = k+1;
	if( k > 0 ) ib--;
	if( k == nPT+1 ) ib--;
	
	xp_sysTot_FRC_TAG[k] = addw + h_frc_tag->GetXaxis()->GetBinLowEdge(ib);
	yp_sysTot_FRC_TAG[k] = h_frc_tag_TOTAL_UP->GetBinContent(ib);
	yp_sysTot_FRC_TAG[nPT+2+k] = h_frc_tag_TOTAL_DOWN->GetBinContent(nPT-(ib-1));
     }      
   for(int k=0;k<nPT+2;k++)
     {
	xp_sysTot_FRC_TAG[nPT+2+k] = xp_sysTot_FRC_TAG[nPT+2-k-1];
     }	
   xp_sysTot_FRC_TAG[np-1] = xp_sysTot_FRC_TAG[0];
   yp_sysTot_FRC_TAG[np-1] = yp_sysTot_FRC_TAG[0];
   
   TPolyLine *sysTot_FRC_TAG = new TPolyLine(np,xp_sysTot_FRC_TAG,yp_sysTot_FRC_TAG);
   sysTot_FRC_TAG->SetFillColor(kGreen);
   sysTot_FRC_TAG->SetLineColor(kGreen);

   // frl
   double xp_sysTot_FRL_TAG[np];
   double yp_sysTot_FRL_TAG[np];
   for(int k=0;k<nPT+2;k++)
     {
	float addw = h_frl_tag->GetBinWidth(k)/2.0;
	if( k == 0 ) addw = 0.0;
	if( k == nPT+1 ) addw = h_frl_tag->GetBinWidth(k-1);
	
	int ib = k+1;
	if( k > 0 ) ib--;
	if( k == nPT+1 ) ib--;
	
	xp_sysTot_FRL_TAG[k] = addw + h_frl_tag->GetXaxis()->GetBinLowEdge(ib);
	yp_sysTot_FRL_TAG[k] = h_frl_tag_TOTAL_UP->GetBinContent(ib);
	yp_sysTot_FRL_TAG[nPT+2+k] = h_frl_tag_TOTAL_DOWN->GetBinContent(nPT-(ib-1));
     }      
   for(int k=0;k<nPT+2;k++)
     {
	xp_sysTot_FRL_TAG[nPT+2+k] = xp_sysTot_FRL_TAG[nPT+2-k-1];
     }	
   xp_sysTot_FRL_TAG[np-1] = xp_sysTot_FRL_TAG[0];
   yp_sysTot_FRL_TAG[np-1] = yp_sysTot_FRL_TAG[0];
   
   TPolyLine *sysTot_FRL_TAG = new TPolyLine(np,xp_sysTot_FRL_TAG,yp_sysTot_FRL_TAG);
   sysTot_FRL_TAG->SetFillColor(kBlue);
   sysTot_FRL_TAG->SetLineColor(kBlue);
   
   h_frb_tag->GetYaxis()->SetTitle("Fit fraction");
   h_frb_tag->GetXaxis()->SetTitle("p_{T} [TeV]");
   
   h_frb_tag->SetMarkerSize(1.0);
   h_frc_tag->SetMarkerSize(1.0);
   h_frl_tag->SetMarkerSize(1.0);

   h_frb_tag->SetMarkerStyle(20);
   h_frc_tag->SetMarkerStyle(22);
   h_frl_tag->SetMarkerStyle(24);
   
   h_frb_tag->SetMarkerColor(0);
   h_frc_tag->SetMarkerColor(0);
   h_frl_tag->SetMarkerColor(0);

   h_frb_tag->SetLineColor(0);
   h_frc_tag->SetLineColor(0);
   h_frl_tag->SetLineColor(0);
   
   h_frb_tag->Draw("e1p");
   h_frc_tag->Draw("e1p same");
   h_frl_tag->Draw("e1p same");
	
   h_frb_tag->GetXaxis()->SetMoreLogLabels();
   h_frb_tag->GetXaxis()->SetNoExponent();
   h_frb_tag->GetYaxis()->SetRangeUser(0.00,1.50);

   sysTot_FRB_TAG->Draw("fSAME");
   sysTot_FRC_TAG->Draw("fSAME");
   sysTot_FRL_TAG->Draw("fSAME");
   h_frb_tag->Draw("e1p same");
   h_frc_tag->Draw("e1p same");
   h_frl_tag->Draw("e1p same");
   
   TLegend *leg3;
   leg3 = new TLegend(0.70,0.85,0.95,0.70);
   leg3->SetFillColor(253);
   leg3->SetBorderSize(0);
   
   TLatex *legl3 = new TLatex();
   legl3->SetNDC();
   legl3->SetTextAlign(22);
   legl3->SetTextFont(63);
   legl3->SetTextSizePixels(30);
   legl3->DrawLatex(0.55,0.82,csv.c_str());

   TH1D *h_frb_tag_clone = (TH1D*)h_frb_tag->Clone("h_frb_tag_clone");
   TH1D *h_frc_tag_clone = (TH1D*)h_frc_tag->Clone("h_frc_tag_clone");
   TH1D *h_frl_tag_clone = (TH1D*)h_frl_tag->Clone("h_frl_tag_clone");
   
   h_frb_tag_clone->SetMarkerColor(2);
   h_frc_tag_clone->SetMarkerColor(3);
   h_frl_tag_clone->SetMarkerColor(4);
  
   h_frb_tag_clone->SetLineColor(2);
   h_frc_tag_clone->SetLineColor(3);
   h_frl_tag_clone->SetLineColor(4);
   
   leg3->AddEntry(h_frb_tag_clone,"b-jets","lp");
   leg3->AddEntry(h_frc_tag_clone,"c-jets","lp");
   leg3->AddEntry(h_frl_tag_clone,"udsg-jets","lp");
   
   c3->RedrawAxis("g");
   
   leg3->Draw();
   
   c3->SetLogx(1);

   tex->Draw();
   tex2->Draw();
   text1->Draw();
   
   picname = "pics/Fr_"+tag+".eps";
   c3->Print(picname.c_str());
   c3->Clear();
   
   std::ofstream fsf("results/SFSYS.tex");

   std::string header = "\n \
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|} \n \
\\hline";
   
   fsf << header << std::endl;

   std::string linh = "$P_{T} [GeV]$ & SF & Stat & $N_{trk}$ & $N_{jets}$ \
& $P_{T} (\\mu)$ & Gluon splitting & b-frag & $D \\to \\mu X$ \
& c-frag & $K_{S}^{0} (\\Lambda)$ & JES & $C_{b}$ & Additional & Total \\\\ \\hline";

   fsf << linh << std::endl;
   
   // write csv file
   for(int ipt=0;ipt<nPT;ipt++)
     {
	int nMeas = Comb_sigma_syst_name[ipt].size();

	std::string ptbin = "";
	if( ipt == 0 ) ptbin = "30-50";
	if( ipt == 1 ) ptbin = "50-70";
	if( ipt == 2 ) ptbin = "70-100";
	if( ipt == 3 ) ptbin = "100-140";
	if( ipt == 4 ) ptbin = "140-200";
	if( ipt == 5 ) ptbin = "200-300";
	if( ipt == 6 ) ptbin = "300-670";

	std::string lin = "";
	lin += ptbin;
	lin += " & ";
	
	std::string sys_ntrk = "";
	std::string sys_njet = "";
	std::string sys_mupt = "";
	std::string sys_gluonsplitting = "";
	std::string sys_bfragmentation = "";
	std::string sys_dmux = "";
	std::string sys_cfragmentation = "";
	std::string sys_ksl = "";
	std::string sys_jes = "";
	std::string sys_cb = "";
	std::string sys_add = "";
	std::string sys_statistic = "";
	std::string sys_total = "";
	
//	std::cout << "-----" << std::endl;
	for(int i=0;i<nMeas;i++)
	  {
//	     std::cout << Comb_sigma_syst_name[ipt][i] << std::endl;

	     sfComb << Comb_op[ipt] << "," <<
	       Comb_type[ipt] << "," <<
	       Comb_sigma_syst_name[ipt][i] << "," <<
	       Comb_flav[ipt] << "," <<
	       Comb_etaMin[ipt] << "," <<
	       Comb_etaMax[ipt] << "," <<
	       Comb_ptMin[ipt] << "," <<
	       Comb_ptMax[ipt] << "," <<
	       Comb_discMin[ipt] << "," <<
	       Comb_discMax[ipt] << "," <<
	       Comb_sigma_syst[ipt][i] << 
	       std::endl;

	     float shift = Comb_sigma_syst[ipt][i]-Comb_sigma_syst[ipt][0];
	     
	     if( i == 0 )
	       {		  
		  lin += std::string(Form("%.3f",Comb_sigma_syst[ipt][i]));
		  lin += " & ";
	       }
	     else if( Comb_sigma_syst_name[ipt][i] == "up_ntrk" || Comb_sigma_syst_name[ipt][i] == "down_ntrk" )
	       {		  
		  sys_ntrk += std::string(Form("%.3f",shift)) + " ";
	       }	     
	     else if( Comb_sigma_syst_name[ipt][i] == "up_njet" || Comb_sigma_syst_name[ipt][i] == "down_njet" )
	       {
		  sys_njet += std::string(Form("%.3f",shift)) + " ";
	       }	     
	     else if( Comb_sigma_syst_name[ipt][i] == "up_mupt" || Comb_sigma_syst_name[ipt][i] == "down_mupt" )
	       {
		  sys_mupt += std::string(Form("%.3f",shift)) + " ";
	       }	     
	     else if( Comb_sigma_syst_name[ipt][i] == "up_gluonsplitting" || Comb_sigma_syst_name[ipt][i] == "down_gluonsplitting" )
	       {
		  sys_gluonsplitting += std::string(Form("%.3f",shift)) + " ";
	       }	     
	     else if( Comb_sigma_syst_name[ipt][i] == "up_bfragmentation" || Comb_sigma_syst_name[ipt][i] == "down_bfragmentation" )
	       {
		  sys_bfragmentation += std::string(Form("%.3f",shift)) + " ";
	       }	     
	     else if( Comb_sigma_syst_name[ipt][i] == "up_dmux" || Comb_sigma_syst_name[ipt][i] == "down_dmux" )
	       {
		  sys_dmux += std::string(Form("%.3f",shift)) + " ";
	       }	     
	     else if( Comb_sigma_syst_name[ipt][i] == "up_cfragmentation" || Comb_sigma_syst_name[ipt][i] == "down_cfragmentation" )
	       {
		  sys_cfragmentation += std::string(Form("%.3f",shift)) + " ";
	       }	     
	     else if( Comb_sigma_syst_name[ipt][i] == "up_ksl" || Comb_sigma_syst_name[ipt][i] == "down_ksl" )
	       {
		  sys_ksl += std::string(Form("%.3f",shift)) + " ";
	       }	     
	     else if( Comb_sigma_syst_name[ipt][i] == "up_jes" || Comb_sigma_syst_name[ipt][i] == "down_jes" )
	       {
		  sys_jes += std::string(Form("%.3f",shift)) + " ";
	       }	     
	     else if( Comb_sigma_syst_name[ipt][i] == "up_cb" || Comb_sigma_syst_name[ipt][i] == "down_cb" )
	       {
		  sys_cb += std::string(Form("%.3f",shift)) + " ";
	       }	     
	     else if( Comb_sigma_syst_name[ipt][i] == "up_add" || Comb_sigma_syst_name[ipt][i] == "down_add" )
	       {
		  sys_add += std::string(Form("%.3f",shift)) + " ";
	       }	     
	     else if( Comb_sigma_syst_name[ipt][i] == "up_statistic" || Comb_sigma_syst_name[ipt][i] == "down_statistic" )
	       {
		  sys_statistic += std::string(Form("%.3f",shift)) + " ";
	       }	     
	     else if( Comb_sigma_syst_name[ipt][i] == "up" || Comb_sigma_syst_name[ipt][i] == "down" )
	       {
		  sys_total += std::string(Form("%.3f",shift)) + " ";
	       }	     
	  }
	
	lin += sys_statistic + " & ";
	lin += sys_ntrk + " & ";
	lin += sys_njet + " & ";
	lin += sys_mupt + " & ";
	lin += sys_gluonsplitting + " & ";
	lin += sys_bfragmentation + " & ";
	lin += sys_dmux + " & ";
	lin += sys_cfragmentation + " & ";
	lin += sys_ksl + " & ";
	lin += sys_jes + " & ";
	lin += sys_cb + " & ";
	lin += sys_add + " & ";
	lin += sys_total + " \\\\ ";

	fsf << lin << std::endl;
     }   

   std::string footer = "\\hline \n \
\\end{tabular}";
   
   fsf << footer << std::endl;

   sfComb.close();
     
   gApplication->Terminate();
}

void SetPlotStyle()
{
   TStyle *styleCurrent = gROOT->GetStyle("PLOT");
   if( !styleCurrent )
     {
	static TStyle* plotStyle = 0;
	if( plotStyle == 0 ) plotStyle = PlotStyleCMS();
	gROOT->SetStyle("PLOT");
	gROOT->ForceStyle();
     }
}

TStyle* PlotStyleCMS()
{
   TStyle *plotStyle = new TStyle("PLOT","Plot style CMS");

   plotStyle->SetOptTitle(0);
   plotStyle->SetOptStat(0);
   plotStyle->SetOptFit(0);
   
   plotStyle->SetPaperSize(20.,26.);

   plotStyle->SetEndErrorSize(2);
//   plotStyle->SetErrorX(0.);
   
   plotStyle->SetFrameBorderMode(0);
   plotStyle->SetFrameFillColor(0);
   plotStyle->SetFrameFillStyle(0);
   plotStyle->SetCanvasBorderMode(0);
   plotStyle->SetFillColor(0);
   plotStyle->SetCanvasColor(0);
   plotStyle->SetCanvasBorderSize(2);
   
   plotStyle->SetPadBorderMode(0);
   plotStyle->SetPadColor(0);
   plotStyle->SetPadGridX(false);
   plotStyle->SetPadGridY(false);
   plotStyle->SetGridColor(0);
   plotStyle->SetGridStyle(3);
   plotStyle->SetGridWidth(1);
   
//   plotStyle->SetCanvasDefH(600);
//   plotStyle->SetCanvasDefW(600);
   plotStyle->SetCanvasDefX(0);
   plotStyle->SetCanvasDefY(0);
     
   plotStyle->SetHistLineColor(1);
   plotStyle->SetHistLineStyle(0);
   plotStyle->SetHistLineWidth(1);
   
   plotStyle->SetPadTickX(1);
   plotStyle->SetPadTickY(1);
   
   plotStyle->SetPadLeftMargin(0.16);
   plotStyle->SetPadRightMargin(0.02);
   plotStyle->SetPadTopMargin(0.06);
   plotStyle->SetPadBottomMargin(0.13);

   plotStyle->SetLabelFont(42,"x");
   plotStyle->SetTitleFont(42,"x");
   plotStyle->SetLabelFont(42,"y");
   plotStyle->SetTitleFont(42,"y");
   plotStyle->SetLabelFont(42,"z");
   plotStyle->SetTitleFont(42,"z");

   plotStyle->SetLabelSize(0.05,"x");
   plotStyle->SetTitleSize(0.06,"x");
   plotStyle->SetLabelSize(0.05,"y");
   plotStyle->SetTitleSize(0.06,"y");
   plotStyle->SetLabelSize(0.035,"z");
   plotStyle->SetTitleSize(0.035,"z");

   plotStyle->SetLabelOffset(0.007,"XYZ");
   
   plotStyle->SetNdivisions(510,"XYZ");
   plotStyle->SetStripDecimals(kTRUE);
   plotStyle->SetTickLength(0.03, "XYZ");
   
   plotStyle->SetTitleXOffset(0.9);
   plotStyle->SetTitleYOffset(1.25);

   plotStyle->SetMarkerStyle(20);
   plotStyle->SetMarkerSize(1.2);
   
   return plotStyle;
}

TStyle* PlotStyle()
{
   TStyle *plotStyle = new TStyle("PLOT","Plot style");
   
   // use plain black on white colors
   Int_t icol=0; // WHITE
   plotStyle->SetFrameBorderMode(icol);
   plotStyle->SetFrameFillColor(icol);
   plotStyle->SetCanvasBorderMode(icol);
   plotStyle->SetCanvasColor(icol);
   plotStyle->SetPadBorderMode(icol);
   plotStyle->SetPadColor(icol);
   plotStyle->SetStatColor(icol);
   
   // set the paper & margin sizes
   plotStyle->SetPaperSize(20,26);
   
   // set margin sizes
   plotStyle->SetPadTopMargin(0.05);
   plotStyle->SetPadRightMargin(0.05);
   plotStyle->SetPadBottomMargin(0.16);
   plotStyle->SetPadLeftMargin(0.16);
   
   // set title offsets (for axis label)
   plotStyle->SetTitleXOffset(1.4);
   plotStyle->SetTitleYOffset(1.4);
   
   // use large fonts
   Int_t font=42;
   Double_t tsize=0.05;
   plotStyle->SetTextFont(font);
   
   plotStyle->SetTextSize(tsize);
   plotStyle->SetLabelFont(font,"x");
   plotStyle->SetTitleFont(font,"x");
   plotStyle->SetLabelFont(font,"y");
   plotStyle->SetTitleFont(font,"y");
   plotStyle->SetLabelFont(font,"z");
   plotStyle->SetTitleFont(font,"z");
   
   plotStyle->SetLabelSize(tsize,"x");
   plotStyle->SetTitleSize(tsize,"x");
   plotStyle->SetLabelSize(tsize,"y");
   plotStyle->SetTitleSize(tsize,"y");
   plotStyle->SetLabelSize(tsize,"z");
   plotStyle->SetTitleSize(tsize,"z");
   
   // use bold lines and markers
   plotStyle->SetMarkerStyle(20);
   plotStyle->SetMarkerSize(1.2);
   plotStyle->SetHistLineWidth(2.);
   plotStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes
   
   // get rid of X error bars
   // plotStyle->SetErrorX(0.001);
   // get rid of error bar caps
   plotStyle->SetEndErrorSize(0.);
   
   // do not display any of the standard histogram decorations
   plotStyle->SetOptTitle(0);
   //plotStyle->SetOptStat(1111);
   plotStyle->SetOptStat(0);
   //plotStyle->SetOptFit(1111);
   plotStyle->SetOptFit(0);
   
   // put tick marks on top and RHS of plots
   plotStyle->SetPadTickX(1);
   plotStyle->SetPadTickY(1);
   
   return plotStyle;
}

float getCb(std::string tag,std::string flav,int binIdx)
{   
   const int nPT = 15;
   
   float cb[nPT];
   
//   std::string fcb = "../../CbFactor/cb_"+tag+"_"+flav+".txt";
   std::string fcb = "../../CbFactorSub/cb_"+tag+"_"+flav+".txt";
   
   std::ifstream f(fcb.c_str());
   if( !f.good() )
     {
	std::cout << "No Cb file" << std::endl;
	exit(1);
     }   
   
   while( !f.eof() )
     {
	int ibin;
	float cbVal;
	float cbErr;
	
	f >> ibin >> cbVal >> cbErr; 
	cb[ibin] = cbVal;
     }   
   
   return cb[binIdx-1];
}

std::string getSysName(int idx)
{
   std::string name = "";
/*   if( idx == 0 ) name = "central";
   else if( idx == 1 ) name = "up_ntrk";
   else if( idx == -1 ) name = "down_ntrk";
   else if( idx == 2 ) name = "up_njet";
   else if( idx == -2 ) name = "down_njet";
   else if( idx == 3 ) name = "up_mupt";
   else if( idx == -3 ) name = "down_mupt";
//   else if( idx == 4 ) name = "up_jeta";
//   else if( idx == -4 ) name = "down_jeta";
//   else if( idx == 5 ) name = "up_pileup";
//   else if( idx == -5 ) name = "down_pileup";
   else if( idx == 4 ) name = "up_gluonsplitting";
   else if( idx == -4 ) name = "down_gluonsplitting";
   else if( idx == 5 ) name = "up_bfragmentation";
   else if( idx == -5 ) name = "down_bfragmentation";
   else if( idx == 6 ) name = "up_dmux";
   else if( idx == -6 ) name = "down_dmux";
   else if( idx == 7 ) name = "up_cfragmentation";
   else if( idx == -7 ) name = "down_cfragmentation";
   else if( idx == 8 ) name = "up_ksl";
   else if( idx == -8 ) name = "down_ksl";
//   else if( idx == 9 ) name = "up_ntrkgen";
//   else if( idx == -9 ) name = "down_ntrkgen";
   else if( idx == 9 ) name = "up_jes";
   else if( idx == -9 ) name = "down_jes";
//   else if( idx == 12 ) name = "up_jes";
//   else if( idx == -12 ) name = "down_jes";
//   else if( idx == 13 ) name = "up_jer";
//   else if( idx == -13 ) name = "down_jer";
   return name;*/
   
   if( idx == 0 ) name = "central";
   else if( idx == 1 ) name = "up_ntrk";
   else if( idx == -1 ) name = "down_ntrk";
//   else if( idx == 2 ) name = "up_mupt";
//   else if( idx == -2 ) name = "down_mupt";
//   else if( idx == 4 ) name = "up_jeta";
//   else if( idx == -4 ) name = "down_jeta";
//   else if( idx == 5 ) name = "up_pileup";
//   else if( idx == -5 ) name = "down_pileup";
   else if( idx == 2 ) name = "up_gluonsplitting";
   else if( idx == -2 ) name = "down_gluonsplitting";
   else if( idx == 3 ) name = "up_bfragmentation";
   else if( idx == -3 ) name = "down_bfragmentation";
   else if( idx == 4 ) name = "up_dmux";
   else if( idx == -4 ) name = "down_dmux";
   else if( idx == 5 ) name = "up_cfragmentation";
   else if( idx == -5 ) name = "down_cfragmentation";
//   else if( idx == 7 ) name = "up_ksl";
//   else if( idx == -7 ) name = "down_ksl";
//   else if( idx == 8 ) name = "up_ntrkgen";
//   else if( idx == -8 ) name = "down_ntrkgen";
   else if( idx == 6 ) name = "up_jes";
   else if( idx == -6 ) name = "down_jes";
//   else if( idx == 12 ) name = "up_jes";
//   else if( idx == -12 ) name = "down_jes";
//   else if( idx == 13 ) name = "up_jer";
//   else if( idx == -13 ) name = "down_jer";
   return name;
}

TLatex* CMSLABEL()
{
   TLatex *text1 = new TLatex(3.14,23.08044,"CMS Preliminary #sqrt{s} = 13 TeV, 25 ns");

   text1->SetNDC();
   text1->SetTextAlign(13);
   text1->SetX(0.238);
   text1->SetY(0.928);
   text1->SetTextFont(42);
   text1->SetTextSizePixels(24);

   return text1;
}
