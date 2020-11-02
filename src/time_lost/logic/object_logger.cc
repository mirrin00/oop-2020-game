#include "time_lost/logic/object_logger.h"

namespace time_lost{

namespace logic{

template<typename T>
ObjectLogger<T>::~ObjectLogger(){
    file.close();
}

template<typename T>
bool ObjectLogger<T>::IsWriteInStream(){
    return write_in_stream;
}

template<typename T>
void ObjectLogger<T>::SetWriteInStream(bool new_write_in_stream){
    write_in_stream = new_write_in_stream;
}

template<typename T>
std::string ObjectLogger<T>::GetCurrentTime(){
    auto cur_time = time(nullptr);
    auto local_cur_time = localtime(&cur_time);
    char str[11] = {0};
    sprintf(str, "[%02d:%02d:%02d]",local_cur_time->tm_hour, local_cur_time->tm_min, local_cur_time->tm_sec);
    return std::string(str);
}
template<typename T>
void ObjectLogger<T>::WriteLog(){
    std::string cur_time = GetCurrentTime();
    file << cur_time << obj;
    if(write_in_stream) stream << cur_time << obj;
}

} // logic
} // time_lost