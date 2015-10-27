vsim -t ps -novopt work.gwt_rx_descrambler_30bit_new work.new_scrambler_top work.the_reader work.the_writer

add wave -position end  sim:/new_scrambler_top/rsi_Reset
add wave -position end  sim:/new_scrambler_top/csi_Clock_160MHz

add wave -position end  sim:/new_scrambler_top/read_to_descramble
add wave -position end  sim:/new_scrambler_top/descramble_to_write

force -freeze sim:/new_scrambler_top/csi_Clock_160MHz 1 0, 0 {3125 ps} -r {6.25 ns}
force -freeze sim:/new_scrambler_top/rsi_Reset 1 0
force -freeze sim:/new_scrambler_top/rsi_Reset 0 1ns

run 83820 ns