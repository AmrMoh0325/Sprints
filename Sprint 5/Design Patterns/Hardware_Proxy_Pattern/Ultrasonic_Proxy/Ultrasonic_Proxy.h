/*
 * Ultrasonic_Proxy.h
 *
 *  Created on: Aug 25, 2021
 *      Author: DELLL
 */

#ifndef HW_PROXY_HANDLER_ULTRASONIC_PROXY_ULTRASONIC_PROXY_H_
#define HW_PROXY_HANDLER_ULTRASONIC_PROXY_ULTRASONIC_PROXY_H_

/*Includes*/
#include "../../ECUAL/Ultrasonic/Ultrasonic.h"

/*Functions Prototypes*/
enuErrorStatus_t UltrasonicProxy_Init(void);
enuErrorStatus_t UltrasonicProxy_Trigger(enuUltrasonicChannel_t Channel);
enuErrorStatus_t UltrasonicProxy_GetDistance(uint16_t *Distance);
enuErrorStatus_t UltrasonicProxy_GetReading_Polling(enuUltrasonicChannel_t Channel,uint32_t *Distance);

#endif /* HW_PROXY_HANDLER_ULTRASONIC_PROXY_ULTRASONIC_PROXY_H_ */
