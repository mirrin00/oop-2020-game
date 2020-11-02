#include "time_lost/types/time_lost_exception.h"

namespace time_lost{

namespace types{

TimeLostException::TimeLostException(const std::string message):
msg(message)
{
}

TimeLostException::~TimeLostException(){}

const char* TimeLostException::what() const noexcept{
    return msg.c_str();
}

} //types
} //time_lost