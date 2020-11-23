#ifndef ENEMY_H
#define ENEMY_H

#include "essence.h"
#include "field.h"
#include "player.h"

namespace time_lost{

namespace objects{

class Enemy: public Essence{
public:
    Enemy(int health, types::Position start_pos = {0,0}): Essence(health, start_pos){}

    virtual ~Enemy() = default;

    virtual void DoSomething(Field& field, Player& player) = 0;

    virtual Enemy& operator+=(Player& player) = 0;

    virtual Enemy& operator-=(Player& player) = 0;
};

} // obcjects
} // time_lost


#endif // ENEMY_H