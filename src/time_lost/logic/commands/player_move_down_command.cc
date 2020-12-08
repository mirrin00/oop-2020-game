#include "time_lost/logic/commands/player_move_down_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerMoveDownCommand::Execute(TimeLost& game){
    if(game.GetTurn() == types::Turns::kStartMenu) game.MenuDown();
    if(game.GetTurn() != types::Turns::kPlayer) return;
    game.PlayerMove({0,1});
    game.NextTurn();
}

bool PlayerMoveDownCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost