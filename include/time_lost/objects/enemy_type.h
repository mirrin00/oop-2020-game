#ifndef ENEMY_TYPE_H
#define ENEMY_TYPE_H

#include "enemy.h"

//#include "../types/behavior_find.h"
//#include "../types/behavior_fly.h"
//#include "../types/behavior_wait.h"
namespace time_lost{

namespace logic{
namespace saves{
class EnemySave;
}
}
}

namespace time_lost{

namespace objects{

template<typename Behavior>
class EnemyType: public Enemy{
public:
    EnemyType(int health, types::Position start_pos = {0,0});

    EnemyType(const EnemyType<Behavior>& enemy);

    EnemyType<Behavior>& operator=(const EnemyType<Behavior>& enemy);
    
    ~EnemyType();

    virtual void DoSomething(Field& field, Player& player) override;

    virtual std::shared_ptr<logic::saves::EnemySave> SaveEnemy() override;

    Enemy& operator+=(Player& player);

    Enemy& operator-=(Player& player);
};

} // objects
} // time_lost

#include "enemy_type.inl"

#endif // ENEMY_TYPE_H