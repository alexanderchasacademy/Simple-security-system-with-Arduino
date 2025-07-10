#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C LCD;

//extern char LCD_message[17];
extern char previous_LCD_message_row0[17];
extern char previous_LCD_message_row1[17];

void write_to_LCD(const char* LCD_message, byte row);
void invalid_input();
void setup_LCD();

#endif