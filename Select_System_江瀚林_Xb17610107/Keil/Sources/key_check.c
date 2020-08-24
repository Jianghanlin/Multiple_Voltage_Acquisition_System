#include <reg52.h>
#include "adjust_voltage.h"
#include "lcd_display.h"
#include "key_check.h"
#include "define.h"
sbit KEY3=P3^0;
sbit KEY4=P3^1;

void KEY_Check() 
{
    static unsigned char now=1,n=0,i=0,j=0;
    //n用来控制刚开始按下进入哪个界面，第二次按下是对固定界面电压调节,i的作用是若按键长时间没变化,隐藏调节界面
    //j的作用是停留在哪个界面上持续控制
    uchar past,key=0;//key来区别那个按键按下
    past=now;
    if(KEY3==0)    {key=3;now=0;}
    else if(KEY4==0)    {key=4;now=0;}
    else    now=1;
    if((past==1)&&(now==0))
    {
        i=0;//按下按键的话，清空长时间未操作累计变量
        if(n==0)///第一次按两个键中的任意一个是判断进入那个界面
        {
            if(key==3)  {display_adjust(1);  j=1;}//1进入上限电压调节界面
            else if(key==4) {display_adjust(-1);  j=-1;}//-1进入下限电压调节界面
            n+=1;            
        }
        else//第二次以后开始调节电压
        {
            switch(j)
            {
                case 1://对上限电压进行调节
                    if(key==3)       
                    {   
                        adjust_up_add(flag);   
                        display_adjust(1);
                    }
                    else if(key==4)  
                    { 
                        adjust_up_reduce(flag);
                        display_adjust(1);
                    }
                    break;
                case -1://对下限电压进行调节
                    if(key==3)       
                    {   
                        adjust_down_add(flag);   
                        display_adjust(-1);
                    }
                    else if(key==4)  
                    { 
                        adjust_down_reduce(flag);
                        display_adjust(-1);
                    }            
                    break;
            }
        }    
    }
    else if((past==1)&&(now==1))
    {
        i++;
        if(i==20)  {display_adjust(0); n=0;}
    }   
}