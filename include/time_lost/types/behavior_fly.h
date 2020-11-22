#ifndef BEHAVIOR_FLY_H
#define BEHAVIOR_FLY_H

#include "../objects/field.h"
#include "../objects/player.h"
#include "../objects/enemy_type.h"

namespace time_lost{

namespace types{

class BehaviorFly{
public:
    static void Do(objects::Enemy& enemy, objects::Field& field, objects::Player& player);
};

} // types
} // time_lost


#endif // BEHAVIOR_FLY_H