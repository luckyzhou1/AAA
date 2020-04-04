#ifndef __aaa_H
#define __aaa_H

#ifdef STM32F4
#include "stm32f4xx_hal.h"
//#elif defined STM32F1
//#include "stm32f1xx_hal.h"
#endif
//#include "mytype.h"
#include "can.h"

extern HAL_StatusTypeDef CAN_Polling(void);
 
#endif
