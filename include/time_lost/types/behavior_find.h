#ifndef BEHAVIOR_RUN_H
#define BEHAVIOR_RUN_H

#include "../objects/field.h"
#include "../objects/player.h"
#include "../objects/enemy_type.h"

namespace time_lost{

namespace types{

class BehaviorFind{
public:
    static void Do(objects::Enemy& enemy, objects::Field& field, objects::Player& player);
};

} // types
} // time_lost


#endif // BEHAVIOR_RUN_H