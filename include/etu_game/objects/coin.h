#ifndef COIN_H
#define COIN_H

#include "item.h"

namespace etu_game{

namespace objects{

class Coin: public Item{
private:
    int count;
protected:
    virtual void Notify() override;
public:
    Coin(int _count, int start_h_pos = 0, int start_w_pos = 0);

    ~Coin();

    Coin(const Coin& coin);

    int GetCount();
    // FIXME: SetCount()?

    Coin& operator=(const Coin& coin);

    virtual void Use(Player& player) override;

    virtual std::shared_ptr<Item> clone() override;

    friend std::ostream& operator<<(std::ostream& os, const Coin& coin);
};

    std::ostream& operator<<(std::ostream& os, const Coin& coin);

} // objects
} // etu_game


#endif // COIN_H