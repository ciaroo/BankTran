//
// Created by Francesco Ciarini on 25/05/24.
//

#include "Bank.h"
#include "BankAccount.h"
#include "Transaction.h"

BankAccount::BankAccount(std::string &name, std::string &surname, int iban, double openingBalance, bool member) : name(
        name), surname(surname), IBAN(iban), balance(openingBalance), member(member) {
    if (member)
        std::cout << "Hi, " << name
                  << "! You are a member of the bank. You will receive 5 member points with every deposit! "
                  << std::endl;
}

void BankAccount::deposit(double amount, std::string &des) {
    if (amount==0)
        throw std::invalid_argument("Zero amount. ");
    balance += amount;
    transactions.emplace_back(amount, des);
    if (member)
        memberpoint += 5;
}

void BankAccount::withdraw(double amount, std::string &des) {
    if (amount==0)
        throw std::invalid_argument("Zero amount. ");
    if (amount <= balance) {
        balance -= amount;
        transactions.emplace_back(-amount, des);
    } else
        throw std::invalid_argument("The selected amount is higher than availability.");
}

void BankAccount::printAccountBalance() {
    if (member)
        std::cout << std::endl << "Account: " << name << " " << surname << " | IBAN: " << IBAN << " | Balance: "
                  << balance << " | Member Point: " << memberpoint << std::endl;
    else
        std::cout << std::endl << "Account: " << name << " " << surname << " | IBAN: " << IBAN << " | Balance: "
                  << balance << std::endl;

    for (const auto &transaction: transactions) {
        transaction.printTransaction();
    }

}




