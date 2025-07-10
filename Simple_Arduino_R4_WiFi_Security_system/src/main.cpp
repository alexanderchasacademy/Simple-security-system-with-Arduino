#include <Arduino.h>
#include "servo_manager.h"
#include "LCD_display.h"
#include "potentiometer.h"
#include "keypad_manager.h"
#include "state_manager.h"
#include "password_manager.h"
#include "buzzer.h"
#include "PIR_sensor_manager.h"
#include "LED_utility.h"

unsigned long timer;

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
}

void loop() {
  
    switch (current_state)
    {
        case state_idle:
        break;

        case state_alarm_start_grace_period:
        break;

        case state_alarm_active:
        break;

        case state_alarm_not_active:
        break;
    }
}

