#ifndef SEAT_STATE_H
#define SEAT_STATE_H

#pragma once
#include <string>
// SeatState.h
// Это базовый интерфейс состояния места.
//
// Что нужно сделать:
// 1. Описать общий интерфейс для всех состояний.
// 2. Добавить методы, которые будут переопределяться в конкретных состояниях.
//
// Возможные действия:
// 1. reserve — забронировать.
// 2. purchase — выкупить.
// 3. cancel — отменить бронь.
// 4. block — заблокировать для обслуживания.
// 5. unblock — разблокировать.
//
// Для чего нужен State Pattern:
// Чтобы каждое состояние само решало,
// какие переходы разрешены, а какие запрещены.
//
// Например:
// FreeState разрешает бронирование.
// PurchasedState запрещает повторную покупку.
// BlockedState запрещает бронирование.

class Seat;
class SeatState {
    public:
        SeatState();
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