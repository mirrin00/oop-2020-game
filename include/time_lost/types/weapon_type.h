#ifndef WEAPON_TYPE_H
#define WEAPON_TYPE_H

#include <iostream>

namespace time_lost{

namespace types{

enum class WeaponType{
    kRifle,
    kPistol,
    kKnife,
};

std::ostream& operator<<(std::ostream& os, WeaponType weapon_type);

} // types
} // time_lost

#endif // WEAPON_TYPE_H