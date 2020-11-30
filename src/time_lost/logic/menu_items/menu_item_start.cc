#include "time_lost/logic/menu_items/menu_item_start.h"

namespace time_lost{

namespace logic{

namespace menu_items{

MenuItemStart::MenuItemStart():
MenuItemInterface("Start")
{
}

void MenuItemStart::Execute(TimeLost& game){
    if(GetIsCanExecute()){
        game.Start();
        game.NextTurn();
    }
}

} // menu_items
} // logic
} // time_lost