#ifndef ESSENCE_H
#define ESSENCE_H

#include <iostream>

#include "object.h"

namespace etu_game {

namespace objects {

class Essence: public Object{
protected:
    int health;

    virtual void Notify() override;
public:
    Essence(int start_health, int start_h_pos = 0, int start_w_pos = 0);

    ~Essence();

    void Move(int on_height, int on_width);

    friend std::ostream& operator<<(std::ostream& os, const Essence& essence);
};

    std::ostream& operator<<(std::ostream& os, const Essence& essence);

} // objects
} // etu_game

#endif // ESSENCE_INTERFACE_H