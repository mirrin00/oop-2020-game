#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <memory>

namespace etu_game {

namespace objects {

class Weapon{
public:
    virtual ~Weapon() = default;
    
    virtual int Attack() = 0;

    virtual std::unique_ptr<Weapon> clone() const = 0;

    virtual std::ostream& print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon);
};
    std::ostream& operator<<(std::ostream& os, const Weapon& weapon){
        return weapon.print(os);
    }

} // objects
} // etu_game

#endif // WEAPON_H