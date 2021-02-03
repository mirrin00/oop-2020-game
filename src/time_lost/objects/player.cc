#include "time_lost/objects/player.h"

namespace time_lost{

namespace objects{

Player::Player(int start_health, types::Position start_pos, types::Direction direct):
Essence(start_health, start_pos, direct),
rifle_bullets(0),
pistol_bullets(0),
first_aid_kits(0)
{
    rifle = std::make_shared<Rifle>();
    pistol = std::make_shared<Pistol>();
    knife = std::make_shared<Knife>();
    cur_weapon = rifle;
}

Player::Player(const Player& player):
Essence(player.health,player.pos)
{
    rifle_bullets = player.rifle_bullets;
    pistol_bullets = player.pistol_bullets;
    first_aid_kits = player.first_aid_kits;
    *rifle = *player.rifle;
    *pistol = *player.pistol;
    *knife = *player.knife;
    switch(player.cur_weapon->GetType()){
        case types::WeaponType::kRifle:
            cur_weapon = rifle;
            break;
        case types::WeaponType::kPistol:
            cur_weapon = pistol;
            break;
        case types::WeaponType::kKnife:
            cur_weapon = knife;
            break;
        default:
            cur_weapon = rifle;
    }
}

Player& Player::operator=(const Player& player){
    if(&player == this) return *this;
    pos = player.pos;
    health = player.health;
    rifle_bullets = player.rifle_bullets;
    pistol_bullets = player.pistol_bullets;
    first_aid_kits = player.first_aid_kits;
    *rifle = *player.rifle;
    *pistol = *player.pistol;
    *knife = *player.knife;
    switch(player.cur_weapon->GetType()){
        case types::WeaponType::kRifle:
            cur_weapon = rifle;
            break;
        case types::WeaponType::kPistol:
            cur_weapon = pistol;
            break;
        case types::WeaponType::kKnife:
            cur_weapon = knife;
            break;
        default:
            cur_weapon = rifle;
    }
    return *this;
}

Player::~Player(){
}

void Player::Notify(){
    pub.Notify<Player>(*this);
}

void Player::AddRifleBullets(int bullet_count){
    rifle_bullets += bullet_count;
}

int Player::GetRifleBullets(){
    return rifle_bullets;
}

void Player::AddPistolBullets(int bullet_count){
    pistol_bullets += bullet_count;
}

int Player::GetPistolBullets(){
    return pistol_bullets;
}

void Player::AddFirstAidKits(int first_aid_kit_count){
    first_aid_kits += first_aid_kit_count;
}

int Player::GetFirstAidKits(){
    return first_aid_kits;
}

std::tuple<int, int, int> Player::Attack(){
    return cur_weapon->Attack();
}

void Player::ChangeWeapon(types::WeaponType weapon_type){
    switch(weapon_type){
        case types::WeaponType::kRifle:
            cur_weapon = rifle;
            break;
        case types::WeaponType::kPistol:
            cur_weapon = pistol;
            break;
        case types::WeaponType::kKnife:
            cur_weapon = knife;
            break;
    }
}

void Player::Reload(){
    switch(cur_weapon->GetType()){
        case types::WeaponType::kRifle:
            cur_weapon->Reload(std::min(rifle_bullets, cur_weapon->GetMaxAmmo()));
            rifle_bullets = std::max(rifle_bullets - cur_weapon->GetMaxAmmo() + cur_weapon->GetCurrentAmmo(), 0);
            break;
        case types::WeaponType::kPistol:
            cur_weapon->Reload(std::min(pistol_bullets, cur_weapon->GetMaxAmmo()));
            pistol_bullets = std::max(pistol_bullets - cur_weapon->GetMaxAmmo() + cur_weapon->GetCurrentAmmo(), 0);
            break;
    }
}

std::shared_ptr<Weapon> Player::GetWeapon(types::WeaponType weapon_type){
    switch(weapon_type){
        case types::WeaponType::kRifle:
            return rifle;
        case types::WeaponType::kPistol:
            return pistol;
        case types::WeaponType::kKnife:
            return knife;
        default:
            return nullptr;
    }
}

logic::saves::PlayerSave Player::SavePlayer(){
    return logic::saves::PlayerSave(pos, health, direct, rifle_bullets, pistol_bullets, first_aid_kits,
        rifle->GetCurrentAmmo(), pistol->GetCurrentAmmo(), cur_weapon->GetType());
}

Player& Player::operator+=(Item& item){
    item.Use(*this);
    Notify(); // Logging
    return *this;
}

Player& Player::operator+=(Item&& item){
    item.Use(*this);
    Notify(); // Logging
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Player& player){
    os << "Player:\n";
    os << *((Essence*)&player);
    os << "    Weapon: " << *(player.cur_weapon) << "\n";
    //os << "    Coins: " << player.coins << "\n";
    return os;
}

} // objects
} // time_lost