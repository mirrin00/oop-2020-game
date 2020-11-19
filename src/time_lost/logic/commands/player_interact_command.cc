#include "time_lost/logic/commands/player_interact_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerInteractCommand::Execute(TimeLost& game){
    game.PlayerInteract();
}

} // commands
} // logic
} // time_lost