//
// Created by Francesco Ciarini on 25/05/24.
//

#include "Bank.h"
#include "BankAccount.h"
#include "Transaction.h"
#include "TransactionException.h"
#include <stdexcept>


BankAccount::BankAccount(const std::string &name, const std::string &surname, int iban, double openingBalance, bool member) : name(
        name), surname(surname), IBAN(iban), balance(openingBalance), member(member) {
    if (openingBalance < 0) {
        throw std::invalid_argument("Opening balance cannot be negative");
    }
    if (member)
        std::cout << "Hi, " << name
                  << "! You are a member of the bank. You will receive 5 member points with every deposit! "
                  << std::endl;
    else
        std::cout << "Hi, " << name << "! Account added successfully!"<< std::endl;
}

void BankAccount::doTransaction(double amount,const std::string &des) {
    if (amount==0)
        throw TransactionException("Amount not valid. ", false);
    balance += amount;
    transactions.emplace_back(amount, des);
    if (member)
        memberPoint += 5;
}

void BankAccount::addTransaction(const Transaction &t) {
    transactions.push_back(t);
    balance += t.getAmount();
    if (member) memberPoint += 5;
}

bool BankAccount::removeTransaction(size_t idx) {
    if (idx >= transactions.size())
        return false;
    auto it = transactions.begin();
    std::advance(it, idx);
    double amt = it->getAmount();
    transactions.erase(it);
    balance -= amt;
    return true;
}

std::vector<Transaction> BankAccount::searchTransactions(const std::string &keyword) const {
    std::vector<Transaction> results;
    for (auto const &t : transactions) {
        if (t.toString().find(keyword) != std::string::npos)
            results.push_back(t);
    }
    return results;
}

std::string BankAccount::toString() const {
    std::ostringstream oss;
    oss << "Account: " << name << " " << surname
        << " | IBAN: " << IBAN
        << " | Balance: " << balance;
    if (member)
        oss << " | Member Points: " << memberPoint;
    oss << "\n";

    size_t idx = 0;
    for (const auto &tr : transactions) {
        oss << "[" << idx++ << "] " << tr.toString() << "\n";
    }
    return oss.str();
}

size_t BankAccount::getTransactionCount() const {
    return transactions.size();
}

double BankAccount::getBalance() const {
    return balance;
}

int BankAccount::getMemberPoint() const {
    return memberPoint;
}

const std::string &BankAccount::getSurname() const {
    return surname;
}

const std::string &BankAccount::getName() const {
    return name;
}



