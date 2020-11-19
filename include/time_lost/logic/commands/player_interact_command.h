#ifndef PLAYER_INTERACT_COMMAND_H
#define PLAYER_INTERACT_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class PlayerInteractCommand: public Command{
public:
    PlayerInteractCommand() = default;

    void Execute(TimeLost& game) override;
};

} // commands
} // logic
} // time_lost


#endif // PLAYER_INTERACT_COMMAND_H