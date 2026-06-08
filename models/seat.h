#ifndef SEAT_H
#define SEAT_H
#include <string>
#include <vector>
#include "seatCategory.h";

// Seat.h
// Здесь объявляется класс Seat.
//
// Что должен хранить Seat:
// 1. Номер места.
// 2. Категорию места:
//    - VIP;
//    - STANDARD;
//    - ECONOMY.
// 3. Базовую стоимость места.
// 4. Текущее состояние места через State Pattern.
//
// Что должен уметь Seat:
// 1. Возвращать номер места.
// 2. Возвращать категорию.
// 3. Возвращать базовую стоимость.
// 4. Возвращать текущее состояние.
// 5. Менять состояние только через разрешенные методы.
// 6. Проверять, доступно ли место для бронирования.
//
// Важно:
// Нельзя просто сделать seat.status = "reserved".
// Состояние должно управляться через объект SeatState.

#pragma once

#include <memory>
#include <string>

#include "seatCategory.h"
#include "seatState.h"
using namespace std;

class Seat {
private:
    int number;
    SeatCategory category;

    double basePrice;
    std::unique_ptr<SeatState> state;

public:
    Seat(int number,SeatCategory category,double basePrice,std::unique_ptr<SeatState> initialState);
    Seat(const Seat& other) = delete;
    Seat& operator=(const Seat& other) = delete;
    Seat(Seat&& other) noexcept = default;
    Seat& operator=(Seat&& other) noexcept = default;
    int getSeatNumber() const;
    SeatCategory getCategory() const;
    double getBasePrice() const;
    std::string getStateName() const;
    bool isAvailable() const;
    void setState(std::unique_ptr<SeatState> newState);

    void reserve();
    void purchase();
    void cancel();
    void block();
    void unblock();
};
#endif // SEAT_H