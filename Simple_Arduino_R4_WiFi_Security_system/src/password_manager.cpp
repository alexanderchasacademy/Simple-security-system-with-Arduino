#include "password_manager.h"

byte password_index = 0;
bool correct_password = false;
char password_attempt[6] = "";
const byte password_length = 5;

unsigned long last_keypress_time = 0;
const unsigned long password_input_timeout = 20000;

const int key_press_tune = 1000;
const int correct_password_tune = 1500;
const int invalid_button_tune = 500;
const int incorrect_password_tune = 300;

const int key_press_tune_duration = 50;
const int correct_password_tune_duration = 100;
const int invalid_button_tune_duration = 200;
const int incorrect_password_tune_duration = 500;

void reset_attempt_password()
{
    memset(password_attempt, 0, sizeof(password_attempt));
    password_index = 0;
}

void check_password_correctness()
{
    if (strcmp(password_attempt, alarm_password) == 0)
    {
        correct_password = true;
        write_to_LCD("Correct password", 0);
        write_to_LCD("Access granted", 1);
        play_tune(correct_password_tune, correct_password_tune_duration);
    }

    else
    {
        correct_password = false;
        write_to_LCD("Wrong password!", 0);
        write_to_LCD("Try again", 1);
        play_tune(incorrect_password_tune, incorrect_password_tune_duration);
    }

    reset_attempt_password();
}

void print_password_LCD()
{
    char masked_password[password_length + 1];
    
    for (byte i = 0; i < password_index; i++) {
        masked_password[i] = '*';
    }
    masked_password[password_index] = '\0';

    write_to_LCD("Input password:", 0);
    write_to_LCD(masked_password, 1);
}

void process_password_key()
{
    char key = read_key();

    if (millis() - last_keypress_time >= password_input_timeout && password_index > 0)
    {
        reset_attempt_password();
        write_to_LCD("Timeout!", 0);
        write_to_LCD("Password cleared", 1);
    }
    
    if (key != NO_KEY && key != '\0')
    {
        last_keypress_time = millis();

        switch (key)
        {
            case 'a':
            if (password_index == password_length)
            {
                check_password_correctness();
            }

            else
            {
                write_to_LCD("Password too short", 0);
                write_to_LCD("Enter 5 digits", 1);
                play_tune(invalid_button_tune, invalid_button_tune_duration);
            }
            break;

            case 'b':
            if (password_index != 0)
            {
                password_index--;
                password_attempt[password_index] = '\0';
            }
            break;

            case 'c':
            reset_attempt_password();
            play_tune(key_press_tune, key_press_tune_duration);
            break;

            case 'd':
            invalid_input();
            play_tune(invalid_button_tune, invalid_button_tune_duration);
            break;

            case '#':
            invalid_input();
            play_tune(invalid_button_tune, invalid_button_tune_duration);
            break;

            case '*':
            invalid_input();
            play_tune(invalid_button_tune, invalid_button_tune_duration);
            break;

            default:
            if (password_index < password_length) 
            {
                password_attempt[password_index] = key;
                password_index++;
                password_attempt[password_index] = '\0';
                
                play_tune(key_press_tune, key_press_tune_duration);
            }
            break;
        }

        print_password_LCD();
    }
}