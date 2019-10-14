/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   测试按键
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
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
  * @brief  主函数
  * @param  无
  * @retval 无
  */ 
int main(void)
{	
	int flag = 0;
	/* LED端口初始化 */
	LED_GPIO_Config();
	//LED1_ON;

	/* 按键端口初始化 */
	Key_GPIO_Config();
	
	/* 轮询按键状态，若按键按下则反转LED */
	while(1)                            
	{	   
		if( Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON  )
		{
			
			LED_RED;
			delay(10000000);
			LED_RGBOFF;
		}
		if( Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == KEY_ON  )
		{
			LED_GREEN;
			delay(10000000);
			LED_RGBOFF;
		}		
	}
}
/*********************************************END OF FILE**********************/
