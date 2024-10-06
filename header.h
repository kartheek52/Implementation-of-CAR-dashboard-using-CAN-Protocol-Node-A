#include<lpc21xx.h>
void timer_init(void);
typedef int s32;
typedef unsigned int u32;
typedef char s8;
typedef unsigned char u8;

void delay_sec(unsigned int);
void delay_ms(unsigned int);

void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_init(void);
void lcd_integer(int);
void lcd_string(char *);

//void uart0_init(u32 baud);
//void uart0_tx(u8 data);
//u8 uart0_rx(void);
//void uart0_rx_string(s8 *ptr,s32 len);
//void uart0_tx_integer(int num);
//void uart0_tx_float(float num);
//void uart0_tx_string(s8 *ptr);

short int adc_read(char ch_num);
void adc_init(void);

typedef struct CAN1_Frame{			//CAN structure
	u32 id;
	u32 dlc;
	u32 rtr;
	u32 byteA;
	u32 byteB;
}CAN1;

void CAN1_init(void);
void CAN1_tx(CAN1 v);
void can1(int n);
void can2(int n,int m);
