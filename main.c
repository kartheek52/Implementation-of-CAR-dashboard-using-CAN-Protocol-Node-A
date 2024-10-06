#include "header.h"
	short int  s,v;
	float temp,vout,Temparature;
	int speed;
	u32 p,q;
	int speedconv(){			//Function to get speed
		return (adc_read(2)/8);
	}
	
	float tempconv(){			// Function to get temparature
		v=adc_read(1);
		vout=(v*3.3)/1023;
		return ((vout-0.5)/0.01);	
	}
	
int main(){
	int c=0;
	adc_init();			//Internal ADC Initialization
	timer_init();		//TIMER1 initialization
	CAN1_init();		//CAN1 initialization
	while(1){	while(T1TC<1);
	c++;
	speed=speedconv();	//send speed
	timer_init();				//timer reset
	can1(speed);
	if(c==50){
		temp=tempconv();
		p=(int)temp;
		temp=(temp-p);
		q=temp*100;
		can2(p,q);				//send temp
		c=0;
		}
	Temparature=temp+p;
	}
}
