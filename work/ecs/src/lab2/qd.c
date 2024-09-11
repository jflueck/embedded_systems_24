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
#define ENCODER_COUNT 1000

#define QD_PHA_PORT PORTA
#define QD_PHB_PORT PORTA
#define QD_PHA_PIN  12
#define QD_PHB_PIN  13

static int32_t TOTAL;
static uint16_t PREV_QDPC;

/******************************************************************************
* Function: init_QD
* Description: Initializes eTimer for Quadrature Decoding
******************************************************************************/
void initQD()
{
  /* Initialize Phase A and B input PCR */
  QD_PHA_PORT->PCR[QD_PHA_PIN] |= PORT_PCR_MUX(0b110);
  QD_PHB_PORT->PCR[QD_PHB_PIN] |= PORT_PCR_MUX(0b110);

  /* Set up FTM2 for Quadrature Decode */
  FTM2->MODE |= FTM_MODE_WPDIS_MASK; /* Disable write protection (should already be disabled) */
  FTM2->MOD = FTM_MOD_MOD(0xFFFF);
  FTM2->CNTIN = FTM_CNTIN_INIT(0x0000);
  FTM2->QDCTRL = FTM_QDCTRL_QUADEN(0b1);   /* Enable QD mode */

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
  uint16_t CURR_QDPC = FTM2->CNT;
  TOTAL = TOTAL + (int16_t)(CURR_QDPC - PREV_QDPC);
  PREV_QDPC = CURR_QDPC;
  return TOTAL;
}


/******************************************************************************
 * Function:    updateAngle
 * Description: Returns the angle of the wheel
 ******************************************************************************/
float updateAngle()
{
  float conversion_factor = (float)360.0 / (ENCODER_COUNT*4);
  return updateCounter() * conversion_factor;
}
