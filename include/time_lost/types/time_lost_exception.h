#ifndef TIME_LOST_EXCEPTION_CLASS_H
#define TIME_LOST_EXCEPTION_CLASS_H

#include<string>

namespace time_lost{

namespace types{

class TimeLostException: std::exception{
private:
    std::string msg;
public:
    TimeLostException(const std::string message);

    ~TimeLostException();

    const char* what() const noexcept;
};


} //types
} //time_lost

#endif // TIME_LOST_EXCEPTION_CLASS_H