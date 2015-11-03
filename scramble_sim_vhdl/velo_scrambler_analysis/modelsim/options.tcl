vsim -t ps -novopt work.VeloPixScrambler work.velo_scrambler_top work.the_reader work.the_writer

add wave -position end  sim:/velo_scrambler_top/rsi_Reset
add wave -position end  sim:/velo_scrambler_top/csi_Clock_160MHz

add wave -position end  sim:/velo_scrambler_top/read_to_scramble1
add wave -position end  sim:/velo_scrambler_top/read_to_scramble2
add wave -position end  sim:/velo_scrambler_top/read_to_scramble3
add wave -position end  sim:/velo_scrambler_top/read_to_scramble4


add wave -position end  sim:/velo_scrambler_top/scramble_to_descramble1
add wave -position end  sim:/velo_scrambler_top/scramble_to_descramble2
add wave -position end  sim:/velo_scrambler_top/scramble_to_descramble3
add wave -position end  sim:/velo_scrambler_top/scramble_to_descramble4

add wave -position end  sim:/velo_scrambler_top/descramble_to_write1
add wave -position end  sim:/velo_scrambler_top/descramble_to_write2
add wave -position end  sim:/velo_scrambler_top/descramble_to_write3
add wave -position end  sim:/velo_scrambler_top/descramble_to_write4

add wave -position end  sim:/velo_scrambler_top/valid_read_scramble
add wave -position end  sim:/velo_scrambler_top/valid_scramble_descramble1
add wave -position end  sim:/velo_scrambler_top/valid_descramble_write1


force -freeze sim:/velo_scrambler_top/csi_Clock_160MHz 1 0, 0 {3125 ps} -r {6.25 ns}
force -freeze sim:/velo_scrambler_top/rsi_Reset 1 0
force -freeze sim:/velo_scrambler_top/rsi_Reset 0 1ns

run 200000 ns
