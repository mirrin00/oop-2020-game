#ifndef ITEM_H
#define ITEM_H

#include <iostream>

namespace etu_game{
namespace objects{
class Player;
}
}

#include "player.h"
#include "../logic/publisher.h"

namespace etu_game{

namespace objects{

class Item{
private:
    int h_pos, w_pos;
    
    bool on_field, can_use;
protected:
    logic::Publisher pub;

    virtual void Notify();
public:
    Item(int start_h_pos = 0, int start_w_pos = 0);

    ~Item();

    Item(const Item& item);

    Item& operator=(const Item& item);
    
    int GetHeightPosition();

    int GetWidthPosition();

    void SetHeightPosition(int new_h_pos);

    void SetWidthPosition(int new_w_pos);

    bool IsOnField();

    void SetOnField(bool on_field);

    bool IsCanUse();

    void SetCanUse(bool can_use);

    void Subscribe(logic::Subscriber& sub);

    void Unsubscribe(logic::Subscriber& sub);

    virtual void Use(Player& player) = 0;

    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};

    std::ostream& operator<<(std::ostream& os, const Item& item);

} // objects
} // etu_game


#endif // ITEM_H