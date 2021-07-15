/*****************************************************************************
* Task: Car Project
* File Name: BIT_math.h
* Description: common macros for bit manipulation
* Author: TEAM2
* Date: 8/7/2021
******************************************************************************/

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

/*- FUNCTION-LIKE MACROS -----------------------------------*/
#define SET_BIT(REG,BIT)         (REG)  |= (1<<(BIT))
#define CLR_BIT(REG,BIT)       	 (REG)  &= ~(1<<(BIT))
#define GET_BIT(REG,BIT)         ((REG) &   (1<<BIT))
#define TOGGLE_BIT(REG,BIT)      (REG) ^= (1 << (BIT))
#define SET_FIRST_NIPPLE(REG)    (REG) |= ((1<<0) | (1<<1) | (1<<2) | (1<<3))
#define SET_SECOND_NIPPLE(REG)   (REG) |= ((1<<4) | (1<<5) | (1<<6) | (1<<7))
#define CLEAR_FIRST_NIPPLE(REG)  (REG) &= ((~(1<<0)) & (~(1<<1)) & (~(1<<2)) & (~(1<<3)))
#define CLEAR_SECOND_NIPPLE(REG) (REG) &= ((~(1<<4)) & (~(1<<5)) & (~(1<<6)) & (~(1<<7)))

#define CONC(BIT7,BIT6,BIT5,BIT4,BIT3,BIT2,BIT1,BIT0)		CONC_HELP(BIT7,BIT6,BIT5,BIT4,BIT3,BIT2,BIT1,BIT0)
#define CONC_HELP(BIT7,BIT6,BIT5,BIT4,BIT3,BIT2,BIT1,BIT0)	0b##BIT7##BIT6##BIT5##BIT4##BIT3##BIT2##BIT1##BIT0


#endif /* LIB_BIT_MATH_H_ */
