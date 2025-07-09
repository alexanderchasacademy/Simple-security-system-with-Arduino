#ifndef SERVO_MANAGER_H
#define SERVO_MANAGER_H

#include <Arduino.h>
#include <Servo.h>
#include "LCD_display.h"

extern Servo servo;
extern byte locked_position;
extern byte unlocked_position;

void setup_servo(byte pin);
void lock_servo();
void unlock_servo();

#endif