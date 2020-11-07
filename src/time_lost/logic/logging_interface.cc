#include "time_lost/logic/logging_interface.h"

namespace time_lost{

namespace logic{

void LoggingInterface::Subscribe(logic::Subscriber& sub){
    pub.Subscribe(sub);
}

void LoggingInterface::Unsubscribe(logic::Subscriber& sub){
    pub.Unsubscribe(sub);
}

} // logic
} // time_lost