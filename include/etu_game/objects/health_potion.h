#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

#include "item.h"

namespace etu_game{

namespace objects{

class HealthPotion: public Item{
private:
    int health_change;

public:
    HealthPotion(int h_change, int start_h_pos = 0, int start_w_pos = 0);

    ~HealthPotion();

    HealthPotion(const HealthPotion& hp);

    HealthPotion& operator=(const HealthPotion& hp);

    int GetHealthChange();
    // FIXME: SetHealthChange()?

    void Use(Player& player);
};

} // objects
} // etu_game


#endif // HEALTH_POTION_H