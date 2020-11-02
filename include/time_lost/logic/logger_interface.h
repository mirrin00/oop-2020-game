#ifndef LOGGER_INTERFACE_H
#define LOGGER_INTERFACE_H

namespace time_lost{

namespace logic{

class LoggerInterface{
public:
    virtual ~LoggerInterface() = default;

    virtual void WriteLog() = 0;
};

} // logic
} // time_lost


#endif // LOGGER_INTERFACE_H