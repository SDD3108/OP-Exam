#include <iostream>
#include <string>
#include "studentFare.h"
// StudentFare.cpp
// Здесь реализуется расчет студенческого тарифа.
//
// Что нужно реализовать:
// 1. Взять базовую цену.
// 2. Применить студенческую скидку.
// 3. Учитывать время до события.
// 4. Вернуть финальную цену.

int FareStrategy::calculateFinalPrice(int price,int hoursBeforeEvent){
    int finalPrice = price;
    int discount = 0.7;
    if(hoursBeforeEvent <= 24){
        discount = 1.2;
    }
    if(hoursBeforeEvent <= 168){
        discount = 0.5;
    }
    finalPrice *= discount;

    return finalPrice;
}