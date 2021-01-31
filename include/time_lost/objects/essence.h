#ifndef ESSENCE_H
#define ESSENCE_H

#include <iostream>

#include "object.h"

namespace time_lost {

namespace objects {

class Essence: public Object{
public:
    enum Direction{
        Up,
        Down,
        Left,
        Right
    };
protected:
    int health;

    Direction direct;

    virtual void Notify() override;
public:

    Essence(int start_health, types::Position start_pos = {0,0}, Direction direct = Direction::Up);

    ~Essence();

    void SetHealth(int new_health);

    void ChangeHealth(int change_h);

    int GetHealth();

    void Move(types::Position move);

    void SetDirection(Direction new_direct);

    Direction GetDirection();

    void RotateRight();

    void RotateLeft();

    friend std::ostream& operator<<(std::ostream& os, const Essence& essence);
};

    std::ostream& operator<<(std::ostream& os, const Essence& essence);

} // objects
} // time_lost

#endif // ESSENCE_INTERFACE_H