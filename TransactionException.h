//
// Created by Francesco Ciarini on 03/06/24.
//

#ifndef BANKTRAN_TRANSACTIONEXCEPTION_H
#define BANKTRAN_TRANSACTIONEXCEPTION_H
#include <exception>
#include <stdexcept>

class TransactionException : public std::runtime_error{
public:
    TransactionException(std::string msg, bool fatal);

    bool isFatal(){
        return fatal;
    };

private:
    bool fatal;
};


#endif //BANKTRAN_TRANSACTIONEXCEPTION_H
