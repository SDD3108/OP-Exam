#include <iostream>
#include <string>
#include <vector>
#include "states/purchasedState.h"
#include "models/seat.h"

#include "states/freeState.h"
#include "states/purchasedState.h"
#include "states/blockedState.h"

using namespace std;


string PurchasedState::getName() const{
    return "Purchased";
};
bool PurchasedState::isAvailable() const{
    return false;
};
void PurchasedState::reserve(Seat& seat){
    throw logic_error("Seat cannot be reserved, its already purchased");
};
void PurchasedState::purchase(Seat& seat){
    throw logic_error("Seat cannot be purchase, its already purchased");
};
void PurchasedState::cancel(Seat& seat){
    throw logic_error("Seat cannot be canceled, refund logic is not success");
};
void PurchasedState::block(Seat& seat){
    throw logic_error("Seat cannot be blocked, its already purchased");
};
void PurchasedState::unblock(Seat& seat){
    throw logic_error("Seat cannot be unblock, this seat is not blocked");
};