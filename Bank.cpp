//
// Created by Francesco Ciarini on 25/05/24.
//


#include <iostream>
#include <vector>
#include <string>
#include "memory"
#include "Bank.h"
#include "BankAccount.h"
#include "TransactionException.h"

int Bank::nextIBAN = 10001000;

void Bank::addAccount(std::string name, std::string surname, double openingBalance, bool member) {
    BankAccount newAccount(name, surname, nextIBAN, openingBalance, member);
    accounts.push_back(newAccount);
    std::cout << "The IBAN of " << name << " " << surname << " is: " << nextIBAN << std::endl;
    nextIBAN++;

}

BankAccount* Bank::findAccount(const int IBAN) {

    for (auto &account: accounts)
        if (account.getIBAN() == IBAN)
            return &account;

    return nullptr;
}

void Bank::doTransaction(int IBAN, double amount, std::string des) {

    BankAccount *accountTemp = findAccount(IBAN);

    if (accountTemp)
        accountTemp->doTransaction(amount, des);
    else
        throw TransactionException("Account not found. ", false);
}

void Bank::printAccountTransaction(const int IBAN) {
    BankAccount *accountTemp = findAccount(IBAN);

    if (accountTemp)
        std::cout << accountTemp->toString();
    else
        throw TransactionException("Account not found. ", false);
}

bool Bank::removeTransaction(int IBAN, size_t idx) {
    BankAccount* acc = findAccount(IBAN);
    if (!acc)
        throw TransactionException("Account not found.", false);
    return acc->removeTransaction(idx);
}

std::vector<Transaction> Bank::searchTransactions(int IBAN, const std::string &keyword) {
    BankAccount* acc = findAccount(IBAN);
    if(!acc)
        throw TransactionException("Account not found.", false);
    return acc->searchTransactions(keyword);
}

