#include "time_lost/logic/commands/player_attack_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerAttackCommand::Execute(TimeLost& game){
    game.PlayerAttack();
}

} // commands
} // logic
} // time_lost