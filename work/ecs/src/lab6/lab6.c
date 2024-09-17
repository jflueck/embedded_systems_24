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

// Additional imports
#include "gpio.h"
#include "s32_core_cm4.h"

void wallDamper(void){
  /* ISR for the wall-damper system */
	static float angle = 0;
	float current_angle = updateAngle();

	uint8_t dipswitch_1_val = readGPIO(DIP_BASE[0], DIP[0]);

	float output_torque;
	if (dipswitch_1_val) {
	  output_torque = virtualWallDamper(current_angle, ((current_angle - angle)/TIMESTEP));
	}
	else {
	  output_torque = virtualWall(current_angle);
	}

	outputTorque(output_torque);
	angle = current_angle;

  /* Make sure to clear interrupt flag */
	clearFlagLPIT(WORLDISR_LPIT_CHANNEL);
}

void springDamper(void){
  /* ISR for the spring-damper system */
  static float angle = 0;
  float current_angle = updateAngle();
  outputTorque(virtualSpringDamper(current_angle, ((current_angle - angle)*10/TIMESTEP)));
  angle = current_angle;
  /*  Make sure to clear interrupt flag  */
  clearFlagLPIT(WORLDISR_LPIT_CHANNEL);
}

void springMass(void){
  /* ISR for the spring-mass system */
  outputTorque(virtualSpringMass(updateAngle()));
  /* Make sure to clear interrupt flag */
  clearFlagLPIT(WORLDISR_LPIT_CHANNEL);
}

void springMassDamper(void){
  /* ISR for the spring-mass-damper system */
  static float angle = 0;
  float current_angle = updateAngle();
  outputTorque(virtualSpringMassDamper(current_angle, ((current_angle - angle)/TIMESTEP)));
  angle = current_angle;

  /* Make sure to clear interrupt flag  */
  clearFlagLPIT(WORLDISR_LPIT_CHANNEL);

}

void knobIndents(void){
  /* ISR for the virtual knob system */

  /* Make sure to clear interrupt flag */

}

int main(void) {
  char byte_in = 0;
  void (*interrupt)(void);
  int section = 4;

  initECS();
  initQD();
  enableLPIT();

  // Initialize PWMs
  initPWMPCRs();

  initPWM(MOTOR_SUBMODULE, MOTOR_CHANNEL, MOTOR_FREQUENCY, 0.5f);
  initPWM(FILTER_SUBMODULE, FILTER_CHANNEL, FILTER_FREQUENCY, 0.5f);

  // Init
  initGPDI(DIP_BASE[0], DIP[0]);

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
  initLPIT(WORLDISR_LPIT_CHANNEL, WORLDISR_FREQUENCY, interrupt, 0xC);

  while(1){
    if(section == 5){
      byte_in = LPUART1_receive_char();
      /* adjust K and M from the keyboard. Must be a critical section. */
    }
  }

}
