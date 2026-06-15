#ifndef SEAT_H
#define SEAT_H
#include <string>
#include <vector>

#pragma once

#include <memory>
#include <string>

#include "common/seatCategory.h"
#include "states/seatState.h"
using namespace std;

class Seat {
private:
    int number;
    SeatCategory category;

    double basePrice;
    unique_ptr<SeatState> state;

public:
    Seat(int number,SeatCategory category,double basePrice,std::unique_ptr<SeatState> initialState);
    Seat(const Seat& other) = delete;
    Seat& operator=(const Seat& other) = delete;
    Seat(Seat&& other) noexcept = default;
    Seat& operator=(Seat&& other) noexcept = default;
    int getSeatNumber() const;
    SeatCategory getCategory() const;
    double getBasePrice() const;
    string getStateName() const;
    bool isAvailable() const;
    void setState(std::unique_ptr<SeatState> newState);

    void reserve();
    void purchase();
    void cancel();
    void block();
    void unblock();
};
#endif // SEAT_H