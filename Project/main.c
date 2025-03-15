#include <REGX52.H>
#include "Delay.h"
#include "MAX7219.h"
#include "UART.h"
#include "segment_location.h"
#include <intrins.h>

void main()
{
	Max7219_Init();
	Uart_Init();
	while(1)
	{
		unsigned char x,y,z;
		for(x=0;x<8;x++)
		{
			CS = 0;
			for(y=0;y<4;y++)
			{
				z = x + 1;
				Max7219_WriteByte(z);
				Max7219_WriteByte(setdata[y][x]);
				_nop_();
			}
			CS = 1;
		}
	}
}

void Uart_IN(void) interrupt 4
{
	unsigned int i,j,k,u;
	unsigned char _data;
	unsigned char rec_data[32];
	if(RI==1)
	{
		rec_data[j]=SBUF;
		++j;
		if(j==32)
		{
			i = 0;
			for(k=0;k<4;k++)
			{
				for(u=0;u<8;u++)
				{
					setdata[k][u] = rec_data[i];
					i++;
				}
			}
			for(u=0;u<8;u++)
			{
				_data = setdata[1][u];
				setdata[1][u] = setdata[2][u];
				setdata[2][u] = _data;
			}
			j=0;
			//SBUF = 0x4C;		//测试	
			
		}
		RI=0;
	}
}
