TFile *fbatchMC[100];

std::string toolMC = "plot_PROC2_v2";
std::string fpathMC = "/gcf/atlas/data/JTNtuple_hist/run_"+toolMC+"/";

const int nhist = 1;
std::string hist[nhist] = 
  {
//     "d0SignJetMuon_vs_MV1"
     "d0SignJet1_vs_d0SignJet2"
  };
const int nptbin = 14;
std::string ptbin[nptbin] = {"pt20t30",
"pt30t40","pt40t50","pt50t60","pt60t75",
"pt75t90","pt90t110","pt110t140",
"pt140t200","pt200t300","pt300t400",
"pt400t500","pt500t700","pt700t1000"};
std::string ptval[nptbin+1] = 
{"20","30","40","50","60","75",
 "90","110","140","200","300",
 "400","500","700","1000"
};
std::string titX[nhist] =
{
//   "MV1 tag weight"
   "S_{d_{0}}(t_{1})"
};
std::string titY[nhist] =
{
//   "S_{d_{0}}(t_{1})"
   "S_{d_{0}}(t_{2})"
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

   std::string header2 = "
\\begin{tabular}{|c|c|c|c|c|c|c|c|} \n
\\hline";

   std::string footer1 = "\\hline \n
\\end{tabular}";

   std::string footer2 = "
\\end{document}";
   
   TH2D *h_bjet;

   for(int ih=0;ih<nhist;ih++)
     {	
	std::string fsave1 = "results/corr2D/table_"+hist[ih]+"_1.tex";
	std::string fsave2 = "results/corr2D/table_"+hist[ih]+"_2.tex";
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
	     std::string varh_bjet = "h_j1_"+hist[ih]+"_bjet_"+ptbin[ipt]+"_nosel_"+tag;
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
	     
	     std::string fsave = "pics/"+varh_bjet+".eps";
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
	fout2 << header2 << std::endl;
	fout2 << linePT_2 << std::endl;
	fout2 << lineFC_2 << std::endl;
	fout2 << footer1 << std::endl;
//	fout2 << footer2 << std::endl;
	
	fout1.close();
	fout2.close();
     }   
   
   gApplication->Terminate();
}
