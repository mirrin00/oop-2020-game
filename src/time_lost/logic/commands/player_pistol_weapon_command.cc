#include "time_lost/logic/commands/player_pistol_weapon_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerPistolWeaponCommand::Execute(TimeLost& game){
    if(game.GetTurn() != types::Turns::kPlayer) return;
    game.PlayerChangeWeapon(types::WeaponType::kPistol);
    game.NextTurn();
}

bool PlayerPistolWeaponCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost