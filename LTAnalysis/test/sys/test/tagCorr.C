TFile *fbatchMC[100];
TFile *fbatchDATA[100];

std::string toolMC = "plot_WITHPURW_MC_CORR";
std::string toolDATA = "plot_PROC_DATA_CORR";
std::string fpathMC = "/gcf/atlas/data/JTNtuple_hist/run_"+toolMC+"/";
std::string fpathDATA = "/gcf/atlas/data/JTNtuple_hist/run_"+toolDATA+"/";

bool ljetFromDATA = true;

const int nhist = 9;
std::string hist[nhist] = 
  {
     "d0SignJet1_vs_MV1",
     "d0SignJet1_vs_JetFitterCOMBNN",
     "d0SignJet1_vs_IP3DSV1",
     "d0SignJetMuonTight_vs_MV1",
     "d0SignJetMuonTight_vs_JetFitterCOMBNN",
     "d0SignJetMuonTight_vs_IP3DSV1",
     "muonTightPtRel_vs_MV1",
     "muonTightPtRel_vs_JetFitterCOMBNN",
     "muonTightPtRel_vs_IP3DSV1"
  };
const int nptbin = 12;
std::string ptbin[nptbin] = {"pt20t30",
"pt30t40","pt40t50","pt50t60","pt60t75",
"pt75t90","pt90t110","pt110t140",
"pt140t200","pt200t260","pt260t340",
"pt340t500"};
std::string ptval[nptbin+1] = 
{"20","30","40","50","60","75",
 "90","110","140","200","260",
 "340","500"
};
//std::string tag = "nosel";
//std::string tag = "mv1c0p985";
std::string tag = "UNTAGbc";
int nbm2d = 3;

void tagCorr()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine("#include <string>");
   gROOT->ProcessLine("#include <TH1F.h>");
   
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
\\begin{table}[hbt!] \n
\\small \n
\\begin{center} \n
\\resizebox{16cm}{!}{ \n
\\begin{tabular}{|c|c|c|c|c|c|c|} \n
\\hline";

   std::string footer1 = "\\hline \n
\\end{tabular} \n
} \n
\\end{center} \n
\\end{table}";

   std::string footer2 = "
\\end{document}";
   
   TH2F *h_ajet;
   TH2F *h_ljet;
   TH2F *h_bjet;
   TH2F *h_cjet;

   for(int ih=0;ih<nhist;ih++)
     {	
	std::string fsave1 = "results/tagCorr/table_"+hist[ih]+"_1.tex";
	std::string fsave2 = "results/tagCorr/table_"+hist[ih]+"_2.tex";
	std::ofstream fout1(fsave1.c_str());
	std::ofstream fout2(fsave2.c_str());
	     
	std::string linePT = "$P_{T}$ [GeV] & ";
	std::string linePT_1 = linePT;
	std::string linePT_2 = linePT;
	
	std::string lineFC = "$f_{C}$ & ";
	std::string lineFC_1 = lineFC;
	std::string lineFC_2 = lineFC;

	std::string lineNDATA = "$N_{Data}$ & ";
	std::string lineNDATA_1 = lineNDATA;
	std::string lineNDATA_2 = lineNDATA;

	std::string lineNHEAVY = "$N_{MC}^{B+C}$ & ";
	std::string lineNHEAVY_1 = lineNHEAVY;
	std::string lineNHEAVY_2 = lineNHEAVY;

	std::string lineRATIO = "$N_{MC}^{B+C}$/$N_{Data}$ & ";
	std::string lineRATIO_1 = lineRATIO;
	std::string lineRATIO_2 = lineRATIO;
	
	for(int ipt=0;ipt<nptbin;ipt++)
	  {
	     std::string varh = "h_j1_"+hist[ih]+"_"+ptbin[ipt]+"_nosel_"+tag;
	     std::string varh_ajet = "h_j1_"+hist[ih]+"_ajet_"+ptbin[ipt]+"_nosel_"+tag;
	     std::string varh_ljet = "h_j1_"+hist[ih]+"_ljet_"+ptbin[ipt]+"_nosel_"+tag;
	     std::string varh_bjet = "h_j1_"+hist[ih]+"_bjet_"+ptbin[ipt]+"_nosel_"+tag;
	     std::string varh_cjet = "h_j1_"+hist[ih]+"_cjet_"+ptbin[ipt]+"_nosel_"+tag;
	     std::string PT = ptval[ipt] + " - " + ptval[ipt+1];

	     for(int i=0;i<v_mc_filt.size();i++)
	       {
		  std::string fname = fpathMC+v_mc_filt.at(i);
		  fbatchMC[i] = TFile::Open(fname.c_str());
		  
		  TH2F *hf_ljet = (TH2F*)fbatchMC[i]->Get(varh_ljet.c_str());
		  TH2F *hf_bjet = (TH2F*)fbatchMC[i]->Get(varh_bjet.c_str());
		  TH2F *hf_cjet = (TH2F*)fbatchMC[i]->Get(varh_cjet.c_str());
		  if( i == 0 ) 
		    {
		       h_ljet = (TH2F*)hf_ljet->Clone("h_ljet");
		       h_bjet = (TH2F*)hf_bjet->Clone("h_bjet");
		       h_cjet = (TH2F*)hf_cjet->Clone("h_cjet");
		    }	
		  else 
		    {
		       h_ljet->Add(hf_ljet);
		       h_bjet->Add(hf_bjet);
		       h_cjet->Add(hf_cjet);
		    }
	       }
	     
	     for(int i=0;i<v_data.size();i++)
	       {
		  std::string fname = fpathDATA+v_data.at(i);
		  fbatchDATA[i] = TFile::Open(fname.c_str());
		  
		  TH2F *hf_ajet = (TH2F*)fbatchDATA[i]->Get(varh_ajet.c_str());
		  if( i == 0 ) 
		    {
		       h_ajet = (TH2F*)hf_ajet->Clone("h_ajet");
		    }	
		  else 
		    {
		       h_ajet->Add(hf_ajet);
		    }		  
	       }	     
	     
	     addbin2D(h_ajet);
	     addbin2D(h_ljet);
	     addbin2D(h_bjet);
	     addbin2D(h_cjet);
	     
	     h_ajet = (TH2F*)h_ajet->Rebin2D(nbm2d,nbm2d,"");
	     h_ljet = (TH2F*)h_ljet->Rebin2D(nbm2d,nbm2d,"");
	     h_bjet = (TH2F*)h_bjet->Rebin2D(nbm2d,nbm2d,"");
	     h_cjet = (TH2F*)h_cjet->Rebin2D(nbm2d,nbm2d,"");

	     double ndata_err = 0.;
	     double ndata = h_ajet->IntegralAndError(0,h_ajet->GetXaxis()->GetNbins()+1,
						     0,h_ajet->GetYaxis()->GetNbins()+1,
						     ndata_err);

	     double nljet_err = 0.;
	     double nljet = h_ljet->IntegralAndError(0,h_ljet->GetXaxis()->GetNbins()+1,
						     0,h_ljet->GetYaxis()->GetNbins()+1,
						     nljet_err);
	     
	     double nbjet_err = 0.;
	     double nbjet = h_bjet->IntegralAndError(0,h_bjet->GetXaxis()->GetNbins()+1,
						     0,h_bjet->GetYaxis()->GetNbins()+1,
						     nbjet_err);

	     double ncjet_err = 0.;
	     double ncjet = h_cjet->IntegralAndError(0,h_cjet->GetXaxis()->GetNbins()+1,
						     0,h_cjet->GetYaxis()->GetNbins()+1,
						     ncjet_err);
	     
	     TH2F *h = NULL;

	     h_ajet->Add(h_bjet,-1.);
	     h_ajet->Add(h_cjet,-1.);
	     
	     if( ljetFromDATA )
	       h = h_ajet;
	     else
	       h = h_ljet;
	     
	     float corrF = h->GetCorrelationFactor();
	     float covM = h->GetCovariance();
	     
	     h->Draw("BOX");
	     
	     std::string fsave = "pics/"+varh+".eps";
	     c1->Print(fsave.c_str());
	     
	     std::string PT = ptval[ipt] + " - " + ptval[ipt+1];
	     std::string FC = TString(Form("%.2f",corrF));
	     
	     double nheavy = nbjet + ncjet;
	     double nheavy_err = sqrt(pow(nbjet_err,2) + pow(ncjet_err,2));
	     
	     std::string NDATA = TString(Form("%.0f",ndata))+"\\pm"+TString(Form("%.1f",ndata_err));
	     std::string NHEAVY = TString(Form("%.1f",nheavy))+"\\pm"+TString(Form("%.1f",nheavy_err));
	     
	     double ratio = ( ndata > 0. ) ? nheavy/ndata : 0.;
	     double ratio_err = sqrt(pow(nheavy/ndata/ndata*ndata_err,2) + pow(nheavy_err/ndata,2));
	     
	     std::string RATIO = TString(Form("%.3f",ratio))+"\\pm"+TString(Form("%.3f",ratio_err));
	     
	     if( ipt < nptbin/2 )
	       {		       
		  linePT_1 += PT;
		  lineFC_1 += FC;
		  lineNDATA_1 += NDATA;
		  lineNHEAVY_1 += NHEAVY;
		  lineRATIO_1 += RATIO;
	       }
	     else
	       {
		  linePT_2 += PT;
		  lineFC_2 += FC;
		  lineNDATA_2 += NDATA;
		  lineNHEAVY_2 += NHEAVY;
		  lineRATIO_2 += RATIO;
	       }	
	     
	     if( ipt < nptbin/2-1 )
	       {
		  linePT_1 += " & ";
		  lineFC_1 += " & ";
		  lineNDATA_1 += " & ";
		  lineNHEAVY_1 += " & ";
		  lineRATIO_1 += " & ";
	       }
		  
	     if( ipt >= nptbin/2 && ipt != nptbin-1 )
	       {
		  linePT_2 += " & ";
		  lineFC_2 += " & ";
		  lineNDATA_2 += " & ";
		  lineNHEAVY_2 += " & ";
		  lineRATIO_2 += " & ";
	       }		  		  

	     for(int i=0;i<v_mc_filt.size();i++)
	       {
		  fbatchMC[i]->Close();
	       }

	     for(int i=0;i<v_data.size();i++)
	       {
		  fbatchDATA[i]->Close();
	       }		  
	  }
	
	linePT_1 += " \\\\ \\hline \\hline ";
	linePT_2 += " \\\\ \\hline \\hline ";
	
	lineFC_1 += " \\\\ ";
	lineFC_2 += " \\\\ ";

	lineNDATA_1 += " \\\\ ";
	lineNDATA_2 += " \\\\ ";

	lineNHEAVY_1 += " \\\\ ";
	lineNHEAVY_2 += " \\\\ ";

	lineRATIO_1 += " \\\\ ";
	lineRATIO_2 += " \\\\ ";
	
	fout1 << header1 << std::endl;
	fout1 << header2 << std::endl;
	fout1 << linePT_1 << std::endl;
	fout1 << lineFC_1 << std::endl;
//	fout1 << lineNDATA_1 << std::endl;
//	fout1 << lineNHEAVY_1 << std::endl;
//	fout1 << lineRATIO_1 << std::endl;
	fout1 << footer1 << std::endl;
	fout1 << footer2 << std::endl;
	
	fout2 << header1 << std::endl;
	fout2 << header2 << std::endl;
	fout2 << linePT_2 << std::endl;
	fout2 << lineFC_2 << std::endl;
//	fout2 << lineNDATA_2 << std::endl;
//	fout2 << lineNHEAVY_2 << std::endl;
//	fout2 << lineRATIO_2 << std::endl;
	fout2 << footer1 << std::endl;
	fout2 << footer2 << std::endl;
	
	fout1.close();
	fout2.close();
     }   
   
   gApplication->Terminate();
}
