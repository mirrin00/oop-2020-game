#ifndef PLAYER_MOVE_DOWN_COMMAND_H
#define PLAYER_MOVE_DOWN_COMMAND_H

#include "command.h"

namespace time_lost{

namespace logic{

class PlayerMoveDownCommand: public Command{
public:
    PlayerMoveDownCommand(TimeLost& _game);

    void Execute() override;
};

} // logic
} // time_lost


#endif // PLAYER_MOVE_DOWN_COMMAND_H