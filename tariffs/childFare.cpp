#include <iostream>
#include <string>
#include "tariffs/childFare.h"
using namespace std;

double ChildFare::calculateFinalPrice(double price,int hoursBeforeEvent) const {
    double finalPrice = price;
    double discount = 0.5;
    if(hoursBeforeEvent <= 24){
        discount = 1.2;
    }
    if(hoursBeforeEvent <= 168){
        discount = 0.9;
    }
    finalPrice *= discount;

    return finalPrice;
}
string ChildFare::getName() const {
    return "Child";
}