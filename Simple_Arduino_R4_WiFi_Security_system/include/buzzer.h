#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>
#include "potentiometer.h"

void setup_buzzer(byte pin); 
void play_tune(unsigned int frequency, unsigned long duration);
void stop_buzzer();

#endif