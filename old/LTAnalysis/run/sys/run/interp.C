void interp(TH1F* hMCb,TH1F* hMCc,TH1F* hMCl,TH1F *hDATA)
{
   int nbins = hMCb->GetXaxis()->GetNbins();
   
   double bvb[10000];
   double beb[10000];
   double bvc[10000];
   double bec[10000];
   double bvl[10000];
   double bel[10000];
   
   int nskip = 0;
   
   for(int ib=1;ib<nbins+1;ib++)
     {
	if( nskip > 0 )
	  {
	     nskip--;
	     continue;
	  }	
	
	double contMCb = hMCb->GetBinContent(ib);
	double contMCc = hMCc->GetBinContent(ib);
	double contMCl = hMCl->GetBinContent(ib);
	double contDATA = hDATA->GetBinContent(ib);
	double errMCb = hMCb->GetBinError(ib);
	double errMCc = hMCc->GetBinError(ib);
	double errMCl = hMCl->GetBinError(ib);
	double errDATA = hDATA->GetBinError(ib);
	
	double contMCa = contMCb+contMCc+contMCl;
	
	if( contDATA > 0 && contMCa == 0 )
	  {
	     int nbZ = 0;
	     for(int ib2=ib;ib2<nbins+1;ib2++)
	       {
		  double contMC2b = hMCb->GetBinContent(ib2);
		  double contMC2c = hMCc->GetBinContent(ib2);
		  double contMC2l = hMCl->GetBinContent(ib2);
		  double contMC2a = contMC2b+contMC2c+contMC2l;
		  
		  double contDATA2 = hDATA->GetBinContent(ib2);
		  
		  if( contMC2a == 0 && contDATA2 > 0 )
		    nbZ++;
	       }
	     nskip = nbZ;
	     
	     double bv2b = hMCb->GetBinContent(ib+nbZ+1);
	     double bv2c = hMCc->GetBinContent(ib+nbZ+1);
	     double bv2l = hMCl->GetBinContent(ib+nbZ+1);
	     double bv2a = bv2b+bv2c+bv2l;
	     
	     double meanb = (contMCb+bv2b)/2.;
	     double meanc = (contMCc+bv2c)/2.;
	     double meanl = (contMCl+bv2l)/2.;
	     double meana = (contMCa+bv2a)/2.;
	     
	     double sigb = sqrt(0.5*(pow(contMCb-meanb,2)+pow(bv2b-meanb,2)));
	     double sigc = sqrt(0.5*(pow(contMCc-meanc,2)+pow(bv2c-meanc,2)));
	     double sigl = sqrt(0.5*(pow(contMCl-meanl,2)+pow(bv2l-meanl,2)));
	     double kfb = contMCb/bv2b;
	     double kfc = contMCc/bv2c;
	     double kfl = contMCl/bv2l;
	     	     
	     for(int ib2=ib;ib2<(ib+nbZ+1);ib2++)
	       {
		  bvb[ib2-1] = meanb*kfb/ib2;
		  beb[ib2-1] = sigb*kfb/ib2;
		  bvc[ib2-1] = meanc*kfc/ib2;
		  bec[ib2-1] = sigc*kfc/ib2;
		  bvl[ib2-1] = meanl*kfl/ib2;
		  bel[ib2-1] = sigl*kfl/ib2;
	       }	     
	  }
	else
	  {
	     bvb[ib-1] = contMCb;
	     beb[ib-1] = errMCb;
	     bvc[ib-1] = contMCc;
	     bec[ib-1] = errMCc;
	     bvl[ib-1] = contMCl;
	     bel[ib-1] = errMCl;
	  }	
     }
   
   std::cout << "BEFORE" << std::endl;
   hMCb->Print("all");
   hDATA->Print("all");
   
   for(int ib=1;ib<nbins+1;ib++)
     {
	hMCb->SetBinContent(ib,bvb[ib-1]);
	hMCb->SetBinError(ib,beb[ib-1]);
	hMCc->SetBinContent(ib,bvc[ib-1]);
	hMCc->SetBinError(ib,bec[ib-1]);
	hMCl->SetBinContent(ib,bvl[ib-1]);
	hMCl->SetBinError(ib,bel[ib-1]);
     }   

   std::cout << "AFTER" << std::endl;
   hMCb->Print("all");
   hDATA->Print("all");
   exit(1);
}
