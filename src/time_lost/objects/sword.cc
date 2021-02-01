#include "time_lost/objects/sword.h"

namespace time_lost{

namespace objects{

Sword::Sword(int _damage, types::Position start_pos):
damage(_damage),
Item(start_pos)
{
}

Sword::~Sword(){}

Sword::Sword(const Sword& sword):Item(sword){
    damage = sword.damage;
}

Sword& Sword::operator=(const Sword& sword){
    if(&sword == this) return *this;
    Item::operator=(sword);
    damage = sword.damage;
    return *this;
}

void Sword::Notify(){
    pub.Notify<Sword>(*this);
}

int Sword::Attack(){
    return damage;
}

logic::saves::SwordSave Sword::SaveSword(){
    return logic::saves::SwordSave(pos, damage, IsOnField());
}

void Sword::Use(Player& player){
    player.ChangeWeapon(*this);
}

std::unique_ptr<Weapon> Sword::CloneWeapon() const{
    return std::make_unique<Sword>(*this);
}

std::shared_ptr<Item> Sword::CloneItem() const{
    return std::make_shared<Sword>(*this);
}

std::shared_ptr<logic::saves::WeaponSaveInterface> Sword::SaveWeapon(){
    return std::make_shared<logic::saves::SwordSave>(pos, damage, IsOnField());
}

std::shared_ptr<logic::saves::ItemSaveInterface> Sword::SaveItem(){
    return std::make_shared<logic::saves::SwordSave>(pos, damage, IsOnField());
}

std::ostream& operator<<(std::ostream& os, const Sword& sword){
    os << "Sword:\n";
    os << *((Item*)&sword);
    os << "    Damage: " << sword.damage << "\n";
    return os;
}

std::ostream& Sword::print(std::ostream& os) const{
    os << *this;
    return os;
}

} // objects
} // time_lost