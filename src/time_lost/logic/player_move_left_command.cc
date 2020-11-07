#include "time_lost/logic/player_move_left_command.h"

namespace time_lost{

namespace logic{

PlayerMoveLeftCommand::PlayerMoveLeftCommand(TimeLost& _game):
Command(_game)
{
}

void PlayerMoveLeftCommand::Execute(){
    game.PlayerMove({-1,0});
}

} // logic
} // time_lost