#ifndef ESSENCE_H
#define ESSENCE_H

#include <iostream>

#include "object.h"
#include "../types/direction.h"

namespace time_lost {

namespace objects {

class Essence: public Object{
protected:
    int health;

    types::Direction direct;

    virtual void Notify() override;
public:

    Essence(int start_health, types::Position start_pos = {0,0}, types::Direction direct = types::Direction::kUp);

    ~Essence();

    void SetHealth(int new_health);

    void ChangeHealth(int change_h);

    int GetHealth();

    void Move(types::Position move);

    void SetDirection(types::Direction new_direct);

    types::Direction GetDirection();

    void RotateRight();

    void RotateLeft();

    friend std::ostream& operator<<(std::ostream& os, const Essence& essence);
};

    std::ostream& operator<<(std::ostream& os, const Essence& essence);

} // objects
} // time_lost

#endif // ESSENCE_INTERFACE_H