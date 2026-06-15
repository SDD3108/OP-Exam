#ifndef BOOKING_EXCEPTION_H
#define BOOKING_EXCEPTION_H
#include <iostream>
#include <string>
using namespace std;

class BookingException : public runtime_error{
    public: 
        BookingException(string& message):runtime_error(message){
        };
};
#endif // BOOKING_EXCEPTION_H