#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "states/seatState.h"
#include "common/seatCategory.h"
#include "common/passengerType.h"
#include "tariffs/fareStrategy.h"
#include "tariffs/childFare.h"
#include "tariffs/studentFare.h"
#include "tariffs/fullFare.h"
#include "services/bookingService.h"
#include "models/user.h"
#include "states/purchasedState.h"
#include "models/ticket.h"
using namespace std;

BookingService::BookingService():nextTicketId(1){};

int BookingService::generateTicketId(){
    return nextTicketId++;
}

Ticket BookingService::bookSeat(User& user,Event& event,Seat& seat,FareStrategy& fare){
    if(!seat.isAvailable()){
        throw logic_error("Booking failed, seat is not available");
    }
    double basePrice = seat.getBasePrice();
    int hoursBeforeEvent = event.getHoursBeforeEvent();
    double finalPrice = fare.calculateFinalPrice(basePrice, hoursBeforeEvent);

    if(finalPrice <= 0){
        throw logic_error("Booking failed, final price is invalid");
    }
    if(!user.haveEnoughMoney(finalPrice)){
        throw logic_error("Booking failed: not enough money.");
    }
    bool paymentSuccess = user.removeBalance(finalPrice);
    if(!paymentSuccess){
        throw logic_error("Booking failed: payment was not completed.");
    }
    seat.purchase();

    Ticket ticket(generateTicketId(),user.getUserId(),event.getId(),seat.getSeatNumber(),seat.getCategory(),finalPrice,chrono::system_clock::now());

    return ticket;
}