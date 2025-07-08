#include "LCD_display.h"

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