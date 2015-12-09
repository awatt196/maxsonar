/*
 * maxsonar.h
 *
 *  Created on: 23 Oct 2015
 *      Author: andwat01
 */

//#ifndef SOURCE_MAXSONAR_H_
//#define SOURCE_MAXSONAR_H_

#include "mbed-drivers/mbed.h"
/*** @file Driver for Maxbotix sonar modules
 * Uses pulse width input to read range results.
 * @author Daniel Casner <http://www.danielcasner.org>
 *
 * Known Issues:
 * If a timer rollover occures during a sample, the driver will drop that sample.
 */

 /** Object representation of a sonar instance
  */
 class Sonar {
 public:
    /** Sets up the driver and starts taking measurements
     * @param input The pin to read pulses from
     * @param t A running timer instance used to measure pulse width.
     * Note that the timer must have been started or results will be
     * invalid.
     */
    Sonar(PinName input, Timer& t);

    /// Returns range in cm as int
    int read();

    /// Returns the range in CM as an int
    operator int();

 private:
    /// Inturrupt at start of pulse
    void pulseStart();
    /// Interrupt at end of pulse
    void pulseStop();

    /// Interrupt driver for the input pin
    InterruptIn interrupt;
    /// Reference to global timer instance
    Timer& time;
    /// Time of the start of the current pulse
    int pulseStartTime;
    /// The most recent sample
    int range;
 };



//#endif /* SOURCE_MAXSONAR_H_ */
