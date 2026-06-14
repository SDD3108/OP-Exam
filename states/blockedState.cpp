#include <iostream>
#include <string>
#include <vector>
#include "blockedState.h"
#include "seat.h"

#include "freeState.h"
#include "reservedState.h"
#include "purchasedState.h"


using namespace std;

// BlockedState.cpp
// Здесь реализуется поведение заблокированного места.
//
// Что нужно реализовать:
// 1. reserve запрещен.
// 2. purchase запрещен.
// 3. cancel запрещен.
// 4. unblock переводит место в FreeState.
//
// Главная цель:
// Не дать пользователю купить технически недоступное место.

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