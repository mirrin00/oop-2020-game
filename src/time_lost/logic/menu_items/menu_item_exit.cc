#include "time_lost/logic/menu_items/menu_item_exit.h"

#include "time_lost/logic/turns/exit_turn.h"

namespace time_lost{

namespace logic{

namespace menu_items{

MenuItemExit::MenuItemExit():
MenuItemInterface("Exit")
{
}

void MenuItemExit::Execute(TimeLost& game){
    if(GetIsCanExecute()) game.SetTurn(std::make_unique<turns::ExitTurn>(game));
}

} // menu_items
} // logic
} // time_lost