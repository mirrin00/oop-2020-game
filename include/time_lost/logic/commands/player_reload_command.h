#ifndef PLAYER_RELOAD_COMMAND_H
#define PLAYER_RELOAD_WEAPON_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class PlayerReloadCommand: public Command{
public:
    PlayerReloadCommand() = default;

    void Execute(TimeLost& game) override;

    bool IsEmpty() override;
};

} // commands
} // logic
} // time_lost


#endif // PLAYER_RELOAD_COMMAND_H