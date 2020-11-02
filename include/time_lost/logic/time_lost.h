#ifndef TIME_LOST_H
#define TIME_LOST_H

#include "../objects/player.h"
#include "../objects/sword.h"
#include "../objects/coin.h"
#include "../objects/health_potion.h"
#include "../objects/field_iterator.h"
#include "logger.h"
#include <vector>

namespace time_lost{

namespace logic{

class TimeLost{
protected:
    objects::Player player;

    objects::Field& field;

    std::vector<std::shared_ptr<objects::Item>> items;
public:
    TimeLost(int height, int width);

    ~TimeLost();

    objects::Field& GetField();

    objects::Player& GetPlayer();

    void PlayerMove(types::Position move);

    void PlayerInteract();

    void AddItem(objects::Item& item);

    void AddItem(objects::Item&& item);

    std::shared_ptr<objects::Item> GetItem(int index);

    void Start();

    bool IsWin();
};

} // logic
} // time_lost


#endif // TIME_LOST_H