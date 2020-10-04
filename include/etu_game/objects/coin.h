#ifndef COIN_H
#define COIN_H

#include "item.h"

namespace etu_game{

namespace objects{

class Coin: public Item{
private:
    int count;
public:
    Coin(int _count, int start_h_pos = 0, int start_w_pos = 0);

    ~Coin();

    Coin(const Coin& coin);

    int GetCount();
    // FIXME: SetCount()?

    Coin& operator=(const Coin& coin);

    void Use(Player& player);
};

} // objects
} // etu_game


#endif // COIN_H