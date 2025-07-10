#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include <Arduino.h>
#include "secrets.h"
#include "keypad_manager.h"
#include "LCD_display.h"
#include "buzzer.h"

extern byte password_index;
extern bool correct_password;
extern char password_attempt[];
extern const byte password_length;

extern unsigned long last_keypress_time;
extern const unsigned long password_input_timeout;

extern const int key_press_tune;
extern const int correct_password_tune;
extern const int invalid_button_tune;
extern const int incorrect_password_tune;

extern const int key_press_tune_duration;
extern const int correct_password_tune_duration;
extern const int invalid_button_tune_duration;
extern const int incorrect_password_tune_duration;

void reset_attempt_password();
void check_password_correctness();
void print_password_LCD();
void process_password_key();

#endif