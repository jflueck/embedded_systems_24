/**************************************************************************
 * FILE NAME: lab3o.c
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Lab 3 solution (oscope)
 *
 * Revision History:
 *  2006-07-25  lovelljc
 *  2007-01-24  ericjw
 *  2009-11-6   wangyef
 *  2013-01-25  jmapatel
 *  2017-03-15  RMC
 *  2018-09-09  cschmotz
 *  2019-01     domanico
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#include "ecs.h"
#include "S32K144.h"
#include "adc.h"
#include "gpio.h"
#include "LPUART.h"
#include "s32_core_cm4.h"
#include "interrupt_manager.h"

#define NUM_POINTS 512

char command = '0';
static volatile uint32_t num_used;
uint16_t buffer[NUM_POINTS];


void ocIsr (void){
  if (num_used >= NUM_POINTS){
    DISABLE_INTERRUPTS();
  }
  else{
    buffer[num_used] = read_ADC0_single(0);
    num_used++;
  }
  /* Clear PIT Timer Interrupt Flag */
  LPIT0->MSR = 0b1;
}


int main(void) {
  uint16_t tmp;
  uint16_t cnt;

  initECS();

  // Init LPIT
  PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(6);
  PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK;
  LPIT0->MCR = 0x00000001;
  LPIT0->TMR[0].TVAL = 799;
  LPIT0->MIER |= 0x1;
  LPIT0->TMR[0].TCTRL = 0x01;
  LPIT0->SETTEN |= 1;
  INT_SYS_InstallHandler(LPIT0_Ch0_IRQn, &ocIsr, (isr_t*) 0);
  INT_SYS_SetPriority(LPIT0_Ch0_IRQn, 0xC);
  INT_SYS_EnableIRQ(LPIT0_Ch0_IRQn);

  initGPDO(LED_BASE[0], LED[0]);
  initGPDO(LED_BASE[1], LED[1]);

  LPUART1_init();

  init_ADC0_single();

  while (1) {
    DISABLE_INTERRUPTS();

    /*initialize variables*/
    num_used = 0;

    /*Check serial port for command*/
    command = LPUART1_receive_char();

    /* Enable the ISR for 50kHz sampling */
    ENABLE_INTERRUPTS();

    /* Wait for the buffer to be filled */
    while (num_used < NUM_POINTS){}

    /* send data */
    for(cnt = 0; cnt < num_used; cnt++){
      tmp = buffer[cnt];
      LPUART1_transmit_char((tmp >> 5) & 0xFF);
    }
  }

  return 0;
}
