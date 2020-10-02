#include "etu_game/objects/sword.h"

namespace etu_game{

namespace objects{

Sword::Sword(int _damage, int h_pos , int w_pos):
damage(_damage),
Item(h_pos, w_pos)
{
}
//FIXME: What is it?
//Sword::~Sword(){}

Sword::Sword(const Sword& sword):Item(sword){
    damage = sword.damage;
}
//FIXME: if(this == &sword)
Sword& Sword::operator=(const Sword& sword){
    //damage = sword.damage;
    return *this;
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

} // objects
} // etu_game