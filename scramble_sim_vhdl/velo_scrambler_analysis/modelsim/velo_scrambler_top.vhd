-- Top Level Entity
-- velo_scrambler_top
-- Author: Ben
-- Date Created: 29/10/15

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity velo_scrambler_top is
  port(
    
    rsi_Reset		        : IN    std_logic;
    csi_Clock_160MHz	     : IN    std_logic
    
    );
end velo_scrambler_top;

architecture a of velo_scrambler_top is
  
  
---- put in scrambling component
  component VeloPixDeScrambler is
    port(
      clk,rst: in std_logic;
      frameIn: in std_logic_vector(29 downto 0);
      valid_in : in std_logic;
      valid_out : out std_logic;
      scramble_out : out std_logic_vector(29 downto 0)
      );
end component;
    COMPONENT the_reader is
      
      port(
        clk_40MHz  : in  std_logic;
        rst  : in  std_logic;
        valid_out : out std_logic;
        pixel_read1, pixel_read2, pixel_read3, pixel_read4 : out  std_logic_vector(29 downto 0)
        );
    end COMPONENT ;

  
  COMPONENT the_writer IS
    port( 
      pixel_write1, pixel_write2, pixel_write3, pixel_write4 : IN std_logic_vector(29 downto 0) ;
      file_name :  in string(20 downto 1);
      rst, clk_40MHz, valid_in: IN std_logic;
      file_name2: in string(19 downto 1)
      ) ;
  end COMPONENT ;
  
  Component VeloPixScrambler is
  port(
    clk: in std_logic;
    rst: in std_logic;
    valid_in: in std_logic;
    valid_out: out std_logic;
    frameIn: in std_logic_vector(29 downto 0);
    scramble_out: out std_logic_vector(29 downto 0)
    );
end component;

  constant reset_pattern_reg	   : std_logic_vector(29 downto 0) := (others => '0');
  SIGNAL reset_reg, clock160_reg	: std_logic;
  SIGNAL common_frame_output_reg : std_logic_vector(29 downto 0);
  SIGNAL data_output_reg	    	: std_logic_vector(29 downto 0);
  signal valid_read_scramble, valid_scramble_descramble1, valid_scramble_descramble2, valid_scramble_descramble3, valid_scramble_descramble4, valid_descramble_write1, valid_descramble_write2, valid_descramble_write3, valid_descramble_write4 : std_logic;
  SIGNAL read_to_scramble1, read_to_scramble2, read_to_scramble3, read_to_scramble4 		: std_logic_vector(29 downto 0);
  SIGNAL descramble_to_write1, descramble_to_write2, descramble_to_write3, descramble_to_write4		: std_logic_vector(29 downto 0);

  
    SIGNAL scramble_to_descramble1, scramble_to_descramble2, scramble_to_descramble3, scramble_to_descramble4 		: std_logic_vector(29 downto 0);
  
BEGIN
  
  
  read_inst1 : the_reader
    PORT MAP (
      clk_40MHz         => clock160_reg,
      rst	        => reset_reg,
      pixel_read1 	=> read_to_scramble1,
      pixel_read2       => read_to_scramble2,
      pixel_read3       => read_to_scramble3,
      pixel_read4       => read_to_scramble4,
      valid_out => valid_read_scramble
      );


  scramble_inst1 : VeloPixScrambler
    port map (
      clk => clock160_reg,
	rst => reset_reg,
      frameIn => read_to_scramble1,
      scramble_out => scramble_to_descramble1,
      valid_in => valid_read_scramble,
      valid_out => valid_scramble_descramble1
      );
  
  scramble_inst2 : VeloPixScrambler
    port map (
      clk => clock160_reg,
	rst => reset_reg,
      frameIn => read_to_scramble2,
      scramble_out => scramble_to_descramble2,
       valid_in => valid_read_scramble,
      valid_out => valid_scramble_descramble2
      );
  
  scramble_inst3 : VeloPixScrambler
    port map (
      clk => clock160_reg,
	rst => reset_reg,
      frameIn => read_to_scramble3,
      scramble_out => scramble_to_descramble3,
       valid_in => valid_read_scramble,
      valid_out => valid_scramble_descramble3
      );
  
  scramble_inst4 : VeloPixScrambler
    port map (
      clk => clock160_reg,
	rst => reset_reg,
      frameIn => read_to_scramble4,
      scramble_out => scramble_to_descramble4,
       valid_in => valid_read_scramble,
      valid_out => valid_scramble_descramble4
      );



 descramble_inst1 : VeloPixDeScrambler
    port map (
      clk => clock160_reg,
	rst => reset_reg,
      frameIn => scramble_to_descramble1,
      scramble_out => descramble_to_write1,
      valid_in => valid_scramble_descramble1,
      valid_out => valid_descramble_write1
      );
 
  
  descramble_inst2 : VeloPixDeScrambler
    port map (
      clk => clock160_reg,
	rst => reset_reg,
      frameIn =>  scramble_to_descramble2,
      scramble_out => descramble_to_write2,
      valid_in => valid_scramble_descramble2,
      valid_out => valid_descramble_write2
      );
  
  descramble_inst3 : VeloPixDeScrambler
    port map (
      clk => clock160_reg,
	rst => reset_reg,
      frameIn =>  scramble_to_descramble3,
      scramble_out => descramble_to_write3,
      valid_in => valid_scramble_descramble3,
      valid_out => valid_descramble_write4
      );
  
  descramble_inst4 : VeloPixDeScrambler
    port map (
      clk => clock160_reg,
	rst => reset_reg,
      frameIn =>  scramble_to_descramble4,
      scramble_out => descramble_to_write4,
      valid_in => valid_scramble_descramble4,
      valid_out => valid_descramble_write4
      );

  
    write_inst1 : the_writer
    PORT MAP (
      pixel_write1       => descramble_to_write1,
      pixel_write2       => descramble_to_write2,
      pixel_write3      => descramble_to_write3,
      pixel_write4       => descramble_to_write4,
      rst	        => reset_reg,
      file_name         => "scrambler_output.txt",
      file_name2        => "new_transitions.txt",
      clk_40MHz	        => clock160_reg,
      valid_in          => valid_descramble_write1
      );

  write_inst2 : the_writer
    PORT MAP (
      pixel_write1       => scramble_to_descramble1,
      pixel_write2       => scramble_to_descramble2,
      pixel_write3       =>  scramble_to_descramble3,
      pixel_write4       =>  scramble_to_descramble4,
      rst	        => reset_reg,
      file_name         => "before_scrambler.txt",
      file_name2        => "pre_transitions.txt",
      clk_40MHz	        => clock160_reg,
      valid_in          => valid_scramble_descramble1
      );


  PROCESS(csi_Clock_160MHz, rsi_Reset)
  BEGIN

    reset_reg <= rsi_Reset;
    clock160_reg <= csi_Clock_160MHz;		

    If (rsi_Reset = '1') THEN 
      
      
      --scrambler_data_out <= (OTHERS => '0');

    ELSIF rising_edge(csi_Clock_160MHz) THEN     
      
      --scrambler_data_out <= data_output_reg;		
      --report "data_output_reg=" & stdvec_to_str(data_output_reg);

    END IF;
    
  END PROCESS;

END a;
