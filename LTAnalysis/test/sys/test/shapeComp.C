TFile *fbatch_MC_unfilt[100];
TFile *fbatch_MC_filt[100];
TFile *fbatch_DATA[100];

std::string toolMC = "plot_PROC_v0";
std::string fpathMC = "/gcf/atlas/data/JTNtuple_hist/run_"+toolMC+"/";

std::string toolDATA = "plot_PROC_v0";
std::string fpathDATA = "/gcf/atlas/data/JTNtuple_hist/run_"+toolDATA+"/";

const int nhist = 1;
std::string hist[nhist] = 
  {
     "d0SignJet1"
  };
std::string xtit[nhist] = 
{
   "S_{d_{0}}(t_{1})"
};
const int nptbin = 12;
std::string ptbin[nptbin] = {"pt20t30",
"pt30t40","pt40t50","pt50t60","pt60t75",
"pt75t90","pt90t110","pt110t140",
"pt140t200","pt200t260","pt260t340",
"pt340t500"};
int nbm1d = 4;
//std::string tag = "mv1c0p148";
std::string tag = "mv1c0p985";

void shapeComp()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine("#include <string>");
   gROOT->ProcessLine("#include <TH1F.h>");
   
   gROOT->ProcessLine(".x common.C");
   gROOT->ProcessLine(".x def.C");
   
   gROOT->ProcessLine(".L addbin.C");

   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   
   gStyle->SetHistTopMargin(0);
   
   TH1F *h_MC_preTag_ljet;
   TH1F *h_MC_postTag_ljet;
   TH1F *h_MC_preTag_bjet;
   TH1F *h_MC_postTag_bjet;
   TH1F *h_MC_preTag_cjet;
   TH1F *h_MC_postTag_cjet;
   TH1F *h_DATA;

   for(int ih=0;ih<nhist;ih++)
     {	
	for(int ipt=0;ipt<nptbin;ipt++)
	  {	
	     std::string varhMC_preTag_ljet = "h_j1_"+hist[ih]+"_ljet_"+ptbin[ipt]+"_nosel_nosel";
	     std::string varhMC_postTag_ljet = "h_j1_"+hist[ih]+"_ljet_"+ptbin[ipt]+"_nosel_" + tag;
	     std::string varhMC_preTag_bjet = "h_j1_"+hist[ih]+"_bjet_"+ptbin[ipt]+"_nosel_nosel";
	     std::string varhMC_postTag_bjet = "h_j1_"+hist[ih]+"_bjet_"+ptbin[ipt]+"_nosel_" + tag;
	     std::string varhMC_preTag_cjet = "h_j1_"+hist[ih]+"_cjet_"+ptbin[ipt]+"_nosel_nosel";
	     std::string varhMC_postTag_cjet = "h_j1_"+hist[ih]+"_cjet_"+ptbin[ipt]+"_nosel_" + tag;
	     std::string varhDATA = "h_j1_"+hist[ih]+"_ajet_"+ptbin[ipt]+"_nosel_UNTAGbc";
	     
	     for(int i=0;i<v_mc_unfilt.size();i++)
	       {
		  std::string fname = fpathMC+v_mc_unfilt.at(i);
		  fbatch_MC_unfilt[i] = TFile::Open(fname.c_str());
		  
		  TH1F *hf_preTag_ljet = (TH1F*)fbatch_MC_unfilt[i]->Get(varhMC_preTag_ljet.c_str());
		  TH1F *hf_postTag_ljet = (TH1F*)fbatch_MC_unfilt[i]->Get(varhMC_postTag_ljet.c_str());

		  if( i == 0 ) 
		    {
		       h_MC_preTag_ljet = (TH1F*)hf_preTag_ljet->Clone("h_MC_preTag_ljet");
		       h_MC_postTag_ljet = (TH1F*)hf_postTag_ljet->Clone("h_MC_postTag_ljet");
		    }	
		  else 
		    {
		       h_MC_preTag_ljet->Add(hf_preTag_ljet);
		       h_MC_postTag_ljet->Add(hf_postTag_ljet);
		    }   
	       }

	     for(int i=0;i<v_mc_filt.size();i++)
	       {
		  std::string fname = fpathMC+v_mc_filt.at(i);
		  fbatch_MC_filt[i] = TFile::Open(fname.c_str());
		  
		  TH1F *hf_preTag_bjet = (TH1F*)fbatch_MC_filt[i]->Get(varhMC_preTag_bjet.c_str());
		  TH1F *hf_postTag_bjet = (TH1F*)fbatch_MC_filt[i]->Get(varhMC_postTag_bjet.c_str());

		  TH1F *hf_preTag_cjet = (TH1F*)fbatch_MC_filt[i]->Get(varhMC_preTag_cjet.c_str());
		  TH1F *hf_postTag_cjet = (TH1F*)fbatch_MC_filt[i]->Get(varhMC_postTag_cjet.c_str());
		  
		  if( i == 0 ) 
		    {
		       h_MC_preTag_bjet = (TH1F*)hf_preTag_bjet->Clone("h_MC_preTag_bjet");
		       h_MC_postTag_bjet = (TH1F*)hf_postTag_bjet->Clone("h_MC_postTag_bjet");

		       h_MC_preTag_cjet = (TH1F*)hf_preTag_cjet->Clone("h_MC_preTag_cjet");
		       h_MC_postTag_cjet = (TH1F*)hf_postTag_cjet->Clone("h_MC_postTag_cjet");
		    }	
		  else 
		    {
		       h_MC_preTag_bjet->Add(hf_preTag_bjet);
		       h_MC_postTag_bjet->Add(hf_postTag_bjet);

		       h_MC_preTag_cjet->Add(hf_preTag_cjet);
		       h_MC_postTag_cjet->Add(hf_postTag_cjet);
		    }   
	       }
	     
	     for(int i=0;i<v_data.size();i++)
	       {
		  std::string fname = fpathDATA+v_data.at(i);
		  fbatch_DATA[i] = TFile::Open(fname.c_str());
		  
		  TH1F *hf = (TH1F*)fbatch_DATA[i]->Get(varhDATA.c_str());

		  if( i == 0 ) 
		    {
		       h_DATA = (TH1F*)hf->Clone("h_DATA");
		    }	
		  else 
		    {
		       h_DATA->Add(hf);
		    }   
	       }
	     
	     addbin(h_MC_preTag_ljet);
	     addbin(h_MC_postTag_ljet);
	     addbin(h_MC_preTag_bjet);
	     addbin(h_MC_postTag_bjet);
	     addbin(h_MC_preTag_cjet);
	     addbin(h_MC_postTag_cjet);
	     addbin(h_DATA);
	     
	     h_MC_preTag_ljet = (TH1F*)h_MC_preTag_ljet->Rebin(nbm1d,"");
	     h_MC_postTag_ljet = (TH1F*)h_MC_postTag_ljet->Rebin(nbm1d,"");
	     h_MC_preTag_bjet = (TH1F*)h_MC_preTag_bjet->Rebin(nbm1d,"");
	     h_MC_postTag_bjet = (TH1F*)h_MC_postTag_bjet->Rebin(nbm1d,"");
	     h_MC_preTag_cjet = (TH1F*)h_MC_preTag_cjet->Rebin(nbm1d,"");
	     h_MC_postTag_cjet = (TH1F*)h_MC_postTag_cjet->Rebin(nbm1d,"");
	     h_DATA = (TH1F*)h_DATA->Rebin(nbm1d,"");

	     if( h_MC_preTag_ljet->Integral() ) h_MC_preTag_ljet->Scale(1./h_MC_preTag_ljet->Integral());
	     if( h_MC_postTag_ljet->Integral() ) h_MC_postTag_ljet->Scale(1./h_MC_postTag_ljet->Integral());
	     if( h_MC_preTag_bjet->Integral() ) h_MC_preTag_bjet->Scale(1./h_MC_preTag_bjet->Integral());
	     if( h_MC_postTag_bjet->Integral() ) h_MC_postTag_bjet->Scale(1./h_MC_postTag_bjet->Integral());
	     if( h_MC_preTag_cjet->Integral() ) h_MC_preTag_cjet->Scale(1./h_MC_preTag_cjet->Integral());
	     if( h_MC_postTag_cjet->Integral() ) h_MC_postTag_cjet->Scale(1./h_MC_postTag_cjet->Integral());
	     if( h_DATA->Integral() ) h_DATA->Scale(1./h_DATA->Integral());

	     h_MC_preTag_ljet->GetXaxis()->SetTitle(xtit[ih].c_str());
	     h_MC_preTag_bjet->GetXaxis()->SetTitle(xtit[ih].c_str());
	     h_MC_preTag_cjet->GetXaxis()->SetTitle(xtit[ih].c_str());
	     
	     h_MC_preTag_ljet->SetLineColor(kRed);
	     h_MC_preTag_ljet->SetMarkerColor(kRed);
	     h_MC_preTag_bjet->SetLineColor(kRed);
	     h_MC_preTag_bjet->SetMarkerColor(kRed);
	     h_MC_preTag_cjet->SetLineColor(kRed);
	     h_MC_preTag_cjet->SetMarkerColor(kRed);
	     h_MC_postTag_ljet->SetLineColor(kBlue);
	     h_MC_postTag_ljet->SetMarkerColor(kBlue);
	     h_MC_postTag_bjet->SetLineColor(kBlue);
	     h_MC_postTag_bjet->SetMarkerColor(kBlue);
	     h_MC_postTag_cjet->SetLineColor(kBlue);
	     h_MC_postTag_cjet->SetMarkerColor(kBlue);
	     h_DATA->SetLineColor(kBlack);
	     h_DATA->SetMarkerColor(kBlack);

	     TLegend *leg = new TLegend(0.65,0.90,0.88,0.75);
	     leg->SetFillColor(253);
	     leg->SetBorderSize(0);
	     leg->AddEntry(h_DATA,"Data","f");
	     leg->AddEntry(h_MC_preTag_ljet,"pre-Tag MC","f");
	     
	     float m_MC_preTag_ljet = h_MC_preTag_ljet->GetMaximum();
	     float m_DATA = h_DATA->GetMaximum();
	     float max = (m_MC_preTag_ljet > m_DATA) ? m_MC_preTag_ljet : m_DATA;

	     h_MC_preTag_ljet->SetMaximum(1.4*max);
	     
	     h_MC_preTag_ljet->Draw("hist e1");
	     h_DATA->Draw("hist e1 same");
	     leg->Draw();	     
	     std::string fsave = "pics/"+hist[ih]+"_"+ptbin[ipt]+"_ljet.eps";
	     c1->Print(fsave.c_str());
	     leg->Clear();
	     c1->Clear();
	     
	     leg->AddEntry(h_MC_postTag_bjet,"post-Tag MC","f");
	     leg->AddEntry(h_MC_preTag_bjet,"pre-Tag MC","f");
	     
	     float m_MC_preTag_bjet = h_MC_preTag_bjet->GetMaximum();
	     float m_MC_postTag_bjet = h_MC_postTag_bjet->GetMaximum();
	     float max_bjet = (m_MC_preTag_bjet > m_MC_postTag_bjet) ? m_MC_preTag_bjet : m_MC_postTag_bjet;

	     h_MC_preTag_bjet->SetMaximum(1.4*max_bjet);
	     
	     h_MC_preTag_bjet->Draw("hist e1");
	     h_MC_postTag_bjet->Draw("hist e1 same");
	     leg->Draw();	     
	     std::string fsave = "pics/"+hist[ih]+"_"+ptbin[ipt]+"_bjet.eps";
	     c1->Print(fsave.c_str());
	     leg->Clear();
	     c1->Clear();	     

	     leg->AddEntry(h_MC_postTag_cjet,"post-Tag MC","f");
	     leg->AddEntry(h_MC_preTag_cjet,"pre-Tag MC","f");
	     
	     float m_MC_preTag_cjet = h_MC_preTag_cjet->GetMaximum();
	     float m_MC_postTag_cjet = h_MC_postTag_cjet->GetMaximum();
	     float max_cjet = (m_MC_preTag_cjet > m_MC_postTag_cjet) ? m_MC_preTag_cjet : m_MC_postTag_cjet;

	     h_MC_preTag_cjet->SetMaximum(1.4*max_cjet);
	     
	     h_MC_preTag_cjet->Draw("hist e1");
	     h_MC_postTag_cjet->Draw("hist e1 same");
	     leg->Draw();	     
	     std::string fsave = "pics/"+hist[ih]+"_"+ptbin[ipt]+"_cjet.eps";
	     c1->Print(fsave.c_str());
	     leg->Clear();
	     c1->Clear();	     
	     
	     delete leg;
	  }
     }   
   
   gApplication->Terminate();
}
