#include <reg52.h>
#include "led_warning.h"
#include "adjust_voltage.h"
sbit led_en=P0^7;
sbit bee=P0^6;
void led_warn()
{
    switch(flag)
    {
        case 0:
            if((temp2>up0) || (temp2<down0)) 
						{
							led_en=1;
							bee=0;
						}
            //temp2为扩大100倍后的电压值，up0为0通道上限电压，down0为0通道下限电压值
            //led_en=1使能报警LED,并且发声；led_en=0不使能报警LED，不发声
            else 
						{
							led_en=0;
							bee=1;	
						}    
            break;
        case 1:
            if((temp2>up1) || (temp2<down1)) 
						{
							led_en=1;
							bee=0;
						}
            else 
						{
							led_en=0;
							bee=1;	
						}       
            break;
        case 2:
            if((temp2>up2) || (temp2<down2)) 
						{
							led_en=1;
							bee=0;
						}
            else 
						{
							led_en=0;
							bee=1;	
						}        
            break;
        case 3: 
            if((temp2>up3) || (temp2<down3)) 
						{
							led_en=1;
							bee=0;
						}
            else 
						{
							led_en=0;
							bee=1;	
						}  							
            break;
        case 4:
            if((temp2>up4) || (temp2<down4)) 
						{
							led_en=1;
							bee=0;
						}
            else 
						{
							led_en=0;
							bee=1;	
						}  							
            break;
        case 5:
            if((temp2>up5) || (temp2<down5)) 
						{
							led_en=1;
							bee=0;
						}
            else 
						{
							led_en=0;
							bee=1;	
						}  							
            break;
        case 6: 
            if((temp2>up6) || (temp2<down6)) 
						{
							led_en=1;
							bee=0;
						}
            else 
						{
							led_en=0;
							bee=1;	
						}  
            break;
        case 7:
            if((temp2>up7) || (temp2<down7)) 
						{
							led_en=1;
							bee=0;
						}
            else 
						{
							led_en=0;
							bee=1;	
						}  							
            break;
    }    
}