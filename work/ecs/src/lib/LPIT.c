/**************************************************************************
 * FILE NAME: LPIT.h
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Low Power Interrupt Timer (LPIT)
 * Read Chapter 30 in S32K144 User's Manual
 *
 * Revision History:
 *  2017-11-16  schmo
 *  2017-03-13  Paul Domanico
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#include "LPIT.h"

/* Array of 4 interrupt service routines.  One for each channel */
static int LPIT_IRQn[4] = /* fill in */

void enableLPIT(){
  /* 29.6.5 PCC LPIT Register  */
  PCC->PCCn[/* fill in */] /* fill in */;  /* Disable PCC LPIT clock to change PCS */
  PCC->PCCn[/* fill in */] /* fill in */;   /* Clock source:  SPLL2_DIV2_CLK */
                           /* fill in */;   /* Enable clk to LPIT0 regs */

  /* 46.4.1.4.2 Module Control Register  */
  LPIT0->MCR  /* fill in */;     /* enable module clk (allows writing other LPIT0 regs)*/
}


void initLPIT(const uint8_t channel, const uint32_t frequency, const isr_t handler, const uint32_t priority) {
  /* 46.4.1.9.3 Timer Value Register   */
  LPIT0->TMR[channel].TVAL = /* fill in */; ;    /* channel timer start value */  
  
  /* 46.4.1.6.2 Module Interrupt Enable Register */
  LPIT0->MIER /* fill in */;    /* Timer Interrupt Enabled for Channel */
  
  /* 46.4.1.9.3 Timer Control Register */  
  LPIT0->TMR[channel].TCTRL /* fill in */; /* T_EN : Timer channel is disabled to set registers*/
  /* fill in */;  /* MODE :  32 periodic counter mode */
  /* fill in */;  /* TSOT : Timer decrements immediately based on restart */
  /* fill in */;  /* TSOI :  Timer does not stop after timeout */
  /* fill in */;  /* TROT : ignore external trigger */            
 
  /* 46.4.1.7.3 Set Timer Enable Register   */                                                 
  LPIT0->SETTEN /* fill in */;    /*SET_T_EN_n :  enable timer for channel */

  /* defined in interrupt_manager.c */
  INT_SYS_InstallHandler(LPIT_IRQn[channel], handler, (isr_t*) 0);
  INT_SYS_SetPriority(LPIT_IRQn[channel], priority);
  INT_SYS_EnableIRQ(LPIT_IRQn[channel]);
}


void clearFlagLPIT(const uint8_t channel){
  /* 46.4.1.5.3 Module Status Register  */
  LPIT0->MSR /* fill in */;   /* clear TIFn */
}

