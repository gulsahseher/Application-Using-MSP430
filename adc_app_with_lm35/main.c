#include "io430.h"
#include "in430.h"
#include "lcd_4bit.h"
 
unsigned int ADC_Result;
unsigned int Temperature;
unsigned char str[3];
int x = 1;
int i;

void adc_init(void)
{
    ADC10CTL0 &= ~ENC;//ADC10 enable conversion,ADC10 disabled
    ADC10CTL0 = ADC10ON + REFON + SREF_1  + ADC10SHT_3 + ADC10IE;//1.5v reference voltage,64*ADC10 clocks, ADC10 on,interrupt enable
    ADC10CTL1 = INCH_6 + ADC10SSEL_3 + ADC10DIV_3;//chosen internal temperature sensor,SMCLK,clock divider 3
    ADC10AE0 = BIT6;//Anlog enable for internal temperature
}

void LCD_Write_Int (unsigned int val,char mul)
{
   char j;
   int temp=1;
    for(j=0;j<mul;j++)
    {
    str[j] = (((val/temp)%10)+48);
    temp=temp*10;
    }
   lcd_putch(str[2]);
   lcd_putch(str[1]);
   lcd_putch('.');
   lcd_putch(str[0]);
   lcd_putch(223);
   lcd_putch('C');
}
 
void main(void)
{
   
  WDTCTL = WDTPW + WDTHOLD;
 
   DCOCTL=CALDCO_1MHZ;
   BCSCTL1=CALBC1_1MHZ;
 
   P1SEL = 0x00;
   P1OUT = 0x00;
   P1DIR = 0xFF;
   P2SEL_bit.P6 = 0;
   P2SEL_bit.P7 = 0;
   P2DIR_bit.P6 = 1;
   P2DIR_bit.P7 = 1;
 
   adc_init();
   lcd_init();
 
   lcd_goto(1,1);
   lcd_puts("    SICAKLIK    ");
   ADC10CTL0 |= ADC10SC + ENC;
 
   for(;;)
   {
           _BIS_SR(CPUOFF + GIE);//low power mode
   }
}
/* 
#pragma vector = TIMER0_A0_VECTOR
__interrupt void bekle(void){
    
   ADC10CTL0 |= ADC10SC + ENC; //start conversion and enable conversion
   while(!(ADC10CTL0 & ADC10IFG));// ADC10IFG = 00000100, wait until flag unset
   ADC_Result = ADC10MEM;//read analog value
   Temperature= (unsigned int)(ADC_Result*0.44828125);//convert to degree from analog value.(Vref*1000)/(1024*10),(1C=10mV)
   TACTL = TACTL & (~TAIFG);// flag is unset

	  // _BIC_SR(LPM0_EXIT);//exit low power mode
}
*/

#pragma vector=ADC10_VECTOR
__interrupt void ADC_ISR(void)
{
   ADC_Result = ADC10MEM;
   Temperature = (unsigned int)(ADC_Result*1.46484375);
   lcd_goto(2,6);
   LCD_Write_Int(Temperature,3);
   ADC10CTL0_bit.ADC10IFG = 0;
   ADC10CTL0 |= ADC10SC + ENC;
   __delay_cycles(650000);
   //TACTL = TACTL & (~TAIFG);
}

/*
#pragma vector = ADC10_VECTOR
__interrupt void adc_kesmesi(void)
{
    x = 1;
    lcd_goto(2,6);
//for write temperature value on lcd
    for(i=0;i<=1;i++)
    {
       str[i] = (((Temperature/x)%10)+48);
       x=x*10;
    }
    for(i=0;i<=1;i++)
    {
       lcd_putch(str[1-i]);
    }
}*/