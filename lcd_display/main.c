#include "io430.h"
#include "in430.h"
#include "lcd_4bit.h"
 
void main(void)
{
   WDTCTL = WDTPW + WDTHOLD;
 
   DCOCTL=CALDCO_1MHZ;
   BCSCTL1=CALBC1_1MHZ;
 
   P1SEL = 0x00;
   P1OUT = 0x00;
   P1DIR = 0xFF;
   P2SEL = 0x00;
   P2OUT = 0x00;
   P2DIR = 0xFF;
 
   lcd_init();
 
   lcd_goto(1,1);
   lcd_puts(". *  Hello  *  .");
   lcd_goto(2,1);
   lcd_puts("     (^.^)      ");
 
   for(;;);
}