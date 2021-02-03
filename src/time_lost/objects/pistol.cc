#include "time_lost/objects/pistol.h"

namespace time_lost{
namespace objects{

constexpr int max_ammo = 8;

Pistol::Pistol(const Pistol& pistol){
    cur_ammo = pistol.cur_ammo;
}

Pistol& Pistol::operator=(const Pistol& pistol){
    if(&pistol == this) return *this;
    cur_ammo = pistol.cur_ammo;
    return *this;
}

std::tuple<int, int, int> Pistol::Attack(){
    if(cur_ammo == 0) return {0, 0, 0};
    return {4, 7, 5};
}

void Pistol::Reload(int bullets){
    cur_ammo = (cur_ammo + bullets) % (max_ammo + 1);
}

types::WeaponType Pistol::GetType(){
    return types::WeaponType::kPistol;
}

int Pistol::GetMaxAmmo(){
    return max_ammo;
}

std::ostream& Pistol::print(std::ostream& os) const{
    os << *this;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Pistol& rifle){
    os << "Pistol";
    return os;
}

}
} // time_lost
