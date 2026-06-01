#ifndef FULL_FARE_H
#define FULL_FARE_H
#include "fareStrategy.h"

// FullFare.h
// Полный тариф для взрослого пассажира.
//
// Что нужно сделать:
// 1. Описать обычный тариф без возрастной скидки.
// 2. Цена может зависеть только от категории места и времени до события.
//
// Пример:
// VIP имеет высокую базовую цену.
// Economy имеет низкую базовую цену.
// Если до рейса осталось мало времени, можно применить повышающий коэффициент.

class FullFare : public FareStrategy{
    public:
        int calculateFinalPrice(int price,int hoursBeforeEvent) override;
};

#endif // FULL_FARE_H
