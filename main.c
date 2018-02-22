/*
 * GccApplication8.c
 *
 * Created: 2/7/2018 11:30:34 PM
 * Author : Raghav Bansal
 */ 
#include <avr/io.h>	
//#define F_CPU 8000000
//#include "USART_128.h"
uint16_t d1=0,d2=0,d3=0,d4=0;	//d1 and d2 for 1 motor and d3 and d4 for the other
uint16_t adc_read(uint8_t channel);
void adc_init(void);
uint8_t direction1 = 0b10000000; //towards d1
uint8_t direction2 = 0b01000000; //towards d2
uint8_t direction3 = 0b00100000; //towards d3
uint8_t direction4 = 0b00010000; //towards d4
uint8_t hault1 = 0b11000000; 
uint8_t hault2 = 0b00110000; 
int reference = 0;
int main(void)
{
	DDRD=0b11111111;
	PORTD=0b00000000;
	//USART_Init(51,0);
	adc_init();
		
 	//	d1=adc_read(0b01000001);
// 		d2=adc_read(0b01000010);
// 		d3=adc_read(0b01000011);
	//USART_TransmitNumber(d0,0);
// 	
// 		USART_TransmitNumber(d1,0);
// 		USART_TransmitNumber(d2,0);
// 		USART_TransmitNumber(d3,0);

	while (1) 
    {
		d1=0;
		d2=0;
		d3=0;
		d4=0;

		d1=adc_read(1);
	//	USART_Transmitchar('a',0);
		//USART_TransmitNumber(d1,0);
		d2=adc_read(2);
		//USART_Transmitchar('b',0);
		//USART_TransmitNumber(d2,0);
		d3=adc_read(3);
		//USART_Transmitchar('c',0);
		//USART_TransmitNumber(d3,0);
		d4=adc_read(4);
		//USART_Transmitchar('d',0);
		//USART_TransmitNumber(d4,0);
			//USART_TransmitNumber(d0,0);
	if(d1-d2>reference)
	{	
		PORTD=direction1;
    }	if(d1-d2<reference)
	{
		PORTD=direction2;
	}
	if(d3-d4>reference)
	{
		PORTD=direction3;
	}
	if(d3-d4<reference)
	{
		PORTD=direction4;
	}
	if(d1==d2)
	{
		PORTD=hault1;
	}
	if(d3==d4)
	{
		PORTD=hault2;
	}
	
}
}
void adc_init(void)
{
	//USART_Transmitchar('r',0);
	ADCSRA|=(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);//|(1<<ADFR);
	ADMUX|=1<<REFS0;//SUPPLY 5V AT AVCC
	ADCSRA|=1<<ADEN;
	ADCSRA|=1<<ADSC;
	//USART_Transmitchar('t',0);
}

uint16_t adc_read(uint8_t channel)
{
	
	ADMUX&=0xF0;
	ADMUX|=channel;																										;
	ADCSRA|=1<<ADSC;
	//USART_Transmitchar('g',0);
	while(ADCSRA&(1<<ADSC));
	//USART_Transmitchar('f',0);
	return ADCW;
}
