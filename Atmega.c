/*
 * GccApplication2.c
 *
 * Created: 2024-11-18 오후 5:39:36
 * Author : competitor
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

void Putch0(char data)
{
	while(!(UCSR1A & 0x20));
	UDR1 = data;
}

void sendString(const char* str) {
	while (*str) {
		Putch0(*str++);
	}
}

int main(void)
{
    DDRA = 0xff;
	DDRD = 0x0f;
	UCSR1B = 0b00011000;
	UCSR1C = 0b00000110;
	UBRR1H = 0;
	UBRR1L = 103;
    while (1) 
    {
		sendString("\nLEDON\r");
		_delay_ms(3000);
		sendString("\nLEDOFF\r");
		_delay_ms(3000);
    }
}

