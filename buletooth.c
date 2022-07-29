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
if(SBUF=='2'){
	l2=0;
}
if(SBUF=='3'){
	l3=0;
}
if(SBUF=='4'){
	l4=0;
}
		
if(SBUF=='5'){
	l1=1;
}
if(SBUF=='6'){
	l2=1;
}
if(SBUF=='7'){
	l3=1;
}
if(SBUF=='8'){
	l4=1;
}	
if(SBUF=='9'){
	l1=0;
	delay(20);
	l1=1;
	delay(20);
	l2=0;
	delay(20);
	l2=1;
	delay(20);
	l3=0;
	delay(20);
	l3=1;
	delay(20);
	l4=0;
	delay(20);
	l4=1;
}	
	
RI = 0;//清除接收中断标志位	
	SBUF = '6';//将接收到的数据放回发送缓存器
	while(!TI);//等待发送数据完成
	TI = 0;//清除发送中断标志位
	
}