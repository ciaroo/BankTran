//
// Created by Francesco Ciarini on 25/05/24.
//

#ifndef BANKTRAN_TRANSACTION_H
#define BANKTRAN_TRANSACTION_H

#include <chrono>
#include <ctime>
#include "iostream"

class Transactions {
public:
    Transactions(double amount, std:: string& des);

    void printTransaction() const ;

private:
    double amount;
    std::tm data;
    std:: string description;
};

#endif //BANKTRAN_TRANSACTION_H
