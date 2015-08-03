TStyle* PlotStyle();
void SetPlotStyle();
float getCb(std::string,std::string,int);
std::string getSysName(int);

std::string SFver = "20150803";
bool inclCB = 1;

void combine()
{
   gROOT->SetBatch(1);

   SetPlotStyle();

   std::string tag = "CSVM";

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

   
   const int nPT = 7;
   std::string pt[nPT] =
     {
//	"pt20t30",
	"pt30t50",
	"pt50t70",
	"pt70t100",
	"pt100t140",
	"pt140t200",
	"pt200t300",
	"pt300t670"
     };
   
   
   int ptb[nPT+1] =
     {
//	20,30,40,50,60,70,80,100,120,160,210,260,320,400,500,670
//	20,30,40,50,60,70,80,100,120,160,210,260,320,400,500
//	20,30,50,70,100,140,250,450
	30,50,70,100,140,200,300,670 // CSVL
     };
   
   float xbins[nPT];
   for(int j=0;j<=nPT;j++)
     {
	xbins[j] = ptb[j]/1000.;
     }
   
   TH1F *h_SF = new TH1F("h_SF","h_SF",nPT,xbins);
   TH1F *h_SF_TOTAL_UP = new TH1F("h_SF_TOTAL_UP","h_SF_TOTAL_UP",nPT,xbins);
   TH1F *h_SF_TOTAL_DOWN = new TH1F("h_SF_TOTAL_DOWN","h_SF_TOTAL_DOWN",nPT,xbins);

   std::string head = "CSV;OperatingPoint,measurementType,sysType,jetFlavor,etaMin,etaMax,ptMin,ptMax,discrMin,discrMax,formula";
   std::string fname = "results/CSV_13TEV_"+SFver+"_"+tag+"_LT.csv";
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
	if( tag == "CSVL" ) Comb_op.push_back(0);
	else if( tag == "CSVM" ) Comb_op.push_back(1);
	else if( tag == "CSVT" ) Comb_op.push_back(2);
	
	Comb_type.push_back("lt");
	Comb_flav.push_back(0);
	Comb_etaMin.push_back(0.0);
	Comb_etaMax.push_back(2.4);
	Comb_discMin.push_back(0.0);
	Comb_discMax.push_back(1.0);
	
	std::vector<int> run;
	std::vector<float> sf;
	
	int idxNom = -666;

	for(int is=0;is<=1;is++)
	  {
	     std::string prefix = "results/";
	     if( is == 1 ) prefix = "results_away/";
	     
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

		       if( (iline == 1 && is == 1) || is == 0 )
			 {			    
			    if( is == 1 ) run_v = 200;
			    if( idx == 3 ) run.push_back(run_v);
			    
			    if( idx == 24 ) 
			      {
				 sf.push_back(atof(item.c_str())); // FIXME IF FORMAT CHANGES
			      }
			    
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

	std::vector<float> sigma_syst_sep;
	std::vector<std::string> sigma_syst_name;
	float sigma_syst_add = 0.;

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
		  if( isUp ) sigma_syst_up += err;
		  else sigma_syst_down += err;
		  if( run[i] < 100 )
		    {		       
		       if( isUp ) sigma_syst_sep.push_back(sf[idxNom]+sqrt(err));
		       else sigma_syst_sep.push_back(sf[idxNom]-sqrt(err));
		       sigma_syst_name.push_back(getSysName(run[i]));
		    }		  
		  
		  if( run[i] >= 100 && run[i] <= 200 )
		    {
		       sigma_syst_add += pow(delta,2);
		    }		  
	       }
	     else
	       {
		  sf_stat_sum += sf[i];
		  istat++;
	       }	     
	  }
	sigma_syst_add = sqrt(sigma_syst_add);

	Comb_sf.push_back(sf[idxNom]);
	
	sf_stat_sum /= istat;

	float sfcbsys = 0.;
	// add Cb systematics
	if( inclCB )
	  {	     
//	     float cb = getCb(tag,"bjet",ipt+1);
	     float cb = getCb(tag,"bjet",ipt+1+1); //FIXME if include 20-30 bin
	     float cbsys = (1-cb)*0.5/cb;
	     sfcbsys = pow(cbsys*sf[idxNom],2);
	     
	     sigma_syst_up += sfcbsys;
	     sigma_syst_down += sfcbsys;
	  }
	
	// add add
	sigma_syst_up += sigma_syst_add*sigma_syst_add;
	sigma_syst_down += sigma_syst_add*sigma_syst_add;
	
	for(int i=0;i<istat;i++)
	  {	     
	     sigma_stat += pow(sf_stat_sum-sf[i],2)/istat;
	  }
	sigma_stat = sqrt(sigma_stat);
	
	sigma_syst_up = sqrt(sigma_syst_up);
	sigma_syst_down = sqrt(sigma_syst_down);

	sigma_total_up = sqrt(sigma_stat*sigma_stat+sigma_syst_up*sigma_syst_up);
	sigma_total_down = sqrt(sigma_stat*sigma_stat+sigma_syst_down*sigma_syst_down);

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
   
   std::string csv = "#bf{"+tag+"}";
   
   const int np = 2*nPT+1;
   double xp_sysTot_SF[np];
   double yp_sysTot_SF[np];
   for(int k=0;k<nPT;k++)
     {
	xp_sysTot_SF[k] = h_SF->GetBinWidth(k+1)/2.0 + h_SF->GetXaxis()->GetBinLowEdge(k+1);
	yp_sysTot_SF[k] = h_SF_TOTAL_UP->GetBinContent(k+1);
	yp_sysTot_SF[nPT+k] = h_SF_TOTAL_DOWN->GetBinContent(nPT-k);
     }      
   for(int k=0;k<nPT;k++)
     {
	xp_sysTot_SF[nPT+k] = xp_sysTot_SF[nPT-k-1];
     }	
   xp_sysTot_SF[np-1] = xp_sysTot_SF[0];   
   yp_sysTot_SF[np-1] = yp_sysTot_SF[0];
   
   TPolyLine *sysTot_SF = new TPolyLine(np,xp_sysTot_SF,yp_sysTot_SF);
   sysTot_SF->SetFillColor(kYellow);
	
   h_SF->GetYaxis()->SetTitle("SF_{b}");
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
   legl->DrawLatex(0.55,0.85,csv.c_str());
   
   leg->AddEntry(h_SF,"Scale factor","p");
   leg->AddEntry(h_SF,"stat","l");
   leg->AddEntry(sysTot_SF,"stat #oplus syst","f");
   
   c1->RedrawAxis("g");
   
   leg->Draw();
   
   c1->SetLogx(1);
   std::string picname = "pics/SF_"+tag+".eps";
   c1->Print(picname.c_str());
   c1->Clear();
   
   delete sysTot_SF;
   
   delete c1;
   delete leg;
   delete legl;

   // write csv file
   for(int ipt=0;ipt<nPT;ipt++)
     {
	int nMeas = Comb_sigma_syst_name[ipt].size();
	
	for(int i=0;i<nMeas;i++)
	  {
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
	  }  
     }   
   
   sfComb.close();
     
   gApplication->Terminate();
}

void SetPlotStyle()
{
   TStyle *styleCurrent = gROOT->GetStyle("PLOT");
   if( !styleCurrent )
     {
	static TStyle* plotStyle = 0;
	if( plotStyle == 0 ) plotStyle = PlotStyle();
	gROOT->SetStyle("PLOT");
	gROOT->ForceStyle();
     }
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
   
   std::string fcb = "../../CbFactor/cb_"+tag+"_"+flav+".txt";   
   
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
   if( idx == 0 ) name = "central";
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
   else if( idx == 9 ) name = "up_ntrkgen";
   else if( idx == -9 ) name = "down_ntrkgen";
//   else if( idx == 12 ) name = "up_jes";
//   else if( idx == -12 ) name = "down_jes";
//   else if( idx == 13 ) name = "up_jer";
//   else if( idx == -13 ) name = "down_jer";
   return name;
}
