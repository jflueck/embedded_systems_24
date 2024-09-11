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
#define SECTION 1

int main(void){
  int32_t counter = 0;
  int i;
  float angle;
  int16_t angleInt;

  /* Initialize ECS, QD, GPDO */

  while(1){
    #if SECTION == 1 //Read the counter

    #elif SECTION == 2 //Overflow and Underflow

    #elif SECTION == 3 //updateCounter and Faulty Casting

    #elif SECTION == 4 //Angle Calculation

    #endif
  }
}
