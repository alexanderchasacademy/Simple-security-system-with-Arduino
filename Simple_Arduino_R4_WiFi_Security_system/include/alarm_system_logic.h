#ifndef ALARM_SYSTEM_LOGIC_H
#define ALARM_SYSTEM_LOGIC_H

#include "servo_manager.h"
#include "LCD_display.h"
//#include "potentiometer.h"
#include "keypad_manager.h"
#include "state_manager.h"
#include "password_manager.h"
#include "buzzer.h"
#include "PIR_sensor_manager.h"
#include "LED_utility.h"

extern int high_alarm_activated_frequency;
extern int low_alarm_activated_frequency;
extern int alarm_frequency_duration;
extern unsigned long alarm_ringing_timer;

extern unsigned long grace_period_start;
extern const unsigned long grace_period_duration;

void alarm_ringing();
void idle_logic();
void disarmed_to_grace_period_logic();
void grace_period_logic();
void transition_to_armed_logic();
void armed_logic();
void transition_armed_to_triggered_logic();  
void alarm_triggered_logic(); 
void transition_to_disarmed_logic();
void disarmed_logic();
void error_state_logic();
void default_state_logic();

#endif