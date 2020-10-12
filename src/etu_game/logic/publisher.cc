#include "etu_game/logic/publisher.h"

namespace etu_game{

namespace logic{

void Publisher::Subscribe(Subscriber& sub){
    Unsubscribe(sub);
    subscribers.push_back(&sub);
}

void Publisher::Unsubscribe(Subscriber& sub){
    subscribers.remove(&sub);
}

} // logic
} // etu_game