#ifndef FARE_STRATEGY_H
#define FARE_STRATEGY_H
#include <string>
using namespace std;

class FareStrategy{
    public: 
        FareStrategy(){};
        virtual double calculateFinalPrice(double price,int hoursBeforeEvent) const = 0;
        virtual string getName() const = 0;
        ~FareStrategy() = default;
};
#endif // FARE_STRATEGY_H