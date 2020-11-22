#ifndef BEHAVIOR_WAIT_H
#define BEHAVIOR_WAIT_H

#include "../objects/field.h"
#include "../objects/player.h"
#include "../objects/enemy_type.h"

namespace time_lost{

namespace types{

class BehaviorWait{
public:
    static void Do(objects::Enemy& enemy, objects::Field& field, objects::Player& player);
};

} // types
} // time_lost


#endif // BEHAVIOR_WAIT_H