#include <iostream>
#include <string>
#include "fullFare.h"
// FullFare.cpp
// Здесь реализуется расчет полного тарифа.
//
// Что нужно реализовать:
// 1. Взять базовую цену.
// 2. Не применять возрастную скидку.
// 3. Применить коэффициент времени до события.
// 4. Вернуть финальную стоимость.

int FareStrategy::calculateFinalPrice(int price,int hoursBeforeEvent){
    int finalPrice = price;
    int discount = 1;
    if(hoursBeforeEvent <= 24){
        discount = 1.2;
    }
    if(hoursBeforeEvent <= 168){
        discount = 0.8;
    }
    finalPrice *= discount;

    return finalPrice;
}