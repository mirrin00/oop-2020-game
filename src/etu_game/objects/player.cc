#include "etu_game/objects/player.h"

namespace etu_game{

namespace objects{

Player::Player(int start_health, int start_h_pos, int start_w_pos):
coins(0),
Essence(start_health, start_h_pos, start_w_pos)
{
    weapon = Hands().clone();
}

Player::~Player(){

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
    weapon = new_weapon.clone();
}

// TODO: Enemy& enemy, weapon must interact with enemy
int Player::Attack(){
    return weapon->Attack();
}

void Player::operator+=(Item& item){
    item.Use(*this);
}



} // objects
} // etu_game