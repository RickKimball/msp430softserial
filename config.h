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
 *
 * Version: 1.00 04-20-2011 Initial version
 * Version: 1.01 04-21-2011 cleanup
 * Version: 1.02 04-21-2011 modified ISR defines to make msp430g2553 happy
 * Version: 1.03 07-27-2012 added support of msp430-gcc 4.5.3 and above
 */

#ifndef CONFIG_H_
#define CONFIG_H_

/**
 * F_CPU - To obtain the best results select a UART friendly speed.
 *         Measure the SMCLK speed at P1.4 using a multimeter or oscilloscope.
 *         Verify you are getting your desired frequency. Also, you
 *         will have the best luck if you choose BAUD_RATE and F_CPU
 *         combination that allows the ISR routines to complete before
 *         the next data bit arrives. If you are having problems with
 *         a specific baud rate, use a larger F_CPU value until it
 *         works.  You can test how well it works by use a copy paste
 *         command in your terminal emulator.  That seems to stress
 *         the full-duplex aspects of the code.
 *
 *   More info about UART friendly F_CPU and BAUD_RATE combos can be found here:
 *
 *         http://mspgcc.sourceforge.net/baudrate.html
 *         http://www.wormfood.net/avrbaudcalc.php and
 */

//-------------------------------------------------------------------------
// CALIBRATE_DCO enable this flag to use the soldered 32.768k watch crystal
//               as a reference clock and calibrate the F_CPU frequency without
//               saving the results to flash. Only calibrated at POC
//               however temperature will affect the values and clock
//               An improvement to the code would be to run occasionally
//-------------------------------------------------------------------------
#define CALIBRATE_DCO       // on by default
#define RX_BUFFER_SIZE 16   // Set the size of the ring buffer data needs to be a power of 2
#define F_CPU 16000000    // fastest clock, factory calibrated sometimes
//#define F_CPU 12000000    // a popular faster clock, factory calibrated sometimes
//#define F_CPU 14745600    // I like this one
//#define F_CPU 11059200    // UART friendly faster clock
//#define F_CPU  8000000    // a popular medium clock, factory calibrated sometimes
//#define F_CPU  7372800    // UART friendly and a little less power friendly
//#define F_CPU  3686400    // can do 1200-9600 exactly and power friendly
//#define F_CPU  1843200    // UART and power friendly
//#define F_CPU  1000000    // slow, but factory calibrated on all chips

#define BAUD_RATE 9600      // launchpad max speed is 9600. However an FT232RL can go faster
                            // http://www.sparkfun.com/products/718 - FT232RL Breakout Board
#endif
