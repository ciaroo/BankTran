//
// Created by Francesco Ciarini on 15/04/25.
//
#include <gtest/gtest.h>
#include "../Transaction.h"
#include "../BankAccount.h"
#include "../Bank.h"
#include "../TransactionException.h"

TEST(TransactionsTest, positiveAmount) {
    Transaction test(123.45, "prova deposito");
    EXPECT_DOUBLE_EQ(test.getAmount(), 123.45);
}

TEST(TransactionsTest, negativeAmount){
    Transaction test(-129.70, "prova ritiro");
    EXPECT_DOUBLE_EQ(test.getAmount(), -129.70);
}

TEST(TransactionTest, toStringTest) {
    Transaction t(1070, "Prova");

    EXPECT_EQ(t.getDescription(), "Prova");
}

TEST(TransactionTest, zeroAmount) {
    EXPECT_THROW(Transaction(0.0, "Importo zero"), TransactionException);
}

TEST(BankAccountTest, openingBalanceNegativeThrows) {
    EXPECT_THROW(BankAccount("Mario", "Rossi", 8, -50.0, false), std::invalid_argument);
}

TEST(BankAccountTest, doTransactionAndMemberPoints) {
    BankAccount acc("Alice", "Bruni", 9, 100.0, true);
    acc.doTransaction(50.0, "Deposit");

    EXPECT_EQ(acc.getBalance(),150.0);
    EXPECT_EQ(acc.getMemberPoint(),5);
}

TEST(BankAccountTest, zeroAmountThrows) {
    BankAccount acc("Stefano", "Belli", 10, 0.0, false);
    EXPECT_THROW(acc.doTransaction(0.0, "Zero"), TransactionException);
}

TEST(BankAccountTest, RemoveTransaction) {
    BankAccount acc("Simone", "Bianchi", 11, 0.0, false);
    acc.doTransaction(20.0, "T1");
    acc.doTransaction(-5.0, "T2");
    EXPECT_EQ(acc.getTransactionCount(), 2);

    EXPECT_TRUE(acc.removeTransaction(1));
    EXPECT_EQ(acc.getTransactionCount(), 1);
}

TEST(BankAccountTest, RemoveNonExistentTransaction) {
    BankAccount acc("Andrea", "Schicco", 18, 0.0, false);
    acc.doTransaction(40, "deposito");

    EXPECT_EQ(acc.getTransactionCount(), 1);
    EXPECT_THROW(acc.removeTransaction(3), TransactionException);
    EXPECT_EQ(acc.getTransactionCount(), 1);
}

TEST(BankAccountTest, SearchTransactions) {
    BankAccount acc("Andrea", "Corti", 12, 0.0, false);
    acc.doTransaction(10.0, "Stipendio");
    acc.doTransaction(-2.0, "Tasse");
    auto res = acc.searchTransactions("Stipendio");
    ASSERT_EQ(res.size(), 1);
    EXPECT_EQ(res[0].getAmount(), 10.0);
}

TEST(BankAccountTest, SearchNonExistentTransaction) {
    BankAccount acc("Andrea", "Bassi", 17, 0.0, false);
    acc.doTransaction(80.0, "Stipendio");

    EXPECT_THROW(acc.searchTransactions("affitto"), TransactionException);
}

TEST(BankAccountTest, WithdrawalBeyondBalanceThrows) {
    BankAccount acc("Paolo", "Rossi", 15, 100.0, false);

    EXPECT_THROW(acc.doTransaction(-150.0, "Overdraw"), TransactionException);

    EXPECT_EQ(acc.getBalance(), 100.0);
    EXPECT_EQ(acc.getTransactionCount(), 0);
}

TEST(BankTest, AddFindAccount) {
    Bank bank;
    bank.addAccount("Eve", "Black", 500.0);
    BankAccount* a1 = bank.findAccount(10001000);
    ASSERT_NE(a1, nullptr);
    EXPECT_EQ(a1->getIBAN(), 10001000);
}

TEST(BankTest, SearchNonExistentAccount) {
    Bank bank;
    bank.addAccount("Eve", "Black", 500.0);
    //first iban should be 10001000
    BankAccount* a1 = bank.findAccount(10001111);
    ASSERT_EQ(a1, nullptr);
}
