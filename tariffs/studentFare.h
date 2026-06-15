#ifndef STUDENT_FARE_H
#define STUDENT_FARE_H
#include "tariffs/fareStrategy.h"
#include <string>
using namespace std;

class StudentFare : public FareStrategy{
    public:
        double calculateFinalPrice(double price,int hoursBeforeEvent) const override;
        string getName() const override;
};


#endif // STUDENT_FARE_H

