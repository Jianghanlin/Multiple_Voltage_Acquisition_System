#include <reg52.h>
#include "lcd_init.h"
#include "delay.h"
#include "define.h"
sbit LCD_RS=P3^7;//RS为寄存器选择引脚,1数据寄存器,0指令寄存器
sbit LCD_RW=P3^6;//读写信号线,1读操作,0写操作
/* 
RS=0,RW=0:写入(指令或显示地址)
RS=0,RW=1:读忙信号
RS=1,RW=0:写入数据 */
sbit LCD_EN=P3^5;//LCD使能端口,由1变0时液晶模块执行命令
sbit add_A=P0^0;
sbit add_B=P0^1;
sbit add_C=P0^2;//ABC为3为地址输入线，译码出8位通道
/* C为高位
000->Y0=0
001->Y1=0
010->Y2=0
... */
void lcd_init()
{
    LCD_Write_Command(0x38);//功能设置指令6：8位数据，双行显示，5*7字形
    LCD_Write_Command(0x0c);//显示开关控制指令4：开启显示屏，关光标，光标不闪烁
    LCD_Write_Command(0x06);//置输入模式指令3：数据读写后光标右移，画面不移动
    LCD_Write_Command(0x01);//清屏指令1
}

void LCD_Write_Command(uchar com)//写命令函数
{
	LCD_EN=0;
    LCD_RS=0;//选择指令寄存器
    LCD_RW=0;//选择写
    P2=com;//传命令
	delay(5);
    LCD_EN=1;//将使能线置高
    delay(5);//将高电平延时1段时间
    LCD_EN=0;//产生下降沿，让LCD执行命令
/*     根据LCD1602的时序图
    首先:EN=0,RS=0,RW=0,写入(指令或显示地址)
    将数据送到总线上,延时一段时间
    EN=1,开始传(指令或显示地址)
    延时一段时间
    EN=0
    数据传入完成 */
}

void LCD_Write_Value(uchar value)//写数据函数
{
	LCD_EN=0;
    LCD_RS=1;//选择数据寄存器
    LCD_RW=0;//选择写
    P2=value;//传输显示数据
		delay(5);
    LCD_EN=1;//将使能线置高
    delay(5);//将高电平延时1段时间
    LCD_EN=0;//产生下降沿，让LCD执行命令
    /*根据LCD1602的时序图
    首先:EN=0,RS=1,RW=0,向LCD1602写入数据
    将数据送到总线上,延时一段时间
    EN=1,开始传数据
    延时一段时间
    EN=0
    数据传入完成 */
}



