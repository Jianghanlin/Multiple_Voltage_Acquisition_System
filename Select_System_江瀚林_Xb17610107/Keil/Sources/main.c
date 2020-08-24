//Desingned by 江瀚林 Xb17610107
//17电子信息工程2019.11.14.江瀚林
#include <reg52.h>
#include "AT89C52_init.h"//集成STC89C52初始化相关函数
#include "lcd_init.h"//集成LCD初始化相关函数
#include "lcd_display.h"//集成LCD显示相关函数
#include "delay.h"//集成延时函数
#include "adjust_voltage.h"//集成电压判断函数
#include "key_check.h"//集成按键检测函数 
#include "led_warning.h"//集成led报警函数
#include "define.h"
#include "my_info.h"

sbit KEY1=P3^2;//前一通道按钮
sbit KEY2=P3^3;//后一通道按钮
sbit led_en=P0^7;//报警led使能引脚

uchar flag=0;//flag用来保存通道序号,由外部中断来更改
//void song();由于换种思维进行LED报警，启用需要取消注释


int main()
{
    led_en=0;//首先不让报警led工作
    lcd_init();//对lcd初始化
    T0_initial();//定时器0初始化
    INT_init();//STC89C52外部中断初始化
    my_info();//显示我的个人信息
    display_normal();//显示固定字段
    while(1)
    {
        KEY_Check();//按键检测，集成上下限电压显示  
        display_channel_Voltage(flag);//显示通道和电压 
    }     
}





//外部中断0的中断函数
void key1() interrupt 0//按键1显示前1通道，递减1 
{
    if(flag==0)  flag=7;//到顶则从7开始
    else flag-=1;        
}

//定时器0溢出中断
void timer0() interrupt 1
{    
    led_warn();
    TH0=0x3C;
    TL0=0x80;//每次进入中断赋初值15536,50ms检测一次
}

//外部中断1的中断函数
void key2() interrupt 2//按键2显示后1通道，递增1
{
    if(flag==7)  flag=0;//到底则从0开始
    else flag+=1;  
}



/* void song() //
{
    bee=1;
    delay(500);
    bee=0;
    delay(50000);
} */




