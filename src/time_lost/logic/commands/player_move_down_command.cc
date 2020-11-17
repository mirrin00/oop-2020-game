#include "time_lost/logic/commands/player_move_down_command.h"

namespace time_lost{

namespace logic{

namespace commands{

PlayerMoveDownCommand::PlayerMoveDownCommand(TimeLost& _game):
Command(_game)
{
}

void PlayerMoveDownCommand::Execute(){
    game.PlayerMove({0,1});
}

} // commands
} // logic
} // time_lost