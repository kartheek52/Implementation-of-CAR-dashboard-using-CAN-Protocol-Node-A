#include "header.h"

#define TCS ((C1GSR>>3)&1)

void CAN1_init(void){			//CAN1 initialization with 60MHZ
VPBDIV=1;
PINSEL1|=0X00040000;
C1MOD=1;
C1BTR=0X001C001D;
AFMR=2;
C1MOD=0;
}

void CAN1_tx(CAN1 v){			//CAN1 Transmit function
	C1TID1=v.id;
	C1TFI1=(v.dlc<<16);
	if(v.rtr==0){
		C1TDA1=v.byteA;
		C1TDB1=v.byteB;
	}else
		C1TFI1|=(1<<30);
		C1CMR=0x21;
		while(TCS==0);
	
}

void can1(int n){				//Function to send speed data
	CAN1 v1;
	v1.id=25;
	v1.dlc=4;
	v1.rtr=0;
	v1.byteA=n;
	v1.byteB=0;
	CAN1_tx(v1);
}

void can2(int n,int m){		//Function to send temparature
	CAN1 v1;
	v1.id=100;
	v1.dlc=8;
	v1.rtr=0;
	v1.byteA=(n&0x00000000FFFFFFFF);
	v1.byteB=(m&0x00000000FFFFFFFF);
	CAN1_tx(v1);
}
