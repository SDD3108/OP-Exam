#ifndef SEAT_STATE_H
#define SEAT_STATE_H

#pragma once
#include <string>
using namespace std;

class Seat;
class SeatState {
    public:
        SeatState() = default;
        virtual ~SeatState() = default;
        virtual string getName() const = 0;
        virtual bool isAvailable() const = 0;
        virtual void reserve(Seat& seat) = 0;
        virtual void purchase(Seat& seat) = 0;
        virtual void cancel(Seat& seat) = 0;
        virtual void block(Seat& seat) = 0;
        virtual void unblock(Seat& seat) = 0;
};

#endif // SEAT_STATE_H