#ifndef FITADDBIN2D_H
#define FITADDBIN2D_H

#include "TMath.h"

void addbin2D(TH2D *h)
{   
   // Add overflow and underflow bins
   Int_t x_nbins = h->GetXaxis()->GetNbins();
   Int_t y_nbins = h->GetYaxis()->GetNbins();
   
   for(int iy=1;iy<y_nbins+1;iy++)
     {	
	h->SetBinContent(1,iy,h->GetBinContent(0,iy)+h->GetBinContent(1,iy));
	h->SetBinError(1,iy,TMath::Sqrt(pow(h->GetBinError(0,iy),2)+pow(h->GetBinError(1,iy),2)));
	h->SetBinContent(x_nbins,iy,h->GetBinContent(x_nbins,iy)+h->GetBinContent(x_nbins+1,iy));
	h->SetBinError(x_nbins,iy,TMath::Sqrt(pow(h->GetBinError(x_nbins,iy),2)+
					      pow(h->GetBinError(x_nbins+1,iy),2)));
	// Set overflow and underflow bins to 0
	h->SetBinContent(0,iy,0.);
	h->SetBinError(0,iy,0.);
	h->SetBinContent(x_nbins+1,iy,0.);
	h->SetBinError(x_nbins+1,iy,0.);
     }   

   for(int ix=1;ix<x_nbins+1;ix++)
     {	
	h->SetBinContent(ix,1,h->GetBinContent(ix,0)+h->GetBinContent(ix,1));
	h->SetBinError(ix,1,TMath::Sqrt(pow(h->GetBinError(ix,0),2)+pow(h->GetBinError(ix,1),2)));
	h->SetBinContent(ix,y_nbins,h->GetBinContent(ix,y_nbins)+h->GetBinContent(ix,y_nbins+1));
	h->SetBinError(ix,y_nbins,TMath::Sqrt(pow(h->GetBinError(ix,y_nbins),2)+
					      pow(h->GetBinError(ix,y_nbins+1),2)));
	// Set overflow and underflow bins to 0
	h->SetBinContent(ix,0,0.);
	h->SetBinError(ix,0,0.);
	h->SetBinContent(ix,y_nbins+1,0.);
	h->SetBinError(ix,y_nbins+1,0.);
     }   
}

#endif
