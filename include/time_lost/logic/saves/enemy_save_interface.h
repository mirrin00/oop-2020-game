#ifndef ENEMY_SAVE_INTERFACE_H
#define ENEMY_SAVE_INTERFACE_H

namespace time_lost{

namespace objects{
template<typename T>
class EnemyType;
}
}

#include "../../objects/enemy.h"
#include "../../objects/enemy_type.h"

namespace time_lost{

namespace logic{

namespace saves{

class EnemySave{
private:
    struct Data{
        types::Position pos;

        int health;

        types::SaveType::Type type;
    };

    Data data;
public:
    EnemySave() = default;

    EnemySave(types::Position pos, int health, types::SaveType::Type type);

    ~EnemySave() = default;

    template<typename Behavior>
    std::shared_ptr<objects::Enemy> LoadEnemy(){
        objects::EnemyType<Behavior> enemy(data.health, data.pos);
        return std::make_shared<objects::EnemyType<Behavior>>(enemy);
    }

    types::SaveType::Type GetSaveType();

    friend std::ostream& operator<<(std::ostream& os, EnemySave& save);

    friend std::istream& operator>>(std::istream& is, EnemySave& save);
};

std::ostream& operator<<(std::ostream& os, EnemySave& save);

std::istream& operator>>(std::istream& is, EnemySave& save);

} // saves
} // logic
} // time_lost


#endif // ENEMY_SAVE_INTERFACE_H