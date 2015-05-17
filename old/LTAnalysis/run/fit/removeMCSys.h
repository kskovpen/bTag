#ifndef REMOVEMCSYS_H
#define REMOVEMCSYS_H

#include "TMath.h"

void removeMCSys(TH1D *hnom,TH1D *hsysUp,TH1D *hsysLow)
{
   int nb = hnom->GetXaxis()->GetNbins();
   for(int ib=1;ib<=nb;ib++)
     {
	double vb0 = hnom->GetBinContent(ib);
	double ve0 = hnom->GetBinError(ib);
	double vbUp = hsysUp->GetBinContent(ib);

	if( vbUp-vb0 > vb0 )
	  {	     
	     hsysUp->SetBinContent(ib,2*vb0);
	  }
     }   
}

#endif
