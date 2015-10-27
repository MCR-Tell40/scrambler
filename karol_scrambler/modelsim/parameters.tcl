restart -f

vsim -c -t ps -novopt work.scrambler_top

config wave -signalnamewidth 1

add wave -noupdate -divider -height 32 TX
add wave -position end -group TX sim:/scrambler_top/TX/TX_RESET_I
add wave -position end  -group TX sim:/scrambler_top/TX/RESET_PATTERN_I
add wave -position end  -group TX sim:/scrambler_top/TX/TX_FRAMECLK_I
add wave -position end  -group TX sim:/scrambler_top/TX/TX_DATA_I
add wave -position end  -group TX sim:/scrambler_top/TX/TX_COMMON_FRAME_O
add wave -position end  -group TX sim:/scrambler_top/TX/feedbackRegister

add wave -noupdate -divider -height 32 RX
add wave -position end  -group RX sim:/scrambler_top/RX/RX_RESET_I
add wave -position end  -group RX sim:/scrambler_top/RX/RX_FRAMECLK_I
add wave -position end  -group RX sim:/scrambler_top/RX/RX_COMMON_FRAME_I
add wave -position end  -group RX sim:/scrambler_top/RX/rx_data_temp
add wave -position end  -group RX sim:/scrambler_top/RX/rx_data_out
add wave -position end  -group RX sim:/scrambler_top/RX/feedbackRegister
add wave -position end  -group RX sim:/scrambler_top/rsi_Reset
add wave -position end  -group RX sim:/scrambler_top/csi_Clock_160MHz

add wave -noupdate -divider -height 32 TOP
add wave -position end  -group TOP sim:/scrambler_top/scrambler_data_out
add wave -position end  -group TOP sim:/scrambler_top/data_reg
add wave -position end  -group TOP sim:/scrambler_top/reset_reg
add wave -position end  -group TOP sim:/scrambler_top/clock160_reg
add wave -position end  -group TOP sim:/scrambler_top/common_frame_output_reg
add wave -position end  -group TOP sim:/scrambler_top/reset_pattern_reg
add wave -position end  -group TOP sim:/scrambler_top/data_output_reg

force -freeze sim:/scrambler_top/rsi_Reset 1,0 1ns
force -freeze sim:/scrambler_top/csi_Clock_160MHz 1 0, 0 {3 ns} -r 6.25ns

run 20ns
wave zoom full