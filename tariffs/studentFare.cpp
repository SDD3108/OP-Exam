#include <iostream>
#include <string>
#include "tariffs/studentFare.h"


double StudentFare::calculateFinalPrice(double price,int hoursBeforeEvent) const {
    double finalPrice = price;
    double discount = 0.7;
    if(hoursBeforeEvent <= 24){
        discount = 1.2;
    }
    if(hoursBeforeEvent <= 168){
        discount = 0.5;
    }
    finalPrice *= discount;

    return finalPrice;
}
string StudentFare::getName() const {
    return "Student";
}