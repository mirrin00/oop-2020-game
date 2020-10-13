#include "etu_game/objects/hands.h"

namespace etu_game{

namespace objects{

Hands::~Hands(){}

int Hands::Attack(){ return 0;}

std::unique_ptr<Weapon> Hands::clone() const{
    return std::make_unique<Hands>(*this);
}

std::ostream& Hands::print(std::ostream& os) const{
    os << "Hands:\n";
    os << "    Attack: 0\n";
    return os;
}

} // objects
} // etu_game