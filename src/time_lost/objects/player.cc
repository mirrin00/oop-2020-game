#include "time_lost/objects/player.h"

namespace time_lost{

namespace objects{

Player::Player(int start_health, types::Position start_pos, Essence::Direction direct):
coins(0),
Essence(start_health, start_pos, direct)
{
    weapon = Hands().CloneWeapon();
}

Player::Player(const Player& player):
Essence(player.health,player.pos)
{
    coins = player.coins;
    weapon = player.weapon->CloneWeapon();
}

Player& Player::operator=(const Player& player){
    if(&player == this) return *this;
    pos = player.pos;
    health = player.health;
    coins = player.coins;
    weapon = player.weapon->CloneWeapon();
    return *this;
}

Player::~Player(){
}

void Player::Notify(){
    pub.Notify<Player>(*this);
}

void Player::AddCoins(int count){
    coins += count;
}

int Player::GetCoins(){
    return coins;
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
    return logic::saves::PlayerSave(pos,coins,health,*weapon);
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
    os << "    Coins: " << player.coins << "\n";
    return os;
}

} // objects
} // time_lost