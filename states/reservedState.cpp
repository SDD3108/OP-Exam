#include <iostream>
#include <string>
#include <vector>
#include "states/reservedState.h"
#include "models/seat.h"

#include "states/freeState.h"
#include "states/purchasedState.h"
#include "states/blockedState.h"

using namespace std;


string ReservedState::getName() const{
    return "Reserved";
};
bool ReservedState::isAvailable() const{
    return false;
};
void ReservedState::reserve(Seat& seat){
    throw logic_error("Seat cannot be reserved, this seat is already reserved");
};
void ReservedState::purchase(Seat& seat){
    seat.setState(make_unique<PurchasedState>());
};
void ReservedState::cancel(Seat& seat){
    seat.setState(make_unique<ReservedState>());
};
void ReservedState::block(Seat& seat){
    seat.setState(make_unique<BlockedState>());
};
void ReservedState::unblock(Seat& seat){
    throw logic_error("Seat cannot be unblock, this seat is not blocked");
};