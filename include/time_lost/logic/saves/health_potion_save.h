#ifndef HEALTH_POTION_SAVE_H
#define HEALTH_POTION_SAVE_H

namespace time_lost{

namespace objects{
class HealthPotion;
}
}

#include "item_save_interface.h"
#include "../../objects/health_potion.h"
#include "../../types/save_type.h"

namespace time_lost{

namespace logic{

namespace saves{

class HealthPotionSave: public ItemSaveInterface{
private:
    types::Position _pos;
    
    int _health_change;

    bool _on_field, _can_use;
public:
    HealthPotionSave() = default;

    HealthPotionSave(types::Position pos, int health_change, bool on_field, bool can_use);

    ~HealthPotionSave();

    objects::HealthPotion LoadHealthPotion();

    std::shared_ptr<objects::Item> LoadItem() override;

    virtual void WriteItem(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, HealthPotionSave& save);

    friend std::istream& operator>>(std::istream& is, HealthPotionSave& save);
};

std::ostream& operator<<(std::ostream& os, HealthPotionSave& save);

std::istream& operator>>(std::istream& is, HealthPotionSave& save);

} // saves
} // logic
} // time_lost


#endif // HEALTH_POTION_SAVE_H