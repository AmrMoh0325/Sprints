/*****************************************************************************
* Task: Car Project
* File Name: TM_registers.h
* Description: header file for the timer memory mapped registers
* Author: TEAM2
* Date: 11/7/2021
******************************************************************************/

#ifndef MCAL_TIMER_TM_REGISTERS_H_
#define MCAL_TIMER_TM_REGISTERS_H_

/*- DEFINES -----------------------------------------------*/

/*- Status Register ---------------------------------------*/
#define SREG_R      (*(volatile unsigned char*) 0x5F)
#define SREG_I_BIT  7		//global interrupt enable bit

/*- Timer0 Registers---------------------------------------*/

/*- Timer/Counter Control Register – TCCR0 ----------------*/
#define TCCR0_R     (*(volatile unsigned char*)0x53)
#define CS00_BIT	0
#define CS01_BIT	1
#define CS02_BIT	2
#define WGM01_BIT	3
#define COM00_BIT	4
#define COM01_BIT	5
#define WGM00_BIT	6
#define FOC0_BIT	7

/*- Timer/Counter Interrupt Mask Register – TIMSK ----------*/
#define TIMSK_R   	(*(volatile unsigned char*)0x59)
#define TOIE0_BIT   0
#define OCIE0_BIT   1
#define TOIE1_BIT   2
#define OCIE1B_BIT  3
#define OCIE1A_BIT  4
#define TICIE1_BIT  5
#define TOIE2_BIT   6
#define OCIE2_BIT   7

/*- Timer/Counter Interrupt Flag Register – TIFR ----------*/
#define TIFR_R     (*(volatile unsigned char*)0x58)
#define TOV0_BIT   0
#define OCF0_BIT   1
#define TOV1_BIT   2
#define OCF1B_BIT  3
#define OCF1A_BIT  4
#define ICF1_BIT   5
#define TOV2_BIT   6
#define OCF2_BIT   7

/*- Output Compare Register – OCR0 -----------------------*/
#define	OCR0_R		(*(volatile unsigned char*)0x5C)

/*- Timer/Counter Register – TCNT0 -----------------------*/
#define	TCNT0_R		(*(volatile unsigned char*)0x52)



/*************************************************************************************************************/
/*- Timer1 Registers----------------------------------------*/
#define	TCNT1H_R	(*(volatile unsigned char*)0x40)
#define	TCNT1L_R	(*(volatile unsigned char*)0x4C)
#define	OCR1AH_R	(*(volatile unsigned char*)0x48)
#define	OCR1AL_R	(*(volatile unsigned char*)0x4A)
#define	OCR1BH_R	(*(volatile unsigned char*)0x49)
#define	OCR1BL_R	(*(volatile unsigned char*)0x48)
#define	ICR1H_R		(*(volatile unsigned char*)0x47)
#define	CR1L_R		(*(volatile unsigned char*)0x46)

/*************************************************************************************************************/
/*- Timer2 Registers----------------------------------------*/
#define	TCNT2_R		(*(volatile unsigned char*)0x44)
#define	OCR2_R		(*(volatile unsigned char*)0x43)

#endif /* MCAL_TIMER_TM_REGISTERS_H_ */
