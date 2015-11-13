
-- Translatiing the VELO scrambler into VHDL from Verilog
-- Author Ben Jeffrey
-- Date Created 29/10/15
-- Algorithm by Sandeep from NIKHEF


-- IEEE VHDL standard library:
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity VeloPixScrambler is
  port(
    dataIn      : in std_logic_vector(29 downto 0);
    state       : in std_logic_vector(29 downto 0);
    dataOutEval : out std_logic_vector(29 downto 0)
    );
end VeloPixScrambler;



architecture a of VeloPixScrambler is


-------------------ALGORITHM ---------------------
begin

  dataOutEval(0)  <= dataIn(0)  XOR state(0)  XOR state(1)  XOR state(15)  XOR state(16);
  dataOutEval(1)  <= dataIn(1)  XOR state(1)  XOR state(2)  XOR state(16)  XOR state(17);
  dataOutEval(2)  <= dataIn(2)  XOR state(2)  XOR state(3)  XOR state(17)  XOR state(18);
  dataOutEval(3)  <= dataIn(3)  XOR state(3)  XOR state(4)  XOR state(18)  XOR state(19);
  dataOutEval(4)  <= dataIn(4)  XOR state(4)  XOR state(5)  XOR state(19)  XOR state(20);
  dataOutEval(5)  <= dataIn(5)  XOR state(5)  XOR state(6)  XOR state(20)  XOR state(21);
  dataOutEval(6)  <= dataIn(6)  XOR state(6)  XOR state(7)  XOR state(21)  XOR state(22);
  dataOutEval(7)  <= dataIn(7)  XOR state(7)  XOR state(8)  XOR state(22)  XOR state(23);
  dataOutEval(8)  <= dataIn(8)  XOR state(8)  XOR state(9)  XOR state(23)  XOR state(24);
  dataOutEval(9)  <= dataIn(9)  XOR state(9)  XOR state(10) XOR state(24)  XOR state(25);
  dataOutEval(10) <= dataIn(10) XOR state(10) XOR state(11) XOR state(25)  XOR state(26);
  dataOutEval(11) <= dataIn(11) XOR state(11) XOR state(12) XOR state(26)  XOR state(27);
  dataOutEval(12) <= dataIn(12) XOR state(12) XOR state(13) XOR state(27)  XOR state(28);
  dataOutEval(13) <= dataIn(13) XOR state(13) XOR state(14) XOR state(28)  XOR state(29);
  dataOutEval(14) <= dataIn(14) XOR state(14) XOR state(15) XOR state(29)  XOR dataIn(0) XOR state(0)  XOR state(1)  XOR state(15)  XOR state(16);
  dataOutEval(15) <= dataIn(15) XOR state(15) XOR state(16) XOR dataIn(0)  XOR state(0)  XOR state(1)  XOR state(15)  XOR state(16)  XOR dataIn(1)  XOR state(1)  XOR state(2)  XOR state(16)  XOR state(17);
  dataOutEval(16) <= dataIn(16) XOR state(16) XOR state(17) XOR dataIn(1)  XOR state(1)  XOR state(2)  XOR state(16)  XOR state(17)  XOR dataIn(2)  XOR state(2)  XOR state(3)  XOR state(17)  XOR state(18);
  dataOutEval(17) <= dataIn(17) XOR state(17) XOR state(18) XOR dataIn(2)  XOR state(2)  XOR state(3)  XOR state(17)  XOR state(18)  XOR dataIn(3)  XOR state(3)  XOR state(4)  XOR state(18)  XOR state(19);
  dataOutEval(18) <= dataIn(18) XOR state(18) XOR state(19) XOR dataIn(3)  XOR state(3)  XOR state(4)  XOR state(18)  XOR state(19)  XOR dataIn(4)  XOR state(4)  XOR state(5)  XOR state(19)  XOR state(20);
  dataOutEval(19) <= dataIn(19) XOR state(19) XOR state(20) XOR dataIn(4)  XOR state(4)  XOR state(5)  XOR state(19)  XOR state(20)  XOR dataIn(5)  XOR state(5)  XOR state(6)  XOR state(20)  XOR state(21);
  dataOutEval(20) <= dataIn(20) XOR state(20) XOR state(21) XOR dataIn(5)  XOR state(5)  XOR state(6)  XOR state(20)  XOR state(21)  XOR dataIn(6)  XOR state(6)  XOR state(7)  XOR state(21)  XOR state(22);
  dataOutEval(21) <= dataIn(21) XOR state(21) XOR state(22) XOR dataIn(6)  XOR state(6)  XOR state(7)  XOR state(21)  XOR state(22)  XOR dataIn(7)  XOR state(7)  XOR state(8)  XOR state(22)  XOR state(23);
  dataOutEval(22) <= dataIn(22) XOR state(22) XOR state(23) XOR dataIn(7)  XOR state(7)  XOR state(8)  XOR state(22)  XOR state(23)  XOR dataIn(8)  XOR state(8)  XOR state(9)  XOR state(23)  XOR state(24);
  dataOutEval(23) <= dataIn(23) XOR state(23) XOR state(24) XOR dataIn(8)  XOR state(8)  XOR state(9)  XOR state(23)  XOR state(24)  XOR dataIn(9)  XOR state(9)  XOR state(10) XOR state(24)  XOR state(25);
  dataOutEval(24) <= dataIn(24) XOR state(24) XOR state(25) XOR dataIn(9)  XOR state(9)  XOR state(10) XOR state(24)  XOR state(25)  XOR dataIn(10) XOR state(10) XOR state(11) XOR state(25)  XOR state(26);
  dataOutEval(25) <= dataIn(25) XOR state(25) XOR state(26) XOR dataIn(10) XOR state(10) XOR state(11) XOR state(25)  XOR state(26)  XOR dataIn(11) XOR state(11) XOR state(12) XOR state(26)  XOR state(27);
  dataOutEval(26) <= dataIn(26) XOR state(26) XOR state(27) XOR dataIn(11) XOR state(11) XOR state(12) XOR state(26)  XOR state(27)  XOR dataIn(12) XOR state(12) XOR state(13) XOR state(27)  XOR state(28);
  dataOutEval(27) <= dataIn(27) XOR state(27) XOR state(28) XOR dataIn(12) XOR state(12) XOR state(13) XOR state(27)  XOR state(28)  XOR dataIn(13) XOR state(13) XOR state(14) XOR state(28)  XOR state(29);
  dataOutEval(28) <= dataIn(28) XOR state(28) XOR state(29) XOR dataIn(13) XOR state(13) XOR state(14) XOR state(28)  XOR state(29)  XOR dataIn(14) XOR state(14) XOR state(15) XOR state(29)  XOR dataIn(0) XOR state(0)  XOR state(1)  XOR state(15)  XOR state(16);
  dataOutEval(29) <= dataIn(29) XOR state(29) XOR dataIn(0)  XOR state(0)  XOR state(1)  XOR state(15)  XOR state(16) XOR dataIn(14) XOR state(14) XOR state(15) XOR state(29)  XOR dataIn(0) XOR state(0)  XOR state(1)  XOR state(15)  XOR state(16) XOR dataIn(15) XOR state(15) XOR state(16) XOR dataIn(0)  XOR state(0)  XOR state(1)  XOR state(15)  XOR state(16)  XOR dataIn(1)  XOR state(1)  XOR state(2)  XOR state(16)  XOR state(17);

end a;
