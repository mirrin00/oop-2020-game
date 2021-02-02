#include "enemy_type.h"

namespace time_lost{

namespace objects{

template<typename Behavior>
EnemyType<Behavior>::EnemyType(int health, types::Position start_pos, types::Direction direct):Enemy(health, start_pos, direct)
{
}

template<typename Behavior>
EnemyType<Behavior>::EnemyType(const EnemyType<Behavior>& enemy):
Enemy(enemy.health, enemy.pos)
{
}

template<typename Behavior>
EnemyType<Behavior>& EnemyType<Behavior>::operator=(const EnemyType<Behavior>& enemy){
    if(&enemy == this) return *this;
    pos = enemy.pos;
    health = enemy.health;
    return *this;
}

template<typename Behavior>
EnemyType<Behavior>::~EnemyType(){}

template<typename Behavior>
void EnemyType<Behavior>::DoSomething(Field& field, Player& player){
    Behavior::Do(*this, field, player);
}

template<typename Behavior>
std::shared_ptr<logic::saves::EnemySave> EnemyType<Behavior>::SaveEnemy(){
    return std::make_shared<logic::saves::EnemySave>(pos, health, direct, Behavior::GetSaveType());
}

template<typename Behavior>
Enemy& EnemyType<Behavior>::operator+=(Player& player){
    Behavior::Attack(player);
    return *this;
}

} // objects
} // time_lost