#ifndef _led_H
#define _led_H
#include "stm32f4xx_hal.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2015/9/7
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

//#define LED0 PFout(9)   	//LED0
//#define LED1 PFout(10)   	//LED1

void LED_Init(void);
void LED1_On(void);
void LED2_On(void);
void LED3_On(void);
#endif
