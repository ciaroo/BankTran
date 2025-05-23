//
// Created by Francesco Ciarini on 25/05/24.
//

#ifndef BANKTRAN_TRANSACTION_H
#define BANKTRAN_TRANSACTION_H

#include <chrono>
#include <ctime>
#include "iostream"
#include <string>
#include "TransactionException.h"

class Transaction {
public:
    Transaction(double amount, const std::string &des);

    std::string toString() const;

    double getAmount() const;

    const std::string &getDescription() const;

private:
    double amount;
    std::tm data;
    std::string description;
};

#endif //BANKTRAN_TRANSACTION_H
