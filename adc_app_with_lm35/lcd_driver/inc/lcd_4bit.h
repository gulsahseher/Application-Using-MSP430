#ifndef _LCD_4BIT_H_
#define _LCD_4BIT_H_
 
#define    LCD_DATA         P1OUT
#define    LCD_RS           P2OUT_bit.P6
#define    LCD_EN           P2OUT_bit.P7
#define    LCD_STROBE()     ((LCD_EN=1),(LCD_EN=0))
 
extern void lcd_write(unsigned char);
extern void lcd_clear(void);
extern void lcd_puts(const char *);
extern void lcd_putch(char c);
extern void lcd_goto(unsigned char, unsigned char);
extern void lcd_init(void);
 
#endif //_LCD_4BIT_H_