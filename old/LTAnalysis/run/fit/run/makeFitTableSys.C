void makeFitTableSys(std::string jtype)
{
   gROOT->SetBatch();

   std::ifstream fsys("results/sys_nosel_ALL.txt");

   const int nptbin = 16;
   std::string ptbinname[nptbin] = {"pt20t30","pt30t40","pt40t50","pt50t60","pt60t70",
   "pt70t80","pt80t100","pt100t120","pt120t160","pt160t210","pt210t260","pt260t320",
   "pt320t400","pt400t500","pt500t670","pt670t1000"};
   std::string pt1[nptbin] = {"20","30","40","50","60","70","80",
   "100","120","160","210","260","320","400","500","670"};
   std::string pt2[nptbin] = {"30","40","50","60","70","80","100","120",
   "160","210","260","320","400","500","670","1000"};
   
   double sys_NTRK[nptbin];
   double sys_NJET[nptbin];
   double sys_MUPT[nptbin];
   double sys_JETA[nptbin];
   double sys_PU[nptbin];
   double sys_GSPLIT[nptbin];
   double sys_BFRAG[nptbin];
   double sys_CDFRAG[nptbin];
   double sys_CFRAG[nptbin];
   double sys_KSL[nptbin];
   double sys_NTRKGEN[nptbin];
   double STAT[nptbin];
   double TOTAL[nptbin];
   
   std::string type = "";
   std::string var = "";
   std::string sysname = "";
   std::string ptbin = "";
   std::string sys = "";
   std::string stat = "";
   while( !fsys.eof() )
     {
	if( fsys.eof() ) break;
	
	fsys >> type >> var >> sysname >> ptbin >> sys >> stat;
	if( type != jtype ) continue;
	
	int ib = -1;
	for(int i=0;i<nptbin;i++)
	  {
	     if( strcmp(ptbin.c_str(),ptbinname[i].c_str()) == 0 )
	       {
		  ib = i;
		  break;
	       }	     
	  }	
	
	if( ib < 0 ) continue;

	STAT[ib] = atof(stat.c_str());

	if( strcmp(sysname.c_str(),"_ntrk_low") == 0 )
	  sys_NTRK[ib] = atof(sys.c_str());
	if( strcmp(sysname.c_str(),"_njet_low") == 0 )
	  sys_NJET[ib] = atof(sys.c_str());
	if( strcmp(sysname.c_str(),"_mupt_low") == 0 )
	  sys_MUPT[ib] = atof(sys.c_str());
	if( strcmp(sysname.c_str(),"_jeta_low") == 0 )
	  sys_JETA[ib] = atof(sys.c_str());
	if( strcmp(sysname.c_str(),"_pu_low") == 0 )
	  sys_PU[ib] = atof(sys.c_str());
	if( strcmp(sysname.c_str(),"_gsplit_low") == 0 )
	  sys_GSPLIT[ib] = atof(sys.c_str());
	if( strcmp(sysname.c_str(),"_bfrag_low") == 0 )
	  sys_BFRAG[ib] = atof(sys.c_str());
	if( strcmp(sysname.c_str(),"_cdfrag_low") == 0 )
	  sys_CDFRAG[ib] = atof(sys.c_str());
	if( strcmp(sysname.c_str(),"_cfrag_low") == 0 )
	  sys_CFRAG[ib] = atof(sys.c_str());
	if( strcmp(sysname.c_str(),"_ksl_low") == 0 )
	  sys_KSL[ib] = atof(sys.c_str());
	if( strcmp(sysname.c_str(),"_ntrkgen_low") == 0 )
	  sys_NTRKGEN[ib] = atof(sys.c_str());
     }

   for(int i=0;i<nptbin;i++)
     {
	TOTAL[i] = sqrt(
			pow(STAT[i],2)+
			pow(sys_NTRK[i],2)+
			pow(sys_NJET[i],2)+
			pow(sys_MUPT[i],2)+
			pow(sys_JETA[i],2)+
			pow(sys_PU[i],2)+
			pow(sys_GSPLIT[i],2)+
			pow(sys_BFRAG[i],2)+
			pow(sys_CDFRAG[i],2)+
			pow(sys_CFRAG[i],2)+
			pow(sys_KSL[i],2)+
			pow(sys_NTRKGEN[i],2)
		       );
     }
   
   std::string tname1 = "results/table_sys_"+jtype+"_1.tex";
   std::string tname2 = "results/table_sys_"+jtype+"_2.tex";

   std::string tname1_full = "results/table_sys_"+jtype+"_full_1.tex";
   std::string tname2_full = "results/table_sys_"+jtype+"_full_2.tex";
   
   std::ofstream fout1(tname1.c_str());
   std::ofstream fout2(tname2.c_str());

   std::ofstream fout1_full(tname1_full.c_str());
   std::ofstream fout2_full(tname2_full.c_str());
   
   std::string header1 = "\\documentclass[a4paper]{article} \n
\\usepackage[english]{babel} \n
\\usepackage{graphicx} \n
\\usepackage{color} \n			   
\\begin{document}";

   std::string header2_1_full = "
\\begin{table}[hbt!] \n
\\small \n
\\begin{center} \n
\\resizebox{16cm}{!}{ \n
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|} \n
\\hline";

      std::string header2_2_full = "
\\begin{table}[hbt!] \n
\\small \n
\\begin{center} \n
\\resizebox{16cm}{!}{ \n
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|} \n
\\hline";

   std::string header2_1 = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|} \n
\\hline";

      std::string header2_2 = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|} \n
\\hline";
   
//   fout << header1 << std::endl;
   
   fout1 << header2_1 << std::endl;
   fout2 << header2_2 << std::endl;

   fout1_full << header1 << std::endl;
   fout2_full << header1 << std::endl;
   
   fout1_full << header2_1_full << std::endl;
   fout2_full << header2_2_full << std::endl;
   
   std::string linePT1 = "$P_{T}$ [GeV] & ";
   std::string linePT2 = "$P_{T}$ [GeV] & ";
   
   std::string lineSTAT1 = "MC statistics & ";
   std::string lineNTRK1 = "$N_{trk}$ & ";
   std::string lineNJET1 = "$N_{jet}$ & ";
   std::string lineMUPT1 = "$P_{T} (\\mu)$ & ";
   std::string lineJETA1 = "$\\eta (jet)$ & ";
   std::string linePU1 = "Pileup & ";
   std::string lineGSPLIT1 = "Gluon splitting & ";
   std::string lineBFRAG1 = "b fragmentation & ";
   std::string lineCDFRAG1 = "D\\to\\mu X & ";
   std::string lineCFRAG1 = "c fragmentation & ";
   std::string lineKSL1 = "$K_{S}^{0}$ (\\Lambda) & ";
   std::string lineNTRKGEN1 = "$N_{trk}^{gen}$ & ";
   std::string lineTOT1 = "Total & ";

   std::string lineSTAT2 = lineSTAT1;
   std::string lineNTRK2 = lineNTRK1;
   std::string lineNJET2 = lineNJET1;
   std::string lineMUPT2 = lineMUPT1;
   std::string lineJETA2 = lineJETA1;
   std::string linePU2 = linePU1;
   std::string lineGSPLIT2 = lineGSPLIT1;
   std::string lineBFRAG2 = lineBFRAG1;
   std::string lineCDFRAG2 = lineCDFRAG1;
   std::string lineCFRAG2 = lineCFRAG1;
   std::string lineKSL2 = lineKSL1;
   std::string lineNTRKGEN2 = lineNTRKGEN1;
   std::string lineTOT2 = lineTOT1;
   
   for(int j=0;j<nptbin;j++)
     {
	stringstream ss("");
	ss.precision(3);

	ss << fixed << pt1[j];
	std::string pt1Str = ss.str();
	ss.str("");
	ss << pt2[j];
	std::string pt2Str = ss.str();

	ss.str("");
	ss << STAT[j];
	std::string statStr = ss.str();

	ss.str("");
	ss << sys_NTRK[j];
	std::string ntrkStr = ss.str();

	ss.str("");
	ss << sys_NJET[j];
	std::string njetStr = ss.str();

	ss.str("");
	ss << sys_MUPT[j];
	std::string muptStr = ss.str();

	ss.str("");
	ss << sys_JETA[j];
	std::string jetaStr = ss.str();
	
	ss.str("");
	ss << sys_PU[j];
	std::string puStr = ss.str();

	ss.str("");
	ss << sys_GSPLIT[j];
	std::string gsplitStr = ss.str();

	ss.str("");
	ss << sys_BFRAG[j];
	std::string bfragStr = ss.str();

	ss.str("");
	ss << sys_CDFRAG[j];
	std::string cdfragStr = ss.str();

	ss.str("");
	ss << sys_CFRAG[j];
	std::string cfragStr = ss.str();

	ss.str("");
	ss << sys_KSL[j];
	std::string kslStr = ss.str();

	ss.str("");
	ss << sys_NTRKGEN[j];
	std::string ntrkgenStr = ss.str();
	
	ss.str("");
	ss << TOTAL[j];
	std::string totStr = ss.str();
	
	std::string linePT_cur = pt1Str + " - " + pt2Str;
	std::string lineSTAT_cur = statStr;
	std::string lineNTRK_cur = ntrkStr;
	std::string lineNJET_cur = njetStr;
	std::string lineMUPT_cur = muptStr;
	std::string lineJETA_cur = jetaStr;
	std::string linePU_cur = puStr;
	std::string lineGSPLIT_cur = gsplitStr;
	std::string lineBFRAG_cur = bfragStr;
	std::string lineCDFRAG_cur = cdfragStr;
	std::string lineCFRAG_cur = cfragStr;
	std::string lineKSL_cur = kslStr;
	std::string lineNTRKGEN_cur = ntrkgenStr;
	std::string lineTOT_cur = totStr;

	if( j <= nptbin/2-1 )
	  {
	     linePT1 += linePT_cur;	
	     lineSTAT1 += lineSTAT_cur;
	     lineNTRK1 += lineNTRK_cur;
	     lineNJET1 += lineNJET_cur;
	     lineMUPT1 += lineMUPT_cur;
	     lineJETA1 += lineJETA_cur;
	     linePU1 += linePU_cur;
	     lineGSPLIT1 += lineGSPLIT_cur;
	     lineBFRAG1 += lineBFRAG_cur;
	     lineCDFRAG1 += lineCDFRAG_cur;
	     lineCFRAG1 += lineCFRAG_cur;
	     lineKSL1 += lineKSL_cur;
	     lineNTRKGEN1 += lineNTRKGEN_cur;
	     lineTOT1 += lineTOT_cur;
	  }
	else
	  {
	     linePT2 += linePT_cur;	
	     lineSTAT2 += lineSTAT_cur;
	     lineNTRK2 += lineNTRK_cur;
	     lineNJET2 += lineNJET_cur;
	     lineMUPT2 += lineMUPT_cur;
	     lineJETA2 += lineJETA_cur;
	     linePU2 += linePU_cur;
	     lineGSPLIT2 += lineGSPLIT_cur;
	     lineBFRAG2 += lineBFRAG_cur;
	     lineCDFRAG2 += lineCDFRAG_cur;
	     lineCFRAG2 += lineCFRAG_cur;
	     lineKSL2 += lineKSL_cur;
	     lineNTRKGEN2 += lineNTRKGEN_cur;
	     lineTOT2 += lineTOT_cur;
	  }	
	
	if( j != nptbin-1 )
	  {
	     if( j < nptbin/2-1 )
	       {
		  linePT1 += " & ";
		  lineSTAT1 += " & ";
		  lineNTRK1 += " & ";
		  lineNJET1 += " & ";
		  lineMUPT1 += " & ";
		  lineJETA1 += " & ";
		  linePU1 += " & ";
		  lineGSPLIT1 += " & ";
		  lineBFRAG1 += " & ";
		  lineCDFRAG1 += " & ";
		  lineCFRAG1 += " & ";
		  lineKSL1 += " & ";
		  lineNTRKGEN1 += " & ";
		  lineTOT1 += " & ";
	       }
	     
	     if( j > nptbin/2-1 )
	       {
		  linePT2 += " & ";	     
		  lineSTAT2 += " & ";
		  lineNTRK2 += " & ";
		  lineNJET2 += " & ";
		  lineMUPT2 += " & ";
		  lineJETA2 += " & ";
		  linePU2 += " & ";
		  lineGSPLIT2 += " & ";
		  lineBFRAG2 += " & ";
		  lineCDFRAG2 += " & ";
		  lineCFRAG2 += " & ";
		  lineKSL2 += " & ";
		  lineNTRKGEN2 += " & ";
		  lineTOT2 += " & ";
	       }	     
	  }	
     }   
  
   std::string endLine = "\\\\";
   
   linePT1 += endLine;   
   lineSTAT1 += endLine;
   lineNTRK1 += endLine;
   lineNJET1 += endLine;
   lineMUPT1 += endLine;
   lineJETA1 += endLine;
   linePU1 += endLine;
   lineGSPLIT1 += endLine;
   lineBFRAG1 += endLine;
   lineCDFRAG1 += endLine;
   lineCFRAG1 += endLine;
   lineKSL1 += endLine;
   lineNTRKGEN1 += endLine;
   lineTOT1 += endLine;

   linePT2 += endLine;
   lineSTAT2 += endLine;
   lineNTRK2 += endLine;
   lineNJET2 += endLine;
   lineMUPT2 += endLine;
   lineJETA2 += endLine;
   linePU2 += endLine;
   lineGSPLIT2 += endLine;
   lineBFRAG2 += endLine;
   lineCDFRAG2 += endLine;
   lineCFRAG2 += endLine;
   lineKSL2 += endLine;
   lineNTRKGEN2 += endLine;
   lineTOT2 += endLine;

   linePT1 += "\n 
\\hline";
   linePT2 += "\n 
\\hline";

   // change to last sys
   if( jtype == "bjet" )
     {	
	lineNTRKGEN1 += "\n
\\hline";
	lineNTRKGEN2 += "\n 
\\hline";
     }
   if( jtype == "cjet" )
     {	
	lineNTRKGEN1 += "\n
\\hline";
	lineNTRKGEN2 += "\n 
\\hline";
     }
   if( jtype == "ljet" )
     {	
	lineKSL1 += "\n
\\hline";
	lineKSL2 += "\n 
\\hline";
     }
   
   
   fout1 << linePT1 << std::endl;
   fout1 << lineSTAT1 << std::endl;
   fout1 << lineNTRK1 << std::endl;
   fout1 << lineNJET1 << std::endl;
   fout1 << lineMUPT1 << std::endl;
   fout1 << lineJETA1 << std::endl;
   fout1 << linePU1 << std::endl;
   if( jtype == "bjet" || jtype == "cjet" ) fout1 << lineGSPLIT1 << std::endl;
   if( jtype == "bjet" ) fout1 << lineBFRAG1 << std::endl;
   if( jtype == "bjet" || jtype == "cjet" ) fout1 << lineCDFRAG1 << std::endl;
   if( jtype == "cjet" ) fout1 << lineCFRAG1 << std::endl;
   if( jtype == "ljet" ) fout1 << lineKSL1 << std::endl;
   if( jtype == "bjet" || jtype == "cjet" ) fout1 << lineNTRKGEN1 << std::endl;
   fout1 << lineTOT1 << std::endl;

   fout2 << linePT2 << std::endl;
   fout2 << lineSTAT2 << std::endl;
   fout2 << lineNTRK2 << std::endl;
   fout2 << lineNJET2 << std::endl;
   fout2 << lineMUPT2 << std::endl;
   fout2 << lineJETA2 << std::endl;
   fout2 << linePU2 << std::endl;
   if( jtype == "bjet" || jtype == "cjet" ) fout2 << lineGSPLIT2 << std::endl;
   if( jtype == "bjet" ) fout2 << lineBFRAG2 << std::endl;
   if( jtype == "bjet" || jtype == "cjet" ) fout2 << lineCDFRAG2 << std::endl;
   if( jtype == "cjet" ) fout2 << lineCFRAG2 << std::endl;
   if( jtype == "ljet" ) fout2 << lineKSL2 << std::endl;
   if( jtype == "bjet" || jtype == "cjet" ) fout1 << lineNTRKGEN2 << std::endl;
   fout2 << lineTOT2 << std::endl;

   fout1_full << linePT1 << std::endl;
   fout1_full << lineSTAT1 << std::endl;
   fout1_full << lineNTRK1 << std::endl;
   fout1_full << lineNJET1 << std::endl;
   fout1_full << lineMUPT1 << std::endl;
   fout1_full << lineJETA1 << std::endl;
   fout1_full << linePU1 << std::endl;
   if( jtype == "bjet" || jtype == "cjet" ) fout1_full << lineGSPLIT1 << std::endl;
   if( jtype == "bjet" ) fout1_full << lineBFRAG1 << std::endl;
   if( jtype == "bjet" || jtype == "cjet" ) fout1_full << lineCDFRAG1 << std::endl;
   if( jtype == "cjet" ) fout1_full << lineCFRAG1 << std::endl;
   if( jtype == "ljet" ) fout1_full << lineKSL1 << std::endl;
   if( jtype == "bjet" || jtype == "cjet" ) fout1_full << lineNTRKGEN1 << std::endl;
   fout1_full << lineTOT1 << std::endl;

   fout2_full << linePT2 << std::endl;
   fout2_full << lineSTAT2 << std::endl;
   fout2_full << lineNTRK2 << std::endl;
   fout2_full << lineNJET2 << std::endl;
   fout2_full << lineMUPT2 << std::endl;
   fout2_full << lineJETA2 << std::endl;
   fout2_full << linePU2 << std::endl;
   if( jtype == "bjet" || jtype == "cjet" ) fout2_full << lineGSPLIT2 << std::endl;
   if( jtype == "bjet" ) fout2_full << lineBFRAG2 << std::endl;
   if( jtype == "bjet" || jtype == "cjet" ) fout2_full << lineCDFRAG2 << std::endl;
   if( jtype == "cjet" ) fout2_full << lineCFRAG2 << std::endl;
   if( jtype == "ljet" ) fout2_full << lineKSL2 << std::endl;
   if( jtype == "bjet" || jtype == "cjet" ) fout2_full << lineNTRKGEN2 << std::endl;
   fout2_full << lineTOT2 << std::endl;
   
   std::string footer1_full = "\\hline \n
\\end{tabular} \n
} \n
\\end{center} \n
\\end{table}";

   std::string footer1 = "\\hline \n
\\end{tabular}";
   
   std::string footer2 = "
\\end{document}";
   
   fout1 << footer1 << std::endl;
   fout2 << footer1 << std::endl;

   fout1_full << footer1_full << std::endl;
   fout2_full << footer1_full << std::endl;
   
   fout1_full << footer2 << std::endl;
   fout2_full << footer2 << std::endl;
   
   fout1.close();
   fout2.close();

   fout1_full.close();
   fout2_full.close();
   
   gApplication->Terminate();
}
