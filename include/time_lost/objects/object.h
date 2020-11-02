#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

#include "../types/position.h"
#include "../logic/publisher.h"

namespace time_lost{

namespace objects{

class Object{
protected:
    types::Position pos;

    logic::Publisher pub;

    virtual void Notify();
public:
    Object(types::Position start_pos = {0,0});

    ~Object();

    Object(const Object& obj);

    Object& operator=(const Object& obj);

    types::Position GetPosition();

    void SetPosition(types::Position new_pos);

    void Subscribe(logic::Subscriber& sub);

    void Unsubscribe(logic::Subscriber& sub);

    friend std::ostream& operator<<(std::ostream& os, const Object& obj);
};

    std::ostream& operator<<(std::ostream& os, const Object& obj);

}
}

#endif // OBJECT_H