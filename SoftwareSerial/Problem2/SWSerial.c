/*
 * SWSerial.c
 *
 * Created: 1/31/2019 3:06:34 PM
 *  Author: caseyem
 */ 

#include <avr/io.h>
#include "SWSerial.h"
#include "EmSys.h"

int calculate_delay_time(long baudrate)
{
	return (1.0 / (float) baudrate) * 1000000;
}

void init_sw_serial(int rx_pin, int tx_pin, long baudrate, int framing)
{
	int delay_time = calculate_delay_time(baudrate);
	
}

void sw_serial_puts(char *str)
{
	// pass
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