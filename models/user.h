#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

#include "common/passengerType.h"

class User{
    private:
        int id;
        string name;
        double balance;
        PassengerType passengerType;
    public:
        User(int i,const string& n,double b,PassengerType pt);
        int getUserId() const;
        string getUserName() const;
        double getUserBalance() const;
        bool haveEnoughMoney(double amount) const;
        bool removeBalance(double amount);
        bool addBalance(double amount);
};

#endif // USER_H