#include <stdio.h>
#include <stdint.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include <unistd.h>

uint32_t time = 200000;
void int_to_seg(int nbr){
	uint16_t i =0;
	uint16_t tab[3] = {0,0,0};

	while (nbr >= 10) {
		tab[i] = nbr % 10;
		nbr = nbr / 10;
		i = i+1;
	}
	tab[i] = nbr;

	IOWR_ALTERA_AVALON_PIO_DATA(SEG1_BASE,tab[0]);
	IOWR_ALTERA_AVALON_PIO_DATA(SEG2_BASE,tab[1]);
	IOWR_ALTERA_AVALON_PIO_DATA(SEG3_BASE,tab[2]);
}


int main(void)
{
    uint16_t num;
    while(1){
        if(num < 999){
		int_to_seg(num);
		num = num +1;

	}else{
		num = 0;
        }
    usleep(time);
    }
    return 0;
}
