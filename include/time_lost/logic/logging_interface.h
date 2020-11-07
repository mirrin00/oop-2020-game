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
    void Subscribe(logic::Subscriber& sub);

    void Unsubscribe(logic::Subscriber& sub);

};

} // logic
} // time_lost


#endif // LOGGING_INTERFACE_H