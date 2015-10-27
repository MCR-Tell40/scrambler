--=================================================================================================--
--##################################   Module Information   #######################################--
--=================================================================================================--
--                                                                                         
-- Company:               CERN (PH-ESE-BE)                                                         
-- Engineer:              Manoel Barros Marin (manoel.barros.marin@cern.ch) (m.barros.marin@ieee.org)
--                                                                                                 
-- Project Name:          gwt-FPGA                                                                
-- Module Name:           gwt TX scrambler 30bit_new                                       
--                                                                                                 
-- Language:              VHDL'93                                                              
--                                                                                                   
-- Target Device:         Vendor agnostic                                                      
-- Tool version:                                                                             
--                                                                                                   
-- Version:               3.1
--
-- Description:            
--
-- Versions history:      DATE         VERSION   AUTHOR                               DESCRIPTION
--                
--                        10/05/2009   0.1       F. Marin (CPPM)                      First .bdf entity definition.
--                
--                        02/10/2010   0.2       S. Muschter (Stockholm University)   Translate from .bdf to .vhd.
--
--                        13/06/2013   3.0       M. Barros Marin                      Cosmetic and minor modifications.                                                                                  
--                        05/06/2015   3.1       K. Hennessy                          30 bit scrambler
--
-- Additional Comments:                                                                               
--
-- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
-- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! IMPORTANT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
-- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
-- !!                                                                                           !!
-- !! * The different parameters of the gwt Bank are set through:                               !!  
-- !!   (Note!! These parameters are vendor specific)                                           !!                    
-- !!                                                                                           !!
-- !!   - The MGT control ports of the gwt Bank module (these ports are listed in the records   !!
-- !!     of the file "<vendor>_<device>_gwt_bank_package.vhd").                                !! 
-- !!     (e.g. xlx_v6_gwt_bank_package.vhd)                                                    !!
-- !!                                                                                           !!  
-- !!   - By modifying the content of the file "<vendor>_<device>_gwt_bank_user_setup.vhd".     !!
-- !!     (e.g. xlx_v6_gwt_bank_user_setup.vhd)                                                 !! 
-- !!                                                                                           !! 
-- !! * The "<vendor>_<device>_gwt_bank_user_setup.vhd" is the only file of the gwt Bank that   !!
-- !!   may be modified by the user. The rest of the files MUST be used as is.                  !!
-- !!                                                                                           !!  
-- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
-- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
--                                                                                                   
--=================================================================================================--
--#################################################################################################--
--=================================================================================================--

-- IEEE VHDL standard library:
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

--=================================================================================================--
--#######################################   Entity   ##############################################--
--=================================================================================================--

entity gwt_tx_scrambler_30bit_new is
   port (
   
      --===============--
      -- Reset & Clock --
      --===============--    
      
      -- Reset scheme:
      ----------------
      TX_RESET_I                                : in  std_logic;
      ------------------------------------------
      RESET_PATTERN_I                           : in  std_logic_vector(29 downto 0);      
      
      -- Clock:
      ---------
      TX_FRAMECLK_I                             : in  std_logic;
      
      --==============--           
      -- Data & Frame --           
      --==============--              
      
      -- Data:
      --------
      TX_DATA_I                                 : in  std_logic_vector(29 downto 0);
      
      -- Common frame:
      ----------------
      TX_COMMON_FRAME_O                         : out std_logic_vector(29 downto 0)
   
   );
end gwt_tx_scrambler_30bit_new;

--=================================================================================================--
--####################################   Architecture   ###########################################-- 
--=================================================================================================--

architecture behavioral of gwt_tx_scrambler_30bit_new is

   --================================ Signal Declarations ================================--
 
   signal feedbackRegister                      : std_logic_vector(29 downto 0);
   
   --=====================================================================================--

--=================================================================================================--
begin                 --========####   Architecture Body   ####========-- 
--=================================================================================================--

   --==================================== User Logic =====================================--

   scrambler30bit_new: process(TX_RESET_I, RESET_PATTERN_I, TX_FRAMECLK_I)
   begin
      if TX_RESET_I = '1' then
         feedbackRegister                       <= RESET_PATTERN_I;
      elsif rising_edge(TX_FRAMECLK_I) then

         feedbackRegister( 0) <= TX_DATA_I( 0) xor feedbackRegister( 0) xor feedbackRegister( 2);
         feedbackRegister( 1) <= TX_DATA_I( 1) xor feedbackRegister( 1) xor feedbackRegister( 3);
         feedbackRegister( 2) <= TX_DATA_I( 2) xor feedbackRegister( 2) xor feedbackRegister( 4);
         feedbackRegister( 3) <= TX_DATA_I( 3) xor feedbackRegister( 3) xor feedbackRegister( 5);
         feedbackRegister( 4) <= TX_DATA_I( 4) xor feedbackRegister( 4) xor feedbackRegister( 6);
         feedbackRegister( 5) <= TX_DATA_I( 5) xor feedbackRegister( 5) xor feedbackRegister( 7);
         feedbackRegister( 6) <= TX_DATA_I( 6) xor feedbackRegister( 6) xor feedbackRegister( 8);
         feedbackRegister( 7) <= TX_DATA_I( 7) xor feedbackRegister( 7) xor feedbackRegister( 9);
         feedbackRegister( 8) <= TX_DATA_I( 8) xor feedbackRegister( 8) xor feedbackRegister(10);
         feedbackRegister( 9) <= TX_DATA_I( 9) xor feedbackRegister( 9) xor feedbackRegister(11);
         feedbackRegister(10) <= TX_DATA_I(10) xor feedbackRegister(10) xor feedbackRegister(12);
         feedbackRegister(11) <= TX_DATA_I(11) xor feedbackRegister(11) xor feedbackRegister(13);
         feedbackRegister(12) <= TX_DATA_I(12) xor feedbackRegister(12) xor feedbackRegister(14);
         feedbackRegister(13) <= TX_DATA_I(13) xor feedbackRegister(13) xor feedbackRegister(15);
         feedbackRegister(14) <= TX_DATA_I(14) xor feedbackRegister(14) xor feedbackRegister(16);
         feedbackRegister(15) <= TX_DATA_I(15) xor feedbackRegister(15) xor feedbackRegister(17);
         feedbackRegister(16) <= TX_DATA_I(16) xor feedbackRegister(16) xor feedbackRegister(18);
         feedbackRegister(17) <= TX_DATA_I(17) xor feedbackRegister(17) xor feedbackRegister(19);
         feedbackRegister(18) <= TX_DATA_I(18) xor feedbackRegister(18) xor feedbackRegister(20);
         feedbackRegister(19) <= TX_DATA_I(19) xor feedbackRegister(19) xor feedbackRegister(21);
         feedbackRegister(20) <= TX_DATA_I(20) xor feedbackRegister(20) xor feedbackRegister(22);
         feedbackRegister(21) <= TX_DATA_I(21) xor feedbackRegister(21) xor feedbackRegister(23);
         feedbackRegister(22) <= TX_DATA_I(22) xor feedbackRegister(22) xor feedbackRegister(24);
         feedbackRegister(23) <= TX_DATA_I(23) xor feedbackRegister(23) xor feedbackRegister(25);
         feedbackRegister(24) <= TX_DATA_I(24) xor feedbackRegister(24) xor feedbackRegister(26);
         feedbackRegister(25) <= TX_DATA_I(25) xor feedbackRegister(25) xor feedbackRegister(27);
         feedbackRegister(26) <= TX_DATA_I(26) xor feedbackRegister(26) xor feedbackRegister(28);
         feedbackRegister(27) <= TX_DATA_I(27) xor feedbackRegister(27) xor feedbackRegister(29);
         feedbackRegister(28) <= TX_DATA_I(28) xor feedbackRegister(28) xor TX_DATA_I(0) xor feedbackRegister(0) xor feedbackRegister(2);
         feedbackRegister(29) <= TX_DATA_I(29) xor feedbackRegister(29) xor TX_DATA_I(1) xor feedbackRegister(1) xor feedbackRegister(3);
                                           
    end if;
   end process;
   
   TX_COMMON_FRAME_O                            <= feedbackRegister;

   --=====================================================================================--   
end behavioral;
--=================================================================================================--
--#################################################################################################--
--=================================================================================================--
