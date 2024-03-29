#include "time_lost/logic/commands/player_move_right_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerMoveRightCommand::Execute(TimeLost& game){
    if(game.GetTurn() != types::Turns::kPlayer) return;
    game.PlayerMove({1,0});
    game.NextTurn();
}

bool PlayerMoveRightCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost