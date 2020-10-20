#ifndef LOGGER_INTERFACE_H
#define LOGGER_INTERFACE_H

namespace etu_game{

namespace logic{

class LoggerInterface{
public:
    virtual ~LoggerInterface();

    virtual void WriteLog() = 0;
};

} // logic
} // etu_game


#endif // LOGGER_INTERFACE_H