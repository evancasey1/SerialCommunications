/*
 * SWSerial.h
 *
 * Created: 1/31/2019 3:06:50 PM
 *  Author: caseyem
 */ 


#ifndef SWSERIAL_H_
#define SWSERIAL_H_

void init_sw_serial(int rx_pin, int tx_pin, long baudrate, int framing);
void sw_serial_puts(char *str);

#endif /* SWSERIAL_H_ */