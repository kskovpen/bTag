void getEntriesRoot(std::string filein)
{
   gROOT->SetBatch();
   
   float nw0 = 0;
   float nc0 = 0;
   
/*   TFile *f = TFile::Open(filein.c_str());
   TH1F* h_weight = (TH1F*)f->Get("FlatTree/hweight");
   nw0 += h_weight->GetBinContent(1);
   TH1F* h_count = (TH1F*)f->Get("FlatTree/hcount");
   nc0 += h_count->GetBinContent(1);
   f->Close();
   
   std::cout << nw0 << " " << nc0 << std::endl;*/

   TFile *f = TFile::Open(filein.c_str());
   TH1F* h_count = (TH1F*)f->Get("allEvents/hEventCount");
   nc0 += h_count->GetBinContent(1);
   f->Close();
   
   std::cout << nc0 << " " << nc0 << std::endl;
   
   gApplication->Terminate();
}
