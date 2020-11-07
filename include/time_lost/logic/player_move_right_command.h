#ifndef PLAYER_MOVE_RIGHT_COMMAND_H
#define PLAYER_MOVE_RIGHT_COMMAND_H

#include "command.h"

namespace time_lost{

namespace logic{

class PlayerMoveRightCommand: public Command{
public:
    PlayerMoveRightCommand(TimeLost& _game);

    void Execute() override;
};

} // logic
} // time_lost


#endif // PLAYER_MOVE_RIGHT_COMMAND_H