#include <iostream>
#include <string>
#include <vector>
#include "purchasedState.h"
#include "seat.h"

#include "freeState.h"
#include "purchasedState.h"
#include "blockedState.h"

using namespace std;

// PurchasedState.cpp
// Здесь реализуется поведение выкупленного места.
//
// Что нужно реализовать:
// 1. Любая попытка reserve должна быть запрещена.
// 2. Любая попытка purchase должна быть запрещена.
// 3. cancel можно запретить, если возвраты не предусмотрены.
// 4. block обычно тоже можно запретить, потому что место уже продано.
//
// Главная цель:
// Защитить систему от двойной продажи одного места.

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