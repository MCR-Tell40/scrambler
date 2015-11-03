#include "root_transition_analysis.h"

void graph_init(int data_points)
{
  if (argc>=3)
  histogram[0] = new TH1F(
			  "desync9X_scrambler_hist",
			  "Transitions per Frame in Desync9X-Scrambled Data",
			  60,30,90
			  );
  if (argc>=4)
  histogram[1] = new TH1F(
			  "Karol_scrambler_hist",
			  "Transitions per Frame in New-Scrambled Data",
			  60,30,90
			  );
  if (agrc>=5)
  histogram[2] = new TH1F(
			  "additive_scrambler_hist",
			  "Transitions per Frame in Additive-Scrambled Data",
			  60,30,90
			  );
  if (argc>=6)
  histogram[3] = new TH1F(
			  "Velopix_scrambler_hist",
			  "Transitions per Frame in Additive-Scrambled Data",
			  60,30,90
			  );
}

void draw_graphs()
{
  for (int j(0); j<input_file.size(); j++)
    {
      int count(0);
    while (!input_file[j]-eof())
      {
	string input;
	input_file[j] >> temp;
	histogram[j] -> Fill(transition_count(str_to_frame(input)));

	count ++;
	if (!count % 10000) cout << histogram[j].getTitle() << count << endl;
      }
}

frame str_to_frame(string signal)
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
    hist->write();
  output_file->Close();
}
