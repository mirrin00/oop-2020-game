#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <memory>

namespace time_lost {

namespace objects {

class Weapon{
public:
    virtual ~Weapon() = default;
    
    virtual int Attack() = 0;

    // FIXME: std::shared_ptr??
    virtual std::unique_ptr<Weapon> CloneWeapon() const = 0;

    virtual std::ostream& print(std::ostream& os) const = 0;
};
    std::ostream& operator<<(std::ostream& os, const Weapon& weapon);

} // objects
} // time_lost

#endif // WEAPON_H