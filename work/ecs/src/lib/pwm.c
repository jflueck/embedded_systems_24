/**************************************************************************
 * FILE NAME: pwm.c
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Pulse-Width Modulation using FlexTimer Module
 * Read Chapter 45 in S32K144 User's Manual
 * Important sections:
 *   45.4.2: Register Descriptions
 *   45.5.7: Edge-Aligned PWM (EPWM) Mode
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#include "ecs.h"
#include "pwm.h"

#define PWM_CLOCK_FREQ  /* fill in */

/* PWM Parameters */
#define MOTOR_PORT  /* fill in */
#define MOTOR_PCR  /* fill in */
#define MOTOR_MUX  /* fill in */

#define FILTER_PORT /* fill in */
#define FILTER_PCR /* fill in */
#define FILTER_MUX /* fill in */

#define DC_UPPER_LIMIT 0.76
#define DC_LOWER_LIMIT 0.24

FTM_Type * FTM_MODULE[4] = FTM_BASE_PTRS;


/******************************************************************************
 * Function:    initPWMPCRs
 * Description: Initialize the pins for each respective output PWM
 ******************************************************************************/
void initPWMPCRs()
{
  /* Initialize motor output PCR */
  MOTOR_PORT->PCR[/* fill in */] |= /* fill in */;

  /* Initialize filter output PCR */
  FILTER_PORT->PCR[/* fill in */] |= /* fill in */;

}

/******************************************************************************
 * Function:    initPWM
 * Description: Initializes PWM - 45.5.7: Edge-Aligned PWM (EPWM) Mode
 ******************************************************************************/
void initPWM(int submodule, int channel, int frequency, float dutyCycle)
{
  uint16_t cmax;

  cmax  = /* fill in */
  
  /* 45.4.3.9 - Feature Mode Selection (MODE) */
  FTM_MODULE[submodule]->MODE |= /* fill in */;  /* Write protect to registers disabled (default) */
  
  /* 45.4.3.2 - Status and Control (SC) */
  FTM_MODULE[submodule]->SC = 0x00000000; /* Clear the status and control register */
  FTM_MODULE[submodule]->SC |= /* fill in */; /* Select external clock */
  
  FTM_MODULE[submodule]->COMBINE = 0x00000000; /* FTM mode settings used: DECAPENx, MCOMBINEx, COMBINEx=0  */

  /* Enable the respective channel */
  FTM_MODULE[submodule]->SC |= /* fill in */;

  /* Channel Control see S45.4.3.5 and Table 45-5 (S45.5.4) */
  FTM_MODULE[submodule]->CONTROLS[channel].CnSC = 0; /* Clear the register*/
  /* fill in *; /* MSB : Edge Align PWM */
  /* fill in *; /* MSA : Edge Align PWM */
  /* fill in *; /* ELSB : High-true pulses */
  /* fill in *; /* ELSA : High-true pulses */
 
  /* 45.5.7 - Edge-Aligned PWM (EPWM) */
  FTM_MODULE[submodule]->   /* fill in */ /* Always start counter from 0 */
  FTM_MODULE[submodule]-> /* fill in */    /* counter rolls over at MOD  */

  FTM_MODULE[submodule]->CONF |= FTM_CONF_BDMMODE(0b11); /* Optional: enable in debug mode */
  
  /* Set the PWM */
  setPWM(submodule, channel, frequency, dutyCycle);
}

/******************************************************************************
 * Function:    setPWM
 * Description: Sets the output PWM for a given channel in FTM_MODULE
 ******************************************************************************/
void setPWM(int submodule, int channel, int frequency, float dutyCycle)
{
  uint16_t cthres;
  uint16_t cmax;

  cmax = /* fill in */
  cthres = /* fill in */

  FTM_MODULE[submodule]->MOD = /* fill in */ /* Set the PWM frequency */
  FTM_MODULE[submodule]->CONTROLS[channel].CnV = /* fill in */ /* Set the PWM duty cycle */
}


/******************************************************************************
 * Function:    outputTorque
 * Description: Outputs the torque to the haptic wheel in N-mm
 ******************************************************************************/
void outputTorque(float torque)
{
  // Calculate duty cycle
 

  // Apply DC_UPPER_LIMIT, DC_LOWER_LIMIT
 

  // Adjust the motor PWM
  setPWM(MOTOR_SUBMODULE, MOTOR_CHANNEL, MOTOR_FREQUENCY, dutyCycle);
}
