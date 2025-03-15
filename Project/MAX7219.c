#include <REGX52.H>
#include "MAX7219.h"
#include <intrins.h>

/**
 * @brief MAX7219初始化
 * @param 无
 * @retval 无
*/
void Max7219_Init()
{
	unsigned char i;
	for(i=0;i<4;i++)
	{
		Max7219_Write(0x09,0x00);		//译码方式：BCD码
	}
	for(i=0;i<4;i++)
	{
		Max7219_Write(0x0a,0x03);		//亮度 
	}
	for(i=0;i<4;i++)
	{
		Max7219_Write(0x0b,0x07);		//扫描界限；8个数码管显示
	}
	for(i=0;i<4;i++)
	{
		Max7219_Write(0x0c,0x01);		//掉电模式：0，普通模式：1
	}
	for(i=0;i<4;i++)
	{
		Max7219_Write(0x0f,0x00);		//显示测试：1；测试结束，正常显示：0
	}
}

/**
 * @brief MAX7210写入单个数据Byte
 * @param Byte
 * @retval 无
*/
void Max7219_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=8;i>=1;i--)
	{
		CLK = 0;
		DIN = Byte & 0x80;
		Byte <<= 1;
		CLK = 1;
	}
}

/**
 * @brief MAX7219写入一串数据
 * @param add_1
 * @param dat_1
 * @param add_2
 * @param dat_2
 * @retval 无
*/
void Max7219_Write(unsigned char add,unsigned char dat)
{
	CS = 0;
	Max7219_WriteByte(add);
	Max7219_WriteByte(dat);
	_nop_();
	CS = 1;
}	
