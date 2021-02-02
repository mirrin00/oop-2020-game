#include "time_lost/objects/rifle.h"

namespace time_lost{
namespace objects{

constexpr int max_ammo = 5;

Rifle::Rifle(const Rifle& rifle){
    cur_ammo = rifle.cur_ammo;
}

Rifle& Rifle::operator=(const Rifle& rifle){
    if(&rifle == this) return *this;
    cur_ammo = rifle.cur_ammo;
    return *this;
}

std::tuple<int, int, int> Rifle::Attack(){
    return {10, 12, 3};
}

void Rifle::Reload(int bullets){
    cur_ammo = (cur_ammo + bullets) % (max_ammo + 1);
}

types::WeaponType Rifle::GetType(){
    return types::WeaponType::kRifle;
}

int Rifle::GetMaxAmmo(){
    return max_ammo;
}

std::ostream& Rifle::print(std::ostream& os) const{
    os << *this;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Rifle& rifle){
    os << "Rifle";
    return os;
}

}
} // time_lost
