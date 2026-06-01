// ChildFare.cpp
// Здесь реализуется расчет детского тарифа.
//
// Что нужно реализовать:
// 1. Взять базовую цену места.
// 2. Применить детскую скидку.
// 3. Применить коэффициент времени до события.
// 4. Вернуть финальную стоимость.
//
// Важно:
// Конкретные проценты можно выбрать самостоятельно,
// если они не указаны в задании.
#include <iostream>
#include <string>
#include "childFare.h"
using namespace std;

int FareStrategy::calculateFinalPrice(int price,int hoursBeforeEvent){
    int finalPrice = price;
    int discount = 0.5;
    if(hoursBeforeEvent <= 24){
        discount = 1.2;
    }
    if(hoursBeforeEvent <= 168){
        discount = 0.9;
    }
    finalPrice *= discount;

    return finalPrice;
}