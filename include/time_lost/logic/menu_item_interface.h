#ifndef MENU_ITEM_INTERFACE_H
#define MENU_ITEM_INTERFACE_H

namespace time_lost{
namespace logic{
class Menu;
}
}

#include "time_lost.h"

namespace time_lost{

namespace logic{

class MenuItemInterface{
private:
    const std::string description;

    bool is_can_execute;

    bool is_selected;
public:
    MenuItemInterface(std::string descript);

    const std::string GetDescription();

    virtual void Execute(TimeLost& game) = 0;

    bool GetIsCanExecute();

    void SetIsCanExecute(bool can_execute);

    bool IsSelected();

    void ChangeSelected();
};

} // logic
} // time_lost


#endif // MENU_ITEM_INTERFACE_H