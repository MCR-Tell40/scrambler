Double_t linFit(Double_t * x, Double_t * par)
{
  return par[0] + TMath::Power(10,x[0]*par[1]);
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
  c1->GetFrame()->SetBorderSize(0);

// for (int i(0); i < Karol_scramble_hist->GetNbinsX(); i++)
//   {
//     Karol_scramble_hist->SetBinContent(i,TMath::Log(Karol_scramble_hist->GetBinContent(i)));
//     un_scramble_hist->SetBinContent(i,log(un_scramble_hist->GetBinContent(i)));
//     additive_scramble_hist->SetBinContent(i,log(additive_scramble_hist->GetBinContent(i)));
//     Velopix_scramble_hist->SetBinContent(i,log(Velopix_scramble_hist->GetBinContent(i)));
//     Random_data_hist->SetBinContent(i,log(Random_data_hist->GetBinContent(i)));
//   }

  // Pre Scramble
  un_scramble_hist->Draw("");
  un_scramble_hist->SetLineColor(6);
  un_scramble_hist->SetLineStyle(1);
  un_scramble_hist->Fit("expo");
  un_scramble_hist->GetFunction("expo")->SetLineColor(6);
  un_scramble_hist->SetTitle(0);
  un_scramble_hist->GetXaxis()->SetTitle("Chain Length");
  un_scramble_hist->GetXaxis()->SetRangeUser(1,30);
  un_scramble_hist->GetYaxis()->SetTitle("Entries");
 
  un_scramble_hist->SetStats(0);
   
  // New Scramble
  

  Karol_scramble_hist->Draw("sames");
  Karol_scramble_hist->SetLineColor(2);
  Karol_scramble_hist->SetLineStyle(1);
  // TF1* Karol_fit = new TF1("Karol_fit",linFit,1,30,2);
  // Karol_fit->SetParameters(1e7,-0.5);
  Karol_scramble_hist->Fit("expo"); 
  Karol_scramble_hist->GetFunction("expo")->SetLineColor(2);
  Karol_scramble_hist->GetFunction("expo")->SetLineColor(1);
  //Karol_scramble_hist->GetYaxis()->SetLabelSize(0.02);
  Karol_scramble_hist->SetStats(0);

  
  
  // Additive Scramble
  additive_scramble_hist->Draw("sames");
  additive_scramble_hist->SetLineColor(4);
  additive_scramble_hist->SetLineStyle(1);
  additive_scramble_hist->Fit("expo"); 
  additive_scramble_hist->GetFunction("expo")->SetLineColor(4); 
  additive_scramble_hist->GetFunction("expo")->SetLineStyle(7);
  additive_scramble_hist->SetStats(0);

  
  // Velopix Scramble
  Velopix_scramble_hist->Draw("sames");
  Velopix_scramble_hist->SetLineColor(7);
  Velopix_scramble_hist->SetLineStyle(1);
  Velopix_scramble_hist->Fit("expo"); 
  Velopix_scramble_hist->GetFunction("expo")->SetLineColor(7); 
  Velopix_scramble_hist->GetFunction("expo")->SetLineStyle(6);
  Velopix_scramble_hist->SetStats(0);

// Random Data
  Random_data_hist->Draw("sames");
  Random_data_hist->SetLineColor(1);
  Random_data_hist->SetLineStyle(1);
  Random_data_hist->Fit("expo"); 
  Random_data_hist->GetFunction("expo")->SetLineColor(1); 
  Random_data_hist->GetFunction("expo")->SetLineStyle(5);
  Random_data_hist->SetStats(0);
  
  double a = un_scramble_hist->GetFunction("expo")->GetParameter(1)*TMath::LogE();
  double p = 1 - pow(10,a);
  double e = (p / a) * un_scramble_hist->GetFunction("expo")->GetParError(1) * TMath::LogE();
  cout << "****Unscrambled: Grad = " << a << "\t p_t = " << p << "\t +/- " << e << endl;

  a = additive_scramble_hist->GetFunction("expo")->GetParameter(1)*TMath::LogE();
  p = 1 - pow(10,a);
  e = (p / a) * additive_scramble_hist->GetFunction("expo")->GetParError(1) * TMath::LogE();
  cout << "****Additive: Grad = " << a << "\t p_t = " << p << "\t +/- " << e << endl;

  a = Karol_scramble_hist->GetFunction("expo")->GetParameter(1)*TMath::LogE();
  p = 1 - pow(10,a);
  e = (p / a) * Karol_scramble_hist->GetFunction("expo")->GetParError(1) * TMath::LogE();
  cout << "****Intermediate: Grad = " << a << "\t p_t = " << p << "\t +/- " << e << endl;

  a = Velopix_scramble_hist->GetFunction("expo")->GetParameter(1)*TMath::LogE();
  p = 1 - pow(10,a);
  e = (p / a) * Velopix_scramble_hist->GetFunction("expo")->GetParError(1) * TMath::LogE();
  cout << "****Velopix: Grad = " << a << "\t p_t = " << p << "\t +/- " << e << endl;

  a = Random_data_hist->GetFunction("expo")->GetParameter(1)*TMath::LogE();
  p = 1 - pow(10,a);
  e = (p / a) * Random_data_hist->GetFunction("expo")->GetParError(1) * TMath::LogE();
  cout << "****Random: Grad = " << a << "\t p_t = " << p << "\t +/- " << e << endl;
  
  // Legend
  leg_top = new TLegend(0.6,0.6,0.87,0.87);
  leg_top->SetLineColor(0);
  leg_top->SetTextSize(0.0275);
  leg_top->AddEntry(un_scramble_hist,"Unscrambled Data","f");
  leg_top->AddEntry(Random_data_hist,"Random Data","f");
  leg_top->AddEntry(additive_scramble_hist,"Additive Scrambler","f");
  leg_top->AddEntry(Karol_scramble_hist,"Intermediate Scrambler","f");
  leg_top->AddEntry(Velopix_scramble_hist,"VeloPix Scrambler","f");
  leg_top->Draw();
  
  c1->SetLogy();
  c1->SetTicks();
  //c1->SetGridy();

  c1->SaveAs("Chain_Length_Full_Hist_Nick.pdf");

}
