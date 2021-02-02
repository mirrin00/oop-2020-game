#include "time_lost/objects/knife.h"

namespace time_lost{
namespace objects{

constexpr int max_ammo = 0;

Knife::Knife(const Knife& knife){}

Knife& Knife::operator=(const Knife& knife){
    return *this;
}

std::tuple<int, int, int> Knife::Attack(){
    return {1, 10, 10};
}

void Knife::Reload(int bullets){}

types::WeaponType Knife::GetType(){
    return types::WeaponType::kKnife;
}

int Knife::GetMaxAmmo(){
    return max_ammo;
}

std::ostream& Knife::print(std::ostream& os) const{
    os << *this;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Knife& rifle){
    os << "Knife";
    return os;
}

}
} // time_lost
