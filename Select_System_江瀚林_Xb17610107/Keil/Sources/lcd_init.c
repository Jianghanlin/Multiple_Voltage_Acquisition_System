#include <reg52.h>
#include "lcd_init.h"
#include "delay.h"
#include "define.h"
sbit LCD_RS=P3^7;//RSΪ�Ĵ���ѡ������,1���ݼĴ���,0ָ��Ĵ���
sbit LCD_RW=P3^6;//��д�ź���,1������,0д����
/* 
RS=0,RW=0:д��(ָ�����ʾ��ַ)
RS=0,RW=1:��æ�ź�
RS=1,RW=0:д������ */
sbit LCD_EN=P3^5;//LCDʹ�ܶ˿�,��1��0ʱҺ��ģ��ִ������
sbit add_A=P0^0;
sbit add_B=P0^1;
sbit add_C=P0^2;//ABCΪ3Ϊ��ַ�����ߣ������8λͨ��
/* CΪ��λ
000->Y0=0
001->Y1=0
010->Y2=0
... */
void lcd_init()
{
    LCD_Write_Command(0x38);//��������ָ��6��8λ���ݣ�˫����ʾ��5*7����
    LCD_Write_Command(0x0c);//��ʾ���ؿ���ָ��4��������ʾ�����ع�꣬��겻��˸
    LCD_Write_Command(0x06);//������ģʽָ��3�����ݶ�д�������ƣ����治�ƶ�
    LCD_Write_Command(0x01);//����ָ��1
}

void LCD_Write_Command(uchar com)//д�����
{
	LCD_EN=0;
    LCD_RS=0;//ѡ��ָ��Ĵ���
    LCD_RW=0;//ѡ��д
    P2=com;//������
	delay(5);
    LCD_EN=1;//��ʹ�����ø�
    delay(5);//���ߵ�ƽ��ʱ1��ʱ��
    LCD_EN=0;//�����½��أ���LCDִ������
/*     ����LCD1602��ʱ��ͼ
    ����:EN=0,RS=0,RW=0,д��(ָ�����ʾ��ַ)
    �������͵�������,��ʱһ��ʱ��
    EN=1,��ʼ��(ָ�����ʾ��ַ)
    ��ʱһ��ʱ��
    EN=0
    ���ݴ������ */
}

void LCD_Write_Value(uchar value)//д���ݺ���
{
	LCD_EN=0;
    LCD_RS=1;//ѡ�����ݼĴ���
    LCD_RW=0;//ѡ��д
    P2=value;//������ʾ����
		delay(5);
    LCD_EN=1;//��ʹ�����ø�
    delay(5);//���ߵ�ƽ��ʱ1��ʱ��
    LCD_EN=0;//�����½��أ���LCDִ������
    /*����LCD1602��ʱ��ͼ
    ����:EN=0,RS=1,RW=0,��LCD1602д������
    �������͵�������,��ʱһ��ʱ��
    EN=1,��ʼ������
    ��ʱһ��ʱ��
    EN=0
    ���ݴ������ */
}



