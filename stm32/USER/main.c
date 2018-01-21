#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "key.h"  
#include "apds_9960.h"
#include "apds_9960_deal.h"
#include "myiic.h"
//ALIENTEK Mini STM32开发板范例代码19
//IIC实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
   	
//要写入到24c02的字符串数组
const u8 TEXT_Buffer[]={"APDS-99960 TEST"};
#define SIZE sizeof(TEXT_Buffer)	

void adps_9960_setup(void);
void handleGesture(void);
 
 int main(void)
 { 
	u8 proximity_data,x;
	bool i=0;
//u8 datatemp[SIZE];
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	delay_init();	    	 //延时函数初始化	  
	uart_init(115200);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
	KEY_Init();				//按键初始化		 	
	APDS9960_Init();			//IIC初始化	
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
