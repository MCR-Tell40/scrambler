#include "root_balance_analysis.h"

void fillVector(fstream* file, vector<int>& balance)
{
  long count(0);

  while (!file->eof())
  //for (int j(0); j < 20; j++)
    {
      string input;
      *file >> input;
      frame line = str_to_frame(input);

      for (int i(0); i<120; i++)
	{
	  if (line[i] == 1) count++;
	  else count--; 

	} 
      balance.push_back(count);	
    }
}

void draw_graph(TGraph* graph, vector<int> datay, string name)
{
  int* y = &datay[0];

  int* x = new int[datay.size()];
  
  for (int i(0); i < datay.size(); i++)
    x[i] = i;
  
  delete graph;
  graph = new TGraph(datay.size(),x,y);  
  
  output_file->cd();
  graph->Write(name.c_str());

  delete x;
}

frame str_to_frame(string signal)
{
  frame _frame = 0;
    
  for (int index(1); index <= 128; index++)
    if (signal[128-index] == '1')
      _frame[index-1] = 1;
    
  return _frame;
}
