#ifndef TIME_LOST_FILE_EXCEPTION_CLASS_H
#define TIME_LOST_FILE_EXCEPTION_CLASS_H

#include<string>

namespace time_lost{

namespace types{

class TimeLostFileException{
private:
    std::string msg;
public:
    TimeLostFileException(const std::string message);

    TimeLostFileException(const std::string filename, int line, const std::string message);

    ~TimeLostFileException();

    const char* what() const noexcept;
};


} //types
} //time_lost

#endif // TIME_LOST_EFILE_XCEPTION_CLASS_H