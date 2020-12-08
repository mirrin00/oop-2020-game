#include "time_lost/logic/commands/player_move_left_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerMoveLeftCommand::Execute(TimeLost& game){
    if(game.GetTurn() != types::Turns::kPlayer) return;
    game.PlayerMove({-1,0});
    game.NextTurn();
}

bool PlayerMoveLeftCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost