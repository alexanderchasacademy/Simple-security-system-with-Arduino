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

unsigned long timer = 0;
const int loop_period_MS = 100;
unsigned long current_loop = 0;

int high_alarm_activated_frequency = 2000;
int low_alarm_activated_frequency = 1200;
int alarm_frequency_duration = 200;
unsigned long alarm_ringing_timer = 0;

unsigned long grace_period_start = 0;
const unsigned long grace_period_duration = 10000;
 
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

    if (current_loop - timer >= loop_period_MS) {

        // Motion triggers alarm if alarm is armed
        if (motion_detected && current_state == state_alarm_armed) {
            current_state = state_transition_armed_to_triggered;
            set_motion_detected_to_false();
        }

        switch (current_state) {

            case state_idle:
            break;

            // === TRANSITION: DISARMED → GRACE PERIOD ===
            case state_transition_disarmed_to_grace_period:

                write_to_LCD("10 sec before", 0);
                write_to_LCD("alarm activates", 1);

                grace_period_start = millis();
                current_state = state_alarm_armed_grace_period;
            break;

            // === GRACE PERIOD ===
            case state_alarm_armed_grace_period:

                if (millis() - grace_period_start >= grace_period_duration) {
                    current_state = state_transition_to_armed;
                }
            break;

            // === TRANSITION: GRACE PERIOD → ARMED ===
            case state_transition_to_armed:

                write_to_LCD("Alarm status:", 0);
                write_to_LCD("Activated", 1);

                current_state = state_alarm_armed;
            break;

            // === ARMED STATE ===
            case state_alarm_armed:
                
                slow_blinking();
                process_password_key();

                if (correct_password) {
                    current_state = state_transition_to_disarmed;
                }
            break;

            // === TRANSITION: ARMED → TRIGGERED ===
            case state_transition_armed_to_triggered:

                lock_servo();
                write_to_LCD("ALARM TRIGGERED!", 0);
                write_to_LCD("Input password", 1);

                alarm_ringing_timer = millis(); // reset buzzer timer
                current_state = state_alarm_triggered;
            break;

            // === ALARM TRIGGERED ===
            case state_alarm_triggered:

                alarm_ringing();
                fast_blinking();
                process_password_key();

                if (correct_password) {
                    current_state = state_transition_to_disarmed;
                }
            break;

            // === TRANSITION: ANY → DISARMED ===
            case state_transition_to_disarmed:

                write_to_LCD("Alarm status:", 0);
                write_to_LCD("Deactivated", 1);
                stop_buzzer();
                turn_off_LED();
                current_state = state_disarmed;
            break;

            // === DISARMED STATE ===
            case state_disarmed:
                process_password_key();

                if (correct_password) {
                    current_state = state_transition_disarmed_to_grace_period;
                }
            break;

            case state_error:
                write_to_LCD("ERROR!", 0);
                write_to_LCD("Invalid state", 1);
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
