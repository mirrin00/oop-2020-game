#include "time_lost/objects/health_potion.h"

namespace time_lost{

namespace objects{

HealthPotion::HealthPotion(int h_change, int start_h_pos, int start_w_pos):
health_change(h_change),
Item(start_h_pos, start_w_pos)
{
}

HealthPotion::~HealthPotion(){}

HealthPotion::HealthPotion(const HealthPotion& hp): Item(hp)
{
    health_change = hp.health_change;
}

HealthPotion& HealthPotion::operator=(const HealthPotion& hp){
    if(&hp == this) return *this;
    Item::operator=(hp);
    health_change = hp.health_change;
    return *this;
}

void HealthPotion::Notify(){
    pub.Notify<HealthPotion>(*this);
}

int HealthPotion::GetHealthChange(){
    return health_change;
}

void HealthPotion::Use(Player& player){
    if(IsCanUse()) player.ChangeHealth(health_change);
    SetCanUse(false);
    Notify(); // Logging
}

std::shared_ptr<Item> HealthPotion::CloneItem() const{
    return std::make_unique<HealthPotion>(*this);
}

std::ostream& operator<<(std::ostream& os, const HealthPotion& hp){
    os << "HealthPotion:\n";
    os << *((Item*)&hp);
    os << "    Health change: " << hp.health_change << "\n";
    return os;
}

} // objects
} // time_lost