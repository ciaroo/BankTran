//
// Created by Francesco Ciarini on 25/05/24.
//

#include "Bank.h"
#include "BankAccount.h"
#include "Transaction.h"
#include "TransactionException.h"


BankAccount::BankAccount(std::string &name, std::string &surname, int iban, double openingBalance, bool member) : name(
        name), surname(surname), IBAN(iban), balance(openingBalance), member(member) {
    if (member)
        std::cout << "Hi, " << name
                  << "! You are a member of the bank. You will receive 5 member points with every deposit! "
                  << std::endl;
    else
        std::cout << "Hi, " << name << "! Account added successfully!"<< std::endl;
}

void BankAccount::doTransaction(double amount, std::string &des) {
    if (amount==0 || amount < balance)
        throw TransactionException("Amount not valid. ", false);
    balance += amount;
    transactions.emplace_back(amount, des);
    if (member)
        memberpoint += 5;
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




