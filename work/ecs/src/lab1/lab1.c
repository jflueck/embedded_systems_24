/**************************************************************************
 * FILE NAME: lab1.c
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Lab 1
 * Read Chapter 11&12 in S32K144 User's Manual
 *
 * Revision History:
 *  2014-03-17  Yitian Chen
 *  2014-07-14  GPCz
 *  2014-07-19  GPCz
 *  2017-03     RMC
 *  2018-03     Paul Domanico
 *  2018-11-15  jfr
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 ***************************************************************************/

#include "ecs.h"
#include <stdint.h>

#include "lab1.h"
#include "gpio.h"

/* Change section number to match the section (1-3) being tested */
#define SECTION 2

#if SECTION == 1



/******************************************************************************
 * Function:    section1
 * Description: read and write to the GPIO registers using your header file
 ******************************************************************************/
void section1(){
  /* code for section 1 */
  volatile uint32_t * const portD_PCR = (uint32_t *)(BASE_PORT_D);
  volatile uint32_t * const portE_PCR = (uint32_t *)(BASE_PORT_E);
  GPIO_mem * const gpioD = (GPIO_mem *)(BASE_GPIO + GPIOD_OFFSET);
  GPIO_mem * const gpioE = (GPIO_mem *)(BASE_GPIO + GPIOE_OFFSET);

  uint16_t sum, value1, value2;
  uint32_t regReadVal;
  int index;

  /* Configure the LED pins */
  for (index = 0; index < 5; index++) {
      /* Configure pin mux to gpio */
      portD_PCR[index] = 0b001 << 8;
      /* Set the direction to output */
      gpioD->PDDR |= 0b1 << index;
  }

  /* Configure the DIP pins */
  for (index = 6; index < 14; index++) {
      /* Configure pin mux to gpio */
      portE_PCR[index] = 0b001 << 8;
      /* Set the direction to input */
      gpioE->PDDR &= ~(1 << index);
  }

  /* Section 4.1.1 */
  gpioD ->PDOR = 0;
  while (1) {
    value1 = (gpioE->PDIR >> 6) & 0b1111;
    value2 = (gpioE->PDIR >> 10) & 0b1111;
    sum = value1 + value2;
    gpioD->PDOR = sum;
  }
}


#elif SECTION == 2
#include "S32K144.h"
#include "gpio.h"
/******************************************************************************
 * Function:    section2
 * Description: Use the provided S32K144.h header file
 ******************************************************************************/
void section2(){
  /* code for section 2 */
  /* Use the Arrays LED, LED_BASE, DIP and DIP_BASE provided in the gpio.c file */
  int led_array_length = sizeof(LED) / sizeof(LED[0]);
  int dip_array_length = sizeof(DIP) / sizeof(DIP[0]);

  // Initializes the inputs
  int index = 0;
  for (index=0; index < dip_array_length; index++){
    initGPDI(DIP_BASE[index], DIP[index]);
  }

  // Initializes the outputs
  for (index=0; index < led_array_length; index++){
    initGPDO(LED_BASE[index], LED[index]);
  }

  // Performs calculations and outputs it to LEDs
  uint16_t sum, value1, value2;
  uint16_t temp;
  while (1) {
    value1 = 0;
    value2 = 0;

    for (index=7; index > 3; index--) {
      temp = readGPIO(DIP_BASE[index], DIP[index]);
      value2 = (value2 << 1) + temp;
    }

    for (index=3; index > -1; index--) {
      temp = readGPIO(DIP_BASE[index], DIP[index]);
      value1 = (value1 << 1) + temp;
    }

    sum = value1 + value2;

  }
}


#elif SECTION == 3
#include "LPUART.h"
#include "gpio.h"
/******************************************************************************
 * Function:    section3
 * Description: Communicate with the computer using the keyboard interface
 ******************************************************************************/
void section3(){
  /* code for section 3 */
  char byte_in, old_byte_in;

  /* LPUART functions for sending and receiving serial data */
  LPUART1_init();
  LPUART1_transmit_string("\n\rSerial Output Enable...........");
  while(1) {
    old_byte_in = byte_in;
    byte_in = LPUART1_receive_char(); // returns ASCII representation


  }
}
#endif

int main(){
  /* Always call initECS() before doing anything else */
  initECS();

  #if(SECTION == 1)
  section1();
  #elif(SECTION == 2)
  section2();
  #elif(SECTION == 3)
  section3();
  #endif

  /* Should never reach this point */
  return 0;
}
