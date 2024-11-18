#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

void Putch0(char data)
{
	while(!(UCSR1A & 0x20));
	UDR1 = data;
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
		Putch0('\n');
		Putch0('t');
		Putch0('e');
		Putch0('s');
		Putch0('t');
		Putch0('\r');
		_delay_ms(300);
    }
}

