//
// Created by Francesco Ciarini on 25/05/24.
//

#include "Bank.h"
#include "BankAccount.h"
#include "Transaction.h"

BankAccount::BankAccount(std::string& name, std::string& surname, int iban, double openingBalance): name(name), surname(surname), IBAN(iban), balance(openingBalance) {
}

void BankAccount::deposit(double amount, std::string& des) {
    balance+=amount;
    transactions.emplace_back(amount, des);

}

void BankAccount::withdraw(double amount, std::string& des) {
    if(amount<=balance) {
        balance -= amount;
        transactions.emplace_back(-amount, des);
    }
    else
        std::cout<<"The selected amount is higher than availability."<< std::endl;
}

void BankAccount::printAccountBalance() {
    std::cout << std::endl<< "IBAN: " << IBAN << ", Balance: " << balance << std::endl;
    for (const auto& transaction : transactions) {
        transaction.printTransition();
    }

}




