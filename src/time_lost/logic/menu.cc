#include "time_lost/logic/menu.h"

#include "time_lost/logic/menu_items/menu_item_start.h"
#include "time_lost/logic/menu_items/menu_item_exit.h"
#include "time_lost/logic/menu_items/menu_item_load.h"
#include "time_lost/logic/menu_items/menu_item_save.h"

namespace time_lost{

namespace logic{

Menu::Menu():
selected(0)
{
}

void Menu::AddItem(std::shared_ptr<MenuItemInterface> item){
    items.emplace_back(item);
}

void Menu::SelectUp(){
    items[selected]->ChangeSelected();
    selected--;
    if(selected < 0) selected = items.size() - 1;
    items[selected]->ChangeSelected();
}

void Menu::SelectDown(){
    items[selected]->ChangeSelected();
    selected = (selected + 1) % items.size();
    items[selected]->ChangeSelected();
}

void Menu::Execute(TimeLost& game){
    items[selected]->Execute(game);
}

const std::vector<std::shared_ptr<MenuItemInterface>> Menu::GetItems() const{
    return items;
}

Menu Menu::GetStartMenu(){
    Menu menu;
    menu.items.reserve(3);
    menu.AddItem(std::make_shared<menu_items::MenuItemStart>());
    std::shared_ptr<menu_items::MenuItemLoad> load = std::make_shared<menu_items::MenuItemLoad>();
    {
        std::ifstream file("time_lost.save");
        if(!file.is_open()) load->SetIsCanExecute(false);
    }
    menu.AddItem(load);
    menu.AddItem(std::make_shared<menu_items::MenuItemExit>());
    menu.items[0]->ChangeSelected();
    return menu;
}

} // logic
} // time_lost