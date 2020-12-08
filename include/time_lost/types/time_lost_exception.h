#ifndef TIME_LOST_EXCEPTION_CLASS_H
#define TIME_LOST_EXCEPTION_CLASS_H

#include<string>

namespace time_lost{

namespace types{

class TimeLostException{
private:
    std::string msg;
public:
    TimeLostException(const std::string message);

    TimeLostException(const std::string filename, int line, const std::string message);

    ~TimeLostException();

    const char* what() const noexcept;
};


} //types
} //time_lost

#endif // TIME_LOST_EXCEPTION_CLASS_H