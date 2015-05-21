void drawSFLOCAL()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x def.C");
   gROOT->ProcessLine(".x common.C");

   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);

   std::ifstream fSF("results/SF.txt");

   double pt1[100];
   double pt2[100];
   double pt[100];
   double pterr[100];
   double sf[100];
   double sferr[100];
   
   int idx = 0;
   while( !fSF.eof() )
     {	
	fSF >> pt1[idx] >> pt2[idx] >> sf[idx] >> sferr[idx];
	pt[idx] = pt1[idx]+(pt2[idx]-pt1[idx])/2.;
	pterr[idx] = 0.;
	idx++;
     }   

   TGraphErrors *gr = new TGraphErrors(idx,pt,sf,pterr,sferr);

   gr->Draw("AP");
   gr->GetXaxis()->SetRangeUser(0.02,1.0);
   
   c1->SetLogx(1);
   c1->Print("pics/SF.eps");
   c1->Clear();   
   
   gApplication->Terminate();
}
