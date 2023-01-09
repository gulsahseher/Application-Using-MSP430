
#include <msp430.h>

unsigned int i;
unsigned int digit[11]={0x11,0xD7,0x32,0x92,0xD4,0x98,0x18,0xD3,0x10,0x90,0xEF};

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P1SEL=0x00; //giris cikis olarak ayarlandi
  P1DIR=0xFF;
  //P1DIR &=~ BIT4;
  //P1REN |= BIT4; // PULL-UP/DOWN setlendi
  //P1OUT |= BIT4; // PULL-UP
  
  
  while(1)
  {
      P1OUT= digit[i];
      __delay_cycles(1000000);
      i++;  
      if (i==11)
        {
            i=0;
        }
  }

  return 0;
}
