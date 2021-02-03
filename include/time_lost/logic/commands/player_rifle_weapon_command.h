#ifndef PLAYER_RIFLE_WEAPON_COMMAND_H
#define PLAYER_RIFLE_WEAPON_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class PlayerRifleWeaponCommand: public Command{
public:
    PlayerRifleWeaponCommand() = default;

    void Execute(TimeLost& game) override;

    bool IsEmpty() override;
};

} // commands
} // logic
} // time_lost


#endif // PLAYER_RIFLE_WEAPON_COMMAND_H