void toyMC()
{
   gROOT->SetBatch(1);

   float bf = 0.1;
   float cf = 1.;
   float lf = 1.;

   float bfd = 0.9;
   
//   float df = 1.;
   
   bf *= 0.02;
   cf *= 0.02;
   lf *= 0.02;
   
   TFile *f = TFile::Open("histCFIT/data.root","READ");
   
   TFile *fout = TFile::Open("toyMC.root","RECREATE");

   // NOSEL
   
   TH1F *h_j1_JP_bjet_pt20t30_nosel_nosel = (TH1F*)f->Get("h_j1_JP_bjet_pt20t30_nosel_nosel");
   h_j1_JP_bjet_pt20t30_nosel_nosel->Scale(bf);
   h_j1_JP_bjet_pt20t30_nosel_nosel->Write();
   TH1F *h_j1_JP_bjet_pt30t50_nosel_nosel = (TH1F*)f->Get("h_j1_JP_bjet_pt30t50_nosel_nosel");
   h_j1_JP_bjet_pt30t50_nosel_nosel->Scale(bf);
   h_j1_JP_bjet_pt30t50_nosel_nosel->Write();
   TH1F *h_j1_JP_bjet_pt50t70_nosel_nosel = (TH1F*)f->Get("h_j1_JP_bjet_pt50t70_nosel_nosel");
   h_j1_JP_bjet_pt50t70_nosel_nosel->Scale(bf);
   h_j1_JP_bjet_pt50t70_nosel_nosel->Write();
   TH1F *h_j1_JP_bjet_pt70t100_nosel_nosel = (TH1F*)f->Get("h_j1_JP_bjet_pt70t100_nosel_nosel");
   h_j1_JP_bjet_pt70t100_nosel_nosel->Scale(bf);
   h_j1_JP_bjet_pt70t100_nosel_nosel->Write();
   TH1F *h_j1_JP_bjet_pt100t140_nosel_nosel = (TH1F*)f->Get("h_j1_JP_bjet_pt100t140_nosel_nosel");
   h_j1_JP_bjet_pt100t140_nosel_nosel->Scale(bf);
   h_j1_JP_bjet_pt100t140_nosel_nosel->Write();
   TH1F *h_j1_JP_bjet_pt140t200_nosel_nosel = (TH1F*)f->Get("h_j1_JP_bjet_pt140t200_nosel_nosel");
   h_j1_JP_bjet_pt140t200_nosel_nosel->Scale(bf);
   h_j1_JP_bjet_pt140t200_nosel_nosel->Write();
   TH1F *h_j1_JP_bjet_pt200t300_nosel_nosel = (TH1F*)f->Get("h_j1_JP_bjet_pt200t300_nosel_nosel");
   h_j1_JP_bjet_pt200t300_nosel_nosel->Scale(bf);
   h_j1_JP_bjet_pt200t300_nosel_nosel->Write();
   TH1F *h_j1_JP_bjet_pt300t670_nosel_nosel = (TH1F*)f->Get("h_j1_JP_bjet_pt300t670_nosel_nosel");
   h_j1_JP_bjet_pt300t670_nosel_nosel->Scale(bf);
   h_j1_JP_bjet_pt300t670_nosel_nosel->Write();

   TH1F *h_j1_JP_cjet_pt20t30_nosel_nosel = (TH1F*)f->Get("h_j1_JP_cjet_pt20t30_nosel_nosel");
   h_j1_JP_cjet_pt20t30_nosel_nosel->Scale(cf);
   h_j1_JP_cjet_pt20t30_nosel_nosel->Write();
   TH1F *h_j1_JP_cjet_pt30t50_nosel_nosel = (TH1F*)f->Get("h_j1_JP_cjet_pt30t50_nosel_nosel");
   h_j1_JP_cjet_pt30t50_nosel_nosel->Scale(cf);
   h_j1_JP_cjet_pt30t50_nosel_nosel->Write();
   TH1F *h_j1_JP_cjet_pt50t70_nosel_nosel = (TH1F*)f->Get("h_j1_JP_cjet_pt50t70_nosel_nosel");
   h_j1_JP_cjet_pt50t70_nosel_nosel->Scale(cf);
   h_j1_JP_cjet_pt50t70_nosel_nosel->Write();
   TH1F *h_j1_JP_cjet_pt70t100_nosel_nosel = (TH1F*)f->Get("h_j1_JP_cjet_pt70t100_nosel_nosel");
   h_j1_JP_cjet_pt70t100_nosel_nosel->Scale(cf);
   h_j1_JP_cjet_pt70t100_nosel_nosel->Write();
   TH1F *h_j1_JP_cjet_pt100t140_nosel_nosel = (TH1F*)f->Get("h_j1_JP_cjet_pt100t140_nosel_nosel");
   h_j1_JP_cjet_pt100t140_nosel_nosel->Scale(cf);
   h_j1_JP_cjet_pt100t140_nosel_nosel->Write();
   TH1F *h_j1_JP_cjet_pt140t200_nosel_nosel = (TH1F*)f->Get("h_j1_JP_cjet_pt140t200_nosel_nosel");
   h_j1_JP_cjet_pt140t200_nosel_nosel->Scale(cf);
   h_j1_JP_cjet_pt140t200_nosel_nosel->Write();
   TH1F *h_j1_JP_cjet_pt200t300_nosel_nosel = (TH1F*)f->Get("h_j1_JP_cjet_pt200t300_nosel_nosel");
   h_j1_JP_cjet_pt200t300_nosel_nosel->Scale(cf);
   h_j1_JP_cjet_pt200t300_nosel_nosel->Write();
   TH1F *h_j1_JP_cjet_pt300t670_nosel_nosel = (TH1F*)f->Get("h_j1_JP_cjet_pt300t670_nosel_nosel");
   h_j1_JP_cjet_pt300t670_nosel_nosel->Scale(cf);
   h_j1_JP_cjet_pt300t670_nosel_nosel->Write();

   TH1F *h_j1_JP_ljet_pt20t30_nosel_nosel = (TH1F*)f->Get("h_j1_JP_ljet_pt20t30_nosel_nosel");
   h_j1_JP_ljet_pt20t30_nosel_nosel->Scale(lf);
   h_j1_JP_ljet_pt20t30_nosel_nosel->Write();
   TH1F *h_j1_JP_ljet_pt30t50_nosel_nosel = (TH1F*)f->Get("h_j1_JP_ljet_pt30t50_nosel_nosel");
   h_j1_JP_ljet_pt30t50_nosel_nosel->Scale(lf);
   h_j1_JP_ljet_pt30t50_nosel_nosel->Write();
   TH1F *h_j1_JP_ljet_pt50t70_nosel_nosel = (TH1F*)f->Get("h_j1_JP_ljet_pt50t70_nosel_nosel");
   h_j1_JP_ljet_pt50t70_nosel_nosel->Scale(lf);
   h_j1_JP_ljet_pt50t70_nosel_nosel->Write();
   TH1F *h_j1_JP_ljet_pt70t100_nosel_nosel = (TH1F*)f->Get("h_j1_JP_ljet_pt70t100_nosel_nosel");
   h_j1_JP_ljet_pt70t100_nosel_nosel->Scale(lf);
   h_j1_JP_ljet_pt70t100_nosel_nosel->Write();
   TH1F *h_j1_JP_ljet_pt100t140_nosel_nosel = (TH1F*)f->Get("h_j1_JP_ljet_pt100t140_nosel_nosel");
   h_j1_JP_ljet_pt100t140_nosel_nosel->Scale(lf);
   h_j1_JP_ljet_pt100t140_nosel_nosel->Write();
   TH1F *h_j1_JP_ljet_pt140t200_nosel_nosel = (TH1F*)f->Get("h_j1_JP_ljet_pt140t200_nosel_nosel");
   h_j1_JP_ljet_pt140t200_nosel_nosel->Scale(lf);
   h_j1_JP_ljet_pt140t200_nosel_nosel->Write();
   TH1F *h_j1_JP_ljet_pt200t300_nosel_nosel = (TH1F*)f->Get("h_j1_JP_ljet_pt200t300_nosel_nosel");
   h_j1_JP_ljet_pt200t300_nosel_nosel->Scale(lf);
   h_j1_JP_ljet_pt200t300_nosel_nosel->Write();
   TH1F *h_j1_JP_ljet_pt300t670_nosel_nosel = (TH1F*)f->Get("h_j1_JP_ljet_pt300t670_nosel_nosel");
   h_j1_JP_ljet_pt300t670_nosel_nosel->Scale(lf);
   h_j1_JP_ljet_pt300t670_nosel_nosel->Write();

   TH1F* h_j1_JP_ajet_pt20t30_nosel_nosel__DATA = (TH1F*)h_j1_JP_bjet_pt20t30_nosel_nosel->Clone("h_j1_JP_ajet_pt20t30_nosel_nosel__DATA");
//   h_j1_JP_ajet_pt20t30_nosel_nosel__DATA->Scale(bfd);
   h_j1_JP_ajet_pt20t30_nosel_nosel__DATA->Add(h_j1_JP_cjet_pt20t30_nosel_nosel);
   h_j1_JP_ajet_pt20t30_nosel_nosel__DATA->Add(h_j1_JP_ljet_pt20t30_nosel_nosel);
//   for(int i=1;i<=h_j1_JP_ajet_pt20t30_nosel_nosel__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt20t30_nosel_nosel__DATA->SetBinError(i,h_j1_JP_ajet_pt20t30_nosel_nosel__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt30t50_nosel_nosel__DATA = (TH1F*)h_j1_JP_bjet_pt30t50_nosel_nosel->Clone("h_j1_JP_ajet_pt30t50_nosel_nosel__DATA");
//   h_j1_JP_ajet_pt30t50_nosel_nosel__DATA->Scale(bfd);
   h_j1_JP_ajet_pt30t50_nosel_nosel__DATA->Add(h_j1_JP_cjet_pt30t50_nosel_nosel);
   h_j1_JP_ajet_pt30t50_nosel_nosel__DATA->Add(h_j1_JP_ljet_pt30t50_nosel_nosel);
//   for(int i=1;i<=h_j1_JP_ajet_pt30t50_nosel_nosel__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt30t50_nosel_nosel__DATA->SetBinError(i,h_j1_JP_ajet_pt30t50_nosel_nosel__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt50t70_nosel_nosel__DATA = (TH1F*)h_j1_JP_bjet_pt50t70_nosel_nosel->Clone("h_j1_JP_ajet_pt50t70_nosel_nosel__DATA");
//   h_j1_JP_ajet_pt50t70_nosel_nosel__DATA->Scale(bfd);
   h_j1_JP_ajet_pt50t70_nosel_nosel__DATA->Add(h_j1_JP_cjet_pt50t70_nosel_nosel);
   h_j1_JP_ajet_pt50t70_nosel_nosel__DATA->Add(h_j1_JP_ljet_pt50t70_nosel_nosel);
//   for(int i=1;i<=h_j1_JP_ajet_pt50t70_nosel_nosel__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt50t70_nosel_nosel__DATA->SetBinError(i,h_j1_JP_ajet_pt50t70_nosel_nosel__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt70t100_nosel_nosel__DATA = (TH1F*)h_j1_JP_bjet_pt70t100_nosel_nosel->Clone("h_j1_JP_ajet_pt70t100_nosel_nosel__DATA");
//   h_j1_JP_ajet_pt70t100_nosel_nosel__DATA->Scale(bfd);
   h_j1_JP_ajet_pt70t100_nosel_nosel__DATA->Add(h_j1_JP_cjet_pt70t100_nosel_nosel);
   h_j1_JP_ajet_pt70t100_nosel_nosel__DATA->Add(h_j1_JP_ljet_pt70t100_nosel_nosel);
//   for(int i=1;i<=h_j1_JP_ajet_pt70t100_nosel_nosel__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt70t100_nosel_nosel__DATA->SetBinError(i,h_j1_JP_ajet_pt70t100_nosel_nosel__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt100t140_nosel_nosel__DATA = (TH1F*)h_j1_JP_bjet_pt100t140_nosel_nosel->Clone("h_j1_JP_ajet_pt100t140_nosel_nosel__DATA");
//   h_j1_JP_ajet_pt100t140_nosel_nosel__DATA->Scale(bfd);
   h_j1_JP_ajet_pt100t140_nosel_nosel__DATA->Add(h_j1_JP_cjet_pt100t140_nosel_nosel);
   h_j1_JP_ajet_pt100t140_nosel_nosel__DATA->Add(h_j1_JP_ljet_pt100t140_nosel_nosel);
//   for(int i=1;i<=h_j1_JP_ajet_pt100t140_nosel_nosel__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt100t140_nosel_nosel__DATA->SetBinError(i,h_j1_JP_ajet_pt100t140_nosel_nosel__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt140t200_nosel_nosel__DATA = (TH1F*)h_j1_JP_bjet_pt140t200_nosel_nosel->Clone("h_j1_JP_ajet_pt140t200_nosel_nosel__DATA");
//   h_j1_JP_ajet_pt140t200_nosel_nosel__DATA->Scale(bfd);
   h_j1_JP_ajet_pt140t200_nosel_nosel__DATA->Add(h_j1_JP_cjet_pt140t200_nosel_nosel);
   h_j1_JP_ajet_pt140t200_nosel_nosel__DATA->Add(h_j1_JP_ljet_pt140t200_nosel_nosel);
//   for(int i=1;i<=h_j1_JP_ajet_pt140t200_nosel_nosel__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt140t200_nosel_nosel__DATA->SetBinError(i,h_j1_JP_ajet_pt140t200_nosel_nosel__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt200t300_nosel_nosel__DATA = (TH1F*)h_j1_JP_bjet_pt200t300_nosel_nosel->Clone("h_j1_JP_ajet_pt200t300_nosel_nosel__DATA");
//   h_j1_JP_ajet_pt200t300_nosel_nosel__DATA->Scale(bfd);
   h_j1_JP_ajet_pt200t300_nosel_nosel__DATA->Add(h_j1_JP_cjet_pt200t300_nosel_nosel);
   h_j1_JP_ajet_pt200t300_nosel_nosel__DATA->Add(h_j1_JP_ljet_pt200t300_nosel_nosel);
//   for(int i=1;i<=h_j1_JP_ajet_pt200t300_nosel_nosel__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt200t300_nosel_nosel__DATA->SetBinError(i,h_j1_JP_ajet_pt200t300_nosel_nosel__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt300t670_nosel_nosel__DATA = (TH1F*)h_j1_JP_bjet_pt300t670_nosel_nosel->Clone("h_j1_JP_ajet_pt300t670_nosel_nosel__DATA");
//   h_j1_JP_ajet_pt300t670_nosel_nosel__DATA->Scale(bfd);
   h_j1_JP_ajet_pt300t670_nosel_nosel__DATA->Add(h_j1_JP_cjet_pt300t670_nosel_nosel);
   h_j1_JP_ajet_pt300t670_nosel_nosel__DATA->Add(h_j1_JP_ljet_pt300t670_nosel_nosel);
//   for(int i=1;i<=h_j1_JP_ajet_pt300t670_nosel_nosel__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt300t670_nosel_nosel__DATA->SetBinError(i,h_j1_JP_ajet_pt300t670_nosel_nosel__DATA->GetBinError(i)*df);

   TRandom3 *genrand = new TRandom3;
   genrand->SetSeed(3454245);
   
   for(int i=1;i<h_j1_JP_ajet_pt20t30_nosel_nosel__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt20t30_nosel_nosel__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt20t30_nosel_nosel__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt20t30_nosel_nosel__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt30t50_nosel_nosel__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt30t50_nosel_nosel__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt30t50_nosel_nosel__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt30t50_nosel_nosel__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt50t70_nosel_nosel__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt50t70_nosel_nosel__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt50t70_nosel_nosel__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt50t70_nosel_nosel__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt70t100_nosel_nosel__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt70t100_nosel_nosel__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt70t100_nosel_nosel__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt70t100_nosel_nosel__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt100t140_nosel_nosel__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt100t140_nosel_nosel__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt100t140_nosel_nosel__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt100t140_nosel_nosel__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt140t200_nosel_nosel__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt140t200_nosel_nosel__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt140t200_nosel_nosel__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt140t200_nosel_nosel__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt200t300_nosel_nosel__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt200t300_nosel_nosel__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt200t300_nosel_nosel__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt200t300_nosel_nosel__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt300t670_nosel_nosel__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt300t670_nosel_nosel__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt300t670_nosel_nosel__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt300t670_nosel_nosel__DATA->SetBinError(i,sqrt(v));
     }   
   
   // UNTAGCSVM
   
   TH1F *h_j1_JP_bjet_pt20t30_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt20t30_nosel_UNTAGCSVM");
   h_j1_JP_bjet_pt20t30_nosel_UNTAGCSVM->Scale(bf);
   h_j1_JP_bjet_pt20t30_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_bjet_pt30t50_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt30t50_nosel_UNTAGCSVM");
   h_j1_JP_bjet_pt30t50_nosel_UNTAGCSVM->Scale(bf);
   h_j1_JP_bjet_pt30t50_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_bjet_pt50t70_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt50t70_nosel_UNTAGCSVM");
   h_j1_JP_bjet_pt50t70_nosel_UNTAGCSVM->Scale(bf);
   h_j1_JP_bjet_pt50t70_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_bjet_pt70t100_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt70t100_nosel_UNTAGCSVM");
   h_j1_JP_bjet_pt70t100_nosel_UNTAGCSVM->Scale(bf);
   h_j1_JP_bjet_pt70t100_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_bjet_pt100t140_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt100t140_nosel_UNTAGCSVM");
   h_j1_JP_bjet_pt100t140_nosel_UNTAGCSVM->Scale(bf);
   h_j1_JP_bjet_pt100t140_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_bjet_pt140t200_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt140t200_nosel_UNTAGCSVM");
   h_j1_JP_bjet_pt140t200_nosel_UNTAGCSVM->Scale(bf);
   h_j1_JP_bjet_pt140t200_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_bjet_pt200t300_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt200t300_nosel_UNTAGCSVM");
   h_j1_JP_bjet_pt200t300_nosel_UNTAGCSVM->Scale(bf);
   h_j1_JP_bjet_pt200t300_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_bjet_pt300t670_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt300t670_nosel_UNTAGCSVM");
   h_j1_JP_bjet_pt300t670_nosel_UNTAGCSVM->Scale(bf);
   h_j1_JP_bjet_pt300t670_nosel_UNTAGCSVM->Write();

   TH1F *h_j1_JP_cjet_pt20t30_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt20t30_nosel_UNTAGCSVM");
   h_j1_JP_cjet_pt20t30_nosel_UNTAGCSVM->Scale(cf);
   h_j1_JP_cjet_pt20t30_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_cjet_pt30t50_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt30t50_nosel_UNTAGCSVM");
   h_j1_JP_cjet_pt30t50_nosel_UNTAGCSVM->Scale(cf);
   h_j1_JP_cjet_pt30t50_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_cjet_pt50t70_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt50t70_nosel_UNTAGCSVM");
   h_j1_JP_cjet_pt50t70_nosel_UNTAGCSVM->Scale(cf);
   h_j1_JP_cjet_pt50t70_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_cjet_pt70t100_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt70t100_nosel_UNTAGCSVM");
   h_j1_JP_cjet_pt70t100_nosel_UNTAGCSVM->Scale(cf);
   h_j1_JP_cjet_pt70t100_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_cjet_pt100t140_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt100t140_nosel_UNTAGCSVM");
   h_j1_JP_cjet_pt100t140_nosel_UNTAGCSVM->Scale(cf);
   h_j1_JP_cjet_pt100t140_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_cjet_pt140t200_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt140t200_nosel_UNTAGCSVM");
   h_j1_JP_cjet_pt140t200_nosel_UNTAGCSVM->Scale(cf);
   h_j1_JP_cjet_pt140t200_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_cjet_pt200t300_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt200t300_nosel_UNTAGCSVM");
   h_j1_JP_cjet_pt200t300_nosel_UNTAGCSVM->Scale(cf);
   h_j1_JP_cjet_pt200t300_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_cjet_pt300t670_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt300t670_nosel_UNTAGCSVM");
   h_j1_JP_cjet_pt300t670_nosel_UNTAGCSVM->Scale(cf);
   h_j1_JP_cjet_pt300t670_nosel_UNTAGCSVM->Write();

   TH1F *h_j1_JP_ljet_pt20t30_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt20t30_nosel_UNTAGCSVM");
   h_j1_JP_ljet_pt20t30_nosel_UNTAGCSVM->Scale(lf);
   h_j1_JP_ljet_pt20t30_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_ljet_pt30t50_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt30t50_nosel_UNTAGCSVM");
   h_j1_JP_ljet_pt30t50_nosel_UNTAGCSVM->Scale(lf);
   h_j1_JP_ljet_pt30t50_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_ljet_pt50t70_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt50t70_nosel_UNTAGCSVM");
   h_j1_JP_ljet_pt50t70_nosel_UNTAGCSVM->Scale(lf);
   h_j1_JP_ljet_pt50t70_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_ljet_pt70t100_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt70t100_nosel_UNTAGCSVM");
   h_j1_JP_ljet_pt70t100_nosel_UNTAGCSVM->Scale(lf);
   h_j1_JP_ljet_pt70t100_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_ljet_pt100t140_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt100t140_nosel_UNTAGCSVM");
   h_j1_JP_ljet_pt100t140_nosel_UNTAGCSVM->Scale(lf);
   h_j1_JP_ljet_pt100t140_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_ljet_pt140t200_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt140t200_nosel_UNTAGCSVM");
   h_j1_JP_ljet_pt140t200_nosel_UNTAGCSVM->Scale(lf);
   h_j1_JP_ljet_pt140t200_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_ljet_pt200t300_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt200t300_nosel_UNTAGCSVM");
   h_j1_JP_ljet_pt200t300_nosel_UNTAGCSVM->Scale(lf);
   h_j1_JP_ljet_pt200t300_nosel_UNTAGCSVM->Write();
   TH1F *h_j1_JP_ljet_pt300t670_nosel_UNTAGCSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt300t670_nosel_UNTAGCSVM");
   h_j1_JP_ljet_pt300t670_nosel_UNTAGCSVM->Scale(lf);
   h_j1_JP_ljet_pt300t670_nosel_UNTAGCSVM->Write();

   TH1F* h_j1_JP_ajet_pt20t30_nosel_UNTAGCSVM__DATA = (TH1F*)h_j1_JP_bjet_pt20t30_nosel_UNTAGCSVM->Clone("h_j1_JP_ajet_pt20t30_nosel_UNTAGCSVM__DATA");
   h_j1_JP_ajet_pt20t30_nosel_UNTAGCSVM__DATA->Scale(1+(1-bfd));
   h_j1_JP_ajet_pt20t30_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_cjet_pt20t30_nosel_UNTAGCSVM);
   h_j1_JP_ajet_pt20t30_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_ljet_pt20t30_nosel_UNTAGCSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt20t30_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt20t30_nosel_UNTAGCSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt20t30_nosel_UNTAGCSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt30t50_nosel_UNTAGCSVM__DATA = (TH1F*)h_j1_JP_bjet_pt30t50_nosel_UNTAGCSVM->Clone("h_j1_JP_ajet_pt30t50_nosel_UNTAGCSVM__DATA");
   h_j1_JP_ajet_pt30t50_nosel_UNTAGCSVM__DATA->Scale(1+(1-bfd));
   h_j1_JP_ajet_pt30t50_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_cjet_pt30t50_nosel_UNTAGCSVM);
   h_j1_JP_ajet_pt30t50_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_ljet_pt30t50_nosel_UNTAGCSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt30t50_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt30t50_nosel_UNTAGCSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt30t50_nosel_UNTAGCSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt50t70_nosel_UNTAGCSVM__DATA = (TH1F*)h_j1_JP_bjet_pt50t70_nosel_UNTAGCSVM->Clone("h_j1_JP_ajet_pt50t70_nosel_UNTAGCSVM__DATA");
   h_j1_JP_ajet_pt50t70_nosel_UNTAGCSVM__DATA->Scale(1+(1-bfd));
   h_j1_JP_ajet_pt50t70_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_cjet_pt50t70_nosel_UNTAGCSVM);
   h_j1_JP_ajet_pt50t70_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_ljet_pt50t70_nosel_UNTAGCSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt50t70_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt50t70_nosel_UNTAGCSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt50t70_nosel_UNTAGCSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt70t100_nosel_UNTAGCSVM__DATA = (TH1F*)h_j1_JP_bjet_pt70t100_nosel_UNTAGCSVM->Clone("h_j1_JP_ajet_pt70t100_nosel_UNTAGCSVM__DATA");
   h_j1_JP_ajet_pt70t100_nosel_UNTAGCSVM__DATA->Scale(1+(1-bfd));
   h_j1_JP_ajet_pt70t100_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_cjet_pt70t100_nosel_UNTAGCSVM);
   h_j1_JP_ajet_pt70t100_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_ljet_pt70t100_nosel_UNTAGCSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt70t100_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt70t100_nosel_UNTAGCSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt70t100_nosel_UNTAGCSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt100t140_nosel_UNTAGCSVM__DATA = (TH1F*)h_j1_JP_bjet_pt100t140_nosel_UNTAGCSVM->Clone("h_j1_JP_ajet_pt100t140_nosel_UNTAGCSVM__DATA");
   h_j1_JP_ajet_pt100t140_nosel_UNTAGCSVM__DATA->Scale(1+(1-bfd));
   h_j1_JP_ajet_pt100t140_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_cjet_pt100t140_nosel_UNTAGCSVM);
   h_j1_JP_ajet_pt100t140_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_ljet_pt100t140_nosel_UNTAGCSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt100t140_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt100t140_nosel_UNTAGCSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt100t140_nosel_UNTAGCSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt140t200_nosel_UNTAGCSVM__DATA = (TH1F*)h_j1_JP_bjet_pt140t200_nosel_UNTAGCSVM->Clone("h_j1_JP_ajet_pt140t200_nosel_UNTAGCSVM__DATA");
   h_j1_JP_ajet_pt140t200_nosel_UNTAGCSVM__DATA->Scale(1+(1-bfd));
   h_j1_JP_ajet_pt140t200_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_cjet_pt140t200_nosel_UNTAGCSVM);
   h_j1_JP_ajet_pt140t200_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_ljet_pt140t200_nosel_UNTAGCSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt140t200_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt140t200_nosel_UNTAGCSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt140t200_nosel_UNTAGCSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt200t300_nosel_UNTAGCSVM__DATA = (TH1F*)h_j1_JP_bjet_pt200t300_nosel_UNTAGCSVM->Clone("h_j1_JP_ajet_pt200t300_nosel_UNTAGCSVM__DATA");
   h_j1_JP_ajet_pt200t300_nosel_UNTAGCSVM__DATA->Scale(1+(1-bfd));
   h_j1_JP_ajet_pt200t300_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_cjet_pt200t300_nosel_UNTAGCSVM);
   h_j1_JP_ajet_pt200t300_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_ljet_pt200t300_nosel_UNTAGCSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt200t300_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt200t300_nosel_UNTAGCSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt200t300_nosel_UNTAGCSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt300t670_nosel_UNTAGCSVM__DATA = (TH1F*)h_j1_JP_bjet_pt300t670_nosel_UNTAGCSVM->Clone("h_j1_JP_ajet_pt300t670_nosel_UNTAGCSVM__DATA");
   h_j1_JP_ajet_pt300t670_nosel_UNTAGCSVM__DATA->Scale(1+(1-bfd));
   h_j1_JP_ajet_pt300t670_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_cjet_pt300t670_nosel_UNTAGCSVM);
   h_j1_JP_ajet_pt300t670_nosel_UNTAGCSVM__DATA->Add(h_j1_JP_ljet_pt300t670_nosel_UNTAGCSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt300t670_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt300t670_nosel_UNTAGCSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt300t670_nosel_UNTAGCSVM__DATA->GetBinError(i)*df);

   for(int i=1;i<h_j1_JP_ajet_pt20t30_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt20t30_nosel_UNTAGCSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt20t30_nosel_UNTAGCSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt20t30_nosel_UNTAGCSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt30t50_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt30t50_nosel_UNTAGCSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt30t50_nosel_UNTAGCSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt30t50_nosel_UNTAGCSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt50t70_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt50t70_nosel_UNTAGCSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt50t70_nosel_UNTAGCSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt50t70_nosel_UNTAGCSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt70t100_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt70t100_nosel_UNTAGCSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt70t100_nosel_UNTAGCSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt70t100_nosel_UNTAGCSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt100t140_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt100t140_nosel_UNTAGCSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt100t140_nosel_UNTAGCSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt100t140_nosel_UNTAGCSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt140t200_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt140t200_nosel_UNTAGCSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt140t200_nosel_UNTAGCSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt140t200_nosel_UNTAGCSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt200t300_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt200t300_nosel_UNTAGCSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt200t300_nosel_UNTAGCSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt200t300_nosel_UNTAGCSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt300t670_nosel_UNTAGCSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt300t670_nosel_UNTAGCSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt300t670_nosel_UNTAGCSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt300t670_nosel_UNTAGCSVM__DATA->SetBinError(i,sqrt(v));
     }   

   // CSVM
   
   TH1F *h_j1_JP_bjet_pt20t30_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt20t30_nosel_CSVM");
   h_j1_JP_bjet_pt20t30_nosel_CSVM->Scale(bf);
   h_j1_JP_bjet_pt20t30_nosel_CSVM->Write();
   TH1F *h_j1_JP_bjet_pt30t50_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt30t50_nosel_CSVM");
   h_j1_JP_bjet_pt30t50_nosel_CSVM->Scale(bf);
   h_j1_JP_bjet_pt30t50_nosel_CSVM->Write();
   TH1F *h_j1_JP_bjet_pt50t70_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt50t70_nosel_CSVM");
   h_j1_JP_bjet_pt50t70_nosel_CSVM->Scale(bf);
   h_j1_JP_bjet_pt50t70_nosel_CSVM->Write();
   TH1F *h_j1_JP_bjet_pt70t100_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt70t100_nosel_CSVM");
   h_j1_JP_bjet_pt70t100_nosel_CSVM->Scale(bf);
   h_j1_JP_bjet_pt70t100_nosel_CSVM->Write();
   TH1F *h_j1_JP_bjet_pt100t140_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt100t140_nosel_CSVM");
   h_j1_JP_bjet_pt100t140_nosel_CSVM->Scale(bf);
   h_j1_JP_bjet_pt100t140_nosel_CSVM->Write();
   TH1F *h_j1_JP_bjet_pt140t200_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt140t200_nosel_CSVM");
   h_j1_JP_bjet_pt140t200_nosel_CSVM->Scale(bf);
   h_j1_JP_bjet_pt140t200_nosel_CSVM->Write();
   TH1F *h_j1_JP_bjet_pt200t300_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt200t300_nosel_CSVM");
   h_j1_JP_bjet_pt200t300_nosel_CSVM->Scale(bf);
   h_j1_JP_bjet_pt200t300_nosel_CSVM->Write();
   TH1F *h_j1_JP_bjet_pt300t670_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_bjet_pt300t670_nosel_CSVM");
   h_j1_JP_bjet_pt300t670_nosel_CSVM->Scale(bf);
   h_j1_JP_bjet_pt300t670_nosel_CSVM->Write();

   TH1F *h_j1_JP_cjet_pt20t30_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt20t30_nosel_CSVM");
   h_j1_JP_cjet_pt20t30_nosel_CSVM->Scale(cf);
   h_j1_JP_cjet_pt20t30_nosel_CSVM->Write();
   TH1F *h_j1_JP_cjet_pt30t50_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt30t50_nosel_CSVM");
   h_j1_JP_cjet_pt30t50_nosel_CSVM->Scale(cf);
   h_j1_JP_cjet_pt30t50_nosel_CSVM->Write();
   TH1F *h_j1_JP_cjet_pt50t70_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt50t70_nosel_CSVM");
   h_j1_JP_cjet_pt50t70_nosel_CSVM->Scale(cf);
   h_j1_JP_cjet_pt50t70_nosel_CSVM->Write();
   TH1F *h_j1_JP_cjet_pt70t100_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt70t100_nosel_CSVM");
   h_j1_JP_cjet_pt70t100_nosel_CSVM->Scale(cf);
   h_j1_JP_cjet_pt70t100_nosel_CSVM->Write();
   TH1F *h_j1_JP_cjet_pt100t140_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt100t140_nosel_CSVM");
   h_j1_JP_cjet_pt100t140_nosel_CSVM->Scale(cf);
   h_j1_JP_cjet_pt100t140_nosel_CSVM->Write();
   TH1F *h_j1_JP_cjet_pt140t200_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt140t200_nosel_CSVM");
   h_j1_JP_cjet_pt140t200_nosel_CSVM->Scale(cf);
   h_j1_JP_cjet_pt140t200_nosel_CSVM->Write();
   TH1F *h_j1_JP_cjet_pt200t300_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt200t300_nosel_CSVM");
   h_j1_JP_cjet_pt200t300_nosel_CSVM->Scale(cf);
   h_j1_JP_cjet_pt200t300_nosel_CSVM->Write();
   TH1F *h_j1_JP_cjet_pt300t670_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_cjet_pt300t670_nosel_CSVM");
   h_j1_JP_cjet_pt300t670_nosel_CSVM->Scale(cf);
   h_j1_JP_cjet_pt300t670_nosel_CSVM->Write();

   TH1F *h_j1_JP_ljet_pt20t30_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt20t30_nosel_CSVM");
   h_j1_JP_ljet_pt20t30_nosel_CSVM->Scale(lf);
   h_j1_JP_ljet_pt20t30_nosel_CSVM->Write();
   TH1F *h_j1_JP_ljet_pt30t50_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt30t50_nosel_CSVM");
   h_j1_JP_ljet_pt30t50_nosel_CSVM->Scale(lf);
   h_j1_JP_ljet_pt30t50_nosel_CSVM->Write();
   TH1F *h_j1_JP_ljet_pt50t70_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt50t70_nosel_CSVM");
   h_j1_JP_ljet_pt50t70_nosel_CSVM->Scale(lf);
   h_j1_JP_ljet_pt50t70_nosel_CSVM->Write();
   TH1F *h_j1_JP_ljet_pt70t100_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt70t100_nosel_CSVM");
   h_j1_JP_ljet_pt70t100_nosel_CSVM->Scale(lf);
   h_j1_JP_ljet_pt70t100_nosel_CSVM->Write();
   TH1F *h_j1_JP_ljet_pt100t140_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt100t140_nosel_CSVM");
   h_j1_JP_ljet_pt100t140_nosel_CSVM->Scale(lf);
   h_j1_JP_ljet_pt100t140_nosel_CSVM->Write();
   TH1F *h_j1_JP_ljet_pt140t200_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt140t200_nosel_CSVM");
   h_j1_JP_ljet_pt140t200_nosel_CSVM->Scale(lf);
   h_j1_JP_ljet_pt140t200_nosel_CSVM->Write();
   TH1F *h_j1_JP_ljet_pt200t300_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt200t300_nosel_CSVM");
   h_j1_JP_ljet_pt200t300_nosel_CSVM->Scale(lf);
   h_j1_JP_ljet_pt200t300_nosel_CSVM->Write();
   TH1F *h_j1_JP_ljet_pt300t670_nosel_CSVM = (TH1F*)f->Get("h_j1_JP_ljet_pt300t670_nosel_CSVM");
   h_j1_JP_ljet_pt300t670_nosel_CSVM->Scale(lf);
   h_j1_JP_ljet_pt300t670_nosel_CSVM->Write();

   TH1F* h_j1_JP_ajet_pt20t30_nosel_CSVM__DATA = (TH1F*)h_j1_JP_bjet_pt20t30_nosel_CSVM->Clone("h_j1_JP_ajet_pt20t30_nosel_CSVM__DATA");
   h_j1_JP_ajet_pt20t30_nosel_CSVM__DATA->Scale(bfd);
   h_j1_JP_ajet_pt20t30_nosel_CSVM__DATA->Add(h_j1_JP_cjet_pt20t30_nosel_CSVM);
   h_j1_JP_ajet_pt20t30_nosel_CSVM__DATA->Add(h_j1_JP_ljet_pt20t30_nosel_CSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt20t30_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt20t30_nosel_CSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt20t30_nosel_CSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA = (TH1F*)h_j1_JP_bjet_pt30t50_nosel_CSVM->Clone("h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA");
   h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA->Scale(bfd);
   h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA->Add(h_j1_JP_cjet_pt30t50_nosel_CSVM);
   h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA->Add(h_j1_JP_ljet_pt30t50_nosel_CSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt50t70_nosel_CSVM__DATA = (TH1F*)h_j1_JP_bjet_pt50t70_nosel_CSVM->Clone("h_j1_JP_ajet_pt50t70_nosel_CSVM__DATA");
   h_j1_JP_ajet_pt50t70_nosel_CSVM__DATA->Scale(bfd);
   h_j1_JP_ajet_pt50t70_nosel_CSVM__DATA->Add(h_j1_JP_cjet_pt50t70_nosel_CSVM);
   h_j1_JP_ajet_pt50t70_nosel_CSVM__DATA->Add(h_j1_JP_ljet_pt50t70_nosel_CSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt70t100_nosel_CSVM__DATA = (TH1F*)h_j1_JP_bjet_pt70t100_nosel_CSVM->Clone("h_j1_JP_ajet_pt70t100_nosel_CSVM__DATA");
   h_j1_JP_ajet_pt70t100_nosel_CSVM__DATA->Scale(bfd);
   h_j1_JP_ajet_pt70t100_nosel_CSVM__DATA->Add(h_j1_JP_cjet_pt70t100_nosel_CSVM);
   h_j1_JP_ajet_pt70t100_nosel_CSVM__DATA->Add(h_j1_JP_ljet_pt70t100_nosel_CSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt70t100_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt70t100_nosel_CSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt70t100_nosel_CSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt100t140_nosel_CSVM__DATA = (TH1F*)h_j1_JP_bjet_pt100t140_nosel_CSVM->Clone("h_j1_JP_ajet_pt100t140_nosel_CSVM__DATA");
   h_j1_JP_ajet_pt100t140_nosel_CSVM__DATA->Scale(bfd);
   h_j1_JP_ajet_pt100t140_nosel_CSVM__DATA->Add(h_j1_JP_cjet_pt100t140_nosel_CSVM);
   h_j1_JP_ajet_pt100t140_nosel_CSVM__DATA->Add(h_j1_JP_ljet_pt100t140_nosel_CSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt100t140_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt100t140_nosel_CSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt100t140_nosel_CSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt140t200_nosel_CSVM__DATA = (TH1F*)h_j1_JP_bjet_pt140t200_nosel_CSVM->Clone("h_j1_JP_ajet_pt140t200_nosel_CSVM__DATA");
   h_j1_JP_ajet_pt140t200_nosel_CSVM__DATA->Scale(bfd);
   h_j1_JP_ajet_pt140t200_nosel_CSVM__DATA->Add(h_j1_JP_cjet_pt140t200_nosel_CSVM);
   h_j1_JP_ajet_pt140t200_nosel_CSVM__DATA->Add(h_j1_JP_ljet_pt140t200_nosel_CSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt140t200_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt140t200_nosel_CSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt140t200_nosel_CSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt200t300_nosel_CSVM__DATA = (TH1F*)h_j1_JP_bjet_pt200t300_nosel_CSVM->Clone("h_j1_JP_ajet_pt200t300_nosel_CSVM__DATA");
   h_j1_JP_ajet_pt200t300_nosel_CSVM__DATA->Scale(bfd);
   h_j1_JP_ajet_pt200t300_nosel_CSVM__DATA->Add(h_j1_JP_cjet_pt200t300_nosel_CSVM);
   h_j1_JP_ajet_pt200t300_nosel_CSVM__DATA->Add(h_j1_JP_ljet_pt200t300_nosel_CSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt200t300_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt200t300_nosel_CSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt200t300_nosel_CSVM__DATA->GetBinError(i)*df);
   TH1F* h_j1_JP_ajet_pt300t670_nosel_CSVM__DATA = (TH1F*)h_j1_JP_bjet_pt300t670_nosel_CSVM->Clone("h_j1_JP_ajet_pt300t670_nosel_CSVM__DATA");
   h_j1_JP_ajet_pt300t670_nosel_CSVM__DATA->Scale(bfd);
   h_j1_JP_ajet_pt300t670_nosel_CSVM__DATA->Add(h_j1_JP_cjet_pt300t670_nosel_CSVM);
   h_j1_JP_ajet_pt300t670_nosel_CSVM__DATA->Add(h_j1_JP_ljet_pt300t670_nosel_CSVM);
//   for(int i=1;i<=h_j1_JP_ajet_pt300t670_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++) h_j1_JP_ajet_pt300t670_nosel_CSVM__DATA->SetBinError(i,h_j1_JP_ajet_pt300t670_nosel_CSVM__DATA->GetBinError(i)*df);

   for(int i=1;i<h_j1_JP_ajet_pt20t30_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt20t30_nosel_CSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt20t30_nosel_CSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt20t30_nosel_CSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt30t50_nosel_CSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt50t70_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt50t70_nosel_CSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt50t70_nosel_CSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt50t70_nosel_CSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt70t100_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt70t100_nosel_CSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt70t100_nosel_CSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt70t100_nosel_CSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt100t140_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt100t140_nosel_CSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt100t140_nosel_CSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt100t140_nosel_CSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt140t200_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt140t200_nosel_CSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt140t200_nosel_CSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt140t200_nosel_CSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt200t300_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt200t300_nosel_CSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt200t300_nosel_CSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt200t300_nosel_CSVM__DATA->SetBinError(i,sqrt(v));
     }   
   for(int i=1;i<h_j1_JP_ajet_pt300t670_nosel_CSVM__DATA->GetXaxis()->GetNbins();i++)
     {	
	float v = h_j1_JP_ajet_pt300t670_nosel_CSVM__DATA->GetBinContent(i);
	h_j1_JP_ajet_pt300t670_nosel_CSVM__DATA->SetBinContent(i,genrand->Poisson(v));
	h_j1_JP_ajet_pt300t670_nosel_CSVM__DATA->SetBinError(i,sqrt(v));
     }   
   
   fout->Write();
   fout->Close();
   
   f->Close();
   
   gApplication->Terminate();
}
