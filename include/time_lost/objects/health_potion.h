#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

#include "item.h"

namespace time_lost{

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

    virtual std::shared_ptr<Item> CloneItem() const override;

    friend std::ostream& operator<<(std::ostream& os, const HealthPotion& hp);
};

    std::ostream& operator<<(std::ostream& os, const HealthPotion& hp);

} // objects
} // time_lost


#endif // HEALTH_POTION_H