#ifndef MENU_ITEM_START_H
#define MENU_ITEM_START_H

#include "../menu_item_interface.h"

namespace time_lost{

namespace logic{

namespace menu_items{

class MenuItemStart: public MenuItemInterface{
public:
    MenuItemStart();

    void Execute(TimeLost& game) override;
};

} // menu_items
} // logic
} // time_lost


#endif // MENU_ITEM_START_H