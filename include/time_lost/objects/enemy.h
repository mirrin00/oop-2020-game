#ifndef ENEMY_H
#define ENEMY_H

#include "essence.h"
#include "field.h"
#include "player.h"

namespace time_lost{
namespace logic{
namespace saves{
class EnemySave;
}
}
}



namespace time_lost{

namespace objects{

class Enemy: public Essence{
public:
    Enemy(int health, types::Position start_pos = {0,0}, types::Direction direct = types::Direction::kUp): Essence(health, start_pos, direct){}

    virtual ~Enemy() = default;

    virtual void DoSomething(Field& field, Player& player) = 0;

    virtual std::shared_ptr<logic::saves::EnemySave> SaveEnemy() = 0;

    virtual Enemy& operator+=(Player& player) = 0;
};

} // obcjects
} // time_lost

#include "../logic/saves/enemy_save_interface.h"

#endif // ENEMY_H