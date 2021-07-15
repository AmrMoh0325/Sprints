/*****************************************************************************
* Task: AVR_DRIVERS
* File Name: Register.h
* Description: File for AVR Register definitions
* Author: Amr Mohamed
* Date: 8/7/2021
******************************************************************************/

#ifndef __REGISTER__
#define __REGISTER__

/* DIO_Registers */
#define DDRA_R  (*(volatile unsigned char*)0x3A)
#define DDRB_R  (*(volatile unsigned char*)0x37)
#define DDRC_R  (*(volatile unsigned char*)0x34)
#define DDRD_R  (*(volatile unsigned char*)0x31)

#define PINA_R  (*(volatile unsigned char*)0x39)
#define PINB_R  (*(volatile unsigned char*)0x36)
#define PINC_R  (*(volatile unsigned char*)0x33)
#define PIND_R  (*(volatile unsigned char*)0x30)

#define PORTA_R (*(volatile unsigned char*)0x3B)
#define PORTB_R (*(volatile unsigned char*)0x38)
#define PORTC_R (*(volatile unsigned char*)0x35)
#define PORTD_R (*(volatile unsigned char*)0x32)
/************************************************************************************************/


/************************************************************************************************/
/* Timer 0 */
#define TCNT0_R   (*(volatile unsigned char*)0x52)
#define TCCR0_R   (*(volatile unsigned char*)0x53)
/* TCCR0 */
#define FOC0_B    7
#define WGM00_B   6
#define COM01_B   5
#define COM00_B   4
#define WGM01_B   3
#define CS02_B    2
#define CS01_B    1
#define CS00_B    0

#define TWCR_R    (*(volatile unsigned char*)0x56)
#define SPMCR_R   (*(volatile unsigned char*)0x57)
#define TIFR_R    (*(volatile unsigned char*)0x58)
#define TIMSK_R   (*(volatile unsigned char*)0x59)
/* TIMSK */
#define OCIE2_B   7
#define TOIE2_B   6
#define TICIE1_B  5
#define OCIE1A_B  4
#define OCIE1B_B  3
#define TOIE1_B   2
#define OCIE0_B   1
#define TOIE0_B   0

#define OCR0_R    (*(volatile unsigned char*)0x5C)
/****************************************************************************************************/

/*TIMER 1*/


#define ICR1_R			(*(volatile unsigned short*)0x46)
#define ICR1L_R		(*(volatile unsigned char*)0x46)
#define ICR1H_R		(*(volatile unsigned char*)0x47)
#define OCR1B_R		(*(volatile unsigned short*)0x48)
#define OCR1BL_R		(*(volatile unsigned char*)0x48)
#define OCR1BH_R		(*(volatile unsigned char*)0x49)
#define OCR1A_R		(*(volatile unsigned short*)0x4A)
#define OCR1AL_R		(*(volatile unsigned char*)0x4A)
#define OCR1AH_R		(*(volatile unsigned char*)0x4B)
#define TCNT1_R		(*(volatile unsigned short*)0x4C)
#define TCNT1L_R		(*(volatile unsigned char*)0x4C)
#define TCNT1H_R		(*(volatile unsigned char*)0x4D)
#define TCCR1B_R     (*(volatile unsigned char*)0x4E)
#define TCCR1A_R     (*(volatile unsigned char*)0x4F)
#define SFIOR_R		(*(volatile unsigned char*)0x50)
#define OSCCAL_R		(*(volatile unsigned char*)0x51)
/*************************************************************************************************/
/* Timer 2 */

#define OCR2_R       (*(volatile unsigned char*)0x43)
#define TCNT2_R      (*(volatile unsigned char*)0x44)
#define TCCR2_R      (*(volatile unsigned char*)0x45)




/* TCCR2 */
#define FOC2_B    7
#define WGM20_B   6
#define COM21_B   5
#define COM20_B   4
#define WGM21_B   3
#define CS22_B    2
#define CS21_B    1
#define CS20_B    0

/* ASSR */
/* bits 7-4 reserved */
#define AS2_B     3
#define TCN2UB_B  2
#define OCR2UB_B  1
#define TCR2UB_B  0

/* TCCR1A */
#define COM1A1_B  7
#define COM1A0_B  6
#define COM1B1_B  5
#define COM1B0_B  4
#define FOC1A_B   3
#define FOC1B_B   2
#define WGM11_B   1
#define WGM10_B   0

/* TCCR1B */
#define ICNC1_B   7
#define ICES1_B   6
/* bit 5 reserved */
#define WGM13_B   4
#define WGM12_B   3
#define CS12_B    2
#define CS11_B    1
#define CS10_B    0


/*************************************************************************************************/




#endif /* __REGISTER__ */