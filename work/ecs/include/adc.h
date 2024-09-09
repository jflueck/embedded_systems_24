/**************************************************************************
 * FILE NAME: adc.h
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Analog to Digital Converter
 * Read Chapter 42 in S32K144 User's Manual
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "S32K144.h"


void init_ADC0_single(void);
uint8_t ADC0_complete(void);
uint32_t read_ADC0_single(uint16_t);


#endif /* ADC_H_ */
