#include <iostream>
#include "Bank.h"
#include "BankAccount.h"
#include "Transaction.h"

void doOperation(Bank bank) {
    bool quit = false;
    char op;
    double amount;
    int iban;
    std::string name;
    std::string surname;
    double openingBalance;
    bool member;

    while (!quit) {
        std::cout
                << "Choose one of the following operation: 'a' to add new account, 'd' for Deposit, 'w' for Withdraw, 'p' to print Transaction and 'q' to Quit."
                << std::endl;
        std::cin >> op;
        if(std::cin.fail())
            throw std::runtime_error("cin fail");
        try {
            switch (op) {

                case 'a':
                    std::cout << "Insert name, surname and opening balance. " << std::endl;
                    std::cin >> name;
                    std::cin >> surname;
                    std::cin >> openingBalance;

                    std::cout << "If is a member account select 1, otherwise 0" << std::endl;
                    std::cin >> member;
                    if(std::cin.fail())
                        throw std::runtime_error("cin fail");

                    bank.addAccount(name, surname, openingBalance, member);
                    break;

                case 'w':

                    std::cout << "Insert IBAN. " << std::endl;
                    std::cin >> iban;
                    if (bank.findAccount(iban)) {
                        std::cout << "Insert amount to withdraw. " << std::endl;
                        std::cin >> amount;
                        if(std::cin.fail())
                            throw std::runtime_error("cin fail");
                        bank.withdraw(iban, amount);
                    } else
                        throw std::runtime_error("iban not found");
                    break;
                case 'd':

                    std::cout << "Insert IBAN. " << std::endl;
                    std::cin >> iban;
                    if(std::cin.fail())
                        throw std::runtime_error("cin fail");

                    if (bank.findAccount(iban)) {
                        std::cout << "Insert amount to deposit. " << std::endl;
                        std::cin >> amount;
                        if(std::cin.fail())
                            throw std::runtime_error("cin fail");
                        bank.deposit(iban, amount);
                    } else
                        throw std::runtime_error("iban not found");
                    break;
                case 'p':
                    std::cout << "Insert IBAN. " << std::endl;
                    std::cin >> iban;
                    if(std::cin.fail())
                        throw std::runtime_error("cin fail");

                    if (bank.findAccount(iban)) {
                        bank.printAccountTransaction(iban);
                    } else
                        throw std::runtime_error("iban not found");
                    break;
                case 'q':
                    quit=true;
                    break;
                default:
                    std::cout<<"Command not found"<< std::endl;
                    break;
            }

        }
        catch (const std::invalid_argument &error) {
            std::cerr << error.what() << std::endl;
        }
        catch (const std::runtime_error &r_error) {
            std::cerr << r_error.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}



        int main() {
            Bank TEMA;

            doOperation(TEMA);

            return 0;
        }
