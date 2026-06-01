#ifndef PASSENGER_TYPE_H
#define PASSENGER_TYPE_H
#include <string>
using namespace std;

enum class PassengerType{
    CHILD,
    STUDENT,
    ADULT,
};

string getPassengerType(PassengerType passenger){
    switch(passenger){
        case PassengerType::ADULT:
            return "ADULT";
        break;
        case PassengerType::STUDENT:
            return "STUDENT";
        break;
        case PassengerType::CHILD:
            return "CHILD";
        break;
        default:
            return "unknown";
        break;
    }
}
#endif // PASSENGER_TYPE_H