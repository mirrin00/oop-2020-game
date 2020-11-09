#include "time_lost/logic/publisher.h"

namespace time_lost{

namespace logic{

void Publisher::Subscribe(std::shared_ptr<Logger> logger){
    Unsubscribe(logger);
    loggers.push_back(logger);
}

void Publisher::Unsubscribe(std::shared_ptr<Logger> logger){
    loggers.remove_if([logger](std::weak_ptr<Logger> weak){
        auto ptr = weak.lock();
        if(ptr) return logger == ptr;
        return false;
    });
}

} // logic
} // time_lost