#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "demo.h"
#include "timer.h"
#include "lv_app.h"
#include "touch.h"



int main(void)
{

	HAL_Init();                     //��ʼ��HAL��   
	Stm32_Clock_Init(360,25,2,8);   //����ʱ��,180Mhz
	delay_init(180);                //��ʼ����ʱ����
	uart_init(115200);              //��ʼ��USART
	LED_Init();                     //��ʼ��LED 
	LCD_Init();	                    //��ʼ��LCD 
	tp_dev.init();
	TIM3_Init(100-1,9000-1);       //��ʱ10ms//��ʱ500ms / 50 = 10ms   5000/50 = 100    ��ʱ10ms
	
	lv_init(); 
	     
	my_lv_display_init();
	my_lv_touchpad_init();
	
	   
	
	demo_create();
	
	
	while(1)
	{
		lv_task_handler();
//		printf("ababab\n");
		tp_dev.scan(0);
//		delay_ms(10);
	}
}
