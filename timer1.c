#include "header.h"
int c,a;
void timer_init(){
unsigned int a[]={15,60,30,15};
unsigned int r=(a[VPBDIV]*1000)-1;
T1PC=0;
T1PR=(r*20);
T1TC=0;
T1TCR=1;
}

