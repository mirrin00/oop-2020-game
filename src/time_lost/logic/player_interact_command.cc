#include "time_lost/logic/player_interact_command.h"

namespace time_lost{

namespace logic{

PlayerInteractCommand::PlayerInteractCommand(TimeLost& _game):
Command(_game)
{
}

void PlayerInteractCommand::Execute(){
    game.PlayerInteract();
}

} // logic
} // time_lost