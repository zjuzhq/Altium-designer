/*AUTHOR:郑琪*/
#include "reg52.h"
#include <stdio.h>
#include <math.h>
typedef unsigned int u16;	  
typedef unsigned char u8;
u8 cmd[2]={'0','0'};
u16 num1=0,num2=0,num3=0;
u8 num1_1,num1_2,num1_3,num1_4,num2_1,num2_2,num2_3,num2_4,num3_1,num3_2,num3_3,num3_4;
u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
u8 hour=12,min=0,sec=0;
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit LSD=P2^5;
void delay(u16 i)
{
	while(i--);	
}

void DigDisplay(u16 flag)
{
	u8 i;
	if(flag==1){
		for(i=0;i<3;i++)
		{
			switch(i)
			{
				case(0):
					LSA=0;LSB=0;LSC=0;LSD=0;P0=0x7c; break;//显示第0位
				case(1):
					LSA=1;LSB=0;LSC=0;LSD=0;P0=0x77; break;//显示第1位
				case(2):
					LSA=0;LSB=1;LSC=0;LSD=0;P0=0x5e; break;//显示第2位
			}
			delay(100);
			P0=0x00;
		}
	}
	else if(flag==0){
		num1_4=num1%10;
		num1_3=((num1-num1_4)/10)%10;
		num1_2=((num1-num1_3*10-num1_4)/100)%10;
		num1_1=((num1-num1_2*100-num1_3*10-num1_4)/1000)%10;
		num2_4=num2%10;
		num2_3=((num2-num2_4)/10)%10;
		num2_2=((num2-num2_3*10-num2_4)/100)%10;
		num2_1=((num2-num2_2*100-num2_3*10-num2_4)/1000)%10;
		num3_4=num3%10;
		num3_3=((num3-num3_4)/10)%10;
		num3_2=((num3-num3_3*10-num3_4)/100)%10;
		num3_1=((num3-num3_2*100-num3_3*10-num3_4)/1000)%10;
		for(i=0;i<8;i++)
		{
			switch(i)	 //位选，选择点亮的数码管，
			{
				case(0):
					LSA=0;LSB=0;LSC=0;LSD=0;P0=smgduan[num1_1]; break;//显示第0位
				case(1):
					LSA=1;LSB=0;LSC=0;LSD=0;P0=smgduan[num1_2]; break;//显示第1位
				case(2):
					LSA=0;LSB=1;LSC=0;LSD=0;P0=smgduan[num1_3]; break;//显示第2位
				case(3):
					LSA=1;LSB=1;LSC=0;LSD=0;P0=smgduan[num1_4]; break;//显示第3位
				case(4):
					LSA=0;LSB=0;LSC=1;LSD=0;P0=smgduan[num2_1]; break;//显示第4位
				case(5):
					LSA=1;LSB=0;LSC=1;LSD=0;P0=smgduan[num2_2]; break;//显示第5位	
				case(6):
					LSA=0;LSB=1;LSC=1;LSD=0;P0=smgduan[num2_3]; break;
				case(7):
					LSA=1;LSB=1;LSC=1;LSD=0;P0=smgduan[num2_4]; break;
				case(8):
					LSA=0;LSB=0;LSC=0;LSD=1;P0=smgduan[num3_1]; break;
				case(9):
					LSA=1;LSB=0;LSC=0;LSD=1;P0=smgduan[num3_2]; break;//显示第0位
				case(10):
					LSA=0;LSB=1;LSC=0;LSD=1;P0=smgduan[num3_3]; break;//显示第1位
				case(11):
					LSA=1;LSB=1;LSC=0;LSD=1;P0=smgduan[num3_4]; break;//显示第2位
			}
			delay(100); //间隔一段时间扫描	
			P0=0x00;//消隐
		}		
	}
	else if(flag==2){
		for(i=0;i<8;i++)
		{
			switch(i)	 //位选，选择点亮的数码管，
			{
				case(0):
					LSA=0;LSB=0;LSC=0;LSD=0;P0=smgduan[hour/10]; break;//显示第0位
				case(1):
					LSA=1;LSB=0;LSC=0;LSD=0;P0=smgduan[hour%10]; break;//显示第1位
				case(2):
					LSA=0;LSB=1;LSC=0;LSD=0;P0=0x40; break;//显示第2位
				case(3):
					LSA=1;LSB=1;LSC=0;LSD=0;P0=smgduan[min/10]; break;//显示第3位
				case(4):
					LSA=0;LSB=0;LSC=1;LSD=0;P0=smgduan[min%10]; break;//显示第4位
				case(5):
					LSA=1;LSB=0;LSC=1;LSD=0;P0=0x40; break;//显示第5位	
				case(6):
					LSA=0;LSB=1;LSC=1;LSD=0;P0=smgduan[sec/10]; break;
				case(7):
					LSA=1;LSB=1;LSC=1;LSD=0;P0=smgduan[sec%10]; break;
				case(8):
					LSA=0;LSB=0;LSC=0;LSD=1;P0=smgduan[num3_1]; break;
				case(9):
					LSA=1;LSB=0;LSC=0;LSD=1;P0=smgduan[num3_2]; break;//显示第0位
				case(10):
					LSA=0;LSB=1;LSC=0;LSD=1;P0=smgduan[num3_3]; break;//显示第1位
				case(11):
					LSA=1;LSB=1;LSC=0;LSD=1;P0=smgduan[num3_4]; break;//显示第2位
			}
			delay(100); //间隔一段时间扫描	
			P0=0x00;//消隐
		}
	}		
}

void UsartInit()
{
	SCON=0X50;			
	TMOD=0X20;			
	PCON=0X80;			
	TH1=0XF4;				
	TL1=0XF4;
	ES=1;						
	EA=1;						
	TR1=1;  	
}

void TimerInit()
{
	TMOD=0X21;
	TH0=0X3C;
	TL0=0XB0;
	ET0=1;
	TR0=1;
}
	

u16 isprime(u16 n)
{
	u16 m;
	//m=2;
	for(m=2;m<=sqrt(n);m++){
		if(n%m==0){
			break;
		}
	}
	if(m<=sqrt(n)){
		return 0;
	}
	else{
		return 1;
	}
}

u16 fenjie(u16 num1)
{
	u16 num2;
	for(num2=3;num2<=num1/2;num2++){
		if(isprime(num2)==1 && isprime(num1-num2)==1){
			break;
		}
	}
	return num2;
}

void main()
{	
	u16 k;
	P2=0xff;
	UsartInit();
	while(1){
		if(cmd[0]=='T' && cmd[1]=='M'){
			TimerInit();
			for(k=0;k<60;k++){
				DigDisplay(2);
			}
		}
		if(cmd[0]=='G' && cmd[1]=='O'){
			if(num1%2==1){
				DigDisplay(1);
			}
			else if(5<num1<10000){
				num2=fenjie(num1);
				num3=num1-num2;
					while(1){
						DigDisplay(0);
					}
				}
			}
		if(cmd[0]=='S' && cmd[1]=='T'){
			while(1){
				num2=fenjie(num1);
				num3=num1-num2;
					for(k=0;k<150;k++){
						DigDisplay(0);
					}
				num1+=2;
			}
		}
	}
}

void Usart() interrupt 4
{
	u8 receiveData;
	receiveData=SBUF;
	RI = 0;
	SBUF=receiveData;
	while(!TI);			 
	TI=0;
	if(cmd[0]=='0'){
		cmd[0]=SBUF;
	}
	else if(cmd[1]=='0'){
		cmd[1]=SBUF;
	}
	else if(cmd[1]!='0'){
		num1=10*num1+SBUF-'0';
	}
}

void Timer() interrupt 2
{
	static u8 times=0;
	times+=1;
	//delay(1600);
	if(times==12){
		sec+=1;
		times=0;
	}
	if(sec==60){
		min+=1;
		sec=0;
	}
	if(min==60){
		hour+=1;
		min=0;
	}
	if(hour==24){
		hour=0;
	}
}