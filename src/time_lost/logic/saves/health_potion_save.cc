#include "time_lost/logic/saves/health_potion_save.h"

namespace time_lost{

namespace logic{

namespace saves{

HealthPotionSave::HealthPotionSave(types::Position pos, int health_change, bool on_field, bool can_use):
_pos(pos),
_health_change(health_change),
_on_field(on_field),
_can_use(can_use)
{
}

HealthPotionSave::~HealthPotionSave(){}

objects::HealthPotion HealthPotionSave::LoadHealthPotion(){
    objects::HealthPotion HealthPotion(_health_change, _pos);
    HealthPotion.SetCanUse(_can_use);
    HealthPotion.SetOnField(_on_field);
    return HealthPotion;
}

std::shared_ptr<objects::Item> HealthPotionSave::LoadItem(){
    return LoadHealthPotion().CloneItem();
}

void HealthPotionSave::WriteItem(std::ostream& os){
    os << *this;
}

std::ostream& operator<<(std::ostream& os, HealthPotionSave& save){
    int type = types::SaveType::kHealthPotion;
    os.write((char*)&type, sizeof(int));
    os.write((char*)&save + offsetof(HealthPotionSave, _pos), offsetof(HealthPotionSave, _can_use)
                 - offsetof(HealthPotionSave, _pos) + sizeof(bool));
    return os;
}

std::istream& operator>>(std::istream& is, HealthPotionSave& save){
    is.read((char*)&save + offsetof(HealthPotionSave, _pos), offsetof(HealthPotionSave, _can_use)
                 - offsetof(HealthPotionSave, _pos) + sizeof(bool));
    return is;
}

} // saves
} // logic
} // time_lost