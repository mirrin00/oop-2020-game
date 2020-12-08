#include "time_lost/logic/saves/coin_save.h"

namespace time_lost{

namespace logic{

namespace saves{

CoinSave::CoinSave(types::Position pos, int count, bool on_field, bool can_use):
_pos(pos),
_count(count),
_on_field(on_field),
_can_use(can_use)
{
}

objects::Coin CoinSave::LoadCoin(){
    objects::Coin Coin(_count, _pos);
    Coin.SetCanUse(_can_use);
    Coin.SetOnField(_on_field);
    return Coin;
}

std::shared_ptr<objects::Item> CoinSave::LoadItem(){
    return LoadCoin().CloneItem();
}

void CoinSave::WriteItem(std::ostream& os){
    os << *this;
}

std::ostream& operator<<(std::ostream& os, CoinSave& save){
    int type = types::SaveType::kCoin;
    os.write((char*)&type, sizeof(int));
    os.write((char*)&save + offsetof(CoinSave, _pos), offsetof(CoinSave, _can_use)
                 - offsetof(CoinSave, _pos) + sizeof(bool));
    return os;
}

std::istream& operator>>(std::istream& is, CoinSave& save){
    is.read((char*)&save + offsetof(CoinSave, _pos), offsetof(CoinSave, _can_use)
                 - offsetof(CoinSave, _pos) + sizeof(bool));
    return is;
}

} // saves
} // logic
} // time_lost