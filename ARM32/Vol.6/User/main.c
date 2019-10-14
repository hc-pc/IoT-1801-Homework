/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ���԰���
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-ָ���� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 

#include "stm32f10x.h"
#include "bsp_led.h"  
#include "bsp_key.h" 

void delay(int loop) {
	while (loop--);
}

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */ 
int main(void)
{	
	int flag = 0;
	/* LED�˿ڳ�ʼ�� */
	LED_GPIO_Config();
	//LED1_ON;

	/* �����˿ڳ�ʼ�� */
	Key_GPIO_Config();
	
	/* ��ѯ����״̬��������������תLED */
	while(1)                            
	{	   
		if( Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON  )
		{
			if (flag == 0) {
				LED_RED;
				delay(10000000);
				LED_RGBOFF;
			}
			else {
				LED_GREEN;
				delay(10000000);
				LED_RGBOFF;
			}
		} 

//		if( Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == KEY_ON  )
//		{
//			LED_GREEN;
//			delay(10000000);
//			LED_RGBOFF;
//		}		
	}
}
/*********************************************END OF FILE**********************/
