#include "time_lost/objects/weapon.h"

namespace time_lost{

namespace objects{

std::ostream& operator<<(std::ostream& os, const Weapon& weapon){
        return weapon.print(os);
    }

} // objects
} // time_lost