#include <iostream>
#include "Bank.h"
#include <limits>
#include "BankAccount.h"
#include "Transaction.h"
#include "TransactionException.h"
#include "cinException.h"

void addAccount(Bank& bank){
    std::string name;
    std::string surname;
    double openingBalance;
    bool member;
    int m;

    std::cout << "Insert name, surname and opening balance. " << std::endl;
    std::cin >> name;
    if(std::cin.fail())
        throw cinException("Expected string.", false);
    std::cin >> surname;
    if(std::cin.fail())
        throw cinException("Expected string.", false);
    std::cin >> openingBalance;
    if(std::cin.fail())
        throw cinException("Expected number.", false);
    else if(openingBalance<0)
        throw TransactionException("Opening Balance cannot be negative", false);

    std::cout << "If is a member account select 1, otherwise 0" << std::endl;
    std::cin >> m;
    if (std::cin.fail() || (m != 0 && m != 1))
        throw cinException("Expected 1 or 0.", false);
    member = (m == 1);

    bank.addAccount(name, surname, openingBalance, member);
}

void newTransaction(Bank& bank){
    int iban;
    double amount;
    std::string description;

    std::cout << "Insert IBAN. " << std::endl;
    std::cin >> iban;
    if(std::cin.fail())
        throw cinException("Expected number.", false);

    std::cout << "Insert amount. " << std::endl;
    std::cin >> amount;
    if(std::cin.fail())
        throw cinException("Expected number.", false);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Write a description: " << std::endl;
    std::getline(std::cin, description);
    if(description.empty())
        throw cinException("Expected string.", false);

    bank.doTransaction(iban, amount, description);
}

void printTransaction(Bank& bank){
    int iban;

    std::cout << "Insert IBAN. " << std::endl;
    std::cin >> iban;
    if(std::cin.fail())
        throw cinException("Expected number.", false);

    bank.printAccountTransaction(iban);

}

void eraseTransaction(Bank& bank) {
    int iban;
    size_t idx;

    std::cout << "Insert IBAN. " << std::endl;
    std::cin >> iban;
    if (std::cin.fail())
        throw cinException("Expected number.", false);

    std::cout << "Index of transaction to erase: " << std::endl;
    std::cin >> idx;
    if (std::cin.fail())
        throw cinException("Expected number.", false);

    if (bank.removeTransaction(iban, idx))
        std::cout << "Transaction " << idx << " deleted.\n";
    else
        std::cout << "Invalid index: no deletion performed.\n";
}

void searchTransaction(Bank& bank) {
    int iban;
    std::string keyword;

    std::cout << "Insert IBAN. " << std::endl;
    std::cin >> iban;
    if (std::cin.fail())
        throw cinException("Expected number.", false);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter keyword to search: " << std::endl;
    std::getline(std::cin, keyword);
    if (keyword.empty())
        throw cinException("Expected string.", false);

    auto results = bank.searchTransactions(iban, keyword);
    if (results.empty()) {
        std::cout << "No transactions found for \"" << keyword << "\".\n";
    } else {
        std::cout << "Found " << results.size() << " transactions:\n";
        for (size_t i = 0; i < results.size(); ++i) {
            std::cout << "[" << i << "] " << results[i].toString() << "\n";
        }
    }
}

void doOperation(Bank& bank) {
    bool quit = false;
    char op;

    while (!quit) {
        std::cout
                << "Choose one of the following operation: 'a' to add new account, 't' for do a new Transaction, 'e' to erase Transaction, 'p' to print Transaction-List, 's' to search Keyword-Transaction and 'q' to Quit."
                << std::endl;
        try {
            std::cin >> op;
            if (std::cin.fail())
                throw cinException("Expected char.", false);
            switch (op) {
                case 'a':
                    addAccount(bank);
                    break;
                case 't':
                    newTransaction(bank);
                    break;
                case 'e':
                    eraseTransaction(bank);
                    break;
                case 'p':
                    printTransaction(bank);
                    break;
                case 's':
                    searchTransaction(bank);
                    break;
                case 'q':
                    quit = true;
                    break;
                default:
                    std::cout << "Command not found" << std::endl;
                    break;


            }
        }
        catch (TransactionException& error){
            std::cerr<<error.what()<<std::endl;

            if(error.isFatal()) {
                std::cerr<<"Fatal error"<<std::endl;
                abort();
            }
        }
        catch(cinException& error){
            std::cin.clear();
            std::cin.ignore();

            std::cerr<<error.what()<<std::endl;

            if(error.isFatal()) {
                std::cerr<<"Fatal error"<<std::endl;
                abort();
            }
        }

    }
}

int main() {
    Bank TEMA;

    TEMA.addAccount("Francesco", "Ciarini", 2000);
    TEMA.addAccount("Elena", "Sassi", 50);

    doOperation(TEMA);

    return 0;
}
