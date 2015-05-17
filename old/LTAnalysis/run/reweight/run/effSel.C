TFile *fbatch_MC1[100];
TFile *fbatch_MC2[100];

std::string toolMC1 = "plot_v1_TightLight";
std::string fpathMC1 = "/gcf/atlas/data/JTNtuple_hist/run_"+toolMC1+"/";

std::string toolMC2 = "plot_v1_Tight";
std::string fpathMC2 = "/gcf/atlas/data/JTNtuple_hist/run_"+toolMC2+"/";

const int nptr = 5;
double statSF = 10.;
std::string ptr[nptr] = {"pt110t140","pt140t200","pt200t260","pt260t340","pt340t500"};
int ptridx[nptr] = {4,5,6,7,8};
std::string sel = "nosel";
std::string var = "d0SignJet1";

void effSel()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine("#include <string>");
   gROOT->ProcessLine("#include <TH1F.h>");
   
   gROOT->ProcessLine(".x common.C");
   gROOT->ProcessLine(".x def.C");

   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   
   gStyle->SetHistTopMargin(0);
   
   TH1F *h_MC1_bjet;
   TH1F *h_MC2_bjet;
   TH1F *h_MC1_cjet;
   TH1F *h_MC2_cjet;
   TH1F *h_MC1_ljet;
   TH1F *h_MC2_ljet;

   int nbins = 10;
   double ptbins[11] = {0.04,0.06,0.08,0.10,0.14,0.20,0.26,0.34,0.5,0.7,1.0};

   TFile fout("results/effSel.root","RECREATE");

   fout.cd();
   TH1F *heff_bjet = new TH1F("heff_bjet","heff_bjet",nbins,ptbins);
   TH1F *heff_cjet = new TH1F("heff_cjet","heff_cjet",nbins,ptbins);
   TH1F *heff_ljet = new TH1F("heff_ljet","heff_ljet",nbins,ptbins);
   TH1F *heff_ajet = new TH1F("heff_ajet","heff_ajet",nbins,ptbins);
   
   for(int p=0;p<nptr;p++)
     {	   
	std::string varh_bjet = "h_j1_"+var+"_bjet_"+ptr[p]+"_"+sel;
	std::string varh_cjet = "h_j1_"+var+"_cjet_"+ptr[p]+"_"+sel;
	std::string varh_ljet = "h_j1_"+var+"_ljet_"+ptr[p]+"_"+sel;
   
	for(int i=0;i<v_mc_unfilt.size();i++)
	  {
	     std::string fname1 = fpathMC1+v_mc_unfilt.at(i);
	     std::string fname2 = fpathMC2+v_mc_unfilt.at(i);
	     fbatch_MC1[i] = TFile::Open(fname1.c_str());
	     fbatch_MC2[i] = TFile::Open(fname2.c_str());
	     
	     TH1F *hf1_bjet = (TH1F*)fbatch_MC1[i]->Get(varh_bjet.c_str());
	     TH1F *hf2_bjet = (TH1F*)fbatch_MC2[i]->Get(varh_bjet.c_str());
	     TH1F *hf1_cjet = (TH1F*)fbatch_MC1[i]->Get(varh_cjet.c_str());
	     TH1F *hf2_cjet = (TH1F*)fbatch_MC2[i]->Get(varh_cjet.c_str());
	     TH1F *hf1_ljet = (TH1F*)fbatch_MC1[i]->Get(varh_ljet.c_str());
	     TH1F *hf2_ljet = (TH1F*)fbatch_MC2[i]->Get(varh_ljet.c_str());
	     if( i == 0 ) 
	       {
		  h_MC1_bjet = (TH1F*)hf1_bjet->Clone("h_MC1_bjet");
		  h_MC2_bjet = (TH1F*)hf2_bjet->Clone("h_MC2_bjet");
		  h_MC1_cjet = (TH1F*)hf1_cjet->Clone("h_MC1_cjet");
		  h_MC2_cjet = (TH1F*)hf2_cjet->Clone("h_MC2_cjet");
		  h_MC1_ljet = (TH1F*)hf1_ljet->Clone("h_MC1_ljet");
		  h_MC2_ljet = (TH1F*)hf2_ljet->Clone("h_MC2_ljet");
	       }	
	     else 
	       {
		  h_MC1_bjet->Add(hf1_bjet);
		  h_MC2_bjet->Add(hf2_bjet);
		  h_MC1_cjet->Add(hf1_cjet);
		  h_MC2_cjet->Add(hf2_cjet);
		  h_MC1_ljet->Add(hf1_ljet);
		  h_MC2_ljet->Add(hf2_ljet);
	       }   
	  }

	double n1_bjet = h_MC1_bjet->GetEntries()*statSF;
	double n2_bjet = h_MC2_bjet->GetEntries();
	double eff_bjet = (n1_bjet > 0 ) ? n2_bjet/n1_bjet : -666.;
	double eff_bjet_err = errf(n1_bjet,n2_bjet);
	double n1_cjet = h_MC1_cjet->GetEntries()*statSF;
	double n2_cjet = h_MC2_cjet->GetEntries();
	double eff_cjet = (n1_cjet > 0 ) ? n2_cjet/n1_cjet : -666.;
	double eff_cjet_err = errf(n1_cjet,n2_cjet);
	double n1_ljet = h_MC1_ljet->GetEntries()*statSF;
	double n2_ljet = h_MC2_ljet->GetEntries();
	double eff_ljet = (n1_ljet > 0 ) ? n2_ljet/n1_ljet : -666.;
	double eff_ljet_err = errf(n1_ljet,n2_ljet);
	double n1_ajet = n1_bjet + n1_cjet + n1_ljet*statSF;
	double n2_ajet = n2_bjet + n2_cjet + n2_ljet;
	double eff_ajet = (n1_ajet > 0 ) ? n2_ajet/n1_ajet : -666.;
	double eff_ajet_err = errf(n1_ajet,n2_ajet);
	
	heff_bjet->SetBinContent(ptridx[p],eff_bjet);
	heff_bjet->SetBinError(ptridx[p],eff_bjet_err);

	heff_cjet->SetBinContent(ptridx[p],eff_cjet);
	heff_cjet->SetBinError(ptridx[p],eff_cjet_err);

	heff_ljet->SetBinContent(ptridx[p],eff_ljet);
	heff_ljet->SetBinError(ptridx[p],eff_ljet_err);

	heff_ajet->SetBinContent(ptridx[p],eff_ajet);
	heff_ajet->SetBinError(ptridx[p],eff_ajet_err);
     }

   heff_ajet->SetLineColor(1);
   heff_ajet->SetMarkerColor(1);
   heff_ajet->SetMarkerStyle(23);
   
   heff_bjet->SetLineColor(46);
   heff_bjet->SetMarkerColor(46);
   heff_bjet->SetMarkerStyle(20);

   heff_cjet->SetLineColor(38);
   heff_cjet->SetMarkerColor(38);
   heff_cjet->SetMarkerStyle(21);

   heff_ljet->SetLineColor(30);
   heff_ljet->SetMarkerColor(30);
   heff_ljet->SetMarkerStyle(22);
   
   heff_ajet->Draw("e1");
   heff_bjet->Draw("e1 same");
   heff_cjet->Draw("e1 same");
   heff_ljet->Draw("e1 same");
   
   heff_ajet->GetYaxis()->SetRangeUser(0.0005,0.05);

   heff_ajet->GetXaxis()->SetTitle("P_{T} [TeV]");
   heff_ajet->GetYaxis()->SetTitle("Efficiency");

   TLegend *leg = new TLegend(0.75,0.90,0.90,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
//   leg->AddEntry(heff_ajet,"Any jet","lep");
   leg->AddEntry(heff_bjet,"Beauty","lep");
   leg->AddEntry(heff_cjet,"Charm","lep");
   leg->AddEntry(heff_ljet,"Light","lep");
   
   leg->Draw();

   c1->SetLogy(1);
   
   std::string fsave = "pics/effSel.eps";
   c1->Print(fsave.c_str());
   c1->Clear();
   
   fout.cd();
   heff_ajet->Write();
   heff_bjet->Write();
   heff_cjet->Write();
   heff_ljet->Write();
   fout.Close();
   
   gApplication->Terminate();
}

double errf(double v1,double v2)
{
   if( v1 == 0 ) return -666;

   double err = v2/v1/v1-v2*v2/v1/v1/v1;
   
   err = sqrt(err);
   
   return err;
}
