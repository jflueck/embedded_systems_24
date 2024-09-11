/**************************************************************************
 * FILE NAME: lab2.c
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Lab 2
 *
 * Revision History:
 *  2014-03-17  Scott Kenyon
 *  2014-07-14  GPCz
 *  2017-03-15  RMC
 *  2018-03     Paul Domanico
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#include "ecs.h"
#include "S32K144.h"
#include "gpio.h"
#include "qd.h"

/* Change section number to match the section (1-4) being tested */
#define SECTION 4

int main(void){
  initECS();
  uint16_t counter = 0;
  int i;
  float angle;
  int16_t angleInt;
  initQD();


  /* Initialize ECS, QD, GPDO */
  int led_array_length = sizeof(LED) / sizeof(LED[0]);
  int index = 0;

  // init GPDO
  for (index=0; index < led_array_length; index++){
    initGPDO(LED_BASE[index], LED[index]);
  }


  while(1){
    #if SECTION == 1 //Read the counter
	  counter = updateCounter();

    #elif SECTION == 2 //Overflow and Underflow
	  counter = updateCounter();
	  for (index=0; index < led_array_length; index++) {
			writeGPIO(LED_BASE[index], LED[index], (counter >> index) & 0b1);
		  }
    #elif SECTION == 3 //updateCounter and Faulty Casting
	  int32_t total = 0;
	  total = updateCounter();
	  int32_t total_led = (total >> 8) & 0xFFFF;

	  for (index=0; index < led_array_length; index++) {
      writeGPIO(LED_BASE[index], LED[index], (total_led >> index) & 0b1);
      }

    #elif SECTION == 4 //Angle Calculation
	  float total_angle = updateAngle();
	  int32_t total_angle_int = (int32_t) total_angle;
		for (index=0; index < led_array_length; index++) {
		  writeGPIO(LED_BASE[index], LED[index], (total_angle_int >> index) & 0b1);
		  }

    #endif
  }
}
