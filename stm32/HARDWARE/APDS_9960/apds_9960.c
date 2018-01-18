#include "apds_9960.h" 
#include "delay.h"
//STM32������
//άǶ�Ƽ�
//
//2017/12/30
//V1.0
//��ʼ��IIC�ӿ�
void APDS9960_Init(void)
{
	IIC_Init();
}
//��APDS9960ָ����ַ����һ������
//ReadAddr:��ʼ�����ĵ�ַ  
//����ֵ  :����������
u8 APDS9960_ReadOneByte(u16 ReadAddr)
{				  
	u8 temp=0;		  	    																 
  IIC_Start();  
  IIC_Send_Byte((0X39)<<1);   //����������ַ0X39,д���� 	 
	IIC_Wait_Ack(); 
  IIC_Send_Byte(ReadAddr);   //���͵͵�ַ
	IIC_Wait_Ack();	    
	IIC_Start();  	 	   
	IIC_Send_Byte(((0X39)<<1)+1);  //�������ģʽ			   
	IIC_Wait_Ack();	 
  temp=IIC_Read_Byte(0);		   
  IIC_Stop();//����һ��ֹͣ����	    
	return temp;
}
//��APDS9960ָ����ַд��һ������
//WriteAddr  :д�����ݵ�Ŀ�ĵ�ַ    
//DataToWrite:Ҫд�������
void APDS9960_WriteOneByte(u16 WriteAddr,u8 DataToWrite)
{				   	  	    																 
  IIC_Start();  
	IIC_Send_Byte((0X39)<<1);   //����������ַ0X39,д���� 	 
	IIC_Wait_Ack();	   
  IIC_Send_Byte(WriteAddr);   //���͵͵�ַ
	IIC_Wait_Ack(); 	 										  		   
	IIC_Send_Byte(DataToWrite);     //�����ֽ�							   
	IIC_Wait_Ack();  		    	   
  IIC_Stop();//����һ��ֹͣ���� 
	delay_ms(10);	 
}
//��APDS9960�����ָ����ַ��ʼд�볤��ΪLen������
//�ú�������д��16bit����32bit������.
//WriteAddr  :��ʼд��ĵ�ַ  
//DataToWrite:���������׵�ַ
//Len        :Ҫд�����ݵĳ���2,4
void APDS9960_WriteLenByte(u16 WriteAddr,u32 DataToWrite,u8 Len)
{  	
	u8 t;
	for(t=0;t<Len;t++)
	{
		APDS9960_WriteOneByte(WriteAddr+t,(DataToWrite>>(8*t))&0xff);
	}												    
}

//��APDS9960�����ָ����ַ��ʼ��������ΪLen������
//�ú������ڶ���16bit����32bit������.
//ReadAddr   :��ʼ�����ĵ�ַ 
//����ֵ     :����
//Len        :Ҫ�������ݵĳ���2,4
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
//���APDS9960�Ƿ�����
//��������24XX�����һ����ַ(255)���洢��־��.
//���������24Cϵ��,�����ַҪ�޸�
//����1:���ʧ��
//����0:���ɹ�
u8 APDS9960_Check(void)
{
	u8 temp;
	temp=APDS9960_ReadOneByte(255);//����ÿ�ο�����дAPDS9960			   
	if(temp==0X55)return 0;		   
	else//�ų���һ�γ�ʼ�������
	{
		APDS9960_WriteOneByte(255,0X55);
	    temp=APDS9960_ReadOneByte(255);	  
		if(temp==0X55)return 0;
	}
	return 1;											  
}

//��APDS9960�����ָ����ַ��ʼ����ָ������������
//ReadAddr :��ʼ�����ĵ�ַ ��24c02Ϊ0~255
//pBuffer  :���������׵�ַ
//NumToRead:Ҫ�������ݵĸ���
void APDS9960_Read(u16 ReadAddr,u8 *pBuffer,u16 NumToRead)
{
	while(NumToRead)
	{
		*pBuffer++=APDS9960_ReadOneByte(ReadAddr++);	
		NumToRead--;
	}
}  
//��APDS9960�����ָ����ַ��ʼд��ָ������������
//WriteAddr :��ʼд��ĵ�ַ
//pBuffer   :���������׵�ַ
//NumToWrite:Ҫд�����ݵĸ���
void APDS9960_Write(u16 WriteAddr,u8 *pBuffer,u16 NumToWrite)
{
	while(NumToWrite--)
	{
		APDS9960_WriteOneByte(WriteAddr,*pBuffer);
		WriteAddr++;
		pBuffer++;
	}
}
 











