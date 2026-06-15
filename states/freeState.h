#ifndef FREE_STATE_H
#define FREE_STATE_H

#include "states/seatState.h"
#include <string>
using namespace std;


class FreeState : public SeatState{
    public:
        string getName() const override;
        bool isAvailable() const override;
        void reserve(Seat& seat) override;
        void purchase(Seat& seat) override;
        void cancel(Seat& seat) override;
        void block(Seat& seat) override;
        void unblock(Seat& seat) override;
};


#endif // FREE_STATE_H