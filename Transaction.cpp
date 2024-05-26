//
// Created by Francesco Ciarini on 25/05/24.
//

#include "Transaction.h"
#include <chrono>
#include <ctime>
#include <iomanip>


Transactions::Transactions(double amount, std:: string& des): amount(amount), description(des){
    time_t now= time(0);
    data= *localtime(&now);
}

void Transactions::printTransaction() const {
    std::cout<<"Data: "<< std::put_time(&data, "%Y-%m-%d %H:%M:%S | ") << "Amount: "<< amount << " | Description: "<< description <<std::endl;
}


