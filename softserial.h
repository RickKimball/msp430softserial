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
 * Version: 1.00 Initial version 04-20-2011
 * Version: 1.01 cleanup 04-21-2011
 * 
 */
 
#ifndef SOFTSERIAL_H_
#define SOFTSERIAL_H_

void SoftSerial_init(void);
int8_t SoftSerial_empty(void);
void SoftSerial_xmit(uint8_t);
int SoftSerial_read(void);

#undef SOFTSERIAL_ENABLE_BUFFERCNT
#if defined(SOFTSERIAL_ENABLE_BUFFERCNT)
uint8_t SoftSerial_available(void);
#endif

//------------------------------------------------------------
// ENABLE_RXDEBUG_PIN - enables a toggled pin from inside
//   the RX ISR. Useful for verifying sample times match to
//   make sure they are done in the center of the data bits
//------------------------------------------------------------
#undef ENABLE_RXDEBUG_PIN

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

#else
#define _SoftSerial_RxDebugPinInit()
#define _SoftSerial_ToggleRxDebugPin()
#endif


#endif /*SOFTSERIAL_H_*/
