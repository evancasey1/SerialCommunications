#include <avr/io.h>
#include <util/delay.h>
#include "EmSys.h"       // This is the test library
#include "SWSerial.h"

void delay_usec(unsigned int);
void init_sw_serial(int rx_pin, int tx_pin, long baudrate, int framing);
void sw_serial_puts(char *str);

int main(void) {

	// init rx_pin, tx_pin, baudrate, framing to defaults for now
	int rx_pin = 0x00;
	int tx_pin = 0x00;
	int baudrate = 0x00;
	int framing = 0x00;

	init_sw_serial(rx_pin, tx_pin, baudrate, framing);  // this is your function
	init_sw_serial_puts_test(baudrate, framing);   // library function: note we need the baudrate and framing here

	while(1) {
		sw_serial_puts("Hello,World!\n");
		test_sw_serial_puts();   // library test function
		_delay_ms(1000);
	}
}

void init_sw_serial(int rx_pin, int tx_pin, long baudrate, int framing)
{
	// pass
}

void sw_serial_puts(char *str) 
{
	// pass
}