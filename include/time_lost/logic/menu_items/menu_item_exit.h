#ifndef MENU_ITEM_EXIT_H
#define MENU_ITEM_EXIT_H

#include "../menu_item_interface.h"

namespace time_lost{

namespace logic{

namespace menu_items{

class MenuItemExit: public MenuItemInterface{
public:
    MenuItemExit();

    void Execute(TimeLost& game) override;
};

} // menu_items
} // logic
} // time_lost


#endif // MENU_ITEM_EXIT_H