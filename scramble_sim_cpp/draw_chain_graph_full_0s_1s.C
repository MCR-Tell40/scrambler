void draw_chain_graph_full_0s_1s()
{
  TFile *f1 = new TFile("0_longest_chain_full.root");

  TH1F *un_scramble_hist = (TH1F*)f1->Get("desync9X_scrambler_hist");
  TH1F *Karol_scramble_hist = (TH1F*)f1->Get("Karol_scrambler_hist");
  TH1F *additive_scramble_hist = (TH1F*)f1->Get("additive_scrambler_hist");
  TH1F *Velopix_scramble_hist = (TH1F*)f1->Get("Velopix_scrambler_hist");
  TH1F *Random_data_hist = (TH1F*)f1->Get("Random_data_hist");


  TFile *f2 = new TFile("1_longest_chain_full.root");

  TH1F *un_scramble_hist_1 = (TH1F*)f2->Get("desync9X_scrambler_hist");
  TH1F *Karol_scramble_hist_1 = (TH1F*)f2->Get("Karol_scrambler_hist");
  TH1F *additive_scramble_hist_1 = (TH1F*)f2->Get("additive_scrambler_hist");
  TH1F *Velopix_scramble_hist_1 = (TH1F*)f2->Get("Velopix_scrambler_hist");
  TH1F *Random_data_hist_1 = (TH1F*)f2->Get("Random_data_hist");


  // gStyle->SetOptStat(0000000000);
  // gStyle->SetOptFit(11);
  // gStyle->SetStatW(0.12);                
  // gStyle->SetStatH(0.12);  
  
  TCanvas *c1 = new TCanvas("c1","Chain Length",900,800);

  c1->Divide(1,2,0.01,0.01);

  c1->cd(1);
  
  // Pre Scramble

  un_scramble_hist->Draw("");
  un_scramble_hist->SetLineColor(6);
  un_scramble_hist->SetLineStyle(1);
  un_scramble_hist->SetLineWidth(3);
  //un_scramble_hist->Fit("gaus");
  //un_scramble_hist->GetFunction("gaus")->SetLineColor(1); 
  un_scramble_hist->SetStats(0);
  un_scramble_hist->GetYaxis()->SetLabelSize(0.06);
  un_scramble_hist->GetXaxis()->SetLabelSize(0.06);
  un_scramble_hist->GetYaxis()->SetTitleSize(0.052);
  un_scramble_hist->GetXaxis()->SetTitleSize(0.052);

  un_scramble_hist->SetTitle(0);
  un_scramble_hist->GetXaxis()->SetTitle("Chain Length");
  un_scramble_hist->GetYaxis()->SetTitle("Entries");

  un_scramble_hist->GetXaxis()->SetRangeUser(1,35);

  // Karol Scramble
  Karol_scramble_hist->Draw("sames");
  Karol_scramble_hist->SetTitle(0);
  Karol_scramble_hist->SetLineColor(2);
  Karol_scramble_hist->SetLineStyle(1);
  Karol_scramble_hist->SetLineWidth(3);
  //Karol_scramble_hist->Fit("gaus"); 
  //Karol_scramble_hist->GetFunction("gaus")->SetLineColor(2);
 
  //Karol_scramble_hist->GetYaxis()->SetRangeUser(5000);
  

  Karol_scramble_hist->SetStats(0);




   
  // Additive Scramble
  additive_scramble_hist->Draw("sames");
  additive_scramble_hist->SetLineColor(4);
  additive_scramble_hist->SetLineStyle(7);
  additive_scramble_hist->SetLineWidth(3);
  //additive_scramble_hist->Fit("gaus"); 
  //additive_scramble_hist->GetFunction("gaus")->SetLineColor(4); 
  additive_scramble_hist->SetStats(0);

 //Velopix Scramble
  Velopix_scramble_hist->Draw("sames");
  Velopix_scramble_hist->SetLineColor(7);
  Velopix_scramble_hist->SetLineStyle(5);
  Velopix_scramble_hist->SetLineWidth(3);
  //Velopix_scramble_hist->Fit("gaus"); 
  //Velopix_scramble_hist->GetFunction("gaus")->SetLineColor(4); 
  Velopix_scramble_hist->SetStats(0);



//Random data
  Random_data_hist->Draw("sames");
  Random_data_hist->SetLineColor(1);
  Random_data_hist->SetLineStyle(6);
  Random_data_hist->SetLineWidth(3);
  //VRandom_data_hist->Fit("gaus"); 
  //Random_data_hist->GetFunction("gaus")->SetLineColor(4); 
  Random_data_hist->SetStats(0);



  
  // Legend
  leg_top = new TLegend(0.65,0.6,0.9,0.9);
  leg_top->AddEntry(un_scramble_hist,"Pre Scrambler","l");
  leg_top->AddEntry(Karol_scramble_hist,"Intermediate Scrambler","l");
  leg_top->AddEntry(additive_scramble_hist,"Additive Scrambler","l");
  leg_top->AddEntry(Velopix_scramble_hist,"Velopix Scrambler","l");
  leg_top->AddEntry(Random_data_hist,"Random Data","l");
  leg_top->Draw();

  c1->Pad()->SetLogy();
  c1->Pad()->SetGridy();


TPaveText *myText= new TPaveText(0.25,0.92,0.51,0.99, "NDC");
//NDC sets coords relative to pad
myText->SetTextSize(0.05);
myText->SetFillColor(0);        
//white background
myText->SetTextAlign(12);
myTextEntry=myText->AddText("Histogram of Chains of 0s");
myText->Draw();



  //----------------------Bottom graph-------------//
  c1->cd(2);
  



  // Pre Scramble
  un_scramble_hist_1->Draw("");
  un_scramble_hist_1->SetLineColor(6);
  un_scramble_hist_1->SetLineStyle(1);
  un_scramble_hist_1->SetLineWidth(3);
  //un_scramble_hist->Fit("gaus");
  //un_scramble_hist->GetFunction("gaus")->SetLineColor(1);
  un_scramble_hist_1->SetTitle(0);
  un_scramble_hist_1->GetXaxis()->SetTitle("Chain Length");
  un_scramble_hist_1->GetYaxis()->SetTitle("Entries");
 
  un_scramble_hist_1->SetStats(0);

  un_scramble_hist_1->GetYaxis()->SetLabelSize(0.06);
  un_scramble_hist_1->GetXaxis()->SetLabelSize(0.06);
  un_scramble_hist_1->GetYaxis()->SetTitleSize(0.052);
  un_scramble_hist_1->GetXaxis()->SetTitleSize(0.052);


  un_scramble_hist_1->GetXaxis()->SetRangeUser(1,35);
   

  // Karol Scramble
  Karol_scramble_hist_1->Draw("sames");
  Karol_scramble_hist_1->SetLineColor(2);
  Karol_scramble_hist_1->SetLineStyle(1);
  Karol_scramble_hist_1->SetLineWidth(3);
  //Karol_scramble_hist->Fit("gaus"); 
  //Karol_scramble_hist->GetFunction("gaus")->SetLineColor(2);

  //Karol_scramble_hist->GetYaxis()->SetLabelSize(0.02);
  Karol_scramble_hist_1->SetStats(0);
  
  
  // Additive Scramble
  additive_scramble_hist_1->Draw("sames");
  additive_scramble_hist_1->SetLineColor(4);
  additive_scramble_hist_1->SetLineStyle(7);
  additive_scramble_hist_1->SetLineWidth(3);
  //additive_scramble_hist->Fit("gaus"); 
  //additive_scramble_hist->GetFunction("gaus")->SetLineColor(4); 
  additive_scramble_hist_1->SetStats(0);

 //Velopix Scramble
  Velopix_scramble_hist_1->Draw("sames");
  Velopix_scramble_hist_1->SetLineColor(7);
  Velopix_scramble_hist_1->SetLineStyle(5);
  Velopix_scramble_hist_1->SetLineWidth(3);
  //Velopix_scramble_hist_1->Fit("gaus"); 
  //Velopix_scramble_hist_1->GetFunction("gaus")->SetLineColor(4); 
  Velopix_scramble_hist_1->SetStats(0);
  

//Random Data
  Random_data_hist_1->Draw("sames");
  Random_data_hist_1->SetLineColor(1);
  Random_data_hist_1->SetLineStyle(6);
  Random_data_hist_1->SetLineWidth(3);
  //Random_data_hist_1->Fit("gaus"); 
  //Random_data_hist_1->GetFunction("gaus")->SetLineColor(4); 
  Random_data_hist_1->SetStats(0);



  // Legend
  leg_top = new TLegend(0.65,0.6,0.9,0.9);
  leg_top->AddEntry(un_scramble_hist_1,"Pre Scrambler","l");
  leg_top->AddEntry(Karol_scramble_hist_1,"Intermediate Scrambler","l");
  leg_top->AddEntry(additive_scramble_hist_1,"Additive Scrambler","l");
  leg_top->AddEntry(Velopix_scramble_hist_1,"Velopix Scrambler","l");
  leg_top->AddEntry(Random_data_hist_1,"Random Data","l");
  leg_top->Draw();
  
  c1->Pad()->SetLogy();
  c1->Pad()->SetGridy();


  TPaveText *myText2= new TPaveText(0.25,0.92,0.51,0.99, "NDC");
//NDC sets coords relative to pad
myText2->SetTextSize(0.05);
myText2->SetFillColor(0);        
//white background
myText2->SetTextAlign(12);
myTextEntry=myText2->AddText("Histogram of Chains of 1s");
myText2->Draw();
  
  //c1->SaveAs("Chain_Length_Full_Hist_Update.pdf");
}
