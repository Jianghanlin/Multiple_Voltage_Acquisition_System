#include "lcd_init.h"
#include "lcd_display.h"
#include "ADC.h"
#include "delay.h"
#include "adjust_voltage.h"
#include "define.h"
/*注意宏定义有两种形式
第一种：
#define uchar unsigned char 
结尾没有封号
第二种：
typedef unsigned char uchar;
结尾有封号 */
uchar code selfchar_up[]={0x04,0x0E,0x15,0x04,0x04,0x04,0x04,0x00};//上升箭头
uchar code selfchar_down[]={0x04,0x04,0x04,0x04,0x15,0x0E,0x04,0x00};//下降箭头
uchar code selfchar_clear[]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};//清除箭头
uchar code my_num[]="Xb17610107";
void display_normal()//显示学号
{ 
    uchar j=0;
    LCD_Write_Command(0x46+0x80);//学号从第2行第7个开始显示,显示地址+指针   
    while(my_num[j]!='\0')
    {	
        LCD_Write_Value(my_num[j]);
        j++;
        delay(5);
    }
    LCD_Write_Command(0x00+0x80);//送通道号显示初地址
    LCD_Write_Value(0x5b);//显示[
    LCD_Write_Value(0x43);//显示C
    LCD_Write_Value(0x68);//显示h
    LCD_Write_Value(0x30);//显示0
    LCD_Write_Value(0x30);//显示0
    LCD_Write_Value(0x5d);//显示]

    LCD_Write_Command(0x07+0x80);//送电压显示初地址
    LCD_Write_Value(0x56);//显示V
    LCD_Write_Value(0x6F);//显示o
    LCD_Write_Value(0x6c);//显示l
    LCD_Write_Value(0x3A);//显示:

    LCD_Write_Command(0x0F+0x80);//送电压显示初地址
    LCD_Write_Value(0x56);//显示V
}

void display_channel_Voltage(uchar m)//显示通道和电压
{
    LCD_Write_Command(0x04+0x80);//送通道号显示初地址
    LCD_Write_Value(flag+0x30);//显示0
    LCD_Write_Command(0x0b+0x80);//送电压显示初地址
    switch(m)
    {
        case 0:
            ADC(0);   
            LCD_Write_Value(temp2/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((temp2/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(temp2%10+0x30);//显示第2位小数       
            break;
        case 1:
            ADC(1);
            LCD_Write_Value(temp2/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((temp2/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(temp2%10+0x30);//显示第2位小数       
            break;
        case 2:
            ADC(2);
            LCD_Write_Value(temp2/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((temp2/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(temp2%10+0x30);//显示第2位小数       
            break;
        case 3:
            ADC(3); 
            LCD_Write_Value(temp2/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((temp2/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(temp2%10+0x30);//显示第2位小数        
            break;
        case 4:
            ADC(4);
            LCD_Write_Value(temp2/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((temp2/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(temp2%10+0x30);//显示第2位小数       
            break;
        case 5:
            ADC(5); 
            LCD_Write_Value(temp2/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((temp2/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(temp2%10+0x30);//显示第2位小数       
            break;
        case 6: 
            ADC(6);
            LCD_Write_Value(temp2/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((temp2/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(temp2%10+0x30);//显示第2位小数
            break;
        case 7:
            ADC(7);
            LCD_Write_Value(temp2/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((temp2/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(temp2%10+0x30);//显示第2位小数 
            break;
    }
}

void display_down(uchar p)
{
    switch(p)
    {
        case 0:
            LCD_Write_Value(down0/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((down0/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(down0%10+0x30);//显示第2位小数
            break; 
        case 1:
            LCD_Write_Value(down1/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((down1/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(down1%10+0x30);//显示第2位小数
            break;
        case 2:
            LCD_Write_Value(down2/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((down2/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(down2%10+0x30);//显示第2位小数
            break;
        case 3:
            LCD_Write_Value(down3/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((down3/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(down3%10+0x30);//显示第2位小数
            break;
        case 4:
            LCD_Write_Value(down4/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((down4/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(down4%10+0x30);//显示第2位小数
            break;
        case 5:
            LCD_Write_Value(down5/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((down5/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(down5%10+0x30);//显示第2位小数
            break;
        case 6:
            LCD_Write_Value(down6/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((down6/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(down6%10+0x30);//显示第2位小数
            break;
        case 7:
            LCD_Write_Value(down7/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((down7/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(down7%10+0x30);//显示第2位小数
            break;
    }
}

void display_up(uchar p)
{
    switch(p)
    {
        case 0:
            LCD_Write_Value(up0/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((up0/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(up0%10+0x30);//显示第2位小数
            break; 
        case 1:
            LCD_Write_Value(up1/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((up1/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(up1%10+0x30);//显示第2位小数
            break;
        case 2:
            LCD_Write_Value(up2/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((up2/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(up2%10+0x30);//显示第2位小数
            break;
        case 3:
            LCD_Write_Value(up3/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((up3/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(up3%10+0x30);//显示第2位小数
            break;
        case 4:
            LCD_Write_Value(up4/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((up4/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(up4%10+0x30);//显示第2位小数
            break;
        case 5:
            LCD_Write_Value(up5/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((up5/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(up5%10+0x30);//显示第2位小数
            break;
        case 6:
            LCD_Write_Value(up6/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((up6/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(up6%10+0x30);//显示第2位小数
            break;
        case 7:
            LCD_Write_Value(up7/100+0x30);//显示最高位
            LCD_Write_Value(0x2E);//显示小数点
            LCD_Write_Value((up7/10)%10+0x30);//显示第1位小数
            LCD_Write_Value(up7%10+0x30);//显示第2位小数
            break;
    }
}

void display_adjust(char s)//显示调节后上下限电压的内容，s用来选择显示上限电压还是下限电压
{
    uchar m;
    LCD_Write_Command(0x40);//设定CGRAM地址，把自定义字符存储进去
    switch(s)
    {
        case -1:
        for(m=0;m<8;m++) //将selfchar_down[]中的数据依次写入CGRAM的8位里
        {
            LCD_Write_Value(selfchar_down[m]);
            delay(5);
        }
        LCD_Write_Command(0x40+0x80);    
        LCD_Write_Value(0x00);//显示自定义字符的位置
        display_down(flag);//显示对应通道的下限电压
        break;
        
        case 1:
        for(m=0;m<8;m++) //将selfchar_up[]中的数据依次写入CGRAM的8位里
        {
            LCD_Write_Value(selfchar_up[m]);
            delay(5);
        }
        LCD_Write_Command(0x40+0x80);    
        LCD_Write_Value(0x00);//显示自定义字符的位置
        display_up(flag);//显示对应通道的上限电压
        break;

        case 0:
        for(m=0;m<8;m++) //将selfchar_clear[]中的数据依次写入CGRAM的8位里
        {
            LCD_Write_Value(selfchar_clear[m]);
            delay(5);
        }
        LCD_Write_Command(0x40+0x80);//长时间不按，消隐
        LCD_Write_Value(0x20);
        LCD_Write_Value(0x20);
        LCD_Write_Value(0x20);
        LCD_Write_Value(0x20);
        LCD_Write_Value(0x20);
        break;                
    }
}


