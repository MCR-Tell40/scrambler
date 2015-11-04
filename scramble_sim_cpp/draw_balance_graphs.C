void draw_balance_graphs()
{
  TFile* f = new TFile("balance_analysis_full.root");

  TGraph* desync9X_graph = (TGraph*)f->Get("desync9X.txt");
  TGraph* Karol_graph = (TGraph*)f->Get("Karol_scramble_output.txt");
  TGraph* additive_graph = (TGraph*)f->Get("additive_scramble_output.txt");
  TGraph* velopix_graph = (TGraph*)f->Get("VeloPix_scramble_output.txt");

  TCanvas* c1 = new TCanvas("Evolution in the Balance of 1s and 0s",
			    "Evolution in the Balance of 1s and 0s",
			    900,600);

  additive_graph->Draw("AL");
  additive_graph->SetLineColor(4);
  additive_graph->SetLineWidth(2);
  additive_graph->GetXaxis()->SetTitle("Frame #");
  additive_graph->GetYaxis()->SetTitle("(#1 - #0)");
  additive_graph->GetYaxis()->SetRangeUser(-17000,40000);
  additive_graph->SetTitle("Evolution in the Balance of 1s and 0s");

  Karol_graph->Draw("same");
  Karol_graph->SetLineColor(2);
  Karol_graph->SetLineWidth(2);
  Karol_graph->SetMarkerStyle(0);

  desync9X_graph->Draw("same");
  desync9X_graph->SetLineColor(6);
  desync9X_graph->SetLineWidth(2);

  velopix_graph->Draw("same");
  velopix_graph->SetLineColor(8);
  velopix_graph->SetLineWidth(2);

  TLegend* leg = new TLegend(0.7,0.5,0.9,0.6);
  leg->AddEntry(desync9X_graph,"Dysync 9X","l");
  leg->AddEntry(Karol_graph,"Markov Scrambler","l");
  leg->AddEntry(velopix_graph,"VeloPix Scrambler","l");
  leg->AddEntry(additive_graph,"Additive Scrambler","l");
  leg->Draw();
  c1->Update();
  c1->SaveAs("Evolution_in_the_Balance_of_1s_and_0s.pdf");
}
