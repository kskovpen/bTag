void getEntriesRoot(std::string filein)
{
   gROOT->SetBatch();
   
   float nw0 = 0;
   
   TFile *f = TFile::Open(filein.c_str());
   TH1F* h_new = (TH1F*)f->Get("allEvents/hEventCount");
   nw0 += h_new->GetBinContent(1);
   f->Close();

   std::cout << nw0 << std::endl;
      
   gApplication->Terminate();
}
