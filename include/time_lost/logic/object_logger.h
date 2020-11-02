#ifndef OBJECT_LOGGER_H
#define OBJECT_LOGGER_H

#include "logger_interface.h"
#include "../types/time_lost_exception.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>

namespace time_lost{

namespace logic{

template<typename T>
class ObjectLogger: public LoggerInterface{
private:
    T& obj;

    std::ofstream file;

    std::ostream& stream;

    bool write_in_stream;

    std::string GetCurrentTime(){
        auto cur_time = time(nullptr);
        auto local_cur_time = localtime(&cur_time);
        char str[11] = {0};
        sprintf(str, "[%02d:%02d:%02d]",local_cur_time->tm_hour, local_cur_time->tm_min, local_cur_time->tm_sec);
        return std::string(str);
    }

public:
    ObjectLogger(T& object, std::string file_name):
    write_in_stream(false),
    stream(std::cout),
    obj(object)
    {
        file.open(file_name, std::ios_base::app);
        if(!file.is_open()) throw types::TimeLostException(
                            (std::string("Can't open file")+file_name;
    }

    ObjectLogger(T& object, std::string file_name, std::ostream& os):
    write_in_stream(true),
    stream(os),
    obj(object)
    {
        file.open(file_name, std::ios_base::app);
        if(!file.is_open()) throw types::TimeLostException(
                            (std::string("Can't open file")+file_name;
    }

    ~ObjectLogger(){
        file.close();
    }

    bool IsWriteInStream(){
        return write_in_stream;
    }

    void SetWriteInStream(bool new_write_in_stream){
        write_in_stream = new_write_in_stream;
    }

    void WriteLog(){
        std::string cur_time = GetCurrentTime();
        file << cur_time << obj;
        if(write_in_stream) stream << cur_time << obj;
    }
};

} // logic
} // time_lost


#endif // LOGGER_INTERFACE_H