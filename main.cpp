#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <memory>
#include <iomanip>
#include <ctime>

#include "common/seatCategory.h"
#include "states/seatState.h"
#include "models/seat.h"
#include "models/event.h"
#include "models/user.h"
#include "tariffs/fareStrategy.h"
#include "services/bookingService.h"
#include "states/freeState.h"
#include "tariffs/childFare.h"
#include "tariffs/studentFare.h"
#include "tariffs/fullFare.h"

using namespace std;

int main() {
    try{
        User user(1,"Damir",50000.0,PassengerType::STUDENT);

        cout << "User created " << user.getUserName() << endl;
        cout << "Initial balance " << user.getUserBalance() << endl;

        auto startTime = chrono::system_clock::now() + chrono::hours(72);
        Event event(1,"Puss in Buts",startTime);
        cout << "Event created: " << event.getTitle() << endl;
        cout << "Hours before event: " << event.getHoursBeforeEvent() << endl;

        event.addSeat(Seat(1,SeatCategory::VIP,30000,make_unique<FreeState>()));
        event.addSeat(Seat(2,SeatCategory::STANDARD,15000,make_unique<FreeState>()));
        event.addSeat(Seat(3,SeatCategory::ECONOMY,8000,make_unique<FreeState>()));
        cout << "Seats added" << endl;


        cout << "Free seats before it " << endl;

        vector<Seat*> availableSeats = event.getFreeSeats();

        for(Seat* seat : availableSeats){
            cout << "Seat number " << seat->getSeatNumber() << ", state " << seat->getStateName() << ", base price " << seat->getBasePrice() << endl;
        }
        ChildFare childFare;
        StudentFare studentFare;
        FullFare fullFare;
        FareStrategy& selectedFare = studentFare;
        BookingService bookingService;

        Seat* selectedSeat = event.findSeatByNumber(2);
        if(selectedSeat == nullptr){
            throw logic_error("Seat not found");
        }

        cout << "Selected seat before it " << endl;
        cout << "Seat number " << selectedSeat->getSeatNumber() << endl;
        cout << "Seat state " << selectedSeat->getStateName() << endl;

        Ticket ticket = bookingService.bookSeat(user,event,*selectedSeat,selectedFare);
        cout << "buying completed " << endl;
        cout << "User balance after it "<< user.getUserBalance() << endl;
        cout << "Seat state after it " << selectedSeat->getStateName() << endl;
        cout << "Created ticket " << endl;
        ticket.printTicket();
        cout << "free seats after it" << endl;

        vector<Seat*> availableSeatsAfterBooking = event.getFreeSeats();
        for (Seat* seat : availableSeatsAfterBooking) {
            cout << "Seat number " << seat->getSeatNumber() << ", state " << seat->getStateName() << ", base price " << seat->getBasePrice() << endl;
        }

        cout << "checking buying the same seat again " << endl;

        Ticket secondTicket = bookingService.bookSeat(
            user,
            event,
            *selectedSeat,
            selectedFare
        );
        secondTicket.printTicket();

    }
    catch(const exception& error){
        cout << "error " << error.what() << endl;
    }
}
