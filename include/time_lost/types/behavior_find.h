#ifndef BEHAVIOR_RUN_H
#define BEHAVIOR_RUN_H



#include "../objects/enemy.h"
#include "../objects/field.h"
#include "../objects/player.h"

#include "save_type.h"

namespace time_lost{

namespace types{

class BehaviorFind{
public:
    static void Do(objects::Enemy& enemy, objects::Field& field, objects::Player& player);

    static SaveType::Type GetSaveType();
};

} // types
} // time_lost



#endif // BEHAVIOR_RUN_H