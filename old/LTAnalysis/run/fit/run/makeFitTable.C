void makeFitTable()
{
   gROOT->SetBatch();

   TFile *f_fit_EFF = TFile::Open("results/fit_EFF_beauty.root");
   TFile *f_fit_EFF_charm = TFile::Open("results/fit_EFF_charm.root");
   TFile *f_fit_EFF_light = TFile::Open("results/fit_EFF_light.root");
   TFile *f_fit_CHISQ_beforeBTAG = TFile::Open("results/fit_CHISQ_beforeBTAG.root");
   TFile *f_fit_FIT123_beforeBTAG = TFile::Open("results/fit_FIT123_beforeBTAG.root");
   TFile *f_fit_CHISQ_afterBTAG = TFile::Open("results/fit_CHISQ_afterBTAG.root");
   TFile *f_fit_FIT123_afterBTAG = TFile::Open("results/fit_FIT123_afterBTAG.root");

   TH1F *h1c = (TH1F*)f_fit_EFF->Get("h1c");
   TH1F *h_eff1DATA = (TH1F*)f_fit_EFF->Get("h_eff1DATA");
   TH1F *h_eff1MC = (TH1F*)f_fit_EFF->Get("h_eff1MC");

   TH1F *h1c_charm = (TH1F*)f_fit_EFF_charm->Get("h1c");
   TH1F *h_eff1DATA_charm = (TH1F*)f_fit_EFF_charm->Get("h_eff1DATA");
   TH1F *h_eff1MC_charm = (TH1F*)f_fit_EFF_charm->Get("h_eff1MC");

   TH1F *h1c_light = (TH1F*)f_fit_EFF_light->Get("h1c");
   TH1F *h_eff1DATA_light = (TH1F*)f_fit_EFF_light->Get("h_eff1DATA");
   TH1F *h_eff1MC_light = (TH1F*)f_fit_EFF_light->Get("h_eff1MC");
   
   TH1F *h_chisq1_beforeBTAG = (TH1F*)f_fit_CHISQ_beforeBTAG->Get("h_chisq1");
   TH1F *h_ndof1_beforeBTAG = (TH1F*)f_fit_CHISQ_beforeBTAG->Get("h_ndof1");
   TH1F *h_prob_beforeBTAG = (TH1F*)f_fit_CHISQ_beforeBTAG->Get("hp");
   TH1F *h_p1f1_beforeBTAG = (TH1F*)f_fit_FIT123_beforeBTAG->Get("h_p1f1");
   TH1F *h_p2f1_beforeBTAG = (TH1F*)f_fit_FIT123_beforeBTAG->Get("h_p2f1");
   TH1F *h_p3f1_beforeBTAG = (TH1F*)f_fit_FIT123_beforeBTAG->Get("h_p3f1");

   TH1F *h_chisq1_afterBTAG = (TH1F*)f_fit_CHISQ_afterBTAG->Get("h_chisq1");
   TH1F *h_ndof1_afterBTAG = (TH1F*)f_fit_CHISQ_afterBTAG->Get("h_ndof1");
   TH1F *h_prob_afterBTAG = (TH1F*)f_fit_CHISQ_afterBTAG->Get("hp");
   TH1F *h_p1f1_afterBTAG = (TH1F*)f_fit_FIT123_afterBTAG->Get("h_p1f1");
   TH1F *h_p2f1_afterBTAG = (TH1F*)f_fit_FIT123_afterBTAG->Get("h_p2f1");
   TH1F *h_p3f1_afterBTAG = (TH1F*)f_fit_FIT123_afterBTAG->Get("h_p3f1");
   
   std::string tname_beforeBTAG = "results/table_beforeBTAG.tex";
   std::string tname_afterBTAG = "results/table_afterBTAG.tex";
   std::string tname = "results/table.tex";
   std::string tname_inc = "results/table_inc.tex";
   std::string tname_inc_heavy = "results/table_inc_heavy.tex";
   std::string tname_inc_light = "results/table_inc_light.tex";
   std::string tname_heavy = "results/table_heavy.tex";
   std::string tname_light = "results/table_light.tex";

   std::string tname_inc_heavy_1 = "results/table_inc_heavy_1.tex";
   std::string tname_inc_light_1 = "results/table_inc_light_1.tex";
   std::string tname_heavy_1 = "results/table_heavy_1.tex";
   std::string tname_light_1 = "results/table_light_1.tex";

   std::string tname_inc_heavy_2 = "results/table_inc_heavy_2.tex";
   std::string tname_inc_light_2 = "results/table_inc_light_2.tex";
   std::string tname_heavy_2 = "results/table_heavy_2.tex";
   std::string tname_light_2 = "results/table_light_2.tex";
   
   std::ofstream fout(tname.c_str());
   std::ofstream fout_inc(tname_inc.c_str());
   std::ofstream fout_inc_heavy(tname_inc_heavy.c_str());
   std::ofstream fout_inc_light(tname_inc_light.c_str());
   std::ofstream fout_heavy(tname_heavy.c_str());
   std::ofstream fout_light(tname_light.c_str());

   std::ofstream fout_inc_heavy_1(tname_inc_heavy_1.c_str());
   std::ofstream fout_inc_light_1(tname_inc_light_1.c_str());
   std::ofstream fout_heavy_1(tname_heavy_1.c_str());
   std::ofstream fout_light_1(tname_light_1.c_str());

   std::ofstream fout_inc_heavy_2(tname_inc_heavy_2.c_str());
   std::ofstream fout_inc_light_2(tname_inc_light_2.c_str());
   std::ofstream fout_heavy_2(tname_heavy_2.c_str());
   std::ofstream fout_light_2(tname_light_2.c_str());
   
   std::string header1 = "\\documentclass[a4paper]{article} \n
\\usepackage[english]{babel} \n
\\usepackage{graphicx} \n
\\usepackage{color} \n			   
\\begin{document}";

   std::string header2 = "
\\begin{table}[hbt!] \n
\\small \n
\\begin{center} \n
\\resizebox{16cm}{!}{ \n
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|c|c|} \n
\\hline";

   std::string header3_full = "
\\begin{table}[hbt!] \n
\\small \n
\\begin{center} \n
\\resizebox{16cm}{!}{ \n
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|} \n
\\hline";

   std::string header4_full = "
\\begin{table}[hbt!] \n
\\small \n
\\begin{center} \n
\\resizebox{16cm}{!}{ \n
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|} \n
\\hline";

   std::string header3 = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|} \n
\\hline";

   std::string header4 = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|} \n
\\hline";
   
   fout << header1 << std::endl;
   fout << header2 << std::endl;
   
   fout_inc << header2 << std::endl;
   fout_inc_heavy << header2 << std::endl;
   fout_inc_light << header2 << std::endl;

   fout_inc_heavy_1 << header3 << std::endl;
   fout_inc_light_1 << header3 << std::endl;

   fout_inc_heavy_2 << header4 << std::endl;
   fout_inc_light_2 << header4 << std::endl;
  
   fout_heavy << header1 << std::endl;
   fout_light << header1 << std::endl;
   fout_heavy << header2 << std::endl;
   fout_light << header2 << std::endl;

   fout_heavy_1 << header1 << std::endl;
   fout_light_1 << header1 << std::endl;
   fout_heavy_1 << header3_full << std::endl;
   fout_light_1 << header3_full << std::endl;

   fout_heavy_2 << header1 << std::endl;
   fout_light_2 << header1 << std::endl;
   fout_heavy_2 << header4_full << std::endl;
   fout_light_2 << header4_full << std::endl;
   
   std::string linePT = "$P_{T}$ [GeV] & ";
   std::string lineP1 = "$p$ (b-jet) & ";
   std::string lineP2 = "$p$ (c-jet) & ";
   std::string lineP3 = "$p$ (l-jet) & ";   
   std::string lineCHISQ = "$\\chi^{2}$/$N_{dof}$ & ";
   std::string lineNDOF = "$N_{dof}$ & ";
   std::string linePROB = "$P (\\chi^{2})$ & ";   
   std::string lineEFFDATA1 = "$\\epsilon$ (b-jet) (Data) & ";
   std::string lineEFFMC1 = "$\\epsilon$ (b-jet) (MC) & ";
   std::string lineSF1 = "$SF$ (b-jet) & ";
   std::string lineEFFDATA1_charm = "$\\epsilon$ (c-jet) (Data) & ";
   std::string lineEFFMC1_charm = "$\\epsilon$ (c-jet) (MC) & ";
   std::string lineSF1_charm = "$SF$ (c-jet) & ";
   std::string lineEFFDATA1_light = "$\\epsilon$ (l-jet) (Data) & ";
   std::string lineEFFMC1_light = "$\\epsilon$ (l-jet) (MC) & ";
   std::string lineSF1_light = "$SF$ (l-jet) & ";

   std::string lineP1_beforeBTAG = lineP1;
   std::string lineP2_beforeBTAG = lineP2;
   std::string lineP3_beforeBTAG = lineP3;
   std::string lineCHISQ_beforeBTAG = lineCHISQ;
   std::string lineNDOF_beforeBTAG = lineNDOF;
   std::string linePROB_beforeBTAG = linePROB;
   std::string linePROB_beforeBTAG_NOCOLOR = linePROB;

   std::string lineP1_afterBTAG = lineP1;
   std::string lineP2_afterBTAG = lineP2;
   std::string lineP3_afterBTAG = lineP3;
   std::string lineCHISQ_afterBTAG = lineCHISQ;
   std::string lineNDOF_afterBTAG = lineNDOF;
   std::string linePROB_afterBTAG = linePROB;
   std::string linePROB_afterBTAG_NOCOLOR = linePROB;

   std::string linePT_1 = linePT;
   std::string linePT_2 = linePT;
   
   std::string lineP1_beforeBTAG_1 = lineP1;
   std::string lineP2_beforeBTAG_1 = lineP2;
   std::string lineP3_beforeBTAG_1 = lineP3;
   std::string lineCHISQ_beforeBTAG_1 = lineCHISQ;
   std::string lineNDOF_beforeBTAG_1 = lineNDOF;
   std::string linePROB_beforeBTAG_1 = linePROB;
   std::string linePROB_beforeBTAG_NOCOLOR_1 = linePROB;

   std::string lineP1_afterBTAG_1 = lineP1;
   std::string lineP2_afterBTAG_1 = lineP2;
   std::string lineP3_afterBTAG_1 = lineP3;
   std::string lineCHISQ_afterBTAG_1 = lineCHISQ;
   std::string lineNDOF_afterBTAG_1 = lineNDOF;
   std::string linePROB_afterBTAG_1 = linePROB;
   std::string linePROB_afterBTAG_NOCOLOR_1 = linePROB;

   std::string lineEFFDATA1_1 = lineEFFDATA1;
   std::string lineEFFMC1_1 = lineEFFMC1;
   std::string lineSF1_1 = lineSF1;
   std::string lineEFFDATA1_charm_1 = lineEFFDATA1_charm;
   std::string lineEFFMC1_charm_1 = lineEFFMC1_charm;
   std::string lineSF1_charm_1 = lineSF1_charm;
   std::string lineEFFDATA1_light_1 = lineEFFDATA1_light;
   std::string lineEFFMC1_light_1 = lineEFFMC1_light;
   std::string lineSF1_light_1 = lineSF1_light;
   
   std::string lineP1_beforeBTAG_2 = lineP1;
   std::string lineP2_beforeBTAG_2 = lineP2;
   std::string lineP3_beforeBTAG_2 = lineP3;
   std::string lineCHISQ_beforeBTAG_2 = lineCHISQ;
   std::string lineNDOF_beforeBTAG_2 = lineNDOF;
   std::string linePROB_beforeBTAG_2 = linePROB;
   std::string linePROB_beforeBTAG_NOCOLOR_2 = linePROB;

   std::string lineP1_afterBTAG_2 = lineP1;
   std::string lineP2_afterBTAG_2 = lineP2;
   std::string lineP3_afterBTAG_2 = lineP3;
   std::string lineCHISQ_afterBTAG_2 = lineCHISQ;
   std::string lineNDOF_afterBTAG_2 = lineNDOF;
   std::string linePROB_afterBTAG_2 = linePROB;
   std::string linePROB_afterBTAG_NOCOLOR_2 = linePROB;

   std::string lineEFFDATA1_2 = lineEFFDATA1;
   std::string lineEFFMC1_2 = lineEFFMC1;
   std::string lineSF1_2 = lineSF1;
   std::string lineEFFDATA1_charm_2 = lineEFFDATA1_charm;
   std::string lineEFFMC1_charm_2 = lineEFFMC1_charm;
   std::string lineSF1_charm_2 = lineSF1_charm;
   std::string lineEFFDATA1_light_2 = lineEFFDATA1_light;
   std::string lineEFFMC1_light_2 = lineEFFMC1_light;
   std::string lineSF1_light_2 = lineSF1_light;
   
   int nbins = h1c->GetXaxis()->GetNbins();
   
//   for(int j=4;j<nbins+1;j++)
   for(int j=1;j<nbins+1;j++)
     {
	double pt1 = h1c->GetXaxis()->GetBinLowEdge(j);
	double pt2 = h1c->GetXaxis()->GetBinUpEdge(j);
	double sf1 = h1c->GetBinContent(j);
	double sf1err = h1c->GetBinError(j);
	double eff1data = h_eff1DATA->GetBinContent(j);
	double eff1errdata = h_eff1DATA->GetBinError(j);
	double eff1mc = h_eff1MC->GetBinContent(j);
	double eff1errmc = h_eff1MC->GetBinError(j);

	double sf1_charm = h1c_charm->GetBinContent(j);
	double sf1err_charm = h1c_charm->GetBinError(j);
	double eff1data_charm = h_eff1DATA_charm->GetBinContent(j);
	double eff1errdata_charm = h_eff1DATA_charm->GetBinError(j);
	double eff1mc_charm = h_eff1MC_charm->GetBinContent(j);
	double eff1errmc_charm = h_eff1MC_charm->GetBinError(j);

	double sf1_light = h1c_light->GetBinContent(j);
	double sf1err_light = h1c_light->GetBinError(j);
	double eff1data_light = h_eff1DATA_light->GetBinContent(j);
	double eff1errdata_light = h_eff1DATA_light->GetBinError(j);
	double eff1mc_light = h_eff1MC_light->GetBinContent(j);
	double eff1errmc_light = h_eff1MC_light->GetBinError(j);
	
	double chisq1_beforeBTAG = h_chisq1_beforeBTAG->GetBinContent(j);
	double ndof1_beforeBTAG = h_ndof1_beforeBTAG->GetBinContent(j);
	double prob_beforeBTAG = h_prob_beforeBTAG->GetBinContent(j);
	double p1_beforeBTAG = h_p1f1_beforeBTAG->GetBinContent(j);
	double p1err_beforeBTAG = h_p1f1_beforeBTAG->GetBinError(j);
	double p2_beforeBTAG = h_p2f1_beforeBTAG->GetBinContent(j);
	double p2err_beforeBTAG = h_p2f1_beforeBTAG->GetBinError(j);
	double p3_beforeBTAG = h_p3f1_beforeBTAG->GetBinContent(j);
	double p3err_beforeBTAG = h_p3f1_beforeBTAG->GetBinError(j);

	double chisq1_afterBTAG = h_chisq1_afterBTAG->GetBinContent(j);
	double ndof1_afterBTAG = h_ndof1_afterBTAG->GetBinContent(j);
	double prob_afterBTAG = h_prob_afterBTAG->GetBinContent(j);
	double p1_afterBTAG = h_p1f1_afterBTAG->GetBinContent(j);
	double p1err_afterBTAG = h_p1f1_afterBTAG->GetBinError(j);
	double p2_afterBTAG = h_p2f1_afterBTAG->GetBinContent(j);
	double p2err_afterBTAG = h_p2f1_afterBTAG->GetBinError(j);
	double p3_afterBTAG = h_p3f1_afterBTAG->GetBinContent(j);
	double p3err_afterBTAG = h_p3f1_afterBTAG->GetBinError(j);
	
	stringstream ss("");
	ss.precision(0);

	// pt
	
	ss << fixed << pt1*1000.;
	std::string pt1Str = ss.str();
	ss.str("");
	ss << pt2*1000.;
	std::string pt2Str = ss.str();

	ss.precision(3);
	
	// eff & SF b-jet
	
	ss.str("");
	ss << sf1;
	std::string sf1Str = ss.str();
	ss.str("");
	ss << sf1err;
	std::string sf1errStr = ss.str();
	
	ss.str("");
	ss << eff1data;
	std::string eff1dataStr = ss.str();
	ss.str("");
	ss << eff1errdata;
	std::string eff1errdataStr = ss.str();

	ss.str("");
	ss << eff1mc;
	std::string eff1mcStr = ss.str();
	ss.str("");
	ss << eff1errmc;
	std::string eff1errmcStr = ss.str();

	// eff & SF c-jet

	ss.str("");
	ss << sf1_charm;
	std::string sf1Str_charm = ss.str();
	ss.str("");
	ss << sf1err_charm;
	std::string sf1errStr_charm = ss.str();
	
	ss.str("");
	ss << eff1data_charm;
	std::string eff1dataStr_charm = ss.str();
	ss.str("");
	ss << eff1errdata_charm;
	std::string eff1errdataStr_charm = ss.str();

	ss.str("");
	ss << eff1mc_charm;
	std::string eff1mcStr_charm = ss.str();
	ss.str("");
	ss << eff1errmc_charm;
	std::string eff1errmcStr_charm = ss.str();
	
	// eff & SF l-jet

	ss.str("");
	ss << sf1_light;
	std::string sf1Str_light = ss.str();
	ss.str("");
	ss << sf1err_light;
	std::string sf1errStr_light = ss.str();
	
	ss.str("");
	ss << eff1data_light;
	std::string eff1dataStr_light = ss.str();
	ss.str("");
	ss << eff1errdata_light;
	std::string eff1errdataStr_light = ss.str();

	ss.str("");
	ss << eff1mc_light;
	std::string eff1mcStr_light = ss.str();
	ss.str("");
	ss << eff1errmc_light;
	std::string eff1errmcStr_light = ss.str();
	
	// before BTAG
	
	ss.str("");
	ss << chisq1_beforeBTAG;
	std::string chisq1Str_beforeBTAG = ss.str();

	ss.str("");
	ss.precision(0);
	ss << ndof1_beforeBTAG;
	std::string ndof1Str_beforeBTAG = ss.str();
	ss.precision(3);

	ss.str("");
	ss.precision(3);
	ss << prob_beforeBTAG;
	std::string prob1Str_beforeBTAG = ss.str();
	ss.precision(3);
	
	ss.str("");
	ss << p1_beforeBTAG;
	std::string p1Str_beforeBTAG = ss.str();
	ss.str("");
	ss << p1err_beforeBTAG;
	std::string p1errStr_beforeBTAG = ss.str();

	ss.str("");
	ss << p2_beforeBTAG;
	std::string p2Str_beforeBTAG = ss.str();
	ss.str("");
	ss << p2err_beforeBTAG;
	std::string p2errStr_beforeBTAG = ss.str();

	ss.str("");
	ss << p3_beforeBTAG;
	std::string p3Str_beforeBTAG = ss.str();
	ss.str("");
	ss << p3err_beforeBTAG;
	std::string p3errStr_beforeBTAG = ss.str();
	
	// after BTAG

	ss.str("");
	ss << chisq1_afterBTAG;
	std::string chisq1Str_afterBTAG = ss.str();

	ss.str("");
	ss.precision(0);
	ss << ndof1_afterBTAG;
	std::string ndof1Str_afterBTAG = ss.str();
	ss.precision(3);

	ss.str("");
	ss.precision(3);
	ss << prob_afterBTAG;
	std::string prob1Str_afterBTAG = ss.str();
	ss.precision(3);
	
	ss.str("");
	ss << p1_afterBTAG;
	std::string p1Str_afterBTAG = ss.str();
	ss.str("");
	ss << p1err_afterBTAG;
	std::string p1errStr_afterBTAG = ss.str();

	ss.str("");
	ss << p2_afterBTAG;
	std::string p2Str_afterBTAG = ss.str();
	ss.str("");
	ss << p2err_afterBTAG;
	std::string p2errStr_afterBTAG = ss.str();

	ss.str("");
	ss << p3_afterBTAG;
	std::string p3Str_afterBTAG = ss.str();
	ss.str("");
	ss << p3err_afterBTAG;
	std::string p3errStr_afterBTAG = ss.str();

	// merge

	std::string colorPROB_beforeBTAG = "\\textcolor{black}\{";
	std::string boldPROB_beforeBTAG = "";
/*	if( prob_beforeBTAG < 0.05 )
	  {
	     colorPROB_beforeBTAG = "\\textcolor\[rgb\]\{1,0.55,0\}\{\\textbf\{";
	     boldPROB_beforeBTAG = "\}";
	  }	
	if( prob_beforeBTAG < 0.01 ) 
	  {
	     colorPROB_beforeBTAG = "\\textcolor{red}\{\\textbf\{";
	     boldPROB_beforeBTAG = "\}";
	  }*/

	std::string colorPROB_afterBTAG = "\\textcolor{black}\{";
	std::string boldPROB_afterBTAG = "";
/*	if( prob_afterBTAG < 0.05 )
	  {
	     colorPROB_afterBTAG = "\\textcolor\[rgb\]\{1,0.55,0\}\{\\textbf\{";
	     boldPROB_afterBTAG = "\}";
	  }	
	if( prob_afterBTAG < 0.01 ) 
	  {
	     colorPROB_afterBTAG = "\\textcolor{red}\{\\textbf\{";
	     boldPROB_afterBTAG = "\}";
	  }*/
	
	std::string linePT_cur = pt1Str + " - " + pt2Str;
	std::string lineSF1_cur = sf1Str + " $\\pm$ " + sf1errStr;
	std::string lineEFFDATA1_cur = eff1dataStr + " $\\pm$ " + eff1errdataStr;
	std::string lineEFFMC1_cur = eff1mcStr + " $\\pm$ " + eff1errmcStr;
	std::string lineSF1_charm_cur = sf1Str_charm + " $\\pm$ " + sf1errStr_charm;
	std::string lineEFFDATA1_charm_cur = eff1dataStr_charm + " $\\pm$ " + eff1errdataStr_charm;
	std::string lineEFFMC1_charm_cur = eff1mcStr_charm + " $\\pm$ " + eff1errmcStr_charm;	
	std::string lineSF1_light_cur = sf1Str_light + " $\\pm$ " + sf1errStr_light;
	std::string lineEFFDATA1_light_cur = eff1dataStr_light + " $\\pm$ " + eff1errdataStr_light;
	std::string lineEFFMC1_light_cur = eff1mcStr_light + " $\\pm$ " + eff1errmcStr_light;	
	std::string lineCHISQ_beforeBTAG_cur = chisq1Str_beforeBTAG;
	std::string lineNDOF_beforeBTAG_cur = ndof1Str_beforeBTAG;
	std::string linePROB_beforeBTAG_cur = colorPROB_beforeBTAG + prob1Str_beforeBTAG + boldPROB_beforeBTAG + "\}";
	std::string linePROB_beforeBTAG_cur_NOCOLOR = prob1Str_beforeBTAG;
	std::string lineP1_beforeBTAG_cur = p1Str_beforeBTAG + " $\\pm$ " + p1errStr_beforeBTAG;
	std::string lineP2_beforeBTAG_cur = p2Str_beforeBTAG + " $\\pm$ " + p2errStr_beforeBTAG;
	std::string lineP3_beforeBTAG_cur = p3Str_beforeBTAG + " $\\pm$ " + p3errStr_beforeBTAG;
	std::string lineCHISQ_afterBTAG_cur = chisq1Str_afterBTAG;
	std::string lineNDOF_afterBTAG_cur = ndof1Str_afterBTAG;
	std::string linePROB_afterBTAG_cur = colorPROB_afterBTAG + prob1Str_afterBTAG + boldPROB_afterBTAG + "\}";
	std::string linePROB_afterBTAG_cur_NOCOLOR = prob1Str_afterBTAG;
	std::string lineP1_afterBTAG_cur = p1Str_afterBTAG + " $\\pm$ " + p1errStr_afterBTAG;
	std::string lineP2_afterBTAG_cur = p2Str_afterBTAG + " $\\pm$ " + p2errStr_afterBTAG;
	std::string lineP3_afterBTAG_cur = p3Str_afterBTAG + " $\\pm$ " + p3errStr_afterBTAG;	
	
	linePT += linePT_cur;	
	lineSF1 += lineSF1_cur;
	lineEFFDATA1 += lineEFFDATA1_cur;
	lineEFFMC1 += lineEFFMC1_cur;
	lineSF1_charm += lineSF1_charm_cur;
	lineEFFDATA1_charm += lineEFFDATA1_charm_cur;
	lineEFFMC1_charm += lineEFFMC1_charm_cur;	
	lineSF1_light += lineSF1_light_cur;
	lineEFFDATA1_light += lineEFFDATA1_light_cur;
	lineEFFMC1_light += lineEFFMC1_light_cur;	
	lineCHISQ_beforeBTAG += lineCHISQ_beforeBTAG_cur;
	lineNDOF_beforeBTAG += lineNDOF_beforeBTAG_cur;
	linePROB_beforeBTAG += linePROB_beforeBTAG_cur;
	linePROB_beforeBTAG_NOCOLOR += linePROB_beforeBTAG_cur_NOCOLOR;
	lineP1_beforeBTAG += lineP1_beforeBTAG_cur;
	lineP2_beforeBTAG += lineP2_beforeBTAG_cur;
	lineP3_beforeBTAG += lineP3_beforeBTAG_cur;
	lineCHISQ_afterBTAG += lineCHISQ_afterBTAG_cur;
	lineNDOF_afterBTAG += lineNDOF_afterBTAG_cur;
	linePROB_afterBTAG += linePROB_afterBTAG_cur;
	linePROB_afterBTAG_NOCOLOR += linePROB_afterBTAG_cur_NOCOLOR;
	lineP1_afterBTAG += lineP1_afterBTAG_cur;
	lineP2_afterBTAG += lineP2_afterBTAG_cur;
	lineP3_afterBTAG += lineP3_afterBTAG_cur;

	if( j <= nbins/2 )
	  {
	     linePT_1 += linePT_cur;	
	     lineSF1_1 += lineSF1_cur;
	     lineEFFDATA1_1 += lineEFFDATA1_cur;
	     lineEFFMC1_1 += lineEFFMC1_cur;
	     lineSF1_charm_1 += lineSF1_charm_cur;
	     lineEFFDATA1_charm_1 += lineEFFDATA1_charm_cur;
	     lineEFFMC1_charm_1 += lineEFFMC1_charm_cur;	
	     lineSF1_light_1 += lineSF1_light_cur;
	     lineEFFDATA1_light_1 += lineEFFDATA1_light_cur;
	     lineEFFMC1_light_1 += lineEFFMC1_light_cur;	
	     lineCHISQ_beforeBTAG_1 += lineCHISQ_beforeBTAG_cur;
	     lineNDOF_beforeBTAG_1 += lineNDOF_beforeBTAG_cur;
	     linePROB_beforeBTAG_1 += linePROB_beforeBTAG_cur;
	     linePROB_beforeBTAG_NOCOLOR_1 += linePROB_beforeBTAG_cur_NOCOLOR;
	     lineP1_beforeBTAG_1 += lineP1_beforeBTAG_cur;
	     lineP2_beforeBTAG_1 += lineP2_beforeBTAG_cur;
	     lineP3_beforeBTAG_1 += lineP3_beforeBTAG_cur;
	     lineCHISQ_afterBTAG_1 += lineCHISQ_afterBTAG_cur;
	     lineNDOF_afterBTAG_1 += lineNDOF_afterBTAG_cur;
	     linePROB_afterBTAG_1 += linePROB_afterBTAG_cur;
	     linePROB_afterBTAG_NOCOLOR_1 += linePROB_afterBTAG_cur_NOCOLOR;
	     lineP1_afterBTAG_1 += lineP1_afterBTAG_cur;
	     lineP2_afterBTAG_1 += lineP2_afterBTAG_cur;
	     lineP3_afterBTAG_1 += lineP3_afterBTAG_cur;
	  }
	else
	  {
	     linePT_2 += linePT_cur;	
	     lineSF1_2 += lineSF1_cur;
	     lineEFFDATA1_2 += lineEFFDATA1_cur;
	     lineEFFMC1_2 += lineEFFMC1_cur;
	     lineSF1_charm_2 += lineSF1_charm_cur;
	     lineEFFDATA1_charm_2 += lineEFFDATA1_charm_cur;
	     lineEFFMC1_charm_2 += lineEFFMC1_charm_cur;	
	     lineSF1_light_2 += lineSF1_light_cur;
	     lineEFFDATA1_light_2 += lineEFFDATA1_light_cur;
	     lineEFFMC1_light_2 += lineEFFMC1_light_cur;	
	     lineCHISQ_beforeBTAG_2 += lineCHISQ_beforeBTAG_cur;
	     lineNDOF_beforeBTAG_2 += lineNDOF_beforeBTAG_cur;
	     linePROB_beforeBTAG_2 += linePROB_beforeBTAG_cur;
	     linePROB_beforeBTAG_NOCOLOR_2 += linePROB_beforeBTAG_cur_NOCOLOR;
	     lineP1_beforeBTAG_2 += lineP1_beforeBTAG_cur;
	     lineP2_beforeBTAG_2 += lineP2_beforeBTAG_cur;
	     lineP3_beforeBTAG_2 += lineP3_beforeBTAG_cur;
	     lineCHISQ_afterBTAG_2 += lineCHISQ_afterBTAG_cur;
	     lineNDOF_afterBTAG_2 += lineNDOF_afterBTAG_cur;
	     linePROB_afterBTAG_2 += linePROB_afterBTAG_cur;
	     linePROB_afterBTAG_NOCOLOR_2 += linePROB_afterBTAG_cur_NOCOLOR;
	     lineP1_afterBTAG_2 += lineP1_afterBTAG_cur;
	     lineP2_afterBTAG_2 += lineP2_afterBTAG_cur;
	     lineP3_afterBTAG_2 += lineP3_afterBTAG_cur;
	  }	
	
	if( j != nbins )
	  {
	     linePT += " & ";	     
	     lineSF1 += " & ";
	     lineEFFDATA1 += " & ";
	     lineEFFMC1 += " & ";
	     lineSF1_charm += " & ";
	     lineEFFDATA1_charm += " & ";
	     lineEFFMC1_charm += " & ";
	     lineSF1_light += " & ";
	     lineEFFDATA1_light += " & ";
	     lineEFFMC1_light += " & ";	     
	     lineCHISQ_beforeBTAG += " & ";
	     lineNDOF_beforeBTAG += " & ";
	     linePROB_beforeBTAG += " & ";
	     linePROB_beforeBTAG_NOCOLOR += " & ";
	     lineP1_beforeBTAG += " & ";
	     lineP2_beforeBTAG += " & ";
	     lineP3_beforeBTAG += " & ";	     
	     lineCHISQ_afterBTAG += " & ";
	     lineNDOF_afterBTAG += " & ";
	     linePROB_afterBTAG += " & ";
	     linePROB_afterBTAG_NOCOLOR += " & ";
	     lineP1_afterBTAG += " & ";
	     lineP2_afterBTAG += " & ";
	     lineP3_afterBTAG += " & ";	     

	     if( j < nbins/2 )
	       {
		  linePT_1 += " & ";	     
		  lineSF1_1 += " & ";
		  lineEFFDATA1_1 += " & ";
		  lineEFFMC1_1 += " & ";
		  lineSF1_charm_1 += " & ";
		  lineEFFDATA1_charm_1 += " & ";
		  lineEFFMC1_charm_1 += " & ";
		  lineSF1_light_1 += " & ";
		  lineEFFDATA1_light_1 += " & ";
		  lineEFFMC1_light_1 += " & ";	     
		  lineCHISQ_beforeBTAG_1 += " & ";
		  lineNDOF_beforeBTAG_1 += " & ";
		  linePROB_beforeBTAG_1 += " & ";
		  linePROB_beforeBTAG_NOCOLOR_1 += " & ";
		  lineP1_beforeBTAG_1 += " & ";
		  lineP2_beforeBTAG_1 += " & ";
		  lineP3_beforeBTAG_1 += " & ";	     
		  lineCHISQ_afterBTAG_1 += " & ";
		  lineNDOF_afterBTAG_1 += " & ";
		  linePROB_afterBTAG_1 += " & ";
		  linePROB_afterBTAG_NOCOLOR_1 += " & ";
		  lineP1_afterBTAG_1 += " & ";
		  lineP2_afterBTAG_1 += " & ";
		  lineP3_afterBTAG_1 += " & ";	     
	       }
	     
	     if( j > nbins/2 )
	       {
		  linePT_2 += " & ";	     
		  lineSF1_2 += " & ";
		  lineEFFDATA1_2 += " & ";
		  lineEFFMC1_2 += " & ";
		  lineSF1_charm_2 += " & ";
		  lineEFFDATA1_charm_2 += " & ";
		  lineEFFMC1_charm_2 += " & ";
		  lineSF1_light_2 += " & ";
		  lineEFFDATA1_light_2 += " & ";
		  lineEFFMC1_light_2 += " & ";	     
		  lineCHISQ_beforeBTAG_2 += " & ";
		  lineNDOF_beforeBTAG_2 += " & ";
		  linePROB_beforeBTAG_2 += " & ";
		  linePROB_beforeBTAG_NOCOLOR_2 += " & ";
		  lineP1_beforeBTAG_2 += " & ";
		  lineP2_beforeBTAG_2 += " & ";
		  lineP3_beforeBTAG_2 += " & ";	     
		  lineCHISQ_afterBTAG_2 += " & ";
		  lineNDOF_afterBTAG_2 += " & ";
		  linePROB_afterBTAG_2 += " & ";
		  linePROB_afterBTAG_NOCOLOR_2 += " & ";
		  lineP1_afterBTAG_2 += " & ";
		  lineP2_afterBTAG_2 += " & ";
		  lineP3_afterBTAG_2 += " & ";	     
	       }	     
	  }	
     }   
  
   std::string endLine = "\\\\";
   
   linePT += endLine;   
   lineSF1 += endLine;
   lineEFFDATA1 += endLine;
   lineEFFMC1 += endLine;
   lineSF1_charm += endLine;
   lineEFFDATA1_charm += endLine;
   lineEFFMC1_charm += endLine;
   lineSF1_light += endLine;
   lineEFFDATA1_light += endLine;
   lineEFFMC1_light += endLine;   
   lineCHISQ_beforeBTAG += endLine;
   lineNDOF_beforeBTAG += endLine;
   linePROB_beforeBTAG += endLine;
   linePROB_beforeBTAG_NOCOLOR += endLine;
   lineP1_beforeBTAG += endLine;
   lineP2_beforeBTAG += endLine;
   lineP3_beforeBTAG += endLine;
   lineCHISQ_afterBTAG += endLine;
   lineNDOF_afterBTAG += endLine;
   linePROB_afterBTAG += endLine;
   linePROB_afterBTAG_NOCOLOR += endLine;
   lineP1_afterBTAG += endLine;
   lineP2_afterBTAG += endLine;
   lineP3_afterBTAG += endLine;

   linePT_1 += endLine;   
   lineSF1_1 += endLine;
   lineEFFDATA1_1 += endLine;
   lineEFFMC1_1 += endLine;
   lineSF1_charm_1 += endLine;
   lineEFFDATA1_charm_1 += endLine;
   lineEFFMC1_charm_1 += endLine;
   lineSF1_light_1 += endLine;
   lineEFFDATA1_light_1 += endLine;
   lineEFFMC1_light_1 += endLine;   
   lineCHISQ_beforeBTAG_1 += endLine;
   lineNDOF_beforeBTAG_1 += endLine;
   linePROB_beforeBTAG_1 += endLine;
   linePROB_beforeBTAG_NOCOLOR_1 += endLine;
   lineP1_beforeBTAG_1 += endLine;
   lineP2_beforeBTAG_1 += endLine;
   lineP3_beforeBTAG_1 += endLine;
   lineCHISQ_afterBTAG_1 += endLine;
   lineNDOF_afterBTAG_1 += endLine;
   linePROB_afterBTAG_1 += endLine;
   linePROB_afterBTAG_NOCOLOR_1 += endLine;
   lineP1_afterBTAG_1 += endLine;
   lineP2_afterBTAG_1 += endLine;
   lineP3_afterBTAG_1 += endLine;

   linePT_2 += endLine;   
   lineSF1_2 += endLine;
   lineEFFDATA1_2 += endLine;
   lineEFFMC1_2 += endLine;
   lineSF1_charm_2 += endLine;
   lineEFFDATA1_charm_2 += endLine;
   lineEFFMC1_charm_2 += endLine;
   lineSF1_light_2 += endLine;
   lineEFFDATA1_light_2 += endLine;
   lineEFFMC1_light_2 += endLine;   
   lineCHISQ_beforeBTAG_2 += endLine;
   lineNDOF_beforeBTAG_2 += endLine;
   linePROB_beforeBTAG_2 += endLine;
   linePROB_beforeBTAG_NOCOLOR_2 += endLine;
   lineP1_beforeBTAG_2 += endLine;
   lineP2_beforeBTAG_2 += endLine;
   lineP3_beforeBTAG_2 += endLine;
   lineCHISQ_afterBTAG_2 += endLine;
   lineNDOF_afterBTAG_2 += endLine;
   linePROB_afterBTAG_2 += endLine;
   linePROB_afterBTAG_NOCOLOR_2 += endLine;
   lineP1_afterBTAG_2 += endLine;
   lineP2_afterBTAG_2 += endLine;
   lineP3_afterBTAG_2 += endLine;
   
   fout << linePT << std::endl;
   fout_inc << linePT << std::endl;
   fout_inc_heavy << linePT << std::endl;
   fout_inc_light << linePT << std::endl;
   fout_heavy << linePT << std::endl;
   fout_light << linePT << std::endl;

   fout_inc_heavy_1 << linePT_1 << std::endl;
   fout_inc_light_1 << linePT_1 << std::endl;
   fout_heavy_1 << linePT_1 << std::endl;
   fout_light_1 << linePT_1 << std::endl;

   fout_inc_heavy_2 << linePT_2 << std::endl;
   fout_inc_light_2 << linePT_2 << std::endl;
   fout_heavy_2 << linePT_2 << std::endl;
   fout_light_2 << linePT_2 << std::endl;
   
   fout << "\\hline" << std::endl;
   fout_inc << "\\hline" << std::endl;
   fout_inc_heavy << "\\hline" << std::endl;
   fout_inc_light << "\\hline" << std::endl;
   fout_heavy << "\\hline" << std::endl;
   fout_light << "\\hline" << std::endl;

   fout_inc_heavy_1 << "\\hline" << std::endl;
   fout_inc_light_1 << "\\hline" << std::endl;
   fout_heavy_1 << "\\hline" << std::endl;
   fout_light_1 << "\\hline" << std::endl;

   fout_inc_heavy_2 << "\\hline" << std::endl;
   fout_inc_light_2 << "\\hline" << std::endl;
   fout_heavy_2 << "\\hline" << std::endl;
   fout_light_2 << "\\hline" << std::endl;
   
   fout << lineP1_beforeBTAG << std::endl;
   fout << lineP2_beforeBTAG << std::endl;
   fout << lineP3_beforeBTAG << std::endl;
   fout << lineNDOF_beforeBTAG << std::endl;
   fout << lineCHISQ_beforeBTAG << std::endl;
   fout << linePROB_beforeBTAG << std::endl;

   fout_inc << lineP1_beforeBTAG << std::endl;
   fout_inc << lineP2_beforeBTAG << std::endl;
   fout_inc << lineP3_beforeBTAG << std::endl;
   fout_inc << lineNDOF_beforeBTAG << std::endl;
   fout_inc << lineCHISQ_beforeBTAG << std::endl;
   fout_inc << linePROB_beforeBTAG_NOCOLOR << std::endl;

   fout_inc_heavy << lineP1_beforeBTAG << std::endl;
   fout_inc_heavy << lineP2_beforeBTAG << std::endl;
   fout_inc_heavy << lineP3_beforeBTAG << std::endl;
   fout_inc_heavy << lineNDOF_beforeBTAG << std::endl;
   fout_inc_heavy << lineCHISQ_beforeBTAG << std::endl;
   fout_inc_heavy << linePROB_beforeBTAG_NOCOLOR << std::endl;

   fout_inc_light << lineP1_beforeBTAG << std::endl;
   fout_inc_light << lineP2_beforeBTAG << std::endl;
   fout_inc_light << lineP3_beforeBTAG << std::endl;
   fout_inc_light << lineNDOF_beforeBTAG << std::endl;
   fout_inc_light << lineCHISQ_beforeBTAG << std::endl;
   fout_inc_light << linePROB_beforeBTAG_NOCOLOR << std::endl;

//   fout_inc_heavy_1 << lineP1_beforeBTAG_1 << std::endl;
//   fout_inc_heavy_1 << lineP2_beforeBTAG_1 << std::endl;
//   fout_inc_heavy_1 << lineP3_beforeBTAG_1 << std::endl;
//   fout_inc_heavy_1 << lineNDOF_beforeBTAG_1 << std::endl;
//   fout_inc_heavy_1 << lineCHISQ_beforeBTAG_1 << std::endl;
//   fout_inc_heavy_1 << linePROB_beforeBTAG_NOCOLOR_1 << std::endl;

   fout_inc_light_1 << lineP1_beforeBTAG_1 << std::endl;
   fout_inc_light_1 << lineP2_beforeBTAG_1 << std::endl;
   fout_inc_light_1 << lineP3_beforeBTAG_1 << std::endl;
   fout_inc_light_1 << lineNDOF_beforeBTAG_1 << std::endl;
   fout_inc_light_1 << lineCHISQ_beforeBTAG_1 << std::endl;
   fout_inc_light_1 << linePROB_beforeBTAG_NOCOLOR_1 << std::endl;

//   fout_inc_heavy_2 << lineP1_beforeBTAG_2 << std::endl;
//   fout_inc_heavy_2 << lineP2_beforeBTAG_2 << std::endl;
//   fout_inc_heavy_2 << lineP3_beforeBTAG_2 << std::endl;
//   fout_inc_heavy_2 << lineNDOF_beforeBTAG_2 << std::endl;
//   fout_inc_heavy_2 << lineCHISQ_beforeBTAG_2 << std::endl;
//   fout_inc_heavy_2 << linePROB_beforeBTAG_NOCOLOR_2 << std::endl;

   fout_inc_light_2 << lineP1_beforeBTAG_2 << std::endl;
   fout_inc_light_2 << lineP2_beforeBTAG_2 << std::endl;
   fout_inc_light_2 << lineP3_beforeBTAG_2 << std::endl;
   fout_inc_light_2 << lineNDOF_beforeBTAG_2 << std::endl;
   fout_inc_light_2 << lineCHISQ_beforeBTAG_2 << std::endl;
   fout_inc_light_2 << linePROB_beforeBTAG_NOCOLOR_2 << std::endl;
   
   fout_heavy << lineP1_beforeBTAG << std::endl;
   fout_heavy << lineP2_beforeBTAG << std::endl;
   fout_heavy << lineP3_beforeBTAG << std::endl;
   fout_heavy << lineNDOF_beforeBTAG << std::endl;
   fout_heavy << lineCHISQ_beforeBTAG << std::endl;
   fout_heavy << linePROB_beforeBTAG << std::endl;

   fout_light << lineP1_beforeBTAG << std::endl;
   fout_light << lineP2_beforeBTAG << std::endl;
   fout_light << lineP3_beforeBTAG << std::endl;
   fout_light << lineNDOF_beforeBTAG << std::endl;
   fout_light << lineCHISQ_beforeBTAG << std::endl;
   fout_light << linePROB_beforeBTAG << std::endl;

//   fout_heavy_1 << lineP1_beforeBTAG_1 << std::endl;
//   fout_heavy_1 << lineP2_beforeBTAG_1 << std::endl;
//   fout_heavy_1 << lineP3_beforeBTAG_1 << std::endl;
//   fout_heavy_1 << lineNDOF_beforeBTAG_1 << std::endl;
//   fout_heavy_1 << lineCHISQ_beforeBTAG_1 << std::endl;
//   fout_heavy_1 << linePROB_beforeBTAG_1 << std::endl;

   fout_light_1 << lineP1_beforeBTAG_1 << std::endl;
   fout_light_1 << lineP2_beforeBTAG_1 << std::endl;
   fout_light_1 << lineP3_beforeBTAG_1 << std::endl;
   fout_light_1 << lineNDOF_beforeBTAG_1 << std::endl;
   fout_light_1 << lineCHISQ_beforeBTAG_1 << std::endl;
   fout_light_1 << linePROB_beforeBTAG_1 << std::endl;

//   fout_heavy_2 << lineP1_beforeBTAG_2 << std::endl;
//   fout_heavy_2 << lineP2_beforeBTAG_2 << std::endl;
//   fout_heavy_2 << lineP3_beforeBTAG_2 << std::endl;
//   fout_heavy_2 << lineNDOF_beforeBTAG_2 << std::endl;
//   fout_heavy_2 << lineCHISQ_beforeBTAG_2 << std::endl;
//   fout_heavy_2 << linePROB_beforeBTAG_2 << std::endl;

   fout_light_2 << lineP1_beforeBTAG_2 << std::endl;
   fout_light_2 << lineP2_beforeBTAG_2 << std::endl;
   fout_light_2 << lineP3_beforeBTAG_2 << std::endl;
   fout_light_2 << lineNDOF_beforeBTAG_2 << std::endl;
   fout_light_2 << lineCHISQ_beforeBTAG_2 << std::endl;
   fout_light_2 << linePROB_beforeBTAG_2 << std::endl;
   
   fout << "\\hline" << std::endl;
   fout_inc << "\\hline" << std::endl;
   fout_inc_heavy << "\\hline" << std::endl;
   fout_inc_light << "\\hline" << std::endl;
   fout_heavy << "\\hline" << std::endl;
   fout_light << "\\hline" << std::endl;

//   fout_inc_heavy_1 << "\\hline" << std::endl;
//   fout_inc_light_1 << "\\hline" << std::endl;
   fout_heavy_1 << "\\hline" << std::endl;
   fout_light_1 << "\\hline" << std::endl;

//   fout_inc_heavy_2 << "\\hline" << std::endl;
//   fout_inc_light_2 << "\\hline" << std::endl;
   fout_heavy_2 << "\\hline" << std::endl;
   fout_light_2 << "\\hline" << std::endl;
   
   fout << lineP1_afterBTAG << std::endl;
   fout << lineP2_afterBTAG << std::endl;
   fout << lineP3_afterBTAG << std::endl;
   fout << lineNDOF_afterBTAG << std::endl;
   fout << lineCHISQ_afterBTAG << std::endl;
   fout << linePROB_afterBTAG << std::endl;

   fout_inc << lineP1_afterBTAG << std::endl;
   fout_inc << lineP2_afterBTAG << std::endl;
   fout_inc << lineP3_afterBTAG << std::endl;
   fout_inc << lineNDOF_afterBTAG << std::endl;
   fout_inc << lineCHISQ_afterBTAG << std::endl;
   fout_inc << linePROB_afterBTAG << std::endl;

   fout_inc_heavy << lineP1_afterBTAG << std::endl;
   fout_inc_heavy << lineP2_afterBTAG << std::endl;
   fout_inc_heavy << lineP3_afterBTAG << std::endl;
   fout_inc_heavy << lineNDOF_afterBTAG << std::endl;
   fout_inc_heavy << lineCHISQ_afterBTAG << std::endl;
   fout_inc_heavy << linePROB_afterBTAG_NOCOLOR << std::endl;

   fout_inc_light << lineP1_afterBTAG << std::endl;
   fout_inc_light << lineP2_afterBTAG << std::endl;
   fout_inc_light << lineP3_afterBTAG << std::endl;
   fout_inc_light << lineNDOF_afterBTAG << std::endl;
   fout_inc_light << lineCHISQ_afterBTAG << std::endl;
   fout_inc_light << linePROB_afterBTAG_NOCOLOR << std::endl;

   fout_inc_heavy_1 << lineP1_afterBTAG_1 << std::endl;
   fout_inc_heavy_1 << lineP2_afterBTAG_1 << std::endl;
   fout_inc_heavy_1 << lineP3_afterBTAG_1 << std::endl;
   fout_inc_heavy_1 << lineNDOF_afterBTAG_1 << std::endl;
   fout_inc_heavy_1 << lineCHISQ_afterBTAG_1 << std::endl;
   fout_inc_heavy_1 << linePROB_afterBTAG_NOCOLOR_1 << std::endl;

   fout_inc_light_1 << lineP1_afterBTAG_1 << std::endl;
   fout_inc_light_1 << lineP2_afterBTAG_1 << std::endl;
   fout_inc_light_1 << lineP3_afterBTAG_1 << std::endl;
   fout_inc_light_1 << lineNDOF_afterBTAG_1 << std::endl;
   fout_inc_light_1 << lineCHISQ_afterBTAG_1 << std::endl;
   fout_inc_light_1 << linePROB_afterBTAG_NOCOLOR_1 << std::endl;

   fout_inc_heavy_2 << lineP1_afterBTAG_2 << std::endl;
   fout_inc_heavy_2 << lineP2_afterBTAG_2 << std::endl;
   fout_inc_heavy_2 << lineP3_afterBTAG_2 << std::endl;
   fout_inc_heavy_2 << lineNDOF_afterBTAG_2 << std::endl;
   fout_inc_heavy_2 << lineCHISQ_afterBTAG_2 << std::endl;
   fout_inc_heavy_2 << linePROB_afterBTAG_NOCOLOR_2 << std::endl;

   fout_inc_light_2 << lineP1_afterBTAG_2 << std::endl;
   fout_inc_light_2 << lineP2_afterBTAG_2 << std::endl;
   fout_inc_light_2 << lineP3_afterBTAG_2 << std::endl;
   fout_inc_light_2 << lineNDOF_afterBTAG_2 << std::endl;
   fout_inc_light_2 << lineCHISQ_afterBTAG_2 << std::endl;
   fout_inc_light_2 << linePROB_afterBTAG_NOCOLOR_2 << std::endl;
   
   fout_heavy << lineP1_afterBTAG << std::endl;
   fout_heavy << lineP2_afterBTAG << std::endl;
   fout_heavy << lineP3_afterBTAG << std::endl;
   fout_heavy << lineNDOF_afterBTAG << std::endl;
   fout_heavy << lineCHISQ_afterBTAG << std::endl;
   fout_heavy << linePROB_afterBTAG << std::endl;

   fout_light << lineP1_afterBTAG << std::endl;
   fout_light << lineP2_afterBTAG << std::endl;
   fout_light << lineP3_afterBTAG << std::endl;
   fout_light << lineNDOF_afterBTAG << std::endl;
   fout_light << lineCHISQ_afterBTAG << std::endl;
   fout_light << linePROB_afterBTAG << std::endl;

   fout_heavy_1 << lineP1_afterBTAG_1 << std::endl;
   fout_heavy_1 << lineP2_afterBTAG_1 << std::endl;
   fout_heavy_1 << lineP3_afterBTAG_1 << std::endl;
   fout_heavy_1 << lineNDOF_afterBTAG_1 << std::endl;
   fout_heavy_1 << lineCHISQ_afterBTAG_1 << std::endl;
   fout_heavy_1 << linePROB_afterBTAG_1 << std::endl;

   fout_light_1 << lineP1_afterBTAG_1 << std::endl;
   fout_light_1 << lineP2_afterBTAG_1 << std::endl;
   fout_light_1 << lineP3_afterBTAG_1 << std::endl;
   fout_light_1 << lineNDOF_afterBTAG_1 << std::endl;
   fout_light_1 << lineCHISQ_afterBTAG_1 << std::endl;
   fout_light_1 << linePROB_afterBTAG_1 << std::endl;

   fout_heavy_2 << lineP1_afterBTAG_2 << std::endl;
   fout_heavy_2 << lineP2_afterBTAG_2 << std::endl;
   fout_heavy_2 << lineP3_afterBTAG_2 << std::endl;
   fout_heavy_2 << lineNDOF_afterBTAG_2 << std::endl;
   fout_heavy_2 << lineCHISQ_afterBTAG_2 << std::endl;
   fout_heavy_2 << linePROB_afterBTAG_2 << std::endl;

   fout_light_2 << lineP1_afterBTAG_2 << std::endl;
   fout_light_2 << lineP2_afterBTAG_2 << std::endl;
   fout_light_2 << lineP3_afterBTAG_2 << std::endl;
   fout_light_2 << lineNDOF_afterBTAG_2 << std::endl;
   fout_light_2 << lineCHISQ_afterBTAG_2 << std::endl;
   fout_light_2 << linePROB_afterBTAG_2 << std::endl;
   
   fout << "\\hline" << std::endl;
   fout_inc << "\\hline" << std::endl;
   fout_inc_heavy << "\\hline" << std::endl;
   fout_inc_light << "\\hline" << std::endl;
   fout_heavy << "\\hline" << std::endl;
   fout_light << "\\hline" << std::endl;

//   fout_inc_heavy_1 << "\\hline" << std::endl;
//   fout_inc_light_1 << "\\hline" << std::endl;
   fout_heavy_1 << "\\hline" << std::endl;
   fout_light_1 << "\\hline" << std::endl;

//   fout_inc_heavy_2 << "\\hline" << std::endl;
//   fout_inc_light_2 << "\\hline" << std::endl;
   fout_heavy_2 << "\\hline" << std::endl;
   fout_light_2 << "\\hline" << std::endl;
   
   fout << lineEFFDATA1 << std::endl;
   fout << lineEFFMC1 << std::endl;
   fout << lineSF1 << std::endl;

   fout_inc << lineEFFDATA1 << std::endl;
   fout_inc << lineEFFMC1 << std::endl;
   fout_inc << lineSF1 << std::endl;

   fout_inc_heavy << lineEFFDATA1 << std::endl;
   fout_inc_heavy << lineEFFMC1 << std::endl;
   fout_inc_heavy << lineSF1 << std::endl;

   fout_heavy << lineEFFDATA1 << std::endl;
   fout_heavy << lineEFFMC1 << std::endl;
   fout_heavy << lineSF1 << std::endl;

//   fout_inc_heavy_1 << lineEFFDATA1_1 << std::endl;
//   fout_inc_heavy_1 << lineEFFMC1_1 << std::endl;
//   fout_inc_heavy_1 << lineSF1_1 << std::endl;

   fout_heavy_1 << lineEFFDATA1_1 << std::endl;
   fout_heavy_1 << lineEFFMC1_1 << std::endl;
   fout_heavy_1 << lineSF1_1 << std::endl;

//   fout_inc_heavy_2 << lineEFFDATA1_2 << std::endl;
//   fout_inc_heavy_2 << lineEFFMC1_2 << std::endl;
//   fout_inc_heavy_2 << lineSF1_2 << std::endl;

   fout_heavy_2 << lineEFFDATA1_2 << std::endl;
   fout_heavy_2 << lineEFFMC1_2 << std::endl;
   fout_heavy_2 << lineSF1_2 << std::endl;
   
   fout << "\\hline" << std::endl;
   fout_inc << "\\hline" << std::endl;
   fout_inc_heavy << "\\hline" << std::endl;
   fout_inc_light << "\\hline" << std::endl;
   fout_heavy << "\\hline" << std::endl;
   fout_light << "\\hline" << std::endl;

   fout_inc_heavy_1 << "\\hline" << std::endl;
   fout_inc_light_1 << "\\hline" << std::endl;
   fout_heavy_1 << "\\hline" << std::endl;
   fout_light_1 << "\\hline" << std::endl;

   fout_inc_heavy_2 << "\\hline" << std::endl;
   fout_inc_light_2 << "\\hline" << std::endl;
   fout_heavy_2 << "\\hline" << std::endl;
   fout_light_2 << "\\hline" << std::endl;
   
/*   fout << lineEFFDATA1_charm << std::endl;
   fout << lineEFFMC1_charm << std::endl;
   fout << lineSF1_charm << std::endl;

   fout_inc << lineEFFDATA1_charm << std::endl;
   fout_inc << lineEFFMC1_charm << std::endl;
   fout_inc << lineSF1_charm << std::endl;

   fout_inc_heavy << lineEFFDATA1_charm << std::endl;
   fout_inc_heavy << lineEFFMC1_charm << std::endl;
   fout_inc_heavy << lineSF1_charm << std::endl;

   fout_heavy << lineEFFDATA1_charm << std::endl;
   fout_heavy << lineEFFMC1_charm << std::endl;
   fout_heavy << lineSF1_charm << std::endl;

   fout_inc_heavy_1 << lineEFFDATA1_charm_1 << std::endl;
   fout_inc_heavy_1 << lineEFFMC1_charm_1 << std::endl;
   fout_inc_heavy_1 << lineSF1_charm_1 << std::endl;

   fout_heavy_1 << lineEFFDATA1_charm_1 << std::endl;
   fout_heavy_1 << lineEFFMC1_charm_1 << std::endl;
   fout_heavy_1 << lineSF1_charm_1 << std::endl;

   fout_inc_heavy_2 << lineEFFDATA1_charm_2 << std::endl;
   fout_inc_heavy_2 << lineEFFMC1_charm_2 << std::endl;
   fout_inc_heavy_2 << lineSF1_charm_2 << std::endl;

   fout_heavy_2 << lineEFFDATA1_charm_2 << std::endl;
   fout_heavy_2 << lineEFFMC1_charm_2 << std::endl;
   fout_heavy_2 << lineSF1_charm_2 << std::endl;
*/   
//   fout << "\\hline" << std::endl;
//   fout_inc << "\\hline" << std::endl;
   
   fout << lineEFFDATA1_light << std::endl;
   fout << lineEFFMC1_light << std::endl;
   fout << lineSF1_light << std::endl;

   fout_inc << lineEFFDATA1_light << std::endl;
   fout_inc << lineEFFMC1_light << std::endl;
   fout_inc << lineSF1_light << std::endl;

   fout_inc_light << lineEFFDATA1_light << std::endl;
   fout_inc_light << lineEFFMC1_light << std::endl;
   fout_inc_light << lineSF1_light << std::endl;

   fout_light << lineEFFDATA1_light << std::endl;
   fout_light << lineEFFMC1_light << std::endl;
   fout_light << lineSF1_light << std::endl;

   fout_inc_light_1 << lineEFFDATA1_light_1 << std::endl;
   fout_inc_light_1 << lineEFFMC1_light_1 << std::endl;
   fout_inc_light_1 << lineSF1_light_1 << std::endl;

   fout_light_1 << lineEFFDATA1_light_1 << std::endl;
   fout_light_1 << lineEFFMC1_light_1 << std::endl;
   fout_light_1 << lineSF1_light_1 << std::endl;

   fout_inc_light_2 << lineEFFDATA1_light_2 << std::endl;
   fout_inc_light_2 << lineEFFMC1_light_2 << std::endl;
   fout_inc_light_2 << lineSF1_light_2 << std::endl;

   fout_light_2 << lineEFFDATA1_light_2 << std::endl;
   fout_light_2 << lineEFFMC1_light_2 << std::endl;
   fout_light_2 << lineSF1_light_2 << std::endl;
   
   std::string footer1_full = "\n
\\end{tabular} \n
} \n
\\end{center} \n
\\end{table}";

   std::string footer1 = "\n
\\end{tabular}";
   
   std::string footer2 = "
\\end{document}";
   
   fout << footer1_full << std::endl;
   fout << footer2 << std::endl;
   
   fout_inc << footer1 << std::endl;
   fout_inc_heavy << footer1 << std::endl;
   fout_inc_light << footer1 << std::endl;

   fout_inc_heavy_1 << footer1 << std::endl;
   fout_inc_light_1 << footer1 << std::endl;
   fout_inc_heavy_2 << footer1 << std::endl;
   fout_inc_light_2 << footer1 << std::endl;
   
   fout_heavy << footer1_full << std::endl;
   fout_heavy << footer2 << std::endl;
   fout_light << footer1_full << std::endl;
   fout_light << footer2 << std::endl;

   fout_heavy_1 << footer1_full << std::endl;
   fout_heavy_1 << footer2 << std::endl;
   fout_light_1 << footer1_full << std::endl;
   fout_light_1 << footer2 << std::endl;

   fout_heavy_2 << footer1_full << std::endl;
   fout_heavy_2 << footer2 << std::endl;
   fout_light_2 << footer1_full << std::endl;
   fout_light_2 << footer2 << std::endl;
   
   fout.close();
   fout_inc.close();
   fout_inc_heavy.close();
   fout_inc_light.close();
   fout_heavy.close();
   fout_light.close();

   fout_inc_heavy_1.close();
   fout_inc_light_1.close();
   fout_heavy_1.close();
   fout_light_1.close();

   fout_inc_heavy_2.close();
   fout_inc_light_2.close();
   fout_heavy_2.close();
   fout_light_2.close();
   
   gApplication->Terminate();
}
