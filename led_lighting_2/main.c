
#include <msp430.h>
unsigned int i;

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P1SEL=0x00; //giris cikis olarak ayarlandi
  P1DIR |= BIT1; //BIT1 setlendi cikis olarak ayarlandi
  P1OUT &=~ BIT1; //BIT1 cikisi lojik 0
  P1DIR &=~ BIT2;
  P1REN |= BIT2; // PULL-UP/DOWN setlendi
  P1OUT |= BIT2; // PULL-UP
  
  
  while(1)
  {
    if(P1IN&BIT2)
    {
      P1OUT &=~ BIT1;
    }
    else
    {
      P1OUT |= BIT1;
    }
  }
  return 0;
}
