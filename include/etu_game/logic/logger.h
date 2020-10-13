#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>

#include "../types/etu_game_exception.h"

namespace etu_game{

namespace logic{

class Logger{

private:
    std::ofstream file;

    std::ostream& stream;

    bool write_in_stream;

    std::string GetCurrentTime();
public:
    Logger(std::string file_name);

    Logger(std::string file_name, std::ostream& os);

    ~Logger();

    bool IsWriteInStream();

    void SetWriteInStream(bool new_write_in_stream);

    template<typename Object>
    void WriteLog(const Object& obj){
        std::string cur_time = GetCurrentTime();
        file << cur_time << obj;
        if(write_in_stream) stream << cur_time << obj;
    }
};

} // logic
} // etu_game


#endif // LOGGER_H