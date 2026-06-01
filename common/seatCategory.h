#ifndef SEAT_CATEGORY_H
#define SEAT_CATEGORY_H
#include <string>
using namespace std;

enum class SeatCategory{
    VIP,
    STANDARD,
    ECONOMY,
};

string getSeatCategory(SeatCategory category){
    switch(category){
        case SeatCategory::VIP:
            return "VIP";
        break;
        case SeatCategory::STANDARD:
            return "STANDARD";
        break;
        case SeatCategory::ECONOMY:
            return "ECONOMY";
        break;
        default:
            return "unknown";
        break;
    }
}
int getSeatCost(SeatCategory category){
    switch(category){
        case SeatCategory::VIP:
            return 10000;
        break;
        case SeatCategory::STANDARD:
            return 3500;
        break;
        case SeatCategory::ECONOMY:
            return 2500;
        break;
        default:
            return -1;
        break;
    }
}

#endif // SEAT_CATEGORY_H