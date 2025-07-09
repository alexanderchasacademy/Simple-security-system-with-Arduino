#include "password_manager.h"

byte password_index = 0;
bool correct_password = false;
char password_attempt[6] = "";
const byte password_length = 5;

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
        reset_attempt_password(); 
    }
}

void process_password_key()
{
    char key = read_key();
    
    if (key != NO_KEY && key != '\0')
    {
        switch (key)
        {
            case 'a':
            if (password_index == password_length)
            {
                check_password_correctness();
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
            break;

            case 'd':
            invalid_input();
            break;

            case '#':
            invalid_input();
            break;

            case '*':
            invalid_input();
            break;

            default:
            if (password_index < password_length) 
            {
                password_attempt[password_index] = key;
                password_index++;
                password_attempt[password_index] = '\0'; 
            }
            break;
        }
    }
}