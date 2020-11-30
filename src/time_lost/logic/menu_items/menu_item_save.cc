#include "time_lost/logic/menu_items/menu_item_save.h"

namespace time_lost{

namespace logic{

namespace menu_items{

MenuItemSave::MenuItemSave():
MenuItemInterface("Save")
{
}

void MenuItemSave::Execute(TimeLost& game){
    if(GetIsCanExecute()) game.Save();
}

} // menu_items
} // logic
} // time_lost