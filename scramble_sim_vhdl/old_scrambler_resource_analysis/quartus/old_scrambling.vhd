-- Scrambling_test code
-- author: B.Jeffrey
-- created: 11/6/15
-- scrambles a 30 bit input signal
-- note: algorithm given by P.Rodriguez

LIBRARY ieee;
LIBRARY work;
USE ieee.std_logic_1164.all;
-- USE work.VELO_Constant_Declaration.all;

use ieee.std_logic_misc.all;
use ieee.numeric_std.all;

ENTITY scrambler IS
  port(
    rst,clk_160MHz:IN std_logic;
    data_in:IN std_logic_vector(29 downto 0);
    data_out:OUT std_logic_vector(29 downto 0)
    );
END scrambler;

ARCHITECTURE scramble_arch OF scrambler IS
  signal lfsr_q : std_logic_vector( 29  downto 0  );
  signal lfsr_c : std_logic_vector( 29  downto 0  );
  signal data_c : std_logic_vector( 29  downto 0  );
begin
  lfsr_c(0 ) <= ( lfsr_q(0 ) xor lfsr_q(29 ) ) ;
  lfsr_c(1 ) <= ( ( lfsr_q(0 ) xor lfsr_q(1 ) )  xor lfsr_q(29 ) ) ;
  lfsr_c(2 ) <= ( lfsr_q(1 ) xor lfsr_q(2 ) ) ;
  lfsr_c(3 ) <= ( lfsr_q(2 ) xor lfsr_q(3 ) ) ;
  lfsr_c(4 ) <= ( lfsr_q(3 ) xor lfsr_q(4 ) ) ;
  lfsr_c(5 ) <= ( lfsr_q(4 ) xor lfsr_q(5 ) ) ;
  lfsr_c(6 ) <= ( lfsr_q(5 ) xor lfsr_q(6 ) ) ;
  lfsr_c(7 ) <= ( lfsr_q(6 ) xor lfsr_q(7 ) ) ;
  lfsr_c(8 ) <= ( lfsr_q(7 ) xor lfsr_q(8 ) ) ;
  lfsr_c(9 ) <= ( lfsr_q(8 ) xor lfsr_q(9 ) ) ;
  lfsr_c(10 ) <= ( lfsr_q(9 ) xor lfsr_q(10 ) ) ;
  lfsr_c(11 ) <= ( lfsr_q(10 ) xor lfsr_q(11 ) ) ;
  lfsr_c(12 ) <= ( lfsr_q(11 ) xor lfsr_q(12 ) ) ;
  lfsr_c(13 ) <= ( lfsr_q(12 ) xor lfsr_q(13 ) ) ;
  lfsr_c(14 ) <= ( lfsr_q(13 ) xor lfsr_q(14 ) ) ;
  lfsr_c(15 ) <= ( lfsr_q(14 ) xor lfsr_q(15 ) ) ;
  lfsr_c(16 ) <= ( lfsr_q(15 ) xor lfsr_q(16 ) ) ;
  lfsr_c(17 ) <= ( lfsr_q(16 ) xor lfsr_q(17 ) ) ;
  lfsr_c(18 ) <= ( lfsr_q(17 ) xor lfsr_q(18 ) ) ;
  lfsr_c(19 ) <= ( lfsr_q(18 ) xor lfsr_q(19 ) ) ;
  lfsr_c(20 ) <= ( lfsr_q(19 ) xor lfsr_q(20 ) ) ;
  lfsr_c(21 ) <= ( lfsr_q(20 ) xor lfsr_q(21 ) ) ;
  lfsr_c(22 ) <= ( lfsr_q(21 ) xor lfsr_q(22 ) ) ;
  lfsr_c(23 ) <= ( lfsr_q(22 ) xor lfsr_q(23 ) ) ;
  lfsr_c(24 ) <= ( lfsr_q(23 ) xor lfsr_q(24 ) ) ;
  lfsr_c(25 ) <= ( lfsr_q(24 ) xor lfsr_q(25 ) ) ;
  lfsr_c(26 ) <= ( lfsr_q(25 ) xor lfsr_q(26 ) ) ;
  lfsr_c(27 ) <= ( lfsr_q(26 ) xor lfsr_q(27 ) ) ;
  lfsr_c(28 ) <= ( lfsr_q(27 ) xor lfsr_q(28 ) ) ;
  lfsr_c(29 ) <= ( lfsr_q(28 ) xor lfsr_q(29 ) ) ;
  data_c(0 ) <= ( data_in(0 ) xor lfsr_q(29 ) ) ;
  data_c(1 ) <= ( data_in(1 ) xor lfsr_q(28 ) ) ;
  data_c(2 ) <= ( data_in(2 ) xor lfsr_q(27 ) ) ;
  data_c(3 ) <= ( data_in(3 ) xor lfsr_q(26) ) ;
  data_c(4 ) <= ( data_in(4 ) xor lfsr_q(25 ) ) ;
  data_c(5 ) <= ( data_in(5 ) xor lfsr_q(24 ) ) ;
  data_c(6 ) <= ( data_in(6 ) xor lfsr_q(23 ) ) ;
  data_c(7 ) <= ( data_in(7 ) xor lfsr_q(22 ) ) ;
  data_c(8 ) <= ( data_in(8 ) xor lfsr_q(21 ) ) ;
  data_c(9 ) <= ( data_in(9 ) xor lfsr_q(20 ) ) ;
  data_c(10 ) <= ( data_in(10 ) xor lfsr_q(19 ) ) ;
  data_c(11 ) <= ( data_in(11 ) xor lfsr_q(18 ) ) ;
  data_c(12 ) <= ( data_in(12 ) xor lfsr_q(17 ) ) ;
  data_c(13 ) <= ( data_in(13 ) xor lfsr_q(16 ) ) ;
  data_c(14 ) <= ( data_in(14 ) xor lfsr_q(15 ) ) ;
  data_c(15 ) <= ( data_in(15 ) xor lfsr_q(14 ) ) ;
  data_c(16 ) <= ( data_in(16 ) xor lfsr_q(13 ) ) ;
  data_c(17 ) <= ( data_in(17 ) xor lfsr_q(12 ) ) ;
  data_c(18 ) <= ( data_in(18 ) xor lfsr_q(11 ) ) ;
  data_c(19 ) <= ( data_in(19 ) xor lfsr_q(10 ) ) ;
  data_c(20 ) <= ( data_in(20 ) xor lfsr_q(9 ) ) ;
  data_c(21 ) <= ( data_in(21 ) xor lfsr_q(8 ) ) ;
  data_c(22 ) <= ( data_in(22 ) xor lfsr_q(7 ) ) ;
  data_c(23 ) <= ( data_in(23 ) xor lfsr_q(6 ) ) ;
  data_c(24 ) <= ( data_in(24 ) xor lfsr_q(5 ) ) ;
  data_c(25 ) <= ( data_in(25 ) xor lfsr_q(4 ) ) ;
  data_c(26 ) <= ( data_in(26 ) xor lfsr_q(3 ) ) ;
  data_c(27 ) <= ( data_in(27 ) xor lfsr_q(2 ) ) ;
  data_c(28 ) <= ( data_in(28 ) xor lfsr_q(1 ) ) ;
  data_c(29 ) <= ( ( data_in(29 ) xor lfsr_q(0 ) )  xor lfsr_q(29 ) ) ;
  process(rst,clk_160MHz)
  begin
    if rst = '1' then
					--lfsr_q <= GWT_Scrambler_Reset_Pattern1;
      data_out<=(others => '0');
    elsif rising_edge(clk_160MHz) then
      lfsr_q <= lfsr_c;
      for i in 0 to 29 loop
        data_out(i) <= data_c(i);
      end loop;
    end if;
  end process;
END scramble_arch;
