#ifndef SWORD_H
#define SWORD_H

#include "item.h"
#include "weapon.h"

namespace time_lost{
namespace logic{
namespace saves{
class SwordSave;
}
}
}

#include "../logic/saves/sword_save.h"

namespace time_lost{

namespace objects{

class Sword: public Item,public Weapon{
private:
    int damage;
protected:
    virtual void Notify() override;
public:
    Sword(int _damage, types::Position start_pos = {0,0});

    Sword(const Sword& sword);

    ~Sword();

    Sword& operator=(const Sword& sword);

    int Attack();

    logic::saves::SwordSave SaveSword();

    virtual void Use(Player& player) override;

    virtual std::unique_ptr<Weapon> CloneWeapon() const override;

    virtual std::shared_ptr<Item> CloneItem() const override;

    virtual std::ostream& print(std::ostream& os) const override;

    virtual std::shared_ptr<logic::saves::WeaponSaveInterface> SaveWeapon() override;

    virtual std::shared_ptr<logic::saves::ItemSaveInterface> SaveItem() override;

    friend std::ostream& operator<<(std::ostream& os, const Sword& sword);
};

    std::ostream& operator<<(std::ostream& os, const Sword& sword);

} // objects
} // time_lost


#endif // SWORD_H