#include "time_lost/logic/player_move_down_command.h"

namespace time_lost{

namespace logic{

PlayerMoveDownCommand::PlayerMoveDownCommand(TimeLost& _game):
Command(_game)
{
}

void PlayerMoveDownCommand::Execute(){
    game.PlayerMove({0,1});
}

} // logic
} // time_lost