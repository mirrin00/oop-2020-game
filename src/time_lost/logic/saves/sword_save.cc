#include "time_lost/logic/saves/sword_save.h"

namespace time_lost{

namespace logic{

namespace saves{

SwordSave::SwordSave(types::Position pos, int damage, bool on_field, bool can_use):
_pos(pos),
_damage(damage),
_on_field(on_field),
_can_use(can_use)
{
}

objects::Sword SwordSave::LoadSword(){
    objects::Sword sword(_damage, _pos);
    sword.SetCanUse(_can_use);
    sword.SetOnField(_on_field);
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
    os.write((char*)&save + offsetof(SwordSave, _pos), offsetof(SwordSave, _can_use)
                 - offsetof(SwordSave, _pos) + sizeof(bool));
    return os;
}

std::istream& operator>>(std::istream& is, SwordSave& save){
    is.read((char*)&save + offsetof(SwordSave, _pos), offsetof(SwordSave, _can_use) 
                - offsetof(SwordSave, _pos) + sizeof(bool));
    return is;
}

} // saves
} // logic
} // time_lost