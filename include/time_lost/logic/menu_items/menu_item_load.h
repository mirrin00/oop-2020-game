#ifndef MENU_ITEM_LOAD_H
#define MENU_ITEM_LOAD_H

#include "../menu_item_interface.h"

namespace time_lost{

namespace logic{

namespace menu_items{

class MenuItemLoad: public MenuItemInterface{
public:
    MenuItemLoad();

    void Execute(TimeLost& game) override;
};

} // menu_items
} // logic
} // time_lost


#endif // MENU_ITEM_LOAD_H