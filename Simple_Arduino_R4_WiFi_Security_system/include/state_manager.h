#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

enum SystemState {
    state_idle,                               // Initial idle state

    // Transitions
    state_transition_disarmed_to_grace_period,
    state_alarm_armed_grace_period,
    state_transition_to_armed,
    state_transition_armed_to_triggered,
    state_transition_to_disarmed,

    // Main operational states
    state_alarm_armed,
    state_alarm_triggered,
    state_disarmed,

    // Fallback
    state_error
};


extern SystemState current_state;

#endif
