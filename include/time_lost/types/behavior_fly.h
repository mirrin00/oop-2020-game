#ifndef BEHAVIOR_FLY_H
#define BEHAVIOR_FLY_H


#include "../objects/enemy.h"
#include "../objects/field.h"
#include "../objects/player.h"

#include "save_type.h"


namespace time_lost{

namespace types{

class BehaviorFly{
public:
    static void Do(objects::Enemy& enemy, objects::Field& field, objects::Player& player);

    static void Attack(objects::Player& player);

    static SaveType::Type GetSaveType();
};

} // types
} // time_lost



#endif // BEHAVIOR_FLY_H