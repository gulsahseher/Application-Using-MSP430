
#include <msp430.h>

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR=0xFF;
  
  while(1)
  {
    P1OUT= 0x11;
    __delay_cycles(1000000);
    P1OUT= 0xD7;
    __delay_cycles(1000000);
    P1OUT= 0x32;
    __delay_cycles(1000000);
    P1OUT= 0x92 ;
    __delay_cycles(1000000);
    P1OUT= 0xD4 ;
    __delay_cycles(1000000);
    P1OUT= 0x98;
    __delay_cycles(1000000);
    P1OUT= 0x18;
    __delay_cycles(1000000);
    P1OUT= 0xD3;
    __delay_cycles(1000000);
    P1OUT= 0x10;
    __delay_cycles(1000000);
    P1OUT= 0x90;
    __delay_cycles(1000000);
    P1OUT= 0xEF ;
    __delay_cycles(1000000);
  }

  return 0;
}
