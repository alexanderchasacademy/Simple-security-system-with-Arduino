#include "LCD_display.h"

LiquidCrystal_I2C LCD(0x27, 16, 2);

//char LCD_message[17];
char previous_LCD_message_row0[17] = "";
char previous_LCD_message_row1[17] = "";

void write_to_LCD(const char* LCD_message, byte row)
{
  char* prev_msg = (row == 0) ? previous_LCD_message_row0 : previous_LCD_message_row1;

  if (strcmp(LCD_message, prev_msg) != 0)
  {
    LCD.setCursor(0, row);
    LCD.print("                ");
    LCD.setCursor(0, row);
    LCD.print(LCD_message);

    strncpy(prev_msg, LCD_message, 16);
    prev_msg[16] = '\0';
  }
}

void invalid_input()
{
  write_to_LCD("Invalid input", 0);
  write_to_LCD("please try again", 1);
}