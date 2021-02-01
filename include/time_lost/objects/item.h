#ifndef ITEM_H
#define ITEM_H

#include <iostream>

namespace time_lost{
namespace objects{
class Player;
}
}

#include "object.h"
#include "player.h"

namespace time_lost{
namespace logic{
namespace saves{
class ItemSaveInterface;
}
}
}

#include "../logic/saves/item_save_interface.h"

namespace time_lost{

namespace objects{

class Item: public Object{
private:
    bool on_field;
protected:
    virtual void Notify() override;
public:
    Item(types::Position start_pos = {0,0});

    ~Item();

    Item(const Item& item);

    Item& operator=(const Item& item);

    bool IsOnField();

    void SetOnField(bool on_field);

    virtual void Use(Player& player) = 0;

    virtual std::shared_ptr<Item> CloneItem() const = 0;

    virtual std::shared_ptr<logic::saves::ItemSaveInterface> SaveItem() = 0;

    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};

    std::ostream& operator<<(std::ostream& os, const Item& item);

} // objects
} // time_lost


#endif // ITEM_H