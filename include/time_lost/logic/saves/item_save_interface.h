#ifndef ITEM_SAVE_INTERFACE_H
#define ITEM_SAVE_INTERFACE_H

namespace time_lost{

namespace objects{
class Item;
}
}

#include "../../objects/item.h"
#include <iostream>

namespace time_lost{

namespace logic{

namespace saves{

class ItemSaveInterface{
public:
    virtual ~ItemSaveInterface() = default;

    virtual std::shared_ptr<objects::Item> LoadItem() = 0;

    virtual void WriteItem(std::ostream& os) = 0;

    friend std::ostream& operator<<(std::ostream& os, ItemSaveInterface& save);
};

std::ostream& operator<<(std::ostream& os, ItemSaveInterface& save);

} // saves
} // logic
} // time_lost


#endif // ITEM_SAVE_INTERFACE_H