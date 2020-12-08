#ifndef HANDS_SAVE_H
#define HANDS_SAVE_H

namespace time_lost{

namespace objects{
class Hands;
}
}

#include "weapon_save_interface.h"
#include "../../objects/hands.h"
#include "../../types/save_type.h"

namespace time_lost{

namespace logic{

namespace saves{

class HandsSave: public WeaponSaveInterface{
public:
    HandsSave();

    ~HandsSave();

    objects::Hands LoadHands();

    virtual void WriteWeapon(std::ostream& os) override;
    
    std::unique_ptr<objects::Weapon> LoadWeapon() override;

    friend std::ostream& operator<<(std::ostream& os, HandsSave& save);

    friend std::istream& operator>>(std::istream& is, HandsSave& save);
};

std::ostream& operator<<(std::ostream& os, HandsSave& save);

std::istream& operator>>(std::istream& is, HandsSave& save);

} // saves
} // logic
} // time_lost


#endif // SWORD_SAVE_H