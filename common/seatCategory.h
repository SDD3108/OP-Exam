#ifndef SEAT_CATEGORY_H
#define SEAT_CATEGORY_H

#include <string>
using namespace std;

enum class SeatCategory {
    VIP,
    STANDARD,
    ECONOMY
};

inline string getSeatCategory(SeatCategory category) {
    switch (category) {
        case SeatCategory::VIP:
            return "VIP";

        case SeatCategory::STANDARD:
            return "STANDARD";

        case SeatCategory::ECONOMY:
            return "ECONOMY";

        default:
            return "unknown";
    }
}

inline double getSeatCost(SeatCategory category) {
    switch (category) {
        case SeatCategory::VIP:
            return 10000.0;

        case SeatCategory::STANDARD:
            return 3500.0;

        case SeatCategory::ECONOMY:
            return 2500.0;

        default:
            return -1.0;
    }
}

#endif // SEAT_CATEGORY_H