#include "buzzer.h"

static byte buzzer_pin; 

void setup_buzzer(byte pin)
{
    buzzer_pin = pin;
    pinMode(buzzer_pin, OUTPUT);
}

void play_tune(unsigned int frequency)
{
    noTone(buzzer_pin);
    tone(buzzer_pin, frequency);
}

void play_tune(unsigned int frequency, unsigned long duration)
{
    noTone(buzzer_pin);
    tone(buzzer_pin, frequency, duration);
}

void stop_buzzer()
{
    noTone(buzzer_pin);
}