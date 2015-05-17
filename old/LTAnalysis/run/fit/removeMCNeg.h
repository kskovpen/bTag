#ifndef REMOVEMCNEG_H
#define REMOVEMCNEG_H

#include "TMath.h"

void removeMCNeg(TH1D *h1)
{
   int nb = h1->GetXaxis()->GetNbins();
   for(int ib=1;ib<=nb;ib++)
     {
	double vb = h1->GetBinContent(ib);
	double ve = h1->GetBinError(ib);
	if( vb < 0 || vb <= ve )
	  {	     
	     h1->SetBinContent(ib,ve);	     
	     h1->SetBinError(ib,ve);
	     
//	     h1->SetBinContent(ib,0);
//	     h1->SetBinError(ib,0);
	  }
     }   
}

#endif
