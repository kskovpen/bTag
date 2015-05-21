#ifndef RATIOERR_H
#define RATIOERR_H

#include "makeErrorBand.h"

void ratioErr(TCanvas *c1, TH1D* h1, TH1D* h2, TH1D *h1_low, TH1D *h1_up)
{
   TH1D* h2e = (TH1D*)h2->Clone("h2e");

   TH1D* h1c = (TH1D*)h1->Clone("h1c");
   
   TH1D* h1c_low = (TH1D*)h1_low->Clone("h1c_low");
   TH1D* h1c_up = (TH1D*)h1_up->Clone("h1c_up");

   h1c->Divide(h1c,h2e,1,1,"");
   
   h1c_low->Divide(h1c_low,h2e,1,1,"");
   h1c_up->Divide(h1c_up,h2e,1,1,"");
   h2e->Divide(h2e,h2e,1,1,"");
   
   c1->cd();
   TPad *c1_2 = new TPad("c1_2", "ratio",0.01,0.01,0.99,0.38);
   c1_2->Draw();
   c1_2->cd();  
   c1_2->SetBottomMargin(0.38);
   c1_2->SetGrid(0,1);
   
   h1c->SetMarkerStyle(20);
   h1c->SetMarkerSize(0.8);
   h1c->GetYaxis()->SetNdivisions(5);
   h1c->GetYaxis()->SetTitle("MCRW/MC");
   
   h1c->GetYaxis()->SetTitleSize((h1c->GetYaxis()->GetTitleSize())*2);
   h1c->GetYaxis()->SetTitleOffset(h1c->GetYaxis()->GetTitleOffset()/2);
   h1c->GetXaxis()->SetTitleSize((h1c->GetXaxis()->GetTitleSize())*2);
   h1c->GetXaxis()->SetTitleOffset(h1c->GetXaxis()->GetTitleOffset()+0.2);

   h1c->GetYaxis()->SetLabelSize((h1c->GetYaxis()->GetLabelSize())*2);
   h1c->GetXaxis()->SetLabelSize((h1c->GetXaxis()->GetLabelSize())*2);

   h1c->GetXaxis()->SetTitle(h1c->GetXaxis()->GetTitle());

   h1c->GetYaxis()->SetRangeUser(0.,2.0);
   
   TGraphAsymmErrors* gr_mc = makeErrorBand(h1c,h1c_up,h1c_low);
   gr_mc->SetFillColor(7);
   
   h1c->Draw("e1");
   
   gr_mc->Draw("2SAME");

   h1c->Draw("e1 same");

   gPad->RedrawAxis("g");

   c1_2->Update();
}

#endif
