#include "header.h"
void adc_init(void){								//Internal ADC Initialization
	PINSEL1|=0X1540000;
	ADCR=0X00200400;
}

short int adc_read(char ch_num){		// Internal ADC Function
	short int result=0;
	ADCR|=(1<<ch_num);
	ADCR|=(1<<24);
	while(((ADDR>>31)&1)==0);
	ADCR^=(1<<24);
	ADCR^=(1<<ch_num);
	result=(ADDR>>6)&0x3FF;
	return result;
}
