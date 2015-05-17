void drawEFF()
{   
   std::string wp = "LOOSE";
   std::string j1 = "";
   std::string flav = "beauty";
   std::string typ = "2011FINALCSV_NEW";
//   std::string typ = "2011FINALCSV";
   std::string eff = "results/SF_"+j1+wp+"_"+typ+"_"+flav+".root";

   std::string off = "results/SF_OFFICIAL2011_"+wp+"_CSV.root";
   
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x def.C");
   gROOT->ProcessLine(".x common.C");

   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   c1->SetGrid(1);

   std::string csv = "#bf{CSVL}";
   if( wp == "MEDIUM" ) csv = "#bf{CSVM}";
   if( wp == "TIGHT" ) csv = "#bf{CSVT}";

   TFile *feff = TFile::Open(eff.c_str());
   
   TH1F *hEFFMC, *hEFFDATA;
   TPolyLine *hEFFMCSYS, *hEFFDATASYS;
   
   hEFFMC = (TH1F*)feff->Get("hEFFMC");
   hEFFMCSYS = (TPolyLine*)feff->Get("hEFFMCSYS");
   
   hEFFDATA = (TH1F*)feff->Get("hEFFDATA");
   hEFFDATASYS = (TPolyLine*)feff->Get("hEFFDATASYS");

   TFile *foff = TFile::Open(off.c_str());
   
   TH1F *hEFFMC_OFF, *hEFFDATA_OFF;
   TPolyLine *hEFFMCSYS_OFF, *hEFFDATASYS_OFF;
   
   hEFFMC_OFF = (TH1F*)foff->Get("OFF_EFFMC");
   hEFFMCSYS_OFF = (TPolyLine*)foff->Get("OFF_EFFSYSMC");
   
   hEFFDATA_OFF = (TH1F*)foff->Get("OFF_EFFDATA");
   hEFFDATASYS_OFF = (TPolyLine*)foff->Get("OFF_EFFSYSDATA");   

   if( flav == "beauty" )
     hEFFMC->GetYaxis()->SetTitle("b-tagging efficiency");
   else
     hEFFMC->GetYaxis()->SetTitle("c-tagging efficiency");
   hEFFMC->SetMarkerSize(0.8);
   hEFFMC->GetXaxis()->SetTitle("P_{T} [TeV]");

   if( flav == "beauty" )
     hEFFDATA->GetYaxis()->SetTitle("b-tagging efficiency");
   else
     hEFFDATA->GetYaxis()->SetTitle("c-tagging efficiency");
   hEFFDATA->SetMarkerSize(0.8);
   
   hEFFMC->Draw("e1p");

   hEFFMC->GetXaxis()->SetMoreLogLabels();
   
   if( flav == "beauty" )
     {	
	if( wp == "LOOSE" ) hEFFMC->GetYaxis()->SetRangeUser(0.5,1.0);
	if( wp == "MEDIUM" ) hEFFMC->GetYaxis()->SetRangeUser(0.3,0.9);
	if( wp == "TIGHT" ) hEFFMC->GetYaxis()->SetRangeUser(0.1,0.7);
     }
   else
     {
	if( wp == "LOOSE" ) hEFFMC->GetYaxis()->SetRangeUser(0.,0.8);
	if( wp == "MEDIUM" ) hEFFMC->GetYaxis()->SetRangeUser(0.,0.6);
	if( wp == "TIGHT" ) hEFFMC->GetYaxis()->SetRangeUser(0.,0.15);
     }  
   hEFFMCSYS->Draw("fSAME");
   hEFFMC->Draw("e1p same");

   hEFFMC_OFF->SetMarkerSize(0.8);
   hEFFMC_OFF->SetMarkerStyle(23);
   hEFFMC_OFF->SetMarkerColor(kRed);
   hEFFMC_OFF->SetLineColor(kRed);
   hEFFMC_OFF->Draw("p same");
   
   hEFFMCSYS_OFF->Draw("lSAME");
   
   TLegend *leg;
   leg = new TLegend(0.35,0.45,0.70,0.20);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
  
   TLatex *legl = new TLatex();
   legl->SetNDC();
   legl->SetTextAlign(22);
   legl->SetTextFont(63);
   legl->SetTextSizePixels(30);
   legl->DrawLatex(0.55,0.85,csv.c_str());

   TLatex *legl2 = new TLatex();
   legl2->SetNDC();
   legl2->SetTextAlign(22);
   legl2->SetTextFont(63);
   legl2->SetTextSizePixels(30);
   legl2->DrawLatex(0.80,0.85,"MC");

   leg->AddEntry(hEFFMC,"Efficiency","p");
   leg->AddEntry(hEFFMC,"stat","l");
   leg->AddEntry(hEFFMCSYS,"stat #oplus syst","f");
   
   leg->AddEntry(hEFFMC_OFF,"Efficiency (LT BTV-12-001)","p");                                                        
   leg->AddEntry(hEFFMCSYS_OFF,"stat #oplus syst (LT BTV-12-001)","f");

   leg->Draw();

   c1->SetLogx(1);
   c1->Print("pics/EFFMC.eps");
   c1->Clear();   

   hEFFDATA->Draw("e1p");
   
   hEFFDATA->GetXaxis()->SetMoreLogLabels();
   
   if( flav == "beauty" )
     {	
	if( wp == "LOOSE" ) hEFFDATA->GetYaxis()->SetRangeUser(0.5,1.0);
	if( wp == "MEDIUM" ) hEFFDATA->GetYaxis()->SetRangeUser(0.3,0.9);
	if( wp == "TIGHT" ) hEFFDATA->GetYaxis()->SetRangeUser(0.1,0.7);
     }
   else
     {
	if( wp == "LOOSE" ) hEFFDATA->GetYaxis()->SetRangeUser(0.,0.8);
	if( wp == "MEDIUM" ) hEFFDATA->GetYaxis()->SetRangeUser(0.,0.6);
	if( wp == "TIGHT" ) hEFFDATA->GetYaxis()->SetRangeUser(0.,0.15);
     }   
   hEFFDATASYS->Draw("fSAME");
   hEFFDATA->Draw("e1p same");

   hEFFDATA_OFF->SetMarkerSize(0.8);
   hEFFDATA_OFF->SetMarkerStyle(23);
   hEFFDATA_OFF->SetMarkerColor(kRed);
   hEFFDATA_OFF->SetLineColor(kRed);
   hEFFDATA_OFF->Draw("p same");
   
   hEFFDATASYS_OFF->Draw("lSAME");
   
   TLegend *legD;
   legD = new TLegend(0.35,0.45,0.70,0.20);
   legD->SetFillColor(253);
   legD->SetBorderSize(0);
  
   TLatex *legd = new TLatex();
   legd->SetNDC();
   legd->SetTextAlign(22);
   legd->SetTextFont(63);
   legd->SetTextSizePixels(30);
   legd->DrawLatex(0.55,0.85,csv.c_str());

   TLatex *legd2 = new TLatex();
   legd2->SetNDC();
   legd2->SetTextAlign(22);
   legd2->SetTextFont(63);
   legd2->SetTextSizePixels(30);
   legd2->DrawLatex(0.80,0.85,"Data");
   
   legD->AddEntry(hEFFDATA,"Efficiency","p");
   legD->AddEntry(hEFFDATA,"stat","l");
   legD->AddEntry(hEFFDATASYS,"stat #oplus syst","f");

   legD->AddEntry(hEFFDATA_OFF,"Efficiency (LT BTV-12-001)","p");                                                        
   legD->AddEntry(hEFFDATASYS_OFF,"stat #oplus syst (LT BTV-12-001)","f");
   
   legD->Draw();

   c1->SetLogx(1);
   c1->Print("pics/EFFDATA.eps");
   c1->Clear();   
   
   gApplication->Terminate();
}
