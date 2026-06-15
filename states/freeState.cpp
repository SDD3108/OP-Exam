#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include "states/freeState.h"
#include "models/seat.h"

#include "states/reservedState.h"
#include "states/purchasedState.h"
#include "states/blockedState.h"

using namespace std;


string FreeState::getName() const {
    return "Free";
};
bool FreeState::isAvailable() const {
    return true;
};
void FreeState::reserve(Seat& seat){
    seat.setState(make_unique<ReservedState>());
};
void FreeState::purchase(Seat& seat){
    seat.setState(make_unique<PurchasedState>());
};
void FreeState::cancel(Seat& seat){
    throw logic_error("Seat cannot be canceled, seat is not reserved");
};
void FreeState::block(Seat& seat){
    seat.setState(make_unique<BlockedState>());
};
void FreeState::unblock(Seat& seat){
    throw logic_error("Seat cannot be unblock, its already free");
};