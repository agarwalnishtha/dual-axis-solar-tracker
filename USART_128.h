#ifndef USART_128
#define USART_128

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#define New_Line(n) USART_Transmitchar(0x0A,n);\
USART_Transmitchar(0x0D,n);
#define Space(n,x) for(int i=0;i<=n;i++)USART_Transmitchar(0x20,x);

void USART_Init(unsigned int, uint16_t);
void USART_InterruptEnable(uint16_t );
void USART_Transmitchar( unsigned char, uint16_t);
unsigned char USART_Receive(uint16_t);
void USART_TransmitString(char *str, uint16_t);
void USART_TransmitNumber(long int, uint16_t);
//void USART0_TransmitBinary(int);

#endif
