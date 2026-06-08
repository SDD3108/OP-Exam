#include <iostream>
#include <string>
#include <vector>
#include "seat.h"
#include "seatState.h"
using namespace std;

// Seat.cpp
// Здесь реализуется логика класса Seat.
//
// Что нужно реализовать:
// 1. Конструктор места.
// 2. Метод получения номера места.
// 3. Метод получения категории.
// 4. Метод получения базовой цены.
// 5. Метод проверки доступности.
// 6. Метод изменения состояния.
//
// Важно:
// Seat не должен сам решать всю бизнес-логику.
// Он должен делегировать действия объекту SeatState.
//
// Например:
// Если место свободно, его можно забронировать.
// Если место уже выкуплено, повторная бронь запрещена.

Seat::Seat(
    int number,
    SeatCategory category,
    double basePrice,
    unique_ptr<SeatState> initialState
)
    : number(number),
      category(category),
      basePrice(basePrice),
      state(move(initialState)) {}

int Seat::getSeatNumber() const {
    return number;
}

SeatCategory Seat::getCategory() const {
    return category;
}

double Seat::getBasePrice() const {
    return basePrice;
}

string Seat::getStateName() const {
    return state->getName();
}

bool Seat::isAvailable() const {
    return state->isAvailable();
}

void Seat::setState(unique_ptr<SeatState> newState) {
    state = move(newState);
}
void Seat::reserve(){
    state->reserve(*this);
}
void Seat::purchase(){
    state->purchase(*this);
}
void Seat::cancel(){
    state->cancel(*this);
}
void Seat::block(){
    state->block(*this);
}
void Seat::unblock(){
    state->unblock(*this);
}