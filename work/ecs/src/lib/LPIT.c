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
static int LPIT_IRQn[4] = LPIT_IRQS;

void enableLPIT(){
  /* 29.6.5 PCC LPIT Register  */
  PCC->PCCn[PCC_LPIT_INDEX] &= ~(PCC_PCCn_CGC_MASK);  /* Disable PCC LPIT clock to change PCS */
  PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_PCS(0b110);    /* Clock source:  SPLL2_DIV2_CLK */
  PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC(0b1);                         /* fill in */;   /* Enable clk to LPIT0 regs */

  /* 46.4.1.4.2 Module Control Register  */
  LPIT0->MCR |= LPIT_MCR_M_CEN(0b1);     /* enable module clk (allows writing other LPIT0 regs)*/
}


void initLPIT(const uint8_t channel, const uint32_t frequency, const isr_t handler, const uint32_t priority) {
  /* 46.4.1.9.3 Timer Value Register   */
  LPIT0->TMR[channel].TVAL = SPLLDIV2_CLK_FREQ / frequency - 1;    /* channel timer start value */
  
  /* 46.4.1.6.2 Module Interrupt Enable Register */
  LPIT0->MIER |= 0b1 << channel;    /* Timer Interrupt Enabled for Channel */
  
  /* 46.4.1.9.3 Timer Control Register */  
  LPIT0->TMR[channel].TCTRL &= ~(LPIT_TMR_TCTRL_T_EN_MASK); /* T_EN : Timer channel is disabled to set registers*/
  LPIT0->TMR[channel].TCTRL &= ~(LPIT_TMR_TCTRL_MODE_MASK); /* MODE :  32 periodic counter mode */
  LPIT0->TMR[channel].TCTRL &= ~(LPIT_TMR_TCTRL_TSOT_MASK);  /* TSOT : Timer decrements immediately based on restart */
  LPIT0->TMR[channel].TCTRL &= ~(LPIT_TMR_TCTRL_TSOI_MASK); /* TSOI :  Timer does not stop after timeout */
  LPIT0->TMR[channel].TCTRL &= ~(LPIT_TMR_TCTRL_TROT_MASK);  /* TROT : ignore external trigger */
 
  /* 46.4.1.7.3 Set Timer Enable Register   */                                                 
  LPIT0->SETTEN |= 0b1 << channel;    /*SET_T_EN_n :  enable timer for channel */

  /* defined in interrupt_manager.c */
  INT_SYS_InstallHandler(LPIT_IRQn[channel], handler, (isr_t*) 0);
  INT_SYS_SetPriority(LPIT_IRQn[channel], priority);
  INT_SYS_EnableIRQ(LPIT_IRQn[channel]);
}


void clearFlagLPIT(const uint8_t channel){
  /* 46.4.1.5.3 Module Status Register  */
  LPIT0->MSR |= 0b1 << channel;   /* clear TIFn */
}

