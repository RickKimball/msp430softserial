/**
 * config.h - configure baud rates, xmit/recv pins and ring buffer size
 * 
 * The values below are known to work on a launchpad
 * with an msp430g2231 in the socket and a 32.768k
 * crystal soldered onto the board.  The crystal is
 * needed to calibrate the DCO clock to the desired
 * CPU frequency.  The DCO needs to be fairly accurate
 * to achieve the proper bit timing at different 
 * baud rates and SMCLK frequencies.
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

#ifndef CONFIG_H_
#define CONFIG_H_

/**
 *  F_CPU - To obtain the best results select a UART friendly speed.
 *          Measure the speed at P1.4 using a multimeter or oscilloscope
 * 	        to verify you are getting your desired frequency. Also, you
 *          will have the best luck if you choose BAUD_RATE and F_CPU
 *          combination that allows the ISR routines to complete before
 *          the next data bit arrives. If you are having problems with
 *          a specific baud rate, use a larger F_CPU value until it
 * 			works.  You can test how well it works by use a copy paste
 *          command, that seems to stress the full duplex ascpects of
 *          the code.
 * 
 *   More info about UART friendly F_CPU and BAUD_RATE combos can be 
 *   found here:
 *      http://mspgcc.sourceforge.net/baudrate.html
 *      http://www.wormfood.net/avrbaudcalc.php and
 */

//-----------------------------------------------------------------------
// CALIBRATE_DCO enable this flag to use a soldered 32.768k watch crystal
//               as a reference clock and calc the F_CPU frequency without
//               saving the results to flash. Only calibrated at POC
//				 however temperature will affect the values and clock
//-----------------------------------------------------------------------
#define CALIBRATE_DCO  		// on by default

//#define F_CPU 18432000		// UART friendly but out of spec, might work from 9600-115200 bps
//#define F_CPU 16000000		// a popular faster clock with less than friendly UART numbers
#define F_CPU 14746000		// UART friendly faster clock
//#define F_CPU 12000000		// a popular clock with large error rates at different common speeds
//#define F_CPU 11059299		// UART friendly faster clock
//#define F_CPU  7372800		// UART and somewhat power friendly rate
//#define F_CPU  3686400		// UART and somewhat power friendly rate
//#define F_CPU  1843200		// UART and power friendly rate works well for 600-57600 bps

#if !defined(CALIBRATE_DCO)
#define F_CPU  1103000			// use default clock without a crystal
#endif 
//#define F_CPU  1000000		// at this speed 9600 has a 7.5% error rate .. better to try 4800

#define BAUD_RATE 9600		// launchpad max speed is 9600. However an FT232RL can go faster
							// http://www.sparkfun.com/products/718 - FT232RL Breakout Board

#define RX_PIN BIT2   		// RX Data on P1.2 (Timer0_A.CCI1A)
#define TX_PIN BIT1  		// TX Data on P1.1 (Timer0_A.OUT0) 

#define RX_BUFFER_SIZE 32	// Set the size of the ring buffer data needs to be a power of 2

typedef unsigned char uint8_t;
typedef char int8_t;

#endif
