#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
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
    Event(int id,const string& title,chrono::system_clock::time_point startTime);

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