#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "logger.h"

namespace etu_game{

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
} // etu_game


#endif // SUBSCRIBER_H