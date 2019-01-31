
/*
 * software_delay.s
 *
 * Created: 1/24/2019 2:26:50 PM
 *  Author: caseyem, abbottbf
 */ 
			.text
			.global delay_usec
delay_usec:
			cpi r25, 0x00
			brne preloop
checkone: /* Check if the 32 bits of r25 and r24 are equal to 0x01, if they are, end, if they are not, continue */
			cpi r24, 0x01
			breq end
			brlo setzero
			dec r24
			jmp loopbody
setzero:
			sbr r25, 0xFF
			sbr r24, 0xFE
			call spacer /* stall for 16 cycles */
			nop
			nop
			nop
			nop
			jmp loopbody
preloop:
			cpi r24, 0x01
			brlo initlarge
			breq stall16
			nop
			dec r24
			jmp loopless
stall16: /* stall for 16 cycles and go back to loop body */
			sbr r24, 0xFF
			dec r25
			nop
			call spacer
			nop
			nop
			jmp loopbody
looplogic:
			cpi r25, 0x01
			brlo end			// If r25 is negative, end
			dec r25				// Subtract 1 from r25
			sbr r24, 0xff		// Set r24 to 0xff
			jmp loopbody
loopextra:
			nop
			nop
			nop
loopwrap:   
			nop
			nop
			nop
loopbody:
			nop
			nop
loopless:	
			nop
			nop
			jmp update
end:
			ret					// Return, 5 cycles
spacer:
			nop
			ret
update:
			dec r24
			cpi r24, 0x00
			brne loopextra
			nop
			cpi r25, 0x01
			brlo end			// If r25 is negative or 0, end
			dec r25				// Subtract 1 from r25
			sbr r24, 0xff		// Set r24 to 0xff
			call spacer			// Execute an extra cycle before returning back
			nop
			nop
			nop
			jmp loopwrap		// Go back to main loop

initlarge:	
			dec r25
			sbr r24, 0xff
			jmp loopless