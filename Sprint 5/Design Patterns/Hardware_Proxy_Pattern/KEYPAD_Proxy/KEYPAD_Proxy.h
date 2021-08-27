/*
 * KEYPAD_Proxy.h
 *
 *  Created on: Aug 23, 2021
 *      Author: DELLL
 */

#ifndef HW_PROXY_HANDLER_KEYPAD_PROXY_KEYPAD_PROXY_H_
#define HW_PROXY_HANDLER_KEYPAD_PROXY_KEYPAD_PROXY_H_

/* Includes */
#include "../../ECUAL/KEYPAD/KEYPAD.h"

/* Functions prototypes */
enuErrorStatus_t KEYPADProxy_Init(void);
enuErrorStatus_t KEYPADProxy_Read(uint8_t* ptr);

#endif /* HW_PROXY_HANDLER_KEYPAD_PROXY_KEYPAD_PROXY_H_ */
