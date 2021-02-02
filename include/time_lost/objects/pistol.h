#ifndef PISTOL_H
#define PISTOL_H

#include "weapon.h"

namespace time_lost{

namespace objects{

class Pistol: public Weapon{
public:
    Pistol() = default;

    ~Pistol() = default;

    Pistol(const Pistol& pistol);

    Pistol& operator=(const Pistol& pistol);

    virtual std::tuple<int, int, int> Attack();

    virtual void Reload(int bullets);

    virtual types::WeaponType GetType();

    virtual int GetMaxAmmo();

    virtual std::ostream& print(std::ostream& os) const;

};

    std::ostream& operator<<(std::ostream& os, const Pistol& rifle);

} // objects
} // time_lost


#endif // PISTOL_H