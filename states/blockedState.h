#ifndef BLOCKED_STATE_H
#define BLOCKED_STATE_H
#include <string>
#include "seatState.h"
using namespace std;

// BlockedState.h
// Состояние места, заблокированного для технического обслуживания.
//
// Что разрешено:
// 1. Можно разблокировать место.
//
// Что запрещено:
// 1. Нельзя бронировать.
// 2. Нельзя покупать.
// 3. Нельзя отменять бронь, если место просто заблокировано.
//
// После действий:
// unblock переводит место в FreeState.

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