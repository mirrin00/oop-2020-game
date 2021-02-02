#ifndef KNIFE_H
#define KNIFE_H

#include "weapon.h"

namespace time_lost{

namespace objects{

class Knife: public Weapon{
public:
    Knife() = default;

    ~Knife() = default;

    Knife(const Knife& knife);

    Knife& operator=(const Knife& knife);

    virtual std::tuple<int, int, int> Attack();

    virtual void Reload(int bullets);

    virtual types::WeaponType GetType();

    virtual int GetMaxAmmo();

    virtual std::ostream& print(std::ostream& os) const;

};

    std::ostream& operator<<(std::ostream& os, const Knife& rifle);

} // objects
} // time_lost


#endif // KNIFE_H