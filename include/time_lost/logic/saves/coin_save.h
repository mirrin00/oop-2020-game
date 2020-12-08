#ifndef COIN_SAVE_H
#define COIN_SAVE_H

namespace time_lost{

namespace objects{
class Coin;
}
}

#include "item_save_interface.h"
#include "../../objects/coin.h"
#include "../../types/save_type.h"

namespace time_lost{

namespace logic{

namespace saves{

class CoinSave: public ItemSaveInterface{
private:
    types::Position _pos;
    
    int _count;

    bool _on_field, _can_use;
public:
    CoinSave() = default;

    CoinSave(types::Position pos, int count, bool on_field, bool can_use);

    ~CoinSave() = default;

    objects::Coin LoadCoin();

    std::shared_ptr<objects::Item> LoadItem() override;

    virtual void WriteItem(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, CoinSave& save);

    friend std::istream& operator>>(std::istream& is, CoinSave& save);
};

std::ostream& operator<<(std::ostream& os, CoinSave& save);

std::istream& operator>>(std::istream& is, CoinSave& save);

} // saves
} // logic
} // time_lost


#endif // COIN_SAVE_H