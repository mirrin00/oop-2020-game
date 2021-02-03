#include "time_lost/logic/commands/player_rifle_weapon_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerRifleWeaponCommand::Execute(TimeLost& game){
    if(game.GetTurn() != types::Turns::kPlayer) return;
    game.PlayerChangeWeapon(types::WeaponType::kRifle);
    game.NextTurn();
}

bool PlayerRifleWeaponCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost