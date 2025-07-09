#include "servo_manager.h"

Servo servo;

byte locked_position = 0;
byte unlocked_position = 180;

void setup_servo(byte pin)
{
    servo.attach(pin);
    servo.write(locked_position);
}

void lock_servo()
{
    servo.write(locked_position);
    write_to_LCD("Status:", 0);
    write_to_LCD("Locked", 1);
}

void unlock_servo()
{
    servo.write(unlocked_position);
    write_to_LCD("Status:", 0);
    write_to_LCD("Unlocked", 1);
}