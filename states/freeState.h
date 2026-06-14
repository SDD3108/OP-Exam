#ifndef FREE_STATE_H
#define FREE_STATE_H

#include "seatState.h"
#include <string>
using namespace std;
// FreeState.h
// Состояние свободного места.
//
// Что разрешено:
// 1. Свободное место можно забронировать.
// 2. Свободное место можно сразу выкупить.
// 3. Свободное место можно заблокировать.
//
// Что запрещено:
// 1. Нельзя отменить бронь, потому что брони еще нет.
//
// После действий:
// reserve переводит место в ReservedState.
// purchase переводит место в PurchasedState.
// block переводит место в BlockedState.

class FreeState : public SeatState{
    string getName() const override;
    bool isAvailable() const override;
    void reserve(Seat& seat) override;
    void purchase(Seat& seat) override;
    void cancel(Seat& seat) override;
    void block(Seat& seat) override;
    void unblock(Seat& seat) override;
};


#endif // FREE_STATE_H