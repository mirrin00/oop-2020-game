#include "enemy_type.h"

namespace time_lost{

namespace objects{

template<typename Behavior>
EnemyType<Behavior>::EnemyType(int health, types::Position start_pos):Enemy(health, start_pos)
{
}

template<typename Behavior>
EnemyType<Behavior>::~EnemyType(){}

template<typename Behavior>
void EnemyType<Behavior>::DoSomething(Field& field, Player& player){
    Behavior::Do(*this, field, player);
}

template<typename Behavior>
Enemy& EnemyType<Behavior>::operator+=(Player& player){
    player.ChangeHealth(-1);
    return *this;
}

template<typename Behavior>
Enemy& EnemyType<Behavior>::operator-=(Player& player){
    player += *this;
    return *this;
}

} // objects
} // time_lost