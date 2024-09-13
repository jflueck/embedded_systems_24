/**************************************************************************
 * FILE NAME: lab4.c
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Lab 4
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#include "ecs.h"
#include "qd.h"
#include "pwm.h"
#include "worlds.h"


int main(void)
{
  int section = 0;
  initECS();
  
  // Initialize QD and ADC
  /* fill in */
  
  // Initialize PWMs
  initPWMPCRs();
  initPWM( /* fill in */ );
  initPWM( /* fill in */ );

  while(1)
  {
    switch(section)
    {
	case 1: // 0 Torque
		outputTorque(0.0);
	  break;
    case 2: //Analog Input Control of PWM
      /* fill in */ 
      break;
    case 3: //Change PWM Frequency to 1 kHz torque = 0 N-mm
       /* fill in */ 
      break;
    case 4: //Set torque to 200 N-mm
       /* fill in */ 
      break;
    case 5: //Virtual Spring
       /* fill in */ 
      break;
    case 6: // Virtual Wall
       /* fill in */ 
      break;
    }
  }
}
