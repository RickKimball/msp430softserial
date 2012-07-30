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
 *
 * Version: 1.00 04-20-2011 Initial version
 * Version: 1.01 04-21-2011 cleanup
 * Version: 1.02 04-21-2011 modified ISR defines to make msp430g2553 happy
 * Version: 1.03 07-27-2012 add support of gcc 4.5.3 and above
 */

#ifndef SOFTSERIAL_H_
#define SOFTSERIAL_H_

#ifdef __cplusplus
extern "C" {
#endif

void SoftSerial_init(void);
void SoftSerial_end(void);

unsigned SoftSerial_available(void);
unsigned SoftSerial_empty(void);
void SoftSerial_xmit(unsigned char);
int SoftSerial_read(void);
unsigned char SoftSerial_read_nc(void);

//------------------------------------------------------------
// TX/RX PINS - you can't really change these as we use the
// latch feature of CCR1. On a different chip you might be
// able to do something
//------------------------------------------------------------
#define TX_PIN BIT1     // TX Data on P1.1 (Timer0_A.OUT0)
#define RX_PIN BIT2     // RX Data on P1.2 (Timer0_A.CCI1A)

#ifdef __cpluscplus
} /* extern "C" */
#endif
#endif /*SOFTSERIAL_H_*/
