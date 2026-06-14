#ifndef PURCHASED_STATE_H
#define PURCHASED_STATE_H

#include <string>
#include "seatState.h"
using namespace std;

// PurchasedState.h
// Состояние выкупленного места.
//
// Что разрешено:
// Обычно ничего, кроме просмотра статуса.
//
// Что запрещено:
// 1. Нельзя повторно забронировать.
// 2. Нельзя повторно купить.
// 3. Нельзя сделать свободным без отдельной логики возврата.
//
// Важно:
// Это финальное состояние места после успешной покупки билета.

class PurchasedState : public SeatState{
    public:
        string getName() const override;
        bool isAvailable() const override;
        void reserve(Seat& seat) override;
        void purchase(Seat& seat) override;
        void cancel(Seat& seat) override;
        void block(Seat& seat) override;
        void unblock(Seat& seat) override;
};

#endif // PURCHASED_STATE_H
