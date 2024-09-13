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
#include "adc.h"
#include "gpio.h"

int main(void)
{
  int section = 5;
  initECS();
  
  // Initialize QD and ADC
  initQD();
  init_ADC0_single();
  
  // Initialize PWMs
  initPWMPCRs();
  initPWM(0,0, 20000, 0.5);
  initPWM(3,0, 1000000, 0.5);

  initGPDO(3, 0);

  while(1)
  {
    switch(section)
    {
	case 1: // 0 Torque
		outputTorque(500);
	  break;
    case 2: //Analog Input Control of PWM

      outputTorque(read_ADC0_single(0b000000)*822.0/2500.0 - 822.0);
      break;
    case 3: //Change PWM Frequency to 1 kHz torque = 0 N-mm
      initPWM(0,0, 1000, 0.5);
      outputTorque(0.0);
      break;
    case 4: //Set torque to 200 N-mm
      outputTorque(200);
      break;
    case 5: //Virtual Spring
      // wheel_angle = updateAngle();
      writeGPIO(3, 0, 0b1);
      outputTorque(virtualSpring(updateAngle()));
      writeGPIO(3, 0, 0b0);
      break;
    case 6: // Virtual Wall
      outputTorque(virtualWall(updateAngle()));
      break;
    }
  }
}
