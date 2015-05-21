void drawSF()
{
   std::string btag = "TCHP"; // CSV or TCHP
   std::string wp = "TIGHT";
   std::string j1 = ""; // empty or J1
   std::string lab = "TEST";
//   std::string lab = "AwayTag";
//   std::string lab = "l-jets -20%";
   std::string flav = "beauty"; // beauty or charm
//   std::string addname1 = "2011FINALCSV_SYS1NEW";
//   std::string addname1 = "2011FINAL"+btag+"_18";
   std::string addname1 = "2011FINAL"+btag;
//   std::string addname1 = "2011FINALCSV_CENTRAL";
//   std::string addname1 = "2011TCHPv2";
//   std::string addname2 = "MAX_NOCOR";
//   std::string addname2 = "MAX";
   std::string addname2 = "ATT_NOCOR";
   bool sf2isMy = 0;
   std::string sf1 = "results/SF_"+wp+"_"+addname1+"_"+flav+".root";
   std::string sf2 = "results/SF_OFFICIAL_"+wp+".root";
   std::size_t found2011 = addname1.find("2011FINAL");
   bool fl_found2011 = (found2011 != std::string::npos);
   if( fl_found2011 ) sf2 = "results/SF_OFFICIAL2011_"+wp+"_"+btag+".root";
//   std::string sf2 = "results/SF_"+j1+wp+"_"+addname2+"_"+flav+".root";
   
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x def.C");
   gROOT->ProcessLine(".x common.C");

   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   c1->SetGrid(1);

   std::string csv = "#bf{"+btag+"L}";
   if( wp == "MEDIUM" ) csv = "#bf{"+btag+"M}";
   if( wp == "TIGHT" ) csv = "#bf{"+btag+"T}";

   TFile *fsf1 = TFile::Open(sf1.c_str());
   TFile *fsf2 = TFile::Open(sf2.c_str());
   
   TH1F *hSF1, *hSF2;
   TPolyLine *hSFSYS1, *hSFSYS2;
   
   hSF1 = (TH1F*)fsf1->Get("hSF");
   hSFSYS1 = (TPolyLine*)fsf1->Get("hSFSYS");
   
   if( sf2isMy )
     {
	hSF2 = (TH1F*)fsf2->Get("hSF");
	hSFSYS2 = (TPolyLine*)fsf2->Get("hSFSYS");	
     }   
   else
     {
	if( !fl_found2011 )
	  {
	     hSF2 = (TH1F*)fsf2->Get("LT_SF");
	     hSFSYS2 = (TPolyLine*)fsf2->Get("LT_SFSYS");
	  }	
	else
	  {
	     hSF2 = (TH1F*)fsf2->Get("OFF_SF");
	     hSFSYS2 = (TPolyLine*)fsf2->Get("OFF_SFSYS");
	  }	
     }   
   
   if( flav == "beauty" )
     hSF1->GetYaxis()->SetTitle("SF_{b}");
   else
     hSF1->GetYaxis()->SetTitle("SF");
//   hSF1->GetYaxis()->SetTitle("SF_{c}");
   hSF1->SetMarkerSize(0.8);

   hSF1->Draw("e1p");
   
   hSF1->GetXaxis()->SetMoreLogLabels(); 

   if( flav == "beauty" )
     hSF1->GetYaxis()->SetRangeUser(0.40,1.30);
   else
     hSF1->GetYaxis()->SetRangeUser(0.40,1.40);   
//   hSF1->GetYaxis()->SetRangeUser(0.40,3.50);
   
   hSFSYS1->Draw("fSAME");

   hSF1->Draw("e1p same");
   
   hSF2->SetMarkerSize(0.8);
   hSF2->SetMarkerStyle(23);
   hSF2->SetMarkerColor(kRed);
   hSF2->SetLineColor(kRed);
   hSF2->Draw("p same");
   
   hSFSYS2->Draw("lSAME");

   TLegend *leg;
   leg = new TLegend(0.35,0.45,0.70,0.20);
//   leg = new TLegend(0.20,0.90,0.50,0.60);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
  
   TLatex *legl = new TLatex();
   legl->SetNDC();
   legl->SetTextAlign(22);
   legl->SetTextFont(63);
   legl->SetTextSizePixels(30);
   legl->DrawLatex(0.55,0.85,csv.c_str());
//   legl->DrawLatex(0.60,0.85,csv.c_str());

//   if( flav == "beauty" )
//     {	
	leg->AddEntry(hSF1,"Scale factor","p");
	leg->AddEntry(hSF1,"stat","l");
	leg->AddEntry(hSFSYS1,"stat #oplus syst","f");
/*     }
   else
     {
	leg->AddEntry(hSF1,"Scale factor (b-jets)","p");
	leg->AddEntry(hSF1,"stat (b-jets)","l");
	leg->AddEntry(hSFSYS1,"stat #oplus syst (b-jets)","f");
     }*/
   
   if( sf2isMy )
     {
	std::string l1name = "Scale factor ("+lab+")";
	leg->AddEntry(hSF2,l1name.c_str(),"p");
	std::string l2name = "stat ("+lab+")";
	hSF2->SetLineStyle(2);
	hSF2->SetMarkerColor(kBlue);
	hSF2->SetLineColor(kBlue);
	hSFSYS2->SetFillColor(0);
	hSFSYS2->SetLineStyle(2);
	hSFSYS2->SetLineColor(kBlue);
	leg->AddEntry(hSF2,l2name.c_str(),"l");
	std::string l3name = "stat #oplus syst ("+lab+")";
	leg->AddEntry(hSFSYS2,l3name.c_str(),"f");
     }
   else
     {
	if( !fl_found2011 )
	  {	     
	     leg->AddEntry(hSF2,"Scale factor (LT EPS13)","p");
	     leg->AddEntry(hSFSYS2,"stat #oplus syst (LT EPS13)","f");
	  }	
	else
	  {	     
	     leg->AddEntry(hSF2,"Scale factor (LT BTV-12-001)","p");
	     leg->AddEntry(hSFSYS2,"stat #oplus syst (LT BTV-12-001)","f");
	  }	
     }   
   
   c1->RedrawAxis("g");
   
   leg->Draw();

   c1->SetLogx(1);
   c1->Print("pics/SF.eps");
   c1->Clear();   
   
   gApplication->Terminate();
}
