#include "time_lost/types/time_lost_exception.h"

namespace time_lost{

namespace types{

TimeLostException::TimeLostException(const std::string message):
msg(message)
{
}

TimeLostException::TimeLostException(const std::string filename, int line, const std::string message){
    msg = "Exception in file " + filename + " on line "
         + std::to_string(line) + ". Message: " + message;
}

TimeLostException::~TimeLostException(){}

const char* TimeLostException::what() const noexcept{
    return msg.c_str();
}

} //types
} //time_lost