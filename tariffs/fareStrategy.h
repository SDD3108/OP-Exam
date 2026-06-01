#ifndef FARE_STRATEGY_H
#define FARE_STRATEGY_H

// FareStrategy.h
// Это базовый интерфейс для всех тарифов.
//
// Что нужно сделать:
// 1. Описать общий метод расчета цены.
// 2. Метод должен принимать:
//    - базовую цену места;
//    - время до события;
//    - возможно, категорию места;
//    - возможно, данные пользователя.
//
// Для чего нужен полиморфизм:
// BookingService не должен знать, как именно считается детский,
// студенческий или полный тариф.
//
// Он просто вызывает общий метод calculateFinalPrice.
class FareStrategy{
    public: 
        FareStrategy(){};
        virtual int calculateFinalPrice(int price,int hoursBeforeEvent);
        ~FareStrategy() = default;
};
#endif // FARE_STRATEGY_H