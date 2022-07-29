#include ".\CORE\STC8Ax_REG.H"
void UartInit(void)		//9600bps@11.0592MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器时钟1T模式
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0xE0;		//设置定时初始值
	TH1 = 0xFE;		//设置定时初始值
	ET1 = 0;		//禁止定时器%d中断
	TR1 = 1;		//定时器1开始计时
}
void send(char dat){
SBUF=dat;
while(!TI){
	TI=0;
}
}
void delay(int ms){
	int i=0,j=0;
	for (i=0;i<5000;i++){
		for (j=0;j<ms;j++);
	}
}

sbit l1=P0^4;
sbit l2=P0^5;
sbit l3=P0^6;
sbit l4=P0^7;
sbit k1=P5^1;
int flag=1;
void main(){
	
	P_SW1 &=0x0f;
	P_SW1 |=0x00;
	P0M0=0;
	P0M1=0;

	UartInit();

if(SBUF=='1'){
	l1=0;
}

}
