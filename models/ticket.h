#ifndef TICKET_H
#define TICKET_H
using namespace std;
#include "seatCategory.h"
#include <chrono>
// Ticket.h
// Здесь объявляется класс Ticket.
//
// Что должен хранить Ticket:
// 1. id билета.
// 2. id пользователя.
// 3. id события.
// 4. Номер места.
// 5. Категорию места.
// 6. Финальную цену.
// 7. Время создания билета.
//
// Что должен уметь Ticket:
// 1. Возвращать информацию о билете.
// 2. Печатать билет в консоль.
// 3. Хранить итоговую стоимость после применения тарифа.
//
// Важно:
// Ticket создается только после успешной оплаты.
// Если оплата не прошла, Ticket создаваться не должен.

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