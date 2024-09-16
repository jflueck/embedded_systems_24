/**************************************************************************
 * FILE NAME: lab5.c
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Lab 5
 *
 * Revision History:
 *  2018-01-21  Paul Domanico (author)
 *  2019-01-06  jfr
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#include "S32K144.h"
#include "ecs.h"

#include "pwm.h"
#include "LPIT.h"
#include "adc.h"
#include "gpio.h"
#include "math.h"

#define LPIT0_CHANNEL  0

float sineTable[10]; // Ten samples/period
int sineIndex = 0;
const float PI = 3.14159;


void IsrA(void){

 	/* Turn on LED */
	/* fill in here */

	/* Read sine value */
	/* fill in here */

	/* Calculate PWM duty cycle */
	/* fill in here */

	/* Set PWM frequency based on dipswitch */
	/* fill in here */

	/* Set PWM duty cycle and frequency */
	/* fill in here */

	/* Turn off LED */
	/* fill in here */

	/* Clear interrupt flag */
	/* fill in here */


}

void IsrB(void){

	/* Turn on LED */
	/* fill in here */

	/* Calculate and set PWM duty cycle */
	/* fill in here */

	/* Turn off LED */
	/* fill in here */

	/* Clear interrupt flag */
	/* fill in here */

}

void IsrC(void){

	/* Turn on LED */
	/* fill in here */

	/* Calculate and set PWM duty cycle */
	/* fill in here */

	/* Turn off LED */
	/* fill in here */

	/* Clear interrupt flag */
	/* fill in here */

}

int main(){

  initECS();
  enableLPIT();
  init_ADC0_single();

  /* Initialize PWMs  */
  /* fill in */

  /* Initialize GPIO  */
  /*   fill in    */

  initLPIT(LPIT0_CHANNEL, 1000, &IsrA, 0xC);

  while(1){
    /*Loop forever */
  };
}

