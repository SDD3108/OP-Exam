#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include "models/ticket.h"
using namespace std;

Ticket::Ticket(int tid,int uid,int eid,int sn,SeatCategory sc,double fc,chrono::system_clock::time_point ca):ticket_id(tid),user_id(uid),event_id(eid),seatNumber(sn),seatCategory(sc),finalCost(fc),createAt(ca){

}

int Ticket::getTicketId() const {
    return ticket_id;
}
int Ticket::getUserId() const {
    return user_id;
}
int Ticket::getEventId() const {
    return event_id;
}
int Ticket::getSeatNumber() const {
    return seatNumber;
}
SeatCategory Ticket::getSeatCategory() const {
    return seatCategory;
}
double Ticket::getFinalCost() const {
    return finalCost;
}

chrono::system_clock::time_point Ticket::getCreatingAt() const{
    return createAt;
};

void Ticket::printTicket() const {
    time_t createdTime = chrono::system_clock::to_time_t(createAt);

    cout << "TICKET" << endl;
    cout << "Ticket ID " << ticket_id << endl;
    cout << "User ID " << user_id << endl;
    cout << "Event ID " << event_id << endl;
    cout << "Seat number " << seatNumber << endl;
    cout << "Seat category ";

    switch(seatCategory){
        case SeatCategory::VIP:
            cout << "VIP";
            break;
        case SeatCategory::STANDARD:
            cout << "STANDARD";
            break;
        case SeatCategory::ECONOMY:
            cout << "ECONOMY";
            break;
        default:
            cout << "error" << endl;
            break;
    }

    cout << endl;

    cout << "Final cost " << finalCost << endl;

    cout << "Created at " << put_time(localtime(&createdTime), "%Y-%m-%d %H:%M:%S") << endl;

    cout << "" << endl;
}