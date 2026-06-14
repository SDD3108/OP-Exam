#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "seatState.h"
#include "seatCategory.h"
#include "passengerType.h"
#include "fareStrategy.h"
#include "childFare.h"
#include "studentFare.h"
#include "fullFare.h"
#include "bookingService.h"
#include "user.h"
#include "purchasedState.h"
#include "ticket.h"

using namespace std;

// BookingService.cpp
// Здесь реализуется основная логика покупки / бронирования билета.
//
// Последовательность bookSeat:
//
// 1. Проверить, что место доступно.
//    Если место не FreeState, выбросить ошибку или вернуть отказ.
//
// 2. Получить базовую цену места.
//    Базовая цена зависит от категории:
//    VIP, STANDARD, ECONOMY.
//
// 3. Рассчитать финальную цену через FareStrategy.
//    Например:
//    ChildFare, StudentFare, FullFare.
//
// 4. Проверить баланс пользователя.
//    Если денег недостаточно, операция отменяется.
//
// 5. Списать деньги с баланса пользователя.
//    Баланс нельзя менять напрямую.
//
// 6. Перевести место в PurchasedState.
//    Потому что по ТЗ метод bookSeat списывает деньги
//    и генерирует Ticket.
//
// 7. Создать объект Ticket.
//    Ticket должен содержать:
//    - пользователя;
//    - событие;
//    - место;
//    - категорию места;
//    - финальную цену.
//
// 8. Вернуть Ticket.
//
// Важно:
// Повторный вызов bookSeat для того же места должен быть невозможен,
// потому что состояние места уже будет PurchasedState.

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

    // 8. Создать объект Ticket.
    Ticket ticket(
        generateTicketId(),
        user.getUserId(),
        event.getId(),
        seat.getSeatNumber(),
        seat.getCategory(),
        finalPrice,
        chrono::system_clock::now()
    );

    // 9. Вернуть созданный билет.
    return ticket;
}