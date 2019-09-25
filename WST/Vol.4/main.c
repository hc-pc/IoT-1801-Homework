#include <ioCC2530.h>

#define LED1 P1_0

unsigned int count = 0;

#pragma vector = T1_VECTOR
__interrupt void T1_ISR(void) {
  IRCON = 0x00;
  if (count > 300) {
    count = 0;
    LED1 = !LED1;
  }
  else {
      count++;
  }
}

void main(void) {
  CLKCONCMD &= ~0x7F;
  while (CLKCONCMD & 0x40);
  T1IE = 1;
  T1CTL = 0x05;
  TIMIF |= 0x40;
  EA = 1;
  P1SEL &= ~0x01;
  P1DIR |= 0x01;
  LED1 = 0;
  while (1);
}
