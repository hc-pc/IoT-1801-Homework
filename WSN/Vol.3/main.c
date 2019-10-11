#include <ioCC2530.h>

#define LED1 P1_0
#define LED2 P1_1
#define SW1 P1_2
#define LED3 P1_3
#define LED4 P1_4

unsigned char statues;

void Init_GPIO() {
  P1SEL &= ~0x1F;
  P1DIR |= 0x1B;
  P1DIR &= ~0x04;
  P1 = 0x00;
  P1INP &= ~0x04;
  P2INP &= ~0x40;
}

void Init_Interrupt() {
  EA = 1;
  IEN2 |= 0x10;
  P1IEN |= 0x04;
  PICTL |= 0x02;
}

#pragma vector = P1INT_VECTOR
__interrupt void P1_ISR(void) {
  if (P1IFG == 0x04) {
    statues++;
    switch (statues) {
    case 1:
      LED1 = 1;
      LED2 = 0; LED3 = 0; LED4 = 0;
      break;
    case 2:
      LED1 = 0;
      LED2 = 1;
      LED3 = 0; LED4 = 0;
      break;
    case 3:
      LED1 = 0; LED2 = 0;
      LED3 = 1;
      LED4 = 0;
      break;
    case 4:
      LED1 = 0; LED2 = 0; LED3 = 0;
      LED4 = 1;
      break;
    default:
      P1 = 0x00;
      statues = 0x00;
      break;
    }
  }
  P1IF = 0x00;
  P1IFG = 0x00;
}

void main(void) {
  Init_GPIO();
  Init_Interrupt();
  
  while(1){;}
}
