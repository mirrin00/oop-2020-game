#include "time_lost/logic/publisher.h"

namespace time_lost{

namespace logic{

void Publisher::Subscribe(Subscriber& sub){
    Unsubscribe(sub);
    subscribers.push_back(&sub);
}

void Publisher::Unsubscribe(Subscriber& sub){
    subscribers.remove(&sub);
}

} // logic
} // time_lost