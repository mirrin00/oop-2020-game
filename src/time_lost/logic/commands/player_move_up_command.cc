#include "time_lost/logic/commands/player_move_up_command.h"

namespace time_lost{

namespace logic{

namespace commands{

PlayerMoveUpCommand::PlayerMoveUpCommand(TimeLost& _game):
Command(_game)
{
}

void PlayerMoveUpCommand::Execute(){
    game.PlayerMove({0,-1});
}

} // commands
} // logic
} // time_lost