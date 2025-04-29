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
    // Remove second transaction
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