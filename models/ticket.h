#ifndef TICKET_H
#define TICKET_H
using namespace std;
#include "common/seatCategory.h"
#include <chrono>

class Ticket{
    private:
        int ticket_id;
        int user_id;
        int event_id;
        int seatNumber;
        SeatCategory seatCategory;
        double finalCost;
        chrono::system_clock::time_point createAt;
    public:
        Ticket(int ticket_id,int user_id,int event_id,int seatNumber,SeatCategory SeatCategory,double finalCost,chrono::system_clock::time_point createAt);
        int getTicketId() const;
        int getUserId() const;
        int getEventId() const;
        int getSeatNumber() const;
        SeatCategory getSeatCategory() const;
        double getFinalCost() const;
        chrono::system_clock::time_point getCreatingAt() const;
        void printTicket() const;
        
    
};

#endif // TICKET_H