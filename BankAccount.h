//
// Created by Francesco Ciarini on 25/05/24.
//

#ifndef BANKTRAN_BANKACCOUNT_H
#define BANKTRAN_BANKACCOUNT_H
#include <iostream>
#include <list>

#include "Transaction.h"
#include "Bank.h"


class BankAccount{
public:
    BankAccount (std::string& name, std::string& surname,int iban, double openingBalance);

    void deposit(double amount, std::string& des);

    void withdraw(double amount, std::string& des);

    void printAccountBalance();

    int getIBAN(){
        return IBAN;
    };


private:
    std::list<Transactions> transactions;
    std:: string name;
    std:: string surname;
    int IBAN;

    double balance;
};


#endif //BANKTRAN_BANKACCOUNT_H
