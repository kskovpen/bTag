#include "func.h"

int main(int argc, char *argv[])
{
   if( argc < 4 )
     {
	std::cout << "Specify the input directories [NOMINAL], [RW], [RW2] and [sysname]" << std::endl;
	exit(1);
     }   
   
   std::string hdir= "/home-pbs/kskovpen/bTagRun2/CMSSW_7_4_6_patch6/src/LTAnalysis/test/";
   
   std::string inDirNOMINAL = argv[1];
   std::string fpathNOMINAL = hdir+inDirNOMINAL+"/";

   std::string inDirRW = argv[2];
   std::string fpathRW = hdir+inDirRW+"/";

   std::string inDirRW2 = argv[3];
   std::string fpathRW2 = hdir+inDirRW2+"/";
   
   rw = argv[4];
   
   SetAtlasStyle();

   def();
   
   // suppress verbose from Print
   gErrorIgnoreLevel = 5000;
   
   std::cout.precision(10);

   leg = new TLegend(0.65,0.90,0.88,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);

   TFile *f_mc_sys = TFile::Open("../../histSYS/MC/data.root","UPDATE");
   TFile *f_data_sys = TFile::Open("../../histSYS/DATA/data.root","UPDATE");
   
   gStyle->SetHistTopMargin(0);

   TH1::AddDirectory(kFALSE);
   TH2::AddDirectory(kFALSE);

   openData_NOMINAL(fpathNOMINAL);
   openData_RW(fpathRW,fpathRW2);
   
   for(int ibtag=0;ibtag<nbtag;ibtag++)
     {
	std::cout << "run" << btag[ibtag] << std::endl;
	for(int iptbin=0;iptbin<nptbin;iptbin++)
	  {
	     PTname = ptbin[iptbin];
	     
	     for(int iflav=0;iflav<nflav;iflav++)
	       {	
		  std::string sptbin = ptbin[iptbin];
		  int nb[nvar];
		  double intI_NOMINAL[nvar];
		  double intI_RW[nvar];
		  double intI_RW2[nvar];
		  TH1D *h_data_noscale[nvar];
		  TH1D *h_mc_noscale_NOMINAL[nvar];
		  TH1D *h_mc_noscale_RW[nvar];
		  TH1D *h_mc_noscale_RW2[nvar];
		  
		  for(int iv=0;iv<nvar;iv++)
		    {		       
		       std::string histName = var1d[iv] + "_" + flav[iflav] + sptbin + "_nosel" + btag[ibtag];
//		       std::cout << histName << std::endl;
		       readData(histName,iv,1); // NOMINAL
		       readData(histName,iv,0); // RW
		       readData(histName,iv,2); // RW2
		       
		       nb[iv] = h_mc_NOMINAL[iv]->GetXaxis()->GetNbins();
		       
			 {			    
			    std::string data_noscale_name = std::string(h_data[iv]->GetName()) + "_clone_noscale";
			    h_data_noscale[iv] = (TH1D*)h_data[iv]->Clone(data_noscale_name.c_str());		       
			    std::string mc_noscale_name = std::string(h_mc_NOMINAL[iv]->GetName()) + "_clone_noscale_NOMINAL";
			    h_mc_noscale_NOMINAL[iv] = (TH1D*)h_mc_NOMINAL[iv]->Clone(mc_noscale_name.c_str());
			    std::string mcrw_noscale_name = std::string(h_mc_RW[iv]->GetName()) + "_clone_noscale_RW";
			    h_mc_noscale_RW[iv] = (TH1D*)h_mc_RW[iv]->Clone(mcrw_noscale_name.c_str());
			    std::string mcrw2_noscale_name = std::string(h_mc_RW2[iv]->GetName()) + "_clone_noscale_RW2";
			    h_mc_noscale_RW2[iv] = (TH1D*)h_mc_RW2[iv]->Clone(mcrw2_noscale_name.c_str());
		       
			    intI_NOMINAL[iv] = h_mc_NOMINAL[iv]->Integral(0,nb[iv]+1);
			    intI_RW[iv] = h_mc_RW[iv]->Integral(0,nb[iv]+1);
			    intI_RW2[iv] = h_mc_RW2[iv]->Integral(0,nb[iv]+1);
			    
/*			    if( fabs(intI_NOMINAL[iv]-intI_RW[iv])/fabs(intI_NOMINAL[iv]) > 10E-5 &&
				iflav == 0 )
			      {
				 std::cout << "Integrals are not the same after reweighting for all jets:" << std::endl;
				 std::cout << "Nominal="<< intI_NOMINAL[iv] << " RW=" << intI_RW[iv] << std::endl;
				 exit(1);
			      }*/
			    
			    if( h_mc_NOMINAL[iv]->Integral(0,nb[iv]+1) > 0 ) h_mc_NOMINAL[iv]->Scale(1./h_mc_NOMINAL[iv]->Integral(0,nb[iv]+1));
			    if( h_data[iv]->Integral(0,nb[iv]+1) > 0 ) h_data[iv]->Scale(1./h_data[iv]->Integral(0,nb[iv]+1));
			    if( intI_RW[iv] > 0 ) h_mc_RW[iv]->Scale(1./intI_RW[iv]);
			    if( intI_RW2[iv] > 0 ) h_mc_RW2[iv]->Scale(1./intI_RW2[iv]);
			 }		       
		       
		       if( iflav == 0 )
			 {			    
			    std::string nname = sptbin+btag[ibtag]+"_"+var1d[iv];
			    plotCOMP(h_mc_RW[iv],h_data[iv],nname,titx[iv]);
			 }		       
		    }		  

		  std::string hnameSAVE = "h_j1_JP_"+flav[iflav]+sptbin+"_nosel"+btag[ibtag];

		  TH1D *h_mc_RW_sys_down = (TH1D*)h_mc_RW[0]->Clone("h_JP_RW_sys_down");
		  TH1D *h_mc_RW_sys_up = (TH1D*)h_mc_RW[0]->Clone("h_JP_RW_sys_up");

		  doSys(h_mc_NOMINAL[0],
			h_mc_RW[0],
			h_mc_RW2[0],
			h_mc_RW_sys_down,
			h_mc_RW_sys_up);
		  
		  std::string hnameSAVE_sys_down = hnameSAVE + "_"+rw+"_down";
		  TH1D *h_mc_RW_sys_down_noscale = (TH1D*)h_mc_RW_sys_down->Clone(hnameSAVE_sys_down.c_str());
		  std::string hnameSAVE_sys_up = hnameSAVE + "_"+rw+"_up";
		  TH1D *h_mc_RW_sys_up_noscale = (TH1D*)h_mc_RW_sys_up->Clone(hnameSAVE_sys_up.c_str());
		  
		  double integ_noscale = intI_NOMINAL[0];
		  
		  h_mc_RW_sys_down_noscale->Scale(integ_noscale);
		  h_mc_RW_sys_up_noscale->Scale(integ_noscale);
		  
		  std::string nname = sptbin+btag[ibtag];
		  if( iflav == 0 )
		    {		       
		       plotSF(h_mc_RW[0],
			      h_mc_NOMINAL[0],
			      h_mc_RW_sys_down,
			      h_mc_RW_sys_up,
			      h_data[0],
			      nname);
		    }		  
		  
		  // Update files with the new histograms
		  f_mc_sys->cd();
		  TH1D *hval;
		  if( useCorMC )
		    {
		       hval = h_mc_noscale_RW[0];
		       h_mc_noscale_RW[0]->Write(hnameSAVE.c_str(),TObject::kOverwrite);
		    }		  
		  else
		    {
		       TH1D* h_mc_y_noscale_norw = (TH1D*)h_mc_noscale_NOMINAL[0]->Clone(hnameSAVE.c_str());
		       h_mc_y_noscale_norw->Write(hnameSAVE.c_str(),TObject::kOverwrite);
		       hval = h_mc_y_noscale_norw;
		    }		  
		  
		  valSys(hval,
			 h_mc_RW_sys_down_noscale,
			 h_mc_RW_sys_up_noscale);

		  h_mc_RW_sys_down_noscale->Write("",TObject::kOverwrite);
		  h_mc_RW_sys_up_noscale->Write("",TObject::kOverwrite);
		  
		  f_data_sys->cd();
		  std::string h_data_y_rw_name = "h_j1_JP_"+flav[iflav]+sptbin+"_nosel"+btag[ibtag];
		  TH1D *h_data_y_rw = (TH1D*)h_data_noscale[0]->Clone(h_data_y_rw_name.c_str());
		  h_data_y_rw->Write("",TObject::kOverwrite);
		  
		  std::string h_data_y_rw_ntrk_sys_down_name = hnameSAVE+"_"+rw+"_down";
		  std::string h_data_y_rw_ntrk_sys_up_name = hnameSAVE+"_"+rw+"_up";
		  TH1D *h_data_y_rw_ntrk_sys_down_noscale = (TH1D*)h_data_noscale[0]->Clone(h_data_y_rw_ntrk_sys_down_name.c_str());
		  TH1D *h_data_y_rw_ntrk_sys_up_noscale = (TH1D*)h_data_noscale[0]->Clone(h_data_y_rw_ntrk_sys_up_name.c_str());
		  h_data_y_rw_ntrk_sys_down_noscale->Write("",TObject::kOverwrite);
		  h_data_y_rw_ntrk_sys_up_noscale->Write("",TObject::kOverwrite);
		  
		  nname = flav[iflav]+sptbin+btag[ibtag];
		  plotSYS(h_mc_noscale_RW[0],
			  h_mc_noscale_RW2[0],
			  h_mc_noscale_NOMINAL[0],
			  h_mc_RW_sys_down_noscale,
			  h_mc_RW_sys_up_noscale,
			  h_data_noscale[0],
			  nname);
	       }	     
	  }	
     }
   
   // close files
   f_mc_sys->Write();
   f_mc_sys->Close();

   f_data_sys->Write();
   f_data_sys->Close();
}
