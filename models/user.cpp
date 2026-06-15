#include <iostream>
#include <string>
#include <vector>
#include "models/user.h"
using namespace std;

User::User(int i,const string& n,double b,PassengerType pt):id(i),name(n),balance(b),passengerType(pt){

};
int User::getUserId() const {
    return id;
};
string User::getUserName() const{
    return name;
};
double User::getUserBalance() const{
    return balance;
};
bool User::haveEnoughMoney(double amount) const{
    return balance >= amount ? true : false;
};
bool User::removeBalance(double amount){
    if(amount <= 0){
        return false;
    };
    if(!haveEnoughMoney(amount)){
        return false;
    }
    balance -= amount;
    return true;
};
bool User::addBalance(double amount){
    if(amount > 0){
        balance += amount;
        return true;
    }
    else{
        return false;
    }
};
