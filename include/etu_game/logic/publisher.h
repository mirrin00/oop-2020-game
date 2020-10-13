#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <list>

#include "subscriber.h"

namespace etu_game{

namespace logic{

class Publisher{
private:
    // FIXME: std_shared_ptr???
    std::list<Subscriber*> subscribers;
public:
    Publisher() = default;

    ~Publisher() = default;

    void Subscribe(Subscriber& sub);

    void Unsubscribe(Subscriber& sub);

    template<typename Object>
    void Notify(const Object& obj){
        for(std::list<Subscriber*>::iterator iter = subscribers.begin();
                 iter != subscribers.end(); ++iter){
            (*iter)->Update<Object>(obj);
        }
    }
};

} // logic
} // etu_game


#endif // PUBLISHER_H