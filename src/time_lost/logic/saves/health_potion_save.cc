#include "time_lost/logic/saves/health_potion_save.h"

namespace time_lost{

namespace logic{

namespace saves{

HealthPotionSave::HealthPotionSave(types::Position pos, int health_change, bool on_field, bool can_use):
data{pos, health_change, on_field, can_use}
{
}

HealthPotionSave::~HealthPotionSave(){}

objects::HealthPotion HealthPotionSave::LoadHealthPotion(){
    objects::HealthPotion HealthPotion(data.health_change, data.pos);
    HealthPotion.SetCanUse(data.can_use);
    HealthPotion.SetOnField(data.on_field);
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
    os.write((char*)&save.data, sizeof(HealthPotionSave::Data));
    return os;
}

std::istream& operator>>(std::istream& is, HealthPotionSave& save){
    is.read((char*)&save.data, sizeof(HealthPotionSave::Data));
    if(save.data.pos.x < 0 || save.data.pos.y < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.health_change <= 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    return is;
}

} // saves
} // logic
} // time_lost