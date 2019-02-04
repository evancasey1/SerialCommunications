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
static int rx_pin;
static int tx_pin;
static int framing;
static long baudrate;

void delay_usec(unsigned int);

int calculate_delay_time(long baudrate)
{
	return (1.0 / (float) baudrate) * 1000000;
}

int get_portb_bits(int pin_number)
{
	int to_shift;
	switch (pin_number) 
	{
		case 53:
			to_shift = 0;
			break;
		case 52:
			to_shift = 1;
			break;
		case 51:
			to_shift = 2;
			break;
		case 50:
			to_shift = 3;
			break;
		case 10:
			to_shift = 4;
			break;
		case 11:
			to_shift = 5;
			break;
		case 12:
			to_shift = 6;
			break;
		default:
			return -1; 
	}
	
	return 0x01 << to_shift;
}

int get_portb_bit_number(int pin)
{
	int mask = 0x01;
	int counter = 0;
	while ((mask & pin) != 0x01) {
		counter++;
		pin = pin >> 0x01;
	}
	return counter;
}

void init_sw_serial(int _rx_pin, int _tx_pin, long _baudrate, int _framing)
{
	delay_time = calculate_delay_time(_baudrate);
	tx_pin = get_portb_bits(_tx_pin);
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
	
	int tx_bit_num = get_portb_bit_number(tx_pin);
	
	PORTB = 0x00;
	delay_usec(delay_time);
	for (int i=0; i < 8; i++) {
		PORTB = ((c >> i) & 0x01) << tx_bit_num;
		delay_usec(delay_time);
	}
	PORTB = tx_pin; // stop bit
	delay_usec(delay_time);
}