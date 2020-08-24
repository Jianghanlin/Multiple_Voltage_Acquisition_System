#include "adjust_voltage.h"
#include "define.h"
int down0=0,up0=500;//通道0的上下限值
int down1=0,up1=500;//通道1的上下限值
int down2=0,up2=500;//通道2的上下限值
int down3=0,up3=500;//通道3的上下限值
int down4=0,up4=500;//通道4的上下限值
int down5=0,up5=500;//通道5的上下限值
int down6=0,up6=500;//通道6的上下限值
int down7=0,up7=500;//通道7的上下限值
void adjust_up_add(uchar p)//调节对应通道上限电压值向上
{
    switch(p)
    {
        case 0:
            if((up0+10)<=500)    up0+=10; 
            break; 
        case 1:
            if((up1+10)<=500)    up1+=10; 
            break;
        case 2:
            if((up2+10)<=500)    up2+=10; 
            break;
        case 3:
            if((up3+10)<=500)    up3+=10; 
            break;
        case 4:
            if((up4+10)<=500)    up4+=10; 
            break;
        case 5:
            if((up5+10)<=500)    up5+=10; 
            break;
        case 6:
            if((up6+10)<=500)    up6+=10; 
            break;
        case 7:
            if((up7+10)<=500)    up7+=10; 
            break;        
    }
}

void adjust_up_reduce(uchar p)//调节对应通道上限电压值向下
{
    switch(p)
    {
        case 0:
            if(up0>down0+10)    up0-=10;
            break; 
        case 1:
            if(up1>down1+10)    up1-=10;
            break;
        case 2:
            if(up2>down2+10)    up2-=10;
            break;
        case 3:
            if(up3>down3+10)    up3-=10;
            break;
        case 4:
            if(up4>down4+10)    up4-=10;
            break;
        case 5:
            if(up5>down5+10)    up5-=10;
            break;
        case 6:
            if(up6>down6+10)    up6-=10;
            break;
        case 7:
            if(up7>down7+10)    up7-=10;
            break;        
    }
}

void adjust_down_add(uchar p)//调节对应通道下限电压值向上
{
    switch(p)
    {
        case 0:
            if(down0<(up0-10))    down0+=10; 
            break; 
        case 1:
            if(down1<(up1-10))    down1+=10; 
            break;
        case 2:
            if(down2<(up2-10))    down2+=10; 
            break;
        case 3:
            if(down3<(up3-10))    down3+=10; 
            break;
        case 4:
            if(down4<(up4-10))    down4+=10; 
            break;
        case 5:
            if(down5<(up5-10))    down5+=10; 
            break;
        case 6:
            if(down6<(up6-10))    down6+=10; 
            break;
        case 7:
            if(down7<(up7-10))    down7+=10; 
            break;        
    }
}

void adjust_down_reduce(uchar p)//调节对应通道下限电压值向下
{
    switch(p)
    {
        case 0:
            if((down0-10)>=0)    down0-=10; 
            break; 
        case 1:
            if((down1-10)>=0)    down1-=10; 
            break;
        case 2:
            if((down2-10)>=0)    down2-=10; 
            break;
        case 3:
            if((down3-10)>=0)    down3-=10; 
            break;
        case 4:
            if((down4-10)>=0)    down4-=10;
            break;
        case 5:
            if((down5-10)>=0)    down5-=10; 
            break;
        case 6:
            if((down6-10)>=0)    down6-=10; 
            break;
        case 7:
            if((down7-10)>=0)    down7-=10; 
            break;        
    }
}