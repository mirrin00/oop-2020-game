#ifndef ITEM_H
#define ITEM_H

#include <iostream>

namespace etu_game{
namespace objects{
class Player;
}
}

#include "object.h"
#include "player.h"

namespace etu_game{

namespace objects{

class Item: public Object{
private:
    bool on_field, can_use;
protected:
    virtual void Notify() override;
public:
    Item(int start_h_pos = 0, int start_w_pos = 0);

    ~Item();

    Item(const Item& item);

    Item& operator=(const Item& item);

    bool IsOnField();

    void SetOnField(bool on_field);

    bool IsCanUse();

    void SetCanUse(bool can_use);

    virtual void Use(Player& player) = 0;

    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};

    std::ostream& operator<<(std::ostream& os, const Item& item);

} // objects
} // etu_game


#endif // ITEM_H