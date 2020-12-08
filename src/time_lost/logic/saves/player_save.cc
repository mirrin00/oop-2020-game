#include "time_lost/logic/saves/player_save.h"

#include "time_lost/logic/saves/sword_save.h"
#include "time_lost/logic/saves/hands_save.h"

namespace time_lost{

namespace logic{

namespace saves{

PlayerSave::PlayerSave(types::Position pos, int coins, int health, objects::Weapon& weapon):
_pos(pos),
_coins(coins),
_health(health),
_weapon(weapon.SaveWeapon())
{
}

objects::Player PlayerSave::LoadPlayer(){
    objects::Player player(_health,_pos);
    player.AddCoins(_coins);
    player.ChangeWeapon(*(_weapon->LoadWeapon()));
    return player;
}

std::ostream& operator<<(std::ostream& os, PlayerSave& save){
    int type = types::SaveType::kPlayer;
    os.write((char*)&type, sizeof(int));
    //auto weapon = save._weapon;
    //save._weapon = nullptr;
    os.write((char*)&save, offsetof(PlayerSave, _weapon));
    save._weapon->WriteWeapon(os);
    //save._weapon = weapon;
    return os;
}

std::istream& operator>>(std::istream& is, PlayerSave& save){
    is.read((char*)&save, offsetof(PlayerSave, _weapon));
    int type;
    is.read((char*)&type,sizeof(int));
    switch(type){
        case types::SaveType::kHands:
            {auto hands = std::make_shared<HandsSave>();
            is >> *(hands);
            save._weapon = hands;}
            break;
        case types::SaveType::kSword:
            {auto sword = std::make_shared<SwordSave>();
            is >> *(sword);
            save._weapon = sword;}
            break;
        default:
            throw types::TimeLostException((std::string(__FILE__) + ":" + std::to_string(__LINE__)) + "Reading save: Bad Save");
    }
    return is;
}

} // saves
} // logic
} // time_lost