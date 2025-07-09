#include "LED_utility.h"

byte LED_pin;
int fast_blinking_interval = 250;
int slow_blinking_interval = 750;
unsigned long blink_timer;

void setup_LED(byte pin)
{
    LED_pin = pin;
    pinMode(LED_pin, OUTPUT);
    digitalWrite(LED_pin, LOW);

    blink_timer = millis();
}

void turn_on_LED()
{
    digitalWrite(LED_pin, HIGH);
}

void turn_off_LED()
{
    digitalWrite(LED_pin, LOW);
}

void fast_blinking()
{
    if (millis() - blink_timer >= fast_blinking_interval) {
    blink_timer += fast_blinking_interval;
    digitalWrite(LED_pin, !digitalRead(LED_pin));
}
}

void slow_blinking()
{
    if (millis() - blink_timer >= slow_blinking_interval) {
    blink_timer += slow_blinking_interval;
    digitalWrite(LED_pin, !digitalRead(LED_pin));
}
}