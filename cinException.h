//
// Created by Francesco Ciarini on 03/06/24.
//

#ifndef BANKTRAN_CINEXCEPTION_H
#define BANKTRAN_CINEXCEPTION_H
#include <exception>
#include <stdexcept>

class cinException : public std::runtime_error{
public:
    cinException(std::string msg, bool fatal);

    bool isFatal(){
        return fatal;
    };

private:
    bool fatal;
};


#endif //BANKTRAN_CINEXCEPTION_H
