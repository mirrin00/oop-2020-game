#include "time_lost/logic/menu_items/menu_item_start.h"

#include "time_lost/logic/turns/player_turn.h"

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
        game.SetTurn(std::make_unique<turns::PlayerTurn>(game));
    }
}

} // menu_items
} // logic
} // time_lost