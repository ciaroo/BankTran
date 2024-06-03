#include <iostream>
#include "Bank.h"
#include "BankAccount.h"
#include "Transaction.h"
#include "TransactionException.h"
#include "cinException.h"

void addAccount(Bank bank){
    std::string name;
    std::string surname;
    double openingBalance;
    bool member;

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
    std::cin >> member;
    if(std::cin.fail())
        throw cinException("Expected 1 or 0.", false);

    bank.addAccount(name, surname, openingBalance, member);
}

void newTransaction(Bank bank){
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
    std::cout << "Write a description: " << std::endl;
    std::cin >> description;
    if(std::cin.fail())
        throw cinException("Expected string.", false);

    bank.doTransaction(iban, amount, description);
}

void printTransaction(Bank bank){
    int iban;

    std::cout << "Insert IBAN. " << std::endl;
    std::cin >> iban;
    if(std::cin.fail())
        throw cinException("Expected number.", false);

    bank.printAccountTransaction(iban);

}

void doOperation(Bank bank) {
    bool quit = false;
    char op;

    while (!quit) {
        std::cout
                << "Choose one of the following operation: 'a' to add new account, 't' for do a new Transaction, 'p' to print Transaction and 'q' to Quit."
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
                case 'p':
                    printTransaction(bank);
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

            doOperation(TEMA);


            return 0;
        }
