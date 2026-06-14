#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include "freeState.h"
#include "seatState.h"
#include "seat.h"

#include "reservedState.h"
#include "purchasedState.h"
#include "blockedState.h"

using namespace std;

// FreeState.cpp
// Здесь реализуются переходы из состояния FreeState.
//
// Что нужно реализовать:
// 1. При reserve изменить состояние места на ReservedState.
// 2. При purchase изменить состояние места на PurchasedState.
// 3. При block изменить состояние места на BlockedState.
// 4. При невозможных действиях выбросить ошибку или вернуть false.
//
// Главная цель:
// Разрешить операции только для свободного места.

string FreeState::getName() const {
    return "Free";
};
bool FreeState::isAvailable() const {
    return true;
};
void FreeState::reserve(Seat& seat){

};
void FreeState::purchase(Seat& seat){

};
void FreeState::cancel(Seat& seat){
    throw logic_error("Seat cannot be canceled, seat is not reserved");
};
void FreeState::block(Seat& seat){

};
void FreeState::unblock(Seat& seat){
    throw logic_error("Seat cannot be unblock, its already free");
};