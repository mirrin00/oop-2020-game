#ifndef TIME_LOST_SAVE_H
#define TIME_LOST_SAVE_H

namespace time_lost{

namespace logic{
class TimeLost;
}
}


#include "../time_lost.h"

#include "player_save.h"
#include "field_save.h"
#include "item_save_interface.h"
#include "enemy_save_interface.h"
#include "../../types/save_type.h"

namespace time_lost{

namespace logic{

namespace saves{

class TimeLostSave{
private:
    PlayerSave _player;

    FieldSave _field;

    std::vector<std::shared_ptr<ItemSaveInterface>> _items;

    std::vector<std::shared_ptr<EnemySave>> _enemys;

    int _step_change;
    
public:
    TimeLostSave() = default;

    TimeLostSave(const TimeLostSave& save);

    TimeLostSave& operator=(const TimeLostSave& save);

    TimeLostSave(objects::Player& player, objects::Field& field,
                std::vector<std::shared_ptr<objects::Item>>& items, 
                std::vector<std::shared_ptr<objects::Enemy>>& enemys, int step_change);

    ~TimeLostSave() = default;

    TimeLost LoadTimeLost();

    friend std::ostream& operator<<(std::ostream& os, TimeLostSave& save);

    friend std::istream& operator>>(std::istream& is, TimeLostSave& save);
};

std::ostream& operator<<(std::ostream& os, TimeLostSave& save);

std::istream& operator>>(std::istream& is, TimeLostSave& save);

} // saves
} // logic
} // time_lost

#endif // TIME_LOST_SAVE_H