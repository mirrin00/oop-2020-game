#ifndef WEAPON_SAVE_INTERFACE_H
#define WEAPON_SAVE_INTERFACE_H

namespace time_lost{

namespace objects{
class Weapon;
}
}


#include "../../objects/weapon.h"

namespace time_lost{

namespace logic{

namespace saves{

class WeaponSaveInterface{
public:
    virtual ~WeaponSaveInterface() = default;

    virtual std::unique_ptr<objects::Weapon> LoadWeapon() = 0;

    virtual void WriteWeapon(std::ostream& os) = 0;

    friend std::ostream& operator<<(std::ostream& os, WeaponSaveInterface& save);
};

std::ostream& operator<<(std::ostream& os, WeaponSaveInterface& save);

} // saves
} // logic
} // time_lost


#endif // WEAPON_SAVE_INTERFACE_H