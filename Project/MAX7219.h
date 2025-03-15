#ifndef __MAX7219_H__
#define __MAX7219_H__

//定义位变量
sbit CLK = P2^2;
sbit CS  = P2^1;
sbit DIN = P2^0;

void Max7219_Init();
void Max7219_WriteByte(unsigned char Data);
void Max7219_Write(unsigned char add,unsigned char dat);

#endif
