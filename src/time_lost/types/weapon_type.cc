#include "time_lost/types/weapon_type.h"

namespace time_lost{
namespace types{
    
std::ostream& operator<<(std::ostream& os, WeaponType weapon_type){
    switch(weapon_type){
        case WeaponType::kPistol:
            os << "Pistol";
            break;
        case WeaponType::kRifle:
            os << "Rifle";
            break;
        case WeaponType::kKnife:
            os << "Knife";
            break;
        default:
            os << "Unknown";
    }
    return os;
}

} // types
} // time_lost
