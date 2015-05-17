void makeFitTableSFOVERLAY()
{
   gROOT->SetBatch();

   std::string sel = "MV180";

   std::string fo = "results/fit_EFF_beauty_SFOVERLAY_"+sel+".root";
   TFile *f = TFile::Open(fo.c_str());

   TH1F *h1c = (TH1F*)f->Get("h1c");
   TH1F *hsf0 = (TH1F*)f->Get("hsf0");
   TH1F *hsf1 = (TH1F*)f->Get("hsf1");
   TH1F *hsf2 = (TH1F*)f->Get("hsf2");
   TH1F *hsf3 = (TH1F*)f->Get("hsf3");
   
   int nbins = h1c->GetXaxis()->GetNbins();

   std::string tname1 = "results/table_SFOVERLAY_bjet_"+sel+"_1.tex";
   std::string tname2 = "results/table_SFOVERLAY_bjet_"+sel+"_2.tex";

   std::ofstream fout1(tname1.c_str());
   std::ofstream fout2(tname2.c_str());

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
\\begin{tabular}{|c|c|c|c|c|c|c|c|} \n
\\hline";

      std::string header2_2_full = "
\\begin{table}[hbt!] \n
\\small \n
\\begin{center} \n
\\resizebox{16cm}{!}{ \n
\\begin{tabular}{|c|c|c|c|c|c|c|c|} \n
\\hline";

   std::string header2_1 = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|} \n
\\hline";

      std::string header2_2 = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|} \n
\\hline";

   fout1 << header2_1 << std::endl;
   fout2 << header2_2 << std::endl;
   
   std::string linePT1 = "$P_{T}$ [GeV] & ";
   std::string linePT2 = "$P_{T}$ [GeV] & ";
   
   std::string lineSF0 = "SF ($t_{1}$) & ";
   std::string lineSF1 = "SF ($t_{2}$) & ";
   std::string lineSF2 = "SF ($t_{3}$) & ";
   std::string lineSF3 = "SF ($\\mu$) & ";
//   std::string lineSFC = "SF (comb) & ";

   std::string lineSF0_2 = lineSF0;
   std::string lineSF1_2 = lineSF1;
   std::string lineSF2_2 = lineSF2;
   std::string lineSF3_2 = lineSF3;
//   std::string lineSFC_2 = lineSFC;
   
   for(int j=1;j<nbins+1;j++)
     {
	double pt1 = h1c->GetXaxis()->GetBinLowEdge(j);
	double pt2 = h1c->GetXaxis()->GetBinUpEdge(j);
//	double sfComb = h1c->GetBinContent(j);
//	double sfCombErr = h1c->GetBinError(j);
	double sf0 = hsf0->GetBinContent(j);
	double sf0Err = hsf0->GetBinError(j);
	double sf1 = hsf1->GetBinContent(j);
	double sf1Err = hsf1->GetBinError(j);
	double sf2 = hsf2->GetBinContent(j);
	double sf2Err = hsf2->GetBinError(j);
	double sf3 = hsf3->GetBinContent(j);
	double sf3Err = hsf3->GetBinError(j);
   
	stringstream ss("");
	ss.precision(0);

	ss << fixed << pt1*1000.;
	std::string pt1Str = ss.str();
	ss.str("");
	ss << pt2*1000.;
	std::string pt2Str = ss.str();

	ss.precision(3);
	
//	ss.str("");
//	ss << sfComb;
//	std::string sfCombStr = ss.str();
//	ss.str("");
//	ss << sfCombErr;
//	std::string sfCombErrStr = ss.str();

	ss.str("");
	ss << sf0;
	std::string sf0Str = ss.str();
	ss.str("");
	ss << sf0Err;
	std::string sf0ErrStr = ss.str();
	
	ss.str("");
	ss << sf1;
	std::string sf1Str = ss.str();
	ss.str("");
	ss << sf1Err;
	std::string sf1ErrStr = ss.str();

	ss.str("");
	ss << sf2;
	std::string sf2Str = ss.str();
	ss.str("");
	ss << sf2Err;
	std::string sf2ErrStr = ss.str();

	ss.str("");
	ss << sf3;
	std::string sf3Str = ss.str();
	ss.str("");
	ss << sf3Err;
	std::string sf3ErrStr = ss.str();
	
	std::string linePT_cur = pt1Str + " - " + pt2Str;
	std::string lineSF0_cur = sf0Str + " $\\pm$ " + sf0ErrStr;
	std::string lineSF1_cur = sf1Str + " $\\pm$ " + sf1ErrStr;
	std::string lineSF2_cur = sf2Str + " $\\pm$ " + sf2ErrStr;
	std::string lineSF3_cur = sf3Str + " $\\pm$ " + sf3ErrStr;
//	std::string lineSFComb_cur = sfCombStr + " $\\pm$ " + sfCombErrStr;

	if( j <= nbins/2 )
	  {
	     linePT1 += linePT_cur;
	     lineSF0 += lineSF0_cur;
	     lineSF1 += lineSF1_cur;
	     lineSF2 += lineSF2_cur;
	     lineSF3 += lineSF3_cur;
//	     lineSFC += lineSFComb_cur;
	  }
	else
	  {
	     linePT2 += linePT_cur;	
	     lineSF0_2 += lineSF0_cur;
	     lineSF1_2 += lineSF1_cur;
	     lineSF2_2 += lineSF2_cur;
	     lineSF3_2 += lineSF3_cur;
//	     lineSFC_2 += lineSFComb_cur;
	  }	
	
	if( j != nbins )
	  {
	     if( j < nbins/2 )
	       {
		  linePT1 += " & ";
		  lineSF0 += " & ";
		  lineSF1 += " & ";
		  lineSF2 += " & ";
		  lineSF3 += " & ";
//		  lineSFC += " & ";
	       }

	     if( j > nbins/2 )
	       {
		  linePT2 += " & ";	     
		  lineSF0_2 += " & ";
		  lineSF1_2 += " & ";
		  lineSF2_2 += " & ";
		  lineSF3_2 += " & ";
//		  lineSFC_2 += " & ";
	       }	     
	  }	
     }   
  
   std::string endLine = "\\\\";
   
   linePT1 += endLine;
   lineSF0 += endLine;
   lineSF1 += endLine;
   lineSF2 += endLine;
   lineSF3 += endLine;
//   lineSFC += endLine;

   linePT2 += endLine;
   lineSF0_2 += endLine;
   lineSF1_2 += endLine;
   lineSF2_2 += endLine;
   lineSF3_2 += endLine;
//   lineSFC_2 += endLine;

   linePT1 += "\n 
\\hline";
   linePT2 += "\n 
\\hline";

//   lineSF3 += "\n
//\\hline";
//   lineSF3_2 += "\n 
//\\hline";
   
   fout1 << linePT1 << std::endl;
   fout1 << lineSF0 << std::endl;
   fout1 << lineSF1 << std::endl;
   fout1 << lineSF2 << std::endl;
   fout1 << lineSF3 << std::endl;
//   fout1 << lineSFC << std::endl;

   fout2 << linePT2 << std::endl;
   fout2 << lineSF0_2 << std::endl;
   fout2 << lineSF1_2 << std::endl;
   fout2 << lineSF2_2 << std::endl;
   fout2 << lineSF3_2 << std::endl;
//   fout2 << lineSFC_2 << std::endl;
   
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
   
   fout1.close();
   fout2.close();

   gApplication->Terminate();
}
