#ifndef _led_H
#define _led_H
#include "stm32f4xx_hal.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2015/9/7
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

//#define LED0 PFout(9)   	//LED0
//#define LED1 PFout(10)   	//LED1

void LED_Init(void);
void LED1_On(void);
void LED2_On(void);
void LED3_On(void);
#endif
