#ifndef KEYPAD_MANAGER_H
#define KEYPAD_MANAGER_H

#include <Arduino.h>
#include <Keypad.h>
#include "LCD_display.h"
#include "buzzer.h"

const byte ROWS = 4;
const byte COLS = 4;

extern char keys[ROWS][COLS];
extern Keypad keypad;

char read_key();

#endif
