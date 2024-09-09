/**************************************************************************
 * FILE NAME: LPUART.h
 *
 * University of Michigan
 * EECS 461, Embedded Control Systems
 *
 * Revision History:
 *	2016-03-17		B46911 (author)
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 **************************************************************************/

#ifndef LPUART_H_
#define LPUART_H_

void LPUART1_init(void);
void LPUART1_transmit_char(char send);
void LPUART1_transmit_string(char data_string[]);
char LPUART1_receive_char(void);
void LPUART1_recieve_and_echo_char(void);
#endif /* LPUART_H_ */
