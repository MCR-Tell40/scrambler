#include "root_longest_chain.h"

void graph_init()
{
  if (input_file.size()>=1)
    histogram.push_back( new TH1F(
				  "desync9X_scrambler_hist",
				  "Chain Lengths in Desync9X-Scrambled Data",
				  30,0,30
				  ));
  if (input_file.size()>=2)
    histogram.push_back( new TH1F(
				  "Karol_scrambler_hist",
				  "Chain Lengths in New-Scrambled Data",
				  30,0,30
				  ));
  if (input_file.size()>=3)
    histogram.push_back( new TH1F(
				  "additive_scrambler_hist",
				  "Chain Lengths in Additive-Scrambled Data",
				  30,0,30
				  ));
  if (input_file.size()>=4)
    histogram.push_back( new TH1F(
				  "Velopix_scrambler_hist",
				  "Chain Lengths in Additive-Scrambled Data",
				  30,0,30
				  ));
  if (input_file.size()>=5)
    histogram.push_back( new TH1F(
				  "Random_data_hist",
				  "Chain Lengths in Random Data",
				  30,0,30
				  ));
}

void draw_graphs()
{
  for (int i(0); i < input_file.size(); i++)
    {
#ifdef __TRANSITION_DEBUG__
      cout << "draw_graphs()" << endl;
#endif
      int count(0);
      while (!input_file[i]->eof())
	{
	  string input;
	  *input_file[i] >> input;
	  chain_count(str_to_frame(input),histogram[i]);
      
	  count ++;
	  if (count%10000 == 0) cout << histogram[i]->GetName() << count << endl;
	}
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

int chain_count(frame DATA, TH1F* histogram) //IN PROGRESS
{ 
  int chain_length(1);
  for (int i(1); i < 120 ; i++)
    {
      if (DATA[i] == DATA[i-1] && DATA[i] == 1)
	//if (DATA[i] == 0)  //chains of 0's
	//if (DATA[i] == 1)  //chains of 1's
	{
	  chain_length = chain_length+1;	 
	}
      else
	{
	 histogram -> Fill(chain_length);	  
	  chain_length = 1;
	}         
    }
  return 0;
}

void save_graphs()
{
  output_file -> cd();
  for (auto& hist: histogram)
    hist->Write();
  output_file->Close();
}
