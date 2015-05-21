#include <vector>
#include "TROOT.h"
#include "TH2D.h"
#include "TFile.h"
#include "TString.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "Riostream.h"
#include "def.h"

#include "atlasstyle-00-03-04/AtlasStyle.h"
#include "atlasstyle-00-03-04/AtlasUtils.h"

TFile *fbatchMC[100];

std::string ver = "histMJ_2D/";
std::string flav = "ljet";

std::string fpathMC = "/opt/sbg/cms/ui5_data1/kskovpen/bTag/CMSSW_5_3_11/src/sysAna/run/"+ver;

const int ncl = 5;
std::string hn[ncl][ncl] = {
   {"1","h_j1_JP_vs_nseltrk","h_j1_JP_vs_njet","h_j1_JP_vs_mupt","h_j1_JP_vs_jeta"},
   {"h_j1_JP_vs_nseltrk","1","h_j1_nseltrk_vs_njet","h_j1_nseltrk_vs_mupt","h_j1_nseltrk_vs_jeta"},
   {"h_j1_JP_vs_njet","h_j1_nseltrk_vs_njet","1","h_j1_njet_vs_mupt","h_j1_njet_vs_jeta"},
   {"h_j1_JP_vs_mupt","h_j1_nseltrk_vs_mupt","h_j1_njet_vs_mupt","1","h_j1_mupt_vs_jeta"},
   {"h_j1_JP_vs_jeta","h_j1_nseltrk_vs_jeta","h_j1_njet_vs_jeta","h_j1_mupt_vs_jeta","1"}
};

std::string nam[ncl] = {
   "$JP$","$N_{trk}$","$N_{jet}$","$P_{T} (\\mu)$","$\\eta (jet)$"
};

TH2D *h2;

const int nptbin = 17;
std::string ptbin[nptbin] = {"pt20t30",
"pt30t40","pt40t50","pt50t60","pt60t70",
"pt70t80","pt80t100","pt100t120",
"pt120t160","pt160t210","pt210t260",
"pt260t320","pt320t400","pt400t500",
"pt500t600","pt600t800","pt800t1000"};

std::string tag = "nosel";

int main()
{
   gROOT->ProcessLine(".L atlasstyle-00-03-04/AtlasStyle.C");
   gROOT->ProcessLine(".L atlasstyle-00-03-04/AtlasUtils.C");
   gROOT->ProcessLine(".L atlasstyle-00-03-04/AtlasLabels.C");
   
   SetAtlasStyle();
   
   def();
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);

   std::string header = "\\begin{tabular}{|c|c|c|c|c|c|} \n\\hline";

   std::string footer = "\\hline \n\\end{tabular} \n\n";

   for(int ipt=0;ipt<nptbin;ipt++)
     {	
	std::string fsave = "tables/table_"+flav+"_"+ptbin[ipt]+".tex";
	std::ofstream fout(fsave.c_str());

	fout << header << std::endl;

	std::string lin0 = " & ";
	
	for(int ic=0;ic<ncl;ic++)
	  {
	     std::string lin = nam[ic];
	     
	     for(int icc=0;icc<ncl;icc++)
	       {
		  std::string FC = "";

		  lin0 += nam[icc];
		  if( icc != ncl-1 ) lin0 += " & ";

		  if( hn[ic][icc] != "1" )
		    {		       
		       std::string varh = hn[ic][icc]+"_"+flav+"_"+ptbin[ipt]+"_nosel_"+tag;
		       
		       for(int i=0;i<v_mc_filt->size();i++)
			 {
			    std::string fname = fpathMC+v_mc_filt->at(i);
			    fbatchMC[i] = TFile::Open(fname.c_str());
			    
			    TH2D *hf = (TH2D*)fbatchMC[i]->Get(varh.c_str());
			    if( i == 0 ) 
			      {
				 h2 = (TH2D*)hf->Clone("h2");
			      }	
			    else 
			      {
				 h2->Add(hf);
			      }
			 }

		       if( ic > icc )
			 {			    
			    h2->Draw("BOX");
			    std::string fs = "pics/"+varh+".eps";
			    c1->Print(fs.c_str());
			    c1->Clear();
			 }
		       
		       float corrF = h2->GetCorrelationFactor();
		       float covM = h2->GetCovariance();
		       
		       FC = TString(Form("%.2f",corrF));
		    }
		  else FC = TString("1");

		  lin += " & " + FC;
		  if( icc == ncl-1 ) lin += " \\\\";
		  if( icc == ncl-1 ) lin0 += " \\\\";

		  if( hn[ic][icc] != "1" )
		    {		       
		       for(int i=0;i<v_mc_filt->size();i++)
			 {
			    fbatchMC[i]->Close();
			 }
		    }
	       }
	     
	     if( ic == 0 ) fout << lin0+" \\hline" << std::endl;
	     fout << lin << std::endl;
	  }	
	
	fout << footer << std::endl;	
	fout.close();
     }
}
