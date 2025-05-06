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
    std::string s = t.toString();
    EXPECT_NE(s.find("1070"), std::string::npos);
    EXPECT_NE(s.find("Prova"), std::string::npos);
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
    // Balance should be 150
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

    EXPECT_FALSE(acc.removeTransaction(5));
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

TEST(BankTest, AddFindAccount) {
    Bank bank;
    bank.addAccount("Eve", "Black", 500.0);
    // First IBAN should be 10001000
    BankAccount* a1 = bank.findAccount(10001000);
    ASSERT_NE(a1, nullptr);
    EXPECT_EQ(a1->getIBAN(), 10001000);
}

TEST(BankTest, DoTransactionNonexistentThrows) {
    Bank bank;
    EXPECT_THROW(bank.doTransaction(999999, 10.0, "x"), TransactionException);
}