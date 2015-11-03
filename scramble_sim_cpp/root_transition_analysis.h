#ifndef __root_graph_transitions_h__
#define __root_graph_transitions_h__

#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TGraph.h>
#include <TH1.h>
#include <string>
#include <bitset>

using namespace std;

//typedef
typedef bitset<128> frame;

//files
fstream ** input_file;
TFile   *  output_file;

//hists
TH1F * histogram;

//nick is awesome
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
      input_file = new fstream[argc-1];

      for (int i(1); i <argc-1; i++)
	input_file[i-1] = new fstream(argv[i],fstream::in);

      output_file = new TFile(argv[argv.size()-1], "RECREATE");
    }
  
  graph_init();
    
  draw_graphs();

  save_graphs();
    
  return 0;
}

#endif
