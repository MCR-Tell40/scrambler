#quit -sim 
#restart -f
#vsim -c -t ps -novopt work.velo_scrambler_top

add wave -divider Top
add wave -position end  sim:/velo_scrambler_top/csi_Clock_160MHz
add wave -position end  sim:/velo_scrambler_top/rsi_Reset
add wave -position end  sim:/velo_scrambler_top/read_inst1/pixel_read1

add wave -divider Scrambler
add wave -position end  sim:/velo_scrambler_top/scramble_inst1/dataIn
add wave -position end  sim:/velo_scrambler_top/scramble_inst1/state
add wave -position end  sim:/velo_scrambler_top/scramble_inst1/dataOutEval

add wave -divider DeScrambler_VHDL
add wave -position end  sim:/velo_scrambler_top/descramble_inst1/frameIn
add wave -position end  sim:/velo_scrambler_top/descramble_inst1/state
add wave -position end  sim:/velo_scrambler_top/descramble_inst1/nextState
add wave -position end  sim:/velo_scrambler_top/descramble_inst1/dataOutEval

add wave -divider Verilog
add wave -position end  sim:/velo_scrambler_top/vlog_scrambler/dataIn
add wave -position end  sim:/velo_scrambler_top/vlog_scrambler/state
add wave -position end  sim:/velo_scrambler_top/vlog_scrambler/nextState
add wave -position end  sim:/velo_scrambler_top/vlog_scrambler/dataOutEval

add wave -divider DeScrambler_Verilog
add wave -position end  sim:/velo_scrambler_top/vlog_descrambler/frameIn
add wave -position end  sim:/velo_scrambler_top/vlog_descrambler/state
add wave -position end  sim:/velo_scrambler_top/vlog_descrambler/nextState
add wave -position end  sim:/velo_scrambler_top/vlog_descrambler/dataOutEval

force -freeze sim:/velo_scrambler_top/csi_Clock_160MHz 1 0, 0 {3125 ps} -r 6.25ns
force -freeze sim:/velo_scrambler_top/rsi_Reset 1,0 1ns

config wave -signalnamewidth 1

run 50ns
