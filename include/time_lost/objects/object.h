#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

#include "../types/position.h"
#include "../logic/logging_interface.h"
#include "../types/last_action.h"

namespace time_lost{

namespace objects{

class Object: public logic::LoggingInterface{
private:
    types::LastAction last_action;
protected:
    types::Position pos;

    virtual void Notify();
public:
    Object(types::Position start_pos = {0,0});

    ~Object();

    Object(const Object& obj);

    Object& operator=(const Object& obj);

    types::Position GetPosition();

    void SetPosition(types::Position new_pos);

    void SetLastAction(types::LastAction new_last_action);

    types::LastAction GetLastAction();

    friend std::ostream& operator<<(std::ostream& os, const Object& obj);
};

    std::ostream& operator<<(std::ostream& os, const Object& obj);

}
}

#endif // OBJECT_H