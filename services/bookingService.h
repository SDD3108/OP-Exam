#ifndef BOOKING_SERVICE_H
#define BOOKING_SERVICE_H

#include <string>

#include "models/user.h"
#include "models/event.h"
#include "models/seat.h"
#include "tariffs/fareStrategy.h"
#include "models/ticket.h"
using namespace std;

class BookingService{
    private:
        int nextTicketId;
        int generateTicketId();
    public:
        BookingService();
        Ticket bookSeat(User& user,Event& event,Seat& seat,FareStrategy& fare);

};

#endif // BOOKING_SERVICE_H