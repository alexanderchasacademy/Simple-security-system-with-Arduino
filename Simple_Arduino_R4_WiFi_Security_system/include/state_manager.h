// state_manager.h
#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

enum SystemState {
    state_idle,
    STATE_WAITING_FOR_PASSWORD,
    STATE_VALIDATING_PASSWORD,
    STATE_ACCESS_GRANTED,
    STATE_ACCESS_DENIED,
    STATE_LOCKED_OUT
};

extern SystemState current_state;

#endif
