#ifndef STUDENT_FARE_H
#define STUDENT_FARE_H
#include "fareStrategy.h"
// StudentFare.h
// Тариф для студента.
//
// Что нужно сделать:
// 1. Описать студенческий тариф.
// 2. Студенческий тариф должен быть дешевле полного,
//    но обычно дороже детского.
//
// Можно добавить условие:
// Студенческая скидка действует только при наличии типа STUDENT у пользователя.

class StudentFare : public FareStrategy {
    public:
        int calculateFinalPrice(int price,int hoursBeforeEvent) override;
};


#endif // STUDENT_FARE_H

