#include "time_lost/logic/commands/player_reload_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerReloadCommand::Execute(TimeLost& game){
    if(game.GetTurn() != types::Turns::kPlayer) return;
    game.PlayerReload();
    game.NextTurn();
}

bool PlayerReloadCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost