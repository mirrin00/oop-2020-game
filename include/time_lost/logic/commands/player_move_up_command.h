#ifndef PLAYER_MOVE_UP_COMMAND_H
#define PLAYER_MOVE_UP_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class PlayerMoveUpCommand: public Command{
public:
    PlayerMoveUpCommand() = default;

    void Execute(TimeLost& game) override;
};

} // commands
} // logic
} // time_lost


#endif // PLAYER_MOVE_UP_COMMAND_H