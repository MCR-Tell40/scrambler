Double_t linFit(Double_t * x, Double_t * par)
{
  return par[0] + TMath::Power(par[1],x[0]);
};

void draw_chain_graph_full()
{
  TFile *f = new TFile("longest_chain_full.root");

  TH1F *un_scramble_hist = (TH1F*)f->Get("desync9X_scrambler_hist");
  TH1F *Karol_scramble_hist = (TH1F*)f->Get("Karol_scrambler_hist");
  TH1F *additive_scramble_hist = (TH1F*)f->Get("additive_scrambler_hist");
  TH1F *Velopix_scramble_hist = (TH1F*)f->Get("Velopix_scrambler_hist");
  TH1F *Random_data_hist = (TH1F*)f->Get("Random_data_hist");
  // gStyle->SetOptStat(0000000000);
  // gStyle->SetOptFit(11);
  // gStyle->SetStatW(0.12);                
  // gStyle->SetStatH(0.12);  
  
  TCanvas *c1 = new TCanvas("c1","Chain Length",900,600);

for (int i(0); i < Karol_scramble_hist->GetNbinsX(); i++)
  {
    Karol_scramble_hist->SetBinContent(i,TMath::Log(Karol_scramble_hist->GetBinContent(i)));
    un_scramble_hist->SetBinContent(i,log(un_scramble_hist->GetBinContent(i)));
    additive_scramble_hist->SetBinContent(i,log(additive_scramble_hist->GetBinContent(i)));
    Velopix_scramble_hist->SetBinContent(i,log(Velopix_scramble_hist->GetBinContent(i)));
    Random_data_hist->SetBinContent(i,log(Random_data_hist->GetBinContent(i)));
  }

  // Pre Scramble
  un_scramble_hist->Draw("");
  un_scramble_hist->SetLineColor(6);
  un_scramble_hist->SetLineStyle(1);
  //un_scramble_hist->Fit("gaus");
  //un_scramble_hist->GetFunction("gaus")->SetLineColor(1);
  un_scramble_hist->SetTitle(0);
  un_scramble_hist->GetXaxis()->SetTitle("Chain Length");
  un_scramble_hist->GetYaxis()->SetTitle("Entries");
 
  un_scramble_hist->SetStats(0);
   

  // New Scramble
  

  Karol_scramble_hist->Draw("sames");
  Karol_scramble_hist->SetLineColor(2);
  Karol_scramble_hist->SetLineStyle(1);
  TF1* Karol_fit = new TF1("Karol_fit",linFit,1,30,2);
  Karol_fit->SetParameters(1e7,-0.5);
  Karol_scramble_hist->Fit("Karol_fit"); 
  //Karol_scramble_hist->GetFunction("gaus")->SetLineColor(2);

  //Karol_scramble_hist->GetYaxis()->SetLabelSize(0.02);
  Karol_scramble_hist->SetStats(0);
  
  
  // Additive Scramble
  additive_scramble_hist->Draw("sames");
  additive_scramble_hist->SetLineColor(4);
  additive_scramble_hist->SetLineStyle(7);
  //additive_scramble_hist->Fit("gaus"); 
  //additive_scramble_hist->GetFunction("gaus")->SetLineColor(4); 
  additive_scramble_hist->SetStats(0);

  // Velopix Scramble
  Velopix_scramble_hist->Draw("sames");
  Velopix_scramble_hist->SetLineColor(7);
  Velopix_scramble_hist->SetLineStyle(6);
  // Velopix_scramble_hist->Fit("gaus"); 
  // Velopix_scramble_hist->GetFunction("gaus")->SetLineColor(4); 
  Velopix_scramble_hist->SetStats(0);


   // Random Data
  Random_data_hist->Draw("sames");
  Random_data_hist->SetLineColor(1);
  Random_data_hist->SetLineStyle(5);
  Random_data_hist->SetLineWidth(3);
  //Random_data_hist->Fit("gaus"); 
  //Random_data_hist->GetFunction("gaus")->SetLineColor(4); 
  Random_data_hist->SetStats(0);
  
  // Legend
  leg_top = new TLegend(0.65,0.6,0.9,0.9);
  leg_top->AddEntry(un_scramble_hist,"Pre Scrambler","f");
  leg_top->AddEntry(Karol_scramble_hist,"Intermediate Scrambler","f");
  leg_top->AddEntry(additive_scramble_hist,"Additive Scrambler","f");
  leg_top->AddEntry(Velopix_scramble_hist,"Velopix Scrambler","f");
  leg_top->AddEntry(Random_data_hist,"Random Data","f");
  leg_top->Draw();
  
  //c1->SetLogy();
  //c1->SetGridy();

  c1->SaveAs("Chain_Length_Full_Hist_Nick.pdf");

}
