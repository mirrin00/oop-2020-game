#include "etu_game/objects/sword.h"

namespace etu_game{

namespace objects{

Sword::Sword(int _damage, int h_pos , int w_pos):
damage(_damage),
Item(h_pos, w_pos)
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
    if(IsCanUse()) return damage;
    return 0;
}

void Sword::Use(Player& player){
    player.ChangeWeapon(*this);
}

std::unique_ptr<Weapon> Sword::clone() const{
    return std::make_unique<Sword>(*this);
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
} // etu_game