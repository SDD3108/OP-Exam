#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

// User.h
// Здесь объявляется класс User.
//
// Что должен хранить User:
// 1. id пользователя.
// 2. Имя пользователя.
// 3. Баланс пользователя.
// 4. Тип пассажира:
//    - ребенок;
//    - студент;
//    - взрослый.
//
// Что должен уметь User:
// 1. Возвращать свой id.
// 2. Возвращать имя.
// 3. Возвращать баланс.
// 4. Проверять, хватает ли денег на покупку билета.
// 5. Списывать деньги с баланса.
// 6. Пополнять баланс.
//
// Важно:
// Поле balance должно быть private.
// Нельзя напрямую менять баланс снаружи.
// Списание должно идти через отдельный метод.

User::User(int i,string& n,double b,PassengerType pt):id(i),name(n),balance(b),passengerType(pt){

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
