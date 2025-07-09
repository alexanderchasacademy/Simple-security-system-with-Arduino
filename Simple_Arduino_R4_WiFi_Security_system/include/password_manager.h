#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include <Arduino.h>
#include "secrets.h"
#include "keypad_manager.h"
#include "LCD_display.h"

extern byte password_index;
extern bool correct_password;
extern char password_attempt[];

void check_password_correctness();
void process_password_key();

#endif