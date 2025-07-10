#include "alarm_system_logic.h"

int high_alarm_activated_frequency = 2000;
int low_alarm_activated_frequency = 1200;
int alarm_frequency_duration = 200;
unsigned long alarm_ringing_timer = 0;

unsigned long grace_period_start = 0;
const unsigned long grace_period_duration = 10000;

void alarm_ringing()
{

    static bool alarm_ringing_high_tone = true;

    if (millis() - alarm_ringing_timer >= alarm_frequency_duration)
    {
        alarm_ringing_timer += alarm_frequency_duration;

        if (alarm_ringing_high_tone)
        {
            play_tune(high_alarm_activated_frequency);
        }

        else 
        {
            play_tune(low_alarm_activated_frequency);
        }

        alarm_ringing_high_tone = !alarm_ringing_high_tone;
    }
}

void alarm_ringing()
{

}

void idle_logic()
{

}

void disarmed_to_grace_period_logic()
{

}

void grace_period_logic()
{

}

void transition_to_armed_logic()
{

}

void armed_logic()
{
    
}

void transition_armed_to_triggered_logic()
{

}  

void alarm_triggered_logic()
{

} 

void transition_to_disarmed_logic()
{

}

void disarmed_logic()
{

}

void error_state_logic()
{

}

void default_state_logic()
{
    
}