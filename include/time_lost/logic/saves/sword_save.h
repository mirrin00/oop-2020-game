#ifndef SWORD_SAVE_H
#define SWORD_SAVE_H

namespace time_lost{

namespace objects{
class Sword;
}
}


#include "weapon_save_interface.h"
#include "item_save_interface.h"
#include "../../objects/sword.h"
#include "../../types/save_type.h"

namespace time_lost{

namespace logic{

namespace saves{

class SwordSave: public WeaponSaveInterface, public ItemSaveInterface{
private:
    types::Position _pos;
    
    int _damage;

    bool _on_field, _can_use;
public:
    SwordSave() = default;

    SwordSave(types::Position pos, int damage, bool on_field, bool can_use);

    ~SwordSave() = default;

    objects::Sword LoadSword();

    virtual std::shared_ptr<objects::Item> LoadItem() override;
    
    virtual std::unique_ptr<objects::Weapon> LoadWeapon() override;

    virtual void WriteItem(std::ostream& os) override;

    virtual void WriteWeapon(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, SwordSave& save);

    friend std::istream& operator>>(std::istream& is, SwordSave& save);
};

std::ostream& operator<<(std::ostream& os, SwordSave& save);

std::istream& operator>>(std::istream& is, SwordSave& save);

} // saves
} // logic
} // time_lost


#endif // SWORD_SAVE_H