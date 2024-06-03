//
// Created by Francesco Ciarini on 03/06/24.
//

#include <string>
#include "TransactionException.h"

TransactionException::TransactionException(std::string msg, bool fatal): std::runtime_error(msg), fatal(fatal) {

}
