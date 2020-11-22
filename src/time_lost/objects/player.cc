#include "time_lost/objects/player.h"

namespace time_lost{

namespace objects{

Player::Player(int start_health, types::Position start_pos):
coins(0),
Essence(start_health, start_pos)
{
    weapon = Hands().CloneWeapon();
}

Player& Player::operator=(const Player& player){
    if(&player == this) return *this;
    coins = player.coins;
    weapon = player.weapon->CloneWeapon();
    return *this;
}

Player::~Player(){
}

void Player::Notify(){
    pub.Notify<Player>(*this);
}

void Player::ChangeHealth(int change_h){
    health += change_h;
}

int Player::GetHealth(){
    return health;
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
    os << *(player.weapon);
    os << "    Coins: " << player.coins << "\n";
    return os;
}

} // objects
} // time_lost