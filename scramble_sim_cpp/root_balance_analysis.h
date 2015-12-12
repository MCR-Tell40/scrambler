#ifndef __root_graph_transitions_h__
#define __root_graph_transitions_h__

#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TGraph.h>
#include <TH1.h>
#include <TVector.h>
#include <TVectorfwd.h>
#include <TMatrix.h>
#include <string>
#include <sstream>
#include <bitset>
#include <vector>

#define __DEBUG__

using namespace std;

//typedef
typedef bitset<128> frame;

//files
vector<fstream*> input_file;
TFile   * output_file;

//graphs
vector<TGraph*> true_graph;
vector<TGraph*> abs_graph;

vector<vector<int>> true_balance;
vector<vector<int>> abs_balance;

//funcitons
void fillVector    (fstream* file, vector<int>& _true, vector<int>& _abs);
void draw_graph    (TGraph* true_, TGraph* abs_, vector<int> true__, vector<int> abs__, string);
frame str_to_frame (string);

int main(int argc, const char ** argv)
{
  if (argc == 1)
  {
    cout << "Invalid arguments, please use form: $ <executable> <unscrambled> <new_scrambled> <old_scrambled> <output_file>" << endl;
    return 1;
  }
  else
  {
#ifdef __DEBUG__
    cout << "argc = " << argc <<endl;
#endif

    for (int i(1); i<argc-1;  i++)
     input_file.push_back(new fstream(argv[i],fstream::in));

#ifdef __DEBUG__
   cout << "In files created" <<endl;
#endif

   output_file = new TFile(argv[argc-1], "RECREATE");
 }

#ifdef __DEBUG__
 cout << "Files Opened" <<endl;
#endif 

 for(int i(0); i<argc-2; i++)
 {
  true_graph.push_back(new TGraph());
  abs_graph.push_back(new TGraph());
  true_balance.push_back(vector<int>());
  abs_balance.push_back(vector<int>());
  fillVector(input_file[i], true_balance[i], abs_balance[i]);    
  
  #ifdef __DEBUG__
  cout << "Vector Filled" <<endl;
  #endif
  
  draw_graph(true_graph[i],abs_graph[i], true_balance[i], abs_balance[i], argv[i+1]);
}


output_file->Close();

return 0;
}

#endif
