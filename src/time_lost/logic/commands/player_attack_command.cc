#include "time_lost/logic/commands/player_attack_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerAttackCommand::Execute(TimeLost& game){
    if(game.GetTurn() != types::Turns::kPlayer) return;
    game.PlayerAttack();
    game.NextTurn();
}

bool PlayerAttackCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost