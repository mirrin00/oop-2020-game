#include "time_lost/logic/logging_interface.h"

namespace time_lost{

namespace logic{

void LoggingInterface::Subscribe(std::shared_ptr<Logger> logger){
    pub.Subscribe(logger);
}

void LoggingInterface::Unsubscribe(std::shared_ptr<Logger> logger){
    pub.Unsubscribe(logger);
}

} // logic
} // time_lost