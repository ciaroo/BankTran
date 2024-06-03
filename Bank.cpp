//
// Created by Francesco Ciarini on 25/05/24.
//


#include <iostream>
#include <vector>
#include <string>
#include "Bank.h"
#include "BankAccount.h"
#include "TransactionException.h"

int Bank::IBAN = 10001000;

void Bank::addAccount(std::string name, std::string surname, double openingBalance, bool member) {
    BankAccount newAccount(name, surname, IBAN, openingBalance, member);
    accounts.push_back(newAccount);
    std::cout << "The IBAN of " << name << " " << surname << " is: " << IBAN << std::endl;
    IBAN++;

}

BankAccount *Bank::findAccount(const int IBAN) {

    for (auto &account: accounts)
        if (account.getIBAN() == IBAN)
            return &account;

    return nullptr;
}

void Bank::doTransaction(int IBAN, int amount, std::string des) {

    BankAccount *accountTemp = findAccount(IBAN);

    if (accountTemp)
        accountTemp->doTransaction(amount, des);
    else
        throw TransactionException("Account not found. ", false);
}

void Bank::printAccountTransaction(const int IBAN) {
    BankAccount *accountTemp = findAccount(IBAN);

    if (accountTemp)
        accountTemp->printAccountBalance();
    else
        throw TransactionException("Account not found. ", false);
}


