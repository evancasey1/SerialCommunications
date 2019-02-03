#include <avr/io.h>
#include <util/delay.h>
#include "EmSys.h"       // This is the test library
#include "SWSerial.h"

void delay_usec(unsigned int);

/*
int main(void) {

	// init rx_pin, tx_pin, baudrate, framing to defaults for now
	static int rx_pin = 11;
	static int tx_pin = 12;
	long baudrate = 9600L;
	int framing = SERIAL_8N1;

	init_sw_serial(rx_pin, tx_pin, baudrate, framing);  // this is your function
	init_sw_serial_puts_test(baudrate, framing);   // library function: note we need the baudrate and framing here

	while(1) {
		sw_serial_puts("Hello,World!\n");
		test_sw_serial_puts();   // library test function
		_delay_ms(1000);
	}
}
*/
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