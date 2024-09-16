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
uint8_t OUTPUT_LED_BASE = LED_BASE[0];
uint8_t OUTPUT_LED_PIN = LED[0];

void IsrA(void){

 	/* Turn on LED */
	writeGPIO(OUTPUT_LED_BASE, OUTPUT_LED_PIN, 0b1);	

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
	writeGPIO(OUTPUT_LED_BASE, OUTPUT_LED_PIN, 0b0);

	/* Clear interrupt flag */
	clearFlagLPIT(LPIT0_CHANNEL);
}

void IsrB(void){

	/* Turn on LED */
	writeGPIO(OUTPUT_LED_BASE, OUTPUT_LED_PIN, 0b1);

	/* Calculate and set PWM duty cycle */
	static int i = 0;
	float theta;
	float duty_cycle;
	theta = 2 * PI * i / 10;
	i = (i + 1) % 10;
	duty_cycle = ((float)0.5) + ((float)0.4) * sinf(theta);

	/* Turn off LED */
	writeGPIO(OUTPUT_LED_BASE, OUTPUT_LED_PIN, 0b0);

	/* Clear interrupt flag */
	clearFlagLPIT(LPIT0_CHANNEL);

}

void IsrC(void){

	/* Turn on LED */
	writeGPIO(OUTPUT_LED_BASE, OUTPUT_LED_PIN, 0b1);

	/* Calculate and set PWM duty cycle */
	static int i = 0;
	float theta, duty_cycle;
	
	theta = 2 * PI * i / 10;
	i = (i + 1) % 10;
	duty_cycle = ((float)0.5) + ((float)0.4) * sineTable[i];

	/* Turn off LED */
	writeGPIO(OUTPUT_LED_BASE, OUTPUT_LED_PIN, 0b0);

	/* Clear interrupt flag */
	clearFlagLPIT(LPIT0_CHANNEL);

}

int main(){

  initECS();
  enableLPIT();
  init_ADC0_single();

  /* Initialize PWMs  */
  initPWMPCRs();
  initPWM(0, 0, 20000, 0.5);	

  /* Initialize GPIO  */
  initGPDI(DIP_BASE[0], DIP[0]);	// Dipswitch 1
  initGPDI(DIP_BASE[1], DIP[1]);	// Dipswitch 2
  initGPDO(OUTPUT_LED_BASE, OUTPUT_LED_PIN);	// LED 0

  initLPIT(LPIT0_CHANNEL, 1000, &IsrA, 0xC);

  while(1){
    /*Loop forever */
  };
}

