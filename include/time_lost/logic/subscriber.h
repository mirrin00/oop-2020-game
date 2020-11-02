#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "logger.h"

namespace time_lost{

namespace logic{

class Subscriber{
private:
    Logger& logger;
public:
    Subscriber(Logger& logger_);

    template<typename Object>
    void Update(const Object& obj){
        logger.WriteLog<Object>(obj);
    }
};

} // logic
} // time_lost


#endif // SUBSCRIBER_H