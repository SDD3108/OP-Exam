#include <iostream>
#include <string>
#include <vector>
#include "models/seat.h"
#include "states/seatState.h"
using namespace std;

Seat::Seat(
    int number,
    SeatCategory category,
    double basePrice,
    unique_ptr<SeatState> initialState
)
    : number(number),
      category(category),
      basePrice(basePrice),
      state(std::move(initialState)) {}

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
    state = std::move(newState);
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