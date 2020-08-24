#ifndef _LCD_DISPLAY_H_
#define _LCD_DISPLAY_H_
extern void display_normal();//显示学号
extern void display_channel_Voltage(unsigned char m);//显示通道和电压
extern void display_down(unsigned char p);//显示下限电压值
extern void display_up(unsigned char p);//显示上限电压值
extern void display_adjust(char s);//显示调节后上下限电压的内容，s用来选择显示上限电压还是下限电压
extern unsigned char flag;//flag用来保存通道序号
#endif