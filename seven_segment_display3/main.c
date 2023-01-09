
#include <msp430.h>

unsigned int i=0;
unsigned int digit[11]={0x11,0xD7,0x32,0x92,0xD4,0x98,0x18,0xD3,0x10,0x90,0xEF};

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P1SEL=0x00;
  P1DIR |= (BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7);
  P1OUT &=~ (BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7);
  P2DIR &= ~BIT0;
  P2REN |= BIT0; // PULL-UP/DOWN setlendi
  P2OUT |= BIT0; // PULL-UP setlendi
  
  while(1)
  {
    if((P2IN & BIT0)!=BIT0)
    { 
      P1OUT &= ~(BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7);  
      P1OUT |= digit[i];
        __delay_cycles(1000000);
        i++; 
       if(i==11)
        {
          i=0;
        }
    }
  }
  return 0;
  
}
