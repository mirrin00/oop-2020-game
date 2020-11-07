#ifndef PLAYER_MOVE_LEFT_COMMAND_H
#define PLAYER_MOVE_LEFT_COMMAND_H

#include "command.h"

namespace time_lost{

namespace logic{

class PlayerMoveLeftCommand: public Command{
public:
    PlayerMoveLeftCommand(TimeLost& _game);

    void Execute() override;
};

} // logic
} // time_lost


#endif // PLAYER_MOVE_LEFT_COMMAND_H