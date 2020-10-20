#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

#include "item.h"

namespace etu_game{

namespace objects{

class HealthPotion: public Item{
private:
    int health_change;
protected:
    virtual void Notify() override;
public:
    HealthPotion(int h_change, int start_h_pos = 0, int start_w_pos = 0);

    ~HealthPotion();

    HealthPotion(const HealthPotion& hp);

    HealthPotion& operator=(const HealthPotion& hp);

    int GetHealthChange();
    // FIXME: SetHealthChange()?

    virtual void Use(Player& player) override;

    virtual std::shared_ptr<Item> clone() override;

    friend std::ostream& operator<<(std::ostream& os, const HealthPotion& hp);
};

    std::ostream& operator<<(std::ostream& os, const HealthPotion& hp);

} // objects
} // etu_game


#endif // HEALTH_POTION_H