#ifndef PLAYER_KNIFE_WEAPON_COMMAND_H
#define PLAYER_KNIFE_WEAPON_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class PlayerKnifeWeaponCommand: public Command{
public:
    PlayerKnifeWeaponCommand() = default;

    void Execute(TimeLost& game) override;

    bool IsEmpty() override;
};

} // commands
} // logic
} // time_lost


#endif // PLAYER_KNIFE_WEAPON_COMMAND_H