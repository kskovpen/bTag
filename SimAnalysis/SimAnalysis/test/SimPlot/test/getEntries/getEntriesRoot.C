void getEntriesRoot(std::string filein)
{
   gROOT->SetBatch();
   
   float nw0 = 0;
   float nc0 = 0;
   
   TFile *f = TFile::Open(filein.c_str());
   TH1F* h_count = (TH1F*)f->Get("SimTree/hcount");
   nc0 += h_count->GetBinContent(1);
   f->Close();

   std::cout << nw0 << " " << nc0 << std::endl;
      
   gApplication->Terminate();
}
