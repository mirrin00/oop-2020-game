#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <memory>
#include <tuple>

#include "../types/weapon_type.h"

namespace time_lost {

namespace objects {

class Weapon{
protected:
    int cur_ammo;
public:
    Weapon():cur_ammo(0){}

    virtual ~Weapon() = default;
    
    virtual std::tuple<int, int, int> Attack() = 0;

    virtual void Reload(int bullets) = 0;

    virtual types::WeaponType GetType() = 0;

    virtual int GetMaxAmmo() = 0;

    virtual int GetCurrentAmmo(){return cur_ammo;}

    virtual std::ostream& print(std::ostream& os) const = 0;
};
    std::ostream& operator<<(std::ostream& os, const Weapon& weapon);

} // objects
} // time_lost

#endif // WEAPON_H