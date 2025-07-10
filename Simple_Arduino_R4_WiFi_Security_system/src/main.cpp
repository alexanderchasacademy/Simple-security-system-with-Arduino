#include <Arduino.h>
#include "servo_manager.h"
#include "LCD_display.h"
//#include "potentiometer.h"
#include "keypad_manager.h"
#include "state_manager.h"
#include "password_manager.h"
#include "buzzer.h"
#include "PIR_sensor_manager.h"
#include "LED_utility.h"

unsigned long timer;
const int loop_period_MS = 50;
unsigned long current_loop;

int high_alarm_activated_frequency = 2000;
int low_alarm_activated_frequency = 1200;
int alarm_frequency_duration = 200;
unsigned long alarm_ringing_timer;
 
void alarm_ringing();

void setup() {

    setup_LCD();
    setup_LED(4);
    setup_PIR_sensor(2);
    setup_buzzer(5);
    setup_servo(3);

    attachInterrupt(digitalPinToInterrupt(PIR_pin), set_motion_detected_to_true, RISING);

    write_to_LCD("Booting system....", 0);
    write_to_LCD("system started", 1);

    timer = millis();
    alarm_ringing_timer = millis();
}

void loop() {

    current_loop = millis();
    
    if (current_loop - timer >= loop_period_MS)
    {
        if (motion_detected)
        {
            current_state = state_alarm_triggered;
            set_motion_detected_to_false();
        }

        switch (current_state)
        {
            case state_idle:
            break;

            case state_alarm_start_grace_period:
            break;

            case state_alarm_triggered:
            lock_servo();
            alarm_ringing();
            fast_blinking();
            break;

            case state_alarm_not_triggered:
            break;

            case state_waiting_for_password:
            break;

            case state_checking_password:
            break;

            case state_intrusion_detected:
            break;

            case state_disarmed:
            break;

            case state_error:
            break;

            default:
            write_to_LCD("Currently not", 0);
            write_to_LCD("In a valid state", 1);
            break;
        }

        timer += loop_period_MS;
    }
}

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