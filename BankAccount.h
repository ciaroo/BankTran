//
// Created by Francesco Ciarini on 25/05/24.
//

#ifndef BANKTRAN_BANKACCOUNT_H
#define BANKTRAN_BANKACCOUNT_H

#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include "Transaction.h"


class BankAccount {
public:
    BankAccount(const std::string &name, const std::string &surname, int iban, double openingBalance, bool member);

    void doTransaction(double amount,const std::string &des);

    void addTransaction(const Transaction &t);

    bool removeTransaction(size_t idx);

    std::vector<Transaction> searchTransactions(const std::string &keyword) const;

    std::string toString() const;

    int getIBAN() const {
        return IBAN;
    };

    double getBalance() const;

    int getMemberPoint() const;

    const std::string &getSurname() const;

    const std::string &getName() const;

    size_t getTransactionCount() const;


private:
    std::list<Transaction> transactions;
    std::string name;
    std::string surname;
    int IBAN;
    bool member;
    int memberPoint{0};
    double balance;
};


#endif //BANKTRAN_BANKACCOUNT_H
