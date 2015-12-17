void draw_balance_graphs_X()
{
  TFile* f = new TFile("balance_analysis_X.root");
  
  TCanvas* c1 = new TCanvas("Evolution in the Balance of 1s and 0s",
          "Evolution in the Balance of 1s and 0s",
          1500,600);
  c1->Divide(2,1);

  // ----- Generate Graphs ----- //

  // TGraph* desyncX_graph = (TGraph*)f->Get("true_desyncX.txt");
  // desyncX_graph->SetLineColor(6);
  // desyncX_graph->SetLineWidth(2);

  TGraph* Karol_graph = (TGraph*)f->Get("true_Karol_scramble_output_x.txt");
  Karol_graph->SetLineColor(2);
  Karol_graph->SetLineWidth(2);

  TGraph* additive_graph = (TGraph*)f->Get("true_additive_scramble_output_x.txt");
  additive_graph->SetLineColor(4);
  additive_graph->SetLineWidth(2);

  TGraph* velopix_graph = (TGraph*)f->Get("true_VeloPix_scramble_output_x.txt");
  velopix_graph->SetLineColor(1);
  velopix_graph->SetLineWidth(2);

  TGraph* random_data = (TGraph*)f->Get("true_random_data_output_X.txt");
  random_data->SetLineColor(1);
  random_data->SetLineWidth(2);

  TGraph* random_data2 = (TGraph*)f->Get("true_random_data_output_X2.txt");
  random_data2->SetLineColor(1);
  random_data2->SetLineWidth(2);

  TGraph* random_data3 = (TGraph*)f->Get("true_random_data_output_X3.txt");
  random_data3->SetLineColor(1);
  random_data3->SetLineWidth(2);

  // ----- Generate Theoritical Preditcion & Xaxis ----- //
  vector<double> x, y, ex, ey1, ey2;

  int n = velopix_graph->GetN();

  for(int i(0); i < n; i ++)
  {
    x.push_back(i*1000);
    y.push_back(0);
    ex.push_back(0);
    ey1.push_back(sqrt(i * 1000* 120));
    ey2.push_back(2* ey1[i]);
  }

  TGraphErrors * Sigma1 = new TGraphErrors(n,&x[0],&y[0],&ex[0],&ey1[0]);
  Sigma1->SetFillColor(3);
  Sigma1->SetLineColor(1);
  Sigma1->SetLineWidth(2);
  Sigma1->SetLineStyle(2);

  TGraphErrors * Sigma2 = new TGraphErrors(n,&x[0],&y[0],&ex[0],&ey2[0]);
  Sigma2->SetFillColor(kYellow);
  Sigma2->SetLineColor(1);
  Sigma2->SetLineWidth(2);
  Sigma2->SetLineStyle(2);

  TGraph * Xaxis = new TGraph(n,&x[0],&y[0]);
  Xaxis->SetLineStyle(2);

  // ----- Multi Graph Left ----- //
  TMultiGraph * mg = new TMultiGraph();
  mg->Add(Sigma2);
  mg->Add(Sigma1);
  mg->Add(additive_graph,"l");
  mg->Add(Karol_graph,"l");
  mg->Add(velopix_graph,"l");
  mg->Add(Xaxis,"l");

  c1->cd(1);
  c1->Pad()->SetTicks();
  mg->Draw("a3");

  mg->GetXaxis()->SetTitle("Number of 120 Bit Frames");
  mg->GetYaxis()->SetTitle("(#1 - #0)");
  mg->GetYaxis()->SetRangeUser(-8e4,10e4);
  mg->GetXaxis()->SetRangeUser(0,n*1000 +3e5);
  //mg->SetTitle("Evolution in the Balance of 1s and 0s");

  TLegend* leg = new TLegend(0.13,0.6,0.25,0.87);
  leg->SetLineColor(0);
  leg->SetTextSize(0.0275);
  // leg->AddEntry(desyncX_graph,"Unscrambled Data","l");
  leg->AddEntry(additive_graph,"Additive Scrambler","l");
  leg->AddEntry(Karol_graph,"Intermediate Scrambler","l");
  leg->AddEntry(velopix_graph,"VeloPix Scrambler","l");
  // leg->AddEntry(random_data,"Random Data","l");
  leg->AddEntry(Sigma2,"Expected","l");
  leg->AddEntry(Sigma1,"#pm 1 #sigma","lf");
  leg->AddEntry(Sigma2,"#pm 2 #sigma","lf");
  leg->Draw();


  // ----- Multi Graph Right ----- //

  TMultiGraph * mg_rad = new TMultiGraph();
  mg_rad->Add(Sigma2);
  mg_rad->Add(Sigma1);
  mg_rad->Add(random_data,"l");
  mg_rad->Add(random_data2,"l");
  mg_rad->Add(random_data3,"l");
  mg_rad->Add(Xaxis,"l");

  TLegend* leg_rad = new TLegend(0.13,0.67,0.25,0.87);
  leg_rad->SetLineColor(0);
  leg_rad->SetTextSize(0.0275);
  // leg->AddEntry(desyncX_graph,"Unscrambled Data","l");
  leg_rad->AddEntry(random_data,"Random Data (3 Sets)","l");
  leg_rad->AddEntry(Sigma2,"Expected","l");
  leg_rad->AddEntry(Sigma1,"#pm 1 #sigma","lf");
  leg_rad->AddEntry(Sigma2,"#pm 2 #sigma","lf");
  
  c1->cd(2);
  c1->Pad()->SetTicks();
  mg_rad->Draw("a3");
  leg_rad->Draw();

  mg_rad->GetXaxis()->SetTitle("Number of 120 Bit Frames");
  mg_rad->GetYaxis()->SetTitle("(#1 - #0)");
  mg_rad->GetYaxis()->SetRangeUser(-8e4,10e4);
  mg_rad->GetXaxis()->SetRangeUser(0,n*1000 +3e5);


  //-----------------------------------------------------------------------//
 



  c1->Update();
  c1->SaveAs("graphs/True_Evolution_in_the_Balance_of_1s_and_0s.png");

  //-----------------------------------------------------------------------//

//   TGraph* abs_desyncX_graph = (TGraph*)f->Get("abs_desyncX.txt");
//   TGraph* abs_Karol_graph = (TGraph*)f->Get("abs_Karol_scramble_output_x.txt");
//   TGraph* abs_additive_graph = (TGraph*)f->Get("abs_additive_scramble_output_x.txt");
//   TGraph* abs_velopix_graph = (TGraph*)f->Get("abs_VeloPix_scramble_output_x.txt");
//   TGraph* abs_random_data = (TGraph*)f->Get("abs_random_data_output_X.txt");
//   TMultiGraph * abs_mg = new TMultiGraph();

//   TCanvas* abs_c1 = new TCanvas("Evolution in the Absolute Value of Balance of 1s and 0",
// 			    "Evolution in the Absolute Value of Balance of 1s and 0s",
// 			    0,800,900,600);
//   abs_c1->SetTicks();

//   abs_mg->Add(Sigma2);
//   abs_mg->Add(Sigma1);
//   abs_mg->Draw("a3");

//   abs_mg->GetXaxis()->SetTitle("Number of 120 Bit Frames");
//   abs_mg->GetYaxis()->SetTitle("abs(#1 - #0)");
//   abs_mg->GetYaxis()->SetRangeUser(0,1e5);
//   abs_mg->GetXaxis()->SetRangeUser(0,n*1000*div);
//   abs_mg->SetTitle("Evolution in the Balance of 1s and 0s");

//   abs_additive_graph->Draw("same");
//   abs_additive_graph->SetLineColor(4);
//   abs_additive_graph->SetLineWidth(2);

//   abs_Karol_graph->Draw("same");
//   abs_Karol_graph->SetLineColor(2);
//   abs_Karol_graph->SetLineWidth(2);
//   abs_Karol_graph->SetMarkerStyle(0);

//   abs_desyncX_graph->Draw("same");
//   abs_desyncX_graph->SetLineColor(6);
//   abs_desyncX_graph->SetLineWidth(2);

//   abs_velopix_graph->Draw("same");
//   abs_velopix_graph->SetLineColor(7);
//   abs_velopix_graph->SetLineWidth(2);

//   abs_random_data->Draw("same");
//   abs_random_data->SetLineColor(1);
//   abs_random_data->SetLineWidth(2);

//   // TLegend* abs_leg = new TLegend(0.13,0.7,0.5,0.87);
//   // abs_leg->SetLineColor(0);
//   // abs_leg->AddEntry(abs_desyncX_graph,"Unscrambled Data","l");
//   // abs_leg->AddEntry(abs_additive_graph,"Additive Scrambler","l");
//   // abs_leg->AddEntry(abs_Karol_graph,"Intermediate Scrambler","l");
//   // abs_leg->AddEntry(abs_velopix_graph,"VeloPix Scrambler","l");
//   // abs_leg->AddEntry(abs_random_data,"Random Data","l");
//   // abs_leg->AddEntry(Sigma1,"#pm 1 #sigma","f");
//   // abs_leg->AddEntry(Sigma2,"#pm 2 #sigma","f");
//   // abs_leg->Draw();
//   true_leg->Draw();

 
//   abs_c1->Update();
//   abs_c1->SaveAs("graphs/Abs_Evolution_in_the_Balance_of_1s_and_0s.png");
}
