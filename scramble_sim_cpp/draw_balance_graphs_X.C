void draw_balance_graphs_X()
{
  TFile* f = new TFile("balance_analysis_X.root");

  TGraph* true_desyncX_graph = (TGraph*)f->Get("true_desyncX.txt");
  TGraph* true_Karol_graph = (TGraph*)f->Get("true_Karol_scramble_output_x.txt");
  TGraph* true_additive_graph = (TGraph*)f->Get("true_additive_scramble_output_x.txt");
  TGraph* true_velopix_graph = (TGraph*)f->Get("true_VeloPix_scramble_output_x.txt");
  TGraph* true_random_data = (TGraph*)f->Get("true_random_data_output_x.txt");
  TGraph* abs_desyncX_graph = (TGraph*)f->Get("abs_desyncX.txt");
  TGraph* abs_Karol_graph = (TGraph*)f->Get("abs_Karol_scramble_output_x.txt");
  TGraph* abs_additive_graph = (TGraph*)f->Get("abs_additive_scramble_output_x.txt");
  TGraph* abs_velopix_graph = (TGraph*)f->Get("abs_VeloPix_scramble_output_x.txt");
  TGraph* abs_random_data = (TGraph*)f->Get("abs_random_data_output_x.txt");

  vector<double> x, y, ex, ey1, ey2;

  int n = true_velopix_graph->GetN();
  int div = 1;
  n = n / div;

  for(int i(0); i < n; i += div)
  {
    x.push_back(i);
    y.push_back(0);
    ex.push_back(0);
    ey1.push_back(sqrt(i * 120));
    ey2.push_back(2* sqrt(i * 120));
  }

  TGraphErrors * Sigma1 = new TGraphErrors(n,&x[0],&y[0],&ex[0],&ey1[0]);
  TGraphErrors * Sigma2 = new TGraphErrors(n,&x[0],&y[0],&ex[0],&ey2[0]);
  TGraph * Xaxis = new TGraph(n,&x[0],&y[0]);

  TCanvas* true_c1 = new TCanvas("Evolution in the Balance of 1s and 0s",
			    "Evolution in the Balance of 1s and 0s",
			    900,600);
  true_c1->SetTicks();

  TMultiGraph * true_mg = new TMultiGraph();
  TMultiGraph * abs_mg = new TMultiGraph();

  Sigma2->SetFillColor(5);
  Sigma2->SetLineColor(5);
  Sigma1->SetFillColor(3);
  Sigma1->SetLineColor(3);

  true_mg->Add(Sigma2);
  true_mg->Add(Sigma1);
  true_mg->Draw("a3");

  Xaxis->Draw("same");

  true_mg->GetXaxis()->SetTitle("Frame #");
  true_mg->GetYaxis()->SetTitle("(#1 - #0)");
  true_mg->GetYaxis()->SetRangeUser(-6e4,1e5);
  true_mg->GetXaxis()->SetRangeUser(0,n*div);
  true_mg->SetTitle("Evolution in the Balance of 1s and 0s");

  true_additive_graph->Draw("same");
  true_additive_graph->SetLineColor(4);
  true_additive_graph->SetLineWidth(2);

  true_Karol_graph->Draw("same");
  true_Karol_graph->SetLineColor(2);
  true_Karol_graph->SetLineWidth(2);
  true_Karol_graph->SetMarkerStyle(0);

  true_desyncX_graph->Draw("same");
  true_desyncX_graph->SetLineColor(6);
  true_desyncX_graph->SetLineWidth(2);

  true_velopix_graph->Draw("same");
  true_velopix_graph->SetLineColor(7);
  true_velopix_graph->SetLineWidth(2);

  true_random_data->Draw("same");
  true_random_data->SetLineColor(1);
  true_random_data->SetLineWidth(2);

  TLegend* true_leg = new TLegend(0.13,0.55,0.25,0.87);
  true_leg->SetLineColor(0);
  true_leg->SetTextSize(0.0275);
  true_leg->AddEntry(true_desyncX_graph,"Unscrambled Data","l");
  true_leg->AddEntry(true_additive_graph,"Additive Scrambler","l");
  true_leg->AddEntry(true_Karol_graph,"Intermediate Scrambler","l");
  true_leg->AddEntry(true_velopix_graph,"VeloPix Scrambler","l");
  true_leg->AddEntry(true_random_data,"Random Data","l");
  true_leg->AddEntry(Sigma1,"#pm 1 #sigma","f");
  true_leg->AddEntry(Sigma2,"#pm 2 #sigma","f");
  true_leg->Draw();

 
  true_c1->Update();
  true_c1->SaveAs("graphs/True_Evolution_in_the_Balance_of_1s_and_0s.png");

  //-----------------------------------------------------------------------//

  TCanvas* abs_c1 = new TCanvas("Evolution in the Absolute Value of Balance of 1s and 0",
			    "Evolution in the Absolute Value of Balance of 1s and 0s",
			    0,800,900,600);
  abs_c1->SetTicks();

  abs_mg->Add(Sigma2);
  abs_mg->Add(Sigma1);
  abs_mg->Draw("a3");

  abs_mg->GetXaxis()->SetTitle("Frame #");
  abs_mg->GetYaxis()->SetTitle("abs(#1 - #0)");
  abs_mg->GetYaxis()->SetRangeUser(0,1e5);
  abs_mg->GetXaxis()->SetRangeUser(0,n*div);
  abs_mg->SetTitle("Evolution in the Balance of 1s and 0s");

  abs_additive_graph->Draw("same");
  abs_additive_graph->SetLineColor(4);
  abs_additive_graph->SetLineWidth(2);

  abs_Karol_graph->Draw("same");
  abs_Karol_graph->SetLineColor(2);
  abs_Karol_graph->SetLineWidth(2);
  abs_Karol_graph->SetMarkerStyle(0);

  abs_desyncX_graph->Draw("same");
  abs_desyncX_graph->SetLineColor(6);
  abs_desyncX_graph->SetLineWidth(2);

  abs_velopix_graph->Draw("same");
  abs_velopix_graph->SetLineColor(7);
  abs_velopix_graph->SetLineWidth(2);

  abs_random_data->Draw("same");
  abs_random_data->SetLineColor(1);
  abs_random_data->SetLineWidth(2);

  // TLegend* abs_leg = new TLegend(0.13,0.7,0.5,0.87);
  // abs_leg->SetLineColor(0);
  // abs_leg->AddEntry(abs_desyncX_graph,"Unscrambled Data","l");
  // abs_leg->AddEntry(abs_additive_graph,"Additive Scrambler","l");
  // abs_leg->AddEntry(abs_Karol_graph,"Intermediate Scrambler","l");
  // abs_leg->AddEntry(abs_velopix_graph,"VeloPix Scrambler","l");
  // abs_leg->AddEntry(abs_random_data,"Random Data","l");
  // abs_leg->AddEntry(Sigma1,"#pm 1 #sigma","f");
  // abs_leg->AddEntry(Sigma2,"#pm 2 #sigma","f");
  // abs_leg->Draw();
  true_leg->Draw();

 
  abs_c1->Update();
  abs_c1->SaveAs("graphs/Abs_Evolution_in_the_Balance_of_1s_and_0s.png");
}
