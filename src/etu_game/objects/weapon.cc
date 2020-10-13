#include "etu_game/objects/weapon.h"

namespace etu_game{

namespace objects{

std::ostream& operator<<(std::ostream& os, const Weapon& weapon){
        return weapon.print(os);
    }

} // objects
} // etu_game