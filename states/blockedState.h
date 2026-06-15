#ifndef BLOCKED_STATE_H
#define BLOCKED_STATE_H
#include <string>
#include "states/seatState.h"
using namespace std;

class BlockedState : public SeatState{
    public:
        string getName() const override;
        bool isAvailable() const override;
        void reserve(Seat& seat) override;
        void purchase(Seat& seat) override;
        void cancel(Seat& seat) override;
        void block(Seat& seat) override;
        void unblock(Seat& seat) override;
};


#endif // BLOCKED_STATE_H