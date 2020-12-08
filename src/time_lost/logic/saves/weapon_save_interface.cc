#include "time_lost/logic/saves/weapon_save_interface.h"

namespace time_lost{

namespace logic{

namespace saves{

std::ostream& operator<<(std::ostream& os, WeaponSaveInterface& save){
    save.WriteWeapon(os);
    return os;
}

}
}
}