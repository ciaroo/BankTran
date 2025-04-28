//
// Created by Francesco Ciarini on 25/05/24.
//

#include "Bank.h"
#include "BankAccount.h"
#include "Transaction.h"
#include "TransactionException.h"


BankAccount::BankAccount(const std::string &name, const std::string &surname, int iban, double openingBalance, bool member) : name(
        name), surname(surname), IBAN(iban), balance(openingBalance), member(member) {
    if (member)
        std::cout << "Hi, " << name
                  << "! You are a member of the bank. You will receive 5 member points with every deposit! "
                  << std::endl;
    else
        std::cout << "Hi, " << name << "! Account added successfully!"<< std::endl;
}

void BankAccount::doTransaction(double amount,const std::string &des) {
    if (amount==0 || amount + balance < balance)
        throw TransactionException("Amount not valid. ", false);
    balance += amount;
    transactions.emplace_back(amount, des);
    if (member)
        memberpoint += 5;
}

void BankAccount::addTransaction(const Transactions &t) {
    transactions.push_back(t);
    balance += t.getAmount();
    if (member) memberpoint += 5;
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

std::vector<Transactions> BankAccount::searchTransactions(const std::string &keyword) const {
    std::vector<Transactions> results;
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
        oss << " | Member Points: " << memberpoint;
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



