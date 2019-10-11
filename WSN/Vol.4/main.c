#include <ioCC2530.h>
#define LED1 P1_0       //P1.0端口控制LED1发光二极管  第3个
#define LED2 P1_1       //P1.1端口控制LED1发光二极管  第4个
#define LED3 P1_3       //P1.3端口控制LED1发光二极管  第1个
#define LED4 P1_4       //P1.4端口控制LED1发光二极管  第2个
//*********************************************************************************
void delay(unsigned int i)
{   unsigned int j,k;
    for(k=0;k<i;k++)
    { for(j=0;j<500;j++);    }}
//*********************************************************************************
void initial_usart_tx()
{   CLKCONCMD &= ~0X7F;                  	//晶振设置为32MHz
    while(CLKCONSTA & 0X40); 	//等待晶振稳定
    CLKCONCMD &= ~0X47;                	 //设置系统主时钟频率为32MHz
    PERCFG = 0X00;                      	 //usart0 使用备用位置1 TX-P0.3 RX-P0.2
    P0SEL |=0X3C;                        		 //P0.2 P0.3 P0.4 P0.5用于外设功能
    P2DIR &= ~0xC0;                     	//P0优先作为UART方式
    U0CSR |= 0XC0; 			 //uart模式 允许接收    
    U0GCR = 9;
    U0BAUD = 59;			//波特率设为19200
    URX0IF = 0; 			//uart0 tx中断标志位清零   
 }
//*********************************************************************************
void uart_tx_string(char *data_tx,int len)
{   unsigned int j;
    for(j=0;j<len;j++)
    {   U0DBUF = *data_tx;
        while(UTX0IF == 0);
        UTX0IF = 0;    }}
//*********************************************************************************
void main(void)
{   initial_usart_tx();
    P1SEL &=0xE6;        //设置P1.0 P1.1 P1.3 P1.4为GPIO
    P1DIR |= 0X1B;       //定义P1.0端口为输出
    P1=0X00;
    while(1)
    {   if( URX0IF == 1)
        {   URX0IF = 0;
            switch(U0DBUF)
            {   case 0x01:LED1 = 1;break;		//'1'表示接收到数据为字符，以下相同
                case 0x02:LED2 = 1;break;	//0X02表示接收到数据为十六进制数，以下相同
                case 0x03:LED3 = 1;break;
                case 0x04:LED4 = 1;break;
                case 0x05:LED1 = 0;LED2 = 0;LED3 = 0;LED4 = 0;break;
                default:break;            
            }   
        }  
    }
}
