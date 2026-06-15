#ifndef CHILD_FARE_H
#define CHILD_FARE_H

#include "tariffs/fareStrategy.h"
#include <string>

class ChildFare : public FareStrategy {
    public:
        double calculateFinalPrice(double price,int hoursBeforeEvent) const override;
        string getName() const override;
};

#endif // CHILD_FARE_H