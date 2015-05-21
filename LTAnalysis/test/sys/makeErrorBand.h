#ifndef FITMAKEERRORBAND_H
#define FITMAKEERRORBAND_H

#include "TMath.h"
#include "TGraphAsymmErrors.h"

TGraphAsymmErrors* makeErrorBand(TH1D* tot, TH1D* plus, TH1D* minus){
  
  int nbins = tot->GetNbinsX();
  
  const int s = 1000;

  double x[s];
  double xerr[s];
  double y[s];
  double yp[s];
  double ym[s];
   
  for(int bin =1; bin<=nbins; ++bin){
    
    int index = bin-1;
    xerr[index] = tot->GetBinWidth(bin)/2.0;
    x[index] = tot->GetBinLowEdge(bin) + xerr[index];
    
    y[index] = tot->GetBinContent(bin);
    yp[index] = plus->GetBinContent(bin)-y[index];
    ym[index] = y[index]-minus->GetBinContent(bin);
    if(y[index] - ym[index] < 0) ym[index] = y[index];

  }
  
  TGraphAsymmErrors* error = new TGraphAsymmErrors(nbins, x, y, xerr, xerr, ym, yp);

  return error;

}

#endif
