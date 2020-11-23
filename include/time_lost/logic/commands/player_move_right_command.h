#ifndef PLAYER_MOVE_RIGHT_COMMAND_H
#define PLAYER_MOVE_RIGHT_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class PlayerMoveRightCommand: public Command{
public:
    PlayerMoveRightCommand() = default;

    void Execute(TimeLost& game) override;

    bool IsEmpty() override;
};

} // commands
} // logic
} // time_lost


#endif // PLAYER_MOVE_RIGHT_COMMAND_H