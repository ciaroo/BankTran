cmake_minimum_required(VERSION 3.28)
project(BankTran)

set(CMAKE_CXX_STANDARD 17)

add_executable(BankTran main.cpp
        Bank.cpp
        Bank.h
        BankAccount.cpp
        BankAccount.h
        Transaction.cpp
        Transaction.h
        TransactionException.cpp
        TransactionException.h
        cinException.cpp
        cinException.h
)
