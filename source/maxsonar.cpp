/*
 * maxsonar.cpp
 *
 *  Created on: 23 Oct 2015
 *      Author: andwat01
 */

#include "maxsonar/maxsonar.h"



Sonar::Sonar(PinName input, Timer& t) :
    interrupt(input),
    time(t),
    pulseStartTime(0),
    range(0) {
    interrupt.rise(this, &Sonar::pulseStart);
    interrupt.fall(this, &Sonar::pulseStop);
}

int Sonar::read() {
    return range;
}

Sonar::operator int() {
    return read();
}

void Sonar::pulseStart() {
	Serial pc(PTC17,PTC16);
    pulseStartTime = time.read_us();
    pc.printf("pulseStartTime = %i", pulseStartTime);
}

void Sonar::pulseStop() {
	Serial pc(PTC17,PTC16);
    int endTime = time.read_us();
    pc.printf("endTime = %i", endTime);
    if (endTime < pulseStartTime) return; // Escape if there's been a roll over
    range = (endTime - pulseStartTime) / 58; // 58uS per CM
}


