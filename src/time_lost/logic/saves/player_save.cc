#include "time_lost/logic/saves/player_save.h"

#include "time_lost/logic/saves/sword_save.h"
#include "time_lost/logic/saves/hands_save.h"

namespace time_lost{

namespace logic{

namespace saves{

PlayerSave::PlayerSave(types::Position pos, int health, types::Direction direct, int rifle_bullets, int pistol_bullets, int first_aid_kits, objects::Weapon& weapon):
data{pos, health, direct, rifle_bullets, pistol_bullets, first_aid_kits},
_weapon(weapon.SaveWeapon())
{
}

objects::Player PlayerSave::LoadPlayer(){
    objects::Player player(data.health,data.pos, data.direct);
    player.AddRifleBullets(data.rifle_bullets);
    player.AddPistolBullets(data.pistol_bullets);
    player.AddFirstAidKits(data.first_aid_kits);
    player.ChangeWeapon(*(_weapon->LoadWeapon()));
    return player;
}

std::ostream& operator<<(std::ostream& os, PlayerSave& save){
    int type = types::SaveType::kPlayer;
    os.write((char*)&type, sizeof(int));
    os.write((char*)&save.data, sizeof(PlayerSave::Data));
    save._weapon->WriteWeapon(os);
    return os;
}

std::istream& operator>>(std::istream& is, PlayerSave& save){
    is.read((char*)&save.data, sizeof(PlayerSave::Data));
    if(save.data.pos.x < 0 || save.data.pos.y < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.first_aid_kits < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.pistol_bullets < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.rifle_bullets < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
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