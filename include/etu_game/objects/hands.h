#ifndef HANDS_H
#define HANDS_H

#include "weapon.h"

namespace etu_game{

namespace objects{

class Hands: public Weapon{
public:
    using Weapon::Weapon;
    
    ~Hands();

    int Attack();

    std::unique_ptr<Weapon> clone() const;

    virtual std::ostream& print(std::ostream& os) const override;
};

} // objects
} // etu_game

#endif // HANDS_H