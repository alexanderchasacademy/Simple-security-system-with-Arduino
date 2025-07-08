#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD(0x27, 16, 2);

char LCD_message[17];
char previous_LCD_message_row0[17] = "";
char previous_LCD_message_row1[17] = "";

void write_to_LCD(const char* LCD_message, byte row);

#endif