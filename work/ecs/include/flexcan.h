/**************************************************************************
 * FILE NAME: flexcan.h
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Controller-Area Network module
 * Read Chapter 53 in S32K144 User's Manual
 *
 * Revision History:
 *      2019-03  Paul Domanico
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#ifndef FLEXCAN_H_
#define FLEXCAN_H_

#include "S32K144.h"
#include "interrupt_manager.h"


#define CAN_RX_ISR_CHANNEL   1
#define CAN_TX_ISR_CHANNEL   0
#define CAN_ISR_FREQUENCY    1000


typedef struct can_rxinfo
{
  uint8_t  buff_num;         /* buffer to be filled */
  uint8_t  length;           /* length of data (bytes) */
  uint32_t id;               /* id registers */
  uint8_t  data[8];          /* data received */
  uint16_t frt;              /* free running-timer */
} CAN_RXINFO;


typedef struct can_txinfo
{
  uint8_t  buff_num;         /* buffer to use for sending */
  uint32_t id;               /* id registers */
  uint8_t  length;           /* length of data to tx (bytes) */
  uint8_t  data[8];          /* data to transmit */
} CAN_TXINFO;


/** TODO: write function descriptions so students know what to expect from these
  *       without needed to read the flexcan.c file
  */
void initFlexcan(void);
int can_txmsg(CAN_TXINFO *txinfo);
int can_rxmsg(CAN_RXINFO *rxinfo);
int can_rxbuff_init(int buff_num, int id, int useIRQ);
void can_set_rxisr(volatile isr_t can_isr);
int can_get_buff_flag(int buff);
int can_clear_buff_flag(int buff);

#endif /* FLEXCAN_H_ */
