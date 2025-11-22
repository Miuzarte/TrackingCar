#include "timer.h"

void Timer0Init() { // 1ms@11.0592MHz
	TMOD &= 0xF0; //设置定时器模式
	TMOD |= 0x01; //设置定时器模式
	TL0 = 0x66; //设置定时初始值
	TH0 = 0xFC; //设置定时初始值
	TF0 = 0; //清除TF0标志
	TR0 = 1; //定时器0开始计时

	EA = 1;  // 总中断
	ET0 = 1; // timer 0 中断
	PT0 = 0; // timer 0 低优先级
}

// void Timer1Init() { // 250us
// 	TMOD &= 0x0F;			//设置定时器模式
// 	TMOD |= 0x20;			//设置定时器模式
// 	TL1 = 0x1A;				//设置定时初始值
// 	TH1 = 0x1A;				//设置定时重载值
// 	TF1 = 0;				//清除TF1标志
// 	TR1 = 1;				//定时器1开始计时

// 	ET1 = 1;
// 	PT1 = 1; // 高优先级
// }

void Timer1Init() { // 115us 1:4cm
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x20;			//设置定时器模式
	TL1 = 0x96;				//设置定时初始值
	TH1 = 0x96;				//设置定时重载值
	TF1 = 0;				//清除TF1标志
	TR1 = 1;				//定时器1开始计时

	ET1 = 1;
	PT1 = 1; // 高优先级
}
