#include "time_lost/logic/commands/player_knife_weapon_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerKnifeWeaponCommand::Execute(TimeLost& game){
    if(game.GetTurn() != types::Turns::kPlayer) return;
    game.PlayerChangeWeapon(types::WeaponType::kKnife);
    game.NextTurn();
}

bool PlayerKnifeWeaponCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost