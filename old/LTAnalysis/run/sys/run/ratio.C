void ratio(TCanvas *c1, TH1F* h1, THStack* h2)
{
   TH1F* h2e = (TH1F*)h1->Clone("h2e");
   h2e->Reset();
   
   TList *li = h2->GetHists();
   TIter iter(li);
   TObject* obj = 0;
   while ((obj = iter()))     
     h2e->Add((TH1F*)obj);

   TH1F* h1c = (TH1F*)h1->Clone("h1c");

   h1c->Divide(h1c,h2e,1,1,"");
 
   c1->cd();
   TPad *c1_2 = new TPad("c1_2", "ratio",0.01,0.01,0.99,0.37);
   c1_2->Draw();
   c1_2->cd();  
   c1_2->SetBottomMargin(0.37);
   c1_2->SetGrid(0,1);
   
   h1c->SetMarkerStyle(20);
   h1c->SetMarkerSize(0.8);
   h1c->GetYaxis()->SetNdivisions(5);
   h1c->GetYaxis()->SetTitle("Data/SM");
   
   h1c->GetYaxis()->SetTitleSize((h1c->GetYaxis()->GetTitleSize())*2);
   h1c->GetYaxis()->SetTitleOffset(h1c->GetYaxis()->GetTitleOffset()/2);
   h1c->GetXaxis()->SetTitleSize((h1c->GetXaxis()->GetTitleSize())*2);
   h1c->GetXaxis()->SetTitleOffset(h1c->GetXaxis()->GetTitleOffset()+0.2);

   h1c->GetYaxis()->SetLabelSize((h1c->GetYaxis()->GetLabelSize())*2);
   h1c->GetXaxis()->SetLabelSize((h1c->GetXaxis()->GetLabelSize())*2);

   h1c->GetXaxis()->SetTitle(h1c->GetXaxis()->GetTitle());

   h1c->GetYaxis()->SetRangeUser(0.3,1.8);
   
   h1c->Draw("e1");
   c1->Update();
}
