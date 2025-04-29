//
// Created by Francesco Ciarini on 25/05/24.
//

#include "Transaction.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>


Transaction::Transaction(double amount, const std::string &des) : amount(amount), description(des) {
    time_t now = time(0);
    data = *localtime(&now);
}

std::string Transaction::toString() const {
    std::ostringstream oss;
    oss << "Data: " << std::put_time(&data, "%Y-%m-%d %H:%M:%S")
        << " | Amount: " << amount
        << " | Description: " << description;
    return oss.str();

}

double Transaction::getAmount() const {
    return amount;
}


