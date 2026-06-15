#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

#include "passengerType.h";

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

class User{
    private:
        int id;
        string name;
        double balance;
        PassengerType passengerType;
    public:
        User(int i,const string& n,double b,PassengerType pt){};
        int getUserId() const;
        string getUserName() const;
        double getUserBalance() const;
        bool haveEnoughMoney(double amount) const;
        bool removeBalance(double amount);
        bool addBalance(double amount);
};

#endif // USER_H