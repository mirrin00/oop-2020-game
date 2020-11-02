#ifndef COIN_H
#define COIN_H

#include "item.h"

namespace time_lost{

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

    virtual std::shared_ptr<Item> CloneItem() const override;

    friend std::ostream& operator<<(std::ostream& os, const Coin& coin);
};

    std::ostream& operator<<(std::ostream& os, const Coin& coin);

} // objects
} // time_lost


#endif // COIN_H