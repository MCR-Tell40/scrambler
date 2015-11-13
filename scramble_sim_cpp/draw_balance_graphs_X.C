void draw_balance_graphs_X()
{
  TFile* f = new TFile("Balance_all.root");

  // TGraph* desync9X_graph = (TGraph*)f->Get("/home/velo/Desktop/desync/desyncX.txt");
  TGraph* true_Karol_graph = (TGraph*)f->Get("true_allKarol.txt");
  TGraph* true_additive_graph = (TGraph*)f->Get("true_allAdd.txt");
  TGraph* true_velopix_graph = (TGraph*)f->Get("true_allVelo.txt");
  TGraph* abs_Karol_graph = (TGraph*)f->Get("abs_allKarol.txt");
  TGraph* abs_additive_graph = (TGraph*)f->Get("abs_allAdd.txt");
  TGraph* abs_velopix_graph = (TGraph*)f->Get("abs_allVelo.txt");

  TCanvas* true_c1 = new TCanvas("Evolution in the Balance of 1s and 0s",
			    "Evolution in the Balance of 1s and 0s",
			    900,600);
  true_c1->Pad()->SetGridy();

  true_additive_graph->Draw("AL");
  true_additive_graph->SetLineColor(4);
  true_additive_graph->SetLineWidth(2);
  true_additive_graph->GetXaxis()->SetTitle("Frame #");
  true_additive_graph->GetYaxis()->SetTitle("(#1 - #0)");
  true_additive_graph->GetYaxis()->SetRangeUser(-6e4,1e5);
  //  true_additive_graph->GetXaxis()->SetRangeUser(0,335e3);
  true_additive_graph->SetTitle("Evolution in the Balance of 1s and 0s");

  true_Karol_graph->Draw("same");
  true_Karol_graph->SetLineColor(2);
  true_Karol_graph->SetLineWidth(2);
  true_Karol_graph->SetMarkerStyle(0);

  //desync9X_graph->Draw("same");
  //desync9X_graph->SetLineColor(6);
  //desync9X_graph->SetLineWidth(2);

  true_velopix_graph->Draw("same");
  true_velopix_graph->SetLineColor(8);
  true_velopix_graph->SetLineWidth(2);

  TLegend* true_leg = new TLegend(0.7,0.82,0.9,0.9);
  //  true_leg->True_AddEntry(desync9X_graph,"Dysync 9X","l");
  true_leg->AddEntry(true_velopix_graph,"VeloPix Scrambler","l");
  true_leg->AddEntry(true_Karol_graph,"Karol Scrambler","l");
  true_leg->AddEntry(true_additive_graph,"Additive Scrambler","l");
  true_leg->Draw();

 
  true_c1->Update();
  true_c1->SaveAs("graphs/True_Evolution_in_the_Balance_of_1s_and_0s.png");

  //-----------------------------------------------------------------------//

  TCanvas* abs_c1 = new TCanvas("Evolution in the Absolute Value of Balance of 1s and 0",
			    "Evolution in the Absolute Value of Balance of 1s and 0s",
			    900,600);
  abs_c1->Pad()->SetGridy();

  abs_additive_graph->Draw("AL");
  abs_additive_graph->SetLineColor(4);
  abs_additive_graph->SetLineWidth(2);
  abs_additive_graph->GetXaxis()->SetTitle("Frame #");
  abs_additive_graph->GetYaxis()->SetTitle("abs(#1 - #0)");
  abs_additive_graph->GetYaxis()->SetRangeUser(0,100000);
  //  abs_additive_graph->GetXaxis()->SetRangeUser(0,335e3);
  abs_additive_graph->SetTitle("Evolution in the Absolute Value of Balance of 1s and 0s");

  abs_Karol_graph->Draw("same");
  abs_Karol_graph->SetLineColor(2);
  abs_Karol_graph->SetLineWidth(2);
  abs_Karol_graph->SetMarkerStyle(0);

  //desync9X_graph->Draw("same");
  //desync9X_graph->SetLineColor(6);
  //desync9X_graph->SetLineWidth(2);

  abs_velopix_graph->Draw("same");
  abs_velopix_graph->SetLineColor(8);
  abs_velopix_graph->SetLineWidth(2);

  TLegend* abs_leg = new TLegend(0.7,0.82,0.9,0.9);
  //  abs_leg->Abs_AddEntry(desync9X_graph,"Dysync 9X","l");
  abs_leg->AddEntry(abs_velopix_graph,"VeloPix Scrambler","l");
  abs_leg->AddEntry(abs_Karol_graph,"Karol Scrambler","l");
  abs_leg->AddEntry(abs_additive_graph,"Additive Scrambler","l");
  abs_leg->Draw();

 
  abs_c1->Update();
  abs_c1->SaveAs("graphs/Abs_Evolution_in_the_Balance_of_1s_and_0s.png");
}
