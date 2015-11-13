#include "root_balance_analysis.h"

void fillVector(fstream* file, vector<int>& true_balance, vector<int>& abs_balance)
{
  long count(0);
  static int filenumber(-1);
  filenumber++;
  cout << "Analysising file " << filenumber << endl;
  long lineCount(0);
  while (!file->eof())
  //for (int j(0); j < 20; j++)
    {
      string input;
      *file >> input;
      frame line = str_to_frame(input);

      if (lineCount % 10000 == 0)
	cout << lineCount << endl;
      
      lineCount++;

      for (int i(0); i<120; i++)
	{
	  if (line[i] == 1) count++;
	  else count--; 

	} 
      true_balance.push_back(count);
      abs_balance.push_back(abs(count));	
    }
}

void draw_graph(TGraph* true_graph, TGraph* abs_graph, vector<int> true_datay, vector<int> abs_datay, string name)
{
  int* true_y = &true_datay[0];
  int* abs_y = &abs_datay[0];

#ifdef __DEBUG__
      cout << "Y data converted to array" <<endl;
#endif

  int* x = new int[true_datay.size()];
  
  for (int i(0); i < true_datay.size(); i++)
    x[i] = i;
  
#ifdef __DEBUG__
      cout << "X data created" <<endl;
#endif

  delete true_graph;
  true_graph = new TGraph(true_datay.size(),x,true_y);  
  
  delete abs_graph;
  abs_graph = new TGraph(abs_datay.size(),x,abs_y);  

#ifdef __DEBUG__
  cout << "Graphs Created" <<endl;
#endif

  stringstream true_filename;
  true_filename << "true_" << name.c_str();

  output_file->cd();
  true_graph->Write(true_filename.str().c_str());

#ifdef __DEBUG__
  cout << "True Graph Written" <<endl;
#endif


  stringstream abs_filename;
  abs_filename << "abs_" << name.c_str();

  output_file->cd();
  abs_graph->Write(abs_filename.str().c_str());
 
#ifdef __DEBUG__
  cout << "Abs Graph Written" <<endl;
#endif

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
