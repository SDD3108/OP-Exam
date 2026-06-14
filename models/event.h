#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <vector>
using namespace std;

// Event.h
// Здесь объявляется класс Event.
//
// Event — это сеанс, рейс, поездка или фильм.
//
// Что должен хранить Event:
// 1. id события.
// 2. Название события.
// 3. Время начала события.
// 4. Список мест.
// 5. Возможно, пункт отправления и назначения, если это рейс или поезд.
//
// Что должен уметь Event:
// 1. Возвращать информацию о событии.
// 2. Добавлять места.
// 3. Искать место по номеру.
// 4. Возвращать время до начала события.
// 5. Показывать список доступных мест.
//
// Важно:
// Время до события нужно для расчета тарифа.
// Например, чем ближе время рейса, тем дороже может быть билет.

#pragma once

#include <chrono>
#include "seat.h"
using namespace std;
class Event {
    private:
        int id;
        string title;
        chrono::system_clock::time_point startTime;
        vector<Seat> seats;
    public:
        Event(int id, const string& title,chrono::system_clock::time_point startTime);

        int getId() const;
        string getTitle() const;

        chrono::system_clock::time_point getStartTime() const;

        void addSeat(Seat&& seat);
        Seat* findSeatByNumber(int number);

        int getHoursBeforeEvent() const;
        vector<Seat*> getFreeSeats();
        vector<Seat>& getSeats();
};

#endif // EVENT_H