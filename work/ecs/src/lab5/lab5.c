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

// Addtional variables
static int i = 0;
float duty_cycle;
float ratio = (10000000u / 600000);

void IsrA(void){

 	/* Turn on LED */
	writeGPIO(LED_BASE[0], LED[0], 0b1);

	/* Read sine value */
	uint32_t input_sine_value = read_ADC0_single(0b000000);

	/* Calculate PWM duty cycle */
	uint8_t dipswitch_2_val = readGPIO(DIP_BASE[1], DIP[1]);
	float pwm_duty_cycle;
	float m, b; // Constants in y = mx + b
	if (dipswitch_2_val) {
		m = 0.00016;
		b = 0.1;
	}
	else {
		m = 0.00004;
		b = 0.4;
	}
	pwm_duty_cycle = m * input_sine_value + b;

	/* Set PWM frequency based on dipswitch */
	uint8_t dipswitch_1_val = readGPIO(DIP_BASE[0], DIP[0]);	
	float pwm_frequency;	// [kHz]
	if (dipswitch_1_val) {
		pwm_frequency = 60000;
	}
	else {
		pwm_frequency = 20000;
	}

	/* Set PWM duty cycle and frequency */
	setPWM(0, 0, pwm_frequency, pwm_duty_cycle);

	/* Turn off LED */
	writeGPIO(LED_BASE[0], LED[0], 0b0);

	/* Clear interrupt flag */
	clearFlagLPIT(LPIT0_CHANNEL);
}

void IsrB(void){

	/* Turn on LED */
	writeGPIO(LED_BASE[0], LED[0], 0b1);

	/* Calculate and set PWM duty cycle */
	static int i = 0;
	float theta;
	float duty_cycle;
	theta = 2 * PI * i / 10;
	i = (i + 1) % 10;
	duty_cycle = (0.5f) + (0.4f) * sinf(theta);

	// setting the PWM
	setPWM(0,0,60000,duty_cycle);

	/* Turn off LED */
	writeGPIO(LED_BASE[0], LED[0], 0b0);

	/* Clear interrupt flag */
	clearFlagLPIT(LPIT0_CHANNEL);

}

void IsrC(void){

	/* Turn on LED */
  PTD->PDOR = 0b1;

	/* Calculate and set PWM duty cycle */
	i++;
	if (i>=10) i = 0;
	duty_cycle = 5 + 4 * sineTable[i];

	// setting the PWM
  FTM0->CONTROLS[0].CnV = ((uint32_t)(duty_cycle * ratio))&0xFFFFu; /* Set the PWM duty cycle */

	/* Turn off LED */
  PTD->PDOR = 0b0;

	/* Clear interrupt flag */
	LPIT0->MSR = 0b1;   /* clear TIFn */

}

int main(){
  initECS();
  enableLPIT();
  init_ADC0_single();

  /* Initialize PWMs  */
  initPWMPCRs();
  initPWM(0, 0, 20000, 0.5);	
  initPWM(3,0, 1000000, 0.5);

  /* Initialize GPIO  */
  initGPDI(DIP_BASE[0], DIP[0]);	// Dipswitch 1
  initGPDI(DIP_BASE[1], DIP[1]);	// Dipswitch 2
  initGPDO(LED_BASE[0], LED[0]);	// LED 0

  int index = 0;
  for (index=0; index < 10; index++) {
    sineTable[index] = sinf(2 * PI * index / 10);
  }

  FTM0->MOD = ((10000000u / 60000) - 1)&0xFFFFu; /* Set the PWM frequency */
  initLPIT(LPIT0_CHANNEL, 1000, &IsrC, 0xC);

  while(1){
    //IsrB();/*Loop forever */
  };
}

