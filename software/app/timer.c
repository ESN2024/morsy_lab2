#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "alt_types.h"
#include "io.h"
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_timer.h"
#include "sys/alt_sys_init.h"
#include <unistd.h>
#include<stdio.h>
#include<stdint.h>


uint32_t time = 0;
void aff(uint32_t nbr);

static void interrup(void *Context){

	alt_printf("INTERRUPT timer\n");
	if(time < 999){
		aff(time);
		time = time +1;

	}else{
		time = 0;
	}


	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0b01);
}

void aff(uint32_t nbr){
	uint8_t i =0;
	uint32_t tab[3] = {0,0,0};

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
    alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID,TIMER_0_IRQ, interrup,NULL, NULL);
    // CHECK LE STATUS
	int status = IORD_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE);
	alt_printf("STATUS = %x\n",status);

	// CHECK LE CONTROL
	int init = IORD_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE);
	alt_printf("init = %x\n",init);


    while(1){
    }
    return 0;
}
