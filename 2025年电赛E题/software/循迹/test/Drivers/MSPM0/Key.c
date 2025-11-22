#include "Key.h"
#include "Delay.h"
// #include "OLED.h"
#include "oled_hardware_i2c.h"


uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	
	if (DL_GPIO_readPins(KEY1_PORT, KEY1_KEY_1_PIN) == 0)
	{
		Delay_ms(20);
		while (DL_GPIO_readPins(KEY1_PORT, KEY1_KEY_1_PIN) == 0);
		Delay_ms(20);
		KeyNum = 1;
	}
	if (DL_GPIO_readPins(KEY2_PORT, KEY2_KEY_2_PIN) == 0)
	{
		Delay_ms(20);
		while (DL_GPIO_readPins(KEY2_PORT, KEY2_KEY_2_PIN) == 0);
		Delay_ms(20);
		KeyNum = 2;
	}
	if (DL_GPIO_readPins(KEY3_PORT, KEY3_KEY_3_PIN) == 0)
	{
		Delay_ms(20);
		while (DL_GPIO_readPins(KEY3_PORT, KEY3_KEY_3_PIN) == 0);
		Delay_ms(20);
		KeyNum = 3;
	}
	if (DL_GPIO_readPins(KEY4_PORT, KEY4_KEY_4_PIN) == 0)
	{
		Delay_ms(20);
		while (DL_GPIO_readPins(KEY4_PORT, KEY4_KEY_4_PIN) == 0);
		Delay_ms(20);
		KeyNum = 4;
	}
	return KeyNum;
}


// void Menu(uint8_t num)
// {
// 	static uint8_t show_flag=0,point_flag=0,select=0;
	
// 	switch(num)
// 	{
// 		case 1:
//             OLED_Clear();

// 			if(show_flag==0){if(++select>3)select=0;}	
// 			else
// 			{

// 			}

//             OLED_ShowString(1,1,"Data");
//             OLED_ShowString(2,1,"Test");
//             OLED_ShowString(3,1,"Test");
//             OLED_ShowString(4,1,"Test");
//             OLED_ShowString(select+1,8,"<");

// 			break;	
// 		case 2:
//             OLED_Clear();

//             if(point_flag==0)
//             {
//                 if(select==0)
//                 {
//                     OLED_ShowString(1,1,"LeftSpeed:");
//                     OLED_ShowString(2,1,"RightSpeed:");	
//                     OLED_ShowString(3,1,"Gz:");
//                     OLED_ShowString(4,1,"CarStop!");
//                 }
//             }
//             else if(point_flag==1)
//             {
//                 OLED_ShowString(1,1,"LeftSpeed:");
//                 OLED_ShowString(2,1,"RightSpeed:");	
//                 OLED_ShowString(3,1,"Gz:");
//                 if(select==0){if(++Motor.button>1)Motor.button=0;}
//                 if(Motor.button==1)OLED_ShowString(4,1,"CarGo!  ");
//                 else OLED_ShowString(4,1,"CarStop!");
//             }
		
// 			point_flag=1;
// 			show_flag=1;	
// 			break;	
// 		case 3:
//             OLED_Clear();

//             OLED_ShowString(1,1,"Data");
//             OLED_ShowString(2,1,"Test");
//             OLED_ShowString(3,1,"Test");
//             OLED_ShowString(4,1,"Test");
//             OLED_ShowString(select+1,8,"<");

// 			Motor.button=0;
// 			point_flag=0;
// 			show_flag=0;			
// 			break;	
// 	}
// 	if(show_flag)
// 	{
//         if(select==0)
// 		{
// 			// OLED_ShowSignedNum(1,13,Encoder.left,3);
// 			// OLED_ShowSignedNum(2,13,Encoder.right,3);	
// 			// OLED_ShowSignedNum(3,5,Mpu.gz,5);
// 			// OLED_ShowSignedNum(4,3,Motor.track_l,3);
// 			// OLED_ShowSignedNum(4,11,Motor.track_r,3);
			
// 			if(Motor.button==1)
// 			{
// 				Motor.run_speed=10;
//                 Motor.turn_error=0;
// 				// Motor.turn_error=130*(Motor.track_l-Motor.track_r);
// 			}
// 		}
// 	}
// }

// void Menu_Init(void)
// {
//     OLED_ShowString(1,1,"Data");
//     OLED_ShowString(2,1,"Test");
//     OLED_ShowString(3,1,"Test");
//     OLED_ShowString(4,1,"Test");
//     OLED_ShowString(1,8,"<");
// }