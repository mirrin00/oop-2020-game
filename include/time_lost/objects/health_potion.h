#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

#include "item.h"

namespace time_lost{
namespace logic{
namespace saves{
class HealthPotionSave;
}
}
}

#include "../logic/saves/health_potion_save.h"

namespace time_lost{

namespace objects{

class HealthPotion: public Item{
private:
    int health_change;
protected:
    virtual void Notify() override;
public:
    HealthPotion(int h_change, types::Position start_pos = {0,0});

    ~HealthPotion();

    HealthPotion(const HealthPotion& hp);

    HealthPotion& operator=(const HealthPotion& hp);

    int GetHealthChange();
    // FIXME: SetHealthChange()?

    virtual void Use(Player& player) override;

    virtual std::shared_ptr<Item> CloneItem() const override;

    std::shared_ptr<logic::saves::HealthPotionSave> SaveHealthPotion();

    virtual std::shared_ptr<logic::saves::ItemSaveInterface> SaveItem() override;

    friend std::ostream& operator<<(std::ostream& os, const HealthPotion& hp);
};

    std::ostream& operator<<(std::ostream& os, const HealthPotion& hp);

} // objects
} // time_lost


#endif // HEALTH_POTION_H