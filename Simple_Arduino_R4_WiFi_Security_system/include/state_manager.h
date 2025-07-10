#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

enum SystemState {
    state_idle,
    state_alarm_start_grace_period,
    state_alarm_triggered,
    state_alarm_not_triggered,
    state_waiting_for_password,
    state_checking_password,
    state_intrusion_detected,
    state_disarmed,
    state_error
};

extern SystemState current_state;

#endif
