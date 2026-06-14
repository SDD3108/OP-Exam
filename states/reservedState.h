#ifndef RESERVED_STATE_H
#define RESERVED_STATE_H

#include "seatState.h"
#include <string>
using namespace std;

// ReservedState.h
// Состояние забронированного места.
//
// Что разрешено:
// 1. Забронированное место можно выкупить.
// 2. Бронь можно отменить.
// 3. Место можно заблокировать только по административной причине.
//
// Что запрещено:
// 1. Нельзя повторно забронировать уже забронированное место.
//
// После действий:
// purchase переводит место в PurchasedState.
// cancel переводит место обратно в FreeState.
// block переводит место в BlockedState.

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