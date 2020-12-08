#include "time_lost/types/time_lost_file_exception.h"

namespace time_lost{

namespace types{

TimeLostFileException::TimeLostFileException(const std::string message):
msg(message)
{
}

TimeLostFileException::TimeLostFileException(const std::string filename, int line, const std::string message){
    msg = "Exception in file " + filename + " on line "
         + std::to_string(line) + ". Message: " + message;
}

TimeLostFileException::~TimeLostFileException(){}

const char* TimeLostFileException::what() const noexcept{
    return msg.c_str();
}

} //types
} //time_lost