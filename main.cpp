#include <iostream>
#include "Bank.h"
#include "BankAccount.h"
#include "Transaction.h"

int main() {
    Bank TEMA;

    TEMA.addAccount("Francesco", "Ciarini", 1000);
    TEMA.deposit(10001000,300);
    TEMA.withdraw(10001000,529,"ps5");

    TEMA.printAccountTransaction(10001000);

    return 0;
}
