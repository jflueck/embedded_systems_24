/**************************************************************************
 * FILE NAME: worlds.h
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Virtual Worlds
 *
 * Revision History:
 *  2011-12-01  Jay Patel
 *  2014-02-24  Scott Kenyon
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#ifndef WORLDS_H_
#define WORLDS_H_

#define TIMESTEP 0.001
#define WALL_POSITION 0 // Angle the virtual wall is located at

#define WORLDISR_LPIT_CHANNEL 1
#define WORLDISR_FREQUENCY 1000

float virtualWall(float angle);
float virtualSpring(float angle);

float virtualSpringDamper(float angle, float velocity);
float virtualWallDamper(float angle, float velocity);
float virtualSpringMass(float angle);
float virtualSpringMassDamper(float angle, float velocity);
float virtualKnob(float angle, float velocity);

// Additional variables
extern volatile float K_SPRING;
extern volatile float J_INERTIA;

#endif /* WORLDS_H_ */
