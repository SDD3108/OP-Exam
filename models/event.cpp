#include <iostream>
#include <string>
#include <vector>
#include "event.h"
#include <chrono>
#include "seat.h"
using namespace std;

// Event.cpp
// Здесь реализуется логика Event.
//
// Что нужно реализовать:
// 1. Конструктор события.
// 2. Добавление мест.
// 3. Поиск места по номеру.
// 4. Получение времени начала события.
// 5. Получение списка свободных мест.
//
// Важно:
// Event не должен списывать деньги.
// Event не должен создавать Ticket.
// Это задача BookingService.

Event::Event(int id, const string& title,chrono::system_clock::time_point startTime){

};
int Event::getId() const {
    return id;
};
string Event::getTitle() const {
    return title;
};
chrono::system_clock::time_point Event::getStartTime() const {
    return startTime;
};
void Event::addSeat(Seat&& seat){
    
};