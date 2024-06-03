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

    BankAccount *findAccount(int IBAN);

    void doTransaction(int IBAN, int amount, std::string des = "Transaction");

    void printAccountTransaction(int IBAN);


private:
    std::vector<BankAccount> accounts;
    static int IBAN;

};


#endif //BANKTRAN_BANK_H
