#include "time_lost/logic/menu_items/menu_item_load.h"

namespace time_lost{

namespace logic{

namespace menu_items{

MenuItemLoad::MenuItemLoad():
MenuItemInterface("Load")
{
}

void MenuItemLoad::Execute(TimeLost& game){
    if(GetIsCanExecute()) game.Load();
}

} // menu_items
} // logic
} // time_lost