#ifndef PLAYER_INTERACT_COMMAND_H
#define PLAYER_INTERACT_COMMAND_H

#include "command.h"

namespace time_lost{

namespace logic{

class PlayerInteractCommand: public Command{
public:
    PlayerInteractCommand(TimeLost& _game);

    void Execute() override;
};

} // logic
} // time_lost


#endif // PLAYER_INTERACT_COMMAND_H