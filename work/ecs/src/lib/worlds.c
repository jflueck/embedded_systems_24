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
	if (angle <= 0.0) {
		float k_spring = 25;	// [N-mm/deg]
		return (-k_spring * angle);
	}

	return 0.0;
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
	float k_spring = 50;			// [N-mm/deg]	
	float b_m_damping = 0.0013;		// [N-m/(rad/sec)]
	float J_inertia = 0.00045;		// [N-m/(rad/sec)^2]
	float b_damping = 1.25;			// [N-mm/(deg/sec)]

	return -k_spring*(angle) - b_damping*(velocity);	
}

/***************************************************************************
 * Virtual Wall Damper
***************************************************************************/
float virtualWallDamper(float angle, float velocity)
{
	if (angle <= 0.0) {
		float k_spring = 10000;	// [N-mm/deg]
		float b_damping = 5.0;	// [N-mm/(deg/sec)]
		return (-k_spring*angle) + (-b_damping*velocity);
	}

	return 0.0;	
}

/***************************************************************************
 * Virtual Spring Mass
***************************************************************************/
float virtualSpringMass(float angle)
{      
	// System parameters
	float k_spring = 17.7;		// [N-mm/deg]
	float j_inertia = 0.45;		// [N-mm/(deg/sec)^2]

	// Initial conditions
	static float x_1 = 0;		// [deg]
	static float x_2 = 0;		// [deg/sec]

	// Integration
	float x_1_next = x_1 + TIMESTEP * x_2;
	float x_2_next = x_2 + ((-k_spring * TIMESTEP)/j_inertia)*x_1 + ((k_spring * TIMESTEP)/j_inertia)*angle;

	float torque_on_puck = k_spring*(x_1 - angle); 

	x_1 = x_1_next;
	x_2 = x_2_next;

	return -torque_on_puck;
}

/***************************************************************************
 * Virtual Spring Mass Damper
***************************************************************************/
float virtualSpringMassDamper(float angle, float velocity) 
{    
	// System parameters
	float k_spring = K_SPRING;		// [N-mm/deg]
	float j_inertia = J_INERTIA;		// [N-mm/(deg/sec)^2]
	float b_damping = 0.01777;	// [N-mm/(deg/sec)]

	// Initial conditions 
	static float x_1 = 0;		// [deg]
	static float x_2 = 0;		// [deg/sec]

	// Integration
	float x_1_next = x_1 + TIMESTEP * x_2;
	float x_2_next = (1 - b_damping*TIMESTEP/j_inertia)*x_2 + ((-k_spring * TIMESTEP)/j_inertia)*x_1 + ((k_spring * TIMESTEP)/j_inertia)*angle + b_damping*TIMESTEP/j_inertia * velocity;

	float torque_on_puck = k_spring*(x_1 - angle) + b_damping*(x_2 - velocity); 

	x_1 = x_1_next;
	x_2 = x_2_next;
	
	return -torque_on_puck;
}

/***************************************************************************
 * Virtual Knob
***************************************************************************/ 
float virtualKnob(float angle, float velocity) 
{     
	float k_spring = 50; // [N-mm/deg]
	float b_damping = 1.25;  // [N-mm/(deg/sec)]

	float angle_knob = 20;
	int n = (int)(angle/angle_knob + 0.5);

	return -k_spring*(angle - n*angle_knob)-b_damping*velocity;
}

