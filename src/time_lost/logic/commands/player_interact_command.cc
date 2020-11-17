#include "time_lost/logic/commands/player_interact_command.h"

namespace time_lost{

namespace logic{

namespace commands{

PlayerInteractCommand::PlayerInteractCommand(TimeLost& _game):
Command(_game)
{
}

void PlayerInteractCommand::Execute(){
    game.PlayerInteract();
}

} // commands
} // logic
} // time_lost