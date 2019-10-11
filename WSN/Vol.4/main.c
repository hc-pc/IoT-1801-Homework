#include <ioCC2530.h>
#define LED1 P1_0       //P1.0�˿ڿ���LED1���������  ��3��
#define LED2 P1_1       //P1.1�˿ڿ���LED1���������  ��4��
#define LED3 P1_3       //P1.3�˿ڿ���LED1���������  ��1��
#define LED4 P1_4       //P1.4�˿ڿ���LED1���������  ��2��
//*********************************************************************************
void delay(unsigned int i)
{   unsigned int j,k;
    for(k=0;k<i;k++)
    { for(j=0;j<500;j++);    }}
//*********************************************************************************
void initial_usart_tx()
{   CLKCONCMD &= ~0X7F;                  	//��������Ϊ32MHz
    while(CLKCONSTA & 0X40); 	//�ȴ������ȶ�
    CLKCONCMD &= ~0X47;                	 //����ϵͳ��ʱ��Ƶ��Ϊ32MHz
    PERCFG = 0X00;                      	 //usart0 ʹ�ñ���λ��1 TX-P0.3 RX-P0.2
    P0SEL |=0X3C;                        		 //P0.2 P0.3 P0.4 P0.5�������蹦��
    P2DIR &= ~0xC0;                     	//P0������ΪUART��ʽ
    U0CSR |= 0XC0; 			 //uartģʽ �������    
    U0GCR = 9;
    U0BAUD = 59;			//��������Ϊ19200
    URX0IF = 0; 			//uart0 tx�жϱ�־λ����   
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
    P1SEL &=0xE6;        //����P1.0 P1.1 P1.3 P1.4ΪGPIO
    P1DIR |= 0X1B;       //����P1.0�˿�Ϊ���
    P1=0X00;
    while(1)
    {   if( URX0IF == 1)
        {   URX0IF = 0;
            switch(U0DBUF)
            {   case 0x01:LED1 = 1;break;		//'1'��ʾ���յ�����Ϊ�ַ���������ͬ
                case 0x02:LED2 = 1;break;	//0X02��ʾ���յ�����Ϊʮ����������������ͬ
                case 0x03:LED3 = 1;break;
                case 0x04:LED4 = 1;break;
                case 0x05:LED1 = 0;LED2 = 0;LED3 = 0;LED4 = 0;break;
                default:break;            
            }   
        }  
    }
}
