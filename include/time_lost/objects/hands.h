#ifndef HANDS_H
#define HANDS_H

#include "weapon.h"

namespace time_lost{

namespace objects{

class Hands: public Weapon{
public:
    using Weapon::Weapon;
    
    ~Hands();

    int Attack();

    std::unique_ptr<Weapon> CloneWeapon() const;

    virtual std::ostream& print(std::ostream& os) const override;
};

} // objects
} // time_lost

#endif // HANDS_H