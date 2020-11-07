#ifndef PLAYER_MOVE_UP_COMMAND_H
#define PLAYER_MOVE_UP_COMMAND_H

#include "command.h"

namespace time_lost{

namespace logic{

class PlayerMoveUpCommand: public Command{
public:
    PlayerMoveUpCommand(TimeLost& _game);

    void Execute() override;
};

} // logic
} // time_lost


#endif // PLAYER_MOVE_UP_COMMAND_H