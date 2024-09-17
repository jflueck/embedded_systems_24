/**************************************************************************
 * FILE NAME: lab6.c
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Lab 6
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#include "S32K144.h"
#include "ecs.h"
#include "LPIT.h"
#include "LPUART.h"
#include "qd.h"
#include "pwm.h"
#include "worlds.h"


void wallDamper(void){
  /* ISR for the wall-damper system */

  /* Make sure to clear interrupt flag */

}

void springDamper(void){
  /* ISR for the spring-damper system */

  /*  Make sure to clear interrupt flag  */

}

void springMass(void){
  /* ISR for the spring-mass system */

  /* Make sure to clear interrupt flag */

}

void springMassDamper(void){
  /* ISR for the spring-mass-damper system */

  /* Make sure to clear interrupt flag  */

}

void knobIndents(void){
  /* ISR for the virtual knob system */

  /* Make sure to clear interrupt flag */

}

int main(void) {
  char byte_in = 0;
  void (*interrupt)(void);
  int section = 6;

  initECS();
  initQD();
  enableLPIT();

  // Initialize PWMs
  initPWMPCRs();

  initPWM(MOTOR_SUBMODULE, MOTOR_CHANNEL, MOTOR_FREQUENCY, 0.5f);
  initPWM(FILTER_SUBMODULE, FILTER_CHANNEL, FILTER_FREQUENCY, 0.5f);

  if(section == 5)
  {
    LPUART1_init();
    LPUART1_transmit_string("\n\n\n\n\n\n\n\rSerial Output Enabled.");
  }
  switch(section)
  {
    case 1:
      interrupt = &wallDamper;
      break;

    case 2:
      interrupt = &springDamper;
      break;

    case 3:
      interrupt = &springMass;
      break;

    case 4:
      interrupt = &springMassDamper;
      break;

    case 5:
      interrupt = &springMassDamper;
      break;

    case 6:
      interrupt = &knobIndents;
      break;
  }

  //Fill in the arguments to initialize the appropriate interrupt routine for
  //each part of the lab. Be sure to use the correct channel specified in worlds.h
  initLPIT(/* fill in */, WORLDISR_FREQUENCY, /* fill in */, 0xC);

  while(1){
    if(section == 5){
      byte_in = LPUART1_receive_char();
      /* adjust K and M from the keyboard. Must be a critical section. */
    }
  }

}
