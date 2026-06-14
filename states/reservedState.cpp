#include <iostream>
#include <string>
#include <vector>
#include "reservedState.h"
#include "seat.h"

#include "freeState.h"
#include "purchasedState.h"
#include "blockedState.h"

using namespace std;

// ReservedState.cpp
// Здесь реализуются переходы из ReservedState.
//
// Что нужно реализовать:
// 1. purchase переводит место в PurchasedState.
// 2. cancel переводит место в ReservedState.
// 3. reserve должен быть запрещен.
// 4. block переводит место в BlockedState, если это разрешено логикой проекта.
//
// Главная цель:
// Не допустить двойного бронирования.

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