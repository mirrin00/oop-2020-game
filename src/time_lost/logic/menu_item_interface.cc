#include "time_lost/logic/menu_item_interface.h"

namespace time_lost{
    
namespace logic{
    
MenuItemInterface::MenuItemInterface(std::string descript):
description(descript),
is_can_execute(true),
is_selected(false)
{
}

const std::string MenuItemInterface::GetDescription(){
    return description;
}

bool MenuItemInterface::GetIsCanExecute(){
    return is_can_execute;
}

void MenuItemInterface::SetIsCanExecute(bool can_execute){
    is_can_execute = can_execute;
}

bool MenuItemInterface::IsSelected(){
    return is_selected;
}

void MenuItemInterface::ChangeSelected(){
    is_selected = !is_selected;
}

} // namespace logic

} // namespace time_lost
