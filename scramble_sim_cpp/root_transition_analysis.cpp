#include "root_transition_analysis.h"

void graph_init()
{
  if (input_file.size()>=1)
    histogram.push_back( new TH1F(
      "desync9X_scrambler_hist",
      "Transitions per Frame in Desync9X-Scrambled Data",
      60,30,90
      ));
  if (input_file.size()>=2)
    histogram.push_back( new TH1F(
      "Karol_scrambler_hist",
      "Transitions per Frame in New-Scrambled Data",
      60,30,90
      ));
  if (input_file.size()>=3)
    histogram.push_back( new TH1F(
      "additive_scrambler_hist",
      "Transitions per Frame in Additive-Scrambled Data",
      60,30,90
      ));
  if (input_file.size()>=4)
    histogram.push_back( new TH1F(
      "Velopix_scrambler_hist",
      "Transitions per Frame in Additive-Scrambled Data",
      60,30,90
      ));
  if (input_file.size()>=5)
    histogram.push_back( new TH1F(
      "Random_data_hist",
      "Transitions per Frame in Randomly Generated Data",
      60,30,90
      ));
}

void draw_graphs()
{
  for (int j(0); j<input_file.size(); j++)
  {
    #ifdef __TRANSITION_DEBUG__
    cout << "draw_graphs()" << endl;
    #endif
    
    int count(0);
    string input;
    
    while (*input_file[j] >> input)
    {
     histogram[j] -> Fill(transition_count(str_to_frame(input)));

     if (count%10000 == 0) cout << histogram[j]->GetName() << count << endl;
     count ++;
    }
  }
}frame str_to_frame(string signal)
{
  frame _frame = 0;

  for (int index(1); index <= 128; index++)
    if (signal[128-index] == '1')
      _frame[index-1] = 1;
    
    return _frame;
  }

  int transition_count(frame DATA)
  {
    int count(0);
    
    for (int i(1); i < 120 ; i++)
      if (DATA[i] != DATA[i-1])
        count++;

      return count;
    }

    void save_graphs()
    {
      output_file -> cd();
      for (auto& hist: histogram)
        hist->Write();
      output_file->Close();
    }
