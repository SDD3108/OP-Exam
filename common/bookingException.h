#ifndef BOOKING_EXCEPTION_H
#define BOOKING_EXCEPTION_H
#include <iostream>
#include <string>
using namespace std;

// BookingException.h
// Здесь можно описать ошибки бронирования.
//
// Что нужно сделать:
// 1. Добавить ошибки для ситуаций:
//    - место уже занято;
//    - место заблокировано;
//    - недостаточно денег;
//    - неверный переход состояния;
//    - событие не найдено;
//    - пользователь не найден.
//
// Для чего нужно:
// Чтобы система не просто падала, а объясняла причину ошибки.

class BookingException : public runtime_error{
    public: 
        BookingException(string& message):runtime_error(message){
        };
};
#endif // BOOKING_EXCEPTION_H