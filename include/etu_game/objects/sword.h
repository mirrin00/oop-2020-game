#ifndef SWORD_H
#define SWORD_H

#include "item.h"
#include "weapon.h"

namespace etu_game{

namespace objects{

class Sword: public Item,public Weapon{
private:
    int damage;

public:
    Sword(int _damage, int h_pos = 0, int w_pos = 0);

    Sword(const Sword& sword);

    Sword& operator=(const Sword& sword);

    int Attack();

    void Use(Player& player);

    virtual std::unique_ptr<Weapon> clone() const override;
};

} // objects
} // etu_game


#endif // SWORD_H