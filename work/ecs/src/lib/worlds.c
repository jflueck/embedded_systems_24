/**************************************************************************
 * FILE NAME: worlds.c
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Virtual Worlds
 *
 * Revision History:
 *  2011-12-01  Jay Patel
 *  2014-02-24  Scott Kenyon
 *  2017-03-14  RMC
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#include "worlds.h"
#include "gpio.h"
 

//====================LAB 4================================
/***************************************************************************
 * Virtual Wall
 ***************************************************************************/
float virtualWall(float angle)
{
	float k_spring = 500;	// [N-mm/deg]
	return (-k_spring * angle);
}

/***************************************************************************
 * Virtual Spring 
 * angle in degrees
 ***************************************************************************/
float virtualSpring(float angle)
{ 
	float k_spring = 50;	// [N-mm/deg]
	return (-k_spring * angle);
}

//====================LAB 6================================
/***************************************************************************
 * Virtual Spring Damper
***************************************************************************/
float virtualSpringDamper(float angle, float velocity)
{
	return 0.0;
}

/***************************************************************************
 * Virtual Wall Damper
***************************************************************************/
float virtualWallDamper(float angle, float velocity)
{
	return 0.0;
}

/***************************************************************************
 * Virtual Spring Mass
***************************************************************************/
float virtualSpringMass(float angle)
{        
	return 0.0;
}

/***************************************************************************
 * Virtual Spring Mass Damper
***************************************************************************/
float virtualSpringMassDamper(float angle, float velocity) 
{      
	return 0.0;
}

/***************************************************************************
 * Virtual Knob
***************************************************************************/ 
float virtualKnob(float angle, float velocity) 
{     
  //There are many ways this can be implemented
	return 0.0;
}

