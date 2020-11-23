#include "time_lost/logic/commands/player_interact_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerInteractCommand::Execute(TimeLost& game){
    game.PlayerInteract();
}

bool PlayerInteractCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost