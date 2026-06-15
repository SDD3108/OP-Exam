#include <iostream>
#include <string>
#include "tariffs/fullFare.h"


double FullFare::calculateFinalPrice(double price,int hoursBeforeEvent) const {
    double finalPrice = price;
    double discount = 1;
    if(hoursBeforeEvent <= 24){
        discount = 1.2;
    }
    if(hoursBeforeEvent <= 168){
        discount = 0.8;
    }
    finalPrice *= discount;

    return finalPrice;
};
string FullFare::getName() const {
    return "Full";
}