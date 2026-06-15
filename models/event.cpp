#include "event.h"

#include <utility>
#include <string>
#include <vector>
using namespace std;

Event::Event(int id,const string& title,chrono::system_clock::time_point startTime):id(id),title(title),startTime(startTime){

};
int Event::getId() const{
    return id;
};
string Event::getTitle() const{
    return title;
};
chrono::system_clock::time_point Event::getStartTime() const {
    return startTime;
};
void Event::addSeat(Seat&& seat){
    seats.push_back(std::move(seat));
};

Seat* Event::findSeatByNumber(int number){
    for(auto& seat : seats){
        if(seat.getSeatNumber() == number){
            return &seat;
        }
    };
    return nullptr;
};

int Event::getHoursBeforeEvent() const{
    auto now = chrono::system_clock::now();
    auto difference = startTime - now;
    auto hours = chrono::duration_cast<chrono::hours>(difference);

    return static_cast<int>(hours.count());
};
vector<Seat*> Event::getFreeSeats(){
    vector<Seat*> freeSeats;
    for(auto& seat : seats){
        if(seat.isAvailable()){
            freeSeats.push_back(&seat);
        }
    }
    return freeSeats;
};
vector<Seat>& Event::getSeats(){
    return seats;
}