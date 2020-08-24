#include "lcd_init.h"
#include "lcd_display.h"
#include "ADC.h"
#include "delay.h"
#include "adjust_voltage.h"
#include "define.h"
/*ע��궨����������ʽ
��һ�֣�
#define uchar unsigned char 
��βû�з��
�ڶ��֣�
typedef unsigned char uchar;
��β�з�� */
uchar code selfchar_up[]={0x04,0x0E,0x15,0x04,0x04,0x04,0x04,0x00};//������ͷ
uchar code selfchar_down[]={0x04,0x04,0x04,0x04,0x15,0x0E,0x04,0x00};//�½���ͷ
uchar code selfchar_clear[]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};//�����ͷ
uchar code my_num[]="Xb17610107";
void display_normal()//��ʾѧ��
{ 
    uchar j=0;
    LCD_Write_Command(0x46+0x80);//ѧ�Ŵӵ�2�е�7����ʼ��ʾ,��ʾ��ַ+ָ��   
    while(my_num[j]!='\0')
    {	
        LCD_Write_Value(my_num[j]);
        j++;
        delay(5);
    }
    LCD_Write_Command(0x00+0x80);//��ͨ������ʾ����ַ
    LCD_Write_Value(0x5b);//��ʾ[
    LCD_Write_Value(0x43);//��ʾC
    LCD_Write_Value(0x68);//��ʾh
    LCD_Write_Value(0x30);//��ʾ0
    LCD_Write_Value(0x30);//��ʾ0
    LCD_Write_Value(0x5d);//��ʾ]

    LCD_Write_Command(0x07+0x80);//�͵�ѹ��ʾ����ַ
    LCD_Write_Value(0x56);//��ʾV
    LCD_Write_Value(0x6F);//��ʾo
    LCD_Write_Value(0x6c);//��ʾl
    LCD_Write_Value(0x3A);//��ʾ:

    LCD_Write_Command(0x0F+0x80);//�͵�ѹ��ʾ����ַ
    LCD_Write_Value(0x56);//��ʾV
}

void display_channel_Voltage(uchar m)//��ʾͨ���͵�ѹ
{
    LCD_Write_Command(0x04+0x80);//��ͨ������ʾ����ַ
    LCD_Write_Value(flag+0x30);//��ʾ0
    LCD_Write_Command(0x0b+0x80);//�͵�ѹ��ʾ����ַ
    switch(m)
    {
        case 0:
            ADC(0);   
            LCD_Write_Value(temp2/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((temp2/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(temp2%10+0x30);//��ʾ��2λС��       
            break;
        case 1:
            ADC(1);
            LCD_Write_Value(temp2/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((temp2/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(temp2%10+0x30);//��ʾ��2λС��       
            break;
        case 2:
            ADC(2);
            LCD_Write_Value(temp2/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((temp2/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(temp2%10+0x30);//��ʾ��2λС��       
            break;
        case 3:
            ADC(3); 
            LCD_Write_Value(temp2/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((temp2/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(temp2%10+0x30);//��ʾ��2λС��        
            break;
        case 4:
            ADC(4);
            LCD_Write_Value(temp2/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((temp2/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(temp2%10+0x30);//��ʾ��2λС��       
            break;
        case 5:
            ADC(5); 
            LCD_Write_Value(temp2/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((temp2/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(temp2%10+0x30);//��ʾ��2λС��       
            break;
        case 6: 
            ADC(6);
            LCD_Write_Value(temp2/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((temp2/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(temp2%10+0x30);//��ʾ��2λС��
            break;
        case 7:
            ADC(7);
            LCD_Write_Value(temp2/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((temp2/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(temp2%10+0x30);//��ʾ��2λС�� 
            break;
    }
}

void display_down(uchar p)
{
    switch(p)
    {
        case 0:
            LCD_Write_Value(down0/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((down0/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(down0%10+0x30);//��ʾ��2λС��
            break; 
        case 1:
            LCD_Write_Value(down1/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((down1/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(down1%10+0x30);//��ʾ��2λС��
            break;
        case 2:
            LCD_Write_Value(down2/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((down2/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(down2%10+0x30);//��ʾ��2λС��
            break;
        case 3:
            LCD_Write_Value(down3/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((down3/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(down3%10+0x30);//��ʾ��2λС��
            break;
        case 4:
            LCD_Write_Value(down4/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((down4/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(down4%10+0x30);//��ʾ��2λС��
            break;
        case 5:
            LCD_Write_Value(down5/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((down5/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(down5%10+0x30);//��ʾ��2λС��
            break;
        case 6:
            LCD_Write_Value(down6/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((down6/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(down6%10+0x30);//��ʾ��2λС��
            break;
        case 7:
            LCD_Write_Value(down7/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((down7/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(down7%10+0x30);//��ʾ��2λС��
            break;
    }
}

void display_up(uchar p)
{
    switch(p)
    {
        case 0:
            LCD_Write_Value(up0/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((up0/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(up0%10+0x30);//��ʾ��2λС��
            break; 
        case 1:
            LCD_Write_Value(up1/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((up1/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(up1%10+0x30);//��ʾ��2λС��
            break;
        case 2:
            LCD_Write_Value(up2/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((up2/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(up2%10+0x30);//��ʾ��2λС��
            break;
        case 3:
            LCD_Write_Value(up3/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((up3/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(up3%10+0x30);//��ʾ��2λС��
            break;
        case 4:
            LCD_Write_Value(up4/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((up4/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(up4%10+0x30);//��ʾ��2λС��
            break;
        case 5:
            LCD_Write_Value(up5/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((up5/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(up5%10+0x30);//��ʾ��2λС��
            break;
        case 6:
            LCD_Write_Value(up6/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((up6/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(up6%10+0x30);//��ʾ��2λС��
            break;
        case 7:
            LCD_Write_Value(up7/100+0x30);//��ʾ���λ
            LCD_Write_Value(0x2E);//��ʾС����
            LCD_Write_Value((up7/10)%10+0x30);//��ʾ��1λС��
            LCD_Write_Value(up7%10+0x30);//��ʾ��2λС��
            break;
    }
}

void display_adjust(char s)//��ʾ���ں������޵�ѹ�����ݣ�s����ѡ����ʾ���޵�ѹ�������޵�ѹ
{
    uchar m;
    LCD_Write_Command(0x40);//�趨CGRAM��ַ�����Զ����ַ��洢��ȥ
    switch(s)
    {
        case -1:
        for(m=0;m<8;m++) //��selfchar_down[]�е���������д��CGRAM��8λ��
        {
            LCD_Write_Value(selfchar_down[m]);
            delay(5);
        }
        LCD_Write_Command(0x40+0x80);    
        LCD_Write_Value(0x00);//��ʾ�Զ����ַ���λ��
        display_down(flag);//��ʾ��Ӧͨ�������޵�ѹ
        break;
        
        case 1:
        for(m=0;m<8;m++) //��selfchar_up[]�е���������д��CGRAM��8λ��
        {
            LCD_Write_Value(selfchar_up[m]);
            delay(5);
        }
        LCD_Write_Command(0x40+0x80);    
        LCD_Write_Value(0x00);//��ʾ�Զ����ַ���λ��
        display_up(flag);//��ʾ��Ӧͨ�������޵�ѹ
        break;

        case 0:
        for(m=0;m<8;m++) //��selfchar_clear[]�е���������д��CGRAM��8λ��
        {
            LCD_Write_Value(selfchar_clear[m]);
            delay(5);
        }
        LCD_Write_Command(0x40+0x80);//��ʱ�䲻��������
        LCD_Write_Value(0x20);
        LCD_Write_Value(0x20);
        LCD_Write_Value(0x20);
        LCD_Write_Value(0x20);
        LCD_Write_Value(0x20);
        break;                
    }
}


