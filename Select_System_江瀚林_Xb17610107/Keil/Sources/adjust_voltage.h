#ifndef _ADJUST_VOLTAGE_H_
#define _ADJUST_VOLTAGE_H_
extern void adjust_up_add(unsigned char p);//调节对应通道上限电压值向上
extern void adjust_up_reduce(unsigned char p);//调节对应通道上限电压值向下
extern void adjust_down_add(unsigned char p);//调节对应通道下限电压值向上
extern void adjust_down_reduce(unsigned char p);//调节对应通道下限电压值向下
extern int down0,down1,down2,down3,down4,down5,down6,down7,up0,up1,up2,up3,up4,up5,up6,up7;
extern unsigned int temp2;
#endif