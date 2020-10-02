#include "etu_game/objects/hands.h"

namespace etu_game{

namespace objects{

Hands::~Hands(){}

int Hands::Attack(){ return 0;}

std::unique_ptr<Weapon> Hands::clone() const{
    return std::make_unique<Hands>(*this);
}

} // objects
} // etu_game