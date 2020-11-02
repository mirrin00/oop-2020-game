#include "time_lost/logic/logger.h"

namespace time_lost{

namespace logic{

Logger::Logger(std::string file_name):
write_in_stream(false),
stream(std::cout)
{
    file.open(file_name, std::ios_base::app);
    if(!file.is_open()) throw types::TimeLostException(
                        (std::string("Can't open file")+file_name));
}

Logger::Logger(std::string file_name, std::ostream& os):
write_in_stream(true),
stream(os)
{
    file.open(file_name, std::ios_base::app);
    if(!file.is_open()) throw types::TimeLostException(
                        (std::string("Can't open file")+file_name));
}

Logger::~Logger(){
    file.close();
}

bool Logger::IsWriteInStream(){
    return write_in_stream;
}

void Logger::SetWriteInStream(bool new_write_in_stream){
    write_in_stream = new_write_in_stream;
}

std::string Logger::GetCurrentTime(){
    auto cur_time = time(nullptr);
    auto local_cur_time = localtime(&cur_time);
    char str[11] = {0};
    sprintf(str, "[%02d:%02d:%02d]",local_cur_time->tm_hour, local_cur_time->tm_min, local_cur_time->tm_sec);
    return std::string(str);
}

} // logic
} // time_lost