#include "time_lost/types/bullet_type.h"

namespace time_lost{
namespace types{
    
std::ostream& operator<<(std::ostream& os, BulletType bullet_type){
    switch(bullet_type){
        case BulletType::kPistol:
            os << "Pistol";
            break;
        case BulletType::kRifle:
            os << "Rifle";
            break;
        default:
            os << "Unknown";
    }
    return os;
}

} // types
} // time_lost
