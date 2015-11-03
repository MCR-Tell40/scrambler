#ifndef __root_graph_transitions_h__
#define __root_graph_transitions_h__

#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TGraph.h>
#include <TH1.h>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

//typedef
typedef bitset<128> frame;

//files
vector<fstream*> input_file;
TFile   *  output_file;

//hists
vector<TH1F*> histogram;

//funcitons
int    count_data_points ();
void   graph_init        (int);
void   draw_graphs       (int);
int    transition_count  (frame);
frame  str_to_frame      (string);
void   save_graphs       ();
            
int main(int argc, const char ** argv)
{
  if (argc = 1)
    {
      cout << "Invalid arguments, please use form: $ <executable> <unscrambled> <new_scrambled> <additive_scrambled> <output_file>" << endl;
      return 1;
    }
  else
    {
      for (int i(1); i <argc-1; i++)
	input_file.push_back(new fstream(argv[i],fstream::in));

      output_file = new TFile(argv[argc-1], "RECREATE");
    }
    
  int data_points(count_data_points());
  cout << data_points << " data_points" << endl;
    
  graph_init(data_points);
    
  draw_graphs(data_points);

  save_graphs();
    
  return 0;
}

#endif
