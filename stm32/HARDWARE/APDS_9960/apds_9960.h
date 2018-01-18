#ifndef __APDS9960_H
#define __APDS9960_H

#include "myiic.h"   
//STM32������
//άǶ�Ƽ�
//
//2017/12/30
//V1.0

					  
u8   APDS9960_ReadOneByte(u16 ReadAddr);							//ָ����ַ��ȡһ���ֽ�
void APDS9960_WriteOneByte(u16 WriteAddr,u8 DataToWrite);		//ָ����ַд��һ���ֽ�
void APDS9960_WriteLenByte(u16 WriteAddr,u32 DataToWrite,u8 Len);//ָ����ַ��ʼд��ָ�����ȵ�����
u32  APDS9960_ReadLenByte(u16 ReadAddr,u8 Len);					//ָ����ַ��ʼ��ȡָ����������
void APDS9960_Write(u16 WriteAddr,u8 *pBuffer,u16 NumToWrite);	//��ָ����ַ��ʼд��ָ�����ȵ�����
void APDS9960_Read(u16 ReadAddr,u8 *pBuffer,u16 NumToRead);   	//��ָ����ַ��ʼ����ָ�����ȵ�����

u8   APDS9960_Check(void);  //�������
void APDS9960_Init(void); //��ʼ��IIC

#endif
















