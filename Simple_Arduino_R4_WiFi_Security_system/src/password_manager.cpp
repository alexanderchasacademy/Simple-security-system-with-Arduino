#include "password_manager.h"

byte password_index = 0;
bool correct_password = false;
char password_attempt[6] = "";

void check_password_correctness()
{
    if (strcmp(password_attempt, alarm_password) == 0)
    {
        correct_password = true; 
    }
}

void process_password_key()
{
    char key = read_key();
    
    if (key != NO_KEY && key != '\0')
    {
        switch (key)
        {
            
        }
    }
}