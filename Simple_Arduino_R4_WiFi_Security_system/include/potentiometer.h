#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H
#include <arduino.h>

int read_and_convert_pot_value(byte Potentiometer_pin, int range_max);

#endif