#include "time_lost/logic/saves/sword_save.h"

namespace time_lost{

namespace logic{

namespace saves{

SwordSave::SwordSave(types::Position pos, int damage, bool on_field):
data{pos, damage, on_field}
{
}

objects::Sword SwordSave::LoadSword(){
    objects::Sword sword(data.damage, data.pos);
    sword.SetOnField(data.on_field);
    return sword;
}

std::shared_ptr<objects::Item> SwordSave::LoadItem(){
    return LoadSword().CloneItem();
}

std::unique_ptr<objects::Weapon> SwordSave::LoadWeapon(){
    return LoadSword().CloneWeapon();
}

void SwordSave::WriteItem(std::ostream& os){
    os << *this;
}

void SwordSave::WriteWeapon(std::ostream& os){
    os << *this;
}

std::ostream& operator<<(std::ostream& os, SwordSave& save){
    int type = types::SaveType::kSword;
    os.write((char*)&type, sizeof(int));
    os.write((char*)&save.data, sizeof(SwordSave::Data));
    return os;
}

std::istream& operator>>(std::istream& is, SwordSave& save){
    is.read((char*)&save.data, sizeof(SwordSave::Data));
    if(save.data.pos.x < 0 || save.data.pos.y < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.damage < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    return is;
}

} // saves
} // logic
} // time_lost