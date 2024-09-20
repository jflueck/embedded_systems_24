/**************************************************************************
 * FILE NAME: flexcan.c
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

#include "flexcan.h"
#include <stdio.h>
#include "S32K144.h"
#include "s32_core_cm4.h"
#include "interrupt_manager.h"

#define CAN_NUM_BUFF  16
#define CAN_MAX_DATA  8
#define CAN0_RX_PCR   4
#define CAN0_TX_PCR   5

#define CAN_MB_HD1_CODE_MASK      0x0F000000u
#define CAN_MB_HD1_CODE_SHIFT     24u
#define CAN_MB_HD1_CODE_WIDTH     4u
#define CAN_MB_HD1_CODE(x)        (((uint32_t)(((uint32_t)(x))<<CAN_MB_HD1_CODE_SHIFT))&CAN_MB_HD1_CODE_MASK)
#define CAN_MB_HD1_IDE_MASK       0x00200000u
#define CAN_MB_HD1_IDE_SHIFT      21u
#define CAN_MB_HD1_IDE_WIDTH      1u
#define CAN_MB_HD1_IDE(x)         (((uint32_t)(((uint32_t)(x))<<CAN_MB_HD1_IDE_SHIFT))&CAN_MB_HD1_IDE_MASK)
#define CAN_MB_HD1_RTR_MASK       0x00100000u
#define CAN_MB_HD1_RTR_SHIFT      20u
#define CAN_MB_HD1_RTR_WIDTH      1u
#define CAN_MB_HD1_RTR(x)         (((uint32_t)(((uint32_t)(x))<<CAN_MB_HD1_RTR_SHIFT))&CAN_MB_HD1_RTR_MASK)
#define CAN_MB_HD1_DLC_MASK       0x000F0000u
#define CAN_MB_HD1_DLC_SHIFT      16u
#define CAN_MB_HD1_DLC_WIDTH      4u
#define CAN_MB_HD1_DLC(x)         (((uint32_t)(((uint32_t)(x))<<CAN_MB_HD1_DLC_SHIFT))&CAN_MB_HD1_DLC_MASK)
#define CAN_MB_HD2_ID_MASK        0x1FFC0000u
#define CAN_MB_HD2_ID_SHIFT       18u
#define CAN_MB_HD2_ID_WIDTH       11u
#define CAN_MB_HD2_ID(x)          (((uint32_t)(((uint32_t)(x))<<CAN_MB_HD2_ID_SHIFT))&CAN_MB_HD2_ID_MASK)

typedef struct{
  volatile uint32_t CAN_MB_HD1;
  volatile uint32_t CAN_MB_HD2;
  volatile uint8_t CAN_MB_DATA[8];
}CAN_MB;

/****************************************************
 * Function:    volatile_memcpy()
 * Description: memcpy() discards the volatile keyword. Custom version of memcpy when accessing
 *              volatile registers
 * Param:       destination: pointer to destination memory
 * Param:       source: pointer to source memory
 * Param:       num: number of bytes to copy from source to destination
 ****************************************************/
volatile void * volatile_memcpy(volatile void * destination, const volatile void * source, int num){
  volatile uint8_t * destByte = (uint8_t *) destination;
  const volatile uint8_t * srcByte = (uint8_t *)source;
  int i;
  for(i = 0; i < num; i++){
    destByte[i] = srcByte[i];
  }
  return destination;
}

/******************************************************************************
 * Function:    initFlexcan()
 * Description: Initializes the CAN module
                See manual section 53.6.1 for step-by-step instructions
 ******************************************************************************/
void initFlexcan()
{
  uint16_t x;
  volatile uint16_t j;

  /* Enable the clock to the FlexCAN0 module */
  /* TODO: Should this be done in eecs461.h? */
  PCC->PCCn[PCC_FlexCAN0_INDEX] |= PCC_PCCn_CGC_MASK;

  /* Tx and Rx pin PCR muxing */
  PORTE->PCR[CAN0_RX_PCR] |= PORT_PCR_MUX(5); /* Port E4: MUX = ALT5, CAN0_RX */
  PORTE->PCR[CAN0_TX_PCR] |= PORT_PCR_MUX(5); /* Port E5: MUX = ALT5, CAN0_TX */

  /* Enable the CAN module */
  CAN0->MCR &= ~CAN_MCR_MDIS(1);

  /* Reset FlexCAN Module */
  CAN0->MCR |= CAN_MCR_SOFTRST(1);
  while((CAN0->MCR & CAN_MCR_SOFTRST_MASK) == CAN_MCR_SOFTRST_MASK){}

  /*Disable the CAN module */
  CAN0->MCR |= CAN_MCR_MDIS(1);

  /* Set CAN clock source 1: bus , 0: oscillator */
  /* Oscillator frequency = 8 MHz */
  CAN0->CTRL1 &= ~CAN_CTRL1_CLKSRC(1);

  /* Enable the CAN module. CAN automatically goes into freeze after this */
  CAN0->MCR &= ~CAN_MCR_MDIS(1);
  while((!(CAN0->MCR & CAN_MCR_FRZACK_MASK)) || !(CAN0->MCR & CAN_MCR_NOTRDY_MASK)){}

  /* Not sure why but a delay is required before writing MCR & CTRL1*/
  for(j=1; j< 255; j++){}

  CAN0->MCR &= ~CAN_MCR_MAXMB_MASK;
  CAN0->MCR |= CAN_MCR_MAXMB(CAN_NUM_BUFF - 1);

  /* Initialize the Control 1 register */
  CAN0->CTRL1 = CAN_CTRL1_PRESDIV(0) /* PRESDIV+1 = Fclksrc/Ftq = 8Mhz */
              | CAN_CTRL1_RJW(3)
              | CAN_CTRL1_PSEG1(5)
              | CAN_CTRL1_PSEG2(5)
              | CAN_CTRL1_PROPSEG(2)
              | CAN_CTRL1_SMP(0)      /* Use 1 bit per CAN sample */
              | CAN_CTRL1_CLKSRC(0);  /* Keep the oscillator clock source */

  /** # of time quanta = SYNC_SEG + (PROPSEG + PSEG1 + 2) + (PSEG2 + 1)
    * 1 + (2 + 5 + 2) + (5 + 1) = 16 *
    *
    * Bit rate =  (CAN clock frequency )/(# of time quanta) = 8MHz/16 = 500 kbps
    */

  /* clear memory from message buffer 0 to 15 */
  for(x = 0; x < (CAN_NUM_BUFF * 4); x += 4){
    /* Clearing control and status(CS) field of message buffer */
    CAN0->RAMn[x] = 0;
    /* Clearing identifier field(ID) of message buffer */
    CAN0->RAMn[x + 1] = 0;
    /* Clearing data field of message buffer */
    CAN0->RAMn[x + 2] = 0;
    CAN0->RAMn[x + 3] = 0;
  }



  /* Disable all buffer interrupts */
  CAN0->IMASK1 = 0;

  /* Get out of halt and freeze */
  CAN0->MCR &= ~CAN_MCR_HALT(1);
  CAN0->MCR &= ~CAN_MCR_FRZ(1);

  while (CAN0->MCR & CAN_MCR_FRZACK_MASK){}
  /* Good practice: wait for FRZACK to clear (not in freeze mode) */
  while (CAN0->MCR & CAN_MCR_NOTRDY_MASK){}

  /* await synchronization (delay) */
  for(j=1; j < 255; j++){}

}

/******************************************************************************
 * Function:    can_txmsg()
 * Description: Initializes message buffer for TX and sends message
 ******************************************************************************/
int can_txmsg(CAN_TXINFO *txinfo)
{
  CAN_MB * mailbox = (CAN_MB *)&(CAN0->RAMn[4 * txinfo->buff_num]);

  // disable buffer from tx first
  // frame format is standard, not extended
  // remote transmission request, 0, has a data frame to be transmitted
  mailbox->CAN_MB_HD1 = CAN_MB_HD1_CODE(0x8)
                      | CAN_MB_HD1_IDE(0)
                      | CAN_MB_HD1_RTR(0)
                      | CAN_MB_HD1_DLC(txinfo->length);
  // buffer identifier
  mailbox->CAN_MB_HD2 = CAN_MB_HD2_ID(txinfo->id);

  CAN0->IFLAG1 = 0b1 << txinfo->buff_num;
  // receive data, length is in bytes
  volatile_memcpy(mailbox->CAN_MB_DATA, txinfo->data, txinfo->length % (8+1));

  mailbox->CAN_MB_HD1 |= CAN_MB_HD1_CODE(0xC);

  return 0;
}

/******************************************************************************
 * Function:    can_set_rxisr()
 * Description: installs handler for ISR to be called when message is received
 ******************************************************************************/
void can_set_rxisr(volatile isr_t can_isr){
  IRQn_Type canIrqNum = CAN0_ORed_0_15_MB_IRQn;
  INT_SYS_InstallHandler(canIrqNum, can_isr, (isr_t*) 0);
  INT_SYS_SetPriority(canIrqNum,0xC);
  INT_SYS_EnableIRQ(canIrqNum);
}

/******************************************************************************
 * Function:    can_rxbuff_init()
 * Description: Initializes message buffer for RX
 ******************************************************************************/
int can_rxbuff_init(int buff_num, int id, int useIRQ){
  CAN_MB * mailbox = (CAN_MB *)&(CAN0->RAMn[4 * buff_num]); /* CAN msg buffer  */

  mailbox->CAN_MB_HD1 = CAN_MB_HD1_CODE(0)  /* buffer inactive  */
                       | CAN_MB_HD1_IDE(0);  /* use standard 11-bit ID  */
 
  mailbox->CAN_MB_HD2 = CAN_MB_HD2_ID(id);   /* specify message identifier  */

  mailbox->CAN_MB_HD1 |= CAN_MB_HD1_CODE(0b0100);  /* activate RX buffer  */

  if ( useIRQ ) {
    //  if we are using a message received interrupt
    CAN0->IMASK1 |= 1<<buff_num; /* set IMASK1 bit for the buffer to enable ISR
                                   when message is received  */
  }

  return 0;
}


/******************************************************************************
 * Function:    can_rxmsg()
 * Description: Reads CAN message from RX message buffer
 ******************************************************************************/
int can_rxmsg(CAN_RXINFO *rxinfo){
  CAN_MB * mailbox = (CAN_MB *)&(CAN0->RAMn[4 * rxinfo->buff_num]);

    /* It is mandatory to read the Control and Status word, as it activates
       an internal lock for the buffer.  Likewise, we must check if the
       BUSY bit is set in the Code field and if so then wait until it's not. */
    while((mailbox->CAN_MB_HD1 >> CAN_MB_HD1_CODE_SHIFT) & 0b1);

    /* Read the ID field of the received msg. */
    rxinfo->id = (mailbox->CAN_MB_HD2  & CAN_MB_HD2_ID_MASK) >> CAN_MB_HD2_ID_SHIFT;

    /* These aren't mandatory by the processor, but populating these fields
       is convenient. */
    rxinfo->length = (mailbox->CAN_MB_HD1 & CAN_MB_HD1_DLC_MASK) >> CAN_MB_HD1_DLC_SHIFT ;
    rxinfo->length = rxinfo->length % (CAN_MAX_DATA + 1);
    /* Get the data.  Mandatory step. */
    volatile_memcpy(rxinfo->data, mailbox->CAN_MB_DATA, rxinfo->length);

    /* Read the free running timer, which unlocks the buffer.
       Mandatory step. */
    rxinfo->frt = CAN0->TIMER;

    /* Clear IFLAG so the next receive is visible to us when it happens. */
    can_clear_buff_flag(rxinfo->buff_num);

  return 0;
}

int can_get_buff_flag(int buff_num)
{
  /* Return the appropriate IFLAG bit. */
  return (((CAN0->IFLAG1) >> buff_num) & 0b1);
}

int can_clear_buff_flag(int buff_num)
{
  /* Clear the appropriate IFLAG bit. */
  CAN0->IFLAG1 = (0b1 << buff_num);
  return 0;
}
