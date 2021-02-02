#ifndef RIFLE_H
#define RIFLE_H

#include "weapon.h"

namespace time_lost{

namespace objects{

class Rifle: public Weapon{
public:
    Rifle() = default;

    ~Rifle() = default;

    Rifle(const Rifle& rifle);

    Rifle& operator=(const Rifle& rifle);

    virtual std::tuple<int, int, int> Attack();

    virtual void Reload(int bullets);

    virtual types::WeaponType GetType();

    virtual int GetMaxAmmo();

    virtual std::ostream& print(std::ostream& os) const;

};

    std::ostream& operator<<(std::ostream& os, const Rifle& rifle);

} // objects
} // time_lost


#endif // RIFLE_H