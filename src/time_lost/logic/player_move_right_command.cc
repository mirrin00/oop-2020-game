#include "time_lost/logic/player_move_right_command.h"

namespace time_lost{

namespace logic{

PlayerMoveRightCommand::PlayerMoveRightCommand(TimeLost& _game):
Command(_game)
{
}

void PlayerMoveRightCommand::Execute(){
    game.PlayerMove({1,0});
}

} // logic
} // time_lost