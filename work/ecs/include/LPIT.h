/**************************************************************************
 * FILE NAME: LPIT.h
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Low Power Interrupt Timer (LPIT)
 * Read Chapter 30 in S32K144 User's Manual
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#ifndef LPIT_H_
#define LPIT_H_

#include "S32K144.h"
#include "ecs.h"
#include "interrupt_manager.h"

#define LPIT_CLK_FREQ SPLLDIV2_CLK_FREQ


void enableLPIT();
void initLPIT(const uint8_t channel, const uint32_t frequency, const isr_t handler, const uint32_t priority);
void clearFlagLPIT(const uint8_t channel);

#endif /* LPIT_H_ */
