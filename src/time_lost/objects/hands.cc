#include "time_lost/objects/hands.h"

namespace time_lost{

namespace objects{

Hands::~Hands(){}

int Hands::Attack(){ return 0;}

std::unique_ptr<Weapon> Hands::CloneWeapon() const{
    return std::make_unique<Hands>(*this);
}

std::ostream& Hands::print(std::ostream& os) const{
    os << "Hands:\n";
    os << "    Attack: 0\n";
    return os;
}

} // objects
} // time_lost