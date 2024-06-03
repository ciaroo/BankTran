//
// Created by Francesco Ciarini on 03/06/24.
//

#include "cinException.h"
#include <string>

cinException::cinException(std::string msg, bool fatal): std::runtime_error(msg), fatal(fatal) {

}
