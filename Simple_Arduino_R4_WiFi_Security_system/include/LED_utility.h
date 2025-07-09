#ifndef LED_UTILITY_H
#define LED_UTILITY_H

#include <Arduino.h>

extern byte LED_pin;
extern int fast_blinking_interval;
extern int slow_blinking_interval;
extern unsigned long blink_timer;

void setup_LED(byte pin);
void turn_on_LED();
void turn_off_LED();
void fast_blinking();
void slow_blinking();

#endif