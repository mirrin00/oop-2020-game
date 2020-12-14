#ifndef MENU_H
#define MENU_H

#include <memory>
#include <vector>

namespace time_lost{
namespace logic{
class MenuItemInterface;
class TimeLost;
}
}



namespace time_lost{

namespace logic{

class Menu{
private:
    std::vector<std::shared_ptr<MenuItemInterface>> items;

    int selected;

    void AddItem(std::shared_ptr<MenuItemInterface> item);
public:
    Menu();

    ~Menu() = default;

    void SelectUp();

    void SelectDown();

    void Execute(TimeLost& game);

    const std::vector<std::shared_ptr<MenuItemInterface>> GetItems() const;

    static Menu GetStartMenu();
};

} // logic
} // time_lost

#include "menu_item_interface.h"
#include "time_lost.h"


#endif // MENU_H