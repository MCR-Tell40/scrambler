void draw_transition_graph_full()
{
  TFile *f = new TFile("transition_analysis_full.root");

  TH1F *desync9X_scramble_hist  = (TH1F*)f->Get("desync9X_scrambler_hist" );
  TH1F *Karol_scramble_hist     = (TH1F*)f->Get("Karol_scrambler_hist"    );
  TH1F *additive_scramble_hist  = (TH1F*)f->Get("additive_scrambler_hist" );
  TH1F *velopix_scramble_hist   = (TH1F*)f->Get("Velopix_scrambler_hist"  );
  TH1F *random_data_hist        = (TH1F*)f->Get("Random_data_hist"        );
   
  TCanvas *c1 = new TCanvas("c1","Transitions Per Packet",900,600);
  c1->SetTicks(1);

  // Karol Scramble
  Karol_scramble_hist->Draw("");
  Karol_scramble_hist->SetLineColor(2);
  Karol_scramble_hist->SetLineStyle(1);
  Karol_scramble_hist->Fit("gaus"); 
  Karol_scramble_hist->GetFunction("gaus")->SetLineColor(2);
  //Karol_scramble_hist->SetTitle("Comparison of the Number of Transitions");
  Karol_scramble_hist->SetTitle("");
  Karol_scramble_hist->GetXaxis()->SetTitle("Transitions Per Frame");
  Karol_scramble_hist->GetYaxis()->SetTitle("Entries");
  Karol_scramble_hist->GetYaxis()->SetRangeUser(0,25000);
  Karol_scramble_hist->GetYaxis()->SetLabelSize(0.02);
  Karol_scramble_hist->SetStats(0);
  
  // Desync9X Scramble
  desync9X_scramble_hist->Draw("sames");
  desync9X_scramble_hist->SetLineColor(6);
  desync9X_scramble_hist->SetLineStyle(1);
  desync9X_scramble_hist->Fit("gaus");
  desync9X_scramble_hist->GetFunction("gaus")->SetLineColor(6); 
  desync9X_scramble_hist->SetStats(0);
   
  // Additive Scramble
  additive_scramble_hist->Draw("sames");
  additive_scramble_hist->SetLineColor(4);
  additive_scramble_hist->SetLineStyle(1);
  additive_scramble_hist->Fit("gaus"); 
  additive_scramble_hist->GetFunction("gaus")->SetLineColor(4); 
  additive_scramble_hist->SetStats(0);

  // Velopix Scramble
  velopix_scramble_hist->Draw("sames");
  velopix_scramble_hist->SetLineColor(7);
  velopix_scramble_hist->SetLineStyle(1);
  velopix_scramble_hist->Fit("gaus"); 
  velopix_scramble_hist->GetFunction("gaus")->SetLineColor(7);
  velopix_scramble_hist->GetFunction("gaus")->SetLineStyle(2); 
  velopix_scramble_hist->SetStats(0);

  //Random Data  
  random_data_hist->Draw("sames");
  random_data_hist->SetLineColor(1);
  random_data_hist->SetLineStyle(1);
  random_data_hist->Fit("gaus"); 
  random_data_hist->GetFunction("gaus")->SetLineColor(1);
  random_data_hist->GetFunction("gaus")->SetLineStyle(3); 
  random_data_hist->SetStats(0);
  
  // ----- Legend ----- //
  //desync9X stats
  stringstream desync9X_scramble_mean_ss;
  desync9X_scramble_mean_ss.precision(3);
  desync9X_scramble_mean_ss << "mean = " << desync9X_scramble_hist->GetFunction("gaus")->GetParameter(1);
  string desync9X_scramble_mean = desync9X_scramble_mean_ss.str();

  stringstream desync9X_scramble_sigma_ss;
  desync9X_scramble_sigma_ss.precision(3);
  desync9X_scramble_sigma_ss << "#sigma = " << desync9X_scramble_hist->GetFunction("gaus")->GetParameter(2);
  string desync9X_scramble_sigma = desync9X_scramble_sigma_ss.str();

  //Karol stats
  stringstream Karol_scramble_mean_ss;
  Karol_scramble_mean_ss.precision(3);
  Karol_scramble_mean_ss << "mean = " << Karol_scramble_hist->GetFunction("gaus")->GetParameter(1);
  string Karol_scramble_mean = Karol_scramble_mean_ss.str();

  stringstream Karol_scramble_sigma_ss;
  Karol_scramble_sigma_ss.precision(3);
  Karol_scramble_sigma_ss << "#sigma = " << Karol_scramble_hist->GetFunction("gaus")->GetParameter(2);
  string Karol_scramble_sigma = Karol_scramble_sigma_ss.str();

  //additive stats
  stringstream additive_scramble_mean_ss;
  additive_scramble_mean_ss.precision(3);
  additive_scramble_mean_ss << "mean = " << additive_scramble_hist->GetFunction("gaus")->GetParameter(1);
  string additive_scramble_mean = additive_scramble_mean_ss.str();

  stringstream additive_scramble_sigma_ss;
  additive_scramble_sigma_ss.precision(3);
  additive_scramble_sigma_ss << "#sigma = " << additive_scramble_hist->GetFunction("gaus")->GetParameter(2);
  string additive_scramble_sigma = additive_scramble_sigma_ss.str();

  //velopix stats
  stringstream velopix_scramble_mean_ss;
  velopix_scramble_mean_ss.precision(3);
  velopix_scramble_mean_ss << "mean = " << velopix_scramble_hist->GetFunction("gaus")->GetParameter(1);
  string velopix_scramble_mean = velopix_scramble_mean_ss.str();

  stringstream velopix_scramble_sigma_ss;
  velopix_scramble_sigma_ss.precision(3);
  velopix_scramble_sigma_ss << "#sigma = " << velopix_scramble_hist->GetFunction("gaus")->GetParameter(2);
  string velopix_scramble_sigma = velopix_scramble_sigma_ss.str();

  //random stats
  stringstream random_data_mean_ss;
  random_data_mean_ss.precision(3);
  random_data_mean_ss << "mean = " << random_data_hist->GetFunction("gaus")->GetParameter(1);
  string random_data_mean = random_data_mean_ss.str();

  stringstream random_data_sigma_ss;
  random_data_sigma_ss.precision(3);
  random_data_sigma_ss << "#sigma = " << random_data_hist->GetFunction("gaus")->GetParameter(2);
  string random_data_sigma = random_data_sigma_ss.str();
  
  leg = new TLegend(0.65,0.4,0.87,0.87);
  leg->SetLineColor(0);
  leg->AddEntry(desync9X_scramble_hist,"Unscrambled Data","f");
  leg->AddEntry(desync9X_scramble_hist,desync9X_scramble_mean.c_str(),"");
  leg->AddEntry(desync9X_scramble_hist,desync9X_scramble_sigma.c_str(),"");
  leg->AddEntry(random_data_hist,"Random Data","f");
  leg->AddEntry(random_data_hist,random_data_mean.c_str(),"");
  leg->AddEntry(random_data_hist,random_data_sigma.c_str(),"");
  leg->AddEntry(velopix_scramble_hist,"Velopix Scrambler","f");
  leg->AddEntry(velopix_scramble_hist,velopix_scramble_mean.c_str(),"");
  leg->AddEntry(velopix_scramble_hist,velopix_scramble_sigma.c_str(),"");
  leg->AddEntry(Karol_scramble_hist,"Intermediate Scrambler","f");
  leg->AddEntry(Karol_scramble_hist,Karol_scramble_mean.c_str(),"");
  leg->AddEntry(Karol_scramble_hist,Karol_scramble_sigma.c_str(),"");
  leg->AddEntry(additive_scramble_hist,"Additive Scrambler","f");
  leg->AddEntry(additive_scramble_hist,additive_scramble_mean.c_str(),"");
  leg->AddEntry(additive_scramble_hist,additive_scramble_sigma.c_str(),"");
  leg->Draw();

  c1->Update();

  c1->SaveAs("Transition_Histogram_update.pdf");
}
