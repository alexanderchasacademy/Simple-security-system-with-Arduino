#include "PIR_sensor_manager.h"

byte PIR_pin;
bool motion_detected = false;

void setup_PIR_sensor(byte pin)
{
    PIR_pin = pin;
    pinMode(PIR_pin, INPUT);
}

byte read_PIR()
{
    return digitalRead(PIR_pin);
}

void set_motion_detected_to_true()
{
    motion_detected = true;
}

void set_motion_detected_to_false()
{
    motion_detected = false;
}