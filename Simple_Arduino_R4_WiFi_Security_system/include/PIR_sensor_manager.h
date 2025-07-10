#ifndef PIR_SENSOR_MANAGER_H
#define PIR_SENSOR_MANAGER_H

#include <Arduino.h>

extern byte PIR_pin;
extern volatile bool motion_detected;

void setup_PIR_sensor(byte pin);
byte read_PIR();
void set_motion_detected_to_true();
void set_motion_detected_to_false();

#endif