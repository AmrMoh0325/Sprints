#ifndef BUTTONCLIENT_H_
#define BUTTONCLIENT_H_

#include "Timer.h"
#include "Button.h"
#include "STD_TYPES.h"

/*************************************************************************************************
* Parameters	: enuDIOPinNo, enuButtonConnectionType, enuTimerSelect
* Return Value	: enuErrorStatus_t
* Description  : Initialize the button client according to the configurations
*************************************************************************************************/
void ButtonClient_Init(enuDIOPinNo_t enuDIOPinNo, enuButtonConnectionType_t enuButtonConnectionType, enuTimerSelect_t enuTimerSelect);
/*************************************************************************************************
* Parameters	: enuDIOPinNo, pfButtonClient_AppFunction
* Return Value	: enuErrorStatus_t
* Description  : Handle the debouncing of the selected button 
*************************************************************************************************/
void ButtonClient_EventReceive(enuDIOPinNo_t enuDIOPinNo, void (*pfButtonClient_AppFunction)(enuButtonStates_t));

#endif /* BUTTONCLIENT_H_ */