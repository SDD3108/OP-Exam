#ifndef RESERVED_STATE_H
#define RESERVED_STATE_H

#include "states/seatState.h"
#include <string>
using namespace std;

class ReservedState : public SeatState{
    public:
        string getName() const override;
        bool isAvailable() const override;
        void reserve(Seat& seat) override;
        void purchase(Seat& seat) override;
        void cancel(Seat& seat) override;
        void block(Seat& seat) override;
        void unblock(Seat& seat) override;
};

#endif // RESERVED_STATE_H