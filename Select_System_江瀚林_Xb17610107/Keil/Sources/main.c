//Desingned by ����� Xb17610107
//17������Ϣ����2019.11.14.�����
#include <reg52.h>
#include "AT89C52_init.h"//����STC89C52��ʼ����غ���
#include "lcd_init.h"//����LCD��ʼ����غ���
#include "lcd_display.h"//����LCD��ʾ��غ���
#include "delay.h"//������ʱ����
#include "adjust_voltage.h"//���ɵ�ѹ�жϺ���
#include "key_check.h"//���ɰ�����⺯�� 
#include "led_warning.h"//����led��������
#include "define.h"
#include "my_info.h"

sbit KEY1=P3^2;//ǰһͨ����ť
sbit KEY2=P3^3;//��һͨ����ť
sbit led_en=P0^7;//����ledʹ������

uchar flag=0;//flag��������ͨ�����,���ⲿ�ж�������
//void song();���ڻ���˼ά����LED������������Ҫȡ��ע��


int main()
{
    led_en=0;//���Ȳ��ñ���led����
    lcd_init();//��lcd��ʼ��
    T0_initial();//��ʱ��0��ʼ��
    INT_init();//STC89C52�ⲿ�жϳ�ʼ��
    my_info();//��ʾ�ҵĸ�����Ϣ
    display_normal();//��ʾ�̶��ֶ�
    while(1)
    {
        KEY_Check();//������⣬���������޵�ѹ��ʾ  
        display_channel_Voltage(flag);//��ʾͨ���͵�ѹ 
    }     
}





//�ⲿ�ж�0���жϺ���
void key1() interrupt 0//����1��ʾǰ1ͨ�����ݼ�1 
{
    if(flag==0)  flag=7;//�������7��ʼ
    else flag-=1;        
}

//��ʱ��0����ж�
void timer0() interrupt 1
{    
    led_warn();
    TH0=0x3C;
    TL0=0x80;//ÿ�ν����жϸ���ֵ15536,50ms���һ��
}

//�ⲿ�ж�1���жϺ���
void key2() interrupt 2//����2��ʾ��1ͨ��������1
{
    if(flag==7)  flag=0;//�������0��ʼ
    else flag+=1;  
}



/* void song() //
{
    bee=1;
    delay(500);
    bee=0;
    delay(50000);
} */




