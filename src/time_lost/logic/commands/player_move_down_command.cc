#include "time_lost/logic/commands/player_move_down_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerMoveDownCommand::Execute(TimeLost& game){
    game.PlayerMove({0,1});
}

} // commands
} // logic
} // time_lost