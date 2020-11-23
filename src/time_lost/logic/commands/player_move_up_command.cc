#include "time_lost/logic/commands/player_move_up_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerMoveUpCommand::Execute(TimeLost& game){
    game.PlayerMove({0,-1});
}

bool PlayerMoveUpCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost