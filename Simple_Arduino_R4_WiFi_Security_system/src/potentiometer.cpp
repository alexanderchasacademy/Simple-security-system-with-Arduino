#include "potentiometer.h"

int read_and_convert_pot_value(byte Potentiometer_pin, int range_max)
{
  int read_value = analogRead(Potentiometer_pin);
  return map(read_value, 0, 1023, 0, range_max);
}