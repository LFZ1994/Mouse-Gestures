#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "key.h"  
#include "apds_9960.h"
#include "apds_9960_deal.h"
#include "myiic.h"
//ALIENTEK Mini STM32�����巶������19
//IICʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
   	
//Ҫд�뵽24c02���ַ�������
const u8 TEXT_Buffer[]={"APDS-99960 TEST"};
#define SIZE sizeof(TEXT_Buffer)	

void adps_9960_setup(void);
void handleGesture(void);
 
 int main(void)
 { 
	u8 proximity_data,x;
	bool i=0;
//u8 datatemp[SIZE];
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ9600
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
	KEY_Init();				//������ʼ��		 	
	APDS9960_Init();			//IIC��ʼ��	
	adps_9960_setup();
	printf("%s\r\n",TEXT_Buffer);
	
	while(1)
	{	
		delay_ms(1);
		if(x==20)
		{
			x=0;
			LED0=APDS9960_INT;
			if(APDS9960_INT==0)
			{
			  handleGesture();
		   //readProximity(&proximity_data);
			}

		}
		x++;		
	}  
 }
 
 void adps_9960_setup()
 {
	 if(APDS9960_deal_init())
	 {
		  printf("APDS-9960 initialization;\r\n");
	 }
//	 if(setProximityGain(PGAIN_2X))
//	 {
//			printf("APDS-9960 PGAIN=8X;\r\n");			
//	 }
//	 if(enableProximitySensor(false))
//	 {	
//			printf("APDS-9960 proximity sensor is running!\r\n");
//	 }
	 if(enableGestureSensor(true))
	 {
		  printf("APDS-9960 gesture sensor is running!\r\n");
	 }
 } 
 
void handleGesture() {
    if (isGestureAvailable() ) {
    switch ( readGesture() ) {
      case DIR_UP:
        printf("UP");
        break;
      case DIR_DOWN:
        printf("DOWN");
        break;
      case DIR_LEFT:
        printf("LEFT");
        break;
      case DIR_RIGHT:
        printf("RIGHT");
        break;
      case DIR_NEAR:
        printf("NEAR");
        break;
      case DIR_FAR:
        printf("FAR");
        break;
      default:
        printf("NONE");
				break;
    }
		printf("\r\n");
  }
}
