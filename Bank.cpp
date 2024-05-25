//
// Created by Francesco Ciarini on 25/05/24.
//


#include <iostream>
#include <vector>
#include <string>
#include "Bank.h"
#include "BankAccount.h"

int Bank::IBAN=10001000;

void Bank::addAccount(std:: string name, std::string surname, double openingBalance) {
    BankAccount newAccount (name, surname, IBAN++, openingBalance);
    accounts.push_back(newAccount);

}

BankAccount *Bank::findAccount(const int IBAN) {
    for(auto & account : accounts)
        if(account.getIBAN()==IBAN)
            return &account;
    return nullptr;
}

void Bank::deposit(const int IBAN, int amount, std::string des) {
    BankAccount* accountTemp = findAccount(IBAN);

    if(accountTemp)
        accountTemp->deposit(amount,des);
    else
        std::cout<<"Account not found. "<< std::endl;
}

void Bank::withdraw(const int IBAN, int amount, std::string des) {
    BankAccount* accountTemp = findAccount(IBAN);

    if(accountTemp)
        accountTemp->withdraw(amount,des);
    else
        std::cout<<"Account not found. "<< std::endl;
}

void Bank::printAccountTransaction(const int IBAN) {
    BankAccount* accountTemp = findAccount(IBAN);

    if(accountTemp)
        accountTemp->printAccountBalance();
    else
        std::cout<<"Account not found. "<< std::endl;

}



