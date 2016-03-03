void table()
{
   gROOT->SetBatch();

//   std::string btag = "CSVT";
   std::string btag = "CMVAT";

/*   const int nPT = 15;
   std::string ptName[nPT] = 
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
	"pt400t500",
	"pt500t670"
     };*/

/*   const int nPT = 7;
   std::string ptName[nPT] = 
     {
	"pt30t50",
	"pt50t70",
	"pt70t100",
	"pt100t140",
	"pt140t200",
	"pt200t300",
	"pt300t670"
     };*/

   const int nPT = 5;
   std::string ptName[nPT] = 
     {
	"pt200t220",
	"pt220t250",
	"pt250t300",
	"pt300t400",
	"pt400t650"
     };

/*   const int nPT = 6;
   std::string ptName[nPT] = 
     {
	"pt0t150",
	"pt150t215",
	"pt215t290",
	"pt290t360",
	"pt360t430",
	"pt430t570"
     };*/
   
   std::ofstream fout_part1("table/table_part1.tex");
   std::ofstream fout_part2("table/table_part2.tex");

   std::ofstream fout_tag_part1("table/table_tag_part1.tex");
   std::ofstream fout_tag_part2("table/table_tag_part2.tex");
   
   std::string header_common = "\\documentclass[a4paper]{article} \n \
\\usepackage[english]{babel} \n \
\\usepackage{graphicx} \n \
\\usepackage{color} \n \
\\begin{document}";

   std::string header_part1 = "\
\\begin{table}[hbt!] \n \
\\small \n \
\\begin{center} \n \
\\resizebox{16cm}{!}{ \n \
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|} \n \
\\hline";

   std::string header_part2 = "\
\\begin{table}[hbt!] \n \
\\small \n \
\\begin{center} \n \
\\resizebox{16cm}{!}{ \n \
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|} \n \
\\hline";
   
   fout_part1 << header_common << std::endl;
   fout_part2 << header_common << std::endl;
   fout_tag_part1 << header_common << std::endl;
   fout_tag_part2 << header_common << std::endl;

   fout_part1 << header_part1 << std::endl;
   fout_part2 << header_part2 << std::endl;
   fout_tag_part1 << header_part1 << std::endl;
   fout_tag_part2 << header_part2 << std::endl;
   
   std::string linePT = "$P_{T}$ [GeV] & ";
   std::string lineP1 = "$p$ (b-jet) & ";
   std::string lineP2 = "$p$ (c-jet) & ";
   std::string lineP3 = "$p$ (l-jet) & ";   
   std::string lineCHISQ = "$\\chi^{2}$/$N_{dof}$ & ";
   std::string lineNDOF = "$N_{dof}$ & ";
   std::string linePROB = "$P (\\chi^{2})$ & ";   
   std::string lineEFFDATA = "$\\epsilon$ (b-jet) (Data) & ";
   std::string lineEFFMC = "$\\epsilon$ (b-jet) (MC) & ";
   std::string lineSF = "$SF$ (b-jet) & ";

   std::string lineP1_part1 = lineP1;
   std::string lineP2_part1 = lineP2;
   std::string lineP3_part1 = lineP3;
   std::string lineCHISQ_part1 = lineCHISQ;
   std::string lineNDOF_part1 = lineNDOF;
   std::string linePROB_part1 = linePROB;

   std::string lineP1_part2 = lineP1;
   std::string lineP2_part2 = lineP2;
   std::string lineP3_part2 = lineP3;
   std::string lineCHISQ_part2 = lineCHISQ;
   std::string lineNDOF_part2 = lineNDOF;
   std::string linePROB_part2 = linePROB;
   
   std::string lineP1_tag_part1 = lineP1;
   std::string lineP2_tag_part1 = lineP2;
   std::string lineP3_tag_part1 = lineP3;
   std::string lineCHISQ_tag_part1 = lineCHISQ;
   std::string lineNDOF_tag_part1 = lineNDOF;
   std::string linePROB_tag_part1 = linePROB;

   std::string lineP1_tag_part2 = lineP1;
   std::string lineP2_tag_part2 = lineP2;
   std::string lineP3_tag_part2 = lineP3;
   std::string lineCHISQ_tag_part2 = lineCHISQ;
   std::string lineNDOF_tag_part2 = lineNDOF;
   std::string linePROB_tag_part2 = linePROB;
   
   std::string linePT_part1 = linePT;
   std::string linePT_part2 = linePT;
   
   std::string linePT_tag_part1 = linePT;   
   std::string linePT_tag_part2 = linePT;
   
   std::string lineEFFDATA_part1 = lineEFFDATA;
   std::string lineEFFMC_part1 = lineEFFMC;
   std::string lineSF_part1 = lineSF;

   std::string lineEFFDATA_part2 = lineEFFDATA;
   std::string lineEFFMC_part2 = lineEFFMC;
   std::string lineSF_part2 = lineSF;

//   std::string lineEFFDATA_tag_part1 = lineEFFDATA;
//   std::string lineEFFMC_tag_part1 = lineEFFMC;
//   std::string lineSF_tag_part1 = lineSF;

//   std::string lineEFFDATA_tag_part2 = lineEFFDATA;
//   std::string lineEFFMC_tag_part2 = lineEFFMC;
//   std::string lineSF_tag_part2 = lineSF;
   
   for(int j=0;j<nPT;j++)
     {
	std::string fname = "results/"+ptName[j]+"_"+btag+".csv";
	//std::string fname = "results_"+btag+"_MJ/"+ptName[j]+"_"+btag+".csv";
	std::cout << fname << std::endl;
	std::ifstream f(fname.c_str());
	std::string line = "";
	int idx = 0;
	while( !f.eof() )
	  {
	     f >> line;
	     if( idx == 1 ) break;
	     idx++;
	  }
	f.close();
	
	std::stringstream ss(line);
	std::string item;
	idx = 0;
	
	double pt1, pt2;
	double sf, sferr, effdata, efferrdata, effmc, efferrmc;
	double chisq, p1, p1err, p2, p2err, p3, p3err, prob;
	double chisq_tag, p1_tag, p1err_tag, p2_tag, p2err_tag, p3_tag, p3err_tag, prob_tag;
	float ndof, ndof_tag;
	float nmcb, nmcbTag, nmcc, nmccTag, nmcl, nmclTag, ndata, ndataTag;
	float frb, frbTag, frc, frcTag, frl, frlTag;
	
	while( std::getline(ss,item,',') )
	  {	     	
	     if( idx == 0 ) pt1 = atoi(item.c_str());
	     else if( idx == 1 ) pt2 = atoi(item.c_str());
	     else if( idx == 4 ) ndata = atof(item.c_str());
	     else if( idx == 5 ) ndataTag = atof(item.c_str());
	     else if( idx == 6 ) nmcb = atof(item.c_str());
	     else if( idx == 7 ) nmcbTag = atof(item.c_str());
	     else if( idx == 8 ) nmcc = atof(item.c_str());
	     else if( idx == 9 ) nmccTag = atof(item.c_str());
	     else if( idx == 10 ) nmcl = atof(item.c_str());
	     else if( idx == 11 ) nmclTag = atof(item.c_str());
	     else if( idx == 14 ) frb = atof(item.c_str());
	     else if( idx == 15 ) frbTag = atof(item.c_str());
	     else if( idx == 16 ) frc = atof(item.c_str());
	     else if( idx == 17 ) frcTag = atof(item.c_str());
	     else if( idx == 18 ) frl = atof(item.c_str());
	     else if( idx == 19 ) frlTag = atof(item.c_str());
	     else if( idx == 24 ) sf = atof(item.c_str());
	     else if( idx == 27 ) sferr = atof(item.c_str());
	     else if( idx == 23 ) effdata = atof(item.c_str());
	     else if( idx == 26 ) efferrdata = atof(item.c_str());
	     else if( idx == 22 ) effmc = atof(item.c_str());
	     else if( idx == 25 ) efferrmc = atof(item.c_str());
	     else if( idx == 20 ) chisq = atof(item.c_str());
	     else if( idx == 38 ) ndof = atoi(item.c_str());
	     else if( idx == 12 ) p1 = atof(item.c_str());
	     else if( idx == 28 ) p1err = atof(item.c_str());
	     else if( idx == 30 ) p2 = atof(item.c_str());
	     else if( idx == 31 ) p2err = atof(item.c_str());
	     else if( idx == 34 ) p3 = atof(item.c_str());
	     else if( idx == 35 ) p3err = atof(item.c_str());	     
	     else if( idx == 21 ) chisq_tag = atof(item.c_str());
	     else if( idx == 39 ) ndof_tag = atoi(item.c_str());
	     else if( idx == 13 ) p1_tag = atof(item.c_str());
	     else if( idx == 29 ) p1err_tag = atof(item.c_str());
	     else if( idx == 32 ) p2_tag = atof(item.c_str());
	     else if( idx == 33 ) p2err_tag = atof(item.c_str());
	     else if( idx == 36 ) p3_tag = atof(item.c_str());
	     else if( idx == 37 ) p3err_tag = atof(item.c_str());
	     idx++;
	  }
	
	// redefine fit parameters to show the relative change in fractions
	float nmc = nmcb+nmcc+nmcl;
	float frbFactor = nmc/ndata*p1;
	float frbFactorError = nmc/ndata*p1err;
	float frcFactor = nmc/ndata*p2;
	float frcFactorError = nmc/ndata*p2err;
	float frlFactor = nmc/ndata*p3;
	float frlFactorError = nmc/ndata*p3err;
	
	float nmcTag = nmcbTag+nmccTag+nmclTag;
	float frbTagFactor = nmcTag/ndataTag*p1_tag;
	float frbTagFactorError = nmc/ndata*p1err_tag;
	float frcTagFactor = nmcTag/ndataTag*p2_tag;
	float frcTagFactorError = nmc/ndata*p2err_tag;
	float frlTagFactor = nmcTag/ndataTag*p3_tag;
	float frlTagFactorError = nmc/ndata*p3err_tag;
	
	p1 = frbFactor;
	p1err = frbFactorError;
	p2 = frcFactor;
	p2err = frcFactorError;
	p3 = frlFactor;
	p3err = frlFactorError;
	
	p1_tag = frbTagFactor;
	p1err_tag = frbTagFactorError;
	p2_tag = frcTagFactor;
	p2err_tag = frcTagFactorError;
	p3_tag = frlTagFactor;
	p3err_tag = frlTagFactorError;
	
	prob = TMath::Prob(chisq*ndof,ndof);
	prob_tag = TMath::Prob(chisq_tag*ndof_tag,ndof_tag);
	
	stringstream sss("");
	sss.precision(0);

	// pt
	
	sss << fixed << pt1;
	std::string pt1Str = sss.str();
	sss.str("");
	sss << pt2;
	std::string pt2Str = sss.str();

	sss.precision(3);
	
	// eff & SF b-jet
	
	sss.str("");
	sss << sf;
	std::string sfStr = sss.str();
	sss.str("");
	sss << sferr;
	std::string sferrStr = sss.str();
	
	sss.str("");
	sss << effdata;
	std::string effdataStr = sss.str();
	sss.str("");
	sss << efferrdata;
	std::string efferrdataStr = sss.str();

	sss.str("");
	sss << effmc;
	std::string effmcStr = sss.str();
	sss.str("");
	sss << efferrmc;
	std::string efferrmcStr = sss.str();
	
	// notag
	
	sss.str("");
	sss << chisq;
	std::string chisqStr = sss.str();

	sss.str("");
	sss.precision(0);
	sss << ndof;
	std::string ndofStr = sss.str();
	sss.precision(3);

	sss.str("");
	sss.precision(3);
	sss << prob;
	std::string probStr = sss.str();
	sss.precision(3);
	
	sss.str("");
	sss << p1;
	std::string p1Str = sss.str();
	sss.str("");
	sss << p1err;
	std::string p1errStr = sss.str();

	sss.str("");
	sss << p2;
	std::string p2Str = sss.str();
	sss.str("");
	sss << p2err;
	std::string p2errStr = sss.str();

	sss.str("");
	sss << p3;
	std::string p3Str = sss.str();
	sss.str("");
	sss << p3err;
	std::string p3errStr = sss.str();
	
	// tag

	sss.str("");
	sss << chisq_tag;
	std::string chisqStr_tag = sss.str();

	sss.str("");
	sss.precision(0);
	sss << ndof_tag;
	std::string ndofStr_tag = sss.str();
	sss.precision(3);

	sss.str("");
	sss.precision(3);
	sss << prob_tag;
	std::string probStr_tag = sss.str();
	sss.precision(3);
	
	sss.str("");
	sss << p1_tag;
	std::string p1Str_tag = sss.str();
	sss.str("");
	sss << p1err_tag;
	std::string p1errStr_tag = sss.str();

	sss.str("");
	sss << p2_tag;
	std::string p2Str_tag = sss.str();
	sss.str("");
	sss << p2err_tag;
	std::string p2errStr_tag = sss.str();

	sss.str("");
	sss << p3_tag;
	std::string p3Str_tag = sss.str();
	sss.str("");
	sss << p3err_tag;
	std::string p3errStr_tag = sss.str();

	// merge

	std::string linePT_cur = pt1Str + " - " + pt2Str;
	std::string linePT_tag_cur = pt1Str + " - " + pt2Str;
	std::string lineSF_cur = sfStr + " $\\pm$ " + sferrStr;
	std::string lineEFFDATA_cur = effdataStr + " $\\pm$ " + efferrdataStr;
	std::string lineEFFMC_cur = effmcStr + " $\\pm$ " + efferrmcStr;
	std::string lineCHISQ_cur = chisqStr;
	std::string lineNDOF_cur = ndofStr;
	std::string linePROB_cur = probStr;
	std::string lineP1_cur = p1Str + " $\\pm$ " + p1errStr;
	std::string lineP2_cur = p2Str + " $\\pm$ " + p2errStr;
	std::string lineP3_cur = p3Str + " $\\pm$ " + p3errStr;
	std::string lineCHISQ_tag_cur = chisqStr_tag;
	std::string lineNDOF_tag_cur = ndofStr_tag;
	std::string linePROB_tag_cur = probStr_tag;
	std::string lineP1_tag_cur = p1Str_tag + " $\\pm$ " + p1errStr_tag;
	std::string lineP2_tag_cur = p2Str_tag + " $\\pm$ " + p2errStr_tag;
	std::string lineP3_tag_cur = p3Str_tag + " $\\pm$ " + p3errStr_tag;

	if( j <= nPT ) // FIXME
//	if( j <= nPT/2 )
	  {
	     linePT_part1 += linePT_cur;
	     linePT_tag_part1 += linePT_tag_cur;
	     lineSF_part1 += lineSF_cur;
	     lineEFFDATA_part1 += lineEFFDATA_cur;
	     lineEFFMC_part1 += lineEFFMC_cur;
	     lineCHISQ_part1 += lineCHISQ_cur;
	     lineNDOF_part1 += lineNDOF_cur;
	     linePROB_part1 += linePROB_cur;
	     lineP1_part1 += lineP1_cur;
	     lineP2_part1 += lineP2_cur;
	     lineP3_part1 += lineP3_cur;
	     lineCHISQ_tag_part1 += lineCHISQ_tag_cur;
	     lineNDOF_tag_part1 += lineNDOF_tag_cur;
	     linePROB_tag_part1 += linePROB_tag_cur;
	     lineP1_tag_part1 += lineP1_tag_cur;
	     lineP2_tag_part1 += lineP2_tag_cur;
	     lineP3_tag_part1 += lineP3_tag_cur;
	  }
	else
	  {
	     linePT_part2 += linePT_cur;
	     linePT_tag_part2 += linePT_tag_cur;
	     lineSF_part2 += lineSF_cur;
	     lineEFFDATA_part2 += lineEFFDATA_cur;
	     lineEFFMC_part2 += lineEFFMC_cur;
	     lineCHISQ_part2 += lineCHISQ_cur;
	     lineNDOF_part2 += lineNDOF_cur;
	     linePROB_part2 += linePROB_cur;
	     lineP1_part2 += lineP1_cur;
	     lineP2_part2 += lineP2_cur;
	     lineP3_part2 += lineP3_cur;
	     lineCHISQ_tag_part2 += lineCHISQ_tag_cur;
	     lineNDOF_tag_part2 += lineNDOF_tag_cur;
	     linePROB_tag_part2 += linePROB_tag_cur;
	     lineP1_tag_part2 += lineP1_tag_cur;
	     lineP2_tag_part2 += lineP2_tag_cur;
	     lineP3_tag_part2 += lineP3_tag_cur;
	  }	
	
	if( j != nPT-1 )
	  {
//	     if( j < nPT/2 ) FIXME
	     if( j < nPT )
	       {
		  linePT_part1 += " & ";
		  linePT_tag_part1 += " & ";
		  lineSF_part1 += " & ";
		  lineEFFDATA_part1 += " & ";
		  lineEFFMC_part1 += " & ";
		  lineCHISQ_part1 += " & ";
		  lineNDOF_part1 += " & ";
		  linePROB_part1 += " & ";
		  lineP1_part1 += " & ";
		  lineP2_part1 += " & ";
		  lineP3_part1 += " & ";	     
		  lineCHISQ_tag_part1 += " & ";
		  lineNDOF_tag_part1 += " & ";
		  linePROB_tag_part1 += " & ";
		  lineP1_tag_part1 += " & ";
		  lineP2_tag_part1 += " & ";
		  lineP3_tag_part1 += " & ";	     
	       }
	     
//	     if( j > nPT/2 ) FIXME
	     if( j > nPT )
	       {
		  linePT_part2 += " & ";
		  linePT_tag_part2 += " & ";
		  lineSF_part2 += " & ";
		  lineEFFDATA_part2 += " & ";
		  lineEFFMC_part2 += " & ";
		  lineCHISQ_part2 += " & ";
		  lineNDOF_part2 += " & ";
		  linePROB_part2 += " & ";
		  lineP1_part2 += " & ";
		  lineP2_part2 += " & ";
		  lineP3_part2 += " & ";	     
		  lineCHISQ_tag_part2 += " & ";
		  lineNDOF_tag_part2 += " & ";
		  linePROB_tag_part2 += " & ";
		  lineP1_tag_part2 += " & ";
		  lineP2_tag_part2 += " & ";
		  lineP3_tag_part2 += " & ";	     
	       }	     
	  }	
     }   
   
   std::string endLine = "\\\\";
   
   linePT_part1 += endLine;
   linePT_tag_part1 += endLine;
   lineSF_part1 += endLine;
   lineEFFDATA_part1 += endLine;
   lineEFFMC_part1 += endLine;
   lineCHISQ_part1 += endLine;
   lineNDOF_part1 += endLine;
   linePROB_part1 += endLine;
   lineP1_part1 += endLine;
   lineP2_part1 += endLine;
   lineP3_part1 += endLine;
   lineCHISQ_tag_part1 += endLine;
   lineNDOF_tag_part1 += endLine;
   linePROB_tag_part1 += endLine;
   lineP1_tag_part1 += endLine;
   lineP2_tag_part1 += endLine;
   lineP3_tag_part1 += endLine;

   linePT_part2 += endLine;
   linePT_tag_part2 += endLine;
   lineSF_part2 += endLine;
   lineEFFDATA_part2 += endLine;
   lineEFFMC_part2 += endLine;
   lineCHISQ_part2 += endLine;
   lineNDOF_part2 += endLine;
   linePROB_part2 += endLine;
   lineP1_part2 += endLine;
   lineP2_part2 += endLine;
   lineP3_part2 += endLine;
   lineCHISQ_tag_part2 += endLine;
   lineNDOF_tag_part2 += endLine;
   linePROB_tag_part2 += endLine;
   lineP1_tag_part2 += endLine;
   lineP2_tag_part2 += endLine;
   lineP3_tag_part2 += endLine;
   
   fout_part1 << linePT_part1 << std::endl;
   fout_tag_part1 << linePT_tag_part1 << std::endl;

   fout_part2 << linePT_part2 << std::endl;
   fout_tag_part2 << linePT_tag_part2 << std::endl;
   
   fout_part1 << "\\hline" << std::endl;
   fout_tag_part1 << "\\hline" << std::endl;
   fout_part2 << "\\hline" << std::endl;
   fout_tag_part2 << "\\hline" << std::endl;
   
   fout_part1 << lineP1_part1 << std::endl;
   fout_part1 << lineP2_part1 << std::endl;
   fout_part1 << lineP3_part1 << std::endl;
   fout_part1 << lineNDOF_part1 << std::endl;
   fout_part1 << lineCHISQ_part1 << std::endl;
   fout_part1 << linePROB_part1 << std::endl;

   fout_part2 << lineP1_part2 << std::endl;
   fout_part2 << lineP2_part2 << std::endl;
   fout_part2 << lineP3_part2 << std::endl;
   fout_part2 << lineNDOF_part2 << std::endl;
   fout_part2 << lineCHISQ_part2 << std::endl;
   fout_part2 << linePROB_part2 << std::endl;

   fout_tag_part1 << lineP1_tag_part1 << std::endl;
   fout_tag_part1 << lineP2_tag_part1 << std::endl;
   fout_tag_part1 << lineP3_tag_part1 << std::endl;
   fout_tag_part1 << lineNDOF_tag_part1 << std::endl;
   fout_tag_part1 << lineCHISQ_tag_part1 << std::endl;
   fout_tag_part1 << linePROB_tag_part1 << std::endl;

   fout_tag_part2 << lineP1_tag_part2 << std::endl;
   fout_tag_part2 << lineP2_tag_part2 << std::endl;
   fout_tag_part2 << lineP3_tag_part2 << std::endl;
   fout_tag_part2 << lineNDOF_tag_part2 << std::endl;
   fout_tag_part2 << lineCHISQ_tag_part2 << std::endl;
   fout_tag_part2 << linePROB_tag_part2 << std::endl;               
   
   fout_part1 << "\\hline" << std::endl;
   fout_tag_part1 << "\\hline" << std::endl;

   fout_part2 << "\\hline" << std::endl;
   fout_tag_part2 << "\\hline" << std::endl;
   
   fout_part1 << lineEFFDATA_part1 << std::endl;
   fout_part1 << lineEFFMC_part1 << std::endl;
   fout_part1 << lineSF_part1 << std::endl;

   fout_part2 << lineEFFDATA_part2 << std::endl;
   fout_part2 << lineEFFMC_part2 << std::endl;
   fout_part2 << lineSF_part2 << std::endl;

//   fout_tag_part1 << lineEFFDATA_tag_part1 << std::endl;
//   fout_tag_part1 << lineEFFMC_tag_part1 << std::endl;
//   fout_tag_part1 << lineSF_tag_part1 << std::endl;

//   fout_tag_part2 << lineEFFDATA_tag_part2 << std::endl;
//   fout_tag_part2 << lineEFFMC_tag_part2 << std::endl;
//   fout_tag_part2 << lineSF_tag_part2 << std::endl;
   
   fout_part1 << "\\hline" << std::endl;
   fout_part2 << "\\hline" << std::endl;

//   fout_tag_part1 << "\\hline" << std::endl;
//   fout_tag_part2 << "\\hline" << std::endl;
   
   std::string footer_common = "\n \
\\end{tabular} \n \
} \n \
\\end{center} \n \
\\end{table} \n \
\\end{document}";
   
   fout_part1 << footer_common << std::endl;
   fout_part2 << footer_common << std::endl;

   fout_tag_part1 << footer_common << std::endl;
   fout_tag_part2 << footer_common << std::endl;
   
   fout_part1.close();
   fout_part2.close();

   fout_tag_part1.close();
   fout_tag_part2.close();
   
   gApplication->Terminate();
}
