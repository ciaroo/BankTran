#include <iostream>
#include "Bank.h"
#include "BankAccount.h"
#include "Transaction.h"

int main() {
    Bank TEMA;

    TEMA.addAccount("Francesco", "Ciarini", 1000, true);
    TEMA.deposit(10001000, 300);
    TEMA.withdraw(10001000, 529, "ps5");

    TEMA.addAccount("Elena", "Sassi", 3000);
    TEMA.deposit(10001001, 398, "bonifico");

    TEMA.deposit(10001000, 500);
    TEMA.printAccountTransaction(10001000);
    TEMA.printAccountTransaction(10001001);


    return 0;
}
