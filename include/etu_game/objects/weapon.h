#ifndef WEAPON_H
#define WEAPON_H

#include <memory>

namespace etu_game {

namespace objects {

class Weapon{
public:
    virtual ~Weapon() = default;
    
    virtual int Attack() = 0;

    virtual std::unique_ptr<Weapon> clone() const = 0;
};

} // objects
} // etu_game

#endif // WEAPON_H