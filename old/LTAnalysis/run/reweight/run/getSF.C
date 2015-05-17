{
   gROOT->SetBatch();
   
   TFile f("results/fit_EFF_beauty_ALL.root");

   TH1F *hSF = (TH1F*)f.Get("h1c");
   
   std::ofstream fSF("results/SF.txt");
   
   int nb = hSF->GetXaxis()->GetNbins();
   for(int ib=1;ib<=nb;ib++)
     {
	float pt1 = hSF->GetXaxis()->GetBinLowEdge(ib);
	float pt2 = hSF->GetXaxis()->GetBinUpEdge(ib);
	float sf = hSF->GetBinContent(ib);
	float sferr = hSF->GetBinError(ib);
	
	fSF << pt1 << " " << pt2 << " " << sf << " " << sferr << std::endl;
     }   
   
   fSF.close();
   
   gApplication->Terminate();
}
