#include "time_lost/objects/player.h"

namespace time_lost{

namespace objects{

Player::Player(int start_health, types::Position start_pos, types::Direction direct):
Essence(start_health, start_pos, direct),
rifle_bullets(0),
pistol_bullets(0),
first_aid_kits(0)
{
    weapon = Hands().CloneWeapon();
}

Player::Player(const Player& player):
Essence(player.health,player.pos)
{
    rifle_bullets = player.rifle_bullets;
    pistol_bullets = player.pistol_bullets;
    first_aid_kits = player.first_aid_kits;
    weapon = player.weapon->CloneWeapon();
}

Player& Player::operator=(const Player& player){
    if(&player == this) return *this;
    pos = player.pos;
    health = player.health;
    rifle_bullets = player.rifle_bullets;
    pistol_bullets = player.pistol_bullets;
    first_aid_kits = player.first_aid_kits;
    weapon = player.weapon->CloneWeapon();
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

void Player::ChangeWeapon(Weapon& new_weapon){
    // FIXME: What do with old weapon?
    weapon = new_weapon.CloneWeapon();
}

// TODO: Enemy& enemy, weapon must interact with enemy
int Player::Attack(){
    return weapon->Attack();
}

logic::saves::PlayerSave Player::SavePlayer(){
    return logic::saves::PlayerSave(pos, health, direct, rifle_bullets, pistol_bullets, first_aid_kits, *weapon);
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

Player& Player::operator+=(Enemy& enemy){
    enemy.ChangeHealth(-Attack());
    return *this;
}

Player& Player::operator-=(Enemy& enemy){
    enemy += *this;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Player& player){
    os << "Player:\n";
    os << *((Essence*)&player);
    os << *(player.weapon);
    //os << "    Coins: " << player.coins << "\n";
    return os;
}

} // objects
} // time_lost