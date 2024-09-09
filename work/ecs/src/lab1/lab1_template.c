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

/* Change section number to match the section (1-3) being tested */
#define SECTION 1

#if SECTION == 1



/******************************************************************************
 * Function:    section1
 * Description: read and write to the GPIO registers using your header file
 ******************************************************************************/
void section1(){
  /* code for section 1 */

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
