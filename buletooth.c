#include ".\CORE\STC8Ax_REG.H"
void UartInit(void)		//9600bps@11.0592MHz
{
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x40;		//��ʱ��ʱ��1Tģʽ
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TL1 = 0xE0;		//���ö�ʱ��ʼֵ
	TH1 = 0xFE;		//���ö�ʱ��ʼֵ
	ET1 = 0;		//��ֹ��ʱ��%d�ж�
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
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
	
RI = 0;//��������жϱ�־λ	
	SBUF = '6';//�����յ������ݷŻط��ͻ�����
	while(!TI);//�ȴ������������
	TI = 0;//��������жϱ�־λ
	
}