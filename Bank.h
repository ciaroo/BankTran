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

    void doTransaction(int IBAN, double amount, std::string des = "Transaction");

    void printAccountTransaction(int IBAN);

    bool removeTransaction(int IBAN, size_t idx);

    std::vector<Transaction> searchTransactions(int IBAN, const std::string &keyword);


private:
    std::list<BankAccount> accounts;
    static int nextIBAN;

};


#endif //BANKTRAN_BANK_H
