#include "delay.h"
#include "define.h"
void delay(uint n)//��λ1ms
{
       unsigned int i,j; 
       for(i=0;i<n;i++)
        for(j=0;j<113;j++);
}