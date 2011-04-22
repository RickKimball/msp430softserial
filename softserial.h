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
// TX/RX PINS - you can't really change these as we use the
//  latch feature of CCR1. On a different chip you might be
//  able to do something
//------------------------------------------------------------
#define TX_PIN BIT1     // TX Data on P1.1 (Timer0_A.OUT0)
#define RX_PIN BIT2     // RX Data on P1.2 (Timer0_A.CCI1A)

//------------------------------------------------------------
// ENABLE_RXDEBUG_PIN - enables a toggled pin from inside
//   the RX ISR. Useful for verifying sample times match the
//   middle of the data bits. Connect an oscilloscope to
//   RXDEBUG_PIN and the RX_PIN.  Use the character 'U' for
//   testing as it has a signal that looks like a clock.
//------------------------------------------------------------
#undef ENABLE_RXDEBUG_PIN

#define RXDEBUG_PIN_PORT  P1    // P1
#define RXDEBUG_PIN     BIT5    // P1.5

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
