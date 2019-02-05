/*
 * problem3.c
 *
 * Created: 2/5/2019 12:30:00 AM
 * Author : Ben
 */ 

#include <avr/io.h>
#include "SWSerial.h"
#include "EmSys.h"

char sw_serial_getc();

int main(void) {
	long baudrate = 9600L;  // initially--can change after this works
	int tx_pin = 12;
	int rx_pin = 11;  // for example
	int framing = SERIAL_8N1;
	
	DDRE = DDRE & 0xFE;
	DDRB |= (1 << PB6);
		
	init_sw_serial(rx_pin, tx_pin, baudrate, framing);  // this is your function
	init_sw_serial_getc_test(baudrate, framing);   // library function: note we need the baudrate and framing here

	debug_init();
	sw_serial_getc();  // throw away first char
	while(1) {
		char c = sw_serial_getc();
		// convert any alpha char c to opposite case
		// you'll need a little code here to do this...
		sw_serial_putc(c);
		test_sw_serial_getc();   // library test function
	}
}