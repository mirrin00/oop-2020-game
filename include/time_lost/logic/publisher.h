#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <list>
#include <memory>

#include "logger.h"

namespace time_lost{

namespace logic{

class Publisher{
private:
    std::list<std::weak_ptr<Logger>> loggers;
public:
    Publisher() = default;

    ~Publisher() = default;

    void Subscribe(std::shared_ptr<Logger> logger);

    void Unsubscribe(std::shared_ptr<Logger> logger);

    template<typename Object>
    void Notify(const Object& obj){
        loggers.remove_if([](std::weak_ptr<Logger> ptr){
            return ptr.expired();
        });
        for(auto weak_logger: loggers){
            if(weak_logger.expired()) continue;
            auto logger = weak_logger.lock();
            logger->WriteLog<Object>(obj);
        }
    }
};

} // logic
} // time_lost


#endif // PUBLISHER_H