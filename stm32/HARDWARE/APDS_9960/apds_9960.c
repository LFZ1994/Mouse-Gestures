#include "apds_9960.h" 
#include "delay.h"
//STM32开发板
//维嵌科技
//
//2017/12/30
//V1.0
//初始化IIC接口
void APDS9960_Init(void)
{
	IIC_Init();
}
//在APDS9960指定地址读出一个数据
//ReadAddr:开始读数的地址  
//返回值  :读到的数据
u8 APDS9960_ReadOneByte(u16 ReadAddr)
{				  
	u8 temp=0;		  	    																 
  IIC_Start();  
  IIC_Send_Byte((0X39)<<1);   //发送器件地址0X39,写数据 	 
	IIC_Wait_Ack(); 
  IIC_Send_Byte(ReadAddr);   //发送低地址
	IIC_Wait_Ack();	    
	IIC_Start();  	 	   
	IIC_Send_Byte(((0X39)<<1)+1);  //进入接收模式			   
	IIC_Wait_Ack();	 
  temp=IIC_Read_Byte(0);		   
  IIC_Stop();//产生一个停止条件	    
	return temp;
}
//在APDS9960指定地址写入一个数据
//WriteAddr  :写入数据的目的地址    
//DataToWrite:要写入的数据
void APDS9960_WriteOneByte(u16 WriteAddr,u8 DataToWrite)
{				   	  	    																 
  IIC_Start();  
	IIC_Send_Byte((0X39)<<1);   //发送器件地址0X39,写数据 	 
	IIC_Wait_Ack();	   
  IIC_Send_Byte(WriteAddr);   //发送低地址
	IIC_Wait_Ack(); 	 										  		   
	IIC_Send_Byte(DataToWrite);     //发送字节							   
	IIC_Wait_Ack();  		    	   
  IIC_Stop();//产生一个停止条件 
	delay_ms(10);	 
}
//在APDS9960里面的指定地址开始写入长度为Len的数据
//该函数用于写入16bit或者32bit的数据.
//WriteAddr  :开始写入的地址  
//DataToWrite:数据数组首地址
//Len        :要写入数据的长度2,4
void APDS9960_WriteLenByte(u16 WriteAddr,u32 DataToWrite,u8 Len)
{  	
	u8 t;
	for(t=0;t<Len;t++)
	{
		APDS9960_WriteOneByte(WriteAddr+t,(DataToWrite>>(8*t))&0xff);
	}												    
}

//在APDS9960里面的指定地址开始读出长度为Len的数据
//该函数用于读出16bit或者32bit的数据.
//ReadAddr   :开始读出的地址 
//返回值     :数据
//Len        :要读出数据的长度2,4
u32 APDS9960_ReadLenByte(u16 ReadAddr,u8 Len)
{  	
	u8 t;
	u32 temp=0;
	for(t=0;t<Len;t++)
	{
		temp<<=8;
		temp+=APDS9960_ReadOneByte(ReadAddr+Len-t-1); 	 				   
	}
	return temp;												    
}
//检查APDS9960是否正常
//这里用了24XX的最后一个地址(255)来存储标志字.
//如果用其他24C系列,这个地址要修改
//返回1:检测失败
//返回0:检测成功
u8 APDS9960_Check(void)
{
	u8 temp;
	temp=APDS9960_ReadOneByte(255);//避免每次开机都写APDS9960			   
	if(temp==0X55)return 0;		   
	else//排除第一次初始化的情况
	{
		APDS9960_WriteOneByte(255,0X55);
	    temp=APDS9960_ReadOneByte(255);	  
		if(temp==0X55)return 0;
	}
	return 1;											  
}

//在APDS9960里面的指定地址开始读出指定个数的数据
//ReadAddr :开始读出的地址 对24c02为0~255
//pBuffer  :数据数组首地址
//NumToRead:要读出数据的个数
void APDS9960_Read(u16 ReadAddr,u8 *pBuffer,u16 NumToRead)
{
	while(NumToRead)
	{
		*pBuffer++=APDS9960_ReadOneByte(ReadAddr++);	
		NumToRead--;
	}
}  
//在APDS9960里面的指定地址开始写入指定个数的数据
//WriteAddr :开始写入的地址
//pBuffer   :数据数组首地址
//NumToWrite:要写入数据的个数
void APDS9960_Write(u16 WriteAddr,u8 *pBuffer,u16 NumToWrite)
{
	while(NumToWrite--)
	{
		APDS9960_WriteOneByte(WriteAddr,*pBuffer);
		WriteAddr++;
		pBuffer++;
	}
}
 











