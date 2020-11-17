#include "time_lost/logic/commands/player_move_right_command.h"

namespace time_lost{

namespace logic{

namespace commands{

PlayerMoveRightCommand::PlayerMoveRightCommand(TimeLost& _game):
Command(_game)
{
}

void PlayerMoveRightCommand::Execute(){
    game.PlayerMove({1,0});
}

} // commands
} // logic
} // time_lost