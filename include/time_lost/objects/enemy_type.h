#ifndef ENEMY_TYPE_H
#define ENEMY_TYPE_H

#include "enemy.h"

namespace time_lost{

namespace objects{

template<typename Behavior>
class EnemyType: public Enemy{
public:
    EnemyType(int health, types::Position start_pos = {0,0});
    
    ~EnemyType();

    virtual void DoSomething(Field& field, Player& player) override;

    Enemy& operator+=(Player& player);

    Enemy& operator-=(Player& player);
};

} // objects
} // time_lost

#include "enemy_type.inl"

#endif // ENEMY_TYPE_H