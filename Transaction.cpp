//
// Created by Francesco Ciarini on 25/05/24.
//

#include "Transaction.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>


Transactions::Transactions(double amount, const std::string &des) : amount(amount), description(des) {
    time_t now = time(0);
    data = *localtime(&now);
}

std::string Transactions::toString() const {
    std::ostringstream oss;
    oss << "Data: " << std::put_time(&data, "%Y-%m-%d %H:%M:%S")
        << " | Amount: " << amount
        << " | Description: " << description;
    return oss.str();

}

double Transactions::getAmount() const {
    return amount;
}


