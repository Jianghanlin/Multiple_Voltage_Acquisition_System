#include "my_info.h"
#include "define.h"
#include "lcd_init.h"
#include "delay.h"
uchar code a1[]="Author: JHL";
uchar code a2[]="Num: Xb17610107";
void my_info()
{
    	uchar i=0,j=0;
 		LCD_Write_Command(0x80);
		while(a1[i]!='\0')
		{	
			LCD_Write_Value(a1[i]);
			i++;
			delay(5);
		}
		
		LCD_Write_Command(0x40+0x80);
		while(a2[j]!='\0')
		{	
			LCD_Write_Value(a2[j]);
			j++;
			delay(5);
		}
		delay(2000);//信息显示2秒后清屏
		LCD_Write_Command(0x01);		
}