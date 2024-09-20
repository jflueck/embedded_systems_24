/**************************************************************************
 * FILE NAME: lab8.c
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 * Lab 8
 *
 * Revision History:
 *  2018-03-13
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#include <string.h>
#include <stdlib.h>

#include "ecs.h"
#include "S32K144.h"
#include "gpio.h"
#include "adc.h"
#include "flexcan.h"
#include "pwm.h"
#include "qd.h"
#include "worlds.h"
#include "LPIT.h"

/* define VWALLA, VWALLB, or VCHAIN depending on lab section */
#define VCHAIN

#ifdef VWALLA
void virt_wall_A(void);
#endif

#ifdef VWALLB
void virt_wall_B(void);
#endif

#ifdef VCHAIN
void virt_chain();
#endif


//*************************************************************************************
// EDIT STATION IDS
#define STATIONBASEID 30 /* ID of your lab station */
#define VWPARTNERID    /* ID of your partner's lab station for the virtual wall */
#define CHAIN_A_ID    40 /* ID of the station to your "left" */
#define CHAIN_B_ID    20 /* ID of the station to your "right" */
//*************************************************************************************

const uint16_t vwA_tx_ID = 0 + STATIONBASEID;
const uint16_t vwA_rx_ID = 1 + VWPARTNERID;
const uint16_t vwB_tx_ID = 1 + STATIONBASEID;
const uint16_t vwB_rx_ID = 0 + VWPARTNERID;

const uint8_t vwA_tx_buffnum = 0;
const uint8_t vwA_rx_buffnum = 1;
const uint8_t vwB_tx_buffnum = 2;
const uint8_t vwB_rx_buffnum = 3;

const uint16_t chain_tx_ID = 2 + STATIONBASEID;
const uint16_t chainA_rx_ID = 2 + CHAIN_A_ID;
const uint16_t chainB_rx_ID = 2 + CHAIN_B_ID;

const uint8_t chain_tx_buff_num = 0;
const uint8_t chainA_rx_buff_num = 1;
const uint8_t chainB_rx_buff_num = 2;

/* Shared Data: the CAN message-received ISR copies new data into
 * the following variables */
static volatile float vw_torque=0;	/* wall torque (FLOAT32, N-mm) */
static volatile float posA=0;		/* chain position A (FLOAT32, N-mm) */
static volatile float velA=0;		/* chain velocity A (FLOAT32, N-mm) */
static volatile float posB=0;		/* chain position B (FLOAT32, N-mm) */
static volatile float velB=0;		/* chain velocity B (FLOAT32, N-mm) */

/***************************************************************************
 * Function:	rx_ISR()
 * Description:	This interrupt is called when a CAN message is received.
 ***************************************************************************/
void rx_ISR(void){

	#ifdef VWALLA
    CAN_RXINFO rxinfo;
    int ret;
   
    /* Message for: Virtual Wall A */
    /* First check to see if there is a new message in the buffer */
    if ( can_get_buff_flag(vwA_rx_buffnum) == 1 )
    {
        /* Read the CAN message and copy torque to global variable */
        /* is the read successful and is the message the right length? */
        //Copy over the data from the CAN buffer to rxinfo
        volatile_memcpy(txinfo.data, &vw_torque, sizeof(vw_torque));
    	virt_wall_A();
    }
	#endif

	#ifdef VWALLB
    /* Message for: Virtual Wall B */
    /* First check to see if there is a new message in the buffer */
    if ( can_get_buff_flag(vwB_rx_buffnum) == 1 ) {
        /* Let virt_wall_B() handle this */
    	virt_wall_B();
    }
	#endif

	#ifdef VCHAIN
    CAN_RXINFO rxinfo;
    int ret;
    /* Message for: Virtual Chain (from A) */
    /* First check to see if there is a new message in the buffer */

    //** NOTE: position and velocity are sent together as a package.
    //**       position is the first four bytes, and velocity is
    //**       the second 4 bytes.

    if( can_get_buff_flag(chainA_rx_buff_num) == 1 ){
        /* 1. Set the number of CAN buffer with message */
        rxinfo.buff_num = chainA_rx_buffnum;
       
        /* 2. Receive CAN message */
        ret = can_rxmsg(&rxinfo);
        ASSERT_EECS(ret == 0);
        
        /* 3. Check if read is successful and message has the right length */
        /* Copy position and velocity to global variables */
        if (rxinfo.length == sizeof(posA) + sizeof(velA)) {
        	volatile_memcpy(&posA, rxinfo.data[0], sizeof(posA));
        	volatile_memcpy(&velA, rxinfo.data[4], sizeof(velA));
        }
    }

    /* Message for: Virtual Chain (from B) */
    /* First check to see if there is a new message in the buffer */
    if( can_get_buff_flag(chainB_rx_buff_num) == 1 ){
        /* 1. Set the number of CAN buffer with message */
        rxinfo.buff_num = chainB_rx_buffnum;

        /* 2. Receive CAN message */
        ret = can_rxmsg(&rxinfo);
        ASSERT_EECS(ret == 0);

        /* 3. Check if read is successful and message has the right length */
        /* Copy position and velocity to global variables */
        if (rxinfo.length == sizeof(posB) + sizeof(velB)) {
        	volatile_memcpy(&posB, rxinfo.data[0], sizeof(posB));
        	volatile_memcpy(&velB, rxinfo.data[4], sizeof(velB));
        }
    }
    virt_chain();
    #endif
}

/***************************************************************************
 * Function:	virt_wall_A()
 * Description:	Implements the sensing and actuation of the virtual wall.
 *				It applies the calculated torque received from wall B.
 *				It then reads the wheel position and transmits it to wall B.
 * Shared Data: vw_torque (FLOAT32, N-mm)
 *
 * 1. Apply the current torque value (last received)
 * 2. Read the wheel position
 * 3. Transmit the wheel position & velocity in a CAN message
 ***************************************************************************/
#ifdef VWALLA
void virt_wall_A() {
	CAN_TXINFO txinfo;		/* buffer to tx wheel angle & velocity */
	float curr_angle = 0;
	int ret;

    /* 1. Apply the current torque value (last received) */
	outputTorque(vw_torque);

    /* 2. Read the wheel position */
    curr_angle = updateAngle();

    /* 3. Transmit the wheel position in a CAN message */
    txinfo.buff_num = vwA_tx_buffnum;
    txinfo.id = vwA_tx_ID;
    txinfo.length = sizeof(curr_angle);
    memcpy(txinfo.data, &curr_angle, sizeof(curr_angle));

	ret = can_txmsg(&txinfo);
    ASSERT_EECS(ret == 0);

    /* clear interrupt flag for TX channel */
    clearFlagLPIT(CAN_TX_ISR_CHANNEL);
}
#endif


 /***************************************************************************
 * Function:	virt_wall_B()
 * Description:	Implements the computation of the virtual wall.
 *				It calculates torque from the received position
 *				value from wall A.
 *
 * 1. Read the CAN message
 * 2. Calculate the torque
 * 3. Transmit the torque as a CAN message
 ***************************************************************************/
#ifdef VWALLB
 void virt_wall_B(void) {
	CAN_RXINFO rxinfo;
	CAN_TXINFO txinfo;

	float curr_angle;
	float torque;
	int ret;

    /* 1. Read the CAN message */
    /**** is the read successful and is the message the right length? ***/
    rxinfo.buff_num = vwB_rx_buffnum;
    ret = can_rxmsg(&rxinfo);
    ASSERT_EECS(ret == 0);
    if (rxinfo.length == sizeof(curr_angle)) {
    	memcpy(&curr_angle, rxinfo.data, sizeof(curr_angle));
    }

    /* 2. Calculate the torque */
    torque = virtualWall();

    /* 3. Transmit the torque back */
    txinfo.buff_num = vwB_tx_buffnum;
	txinfo.id = vwB_tx_ID;
	txinfo.length = sizeof(torque);
	memcpy(txinfo.data, &torque, sizeof(torque));

    ret = can_txmsg(&txinfo);
    ASSERT_EECS(ret == 0);

    /* clear interrupt flag for TX channel */
    clearFlagLPIT(CAN_TX_ISR_CHANNEL);
}
#endif



 /***************************************************************************
 * Function:	virt_chain()
 * Description:	Implements one station in part of a chain.  The position and
 *				velocity of neighboring stations are received and the
 *				appropriate torque calculations are applied.
 * Equation:	k*(posA+posB-2*pos) + b*(velA+velB-2*vel)
 * Shared Data: posA (float, deg)
 *				velA (float, deg/s)
 *				posB (float, deg)
 *				velB (float, deg/s)
 *
 * 1. Read wheel angle (deg)
 * 2. Calculate wheel velocity (deg/s)
 * 3. Calculate & apply torque
 * 4. Transmit the wheel position and velocity
 ***************************************************************************/
#ifdef VCHAIN
const uint32_t vc_f = 250; /* frequency of the chain wall (Hz) */
const float k = 25.0;      /* spring-rate (N-mm/deg) */
const float b = 0.2;       /* damping (N-mm/(deg/s)) */

void virt_chain()
{
	CAN_TXINFO txinfo; 		/* buffer to transmit pos and velocity */
	float curr_angle, velocity,torque_left,torque_right,torque;
	static float prev_angle=0;


    /* 1. Read wheel angle (deg) */
	curr_angle = updateAngle();

    /* 2. Calculate wheel velocity (deg/s) */
    velocity = (curr_angle - prev_angle) * vc_f;

    /* 3. Calculate & apply torque  */
    outputTorque(k*(posA+posB-2*curr_angle) + b*(velA+velB-2*velocity));

    /* 4. Transmit your wheel position and velocity */
    /**** 8-bytes (first 4 for position and second 4 for velocity) ****/
    /* 3. Transmit the wheel position in a CAN message */
    txinfo.buff_num = chain_tx_buffnum;
    txinfo.id = chain_tx_ID;
    txinfo.length = sizeof(velocity) + sizeof(curr_angle);
    memcpy(txinfo.data[0], &curr_angle, sizeof(curr_angle));
    memcpy(txinfo.data[4], &velocity, sizeof(velocity));

	ret = can_txmsg(&txinfo);
    ASSERT_EECS(ret == 0);

    /* clear interrupt flag for TX channel */
    clearFlagLPIT(CAN_TX_ISR_CHANNEL);

	return;
}
#endif


int main()
{
	float angle = 0.0f;
	int ret;

	/* Processor initialization */
	initECS();

	/* Configure QD module */
	initQD();

	/* Configure PWM module for motor */
	initPWMPCRs();
	initGPDI(DIP_BASE[0], DIP[0]);
	initPWM(MOTOR_SUBMODULE,MOTOR_CHANNEL,MOTOR_FREQUENCY, 0.50f);
	initPWM(FILTER_SUBMODULE,FILTER_CHANNEL,FILTER_FREQUENCY, 0.50f);

	/* Configure FlexCan module */
	initFlexcan();

	/* Set the CAN receive ISR */
	can_set_rxisr(&rx_ISR);

	#ifdef VWALLA
	can_rxbuff_init(vwA_rx_buffnum, vwA_rx_ID, 1);
	#endif

	#ifdef VWALLB
	can_rxbuff_init(vwB_rx_buffnum, vwB_rx_ID, 1);
	#endif

	#ifdef VCHAIN
	can_rxbuff_init(chain_rx_buffnum, chain_rx_ID, 1);
	#endif

	/* Initialize the shared global variables */
	vw_torque = 0 ;	/* wall torque (FLOAT32, N-mm) */
	posA = 0 ;		/* chain position A (FLOAT32, N-mm) */
	velA = 0 ;		/* chain velocity A (FLOAT32, N-mm) */
	posB = 0 ;		/* chain position B (FLOAT32, N-mm) */
	velB = 0 ;		/* chain velocity B (FLOAT32, N-mm) */

	#ifdef VWALLA
		initLPIT(CAN_TX_ISR_CHANNEL, 250, &virt_wall_A, 0xB);
	#endif

	#ifdef VWALLB
		// Do nothing. VWALLB interrupted by CAN Rx only
	#endif

	#ifdef VCHAIN
		initLPIT(CAN_TX_ISR_CHANNEL, 250, &virt_chain, 0xB);
	#endif
	ENABLE_INTERRUPTS()


	// idle loop
	while (1)
	{}
   }
