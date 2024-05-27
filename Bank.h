//
// Created by Francesco Ciarini on 25/05/24.
//

#ifndef BANKTRAN_BANK_H
#define BANKTRAN_BANK_H

#include <iostream>
#include <vector>
#include <string>
#include "BankAccount.h"

class Bank {
public:
    void addAccount(std::string name, std::string surname, double openingBalance, bool member = false);

    BankAccount *findAccount(const int IBAN);

    void deposit(const int IBAN, int amount, std::string des = "DEPOSIT");

    void withdraw(const int IBAN, int amount, std::string des = "WITHDRAW");


    void printAccountTransaction(const int IBAN);


private:
    std::vector<BankAccount> accounts;
    static int IBAN;

};


#endif //BANKTRAN_BANK_H
