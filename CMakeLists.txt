cmake_minimum_required(VERSION 3.28)
project(BankTran)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES Bank.cpp
        Bank.h
        BankAccount.cpp
        BankAccount.h
        Transaction.cpp
        Transaction.h
        TransactionException.cpp
        TransactionException.h
        cinException.cpp
        cinException.h)

add_executable(BankTran main.cpp )
add_library(core ${SOURCE_FILES})
target_link_libraries(BankTran core)
enable_testing()

add_subdirectory(googletest)

