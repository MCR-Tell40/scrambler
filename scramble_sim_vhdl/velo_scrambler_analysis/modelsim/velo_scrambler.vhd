
-- Translatiing the VELO scrambler into VHDL from Verilog
-- Author Ben Jeffrey
-- Date Created 29/10/15
-- Algorithm by Sandeep from NIKHEF


-- IEEE VHDL standard library:
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

-- need to create entity
-- need to create architecture
-- need to create process

entity VeloPixScrambler is
  port(
    clk: in std_logic;
    rst: in std_logic;
    valid_in: in std_logic;
    valid_out: out std_logic;
    frameIn: in std_logic_vector(29 downto 0);
    scramble_out: out std_logic_vector(29 downto 0)
    );
end VeloPixScrambler;

architecture a of VeloPixScrambler is


  signal state, nextState, dataOutEval : std_logic_vector(29 downto 0);
  constant reset_pattern:  std_logic_vector(29 downto 0 ) := "10" & x"AAAAAAA";
--  constant reset_pattern:  std_logic_vector(29 downto 0 ) := (others => '0');
--  constant reset_pattern : std_logic_vector( 29 downto 0) := (2 downto 0 => '1', others => '0');

-------------------ALGORITHM ---------------------
begin

 
		nextState(0) <= frameIn(0) XOR state(0) XOR state(1) XOR state(15) XOR state(16);
		nextState(1) <= frameIn(1) XOR state(1) XOR state(2) XOR state(16) XOR state(17);
		nextState(2) <= frameIn(2) XOR state(2) XOR state(3) XOR state(17) XOR state(18);
		nextState(3) <= frameIn(3) XOR state(3) XOR state(4) XOR state(18) XOR state(19);
		nextState(4) <= frameIn(4) XOR state(4) XOR state(5) XOR state(19) XOR state(20);
		nextState(5) <= frameIn(5) XOR state(5) XOR state(6) XOR state(20) XOR state(21);
		nextState(6) <= frameIn(6) XOR state(6) XOR state(7) XOR state(21) XOR state(22);
		nextState(7) <= frameIn(7) XOR state(7) XOR state(8) XOR state(22) XOR state(23);
		nextState(8) <= frameIn(8) XOR state(8) XOR state(9) XOR state(23) XOR state(24);
		nextState(9) <= frameIn(9) XOR state(9) XOR state(10) XOR state(24) XOR state(25);
		nextState(10) <= frameIn(10) XOR state(10) XOR state(11) XOR state(25) XOR state(26);
		nextState(11) <= frameIn(11) XOR state(11) XOR state(12) XOR state(26) XOR state(27);
		nextState(12) <= frameIn(12) XOR state(12) XOR state(13) XOR state(27) XOR state(28);
		nextState(13) <= frameIn(13) XOR state(13) XOR state(14) XOR state(28) XOR state(29);
		nextState(14) <= frameIn(14) XOR state(14) XOR state(15) XOR state(29) XOR nextState(0);
		nextState(15) <= frameIn(15) XOR state(15) XOR state(16) XOR nextState(0) XOR nextState(1);
		nextState(16) <= frameIn(16) XOR state(16) XOR state(17) XOR nextState(1) XOR nextState(2);
		nextState(17) <= frameIn(17) XOR state(17) XOR state(18) XOR nextState(2) XOR nextState(3);
		nextState(18) <= frameIn(18) XOR state(18) XOR state(19) XOR nextState(3) XOR nextState(4);
		nextState(19) <= frameIn(19) XOR state(19) XOR state(20) XOR nextState(4) XOR nextState(5);
		nextState(20) <= frameIn(20) XOR state(20) XOR state(21) XOR nextState(5) XOR nextState(6);
		nextState(21) <= frameIn(21) XOR state(21) XOR state(22) XOR nextState(6) XOR nextState(7);
		nextState(22) <= frameIn(22) XOR state(22) XOR state(23) XOR nextState(7) XOR nextState(8);
		nextState(23) <= frameIn(23) XOR state(23) XOR state(24) XOR nextState(8) XOR nextState(9);
		nextState(24) <= frameIn(24) XOR state(24) XOR state(25) XOR nextState(9) XOR nextState(10);
		nextState(25) <= frameIn(25) XOR state(25) XOR state(26) XOR nextState(10) XOR nextState(11);
		nextState(26) <= frameIn(26) XOR state(26) XOR state(27) XOR nextState(11) XOR nextState(12);
		nextState(27) <= frameIn(27) XOR state(27) XOR state(28) XOR nextState(12) XOR nextState(13);
		nextState(28) <= frameIn(28) XOR state(28) XOR state(29) XOR nextState(13) XOR nextState(14);
		nextState(29) <= frameIn(29) XOR state(29) XOR nextState(0) XOR nextState(14) XOR nextState(15);
		dataOutEval <= nextState;

--------------- END OF ALGORITHM ---------------------

  process(clk,rst)
  begin
    if rst = '1' then
      state <= reset_pattern;
      scramble_out <= (others => '0');
      valid_out <= '0';
    else
      if rising_edge(clk) then
        
        if valid_in = '1' then
          scramble_out <= dataOutEval;
          state <= frameIn;
        else
          scramble_out <= frameIn;
          state <= reset_pattern;
        end if;
        valid_out <= valid_in;
      end if;
    end if;
  end process;
end a;