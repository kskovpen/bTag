TFile *fbatchMC[100];

std::string ver = "histMJ_2D/";
std::string flav = "ljet";

std::string fpathMC = "/opt/sbg/cms/ui5_data1/kskovpen/bTag/CMSSW_5_3_11/src/sysAna/run/"+ver;

const int nhist = 1;
std::string hist[nhist] = 
  {
     "JP_vs_CSV"
//     "JP_vs_pt",
//     "JP_vs_mupt"
  };
const int nptbin = 17;
std::string ptbin[nptbin] = {"pt20t30",
"pt30t40","pt40t50","pt50t60","pt60t70",
"pt70t80","pt80t100","pt100t120",
"pt120t160","pt160t210","pt210t260",
"pt260t320","pt320t400","pt400t500",
"pt500t600","pt600t800","pt800t1000"};
std::string ptval[nptbin+1] = 
{"20","30","40","50","60","70",
 "80","100","120","160","210",
 "260","320","400","500","600",
   "800","1000"
};
std::string titX[nhist] =
{
   "CSV weight"
//   "P_{T} (jet) / P_{T}^{bin} ",
//   "P_{T} (#mu) [GeV]"
};
std::string titY[nhist] =
{
   "Jet probability"
//   "Jet probability",
//   "Jet probability"
};

std::string tag = "nosel";
int nbm2d = 1;

void corr2D()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine("#include <string>");
   gROOT->ProcessLine("#include <TH1D.h>");
   
   gROOT->ProcessLine(".x common.C");
   gROOT->ProcessLine(".x def.C");
   
   gROOT->ProcessLine(".L addbin2D.C");

   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   
   gStyle->SetHistTopMargin(0);

   std::string header1 = "\\documentclass[a4paper]{article} \n
\\usepackage[english]{babel} \n
\\usepackage{graphicx} \n
\\usepackage{color} \n			   
\\begin{document}";

//   std::string header2 = "
//\\resizebox{16cm}{!}{ \n
//\\begin{tabular}{|c|c|c|c|c|c|c|c|c|} \n
//\\hline";

//   std::string header2_2 = "
//\\resizebox{16cm}{!}{ \n
//\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|} \n
//\\hline";

   std::string header2 = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|} \n
\\hline";

   std::string header2_2 = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|} \n
\\hline";
   
   std::string footer1 = "\\hline \n
\\end{tabular} \n
\n";

//   std::string footer1 = "\\hline \n
//\\end{tabular} \n
//} \n";
   
   std::string footer2 = "
\\end{document}";
   
   TH2D *h_bjet;
   
   for(int ih=0;ih<nhist;ih++)
     {		
	std::string fsave1 = "results/corr2D/table_"+flav+"_"+hist[ih]+"_1.tex";
	std::string fsave2 = "results/corr2D/table_"+flav+"_"+hist[ih]+"_2.tex";
	std::ofstream fout1(fsave1.c_str());
	std::ofstream fout2(fsave2.c_str());
	     
	std::string linePT = "$P_{T}$ [GeV] & ";
	std::string linePT_1 = linePT;
	std::string linePT_2 = linePT;
	
	std::string lineFC = "$f_{C}$ & ";
	std::string lineFC_1 = lineFC;
	std::string lineFC_2 = lineFC;
	
	for(int ipt=0;ipt<nptbin;ipt++)
	  {
	     std::string varh_bjet = "h_j1_"+hist[ih]+"_"+flav+"_"+ptbin[ipt]+"_nosel_"+tag;
	     std::string PT = ptval[ipt] + " - " + ptval[ipt+1];

	     for(int i=0;i<v_mc_filt.size();i++)
	       {
		  std::string fname = fpathMC+v_mc_filt.at(i);
		  fbatchMC[i] = TFile::Open(fname.c_str());
		  
		  TH2D *hf_bjet = (TH2D*)fbatchMC[i]->Get(varh_bjet.c_str());
		  if( i == 0 ) 
		    {
		       h_bjet = (TH2D*)hf_bjet->Clone("h_bjet");
		    }	
		  else 
		    {
		       h_bjet->Add(hf_bjet);
		    }
	       }
	     
	     addbin2D(h_bjet);
	     
	     h_bjet = (TH2D*)h_bjet->Rebin2D(nbm2d,nbm2d,"");

	     float corrF = h_bjet->GetCorrelationFactor();
	     float covM = h_bjet->GetCovariance();
	     
	     h_bjet->Draw("BOX");
	     
	     h_bjet->GetXaxis()->SetTitle(titX[ih].c_str());
	     h_bjet->GetYaxis()->SetTitle(titY[ih].c_str());
	     
	     std::string fsave = "pics/"+flav+"_"+varh_bjet+".eps";
	     c1->Print(fsave.c_str());
	     
	     std::string PT = ptval[ipt] + " - " + ptval[ipt+1];
	     std::string FC = TString(Form("%.2f",corrF));
	     
	     if( ipt < nptbin/2 )
	       {		       
		  linePT_1 += PT;
		  lineFC_1 += FC;
	       }
	     else
	       {
		  linePT_2 += PT;
		  lineFC_2 += FC;
	       }	
	     
	     if( ipt < nptbin/2-1 )
	       {
		  linePT_1 += " & ";
		  lineFC_1 += " & ";
	       }

	     if( ipt >= nptbin/2 && ipt != nptbin-1 )
	       {
		  linePT_2 += " & ";
		  lineFC_2 += " & ";
	       }		  		  

	     for(int i=0;i<v_mc_filt.size();i++)
	       {
		  fbatchMC[i]->Close();
	       }
	  }
	
	linePT_1 += " \\\\ \\hline \\hline ";
	linePT_2 += " \\\\ \\hline \\hline ";
	
	lineFC_1 += " \\\\ ";
	lineFC_2 += " \\\\ ";
	
//	fout1 << header1 << std::endl;
	fout1 << header2 << std::endl;
	fout1 << linePT_1 << std::endl;
	fout1 << lineFC_1 << std::endl;
	fout1 << footer1 << std::endl;
//	fout1 << footer2 << std::endl;
	
//	fout2 << header1 << std::endl;
	fout2 << header2_2 << std::endl;
	fout2 << linePT_2 << std::endl;
	fout2 << lineFC_2 << std::endl;
	fout2 << footer1 << std::endl;
//	fout2 << footer2 << std::endl;
	
	fout1.close();
	fout2.close();
     }   
   
   gApplication->Terminate();
}
