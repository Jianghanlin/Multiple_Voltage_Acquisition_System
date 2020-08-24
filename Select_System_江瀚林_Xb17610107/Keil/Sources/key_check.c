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
    //n�������Ƹտ�ʼ���½����ĸ����棬�ڶ��ΰ����ǶԹ̶������ѹ����,i����������������ʱ��û�仯,���ص��ڽ���
    //j��������ͣ�����ĸ������ϳ�������
    uchar past,key=0;//key�������Ǹ���������
    past=now;
    if(KEY3==0)    {key=3;now=0;}
    else if(KEY4==0)    {key=4;now=0;}
    else    now=1;
    if((past==1)&&(now==0))
    {
        i=0;//���°����Ļ�����ճ�ʱ��δ�����ۼƱ���
        if(n==0)///��һ�ΰ��������е�����һ�����жϽ����Ǹ�����
        {
            if(key==3)  {display_adjust(1);  j=1;}//1�������޵�ѹ���ڽ���
            else if(key==4) {display_adjust(-1);  j=-1;}//-1�������޵�ѹ���ڽ���
            n+=1;            
        }
        else//�ڶ����Ժ�ʼ���ڵ�ѹ
        {
            switch(j)
            {
                case 1://�����޵�ѹ���е���
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
                case -1://�����޵�ѹ���е���
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