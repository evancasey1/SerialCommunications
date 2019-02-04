#include <avr/io.h>
#include <util/delay.h>
#include "EmSys.h"       // This is the test library
#include "SWSerial.h"

void delay_usec(unsigned int);


int main(void) {

	// init rx_pin, tx_pin, baudrate, framing to defaults for now
	int rx_pin = 19;
	int tx_pin = 12;
	long baudrate = 9600L;
	int framing = SERIAL_8N1;
	
	DDRB |= (1 << PB6);
	
	init_sw_serial(rx_pin, tx_pin, baudrate, framing);  // this is your function
	init_sw_serial_puts_test(baudrate, framing);   // library function: note we need the baudrate and framing here

	while(1) {
		sw_serial_puts("Hello,World!\n");
		test_sw_serial_puts();   // library test function
		_delay_ms(1000);
	}
}
