#include <ioCC2530.h>

#define LED1 P1_0
#define LED2 P1_1
#define LED3 P1_3
#define LED4 P1_4

void delay(int loop) {
  int i = 0;
  int j = 0;
  for (i = 0; i < loop; i++)
    for(j = 0; j < loop; j++);
}

void main() {
  P1SEL &= ~0x1B;
  P1DIR |= ~0x1B;
  P1 &= ~0x1B;
  while (1) {
    LED1 = 1;
    LED2 = 0; LED3 = 0; LED4 = 0;
    delay(100);
    
    LED1 = 0;
    LED2 = 1;
    LED3 = 0; LED4 = 0;
    delay(100);
    
    LED1 = 0; LED2 = 0;
    LED3 = 1;
    LED4 = 0;
    delay(100);
    
    LED1 = 0; LED2 = 0; LED3 = 0;
    LED4 = 1;
    delay(100);
  }
}