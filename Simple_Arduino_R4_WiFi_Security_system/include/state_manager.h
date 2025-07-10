#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

enum SystemState {
    state_idle,
    state_alarm_start_grace_period,
    state_alarm_active,
    state_alarm_not_active,
    STATE_ACCESS_GRANTED,
    STATE_ACCESS_DENIED,
    STATE_LOCKED_OUT
};

extern SystemState current_state;

#endif
