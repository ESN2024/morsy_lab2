library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity morsy_lab2 is port (
        clk : in std_logic := '0' ;
        reset_n : in std_logic :='0';
        SEG  : out  std_logic_vector(7 downto 0);
		  SEG1  : out  std_logic_vector(7 downto 0);
		  SEG2  : out  std_logic_vector(7 downto 0));
end entity;

architecture arch of morsy_lab2 is
    
    
    component lab2 is
        port (
            clk_clk                         : in  std_logic                    := 'X'; -- clk
            reset_reset_n                   : in  std_logic                    := 'X'; -- reset_n
            seg2_external_connection_export : out std_logic_vector(3 downto 0);        -- export
            seg1_external_connection_export : out std_logic_vector(3 downto 0);        -- export
            seg3_external_connection_export : out std_logic_vector(3 downto 0)         -- export
        );
    end component lab2;
	 
	 component BCD_2_7SEG is
			port(
            inp : in std_logic_vector(3 downto 0); -- input 
            outp : out std_logic_vector(7 downto 0) -- output 
        );
	end component BCD_2_7SEG;

signal seg_1 : std_logic_vector(3 downto 0);
signal seg_2 : std_logic_vector(3 downto 0);
signal seg_3 : std_logic_vector(3 downto 0);
	
begin
    u0 : component lab2
        port map (
            clk_clk                         => clk,                         --                      clk.clk
            reset_reset_n                   => reset_n,                   --                    reset.reset_n
            seg2_external_connection_export => seg_2, -- seg2_external_connection.export
            seg1_external_connection_export => seg_1, -- seg1_external_connection.export
            seg3_external_connection_export => seg_3  -- seg3_external_connection.export
        );


        u1 : component BCD_2_7SEG
            port map (
                inp => seg_1,
                outp => SEG
            );

        u2 : component BCD_2_7SEG
            port map (
                inp => seg_2,
                outp => SEG1
            );

        u3 : component BCD_2_7SEG
            port map (
                inp => seg_3,
                outp => SEG2
            );
end architecture;