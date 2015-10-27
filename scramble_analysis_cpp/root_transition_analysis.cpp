#include "root_transition_analysis.h"

int count_data_points()
{
  int count(0);
  while(!un_scrambled_datafile->eof())
    {
      string temp;
      *un_scrambled_datafile >> temp;
      count++;
    }
  return count;
}

void graph_init(int data_points)
{
  un_scrambled_graph = new TGraph(data_points-1);
  new_scrambled_graph = new TGraph(data_points-1);
  old_scrambled_graph = new TGraph(data_points-1);

  pre_scramble_hist = new TH1F(
			       "pre_scramble_hist",
			       "Transitions per Packet in Pre-Scrambled Data",
			       60,30,90
			       );
  new_scramble_hist = new TH1F(
			       "new_scramble_hist",
			       "Transitions per Packet in New-Scrambled Data",
			       60,30,90
			       );
  old_scramble_hist = new TH1F(
			       "old_scramble_hist",
			       "Transitions per Packet in Old-Scrambled Data",
			       60,30,90
			       );
}

void draw_graphs(int data_points)
{
  for (int i(0); i < data_points-1; i++)
    {
      string temp;
      *un_scrambled_datafile >> temp;
      if (transition_count(str_to_packet(temp)!=0))
	un_scrambled_graph -> SetPoint(i,i,transition_count(str_to_packet(temp)));
      pre_scramble_hist -> Fill(transition_count(str_to_packet(temp)));

      *new_scrambled_datafile >> temp;
      if (transition_count(str_to_packet(temp)!=0))
	new_scrambled_graph -> SetPoint(i,i,transition_count(str_to_packet(temp)));
      new_scramble_hist -> Fill(transition_count(str_to_packet(temp)));

      *old_scrambled_datafile >> temp;
      if (transition_count(str_to_packet(temp)!=0))
	old_scrambled_graph -> SetPoint(i,i,transition_count(str_to_packet(temp)));
      old_scramble_hist -> Fill(transition_count(str_to_packet(temp)));
    }
}

packet str_to_packet(string signal)
{
  packet _packet = 0;
    
  for (int index(1); index <= 128; index++)
    if (signal[128-index] == '1')
      _packet[index-1] = 1;
    
  return _packet;
}

int transition_count(packet DATA)
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
  un_scrambled_graph -> Write("Un_Scramble");
  new_scrambled_graph -> Write("New_Scramble");
  old_scrambled_graph -> Write("Old_Scramble");
  pre_scramble_hist -> Write();
  new_scramble_hist -> Write();
  old_scramble_hist -> Write();
  output_file->Close();
}
