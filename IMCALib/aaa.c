#include "can.h"
#include "aaa.h"
#include "led.h"

//CAN_HandleTypeDef hcan1;

CAN_RxHeaderTypeDef   RxHeader;

uint8_t               RxData[8];
uint32_t              TxMailbox;


 //void Error_Handler(void);



void can_user_init(CAN_HandleTypeDef* hcan )
{
  CAN_FilterTypeDef  sFilterConfig;
	
	sFilterConfig.FilterBank = 0;
  sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
  sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
  sFilterConfig.FilterIdHigh = 0x0000;
  sFilterConfig.FilterIdLow = 0x0000;
  sFilterConfig.FilterMaskIdHigh = 0x0000;
  sFilterConfig.FilterMaskIdLow = 0x0000;
  sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
  sFilterConfig.FilterActivation = ENABLE;
  sFilterConfig.SlaveStartFilterBank = 14;
	
	
	HAL_CAN_ConfigFilter(hcan, &sFilterConfig);        // init can filter
  HAL_CAN_Start(&hcan1);                          // start can1
  HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING); // enable can1 rx interrupt
  
  
}
	void motodsjd(void)
	{
		CAN_TxHeaderTypeDef   TxHeader;
		uint8_t               TxData[8];
		
	 TxHeader.StdId = 0x200;
  TxHeader.RTR = CAN_RTR_DATA;
  TxHeader.IDE = CAN_ID_STD;
  TxHeader.DLC = 2;
  TxHeader.TransmitGlobalTime = DISABLE;
  TxData[0] = 0x03;
  TxData[1] = 0xe9;
  
  /* Request transmission 请求传输*/
	HAL_CAN_AddTxMessage(&hcan1, &TxHeader, TxData,(uint32_t*)CAN_TX_MAILBOX0); 
 
  /* Wait transmission complete */
   while(HAL_CAN_GetTxMailboxesFreeLevel(&hcan1) !=3) {}

  /*##-5- Start the Reception process ########################################*/
  if(HAL_CAN_GetRxFifoFillLevel(&hcan1, CAN_RX_FIFO0) != 1)
  {
    /* Reception Missing接收丢失 */
    Error_Handler();
 }

  if(HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK)
  {
    /* Reception Error */
    Error_Handler();
	}

  
}
  

