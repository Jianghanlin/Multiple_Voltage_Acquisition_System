#include <reg52.h>
#include "ADC.h"
#include "delay.h"
#include "define.h"
sbit add_A=P0^0;
sbit add_B=P0^1;
sbit add_C=P0^2;//ABC为3为地址输入线，译码出8位通道
sbit START_ALE=P0^3;//地址锁存，锁存CBA地址
sbit OE=P0^4;//转换后数据输出使能
sbit EOC=P0^5;//是否转换完成，0正忙，1转换成功
float temp1=0;//temp1用来读取转换后的16进制
uint temp2=0;//用来保存扩大啊100后的temp1
void ADC(uchar n)
{
    char i;
    switch(n)
    {
        case 0:
        temp1=0;//采样5次求平均值，所以需要复位
        for(i=5;i>0;i--)
        {
            START_ALE=0;
            OE=0;
            select_channel(0);//选择通道0进行转化
            START_ALE=1;
            delay(5);
            START_ALE=0;
            delay(5);//等待AD转换完成
            while(EOC==1)  
            {
                P1=0xff;//读数据之前将P1口的电压置高
                OE=1;
                temp1=temp1+P1/51.0;//将转换后的16进制准换成电压
                delay(5);
                OE=0;
                break;
            }              
        }
        temp2=(temp1/5.0)*100;
        break;
        case 1:
			  temp1=0;//采样5次求平均值，所以需要复位
        for(i=5;i>0;i--)
				{
					START_ALE=0;
					OE=0;
					select_channel(1);//选择通道1进行转化
					START_ALE=1;
					delay(5);
					START_ALE=0;
					delay(5);//等待AD转换完成
					while(EOC==1)  
					{
							P1=0xff;//读数据之前将P1口的电压置高
							OE=1;
                temp1=temp1+P1/51.0;//将转换后的16进制准换成电压
							delay(5);
							OE=0;
							break;
					}				
				}
				temp2=(temp1/5.0)*100;
        break;
        case 2:
        temp1=0;//采样5次求平均值，所以需要复位
        for(i=5;i>0;i--)
				{
					START_ALE=0;
					OE=0;//禁止转换数据输出
					select_channel(2);//选择通道2进行转化
					START_ALE=1;
					delay(5);
					START_ALE=0;//下降沿信号，转换开始
					delay(5);//等待AD转换完成
					while(EOC==1)//通过检查EOC判断转换时候完成
					{
							P1=0xff;//读数据之前将P1口的电压置高，避免干扰
							OE=1;//打开数据输出
                temp1=temp1+P1/51.0;//将转换后的16进制准换成电压
                delay(5);
							OE=0;
							break;
					}			
				}
				temp2=(temp1/5.0)*100;
        break;
        case 3:
        temp1=0;//采样5次求平均值，所以需要复位
        for(i=5;i>0;i--)
        {
					START_ALE=0;
					OE=0;
					select_channel(3);//选择通道3进行转化
					START_ALE=1;
					delay(5);
					START_ALE=0;
					delay(5);//等待AD转换完成
					while(EOC==1)  
					{
							P1=0xff;//读数据之前将P1口的电压置高
							OE=1;
                temp1=temp1+P1/51.0;//将转换后的16进制准换成电压
                delay(5);
							OE=0;
							break;
					}								
				}
				temp2=(temp1/5.0)*100;
        break;
        case 4:
				temp1=0;//采样5次求平均值，所以需要复位
        for(i=5;i>0;i--)
				{
					START_ALE=0;
					OE=0;
					select_channel(4);//选择通道4进行转化
					START_ALE=1;
					delay(5);
					START_ALE=0;
					delay(5);//等待AD转换完成
					while(EOC==1)  
					{
							P1=0xff;//读数据之前将P1口的电压置高
							OE=1;
                temp1=temp1+P1/51.0;//将转换后的16进制准换成电压
                delay(5);
							OE=0;
							break;
					}				
				}
				temp2=(temp1/5.0)*100;
        break;
        case 5:
				temp1=0;//采样5次求平均值，所以需要复位
        for(i=5;i>0;i--)				
				{
					START_ALE=0;
					OE=0;
					select_channel(5);//选择通道5进行转化
					START_ALE=1;
					delay(5);
					START_ALE=0;
					delay(5);//等待AD转换完成
					while(EOC==1)  
					{
							P1=0xff;//读数据之前将P1口的电压置高
							OE=1;
                temp1=temp1+P1/51.0;//将转换后的16进制准换成电压
                delay(5);
							OE=0;
							break;
					}				
				}
				temp2=(temp1/5.0)*100;
        break;
        case 6:
				temp1=0;//采样5次求平均值，所以需要复位
        for(i=5;i>0;i--)	
				{
					START_ALE=0;
					OE=0;
					select_channel(6);//选择通道6进行转化
					START_ALE=1;
					delay(5);
					START_ALE=0;
					delay(5);//等待AD转换完成
					while(EOC==1)  
					{
							P1=0xff;//读数据之前将P1口的电压置高
							OE=1;
                temp1=temp1+P1/51.0;//将转换后的16进制准换成电压
                delay(5);
							OE=0;
							break;
					}				
				}
				temp2=(temp1/5.0)*100;
        break;
        case 7:
        temp1=0;//采样5次求平均值，所以需要复位
        for(i=5;i>0;i--)
				{
					START_ALE=0;
					OE=0;
					select_channel(7);//选择通道7进行转化
					START_ALE=1;
					delay(5);
					START_ALE=0;
					delay(5);//等待AD转换完成
					while(EOC==1)  
					{
							P1=0xff;//读数据之前将P1口的电压置高
							OE=1;
                temp1=temp1+P1/51.0;//将转换后的16进制准换成电压
                delay(5);
							OE=0;
							break;
					}				
				}
				temp2=(temp1/5.0)*100;
        break;
    }
}

void select_channel(uchar n)//通道选择函数
{
    switch(n)
    {
        case 0: add_C=0; add_B=0; add_A=0; break;//开启通道0
        case 1: add_C=0; add_B=0; add_A=1; break;//开启通道1
        case 2: add_C=0; add_B=1; add_A=0; break;//开启通道2
        case 3: add_C=0; add_B=1; add_A=1; break;//开启通道3
        case 4: add_C=1; add_B=0; add_A=0; break;//开启通道4
        case 5: add_C=1; add_B=0; add_A=1; break;//开启通道5
        case 6: add_C=1; add_B=1; add_A=0; break;//开启通道6
        case 7: add_C=1; add_B=1; add_A=1; break;//开启通道7
    }
} 