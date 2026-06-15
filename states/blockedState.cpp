#include <iostream>
#include <string>
#include <vector>
#include "states/blockedState.h"
#include "models/seat.h"

#include "states/freeState.h"
#include "states/reservedState.h"
#include "states/purchasedState.h"
using namespace std;

string BlockedState::getName() const{
    return "Blocked";
};
bool BlockedState::isAvailable() const{
    return false;
};
void BlockedState::reserve(Seat& seat){
    throw logic_error("Seat cannot be reserved, its blocked for maintenance");
};
void BlockedState::purchase(Seat& seat){
    throw logic_error("Seat cannot be purchased, its blocked for maintenance");
};
void BlockedState::cancel(Seat& seat){
    throw logic_error("Seat cannot be canceled, its blocked for maintenance");
};
void BlockedState::block(Seat& seat){
    throw logic_error("Seat cannot be blocked, its already blocked");
};
void BlockedState::unblock(Seat& seat){
    seat.setState(make_unique<FreeState>());
};