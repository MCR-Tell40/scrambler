ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS  = $(shell root-config --libs)
FLAGS = -std=c++11

all: scramble_sim root_transition_analysis root_longest_chain root_balance_analysis

scramble_sim: scramble_sim.cpp scramble_sim.h
	g++ -o $@ scramble_sim.cpp

root_transition_analysis: root_transition_analysis.cpp root_transition_analysis.h
	g++ -o $@ root_transition_analysis.cpp $(ROOTFLAGS) $(ROOTLIBS) $(FLAGS)

root_longest_chain: root_longest_chain.cpp root_longest_chain.h
	g++ -o $@ root_longest_chain.cpp $(ROOTFLAGS) $(ROOTLIBS) $(FLAGS)

root_balance_analysis: root_balance_analysis.cpp root_balance_analysis.h
	g++ -o $@ root_balance_analysis.cpp $(ROOTFLAGS) $(ROOTLIBS) $(FLAGS)

run_short: scramble_sim root_transition_analysis root_longest_chain root_balance_analysis
	./scramble_sim             desyncFilter.txt Karol_scramble_output.txt additive_scramble_output.txt VeloPix_scramble_output.txt
	./root_transition_analysis desyncFilter.txt Karol_scramble_output.txt additive_scramble_output.txt VeloPix_scramble_output.txt transition_analysis_short.root
	./root_longest_chain       desyncFilter.txt Karol_scramble_output.txt additive_scramble_output.txt VeloPix_scramble_output.txt longest_chain_short.root
	./root_balance_analysis    desyncFilter.txt Karol_scramble_output.txt additive_scramble_output.txt VeloPix_scramble_output.txt balance_analysis_short.root

run_9X: scramble_sim root_transition_analysis root_longest_chain root_balance_analysis
	./scramble_sim             desync9X.txt Karol_scramble_output.txt additive_scramble_output.txt VeloPix_scramble_output.txt
	./root_transition_analysis desync9X.txt Karol_scramble_output.txt additive_scramble_output.txt VeloPix_scramble_output.txt random_data_output.txt transition_analysis_full.root
	./root_longest_chain       desync9X.txt Karol_scramble_output.txt additive_scramble_output.txt VeloPix_scramble_output.txt random_data_output.txt longest_chain_full.root
	./root_balance_analysis    desync9X.txt Karol_scramble_output.txt additive_scramble_output.txt VeloPix_scramble_output.txt random_data_output.txt balance_analysis_full.root

run_X: scramble_sim root_transition_analysis root_longest_chain root_balance_analysis
	./scramble_sim             desyncX.txt Karol_scramble_output_x.txt additive_scramble_output_x.txt VeloPix_scramble_output_x.txt
	./root_transition_analysis desyncX.txt Karol_scramble_output_x.txt additive_scramble_output_x.txt VeloPix_scramble_output_x.txt random_data_output_x.txt transition_analysis_X.root
	./root_longest_chain       desyncX.txt Karol_scramble_output_x.txt additive_scramble_output_x.txt VeloPix_scramble_output_x.txt random_data_output_x.txt longest_chain_X.root
	./root_balance_analysis    desyncX.txt Karol_scramble_output_x.txt additive_scramble_output_x.txt VeloPix_scramble_output_x.txt random_data_output_x.txt balance_analysis_X.root

clean:
	rm -f scramble_sim
	rm -f root_transition_analysis
	rm -f root_longest_chain
