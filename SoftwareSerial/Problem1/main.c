/*
 * Problem1.c
 *
 * Created: 1/29/2019 3:01:04 PM
 * Author : caseyem
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "EmSys.h"

void sw_serial_putc(char c);
void delay_usec(unsigned int);

int main(void) {
	// init PORTB so that bit 6 (digital pin 12) is set for OUTPUT
	DDRB |= (1 << PB6);  // Remember that this is the DATA DIRECTION register--use PORTB to set/clear bit 6 output
	init_sw_serial_putc_test(9600,SERIAL_8N1);
	while(1) {
		sw_serial_putc('U');
		test_sw_serial_putc();
		_delay_ms(1000);
	}
}

void sw_serial_putc(char c)
{ 
	// 8N1 at 9600 baud
	// Pin 12
	// 104 and (1/6) microseconds between bits
	PORTB = 0x00;
	delay_usec(104);
	for (int i=0; i < 8; i++) {
		PORTB = ((c >> i) & 0x01) << 0x06;
		delay_usec(104);	
	}
	PORTB = 0x40;
	delay_usec(104);
}
