/**************************************************************************
 * FILE NAME: qd.c
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * FlexTimer Module (FTM): Quadrature Decode
 * Read Chapter 45 in S32K144 User's Manual
 * Section 45.5.27: Quadrature Decoder Mode
 *
 * Revision History
 *  2017-03-14  RMC
 *  2018-03     Paul Domanico
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#include "qd.h"

/* Quadrature Decoding Parameters */
#define ENCODER_COUNT /* fill in */

#define QD_PHA_PORT /* fill in */
#define QD_PHB_PORT /* fill in */
#define QD_PHA_PIN  /* fill in */
#define QD_PHB_PIN  /* fill in */

/******************************************************************************
* Function: init_QD
* Description: Initializes eTimer for Quadrature Decoding
******************************************************************************/
void initQD()
{
  /* Initialize Phase A and B input PCR */
  QD_PHA_PORT->PCR[/* fill in */] |= PORT_PCR_MUX(/* fill in */);
  QD_PHB_PORT->PCR[/* fill in */] |= PORT_PCR_MUX(/* fill in */);

  /* Set up FTM2 for Quadrature Decode */
  FTM2->MODE |= FTM_MODE_WPDIS_MASK; /* Disable write protection (should already be disabled) */
  FTM2->MOD = /* fill in */;
  FTM2->CNTIN = /* fill in */;
  FTM2->QDCTRL = /* fill in */;   /* Enable QD mode */

  FTM2->CONF |= FTM_CONF_BDMMODE(0b11); /* Optional: enable in debug mode */

  return;
}

/******************************************************************************
 * Function:    updateCounter
 * Description: Returns an updated counter value that keeps track of absolute
 *              wheel position
 ******************************************************************************/
int32_t updateCounter()
{
  /* fill in */
}


/******************************************************************************
 * Function:    updateAngle
 * Description: Returns the angle of the wheel
 ******************************************************************************/
float updateAngle()
{
  /* fill in  -- don't reinvent the wheel*/
}
