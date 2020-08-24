#include <reg52.h>
#include "ADC.h"
#include "delay.h"
#include "define.h"
sbit add_A=P0^0;
sbit add_B=P0^1;
sbit add_C=P0^2;//ABCΪ3Ϊ��ַ�����ߣ������8λͨ��
sbit START_ALE=P0^3;//��ַ���棬����CBA��ַ
sbit OE=P0^4;//ת�����������ʹ��
sbit EOC=P0^5;//�Ƿ�ת����ɣ�0��æ��1ת���ɹ�
float temp1=0;//temp1������ȡת�����16����
uint temp2=0;//������������100���temp1
void ADC(uchar n)
{
    char i;
    switch(n)
    {
        case 0:
        temp1=0;//����5����ƽ��ֵ��������Ҫ��λ
        for(i=5;i>0;i--)
        {
            START_ALE=0;
            OE=0;
            select_channel(0);//ѡ��ͨ��0����ת��
            START_ALE=1;
            delay(5);
            START_ALE=0;
            delay(5);//�ȴ�ADת�����
            while(EOC==1)  
            {
                P1=0xff;//������֮ǰ��P1�ڵĵ�ѹ�ø�
                OE=1;
                temp1=temp1+P1/51.0;//��ת�����16����׼���ɵ�ѹ
                delay(5);
                OE=0;
                break;
            }              
        }
        temp2=(temp1/5.0)*100;
        break;
        case 1:
			  temp1=0;//����5����ƽ��ֵ��������Ҫ��λ
        for(i=5;i>0;i--)
				{
					START_ALE=0;
					OE=0;
					select_channel(1);//ѡ��ͨ��1����ת��
					START_ALE=1;
					delay(5);
					START_ALE=0;
					delay(5);//�ȴ�ADת�����
					while(EOC==1)  
					{
							P1=0xff;//������֮ǰ��P1�ڵĵ�ѹ�ø�
							OE=1;
                temp1=temp1+P1/51.0;//��ת�����16����׼���ɵ�ѹ
							delay(5);
							OE=0;
							break;
					}				
				}
				temp2=(temp1/5.0)*100;
        break;
        case 2:
        temp1=0;//����5����ƽ��ֵ��������Ҫ��λ
        for(i=5;i>0;i--)
				{
					START_ALE=0;
					OE=0;//��ֹת���������
					select_channel(2);//ѡ��ͨ��2����ת��
					START_ALE=1;
					delay(5);
					START_ALE=0;//�½����źţ�ת����ʼ
					delay(5);//�ȴ�ADת�����
					while(EOC==1)//ͨ�����EOC�ж�ת��ʱ�����
					{
							P1=0xff;//������֮ǰ��P1�ڵĵ�ѹ�øߣ��������
							OE=1;//���������
                temp1=temp1+P1/51.0;//��ת�����16����׼���ɵ�ѹ
                delay(5);
							OE=0;
							break;
					}			
				}
				temp2=(temp1/5.0)*100;
        break;
        case 3:
        temp1=0;//����5����ƽ��ֵ��������Ҫ��λ
        for(i=5;i>0;i--)
        {
					START_ALE=0;
					OE=0;
					select_channel(3);//ѡ��ͨ��3����ת��
					START_ALE=1;
					delay(5);
					START_ALE=0;
					delay(5);//�ȴ�ADת�����
					while(EOC==1)  
					{
							P1=0xff;//������֮ǰ��P1�ڵĵ�ѹ�ø�
							OE=1;
                temp1=temp1+P1/51.0;//��ת�����16����׼���ɵ�ѹ
                delay(5);
							OE=0;
							break;
					}								
				}
				temp2=(temp1/5.0)*100;
        break;
        case 4:
				temp1=0;//����5����ƽ��ֵ��������Ҫ��λ
        for(i=5;i>0;i--)
				{
					START_ALE=0;
					OE=0;
					select_channel(4);//ѡ��ͨ��4����ת��
					START_ALE=1;
					delay(5);
					START_ALE=0;
					delay(5);//�ȴ�ADת�����
					while(EOC==1)  
					{
							P1=0xff;//������֮ǰ��P1�ڵĵ�ѹ�ø�
							OE=1;
                temp1=temp1+P1/51.0;//��ת�����16����׼���ɵ�ѹ
                delay(5);
							OE=0;
							break;
					}				
				}
				temp2=(temp1/5.0)*100;
        break;
        case 5:
				temp1=0;//����5����ƽ��ֵ��������Ҫ��λ
        for(i=5;i>0;i--)				
				{
					START_ALE=0;
					OE=0;
					select_channel(5);//ѡ��ͨ��5����ת��
					START_ALE=1;
					delay(5);
					START_ALE=0;
					delay(5);//�ȴ�ADת�����
					while(EOC==1)  
					{
							P1=0xff;//������֮ǰ��P1�ڵĵ�ѹ�ø�
							OE=1;
                temp1=temp1+P1/51.0;//��ת�����16����׼���ɵ�ѹ
                delay(5);
							OE=0;
							break;
					}				
				}
				temp2=(temp1/5.0)*100;
        break;
        case 6:
				temp1=0;//����5����ƽ��ֵ��������Ҫ��λ
        for(i=5;i>0;i--)	
				{
					START_ALE=0;
					OE=0;
					select_channel(6);//ѡ��ͨ��6����ת��
					START_ALE=1;
					delay(5);
					START_ALE=0;
					delay(5);//�ȴ�ADת�����
					while(EOC==1)  
					{
							P1=0xff;//������֮ǰ��P1�ڵĵ�ѹ�ø�
							OE=1;
                temp1=temp1+P1/51.0;//��ת�����16����׼���ɵ�ѹ
                delay(5);
							OE=0;
							break;
					}				
				}
				temp2=(temp1/5.0)*100;
        break;
        case 7:
        temp1=0;//����5����ƽ��ֵ��������Ҫ��λ
        for(i=5;i>0;i--)
				{
					START_ALE=0;
					OE=0;
					select_channel(7);//ѡ��ͨ��7����ת��
					START_ALE=1;
					delay(5);
					START_ALE=0;
					delay(5);//�ȴ�ADת�����
					while(EOC==1)  
					{
							P1=0xff;//������֮ǰ��P1�ڵĵ�ѹ�ø�
							OE=1;
                temp1=temp1+P1/51.0;//��ת�����16����׼���ɵ�ѹ
                delay(5);
							OE=0;
							break;
					}				
				}
				temp2=(temp1/5.0)*100;
        break;
    }
}

void select_channel(uchar n)//ͨ��ѡ����
{
    switch(n)
    {
        case 0: add_C=0; add_B=0; add_A=0; break;//����ͨ��0
        case 1: add_C=0; add_B=0; add_A=1; break;//����ͨ��1
        case 2: add_C=0; add_B=1; add_A=0; break;//����ͨ��2
        case 3: add_C=0; add_B=1; add_A=1; break;//����ͨ��3
        case 4: add_C=1; add_B=0; add_A=0; break;//����ͨ��4
        case 5: add_C=1; add_B=0; add_A=1; break;//����ͨ��5
        case 6: add_C=1; add_B=1; add_A=0; break;//����ͨ��6
        case 7: add_C=1; add_B=1; add_A=1; break;//����ͨ��7
    }
} 