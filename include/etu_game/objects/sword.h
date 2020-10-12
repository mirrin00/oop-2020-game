#ifndef SWORD_H
#define SWORD_H

#include "item.h"
#include "weapon.h"

namespace etu_game{

namespace objects{

class Sword: public Item,public Weapon{
private:
    int damage;
protected:
    virtual void Notify() override;
public:
    Sword(int _damage, int h_pos = 0, int w_pos = 0);

    Sword(const Sword& sword);

    ~Sword();

    Sword& operator=(const Sword& sword);

    int Attack();

    virtual void Use(Player& player) override;

    virtual std::unique_ptr<Weapon> clone() const override;

    virtual std::ostream& print(std::ostream& os) const override;

    friend std::ostream& operator<<(std::ostream& os, const Sword& sword);
};

    std::ostream& operator<<(std::ostream& os, const Sword& sword);

} // objects
} // etu_game


#endif // SWORD_H