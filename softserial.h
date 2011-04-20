/**
 * softserial.h - full-duplex software UART implementation
 * 
 * License: Do with this code what you want. However, don't blame
 * me if you connect it to a heart pump and it stops.  This source
 * is provided as is with no warranties. It probably has bugs!!
 * You have been warned!
 * 
 * Author: Rick Kimball
 * email: rick@kimballsoftware.com
 * Version: 1.0 Initial version 04-20-2011
 * 
 */
 
#ifndef SOFTSERIAL_H_
#define SOFTSERIAL_H_

void SoftSerial_init(void);
uint8_t SoftSerial_available(void);
void SoftSerial_xmit(uint8_t);
int SoftSerial_read(void);

//------------------------------------------------------------
// ENABLE_RXDEBUG_PIN - enables a toggled pin from inside
//   the RX ISR. Useful for verifying sample times match to
//   make sure they are done in the center of the data bits
//------------------------------------------------------------
#define ENABLE_RXDEBUG_PIN

#define RXDEBUG_PIN_PORT	P1		// P1
#define RXDEBUG_PIN 		BIT5 	// P1.5

#ifdef ENABLE_RXDEBUG_PIN

#define _SoftSerial_RxDebugPinInit() { \
    P1OUT |= RXDEBUG_PIN; \
    P1DIR |= RXDEBUG_PIN; \
}
	 
#define _SoftSerial_ToggleRxDebugPin() { \
	P1OUT ^= RXDEBUG_PIN; \
}
	
#define _SoftSerial_ToggleRxDebugPin() { \
	P1OUT ^= RXDEBUG_PIN; \
}
	
#define _SoftSerial_SetRxDebugPin() { \
	P1OUT |= RXDEBUG_PIN; \
}
	
#define _SoftSerial_ResetRxDebugPin() { \
	P1OUT ^= ~RXDEBUG_PIN; \
}

#else
#define _SoftSerial_RxDebugPinInit()
#define _SoftSerial_ToggleRxDebugPin()
#define _SoftSerial_ToggleRxDebugPin()
#define _SoftSerial_SetRxDebugPin()
#define _SoftSerial_ResetRxDebugPin()
#endif


#endif /*SOFTSERIAL_H_*/
