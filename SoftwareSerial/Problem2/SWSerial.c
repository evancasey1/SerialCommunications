/*
 * SWSerial.c
 *
 * Created: 1/31/2019 3:06:34 PM
 *  Author: caseyem
 */ 

#include "SWSerial.h"

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