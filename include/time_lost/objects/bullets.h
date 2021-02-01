#ifndef BULLETS_H
#define BULLETS_H

#include "../types/bullet_type.h"
#include "item.h"

namespace time_lost{
namespace logic{
namespace saves{
class BulletsSave;
}
}
}

#include "../logic/saves/bullets_save.h"

namespace time_lost{

namespace objects{

class Bullets: public Item{
private:
    int count;

    types::BulletType type;
protected:
    virtual void Notify() override;
public:
    Bullets(int _count, types::BulletType _type, types::Position start_pos = {0,0});

    ~Bullets();

    Bullets(const Bullets& coin);

    int GetCount();
    
    void SetCount(int new_count);

    types::BulletType GetType();

    Bullets& operator=(const Bullets& coin);

    virtual void Use(Player& player) override;

    virtual std::shared_ptr<Item> CloneItem() const override;

    virtual std::shared_ptr<logic::saves::BulletsSave> SaveBullets();

    virtual std::shared_ptr<logic::saves::ItemSaveInterface> SaveItem() override;

    friend std::ostream& operator<<(std::ostream& os, const Bullets& coin);
};

    std::ostream& operator<<(std::ostream& os, const Bullets& coin);

} // objects
} // time_lost


#endif // BULLETS_H