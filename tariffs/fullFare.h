#ifndef FULL_FARE_H
#define FULL_FARE_H
#include "tariffs/fareStrategy.h"

class FullFare : public FareStrategy{
    public:
        double calculateFinalPrice(double price,int hoursBeforeEvent) const override;
        string getName() const override;
};

#endif // FULL_FARE_H
