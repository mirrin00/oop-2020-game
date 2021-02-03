#ifndef PLAYER_PISTOL_WEAPON_COMMAND_H
#define PLAYER_PISTOL_WEAPON_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class PlayerPistolWeaponCommand: public Command{
public:
    PlayerPistolWeaponCommand() = default;

    void Execute(TimeLost& game) override;

    bool IsEmpty() override;
};

} // commands
} // logic
} // time_lost


#endif // PLAYER_PISTOL_WEAPON_COMMAND_H