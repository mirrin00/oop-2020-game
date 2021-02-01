#ifndef BULLETS_SAVE_H
#define BULLETS_SAVE_H

namespace time_lost{

namespace objects{
class Bullets;
}
}

#include "item_save_interface.h"
#include "../../objects/bullets.h"
#include "../../types/save_type.h"

namespace time_lost{

namespace logic{

namespace saves{

class BulletsSave: public ItemSaveInterface{
private:
    struct Data{
        types::Position pos;
        
        int count;

        types::BulletType type;

        bool on_field;
    };

    Data data;
public:
    BulletsSave() = default;

    BulletsSave(types::Position pos, int count, types::BulletType type, bool on_field);

    ~BulletsSave() = default;

    objects::Bullets LoadBullets();

    std::shared_ptr<objects::Item> LoadItem() override;

    virtual void WriteItem(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, BulletsSave& save);

    friend std::istream& operator>>(std::istream& is, BulletsSave& save);
};

std::ostream& operator<<(std::ostream& os, BulletsSave& save);

std::istream& operator>>(std::istream& is, BulletsSave& save);

} // saves
} // logic
} // time_lost


#endif // BULLETS_SAVE_H