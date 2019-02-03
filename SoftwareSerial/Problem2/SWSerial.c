/*
 * SWSerial.c
 *
 * Created: 1/31/2019 3:06:34 PM
 *  Author: caseyem
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "SWSerial.h"
#include "EmSys.h"

static int delay_time;

void delay_usec(unsigned int);

int calculate_delay_time(long baudrate)
{
	return (1.0 / (float) baudrate) * 1000000;
}

int get_portb_bits(int pin_number)
{
	int to_shift = pin_number - 19;
	
	return 1L << to_shift;
}

int get_portb_bit_number(int pin_number)
{
	return pin_number - 19;
}

void init_sw_serial(int rx_pin, int tx_pin, long baudrate, int framing)
{
	delay_time = calculate_delay_time(baudrate);
	tx_pin = get_portb_bits(tx_pin);
	rx_pin = get_portb_bits(rx_pin);
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
	static int rx_pin = 45;
	static int tx_pin = 25;
	int tx_bit_num = get_portb_bit_number(tx_pin);
	long baudrate = 9600;
	
	init_sw_serial(rx_pin, tx_pin, baudrate, SERIAL_8N1);
	PORTB = 0x00;
	delay_usec(delay_time);
	for (int i=0; i < 8; i++) {
		PORTB = ((c >> i) & 0x01) << tx_bit_num;
		delay_usec(delay_time);
	}
	PORTB = get_portb_bits(tx_pin);
	delay_usec(delay_time);
}