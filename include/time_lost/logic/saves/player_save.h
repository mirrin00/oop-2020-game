#ifndef PLAYER_SAVE_H
#define PLAYER_SAVE_H

namespace time_lost{

namespace objects{
class Player;
}
}


#include "weapon_save_interface.h"
#include "../../objects/player.h"
#include "../../types/save_type.h"

namespace time_lost{

namespace logic{

namespace saves{

class PlayerSave{
private:
    struct Data{
        types::Position pos;

        int coins;

        int health;
    };

    Data data;

    std::shared_ptr<WeaponSaveInterface> _weapon;

public:
    PlayerSave() = default;

    PlayerSave(types::Position pos, int coins, int health, objects::Weapon& weapon);

    ~PlayerSave() = default;

    objects::Player LoadPlayer();

    friend std::ostream& operator<<(std::ostream& os, PlayerSave& save);

    friend std::istream& operator>>(std::istream& is, PlayerSave& save);
};

std::ostream& operator<<(std::ostream& os, PlayerSave& save);

std::istream& operator>>(std::istream& is, PlayerSave& save);

} // saves
} // logic
} // time_lost


#endif // PLAYER_SAVE_H