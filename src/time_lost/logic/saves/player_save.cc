#include "time_lost/logic/saves/player_save.h"

namespace time_lost{

namespace logic{

namespace saves{

PlayerSave::PlayerSave(types::Position pos, int health, types::Direction direct, int rifle_bullets,
         int pistol_bullets, int first_aid_kits, int rifle_ammo, int pistol_ammo, types::WeaponType cur_type):
data{pos, health, direct, rifle_bullets, pistol_bullets, first_aid_kits, rifle_ammo, pistol_ammo, cur_type}
{
}

objects::Player PlayerSave::LoadPlayer(){
    objects::Player player(data.health,data.pos, data.direct);
    player.AddRifleBullets(data.rifle_bullets);
    player.AddPistolBullets(data.pistol_bullets);
    player.AddFirstAidKits(data.first_aid_kits);
    player.GetWeapon(types::WeaponType::kRifle)->Reload(data.rifle_ammo);
    player.GetWeapon(types::WeaponType::kPistol)->Reload(data.pistol_ammo);
    player.ChangeWeapon(data.cur_type);
    return player;
}

std::ostream& operator<<(std::ostream& os, PlayerSave& save){
    int type = types::SaveType::kPlayer;
    os.write((char*)&type, sizeof(int));
    os.write((char*)&save.data, sizeof(PlayerSave::Data));
    return os;
}

std::istream& operator>>(std::istream& is, PlayerSave& save){
    is.read((char*)&save.data, sizeof(PlayerSave::Data));
    if(save.data.pos.x < 0 || save.data.pos.y < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.first_aid_kits < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.pistol_bullets < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.rifle_bullets < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.rifle_ammo < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.pistol_ammo < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    return is;
}

} // saves
} // logic
} // time_lost