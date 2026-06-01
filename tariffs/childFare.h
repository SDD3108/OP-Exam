#ifndef CHILD_FARE_H
#define CHILD_FARE_H

// ChildFare.h
// Тариф для ребенка.
//
// Что нужно сделать:
// 1. Описать детский тариф.
// 2. Детский тариф должен давать скидку от базовой цены.
// 3. Также можно учитывать время до рейса.
//
// Пример логики:
// Если до рейса много времени — обычная скидка.
// Если до рейса мало времени — цена может немного увеличиться.

#include "fareStrategy.h";
#include <string>

class ChildFare : public FareStrategy {
    public:
        int calculateFinalPrice(int price,int hoursBeforeEvent) override;
};

#endif // CHILD_FARE_H