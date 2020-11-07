#include "time_lost/logic/player_move_up_command.h"

namespace time_lost{

namespace logic{

PlayerMoveUpCommand::PlayerMoveUpCommand(TimeLost& _game):
Command(_game)
{
}

void PlayerMoveUpCommand::Execute(){
    game.PlayerMove({0,-1});
}

} // logic
} // time_lost