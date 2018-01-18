#ifndef __APDS9960_H
#define __APDS9960_H

#include "myiic.h"   
//STM32开发板
//维嵌科技
//
//2017/12/30
//V1.0

					  
u8   APDS9960_ReadOneByte(u16 ReadAddr);							//指定地址读取一个字节
void APDS9960_WriteOneByte(u16 WriteAddr,u8 DataToWrite);		//指定地址写入一个字节
void APDS9960_WriteLenByte(u16 WriteAddr,u32 DataToWrite,u8 Len);//指定地址开始写入指定长度的数据
u32  APDS9960_ReadLenByte(u16 ReadAddr,u8 Len);					//指定地址开始读取指定长度数据
void APDS9960_Write(u16 WriteAddr,u8 *pBuffer,u16 NumToWrite);	//从指定地址开始写入指定长度的数据
void APDS9960_Read(u16 ReadAddr,u8 *pBuffer,u16 NumToRead);   	//从指定地址开始读出指定长度的数据

u8   APDS9960_Check(void);  //检查器件
void APDS9960_Init(void); //初始化IIC

#endif
















