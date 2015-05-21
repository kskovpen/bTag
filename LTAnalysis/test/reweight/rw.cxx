#include "func.h"

int main(int argc, char *argv[])
{
   if( argc < 3 )
     {
	std::cout << "Specify the input directory, reweight type and overwrite flag" << std::endl;
	exit(1);
     }   
   
   std::string inDir = argv[1];
   std::string fpath = "/home-pbs/kskovpen/bTag/CMSSW_7_4_0/src/LTAnalysis/test/"+inDir+"/";
   std::string type = argv[2];
   overwrite = atoi(argv[3]);
   
   SetAtlasStyle();

   def();
   
   // suppress verbose from Print
   gErrorIgnoreLevel = 5000;
   
   std::cout.precision(10);

   leg = new TLegend(0.65,0.90,0.88,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);

   TFile *f = new TFile("corrections.root","UPDATE");
   
   gStyle->SetHistTopMargin(0);

   TH1::AddDirectory(kFALSE);
   TH2::AddDirectory(kFALSE);

   openData(fpath);
   
   for(int ibtag=0;ibtag<nbtag;ibtag++)
     {	
	for(int iptbin=0;iptbin<nptbin;iptbin++)
	  {
	     for(int iflav=0;iflav<nflav;iflav++)
	       {	
		  std::string sptbin = ptbin[iptbin];
		  
		  if( type == "3d" )
		    {		       
		       int nbX[nvar3d];
		       int nbY[nvar3d];
		       int nbZ[nvar3d];
		       
		       for(int iv=0;iv<nvar3d;iv++)
			 {		       
			    std::string histName = var3d[iv] + flav[iflav] + sptbin + "_nosel" + btag[ibtag];
			    readData(histName,iv,type);
			    
			    nbX[iv] = h_mc_3d[iv]->GetXaxis()->GetNbins();
			    nbY[iv] = h_mc_3d[iv]->GetYaxis()->GetNbins();
			    nbZ[iv] = h_mc_3d[iv]->GetZaxis()->GetNbins();

			    h_mc_3d[iv]->Scale(1./h_mc_3d[iv]->Integral(0,nbX[iv]+1,0,nbY[iv]+1,0,nbZ[iv]+1));
			    h_data_3d[iv]->Scale(1./h_data_3d[iv]->Integral(0,nbX[iv]+1,0,nbY[iv]+1,0,nbZ[iv]+1));
			 }		  

		       f->cd();
		       
		       // calculate SFs
		       if( iflav == 0 )
			 {
			    std::string varname = var3dx[0];
			    std::string iname = std::string(Form("sf_%s%s_%s",sptbin.c_str(),btag[ibtag].c_str(),varname.c_str()));
			    calcSF_3d(0,iname,h_mc_3d[0],h_data_3d[0]);
			    
			    if( ! f->GetListOfKeys()->Contains(h_sf_3d[0]->GetName()) || overwrite == 1 )
			      h_sf_3d[0]->Write("",TObject::kOverwrite);
			 }		  
		    }		  
		  if( type == "2d" )
		    {		       
		       int nbX[nvar2d];
		       int nbY[nvar2d];
		       
		       for(int iv=0;iv<nvar2d;iv++)
			 {		       
			    std::string histName = var2d[iv] + flav[iflav] + sptbin + "_nosel" + btag[ibtag];
			    readData(histName,iv,type);
			    
			    nbX[iv] = h_mc_2d[iv]->GetXaxis()->GetNbins();
			    nbY[iv] = h_mc_2d[iv]->GetYaxis()->GetNbins();

			    h_mc_2d[iv]->Scale(1./h_mc_2d[iv]->Integral(0,nbX[iv]+1,0,nbY[iv]+1));
			    h_data_2d[iv]->Scale(1./h_data_2d[iv]->Integral(0,nbX[iv]+1,0,nbY[iv]+1));
			 }		  

		       f->cd();
		       
		       // calculate SFs
		       if( iflav == 0 )
			 {
			    std::string varname = var2dx[0];
			    std::string iname = std::string(Form("sf_%s%s_%s",sptbin.c_str(),btag[ibtag].c_str(),varname.c_str()));
			    calcSF_2d(0,iname,h_mc_2d[0],h_data_2d[0]);
			    
			    if( ! f->GetListOfKeys()->Contains(h_sf_2d[0]->GetName()) || overwrite == 1 )
			      h_sf_2d[0]->Write("",TObject::kOverwrite);
			 }		  
		    }		  
		  if( type == "1d" )
		    {		       
		       int nbX[nvar1d];
		       
		       for(int iv=0;iv<nvar1d;iv++)
			 {		       
			    std::string histName = var1d[iv] + flav[iflav] + sptbin + "_nosel" + btag[ibtag];
			    readData(histName,iv,type);
			    
			    nbX[iv] = h_mc_1d[iv]->GetXaxis()->GetNbins();

			    h_mc_1d[iv]->Scale(1./h_mc_1d[iv]->Integral(0,nbX[iv]+1));
			    h_data_1d[iv]->Scale(1./h_data_1d[iv]->Integral(0,nbX[iv]+1));
			 }		  
		  
		       f->cd();

		       for(int iv=0;iv<nvar1d;iv++)
			 {			    
			    // calculate SFs
			    if( iflav == 0 )
			      {
				 std::string varname = var1dx[iv];
				 std::string iname = std::string(Form("sf_%s%s_%s",sptbin.c_str(),btag[ibtag].c_str(),varname.c_str()));
				 calcSF_1d(iv,iname,h_mc_1d[iv],h_data_1d[iv]);
				 
				 if( ! f->GetListOfKeys()->Contains(h_sf_1d[iv]->GetName()) || overwrite == 1 )
				   h_sf_1d[iv]->Write("",TObject::kOverwrite);
			      }		  
			 }		       
		    }		  
	       }	     
	  }	
     }
   
   f->Write();
   f->Close();
}
