#ifndef LOGGING_INTERFACE_H
#define LOGGING_INTERFACE_H

#include "publisher.h"

namespace time_lost{

namespace logic{

class LoggingInterface{
protected:
    Publisher pub;

    virtual void Notify() = 0;
public:
    void Subscribe(std::shared_ptr<Logger>  logger);

    void Unsubscribe(std::shared_ptr<Logger>  logger);

};

} // logic
} // time_lost


#endif // LOGGING_INTERFACE_H